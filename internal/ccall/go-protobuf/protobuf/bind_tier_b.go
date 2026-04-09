//go:build googlesql_tier_b && (linux || darwin)

package protobuf

// Tier B: link Bazel-built libprotobuf_cgo.a instead of compiling export.inc here.
// Build the archive: `make extract-protobuf-lib` from repo root (requires bazelisk, submodule cache).
// The extract script writes lib/$GOOS_$GOARCH/libprotobuf_cgo.a and symlinks lib/libprotobuf_cgo.a.
//
// This path does not yet provide GO_GOOGLESQL_PB_EXPORT / export_protobuf_* symbols from the
// amalgamation — use together with generator global_exclude_replace_names and a full unified
// link story (see docs/tier-b-absl-protobuf.md). The anchor only forces libprotobuf_cgo.a into the link.
//
// Linux: Bazel-built .a uses libc++ (std::__1:: / Abseil). Bare -lc++ often fails ("cannot find -lc++")
// because libdir is not on the default path — search common LLVM locations before -lc++.

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../
#cgo CXXFLAGS: -I${SRCDIR}/../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../utf8_range
#cgo linux LDFLAGS: -L/usr/lib/x86_64-linux-gnu
#cgo linux LDFLAGS: -L/usr/lib/llvm-20/lib -L/usr/lib/llvm-19/lib -L/usr/lib/llvm-18/lib -L/usr/lib/llvm-17/lib -L/usr/lib/llvm-16/lib -L/usr/lib/llvm-15/lib -L/usr/lib/llvm-14/lib
#cgo linux LDFLAGS: -L${SRCDIR}/lib -lprotobuf_cgo -lz -lc++ -lc++abi -ldl
#cgo darwin LDFLAGS: -L${SRCDIR}/lib -lprotobuf_cgo -lz -lc++

void __go_googlesql_tier_b_protobuf_anchor(void) {}
*/
import "C"

import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/utf8_range_link"
)
