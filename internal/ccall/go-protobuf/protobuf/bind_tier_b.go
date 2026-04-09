//go:build googlesql_tier_b && (linux || darwin)

package protobuf

// Tier B: link Bazel-built libprotobuf_cgo.a instead of compiling export.inc here.
// Build the archive: `make extract-protobuf-lib` from repo root (requires bazelisk, submodule cache).
// The extract script writes lib/$GOOS_$GOARCH/libprotobuf_cgo.a and symlinks lib/libprotobuf_cgo.a.
//
// ABI alignment: amalgamation and generated `*.pb.h` under internal/ccall/googlesql are built against
// vendored internal/ccall/protobuf (~4.23.x, GOOGLE_PROTOBUF_VERSION 4023003). `extract_protobuf_cgo_lib.sh`
// uses `@com_google_protobuf` from internal/cmd/updater/googlesql/MODULE.bazel (currently 29.x). That
// mix yields undefined `google::protobuf::…` at link time. Fixing it requires either refreshing the
// vendored protobuf tree + regenerating protos to match MODULE.bazel, or pinning `protobuf` in MODULE.bazel
// to the same OSS era as the vendor (older pins such as 23.1 conflict with current rules_java/grpc in the
// GoogleSQL workspace).
//
// This path does not yet provide GO_GOOGLESQL_PB_EXPORT / export_protobuf_* symbols from the
// amalgamation — use together with generator global_exclude_replace_names and a full unified
// link story (see docs/tier-b-absl-protobuf.md). The anchor only forces libprotobuf_cgo.a into the link.
//
// Linux: Bazel-built .a uses libc++ (std::__1:: / Abseil). Bare -lc++ often fails ("cannot find -lc++")
// because libdir is not on the default path — search common LLVM locations before -lc++.
// Compile all other CGO C++ with CGO_CXXFLAGS=-stdlib=libc++ (see Makefile CGO_CXXFLAGS_TIER_B) or
// protobuf template symbols from amalgamation TUs won't link (std::__cxx11:: vs std::__1::).
//
// --whole-archive: mold/ld otherwise omit .o members from the static archive and core protobuf
// APIs stay undefined. extract_protobuf_cgo_lib.sh excludes gtest-backed Abseil objects so
// whole-archive does not require libgtest.
//
// start-group/end-group: libc++ symbols such as std::__1::__hash_memory resolve when other CGO
// packages append -lstdc++ and disturb single-pass resolution.

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../
#cgo CXXFLAGS: -I${SRCDIR}/../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../utf8_range
#cgo linux LDFLAGS: -L/usr/lib/x86_64-linux-gnu
#cgo linux LDFLAGS: -L/usr/lib/llvm-20/lib -L/usr/lib/llvm-19/lib -L/usr/lib/llvm-18/lib -L/usr/lib/llvm-17/lib -L/usr/lib/llvm-16/lib -L/usr/lib/llvm-15/lib -L/usr/lib/llvm-14/lib
#cgo linux LDFLAGS: -L${SRCDIR}/lib -Wl,--whole-archive -lprotobuf_cgo -Wl,--no-whole-archive -lz
#cgo linux LDFLAGS: -Wl,--start-group -lc++ -lc++abi -Wl,--end-group -ldl
#cgo darwin LDFLAGS: -L${SRCDIR}/lib -Wl,-force_load,${SRCDIR}/lib/libprotobuf_cgo.a -lz -lc++

void __go_googlesql_tier_b_protobuf_anchor(void) {}
*/
import "C"

import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/utf8_range_link"
)
