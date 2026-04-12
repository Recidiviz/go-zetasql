package pkg

import "testing"

func TestLibPkgKey(t *testing.T) {
	if got := LibPkgKey("zetasql/base", "refcount"); got != "googlesql/base/refcount" {
		t.Fatalf("LibPkgKey legacy BUILD root zetasql/base: got %q", got)
	}
	if got := LibPkgKey("googlesql/parser", "keywords"); got != "googlesql/parser/keywords" {
		t.Fatalf("LibPkgKey googlesql/parser: got %q", got)
	}
}

func TestTierBAbslRelPaths(t *testing.T) {
	inc, lib, anchor, ok := tierBAbslRelPaths("/home/x/internal/ccall/go-absl/base/config")
	if !ok {
		t.Fatal("expected ok")
	}
	if inc != "../../../" || lib != "../../lib" || anchor != "base_config" {
		t.Fatalf("base/config: inc=%q lib=%q anchor=%q", inc, lib, anchor)
	}
	_, _, _, ok = tierBAbslRelPaths("/home/x/internal/ccall/go-googlesql")
	if ok {
		t.Fatal("non-go-absl path should not match")
	}
}
