package vendorpatch

import (
	"os"
	"os/exec"
	"path/filepath"
	"strings"
	"testing"
)

func TestApplyProtobufGitPatches_noPatchesDir(t *testing.T) {
	dir := t.TempDir()
	if err := ApplyProtobufGitPatches(dir); err != nil {
		t.Fatal(err)
	}
}

func TestApplyProtobufGitPatches_emptyPatchesDir(t *testing.T) {
	dir := t.TempDir()
	mustMkdir(t, filepath.Join(dir, "internal", "ccall", "protobuf", "patches"))
	if err := ApplyProtobufGitPatches(dir); err != nil {
		t.Fatal(err)
	}
}

func TestApplyProtobufGitPatches_appliesInSortedOrder(t *testing.T) {
	if _, err := exec.LookPath("git"); err != nil {
		t.Skip("git not on PATH:", err)
	}
	dir := t.TempDir()
	target := filepath.Join(dir, "internal", "ccall", "protobuf", "test_git_patch_target.txt")
	mustMkdir(t, filepath.Dir(target))
	if err := os.WriteFile(target, []byte("alpha\n"), 0o644); err != nil {
		t.Fatal(err)
	}
	pdir := filepath.Join(dir, "internal", "ccall", "protobuf", "patches")
	mustMkdir(t, pdir)

	// Second patch (lexicographically after first) appends "gamma"; first adds "beta".
	patch1 := `diff --git a/internal/ccall/protobuf/test_git_patch_target.txt b/internal/ccall/protobuf/test_git_patch_target.txt
--- a/internal/ccall/protobuf/test_git_patch_target.txt
+++ b/internal/ccall/protobuf/test_git_patch_target.txt
@@ -1 +1,2 @@
 alpha
+beta
`
	patch2 := `diff --git a/internal/ccall/protobuf/test_git_patch_target.txt b/internal/ccall/protobuf/test_git_patch_target.txt
--- a/internal/ccall/protobuf/test_git_patch_target.txt
+++ b/internal/ccall/protobuf/test_git_patch_target.txt
@@ -1,2 +1,3 @@
 alpha
 beta
+gamma
`
	if err := os.WriteFile(filepath.Join(pdir, "01-first.patch"), []byte(patch1), 0o644); err != nil {
		t.Fatal(err)
	}
	if err := os.WriteFile(filepath.Join(pdir, "02-second.patch"), []byte(patch2), 0o644); err != nil {
		t.Fatal(err)
	}

	if err := ApplyProtobufGitPatches(dir); err != nil {
		t.Fatal(err)
	}
	got, err := os.ReadFile(target)
	if err != nil {
		t.Fatal(err)
	}
	want := "alpha\nbeta\ngamma\n"
	if string(got) != want {
		t.Fatalf("got %q want %q", string(got), want)
	}
}

func TestApplyProtobufGitPatches_applyError(t *testing.T) {
	if _, err := exec.LookPath("git"); err != nil {
		t.Skip("git not on PATH:", err)
	}
	dir := t.TempDir()
	pdir := filepath.Join(dir, "internal", "ccall", "protobuf", "patches")
	mustMkdir(t, pdir)
	if err := os.WriteFile(filepath.Join(pdir, "bad.patch"), []byte("not a valid patch\n"), 0o644); err != nil {
		t.Fatal(err)
	}
	err := ApplyProtobufGitPatches(dir)
	if err == nil {
		t.Fatal("expected error")
	}
	if !strings.Contains(err.Error(), "bad.patch") {
		t.Fatalf("error should mention patch name: %v", err)
	}
}

func mustMkdir(t *testing.T, path string) {
	t.Helper()
	if err := os.MkdirAll(path, 0o755); err != nil {
		t.Fatal(err)
	}
}
