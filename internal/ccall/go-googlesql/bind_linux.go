//go:build !googlesql_unified_prebuilt

package googlesql

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I../
#cgo CXXFLAGS: -I../protobuf
#cgo CXXFLAGS: -I../utf8_range
#cgo CXXFLAGS: -I../gtest
#cgo CXXFLAGS: -I../icu
#cgo CXXFLAGS: -I../re2
#cgo CXXFLAGS: -I../json
#cgo CXXFLAGS: -I../googleapis
#cgo CXXFLAGS: -I../boringssl
#cgo CXXFLAGS: -I../flex/src
#cgo CXXFLAGS: -Wno-final-dtor-non-final-class
#cgo CXXFLAGS: -Wno-implicit-const-int-float-conversion
#cgo CXXFLAGS: -Wno-deprecated-enum-enum-conversion
#cgo CXXFLAGS: -Wno-deprecated-anon-enum-enum-conversion
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
#cgo LDFLAGS: -ldl

#define GO_EXPORT(API) export_googlesql_ ## API
#include "bridge.h"
#include "../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-googlesql/public/analyzer"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-protobuf/protobuf"
	_ "github.com/vantaboard/go-googlesql/internal/ccall/utf8_range_link"
	"unsafe"
)

func cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_cctz_FixedOffsetFromName(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_cctz_FixedOffsetFromName(arg0, arg1, arg2)
}

func cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_cctz_FixedOffsetToName(
		arg0,
		arg1,
	)
}

func googlesql_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_cctz_FixedOffsetToName(arg0, arg1)
}

func cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_cctz_FixedOffsetToAbbr(
		arg0,
		arg1,
	)
}

func googlesql_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_cctz_FixedOffsetToAbbr(arg0, arg1)
}

func cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	googlesql_cctz_detail_format(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func googlesql_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_cctz_detail_format(arg0, arg1, arg2, arg3, arg4)
}

func cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *bool) {
	googlesql_cctz_detail_parse(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
		arg5,
		(*C.char)(unsafe.Pointer(arg6)),
	)
}

func googlesql_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char) {
	C.export_googlesql_cctz_detail_parse(arg0, arg1, arg2, arg3, arg4, arg5, arg6)
}

func TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TimeZoneIf_Load(
		arg0,
		arg1,
	)
}

func googlesql_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneIf_Load(arg0, arg1)
}

func time_zone_Impl_UTC(arg0 *unsafe.Pointer) {
	googlesql_time_zone_Impl_UTC(
		arg0,
	)
}

func googlesql_time_zone_Impl_UTC(arg0 *unsafe.Pointer) {
	C.export_googlesql_time_zone_Impl_UTC(arg0)
}

func time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_time_zone_Impl_LoadTimeZone(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_time_zone_Impl_LoadTimeZone(arg0, arg1, arg2)
}

func time_zone_Impl_ClearTimeZoneMapTestOnly() {
	googlesql_time_zone_Impl_ClearTimeZoneMapTestOnly()
}

func googlesql_time_zone_Impl_ClearTimeZoneMapTestOnly() {
	C.export_googlesql_time_zone_Impl_ClearTimeZoneMapTestOnly()
}

func time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer) {
	googlesql_time_zone_Impl_UTCImpl(
		arg0,
	)
}

func googlesql_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer) {
	C.export_googlesql_time_zone_Impl_UTCImpl(arg0)
}

func TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_TimeZoneInfo_Load(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_TimeZoneInfo_Load(arg0, arg1, arg2)
}

func TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_TimeZoneInfo_BreakTime(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneInfo_BreakTime(arg0, arg1, arg2)
}

func TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_TimeZoneInfo_MakeTime(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneInfo_MakeTime(arg0, arg1, arg2)
}

func TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TimeZoneInfo_Version(
		arg0,
		arg1,
	)
}

func googlesql_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneInfo_Version(arg0, arg1)
}

func TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TimeZoneInfo_Description(
		arg0,
		arg1,
	)
}

func googlesql_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneInfo_Description(arg0, arg1)
}

func TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	googlesql_TimeZoneInfo_NextTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func googlesql_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_googlesql_TimeZoneInfo_NextTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	googlesql_TimeZoneInfo_PrevTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func googlesql_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_googlesql_TimeZoneInfo_PrevTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_TimeZoneLibC_BreakTime(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneLibC_BreakTime(arg0, arg1, arg2)
}

func TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_TimeZoneLibC_MakeTime(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneLibC_MakeTime(arg0, arg1, arg2)
}

func TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TimeZoneLibC_Version(
		arg0,
		arg1,
	)
}

func googlesql_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TimeZoneLibC_Version(arg0, arg1)
}

func TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	googlesql_TimeZoneLibC_NextTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func googlesql_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_googlesql_TimeZoneLibC_NextTransition(arg0, arg1, arg2, arg3)
}

func TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	googlesql_TimeZoneLibC_PrevTransition(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func googlesql_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_googlesql_TimeZoneLibC_PrevTransition(arg0, arg1, arg2, arg3)
}

func time_zone_name(arg0 *unsafe.Pointer) {
	googlesql_time_zone_name(
		arg0,
	)
}

func googlesql_time_zone_name(arg0 *unsafe.Pointer) {
	C.export_googlesql_time_zone_name(arg0)
}

func time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_time_zone_lookup(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_time_zone_lookup(arg0, arg1, arg2)
}

func time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_time_zone_lookup2(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_time_zone_lookup2(arg0, arg1, arg2)
}

func time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_time_zone_next_transition(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_time_zone_next_transition(arg0, arg1, arg2)
}

func time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_time_zone_prev_transition(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_time_zone_prev_transition(arg0, arg1, arg2)
}

func time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_time_zone_version(
		arg0,
		arg1,
	)
}

func googlesql_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_time_zone_version(arg0, arg1)
}

func time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_time_zone_description(
		arg0,
		arg1,
	)
}

func googlesql_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_time_zone_description(arg0, arg1)
}

func cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_cctz_load_time_zone(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_cctz_load_time_zone(arg0, arg1, arg2)
}

func cctz_utc_time_zone(arg0 *unsafe.Pointer) {
	googlesql_cctz_utc_time_zone(
		arg0,
	)
}

func googlesql_cctz_utc_time_zone(arg0 *unsafe.Pointer) {
	C.export_googlesql_cctz_utc_time_zone(arg0)
}

func cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_cctz_fixed_time_zone(
		arg0,
		arg1,
	)
}

func googlesql_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_cctz_fixed_time_zone(arg0, arg1)
}

func cctz_local_time_zone(arg0 *unsafe.Pointer) {
	googlesql_cctz_local_time_zone(
		arg0,
	)
}

func googlesql_cctz_local_time_zone(arg0 *unsafe.Pointer) {
	C.export_googlesql_cctz_local_time_zone(arg0)
}

func cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_cctz_ParsePosixSpec(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_cctz_ParsePosixSpec(arg0, arg1, arg2)
}

func LanguageOptions_new(arg0 *unsafe.Pointer) {
	googlesql_LanguageOptions_new(
		arg0,
	)
}

func googlesql_LanguageOptions_new(arg0 *unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_new(arg0)
}

func LanguageOptions_SupportsStatementKind(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	googlesql_LanguageOptions_SupportsStatementKind(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_LanguageOptions_SupportsStatementKind(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_googlesql_LanguageOptions_SupportsStatementKind(arg0, arg1, arg2)
}

func LanguageOptions_SetSupportedStatementKinds(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_LanguageOptions_SetSupportedStatementKinds(
		arg0,
		arg1,
	)
}

func googlesql_LanguageOptions_SetSupportedStatementKinds(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_SetSupportedStatementKinds(arg0, arg1)
}

func LanguageOptions_SetSupportsAllStatementKinds(arg0 unsafe.Pointer) {
	googlesql_LanguageOptions_SetSupportsAllStatementKinds(
		arg0,
	)
}

func googlesql_LanguageOptions_SetSupportsAllStatementKinds(arg0 unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_SetSupportsAllStatementKinds(arg0)
}

func LanguageOptions_AddSupportedStatementKind(arg0 unsafe.Pointer, arg1 int) {
	googlesql_LanguageOptions_AddSupportedStatementKind(
		arg0,
		C.int(arg1),
	)
}

func googlesql_LanguageOptions_AddSupportedStatementKind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_LanguageOptions_AddSupportedStatementKind(arg0, arg1)
}

func LanguageOptions_LanguageFeatureEnabled(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	googlesql_LanguageOptions_LanguageFeatureEnabled(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_LanguageOptions_LanguageFeatureEnabled(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_googlesql_LanguageOptions_LanguageFeatureEnabled(arg0, arg1, arg2)
}

func LanguageOptions_SetLanguageVersion(arg0 unsafe.Pointer, arg1 int) {
	googlesql_LanguageOptions_SetLanguageVersion(
		arg0,
		C.int(arg1),
	)
}

func googlesql_LanguageOptions_SetLanguageVersion(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_LanguageOptions_SetLanguageVersion(arg0, arg1)
}

func LanguageOptions_EnableLanguageFeature(arg0 unsafe.Pointer, arg1 int) {
	googlesql_LanguageOptions_EnableLanguageFeature(
		arg0,
		C.int(arg1),
	)
}

func googlesql_LanguageOptions_EnableLanguageFeature(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_LanguageOptions_EnableLanguageFeature(arg0, arg1)
}

func LanguageOptions_SetEnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_LanguageOptions_SetEnabledLanguageFeatures(
		arg0,
		arg1,
	)
}

func googlesql_LanguageOptions_SetEnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_SetEnabledLanguageFeatures(arg0, arg1)
}

func LanguageOptions_EnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_LanguageOptions_EnabledLanguageFeatures(
		arg0,
		arg1,
	)
}

func googlesql_LanguageOptions_EnabledLanguageFeatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_EnabledLanguageFeatures(arg0, arg1)
}

func LanguageOptions_EnabledLanguageFeaturesAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_LanguageOptions_EnabledLanguageFeaturesAsString(
		arg0,
		arg1,
	)
}

func googlesql_LanguageOptions_EnabledLanguageFeaturesAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_EnabledLanguageFeaturesAsString(arg0, arg1)
}

func LanguageOptions_DisableAllLanguageFeatures(arg0 unsafe.Pointer) {
	googlesql_LanguageOptions_DisableAllLanguageFeatures(
		arg0,
	)
}

func googlesql_LanguageOptions_DisableAllLanguageFeatures(arg0 unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_DisableAllLanguageFeatures(arg0)
}

func LanguageOptions_EnableMaximumLanguageFeatures(arg0 unsafe.Pointer) {
	googlesql_LanguageOptions_EnableMaximumLanguageFeatures(
		arg0,
	)
}

func googlesql_LanguageOptions_EnableMaximumLanguageFeatures(arg0 unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_EnableMaximumLanguageFeatures(arg0)
}

func LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0 unsafe.Pointer) {
	googlesql_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(
		arg0,
	)
}

func googlesql_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0 unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment(arg0)
}

func LanguageOptions_set_name_resolution_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_LanguageOptions_set_name_resolution_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_LanguageOptions_set_name_resolution_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_LanguageOptions_set_name_resolution_mode(arg0, arg1)
}

func LanguageOptions_name_resolution_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_LanguageOptions_name_resolution_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_LanguageOptions_name_resolution_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_LanguageOptions_name_resolution_mode(arg0, arg1)
}

func LanguageOptions_set_product_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_LanguageOptions_set_product_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_LanguageOptions_set_product_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_LanguageOptions_set_product_mode(arg0, arg1)
}

func LanguageOptions_product_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_LanguageOptions_product_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_LanguageOptions_product_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_LanguageOptions_product_mode(arg0, arg1)
}

func LanguageOptions_SupportsProtoTypes(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_LanguageOptions_SupportsProtoTypes(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_LanguageOptions_SupportsProtoTypes(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_LanguageOptions_SupportsProtoTypes(arg0, arg1)
}

func LanguageOptions_set_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 int) {
	googlesql_LanguageOptions_set_error_on_deprecated_syntax(
		arg0,
		C.int(arg1),
	)
}

func googlesql_LanguageOptions_set_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_LanguageOptions_set_error_on_deprecated_syntax(arg0, arg1)
}

func LanguageOptions_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_LanguageOptions_error_on_deprecated_syntax(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_LanguageOptions_error_on_deprecated_syntax(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_LanguageOptions_error_on_deprecated_syntax(arg0, arg1)
}

func LanguageOptions_SetSupportedGenericEntityTypes(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_LanguageOptions_SetSupportedGenericEntityTypes(
		arg0,
		arg1,
	)
}

func googlesql_LanguageOptions_SetSupportedGenericEntityTypes(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_SetSupportedGenericEntityTypes(arg0, arg1)
}

func LanguageOptions_GenericEntityTypeSupported(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_LanguageOptions_GenericEntityTypeSupported(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_LanguageOptions_GenericEntityTypeSupported(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_LanguageOptions_GenericEntityTypeSupported(arg0, arg1, arg2)
}

func LanguageOptions_IsReservedKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_LanguageOptions_IsReservedKeyword(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_LanguageOptions_IsReservedKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_LanguageOptions_IsReservedKeyword(arg0, arg1, arg2)
}

func LanguageOptions_EnableReservableKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	googlesql_LanguageOptions_EnableReservableKeyword(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func googlesql_LanguageOptions_EnableReservableKeyword(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_LanguageOptions_EnableReservableKeyword(arg0, arg1, arg2, arg3)
}

func LanguageOptions_EnableAllReservableKeywords(arg0 unsafe.Pointer, arg1 int) {
	googlesql_LanguageOptions_EnableAllReservableKeywords(
		arg0,
		C.int(arg1),
	)
}

func googlesql_LanguageOptions_EnableAllReservableKeywords(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_LanguageOptions_EnableAllReservableKeywords(arg0, arg1)
}

func AnalyzerOptions_new(arg0 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_new(
		arg0,
	)
}

func googlesql_AnalyzerOptions_new(arg0 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_new(arg0)
}

func AnalyzerOptions_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_language(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_language(arg0, arg1)
}

func AnalyzerOptions_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_AnalyzerOptions_set_language(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_set_language(arg0, arg1)
}

func AnalyzerOptions_AddQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_AddQueryParameter(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_AnalyzerOptions_AddQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_AddQueryParameter(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_query_parameters(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_query_parameters(arg0, arg1)
}

func AnalyzerOptions_clear_query_parameters(arg0 unsafe.Pointer) {
	googlesql_AnalyzerOptions_clear_query_parameters(
		arg0,
	)
}

func googlesql_AnalyzerOptions_clear_query_parameters(arg0 unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_clear_query_parameters(arg0)
}

func AnalyzerOptions_AddPositionalQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_AddPositionalQueryParameter(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_AnalyzerOptions_AddPositionalQueryParameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_AddPositionalQueryParameter(arg0, arg1, arg2)
}

func AnalyzerOptions_positional_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_positional_query_parameters(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_positional_query_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_positional_query_parameters(arg0, arg1)
}

func AnalyzerOptions_clear_positional_query_parameters(arg0 unsafe.Pointer) {
	googlesql_AnalyzerOptions_clear_positional_query_parameters(
		arg0,
	)
}

func googlesql_AnalyzerOptions_clear_positional_query_parameters(arg0 unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_clear_positional_query_parameters(arg0)
}

func AnalyzerOptions_AddExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_AddExpressionColumn(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_AnalyzerOptions_AddExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_AddExpressionColumn(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_SetInScopeExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_SetInScopeExpressionColumn(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_AnalyzerOptions_SetInScopeExpressionColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_SetInScopeExpressionColumn(arg0, arg1, arg2, arg3)
}

func AnalyzerOptions_expression_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_expression_columns(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_expression_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_expression_columns(arg0, arg1)
}

func AnalyzerOptions_has_in_scope_expression_column(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_AnalyzerOptions_has_in_scope_expression_column(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_has_in_scope_expression_column(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_AnalyzerOptions_has_in_scope_expression_column(arg0, arg1)
}

func AnalyzerOptions_in_scope_expression_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_in_scope_expression_column_name(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_in_scope_expression_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_in_scope_expression_column_name(arg0, arg1)
}

func AnalyzerOptions_in_scope_expression_column_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_in_scope_expression_column_type(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_in_scope_expression_column_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_in_scope_expression_column_type(arg0, arg1)
}

func AnalyzerOptions_set_error_message_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_error_message_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_error_message_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_error_message_mode(arg0, arg1)
}

func AnalyzerOptions_error_message_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_AnalyzerOptions_error_message_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_error_message_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_AnalyzerOptions_error_message_mode(arg0, arg1)
}

func AnalyzerOptions_set_statement_context(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_statement_context(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_statement_context(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_statement_context(arg0, arg1)
}

func AnalyzerOptions_statement_context(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_AnalyzerOptions_statement_context(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_statement_context(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_AnalyzerOptions_statement_context(arg0, arg1)
}

func AnalyzerOptions_set_parse_location_record_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_parse_location_record_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_parse_location_record_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_parse_location_record_type(arg0, arg1)
}

func AnalyzerOptions_parse_location_record_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_AnalyzerOptions_parse_location_record_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_parse_location_record_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_AnalyzerOptions_parse_location_record_type(arg0, arg1)
}

func AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_create_new_column_for_each_projected_output(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_create_new_column_for_each_projected_output(arg0, arg1)
}

func AnalyzerOptions_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_AnalyzerOptions_create_new_column_for_each_projected_output(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_create_new_column_for_each_projected_output(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_AnalyzerOptions_create_new_column_for_each_projected_output(arg0, arg1)
}

func AnalyzerOptions_set_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_allow_undeclared_parameters(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_allow_undeclared_parameters(arg0, arg1)
}

func AnalyzerOptions_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_AnalyzerOptions_allow_undeclared_parameters(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_allow_undeclared_parameters(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_AnalyzerOptions_allow_undeclared_parameters(arg0, arg1)
}

func AnalyzerOptions_set_parameter_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_parameter_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_parameter_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_parameter_mode(arg0, arg1)
}

func AnalyzerOptions_parameter_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_AnalyzerOptions_parameter_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_parameter_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_AnalyzerOptions_parameter_mode(arg0, arg1)
}

func AnalyzerOptions_set_prune_unused_columns(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_prune_unused_columns(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_prune_unused_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_prune_unused_columns(arg0, arg1)
}

func AnalyzerOptions_prune_unused_columns(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_AnalyzerOptions_prune_unused_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_prune_unused_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_AnalyzerOptions_prune_unused_columns(arg0, arg1)
}

func AnalyzerOptions_set_preserve_column_aliases(arg0 unsafe.Pointer, arg1 int) {
	googlesql_AnalyzerOptions_set_preserve_column_aliases(
		arg0,
		C.int(arg1),
	)
}

func googlesql_AnalyzerOptions_set_preserve_column_aliases(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_AnalyzerOptions_set_preserve_column_aliases(arg0, arg1)
}

func AnalyzerOptions_preserve_column_aliases(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_AnalyzerOptions_preserve_column_aliases(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_AnalyzerOptions_preserve_column_aliases(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_AnalyzerOptions_preserve_column_aliases(arg0, arg1)
}

func AnalyzerOptions_GetParserOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOptions_GetParserOptions(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOptions_GetParserOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOptions_GetParserOptions(arg0, arg1)
}

func ValidateAnalyzerOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ValidateAnalyzerOptions(
		arg0,
		arg1,
	)
}

func googlesql_ValidateAnalyzerOptions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ValidateAnalyzerOptions(arg0, arg1)
}

func AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	googlesql_AnalyzeStatement(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func googlesql_AnalyzeStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_AnalyzeStatement(arg0, arg1, arg2, arg3, arg4)
}

func AnalyzeNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *bool, arg5 *unsafe.Pointer) {
	googlesql_AnalyzeNextStatement(
		arg0,
		arg1,
		arg2,
		arg3,
		(*C.char)(unsafe.Pointer(arg4)),
		arg5,
	)
}

func googlesql_AnalyzeNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *C.char, arg5 *unsafe.Pointer) {
	C.export_googlesql_AnalyzeNextStatement(arg0, arg1, arg2, arg3, arg4, arg5)
}

func AnalyzeExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	googlesql_AnalyzeExpression(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
	)
}

func googlesql_AnalyzeExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_AnalyzeExpression(arg0, arg1, arg2, arg3, arg4)
}

func AnalyzeStatementFromParserAST(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	googlesql_AnalyzeStatementFromParserAST(
		arg0,
		arg1,
		arg2,
		arg3,
		arg4,
		arg5,
	)
}

func googlesql_AnalyzeStatementFromParserAST(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	C.export_googlesql_AnalyzeStatementFromParserAST(arg0, arg1, arg2, arg3, arg4, arg5)
}

func AnalyzerOutput_resolved_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_AnalyzerOutput_resolved_statement(
		arg0,
		arg1,
	)
}

func googlesql_AnalyzerOutput_resolved_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_AnalyzerOutput_resolved_statement(arg0, arg1)
}

func ResolvedNode_node_kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedNode_node_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNode_node_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedNode_node_kind(arg0, arg1)
}

func ResolvedNode_IsScan(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedNode_IsScan(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNode_IsScan(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedNode_IsScan(arg0, arg1)
}

func ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedNode_IsExpression(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNode_IsExpression(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedNode_IsExpression(arg0, arg1)
}

func ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedNode_IsStatement(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNode_IsStatement(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedNode_IsStatement(arg0, arg1)
}

func ResolvedNode_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedNode_DebugString(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedNode_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedNode_DebugString(arg0, arg1)
}

func ResolvedNode_GetChildNodes_num(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedNode_GetChildNodes_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNode_GetChildNodes_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedNode_GetChildNodes_num(arg0, arg1)
}

func ResolvedNode_GetChildNode(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_ResolvedNode_GetChildNode(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_ResolvedNode_GetChildNode(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_ResolvedNode_GetChildNode(arg0, arg1, arg2)
}

func ResolvedNode_GetParseLocationRangeOrNULL(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedNode_GetParseLocationRangeOrNULL(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedNode_GetParseLocationRangeOrNULL(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedNode_GetParseLocationRangeOrNULL(arg0, arg1)
}

func ResolvedNode_GetTreeDepth(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedNode_GetTreeDepth(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNode_GetTreeDepth(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedNode_GetTreeDepth(arg0, arg1)
}

func ResolvedExpr_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExpr_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExpr_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExpr_type(arg0, arg1)
}

func ResolvedExpr_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExpr_set_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExpr_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExpr_set_type(arg0, arg1)
}

func ResolvedExpr_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExpr_type_annotation_map(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExpr_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExpr_type_annotation_map(arg0, arg1)
}

func ResolvedExpr_set_type_annotation_map(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExpr_set_type_annotation_map(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExpr_set_type_annotation_map(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExpr_set_type_annotation_map(arg0, arg1)
}

func ResolvedLiteral_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedLiteral_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLiteral_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedLiteral_value(arg0, arg1)
}

func ResolvedLiteral_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedLiteral_set_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLiteral_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedLiteral_set_value(arg0, arg1)
}

func ResolvedLiteral_has_explicit_type(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedLiteral_has_explicit_type(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedLiteral_has_explicit_type(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedLiteral_has_explicit_type(arg0, arg1)
}

func ResolvedLiteral_set_has_explicit_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedLiteral_set_has_explicit_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedLiteral_set_has_explicit_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedLiteral_set_has_explicit_type(arg0, arg1)
}

func ResolvedLiteral_float_literal_id(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedLiteral_float_literal_id(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedLiteral_float_literal_id(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedLiteral_float_literal_id(arg0, arg1)
}

func ResolvedLiteral_set_float_literal_id(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedLiteral_set_float_literal_id(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedLiteral_set_float_literal_id(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedLiteral_set_float_literal_id(arg0, arg1)
}

func ResolvedLiteral_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedLiteral_preserve_in_literal_remover(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedLiteral_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedLiteral_preserve_in_literal_remover(arg0, arg1)
}

func ResolvedLiteral_set_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedLiteral_set_preserve_in_literal_remover(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedLiteral_set_preserve_in_literal_remover(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedLiteral_set_preserve_in_literal_remover(arg0, arg1)
}

func ResolvedParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedParameter_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedParameter_name(arg0, arg1)
}

func ResolvedParameter_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedParameter_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedParameter_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedParameter_set_name(arg0, arg1)
}

func ResolvedParameter_position(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedParameter_position(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedParameter_position(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedParameter_position(arg0, arg1)
}

func ResolvedParameter_set_position(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedParameter_set_position(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedParameter_set_position(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedParameter_set_position(arg0, arg1)
}

func ResolvedParameter_is_untyped(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedParameter_is_untyped(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedParameter_is_untyped(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedParameter_is_untyped(arg0, arg1)
}

func ResolvedParameter_set_is_untyped(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedParameter_set_is_untyped(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedParameter_set_is_untyped(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedParameter_set_is_untyped(arg0, arg1)
}

func ResolvedExpressionColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExpressionColumn_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExpressionColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExpressionColumn_name(arg0, arg1)
}

func ResolvedExpressionColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExpressionColumn_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExpressionColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExpressionColumn_set_name(arg0, arg1)
}

func ResolvedColumnRef_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnRef_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnRef_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnRef_column(arg0, arg1)
}

func ResolvedColumnRef_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnRef_set_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnRef_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnRef_set_column(arg0, arg1)
}

func ResolvedColumnRef_is_correlated(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedColumnRef_is_correlated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedColumnRef_is_correlated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedColumnRef_is_correlated(arg0, arg1)
}

func ResolvedColumnRef_set_is_correlated(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedColumnRef_set_is_correlated(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedColumnRef_set_is_correlated(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedColumnRef_set_is_correlated(arg0, arg1)
}

func ResolvedConstant_constant(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedConstant_constant(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedConstant_constant(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedConstant_constant(arg0, arg1)
}

func ResolvedConstant_set_constant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedConstant_set_constant(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedConstant_set_constant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedConstant_set_constant(arg0, arg1)
}

func ResolvedSystemVariable_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSystemVariable_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSystemVariable_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSystemVariable_name_path(arg0, arg1)
}

func ResolvedSystemVariable_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSystemVariable_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSystemVariable_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSystemVariable_set_name_path(arg0, arg1)
}

func ResolvedSystemVariable_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSystemVariable_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSystemVariable_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSystemVariable_add_name_path(arg0, arg1)
}

func ResolvedInlineLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_argument_list(arg0, arg1)
}

func ResolvedInlineLambda_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_set_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_set_argument_list(arg0, arg1)
}

func ResolvedInlineLambda_add_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_add_argument(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_add_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_add_argument(arg0, arg1)
}

func ResolvedInlineLambda_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_parameter_list(arg0, arg1)
}

func ResolvedInlineLambda_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_set_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_set_parameter_list(arg0, arg1)
}

func ResolvedInlineLambda_add_parameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_add_parameter(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_add_parameter(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_add_parameter(arg0, arg1)
}

func ResolvedInlineLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_body(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_body(arg0, arg1)
}

func ResolvedInlineLambda_set_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInlineLambda_set_body(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInlineLambda_set_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInlineLambda_set_body(arg0, arg1)
}

func ResolvedFilterFieldArg_include(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedFilterFieldArg_include(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedFilterFieldArg_include(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedFilterFieldArg_include(arg0, arg1)
}

func ResolvedFilterFieldArg_set_include(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedFilterFieldArg_set_include(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedFilterFieldArg_set_include(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedFilterFieldArg_set_include(arg0, arg1)
}

func ResolvedFilterField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFilterField_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterField_expr(arg0, arg1)
}

func ResolvedFilterField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFilterField_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterField_set_expr(arg0, arg1)
}

func ResolvedFilterField_filter_field_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFilterField_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterField_filter_field_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterField_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_set_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFilterField_set_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterField_set_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterField_set_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_add_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFilterField_add_filter_field_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterField_add_filter_field_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterField_add_filter_field_arg_list(arg0, arg1)
}

func ResolvedFilterField_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedFilterField_reset_cleared_required_fields(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedFilterField_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedFilterField_reset_cleared_required_fields(arg0, arg1)
}

func ResolvedFilterField_set_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedFilterField_set_reset_cleared_required_fields(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedFilterField_set_reset_cleared_required_fields(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedFilterField_set_reset_cleared_required_fields(arg0, arg1)
}

func ResolvedFunctionCallBase_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_function(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_function(arg0, arg1)
}

func ResolvedFunctionCallBase_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_set_function(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_set_function(arg0, arg1)
}

func ResolvedFunctionCallBase_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_signature(arg0, arg1)
}

func ResolvedFunctionCallBase_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_set_signature(arg0, arg1)
}

func ResolvedFunctionCallBase_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_set_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_set_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_add_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_add_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_generic_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_generic_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_generic_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_set_generic_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_set_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_set_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_add_generic_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_add_generic_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_add_generic_argument_list(arg0, arg1)
}

func ResolvedFunctionCallBase_error_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedFunctionCallBase_error_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedFunctionCallBase_error_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedFunctionCallBase_error_mode(arg0, arg1)
}

func ResolvedFunctionCallBase_set_error_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedFunctionCallBase_set_error_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedFunctionCallBase_set_error_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedFunctionCallBase_set_error_mode(arg0, arg1)
}

func ResolvedFunctionCallBase_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_set_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_set_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_add_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_add_hint_list(arg0, arg1)
}

func ResolvedFunctionCallBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_collation_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_collation_list(arg0, arg1)
}

func ResolvedFunctionCallBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_set_collation_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_set_collation_list(arg0, arg1)
}

func ResolvedFunctionCallBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCallBase_add_collation_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallBase_add_collation_list(arg0, arg1)
}

func ResolvedFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCall_function_call_info(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCall_function_call_info(arg0, arg1)
}

func ResolvedFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionCall_set_function_call_info(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCall_set_function_call_info(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_distinct(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedNonScalarFunctionCallBase_distinct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNonScalarFunctionCallBase_distinct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedNonScalarFunctionCallBase_distinct(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_distinct(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedNonScalarFunctionCallBase_set_distinct(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedNonScalarFunctionCallBase_set_distinct(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedNonScalarFunctionCallBase_set_distinct(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedNonScalarFunctionCallBase_null_handling_modifier(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedNonScalarFunctionCallBase_null_handling_modifier(arg0, arg1)
}

func ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedNonScalarFunctionCallBase_set_null_handling_modifier(arg0, arg1)
}

func ResolvedAggregateFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_having_modifier(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_having_modifier(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_having_modifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_set_having_modifier(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_set_having_modifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_set_having_modifier(arg0, arg1)
}

func ResolvedAggregateFunctionCall_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_set_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_add_order_by_item_list(arg0, arg1)
}

func ResolvedAggregateFunctionCall_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_limit(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_limit(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_set_limit(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_set_limit(arg0, arg1)
}

func ResolvedAggregateFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_function_call_info(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_function_call_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_function_call_info(arg0, arg1)
}

func ResolvedAggregateFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateFunctionCall_set_function_call_info(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateFunctionCall_set_function_call_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateFunctionCall_set_function_call_info(arg0, arg1)
}

func ResolvedAnalyticFunctionCall_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionCall_window_frame(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionCall_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionCall_window_frame(arg0, arg1)
}

func ResolvedAnalyticFunctionCall_set_window_frame(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionCall_set_window_frame(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionCall_set_window_frame(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionCall_set_window_frame(arg0, arg1)
}

func ResolvedExtendedCastElement_from_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExtendedCastElement_from_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCastElement_from_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCastElement_from_type(arg0, arg1)
}

func ResolvedExtendedCastElement_set_from_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExtendedCastElement_set_from_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCastElement_set_from_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCastElement_set_from_type(arg0, arg1)
}

func ResolvedExtendedCastElement_to_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExtendedCastElement_to_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCastElement_to_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCastElement_to_type(arg0, arg1)
}

func ResolvedExtendedCastElement_set_to_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExtendedCastElement_set_to_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCastElement_set_to_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCastElement_set_to_type(arg0, arg1)
}

func ResolvedExtendedCastElement_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExtendedCastElement_function(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCastElement_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCastElement_function(arg0, arg1)
}

func ResolvedExtendedCastElement_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExtendedCastElement_set_function(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCastElement_set_function(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCastElement_set_function(arg0, arg1)
}

func ResolvedExtendedCast_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExtendedCast_element_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCast_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCast_element_list(arg0, arg1)
}

func ResolvedExtendedCast_set_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExtendedCast_set_element_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCast_set_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCast_set_element_list(arg0, arg1)
}

func ResolvedExtendedCast_add_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExtendedCast_add_element_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExtendedCast_add_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExtendedCast_add_element_list(arg0, arg1)
}

func ResolvedCast_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCast_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_expr(arg0, arg1)
}

func ResolvedCast_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCast_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_set_expr(arg0, arg1)
}

func ResolvedCast_return_null_on_error(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCast_return_null_on_error(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCast_return_null_on_error(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCast_return_null_on_error(arg0, arg1)
}

func ResolvedCast_set_return_null_on_error(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCast_set_return_null_on_error(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCast_set_return_null_on_error(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCast_set_return_null_on_error(arg0, arg1)
}

func ResolvedCast_extended_cast(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCast_extended_cast(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_extended_cast(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_extended_cast(arg0, arg1)
}

func ResolvedCast_set_extended_cast(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCast_set_extended_cast(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_set_extended_cast(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_set_extended_cast(arg0, arg1)
}

func ResolvedCast_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCast_format(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_format(arg0, arg1)
}

func ResolvedCast_set_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCast_set_format(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_set_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_set_format(arg0, arg1)
}

func ResolvedCast_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCast_time_zone(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_time_zone(arg0, arg1)
}

func ResolvedCast_set_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCast_set_time_zone(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_set_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_set_time_zone(arg0, arg1)
}

func ResolvedCast_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCast_type_parameters(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_type_parameters(arg0, arg1)
}

func ResolvedCast_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCast_set_type_parameters(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCast_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCast_set_type_parameters(arg0, arg1)
}

func ResolvedMakeStruct_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMakeStruct_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeStruct_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeStruct_field_list(arg0, arg1)
}

func ResolvedMakeStruct_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMakeStruct_set_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeStruct_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeStruct_set_field_list(arg0, arg1)
}

func ResolvedMakeStruct_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMakeStruct_add_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeStruct_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeStruct_add_field_list(arg0, arg1)
}

func ResolvedMakeProto_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMakeProto_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeProto_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeProto_field_list(arg0, arg1)
}

func ResolvedMakeProto_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMakeProto_set_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeProto_set_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeProto_set_field_list(arg0, arg1)
}

func ResolvedMakeProto_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMakeProto_add_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeProto_add_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeProto_add_field_list(arg0, arg1)
}

func ResolvedMakeProtoField_format(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedMakeProtoField_format(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedMakeProtoField_format(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedMakeProtoField_format(arg0, arg1)
}

func ResolvedMakeProtoField_set_format(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedMakeProtoField_set_format(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedMakeProtoField_set_format(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedMakeProtoField_set_format(arg0, arg1)
}

func ResolvedMakeProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMakeProtoField_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeProtoField_expr(arg0, arg1)
}

func ResolvedMakeProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMakeProtoField_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMakeProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMakeProtoField_set_expr(arg0, arg1)
}

func ResolvedGetStructField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGetStructField_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetStructField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGetStructField_expr(arg0, arg1)
}

func ResolvedGetStructField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGetStructField_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetStructField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGetStructField_set_expr(arg0, arg1)
}

func ResolvedGetStructField_field_idx(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedGetStructField_field_idx(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedGetStructField_field_idx(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedGetStructField_field_idx(arg0, arg1)
}

func ResolvedGetStructField_set_field_idx(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedGetStructField_set_field_idx(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedGetStructField_set_field_idx(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedGetStructField_set_field_idx(arg0, arg1)
}

func ResolvedGetProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGetProtoField_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetProtoField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGetProtoField_expr(arg0, arg1)
}

func ResolvedGetProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGetProtoField_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetProtoField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGetProtoField_set_expr(arg0, arg1)
}

func ResolvedGetProtoField_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGetProtoField_default_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetProtoField_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGetProtoField_default_value(arg0, arg1)
}

func ResolvedGetProtoField_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGetProtoField_set_default_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetProtoField_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGetProtoField_set_default_value(arg0, arg1)
}

func ResolvedGetProtoField_get_has_bit(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedGetProtoField_get_has_bit(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedGetProtoField_get_has_bit(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedGetProtoField_get_has_bit(arg0, arg1)
}

func ResolvedGetProtoField_set_get_has_bit(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedGetProtoField_set_get_has_bit(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedGetProtoField_set_get_has_bit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedGetProtoField_set_get_has_bit(arg0, arg1)
}

func ResolvedGetProtoField_format(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedGetProtoField_format(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedGetProtoField_format(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedGetProtoField_format(arg0, arg1)
}

func ResolvedGetProtoField_set_format(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedGetProtoField_set_format(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedGetProtoField_set_format(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedGetProtoField_set_format(arg0, arg1)
}

func ResolvedGetProtoField_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedGetProtoField_return_default_value_when_unset(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedGetProtoField_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedGetProtoField_return_default_value_when_unset(arg0, arg1)
}

func ResolvedGetProtoField_set_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedGetProtoField_set_return_default_value_when_unset(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedGetProtoField_set_return_default_value_when_unset(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedGetProtoField_set_return_default_value_when_unset(arg0, arg1)
}

func ResolvedGetJsonField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGetJsonField_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetJsonField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGetJsonField_expr(arg0, arg1)
}

func ResolvedGetJsonField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGetJsonField_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetJsonField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGetJsonField_set_expr(arg0, arg1)
}

func ResolvedGetJsonField_field_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGetJsonField_field_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetJsonField_field_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGetJsonField_field_name(arg0, arg1)
}

func ResolvedGetJsonField_set_field_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGetJsonField_set_field_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGetJsonField_set_field_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGetJsonField_set_field_name(arg0, arg1)
}

func ResolvedFlatten_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFlatten_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFlatten_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFlatten_expr(arg0, arg1)
}

func ResolvedFlatten_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFlatten_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFlatten_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFlatten_set_expr(arg0, arg1)
}

func ResolvedFlatten_get_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFlatten_get_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFlatten_get_field_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFlatten_get_field_list(arg0, arg1)
}

func ResolvedFlatten_set_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFlatten_set_get_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFlatten_set_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFlatten_set_get_field_list(arg0, arg1)
}

func ResolvedFlatten_add_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFlatten_add_get_field_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFlatten_add_get_field_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFlatten_add_get_field_list(arg0, arg1)
}

func ResolvedReplaceFieldItem_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedReplaceFieldItem_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceFieldItem_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceFieldItem_expr(arg0, arg1)
}

func ResolvedReplaceFieldItem_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReplaceFieldItem_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceFieldItem_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceFieldItem_set_expr(arg0, arg1)
}

func ResolvedReplaceFieldItem_struct_index_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedReplaceFieldItem_struct_index_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceFieldItem_struct_index_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceFieldItem_struct_index_path(arg0, arg1)
}

func ResolvedReplaceFieldItem_set_struct_index_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReplaceFieldItem_set_struct_index_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceFieldItem_set_struct_index_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceFieldItem_set_struct_index_path(arg0, arg1)
}

func ResolvedReplaceFieldItem_add_struct_index_path(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedReplaceFieldItem_add_struct_index_path(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedReplaceFieldItem_add_struct_index_path(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedReplaceFieldItem_add_struct_index_path(arg0, arg1)
}

func ResolvedReplaceField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedReplaceField_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceField_expr(arg0, arg1)
}

func ResolvedReplaceField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReplaceField_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceField_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceField_set_expr(arg0, arg1)
}

func ResolvedReplaceField_replace_field_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedReplaceField_replace_field_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceField_replace_field_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceField_replace_field_item_list(arg0, arg1)
}

func ResolvedReplaceField_set_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReplaceField_set_replace_field_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceField_set_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceField_set_replace_field_item_list(arg0, arg1)
}

func ResolvedReplaceField_add_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReplaceField_add_replace_field_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReplaceField_add_replace_field_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReplaceField_add_replace_field_item_list(arg0, arg1)
}

func ResolvedSubqueryExpr_subquery_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedSubqueryExpr_subquery_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedSubqueryExpr_subquery_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedSubqueryExpr_subquery_type(arg0, arg1)
}

func ResolvedSubqueryExpr_set_subquery_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedSubqueryExpr_set_subquery_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedSubqueryExpr_set_subquery_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedSubqueryExpr_set_subquery_type(arg0, arg1)
}

func ResolvedSubqueryExpr_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_set_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_set_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_set_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_add_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_add_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_add_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_add_parameter_list(arg0, arg1)
}

func ResolvedSubqueryExpr_in_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_in_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_in_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_in_expr(arg0, arg1)
}

func ResolvedSubqueryExpr_set_in_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_set_in_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_set_in_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_set_in_expr(arg0, arg1)
}

func ResolvedSubqueryExpr_in_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_in_collation(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_in_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_in_collation(arg0, arg1)
}

func ResolvedSubqueryExpr_set_in_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_set_in_collation(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_set_in_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_set_in_collation(arg0, arg1)
}

func ResolvedSubqueryExpr_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_subquery(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_subquery(arg0, arg1)
}

func ResolvedSubqueryExpr_set_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_set_subquery(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_set_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_set_subquery(arg0, arg1)
}

func ResolvedSubqueryExpr_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_hint_list(arg0, arg1)
}

func ResolvedSubqueryExpr_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_set_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_set_hint_list(arg0, arg1)
}

func ResolvedSubqueryExpr_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSubqueryExpr_add_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSubqueryExpr_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSubqueryExpr_add_hint_list(arg0, arg1)
}

func ResolvedScan_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedScan_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedScan_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedScan_column_list(arg0, arg1)
}

func ResolvedScan_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedScan_set_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedScan_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedScan_set_column_list(arg0, arg1)
}

func ResolvedScan_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedScan_add_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedScan_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedScan_add_column_list(arg0, arg1)
}

func ResolvedScan_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedScan_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedScan_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedScan_hint_list(arg0, arg1)
}

func ResolvedScan_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedScan_set_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedScan_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedScan_set_hint_list(arg0, arg1)
}

func ResolvedScan_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedScan_add_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedScan_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedScan_add_hint_list(arg0, arg1)
}

func ResolvedScan_is_ordered(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedScan_is_ordered(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedScan_is_ordered(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedScan_is_ordered(arg0, arg1)
}

func ResolvedScan_set_is_ordered(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedScan_set_is_ordered(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedScan_set_is_ordered(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedScan_set_is_ordered(arg0, arg1)
}

func ResolvedModel_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedModel_model(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModel_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedModel_model(arg0, arg1)
}

func ResolvedModel_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedModel_set_model(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModel_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedModel_set_model(arg0, arg1)
}

func ResolvedConnection_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedConnection_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedConnection_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedConnection_connection(arg0, arg1)
}

func ResolvedConnection_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedConnection_set_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedConnection_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedConnection_set_connection(arg0, arg1)
}

func ResolvedDescriptor_descriptor_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDescriptor_descriptor_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescriptor_descriptor_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDescriptor_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_set_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescriptor_set_descriptor_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescriptor_set_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescriptor_set_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_add_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescriptor_add_descriptor_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescriptor_add_descriptor_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescriptor_add_descriptor_column_list(arg0, arg1)
}

func ResolvedDescriptor_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDescriptor_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescriptor_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDescriptor_descriptor_column_name_list(arg0, arg1)
}

func ResolvedDescriptor_set_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescriptor_set_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescriptor_set_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescriptor_set_descriptor_column_name_list(arg0, arg1)
}

func ResolvedDescriptor_add_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescriptor_add_descriptor_column_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescriptor_add_descriptor_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescriptor_add_descriptor_column_name_list(arg0, arg1)
}

func ResolvedTableScan_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTableScan_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_table(arg0, arg1)
}

func ResolvedTableScan_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTableScan_set_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_set_table(arg0, arg1)
}

func ResolvedTableScan_for_system_time_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTableScan_for_system_time_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_for_system_time_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_for_system_time_expr(arg0, arg1)
}

func ResolvedTableScan_set_for_system_time_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTableScan_set_for_system_time_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_set_for_system_time_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_set_for_system_time_expr(arg0, arg1)
}

func ResolvedTableScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTableScan_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_column_index_list(arg0, arg1)
}

func ResolvedTableScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTableScan_set_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_set_column_index_list(arg0, arg1)
}

func ResolvedTableScan_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedTableScan_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedTableScan_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedTableScan_add_column_index_list(arg0, arg1)
}

func ResolvedTableScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTableScan_alias(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_alias(arg0, arg1)
}

func ResolvedTableScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTableScan_set_alias(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTableScan_set_alias(arg0, arg1)
}

func ResolvedJoinScan_join_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedJoinScan_join_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedJoinScan_join_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedJoinScan_join_type(arg0, arg1)
}

func ResolvedJoinScan_set_join_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedJoinScan_set_join_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedJoinScan_set_join_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedJoinScan_set_join_type(arg0, arg1)
}

func ResolvedJoinScan_left_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedJoinScan_left_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedJoinScan_left_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedJoinScan_left_scan(arg0, arg1)
}

func ResolvedJoinScan_set_left_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedJoinScan_set_left_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedJoinScan_set_left_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedJoinScan_set_left_scan(arg0, arg1)
}

func ResolvedJoinScan_right_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedJoinScan_right_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedJoinScan_right_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedJoinScan_right_scan(arg0, arg1)
}

func ResolvedJoinScan_set_right_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedJoinScan_set_right_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedJoinScan_set_right_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedJoinScan_set_right_scan(arg0, arg1)
}

func ResolvedJoinScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedJoinScan_join_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedJoinScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedJoinScan_join_expr(arg0, arg1)
}

func ResolvedJoinScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedJoinScan_set_join_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedJoinScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedJoinScan_set_join_expr(arg0, arg1)
}

func ResolvedArrayScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArrayScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_input_scan(arg0, arg1)
}

func ResolvedArrayScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArrayScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_set_input_scan(arg0, arg1)
}

func ResolvedArrayScan_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArrayScan_array_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_array_expr(arg0, arg1)
}

func ResolvedArrayScan_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArrayScan_set_array_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_set_array_expr(arg0, arg1)
}

func ResolvedArrayScan_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArrayScan_element_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_element_column(arg0, arg1)
}

func ResolvedArrayScan_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArrayScan_set_element_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_set_element_column(arg0, arg1)
}

func ResolvedArrayScan_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArrayScan_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_array_offset_column(arg0, arg1)
}

func ResolvedArrayScan_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArrayScan_set_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_set_array_offset_column(arg0, arg1)
}

func ResolvedArrayScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArrayScan_join_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_join_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_join_expr(arg0, arg1)
}

func ResolvedArrayScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArrayScan_set_join_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArrayScan_set_join_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArrayScan_set_join_expr(arg0, arg1)
}

func ResolvedArrayScan_is_outer(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedArrayScan_is_outer(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedArrayScan_is_outer(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedArrayScan_is_outer(arg0, arg1)
}

func ResolvedArrayScan_set_is_outer(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedArrayScan_set_is_outer(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedArrayScan_set_is_outer(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedArrayScan_set_is_outer(arg0, arg1)
}

func ResolvedColumnHolder_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnHolder_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnHolder_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnHolder_column(arg0, arg1)
}

func ResolvedColumnHolder_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnHolder_set_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnHolder_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnHolder_set_column(arg0, arg1)
}

func ResolvedFilterScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFilterScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterScan_input_scan(arg0, arg1)
}

func ResolvedFilterScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFilterScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterScan_set_input_scan(arg0, arg1)
}

func ResolvedFilterScan_filter_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFilterScan_filter_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterScan_filter_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterScan_filter_expr(arg0, arg1)
}

func ResolvedFilterScan_set_filter_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFilterScan_set_filter_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterScan_set_filter_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterScan_set_filter_expr(arg0, arg1)
}

func ResolvedGroupingSet_group_by_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGroupingSet_group_by_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupingSet_group_by_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupingSet_group_by_column_list(arg0, arg1)
}

func ResolvedGroupingSet_set_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGroupingSet_set_group_by_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupingSet_set_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupingSet_set_group_by_column_list(arg0, arg1)
}

func ResolvedGroupingSet_add_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGroupingSet_add_group_by_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupingSet_add_group_by_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupingSet_add_group_by_column_list(arg0, arg1)
}

func ResolvedAggregateScanBase_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_input_scan(arg0, arg1)
}

func ResolvedAggregateScanBase_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_set_input_scan(arg0, arg1)
}

func ResolvedAggregateScanBase_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_group_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_set_group_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_set_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_add_group_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_add_group_by_list(arg0, arg1)
}

func ResolvedAggregateScanBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_collation_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_collation_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_set_collation_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_set_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_set_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_add_collation_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_add_collation_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_add_collation_list(arg0, arg1)
}

func ResolvedAggregateScanBase_aggregate_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_aggregate_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_aggregate_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScanBase_set_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_set_aggregate_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_set_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_set_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScanBase_add_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScanBase_add_aggregate_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScanBase_add_aggregate_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScanBase_add_aggregate_list(arg0, arg1)
}

func ResolvedAggregateScan_grouping_set_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateScan_grouping_set_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScan_grouping_set_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScan_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_set_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScan_set_grouping_set_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScan_set_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScan_set_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_add_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScan_add_grouping_set_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScan_add_grouping_set_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScan_add_grouping_set_list(arg0, arg1)
}

func ResolvedAggregateScan_rollup_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateScan_rollup_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScan_rollup_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScan_rollup_column_list(arg0, arg1)
}

func ResolvedAggregateScan_set_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScan_set_rollup_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScan_set_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScan_set_rollup_column_list(arg0, arg1)
}

func ResolvedAggregateScan_add_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateScan_add_rollup_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateScan_add_rollup_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateScan_add_rollup_column_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnonymizedAggregateScan_k_threshold_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnonymizedAggregateScan_k_threshold_expr(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnonymizedAggregateScan_set_k_threshold_expr(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnonymizedAggregateScan_anonymization_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnonymizedAggregateScan_anonymization_option_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnonymizedAggregateScan_set_anonymization_option_list(arg0, arg1)
}

func ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnonymizedAggregateScan_add_anonymization_option_list(arg0, arg1)
}

func ResolvedSetOperationItem_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetOperationItem_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationItem_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationItem_scan(arg0, arg1)
}

func ResolvedSetOperationItem_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetOperationItem_set_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationItem_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationItem_set_scan(arg0, arg1)
}

func ResolvedSetOperationItem_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetOperationItem_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationItem_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationItem_output_column_list(arg0, arg1)
}

func ResolvedSetOperationItem_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetOperationItem_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationItem_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationItem_set_output_column_list(arg0, arg1)
}

func ResolvedSetOperationItem_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetOperationItem_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationItem_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationItem_add_output_column_list(arg0, arg1)
}

func ResolvedSetOperationScan_op_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedSetOperationScan_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedSetOperationScan_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedSetOperationScan_op_type(arg0, arg1)
}

func ResolvedSetOperationScan_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedSetOperationScan_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedSetOperationScan_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedSetOperationScan_set_op_type(arg0, arg1)
}

func ResolvedSetOperationScan_input_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetOperationScan_input_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationScan_input_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationScan_input_item_list(arg0, arg1)
}

func ResolvedSetOperationScan_set_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetOperationScan_set_input_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationScan_set_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationScan_set_input_item_list(arg0, arg1)
}

func ResolvedSetOperationScan_add_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetOperationScan_add_input_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOperationScan_add_input_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOperationScan_add_input_item_list(arg0, arg1)
}

func ResolvedOrderByScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOrderByScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByScan_input_scan(arg0, arg1)
}

func ResolvedOrderByScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOrderByScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByScan_set_input_scan(arg0, arg1)
}

func ResolvedOrderByScan_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOrderByScan_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByScan_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByScan_order_by_item_list(arg0, arg1)
}

func ResolvedOrderByScan_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOrderByScan_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByScan_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByScan_set_order_by_item_list(arg0, arg1)
}

func ResolvedOrderByScan_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOrderByScan_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByScan_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByScan_add_order_by_item_list(arg0, arg1)
}

func ResolvedLimitOffsetScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedLimitOffsetScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLimitOffsetScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedLimitOffsetScan_input_scan(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedLimitOffsetScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLimitOffsetScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedLimitOffsetScan_set_input_scan(arg0, arg1)
}

func ResolvedLimitOffsetScan_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedLimitOffsetScan_limit(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLimitOffsetScan_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedLimitOffsetScan_limit(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedLimitOffsetScan_set_limit(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLimitOffsetScan_set_limit(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedLimitOffsetScan_set_limit(arg0, arg1)
}

func ResolvedLimitOffsetScan_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedLimitOffsetScan_offset(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLimitOffsetScan_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedLimitOffsetScan_offset(arg0, arg1)
}

func ResolvedLimitOffsetScan_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedLimitOffsetScan_set_offset(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedLimitOffsetScan_set_offset(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedLimitOffsetScan_set_offset(arg0, arg1)
}

func ResolvedWithRefScan_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWithRefScan_with_query_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithRefScan_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWithRefScan_with_query_name(arg0, arg1)
}

func ResolvedWithRefScan_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithRefScan_set_with_query_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithRefScan_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithRefScan_set_with_query_name(arg0, arg1)
}

func ResolvedAnalyticScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyticScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticScan_input_scan(arg0, arg1)
}

func ResolvedAnalyticScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticScan_set_input_scan(arg0, arg1)
}

func ResolvedAnalyticScan_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyticScan_function_group_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticScan_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticScan_function_group_list(arg0, arg1)
}

func ResolvedAnalyticScan_set_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticScan_set_function_group_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticScan_set_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticScan_set_function_group_list(arg0, arg1)
}

func ResolvedAnalyticScan_add_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticScan_add_function_group_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticScan_add_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticScan_add_function_group_list(arg0, arg1)
}

func ResolvedSampleScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSampleScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_input_scan(arg0, arg1)
}

func ResolvedSampleScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSampleScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_set_input_scan(arg0, arg1)
}

func ResolvedSampleScan_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSampleScan_method(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_method(arg0, arg1)
}

func ResolvedSampleScan_set_method(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSampleScan_set_method(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_set_method(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_set_method(arg0, arg1)
}

func ResolvedSampleScan_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSampleScan_size(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_size(arg0, arg1)
}

func ResolvedSampleScan_set_size(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSampleScan_set_size(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_set_size(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_set_size(arg0, arg1)
}

func ResolvedSampleScan_unit(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedSampleScan_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedSampleScan_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedSampleScan_unit(arg0, arg1)
}

func ResolvedSampleScan_set_unit(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedSampleScan_set_unit(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedSampleScan_set_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedSampleScan_set_unit(arg0, arg1)
}

func ResolvedSampleScan_repeatable_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSampleScan_repeatable_argument(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_repeatable_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_repeatable_argument(arg0, arg1)
}

func ResolvedSampleScan_set_repeatable_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSampleScan_set_repeatable_argument(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_set_repeatable_argument(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_set_repeatable_argument(arg0, arg1)
}

func ResolvedSampleScan_weight_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSampleScan_weight_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_weight_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_weight_column(arg0, arg1)
}

func ResolvedSampleScan_set_weight_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSampleScan_set_weight_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_set_weight_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_set_weight_column(arg0, arg1)
}

func ResolvedSampleScan_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSampleScan_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_partition_by_list(arg0, arg1)
}

func ResolvedSampleScan_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSampleScan_set_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_set_partition_by_list(arg0, arg1)
}

func ResolvedSampleScan_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSampleScan_add_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSampleScan_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSampleScan_add_partition_by_list(arg0, arg1)
}

func ResolvedComputedColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedComputedColumn_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedComputedColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedComputedColumn_column(arg0, arg1)
}

func ResolvedComputedColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedComputedColumn_set_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedComputedColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedComputedColumn_set_column(arg0, arg1)
}

func ResolvedComputedColumn_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedComputedColumn_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedComputedColumn_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedComputedColumn_expr(arg0, arg1)
}

func ResolvedComputedColumn_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedComputedColumn_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedComputedColumn_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedComputedColumn_set_expr(arg0, arg1)
}

func ResolvedOrderByItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOrderByItem_column_ref(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByItem_column_ref(arg0, arg1)
}

func ResolvedOrderByItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOrderByItem_set_column_ref(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByItem_set_column_ref(arg0, arg1)
}

func ResolvedOrderByItem_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOrderByItem_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByItem_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByItem_collation_name(arg0, arg1)
}

func ResolvedOrderByItem_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOrderByItem_set_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByItem_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByItem_set_collation_name(arg0, arg1)
}

func ResolvedOrderByItem_is_descending(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedOrderByItem_is_descending(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedOrderByItem_is_descending(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedOrderByItem_is_descending(arg0, arg1)
}

func ResolvedOrderByItem_set_is_descending(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedOrderByItem_set_is_descending(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedOrderByItem_set_is_descending(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedOrderByItem_set_is_descending(arg0, arg1)
}

func ResolvedOrderByItem_null_order(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedOrderByItem_null_order(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedOrderByItem_null_order(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedOrderByItem_null_order(arg0, arg1)
}

func ResolvedOrderByItem_set_null_order(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedOrderByItem_set_null_order(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedOrderByItem_set_null_order(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedOrderByItem_set_null_order(arg0, arg1)
}

func ResolvedOrderByItem_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOrderByItem_collation(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByItem_collation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByItem_collation(arg0, arg1)
}

func ResolvedOrderByItem_set_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOrderByItem_set_collation(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOrderByItem_set_collation(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOrderByItem_set_collation(arg0, arg1)
}

func ResolvedColumnAnnotations_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_collation_name(arg0, arg1)
}

func ResolvedColumnAnnotations_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_set_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_set_collation_name(arg0, arg1)
}

func ResolvedColumnAnnotations_not_null(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedColumnAnnotations_not_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedColumnAnnotations_not_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedColumnAnnotations_not_null(arg0, arg1)
}

func ResolvedColumnAnnotations_set_not_null(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedColumnAnnotations_set_not_null(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedColumnAnnotations_set_not_null(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedColumnAnnotations_set_not_null(arg0, arg1)
}

func ResolvedColumnAnnotations_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_set_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_add_option_list(arg0, arg1)
}

func ResolvedColumnAnnotations_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_child_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_set_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_set_child_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_set_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_set_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_add_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_add_child_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_add_child_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_add_child_list(arg0, arg1)
}

func ResolvedColumnAnnotations_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_type_parameters(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_type_parameters(arg0, arg1)
}

func ResolvedColumnAnnotations_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnAnnotations_set_type_parameters(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnAnnotations_set_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnAnnotations_set_type_parameters(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGeneratedColumnInfo_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGeneratedColumnInfo_expression(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGeneratedColumnInfo_set_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGeneratedColumnInfo_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGeneratedColumnInfo_set_expression(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedGeneratedColumnInfo_stored_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedGeneratedColumnInfo_stored_mode(arg0, arg1)
}

func ResolvedGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedGeneratedColumnInfo_set_stored_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedGeneratedColumnInfo_set_stored_mode(arg0, arg1)
}

func ResolvedColumnDefaultValue_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefaultValue_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefaultValue_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefaultValue_expression(arg0, arg1)
}

func ResolvedColumnDefaultValue_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefaultValue_set_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefaultValue_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefaultValue_set_expression(arg0, arg1)
}

func ResolvedColumnDefaultValue_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefaultValue_sql(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefaultValue_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefaultValue_sql(arg0, arg1)
}

func ResolvedColumnDefaultValue_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefaultValue_set_sql(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefaultValue_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefaultValue_set_sql(arg0, arg1)
}

func ResolvedColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_name(arg0, arg1)
}

func ResolvedColumnDefinition_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_set_name(arg0, arg1)
}

func ResolvedColumnDefinition_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_type(arg0, arg1)
}

func ResolvedColumnDefinition_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_set_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_set_type(arg0, arg1)
}

func ResolvedColumnDefinition_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_annotations(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_annotations(arg0, arg1)
}

func ResolvedColumnDefinition_set_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_set_annotations(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_set_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_set_annotations(arg0, arg1)
}

func ResolvedColumnDefinition_is_hidden(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedColumnDefinition_is_hidden(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedColumnDefinition_is_hidden(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedColumnDefinition_is_hidden(arg0, arg1)
}

func ResolvedColumnDefinition_set_is_hidden(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedColumnDefinition_set_is_hidden(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedColumnDefinition_set_is_hidden(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedColumnDefinition_set_is_hidden(arg0, arg1)
}

func ResolvedColumnDefinition_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_column(arg0, arg1)
}

func ResolvedColumnDefinition_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_set_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_set_column(arg0, arg1)
}

func ResolvedColumnDefinition_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_generated_column_info(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_generated_column_info(arg0, arg1)
}

func ResolvedColumnDefinition_set_generated_column_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_set_generated_column_info(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_set_generated_column_info(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_set_generated_column_info(arg0, arg1)
}

func ResolvedColumnDefinition_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_default_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_default_value(arg0, arg1)
}

func ResolvedColumnDefinition_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedColumnDefinition_set_default_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumnDefinition_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumnDefinition_set_default_value(arg0, arg1)
}

func ResolvedPrimaryKey_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_column_offset_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_set_column_offset_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_set_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_set_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedPrimaryKey_add_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedPrimaryKey_add_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedPrimaryKey_add_column_offset_list(arg0, arg1)
}

func ResolvedPrimaryKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_set_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_add_option_list(arg0, arg1)
}

func ResolvedPrimaryKey_unenforced(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedPrimaryKey_unenforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedPrimaryKey_unenforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedPrimaryKey_unenforced(arg0, arg1)
}

func ResolvedPrimaryKey_set_unenforced(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedPrimaryKey_set_unenforced(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedPrimaryKey_set_unenforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedPrimaryKey_set_unenforced(arg0, arg1)
}

func ResolvedPrimaryKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_constraint_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_constraint_name(arg0, arg1)
}

func ResolvedPrimaryKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_set_constraint_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_set_constraint_name(arg0, arg1)
}

func ResolvedPrimaryKey_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_column_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_column_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_column_name_list(arg0, arg1)
}

func ResolvedPrimaryKey_set_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_set_column_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_set_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_set_column_name_list(arg0, arg1)
}

func ResolvedPrimaryKey_add_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrimaryKey_add_column_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrimaryKey_add_column_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrimaryKey_add_column_name_list(arg0, arg1)
}

func ResolvedForeignKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedForeignKey_constraint_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_constraint_name(arg0, arg1)
}

func ResolvedForeignKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_set_constraint_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_set_constraint_name(arg0, arg1)
}

func ResolvedForeignKey_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedForeignKey_referencing_column_offset_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_set_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_set_referencing_column_offset_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_set_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_set_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_add_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedForeignKey_add_referencing_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedForeignKey_add_referencing_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedForeignKey_add_referencing_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_referenced_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedForeignKey_referenced_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_referenced_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_referenced_table(arg0, arg1)
}

func ResolvedForeignKey_set_referenced_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_set_referenced_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_set_referenced_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_set_referenced_table(arg0, arg1)
}

func ResolvedForeignKey_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedForeignKey_referenced_column_offset_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_set_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_set_referenced_column_offset_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_set_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_set_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_add_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedForeignKey_add_referenced_column_offset_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedForeignKey_add_referenced_column_offset_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedForeignKey_add_referenced_column_offset_list(arg0, arg1)
}

func ResolvedForeignKey_match_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedForeignKey_match_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedForeignKey_match_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedForeignKey_match_mode(arg0, arg1)
}

func ResolvedForeignKey_set_match_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedForeignKey_set_match_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedForeignKey_set_match_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedForeignKey_set_match_mode(arg0, arg1)
}

func ResolvedForeignKey_update_action(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedForeignKey_update_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedForeignKey_update_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedForeignKey_update_action(arg0, arg1)
}

func ResolvedForeignKey_set_update_action(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedForeignKey_set_update_action(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedForeignKey_set_update_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedForeignKey_set_update_action(arg0, arg1)
}

func ResolvedForeignKey_delete_action(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedForeignKey_delete_action(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedForeignKey_delete_action(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedForeignKey_delete_action(arg0, arg1)
}

func ResolvedForeignKey_set_delete_action(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedForeignKey_set_delete_action(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedForeignKey_set_delete_action(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedForeignKey_set_delete_action(arg0, arg1)
}

func ResolvedForeignKey_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedForeignKey_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedForeignKey_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedForeignKey_enforced(arg0, arg1)
}

func ResolvedForeignKey_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedForeignKey_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedForeignKey_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedForeignKey_set_enforced(arg0, arg1)
}

func ResolvedForeignKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedForeignKey_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_option_list(arg0, arg1)
}

func ResolvedForeignKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_set_option_list(arg0, arg1)
}

func ResolvedForeignKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_add_option_list(arg0, arg1)
}

func ResolvedForeignKey_referencing_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedForeignKey_referencing_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_referencing_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_referencing_column_list(arg0, arg1)
}

func ResolvedForeignKey_set_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_set_referencing_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_set_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_set_referencing_column_list(arg0, arg1)
}

func ResolvedForeignKey_add_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedForeignKey_add_referencing_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedForeignKey_add_referencing_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedForeignKey_add_referencing_column_list(arg0, arg1)
}

func ResolvedCheckConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCheckConstraint_constraint_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCheckConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCheckConstraint_constraint_name(arg0, arg1)
}

func ResolvedCheckConstraint_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCheckConstraint_set_constraint_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCheckConstraint_set_constraint_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCheckConstraint_set_constraint_name(arg0, arg1)
}

func ResolvedCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCheckConstraint_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCheckConstraint_expression(arg0, arg1)
}

func ResolvedCheckConstraint_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCheckConstraint_set_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCheckConstraint_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCheckConstraint_set_expression(arg0, arg1)
}

func ResolvedCheckConstraint_enforced(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCheckConstraint_enforced(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCheckConstraint_enforced(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCheckConstraint_enforced(arg0, arg1)
}

func ResolvedCheckConstraint_set_enforced(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCheckConstraint_set_enforced(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCheckConstraint_set_enforced(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCheckConstraint_set_enforced(arg0, arg1)
}

func ResolvedCheckConstraint_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCheckConstraint_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCheckConstraint_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCheckConstraint_option_list(arg0, arg1)
}

func ResolvedCheckConstraint_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCheckConstraint_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCheckConstraint_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCheckConstraint_set_option_list(arg0, arg1)
}

func ResolvedCheckConstraint_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCheckConstraint_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCheckConstraint_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCheckConstraint_add_option_list(arg0, arg1)
}

func ResolvedOutputColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOutputColumn_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOutputColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOutputColumn_name(arg0, arg1)
}

func ResolvedOutputColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOutputColumn_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOutputColumn_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOutputColumn_set_name(arg0, arg1)
}

func ResolvedOutputColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOutputColumn_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOutputColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOutputColumn_column(arg0, arg1)
}

func ResolvedOutputColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOutputColumn_set_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOutputColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOutputColumn_set_column(arg0, arg1)
}

func ResolvedProjectScan_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedProjectScan_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedProjectScan_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedProjectScan_expr_list(arg0, arg1)
}

func ResolvedProjectScan_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedProjectScan_set_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedProjectScan_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedProjectScan_set_expr_list(arg0, arg1)
}

func ResolvedProjectScan_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedProjectScan_add_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedProjectScan_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedProjectScan_add_expr_list(arg0, arg1)
}

func ResolvedProjectScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedProjectScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedProjectScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedProjectScan_input_scan(arg0, arg1)
}

func ResolvedProjectScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedProjectScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedProjectScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedProjectScan_set_input_scan(arg0, arg1)
}

func ResolvedTVFScan_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTVFScan_tvf(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_tvf(arg0, arg1)
}

func ResolvedTVFScan_set_tvf(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTVFScan_set_tvf(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_set_tvf(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_set_tvf(arg0, arg1)
}

func ResolvedTVFScan_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTVFScan_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_signature(arg0, arg1)
}

func ResolvedTVFScan_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTVFScan_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_set_signature(arg0, arg1)
}

func ResolvedTVFScan_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTVFScan_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_argument_list(arg0, arg1)
}

func ResolvedTVFScan_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTVFScan_set_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_set_argument_list(arg0, arg1)
}

func ResolvedTVFScan_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTVFScan_add_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_add_argument_list(arg0, arg1)
}

func ResolvedTVFScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTVFScan_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTVFScan_set_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_set_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedTVFScan_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedTVFScan_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedTVFScan_add_column_index_list(arg0, arg1)
}

func ResolvedTVFScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTVFScan_alias(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_alias(arg0, arg1)
}

func ResolvedTVFScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTVFScan_set_alias(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_set_alias(arg0, arg1)
}

func ResolvedTVFScan_function_call_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTVFScan_function_call_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_function_call_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_function_call_signature(arg0, arg1)
}

func ResolvedTVFScan_set_function_call_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTVFScan_set_function_call_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTVFScan_set_function_call_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTVFScan_set_function_call_signature(arg0, arg1)
}

func ResolvedGroupRowsScan_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGroupRowsScan_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupRowsScan_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupRowsScan_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_set_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGroupRowsScan_set_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupRowsScan_set_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupRowsScan_set_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_add_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGroupRowsScan_add_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupRowsScan_add_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupRowsScan_add_input_column_list(arg0, arg1)
}

func ResolvedGroupRowsScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGroupRowsScan_alias(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupRowsScan_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupRowsScan_alias(arg0, arg1)
}

func ResolvedGroupRowsScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGroupRowsScan_set_alias(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGroupRowsScan_set_alias(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGroupRowsScan_set_alias(arg0, arg1)
}

func ResolvedFunctionArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_expr(arg0, arg1)
}

func ResolvedFunctionArgument_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_set_expr(arg0, arg1)
}

func ResolvedFunctionArgument_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_scan(arg0, arg1)
}

func ResolvedFunctionArgument_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_set_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_set_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_set_scan(arg0, arg1)
}

func ResolvedFunctionArgument_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_model(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_model(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_model(arg0, arg1)
}

func ResolvedFunctionArgument_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_set_model(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_set_model(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_set_model(arg0, arg1)
}

func ResolvedFunctionArgument_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_connection(arg0, arg1)
}

func ResolvedFunctionArgument_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_set_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_set_connection(arg0, arg1)
}

func ResolvedFunctionArgument_descriptor_arg(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_descriptor_arg(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_descriptor_arg(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_descriptor_arg(arg0, arg1)
}

func ResolvedFunctionArgument_set_descriptor_arg(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_set_descriptor_arg(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_set_descriptor_arg(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_set_descriptor_arg(arg0, arg1)
}

func ResolvedFunctionArgument_argument_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_argument_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_argument_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_set_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_set_argument_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_set_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_set_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_add_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_add_argument_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_add_argument_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_add_argument_column_list(arg0, arg1)
}

func ResolvedFunctionArgument_inline_lambda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_inline_lambda(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_inline_lambda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_inline_lambda(arg0, arg1)
}

func ResolvedFunctionArgument_set_inline_lambda(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionArgument_set_inline_lambda(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionArgument_set_inline_lambda(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionArgument_set_inline_lambda(arg0, arg1)
}

func ResolvedStatement_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedStatement_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedStatement_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedStatement_hint_list(arg0, arg1)
}

func ResolvedStatement_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedStatement_set_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedStatement_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedStatement_set_hint_list(arg0, arg1)
}

func ResolvedStatement_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedStatement_add_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedStatement_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedStatement_add_hint_list(arg0, arg1)
}

func ResolvedExplainStmt_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExplainStmt_statement(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExplainStmt_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExplainStmt_statement(arg0, arg1)
}

func ResolvedExplainStmt_set_statement(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExplainStmt_set_statement(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExplainStmt_set_statement(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExplainStmt_set_statement(arg0, arg1)
}

func ResolvedQueryStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedQueryStmt_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedQueryStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedQueryStmt_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedQueryStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedQueryStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedQueryStmt_set_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedQueryStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedQueryStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedQueryStmt_add_output_column_list(arg0, arg1)
}

func ResolvedQueryStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedQueryStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedQueryStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedQueryStmt_is_value_table(arg0, arg1)
}

func ResolvedQueryStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedQueryStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedQueryStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedQueryStmt_set_is_value_table(arg0, arg1)
}

func ResolvedQueryStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedQueryStmt_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedQueryStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedQueryStmt_query(arg0, arg1)
}

func ResolvedQueryStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedQueryStmt_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedQueryStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedQueryStmt_set_query(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateDatabaseStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateDatabaseStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateDatabaseStmt_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateDatabaseStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateDatabaseStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateDatabaseStmt_set_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateDatabaseStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateDatabaseStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateDatabaseStmt_add_name_path(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateDatabaseStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateDatabaseStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateDatabaseStmt_option_list(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateDatabaseStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateDatabaseStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateDatabaseStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateDatabaseStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateDatabaseStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateDatabaseStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateDatabaseStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateStatement_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateStatement_name_path(arg0, arg1)
}

func ResolvedCreateStatement_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateStatement_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateStatement_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateStatement_set_name_path(arg0, arg1)
}

func ResolvedCreateStatement_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateStatement_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateStatement_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateStatement_add_name_path(arg0, arg1)
}

func ResolvedCreateStatement_create_scope(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedCreateStatement_create_scope(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateStatement_create_scope(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedCreateStatement_create_scope(arg0, arg1)
}

func ResolvedCreateStatement_set_create_scope(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateStatement_set_create_scope(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateStatement_set_create_scope(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateStatement_set_create_scope(arg0, arg1)
}

func ResolvedCreateStatement_create_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedCreateStatement_create_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateStatement_create_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedCreateStatement_create_mode(arg0, arg1)
}

func ResolvedCreateStatement_set_create_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateStatement_set_create_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateStatement_set_create_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateStatement_set_create_mode(arg0, arg1)
}

func ResolvedIndexItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedIndexItem_column_ref(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedIndexItem_column_ref(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedIndexItem_column_ref(arg0, arg1)
}

func ResolvedIndexItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedIndexItem_set_column_ref(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedIndexItem_set_column_ref(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedIndexItem_set_column_ref(arg0, arg1)
}

func ResolvedIndexItem_descending(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedIndexItem_descending(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedIndexItem_descending(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedIndexItem_descending(arg0, arg1)
}

func ResolvedIndexItem_set_descending(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedIndexItem_set_descending(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedIndexItem_set_descending(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedIndexItem_set_descending(arg0, arg1)
}

func ResolvedUnnestItem_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnnestItem_array_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnnestItem_array_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnnestItem_array_expr(arg0, arg1)
}

func ResolvedUnnestItem_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnnestItem_set_array_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnnestItem_set_array_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnnestItem_set_array_expr(arg0, arg1)
}

func ResolvedUnnestItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnnestItem_element_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnnestItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnnestItem_element_column(arg0, arg1)
}

func ResolvedUnnestItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnnestItem_set_element_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnnestItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnnestItem_set_element_column(arg0, arg1)
}

func ResolvedUnnestItem_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnnestItem_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnnestItem_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnnestItem_array_offset_column(arg0, arg1)
}

func ResolvedUnnestItem_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnnestItem_set_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnnestItem_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnnestItem_set_array_offset_column(arg0, arg1)
}

func ResolvedCreateIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_table_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_set_table_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_add_table_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_add_table_name_path(arg0, arg1)
}

func ResolvedCreateIndexStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_table_scan(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateIndexStmt_is_unique(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateIndexStmt_is_unique(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateIndexStmt_is_unique(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateIndexStmt_is_unique(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_is_unique(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateIndexStmt_set_is_unique(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateIndexStmt_set_is_unique(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_is_unique(arg0, arg1)
}

func ResolvedCreateIndexStmt_is_search(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateIndexStmt_is_search(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateIndexStmt_is_search(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateIndexStmt_is_search(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_is_search(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateIndexStmt_set_is_search(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateIndexStmt_set_is_search(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_is_search(arg0, arg1)
}

func ResolvedCreateIndexStmt_index_all_columns(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateIndexStmt_index_all_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateIndexStmt_index_all_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateIndexStmt_index_all_columns(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_index_all_columns(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateIndexStmt_set_index_all_columns(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateIndexStmt_set_index_all_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_index_all_columns(arg0, arg1)
}

func ResolvedCreateIndexStmt_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_index_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_set_index_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_set_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_add_index_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_add_index_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_add_index_item_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_storing_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_storing_expression_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_storing_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_set_storing_expression_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_set_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_add_storing_expression_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_add_storing_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_add_storing_expression_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_computed_columns_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_computed_columns_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_computed_columns_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_set_computed_columns_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_set_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_add_computed_columns_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_add_computed_columns_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_add_computed_columns_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_unnest_expressions_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_unnest_expressions_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_set_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_set_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateIndexStmt_add_unnest_expressions_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateIndexStmt_add_unnest_expressions_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateSchemaStmt_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSchemaStmt_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSchemaStmt_collation_name(arg0, arg1)
}

func ResolvedCreateSchemaStmt_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateSchemaStmt_set_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSchemaStmt_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSchemaStmt_set_collation_name(arg0, arg1)
}

func ResolvedCreateSchemaStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateSchemaStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSchemaStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSchemaStmt_option_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateSchemaStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSchemaStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSchemaStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateSchemaStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateSchemaStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSchemaStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSchemaStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_add_option_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_add_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_pseudo_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_pseudo_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_add_pseudo_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_add_pseudo_column_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_primary_key(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_primary_key(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_primary_key(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_primary_key(arg0, arg1)
}

func ResolvedCreateTableStmtBase_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_foreign_key_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_foreign_key_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_add_foreign_key_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_add_foreign_key_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_check_constraint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_check_constraint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_add_check_constraint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_add_check_constraint_list(arg0, arg1)
}

func ResolvedCreateTableStmtBase_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateTableStmtBase_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateTableStmtBase_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateTableStmtBase_is_value_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateTableStmtBase_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_is_value_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_like_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_like_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_like_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_like_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_like_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_like_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_like_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_like_table(arg0, arg1)
}

func ResolvedCreateTableStmtBase_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_collation_name(arg0, arg1)
}

func ResolvedCreateTableStmtBase_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmtBase_set_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmtBase_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmtBase_set_collation_name(arg0, arg1)
}

func ResolvedCreateTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_clone_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_clone_from(arg0, arg1)
}

func ResolvedCreateTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_set_clone_from(arg0, arg1)
}

func ResolvedCreateTableStmt_copy_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_copy_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_copy_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_copy_from(arg0, arg1)
}

func ResolvedCreateTableStmt_set_copy_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_set_copy_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_set_copy_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_set_copy_from(arg0, arg1)
}

func ResolvedCreateTableStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_query(arg0, arg1)
}

func ResolvedCreateTableAsSelectStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableAsSelectStmt_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableAsSelectStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableAsSelectStmt_set_query(arg0, arg1)
}

func ResolvedCreateModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateModelStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_query(arg0, arg1)
}

func ResolvedCreateModelStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_set_query(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_transform_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_transform_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_set_transform_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_set_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_set_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_add_transform_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_add_transform_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_add_transform_input_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_transform_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_transform_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_set_transform_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_set_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_set_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_add_transform_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_add_transform_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_add_transform_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_transform_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_transform_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_set_transform_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_set_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_set_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_add_transform_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_add_transform_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_add_transform_output_column_list(arg0, arg1)
}

func ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_set_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateModelStmt_add_transform_analytic_function_group_list(arg0, arg1)
}

func ResolvedCreateViewBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_set_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_add_option_list(arg0, arg1)
}

func ResolvedCreateViewBase_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_set_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_add_output_column_list(arg0, arg1)
}

func ResolvedCreateViewBase_has_explicit_columns(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateViewBase_has_explicit_columns(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateViewBase_has_explicit_columns(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateViewBase_has_explicit_columns(arg0, arg1)
}

func ResolvedCreateViewBase_set_has_explicit_columns(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateViewBase_set_has_explicit_columns(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateViewBase_set_has_explicit_columns(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateViewBase_set_has_explicit_columns(arg0, arg1)
}

func ResolvedCreateViewBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_query(arg0, arg1)
}

func ResolvedCreateViewBase_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_set_query(arg0, arg1)
}

func ResolvedCreateViewBase_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_sql(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_sql(arg0, arg1)
}

func ResolvedCreateViewBase_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateViewBase_set_sql(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateViewBase_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateViewBase_set_sql(arg0, arg1)
}

func ResolvedCreateViewBase_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedCreateViewBase_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateViewBase_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedCreateViewBase_sql_security(arg0, arg1)
}

func ResolvedCreateViewBase_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateViewBase_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateViewBase_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateViewBase_set_sql_security(arg0, arg1)
}

func ResolvedCreateViewBase_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateViewBase_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateViewBase_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateViewBase_is_value_table(arg0, arg1)
}

func ResolvedCreateViewBase_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateViewBase_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateViewBase_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateViewBase_set_is_value_table(arg0, arg1)
}

func ResolvedCreateViewBase_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateViewBase_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateViewBase_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateViewBase_recursive(arg0, arg1)
}

func ResolvedCreateViewBase_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateViewBase_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateViewBase_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateViewBase_set_recursive(arg0, arg1)
}

func ResolvedWithPartitionColumns_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWithPartitionColumns_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithPartitionColumns_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWithPartitionColumns_column_definition_list(arg0, arg1)
}

func ResolvedWithPartitionColumns_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithPartitionColumns_set_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithPartitionColumns_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithPartitionColumns_set_column_definition_list(arg0, arg1)
}

func ResolvedWithPartitionColumns_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithPartitionColumns_add_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithPartitionColumns_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithPartitionColumns_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateSnapshotTableStmt_clone_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSnapshotTableStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSnapshotTableStmt_clone_from(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateSnapshotTableStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSnapshotTableStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSnapshotTableStmt_set_clone_from(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateSnapshotTableStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSnapshotTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSnapshotTableStmt_option_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateSnapshotTableStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSnapshotTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSnapshotTableStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateSnapshotTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateSnapshotTableStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateSnapshotTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateSnapshotTableStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateExternalTableStmt_with_partition_columns(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateExternalTableStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateExternalTableStmt_with_partition_columns(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateExternalTableStmt_set_with_partition_columns(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateExternalTableStmt_set_with_partition_columns(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateExternalTableStmt_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateExternalTableStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateExternalTableStmt_connection(arg0, arg1)
}

func ResolvedCreateExternalTableStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateExternalTableStmt_set_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateExternalTableStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateExternalTableStmt_set_connection(arg0, arg1)
}

func ResolvedExportModelStmt_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_model_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_set_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_set_model_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_set_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_set_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_add_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_add_model_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_add_model_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_add_model_name_path(arg0, arg1)
}

func ResolvedExportModelStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_connection(arg0, arg1)
}

func ResolvedExportModelStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_set_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_set_connection(arg0, arg1)
}

func ResolvedExportModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_option_list(arg0, arg1)
}

func ResolvedExportModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_set_option_list(arg0, arg1)
}

func ResolvedExportModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportModelStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportModelStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportModelStmt_add_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_connection(arg0, arg1)
}

func ResolvedExportDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_set_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_set_connection(arg0, arg1)
}

func ResolvedExportDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_set_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_add_option_list(arg0, arg1)
}

func ResolvedExportDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_set_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_add_output_column_list(arg0, arg1)
}

func ResolvedExportDataStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedExportDataStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedExportDataStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedExportDataStmt_is_value_table(arg0, arg1)
}

func ResolvedExportDataStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedExportDataStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedExportDataStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedExportDataStmt_set_is_value_table(arg0, arg1)
}

func ResolvedExportDataStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_query(arg0, arg1)
}

func ResolvedExportDataStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExportDataStmt_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExportDataStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExportDataStmt_set_query(arg0, arg1)
}

func ResolvedDefineTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDefineTableStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDefineTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDefineTableStmt_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDefineTableStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDefineTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDefineTableStmt_set_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDefineTableStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDefineTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDefineTableStmt_add_name_path(arg0, arg1)
}

func ResolvedDefineTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDefineTableStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDefineTableStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDefineTableStmt_option_list(arg0, arg1)
}

func ResolvedDefineTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDefineTableStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDefineTableStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDefineTableStmt_set_option_list(arg0, arg1)
}

func ResolvedDefineTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDefineTableStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDefineTableStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDefineTableStmt_add_option_list(arg0, arg1)
}

func ResolvedDescribeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_object_type(arg0, arg1)
}

func ResolvedDescribeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_set_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_set_object_type(arg0, arg1)
}

func ResolvedDescribeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_set_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_add_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_from_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_from_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_from_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_from_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_set_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_set_from_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_set_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_set_from_name_path(arg0, arg1)
}

func ResolvedDescribeStmt_add_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDescribeStmt_add_from_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDescribeStmt_add_from_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDescribeStmt_add_from_name_path(arg0, arg1)
}

func ResolvedShowStmt_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedShowStmt_identifier(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedShowStmt_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedShowStmt_identifier(arg0, arg1)
}

func ResolvedShowStmt_set_identifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedShowStmt_set_identifier(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedShowStmt_set_identifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedShowStmt_set_identifier(arg0, arg1)
}

func ResolvedShowStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedShowStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedShowStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedShowStmt_name_path(arg0, arg1)
}

func ResolvedShowStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedShowStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedShowStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedShowStmt_set_name_path(arg0, arg1)
}

func ResolvedShowStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedShowStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedShowStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedShowStmt_add_name_path(arg0, arg1)
}

func ResolvedShowStmt_like_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedShowStmt_like_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedShowStmt_like_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedShowStmt_like_expr(arg0, arg1)
}

func ResolvedShowStmt_set_like_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedShowStmt_set_like_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedShowStmt_set_like_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedShowStmt_set_like_expr(arg0, arg1)
}

func ResolvedBeginStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedBeginStmt_read_write_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedBeginStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedBeginStmt_read_write_mode(arg0, arg1)
}

func ResolvedBeginStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedBeginStmt_set_read_write_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedBeginStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedBeginStmt_set_read_write_mode(arg0, arg1)
}

func ResolvedBeginStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedBeginStmt_isolation_level_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedBeginStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedBeginStmt_isolation_level_list(arg0, arg1)
}

func ResolvedBeginStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedBeginStmt_set_isolation_level_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedBeginStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedBeginStmt_set_isolation_level_list(arg0, arg1)
}

func ResolvedBeginStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedBeginStmt_add_isolation_level_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedBeginStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedBeginStmt_add_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedSetTransactionStmt_read_write_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedSetTransactionStmt_read_write_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedSetTransactionStmt_read_write_mode(arg0, arg1)
}

func ResolvedSetTransactionStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedSetTransactionStmt_set_read_write_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedSetTransactionStmt_set_read_write_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedSetTransactionStmt_set_read_write_mode(arg0, arg1)
}

func ResolvedSetTransactionStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetTransactionStmt_isolation_level_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetTransactionStmt_isolation_level_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetTransactionStmt_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetTransactionStmt_set_isolation_level_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetTransactionStmt_set_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetTransactionStmt_set_isolation_level_list(arg0, arg1)
}

func ResolvedSetTransactionStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetTransactionStmt_add_isolation_level_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetTransactionStmt_add_isolation_level_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetTransactionStmt_add_isolation_level_list(arg0, arg1)
}

func ResolvedStartBatchStmt_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedStartBatchStmt_batch_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedStartBatchStmt_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedStartBatchStmt_batch_type(arg0, arg1)
}

func ResolvedStartBatchStmt_set_batch_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedStartBatchStmt_set_batch_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedStartBatchStmt_set_batch_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedStartBatchStmt_set_batch_type(arg0, arg1)
}

func ResolvedDropStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropStmt_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropStmt_object_type(arg0, arg1)
}

func ResolvedDropStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropStmt_set_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropStmt_set_object_type(arg0, arg1)
}

func ResolvedDropStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropStmt_name_path(arg0, arg1)
}

func ResolvedDropStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropStmt_set_name_path(arg0, arg1)
}

func ResolvedDropStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropStmt_add_name_path(arg0, arg1)
}

func ResolvedDropStmt_drop_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedDropStmt_drop_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropStmt_drop_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedDropStmt_drop_mode(arg0, arg1)
}

func ResolvedDropStmt_set_drop_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropStmt_set_drop_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropStmt_set_drop_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropStmt_set_drop_mode(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropMaterializedViewStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropMaterializedViewStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropMaterializedViewStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropMaterializedViewStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropMaterializedViewStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropMaterializedViewStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropMaterializedViewStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropMaterializedViewStmt_name_path(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropMaterializedViewStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropMaterializedViewStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropMaterializedViewStmt_set_name_path(arg0, arg1)
}

func ResolvedDropMaterializedViewStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropMaterializedViewStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropMaterializedViewStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropMaterializedViewStmt_add_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropSnapshotTableStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropSnapshotTableStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropSnapshotTableStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropSnapshotTableStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropSnapshotTableStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropSnapshotTableStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSnapshotTableStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSnapshotTableStmt_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropSnapshotTableStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSnapshotTableStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSnapshotTableStmt_set_name_path(arg0, arg1)
}

func ResolvedDropSnapshotTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropSnapshotTableStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSnapshotTableStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSnapshotTableStmt_add_name_path(arg0, arg1)
}

func ResolvedRecursiveScan_op_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedRecursiveScan_op_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedRecursiveScan_op_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedRecursiveScan_op_type(arg0, arg1)
}

func ResolvedRecursiveScan_set_op_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedRecursiveScan_set_op_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedRecursiveScan_set_op_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedRecursiveScan_set_op_type(arg0, arg1)
}

func ResolvedRecursiveScan_non_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRecursiveScan_non_recursive_term(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRecursiveScan_non_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRecursiveScan_non_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_set_non_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRecursiveScan_set_non_recursive_term(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRecursiveScan_set_non_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRecursiveScan_set_non_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRecursiveScan_recursive_term(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRecursiveScan_recursive_term(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRecursiveScan_recursive_term(arg0, arg1)
}

func ResolvedRecursiveScan_set_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRecursiveScan_set_recursive_term(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRecursiveScan_set_recursive_term(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRecursiveScan_set_recursive_term(arg0, arg1)
}

func ResolvedWithScan_with_entry_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWithScan_with_entry_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithScan_with_entry_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWithScan_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_set_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithScan_set_with_entry_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithScan_set_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithScan_set_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_add_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithScan_add_with_entry_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithScan_add_with_entry_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithScan_add_with_entry_list(arg0, arg1)
}

func ResolvedWithScan_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWithScan_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithScan_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWithScan_query(arg0, arg1)
}

func ResolvedWithScan_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithScan_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithScan_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithScan_set_query(arg0, arg1)
}

func ResolvedWithScan_recursive(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedWithScan_recursive(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedWithScan_recursive(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedWithScan_recursive(arg0, arg1)
}

func ResolvedWithScan_set_recursive(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedWithScan_set_recursive(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedWithScan_set_recursive(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedWithScan_set_recursive(arg0, arg1)
}

func ResolvedWithEntry_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWithEntry_with_query_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithEntry_with_query_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWithEntry_with_query_name(arg0, arg1)
}

func ResolvedWithEntry_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithEntry_set_with_query_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithEntry_set_with_query_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithEntry_set_with_query_name(arg0, arg1)
}

func ResolvedWithEntry_with_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWithEntry_with_subquery(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithEntry_with_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWithEntry_with_subquery(arg0, arg1)
}

func ResolvedWithEntry_set_with_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWithEntry_set_with_subquery(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWithEntry_set_with_subquery(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWithEntry_set_with_subquery(arg0, arg1)
}

func ResolvedOption_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOption_qualifier(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOption_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOption_qualifier(arg0, arg1)
}

func ResolvedOption_set_qualifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOption_set_qualifier(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOption_set_qualifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOption_set_qualifier(arg0, arg1)
}

func ResolvedOption_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOption_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOption_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOption_name(arg0, arg1)
}

func ResolvedOption_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOption_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOption_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOption_set_name(arg0, arg1)
}

func ResolvedOption_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedOption_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOption_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedOption_value(arg0, arg1)
}

func ResolvedOption_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedOption_set_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedOption_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedOption_set_value(arg0, arg1)
}

func ResolvedWindowPartitioning_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWindowPartitioning_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowPartitioning_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowPartitioning_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowPartitioning_set_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowPartitioning_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowPartitioning_set_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowPartitioning_add_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowPartitioning_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowPartitioning_add_partition_by_list(arg0, arg1)
}

func ResolvedWindowPartitioning_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWindowPartitioning_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowPartitioning_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowPartitioning_hint_list(arg0, arg1)
}

func ResolvedWindowPartitioning_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowPartitioning_set_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowPartitioning_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowPartitioning_set_hint_list(arg0, arg1)
}

func ResolvedWindowPartitioning_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowPartitioning_add_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowPartitioning_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowPartitioning_add_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWindowOrdering_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowOrdering_order_by_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowOrdering_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowOrdering_set_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowOrdering_set_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowOrdering_set_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowOrdering_add_order_by_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowOrdering_add_order_by_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowOrdering_add_order_by_item_list(arg0, arg1)
}

func ResolvedWindowOrdering_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWindowOrdering_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowOrdering_hint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowOrdering_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowOrdering_set_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowOrdering_set_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowOrdering_set_hint_list(arg0, arg1)
}

func ResolvedWindowOrdering_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowOrdering_add_hint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowOrdering_add_hint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowOrdering_add_hint_list(arg0, arg1)
}

func ResolvedWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedWindowFrame_frame_unit(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedWindowFrame_frame_unit(arg0, arg1)
}

func ResolvedWindowFrame_set_frame_unit(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedWindowFrame_set_frame_unit(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedWindowFrame_set_frame_unit(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedWindowFrame_set_frame_unit(arg0, arg1)
}

func ResolvedWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWindowFrame_start_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowFrame_start_expr(arg0, arg1)
}

func ResolvedWindowFrame_set_start_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowFrame_set_start_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowFrame_set_start_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowFrame_set_start_expr(arg0, arg1)
}

func ResolvedWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWindowFrame_end_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowFrame_end_expr(arg0, arg1)
}

func ResolvedWindowFrame_set_end_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowFrame_set_end_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowFrame_set_end_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowFrame_set_end_expr(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionGroup_partition_by(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionGroup_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionGroup_partition_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_partition_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionGroup_set_partition_by(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionGroup_set_partition_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionGroup_set_partition_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionGroup_order_by(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionGroup_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionGroup_order_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_order_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionGroup_set_order_by(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionGroup_set_order_by(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionGroup_set_order_by(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_analytic_function_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionGroup_analytic_function_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionGroup_analytic_function_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionGroup_analytic_function_list(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionGroup_set_analytic_function_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionGroup_set_analytic_function_list(arg0, arg1)
}

func ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyticFunctionGroup_add_analytic_function_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyticFunctionGroup_add_analytic_function_list(arg0, arg1)
}

func ResolvedWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedWindowFrameExpr_boundary_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedWindowFrameExpr_boundary_type(arg0, arg1)
}

func ResolvedWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedWindowFrameExpr_set_boundary_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedWindowFrameExpr_set_boundary_type(arg0, arg1)
}

func ResolvedWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedWindowFrameExpr_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowFrameExpr_expression(arg0, arg1)
}

func ResolvedWindowFrameExpr_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedWindowFrameExpr_set_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedWindowFrameExpr_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedWindowFrameExpr_set_expression(arg0, arg1)
}

func ResolvedDMLValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDMLValue_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDMLValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDMLValue_value(arg0, arg1)
}

func ResolvedDMLValue_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDMLValue_set_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDMLValue_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDMLValue_set_value(arg0, arg1)
}

func ResolvedAssertStmt_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAssertStmt_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssertStmt_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAssertStmt_expression(arg0, arg1)
}

func ResolvedAssertStmt_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAssertStmt_set_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssertStmt_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAssertStmt_set_expression(arg0, arg1)
}

func ResolvedAssertStmt_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAssertStmt_description(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssertStmt_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAssertStmt_description(arg0, arg1)
}

func ResolvedAssertStmt_set_description(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAssertStmt_set_description(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssertStmt_set_description(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAssertStmt_set_description(arg0, arg1)
}

func ResolvedAssertRowsModified_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAssertRowsModified_rows(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssertRowsModified_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAssertRowsModified_rows(arg0, arg1)
}

func ResolvedAssertRowsModified_set_rows(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAssertRowsModified_set_rows(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssertRowsModified_set_rows(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAssertRowsModified_set_rows(arg0, arg1)
}

func ResolvedInsertRow_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertRow_value_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertRow_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertRow_value_list(arg0, arg1)
}

func ResolvedInsertRow_set_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertRow_set_value_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertRow_set_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertRow_set_value_list(arg0, arg1)
}

func ResolvedInsertRow_add_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertRow_add_value_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertRow_add_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertRow_add_value_list(arg0, arg1)
}

func ResolvedInsertStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_table_scan(arg0, arg1)
}

func ResolvedInsertStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_table_scan(arg0, arg1)
}

func ResolvedInsertStmt_insert_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedInsertStmt_insert_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedInsertStmt_insert_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedInsertStmt_insert_mode(arg0, arg1)
}

func ResolvedInsertStmt_set_insert_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedInsertStmt_set_insert_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedInsertStmt_set_insert_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedInsertStmt_set_insert_mode(arg0, arg1)
}

func ResolvedInsertStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedInsertStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedInsertStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_returning(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_returning(arg0, arg1)
}

func ResolvedInsertStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_returning(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_returning(arg0, arg1)
}

func ResolvedInsertStmt_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_insert_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_insert_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_add_insert_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_add_insert_column_list(arg0, arg1)
}

func ResolvedInsertStmt_query_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_query_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_query_parameter_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_set_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_query_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_add_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_add_query_parameter_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_add_query_parameter_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_add_query_parameter_list(arg0, arg1)
}

func ResolvedInsertStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_query(arg0, arg1)
}

func ResolvedInsertStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_query(arg0, arg1)
}

func ResolvedInsertStmt_query_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_query_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_query_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_set_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_query_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_add_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_add_query_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_add_query_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_add_query_output_column_list(arg0, arg1)
}

func ResolvedInsertStmt_row_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_row_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_row_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_row_list(arg0, arg1)
}

func ResolvedInsertStmt_set_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_set_row_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_set_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_set_row_list(arg0, arg1)
}

func ResolvedInsertStmt_add_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedInsertStmt_add_row_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedInsertStmt_add_row_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedInsertStmt_add_row_list(arg0, arg1)
}

func ResolvedDeleteStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_table_scan(arg0, arg1)
}

func ResolvedDeleteStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_set_table_scan(arg0, arg1)
}

func ResolvedDeleteStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedDeleteStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedDeleteStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_returning(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_returning(arg0, arg1)
}

func ResolvedDeleteStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_set_returning(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_set_returning(arg0, arg1)
}

func ResolvedDeleteStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_array_offset_column(arg0, arg1)
}

func ResolvedDeleteStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_set_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_set_array_offset_column(arg0, arg1)
}

func ResolvedDeleteStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_where_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_where_expr(arg0, arg1)
}

func ResolvedDeleteStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDeleteStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDeleteStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDeleteStmt_set_where_expr(arg0, arg1)
}

func ResolvedUpdateItem_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_target(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_target(arg0, arg1)
}

func ResolvedUpdateItem_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_target(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_target(arg0, arg1)
}

func ResolvedUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_value(arg0, arg1)
}

func ResolvedUpdateItem_set_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_set_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_set_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_set_value(arg0, arg1)
}

func ResolvedUpdateItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_element_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_element_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_element_column(arg0, arg1)
}

func ResolvedUpdateItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_element_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_element_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_element_column(arg0, arg1)
}

func ResolvedUpdateItem_delete_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_delete_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_delete_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_set_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_delete_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_add_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_add_delete_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_add_delete_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_add_delete_list(arg0, arg1)
}

func ResolvedUpdateItem_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_update_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_update_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_update_list(arg0, arg1)
}

func ResolvedUpdateItem_set_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_update_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_update_list(arg0, arg1)
}

func ResolvedUpdateItem_add_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_add_update_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_add_update_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_add_update_list(arg0, arg1)
}

func ResolvedUpdateItem_insert_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_insert_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_insert_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_insert_list(arg0, arg1)
}

func ResolvedUpdateItem_set_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_insert_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_insert_list(arg0, arg1)
}

func ResolvedUpdateItem_add_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_add_insert_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_add_insert_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_add_insert_list(arg0, arg1)
}

func ResolvedUpdateItem_update_item_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_update_item_element_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_update_item_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_update_item_element_list(arg0, arg1)
}

func ResolvedUpdateItem_set_update_item_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_set_update_item_element_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_set_update_item_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_set_update_item_element_list(arg0, arg1)
}

func ResolvedUpdateItem_add_update_item_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItem_add_update_item_element_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItem_add_update_item_element_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItem_add_update_item_element_list(arg0, arg1)
}

func ResolvedUpdateItemElement_subscript(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItemElement_subscript(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItemElement_subscript(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItemElement_subscript(arg0, arg1)
}

func ResolvedUpdateItemElement_set_subscript(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItemElement_set_subscript(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItemElement_set_subscript(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItemElement_set_subscript(arg0, arg1)
}

func ResolvedUpdateItemElement_update_item(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateItemElement_update_item(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItemElement_update_item(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItemElement_update_item(arg0, arg1)
}

func ResolvedUpdateItemElement_set_update_item(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateItemElement_set_update_item(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateItemElement_set_update_item(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateItemElement_set_update_item(arg0, arg1)
}

func ResolvedUpdateItemElement_update_item_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedUpdateItemElement_update_item_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedUpdateItemElement_update_item_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedUpdateItemElement_update_item_mode(arg0, arg1)
}

func ResolvedUpdateItemElement_set_update_item_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedUpdateItemElement_set_update_item_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedUpdateItemElement_set_update_item_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedUpdateItemElement_set_update_item_mode(arg0, arg1)
}

func ResolvedUpdateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_table_scan(arg0, arg1)
}

func ResolvedUpdateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_table_scan(arg0, arg1)
}

func ResolvedUpdateStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_column_access_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_column_access_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedUpdateStmt_add_column_access_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedUpdateStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedUpdateStmt_add_column_access_list(arg0, arg1)
}

func ResolvedUpdateStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_assert_rows_modified(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_assert_rows_modified(arg0, arg1)
}

func ResolvedUpdateStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_assert_rows_modified(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_assert_rows_modified(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_assert_rows_modified(arg0, arg1)
}

func ResolvedUpdateStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_returning(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_returning(arg0, arg1)
}

func ResolvedUpdateStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_returning(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_returning(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_returning(arg0, arg1)
}

func ResolvedUpdateStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_array_offset_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_array_offset_column(arg0, arg1)
}

func ResolvedUpdateStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_array_offset_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_array_offset_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_array_offset_column(arg0, arg1)
}

func ResolvedUpdateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_where_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_where_expr(arg0, arg1)
}

func ResolvedUpdateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_where_expr(arg0, arg1)
}

func ResolvedUpdateStmt_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_update_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_update_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_add_update_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_add_update_item_list(arg0, arg1)
}

func ResolvedUpdateStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_from_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_from_scan(arg0, arg1)
}

func ResolvedUpdateStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUpdateStmt_set_from_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUpdateStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUpdateStmt_set_from_scan(arg0, arg1)
}

func ResolvedMergeWhen_match_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedMergeWhen_match_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedMergeWhen_match_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedMergeWhen_match_type(arg0, arg1)
}

func ResolvedMergeWhen_set_match_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedMergeWhen_set_match_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedMergeWhen_set_match_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedMergeWhen_set_match_type(arg0, arg1)
}

func ResolvedMergeWhen_match_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_match_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_match_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_match_expr(arg0, arg1)
}

func ResolvedMergeWhen_set_match_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_set_match_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_set_match_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_set_match_expr(arg0, arg1)
}

func ResolvedMergeWhen_action_type(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedMergeWhen_action_type(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedMergeWhen_action_type(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedMergeWhen_action_type(arg0, arg1)
}

func ResolvedMergeWhen_set_action_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedMergeWhen_set_action_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedMergeWhen_set_action_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedMergeWhen_set_action_type(arg0, arg1)
}

func ResolvedMergeWhen_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_insert_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_set_insert_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_set_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_set_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_add_insert_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_add_insert_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_add_insert_column_list(arg0, arg1)
}

func ResolvedMergeWhen_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_insert_row(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_insert_row(arg0, arg1)
}

func ResolvedMergeWhen_set_insert_row(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_set_insert_row(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_set_insert_row(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_set_insert_row(arg0, arg1)
}

func ResolvedMergeWhen_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_update_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_update_item_list(arg0, arg1)
}

func ResolvedMergeWhen_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_set_update_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_set_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_set_update_item_list(arg0, arg1)
}

func ResolvedMergeWhen_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeWhen_add_update_item_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeWhen_add_update_item_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeWhen_add_update_item_list(arg0, arg1)
}

func ResolvedMergeStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_table_scan(arg0, arg1)
}

func ResolvedMergeStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_set_table_scan(arg0, arg1)
}

func ResolvedMergeStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_column_access_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_column_access_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_set_column_access_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_set_column_access_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_set_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedMergeStmt_add_column_access_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedMergeStmt_add_column_access_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedMergeStmt_add_column_access_list(arg0, arg1)
}

func ResolvedMergeStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_from_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_from_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_from_scan(arg0, arg1)
}

func ResolvedMergeStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_set_from_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_set_from_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_set_from_scan(arg0, arg1)
}

func ResolvedMergeStmt_merge_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_merge_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_merge_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_merge_expr(arg0, arg1)
}

func ResolvedMergeStmt_set_merge_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_set_merge_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_set_merge_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_set_merge_expr(arg0, arg1)
}

func ResolvedMergeStmt_when_clause_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_when_clause_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_when_clause_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_when_clause_list(arg0, arg1)
}

func ResolvedMergeStmt_set_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_set_when_clause_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_set_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_set_when_clause_list(arg0, arg1)
}

func ResolvedMergeStmt_add_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedMergeStmt_add_when_clause_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedMergeStmt_add_when_clause_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedMergeStmt_add_when_clause_list(arg0, arg1)
}

func ResolvedTruncateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTruncateStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTruncateStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTruncateStmt_table_scan(arg0, arg1)
}

func ResolvedTruncateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTruncateStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTruncateStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTruncateStmt_set_table_scan(arg0, arg1)
}

func ResolvedTruncateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTruncateStmt_where_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTruncateStmt_where_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTruncateStmt_where_expr(arg0, arg1)
}

func ResolvedTruncateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTruncateStmt_set_where_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTruncateStmt_set_where_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTruncateStmt_set_where_expr(arg0, arg1)
}

func ResolvedObjectUnit_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedObjectUnit_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedObjectUnit_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedObjectUnit_name_path(arg0, arg1)
}

func ResolvedObjectUnit_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedObjectUnit_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedObjectUnit_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedObjectUnit_set_name_path(arg0, arg1)
}

func ResolvedObjectUnit_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedObjectUnit_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedObjectUnit_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedObjectUnit_add_name_path(arg0, arg1)
}

func ResolvedPrivilege_action_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPrivilege_action_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrivilege_action_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPrivilege_action_type(arg0, arg1)
}

func ResolvedPrivilege_set_action_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrivilege_set_action_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrivilege_set_action_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrivilege_set_action_type(arg0, arg1)
}

func ResolvedPrivilege_unit_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPrivilege_unit_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrivilege_unit_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPrivilege_unit_list(arg0, arg1)
}

func ResolvedPrivilege_set_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrivilege_set_unit_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrivilege_set_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrivilege_set_unit_list(arg0, arg1)
}

func ResolvedPrivilege_add_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPrivilege_add_unit_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPrivilege_add_unit_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPrivilege_add_unit_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_set_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_set_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_set_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_add_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_add_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_add_privilege_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_object_type(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_set_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_set_object_type(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_set_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_add_name_path(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_grantee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_set_grantee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_set_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_add_grantee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_add_grantee_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_set_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantOrRevokeStmt_add_grantee_expr_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterObjectStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterObjectStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterObjectStmt_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterObjectStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterObjectStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterObjectStmt_set_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterObjectStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterObjectStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterObjectStmt_add_name_path(arg0, arg1)
}

func ResolvedAlterObjectStmt_alter_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterObjectStmt_alter_action_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterObjectStmt_alter_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterObjectStmt_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterObjectStmt_set_alter_action_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterObjectStmt_set_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterObjectStmt_set_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_add_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterObjectStmt_add_alter_action_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterObjectStmt_add_alter_action_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterObjectStmt_add_alter_action_list(arg0, arg1)
}

func ResolvedAlterObjectStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedAlterObjectStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAlterObjectStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedAlterObjectStmt_is_if_exists(arg0, arg1)
}

func ResolvedAlterObjectStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAlterObjectStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAlterObjectStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAlterObjectStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedAlterColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAlterColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedAlterColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAlterColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAlterColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAlterColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnAction_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterColumnAction_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnAction_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnAction_column(arg0, arg1)
}

func ResolvedAlterColumnAction_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterColumnAction_set_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnAction_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnAction_set_column(arg0, arg1)
}

func ResolvedSetOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetOptionsAction_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOptionsAction_option_list(arg0, arg1)
}

func ResolvedSetOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetOptionsAction_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOptionsAction_set_option_list(arg0, arg1)
}

func ResolvedSetOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetOptionsAction_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetOptionsAction_add_option_list(arg0, arg1)
}

func ResolvedAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedAddColumnAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedAddColumnAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAddColumnAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAddColumnAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAddColumnAction_column_definition(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAddColumnAction_column_definition(arg0, arg1)
}

func ResolvedAddColumnAction_set_column_definition(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAddColumnAction_set_column_definition(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddColumnAction_set_column_definition(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAddColumnAction_set_column_definition(arg0, arg1)
}

func ResolvedAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedAddConstraintAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedAddConstraintAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAddConstraintAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAddConstraintAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAddConstraintAction_constraint(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAddConstraintAction_constraint(arg0, arg1)
}

func ResolvedAddConstraintAction_set_constraint(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAddConstraintAction_set_constraint(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddConstraintAction_set_constraint(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAddConstraintAction_set_constraint(arg0, arg1)
}

func ResolvedAddConstraintAction_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAddConstraintAction_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddConstraintAction_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAddConstraintAction_table(arg0, arg1)
}

func ResolvedAddConstraintAction_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAddConstraintAction_set_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddConstraintAction_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAddConstraintAction_set_table(arg0, arg1)
}

func ResolvedDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropConstraintAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropConstraintAction_is_if_exists(arg0, arg1)
}

func ResolvedDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropConstraintAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropConstraintAction_set_is_if_exists(arg0, arg1)
}

func ResolvedDropConstraintAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropConstraintAction_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropConstraintAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropConstraintAction_name(arg0, arg1)
}

func ResolvedDropConstraintAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropConstraintAction_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropConstraintAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropConstraintAction_set_name(arg0, arg1)
}

func ResolvedDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropPrimaryKeyAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropPrimaryKeyAction_is_if_exists(arg0, arg1)
}

func ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropPrimaryKeyAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropPrimaryKeyAction_set_is_if_exists(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterColumnOptionsAction_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnOptionsAction_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnOptionsAction_option_list(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterColumnOptionsAction_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnOptionsAction_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnOptionsAction_set_option_list(arg0, arg1)
}

func ResolvedAlterColumnOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterColumnOptionsAction_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnOptionsAction_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnOptionsAction_add_option_list(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDataTypeAction_updated_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDataTypeAction_updated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDataTypeAction_updated_type(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_type(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDataTypeAction_updated_type_parameters(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDataTypeAction_updated_annotations(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDataTypeAction_updated_annotations(arg0, arg1)
}

func ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDataTypeAction_set_updated_annotations(arg0, arg1)
}

func ResolvedAlterColumnSetDefaultAction_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDefaultAction_default_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDefaultAction_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDefaultAction_default_value(arg0, arg1)
}

func ResolvedAlterColumnSetDefaultAction_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterColumnSetDefaultAction_set_default_value(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterColumnSetDefaultAction_set_default_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterColumnSetDefaultAction_set_default_value(arg0, arg1)
}

func ResolvedDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedDropColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropColumnAction_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropColumnAction_name(arg0, arg1)
}

func ResolvedDropColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropColumnAction_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropColumnAction_set_name(arg0, arg1)
}

func ResolvedRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedRenameColumnAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedRenameColumnAction_is_if_exists(arg0, arg1)
}

func ResolvedRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedRenameColumnAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedRenameColumnAction_set_is_if_exists(arg0, arg1)
}

func ResolvedRenameColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRenameColumnAction_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameColumnAction_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameColumnAction_name(arg0, arg1)
}

func ResolvedRenameColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameColumnAction_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameColumnAction_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameColumnAction_set_name(arg0, arg1)
}

func ResolvedRenameColumnAction_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRenameColumnAction_new_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameColumnAction_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameColumnAction_new_name(arg0, arg1)
}

func ResolvedRenameColumnAction_set_new_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameColumnAction_set_new_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameColumnAction_set_new_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameColumnAction_set_new_name(arg0, arg1)
}

func ResolvedSetAsAction_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetAsAction_entity_body_json(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetAsAction_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetAsAction_entity_body_json(arg0, arg1)
}

func ResolvedSetAsAction_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetAsAction_set_entity_body_json(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetAsAction_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetAsAction_set_entity_body_json(arg0, arg1)
}

func ResolvedSetAsAction_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetAsAction_entity_body_text(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetAsAction_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetAsAction_entity_body_text(arg0, arg1)
}

func ResolvedSetAsAction_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetAsAction_set_entity_body_text(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetAsAction_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetAsAction_set_entity_body_text(arg0, arg1)
}

func ResolvedSetCollateClause_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedSetCollateClause_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetCollateClause_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedSetCollateClause_collation_name(arg0, arg1)
}

func ResolvedSetCollateClause_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedSetCollateClause_set_collation_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedSetCollateClause_set_collation_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedSetCollateClause_set_collation_name(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterTableSetOptionsStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterTableSetOptionsStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_set_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterTableSetOptionsStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_add_name_path(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterTableSetOptionsStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterTableSetOptionsStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_set_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterTableSetOptionsStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_add_option_list(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedAlterTableSetOptionsStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_is_if_exists(arg0, arg1)
}

func ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAlterTableSetOptionsStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedRenameStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_object_type(arg0, arg1)
}

func ResolvedRenameStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_set_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_set_object_type(arg0, arg1)
}

func ResolvedRenameStmt_old_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_old_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_old_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_set_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_set_old_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_set_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_set_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_add_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_add_old_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_add_old_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_add_old_name_path(arg0, arg1)
}

func ResolvedRenameStmt_new_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_new_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_new_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_new_name_path(arg0, arg1)
}

func ResolvedRenameStmt_set_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_set_new_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_set_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_set_new_name_path(arg0, arg1)
}

func ResolvedRenameStmt_add_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameStmt_add_new_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameStmt_add_new_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameStmt_add_new_name_path(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_restrictee_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list(arg0, arg1)
}

func ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_create_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_create_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_create_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_create_mode(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_create_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_create_mode(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_target_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_add_target_name_path(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_grantee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_add_grantee_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_table_scan(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_predicate(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_predicate(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_predicate(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_predicate(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_predicate_str(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_predicate_str(arg0, arg1)
}

func ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateRowAccessPolicyStmt_set_predicate_str(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_add_name_path(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropRowAccessPolicyStmt_is_drop_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_is_drop_all(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_set_is_drop_all(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropRowAccessPolicyStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropRowAccessPolicyStmt_target_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_target_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_target_name_path(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropRowAccessPolicyStmt_set_target_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_set_target_name_path(arg0, arg1)
}

func ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropRowAccessPolicyStmt_add_target_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropRowAccessPolicyStmt_add_target_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropSearchIndexStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropSearchIndexStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropSearchIndexStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropSearchIndexStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropSearchIndexStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropSearchIndexStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropSearchIndexStmt_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSearchIndexStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSearchIndexStmt_name(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropSearchIndexStmt_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSearchIndexStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSearchIndexStmt_set_name(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropSearchIndexStmt_table_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSearchIndexStmt_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSearchIndexStmt_table_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropSearchIndexStmt_set_table_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSearchIndexStmt_set_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSearchIndexStmt_set_table_name_path(arg0, arg1)
}

func ResolvedDropSearchIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropSearchIndexStmt_add_table_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropSearchIndexStmt_add_table_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropSearchIndexStmt_add_table_name_path(arg0, arg1)
}

func ResolvedGrantToAction_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedGrantToAction_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantToAction_grantee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantToAction_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantToAction_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantToAction_set_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantToAction_set_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantToAction_set_grantee_expr_list(arg0, arg1)
}

func ResolvedGrantToAction_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedGrantToAction_add_grantee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedGrantToAction_add_grantee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedGrantToAction_add_grantee_expr_list(arg0, arg1)
}

func ResolvedRestrictToAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRestrictToAction_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRestrictToAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRestrictToAction_restrictee_list(arg0, arg1)
}

func ResolvedRestrictToAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRestrictToAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRestrictToAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRestrictToAction_set_restrictee_list(arg0, arg1)
}

func ResolvedRestrictToAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRestrictToAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRestrictToAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRestrictToAction_add_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedAddToRestricteeListAction_is_if_not_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAddToRestricteeListAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedAddToRestricteeListAction_is_if_not_exists(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAddToRestricteeListAction_set_is_if_not_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAddToRestricteeListAction_set_is_if_not_exists(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAddToRestricteeListAction_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddToRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAddToRestricteeListAction_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAddToRestricteeListAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddToRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAddToRestricteeListAction_set_restrictee_list(arg0, arg1)
}

func ResolvedAddToRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAddToRestricteeListAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAddToRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAddToRestricteeListAction_add_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedRemoveFromRestricteeListAction_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedRemoveFromRestricteeListAction_is_if_exists(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedRemoveFromRestricteeListAction_set_is_if_exists(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRemoveFromRestricteeListAction_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRemoveFromRestricteeListAction_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRemoveFromRestricteeListAction_set_restrictee_list(arg0, arg1)
}

func ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRemoveFromRestricteeListAction_add_restrictee_list(arg0, arg1)
}

func ResolvedFilterUsingAction_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFilterUsingAction_predicate(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterUsingAction_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterUsingAction_predicate(arg0, arg1)
}

func ResolvedFilterUsingAction_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFilterUsingAction_set_predicate(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterUsingAction_set_predicate(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterUsingAction_set_predicate(arg0, arg1)
}

func ResolvedFilterUsingAction_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFilterUsingAction_predicate_str(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterUsingAction_predicate_str(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterUsingAction_predicate_str(arg0, arg1)
}

func ResolvedFilterUsingAction_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFilterUsingAction_set_predicate_str(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFilterUsingAction_set_predicate_str(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFilterUsingAction_set_predicate_str(arg0, arg1)
}

func ResolvedRevokeFromAction_revokee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRevokeFromAction_revokee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRevokeFromAction_revokee_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRevokeFromAction_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_set_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRevokeFromAction_set_revokee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRevokeFromAction_set_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRevokeFromAction_set_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_add_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRevokeFromAction_add_revokee_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRevokeFromAction_add_revokee_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRevokeFromAction_add_revokee_expr_list(arg0, arg1)
}

func ResolvedRevokeFromAction_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedRevokeFromAction_is_revoke_from_all(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedRevokeFromAction_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedRevokeFromAction_is_revoke_from_all(arg0, arg1)
}

func ResolvedRevokeFromAction_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedRevokeFromAction_set_is_revoke_from_all(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedRevokeFromAction_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedRevokeFromAction_set_is_revoke_from_all(arg0, arg1)
}

func ResolvedRenameToAction_new_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRenameToAction_new_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameToAction_new_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameToAction_new_path(arg0, arg1)
}

func ResolvedRenameToAction_set_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameToAction_set_new_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameToAction_set_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameToAction_set_new_path(arg0, arg1)
}

func ResolvedRenameToAction_add_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRenameToAction_add_new_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRenameToAction_add_new_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRenameToAction_add_new_path(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterPrivilegeRestrictionStmt_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterPrivilegeRestrictionStmt_object_type(arg0, arg1)
}

func ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterPrivilegeRestrictionStmt_set_object_type(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterRowAccessPolicyStmt_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterRowAccessPolicyStmt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterRowAccessPolicyStmt_name(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterRowAccessPolicyStmt_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterRowAccessPolicyStmt_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterRowAccessPolicyStmt_set_name(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterRowAccessPolicyStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterRowAccessPolicyStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterRowAccessPolicyStmt_table_scan(arg0, arg1)
}

func ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterRowAccessPolicyStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterRowAccessPolicyStmt_set_table_scan(arg0, arg1)
}

func ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterAllRowAccessPoliciesStmt_table_scan(arg0, arg1)
}

func ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan(arg0, arg1)
}

func ResolvedCreateConstantStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateConstantStmt_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateConstantStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateConstantStmt_expr(arg0, arg1)
}

func ResolvedCreateConstantStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateConstantStmt_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateConstantStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateConstantStmt_set_expr(arg0, arg1)
}

func ResolvedCreateFunctionStmt_has_explicit_return_type(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateFunctionStmt_has_explicit_return_type(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateFunctionStmt_has_explicit_return_type(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateFunctionStmt_has_explicit_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateFunctionStmt_set_has_explicit_return_type(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_has_explicit_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_return_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_return_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_return_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_return_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_return_type(arg0, arg1)
}

func ResolvedCreateFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_signature(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedCreateFunctionStmt_is_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateFunctionStmt_is_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateFunctionStmt_is_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateFunctionStmt_is_aggregate(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_is_aggregate(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateFunctionStmt_set_is_aggregate(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_is_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_is_aggregate(arg0, arg1)
}

func ResolvedCreateFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_language(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_language(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_language(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_language(arg0, arg1)
}

func ResolvedCreateFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_code(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_code(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_code(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_code(arg0, arg1)
}

func ResolvedCreateFunctionStmt_aggregate_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_aggregate_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_add_aggregate_expression_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_add_aggregate_expression_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_function_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_function_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_function_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_function_expression(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_function_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_function_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_function_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_function_expression(arg0, arg1)
}

func ResolvedCreateFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedCreateFunctionStmt_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedCreateFunctionStmt_sql_security(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateFunctionStmt_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_sql_security(arg0, arg1)
}

func ResolvedCreateFunctionStmt_determinism_level(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedCreateFunctionStmt_determinism_level(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateFunctionStmt_determinism_level(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedCreateFunctionStmt_determinism_level(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_determinism_level(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateFunctionStmt_set_determinism_level(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_determinism_level(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_determinism_level(arg0, arg1)
}

func ResolvedCreateFunctionStmt_is_remote(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateFunctionStmt_is_remote(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateFunctionStmt_is_remote(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateFunctionStmt_is_remote(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_is_remote(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateFunctionStmt_set_is_remote(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_is_remote(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_is_remote(arg0, arg1)
}

func ResolvedCreateFunctionStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_connection(arg0, arg1)
}

func ResolvedCreateFunctionStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateFunctionStmt_set_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateFunctionStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateFunctionStmt_set_connection(arg0, arg1)
}

func ResolvedArgumentDef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArgumentDef_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentDef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentDef_name(arg0, arg1)
}

func ResolvedArgumentDef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArgumentDef_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentDef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentDef_set_name(arg0, arg1)
}

func ResolvedArgumentDef_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArgumentDef_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentDef_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentDef_type(arg0, arg1)
}

func ResolvedArgumentDef_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArgumentDef_set_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentDef_set_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentDef_set_type(arg0, arg1)
}

func ResolvedArgumentDef_argument_kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedArgumentDef_argument_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedArgumentDef_argument_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedArgumentDef_argument_kind(arg0, arg1)
}

func ResolvedArgumentDef_set_argument_kind(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedArgumentDef_set_argument_kind(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedArgumentDef_set_argument_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedArgumentDef_set_argument_kind(arg0, arg1)
}

func ResolvedArgumentRef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArgumentRef_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentRef_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentRef_name(arg0, arg1)
}

func ResolvedArgumentRef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArgumentRef_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentRef_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentRef_set_name(arg0, arg1)
}

func ResolvedArgumentRef_argument_kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedArgumentRef_argument_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedArgumentRef_argument_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedArgumentRef_argument_kind(arg0, arg1)
}

func ResolvedArgumentRef_set_argument_kind(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedArgumentRef_set_argument_kind(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedArgumentRef_set_argument_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedArgumentRef_set_argument_kind(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_new(arg0 unsafe.Pointer, arg1 int, arg2 int, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 int, arg6 unsafe.Pointer, arg7 unsafe.Pointer, arg8 unsafe.Pointer, arg9 unsafe.Pointer, arg10 unsafe.Pointer, arg11 int, arg12 int, arg13 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_new(
		arg0,
		C.int(arg1),
		C.int(arg2),
		arg3,
		arg4,
		C.int(arg5),
		arg6,
		arg7,
		arg8,
		arg9,
		arg10,
		C.int(arg11),
		C.int(arg12),
		arg13,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_new(arg0 unsafe.Pointer, arg1 C.int, arg2 C.int, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 C.int, arg6 unsafe.Pointer, arg7 unsafe.Pointer, arg8 unsafe.Pointer, arg9 unsafe.Pointer, arg10 unsafe.Pointer, arg11 C.int, arg12 C.int, arg13 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_new(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
}

func ResolvedCreateTableFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_signature(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_has_explicit_return_schema(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_language(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_language(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_set_language(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_language(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_language(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_code(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_code(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_set_code(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_code(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_code(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_query(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_set_query(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_query(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_query(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateTableFunctionStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_add_output_column_list(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCreateTableFunctionStmt_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_is_value_table(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateTableFunctionStmt_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_is_value_table(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedCreateTableFunctionStmt_sql_security(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_sql_security(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_sql_security(arg0, arg1)
}

func ResolvedCreateTableFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedCreateTableFunctionStmt_set_sql_security(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedCreateTableFunctionStmt_set_sql_security(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedCreateTableFunctionStmt_set_sql_security(arg0, arg1)
}

func ResolvedRelationArgumentScan_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedRelationArgumentScan_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRelationArgumentScan_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedRelationArgumentScan_name(arg0, arg1)
}

func ResolvedRelationArgumentScan_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedRelationArgumentScan_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedRelationArgumentScan_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedRelationArgumentScan_set_name(arg0, arg1)
}

func ResolvedRelationArgumentScan_is_value_table(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedRelationArgumentScan_is_value_table(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedRelationArgumentScan_is_value_table(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedRelationArgumentScan_is_value_table(arg0, arg1)
}

func ResolvedRelationArgumentScan_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedRelationArgumentScan_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedRelationArgumentScan_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedRelationArgumentScan_set_is_value_table(arg0, arg1)
}

func ResolvedArgumentList_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedArgumentList_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentList_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentList_arg_list(arg0, arg1)
}

func ResolvedArgumentList_set_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArgumentList_set_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentList_set_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentList_set_arg_list(arg0, arg1)
}

func ResolvedArgumentList_add_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedArgumentList_add_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedArgumentList_add_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedArgumentList_add_arg_list(arg0, arg1)
}

func ResolvedFunctionSignatureHolder_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionSignatureHolder_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionSignatureHolder_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionSignatureHolder_signature(arg0, arg1)
}

func ResolvedFunctionSignatureHolder_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedFunctionSignatureHolder_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionSignatureHolder_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionSignatureHolder_set_signature(arg0, arg1)
}

func ResolvedDropFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropFunctionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropFunctionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropFunctionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropFunctionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropFunctionStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropFunctionStmt_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropFunctionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropFunctionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropFunctionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropFunctionStmt_add_name_path(arg0, arg1)
}

func ResolvedDropFunctionStmt_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropFunctionStmt_arguments(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropFunctionStmt_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropFunctionStmt_arguments(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_arguments(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropFunctionStmt_set_arguments(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropFunctionStmt_set_arguments(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropFunctionStmt_set_arguments(arg0, arg1)
}

func ResolvedDropFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropFunctionStmt_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropFunctionStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropFunctionStmt_signature(arg0, arg1)
}

func ResolvedDropFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropFunctionStmt_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropFunctionStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropFunctionStmt_set_signature(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedDropTableFunctionStmt_is_if_exists(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedDropTableFunctionStmt_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedDropTableFunctionStmt_is_if_exists(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedDropTableFunctionStmt_set_is_if_exists(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedDropTableFunctionStmt_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedDropTableFunctionStmt_set_is_if_exists(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedDropTableFunctionStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropTableFunctionStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedDropTableFunctionStmt_name_path(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropTableFunctionStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropTableFunctionStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropTableFunctionStmt_set_name_path(arg0, arg1)
}

func ResolvedDropTableFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedDropTableFunctionStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedDropTableFunctionStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedDropTableFunctionStmt_add_name_path(arg0, arg1)
}

func ResolvedCallStmt_procedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCallStmt_procedure(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCallStmt_procedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCallStmt_procedure(arg0, arg1)
}

func ResolvedCallStmt_set_procedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCallStmt_set_procedure(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCallStmt_set_procedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCallStmt_set_procedure(arg0, arg1)
}

func ResolvedCallStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCallStmt_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCallStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCallStmt_signature(arg0, arg1)
}

func ResolvedCallStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCallStmt_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCallStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCallStmt_set_signature(arg0, arg1)
}

func ResolvedCallStmt_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCallStmt_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCallStmt_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCallStmt_argument_list(arg0, arg1)
}

func ResolvedCallStmt_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCallStmt_set_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCallStmt_set_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCallStmt_set_argument_list(arg0, arg1)
}

func ResolvedCallStmt_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCallStmt_add_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCallStmt_add_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCallStmt_add_argument_list(arg0, arg1)
}

func ResolvedImportStmt_import_kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedImportStmt_import_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedImportStmt_import_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedImportStmt_import_kind(arg0, arg1)
}

func ResolvedImportStmt_set_import_kind(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedImportStmt_set_import_kind(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedImportStmt_set_import_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedImportStmt_set_import_kind(arg0, arg1)
}

func ResolvedImportStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedImportStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_name_path(arg0, arg1)
}

func ResolvedImportStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_set_name_path(arg0, arg1)
}

func ResolvedImportStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_add_name_path(arg0, arg1)
}

func ResolvedImportStmt_file_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedImportStmt_file_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_file_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_file_path(arg0, arg1)
}

func ResolvedImportStmt_set_file_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_set_file_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_set_file_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_set_file_path(arg0, arg1)
}

func ResolvedImportStmt_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedImportStmt_alias_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_alias_path(arg0, arg1)
}

func ResolvedImportStmt_set_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_set_alias_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_set_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_set_alias_path(arg0, arg1)
}

func ResolvedImportStmt_add_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_add_alias_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_add_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_add_alias_path(arg0, arg1)
}

func ResolvedImportStmt_into_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedImportStmt_into_alias_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_into_alias_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_set_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_set_into_alias_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_set_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_set_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_add_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_add_into_alias_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_add_into_alias_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_add_into_alias_path(arg0, arg1)
}

func ResolvedImportStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedImportStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_option_list(arg0, arg1)
}

func ResolvedImportStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_set_option_list(arg0, arg1)
}

func ResolvedImportStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedImportStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedImportStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedImportStmt_add_option_list(arg0, arg1)
}

func ResolvedModuleStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedModuleStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModuleStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedModuleStmt_name_path(arg0, arg1)
}

func ResolvedModuleStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedModuleStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModuleStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedModuleStmt_set_name_path(arg0, arg1)
}

func ResolvedModuleStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedModuleStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModuleStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedModuleStmt_add_name_path(arg0, arg1)
}

func ResolvedModuleStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedModuleStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModuleStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedModuleStmt_option_list(arg0, arg1)
}

func ResolvedModuleStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedModuleStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModuleStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedModuleStmt_set_option_list(arg0, arg1)
}

func ResolvedModuleStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedModuleStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedModuleStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedModuleStmt_add_option_list(arg0, arg1)
}

func ResolvedAggregateHavingModifier_kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedAggregateHavingModifier_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAggregateHavingModifier_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedAggregateHavingModifier_kind(arg0, arg1)
}

func ResolvedAggregateHavingModifier_set_kind(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAggregateHavingModifier_set_kind(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAggregateHavingModifier_set_kind(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAggregateHavingModifier_set_kind(arg0, arg1)
}

func ResolvedAggregateHavingModifier_having_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAggregateHavingModifier_having_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateHavingModifier_having_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateHavingModifier_having_expr(arg0, arg1)
}

func ResolvedAggregateHavingModifier_set_having_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAggregateHavingModifier_set_having_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAggregateHavingModifier_set_having_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAggregateHavingModifier_set_having_expr(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_set_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_set_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_add_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_add_column_definition_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_cluster_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateMaterializedViewStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_argument_name_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_set_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_set_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_set_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_add_argument_name_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_add_argument_name_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_add_argument_name_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_signature(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_set_signature(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_set_signature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_set_signature(arg0, arg1)
}

func ResolvedCreateProcedureStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_add_option_list(arg0, arg1)
}

func ResolvedCreateProcedureStmt_procedure_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_procedure_body(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_procedure_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_procedure_body(arg0, arg1)
}

func ResolvedCreateProcedureStmt_set_procedure_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateProcedureStmt_set_procedure_body(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateProcedureStmt_set_procedure_body(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateProcedureStmt_set_procedure_body(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateArgument_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateArgument_name(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateArgument_set_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateArgument_set_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateArgument_set_name(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateArgument_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateArgument_expression(arg0, arg1)
}

func ResolvedExecuteImmediateArgument_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateArgument_set_expression(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateArgument_set_expression(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateArgument_set_expression(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_sql(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_sql(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_set_sql(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_set_sql(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_set_sql(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_into_identifier_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_into_identifier_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_into_identifier_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_set_into_identifier_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_set_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_add_into_identifier_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_add_into_identifier_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_using_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_using_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_using_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_using_argument_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_set_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_set_using_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_set_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_set_using_argument_list(arg0, arg1)
}

func ResolvedExecuteImmediateStmt_add_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedExecuteImmediateStmt_add_using_argument_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedExecuteImmediateStmt_add_using_argument_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedExecuteImmediateStmt_add_using_argument_list(arg0, arg1)
}

func ResolvedAssignmentStmt_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAssignmentStmt_target(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssignmentStmt_target(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAssignmentStmt_target(arg0, arg1)
}

func ResolvedAssignmentStmt_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAssignmentStmt_set_target(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssignmentStmt_set_target(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAssignmentStmt_set_target(arg0, arg1)
}

func ResolvedAssignmentStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAssignmentStmt_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssignmentStmt_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAssignmentStmt_expr(arg0, arg1)
}

func ResolvedAssignmentStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAssignmentStmt_set_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAssignmentStmt_set_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAssignmentStmt_set_expr(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_entity_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_entity_type(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_set_entity_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_set_entity_type(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_entity_body_json(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_entity_body_json(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_entity_body_json(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_set_entity_body_json(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_set_entity_body_json(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_set_entity_body_json(arg0, arg1)
}

func ResolvedCreateEntityStmt_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_entity_body_text(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_entity_body_text(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_entity_body_text(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_set_entity_body_text(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_set_entity_body_text(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_set_entity_body_text(arg0, arg1)
}

func ResolvedCreateEntityStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_option_list(arg0, arg1)
}

func ResolvedCreateEntityStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_set_option_list(arg0, arg1)
}

func ResolvedCreateEntityStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCreateEntityStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCreateEntityStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCreateEntityStmt_add_option_list(arg0, arg1)
}

func ResolvedAlterEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAlterEntityStmt_entity_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterEntityStmt_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterEntityStmt_entity_type(arg0, arg1)
}

func ResolvedAlterEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAlterEntityStmt_set_entity_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAlterEntityStmt_set_entity_type(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAlterEntityStmt_set_entity_type(arg0, arg1)
}

func ResolvedPivotColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPivotColumn_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotColumn_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotColumn_column(arg0, arg1)
}

func ResolvedPivotColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotColumn_set_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotColumn_set_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotColumn_set_column(arg0, arg1)
}

func ResolvedPivotColumn_pivot_expr_index(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedPivotColumn_pivot_expr_index(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedPivotColumn_pivot_expr_index(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedPivotColumn_pivot_expr_index(arg0, arg1)
}

func ResolvedPivotColumn_set_pivot_expr_index(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedPivotColumn_set_pivot_expr_index(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedPivotColumn_set_pivot_expr_index(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedPivotColumn_set_pivot_expr_index(arg0, arg1)
}

func ResolvedPivotColumn_pivot_value_index(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedPivotColumn_pivot_value_index(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedPivotColumn_pivot_value_index(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedPivotColumn_pivot_value_index(arg0, arg1)
}

func ResolvedPivotColumn_set_pivot_value_index(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedPivotColumn_set_pivot_value_index(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedPivotColumn_set_pivot_value_index(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedPivotColumn_set_pivot_value_index(arg0, arg1)
}

func ResolvedPivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPivotScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_input_scan(arg0, arg1)
}

func ResolvedPivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_set_input_scan(arg0, arg1)
}

func ResolvedPivotScan_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPivotScan_group_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_group_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_set_group_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_set_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_set_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_add_group_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_add_group_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_add_group_by_list(arg0, arg1)
}

func ResolvedPivotScan_pivot_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPivotScan_pivot_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_pivot_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_set_pivot_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_set_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_set_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_add_pivot_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_add_pivot_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_add_pivot_expr_list(arg0, arg1)
}

func ResolvedPivotScan_for_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPivotScan_for_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_for_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_for_expr(arg0, arg1)
}

func ResolvedPivotScan_set_for_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_set_for_expr(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_set_for_expr(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_set_for_expr(arg0, arg1)
}

func ResolvedPivotScan_pivot_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPivotScan_pivot_value_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_pivot_value_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_set_pivot_value_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_set_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_set_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_add_pivot_value_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_add_pivot_value_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_add_pivot_value_list(arg0, arg1)
}

func ResolvedPivotScan_pivot_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedPivotScan_pivot_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_pivot_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_pivot_column_list(arg0, arg1)
}

func ResolvedPivotScan_set_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_set_pivot_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_set_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_set_pivot_column_list(arg0, arg1)
}

func ResolvedPivotScan_add_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedPivotScan_add_pivot_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedPivotScan_add_pivot_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedPivotScan_add_pivot_column_list(arg0, arg1)
}

func ResolvedReturningClause_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedReturningClause_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReturningClause_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_set_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReturningClause_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_add_output_column_list(arg0, arg1)
}

func ResolvedReturningClause_action_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedReturningClause_action_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_action_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_action_column(arg0, arg1)
}

func ResolvedReturningClause_set_action_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReturningClause_set_action_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_set_action_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_set_action_column(arg0, arg1)
}

func ResolvedReturningClause_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedReturningClause_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_expr_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_expr_list(arg0, arg1)
}

func ResolvedReturningClause_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReturningClause_set_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_set_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_set_expr_list(arg0, arg1)
}

func ResolvedReturningClause_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedReturningClause_add_expr_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedReturningClause_add_expr_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedReturningClause_add_expr_list(arg0, arg1)
}

func ResolvedUnpivotArg_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnpivotArg_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotArg_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotArg_column_list(arg0, arg1)
}

func ResolvedUnpivotArg_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotArg_set_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotArg_set_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotArg_set_column_list(arg0, arg1)
}

func ResolvedUnpivotArg_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotArg_add_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotArg_add_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotArg_add_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_input_scan(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_input_scan(arg0, arg1)
}

func ResolvedUnpivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_set_input_scan(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_set_input_scan(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_set_input_scan(arg0, arg1)
}

func ResolvedUnpivotScan_value_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_value_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_value_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_set_value_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_set_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_set_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_add_value_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_add_value_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_add_value_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_label_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_label_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_label_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_label_column(arg0, arg1)
}

func ResolvedUnpivotScan_set_label_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_set_label_column(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_set_label_column(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_set_label_column(arg0, arg1)
}

func ResolvedUnpivotScan_label_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_label_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_label_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_set_label_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_set_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_set_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_add_label_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_add_label_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_add_label_list(arg0, arg1)
}

func ResolvedUnpivotScan_unpivot_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_unpivot_arg_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_set_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_set_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_set_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_add_unpivot_arg_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_add_unpivot_arg_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_add_unpivot_arg_list(arg0, arg1)
}

func ResolvedUnpivotScan_projected_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_projected_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_projected_input_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_set_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_set_projected_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_set_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_set_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_add_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedUnpivotScan_add_projected_input_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedUnpivotScan_add_projected_input_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedUnpivotScan_add_projected_input_column_list(arg0, arg1)
}

func ResolvedUnpivotScan_include_nulls(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedUnpivotScan_include_nulls(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedUnpivotScan_include_nulls(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedUnpivotScan_include_nulls(arg0, arg1)
}

func ResolvedUnpivotScan_set_include_nulls(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedUnpivotScan_set_include_nulls(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedUnpivotScan_set_include_nulls(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedUnpivotScan_set_include_nulls(arg0, arg1)
}

func ResolvedCloneDataStmt_target_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCloneDataStmt_target_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCloneDataStmt_target_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCloneDataStmt_target_table(arg0, arg1)
}

func ResolvedCloneDataStmt_set_target_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCloneDataStmt_set_target_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCloneDataStmt_set_target_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCloneDataStmt_set_target_table(arg0, arg1)
}

func ResolvedCloneDataStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCloneDataStmt_clone_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCloneDataStmt_clone_from(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCloneDataStmt_clone_from(arg0, arg1)
}

func ResolvedCloneDataStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedCloneDataStmt_set_clone_from(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCloneDataStmt_set_clone_from(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedCloneDataStmt_set_clone_from(arg0, arg1)
}

func ResolvedTableAndColumnInfo_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTableAndColumnInfo_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableAndColumnInfo_table(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTableAndColumnInfo_table(arg0, arg1)
}

func ResolvedTableAndColumnInfo_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTableAndColumnInfo_set_table(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableAndColumnInfo_set_table(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTableAndColumnInfo_set_table(arg0, arg1)
}

func ResolvedTableAndColumnInfo_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedTableAndColumnInfo_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableAndColumnInfo_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedTableAndColumnInfo_column_index_list(arg0, arg1)
}

func ResolvedTableAndColumnInfo_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedTableAndColumnInfo_set_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedTableAndColumnInfo_set_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedTableAndColumnInfo_set_column_index_list(arg0, arg1)
}

func ResolvedTableAndColumnInfo_add_column_index_list(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedTableAndColumnInfo_add_column_index_list(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedTableAndColumnInfo_add_column_index_list(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedTableAndColumnInfo_add_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyzeStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyzeStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyzeStmt_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyzeStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyzeStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyzeStmt_set_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyzeStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyzeStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyzeStmt_add_option_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_table_and_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAnalyzeStmt_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyzeStmt_table_and_column_index_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyzeStmt_table_and_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyzeStmt_set_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyzeStmt_set_table_and_column_index_list(arg0, arg1)
}

func ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAnalyzeStmt_add_table_and_column_index_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAnalyzeStmt_add_table_and_column_index_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_insertion_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedAuxLoadDataStmt_insertion_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedAuxLoadDataStmt_insertion_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_insertion_mode(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_insertion_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_ResolvedAuxLoadDataStmt_set_insertion_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_insertion_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_insertion_mode(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_name_path(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_name_path(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_name_path(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_output_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_output_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_output_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_output_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_column_definition_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_column_definition_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_column_definition_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_column_definition_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_pseudo_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_pseudo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_pseudo_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_pseudo_column_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_pseudo_column_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_primary_key(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_primary_key(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_primary_key(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_primary_key(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_primary_key(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_primary_key(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_foreign_key_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_foreign_key_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_foreign_key_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_foreign_key_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_foreign_key_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_check_constraint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_check_constraint_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_check_constraint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_check_constraint_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_check_constraint_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_partition_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_partition_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_partition_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_partition_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_cluster_by_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_cluster_by_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_cluster_by_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_with_partition_columns(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_with_partition_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_with_partition_columns(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_with_partition_columns(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_with_partition_columns(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_connection(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_connection(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_connection(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_connection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_connection(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_from_files_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_from_files_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_from_files_option_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_from_files_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_set_from_files_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_set_from_files_option_list(arg0, arg1)
}

func ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_ResolvedAuxLoadDataStmt_add_from_files_option_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_ResolvedAuxLoadDataStmt_add_from_files_option_list(arg0, arg1)
}

func ResolvedColumn_IsInitialized(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedColumn_IsInitialized(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedColumn_IsInitialized(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedColumn_IsInitialized(arg0, arg1)
}

func ResolvedColumn_Clear(arg0 unsafe.Pointer) {
	googlesql_ResolvedColumn_Clear(
		arg0,
	)
}

func googlesql_ResolvedColumn_Clear(arg0 unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_Clear(arg0)
}

func ResolvedColumn_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_DebugString(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_DebugString(arg0, arg1)
}

func ResolvedColumn_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_ShortDebugString(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_ShortDebugString(arg0, arg1)
}

func ResolvedColumn_column_id(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_ResolvedColumn_column_id(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedColumn_column_id(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_ResolvedColumn_column_id(arg0, arg1)
}

func ResolvedColumn_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_table_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_table_name(arg0, arg1)
}

func ResolvedColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_name(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_name(arg0, arg1)
}

func ResolvedColumn_table_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_table_name_id(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_table_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_table_name_id(arg0, arg1)
}

func ResolvedColumn_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_name_id(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_name_id(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_name_id(arg0, arg1)
}

func ResolvedColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_type(arg0, arg1)
}

func ResolvedColumn_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_type_annotation_map(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_type_annotation_map(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_type_annotation_map(arg0, arg1)
}

func ResolvedColumn_annotated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedColumn_annotated_type(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedColumn_annotated_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedColumn_annotated_type(arg0, arg1)
}

func ResolvedCollation_Empty(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCollation_Empty(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCollation_Empty(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCollation_Empty(arg0, arg1)
}

func ResolvedCollation_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_ResolvedCollation_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_ResolvedCollation_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_ResolvedCollation_Equals(arg0, arg1, arg2)
}

func ResolvedCollation_HasCompatibleStructure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_ResolvedCollation_HasCompatibleStructure(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_ResolvedCollation_HasCompatibleStructure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_ResolvedCollation_HasCompatibleStructure(arg0, arg1, arg2)
}

func ResolvedCollation_HasCollation(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_ResolvedCollation_HasCollation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_ResolvedCollation_HasCollation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_ResolvedCollation_HasCollation(arg0, arg1)
}

func ResolvedCollation_CollationName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCollation_CollationName(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCollation_CollationName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCollation_CollationName(arg0, arg1)
}

func ResolvedCollation_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCollation_child_list(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCollation_child_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCollation_child_list(arg0, arg1)
}

func ResolvedCollation_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedCollation_DebugString(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedCollation_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedCollation_DebugString(arg0, arg1)
}

func ResolvedFunctionCallInfo_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ResolvedFunctionCallInfo_DebugString(
		arg0,
		arg1,
	)
}

func googlesql_ResolvedFunctionCallInfo_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ResolvedFunctionCallInfo_DebugString(arg0, arg1)
}

func GoCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_GoCatalog_new(
		arg0,
		arg1,
	)
}

func googlesql_GoCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_GoCatalog_new(arg0, arg1)
}

func GoTable_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_GoTable_new(
		arg0,
		arg1,
	)
}

func googlesql_GoTable_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_GoTable_new(arg0, arg1)
}

func Type_Kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Type_Kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_Kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Type_Kind(arg0, arg1)
}

func Type_IsInt32(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsInt32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsInt32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsInt32(arg0, arg1)
}

func Type_IsInt64(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsInt64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsInt64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsInt64(arg0, arg1)
}

func Type_IsUint32(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsUint32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsUint32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsUint32(arg0, arg1)
}

func Type_IsUint64(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsUint64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsUint64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsUint64(arg0, arg1)
}

func Type_IsBool(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsBool(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsBool(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsBool(arg0, arg1)
}

func Type_IsFloat(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsFloat(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsFloat(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsFloat(arg0, arg1)
}

func Type_IsDouble(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsDouble(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsDouble(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsDouble(arg0, arg1)
}

func Type_IsString(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsString(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsString(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsString(arg0, arg1)
}

func Type_IsBytes(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsBytes(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsBytes(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsBytes(arg0, arg1)
}

func Type_IsDate(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsDate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsDate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsDate(arg0, arg1)
}

func Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsTimestamp(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsTimestamp(arg0, arg1)
}

func Type_IsTime(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsTime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsTime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsTime(arg0, arg1)
}

func Type_IsDatetime(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsDatetime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsDatetime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsDatetime(arg0, arg1)
}

func Type_IsInterval(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsInterval(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsInterval(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsInterval(arg0, arg1)
}

func Type_IsNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsNumericType(arg0, arg1)
}

func Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsBigNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsBigNumericType(arg0, arg1)
}

func Type_IsJsonType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsJsonType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsJsonType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsJsonType(arg0, arg1)
}

func Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsFeatureV12CivilTimeType(arg0, arg1)
}

func Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_UsingFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_UsingFeatureV12CivilTimeType(arg0, arg1)
}

func Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsCivilDateOrTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsCivilDateOrTimeType(arg0, arg1)
}

func Type_IsGeography(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsGeography(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsGeography(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsGeography(arg0, arg1)
}

func Type_IsJson(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsJson(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsJson(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsJson(arg0, arg1)
}

func Type_IsEnum(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsEnum(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsEnum(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsEnum(arg0, arg1)
}

func Type_IsArray(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsArray(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsArray(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsArray(arg0, arg1)
}

func Type_IsStruct(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsStruct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsStruct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsStruct(arg0, arg1)
}

func Type_IsProto(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsProto(arg0, arg1)
}

func Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsStructOrProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsStructOrProto(arg0, arg1)
}

func Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsFloatingPoint(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsFloatingPoint(arg0, arg1)
}

func Type_IsNumerical(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsNumerical(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsNumerical(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsNumerical(arg0, arg1)
}

func Type_IsInteger(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsInteger(arg0, arg1)
}

func Type_IsInteger32(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsInteger32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsInteger32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsInteger32(arg0, arg1)
}

func Type_IsInteger64(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsInteger64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsInteger64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsInteger64(arg0, arg1)
}

func Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsSignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsSignedInteger(arg0, arg1)
}

func Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsUnsignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsUnsignedInteger(arg0, arg1)
}

func Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsSimpleType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsSimpleType(arg0, arg1)
}

func Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_IsExtendedType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_IsExtendedType(arg0, arg1)
}

func Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Type_AsArray(
		arg0,
		arg1,
	)
}

func googlesql_Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Type_AsArray(arg0, arg1)
}

func Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Type_AsStruct(
		arg0,
		arg1,
	)
}

func googlesql_Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Type_AsStruct(arg0, arg1)
}

func Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Type_AsProto(
		arg0,
		arg1,
	)
}

func googlesql_Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Type_AsProto(arg0, arg1)
}

func Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Type_AsEnum(
		arg0,
		arg1,
	)
}

func googlesql_Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Type_AsEnum(arg0, arg1)
}

func Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Type_AsExtendedType(
		arg0,
		arg1,
	)
}

func googlesql_Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Type_AsExtendedType(arg0, arg1)
}

func Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_SupportsGrouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_SupportsGrouping(arg0, arg1)
}

func Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_SupportsPartitioning(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_SupportsPartitioning(arg0, arg1)
}

func Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_SupportsOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_SupportsOrdering(arg0, arg1)
}

func Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_SupportsEquality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_SupportsEquality(arg0, arg1)
}

func Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_Type_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_Type_Equals(arg0, arg1, arg2)
}

func Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_Type_Equivalent(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_Type_Equivalent(arg0, arg1, arg2)
}

func Type_ShortTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Type_ShortTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Type_ShortTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Type_ShortTypeName(arg0, arg1, arg2)
}

func Type_TypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Type_TypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Type_TypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Type_TypeName(arg0, arg1, arg2)
}

func Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	googlesql_Type_TypeNameWithParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func googlesql_Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_Type_TypeNameWithParameters(arg0, arg1, arg2, arg3, arg4)
}

func Type_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Type_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Type_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Type_DebugString(arg0, arg1, arg2)
}

func Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Type_HasAnyFields(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Type_HasAnyFields(arg0, arg1)
}

func Type_NestingDepth(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Type_NestingDepth(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Type_NestingDepth(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Type_NestingDepth(arg0, arg1)
}

func Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	googlesql_Type_ValidateAndResolveTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		C.int(arg3),
		arg4,
		arg5,
	)
}

func googlesql_Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 C.int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	C.export_googlesql_Type_ValidateAndResolveTypeParameters(arg0, arg1, arg2, arg3, arg4, arg5)
}

func Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	googlesql_Type_ValidateResolvedTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func googlesql_Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_Type_ValidateResolvedTypeParameters(arg0, arg1, arg2, arg3)
}

func ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ArrayType_element_type(
		arg0,
		arg1,
	)
}

func googlesql_ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ArrayType_element_type(arg0, arg1)
}

func StructType_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_StructType_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_StructType_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_StructType_num_fields(arg0, arg1)
}

func StructType_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_StructType_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_StructType_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_StructType_field(arg0, arg1, arg2)
}

func StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_StructType_fields(
		arg0,
		arg1,
	)
}

func googlesql_StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_StructType_fields(arg0, arg1)
}

func StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_StructField_new(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_StructField_new(arg0, arg1, arg2)
}

func StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_StructField_name(
		arg0,
		arg1,
	)
}

func googlesql_StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_StructField_name(arg0, arg1)
}

func StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_StructField_type(
		arg0,
		arg1,
	)
}

func googlesql_StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_StructField_type(arg0, arg1)
}

func TypeFactory_new(arg0 *unsafe.Pointer) {
	googlesql_TypeFactory_new(
		arg0,
	)
}

func googlesql_TypeFactory_new(arg0 *unsafe.Pointer) {
	C.export_googlesql_TypeFactory_new(arg0)
}

func TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_TypeFactory_MakeArrayType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_TypeFactory_MakeArrayType(arg0, arg1, arg2, arg3)
}

func TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_TypeFactory_MakeStructType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_TypeFactory_MakeStructType(arg0, arg1, arg2, arg3)
}

func Int32Type(arg0 *unsafe.Pointer) {
	googlesql_Int32Type(
		arg0,
	)
}

func googlesql_Int32Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_Int32Type(arg0)
}

func Int64Type(arg0 *unsafe.Pointer) {
	googlesql_Int64Type(
		arg0,
	)
}

func googlesql_Int64Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_Int64Type(arg0)
}

func Uint32Type(arg0 *unsafe.Pointer) {
	googlesql_Uint32Type(
		arg0,
	)
}

func googlesql_Uint32Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_Uint32Type(arg0)
}

func Uint64Type(arg0 *unsafe.Pointer) {
	googlesql_Uint64Type(
		arg0,
	)
}

func googlesql_Uint64Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_Uint64Type(arg0)
}

func BoolType(arg0 *unsafe.Pointer) {
	googlesql_BoolType(
		arg0,
	)
}

func googlesql_BoolType(arg0 *unsafe.Pointer) {
	C.export_googlesql_BoolType(arg0)
}

func FloatType(arg0 *unsafe.Pointer) {
	googlesql_FloatType(
		arg0,
	)
}

func googlesql_FloatType(arg0 *unsafe.Pointer) {
	C.export_googlesql_FloatType(arg0)
}

func DoubleType(arg0 *unsafe.Pointer) {
	googlesql_DoubleType(
		arg0,
	)
}

func googlesql_DoubleType(arg0 *unsafe.Pointer) {
	C.export_googlesql_DoubleType(arg0)
}

func StringType(arg0 *unsafe.Pointer) {
	googlesql_StringType(
		arg0,
	)
}

func googlesql_StringType(arg0 *unsafe.Pointer) {
	C.export_googlesql_StringType(arg0)
}

func BytesType(arg0 *unsafe.Pointer) {
	googlesql_BytesType(
		arg0,
	)
}

func googlesql_BytesType(arg0 *unsafe.Pointer) {
	C.export_googlesql_BytesType(arg0)
}

func DateType(arg0 *unsafe.Pointer) {
	googlesql_DateType(
		arg0,
	)
}

func googlesql_DateType(arg0 *unsafe.Pointer) {
	C.export_googlesql_DateType(arg0)
}

func TimestampType(arg0 *unsafe.Pointer) {
	googlesql_TimestampType(
		arg0,
	)
}

func googlesql_TimestampType(arg0 *unsafe.Pointer) {
	C.export_googlesql_TimestampType(arg0)
}

func TimeType(arg0 *unsafe.Pointer) {
	googlesql_TimeType(
		arg0,
	)
}

func googlesql_TimeType(arg0 *unsafe.Pointer) {
	C.export_googlesql_TimeType(arg0)
}

func DatetimeType(arg0 *unsafe.Pointer) {
	googlesql_DatetimeType(
		arg0,
	)
}

func googlesql_DatetimeType(arg0 *unsafe.Pointer) {
	C.export_googlesql_DatetimeType(arg0)
}

func IntervalType(arg0 *unsafe.Pointer) {
	googlesql_IntervalType(
		arg0,
	)
}

func googlesql_IntervalType(arg0 *unsafe.Pointer) {
	C.export_googlesql_IntervalType(arg0)
}

func GeographyType(arg0 *unsafe.Pointer) {
	googlesql_GeographyType(
		arg0,
	)
}

func googlesql_GeographyType(arg0 *unsafe.Pointer) {
	C.export_googlesql_GeographyType(arg0)
}

func NumericType(arg0 *unsafe.Pointer) {
	googlesql_NumericType(
		arg0,
	)
}

func googlesql_NumericType(arg0 *unsafe.Pointer) {
	C.export_googlesql_NumericType(arg0)
}

func BigNumericType(arg0 *unsafe.Pointer) {
	googlesql_BigNumericType(
		arg0,
	)
}

func googlesql_BigNumericType(arg0 *unsafe.Pointer) {
	C.export_googlesql_BigNumericType(arg0)
}

func JsonType(arg0 *unsafe.Pointer) {
	googlesql_JsonType(
		arg0,
	)
}

func googlesql_JsonType(arg0 *unsafe.Pointer) {
	C.export_googlesql_JsonType(arg0)
}

func EmptyStructType(arg0 *unsafe.Pointer) {
	googlesql_EmptyStructType(
		arg0,
	)
}

func googlesql_EmptyStructType(arg0 *unsafe.Pointer) {
	C.export_googlesql_EmptyStructType(arg0)
}

func Int32ArrayType(arg0 *unsafe.Pointer) {
	googlesql_Int32ArrayType(
		arg0,
	)
}

func googlesql_Int32ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_Int32ArrayType(arg0)
}

func Int64ArrayType(arg0 *unsafe.Pointer) {
	googlesql_Int64ArrayType(
		arg0,
	)
}

func googlesql_Int64ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_Int64ArrayType(arg0)
}

func Uint32ArrayType(arg0 *unsafe.Pointer) {
	googlesql_Uint32ArrayType(
		arg0,
	)
}

func googlesql_Uint32ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_Uint32ArrayType(arg0)
}

func Uint64ArrayType(arg0 *unsafe.Pointer) {
	googlesql_Uint64ArrayType(
		arg0,
	)
}

func googlesql_Uint64ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_Uint64ArrayType(arg0)
}

func BoolArrayType(arg0 *unsafe.Pointer) {
	googlesql_BoolArrayType(
		arg0,
	)
}

func googlesql_BoolArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_BoolArrayType(arg0)
}

func FloatArrayType(arg0 *unsafe.Pointer) {
	googlesql_FloatArrayType(
		arg0,
	)
}

func googlesql_FloatArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_FloatArrayType(arg0)
}

func DoubleArrayType(arg0 *unsafe.Pointer) {
	googlesql_DoubleArrayType(
		arg0,
	)
}

func googlesql_DoubleArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_DoubleArrayType(arg0)
}

func StringArrayType(arg0 *unsafe.Pointer) {
	googlesql_StringArrayType(
		arg0,
	)
}

func googlesql_StringArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_StringArrayType(arg0)
}

func BytesArrayType(arg0 *unsafe.Pointer) {
	googlesql_BytesArrayType(
		arg0,
	)
}

func googlesql_BytesArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_BytesArrayType(arg0)
}

func TimestampArrayType(arg0 *unsafe.Pointer) {
	googlesql_TimestampArrayType(
		arg0,
	)
}

func googlesql_TimestampArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_TimestampArrayType(arg0)
}

func DateArrayType(arg0 *unsafe.Pointer) {
	googlesql_DateArrayType(
		arg0,
	)
}

func googlesql_DateArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_DateArrayType(arg0)
}

func DatetimeArrayType(arg0 *unsafe.Pointer) {
	googlesql_DatetimeArrayType(
		arg0,
	)
}

func googlesql_DatetimeArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_DatetimeArrayType(arg0)
}

func TimeArrayType(arg0 *unsafe.Pointer) {
	googlesql_TimeArrayType(
		arg0,
	)
}

func googlesql_TimeArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_TimeArrayType(arg0)
}

func IntervalArrayType(arg0 *unsafe.Pointer) {
	googlesql_IntervalArrayType(
		arg0,
	)
}

func googlesql_IntervalArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_IntervalArrayType(arg0)
}

func GeographyArrayType(arg0 *unsafe.Pointer) {
	googlesql_GeographyArrayType(
		arg0,
	)
}

func googlesql_GeographyArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_GeographyArrayType(arg0)
}

func NumericArrayType(arg0 *unsafe.Pointer) {
	googlesql_NumericArrayType(
		arg0,
	)
}

func googlesql_NumericArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_NumericArrayType(arg0)
}

func BigNumericArrayType(arg0 *unsafe.Pointer) {
	googlesql_BigNumericArrayType(
		arg0,
	)
}

func googlesql_BigNumericArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_BigNumericArrayType(arg0)
}

func JsonArrayType(arg0 *unsafe.Pointer) {
	googlesql_JsonArrayType(
		arg0,
	)
}

func googlesql_JsonArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_JsonArrayType(arg0)
}

func DatePartEnumType(arg0 *unsafe.Pointer) {
	googlesql_DatePartEnumType(
		arg0,
	)
}

func googlesql_DatePartEnumType(arg0 *unsafe.Pointer) {
	C.export_googlesql_DatePartEnumType(arg0)
}

func NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	googlesql_NormalizeModeEnumType(
		arg0,
	)
}

func googlesql_NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	C.export_googlesql_NormalizeModeEnumType(arg0)
}

func TypeFromSimpleTypeKind(arg0 int, arg1 *unsafe.Pointer) {
	googlesql_TypeFromSimpleTypeKind(
		C.int(arg0),
		arg1,
	)
}

func googlesql_TypeFromSimpleTypeKind(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_googlesql_TypeFromSimpleTypeKind(arg0, arg1)
}

func Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_type(
		arg0,
		arg1,
	)
}

func googlesql_Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_type(arg0, arg1)
}

func Value_type_kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Value_type_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_type_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Value_type_kind(arg0, arg1)
}

func Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *uint64) {
	googlesql_Value_physical_byte_size(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_Value_physical_byte_size(arg0, arg1)
}

func Value_is_null(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_is_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_is_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_is_null(arg0, arg1)
}

func Value_is_empty_array(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_is_empty_array(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_is_empty_array(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_is_empty_array(arg0, arg1)
}

func Value_is_valid(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_is_valid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_is_valid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_is_valid(arg0, arg1)
}

func Value_has_content(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_has_content(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_has_content(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_has_content(arg0, arg1)
}

func Value_int32_value(arg0 unsafe.Pointer, arg1 *int32) {
	googlesql_Value_int32_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_int32_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_googlesql_Value_int32_value(arg0, arg1)
}

func Value_int64_value(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_Value_int64_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_int64_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_Value_int64_value(arg0, arg1)
}

func Value_uint32_value(arg0 unsafe.Pointer, arg1 *uint32) {
	googlesql_Value_uint32_value(
		arg0,
		(*C.uint32_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_uint32_value(arg0 unsafe.Pointer, arg1 *C.uint32_t) {
	C.export_googlesql_Value_uint32_value(arg0, arg1)
}

func Value_uint64_value(arg0 unsafe.Pointer, arg1 *uint64) {
	googlesql_Value_uint64_value(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_uint64_value(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_Value_uint64_value(arg0, arg1)
}

func Value_bool_value(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_bool_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_bool_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_bool_value(arg0, arg1)
}

func Value_float_value(arg0 unsafe.Pointer, arg1 *float32) {
	googlesql_Value_float_value(
		arg0,
		(*C.float)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_float_value(arg0 unsafe.Pointer, arg1 *C.float) {
	C.export_googlesql_Value_float_value(arg0, arg1)
}

func Value_double_value(arg0 unsafe.Pointer, arg1 *float64) {
	googlesql_Value_double_value(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_double_value(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_googlesql_Value_double_value(arg0, arg1)
}

func Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_string_value(
		arg0,
		arg1,
	)
}

func googlesql_Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_string_value(arg0, arg1)
}

func Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_bytes_value(
		arg0,
		arg1,
	)
}

func googlesql_Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_bytes_value(arg0, arg1)
}

func Value_date_value(arg0 unsafe.Pointer, arg1 *int32) {
	googlesql_Value_date_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_date_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_googlesql_Value_date_value(arg0, arg1)
}

func Value_enum_value(arg0 unsafe.Pointer, arg1 *int32) {
	googlesql_Value_enum_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_enum_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_googlesql_Value_enum_value(arg0, arg1)
}

func Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_enum_name(
		arg0,
		arg1,
	)
}

func googlesql_Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_enum_name(arg0, arg1)
}

func Value_ToTime(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_Value_ToTime(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_ToTime(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_Value_ToTime(arg0, arg1)
}

func Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_Value_ToUnixMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_Value_ToUnixMicros(arg0, arg1)
}

func Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *int64, arg2 *unsafe.Pointer) {
	googlesql_Value_ToUnixNanos(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
		arg2,
	)
}

func googlesql_Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *C.int64_t, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_ToUnixNanos(arg0, arg1, arg2)
}

func Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_Value_ToPacked64TimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_Value_ToPacked64TimeMicros(arg0, arg1)
}

func Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_Value_ToPacked64DatetimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_Value_ToPacked64DatetimeMicros(arg0, arg1)
}

func Value_is_validated_json(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_is_validated_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_is_validated_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_is_validated_json(arg0, arg1)
}

func Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_is_unparsed_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_is_unparsed_json(arg0, arg1)
}

func Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_json_value_unparsed(
		arg0,
		arg1,
	)
}

func googlesql_Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_json_value_unparsed(arg0, arg1)
}

func Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_json_string(
		arg0,
		arg1,
	)
}

func googlesql_Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_json_string(arg0, arg1)
}

func Value_ToInt64(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_Value_ToInt64(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_ToInt64(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_Value_ToInt64(arg0, arg1)
}

func Value_ToUint64(arg0 unsafe.Pointer, arg1 *uint64) {
	googlesql_Value_ToUint64(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_ToUint64(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_Value_ToUint64(arg0, arg1)
}

func Value_ToDouble(arg0 unsafe.Pointer, arg1 *float64) {
	googlesql_Value_ToDouble(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_ToDouble(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_googlesql_Value_ToDouble(arg0, arg1)
}

func Value_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Value_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Value_num_fields(arg0, arg1)
}

func Value_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Value_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Value_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_field(arg0, arg1, arg2)
}

func Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Value_FindFieldByName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_FindFieldByName(arg0, arg1, arg2)
}

func Value_empty(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Value_empty(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_empty(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Value_empty(arg0, arg1)
}

func Value_num_elements(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Value_num_elements(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_num_elements(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Value_num_elements(arg0, arg1)
}

func Value_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Value_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Value_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_element(arg0, arg1, arg2)
}

func Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_Value_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_Value_Equals(arg0, arg1, arg2)
}

func Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Value_SqlEquals(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_SqlEquals(arg0, arg1, arg2)
}

func Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_Value_LessThan(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_Value_LessThan(arg0, arg1, arg2)
}

func Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Value_SqlLessThan(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_SqlLessThan(arg0, arg1, arg2)
}

func Value_HashCode(arg0 unsafe.Pointer, arg1 *uint64) {
	googlesql_Value_HashCode(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Value_HashCode(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_Value_HashCode(arg0, arg1)
}

func Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_ShortDebugString(
		arg0,
		arg1,
	)
}

func googlesql_Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_ShortDebugString(arg0, arg1)
}

func Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_FullDebugString(
		arg0,
		arg1,
	)
}

func googlesql_Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_FullDebugString(arg0, arg1)
}

func Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_DebugString(
		arg0,
		arg1,
	)
}

func googlesql_Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_DebugString(arg0, arg1)
}

func Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Value_Format(
		arg0,
		arg1,
	)
}

func googlesql_Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Value_Format(arg0, arg1)
}

func Value_GetSQL(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Value_GetSQL(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Value_GetSQL(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_GetSQL(arg0, arg1, arg2)
}

func Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Value_GetSQLLiteral(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Value_GetSQLLiteral(arg0, arg1, arg2)
}

func Int64(arg0 int64, arg1 *unsafe.Pointer) {
	googlesql_Int64(
		C.int64_t(arg0),
		arg1,
	)
}

func googlesql_Int64(arg0 C.int64_t, arg1 *unsafe.Pointer) {
	C.export_googlesql_Int64(arg0, arg1)
}

func Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Column_Name(
		arg0,
		arg1,
	)
}

func googlesql_Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Column_Name(arg0, arg1)
}

func Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Column_FullName(
		arg0,
		arg1,
	)
}

func googlesql_Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Column_FullName(arg0, arg1)
}

func Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Column_Type(
		arg0,
		arg1,
	)
}

func googlesql_Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Column_Type(arg0, arg1)
}

func Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Column_IsPseudoColumn(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Column_IsPseudoColumn(arg0, arg1)
}

func Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Column_IsWritableColumn(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Column_IsWritableColumn(arg0, arg1)
}

func SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleColumn_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleColumn_new(arg0, arg1, arg2, arg3)
}

func SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 int, arg4 int, arg5 *unsafe.Pointer) {
	googlesql_SimpleColumn_new_with_opt(
		arg0,
		arg1,
		arg2,
		C.int(arg3),
		C.int(arg4),
		arg5,
	)
}

func googlesql_SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 C.int, arg4 C.int, arg5 *unsafe.Pointer) {
	C.export_googlesql_SimpleColumn_new_with_opt(arg0, arg1, arg2, arg3, arg4, arg5)
}

func SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleColumn_AnnotatedType(
		arg0,
		arg1,
	)
}

func googlesql_SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleColumn_AnnotatedType(arg0, arg1)
}

func SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 int) {
	googlesql_SimpleColumn_SetIsPseudoColumn(
		arg0,
		C.int(arg1),
	)
}

func googlesql_SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_SimpleColumn_SetIsPseudoColumn(arg0, arg1)
}

func Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Table_Name(
		arg0,
		arg1,
	)
}

func googlesql_Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Table_Name(arg0, arg1)
}

func Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Table_FullName(
		arg0,
		arg1,
	)
}

func googlesql_Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Table_FullName(arg0, arg1)
}

func Table_NumColumns(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Table_NumColumns(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Table_NumColumns(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Table_NumColumns(arg0, arg1)
}

func Table_Column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Table_Column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Table_Column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Table_Column(arg0, arg1, arg2)
}

func Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Table_PrimaryKey_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Table_PrimaryKey_num(arg0, arg1)
}

func Table_PrimaryKey(arg0 unsafe.Pointer, arg1 int, arg2 *int) {
	googlesql_Table_PrimaryKey(
		arg0,
		C.int(arg1),
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func googlesql_Table_PrimaryKey(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.int) {
	C.export_googlesql_Table_PrimaryKey(arg0, arg1, arg2)
}

func Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Table_FindColumnByName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Table_FindColumnByName(arg0, arg1, arg2)
}

func Table_IsValueTable(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Table_IsValueTable(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Table_IsValueTable(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Table_IsValueTable(arg0, arg1)
}

func Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Table_GetSerializationId(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Table_GetSerializationId(arg0, arg1)
}

func Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	googlesql_Table_CreateEvaluatorTableIterator(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func googlesql_Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_Table_CreateEvaluatorTableIterator(arg0, arg1, arg2, arg3, arg4)
}

func Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Table_GetAnonymizationInfo(
		arg0,
		arg1,
	)
}

func googlesql_Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Table_GetAnonymizationInfo(arg0, arg1)
}

func Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Table_SupportsAnonymization(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Table_SupportsAnonymization(arg0, arg1)
}

func Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Table_GetTableTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Table_GetTableTypeName(arg0, arg1, arg2)
}

func SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	googlesql_SimpleTable_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func googlesql_SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleTable_new(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	googlesql_SimpleTable_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func googlesql_SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_SimpleTable_set_is_value_table(arg0, arg1)
}

func SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_SimpleTable_AllowAnonymousColumnName(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_SimpleTable_AllowAnonymousColumnName(arg0, arg1)
}

func SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_SimpleTable_set_allow_anonymous_column_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleTable_set_allow_anonymous_column_name(arg0, arg1, arg2)
}

func SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_SimpleTable_AllowDuplicateColumnNames(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_SimpleTable_AllowDuplicateColumnNames(arg0, arg1)
}

func SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_SimpleTable_set_allow_duplicate_column_names(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleTable_set_allow_duplicate_column_names(arg0, arg1, arg2)
}

func SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleTable_AddColumn(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleTable_AddColumn(arg0, arg1, arg2)
}

func SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	googlesql_SimpleTable_SetPrimaryKey(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func googlesql_SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleTable_SetPrimaryKey(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleTable_set_full_name(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleTable_set_full_name(arg0, arg1, arg2)
}

func SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleTable_SetAnonymizationInfo(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleTable_SetAnonymizationInfo(arg0, arg1, arg2)
}

func SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	googlesql_SimpleTable_ResetAnonymizationInfo(
		arg0,
	)
}

func googlesql_SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	C.export_googlesql_SimpleTable_ResetAnonymizationInfo(arg0)
}

func Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Catalog_FullName(
		arg0,
		arg1,
	)
}

func googlesql_Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FullName(arg0, arg1)
}

func Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_Catalog_FindTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FindTable(arg0, arg1, arg2, arg3)
}

func Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_Catalog_FindModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FindModel(arg0, arg1, arg2, arg3)
}

func Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_Catalog_FindFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FindFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_Catalog_FindTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FindTableValuedFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_Catalog_FindProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FindProcedure(arg0, arg1, arg2, arg3)
}

func Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_Catalog_FindType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FindType(arg0, arg1, arg2, arg3)
}

func Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *int, arg4 *unsafe.Pointer) {
	googlesql_Catalog_FindConstant(
		arg0,
		arg1,
		arg2,
		(*C.int)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func googlesql_Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.int, arg4 *unsafe.Pointer) {
	C.export_googlesql_Catalog_FindConstant(arg0, arg1, arg2, arg3, arg4)
}

func Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Catalog_SuggestTable(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Catalog_SuggestTable(arg0, arg1, arg2)
}

func Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Catalog_SuggestModel(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Catalog_SuggestModel(arg0, arg1, arg2)
}

func Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Catalog_SuggestFunction(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Catalog_SuggestFunction(arg0, arg1, arg2)
}

func Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Catalog_SuggestTableValuedTable(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Catalog_SuggestTableValuedTable(arg0, arg1, arg2)
}

func Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Catalog_SuggestConstant(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Catalog_SuggestConstant(arg0, arg1, arg2)
}

func EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_EnumerableCatalog_Catalogs(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_EnumerableCatalog_Catalogs(arg0, arg1, arg2)
}

func EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_EnumerableCatalog_Tables(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_EnumerableCatalog_Tables(arg0, arg1, arg2)
}

func EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_EnumerableCatalog_Types(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_EnumerableCatalog_Types(arg0, arg1, arg2)
}

func EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_EnumerableCatalog_Functions(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_EnumerableCatalog_Functions(arg0, arg1, arg2)
}

func SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleCatalog_new(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_new(arg0, arg1)
}

func SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetTable(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetTables(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetTables(arg0, arg1, arg2)
}

func SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleCatalog_table_names(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_table_names(arg0, arg1)
}

func SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetModel(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetFunctions(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetFunctions(arg0, arg1, arg2)
}

func SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleCatalog_function_names(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_function_names(arg0, arg1)
}

func SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetTableValuedFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleCatalog_table_valued_functions(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_table_valued_functions(arg0, arg1)
}

func SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleCatalog_table_valued_function_names(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_table_valued_function_names(arg0, arg1)
}

func SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetProcedure(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleCatalog_procedures(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_procedures(arg0, arg1)
}

func SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetType(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetTypes(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetTypes(arg0, arg1, arg2)
}

func SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetCatalog(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetCatalog(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleCatalog_GetCatalogs(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_GetCatalogs(arg0, arg1, arg2)
}

func SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_SimpleCatalog_catalog_names(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_catalog_names(arg0, arg1)
}

func SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddTable(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddTable(arg0, arg1)
}

func SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddTableWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddTableWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddModel(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddModel(arg0, arg1)
}

func SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddModelWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddModelWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddConnection(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddConnection(arg0, arg1)
}

func SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddConnectionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddConnectionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddType(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddType(arg0, arg1, arg2)
}

func SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	googlesql_SimpleCatalog_AddTypeIfNotPresent(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func googlesql_SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_googlesql_SimpleCatalog_AddTypeIfNotPresent(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddCatalog(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddCatalog(arg0, arg1)
}

func SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddCatalogWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddCatalogWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddFunction(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddFunction(arg0, arg1)
}

func SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddTableValuedFunction(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddTableValuedFunction(arg0, arg1)
}

func SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddTableValuedFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddTableValuedFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddProcedure(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddProcedure(arg0, arg1)
}

func SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddProcedureWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddProcedureWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddConstant(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddConstant(arg0, arg1)
}

func SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddConstantWithName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddConstantWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddGoogleSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_SimpleCatalog_AddGoogleSQLFunctions(
		arg0,
		arg1,
	)
}

func googlesql_SimpleCatalog_AddGoogleSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_SimpleCatalog_AddGoogleSQLFunctions(arg0, arg1)
}

func Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Constant_Name(
		arg0,
		arg1,
	)
}

func googlesql_Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Constant_Name(arg0, arg1)
}

func Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Constant_FullName(
		arg0,
		arg1,
	)
}

func googlesql_Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Constant_FullName(arg0, arg1)
}

func Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Constant_type(
		arg0,
		arg1,
	)
}

func googlesql_Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Constant_type(arg0, arg1)
}

func Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Constant_DebugString(
		arg0,
		arg1,
	)
}

func googlesql_Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Constant_DebugString(arg0, arg1)
}

func Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Constant_name_path(
		arg0,
		arg1,
	)
}

func googlesql_Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Constant_name_path(arg0, arg1)
}

func Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Model_Name(
		arg0,
		arg1,
	)
}

func googlesql_Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Model_Name(arg0, arg1)
}

func Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Model_FullName(
		arg0,
		arg1,
	)
}

func googlesql_Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Model_FullName(arg0, arg1)
}

func Model_NumInputs(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Model_NumInputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Model_NumInputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Model_NumInputs(arg0, arg1)
}

func Model_Input(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Model_Input(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Model_Input(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Model_Input(arg0, arg1, arg2)
}

func Model_NumOutputs(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Model_NumOutputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Model_NumOutputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Model_NumOutputs(arg0, arg1)
}

func Model_Output(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Model_Output(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Model_Output(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Model_Output(arg0, arg1, arg2)
}

func Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Model_FindInputByName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Model_FindInputByName(arg0, arg1, arg2)
}

func Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Model_FindOutputByName(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Model_FindOutputByName(arg0, arg1, arg2)
}

func Model_SerializationID(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Model_SerializationID(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Model_SerializationID(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Model_SerializationID(arg0, arg1)
}

func SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_SimpleModel_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_SimpleModel_new(arg0, arg1, arg2, arg3)
}

func SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleModel_AddInput(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleModel_AddInput(arg0, arg1, arg2)
}

func SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SimpleModel_AddOutput(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SimpleModel_AddOutput(arg0, arg1, arg2)
}

func BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_BuiltinFunctionOptions_new(
		arg0,
		arg1,
	)
}

func googlesql_BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_BuiltinFunctionOptions_new(arg0, arg1)
}

func Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	googlesql_Function_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func googlesql_Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_Function_new(arg0, arg1, arg2, arg3, arg4)
}

func Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Function_Name(
		arg0,
		arg1,
	)
}

func googlesql_Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Function_Name(arg0, arg1)
}

func Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Function_FunctionNamePath(
		arg0,
		arg1,
	)
}

func googlesql_Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Function_FunctionNamePath(arg0, arg1)
}

func Function_FullName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Function_FullName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Function_FullName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Function_FullName(arg0, arg1, arg2)
}

func Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Function_SQLName(
		arg0,
		arg1,
	)
}

func googlesql_Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Function_SQLName(arg0, arg1)
}

func Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Function_QualifiedSQLName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Function_QualifiedSQLName(arg0, arg1, arg2)
}

func Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Function_Group(
		arg0,
		arg1,
	)
}

func googlesql_Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Function_Group(arg0, arg1)
}

func Function_IsGoogleSQLBuiltin(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_IsGoogleSQLBuiltin(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_IsGoogleSQLBuiltin(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_IsGoogleSQLBuiltin(arg0, arg1)
}

func Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_ArgumentsAreCoercible(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_ArgumentsAreCoercible(arg0, arg1)
}

func Function_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Function_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Function_NumSignatures(arg0, arg1)
}

func Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Function_signatures(
		arg0,
		arg1,
	)
}

func googlesql_Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Function_signatures(arg0, arg1)
}

func Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_Function_ResetSignatures(
		arg0,
		arg1,
	)
}

func googlesql_Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_Function_ResetSignatures(arg0, arg1)
}

func Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_Function_AddSignature(
		arg0,
		arg1,
	)
}

func googlesql_Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_Function_AddSignature(arg0, arg1)
}

func Function_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_Function_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_Function_mode(arg0, arg1)
}

func Function_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_IsScalar(arg0, arg1)
}

func Function_IsAggregate(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_IsAggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_IsAggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_IsAggregate(arg0, arg1)
}

func Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_IsAnalytic(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_IsAnalytic(arg0, arg1)
}

func Function_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Function_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Function_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Function_DebugString(arg0, arg1, arg2)
}

func Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	googlesql_Function_GetSQL(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func googlesql_Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_Function_GetSQL(arg0, arg1, arg2, arg3)
}

func Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsOverClause(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsOverClause(arg0, arg1)
}

func Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsWindowOrdering(arg0, arg1)
}

func Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_RequiresWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_RequiresWindowOrdering(arg0, arg1)
}

func Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsWindowFraming(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsWindowFraming(arg0, arg1)
}

func Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsOrderingArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsOrderingArguments(arg0, arg1)
}

func Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsLimitArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsLimitArguments(arg0, arg1)
}

func Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsNullHandlingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsNullHandlingModifier(arg0, arg1)
}

func Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsSafeErrorMode(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsSafeErrorMode(arg0, arg1)
}

func Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsHavingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsHavingModifier(arg0, arg1)
}

func Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsDistinctModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsDistinctModifier(arg0, arg1)
}

func Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_SupportsClampedBetweenModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_SupportsClampedBetweenModifier(arg0, arg1)
}

func Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_Function_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_Function_IsDeprecated(arg0, arg1)
}

func Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Function_alias_name(
		arg0,
		arg1,
	)
}

func googlesql_Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Function_alias_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_new(arg0 int, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_new(
		C.int(arg0),
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_new(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_new(arg0, arg1)
}

func FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionArgumentTypeOptions_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_must_be_non_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_is_not_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_must_support_equality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_must_support_ordering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_must_support_grouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_has_min_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_has_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_has_max_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_has_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_FunctionArgumentTypeOptions_min_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_FunctionArgumentTypeOptions_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *int64) {
	googlesql_FunctionArgumentTypeOptions_max_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_FunctionArgumentTypeOptions_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_has_relation_input_schema(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_has_relation_input_schema(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_has_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_argument_name(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_argument_name_is_mandatory(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionArgumentTypeOptions_procedure_argument_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_cardinality(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_must_be_constant(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_must_be_non_null(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_is_not_aggregate(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_must_support_equality(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_must_support_ordering(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_must_support_grouping(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 int64) {
	googlesql_FunctionArgumentTypeOptions_set_min_value(
		arg0,
		C.int64_t(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 int64) {
	googlesql_FunctionArgumentTypeOptions_set_max_value(
		arg0,
		C.int64_t(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_set_argument_name(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_procedure_argument_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_OptionsDebugString(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_OptionsDebugString(arg0, arg1)
}

func FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0, arg1, arg2)
}

func FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_set_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_set_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_set_default(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_has_default(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_has_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_get_default(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_get_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	googlesql_FunctionArgumentTypeOptions_clear_default(
		arg0,
	)
}

func googlesql_FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentTypeOptions_clear_default(arg0)
}

func FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionArgumentTypeOptions_argument_collation_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentTypeOptions_uses_array_element_for_collation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentTypeOptions_set_argument_collation_mode(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_new(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_new(arg0, arg1, arg2)
}

func FunctionArgumentType_new_templated_type(arg0 int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_new_templated_type(
		C.int(arg0),
		arg1,
		arg2,
	)
}

func googlesql_FunctionArgumentType_new_templated_type(arg0 C.int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_new_templated_type(arg0, arg1, arg2)
}

func FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_options(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_options(arg0, arg1)
}

func FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_required(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_required(arg0, arg1)
}

func FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_repeated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_repeated(arg0, arg1)
}

func FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_optional(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_optional(arg0, arg1)
}

func FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionArgumentType_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionArgumentType_cardinality(arg0, arg1)
}

func FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_must_be_constant(arg0, arg1)
}

func FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_has_argument_name(arg0, arg1)
}

func FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_argument_name(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_argument_name(arg0, arg1)
}

func FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionArgumentType_num_occurrences(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionArgumentType_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionArgumentType_set_num_occurrences(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionArgumentType_set_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	googlesql_FunctionArgumentType_IncrementNumOccurrences(
		arg0,
	)
}

func googlesql_FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_IncrementNumOccurrences(arg0)
}

func FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_type(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_type(arg0, arg1)
}

func FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionArgumentType_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionArgumentType_kind(arg0, arg1)
}

func FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_labmda(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_labmda(arg0, arg1)
}

func FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsConcrete(arg0, arg1)
}

func FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsTemplated(arg0, arg1)
}

func FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsScalar(arg0, arg1)
}

func FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsRelation(arg0, arg1)
}

func FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsModel(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsModel(arg0, arg1)
}

func FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsConnection(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsConnection(arg0, arg1)
}

func FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsLambda(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsLambda(arg0, arg1)
}

func FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsFixedRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsFixedRelation(arg0, arg1)
}

func FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsVoid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsVoid(arg0, arg1)
}

func FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_IsDescriptor(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_IsDescriptor(arg0, arg1)
}

func FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	googlesql_FunctionArgumentType_TemplatedKindIsRelated(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_googlesql_FunctionArgumentType_TemplatedKindIsRelated(arg0, arg1, arg2)
}

func FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	googlesql_FunctionArgumentType_AllowCoercionFrom(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func googlesql_FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_FunctionArgumentType_AllowCoercionFrom(arg0, arg1, arg2)
}

func FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionArgumentType_HasDefault(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionArgumentType_HasDefault(arg0, arg1)
}

func FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_GetDefault(
		arg0,
		arg1,
	)
}

func googlesql_FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_GetDefault(arg0, arg1)
}

func FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_UserFacingName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_UserFacingName(arg0, arg1, arg2)
}

func FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_UserFacingNameWithCardinality(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_UserFacingNameWithCardinality(arg0, arg1, arg2)
}

func FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_IsValid(arg0, arg1, arg2)
}

func FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_DebugString(arg0, arg1, arg2)
}

func FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_FunctionArgumentType_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionArgumentType_GetSQLDeclaration(arg0, arg1, arg2)
}

func ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ArgumentTypeLambda_argument_types(
		arg0,
		arg1,
	)
}

func googlesql_ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ArgumentTypeLambda_argument_types(arg0, arg1)
}

func ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_ArgumentTypeLambda_body_type(
		arg0,
		arg1,
	)
}

func googlesql_ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_ArgumentTypeLambda_body_type(arg0, arg1)
}

func FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_FunctionSignature_new(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_new(arg0, arg1, arg2)
}

func FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionSignature_arguments(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_arguments(arg0, arg1)
}

func FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionSignature_concret_arguments(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_concret_arguments(arg0, arg1)
}

func FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionSignature_result_type(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_result_type(arg0, arg1)
}

func FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionSignature_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionSignature_IsConcrete(arg0, arg1)
}

func FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionSignature_HasConcreteArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionSignature_HasConcreteArguments(arg0, arg1)
}

func FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_FunctionSignature_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_IsValid(arg0, arg1, arg2)
}

func FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionSignature_IsValidForFunction(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_IsValidForFunction(arg0, arg1)
}

func FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionSignature_IsValidForTableValuedFunction(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_IsValidForTableValuedFunction(arg0, arg1)
}

func FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionSignature_IsValidForProcedure(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_IsValidForProcedure(arg0, arg1)
}

func FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionSignature_FirstRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionSignature_FirstRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionSignature_LastRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionSignature_LastRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionSignature_NumRequiredArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionSignature_NumRequiredArguments(arg0, arg1)
}

func FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionSignature_NumRepeatedArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionSignature_NumRepeatedArguments(arg0, arg1)
}

func FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_FunctionSignature_NumOptionalArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_FunctionSignature_NumOptionalArguments(arg0, arg1)
}

func FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	googlesql_FunctionSignature_DebugString(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func googlesql_FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_DebugString(arg0, arg1, arg2, arg3)
}

func FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	googlesql_FunctionSignature_GetSQLDeclaration(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func googlesql_FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_GetSQLDeclaration(arg0, arg1, arg2, arg3)
}

func FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionSignature_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionSignature_IsDeprecated(arg0, arg1)
}

func FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 int) {
	googlesql_FunctionSignature_SetIsDeprecated(
		arg0,
		C.int(arg1),
	)
}

func googlesql_FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_FunctionSignature_SetIsDeprecated(arg0, arg1)
}

func FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionSignature_IsInternal(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionSignature_IsInternal(arg0, arg1)
}

func FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_FunctionSignature_options(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_options(arg0, arg1)
}

func FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	googlesql_FunctionSignature_SetConcreteResultType(
		arg0,
		arg1,
	)
}

func googlesql_FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_FunctionSignature_SetConcreteResultType(arg0, arg1)
}

func FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionSignature_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionSignature_IsTemplated(arg0, arg1)
}

func FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *bool) {
	googlesql_FunctionSignature_AllArgumentsHaveDefaults(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func googlesql_FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_FunctionSignature_AllArgumentsHaveDefaults(arg0, arg1)
}

func Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_Procedure_new(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_Procedure_new(arg0, arg1, arg2)
}

func Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Procedure_Name(
		arg0,
		arg1,
	)
}

func googlesql_Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Procedure_Name(arg0, arg1)
}

func Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Procedure_FullName(
		arg0,
		arg1,
	)
}

func googlesql_Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Procedure_FullName(arg0, arg1)
}

func Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Procedure_NamePath(
		arg0,
		arg1,
	)
}

func googlesql_Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Procedure_NamePath(arg0, arg1)
}

func Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_Procedure_Signature(
		arg0,
		arg1,
	)
}

func googlesql_Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_Procedure_Signature(arg0, arg1)
}

func Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_Procedure_SupportedSignatureUserFacingText(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_Procedure_SupportedSignatureUserFacingText(arg0, arg1, arg2)
}

func SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_SQLTableValuedFunction_new(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_SQLTableValuedFunction_new(arg0, arg1, arg2)
}

func TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TableValuedFunction_Name(
		arg0,
		arg1,
	)
}

func googlesql_TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_Name(arg0, arg1)
}

func TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TableValuedFunction_FullName(
		arg0,
		arg1,
	)
}

func googlesql_TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_FullName(arg0, arg1)
}

func TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TableValuedFunction_function_name_path(
		arg0,
		arg1,
	)
}

func googlesql_TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_function_name_path(arg0, arg1)
}

func TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	googlesql_TableValuedFunction_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func googlesql_TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_TableValuedFunction_NumSignatures(arg0, arg1)
}

func TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TableValuedFunction_signatures(
		arg0,
		arg1,
	)
}

func googlesql_TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_signatures(arg0, arg1)
}

func TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_TableValuedFunction_AddSignature(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_AddSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	googlesql_TableValuedFunction_GetSignature(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func googlesql_TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_GetSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TableValuedFunction_GetSupportedSignaturesUserFacingText(
		arg0,
		arg1,
	)
}

func googlesql_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0, arg1)
}

func TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TableValuedFunction_DebugString(
		arg0,
		arg1,
	)
}

func googlesql_TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_DebugString(arg0, arg1)
}

func TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_TableValuedFunction_SetUserIdColumnNamePath(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_SetUserIdColumnNamePath(arg0, arg1, arg2)
}

func TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	googlesql_TableValuedFunction_anonymization_info(
		arg0,
		arg1,
	)
}

func googlesql_TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_TableValuedFunction_anonymization_info(arg0, arg1)
}

func FormatSql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	googlesql_FormatSql(
		arg0,
		arg1,
		arg2,
	)
}

func googlesql_FormatSql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_FormatSql(arg0, arg1, arg2)
}

//export export_googlesql_cctz_FixedOffsetFromName
//go:linkname export_googlesql_cctz_FixedOffsetFromName github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_googlesql_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_cctz_FixedOffsetToName
//go:linkname export_googlesql_cctz_FixedOffsetToName github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_googlesql_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_cctz_FixedOffsetToAbbr
//go:linkname export_googlesql_cctz_FixedOffsetToAbbr github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_googlesql_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_cctz_detail_format
//go:linkname export_googlesql_cctz_detail_format github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_googlesql_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_googlesql_cctz_detail_parse
//go:linkname export_googlesql_cctz_detail_parse github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_googlesql_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_googlesql_TimeZoneIf_Load
//go:linkname export_googlesql_TimeZoneIf_Load github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_googlesql_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_time_zone_Impl_UTC
//go:linkname export_googlesql_time_zone_Impl_UTC github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_googlesql_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_googlesql_time_zone_Impl_LoadTimeZone
//go:linkname export_googlesql_time_zone_Impl_LoadTimeZone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_googlesql_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_googlesql_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_googlesql_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_googlesql_time_zone_Impl_UTCImpl
//go:linkname export_googlesql_time_zone_Impl_UTCImpl github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_googlesql_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_googlesql_TimeZoneInfo_Load
//go:linkname export_googlesql_TimeZoneInfo_Load github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_googlesql_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_TimeZoneInfo_BreakTime
//go:linkname export_googlesql_TimeZoneInfo_BreakTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_googlesql_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_TimeZoneInfo_MakeTime
//go:linkname export_googlesql_TimeZoneInfo_MakeTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_googlesql_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_TimeZoneInfo_Version
//go:linkname export_googlesql_TimeZoneInfo_Version github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_googlesql_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_TimeZoneInfo_Description
//go:linkname export_googlesql_TimeZoneInfo_Description github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_googlesql_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_TimeZoneInfo_NextTransition
//go:linkname export_googlesql_TimeZoneInfo_NextTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_googlesql_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_TimeZoneInfo_PrevTransition
//go:linkname export_googlesql_TimeZoneInfo_PrevTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_googlesql_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_TimeZoneLibC_BreakTime
//go:linkname export_googlesql_TimeZoneLibC_BreakTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_googlesql_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_TimeZoneLibC_MakeTime
//go:linkname export_googlesql_TimeZoneLibC_MakeTime github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_googlesql_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_TimeZoneLibC_Version
//go:linkname export_googlesql_TimeZoneLibC_Version github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_googlesql_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_TimeZoneLibC_NextTransition
//go:linkname export_googlesql_TimeZoneLibC_NextTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_googlesql_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_TimeZoneLibC_PrevTransition
//go:linkname export_googlesql_TimeZoneLibC_PrevTransition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_googlesql_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_time_zone_name
//go:linkname export_googlesql_time_zone_name github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_googlesql_time_zone_name(arg0 *unsafe.Pointer)

//export export_googlesql_time_zone_lookup
//go:linkname export_googlesql_time_zone_lookup github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_googlesql_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_time_zone_lookup2
//go:linkname export_googlesql_time_zone_lookup2 github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_googlesql_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_time_zone_next_transition
//go:linkname export_googlesql_time_zone_next_transition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_googlesql_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_time_zone_prev_transition
//go:linkname export_googlesql_time_zone_prev_transition github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_googlesql_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_time_zone_version
//go:linkname export_googlesql_time_zone_version github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_googlesql_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_time_zone_description
//go:linkname export_googlesql_time_zone_description github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_googlesql_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_cctz_load_time_zone
//go:linkname export_googlesql_cctz_load_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_googlesql_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_cctz_utc_time_zone
//go:linkname export_googlesql_cctz_utc_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_googlesql_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_googlesql_cctz_fixed_time_zone
//go:linkname export_googlesql_cctz_fixed_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_googlesql_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_cctz_local_time_zone
//go:linkname export_googlesql_cctz_local_time_zone github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_googlesql_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_googlesql_cctz_ParsePosixSpec
//go:linkname export_googlesql_cctz_ParsePosixSpec github.com/vantaboard/go-googlesql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_googlesql_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)
