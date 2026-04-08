// Command vendorpatch applies mechanical post-copy patches to vendored trees under
// internal/ccall: protobuf amalgamation (port_def/port_undef) then optional git patches
// (see docs/protobuf-vendoring.md).
//
// Usage: from repository root,
//
//	go run ./internal/cmd/vendorpatch
//
//	go run ./internal/cmd/vendorpatch -ccall /path/to/ccall -amalgamation-only
//
// Flags:
//
//	-ccall <path>          ccall root (default <repo>/internal/ccall)
//	-amalgamation-only     only port_def/port_undef (skip patches/*.patch)
//
// (for comparing upstream + amalgamation vs the vendored tree when generating patches)
package main

import (
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"runtime"

	"github.com/vantaboard/go-googlesql/internal/vendorpatch"
)

func repoRoot() string {
	_, file, _, _ := runtime.Caller(0)
	// internal/cmd/vendorpatch/main.go -> repo root is ../../..
	return filepath.Clean(filepath.Join(filepath.Dir(file), "..", "..", ".."))
}

func main() {
	ccallFlag := flag.String("ccall", "", "ccall root (default: <repo>/internal/ccall)")
	amalgOnly := flag.Bool("amalgamation-only", false, "only apply port_def/port_undef amalgamation (skip git apply of patches/)")
	flag.Parse()

	root := repoRoot()
	ccall := filepath.Join(root, "internal", "ccall")
	if *ccallFlag != "" {
		var err error
		ccall, err = filepath.Abs(*ccallFlag)
		if err != nil {
			fmt.Fprintf(os.Stderr, "vendorpatch: %v\n", err)
			os.Exit(1)
		}
	}
	if err := vendorpatch.ApplyProtobufAmalgamationPatches(ccall); err != nil {
		fmt.Fprintf(os.Stderr, "vendorpatch: %v\n", err)
		os.Exit(1)
	}
	if *amalgOnly {
		return
	}
	if err := vendorpatch.ApplyProtobufGitPatches(root); err != nil {
		fmt.Fprintf(os.Stderr, "vendorpatch: %v\n", err)
		os.Exit(1)
	}
}
