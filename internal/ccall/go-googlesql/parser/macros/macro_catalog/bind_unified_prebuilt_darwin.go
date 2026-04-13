//go:build googlesql_unified_prebuilt

package macro_catalog

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I../../../../
#cgo CXXFLAGS: -I../../../../protobuf
#cgo CXXFLAGS: -I../../../../utf8_range
#cgo CXXFLAGS: -I../../../../gtest
#cgo CXXFLAGS: -I../../../../icu
#cgo CXXFLAGS: -I../../../../re2
#cgo CXXFLAGS: -I../../../../json
#cgo CXXFLAGS: -I../../../../googleapis
#cgo CXXFLAGS: -I../../../../boringssl
#cgo CXXFLAGS: -I../../../../flex/src
#cgo CXXFLAGS: -DGOOGLESQL_LINK_ONLY_BIND
#cgo CXXFLAGS: -DGOOGLESQL_UNIFIED_PREBUILT_THIN_BIND_CC
#cgo CXXFLAGS: -Wno-char-subscripts
#cgo CXXFLAGS: -Wno-sign-compare
#cgo CXXFLAGS: -Wno-switch
#cgo CXXFLAGS: -Wno-unused-function
#cgo CXXFLAGS: -Wno-deprecated-declarations
#cgo CXXFLAGS: -Wno-deprecated-enum-enum-conversion
#cgo CXXFLAGS: -Wno-deprecated-anon-enum-enum-conversion
#cgo CXXFLAGS: -Wno-deprecated-this-capture
#cgo CXXFLAGS: -Wno-inconsistent-missing-override
#cgo CXXFLAGS: -Wno-unknown-attributes
#cgo CXXFLAGS: -Wno-macro-redefined
#cgo CXXFLAGS: -Wno-shift-count-overflow
#cgo CXXFLAGS: -Wno-enum-compare-switch
#cgo CXXFLAGS: -Wno-return-type
#cgo CXXFLAGS: -Wno-subobject-linkage
#cgo CXXFLAGS: -Wno-defaulted-function-deleted
#cgo CXXFLAGS: -Wno-unknown-warning-option
#cgo CXXFLAGS: -DHAVE_PTHREAD
#cgo CXXFLAGS: -DU_COMMON_IMPLEMENTATION
#cgo LDFLAGS: -L${SRCDIR}/../../../../go-googlesql-unified/lib
#cgo LDFLAGS: -Wl,-force_load,${SRCDIR}/../../../../go-googlesql-unified/lib/libgooglesql.a
#cgo LDFLAGS: -lz
#cgo LDFLAGS: -lc++
#define GO_EXPORT(API) export_googlesql_parser_macros_macro_catalog_ ## API
#include "bridge.h"
#undef GO_EXPORT
#define GO_EXPORT(API) export_absl_time_internal_cctz_time_zone_ ## API
#include "../../../../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-protobuf/protobuf"
)
import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-googlesql-unified/googlesqlunified"
)
