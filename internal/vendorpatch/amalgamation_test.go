package vendorpatch

import (
	"strings"
	"testing"
)

func TestApplyPortDefAmalgamationPatch_idempotent(t *testing.T) {
	const patched = `// header
// #undef.

// The definitions in this file are intended to be portable across Clang,
#ifdef GO_GOOGLESQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF
#else
body
#endif  // GO_GOOGLESQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF
`
	out, err := ApplyPortDefAmalgamationPatch(patched)
	if err != nil {
		t.Fatal(err)
	}
	if out != strings.ReplaceAll(patched, "\r\n", "\n") {
		t.Fatalf("expected no-op, got changed output")
	}
}

func TestApplyPortDefAmalgamationPatch_unpatched(t *testing.T) {
	const unpatched = `// license
// #undef.

// The definitions in this file are intended to be portable across Clang,
#define X 1
`
	out, err := ApplyPortDefAmalgamationPatch(unpatched)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(out, "GO_GOOGLESQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF") {
		t.Fatal("expected guard in output")
	}
	if !strings.Contains(out, "#define X 1") {
		t.Fatal("expected body preserved")
	}
	if !strings.HasSuffix(strings.TrimSpace(out), "#endif  // GO_GOOGLESQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF") {
		t.Fatalf("expected closing endif at end of output")
	}
}

func TestApplyPortDefAmalgamationPatch_missingAnchor(t *testing.T) {
	_, err := ApplyPortDefAmalgamationPatch(`// no body anchor here`)
	if err == nil {
		t.Fatal("expected error")
	}
}

func TestApplyPortUndefAmalgamationPatch_idempotent(t *testing.T) {
	const patched = `// license
// for more info.

#ifdef GO_GOOGLESQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF
#else
#ifndef PROTOBUF_NAMESPACE
#endif
#endif  // GO_GOOGLESQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF
`
	out, err := ApplyPortUndefAmalgamationPatch(patched)
	if err != nil {
		t.Fatal(err)
	}
	if out != strings.ReplaceAll(patched, "\r\n", "\n") {
		t.Fatalf("expected no-op")
	}
}

func TestApplyPortUndefAmalgamationPatch_unpatched(t *testing.T) {
	const unpatched = `// license
// for more info.

#ifndef PROTOBUF_NAMESPACE
#error "x"
#endif
#undef FOO
`
	out, err := ApplyPortUndefAmalgamationPatch(unpatched)
	if err != nil {
		t.Fatal(err)
	}
	if !strings.Contains(out, "GO_GOOGLESQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF") {
		t.Fatal("expected guard")
	}
	if !strings.Contains(out, "#undef FOO") {
		t.Fatal("expected body preserved")
	}
}

func TestApplyPortUndefAmalgamationPatch_missingAnchor(t *testing.T) {
	_, err := ApplyPortUndefAmalgamationPatch(`#define X`)
	if err == nil {
		t.Fatal("expected error")
	}
}

func TestApplyPortUndefAmalgamationPatch_wrongBody(t *testing.T) {
	_, err := ApplyPortUndefAmalgamationPatch(`// license
// for more info.

// not preprocessor
`)
	if err == nil {
		t.Fatal("expected error for body not starting with #ifndef/#error")
	}
}
