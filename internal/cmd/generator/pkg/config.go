package pkg

import (
	"github.com/goccy/go-yaml"
)

type Config struct {
	// EmitTierBAbslGo enables Tier B Abseil link-only bind files for go-absl generator output (see docs/prebuilt-cgo.md).
	EmitTierBAbslGo                 bool                   `yaml:"emit_tier_b_absl_go"`
	Dependencies                    []ThirdPartyDependency `yaml:"dependencies"`
	GlobalSymbols                   []string               `yaml:"global_symbols"`
	TopLevelNamespaces              []string               `yaml:"top_level_namespaces"`
	ConflictSymbols                 []ConflictSymbol       `yaml:"conflict_symbols"`
	AddSources                      []SourceConfig         `yaml:"add_sources"`
	ExcludeGoogleSQLDirs            []string               `yaml:"exclude_googlesql_dirs"`
	ProtobufInternalExportNameFiles []string               `yaml:"protobuf_internal_export_name_files"`
	CCLib                           CCLibConfig            `yaml:"cclib"`
	Protoc                          []ProtocConfig         `yaml:"protoc"`
}

type ThirdPartyDependency struct {
	Name string             `yaml:"name"`
	FQDN string             `yaml:"fqdn"`
	Deps []DependencyConfig `yaml:"deps"`
}

type DependencyConfig struct {
	Base string `yaml:"base"`
	Pkg  string `yaml:"pkg"`
}

type ConflictSymbol struct {
	File           string            `yaml:"file"`
	Symbol         string            `yaml:"symbol"`
	Symbols        []string          `yaml:"symbols"`
	ExportSuffixes map[string]string `yaml:"export_suffixes"` // per-symbol suffix between FQDN and symbol (e.g. expr -> FQDN_expr_kOrderById)
}

type SourceConfig struct {
	File           string   `yaml:"file"`
	Source         string   `yaml:"source"`
	BeforeIncludes []string `yaml:"before_includes"`
	// AfterIncludes are #included immediately after #include of File (order preserved).
	AfterIncludes []string `yaml:"after_includes"`
	// FlexPrelude is emitted after BeforeIncludes and before #include of File (e.g. flex after grammar).
	FlexPrelude string `yaml:"flex_prelude,omitempty"`
}

type AmalgamationHeaderExclude struct {
	Pkg     string   `yaml:"pkg"`     // e.g. absl/types/optional (BasePkg/Name)
	Headers []string `yaml:"headers"` // e.g. absl/types/internal/optional.h as emitted by HeaderPaths
}

// AmalgamationSourceExclude drops .cc/.c sources from bind.cc amalgamation for a Bazel lib
// (paths as emitted by Lib.SourcePaths(), e.g. zetasql/parser/flex_tokenizer.flex.cc).
type AmalgamationSourceExclude struct {
	Pkg     string   `yaml:"pkg"`
	Sources []string `yaml:"sources"`
}

// BindCCPreludeBeforeHeaders is inserted immediately before the "// include headers" line
// (after GO_EXPORT / ICU rename macros). Use for ordering-sensitive includes such as generated flex.
type BindCCPreludeBeforeHeaders struct {
	Pkg   string `yaml:"pkg"`
	Lines string `yaml:"lines"`
}

// SymbolDefineOverride replaces the default #define <sym> <fqdn>_<sym> for one global symbol in a
// single package (e.g. point ZetaSqlFlexTokenizerBase at another package's mangled symbol).
type SymbolDefineOverride struct {
	Pkg         string `yaml:"pkg"`
	Symbol      string `yaml:"symbol"`
	Replacement string `yaml:"replacement"`
	Comment     string `yaml:"comment"`
}

// InjectReplaceNames inserts extra #define names (same expansion as global_symbols) immediately
// after After in the replace-name list for one package only.
type InjectReplaceNames struct {
	Pkg   string   `yaml:"pkg"`
	After string   `yaml:"after"` // symbol name to insert after (must exist in the base list)
	Names []string `yaml:"names"`
}

// ExtraBindGoImport adds a blank `_ "pkg"` import to bind_linux.go / bind_darwin.go for a
// ccall package (e.g. link protobuf utf8_range + bison flex objects into parser).
type ExtraBindGoImport struct {
	Pkg     string   `yaml:"pkg"`     // e.g. zetasql/parser/parser
	Imports []string `yaml:"imports"` // full module paths
}

// ExcludeReplaceNames omits #define lines for given symbols in one package (e.g. skip `google`
// so protobuf headers keep namespace google::protobuf and link against go-protobuf).
type ExcludeReplaceNames struct {
	Pkg   string   `yaml:"pkg"`
	Names []string `yaml:"names"`
}

// OmitDependencyExportIncludes drops go-*/export.inc lines for listed deps on one cc_library
// (e.g. wire_format is amalgamated inside type_annotation_cc_proto; skip duplicate export.inc).
type OmitDependencyExportIncludes struct {
	Pkg  string   `yaml:"pkg"`  // e.g. googlesql/public/types/type (BasePkg/Name)
	Deps []string `yaml:"deps"` // dependency package keys, same as libMap keys
}

type CCLibConfig struct {
	// GlobalExcludeReplaceNames omits #define lines for these symbol names in every
	// package (unlike exclude_replace_names which is per-pkg). Used for Tier B +
	// unified absl/google namespaces — see docs/tier-b-absl-protobuf.md.
	GlobalExcludeReplaceNames    []string                       `yaml:"global_exclude_replace_names"`
	Excludes                     []string                       `yaml:"excludes"`
	ExcludeAmalgamationHeaders   []AmalgamationHeaderExclude    `yaml:"exclude_amalgamation_headers"`
	ExcludeAmalgamationSources   []AmalgamationSourceExclude    `yaml:"exclude_amalgamation_sources"`
	BindCCPreludeBeforeHeaders   []BindCCPreludeBeforeHeaders   `yaml:"bind_cc_prelude_before_headers"`
	SymbolDefineOverrides        []SymbolDefineOverride         `yaml:"symbol_define_overrides"`
	InjectReplaceNames           []InjectReplaceNames           `yaml:"inject_replace_names"`
	ExtraBindGoImports           []ExtraBindGoImport            `yaml:"extra_bind_go_imports"`
	ExcludeReplaceNames          []ExcludeReplaceNames          `yaml:"exclude_replace_names"`
	OmitDependencyExportIncludes []OmitDependencyExportIncludes `yaml:"omit_dependency_export_includes"`
	// LinkOnlyBindPackages lists cc_library keys (BasePkg/Name, e.g. googlesql/public/analyzer) for
	// which bind.cc omits amalgamated .cc includes and dependency export.inc — intended for a future
	// prebuilt libgooglesql.a / Tier B link-only path (see docs/link-only-cgo-migration.md). Default
	// empty: no packages use this mode.
	LinkOnlyBindPackages []string `yaml:"link_only_bind_packages"`
}

type ProtocConfig struct {
	Name string   `yaml:"name"`
	Deps []string `yaml:"deps"`
}

func LoadConfig(configYAML []byte) (*Config, error) {
	var cfg Config
	if err := yaml.Unmarshal(configYAML, &cfg); err != nil {
		return nil, err
	}
	return &cfg, nil
}
