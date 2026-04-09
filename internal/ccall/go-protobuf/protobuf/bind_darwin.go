//go:build darwin

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
// Darwin also uses libc++ throughout. Compile all other CGO C++ with
// CGO_CXXFLAGS=-stdlib=libc++ (see Makefile CGO_CXXFLAGS_PREBUILT) so protobuf template symbols
// match the prebuilt archive.

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../
#cgo CXXFLAGS: -I${SRCDIR}/../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../utf8_range
#cgo LDFLAGS: -L${SRCDIR}/lib -Wl,-force_load,${SRCDIR}/lib/libprotobuf_cgo.a -lz -lc++

void __go_googlesql_protobuf_prebuilt_anchor(void) {}
*/
import "C"

import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/utf8_range_link"
)
