package pkg

import (
	"bufio"
	"bytes"
	"embed"
	"errors"
	"fmt"
	"go/format"
	"io/fs"
	"log"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"text/template"

	"github.com/goccy/go-zetasql/internal/exportinc"
)

var (
	bazelSupportedLibs = []string{"zetasql", "absl", "algorithms", "base", "proto"}
	includeDirs        = []string{"protobuf", "utf8_range", "gtest", "icu", "re2", "json", "googleapis", "boringssl", "flex/src"}
)

type Generator struct {
	buildFileParser               *BuildFileParser
	cfg                           *Config
	bridge                        *Bridge
	importSymbol                  *ImportSymbol
	libMap                        map[string]*Lib
	pkgMap                        map[string]Package
	importSymbolPackageMap        map[string]Package
	containsConflictSymbolFileMap     map[string][]string
	conflictExportSuffixByFileSymbol map[string]map[string]string // file -> symbol -> suffix
	containsAddSourceFileMap      map[string]SourceConfig
	pkgToAllDeps                  map[string][]string
	internalExportNames           []string
	templates                     embed.FS
}

func NewGenerator(cfg *Config, bridge *Bridge, importSymbol *ImportSymbol, templates embed.FS) *Generator {
	containsConflictSymbolFileMap := map[string][]string{}
	conflictExportSuffixByFileSymbol := map[string]map[string]string{}
	for _, sym := range cfg.ConflictSymbols {
		sym := sym
		symbols := append([]string{}, sym.Symbols...)
		if sym.Symbol != "" {
			symbols = append(symbols, sym.Symbol)
		}
		containsConflictSymbolFileMap[sym.File] = append(containsConflictSymbolFileMap[sym.File], symbols...)
		if len(sym.ExportSuffixes) > 0 {
			if conflictExportSuffixByFileSymbol[sym.File] == nil {
				conflictExportSuffixByFileSymbol[sym.File] = map[string]string{}
			}
			for k, v := range sym.ExportSuffixes {
				conflictExportSuffixByFileSymbol[sym.File][k] = v
			}
		}
	}
	containsAddSourceFileMap := map[string]SourceConfig{}
	for _, src := range cfg.AddSources {
		src := src
		containsAddSourceFileMap[src.File] = src
	}
	pkgMap := map[string]Package{}
	for _, pkg := range bridge.Packages {
		pkg := pkg
		pkgMap[pkg.Name] = pkg
	}
	importSymbolPackageMap := map[string]Package{}
	for _, pkg := range importSymbol.Packages {
		pkg := pkg
		importSymbolPackageMap[pkg.Name] = pkg
		pkgMap[pkg.Name] = pkg // merge import symbols to package map
	}
	return &Generator{
		buildFileParser:               NewBuildFileParser(cfg),
		cfg:                           cfg,
		bridge:                        bridge,
		importSymbol:                  importSymbol,
		templates:                     templates,
		containsConflictSymbolFileMap:     containsConflictSymbolFileMap,
		conflictExportSuffixByFileSymbol: conflictExportSuffixByFileSymbol,
		containsAddSourceFileMap:      containsAddSourceFileMap,
		importSymbolPackageMap:        importSymbolPackageMap,
		pkgMap:                        pkgMap,
	}
}

func (g *Generator) Generate() error {
	parsedFiles, err := g.createParsedFiles()
	if err != nil {
		return err
	}
	g.libMap = g.createLibMap(parsedFiles)
	pkgToAllDeps, err := g.createAllDependencyMap(parsedFiles)
	if err != nil {
		return err
	}
	g.pkgToAllDeps = pkgToAllDeps
	internalExportNames, err := g.protobufInternalExportNames(parsedFiles)
	if err != nil {
		return err
	}
	g.internalExportNames = internalExportNames
	for _, parsedFile := range parsedFiles {
		if err := g.generate(parsedFile); err != nil {
			return err
		}
	}
	dummyGo, err := g.templates.ReadFile("templates/dummy.go.tmpl")
	if err != nil {
		return err
	}
	for _, dir := range append(includeDirs, "zetasql", "absl", "algorithms", "base", "proto") {
		if err := filepath.Walk(filepath.Join(ccallDir(), dir), func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return err
			}
			if info.IsDir() {
				if err := os.WriteFile(filepath.Join(path, "dummy.go"), dummyGo, 0o600); err != nil {
					return err
				}
			}
			return nil
		}); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) createParsedFiles() ([]*ParsedFile, error) {
	var parsedFiles []*ParsedFile
	for _, lib := range bazelSupportedLibs {
		srcPath := toSourceDirFromLibName(lib)
		if err := filepath.Walk(srcPath, func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return fmt.Errorf("unexpected error in walk: %w", err)
			}
			switch filepath.Base(path) {
			case "BUILD", "BUILD.bazel":
				f, err := g.buildFileParser.Parse(path)
				if err != nil {
					return err
				}
				parsedFiles = append(parsedFiles, f)
			}
			return nil
		}); err != nil {
			return nil, err
		}
	}
	return parsedFiles, nil
}

func (g *Generator) createLibMap(parsedFiles []*ParsedFile) map[string]*Lib {
	cclibMap := map[string]*Lib{}
	for _, parsedFile := range parsedFiles {
		for _, cclib := range parsedFile.cclibs {
			srcPkgName := fmt.Sprintf("%s/%s", cclib.BasePkg, cclib.Name)
			cclibMap[srcPkgName] = cclib
		}
	}
	for _, dep := range g.cfg.Dependencies {
		cclibdeps := make([]Dependency, 0, len(dep.Deps))
		for _, d := range dep.Deps {
			cclibdeps = append(cclibdeps, Dependency{
				BasePkg: d.Base,
				Pkg:     d.Pkg,
			})
		}
		cclibMap[fmt.Sprintf("%s/%s", dep.Name, dep.Name)] = &Lib{
			BasePkg: dep.Name,
			Name:    dep.Name,
			Deps:    cclibdeps,
		}
	}
	return cclibMap
}

func (g *Generator) createAllDependencyMap(parsedFiles []*ParsedFile) (map[string][]string, error) {
	pkgToAllDeps := map[string][]string{}
	for pkgName, lib := range g.libMap {
		pkgMap := map[string]struct{}{}
		if err := g.resolveDeps(pkgMap, lib); err != nil {
			return nil, err
		}
		sorted := []string{}
		for k := range pkgMap {
			lib, exists := g.libMap[k]
			if exists {
				if len(lib.Sources) == 0 || lib.headerOnly() {
					continue
				}
			}
			sorted = append(sorted, k)
		}
		sort.Strings(sorted)
		pkgToAllDeps[pkgName] = sorted
	}
	return pkgToAllDeps, nil
}

func (g *Generator) resolveDeps(pkgMap map[string]struct{}, lib *Lib) error {
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	for _, dep := range lib.Deps {
		dep := dep
		depPkgName := fmt.Sprintf("%s/%s", dep.BasePkg, dep.Pkg)
		if _, exists := pkgMap[depPkgName]; exists {
			continue
		}
		lib, exists := g.libMap[depPkgName]
		if exists {
			if err := g.resolveDeps(pkgMap, lib); err != nil {
				return err
			}
		}
	}
	pkgMap[pkgName] = struct{}{}
	return nil
}

func (g *Generator) protobufInternalExportNames(parsedFiles []*ParsedFile) ([]string, error) {
	internalExportNames := []string{}
	appendInternalExportNames := func(name string) {
		internalExportNames = append(internalExportNames,
			name,
			descriptorTableName(name),
			tableStructName(name),
		)
	}
	for _, path := range g.cfg.ProtobufInternalExportNameFiles {
		internalExportName, err := g.headerPathToInternalExportName(filepath.Join(ccallDir(), path))
		if err != nil {
			return nil, err
		}
		appendInternalExportNames(internalExportName)
	}
	for _, parsedFile := range parsedFiles {
		for _, ccproto := range parsedFile.ccprotos {
			for _, header := range ccproto.Headers {
				headerPath := filepath.Join(ccallDir(), ccproto.BasePkg, header)
				internalExportName, err := g.headerPathToInternalExportName(headerPath)
				if err != nil {
					return nil, err
				}
				appendInternalExportNames(internalExportName)
			}
		}
	}
	return internalExportNames, nil
}

func descriptorTableName(internalExportName string) string {
	return "descriptor_table_" + internalExportName
}

func tableStructName(internalExportName string) string {
	return "TableStruct_" + internalExportName
}

func (g *Generator) headerPathToInternalExportName(path string) (string, error) {
	f, err := os.Open(path)
	if err != nil {
		return "", err
	}
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		text := scanner.Text()
		if strings.HasPrefix(text, "#define PROTOBUF_INTERNAL_EXPORT") {
			splitted := strings.Split(text, " ")
			return splitted[1][len("PROTOBUF_INTERNAL_EXPORT_"):], nil
		}
	}
	if err := scanner.Err(); err != nil {
		return "", err
	}
	return "", fmt.Errorf("failed to find PROTOBUF_INTERNAL_EXPORT in %s", path)
}

func (g *Generator) generate(f *ParsedFile) error {
	for _, lib := range f.cclibs {
		outputDir := filepath.Join(ccallDir(), goPkgPath(lib.BasePkg, lib.Name))
		if err := os.MkdirAll(outputDir, 0o755); err != nil {
			return err
		}
		if err := g.generateBindCC(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeExternH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeCCInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBridgeInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBindGO(outputDir, lib); err != nil {
			return err
		}
	}
	for _, lib := range f.ccprotos {
		outputDir := filepath.Join(ccallDir(), goPkgPath(lib.BasePkg, lib.Name))
		if err := os.MkdirAll(outputDir, 0o755); err != nil {
			return err
		}
		if err := g.generateBindCC(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeExternH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeCCInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBridgeInc(outputDir); err != nil {
			return err
		}
	}
	rootOutputDir := filepath.Join(ccallDir(), "go-zetasql")
	if err := os.MkdirAll(rootOutputDir, 0o755); err != nil {
		return err
	}
	if err := g.generateRootBindCC(rootOutputDir); err != nil {
		return err
	}
	if err := g.generateRootBridgeH(rootOutputDir); err != nil {
		return err
	}
	if err := g.generateRootBindGO(rootOutputDir); err != nil {
		return err
	}
	return nil
}

// rootZetaSQLAmalgamationLibs lists zetasql ccall libs linked into root bind.cc / bridge.h.
// zetasql/parser/parser is omitted: that package has its own bind.cc with namespace-prefix
// macros; re-including parser/export.inc in the parent TU duplicates absl flags and parser .o.
func (g *Generator) rootZetaSQLAmalgamationLibs() []string {
	pkgs := g.pkgs()
	libs := make([]string, 0, len(pkgs))
	for _, pkg := range pkgs {
		if !strings.Contains(pkg.Name, "zetasql") {
			continue
		}
		if pkg.Name == "zetasql/parser/parser" {
			continue
		}
		libs = append(libs, pkg.Name)
	}
	return libs
}

func (g *Generator) generateRootBindCC(outputDir string) error {
	libs := g.rootZetaSQLAmalgamationLibs()
	output, err := g.generateCCSourceByTemplate(
		"templates/root_bind.cc.tmpl",
		libs,
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBindCC(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bind.cc.tmpl",
		g.createBindCCParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), output, 0o600); err != nil {
		return err
	}
	return g.syncExportInc(outputDir, output)
}

func (g *Generator) syncExportInc(outputDir string, bindCC []byte) error {
	packageDir, err := exportinc.PackageDirForGuard(outputDir, repoRootDir())
	if err != nil {
		return err
	}
	exportPath := filepath.Join(outputDir, "export.inc")
	out, err := exportinc.BuildFromBindCC(packageDir, bindCC)
	if err != nil {
		if errors.Is(err, exportinc.ErrNoPrelude) {
			return nil
		}
		return fmt.Errorf("export.inc %s: %w", outputDir, err)
	}
	return os.WriteFile(exportPath, out, 0o600)
}

func (g *Generator) pkgs() []*Package {
	pkgs := make([]*Package, 0, len(g.pkgMap))
	for _, pkg := range g.pkgMap {
		pkg := pkg
		pkgs = append(pkgs, &pkg)
	}
	sort.Slice(pkgs, func(i, j int) bool {
		return pkgs[i].Name < pkgs[j].Name
	})
	return pkgs
}

func (g *Generator) generateRootBridgeH(outputDir string) error {
	libs := g.rootZetaSQLAmalgamationLibs()
	output, err := g.generateCCSourceByTemplate(
		"templates/root_bridge.h.tmpl",
		libs,
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeH(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bridge.h.tmpl",
		g.createBindCCParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeExternH(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bridge_extern.h.tmpl",
		g.createBridgeExternParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge_extern.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBindGO(outputDir string, lib *Lib) error {
	{
		// for darwin ( currently windows not supported )
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createBindGoParamDarwin(lib),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), output, 0o600); err != nil {
			return err
		}
	}
	{
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createBindGoParamLinux(lib),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), output, 0o600); err != nil {
			return err
		}
	}
	if existsFile(filepath.Join(outputDir, "bind.go")) {
		if err := os.Remove(filepath.Join(outputDir, "bind.go")); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) generateRootBindGO(outputDir string) error {
	{
		// for darwin ( currently windows not supported )
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createRootBindGoParamDarwin(),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), output, 0o600); err != nil {
			return err
		}
	}
	{
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createRootBindGoParamLinux(),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), output, 0o600); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) generateBridgeCCInc(outputDir string) error {
	if existsFile(filepath.Join(outputDir, "bridge_cc.inc")) {
		return nil
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge_cc.inc"), nil, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeInc(outputDir string) error {
	if existsFile(filepath.Join(outputDir, "bridge.inc")) {
		return nil
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge.inc"), nil, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateCCSourceByTemplate(tmplPath string, param interface{}) ([]byte, error) {
	tmplText, err := g.templates.ReadFile(tmplPath)
	if err != nil {
		return nil, fmt.Errorf("failed to read template: %w", err)
	}
	tmpl, err := template.New("").Parse(string(tmplText))
	if err != nil {
		return nil, fmt.Errorf("failed to parse template: %w", err)
	}
	var b bytes.Buffer
	if err := tmpl.Execute(&b, param); err != nil {
		return nil, fmt.Errorf("failed to execute template: %w", err)
	}
	return b.Bytes(), nil
}

func (g *Generator) generateGoSourceByTemplate(tmplPath string, param interface{}) ([]byte, error) {
	tmplText, err := g.templates.ReadFile(tmplPath)
	if err != nil {
		return nil, fmt.Errorf("failed to read template: %w", err)
	}
	tmpl, err := template.New("").Parse(string(tmplText))
	if err != nil {
		return nil, fmt.Errorf("failed to parse template: %w", err)
	}
	var b bytes.Buffer
	if err := tmpl.Execute(&b, param); err != nil {
		return nil, fmt.Errorf("failed to execute template: %w", err)
	}
	buf, err := format.Source(b.Bytes())
	if err != nil {
		return nil, fmt.Errorf("failed to format %s: %w", b.String(), err)
	}
	return buf, nil
}

type ReplaceNameEntry struct {
	Name              string
	CustomReplacement string // if set, emit #define Name CustomReplacement (else fqdn_Name)
	Comment           string // optional // line before a custom #define
}

type BindCCParam struct {
	FQDN                 string
	PkgPath              string
	ReplaceNameEntries   []ReplaceNameEntry
	PreludeBeforeHeaders string // optional; before "// include headers"
	Headers              []string
	Sources              []SourceParam
	Deps                 []string
}

type SourceParam struct {
	Value             string
	BeforeIncludeHook string
	AfterIncludeHook  string
}

// amalgamationExcludePaths returns paths to omit from bind.cc includes for a
// Bazel lib (BasePkg/Name). Applies to both hdrs and srcs (e.g. .h listed only
// in srcs for optional).
func (g *Generator) amalgamationExcludePaths(lib *Lib) map[string]struct{} {
	pkgKey := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	var exclude map[string]struct{}
	for _, ex := range g.cfg.CCLib.ExcludeAmalgamationHeaders {
		if ex.Pkg != pkgKey {
			continue
		}
		if exclude == nil {
			exclude = map[string]struct{}{}
		}
		for _, h := range ex.Headers {
			exclude[h] = struct{}{}
		}
	}
	return exclude
}

// amalgamationExcludeSourcePaths returns source paths to omit from bind.cc for a Bazel lib.
func (g *Generator) amalgamationExcludeSourcePaths(lib *Lib) map[string]struct{} {
	pkgKey := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	var exclude map[string]struct{}
	for _, ex := range g.cfg.CCLib.ExcludeAmalgamationSources {
		if ex.Pkg != pkgKey {
			continue
		}
		if exclude == nil {
			exclude = map[string]struct{}{}
		}
		for _, s := range ex.Sources {
			exclude[s] = struct{}{}
		}
	}
	return exclude
}

func bindCCPreludeBeforeHeaders(cfg *Config, lib *Lib) string {
	pkgKey := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	for _, ph := range cfg.CCLib.BindCCPreludeBeforeHeaders {
		if ph.Pkg != pkgKey {
			continue
		}
		s := strings.TrimSpace(ph.Lines)
		if s == "" {
			return ""
		}
		// Blank line before "// include headers" matches hand-curated bind.cc layout.
		return s + "\n\n"
	}
	return ""
}

func (g *Generator) buildReplaceNameEntries(pkgKey string) []ReplaceNameEntry {
	names := append(
		append(
			append([]string{}, g.cfg.TopLevelNamespaces...),
			g.cfg.GlobalSymbols...,
		),
		g.internalExportNames...,
	)
	for _, inj := range g.cfg.CCLib.InjectReplaceNames {
		if inj.Pkg != pkgKey {
			continue
		}
		idx := -1
		for i, n := range names {
			if n == inj.After {
				idx = i
				break
			}
		}
		if idx < 0 {
			log.Fatalf("inject_replace_names: after symbol %q not found for pkg %s", inj.After, pkgKey)
		}
		inserted := append([]string{}, names[:idx+1]...)
		inserted = append(inserted, inj.Names...)
		inserted = append(inserted, names[idx+1:]...)
		names = inserted
	}
	overrideBySymbol := map[string]SymbolDefineOverride{}
	for _, o := range g.cfg.CCLib.SymbolDefineOverrides {
		if o.Pkg != pkgKey {
			continue
		}
		overrideBySymbol[o.Symbol] = o
	}
	out := make([]ReplaceNameEntry, 0, len(names))
	for _, name := range names {
		if o, ok := overrideBySymbol[name]; ok {
			out = append(out, ReplaceNameEntry{
				Name:              name,
				CustomReplacement: o.Replacement,
				Comment:           o.Comment,
			})
			continue
		}
		out = append(out, ReplaceNameEntry{Name: name})
	}
	return out
}

func filterStrings(paths []string, exclude map[string]struct{}) []string {
	if exclude == nil {
		return paths
	}
	out := make([]string, 0, len(paths))
	for _, p := range paths {
		if _, drop := exclude[p]; drop {
			continue
		}
		out = append(out, p)
	}
	return out
}

func (g *Generator) createBindCCParam(lib *Lib) *BindCCParam {
	param := &BindCCParam{}

	basePrefix := sanitizeIdentifier(strings.ReplaceAll(lib.BasePkg, "/", "_"))
	param.FQDN = fmt.Sprintf("%s_%s", basePrefix, sanitizeIdentifier(lib.Name))
	param.PkgPath = lib.BasePkg
	pkgKey := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	param.ReplaceNameEntries = g.buildReplaceNameEntries(pkgKey)
	param.PreludeBeforeHeaders = bindCCPreludeBeforeHeaders(g.cfg, lib)
	excludeAmalg := g.amalgamationExcludePaths(lib)
	excludeSrc := g.amalgamationExcludeSourcePaths(lib)
	param.Headers = filterStrings(lib.HeaderPaths(), excludeAmalg)
	sources := make([]SourceParam, 0, len(lib.Sources))
	for _, src := range filterStrings(filterStrings(lib.SourcePaths(), excludeAmalg), excludeSrc) {
		sourceParam := SourceParam{Value: src}
		if addSource, exists := g.containsAddSourceFileMap[src]; exists {
			for _, inc := range addSource.BeforeIncludes {
				if sourceParam.BeforeIncludeHook == "" {
					sourceParam.BeforeIncludeHook += "\n"
				}
				sourceParam.BeforeIncludeHook += fmt.Sprintf("#include \"%s\"\n", inc)
			}
			if addSource.FlexPrelude != "" {
				sourceParam.BeforeIncludeHook += "\n" + addSource.FlexPrelude + "\n"
			}
		}
		if symbols, exists := g.containsConflictSymbolFileMap[src]; exists {
			for _, symbol := range symbols {
				rhs := fmt.Sprintf("%s_%s", param.FQDN, symbol)
				if g.conflictExportSuffixByFileSymbol != nil {
					if suf, ok := g.conflictExportSuffixByFileSymbol[src][symbol]; ok && suf != "" {
						rhs = fmt.Sprintf("%s_%s_%s", param.FQDN, suf, symbol)
					}
				}
				sourceParam.BeforeIncludeHook += fmt.Sprintf("\n#define %s %s", symbol, rhs)
			}
			sourceParam.AfterIncludeHook = "\n"
			for i := len(symbols) - 1; i >= 0; i-- {
				sourceParam.AfterIncludeHook += fmt.Sprintf("#undef %s\n", symbols[i])
			}
		}
		if addSource, exists := g.containsAddSourceFileMap[src]; exists && addSource.Source != "" {
			sourceParam.AfterIncludeHook += fmt.Sprintf("\n#include \"%s\"\n", addSource.Source)
		}
		sources = append(sources, sourceParam)
	}
	param.Sources = sources
	deps := make([]string, 0, len(lib.Deps))
	for _, dep := range lib.Deps {
		deps = append(deps, goPkgPath(dep.BasePkg, dep.Pkg))
	}
	param.Deps = deps
	return param
}

type BindGoParam struct {
	Compiler        string
	DebugMode       bool
	Pkg             string
	FQDN            string
	ImportUnsafePkg bool
	IncludePaths    []string
	CXXFlags        []string
	LDFlags         []string
	BridgeHeaders   []string
	ImportGoLibs    []string
	Funcs           []Func
	ExportFuncs     []ExportFunc
}

type BridgeExternParam struct {
	Funcs []Func
}

type Func struct {
	BasePkg string
	Name    string
	Args    []Type
}

type ExportFunc struct {
	Func
	LibName string
}

type Type struct {
	IsCustomType bool
	IsRetType    bool
	NeedsCast    bool
	GO           string
	CGO          string
	C            string
}

func (t *Type) GoToC(index int) string {
	argName := fmt.Sprintf("arg%d", index)
	if t.IsRetType {
		return fmt.Sprintf("(%s)(unsafe.Pointer(%s))", t.CGO, argName)
	}
	return fmt.Sprintf("%s(%s)", t.CGO, argName)
}

var reservedKeywords = []string{
	"case", "range", "type",
}

func sanitizeIdentifier(v string) string {
	v = strings.ReplaceAll(v, "-", "_")
	return strings.ReplaceAll(v, ".", "_")
}

func (g *Generator) goReservedKeyword(keyword string) bool {
	for _, k := range reservedKeywords {
		if keyword == k {
			return true
		}
	}
	return false
}

func (g *Generator) cgoCompiler(lib *Lib) string {
	return "c++17"
}

func (g *Generator) goPkgName(lib *Lib) string {
	name := sanitizeIdentifier(lib.Name)
	if g.goReservedKeyword(name) {
		return "go_" + name
	}
	return name
}

func (g *Generator) extendLibs(lib *Lib) []string {
	if lib.BasePkg == "absl/time/internal/cctz" && lib.Name == "time_zone" {
		// TODO: switch by platform
		return []string{"-framework Foundation"}
	}
	return nil
}

func (g *Generator) createBindGoParamLinux(lib *Lib) *BindGoParam {
	ldflags := []string{"-ldl"}
	for _, flag := range lib.LinkerFlags {
		if flag.OSType == Darwin || flag.OSType == Windows {
			continue
		}
		ldflags = append(ldflags, flag.Flag)
	}
	cxxflags := []string{
		"-Wno-final-dtor-non-final-class",
		"-Wno-implicit-const-int-float-conversion",
	}
	return g.createBindGoParam(lib, cxxflags, ldflags)
}

func (g *Generator) createBindGoParamDarwin(lib *Lib) *BindGoParam {
	ldflags := []string{}
	for _, flag := range lib.LinkerFlags {
		if flag.OSType != Darwin {
			continue
		}
		ldflags = append(ldflags, flag.Flag)
	}
	return g.createBindGoParam(lib, nil, ldflags)
}

func (g *Generator) createRootBindGoParamLinux() *BindGoParam {
	ldflags := []string{"-ldl"}
	cxxflags := []string{
		"-Wno-final-dtor-non-final-class",
		"-Wno-implicit-const-int-float-conversion",
	}
	return g.createRootBindGoParam(cxxflags, ldflags)
}

func (g *Generator) createRootBindGoParamDarwin() *BindGoParam {
	return g.createRootBindGoParam(nil, nil)
}

func (g *Generator) createRootBindGoParam(cxxflags, ldflags []string) *BindGoParam {
	param := &BindGoParam{DebugMode: false}
	param.Pkg = "zetasql"
	param.FQDN = "zetasql"
	param.Compiler = "c++17"
	param.CXXFlags = cxxflags
	param.LDFlags = ldflags

	ccallDir := "../"
	includePaths := []string{ccallDir}
	for _, includeDir := range includeDirs {
		includePaths = append(includePaths, filepath.Join(ccallDir, includeDir))
	}
	param.IncludePaths = includePaths
	bridgeHeaderMap := map[string]struct{}{}
	for _, pkg := range g.pkgs() {
		// Parser methods use export_zetasql_parser_parser_* in parser/parser/bind_linux.go only.
		if pkg.Name == "zetasql/parser/parser" {
			continue
		}
		pkgName := pkg.Name
		for _, dep := range g.pkgToAllDeps[pkgName] {
			if dep == pkgName {
				continue
			}
			pkg, exists := g.importSymbolPackageMap[dep]
			if !exists {
				continue
			}
			goPkgPath := normalizeGoPkgPath(dep)
			libName := fmt.Sprintf("github.com/goccy/go-zetasql/internal/ccall/%s", goPkgPath)
			param.ImportGoLibs = append(param.ImportGoLibs, libName)
			basePkg := sanitizeIdentifier(filepath.Base(goPkgPath))
			bridgeHeader := filepath.Join(ccallDir, goPkgPath, "bridge.h")
			if _, exists := bridgeHeaderMap[bridgeHeader]; exists {
				continue
			}
			param.BridgeHeaders = append(param.BridgeHeaders, bridgeHeader)
			bridgeHeaderMap[bridgeHeader] = struct{}{}
			for _, method := range pkg.Methods {
				method := method
				fn, needsImportUnsagePkg := g.pkgMethodToFunc(basePkg, &method)
				if needsImportUnsagePkg {
					param.ImportUnsafePkg = true
				}
				param.ExportFuncs = append(param.ExportFuncs, ExportFunc{
					Func:    fn,
					LibName: libName,
				})
			}
		}
		funcs, needsImportUnsafePkg := g.pkgToFuncs("zetasql", pkg)
		param.Funcs = append(param.Funcs, funcs...)
		if needsImportUnsafePkg {
			param.ImportUnsafePkg = true
		}
	}
	param.ImportGoLibs = append(param.ImportGoLibs,
		"github.com/goccy/go-zetasql/internal/ccall/utf8_range_link",
	)
	return param
}

func (g *Generator) createBindGoParam(lib *Lib, cxxflags, ldflags []string) *BindGoParam {
	param := &BindGoParam{DebugMode: false}
	param.Pkg = g.goPkgName(lib)
	param.Compiler = g.cgoCompiler(lib)
	param.CXXFlags = cxxflags
	param.LDFlags = ldflags
	prefix := sanitizeIdentifier(strings.ReplaceAll(lib.BasePkg, "/", "_"))
	param.FQDN = fmt.Sprintf("%s_%s", prefix, sanitizeIdentifier(lib.Name))
	ccallDir := strings.Repeat("../", len(strings.Split(lib.BasePkg, "/"))+1)
	includePaths := []string{ccallDir}
	for _, includeDir := range includeDirs {
		includePaths = append(includePaths, filepath.Join(ccallDir, includeDir))
	}
	param.IncludePaths = includePaths
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	exportFuncs := []ExportFunc{}
	bridgeHeaders := []string{}
	importGoLibs := []string{}
	for _, dep := range g.pkgToAllDeps[pkgName] {
		if dep == pkgName {
			continue
		}
		pkg, exists := g.importSymbolPackageMap[dep]
		if !exists {
			continue
		}
		goPkgPath := normalizeGoPkgPath(dep)
		libName := fmt.Sprintf("github.com/goccy/go-zetasql/internal/ccall/%s", goPkgPath)
		importGoLibs = append(importGoLibs, libName)
		basePkg := sanitizeIdentifier(filepath.Base(goPkgPath))
		bridgeHeaders = append(bridgeHeaders, filepath.Join(ccallDir, goPkgPath, "bridge.h"))
		for _, method := range pkg.Methods {
			method := method
			fn, needsImportUnsagePkg := g.pkgMethodToFunc(basePkg, &method)
			if needsImportUnsagePkg {
				param.ImportUnsafePkg = true
			}
			exportFuncs = append(exportFuncs, ExportFunc{
				Func:    fn,
				LibName: libName,
			})
		}
	}
	param.ImportGoLibs = importGoLibs
	for _, extra := range g.cfg.CCLib.ExtraBindGoImports {
		if extra.Pkg != pkgName {
			continue
		}
		param.ImportGoLibs = append(param.ImportGoLibs, extra.Imports...)
	}
	param.BridgeHeaders = bridgeHeaders
	param.ExportFuncs = exportFuncs
	if pkg, exists := g.pkgMap[pkgName]; exists {
		pkg := pkg
		funcs, needsImportUnsafePkg := g.pkgToFuncs(sanitizeIdentifier(lib.Name), &pkg)
		param.Funcs = funcs
		if needsImportUnsafePkg {
			param.ImportUnsafePkg = true
		}
	}
	return param
}

func (g *Generator) pkgToFuncs(pkgName string, pkg *Package) ([]Func, bool) {
	needsImportUnsafePkg := false
	funcs := make([]Func, 0, len(pkg.Methods))
	for _, method := range pkg.Methods {
		method := method
		fn, needsUnsafePkg := g.pkgMethodToFunc(pkgName, &method)
		funcs = append(funcs, fn)
		if needsUnsafePkg {
			needsImportUnsafePkg = true
		}
	}
	return funcs, needsImportUnsafePkg
}

func (g *Generator) pkgMethodToFunc(pkgName string, method *Method) (Func, bool) {
	needsImportUnsafePkg := false
	fn := Func{
		BasePkg: pkgName,
		Name:    method.Name,
	}
	args := []Type{}
	for _, arg := range method.Args {
		cgoType := g.toCGOType(arg)
		if cgoType == "" {
			log.Fatalf("unexpected type: %s.%s.%s", pkgName, method.Name, arg)
		}
		if cgoType == "unsafe.Pointer" {
			needsImportUnsafePkg = true
		}
		goType := g.toGoType(arg)
		needsCast := goType != cgoType
		args = append(args, Type{
			NeedsCast: needsCast,
			GO:        goType,
			CGO:       cgoType,
		})
	}
	for _, ret := range method.Ret {
		cgoType := g.toCGOType(ret)
		if cgoType == "" {
			log.Fatalf("unexpected type: %s.%s.%s", pkgName, method.Name, ret)
		}
		if cgoType == "unsafe.Pointer" {
			needsImportUnsafePkg = true
		}
		goType := g.toGoType(ret)
		needsCast := goType != cgoType
		if needsCast {
			needsImportUnsafePkg = true
		}
		args = append(args, Type{
			IsRetType: true,
			NeedsCast: needsCast,
			GO:        "*" + goType,
			CGO:       "*" + cgoType,
		})
	}
	fn.Args = args
	return fn, needsImportUnsafePkg
}

func (g *Generator) createBridgeExternParam(lib *Lib) *BridgeExternParam {
	param := &BridgeExternParam{}
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	if pkg, exists := g.pkgMap[pkgName]; exists {
		funcs := make([]Func, 0, len(pkg.Methods))
		for _, method := range pkg.Methods {
			fn := Func{
				BasePkg: lib.Name,
				Name:    method.Name,
			}
			args := []Type{}
			for _, arg := range method.Args {
				args = append(args, Type{C: g.toCType(arg)})
			}
			for _, ret := range method.Ret {
				args = append(args, Type{C: fmt.Sprintf("%s*", g.toCType(ret))})
			}
			fn.Args = args
			funcs = append(funcs, fn)
		}
		param.Funcs = funcs
	}
	return param
}

func (g *Generator) toGoType(typ string) string {
	if typ == "string" || typ == "struct" {
		return "unsafe.Pointer"
	}
	return typ
}

func (g *Generator) toCGOType(typ string) string {
	switch typ {
	case "bool":
		return "C.char"
	case "int":
		return "C.int"
	case "int8":
		return "C.int8_t"
	case "int16":
		return "C.int16_t"
	case "int32":
		return "C.int32_t"
	case "int64":
		return "C.int64_t"
	case "uint":
		return "C.uint"
	case "uint8":
		return "C.uint8_t"
	case "uint16":
		return "C.uint16_t"
	case "uint32":
		return "C.uint32_t"
	case "uint64":
		return "C.uint64_t"
	case "float32":
		return "C.float"
	case "float64":
		return "C.double"
	case "string", "struct":
		return "unsafe.Pointer"
	}
	return ""
}

func (g *Generator) toCType(typ string) string {
	switch typ {
	case "bool":
		return "char"
	case "int":
		return "int"
	case "int8":
		return "int8_t"
	case "int16":
		return "int16_t"
	case "int32":
		return "int32_t"
	case "int64":
		return "int64_t"
	case "uint":
		return "uint"
	case "uint8":
		return "uint8_t"
	case "uint16":
		return "uint16_t"
	case "uint32":
		return "uint32_t"
	case "uint64":
		return "uint64_t"
	case "float32":
		return "float"
	case "float64":
		return "double"
	case "string", "struct":
		return "void *"
	}
	return ""
}
