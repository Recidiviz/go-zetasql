package pkg

import (
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strings"

	"github.com/bazelbuild/buildtools/build"
)

type Lib struct {
	BasePkg     string
	Name        string
	Headers     []string
	Sources     []string
	Deps        []Dependency
	LinkerFlags []LinkerFlag
}

func (lib *Lib) NeedsBuildConstraint() bool {
	for _, flag := range lib.LinkerFlags {
		if flag.OSType == Darwin {
			return true
		}
	}
	return false
}

func (lib *Lib) HeaderPaths() []string {
	paths := make([]string, 0, len(lib.Headers))
	for _, path := range lib.Headers {
		paths = append(paths, fmt.Sprintf("%s/%s", lib.BasePkg, path))
	}
	return paths
}

func (lib *Lib) SourcePaths() []string {
	paths := make([]string, 0, len(lib.Sources))
	for _, path := range lib.Sources {
		paths = append(paths, fmt.Sprintf("%s/%s", lib.BasePkg, path))
	}
	return paths
}

func (lib *Lib) headerOnly() bool {
	for _, src := range lib.Sources {
		if filepath.Ext(src) != ".h" {
			return false
		}
	}
	return true
}

type Dependency struct {
	Value   string
	Lib     string
	BasePkg string
	Pkg     string
}

type OSType int

const (
	Darwin  OSType = 0
	Linux   OSType = 1
	Windows OSType = 2
)

type LinkerFlag struct {
	OSType OSType
	Flag   string
}

type ParsedFile struct {
	tree     *build.File
	path     string
	pkgPath  string
	cclibs   []*Lib
	ccprotos []*Lib
}

type BuildFileParser struct {
	cfg                        *Config
	excludeLibPatterns         []*regexp.Regexp
	thirdPartyLibFQDNToNameMap map[string]string
}

func NewBuildFileParser(cfg *Config) *BuildFileParser {
	excludeLibPatterns := make([]*regexp.Regexp, 0, len(cfg.CCLib.Excludes))
	for _, pattern := range cfg.CCLib.Excludes {
		excludeLibPatterns = append(excludeLibPatterns, regexp.MustCompile(pattern))
	}
	libMap := map[string]string{}
	for _, dep := range cfg.Dependencies {
		libMap[dep.FQDN] = dep.Name
	}
	return &BuildFileParser{
		cfg:                        cfg,
		excludeLibPatterns:         excludeLibPatterns,
		thirdPartyLibFQDNToNameMap: libMap,
	}
}

func (p *BuildFileParser) getText(expr build.Expr) string {
	switch e := expr.(type) {
	case *build.Ident:
		return e.Name
	case *build.StringExpr:
		return e.Value
	}
	return ""
}

func (p *BuildFileParser) getTexts(list *build.ListExpr) []string {
	texts := make([]string, 0, len(list.List))
	for _, value := range list.List {
		texts = append(texts, p.getText(value))
	}
	return texts
}

func (p *BuildFileParser) exprTexts(expr build.Expr) []string {
	switch e := expr.(type) {
	case *build.ListExpr:
		return p.getTexts(e)
	case *build.BinaryExpr:
		texts := p.exprTexts(e.X)
		return append(texts, p.exprTexts(e.Y)...)
	}
	return nil
}

func (p *BuildFileParser) pkgPath(path string) (string, error) {
	splitted := strings.Split(filepath.Dir(path), "ccall")
	if len(splitted) != 2 {
		return "", fmt.Errorf("unexpected path %s", path)
	}
	pkgPath := strings.TrimLeft(splitted[1], "/")
	return pkgPath, nil
}

func (p *BuildFileParser) filterSource(srcs []string) []string {
	filtered := make([]string, 0, len(srcs))
	for _, src := range srcs {
		if filepath.Ext(src) == ".inc" {
			continue
		}
		filtered = append(filtered, src)
	}
	return filtered
}

func (p *BuildFileParser) Parse(path string) (*ParsedFile, error) {
	file, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("failed to read file: %w", err)
	}
	pkgPath, err := p.pkgPath(path)
	if err != nil {
		return nil, err
	}
	tree, err := build.ParseBuild(path, file)
	if err != nil {
		return nil, fmt.Errorf("failed to parse BUILD file: %w", err)
	}
	cclibs, err := p.cclibs(path, tree)
	if err != nil {
		return nil, err
	}
	ccprotos, err := p.ccprotos(path, tree)
	if err != nil {
		return nil, err
	}
	return &ParsedFile{
		tree:     tree,
		path:     path,
		pkgPath:  pkgPath,
		cclibs:   cclibs,
		ccprotos: ccprotos,
	}, nil
}

func (p *BuildFileParser) isExcludedPath(path string) bool {
	for _, dir := range p.cfg.ExcludeGoogleSQLDirs {
		if strings.Contains(path, dir) {
			return true
		}
	}
	return false
}

// filegroupsFromTree maps filegroup name -> srcs for the current BUILD file (local :label expansion).
func (p *BuildFileParser) filegroupsFromTree(tree *build.File) map[string][]string {
	out := map[string][]string{}
	for _, stmt := range tree.Stmt {
		callExpr, ok := stmt.(*build.CallExpr)
		if !ok || p.getText(callExpr.X) != "filegroup" {
			continue
		}
		var name string
		var srcs []string
		for _, item := range callExpr.List {
			assignExpr, ok := item.(*build.AssignExpr)
			if !ok {
				continue
			}
			switch p.getText(assignExpr.LHS) {
			case "name":
				name = p.getText(assignExpr.RHS)
			case "srcs":
				srcs = p.exprTexts(assignExpr.RHS)
			}
		}
		if name != "" {
			out[name] = srcs
		}
	}
	return out
}

func expandLocalHdrLabels(hdrs []string, filegroups map[string][]string) []string {
	var out []string
	for _, h := range hdrs {
		if strings.HasPrefix(h, ":") {
			key := strings.TrimPrefix(h, ":")
			if files, ok := filegroups[key]; ok {
				out = append(out, files...)
				continue
			}
			continue
		}
		out = append(out, h)
	}
	return out
}

func (p *BuildFileParser) cclibs(path string, tree *build.File) ([]*Lib, error) {
	if p.isExcludedPath(path) {
		return nil, nil
	}
	pkgPath, err := p.pkgPath(path)
	if err != nil {
		return nil, err
	}
	filegroups := p.filegroupsFromTree(tree)
	cclibs := make([]*Lib, 0, len(tree.Stmt))
	for _, stmt := range tree.Stmt {
		callExpr, ok := stmt.(*build.CallExpr)
		if !ok {
			continue
		}
		name := p.getText(callExpr.X)
		if name != "cc_library" {
			continue
		}
		cclib := &Lib{}
		cclib.BasePkg = pkgPath
		for _, item := range callExpr.List {
			assignExpr, ok := item.(*build.AssignExpr)
			if !ok {
				continue
			}
			kind := p.getText(assignExpr.LHS)
			rhs := assignExpr.RHS
			switch kind {
			case "name":
				cclib.Name = p.getText(rhs)
			case "hdrs":
				cclib.Headers = expandLocalHdrLabels(p.exprTexts(rhs), filegroups)
			case "srcs":
				cclib.Sources = p.filterSource(p.exprTexts(rhs))
			case "deps":
				deps, err := p.toDependencies(path, p.exprTexts(rhs))
				if err != nil {
					return nil, err
				}
				cclib.Deps = deps
			case "linkopts":
				callExpr, ok := rhs.(*build.CallExpr)
				if !ok {
					continue
				}
				for _, item := range callExpr.List {
					dictExpr, ok := item.(*build.DictExpr)
					if !ok {
						continue
					}
					for _, item := range dictExpr.List {
						switch item.Key.(*build.StringExpr).Value {
						case ":osx":
							cclib.LinkerFlags = append(cclib.LinkerFlags, LinkerFlag{
								OSType: Darwin,
								Flag:   strings.Join(p.getTexts(item.Value.(*build.ListExpr)), " "),
							})
						}
					}
				}
			}
		}
		if p.isExcludedLib(cclib.Name) {
			continue
		}
		if p.looksLikeDedicatedTestLib(cclib.Name, cclib.Deps) {
			continue
		}
		cclibs = append(cclibs, cclib)
	}
	return cclibs, nil
}

func (p *BuildFileParser) looksLikeDedicatedTestLib(name string, deps []Dependency) bool {
	if strings.Contains(name, "test") {
		return true
	}
	// Do not skip libs solely because they list gtest in deps — upstream often adds
	// @com_google_googletest//:gtest to non-test targets; skipping would freeze
	// bind.cc generation and omit new //googlesql/... export.inc dependencies.
	_ = deps
	return false
}

func (p *BuildFileParser) isExcludedLib(lib string) bool {
	for _, pattern := range p.excludeLibPatterns {
		if pattern.MatchString(lib) {
			return true
		}
	}
	return false
}

func (p *BuildFileParser) toDependencies(path string, values []string) ([]Dependency, error) {
	deps := make([]Dependency, 0, len(values))
	for _, value := range values {
		if p.isExcludedLib(value) {
			continue
		}
		dep := Dependency{Value: value}
		switch value[0] {
		case '@':
			if strings.Contains(value, "//") {
				splitted := strings.Split(value, "//")
				if len(splitted) != 2 {
					return nil, fmt.Errorf("failed to parse dependency of %s", value)
				}
				libFQDN := splitted[0]
				dep.Lib = p.thirdPartyLibFQDNToNameMap[libFQDN]

				pkgPath := splitted[1]
				if strings.Contains(pkgPath, ":") {
					splittedPkgPath := strings.Split(pkgPath, ":")
					if len(splittedPkgPath) != 2 {
						return nil, fmt.Errorf("failed to parse package path of %s", value)
					}
					dep.BasePkg = splittedPkgPath[0]
					dep.Pkg = splittedPkgPath[1]
				} else {
					dep.BasePkg = pkgPath
					dep.Pkg = filepath.Base(pkgPath)
				}
			} else {
				// only @xyz
				dep.BasePkg = value
				dep.Pkg = value
			}
		case ':':
			pkgPath, err := p.pkgPath(path)
			if err != nil {
				return nil, err
			}
			dep.BasePkg = pkgPath
			dep.Pkg = value[1:]
		case '/':
			if value[1] != '/' {
				return nil, fmt.Errorf("unexpected dependency value: %s", value)
			}
			pkgPath := value[2:]
			if strings.Contains(pkgPath, ":") {
				splittedPkgPath := strings.Split(pkgPath, ":")
				if len(splittedPkgPath) != 2 {
					return nil, fmt.Errorf("failed to parse package path of %s", value)
				}
				dep.BasePkg = splittedPkgPath[0]
				dep.Pkg = splittedPkgPath[1]
			} else {
				dep.BasePkg = pkgPath
				dep.Pkg = filepath.Base(pkgPath)
			}
		default:
			return nil, fmt.Errorf("unexpected dependency value: %s", value)
		}
		if dep.BasePkg == "" {
			if dep.Lib == "" {
				return nil, fmt.Errorf("failed to parse dependency: %s", value)
			}
			switch dep.Lib {
			case "googleapis", "benchmark", "json":
				// ignore googleapis/benchmark/json dependency
				continue
			}
			dep.BasePkg = dep.Lib
			dep.Pkg = dep.Lib
		}
		deps = append(deps, dep)
	}
	return deps, nil
}

func (p *BuildFileParser) ccprotos(path string, tree *build.File) ([]*Lib, error) {
	if p.isExcludedPath(path) {
		return nil, nil
	}
	pkgPath, err := p.pkgPath(path)
	if err != nil {
		return nil, err
	}
	protocMap := map[string]ProtocConfig{}
	for _, c := range p.cfg.Protoc {
		c := c
		protocMap[c.Name] = c
	}
	// protoLibraryBases maps proto_library name -> basename of each .proto (order preserved).
	protoLibraryBases := map[string][]string{}
	for _, stmt := range tree.Stmt {
		callExpr, ok := stmt.(*build.CallExpr)
		if !ok {
			continue
		}
		if p.getText(callExpr.X) != "proto_library" {
			continue
		}
		var name string
		var srcs []string
		for _, item := range callExpr.List {
			assignExpr, ok := item.(*build.AssignExpr)
			if !ok {
				continue
			}
			switch p.getText(assignExpr.LHS) {
			case "name":
				name = p.getText(assignExpr.RHS)
			case "srcs":
				srcs = p.exprTexts(assignExpr.RHS)
			}
		}
		if name == "" || len(srcs) == 0 {
			continue
		}
		bases := make([]string, 0, len(srcs))
		for _, s := range srcs {
			bases = append(bases, strings.TrimSuffix(s, ".proto"))
		}
		protoLibraryBases[name] = bases
	}
	ccprotos := make([]*Lib, 0, len(tree.Stmt))
	for _, stmt := range tree.Stmt {
		callExpr, ok := stmt.(*build.CallExpr)
		if !ok {
			continue
		}
		name := p.getText(callExpr.X)
		if name != "cc_proto_library" {
			continue
		}
		ccproto := &Lib{}
		ccproto.BasePkg = pkgPath
		for _, item := range callExpr.List {
			assignExpr, ok := item.(*build.AssignExpr)
			if !ok {
				continue
			}
			kind := p.getText(assignExpr.LHS)
			rhs := assignExpr.RHS
			switch kind {
			case "name":
				ccproto.Name = p.getText(rhs)
			}
		}
		libName := ccproto.Name[:len(ccproto.Name)-len("_cc_proto")]
		var protoBases []string
		for _, item := range callExpr.List {
			assignExpr, ok := item.(*build.AssignExpr)
			if !ok || p.getText(assignExpr.LHS) != "deps" {
				continue
			}
			for _, dep := range p.exprTexts(assignExpr.RHS) {
				if !strings.HasPrefix(dep, ":") {
					continue
				}
				if bases := protoLibraryBases[dep[1:]]; len(bases) > 0 {
					libName = bases[0]
					protoBases = bases
					break
				}
			}
		}
		if p.isExcludedLib(libName) {
			continue
		}
		pkgName := fmt.Sprintf("%s/%s", ccproto.BasePkg, ccproto.Name)
		if len(protoBases) > 0 {
			ccproto.Headers = make([]string, 0, len(protoBases))
			ccproto.Sources = make([]string, 0, len(protoBases))
			for _, b := range protoBases {
				ccproto.Headers = append(ccproto.Headers, fmt.Sprintf("%s.pb.h", b))
				ccproto.Sources = append(ccproto.Sources, fmt.Sprintf("%s.pb.cc", b))
			}
		} else {
			ccproto.Headers = []string{fmt.Sprintf("%s.pb.h", libName)}
			ccproto.Sources = []string{fmt.Sprintf("%s.pb.cc", libName)}
		}
		deps := []Dependency{}
		for _, dep := range protocMap[pkgName].Deps {
			dep := dep
			deps = append(deps, Dependency{
				Value:   dep,
				Lib:     "googlesql",
				BasePkg: filepath.Dir(dep),
				Pkg:     filepath.Base(dep),
			})
		}
		deps = append(deps, Dependency{
			Value:   "protobuf/protobuf",
			Lib:     "protobuf",
			BasePkg: "protobuf",
			Pkg:     "protobuf",
		})
		ccproto.Deps = deps
		ccprotos = append(ccprotos, ccproto)
	}
	return ccprotos, nil
}
