//go:build googlesql_unified_prebuilt

package regexp

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

#define GO_EXPORT(API) export_googlesql_public_functions_regexp_ ## API
#include "bridge.h"
#include "../../../../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-protobuf/protobuf"
)
import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-googlesql-unified/googlesqlunified"
	"unsafe"
)

//export export_googlesql_public_functions_regexp_cctz_FixedOffsetFromName
//go:linkname export_googlesql_public_functions_regexp_cctz_FixedOffsetFromName github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_googlesql_public_functions_regexp_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_functions_regexp_cctz_FixedOffsetToName
//go:linkname export_googlesql_public_functions_regexp_cctz_FixedOffsetToName github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_googlesql_public_functions_regexp_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_cctz_FixedOffsetToAbbr
//go:linkname export_googlesql_public_functions_regexp_cctz_FixedOffsetToAbbr github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_googlesql_public_functions_regexp_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_cctz_detail_format
//go:linkname export_googlesql_public_functions_regexp_cctz_detail_format github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_googlesql_public_functions_regexp_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_cctz_detail_parse
//go:linkname export_googlesql_public_functions_regexp_cctz_detail_parse github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_googlesql_public_functions_regexp_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_googlesql_public_functions_regexp_TimeZoneIf_Load
//go:linkname export_googlesql_public_functions_regexp_TimeZoneIf_Load github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_googlesql_public_functions_regexp_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_time_zone_Impl_UTC
//go:linkname export_googlesql_public_functions_regexp_time_zone_Impl_UTC github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_googlesql_public_functions_regexp_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_time_zone_Impl_LoadTimeZone
//go:linkname export_googlesql_public_functions_regexp_time_zone_Impl_LoadTimeZone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_googlesql_public_functions_regexp_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_functions_regexp_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_googlesql_public_functions_regexp_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_googlesql_public_functions_regexp_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_googlesql_public_functions_regexp_time_zone_Impl_UTCImpl
//go:linkname export_googlesql_public_functions_regexp_time_zone_Impl_UTCImpl github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_googlesql_public_functions_regexp_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneInfo_Load
//go:linkname export_googlesql_public_functions_regexp_TimeZoneInfo_Load github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_googlesql_public_functions_regexp_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_functions_regexp_TimeZoneInfo_BreakTime
//go:linkname export_googlesql_public_functions_regexp_TimeZoneInfo_BreakTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_googlesql_public_functions_regexp_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneInfo_MakeTime
//go:linkname export_googlesql_public_functions_regexp_TimeZoneInfo_MakeTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_googlesql_public_functions_regexp_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneInfo_Version
//go:linkname export_googlesql_public_functions_regexp_TimeZoneInfo_Version github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_googlesql_public_functions_regexp_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneInfo_Description
//go:linkname export_googlesql_public_functions_regexp_TimeZoneInfo_Description github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_googlesql_public_functions_regexp_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneInfo_NextTransition
//go:linkname export_googlesql_public_functions_regexp_TimeZoneInfo_NextTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_googlesql_public_functions_regexp_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_functions_regexp_TimeZoneInfo_PrevTransition
//go:linkname export_googlesql_public_functions_regexp_TimeZoneInfo_PrevTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_googlesql_public_functions_regexp_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_functions_regexp_TimeZoneLibC_BreakTime
//go:linkname export_googlesql_public_functions_regexp_TimeZoneLibC_BreakTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_googlesql_public_functions_regexp_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneLibC_MakeTime
//go:linkname export_googlesql_public_functions_regexp_TimeZoneLibC_MakeTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_googlesql_public_functions_regexp_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneLibC_Version
//go:linkname export_googlesql_public_functions_regexp_TimeZoneLibC_Version github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_googlesql_public_functions_regexp_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_TimeZoneLibC_NextTransition
//go:linkname export_googlesql_public_functions_regexp_TimeZoneLibC_NextTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_googlesql_public_functions_regexp_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_functions_regexp_TimeZoneLibC_PrevTransition
//go:linkname export_googlesql_public_functions_regexp_TimeZoneLibC_PrevTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_googlesql_public_functions_regexp_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_functions_regexp_time_zone_name
//go:linkname export_googlesql_public_functions_regexp_time_zone_name github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_googlesql_public_functions_regexp_time_zone_name(arg0 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_time_zone_lookup
//go:linkname export_googlesql_public_functions_regexp_time_zone_lookup github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_googlesql_public_functions_regexp_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_time_zone_lookup2
//go:linkname export_googlesql_public_functions_regexp_time_zone_lookup2 github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_googlesql_public_functions_regexp_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_time_zone_next_transition
//go:linkname export_googlesql_public_functions_regexp_time_zone_next_transition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_googlesql_public_functions_regexp_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_functions_regexp_time_zone_prev_transition
//go:linkname export_googlesql_public_functions_regexp_time_zone_prev_transition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_googlesql_public_functions_regexp_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_functions_regexp_time_zone_version
//go:linkname export_googlesql_public_functions_regexp_time_zone_version github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_googlesql_public_functions_regexp_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_time_zone_description
//go:linkname export_googlesql_public_functions_regexp_time_zone_description github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_googlesql_public_functions_regexp_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_cctz_load_time_zone
//go:linkname export_googlesql_public_functions_regexp_cctz_load_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_googlesql_public_functions_regexp_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_functions_regexp_cctz_utc_time_zone
//go:linkname export_googlesql_public_functions_regexp_cctz_utc_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_googlesql_public_functions_regexp_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_cctz_fixed_time_zone
//go:linkname export_googlesql_public_functions_regexp_cctz_fixed_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_googlesql_public_functions_regexp_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_cctz_local_time_zone
//go:linkname export_googlesql_public_functions_regexp_cctz_local_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_googlesql_public_functions_regexp_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_googlesql_public_functions_regexp_cctz_ParsePosixSpec
//go:linkname export_googlesql_public_functions_regexp_cctz_ParsePosixSpec github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_googlesql_public_functions_regexp_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)
