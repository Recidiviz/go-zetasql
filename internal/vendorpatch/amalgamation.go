// Package vendorpatch applies go-zetasql-specific mechanical patches to vendored
// third-party trees (see docs/protobuf-vendoring.md).
package vendorpatch

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

const (
	portDefMarker   = "GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF"
	portUndefMarker = "GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF"

	portDefBodyPrefix = "// The definitions in this file are intended to be portable"

	portDefGuardOpen = `// go-zetasql: in amalgamation.cc / export.inc, port_def is included once at
// the start of the TU; subsequent includes from headers skip the body.
#ifdef GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF
#else

`

	portDefGuardClose = `
#endif  // GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF
`

	portUndefAnchorSuffix = "// for more info.\n"

	portUndefGuardOpen = `// go-zetasql: skip intermediate undefs in amalgamation (export.inc does one
// final port_undef at the end of the TU).
#ifdef GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF
#else

`

	portUndefGuardClose = `
#endif  // GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF
`
)

// ApplyPortDefAmalgamationPatch wraps google/protobuf/port_def.inc for single-TU
// amalgamation. Idempotent if the marker is already present.
func ApplyPortDefAmalgamationPatch(content string) (string, error) {
	content = strings.ReplaceAll(content, "\r\n", "\n")
	if strings.Contains(content, portDefMarker) {
		return content, nil
	}
	insert := strings.Index(content, "\n\n"+portDefBodyPrefix)
	if insert == -1 {
		return "", fmt.Errorf("port_def.inc: missing anchor before body (expected blank line then %q)", portDefBodyPrefix)
	}
	insert += 2 // past \n\n, at start of portDefBodyPrefix line
	out := content[:insert] + portDefGuardOpen + content[insert:] + portDefGuardClose
	return out, nil
}

// ApplyPortUndefAmalgamationPatch wraps google/protobuf/port_undef.inc for
// single-TU amalgamation. Idempotent if the marker is already present.
func ApplyPortUndefAmalgamationPatch(content string) (string, error) {
	content = strings.ReplaceAll(content, "\r\n", "\n")
	if strings.Contains(content, portUndefMarker) {
		return content, nil
	}
	if !strings.Contains(content, portUndefAnchorSuffix) {
		return "", fmt.Errorf("port_undef.inc: missing anchor %q", strings.TrimSuffix(portUndefAnchorSuffix, "\n"))
	}
	// Body starts after license block: "// for more info.\n\n" then #ifndef or #error.
	const needle = portUndefAnchorSuffix + "\n"
	idx := strings.Index(content, needle)
	if idx == -1 {
		return "", fmt.Errorf("port_undef.inc: expected blank line after %q", strings.TrimSuffix(portUndefAnchorSuffix, "\n"))
	}
	insert := idx + len(needle)
	if insert >= len(content) {
		return "", fmt.Errorf("port_undef.inc: unexpected EOF after anchor")
	}
	rest := strings.TrimLeft(content[insert:], " \t")
	if !strings.HasPrefix(rest, "#ifndef") && !strings.HasPrefix(rest, "#error") {
		return "", fmt.Errorf("port_undef.inc: body after intro must start with #ifndef or #error, got %.40q", rest)
	}
	out := content[:insert] + portUndefGuardOpen + content[insert:] + portUndefGuardClose
	return out, nil
}

// ApplyProtobufAmalgamationPatches rewrites port_def.inc and port_undef.inc under
// ccallRoot/protobuf/google/protobuf/. Writes files only when content changes.
func ApplyProtobufAmalgamationPatches(ccallRoot string) error {
	base := filepath.Join(ccallRoot, "protobuf", "google", "protobuf")
	for _, pair := range []struct {
		name string
		fn   func(string) (string, error)
	}{
		{"port_def.inc", ApplyPortDefAmalgamationPatch},
		{"port_undef.inc", ApplyPortUndefAmalgamationPatch},
	} {
		path := filepath.Join(base, pair.name)
		data, err := os.ReadFile(path)
		if err != nil {
			return fmt.Errorf("vendorpatch: read %s: %w", path, err)
		}
		out, err := pair.fn(string(data))
		if err != nil {
			return fmt.Errorf("vendorpatch: %s: %w", pair.name, err)
		}
		if out == string(data) {
			continue
		}
		if err := os.WriteFile(path, []byte(out), 0o644); err != nil {
			return fmt.Errorf("vendorpatch: write %s: %w", path, err)
		}
	}
	return nil
}
