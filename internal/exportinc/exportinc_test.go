package exportinc

import (
	"strings"
	"testing"
)

func TestPreludeLinesFromBindCC(t *testing.T) {
	bind := `
// include headers
#include "a.h"
// include sources
#include "a.cc"

// include dependencies
#include "dep/export.inc"

#include "bridge.h"
`
	got, err := PreludeLinesFromBindCC([]byte(bind))
	if err != nil {
		t.Fatal(err)
	}
	want := []string{
		`#include "a.h"`,
		`// include sources`,
		`#include "a.cc"`,
		`// include dependencies`,
		`#include "dep/export.inc"`,
	}
	if len(got) != len(want) {
		t.Fatalf("got %v want %v", got, want)
	}
	for i := range want {
		if got[i] != want[i] {
			t.Fatalf("line %d: got %q want %q", i, got[i], want[i])
		}
	}
}

func TestExtractIfZeroBlock(t *testing.T) {
	src := `#ifndef X
#define X
#include "a.h"
#if 0
nested
#if 1
inner
#endif
tail
#endif
#include "after.h"
#endif
`
	block := ExtractIfZeroBlock([]byte(src))
	if block == nil {
		t.Fatal("expected block")
	}
	if !strings.Contains(string(block), "nested") || !strings.Contains(string(block), "#endif") {
		t.Fatalf("block: %q", block)
	}
	if strings.Contains(string(block), "after.h") {
		t.Fatal("block should not include trailing includes")
	}
}

func TestGuardMacro(t *testing.T) {
	g := GuardMacro("internal/ccall/go-absl/base/config")
	if g != "INTERNAL_CCALL_GO_ABSL_BASE_CONFIG_EXPORT_H" {
		t.Fatalf("got %q", g)
	}
}
