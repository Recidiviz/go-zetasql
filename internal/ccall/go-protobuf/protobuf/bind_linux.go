package protobuf

// Protobuf is compiled via export.inc (single TU). Optional libprotobuf_cgo.a from
// extract_protobuf_cgo_lib.sh is not linked here by default; see docs/protobuf-vendoring.md.

/*
#cgo CFLAGS: -x c++
#cgo CFLAGS: -std=c++17
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
#cgo CFLAGS: -Wno-inconsistent-missing-override
#cgo CFLAGS: -Wno-unknown-attributes
#cgo CFLAGS: -Wno-macro-redefined
#cgo CFLAGS: -Wno-shift-count-overflow
#cgo CFLAGS: -Wno-enum-compare-switch
#cgo CFLAGS: -Wno-return-type
#cgo CFLAGS: -Wno-subobject-linkage
#cgo CFLAGS: -Wno-defaulted-function-deleted
#cgo CFLAGS: -Wno-unknown-warning-option
#cgo CFLAGS: -DHAVE_PTHREAD
#cgo CFLAGS: -DHAVE_ZLIB
#cgo CFLAGS: -DU_COMMON_IMPLEMENTATION
#cgo CXXFLAGS: -std=c++17
#cgo CXXFLAGS: -I${SRCDIR}/../../
#cgo CXXFLAGS: -I${SRCDIR}/../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../gtest
#cgo CXXFLAGS: -I${SRCDIR}/../../icu
#cgo CXXFLAGS: -I${SRCDIR}/../../utf8_range
#cgo CXXFLAGS: -Wno-macro-redefined
#cgo CXXFLAGS: -Wno-defaulted-function-deleted
#cgo LDFLAGS: -ldl -lz -lstdc++

#include "export.inc"
*/
import "C"
