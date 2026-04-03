package vendorpatch

import (
	"bytes"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"sort"
	"strings"
)

// ApplyProtobufGitPatches runs git apply on each *.patch file in
// internal/ccall/protobuf/patches/ under repoRoot, in sorted filename order.
// All patches are concatenated and applied as one stream so idempotency works
// when multiple patches touch the same files. Patches must be unified diffs with
// paths relative to the repository root
// (e.g. internal/ccall/protobuf/google/protobuf/foo.h). If the patches
// directory is missing or contains no .patch files, it returns nil.
// Re-applying on a tree that already contains the patch is a no-op (detected
// via git apply --reverse --check on the combined patch). Requires git on PATH.
func ApplyProtobufGitPatches(repoRoot string) error {
	dir := filepath.Join(repoRoot, "internal", "ccall", "protobuf", "patches")
	entries, err := os.ReadDir(dir)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return fmt.Errorf("vendorpatch: read patches dir: %w", err)
	}
	var names []string
	for _, e := range entries {
		if e.IsDir() {
			continue
		}
		if strings.HasSuffix(e.Name(), ".patch") {
			names = append(names, e.Name())
		}
	}
	if len(names) == 0 {
		return nil
	}
	sort.Strings(names)

	var combined bytes.Buffer
	for _, name := range names {
		p := filepath.Join(dir, name)
		b, err := os.ReadFile(p)
		if err != nil {
			return fmt.Errorf("vendorpatch: read %s: %w", name, err)
		}
		combined.Write(b)
		if !bytes.HasSuffix(b, []byte("\n")) {
			combined.WriteByte('\n')
		}
	}

	return gitApplyCombined(repoRoot, combined.Bytes(), "patches/*.patch")
}

func gitApplyCombined(repoRoot string, patch []byte, displayName string) error {
	cmdCheck := exec.Command("git", "apply", "--check", "-")
	cmdCheck.Dir = repoRoot
	cmdCheck.Stdin = bytes.NewReader(patch)
	if err := cmdCheck.Run(); err == nil {
		return gitApplyCombinedForward(repoRoot, patch, displayName)
	}
	cmdRev := exec.Command("git", "apply", "--reverse", "--check", "-")
	cmdRev.Dir = repoRoot
	cmdRev.Stdin = bytes.NewReader(patch)
	if err := cmdRev.Run(); err == nil {
		return nil
	}
	return gitApplyCombinedForward(repoRoot, patch, displayName)
}

func gitApplyCombinedForward(repoRoot string, patch []byte, displayName string) error {
	cmd := exec.Command("git", "apply", "--whitespace=nowarn", "-")
	cmd.Dir = repoRoot
	cmd.Stdin = bytes.NewReader(patch)
	out, err := cmd.CombinedOutput()
	if err != nil {
		msg := strings.TrimSpace(string(out))
		if msg == "" {
			msg = err.Error()
		}
		return fmt.Errorf("git apply %s: %s", displayName, msg)
	}
	return nil
}
