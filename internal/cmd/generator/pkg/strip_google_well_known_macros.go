package pkg

import (
	"bufio"
	"bytes"
	"os"
	"path/filepath"
	"strings"
)

// stripGoogleWellKnownProtoAndAbslMacros removes stale namespace shims that break
// single-owner go-protobuf linking: shard #defines for absl and for google/protobuf,
// google/type, and google/rpc descriptor symbols must not appear outside the protobuf
// amalgamation TU (plain absl:: / global descriptor_table_* match libprotobuf).
func stripGoogleWellKnownProtoAndAbslMacros(path string) error {
	raw, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	out := filterBindCCLines(raw)
	if bytes.Equal(raw, out) {
		return nil
	}
	return os.WriteFile(path, out, 0o600)
}

func filterBindCCLines(src []byte) []byte {
	sc := bufio.NewScanner(bytes.NewReader(src))
	var b strings.Builder
	for sc.Scan() {
		line := sc.Text()
		if shouldDropBindCCMacroLine(line) {
			continue
		}
		b.WriteString(line)
		b.WriteByte('\n')
	}
	if err := sc.Err(); err != nil {
		return src
	}
	return []byte(b.String())
}

func shouldDropBindCCMacroLine(line string) bool {
	t := strings.TrimSpace(line)
	if !strings.HasPrefix(t, "#define ") {
		return false
	}
	// Unified absl (global_exclude_replace_names: absl)
	if strings.HasPrefix(t, "#define absl ") {
		return true
	}
	// Well-known Google protos compiled in go-protobuf only
	prefixes := []string{
		"#define google_2fprotobuf_",
		"#define descriptor_table_google_2fprotobuf_",
		"#define TableStruct_google_2fprotobuf_",
		"#define google_2ftype_",
		"#define descriptor_table_google_2ftype_",
		"#define TableStruct_google_2ftype_",
		"#define google_2frpc_",
		"#define descriptor_table_google_2frpc_",
		"#define TableStruct_google_2frpc_",
	}
	for _, p := range prefixes {
		if strings.HasPrefix(t, p) {
			return true
		}
	}
	return false
}

func stripGoGooglesqlBindCCGoogleMacros() error {
	root := filepath.Join(ccallDir(), "go-googlesql")
	return filepath.WalkDir(root, func(path string, d os.DirEntry, err error) error {
		if err != nil {
			return err
		}
		if d.IsDir() {
			return nil
		}
		if filepath.Base(path) != "bind.cc" {
			return nil
		}
		return stripGoogleWellKnownProtoAndAbslMacros(path)
	})
}

func stripRootAnalyzerAmalgamationMacros() error {
	p := filepath.Join(ccallDir(), "go-googlesql", "root_analyzer_amalgamation_macros.inc")
	return stripGoogleWellKnownProtoAndAbslMacros(p)
}
