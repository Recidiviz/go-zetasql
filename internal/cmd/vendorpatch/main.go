// Command vendorpatch applies mechanical post-copy patches to vendored trees under
// internal/ccall (protobuf amalgamation guards; see docs/protobuf-vendoring.md).
//
// Usage: from repository root,
//
//	go run ./internal/cmd/vendorpatch
package main

import (
	"fmt"
	"os"
	"path/filepath"
	"runtime"

	"github.com/goccy/go-zetasql/internal/vendorpatch"
)

func repoRoot() string {
	_, file, _, _ := runtime.Caller(0)
	// internal/cmd/vendorpatch/main.go -> repo root is ../../..
	return filepath.Clean(filepath.Join(filepath.Dir(file), "..", "..", ".."))
}

func main() {
	ccall := filepath.Join(repoRoot(), "internal", "ccall")
	if err := vendorpatch.ApplyProtobufAmalgamationPatches(ccall); err != nil {
		fmt.Fprintf(os.Stderr, "vendorpatch: %v\n", err)
		os.Exit(1)
	}
}
