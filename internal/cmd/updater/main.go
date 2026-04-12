package main

import (
	"flag"
	"io"
	"io/fs"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"strings"

	cp "github.com/otiai10/copy"
)

// When GO_GOOGLESQL_SKIP_PROTOBUF_COPY=1, do not copy com_google_protobuf from the
// Bazel external tree into internal/ccall/protobuf. Use this when upgrading
// GoogleSQL sources while keeping the existing protobuf vendoring + export.inc in sync.
func copyExternalLibMapForRun() map[string]string {
	if os.Getenv("GO_GOOGLESQL_SKIP_PROTOBUF_COPY") == "1" {
		m := make(map[string]string, len(copyExternalLibMap))
		for k, v := range copyExternalLibMap {
			if k == "com_google_protobuf/src" {
				continue
			}
			m[k] = v
		}
		return m
	}
	return copyExternalLibMap
}

func pkgDir() string {
	_, file, _, _ := runtime.Caller(0)
	return filepath.Dir(file)
}

func repoRootDir() string {
	path, _ := filepath.Abs(filepath.Join(pkgDir(), "..", "..", ".."))
	return path
}

func internalDir() string {
	return filepath.Join(repoRootDir(), "internal")
}

func ccallDir() string {
	return filepath.Join(internalDir(), "ccall")
}

func cacheDir() string {
	return filepath.Join(pkgDir(), "cache")
}

func externalDir() string {
	return filepath.Join(cacheDir(), "external")
}

// execrootRoot returns the Bazel execroot directory for the vendored SQL engine
// workspace. Upstream renamed the module to googlesql; older caches may still use
// com_google_zetasql.
func execrootRoot() string {
	root := filepath.Join(cacheDir(), "execroot")
	for _, name := range []string{"googlesql", "com_google_googlesql", "com_google_zetasql"} {
		p := filepath.Join(root, name)
		if st, err := os.Stat(p); err == nil && st.IsDir() {
			return p
		}
	}
	return filepath.Join(root, "googlesql")
}

func bazelBinDir() string {
	return filepath.Join(execrootRoot(), "bazel-out", "k8-fastbuild", "bin")
}

func outExternalDir() string {
	return filepath.Join(bazelBinDir(), "external")
}

func appendLineIfMissing(path string, needle string, insertAfter string) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	content := string(data)
	if strings.Contains(content, needle) {
		return nil
	}
	idx := strings.Index(content, insertAfter)
	if idx == -1 {
		return nil
	}
	idx += len(insertAfter)
	content = content[:idx] + "\n" + needle + content[idx:]
	return os.WriteFile(path, []byte(content), 0o644)
}

func replaceIfMissing(path string, old string, new string) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	content := string(data)
	if strings.Contains(content, new) {
		return nil
	}
	if !strings.Contains(content, old) {
		return nil
	}
	content = strings.Replace(content, old, new, 1)
	return os.WriteFile(path, []byte(content), 0o644)
}

// Maintainer notes on vendored protobuf/third-party patches: docs/protobuf-vendoring.md
func applyPostCopyOverlays() error {
	if err := replaceIfMissing(
		filepath.Join(ccallDir(), "googlesql", "public", "functions", "date_time_util.cc"),
		`  return MakeEvalError() << "Converting timestamp interval " << interval
                         << " at " << TimestampScale_Name(interval_scale)
                         << " scale to " << TimestampScale_Name(output_scale)
                         << " scale causes overflow";
}`,
		`  return MakeEvalError() << "Converting timestamp interval " << interval
                         << " at " << TimestampScale_Name(interval_scale)
                         << " scale to " << TimestampScale_Name(output_scale)
                         << " scale causes overflow";
}
#undef FCT`,
	); err != nil {
		return err
	}
	if err := appendLineIfMissing(
		filepath.Join(ccallDir(), "googlesql", "public", "types", "BUILD"),
		`        "//googlesql/public/proto:wire_format_annotation_cc_proto",`,
		`        "//googlesql/public/functions:rounding_mode_cc_proto",`,
	); err != nil {
		return err
	}
	// Upstream googlesql/public/BUILD omits :sql_tvf next to public/types in one cc_library; go-googlesql
	// needs it for TVF-related sources pulled into the amalgamation.
	if err := replaceIfMissing(
		filepath.Join(ccallDir(), "googlesql", "public", "BUILD"),
		`        "//googlesql/proto:simple_property_graph_cc_proto",
        "//googlesql/public/proto:type_annotation_cc_proto",
        "//googlesql/public/types",
        "//googlesql/resolved_ast",
        "//googlesql/resolved_ast:resolved_ast_cc_proto",`,
		`        "//googlesql/proto:simple_property_graph_cc_proto",
        "//googlesql/public/proto:type_annotation_cc_proto",
        "//googlesql/public/types",
        ":sql_tvf",
        "//googlesql/resolved_ast",
        "//googlesql/resolved_ast:resolved_ast_cc_proto",`,
	); err != nil {
		return err
	}
	if err := replaceIfMissing(
		filepath.Join(ccallDir(), "icu", "common", "bytesinkutil.h"),
		`#include "unicode/utypes.h"
`,
		`#ifndef GO_GOOGLESQL_ICU_COMMON_BYTESINKUTIL_H_
#define GO_GOOGLESQL_ICU_COMMON_BYTESINKUTIL_H_

#include "unicode/utypes.h"
`,
	); err != nil {
		return err
	}
	if err := replaceIfMissing(
		filepath.Join(ccallDir(), "icu", "common", "bytesinkutil.h"),
		"U_NAMESPACE_END\n",
		`U_NAMESPACE_END

#endif  // GO_GOOGLESQL_ICU_COMMON_BYTESINKUTIL_H_
`,
	); err != nil {
		return err
	}
	// options.pb.h may lag options.proto for new LanguageFeature values; use numeric id 102 ==
	// FEATURE_ENABLE_ALTER_ARRAY_OPTIONS until protos are regenerated in lockstep.
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "bison_parser.cc"),
		"FEATURE_ENABLE_ALTER_ARRAY_OPTIONS",
		"static_cast<::zetasql::LanguageFeature>(102)",
	); err != nil {
		return err
	}
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.cc"),
		"FEATURE_ENABLE_ALTER_ARRAY_OPTIONS",
		"static_cast<::zetasql::LanguageFeature>(102)",
	); err != nil {
		return err
	}
	// Generated flex may set yyFlexLexer=ZetaSqlFlexLexer; flex_tokenizer.h expects GoogleSqlFlexTokenizerBase.
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.flex.cc"),
		"    #define yyFlexLexer ZetaSqlFlexLexer",
		`#ifndef yyFlexLexer
    #define yyFlexLexer GoogleSqlFlexTokenizerBase
#endif`,
	); err != nil {
		return err
	}
	// bind.cc includes flex_tokenizer.h first (FlexLexer.h once); drop duplicate #include only.
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.flex.cc"),
		`#define yytext_ptr yytext

#include <FlexLexer.h>

int yyFlexLexer::yywrap()`,
		`#define yytext_ptr yytext

int yyFlexLexer::yywrap()`,
	); err != nil {
		return err
	}
	// With %option yyclass="FlexTokenizer", yyFlexLexer stub definitions conflict with
	// YY_DECL; flex_tokenizer.h supplies inline stubs unless SUPPRESS is set (see generator).
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.flex.cc"),
		`int yyFlexLexer::yywrap() { return 1; }
int yyFlexLexer::yylex()
	{
	LexerError( "yyFlexLexer::yylex invoked but %option yyclass used" );
	return 0;
	}

#define YY_DECL int FlexTokenizer::yylex()`,
		``,
	); err != nil {
		return err
	}
	// Bazel/flex may leave a stray YY_DECL before the tables; flex_tokenizer.cc.inc redefines it.
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.flex.cc"),
		`#define YY_DECL int FlexTokenizer::yylex()`,
		``,
	); err != nil {
		return err
	}
	// Out-of-line ctor/dtor names must match the renamed lexer class (yyFlexLexer macro is unreliable here).
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.flex.cc"),
		`GoogleSqlFlexTokenizerBase::yyFlexLexer(`,
		`GoogleSqlFlexTokenizerBase::GoogleSqlFlexTokenizerBase(`,
	); err != nil {
		return err
	}
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.flex.cc"),
		`GoogleSqlFlexTokenizerBase::~yyFlexLexer(`,
		`GoogleSqlFlexTokenizerBase::~GoogleSqlFlexTokenizerBase(`,
	); err != nil {
		return err
	}
	// Stubs conflict with flex-generated yylex when amalgamated after flex_tokenizer.flex.cc.
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "flex_tokenizer.h"),
		`// This incantation is necessary because for some reason these functions are not
// generated for GoogleSqlFlexTokenizerBase, but the class does reference them.
inline int GoogleSqlFlexTokenizerBase::yylex() { return 0; }
inline int GoogleSqlFlexTokenizerBase::yywrap() { return 1; }

#endif  // GOOGLESQL_PARSER_FLEX_TOKENIZER_H_`,
		`// This incantation is necessary because for some reason these functions are not
// generated for GoogleSqlFlexTokenizerBase, but the class does reference them.
#ifndef GOOGLESQL_PARSER_FLEX_TOKENIZER_SUPPRESS_FLEXLEXER_STUBS
inline int GoogleSqlFlexTokenizerBase::yylex() { return 0; }
inline int GoogleSqlFlexTokenizerBase::yywrap() { return 1; }
#endif

#endif  // GOOGLESQL_PARSER_FLEX_TOKENIZER_H_`,
	); err != nil {
		return err
	}
	// ASTOptionsEntry dropped GetSQLForOperator upstream; options entries use " = " between name and value.
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "unparser.cc"),
		`UnparseChildrenWithSeparator(node, data, node->GetSQLForOperator());`,
		`UnparseChildrenWithSeparator(node, data, " = ");`,
	); err != nil {
		return err
	}
	// Until bison/flex are regenerated together with keywords.cc, drop "project" (KW_PROJECT).
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "keywords.cc"),
		"    {\"project\", KW_PROJECT},\n",
		"",
	); err != nil {
		return err
	}
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "parser", "parse_tree.cc"),
		`

std::string ASTOptionsEntry::GetSQLForOperator() const {
  switch (assignment_op_) {
    case NOT_SET:
      return "<UNKNOWN OPERATOR>";
    case ASSIGN:
      return "=";
    case ADD_ASSIGN:
      return "+=";
    case SUB_ASSIGN:
      return "-=";
  }
}
`,
		"",
	); err != nil {
		return err
	}
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "public", "types", "proto_type.cc"),
		"  value_proto->set_proto_value(GetCordValue(value));",
		"  value_proto->set_proto_value(std::string(GetCordValue(value)));",
	); err != nil {
		return err
	}
	if err := replaceAllInFile(
		filepath.Join(ccallDir(), "googlesql", "public", "types", "proto_type.cc"),
		"  value->set(new internal::ProtoRep(this, value_proto.proto_value()));",
		"  value->set(\n      new internal::ProtoRep(this, absl::Cord(value_proto.proto_value())));",
	); err != nil {
		return err
	}
	return nil
}

func replaceAllInFile(path, old, new string) error {
	b, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	s := string(b)
	if !strings.Contains(s, old) {
		return nil
	}
	return os.WriteFile(path, []byte(strings.ReplaceAll(s, old, new)), 0o644)
}

// copyZetasqlGeneratedIntoGooglesqlGaps copies Bazel //zetasql outputs into internal/ccall/googlesql
// only when the destination path does not already exist. The primary googlesql copy wins on
// conflicts; this pass supplies zetasql-only artifacts (e.g. flex/bison) merged into one tree.
func copyZetasqlGeneratedIntoGooglesqlGaps() error {
	root := filepath.Join(bazelBinDir(), "zetasql")
	if _, err := os.Stat(root); err != nil {
		return nil
	}
	return filepath.Walk(root, func(path string, info fs.FileInfo, err error) error {
		if err != nil {
			return err
		}
		if info.IsDir() {
			return nil
		}
		if (info.Mode() & fs.ModeSymlink) != 0 {
			return nil
		}
		fileName := filepath.Base(path)
		if len(fileName) == 0 {
			return nil
		}
		lastChar := fileName[len(fileName)-1]
		if lastChar != 'h' && lastChar != 'c' {
			return nil
		}
		rel, err := filepath.Rel(root, path)
		if err != nil {
			return err
		}
		dstFile := filepath.Join(ccallDir(), "googlesql", rel)
		if _, err := os.Stat(dstFile); err == nil {
			return nil
		}
		src, err := os.Open(path)
		if err != nil {
			return err
		}
		defer src.Close()
		if err := os.MkdirAll(filepath.Dir(dstFile), 0o755); err != nil {
			return err
		}
		dst, err := os.Create(dstFile)
		if err != nil {
			return err
		}
		defer dst.Close()
		_, err = io.Copy(dst, src)
		return err
	})
}

var copyExternalLibMap = map[string]string{
	"icu/source":                "icu",
	"json":                      "json",
	"flex":                      "flex",
	"com_google_absl/absl":      "absl",
	"com_google_protobuf/src":   "protobuf",
	"com_googlesource_code_re2": "re2",
	"com_google_cc_differential_privacy/algorithms": "algorithms",
	"com_google_cc_differential_privacy/base":       "base",
	"com_google_cc_differential_privacy/proto":      "proto",
	"com_google_differential_privacy/proto":         "proto",
}

var copyOutExternalLibMap = map[string]string{
	"com_google_googleapis":                 "googleapis",
	"com_google_differential_privacy/proto": "proto",
}

func main() {
	noOverlays := flag.Bool("no-overlays", false, "skip post-copy string overlays on internal/ccall (raw upstream + Bazel copy only)")
	noVendorpatch := flag.Bool("no-vendorpatch", false, "skip internal/cmd/vendorpatch (protobuf amalgamation + patches/*.patch); use with -no-overlays for a full raw tree")
	flag.Parse()

	opt := cp.Options{
		AddPermission: 0o755,
		Skip: func(src string) (bool, error) {
			info, err := os.Stat(src)
			if err != nil {
				return false, err
			}
			if info.IsDir() {
				return false, nil
			}
			switch filepath.Base(src) {
			case "BUILD", "BUILD.bazel":
				return false, nil
			}
			switch filepath.Ext(src) {
			case ".h", ".hh", ".cc", ".c", ".inc":
				return false, nil
			}
			return true, nil
		},
	}
	for src, dst := range copyExternalLibMapForRun() {
		cp.Copy(
			filepath.Join(externalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	for src, dst := range copyOutExternalLibMap {
		cp.Copy(
			filepath.Join(outExternalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	cp.Copy(
		filepath.Join(pkgDir(), "googlesql", "googlesql"),
		filepath.Join(ccallDir(), "googlesql"),
		opt,
	)
	copyBazelGenerated := func(binSegment, legacySubdir string) error {
		root := filepath.Join(bazelBinDir(), binSegment)
		if _, err := os.Stat(root); err != nil {
			return nil
		}
		return filepath.Walk(root, func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return err
			}
			if info.IsDir() {
				return nil
			}
			if (info.Mode() & fs.ModeSymlink) != 0 {
				return nil
			}
			fileName := filepath.Base(path)
			if len(fileName) == 0 {
				return nil
			}
			lastChar := fileName[len(fileName)-1]
			if lastChar != 'h' && lastChar != 'c' {
				return nil
			}
			rel, err := filepath.Rel(root, path)
			if err != nil {
				return err
			}
			var dstFile string
			if legacySubdir == "" {
				dstFile = filepath.Join(ccallDir(), "googlesql", rel)
			} else {
				dstFile = filepath.Join(ccallDir(), "googlesql", legacySubdir, rel)
			}
			src, err := os.Open(path)
			if err != nil {
				return err
			}
			defer src.Close()
			if err := os.MkdirAll(filepath.Dir(dstFile), 0o755); err != nil {
				return err
			}
			if err := os.Remove(dstFile); err != nil && !os.IsNotExist(err) {
				return err
			}
			dst, err := os.Create(dstFile)
			if err != nil {
				return err
			}
			defer dst.Close()
			if _, err := io.Copy(dst, src); err != nil {
				return err
			}
			return nil
		})
	}
	if err := copyBazelGenerated("googlesql", ""); err != nil {
		panic(err)
	}
	if err := copyZetasqlGeneratedIntoGooglesqlGaps(); err != nil {
		panic(err)
	}
	if !*noOverlays {
		if err := applyPostCopyOverlays(); err != nil {
			panic(err)
		}
	}
	if !*noVendorpatch {
		if err := runVendorpatchCLI(); err != nil {
			panic(err)
		}
	}
}

// runVendorpatchCLI applies protobuf amalgamation patches via the root module's
// internal/cmd/vendorpatch (same logic as scripts/apply-vendor-patches.sh). The
// updater lives in a nested module and cannot import internal/vendorpatch directly.
func runVendorpatchCLI() error {
	cmd := exec.Command("go", "run", filepath.Join(repoRootDir(), "internal/cmd/vendorpatch"))
	cmd.Dir = repoRootDir()
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.Env = os.Environ()
	return cmd.Run()
}
