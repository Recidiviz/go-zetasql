//go:build linux

package protobuf

// Default protobuf path: link Bazel-built libprotobuf_cgo.a (no amalgamated protobuf sources in this package).
// Build the archive with `make prebuilt-libs` from repo root (requires bazelisk/bazel and a
// populated GoogleSQL submodule / cache).
//
// ABI alignment: vendored internal/ccall/protobuf, regenerated internal/ccall/googlesql/**/*.pb.{h,cc},
// and libprotobuf_cgo.a from extract_protobuf_cgo_lib.sh must all track the same
// @com_google_protobuf revision (see docs/protobuf-vendoring.md and
// scripts/verify-protobuf-tier-b-alignment.sh).
//
// Linux: Bazel-built .a uses libc++ (std::__1:: / Abseil). Compile all other CGO C++ with
// CGO_CXXFLAGS=-stdlib=libc++ (see Makefile CGO_CXXFLAGS_PREBUILT) or protobuf template symbols
// from other translation units won't link (std::__cxx11:: vs std::__1::).
//
// --whole-archive: mold/ld otherwise omit .o members from the static archive and core protobuf
// APIs stay undefined. extract_protobuf_cgo_lib.sh excludes gtest-backed Abseil objects so
// whole-archive does not require libgtest.
//
// start-group/end-group: libc++ symbols such as std::__1::__hash_memory resolve when other CGO
// packages append -lstdc++ and disturb single-pass resolution. The Linux bind links libc++ /
// libc++abi copied from the same Bazel LLVM toolchain as extract_protobuf_cgo_lib.sh
// (lib/libcxx_prebuilt.a, lib/libcxxabi_prebuilt.a), because system -lc++ can mismatch the ABI tags
// used by Abseil objects inside libprotobuf_cgo.a.

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../
#cgo CXXFLAGS: -I${SRCDIR}/../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../utf8_range
#cgo LDFLAGS: -L${SRCDIR}/lib -Wl,--whole-archive -lprotobuf_cgo -Wl,--no-whole-archive -lz
#cgo LDFLAGS: -Wl,--start-group -l:libcxx_prebuilt.a -l:libcxxabi_prebuilt.a -Wl,--end-group -ldl

void __go_googlesql_protobuf_prebuilt_anchor(void) {}
*/
import "C"

import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/utf8_range_link"
)
