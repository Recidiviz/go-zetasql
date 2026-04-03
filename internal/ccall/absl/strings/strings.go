//go:build ignore

// Raw Abseil sources live here; the cgo package is internal/ccall/go-absl/strings.
// This file is ignored so plain Go tooling (go test ./... without treating .cc
// as illegal in a non-cgo package) skips this directory.
package strings
