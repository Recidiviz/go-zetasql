//go:build !googlesql_tier_b

package protobuf

// Protobuf is compiled via export.inc (single TU). Optional libprotobuf_cgo.a from
// extract_protobuf_cgo_lib.sh is not linked here by default; see docs/protobuf-vendoring.md.
//
// cgo-invalidate: 20260408n — bump this when editing vendored C++ under internal/ccall/protobuf/
// (Go does not track #included .cc files; changing only those will not rebuild the TU).
//
// Linux: the previous flag set mixed Clang-only -Wno options (e.g. -Wno-unknown-warning-option,
// -Wno-macro-redefined) with GCC, which then printed "unrecognized command-line option" and noisy
// notes. This file uses GCC-supported names (e.g. -Wno-builtin-macro-redefined) and -Wno-attributes
// for protobuf always_inline / -Wattributes noise.
//
// Remaining -Wsubobject-linkage from vendored protobuf/absl is GCC-specific to suppress; Clang does
// not accept -Wno-subobject-linkage. If you use GCC for C++ (recommended: CC=gcc CXX=g++), you can
// add e.g. export CGO_CXXFLAGS="$CGO_CXXFLAGS -Wno-subobject-linkage" for a quieter build.

/*
#cgo CFLAGS: -x c++
#cgo CFLAGS: -std=c++20
#cgo CFLAGS: -I${SRCDIR}/../../
#cgo CFLAGS: -I${SRCDIR}/../../protobuf
#cgo CFLAGS: -I${SRCDIR}/../../gtest
#cgo CFLAGS: -I${SRCDIR}/../../icu
#cgo CFLAGS: -I${SRCDIR}/../../utf8_range
#cgo CFLAGS: -Wno-char-subscripts
#cgo CFLAGS: -Wno-sign-compare
#cgo CFLAGS: -Wno-switch
#cgo CFLAGS: -Wno-unused-function
#cgo CFLAGS: -Wno-deprecated-declarations
#cgo CFLAGS: -Wno-builtin-macro-redefined
#cgo CFLAGS: -Wno-shift-count-overflow
#cgo CFLAGS: -Wno-return-type
#cgo CFLAGS: -Wno-attributes
#cgo CFLAGS: -DHAVE_PTHREAD
#cgo CFLAGS: -DHAVE_ZLIB
#cgo CFLAGS: -DU_COMMON_IMPLEMENTATION
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../
#cgo CXXFLAGS: -I${SRCDIR}/../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../gtest
#cgo CXXFLAGS: -I${SRCDIR}/../../icu
#cgo CXXFLAGS: -I${SRCDIR}/../../utf8_range
#cgo CXXFLAGS: -Wno-builtin-macro-redefined
#cgo CXXFLAGS: -Wno-attributes
#cgo LDFLAGS: -ldl -lz -lstdc++

#include "export.inc"
#include "absl_plain_link.inc"
*/
import "C"

import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/utf8_range_link"
)
