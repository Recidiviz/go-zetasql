package pkg

import (
	"github.com/goccy/go-yaml"
)

type Config struct {
	Dependencies                    []ThirdPartyDependency `yaml:"dependencies"`
	GlobalSymbols                   []string               `yaml:"global_symbols"`
	TopLevelNamespaces              []string               `yaml:"top_level_namespaces"`
	ConflictSymbols                 []ConflictSymbol       `yaml:"conflict_symbols"`
	AddSources                      []SourceConfig         `yaml:"add_sources"`
	ExcludeZetaSQLDirs              []string               `yaml:"exclude_zetasql_dirs"`
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
	File   string `yaml:"file"`
	Source string `yaml:"source"`
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

type CCLibConfig struct {
	Excludes                     []string                     `yaml:"excludes"`
	ExcludeAmalgamationHeaders   []AmalgamationHeaderExclude  `yaml:"exclude_amalgamation_headers"`
	ExcludeAmalgamationSources   []AmalgamationSourceExclude  `yaml:"exclude_amalgamation_sources"`
	BindCCPreludeBeforeHeaders   []BindCCPreludeBeforeHeaders `yaml:"bind_cc_prelude_before_headers"`
	SymbolDefineOverrides        []SymbolDefineOverride       `yaml:"symbol_define_overrides"`
	InjectReplaceNames           []InjectReplaceNames         `yaml:"inject_replace_names"`
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
