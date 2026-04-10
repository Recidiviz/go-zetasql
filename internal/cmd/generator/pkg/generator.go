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

	"github.com/vantaboard/go-googlesql/internal/exportinc"
)

// defaultCgoStd is the -std= value for generated #cgo CXXFLAGS (matches upstream Bazel / GoogleSQL).
const defaultCgoStd = "c++20"

var (
	bazelSupportedLibs = []string{"googlesql", "absl", "algorithms", "base", "proto"}
	includeDirs        = []string{"protobuf", "utf8_range", "gtest", "icu", "re2", "json", "googleapis", "boringssl", "flex/src"}
	// goProtobufImportPath ensures CGO links the package that owns libprotobuf_cgo.a (prebuilt protobuf).
	goProtobufImportPath = "github.com/vantaboard/go-googlesql/internal/ccall/go-protobuf/protobuf"
	// goProtobufCCLibPkgKey is the synthetic cc_library key for internal/ccall/go-protobuf/protobuf.
	goProtobufCCLibPkgKey = "protobuf/protobuf"
	// goRootAnalyzerPublicImportPath links options.pb.cc and analyzer amalgamation for root bind.cc.
	goRootAnalyzerPublicImportPath = "github.com/vantaboard/go-googlesql/internal/ccall/go-googlesql/public/analyzer"
)

type Generator struct {
	buildFileParser                  *BuildFileParser
	cfg                              *Config
	bridge                           *Bridge
	importSymbol                     *ImportSymbol
	libMap                           map[string]*Lib
	pkgMap                           map[string]Package
	importSymbolPackageMap           map[string]Package
	containsConflictSymbolFileMap    map[string][]string
	conflictExportSuffixByFileSymbol map[string]map[string]string // file -> symbol -> suffix
	containsAddSourceFileMap         map[string]SourceConfig
	pkgToAllDeps                     map[string][]string
	internalExportNames              []string
	templates                        embed.FS
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
		buildFileParser:                  NewBuildFileParser(cfg),
		cfg:                              cfg,
		bridge:                           bridge,
		importSymbol:                     importSymbol,
		templates:                        templates,
		containsConflictSymbolFileMap:    containsConflictSymbolFileMap,
		conflictExportSuffixByFileSymbol: conflictExportSuffixByFileSymbol,
		containsAddSourceFileMap:         containsAddSourceFileMap,
		importSymbolPackageMap:           importSymbolPackageMap,
		pkgMap:                           pkgMap,
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
	// Some cc_library dirs are not regenerated from Bazel; strip stale macros so
	// single-owner protobuf + plain absl stay link-consistent across all bind.cc.
	if err := stripGoGooglesqlBindCCGoogleMacros(); err != nil {
		return err
	}
	if err := stripRootAnalyzerAmalgamationMacros(); err != nil {
		return err
	}
	dummyGo, err := g.templates.ReadFile("templates/dummy.go.tmpl")
	if err != nil {
		return err
	}
	for _, dir := range append(includeDirs, "googlesql", "absl", "algorithms", "base", "proto") {
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
		if g.linkOnlyBind(lib) {
			if err := g.generateBindGO(outputDir, lib); err != nil {
				return err
			}
		}
	}
	rootOutputDir := filepath.Join(ccallDir(), "go-googlesql")
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

// rootGoogleSQLAmalgamationLibs lists googlesql ccall libs linked into root bind.cc / bridge.h.
// googlesql/parser/parser is omitted: that package has its own bind.cc with namespace-prefix
// macros; re-including parser/export.inc in the parent TU duplicates absl flags and parser .o.
func (g *Generator) rootGoogleSQLAmalgamationLibs() []string {
	pkgs := g.pkgs()
	libs := make([]string, 0, len(pkgs))
	for _, pkg := range pkgs {
		if !strings.Contains(pkg.Name, "googlesql") {
			continue
		}
		if pkg.Name == "googlesql/parser/parser" {
			continue
		}
		libs = append(libs, pkg.Name)
	}
	return libs
}

// rootLinkOnlyPrelude returns #include lines for primary headers (same as per-package
// bind_link_only.cc.tmpl) so bridge_cc.inc sees C++ STL and API types before templates.
func (g *Generator) rootLinkOnlyPrelude(libs []string) string {
	seen := map[string]struct{}{}
	var sb strings.Builder
	for _, name := range libs {
		lib, ok := g.libMap[name]
		if !ok || !g.linkOnlyBind(lib) {
			continue
		}
		p := g.createBindCCParam(lib, true)
		for _, h := range p.Headers {
			if _, dup := seen[h]; dup {
				continue
			}
			seen[h] = struct{}{}
			sb.WriteString(fmt.Sprintf("#include \"%s\"\n", h))
		}
	}
	return sb.String()
}

func (g *Generator) generateRootBindCC(outputDir string) error {
	libs := g.rootGoogleSQLAmalgamationLibs()
	amalg, err := g.generateCCSourceByTemplate(
		"templates/root_bind.cc.tmpl",
		libs,
	)
	if err != nil {
		return err
	}
	thin, err := g.generateCCSourceByTemplate(
		"templates/root_bind_link_only.cc.tmpl",
		struct {
			Libs    []string
			Prelude string
		}{
			Libs:    libs,
			Prelude: g.rootLinkOnlyPrelude(libs),
		},
	)
	if err != nil {
		return err
	}
	merged := g.mergeLinkOnlyBindCC("googlesql", amalg, thin)
	if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), merged, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBindCC(outputDir string, lib *Lib) error {
	param := g.createBindCCParam(lib, false)
	if g.linkOnlyBind(lib) {
		amalg, err := g.generateCCSourceByTemplate("templates/bind.cc.tmpl", param)
		if err != nil {
			return err
		}
		amalg = wrapParserBindTokenDisambiguatorInclude(lib, amalg)
		linkOnlyParam := g.createBindCCParam(lib, true)
		thin, err := g.generateCCSourceByTemplate("templates/bind_link_only.cc.tmpl", linkOnlyParam)
		if err != nil {
			return err
		}
		thin = wrapParserBindTokenDisambiguatorInclude(lib, thin)
		merged := g.mergeLinkOnlyBindCC(linkOnlyParam.FQDN, amalg, thin)
		if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), merged, 0o600); err != nil {
			return err
		}
		return g.syncExportInc(outputDir, amalg)
	}
	output, err := g.generateCCSourceByTemplate("templates/bind.cc.tmpl", param)
	if err != nil {
		return err
	}
	output = wrapParserBindTokenDisambiguatorInclude(lib, output)
	if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), output, 0o600); err != nil {
		return err
	}
	return g.syncExportInc(outputDir, output)
}

// stripBindCCInner returns the body of bind.cc.tmpl / bind_link_only.cc.tmpl after the
// opening #ifndef FQDN_bind_cc / #define lines and before the closing #endif.
func stripBindCCInner(fqdn string, src []byte) []byte {
	mark := fmt.Sprintf("#define %s_bind_cc\n", fqdn)
	i := bytes.Index(src, []byte(mark))
	if i < 0 {
		return bytes.TrimSpace(src)
	}
	body := src[i+len(mark):]
	endPat := fmt.Sprintf("#endif /* %s_bind_cc */", fqdn)
	j := bytes.LastIndex(body, []byte(endPat))
	if j < 0 {
		return bytes.TrimSpace(body)
	}
	return bytes.TrimSpace(body[:j])
}

func (g *Generator) mergeLinkOnlyBindCC(fqdn string, amalg, thin []byte) []byte {
	ai := stripBindCCInner(fqdn, amalg)
	ti := stripBindCCInner(fqdn, thin)
	var sb strings.Builder
	sb.WriteString(fmt.Sprintf("#ifndef %s_bind_cc\n#define %s_bind_cc\n\n", fqdn, fqdn))
	sb.WriteString("#ifndef GOOGLESQL_LINK_ONLY_BIND\n\n")
	sb.Write(ai)
	sb.WriteString("\n\n#else /* GOOGLESQL_LINK_ONLY_BIND */\n\n")
	sb.Write(ti)
	sb.WriteString(fmt.Sprintf("\n\n#endif /* GOOGLESQL_LINK_ONLY_BIND */\n\n#endif /* %s_bind_cc */\n", fqdn))
	return []byte(sb.String())
}

func (g *Generator) linkOnlyBind(lib *Lib) bool {
	if len(g.cfg.CCLib.LinkOnlyBindPackages) == 0 {
		return false
	}
	key := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	for _, p := range g.cfg.CCLib.LinkOnlyBindPackages {
		if p == key {
			return true
		}
	}
	return false
}

// wrapParserBindTokenDisambiguatorInclude matches exportinc.wrapParserTokenDisambiguatorFlexInclude:
// parser amalgamation already includes flex_tokenizer.cc; downstream export.inc files must see
// GOOGLESQL_PARSER_AMALGAMATION_HAS_FLEX while expanding token_disambiguator.
// isGooglesqlParserPackage is true for the parser shard under googlesql/parser (not subpackages).
func isGooglesqlParserPackage(lib *Lib) bool {
	return lib.Name == "parser" && lib.BasePkg == "googlesql/parser"
}

func wrapParserBindTokenDisambiguatorInclude(lib *Lib, bindCC []byte) []byte {
	if !isGooglesqlParserPackage(lib) {
		return bindCC
	}
	const direct = `#include "go-googlesql/parser/token_disambiguator/export.inc"`
	repl := "#define GOOGLESQL_PARSER_AMALGAMATION_HAS_FLEX\n" +
		direct + "\n" +
		"#undef GOOGLESQL_PARSER_AMALGAMATION_HAS_FLEX"
	return bytes.Replace(bindCC, []byte(direct), []byte(repl), 1)
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
	libs := g.rootGoogleSQLAmalgamationLibs()
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
		g.createBindCCParam(lib, false),
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
	if g.linkOnlyBind(lib) {
		return g.generateBindGOLinkOnly(outputDir, lib)
	}
	darwinBytes, err := g.generateGoSourceByTemplate(
		"templates/bind.go.tmpl",
		g.createBindGoParamDarwin(lib),
	)
	if err != nil {
		return err
	}
	linuxBytes, err := g.generateGoSourceByTemplate(
		"templates/bind.go.tmpl",
		g.createBindGoParamLinux(lib),
	)
	if err != nil {
		return err
	}
	darwinBytes, linuxBytes, err = g.applyTierBAbslGo(outputDir, lib, darwinBytes, linuxBytes)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), darwinBytes, 0o600); err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), linuxBytes, 0o600); err != nil {
		return err
	}
	if existsFile(filepath.Join(outputDir, "bind.go")) {
		if err := os.Remove(filepath.Join(outputDir, "bind.go")); err != nil {
			return err
		}
	}
	return nil
}

// unifiedPrebuiltLibDirRel returns a ${SRCDIR}-relative path to .../go-googlesql-unified/lib.
func unifiedPrebuiltLibDirRel(outputDir string) string {
	libDir := filepath.Join(ccallDir(), "go-googlesql-unified", "lib")
	rel, err := filepath.Rel(outputDir, libDir)
	if err != nil {
		return filepath.ToSlash(filepath.Join("..", "..", "go-googlesql-unified", "lib"))
	}
	return filepath.ToSlash(rel)
}

// protobufPrebuiltLibDirRel returns a ${SRCDIR}-relative path to .../go-protobuf/protobuf/lib
// (libcxx_prebuilt.a / libcxxabi_prebuilt.a: same LLVM as libprotobuf_cgo.a and Bazel GoogleSQL .o).
func protobufPrebuiltLibDirRel(outputDir string) string {
	libDir := filepath.Join(ccallDir(), "go-protobuf", "protobuf", "lib")
	rel, err := filepath.Rel(outputDir, libDir)
	if err != nil {
		return filepath.ToSlash(filepath.Join("..", "..", "..", "go-protobuf", "protobuf", "lib"))
	}
	return filepath.ToSlash(rel)
}

func (g *Generator) bindGoParamUnifiedPrebuilt(base *BindGoParam, outputDir, platform string) *BindGoParam {
	p := *base
	p.ExtraCXXFlags = []string{"-DGOOGLESQL_LINK_ONLY_BIND"}
	rel := unifiedPrebuiltLibDirRel(outputDir)
	switch platform {
	case "linux":
		// Keep flags CGO-whitelist-friendly (avoid comma-separated -Wl groups); match
		// internal/ccall/go-googlesql-unified/googlesqlunified/bind_unified_prebuilt.go shape.
		// Link Bazel LLVM libc++ static archives so per-package cgo links do not resolve
		// -stdlib=libc++ to the host's libc++.so (ABI skew vs libgooglesql.a / libprotobuf_cgo.a).
		pbRel := protobufPrebuiltLibDirRel(outputDir)
		p.ExtraLDFlags = []string{
			"-L${SRCDIR}/" + rel,
			"-lgooglesql", "-lz", "-ldl", "-lpthread",
			"-L${SRCDIR}/" + pbRel,
			"-Wl,--start-group", "-l:libcxx_prebuilt.a", "-l:libcxxabi_prebuilt.a", "-Wl,--end-group",
		}
	case "darwin":
		p.ExtraLDFlags = []string{
			"-L${SRCDIR}/" + rel,
			"-Wl,-force_load,${SRCDIR}/" + rel + "/libgooglesql.a",
			"-lz", "-lc++",
		}
	default:
		p.ExtraLDFlags = []string{"-L${SRCDIR}/" + rel, "-lgooglesql"}
	}
	p.ImportGoLibs = appendUniqueGoImport(p.ImportGoLibs, "github.com/vantaboard/go-googlesql/internal/ccall/go-googlesql-unified/googlesqlunified")
	return &p
}

func linkOnlyUnifiedGoBuildPrefix(cfg *Config) []byte {
	if cfg.EmitTierBAbslGo {
		return []byte("//go:build googlesql_unified_prebuilt && !googlesql_tier_b_absl\n\n")
	}
	return []byte("//go:build googlesql_unified_prebuilt\n\n")
}

func (g *Generator) generateBindGOLinkOnly(outputDir string, lib *Lib) error {
	linuxBase := g.createBindGoParamLinux(lib)
	darwinBase := g.createBindGoParamDarwin(lib)
	linuxUnified := g.bindGoParamUnifiedPrebuilt(linuxBase, outputDir, "linux")
	darwinUnified := g.bindGoParamUnifiedPrebuilt(darwinBase, outputDir, "darwin")

	linuxBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", linuxBase)
	if err != nil {
		return err
	}
	darwinBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", darwinBase)
	if err != nil {
		return err
	}
	linuxUnifiedBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", linuxUnified)
	if err != nil {
		return err
	}
	darwinUnifiedBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", darwinUnified)
	if err != nil {
		return err
	}

	uniPre := linkOnlyUnifiedGoBuildPrefix(g.cfg)

	// Tier B Abseil pilot: reuse applyTierBAbslGo for the default CGO files only.
	darwinBytes, linuxBytes, err = g.applyTierBAbslGo(outputDir, lib, darwinBytes, linuxBytes)
	if err != nil {
		return err
	}
	tierBAbSLPrefix := []byte("//go:build !googlesql_tier_b_absl\n\n")
	combinedTierUni := []byte("//go:build !googlesql_tier_b_absl && !googlesql_unified_prebuilt\n\n")
	plainNoUni := []byte("//go:build !googlesql_unified_prebuilt\n\n")
	patchDefaultBuildTags := func(b []byte) []byte {
		if bytes.HasPrefix(b, tierBAbSLPrefix) {
			return append(combinedTierUni, bytes.TrimPrefix(b, tierBAbSLPrefix)...)
		}
		return append(plainNoUni, b...)
	}
	darwinBytes = patchDefaultBuildTags(darwinBytes)
	linuxBytes = patchDefaultBuildTags(linuxBytes)

	darwinUnifiedBytes = append(uniPre, darwinUnifiedBytes...)
	linuxUnifiedBytes = append(uniPre, linuxUnifiedBytes...)

	if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), darwinBytes, 0o600); err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), linuxBytes, 0o600); err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_unified_prebuilt_darwin.go"), darwinUnifiedBytes, 0o600); err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_unified_prebuilt_linux.go"), linuxUnifiedBytes, 0o600); err != nil {
		return err
	}
	if existsFile(filepath.Join(outputDir, "bind.go")) {
		if err := os.Remove(filepath.Join(outputDir, "bind.go")); err != nil {
			return err
		}
	}
	return nil
}

// tierBAbslBindParam is used with templates/bind_tier_b_absl.go.tmpl when Config.EmitTierBAbslGo is true.
type tierBAbslBindParam struct {
	Package      string
	IncludeRel   string
	LibRel       string
	AnchorSuffix string
}

func (g *Generator) applyTierBAbslGo(outputDir string, lib *Lib, darwinBytes, linuxBytes []byte) ([]byte, []byte, error) {
	if !g.cfg.EmitTierBAbslGo {
		return darwinBytes, linuxBytes, nil
	}
	includeRel, libRel, anchorSuffix, ok := tierBAbslRelPaths(outputDir)
	if !ok {
		return darwinBytes, linuxBytes, nil
	}
	prefix := []byte("//go:build !googlesql_tier_b_absl\n\n")
	darwinOut := append(prefix, darwinBytes...)
	linuxOut := append(prefix, linuxBytes...)
	pkgName := "googlesql"
	if lib != nil {
		pkgName = g.goPkgName(lib)
	}
	param := tierBAbslBindParam{
		Package:      pkgName,
		IncludeRel:   includeRel,
		LibRel:       libRel,
		AnchorSuffix: anchorSuffix,
	}
	tierBytes, err := g.generateGoSourceByTemplate("templates/bind_tier_b_absl.go.tmpl", param)
	if err != nil {
		return nil, nil, err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_tier_b_absl.go"), tierBytes, 0o600); err != nil {
		return nil, nil, err
	}
	return darwinOut, linuxOut, nil
}

func (g *Generator) generateRootBindGO(outputDir string) error {
	linuxBase := g.createRootBindGoParamLinux()
	darwinBase := g.createRootBindGoParamDarwin()
	linuxUnified := g.bindGoParamUnifiedPrebuilt(linuxBase, outputDir, "linux")
	darwinUnified := g.bindGoParamUnifiedPrebuilt(darwinBase, outputDir, "darwin")

	linuxBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", linuxBase)
	if err != nil {
		return err
	}
	darwinBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", darwinBase)
	if err != nil {
		return err
	}
	linuxUnifiedBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", linuxUnified)
	if err != nil {
		return err
	}
	darwinUnifiedBytes, err := g.generateGoSourceByTemplate("templates/bind.go.tmpl", darwinUnified)
	if err != nil {
		return err
	}

	uniPre := linkOnlyUnifiedGoBuildPrefix(g.cfg)

	darwinBytes, linuxBytes, err = g.applyTierBAbslGo(outputDir, nil, darwinBytes, linuxBytes)
	if err != nil {
		return err
	}
	tierBAbSLPrefix := []byte("//go:build !googlesql_tier_b_absl\n\n")
	combinedTierUni := []byte("//go:build !googlesql_tier_b_absl && !googlesql_unified_prebuilt\n\n")
	plainNoUni := []byte("//go:build !googlesql_unified_prebuilt\n\n")
	patchDefaultBuildTags := func(b []byte) []byte {
		if bytes.HasPrefix(b, tierBAbSLPrefix) {
			return append(combinedTierUni, bytes.TrimPrefix(b, tierBAbSLPrefix)...)
		}
		return append(plainNoUni, b...)
	}
	darwinBytes = patchDefaultBuildTags(darwinBytes)
	linuxBytes = patchDefaultBuildTags(linuxBytes)

	darwinUnifiedBytes = append(uniPre, darwinUnifiedBytes...)
	linuxUnifiedBytes = append(uniPre, linuxUnifiedBytes...)

	if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), darwinBytes, 0o600); err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), linuxBytes, 0o600); err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_unified_prebuilt_darwin.go"), darwinUnifiedBytes, 0o600); err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind_unified_prebuilt_linux.go"), linuxUnifiedBytes, 0o600); err != nil {
		return err
	}
	if existsFile(filepath.Join(outputDir, "bind.go")) {
		if err := os.Remove(filepath.Join(outputDir, "bind.go")); err != nil {
			return err
		}
	}
	if existsFile(filepath.Join(outputDir, "bind_unified_prebuilt.go")) {
		if err := os.Remove(filepath.Join(outputDir, "bind_unified_prebuilt.go")); err != nil {
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

// optionsPublicDescriptorMacrosPrelude must appear before "// include headers" for every
// googlesql/* bind.cc whose headers may include googlesql/public/options.pb.h or type.pb.h (often before
// "// include dependencies" can pull *_cc_proto/export.inc). Matches
// root_analyzer_amalgamation_macros.inc and internal/exportinc prepend*DescriptorMacros.
const optionsPublicDescriptorMacrosPrelude = `
// Descriptor table identifiers for googlesql/public/options.proto (see googlesql/public/analyzer amalgamation).
#define googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_googlesql_2fpublic_2foptions_2eproto
#define descriptor_table_googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2foptions_2eproto
#define TableStruct_googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2foptions_2eproto
// Descriptor table identifiers for googlesql/public/type.proto (same single-owner TU as options.pb.cc).
#define googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_googlesql_2fpublic_2ftype_2eproto
#define descriptor_table_googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2ftype_2eproto
#define TableStruct_googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2ftype_2eproto
// googlesql/public/proto/wire_format_annotation.proto (paired with public/proto/type_annotation in analyzer).
#define googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define descriptor_table_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
#define TableStruct_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto
// googlesql/public/proto/type_annotation.proto (extends google.protobuf.FieldOptions; single-owner TU).
#define googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define descriptor_table_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto
#define TableStruct_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto
`

// appendConflictWrappedInclude emits #include for a dependency .cc (e.g. add_sources after_includes)
// with the same #define schemas / file_default_instances wrapping as a primary amalgamation source.
func (g *Generator) appendConflictWrappedInclude(sb *strings.Builder, incPath string, fqdn string) {
	symbols, hasConflict := g.containsConflictSymbolFileMap[incPath]
	if hasConflict {
		for _, symbol := range symbols {
			rhs := fmt.Sprintf("%s_%s", fqdn, symbol)
			if g.conflictExportSuffixByFileSymbol != nil {
				if suf, ok := g.conflictExportSuffixByFileSymbol[incPath][symbol]; ok && suf != "" {
					rhs = fmt.Sprintf("%s_%s_%s", fqdn, suf, symbol)
				}
			}
			sb.WriteString(fmt.Sprintf("\n#define %s %s", symbol, rhs))
		}
	}
	sb.WriteString(fmt.Sprintf("\n#include \"%s\"\n", incPath))
	if hasConflict {
		for i := len(symbols) - 1; i >= 0; i-- {
			sb.WriteString(fmt.Sprintf("#undef %s\n", symbols[i]))
		}
	}
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

func (g *Generator) buildReplaceNameEntries(pkgKey string, linkOnly bool) []ReplaceNameEntry {
	names := append(
		append([]string{}, g.cfg.TopLevelNamespaces...),
		g.cfg.GlobalSymbols...,
	)
	// Descriptor table / PROTOBUF_INTERNAL_EXPORT_* names must match the single-owner TU
	// (go-protobuf/protobuf). Other packages link that archive; shard-prefixing these symbols
	// causes undefined references to google::protobuf::* and descriptor_table_*.
	if pkgKey == goProtobufCCLibPkgKey {
		names = append(names, g.internalExportNames...)
	}
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
	if linkOnly {
		if pkgKey == "googlesql/public/analyzer" {
			overrideBySymbol["zetasql"] = SymbolDefineOverride{
				Pkg:         pkgKey,
				Symbol:      "zetasql",
				Replacement: "googlesql",
				Comment:     "Bridge code still uses zetasql:: while Bazel libgooglesql.a exports googlesql::.",
			}
		}
	}
	excluded := map[string]struct{}{}
	for _, n := range g.cfg.CCLib.GlobalExcludeReplaceNames {
		excluded[n] = struct{}{}
	}
	if linkOnly {
		for _, e := range g.cfg.CCLib.ExcludeReplaceNames {
			if e.Pkg != pkgKey {
				continue
			}
			for _, n := range e.Names {
				excluded[n] = struct{}{}
			}
		}
	}
	out := make([]ReplaceNameEntry, 0, len(names))
	for _, name := range names {
		if _, skip := excluded[name]; skip {
			continue
		}
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

// dropCCHeadersDuplicatedInSources removes *.cc paths from the header list when the same
// path is also a Bazel src (tm_parser lists tm_parser.cc under both hdrs and srcs).
func dropCCHeadersDuplicatedInSources(headers []string, lib *Lib) []string {
	src := make(map[string]struct{}, len(lib.Sources))
	for _, s := range lib.Sources {
		src[fmt.Sprintf("%s/%s", lib.BasePkg, s)] = struct{}{}
	}
	out := make([]string, 0, len(headers))
	for _, h := range headers {
		if strings.HasSuffix(h, ".cc") {
			if _, ok := src[h]; ok {
				continue
			}
		}
		out = append(out, h)
	}
	return out
}

func (g *Generator) omitDependencyExportInclude(pkgKey, depKey string) bool {
	for _, o := range g.cfg.CCLib.OmitDependencyExportIncludes {
		if o.Pkg != pkgKey {
			continue
		}
		for _, d := range o.Deps {
			if d == depKey {
				return true
			}
		}
	}
	return false
}

func appendUniqueGoImport(imports []string, s string) []string {
	for _, x := range imports {
		if x == s {
			return imports
		}
	}
	return append(imports, s)
}

// libNeedsGoProtobufImport is true when this library's dependency graph includes the
// synthetic protobuf/protobuf cc_library (needs blank-import when bind.cc omits the protobuf dep chain).
func (g *Generator) libNeedsGoProtobufImport(lib *Lib) bool {
	seen := map[string]bool{}
	var walk func(*Lib) bool
	walk = func(l *Lib) bool {
		pn := fmt.Sprintf("%s/%s", l.BasePkg, l.Name)
		if seen[pn] {
			return false
		}
		seen[pn] = true
		for _, d := range l.Deps {
			if d.BasePkg == "protobuf" && d.Pkg == "protobuf" {
				return true
			}
			dpn := fmt.Sprintf("%s/%s", d.BasePkg, d.Pkg)
			if child, ok := g.libMap[dpn]; ok {
				if walk(child) {
					return true
				}
			}
		}
		return false
	}
	return walk(lib)
}

func (g *Generator) createBindCCParam(lib *Lib, linkOnly bool) *BindCCParam {
	param := &BindCCParam{}

	basePrefix := sanitizeIdentifier(strings.ReplaceAll(lib.BasePkg, "/", "_"))
	param.FQDN = fmt.Sprintf("%s_%s", basePrefix, sanitizeIdentifier(lib.Name))
	param.PkgPath = lib.BasePkg
	pkgKey := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	param.ReplaceNameEntries = g.buildReplaceNameEntries(pkgKey, linkOnly)
	param.PreludeBeforeHeaders = bindCCPreludeBeforeHeaders(g.cfg, lib)
	if strings.HasPrefix(lib.BasePkg, "googlesql") {
		param.PreludeBeforeHeaders += optionsPublicDescriptorMacrosPrelude
	}
	excludeAmalg := g.amalgamationExcludePaths(lib)
	excludeSrc := g.amalgamationExcludeSourcePaths(lib)
	param.Headers = dropCCHeadersDuplicatedInSources(filterStrings(lib.HeaderPaths(), excludeAmalg), lib)
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
		if addSource, exists := g.containsAddSourceFileMap[src]; exists {
			var sb strings.Builder
			for _, inc := range addSource.AfterIncludes {
				g.appendConflictWrappedInclude(&sb, inc, param.FQDN)
			}
			sourceParam.AfterIncludeHook += sb.String()
			if addSource.Source != "" {
				sourceParam.AfterIncludeHook += fmt.Sprintf("\n#include \"%s\"\n", addSource.Source)
			}
		}
		sources = append(sources, sourceParam)
	}
	param.Sources = sources
	// bridge.inc may reference types only forward-declared in catalog.h (e.g. Conversion); link-only
	// TUs need the full definitions without amalgamated .cc bodies.
	if linkOnly && pkgKey == "googlesql/public/catalog" {
		param.Headers = append(param.Headers, "googlesql/public/cast.h")
	}
	deps := make([]string, 0, len(lib.Deps))
	for _, dep := range lib.Deps {
		// Parser amalgamation inlines flex_tokenizer.{h,flex.cc,cc}; including
		// flex_tokenizer/export.inc again duplicates the TU (ABSL_FLAG + methods).
		if isGooglesqlParserPackage(lib) &&
			dep.BasePkg == lib.BasePkg && dep.Pkg == "flex_tokenizer" {
			continue
		}
		// Parser bind.cc flex_prelude amalgamates tm_lexer.cc, textmapper_lexer_adapter.cc,
		// tm_parser.cc; including tm_parser/export.inc again duplicates those TUs.
		if isGooglesqlParserPackage(lib) &&
			dep.BasePkg == lib.BasePkg && dep.Pkg == "tm_parser" {
			continue
		}
		depKey := fmt.Sprintf("%s/%s", dep.BasePkg, dep.Pkg)
		if g.omitDependencyExportInclude(pkgKey, depKey) {
			continue
		}
		// Single-owner protobuf: implementations come from go-protobuf/protobuf (prebuilt archive); omit duplicate export.inc.
		if dep.BasePkg == "protobuf" && dep.Pkg == "protobuf" {
			continue
		}
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
	// ExtraCXXFlags are emitted as extra #cgo CXXFLAGS lines (e.g. -DGOOGLESQL_LINK_ONLY_BIND).
	ExtraCXXFlags []string
	LDFlags       []string
	// ExtraLDFlags are emitted as extra #cgo LDFLAGS lines (e.g. -L/-lgooglesql).
	ExtraLDFlags  []string
	BridgeHeaders []string
	ImportGoLibs  []string
	Funcs         []Func
	ExportFuncs   []ExportFunc
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
	"case", "map", "range", "type",
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
	return defaultCgoStd
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
		"-Wno-deprecated-enum-enum-conversion",
		"-Wno-deprecated-anon-enum-enum-conversion",
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
		"-Wno-deprecated-enum-enum-conversion",
		"-Wno-deprecated-anon-enum-enum-conversion",
	}
	return g.createRootBindGoParam(cxxflags, ldflags)
}

func (g *Generator) createRootBindGoParamDarwin() *BindGoParam {
	return g.createRootBindGoParam(nil, nil)
}

func (g *Generator) createRootBindGoParam(cxxflags, ldflags []string) *BindGoParam {
	param := &BindGoParam{DebugMode: false}
	param.Pkg = "googlesql"
	param.FQDN = "googlesql"
	param.Compiler = defaultCgoStd
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
		// Parser methods use export_googlesql_parser_parser_* in parser/parser/bind_linux.go only.
		if pkg.Name == "googlesql/parser/parser" {
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
			libName := fmt.Sprintf("github.com/vantaboard/go-googlesql/internal/ccall/%s", goPkgPath)
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
		funcs, needsImportUnsafePkg := g.pkgToFuncs("googlesql", pkg)
		param.Funcs = append(param.Funcs, funcs...)
		if needsImportUnsafePkg {
			param.ImportUnsafePkg = true
		}
	}
	param.ImportGoLibs = append(param.ImportGoLibs,
		"github.com/vantaboard/go-googlesql/internal/ccall/utf8_range_link",
	)
	param.ImportGoLibs = appendUniqueGoImport(param.ImportGoLibs, goProtobufImportPath)
	param.ImportGoLibs = appendUniqueGoImport(param.ImportGoLibs, goRootAnalyzerPublicImportPath)
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
		libName := fmt.Sprintf("github.com/vantaboard/go-googlesql/internal/ccall/%s", goPkgPath)
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
	if g.libNeedsGoProtobufImport(lib) {
		param.ImportGoLibs = appendUniqueGoImport(param.ImportGoLibs, goProtobufImportPath)
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
