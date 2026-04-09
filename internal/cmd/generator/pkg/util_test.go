package pkg

import "testing"

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
