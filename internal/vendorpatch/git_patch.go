package vendorpatch

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"sort"
	"strings"
)

// ApplyProtobufGitPatches runs git apply on each *.patch file in
// internal/ccall/protobuf/patches/ under repoRoot, in sorted filename order.
// Patches must be unified diffs with paths relative to the repository root
// (e.g. internal/ccall/protobuf/google/protobuf/foo.h). If the patches
// directory is missing or contains no .patch files, it returns nil.
// Requires git on PATH.
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
	for _, name := range names {
		patchPath := filepath.Join(dir, name)
		if err := gitApply(repoRoot, patchPath, name); err != nil {
			return err
		}
	}
	return nil
}

func gitApply(repoRoot, patchPath, displayName string) error {
	cmd := exec.Command("git", "apply", "--whitespace=nowarn", patchPath)
	cmd.Dir = repoRoot
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
