package catalog

/*
#cgo CXXFLAGS: -std=c++17
#cgo CXXFLAGS: -I../../../
#cgo CXXFLAGS: -I../../../protobuf
#cgo CXXFLAGS: -I../../../utf8_range
#cgo CXXFLAGS: -I../../../gtest
#cgo CXXFLAGS: -I../../../icu
#cgo CXXFLAGS: -I../../../re2
#cgo CXXFLAGS: -I../../../json
#cgo CXXFLAGS: -I../../../googleapis
#cgo CXXFLAGS: -I../../../boringssl
#cgo CXXFLAGS: -I../../../flex/src
#cgo CXXFLAGS: -Wno-final-dtor-non-final-class
#cgo CXXFLAGS: -Wno-implicit-const-int-float-conversion
#cgo CXXFLAGS: -Wno-char-subscripts
#cgo CXXFLAGS: -Wno-sign-compare
#cgo CXXFLAGS: -Wno-switch
#cgo CXXFLAGS: -Wno-unused-function
#cgo CXXFLAGS: -Wno-deprecated-declarations
#cgo CXXFLAGS: -Wno-inconsistent-missing-override
#cgo CXXFLAGS: -Wno-unknown-attributes
#cgo CXXFLAGS: -Wno-macro-redefined
#cgo CXXFLAGS: -Wno-shift-count-overflow
#cgo CXXFLAGS: -Wno-enum-compare-switch
#cgo CXXFLAGS: -Wno-return-type
#cgo CXXFLAGS: -Wno-subobject-linkage
#cgo CXXFLAGS: -Wno-unknown-warning-option
#cgo CXXFLAGS: -DHAVE_PTHREAD
#cgo CXXFLAGS: -DU_COMMON_IMPLEMENTATION
#cgo LDFLAGS: -ldl

#define GO_EXPORT(API) export_zetasql_public_catalog_ ## API
#include "bridge.h"
#include "../../../go-absl/time/go_internal/cctz/time_zone/bridge.h"
*/
import "C"
import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql"
	"unsafe"
)

func GoCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	catalog_GoCatalog_new(
		arg0,
		arg1,
	)
}

func catalog_GoCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_catalog_GoCatalog_new(arg0, arg1)
}

func GoTable_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	catalog_GoTable_new(
		arg0,
		arg1,
	)
}

func catalog_GoTable_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_zetasql_public_catalog_GoTable_new(arg0, arg1)
}

//export GoCatalog_FullName
//go:linkname GoCatalog_FullName github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FullName
func GoCatalog_FullName(v unsafe.Pointer) *C.char

//export GoCatalog_FindTable
//go:linkname GoCatalog_FindTable github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindTable
func GoCatalog_FindTable(v unsafe.Pointer, pathPtr unsafe.Pointer, table *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindModel
//go:linkname GoCatalog_FindModel github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindModel
func GoCatalog_FindModel(v unsafe.Pointer, pathPtr unsafe.Pointer, model *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindConnection
//go:linkname GoCatalog_FindConnection github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindConnection
func GoCatalog_FindConnection(v unsafe.Pointer, pathPtr unsafe.Pointer, conn *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindFunction
//go:linkname GoCatalog_FindFunction github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindFunction
func GoCatalog_FindFunction(v unsafe.Pointer, pathPtr unsafe.Pointer, fn *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindTableValuedFunction
//go:linkname GoCatalog_FindTableValuedFunction github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindTableValuedFunction
func GoCatalog_FindTableValuedFunction(v unsafe.Pointer, pathPtr unsafe.Pointer, fn *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindProcedure
//go:linkname GoCatalog_FindProcedure github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindProcedure
func GoCatalog_FindProcedure(v unsafe.Pointer, pathPtr unsafe.Pointer, proc *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindType
//go:linkname GoCatalog_FindType github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindType
func GoCatalog_FindType(v unsafe.Pointer, pathPtr unsafe.Pointer, typ *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindConstant
//go:linkname GoCatalog_FindConstant github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindConstant
func GoCatalog_FindConstant(v unsafe.Pointer, pathPtr unsafe.Pointer, numNamesConsumed *C.int, constant *unsafe.Pointer, ret **C.char)

//export GoCatalog_FindConversion
//go:linkname GoCatalog_FindConversion github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_FindConversion
func GoCatalog_FindConversion(v unsafe.Pointer, from unsafe.Pointer, to unsafe.Pointer, conv *unsafe.Pointer, ret **C.char)

//export GoCatalog_ExtendedTypeSuperTypes
//go:linkname GoCatalog_ExtendedTypeSuperTypes github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_ExtendedTypeSuperTypes
func GoCatalog_ExtendedTypeSuperTypes(v unsafe.Pointer, typ unsafe.Pointer, list *unsafe.Pointer, ret **C.char)

//export GoCatalog_SuggestTable
//go:linkname GoCatalog_SuggestTable github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_SuggestTable
func GoCatalog_SuggestTable(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char

//export GoCatalog_SuggestModel
//go:linkname GoCatalog_SuggestModel github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_SuggestModel
func GoCatalog_SuggestModel(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char

//export GoCatalog_SuggestFunction
//go:linkname GoCatalog_SuggestFunction github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_SuggestFunction
func GoCatalog_SuggestFunction(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char

//export GoCatalog_SuggestTableValuedFunction
//go:linkname GoCatalog_SuggestTableValuedFunction github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_SuggestTableValuedFunction
func GoCatalog_SuggestTableValuedFunction(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char

//export GoCatalog_SuggestConstant
//go:linkname GoCatalog_SuggestConstant github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoCatalog_SuggestConstant
func GoCatalog_SuggestConstant(v unsafe.Pointer, pathPtr unsafe.Pointer) *C.char

//export GoTable_Name
//go:linkname GoTable_Name github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_Name
func GoTable_Name(v unsafe.Pointer) *C.char

//export GoTable_FullName
//go:linkname GoTable_FullName github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_FullName
func GoTable_FullName(v unsafe.Pointer) *C.char

//export GoTable_NumColumns
//go:linkname GoTable_NumColumns github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_NumColumns
func GoTable_NumColumns(v unsafe.Pointer) C.int

//export GoTable_Column
//go:linkname GoTable_Column github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_Column
func GoTable_Column(v unsafe.Pointer, idx C.int) unsafe.Pointer

//export GoTable_PrimaryKey
//go:linkname GoTable_PrimaryKey github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_PrimaryKey
func GoTable_PrimaryKey(v unsafe.Pointer) unsafe.Pointer

//export GoTable_FindColumnByName
//go:linkname GoTable_FindColumnByName github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_FindColumnByName
func GoTable_FindColumnByName(v unsafe.Pointer, name *C.char) unsafe.Pointer

//export GoTable_IsValueTable
//go:linkname GoTable_IsValueTable github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_IsValueTable
func GoTable_IsValueTable(v unsafe.Pointer) C.int

//export GoTable_SerializationID
//go:linkname GoTable_SerializationID github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_SerializationID
func GoTable_SerializationID(v unsafe.Pointer) C.int64_t

//export GoTable_CreateEvaluatorTableIterator
//go:linkname GoTable_CreateEvaluatorTableIterator github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_CreateEvaluatorTableIterator
func GoTable_CreateEvaluatorTableIterator(v unsafe.Pointer, columnIdxsPtr unsafe.Pointer, iter *unsafe.Pointer, ret **C.char)

//export GoTable_AnonymizationInfo
//go:linkname GoTable_AnonymizationInfo github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_AnonymizationInfo
func GoTable_AnonymizationInfo(v unsafe.Pointer) unsafe.Pointer

//export GoTable_SupportsAnonymization
//go:linkname GoTable_SupportsAnonymization github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_SupportsAnonymization
func GoTable_SupportsAnonymization(v unsafe.Pointer) C.int

//export GoTable_TableTypeName
//go:linkname GoTable_TableTypeName github.com/goccy/go-zetasql/internal/ccall/go-zetasql.GoTable_TableTypeName
func GoTable_TableTypeName(v unsafe.Pointer, mode C.int) *C.char

//export export_zetasql_public_catalog_cctz_FixedOffsetFromName
//go:linkname export_zetasql_public_catalog_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_zetasql_public_catalog_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_catalog_cctz_FixedOffsetToName
//go:linkname export_zetasql_public_catalog_cctz_FixedOffsetToName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_zetasql_public_catalog_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_cctz_FixedOffsetToAbbr
//go:linkname export_zetasql_public_catalog_cctz_FixedOffsetToAbbr github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_zetasql_public_catalog_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_cctz_detail_format
//go:linkname export_zetasql_public_catalog_cctz_detail_format github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_zetasql_public_catalog_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_zetasql_public_catalog_cctz_detail_parse
//go:linkname export_zetasql_public_catalog_cctz_detail_parse github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_zetasql_public_catalog_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_zetasql_public_catalog_TimeZoneIf_Load
//go:linkname export_zetasql_public_catalog_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_zetasql_public_catalog_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_time_zone_Impl_UTC
//go:linkname export_zetasql_public_catalog_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_zetasql_public_catalog_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_zetasql_public_catalog_time_zone_Impl_LoadTimeZone
//go:linkname export_zetasql_public_catalog_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_zetasql_public_catalog_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_zetasql_public_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_zetasql_public_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_zetasql_public_catalog_time_zone_Impl_UTCImpl
//go:linkname export_zetasql_public_catalog_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_zetasql_public_catalog_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneInfo_Load
//go:linkname export_zetasql_public_catalog_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_zetasql_public_catalog_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_catalog_TimeZoneInfo_BreakTime
//go:linkname export_zetasql_public_catalog_TimeZoneInfo_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_zetasql_public_catalog_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneInfo_MakeTime
//go:linkname export_zetasql_public_catalog_TimeZoneInfo_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_zetasql_public_catalog_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneInfo_Version
//go:linkname export_zetasql_public_catalog_TimeZoneInfo_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_zetasql_public_catalog_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneInfo_Description
//go:linkname export_zetasql_public_catalog_TimeZoneInfo_Description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_zetasql_public_catalog_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneInfo_NextTransition
//go:linkname export_zetasql_public_catalog_TimeZoneInfo_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_zetasql_public_catalog_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_catalog_TimeZoneInfo_PrevTransition
//go:linkname export_zetasql_public_catalog_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_zetasql_public_catalog_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_catalog_TimeZoneLibC_BreakTime
//go:linkname export_zetasql_public_catalog_TimeZoneLibC_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_zetasql_public_catalog_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneLibC_MakeTime
//go:linkname export_zetasql_public_catalog_TimeZoneLibC_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_zetasql_public_catalog_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneLibC_Version
//go:linkname export_zetasql_public_catalog_TimeZoneLibC_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_zetasql_public_catalog_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_TimeZoneLibC_NextTransition
//go:linkname export_zetasql_public_catalog_TimeZoneLibC_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_zetasql_public_catalog_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_catalog_TimeZoneLibC_PrevTransition
//go:linkname export_zetasql_public_catalog_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_zetasql_public_catalog_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_zetasql_public_catalog_time_zone_name
//go:linkname export_zetasql_public_catalog_time_zone_name github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_zetasql_public_catalog_time_zone_name(arg0 *unsafe.Pointer)

//export export_zetasql_public_catalog_time_zone_lookup
//go:linkname export_zetasql_public_catalog_time_zone_lookup github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_zetasql_public_catalog_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_catalog_time_zone_lookup2
//go:linkname export_zetasql_public_catalog_time_zone_lookup2 github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_zetasql_public_catalog_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_zetasql_public_catalog_time_zone_next_transition
//go:linkname export_zetasql_public_catalog_time_zone_next_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_zetasql_public_catalog_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_catalog_time_zone_prev_transition
//go:linkname export_zetasql_public_catalog_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_zetasql_public_catalog_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_catalog_time_zone_version
//go:linkname export_zetasql_public_catalog_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_zetasql_public_catalog_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_time_zone_description
//go:linkname export_zetasql_public_catalog_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_zetasql_public_catalog_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_cctz_load_time_zone
//go:linkname export_zetasql_public_catalog_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_zetasql_public_catalog_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_zetasql_public_catalog_cctz_utc_time_zone
//go:linkname export_zetasql_public_catalog_cctz_utc_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_zetasql_public_catalog_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_public_catalog_cctz_fixed_time_zone
//go:linkname export_zetasql_public_catalog_cctz_fixed_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_zetasql_public_catalog_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_zetasql_public_catalog_cctz_local_time_zone
//go:linkname export_zetasql_public_catalog_cctz_local_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_zetasql_public_catalog_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_zetasql_public_catalog_cctz_ParsePosixSpec
//go:linkname export_zetasql_public_catalog_cctz_ParsePosixSpec github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_zetasql_public_catalog_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)
