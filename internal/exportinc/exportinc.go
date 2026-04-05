// Package exportinc derives export.inc from bind.cc: the include prelude is everything
// after "// include headers" through the line before #include "bridge.h" (excluding blank
// lines and "//#" snippet lines), matching how CGO pulls headers without bridge symbols.
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
	prelude = prependParserExportFlexSuppress(packageDir, prelude)
	prelude = filterBisonExportDuplicateFlexTokenizer(packageDir, prelude)
	prelude = wrapUnicodeUtilsCCInclude(prelude)
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

// filterBisonExportDuplicateFlexTokenizer drops flex_tokenizer.cc from the bison generated-lib
// export prelude. The parser package bind.cc already amalgamates that TU; re-exporting it pulls
// duplicate definitions when parser includes bison's export.inc.
func filterBisonExportDuplicateFlexTokenizer(packageDir string, prelude []string) []string {
	if !strings.Contains(packageDir, "/parser/bison_parser_generated_lib") {
		return prelude
	}
	const drop = `#include "zetasql/parser/flex_tokenizer.cc"`
	out := make([]string, 0, len(prelude))
	for _, line := range prelude {
		if strings.TrimSpace(line) == drop {
			continue
		}
		out = append(out, line)
	}
	return out
}

// wrapUnicodeUtilsCCInclude guards zetasql/common/unicode_utils.cc so the public/analyzer CGO
// package can define ZETASQL_OMIT_UNICODE_UTILS_CC (see bind_cc_prelude_before_headers) and avoid
// duplicating FLAGS_zetasql_idstring_* with root bind.cc, while other TUs include the .cc as before.
func wrapUnicodeUtilsCCInclude(prelude []string) []string {
	const direct = `#include "zetasql/common/unicode_utils.cc"`
	out := make([]string, 0, len(prelude)+2)
	for _, line := range prelude {
		if strings.TrimSpace(line) == direct {
			out = append(out,
				"#ifndef ZETASQL_OMIT_UNICODE_UTILS_CC",
				direct,
				"#endif",
			)
			continue
		}
		out = append(out, line)
	}
	return out
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
