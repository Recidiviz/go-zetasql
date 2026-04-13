// Package exportinc derives export.inc from bind.cc: the include prelude is everything
// after "// include headers" through the line before #include "bridge.h" (excluding blank
// lines and "//#" snippet lines), matching how CGO pulls headers without bridge symbols.
// Link-only binds (see docs/cgo-consolidation.md) use header-only preludes; implementations
// come from libgooglesql.a / libprotobuf_cgo.a — sync export.inc after generator runs.
//
// Contract for packages whose bind.cc uses the generator template ("// include headers" … bridge.h):
//
//   - By default, export.inc repeats the full prelude (headers, sources, dependency exports),
//     wrapped in a unique include guard, so root bind.cc gets the same C++ surface as each
//     package’s bind.cc (modulo bridge).
//   - Exception — internal/ccall/go-absl/types/: export.inc lists only the "// include dependencies"
//     subsection (go-* export.inc includes). Those headers must be compiled through each package’s
//     own bind.cc; re-exporting absl types headers through export.inc pulls them into parent TUs
//     where std::optional / absl::optional aliases conflict.
//   - Section comments from bind.cc are kept when they are part of the selected prelude.
//   - Historical "#if 0" stub blocks are not preserved when syncing from bind.cc (they caused
//     duplicate closing #endif directives after dependencies moved into the prelude). Regenerate
//     stubs manually if still needed.
//
// bind.cc files without a prelude (no template block) are skipped for sync; CheckBindVsExport ignores them.
package exportinc

import (
	"bufio"
	"bytes"
	"errors"
	"fmt"
	"path/filepath"
	"strings"
)

// ErrNoPrelude means bind.cc has no usable prelude (no "// include headers" region or empty).
var ErrNoPrelude = fmt.Errorf("exportinc: no include prelude in bind.cc")

// PackageDirForGuard returns "internal/ccall/<go-pkg>/..." from an absolute package directory
// under the repository's internal/ccall tree.
func PackageDirForGuard(absPkgDir, repoRoot string) (string, error) {
	ap := filepath.Clean(absPkgDir)
	ccall := filepath.Join(repoRoot, "internal", "ccall")
	rel, err := filepath.Rel(ccall, ap)
	if err != nil {
		return "", err
	}
	if rel == ".." || strings.HasPrefix(rel, ".."+string(filepath.Separator)) {
		return "", fmt.Errorf("exportinc: %q is not under %q", absPkgDir, ccall)
	}
	return filepath.ToSlash(filepath.Join("internal", "ccall", rel)), nil
}

// GuardMacro returns the include-guard macro name for a package directory key
// (typically PackageDirForGuard's result).
func GuardMacro(packageDir string) string {
	relDir := filepath.ToSlash(packageDir)
	return strings.ToUpper(strings.NewReplacer("/", "_", "-", "_").Replace(relDir)) + "_EXPORT_H"
}

// PreludeLinesFromBindCC extracts non-blank prelude lines from bind.cc content (excluding "//#" lines).
func PreludeLinesFromBindCC(bindCC []byte) ([]string, error) {
	scanner := bufio.NewScanner(bytes.NewReader(bindCC))
	var lines []string
	inPrelude := false
	for scanner.Scan() {
		line := scanner.Text()
		switch {
		case strings.Contains(line, "// include headers"):
			inPrelude = true
		case strings.Contains(line, `#include "bridge.h"`):
			inPrelude = false
		case !inPrelude:
			continue
		case strings.HasPrefix(line, "//#"):
			continue
		case strings.TrimSpace(line) == "":
			continue
		default:
			lines = append(lines, line)
		}
	}
	if err := scanner.Err(); err != nil {
		return nil, err
	}
	if len(lines) == 0 {
		return nil, ErrNoPrelude
	}
	return lines, nil
}

// applyExportPreludePolicy applies export.inc exceptions derived from bind.cc preludes.
func applyExportPreludePolicy(packageDir string, prelude []string) []string {
	prelude = filterGoProtobufAmalgamationSingleOwner(packageDir, prelude)
	prelude = filterPublicOptionsCcProtoSourcesSingleOwner(packageDir, prelude)
	prelude = filterPublicTypeCcProtoSourcesSingleOwner(packageDir, prelude)
	prelude = filterPublicProtoTypeAnnotationCcProtoSourcesSingleOwner(packageDir, prelude)
	prelude = filterPublicAnalyzerExportIncOptionsPbSingleOwner(packageDir, prelude)
	prelude = prependPublicOptionsCcProtoDescriptorMacros(packageDir, prelude)
	prelude = prependPublicTypeCcProtoDescriptorMacros(packageDir, prelude)
	prelude = prependPublicProtoTypeAnnotationCcProtoDescriptorMacros(packageDir, prelude)
	prelude = prependParserExportFlexSuppress(packageDir, prelude)
	prelude = filterBisonExportDuplicateFlexTokenizer(packageDir, prelude)
	prelude = filterFlexTokenizerExportDuplicateSources(packageDir, prelude)
	prelude = filterParserPackageExportDuplicateFlex(packageDir, prelude)
	prelude = filterAlgorithmsUtilLinkOnlySources(packageDir, prelude)
	if !strings.Contains(packageDir, "/go-absl/types/") {
		return prelude
	}
	for i, line := range prelude {
		if strings.Contains(line, "// include dependencies") {
			return prelude[i:]
		}
	}
	return prelude
}

// filterAlgorithmsUtilLinkOnlySources drops algorithms/*.cc lines for link-only go-algorithms
// packages (cclib.link_only_bind_packages). Generator syncs export.inc from amalgamation-shaped
// bind.cc.tmpl for dependency edges; thin bind.cc is link-only. The .cc objects live in
// libgooglesql.a (com_google_cc_differential_privacy). Parent TUs must not compile those bodies
// again via export.inc.
func filterAlgorithmsUtilLinkOnlySources(packageDir string, prelude []string) []string {
	var drops []string
	switch {
	case strings.Contains(packageDir, "go-algorithms/util"):
		drops = []string{`#include "algorithms/util.cc"`}
	case strings.Contains(packageDir, "go-algorithms/distributions"):
		drops = []string{`#include "algorithms/distributions.cc"`}
	case strings.Contains(packageDir, "go-algorithms/numerical-mechanisms"):
		drops = []string{`#include "algorithms/numerical-mechanisms.cc"`}
	case strings.Contains(packageDir, "go-algorithms/rand"):
		drops = []string{`#include "algorithms/rand.cc"`}
	case strings.Contains(packageDir, "go-algorithms/go_internal/gaussian-stddev-calculator"):
		drops = []string{`#include "algorithms/internal/gaussian-stddev-calculator.cc"`}
	case strings.Contains(packageDir, "go-algorithms/go_internal/bounded-mean-ci"):
		drops = []string{`#include "algorithms/internal/bounded-mean-ci.cc"`}
	case strings.Contains(packageDir, "go-algorithms/go_internal/count-tree"):
		drops = []string{`#include "algorithms/internal/count-tree.cc"`}
	case strings.Contains(packageDir, "go-algorithms/gaussian-dp-calculator"):
		drops = []string{`#include "algorithms/gaussian-dp-calculator.cc"`}
	default:
		return prelude
	}
	dropSet := make(map[string]struct{}, len(drops))
	for _, d := range drops {
		dropSet[d] = struct{}{}
	}
	out := make([]string, 0, len(prelude))
	for _, line := range prelude {
		if _, ok := dropSet[strings.TrimSpace(line)]; ok {
			continue
		}
		out = append(out, line)
	}
	return out
}

// filterGoProtobufAmalgamationSingleOwner drops a legacy include of the removed
// go-protobuf/protobuf/export.inc from generated export.inc preludes (historical single-TU bundle).
func filterGoProtobufAmalgamationSingleOwner(packageDir string, prelude []string) []string {
	if strings.Contains(packageDir, "go-protobuf/protobuf") {
		return prelude
	}
	const includeLine = `#include "go-protobuf/protobuf/export.inc"`
	out := make([]string, 0, len(prelude))
	for _, line := range prelude {
		if strings.TrimSpace(line) == includeLine {
			continue
		}
		out = append(out, line)
	}
	return out
}

// prependPublicOptionsCcProtoDescriptorMacros inserts descriptor table #defines before
// options.pb.h so every TU that includes this export.inc resolves the same symbols as
// googlesql/public/analyzer (where options.pb.cc is amalgamated). Matches
// root_analyzer_amalgamation_macros.inc lines for googlesql/public/options.proto.
func prependPublicOptionsCcProtoDescriptorMacros(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "go-googlesql/public/options_cc_proto") {
		return prelude
	}
	const includeOpt = `#include "googlesql/public/options.pb.h"`
	out := make([]string, 0, len(prelude)+8)
	for _, line := range prelude {
		if strings.TrimSpace(line) == includeOpt {
			out = append(out,
				"// Descriptor table identifiers match googlesql/public/analyzer (options.pb.cc amalgamation).",
				"#define googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_googlesql_2fpublic_2foptions_2eproto",
				"#define descriptor_table_googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2foptions_2eproto",
				"#define TableStruct_googlesql_2fpublic_2foptions_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2foptions_2eproto",
				line,
			)
			continue
		}
		out = append(out, line)
	}
	return out
}

// filterPublicOptionsCcProtoSourcesSingleOwner removes googlesql/public/options.pb.cc from the
// export.inc prelude for go-googlesql/public/options_cc_proto. The .pb.cc is amalgamated only in
// googlesql/public/analyzer/bind.cc; including it again via export.inc duplicates extension registrations.
func filterPublicOptionsCcProtoSourcesSingleOwner(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "go-googlesql/public/options_cc_proto") {
		return prelude
	}
	out := make([]string, 0, len(prelude))
	for i := 0; i < len(prelude); i++ {
		line := prelude[i]
		if strings.TrimSpace(line) != "// include sources" {
			out = append(out, line)
			continue
		}
		out = append(out, line)
		out = append(out, "// googlesql/public/options.pb.cc is amalgamated only in googlesql/public/analyzer/bind.cc (single owner).")
		i++
		for i < len(prelude) && strings.TrimSpace(prelude[i]) != "// include dependencies" {
			t := strings.TrimSpace(prelude[i])
			if isPublicOptionsPbCcAmalgamationLine(t) {
				i++
				continue
			}
			out = append(out, prelude[i])
			i++
		}
		if i < len(prelude) {
			out = append(out, prelude[i])
		}
	}
	return out
}

func isPublicOptionsPbCcAmalgamationLine(t string) bool {
	return strings.HasPrefix(t, "#define schemas") ||
		strings.HasPrefix(t, "#define file_default_instances") ||
		t == `#include "googlesql/public/options.pb.cc"` ||
		strings.HasPrefix(t, "#undef file_default_instances") ||
		strings.HasPrefix(t, "#undef schemas")
}

func isPublicTypePbCcAmalgamationLine(t string) bool {
	return strings.HasPrefix(t, "#define schemas") ||
		strings.HasPrefix(t, "#define file_default_instances") ||
		t == `#include "googlesql/public/type.pb.cc"` ||
		strings.HasPrefix(t, "#undef file_default_instances") ||
		strings.HasPrefix(t, "#undef schemas")
}

// isAnalyzerOwnedOptionsOrTypePbCcAmalgamationLine matches conflict-wrapped amalgamation of
// options.pb.cc and/or type.pb.cc in analyzer bind.cc (stripped from analyzer/export.inc for root).
func isPublicProtoTypeAnnotationCcProtoAmalgamationLine(t string) bool {
	return strings.HasPrefix(t, "#define schemas") ||
		strings.HasPrefix(t, "#define file_default_instances") ||
		t == `#include "googlesql/public/proto/type_annotation.pb.cc"` ||
		t == `#include "googlesql/public/proto/wire_format_annotation.pb.cc"` ||
		strings.HasPrefix(t, "#undef file_default_instances") ||
		strings.HasPrefix(t, "#undef schemas")
}

func isAnalyzerOwnedOptionsOrTypePbCcAmalgamationLine(t string) bool {
	return isPublicOptionsPbCcAmalgamationLine(t) ||
		isPublicTypePbCcAmalgamationLine(t) ||
		isPublicProtoTypeAnnotationCcProtoAmalgamationLine(t)
}

// filterPublicProtoTypeAnnotationCcProtoSourcesSingleOwner removes proto/type_annotation and
// wire_format_annotation .pb.cc amalgamation from go-googlesql/public/proto/type_annotation_cc_proto.
// Both compile only in googlesql/public/analyzer/bind.cc.
func filterPublicProtoTypeAnnotationCcProtoSourcesSingleOwner(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "go-googlesql/public/proto/type_annotation_cc_proto") {
		return prelude
	}
	out := make([]string, 0, len(prelude))
	for i := 0; i < len(prelude); i++ {
		line := prelude[i]
		if strings.TrimSpace(line) != "// include sources" {
			out = append(out, line)
			continue
		}
		out = append(out, line)
		out = append(out, "// googlesql/public/proto/type_annotation.pb.cc and wire_format_annotation.pb.cc are amalgamated only in googlesql/public/analyzer/bind.cc (single owner).")
		i++
		for i < len(prelude) && strings.TrimSpace(prelude[i]) != "// include dependencies" {
			t := strings.TrimSpace(prelude[i])
			if isPublicProtoTypeAnnotationCcProtoAmalgamationLine(t) {
				i++
				continue
			}
			out = append(out, prelude[i])
			i++
		}
		if i < len(prelude) {
			out = append(out, prelude[i])
		}
	}
	return out
}

// prependPublicProtoTypeAnnotationCcProtoDescriptorMacros inserts descriptor table #defines before
// the .pb.h includes so TUs that include this export.inc match googlesql/public/analyzer.
func prependPublicProtoTypeAnnotationCcProtoDescriptorMacros(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "go-googlesql/public/proto/type_annotation_cc_proto") {
		return prelude
	}
	const (
		includeWire = `#include "googlesql/public/proto/wire_format_annotation.pb.h"`
		includeType = `#include "googlesql/public/proto/type_annotation.pb.h"`
	)
	out := make([]string, 0, len(prelude)+16)
	for _, line := range prelude {
		switch strings.TrimSpace(line) {
		case includeWire:
			out = append(out,
				"// Descriptor table identifiers match googlesql/public/analyzer (wire_format_annotation.pb.cc amalgamation).",
				"#define googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto",
				"#define descriptor_table_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto",
				"#define TableStruct_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2fproto_2fwire_5fformat_5fannotation_2eproto",
				line,
			)
		case includeType:
			out = append(out,
				"// Descriptor table identifiers match googlesql/public/analyzer (proto/type_annotation.pb.cc amalgamation).",
				"#define googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto",
				"#define descriptor_table_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto",
				"#define TableStruct_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2fproto_2ftype_5fannotation_2eproto",
				line,
			)
		default:
			out = append(out, line)
		}
	}
	return out
}

// filterPublicTypeCcProtoSourcesSingleOwner removes googlesql/public/type.pb.cc from the
// export.inc prelude for go-googlesql/public/type_cc_proto. The .pb.cc is amalgamated only in
// googlesql/public/analyzer/bind.cc; including it again via export.inc duplicates extension registrations.
func filterPublicTypeCcProtoSourcesSingleOwner(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "go-googlesql/public/type_cc_proto") {
		return prelude
	}
	out := make([]string, 0, len(prelude))
	for i := 0; i < len(prelude); i++ {
		line := prelude[i]
		if strings.TrimSpace(line) != "// include sources" {
			out = append(out, line)
			continue
		}
		out = append(out, line)
		out = append(out, "// googlesql/public/type.pb.cc is amalgamated only in googlesql/public/analyzer/bind.cc (single owner).")
		i++
		for i < len(prelude) && strings.TrimSpace(prelude[i]) != "// include dependencies" {
			t := strings.TrimSpace(prelude[i])
			if isPublicTypePbCcAmalgamationLine(t) {
				i++
				continue
			}
			out = append(out, prelude[i])
			i++
		}
		if i < len(prelude) {
			out = append(out, prelude[i])
		}
	}
	return out
}

// prependPublicTypeCcProtoDescriptorMacros inserts descriptor table #defines before
// type.pb.h so every TU that includes this export.inc resolves the same symbols as
// googlesql/public/analyzer (where type.pb.cc is amalgamated). Matches
// root_analyzer_amalgamation_macros.inc lines for googlesql/public/type.proto.
func prependPublicTypeCcProtoDescriptorMacros(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "go-googlesql/public/type_cc_proto") {
		return prelude
	}
	const includeType = `#include "googlesql/public/type.pb.h"`
	out := make([]string, 0, len(prelude)+8)
	for _, line := range prelude {
		if strings.TrimSpace(line) == includeType {
			out = append(out,
				"// Descriptor table identifiers match googlesql/public/analyzer (type.pb.cc amalgamation).",
				"#define googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_googlesql_2fpublic_2ftype_2eproto",
				"#define descriptor_table_googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_descriptor_table_googlesql_2fpublic_2ftype_2eproto",
				"#define TableStruct_googlesql_2fpublic_2ftype_2eproto googlesql_public_analyzer_TableStruct_googlesql_2fpublic_2ftype_2eproto",
				line,
			)
			continue
		}
		out = append(out, line)
	}
	return out
}

// filterPublicAnalyzerExportIncOptionsPbSingleOwner removes googlesql/public/options.pb.cc and
// googlesql/public/type.pb.cc amalgamation blocks from go-googlesql/public/analyzer/export.inc.
// Root bind.cc includes that export.inc; without this, those .pb.cc files would be compiled twice
// (root TU + analyzer package) and duplicate extension registration. The root package links the
// analyzer archive for those symbols.
func filterPublicAnalyzerExportIncOptionsPbSingleOwner(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "go-googlesql/public/analyzer") {
		return prelude
	}
	out := make([]string, 0, len(prelude))
	for i := 0; i < len(prelude); i++ {
		line := prelude[i]
		if strings.TrimSpace(line) != "// include sources" {
			out = append(out, line)
			continue
		}
		out = append(out, line)
		out = append(out, "// options/type/proto type_annotation+wire_format .pb.cc amalgamation blocks are only in analyzer bind.cc; root links that package.")
		i++
		for i < len(prelude) && strings.TrimSpace(prelude[i]) != "// include dependencies" {
			t := strings.TrimSpace(prelude[i])
			if isAnalyzerOwnedOptionsOrTypePbCcAmalgamationLine(t) {
				i++
				continue
			}
			out = append(out, prelude[i])
			i++
		}
		if i < len(prelude) {
			out = append(out, prelude[i])
		}
	}
	return out
}

// filterBisonExportDuplicateFlexTokenizer drops flex_tokenizer.cc from the bison generated-lib
// export prelude. The parser package bind.cc already amalgamates that TU; re-exporting it pulls
// duplicate definitions when parser includes bison's export.inc.
func filterBisonExportDuplicateFlexTokenizer(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "/parser/bison_parser_generated_lib") {
		return prelude
	}
	const (
		dropLegacyZetasqlInclude = `#include "zetasql/parser/flex_tokenizer.cc"`
		dropGooglesqlInclude     = `#include "googlesql/parser/flex_tokenizer.cc"`
	)
	out := make([]string, 0, len(prelude))
	for _, line := range prelude {
		t := strings.TrimSpace(line)
		if t == dropLegacyZetasqlInclude || t == dropGooglesqlInclude {
			continue
		}
		out = append(out, line)
	}
	return out
}

// filterFlexTokenizerExportDuplicateSources drops flex_tokenizer.{cc,flex.cc} from flex_tokenizer's
// export.inc. Parser bind.cc amalgamates those translation units; dependents (e.g. flex_token_provider)
// include flex_tokenizer/export.inc and would otherwise duplicate ABSL_FLAG and lexer symbols.
func filterFlexTokenizerExportDuplicateSources(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "/parser/flex_tokenizer") {
		return prelude
	}
	const (
		dropLegacyZetasqlCC   = `#include "zetasql/parser/flex_tokenizer.cc"`
		dropLegacyZetasqlFlex = `#include "zetasql/parser/flex_tokenizer.flex.cc"`
		dropGooglesqlCC       = `#include "googlesql/parser/flex_tokenizer.cc"`
		dropGooglesqlFlex     = `#include "googlesql/parser/flex_tokenizer.flex.cc"`
	)
	out := make([]string, 0, len(prelude))
	for _, line := range prelude {
		t := strings.TrimSpace(line)
		if t == dropLegacyZetasqlCC || t == dropLegacyZetasqlFlex || t == dropGooglesqlCC || t == dropGooglesqlFlex {
			continue
		}
		out = append(out, line)
	}
	note := "// flex_tokenizer.cc / flex_tokenizer.flex.cc are amalgamated in parser/bind.cc (parser prelude)."
	for i, line := range out {
		if strings.Contains(line, "// include sources") && i+1 < len(out) && !strings.Contains(out[i+1], "amalgamated in parser/bind.cc") {
			out = slicesInsert(out, i+1, note)
			break
		}
	}
	return out
}

// filterParserPackageExportDuplicateFlex used to drop flex_tokenizer.{cc,flex.cc} from
// go-googlesql/parser/parser/export.inc to avoid duplicate lexer symbols when the root and parser
// packages linked different namespace-isolated copies. Root analyzer amalgamation must still
// compile the same flex + TextMapper sources as parser/bind.cc (with root namespace macros), or
// references from bison_parser.cc / flex_tokenizer stay undefined. Parser vs root symbols do not
// unify across CGO packages, so each TU needs its own copy.
func filterParserPackageExportDuplicateFlex(packageDir string, prelude []string) []string {
	return prelude
}

func slicesInsert(s []string, at int, val string) []string {
	s = append(s, "")
	copy(s[at+1:], s[at:])
	s[at] = val
	return s
}

// prependParserExportFlexSuppress used to force SUPPRESS so flex_tokenizer.flex.cc stubs did not
// clash with flex_tokenizer.h inline stubs. Parser bind.cc no longer sets SUPPRESS (inline stubs
// are required); export.inc must match bind.cc or dependent TUs get mismatched flex linkage.
func prependParserExportFlexSuppress(packageDir string, prelude []string) []string {
	return prelude
}

// PreludeForExport returns the prelude lines that export.inc should contain (raw extraction plus policy).
func PreludeForExport(packageDir string, bindCC []byte) ([]string, error) {
	raw, err := PreludeLinesFromBindCC(bindCC)
	if err != nil {
		return nil, err
	}
	return applyExportPreludePolicy(packageDir, raw), nil
}

// FormatExportInc builds the full export.inc: include guard, prelude lines, optional balanced #if 0 block, closing #endif.
func FormatExportInc(packageDir string, preludeLines []string, ifZeroBlock []byte) []byte {
	guard := GuardMacro(packageDir)
	var out bytes.Buffer
	out.WriteString("#ifndef " + guard + "\n")
	out.WriteString("#define " + guard + "\n\n")
	for _, line := range preludeLines {
		out.WriteString(line)
		out.WriteByte('\n')
	}
	if len(ifZeroBlock) > 0 {
		out.WriteByte('\n')
		out.Write(ifZeroBlock)
		if ifZeroBlock[len(ifZeroBlock)-1] != '\n' {
			out.WriteByte('\n')
		}
	}
	out.WriteString("\n#endif\n")
	return out.Bytes()
}

// ExtractIfZeroBlock returns the first balanced "#if 0" ... "#endif" region (including nested #if),
// or nil if none.
func ExtractIfZeroBlock(exportInc []byte) []byte {
	lines := strings.Split(strings.TrimSuffix(string(exportInc), "\n"), "\n")
	for i := range lines {
		if strings.TrimSpace(lines[i]) != "#if 0" {
			continue
		}
		depth := 1
		for j := i + 1; j < len(lines); j++ {
			t := strings.TrimSpace(lines[j])
			switch {
			case strings.HasPrefix(t, "#if ") || strings.HasPrefix(t, "#ifdef ") || strings.HasPrefix(t, "#ifndef "):
				depth++
			case t == "#endif":
				depth--
				if depth == 0 {
					return []byte(strings.Join(lines[i:j+1], "\n") + "\n")
				}
			}
		}
		return nil
	}
	return nil
}

// PreludeLinesFromExportInc returns the prelude lines from an existing export.inc: content after
// the include-guard #define through either the line before #if 0 or the closing #endif.
func PreludeLinesFromExportInc(exportInc []byte) ([]string, error) {
	raw := strings.Split(strings.TrimSuffix(string(exportInc), "\n"), "\n")
	i := 0
	for i < len(raw) && !strings.HasPrefix(strings.TrimSpace(raw[i]), "#ifndef ") {
		i++
	}
	if i >= len(raw) {
		return nil, fmt.Errorf("exportinc: missing #ifndef in export.inc")
	}
	i++
	if i >= len(raw) || !strings.HasPrefix(strings.TrimSpace(raw[i]), "#define ") {
		return nil, fmt.Errorf("exportinc: missing #define after #ifndef")
	}
	i++
	for i < len(raw) && strings.TrimSpace(raw[i]) == "" {
		i++
	}
	start := i
	if start >= len(raw) {
		return nil, nil
	}
	// Prelude ends before #if 0 or before the include guard's closing #endif.
	if0 := -1
	for j := start; j < len(raw); j++ {
		if strings.TrimSpace(raw[j]) == "#if 0" {
			if0 = j
			break
		}
	}
	end := len(raw)
	if if0 >= 0 {
		end = if0
	} else {
		for end > start && strings.TrimSpace(raw[end-1]) == "" {
			end--
		}
		if end <= start || strings.TrimSpace(raw[end-1]) != "#endif" {
			return nil, fmt.Errorf("exportinc: missing closing #endif")
		}
		end-- // exclude closing #endif
	}
	out := make([]string, 0, end-start)
	for j := start; j < end; j++ {
		if strings.TrimSpace(raw[j]) == "" && j == end-1 {
			continue
		}
		out = append(out, raw[j])
	}
	// Trim trailing blank lines from prelude
	for len(out) > 0 && strings.TrimSpace(out[len(out)-1]) == "" {
		out = out[:len(out)-1]
	}
	return out, nil
}

// BuildFromBindCC creates full export.inc bytes from bind.cc.
func BuildFromBindCC(packageDir string, bindCC []byte) ([]byte, error) {
	prelude, err := PreludeForExport(packageDir, bindCC)
	if err != nil {
		return nil, err
	}
	return FormatExportInc(packageDir, prelude, nil), nil
}

// CheckBindVsExport returns nil if export.inc prelude matches bind.cc; otherwise an error describing the diff.
// If bind.cc has no standard prelude (ErrNoPrelude), verification is skipped and nil is returned.
func CheckBindVsExport(packageDir string, bindCC, exportInc []byte) error {
	want, err := PreludeForExport(packageDir, bindCC)
	if err != nil {
		if errors.Is(err, ErrNoPrelude) {
			return nil
		}
		return err
	}
	got, err := PreludeLinesFromExportInc(exportInc)
	if err != nil {
		return fmt.Errorf("parse export.inc: %w", err)
	}
	if len(want) != len(got) {
		return mismatchError(want, got)
	}
	for i := range want {
		if strings.TrimRight(want[i], "\r") != strings.TrimRight(got[i], "\r") {
			return mismatchError(want, got)
		}
	}
	return nil
}

func mismatchError(want, got []string) error {
	var b strings.Builder
	b.WriteString("prelude mismatch:\n--- bind.cc (want)\n+++ export.inc (got)\n")
	max := len(want)
	if len(got) > max {
		max = len(got)
	}
	for i := 0; i < max; i++ {
		w := ""
		if i < len(want) {
			w = want[i]
		}
		g := ""
		if i < len(got) {
			g = got[i]
		}
		if w != g {
			fmt.Fprintf(&b, "[%d] - %q\n[%d] + %q\n", i, w, i, g)
		}
	}
	return fmt.Errorf("%s", b.String())
}
