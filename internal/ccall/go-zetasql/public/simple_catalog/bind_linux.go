package simple_catalog

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
#cgo CXXFLAGS: -Wno-defaulted-function-deleted
#cgo CXXFLAGS: -Wno-unknown-warning-option
#cgo CXXFLAGS: -DHAVE_PTHREAD
#cgo CXXFLAGS: -DU_COMMON_IMPLEMENTATION
#cgo LDFLAGS: -ldl

#define GO_EXPORT(API) export_googlesql_public_simple_catalog_ ## API
#include "bridge.h"
#include "../../../go-absl/time/go_internal/cctz/time_zone/bridge.h"
#include "../../../go-zetasql/parser/parser/bridge.h"
#include "../../../go-zetasql/public/catalog/bridge.h"
*/
import "C"
import (
	_ "github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser"
	_ "github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/catalog"
	"unsafe"
)

func Type_Kind(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Type_Kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_Kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Type_Kind(arg0, arg1)
}

func Type_IsInt32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInt32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInt32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsInt32(arg0, arg1)
}

func Type_IsInt64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInt64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInt64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsInt64(arg0, arg1)
}

func Type_IsUint32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUint32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUint32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsUint32(arg0, arg1)
}

func Type_IsUint64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUint64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUint64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsUint64(arg0, arg1)
}

func Type_IsBool(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBool(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBool(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsBool(arg0, arg1)
}

func Type_IsFloat(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFloat(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFloat(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsFloat(arg0, arg1)
}

func Type_IsDouble(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDouble(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDouble(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsDouble(arg0, arg1)
}

func Type_IsString(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsString(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsString(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsString(arg0, arg1)
}

func Type_IsBytes(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBytes(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBytes(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsBytes(arg0, arg1)
}

func Type_IsDate(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsDate(arg0, arg1)
}

func Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsTimestamp(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsTimestamp(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsTimestamp(arg0, arg1)
}

func Type_IsTime(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsTime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsTime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsTime(arg0, arg1)
}

func Type_IsDatetime(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsDatetime(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsDatetime(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsDatetime(arg0, arg1)
}

func Type_IsInterval(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInterval(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInterval(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsInterval(arg0, arg1)
}

func Type_IsNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsNumericType(arg0, arg1)
}

func Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsBigNumericType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsBigNumericType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsBigNumericType(arg0, arg1)
}

func Type_IsJsonType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsJsonType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsJsonType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsJsonType(arg0, arg1)
}

func Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsFeatureV12CivilTimeType(arg0, arg1)
}

func Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_UsingFeatureV12CivilTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_UsingFeatureV12CivilTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_UsingFeatureV12CivilTimeType(arg0, arg1)
}

func Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsCivilDateOrTimeType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsCivilDateOrTimeType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsCivilDateOrTimeType(arg0, arg1)
}

func Type_IsGeography(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsGeography(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsGeography(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsGeography(arg0, arg1)
}

func Type_IsJson(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsJson(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsJson(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsJson(arg0, arg1)
}

func Type_IsEnum(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsEnum(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsEnum(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsEnum(arg0, arg1)
}

func Type_IsArray(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsArray(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsArray(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsArray(arg0, arg1)
}

func Type_IsStruct(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsStruct(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsStruct(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsStruct(arg0, arg1)
}

func Type_IsProto(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsProto(arg0, arg1)
}

func Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsStructOrProto(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsStructOrProto(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsStructOrProto(arg0, arg1)
}

func Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsFloatingPoint(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsFloatingPoint(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsFloatingPoint(arg0, arg1)
}

func Type_IsNumerical(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsNumerical(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsNumerical(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsNumerical(arg0, arg1)
}

func Type_IsInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsInteger(arg0, arg1)
}

func Type_IsInteger32(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger32(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger32(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsInteger32(arg0, arg1)
}

func Type_IsInteger64(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsInteger64(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsInteger64(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsInteger64(arg0, arg1)
}

func Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsSignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsSignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsSignedInteger(arg0, arg1)
}

func Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsUnsignedInteger(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsUnsignedInteger(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsUnsignedInteger(arg0, arg1)
}

func Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsSimpleType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsSimpleType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsSimpleType(arg0, arg1)
}

func Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_IsExtendedType(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_IsExtendedType(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_IsExtendedType(arg0, arg1)
}

func Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsArray(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsArray(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_AsArray(arg0, arg1)
}

func Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsStruct(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsStruct(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_AsStruct(arg0, arg1)
}

func Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsProto(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsProto(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_AsProto(arg0, arg1)
}

func Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsEnum(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsEnum(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_AsEnum(arg0, arg1)
}

func Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Type_AsExtendedType(
		arg0,
		arg1,
	)
}

func simple_catalog_Type_AsExtendedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_AsExtendedType(arg0, arg1)
}

func Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsGrouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsGrouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_SupportsGrouping(arg0, arg1)
}

func Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsPartitioning(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsPartitioning(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_SupportsPartitioning(arg0, arg1)
}

func Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_SupportsOrdering(arg0, arg1)
}

func Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_SupportsEquality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_SupportsEquality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_SupportsEquality(arg0, arg1)
}

func Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Type_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Type_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_Equals(arg0, arg1, arg2)
}

func Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Type_Equivalent(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Type_Equivalent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_Equivalent(arg0, arg1, arg2)
}

func Type_ShortTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Type_ShortTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Type_ShortTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_ShortTypeName(arg0, arg1, arg2)
}

func Type_TypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Type_TypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Type_TypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_TypeName(arg0, arg1, arg2)
}

func Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	simple_catalog_Type_TypeNameWithParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func simple_catalog_Type_TypeNameWithParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_TypeNameWithParameters(arg0, arg1, arg2, arg3, arg4)
}

func Type_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Type_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Type_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_DebugString(arg0, arg1, arg2)
}

func Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Type_HasAnyFields(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_HasAnyFields(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Type_HasAnyFields(arg0, arg1)
}

func Type_NestingDepth(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Type_NestingDepth(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Type_NestingDepth(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Type_NestingDepth(arg0, arg1)
}

func Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	simple_catalog_Type_ValidateAndResolveTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		C.int(arg3),
		arg4,
		arg5,
	)
}

func simple_catalog_Type_ValidateAndResolveTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 C.int, arg4 *unsafe.Pointer, arg5 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_ValidateAndResolveTypeParameters(arg0, arg1, arg2, arg3, arg4, arg5)
}

func Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_Type_ValidateResolvedTypeParameters(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_Type_ValidateResolvedTypeParameters(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Type_ValidateResolvedTypeParameters(arg0, arg1, arg2, arg3)
}

func ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_ArrayType_element_type(
		arg0,
		arg1,
	)
}

func simple_catalog_ArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_ArrayType_element_type(arg0, arg1)
}

func StructType_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_StructType_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_StructType_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_StructType_num_fields(arg0, arg1)
}

func StructType_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_StructType_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_StructType_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_StructType_field(arg0, arg1, arg2)
}

func StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_StructType_fields(
		arg0,
		arg1,
	)
}

func simple_catalog_StructType_fields(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_StructType_fields(arg0, arg1)
}

func StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_StructField_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_StructField_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_StructField_new(arg0, arg1, arg2)
}

func StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_StructField_name(
		arg0,
		arg1,
	)
}

func simple_catalog_StructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_StructField_name(arg0, arg1)
}

func StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_StructField_type(
		arg0,
		arg1,
	)
}

func simple_catalog_StructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_StructField_type(arg0, arg1)
}

func TypeFactory_new(arg0 *unsafe.Pointer) {
	simple_catalog_TypeFactory_new(
		arg0,
	)
}

func simple_catalog_TypeFactory_new(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TypeFactory_new(arg0)
}

func TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_TypeFactory_MakeArrayType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_TypeFactory_MakeArrayType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TypeFactory_MakeArrayType(arg0, arg1, arg2, arg3)
}

func TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_TypeFactory_MakeStructType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_TypeFactory_MakeStructType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TypeFactory_MakeStructType(arg0, arg1, arg2, arg3)
}

func Int32Type(arg0 *unsafe.Pointer) {
	simple_catalog_Int32Type(
		arg0,
	)
}

func simple_catalog_Int32Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Int32Type(arg0)
}

func Int64Type(arg0 *unsafe.Pointer) {
	simple_catalog_Int64Type(
		arg0,
	)
}

func simple_catalog_Int64Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Int64Type(arg0)
}

func Uint32Type(arg0 *unsafe.Pointer) {
	simple_catalog_Uint32Type(
		arg0,
	)
}

func simple_catalog_Uint32Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Uint32Type(arg0)
}

func Uint64Type(arg0 *unsafe.Pointer) {
	simple_catalog_Uint64Type(
		arg0,
	)
}

func simple_catalog_Uint64Type(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Uint64Type(arg0)
}

func BoolType(arg0 *unsafe.Pointer) {
	simple_catalog_BoolType(
		arg0,
	)
}

func simple_catalog_BoolType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_BoolType(arg0)
}

func FloatType(arg0 *unsafe.Pointer) {
	simple_catalog_FloatType(
		arg0,
	)
}

func simple_catalog_FloatType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FloatType(arg0)
}

func DoubleType(arg0 *unsafe.Pointer) {
	simple_catalog_DoubleType(
		arg0,
	)
}

func simple_catalog_DoubleType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_DoubleType(arg0)
}

func StringType(arg0 *unsafe.Pointer) {
	simple_catalog_StringType(
		arg0,
	)
}

func simple_catalog_StringType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_StringType(arg0)
}

func BytesType(arg0 *unsafe.Pointer) {
	simple_catalog_BytesType(
		arg0,
	)
}

func simple_catalog_BytesType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_BytesType(arg0)
}

func DateType(arg0 *unsafe.Pointer) {
	simple_catalog_DateType(
		arg0,
	)
}

func simple_catalog_DateType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_DateType(arg0)
}

func TimestampType(arg0 *unsafe.Pointer) {
	simple_catalog_TimestampType(
		arg0,
	)
}

func simple_catalog_TimestampType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TimestampType(arg0)
}

func TimeType(arg0 *unsafe.Pointer) {
	simple_catalog_TimeType(
		arg0,
	)
}

func simple_catalog_TimeType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TimeType(arg0)
}

func DatetimeType(arg0 *unsafe.Pointer) {
	simple_catalog_DatetimeType(
		arg0,
	)
}

func simple_catalog_DatetimeType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_DatetimeType(arg0)
}

func IntervalType(arg0 *unsafe.Pointer) {
	simple_catalog_IntervalType(
		arg0,
	)
}

func simple_catalog_IntervalType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_IntervalType(arg0)
}

func GeographyType(arg0 *unsafe.Pointer) {
	simple_catalog_GeographyType(
		arg0,
	)
}

func simple_catalog_GeographyType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_GeographyType(arg0)
}

func NumericType(arg0 *unsafe.Pointer) {
	simple_catalog_NumericType(
		arg0,
	)
}

func simple_catalog_NumericType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_NumericType(arg0)
}

func BigNumericType(arg0 *unsafe.Pointer) {
	simple_catalog_BigNumericType(
		arg0,
	)
}

func simple_catalog_BigNumericType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_BigNumericType(arg0)
}

func JsonType(arg0 *unsafe.Pointer) {
	simple_catalog_JsonType(
		arg0,
	)
}

func simple_catalog_JsonType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_JsonType(arg0)
}

func EmptyStructType(arg0 *unsafe.Pointer) {
	simple_catalog_EmptyStructType(
		arg0,
	)
}

func simple_catalog_EmptyStructType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_EmptyStructType(arg0)
}

func Int32ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Int32ArrayType(
		arg0,
	)
}

func simple_catalog_Int32ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Int32ArrayType(arg0)
}

func Int64ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Int64ArrayType(
		arg0,
	)
}

func simple_catalog_Int64ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Int64ArrayType(arg0)
}

func Uint32ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Uint32ArrayType(
		arg0,
	)
}

func simple_catalog_Uint32ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Uint32ArrayType(arg0)
}

func Uint64ArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_Uint64ArrayType(
		arg0,
	)
}

func simple_catalog_Uint64ArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Uint64ArrayType(arg0)
}

func BoolArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_BoolArrayType(
		arg0,
	)
}

func simple_catalog_BoolArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_BoolArrayType(arg0)
}

func FloatArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_FloatArrayType(
		arg0,
	)
}

func simple_catalog_FloatArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FloatArrayType(arg0)
}

func DoubleArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_DoubleArrayType(
		arg0,
	)
}

func simple_catalog_DoubleArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_DoubleArrayType(arg0)
}

func StringArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_StringArrayType(
		arg0,
	)
}

func simple_catalog_StringArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_StringArrayType(arg0)
}

func BytesArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_BytesArrayType(
		arg0,
	)
}

func simple_catalog_BytesArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_BytesArrayType(arg0)
}

func TimestampArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_TimestampArrayType(
		arg0,
	)
}

func simple_catalog_TimestampArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TimestampArrayType(arg0)
}

func DateArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_DateArrayType(
		arg0,
	)
}

func simple_catalog_DateArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_DateArrayType(arg0)
}

func DatetimeArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_DatetimeArrayType(
		arg0,
	)
}

func simple_catalog_DatetimeArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_DatetimeArrayType(arg0)
}

func TimeArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_TimeArrayType(
		arg0,
	)
}

func simple_catalog_TimeArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TimeArrayType(arg0)
}

func IntervalArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_IntervalArrayType(
		arg0,
	)
}

func simple_catalog_IntervalArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_IntervalArrayType(arg0)
}

func GeographyArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_GeographyArrayType(
		arg0,
	)
}

func simple_catalog_GeographyArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_GeographyArrayType(arg0)
}

func NumericArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_NumericArrayType(
		arg0,
	)
}

func simple_catalog_NumericArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_NumericArrayType(arg0)
}

func BigNumericArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_BigNumericArrayType(
		arg0,
	)
}

func simple_catalog_BigNumericArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_BigNumericArrayType(arg0)
}

func JsonArrayType(arg0 *unsafe.Pointer) {
	simple_catalog_JsonArrayType(
		arg0,
	)
}

func simple_catalog_JsonArrayType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_JsonArrayType(arg0)
}

func DatePartEnumType(arg0 *unsafe.Pointer) {
	simple_catalog_DatePartEnumType(
		arg0,
	)
}

func simple_catalog_DatePartEnumType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_DatePartEnumType(arg0)
}

func NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	simple_catalog_NormalizeModeEnumType(
		arg0,
	)
}

func simple_catalog_NormalizeModeEnumType(arg0 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_NormalizeModeEnumType(arg0)
}

func TypeFromSimpleTypeKind(arg0 int, arg1 *unsafe.Pointer) {
	simple_catalog_TypeFromSimpleTypeKind(
		C.int(arg0),
		arg1,
	)
}

func simple_catalog_TypeFromSimpleTypeKind(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TypeFromSimpleTypeKind(arg0, arg1)
}

func Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_type(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_type(arg0, arg1)
}

func Value_type_kind(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Value_type_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_type_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Value_type_kind(arg0, arg1)
}

func Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_physical_byte_size(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_physical_byte_size(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_public_simple_catalog_Value_physical_byte_size(arg0, arg1)
}

func Value_is_null(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_is_null(arg0, arg1)
}

func Value_is_empty_array(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_empty_array(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_empty_array(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_is_empty_array(arg0, arg1)
}

func Value_is_valid(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_valid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_valid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_is_valid(arg0, arg1)
}

func Value_has_content(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_has_content(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_has_content(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_has_content(arg0, arg1)
}

func Value_int32_value(arg0 unsafe.Pointer, arg1 *int32) {
	simple_catalog_Value_int32_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_int32_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_googlesql_public_simple_catalog_Value_int32_value(arg0, arg1)
}

func Value_int64_value(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_int64_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_int64_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_Value_int64_value(arg0, arg1)
}

func Value_uint32_value(arg0 unsafe.Pointer, arg1 *uint32) {
	simple_catalog_Value_uint32_value(
		arg0,
		(*C.uint32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_uint32_value(arg0 unsafe.Pointer, arg1 *C.uint32_t) {
	C.export_googlesql_public_simple_catalog_Value_uint32_value(arg0, arg1)
}

func Value_uint64_value(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_uint64_value(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_uint64_value(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_public_simple_catalog_Value_uint64_value(arg0, arg1)
}

func Value_bool_value(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_bool_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_bool_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_bool_value(arg0, arg1)
}

func Value_float_value(arg0 unsafe.Pointer, arg1 *float32) {
	simple_catalog_Value_float_value(
		arg0,
		(*C.float)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_float_value(arg0 unsafe.Pointer, arg1 *C.float) {
	C.export_googlesql_public_simple_catalog_Value_float_value(arg0, arg1)
}

func Value_double_value(arg0 unsafe.Pointer, arg1 *float64) {
	simple_catalog_Value_double_value(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_double_value(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_googlesql_public_simple_catalog_Value_double_value(arg0, arg1)
}

func Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_string_value(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_string_value(arg0, arg1)
}

func Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_bytes_value(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_bytes_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_bytes_value(arg0, arg1)
}

func Value_date_value(arg0 unsafe.Pointer, arg1 *int32) {
	simple_catalog_Value_date_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_date_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_googlesql_public_simple_catalog_Value_date_value(arg0, arg1)
}

func Value_enum_value(arg0 unsafe.Pointer, arg1 *int32) {
	simple_catalog_Value_enum_value(
		arg0,
		(*C.int32_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_enum_value(arg0 unsafe.Pointer, arg1 *C.int32_t) {
	C.export_googlesql_public_simple_catalog_Value_enum_value(arg0, arg1)
}

func Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_enum_name(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_enum_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_enum_name(arg0, arg1)
}

func Value_ToTime(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToTime(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToTime(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_Value_ToTime(arg0, arg1)
}

func Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToUnixMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToUnixMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_Value_ToUnixMicros(arg0, arg1)
}

func Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *int64, arg2 *unsafe.Pointer) {
	simple_catalog_Value_ToUnixNanos(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
		arg2,
	)
}

func simple_catalog_Value_ToUnixNanos(arg0 unsafe.Pointer, arg1 *C.int64_t, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_ToUnixNanos(arg0, arg1, arg2)
}

func Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToPacked64TimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToPacked64TimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_Value_ToPacked64TimeMicros(arg0, arg1)
}

func Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToPacked64DatetimeMicros(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToPacked64DatetimeMicros(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_Value_ToPacked64DatetimeMicros(arg0, arg1)
}

func Value_is_validated_json(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_validated_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_validated_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_is_validated_json(arg0, arg1)
}

func Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_is_unparsed_json(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_is_unparsed_json(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_is_unparsed_json(arg0, arg1)
}

func Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_json_value_unparsed(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_json_value_unparsed(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_json_value_unparsed(arg0, arg1)
}

func Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_json_string(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_json_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_json_string(arg0, arg1)
}

func Value_ToInt64(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_Value_ToInt64(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToInt64(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_Value_ToInt64(arg0, arg1)
}

func Value_ToUint64(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_ToUint64(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToUint64(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_public_simple_catalog_Value_ToUint64(arg0, arg1)
}

func Value_ToDouble(arg0 unsafe.Pointer, arg1 *float64) {
	simple_catalog_Value_ToDouble(
		arg0,
		(*C.double)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_ToDouble(arg0 unsafe.Pointer, arg1 *C.double) {
	C.export_googlesql_public_simple_catalog_Value_ToDouble(arg0, arg1)
}

func Value_num_fields(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Value_num_fields(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_num_fields(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Value_num_fields(arg0, arg1)
}

func Value_field(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_field(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_field(arg0, arg1, arg2)
}

func Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Value_FindFieldByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Value_FindFieldByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_FindFieldByName(arg0, arg1, arg2)
}

func Value_empty(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Value_empty(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_empty(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_empty(arg0, arg1)
}

func Value_num_elements(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Value_num_elements(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_num_elements(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Value_num_elements(arg0, arg1)
}

func Value_element(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_element(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_element(arg0, arg1, arg2)
}

func Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Value_Equals(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Value_Equals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_Equals(arg0, arg1, arg2)
}

func Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Value_SqlEquals(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Value_SqlEquals(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_SqlEquals(arg0, arg1, arg2)
}

func Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_Value_LessThan(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Value_LessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_public_simple_catalog_Value_LessThan(arg0, arg1, arg2)
}

func Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Value_SqlLessThan(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Value_SqlLessThan(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_SqlLessThan(arg0, arg1, arg2)
}

func Value_HashCode(arg0 unsafe.Pointer, arg1 *uint64) {
	simple_catalog_Value_HashCode(
		arg0,
		(*C.uint64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Value_HashCode(arg0 unsafe.Pointer, arg1 *C.uint64_t) {
	C.export_googlesql_public_simple_catalog_Value_HashCode(arg0, arg1)
}

func Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_ShortDebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_ShortDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_ShortDebugString(arg0, arg1)
}

func Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_FullDebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_FullDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_FullDebugString(arg0, arg1)
}

func Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_DebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_DebugString(arg0, arg1)
}

func Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Value_Format(
		arg0,
		arg1,
	)
}

func simple_catalog_Value_Format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_Format(arg0, arg1)
}

func Value_GetSQL(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_GetSQL(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_GetSQL(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_GetSQL(arg0, arg1, arg2)
}

func Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Value_GetSQLLiteral(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Value_GetSQLLiteral(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Value_GetSQLLiteral(arg0, arg1, arg2)
}

func Int64(arg0 int64, arg1 *unsafe.Pointer) {
	simple_catalog_Int64(
		C.int64_t(arg0),
		arg1,
	)
}

func simple_catalog_Int64(arg0 C.int64_t, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Int64(arg0, arg1)
}

func Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Column_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Column_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Column_Name(arg0, arg1)
}

func Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Column_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Column_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Column_FullName(arg0, arg1)
}

func Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Column_Type(
		arg0,
		arg1,
	)
}

func simple_catalog_Column_Type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Column_Type(arg0, arg1)
}

func Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Column_IsPseudoColumn(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Column_IsPseudoColumn(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Column_IsPseudoColumn(arg0, arg1)
}

func Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Column_IsWritableColumn(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Column_IsWritableColumn(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Column_IsWritableColumn(arg0, arg1)
}

func SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleColumn_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleColumn_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleColumn_new(arg0, arg1, arg2, arg3)
}

func SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 int, arg4 int, arg5 *unsafe.Pointer) {
	simple_catalog_SimpleColumn_new_with_opt(
		arg0,
		arg1,
		arg2,
		C.int(arg3),
		C.int(arg4),
		arg5,
	)
}

func simple_catalog_SimpleColumn_new_with_opt(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 C.int, arg4 C.int, arg5 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleColumn_new_with_opt(arg0, arg1, arg2, arg3, arg4, arg5)
}

func SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleColumn_AnnotatedType(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleColumn_AnnotatedType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleColumn_AnnotatedType(arg0, arg1)
}

func SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_SimpleColumn_SetIsPseudoColumn(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_SimpleColumn_SetIsPseudoColumn(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_SimpleColumn_SetIsPseudoColumn(arg0, arg1)
}

func Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Table_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Table_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Table_Name(arg0, arg1)
}

func Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Table_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Table_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Table_FullName(arg0, arg1)
}

func Table_NumColumns(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Table_NumColumns(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_NumColumns(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Table_NumColumns(arg0, arg1)
}

func Table_Column(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Table_Column(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Table_Column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Table_Column(arg0, arg1, arg2)
}

func Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Table_PrimaryKey_num(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_PrimaryKey_num(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Table_PrimaryKey_num(arg0, arg1)
}

func Table_PrimaryKey(arg0 unsafe.Pointer, arg1 int, arg2 *int) {
	simple_catalog_Table_PrimaryKey(
		arg0,
		C.int(arg1),
		(*C.int)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_Table_PrimaryKey(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.int) {
	C.export_googlesql_public_simple_catalog_Table_PrimaryKey(arg0, arg1, arg2)
}

func Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Table_FindColumnByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Table_FindColumnByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Table_FindColumnByName(arg0, arg1, arg2)
}

func Table_IsValueTable(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Table_IsValueTable(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_IsValueTable(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Table_IsValueTable(arg0, arg1)
}

func Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Table_GetSerializationId(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_GetSerializationId(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Table_GetSerializationId(arg0, arg1)
}

func Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	simple_catalog_Table_CreateEvaluatorTableIterator(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func simple_catalog_Table_CreateEvaluatorTableIterator(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Table_CreateEvaluatorTableIterator(arg0, arg1, arg2, arg3, arg4)
}

func Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Table_GetAnonymizationInfo(
		arg0,
		arg1,
	)
}

func simple_catalog_Table_GetAnonymizationInfo(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Table_GetAnonymizationInfo(arg0, arg1)
}

func Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Table_SupportsAnonymization(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Table_SupportsAnonymization(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Table_SupportsAnonymization(arg0, arg1)
}

func Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Table_GetTableTypeName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Table_GetTableTypeName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Table_GetTableTypeName(arg0, arg1, arg2)
}

func SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleTable_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_SimpleTable_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_new(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_SimpleTable_set_is_value_table(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_SimpleTable_set_is_value_table(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_SimpleTable_set_is_value_table(arg0, arg1)
}

func SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_SimpleTable_AllowAnonymousColumnName(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleTable_AllowAnonymousColumnName(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_SimpleTable_AllowAnonymousColumnName(arg0, arg1)
}

func SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_set_allow_anonymous_column_name(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_SimpleTable_set_allow_anonymous_column_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_set_allow_anonymous_column_name(arg0, arg1, arg2)
}

func SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_SimpleTable_AllowDuplicateColumnNames(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_SimpleTable_AllowDuplicateColumnNames(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_SimpleTable_AllowDuplicateColumnNames(arg0, arg1)
}

func SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_set_allow_duplicate_column_names(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_SimpleTable_set_allow_duplicate_column_names(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_set_allow_duplicate_column_names(arg0, arg1, arg2)
}

func SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_AddColumn(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleTable_AddColumn(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_AddColumn(arg0, arg1, arg2)
}

func SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleTable_SetPrimaryKey(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_SimpleTable_SetPrimaryKey(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_SetPrimaryKey(arg0, arg1, arg2, arg3)
}

func SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_set_full_name(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleTable_set_full_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_set_full_name(arg0, arg1, arg2)
}

func SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleTable_SetAnonymizationInfo(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleTable_SetAnonymizationInfo(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_SetAnonymizationInfo(arg0, arg1, arg2)
}

func SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	simple_catalog_SimpleTable_ResetAnonymizationInfo(
		arg0,
	)
}

func simple_catalog_SimpleTable_ResetAnonymizationInfo(arg0 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleTable_ResetAnonymizationInfo(arg0)
}

func Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Catalog_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Catalog_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FullName(arg0, arg1)
}

func Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FindTable(arg0, arg1, arg2, arg3)
}

func Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FindModel(arg0, arg1, arg2, arg3)
}

func Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FindFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FindTableValuedFunction(arg0, arg1, arg2, arg3)
}

func Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FindProcedure(arg0, arg1, arg2, arg3)
}

func Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Catalog_FindType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Catalog_FindType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FindType(arg0, arg1, arg2, arg3)
}

func Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *int, arg4 *unsafe.Pointer) {
	simple_catalog_Catalog_FindConstant(
		arg0,
		arg1,
		arg2,
		(*C.int)(unsafe.Pointer(arg3)),
		arg4,
	)
}

func simple_catalog_Catalog_FindConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.int, arg4 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_FindConstant(arg0, arg1, arg2, arg3, arg4)
}

func Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestTable(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_SuggestTable(arg0, arg1, arg2)
}

func Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestModel(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_SuggestModel(arg0, arg1, arg2)
}

func Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestFunction(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_SuggestFunction(arg0, arg1, arg2)
}

func Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestTableValuedTable(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestTableValuedTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_SuggestTableValuedTable(arg0, arg1, arg2)
}

func Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Catalog_SuggestConstant(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Catalog_SuggestConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Catalog_SuggestConstant(arg0, arg1, arg2)
}

func EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Catalogs(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Catalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_EnumerableCatalog_Catalogs(arg0, arg1, arg2)
}

func EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Tables(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Tables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_EnumerableCatalog_Tables(arg0, arg1, arg2)
}

func EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Types(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_EnumerableCatalog_Types(arg0, arg1, arg2)
}

func EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_EnumerableCatalog_Functions(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_EnumerableCatalog_Functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_EnumerableCatalog_Functions(arg0, arg1, arg2)
}

func SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_new(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_new(arg0, arg1)
}

func SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTable(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetTable(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTables(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetTables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetTables(arg0, arg1, arg2)
}

func SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_table_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_table_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_table_names(arg0, arg1)
}

func SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetModel(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetModel(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetFunctions(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetFunctions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetFunctions(arg0, arg1, arg2)
}

func SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_function_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_function_names(arg0, arg1)
}

func SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTableValuedFunction(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetTableValuedFunction(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_table_valued_functions(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_table_valued_functions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_table_valued_functions(arg0, arg1)
}

func SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_table_valued_function_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_table_valued_function_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_table_valued_function_names(arg0, arg1)
}

func SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetProcedure(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetProcedure(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_procedures(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_procedures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_procedures(arg0, arg1)
}

func SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetType(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetType(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetTypes(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetTypes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetTypes(arg0, arg1, arg2)
}

func SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetCatalog(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleCatalog_GetCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetCatalog(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_GetCatalogs(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_GetCatalogs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_GetCatalogs(arg0, arg1, arg2)
}

func SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_SimpleCatalog_catalog_names(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_catalog_names(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_catalog_names(arg0, arg1)
}

func SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTable(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddTable(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddTable(arg0, arg1)
}

func SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTableWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddTableWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddTableWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddModel(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddModel(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddModel(arg0, arg1)
}

func SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddModelWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddModelWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddModelWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConnection(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddConnection(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddConnection(arg0, arg1)
}

func SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConnectionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddConnectionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddConnectionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddType(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddType(arg0, arg1, arg2)
}

func SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *bool) {
	simple_catalog_SimpleCatalog_AddTypeIfNotPresent(
		arg0,
		arg1,
		arg2,
		(*C.char)(unsafe.Pointer(arg3)),
	)
}

func simple_catalog_SimpleCatalog_AddTypeIfNotPresent(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddTypeIfNotPresent(arg0, arg1, arg2, arg3)
}

func SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddCatalog(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddCatalog(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddCatalog(arg0, arg1)
}

func SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddCatalogWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddCatalogWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddCatalogWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddFunction(arg0, arg1)
}

func SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTableValuedFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddTableValuedFunction(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddTableValuedFunction(arg0, arg1)
}

func SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddTableValuedFunctionWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddTableValuedFunctionWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddTableValuedFunctionWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddProcedure(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddProcedure(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddProcedure(arg0, arg1)
}

func SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddProcedureWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddProcedureWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddProcedureWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConstant(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddConstant(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddConstant(arg0, arg1)
}

func SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddConstantWithName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleCatalog_AddConstantWithName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddConstantWithName(arg0, arg1, arg2)
}

func SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_SimpleCatalog_AddZetaSQLFunctions(
		arg0,
		arg1,
	)
}

func simple_catalog_SimpleCatalog_AddZetaSQLFunctions(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleCatalog_AddZetaSQLFunctions(arg0, arg1)
}

func Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Constant_Name(arg0, arg1)
}

func Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Constant_FullName(arg0, arg1)
}

func Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_type(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Constant_type(arg0, arg1)
}

func Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_DebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Constant_DebugString(arg0, arg1)
}

func Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Constant_name_path(
		arg0,
		arg1,
	)
}

func simple_catalog_Constant_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Constant_name_path(arg0, arg1)
}

func Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Model_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Model_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Model_Name(arg0, arg1)
}

func Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Model_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Model_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Model_FullName(arg0, arg1)
}

func Model_NumInputs(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Model_NumInputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Model_NumInputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Model_NumInputs(arg0, arg1)
}

func Model_Input(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Model_Input(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Model_Input(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Model_Input(arg0, arg1, arg2)
}

func Model_NumOutputs(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Model_NumOutputs(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Model_NumOutputs(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Model_NumOutputs(arg0, arg1)
}

func Model_Output(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Model_Output(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Model_Output(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Model_Output(arg0, arg1, arg2)
}

func Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Model_FindInputByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Model_FindInputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Model_FindInputByName(arg0, arg1, arg2)
}

func Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Model_FindOutputByName(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Model_FindOutputByName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Model_FindOutputByName(arg0, arg1, arg2)
}

func Model_SerializationID(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Model_SerializationID(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Model_SerializationID(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Model_SerializationID(arg0, arg1)
}

func SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_SimpleModel_new(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_SimpleModel_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleModel_new(arg0, arg1, arg2, arg3)
}

func SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleModel_AddInput(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleModel_AddInput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleModel_AddInput(arg0, arg1, arg2)
}

func SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SimpleModel_AddOutput(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SimpleModel_AddOutput(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SimpleModel_AddOutput(arg0, arg1, arg2)
}

func BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_BuiltinFunctionOptions_new(
		arg0,
		arg1,
	)
}

func simple_catalog_BuiltinFunctionOptions_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_BuiltinFunctionOptions_new(arg0, arg1)
}

func Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	simple_catalog_Function_new(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
		arg4,
	)
}

func simple_catalog_Function_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 unsafe.Pointer, arg4 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_new(arg0, arg1, arg2, arg3, arg4)
}

func Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_Name(arg0, arg1)
}

func Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_FunctionNamePath(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_FunctionNamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_FunctionNamePath(arg0, arg1)
}

func Function_FullName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Function_FullName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Function_FullName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_FullName(arg0, arg1, arg2)
}

func Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_SQLName(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_SQLName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_SQLName(arg0, arg1)
}

func Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Function_QualifiedSQLName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Function_QualifiedSQLName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_QualifiedSQLName(arg0, arg1, arg2)
}

func Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_Group(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_Group(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_Group(arg0, arg1)
}

func Function_IsZetaSQLBuiltin(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsZetaSQLBuiltin(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsZetaSQLBuiltin(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_IsZetaSQLBuiltin(arg0, arg1)
}

func Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_ArgumentsAreCoercible(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_ArgumentsAreCoercible(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_ArgumentsAreCoercible(arg0, arg1)
}

func Function_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Function_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Function_NumSignatures(arg0, arg1)
}

func Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_signatures(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_signatures(arg0, arg1)
}

func Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_Function_ResetSignatures(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_ResetSignatures(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_ResetSignatures(arg0, arg1)
}

func Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_Function_AddSignature(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_AddSignature(arg0, arg1)
}

func Function_mode(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_Function_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_Function_mode(arg0, arg1)
}

func Function_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_IsScalar(arg0, arg1)
}

func Function_IsAggregate(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsAggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsAggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_IsAggregate(arg0, arg1)
}

func Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsAnalytic(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsAnalytic(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_IsAnalytic(arg0, arg1)
}

func Function_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Function_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Function_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_DebugString(arg0, arg1, arg2)
}

func Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	simple_catalog_Function_GetSQL(
		arg0,
		arg1,
		arg2,
		arg3,
	)
}

func simple_catalog_Function_GetSQL(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_GetSQL(arg0, arg1, arg2, arg3)
}

func Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsOverClause(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsOverClause(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsOverClause(arg0, arg1)
}

func Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsWindowOrdering(arg0, arg1)
}

func Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_RequiresWindowOrdering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_RequiresWindowOrdering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_RequiresWindowOrdering(arg0, arg1)
}

func Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsWindowFraming(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsWindowFraming(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsWindowFraming(arg0, arg1)
}

func Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsOrderingArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsOrderingArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsOrderingArguments(arg0, arg1)
}

func Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsLimitArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsLimitArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsLimitArguments(arg0, arg1)
}

func Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsNullHandlingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsNullHandlingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsNullHandlingModifier(arg0, arg1)
}

func Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsSafeErrorMode(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsSafeErrorMode(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsSafeErrorMode(arg0, arg1)
}

func Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsHavingModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsHavingModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsHavingModifier(arg0, arg1)
}

func Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsDistinctModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsDistinctModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsDistinctModifier(arg0, arg1)
}

func Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_SupportsClampedBetweenModifier(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_SupportsClampedBetweenModifier(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_SupportsClampedBetweenModifier(arg0, arg1)
}

func Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_Function_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_Function_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_Function_IsDeprecated(arg0, arg1)
}

func Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Function_alias_name(
		arg0,
		arg1,
	)
}

func simple_catalog_Function_alias_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Function_alias_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_new(arg0 int, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_new(
		C.int(arg0),
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_new(arg0 C.int, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_new(arg0, arg1)
}

func FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_be_non_null(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_be_non_null(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_is_not_aggregate(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_is_not_aggregate(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_support_equality(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_support_equality(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_support_ordering(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_support_ordering(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_must_support_grouping(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_must_support_grouping(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_min_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_min_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_has_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_max_value(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_max_value(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_has_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_FunctionArgumentTypeOptions_min_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_min_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *int64) {
	simple_catalog_FunctionArgumentTypeOptions_max_value(
		arg0,
		(*C.int64_t)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_max_value(arg0 unsafe.Pointer, arg1 *C.int64_t) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_relation_input_schema(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_relation_input_schema(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_has_relation_input_schema(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_get_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_has_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_argument_name(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_argument_name_is_mandatory(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_procedure_argument_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_procedure_argument_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_cardinality(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_cardinality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_cardinality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_be_constant(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_be_constant(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_be_constant(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_be_non_null(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_be_non_null(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_be_non_null(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_is_not_aggregate(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_is_not_aggregate(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_support_equality(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_support_equality(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_support_equality(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_support_ordering(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_support_ordering(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_support_ordering(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_must_support_grouping(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_must_support_grouping(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_must_support_grouping(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 int64) {
	simple_catalog_FunctionArgumentTypeOptions_set_min_value(
		arg0,
		C.int64_t(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_min_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_min_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 int64) {
	simple_catalog_FunctionArgumentTypeOptions_set_max_value(
		arg0,
		C.int64_t(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_max_value(arg0 unsafe.Pointer, arg1 C.int64_t) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_max_value(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_extra_relation_input_columns_allowed(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_name(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_name(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_name(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_name_is_mandatory(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_procedure_argument_mode(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_procedure_argument_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_resolve_descriptor_names_table_offset(arg0, arg1)
}

func FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_OptionsDebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_OptionsDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_OptionsDebugString(arg0, arg1)
}

func FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_GetSQLDeclaration(arg0, arg1, arg2)
}

func FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_argument_name_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_name_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_argument_name_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_argument_type_parse_location(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_type_parse_location(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_argument_type_parse_location(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_set_default(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_default(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_has_default(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_has_default(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_has_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_get_default(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_get_default(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_get_default(arg0, arg1)
}

func FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	simple_catalog_FunctionArgumentTypeOptions_clear_default(
		arg0,
	)
}

func simple_catalog_FunctionArgumentTypeOptions_clear_default(arg0 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_clear_default(arg0)
}

func FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentTypeOptions_argument_collation_mode(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_argument_collation_mode(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentTypeOptions_uses_array_element_for_collation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_uses_array_element_for_collation(arg0, arg1)
}

func FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentTypeOptions_set_argument_collation_mode(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentTypeOptions_set_argument_collation_mode(arg0, arg1)
}

func FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_new(arg0, arg1, arg2)
}

func FunctionArgumentType_new_templated_type(arg0 int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_new_templated_type(
		C.int(arg0),
		arg1,
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_new_templated_type(arg0 C.int, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_new_templated_type(arg0, arg1, arg2)
}

func FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_options(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_options(arg0, arg1)
}

func FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_required(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_required(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_required(arg0, arg1)
}

func FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_repeated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_repeated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_repeated(arg0, arg1)
}

func FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_optional(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_optional(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_optional(arg0, arg1)
}

func FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentType_cardinality(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_cardinality(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_cardinality(arg0, arg1)
}

func FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_must_be_constant(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_must_be_constant(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_must_be_constant(arg0, arg1)
}

func FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_has_argument_name(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_has_argument_name(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_has_argument_name(arg0, arg1)
}

func FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_argument_name(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_argument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_argument_name(arg0, arg1)
}

func FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentType_num_occurrences(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_num_occurrences(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionArgumentType_set_num_occurrences(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionArgumentType_set_num_occurrences(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_set_num_occurrences(arg0, arg1)
}

func FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_IncrementNumOccurrences(
		arg0,
	)
}

func simple_catalog_FunctionArgumentType_IncrementNumOccurrences(arg0 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IncrementNumOccurrences(arg0)
}

func FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_type(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_type(arg0, arg1)
}

func FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionArgumentType_kind(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_kind(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_kind(arg0, arg1)
}

func FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_labmda(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_labmda(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_labmda(arg0, arg1)
}

func FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsConcrete(arg0, arg1)
}

func FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsTemplated(arg0, arg1)
}

func FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsScalar(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsScalar(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsScalar(arg0, arg1)
}

func FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsRelation(arg0, arg1)
}

func FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsModel(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsModel(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsModel(arg0, arg1)
}

func FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsConnection(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsConnection(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsConnection(arg0, arg1)
}

func FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsLambda(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsLambda(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsLambda(arg0, arg1)
}

func FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsFixedRelation(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsFixedRelation(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsFixedRelation(arg0, arg1)
}

func FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsVoid(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsVoid(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsVoid(arg0, arg1)
}

func FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_IsDescriptor(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_IsDescriptor(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsDescriptor(arg0, arg1)
}

func FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 int, arg2 *bool) {
	simple_catalog_FunctionArgumentType_TemplatedKindIsRelated(
		arg0,
		C.int(arg1),
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_FunctionArgumentType_TemplatedKindIsRelated(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_TemplatedKindIsRelated(arg0, arg1, arg2)
}

func FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *bool) {
	simple_catalog_FunctionArgumentType_AllowCoercionFrom(
		arg0,
		arg1,
		(*C.char)(unsafe.Pointer(arg2)),
	)
}

func simple_catalog_FunctionArgumentType_AllowCoercionFrom(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_AllowCoercionFrom(arg0, arg1, arg2)
}

func FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionArgumentType_HasDefault(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionArgumentType_HasDefault(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_HasDefault(arg0, arg1)
}

func FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_GetDefault(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionArgumentType_GetDefault(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_GetDefault(arg0, arg1)
}

func FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_UserFacingName(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_UserFacingName(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_UserFacingName(arg0, arg1, arg2)
}

func FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_UserFacingNameWithCardinality(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_UserFacingNameWithCardinality(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_UserFacingNameWithCardinality(arg0, arg1, arg2)
}

func FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_IsValid(arg0, arg1, arg2)
}

func FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_DebugString(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_DebugString(arg0, arg1, arg2)
}

func FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionArgumentType_GetSQLDeclaration(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionArgumentType_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionArgumentType_GetSQLDeclaration(arg0, arg1, arg2)
}

func ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_ArgumentTypeLambda_argument_types(
		arg0,
		arg1,
	)
}

func simple_catalog_ArgumentTypeLambda_argument_types(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_ArgumentTypeLambda_argument_types(arg0, arg1)
}

func ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_ArgumentTypeLambda_body_type(
		arg0,
		arg1,
	)
}

func simple_catalog_ArgumentTypeLambda_body_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_ArgumentTypeLambda_body_type(arg0, arg1)
}

func FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_FunctionSignature_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_new(arg0, arg1, arg2)
}

func FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_arguments(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_arguments(arg0, arg1)
}

func FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_concret_arguments(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_concret_arguments(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_concret_arguments(arg0, arg1)
}

func FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_result_type(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_result_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_result_type(arg0, arg1)
}

func FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsConcrete(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsConcrete(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsConcrete(arg0, arg1)
}

func FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_HasConcreteArguments(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_HasConcreteArguments(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_HasConcreteArguments(arg0, arg1)
}

func FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValid(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_FunctionSignature_IsValid(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsValid(arg0, arg1, arg2)
}

func FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValidForFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_IsValidForFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsValidForFunction(arg0, arg1)
}

func FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValidForTableValuedFunction(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_IsValidForTableValuedFunction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsValidForTableValuedFunction(arg0, arg1)
}

func FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_IsValidForProcedure(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_IsValidForProcedure(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsValidForProcedure(arg0, arg1)
}

func FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_FirstRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_FirstRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_FirstRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_LastRepeatedArgumentIndex(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_LastRepeatedArgumentIndex(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_LastRepeatedArgumentIndex(arg0, arg1)
}

func FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_NumRequiredArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_NumRequiredArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_NumRequiredArguments(arg0, arg1)
}

func FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_NumRepeatedArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_NumRepeatedArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_NumRepeatedArguments(arg0, arg1)
}

func FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_FunctionSignature_NumOptionalArguments(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_NumOptionalArguments(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_NumOptionalArguments(arg0, arg1)
}

func FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_DebugString(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_FunctionSignature_DebugString(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_DebugString(arg0, arg1, arg2, arg3)
}

func FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 int, arg3 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_GetSQLDeclaration(
		arg0,
		arg1,
		C.int(arg2),
		arg3,
	)
}

func simple_catalog_FunctionSignature_GetSQLDeclaration(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_GetSQLDeclaration(arg0, arg1, arg2, arg3)
}

func FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsDeprecated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsDeprecated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsDeprecated(arg0, arg1)
}

func FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 int) {
	simple_catalog_FunctionSignature_SetIsDeprecated(
		arg0,
		C.int(arg1),
	)
}

func simple_catalog_FunctionSignature_SetIsDeprecated(arg0 unsafe.Pointer, arg1 C.int) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_SetIsDeprecated(arg0, arg1)
}

func FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsInternal(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsInternal(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsInternal(arg0, arg1)
}

func FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_FunctionSignature_options(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_options(arg0, arg1)
}

func FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	simple_catalog_FunctionSignature_SetConcreteResultType(
		arg0,
		arg1,
	)
}

func simple_catalog_FunctionSignature_SetConcreteResultType(arg0 unsafe.Pointer, arg1 unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_SetConcreteResultType(arg0, arg1)
}

func FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_IsTemplated(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_IsTemplated(arg0, arg1)
}

func FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *bool) {
	simple_catalog_FunctionSignature_AllArgumentsHaveDefaults(
		arg0,
		(*C.char)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_FunctionSignature_AllArgumentsHaveDefaults(arg0 unsafe.Pointer, arg1 *C.char) {
	C.export_googlesql_public_simple_catalog_FunctionSignature_AllArgumentsHaveDefaults(arg0, arg1)
}

func Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_Procedure_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_Procedure_new(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Procedure_new(arg0, arg1, arg2)
}

func Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Procedure_Name(arg0, arg1)
}

func Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Procedure_FullName(arg0, arg1)
}

func Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_NamePath(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_NamePath(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Procedure_NamePath(arg0, arg1)
}

func Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_Procedure_Signature(
		arg0,
		arg1,
	)
}

func simple_catalog_Procedure_Signature(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Procedure_Signature(arg0, arg1)
}

func Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_Procedure_SupportedSignatureUserFacingText(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_Procedure_SupportedSignatureUserFacingText(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_Procedure_SupportedSignatureUserFacingText(arg0, arg1, arg2)
}

func SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_SQLTableValuedFunction_new(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_SQLTableValuedFunction_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_SQLTableValuedFunction_new(arg0, arg1, arg2)
}

func TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_Name(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_Name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_Name(arg0, arg1)
}

func TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_FullName(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_FullName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_FullName(arg0, arg1)
}

func TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_function_name_path(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_function_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_function_name_path(arg0, arg1)
}

func TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *int) {
	simple_catalog_TableValuedFunction_NumSignatures(
		arg0,
		(*C.int)(unsafe.Pointer(arg1)),
	)
}

func simple_catalog_TableValuedFunction_NumSignatures(arg0 unsafe.Pointer, arg1 *C.int) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_NumSignatures(arg0, arg1)
}

func TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_signatures(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_signatures(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_signatures(arg0, arg1)
}

func TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_AddSignature(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_TableValuedFunction_AddSignature(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_AddSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 int, arg2 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_GetSignature(
		arg0,
		C.int(arg1),
		arg2,
	)
}

func simple_catalog_TableValuedFunction_GetSignature(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_GetSignature(arg0, arg1, arg2)
}

func TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_GetSupportedSignaturesUserFacingText(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_GetSupportedSignaturesUserFacingText(arg0, arg1)
}

func TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_DebugString(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_DebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_DebugString(arg0, arg1)
}

func TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_SetUserIdColumnNamePath(
		arg0,
		arg1,
		arg2,
	)
}

func simple_catalog_TableValuedFunction_SetUserIdColumnNamePath(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_SetUserIdColumnNamePath(arg0, arg1, arg2)
}

func TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	simple_catalog_TableValuedFunction_anonymization_info(
		arg0,
		arg1,
	)
}

func simple_catalog_TableValuedFunction_anonymization_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer) {
	C.export_googlesql_public_simple_catalog_TableValuedFunction_anonymization_info(arg0, arg1)
}

//export export_googlesql_public_simple_catalog_cctz_FixedOffsetFromName
//go:linkname export_googlesql_public_simple_catalog_cctz_FixedOffsetFromName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetFromName
func export_googlesql_public_simple_catalog_cctz_FixedOffsetFromName(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_simple_catalog_cctz_FixedOffsetToName
//go:linkname export_googlesql_public_simple_catalog_cctz_FixedOffsetToName github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToName
func export_googlesql_public_simple_catalog_cctz_FixedOffsetToName(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_cctz_FixedOffsetToAbbr
//go:linkname export_googlesql_public_simple_catalog_cctz_FixedOffsetToAbbr github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_FixedOffsetToAbbr
func export_googlesql_public_simple_catalog_cctz_FixedOffsetToAbbr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_cctz_detail_format
//go:linkname export_googlesql_public_simple_catalog_cctz_detail_format github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_format
func export_googlesql_public_simple_catalog_cctz_detail_format(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_cctz_detail_parse
//go:linkname export_googlesql_public_simple_catalog_cctz_detail_parse github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_detail_parse
func export_googlesql_public_simple_catalog_cctz_detail_parse(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 unsafe.Pointer, arg4 unsafe.Pointer, arg5 unsafe.Pointer, arg6 *C.char)

//export export_googlesql_public_simple_catalog_TimeZoneIf_Load
//go:linkname export_googlesql_public_simple_catalog_TimeZoneIf_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneIf_Load
func export_googlesql_public_simple_catalog_TimeZoneIf_Load(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_time_zone_Impl_UTC
//go:linkname export_googlesql_public_simple_catalog_time_zone_Impl_UTC github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTC
func export_googlesql_public_simple_catalog_time_zone_Impl_UTC(arg0 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_time_zone_Impl_LoadTimeZone
//go:linkname export_googlesql_public_simple_catalog_time_zone_Impl_LoadTimeZone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_LoadTimeZone
func export_googlesql_public_simple_catalog_time_zone_Impl_LoadTimeZone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly
//go:linkname export_googlesql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_ClearTimeZoneMapTestOnly
func export_googlesql_public_simple_catalog_time_zone_Impl_ClearTimeZoneMapTestOnly()

//export export_googlesql_public_simple_catalog_time_zone_Impl_UTCImpl
//go:linkname export_googlesql_public_simple_catalog_time_zone_Impl_UTCImpl github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_Impl_UTCImpl
func export_googlesql_public_simple_catalog_time_zone_Impl_UTCImpl(arg0 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneInfo_Load
//go:linkname export_googlesql_public_simple_catalog_TimeZoneInfo_Load github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Load
func export_googlesql_public_simple_catalog_TimeZoneInfo_Load(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_simple_catalog_TimeZoneInfo_BreakTime
//go:linkname export_googlesql_public_simple_catalog_TimeZoneInfo_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_BreakTime
func export_googlesql_public_simple_catalog_TimeZoneInfo_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneInfo_MakeTime
//go:linkname export_googlesql_public_simple_catalog_TimeZoneInfo_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_MakeTime
func export_googlesql_public_simple_catalog_TimeZoneInfo_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneInfo_Version
//go:linkname export_googlesql_public_simple_catalog_TimeZoneInfo_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Version
func export_googlesql_public_simple_catalog_TimeZoneInfo_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneInfo_Description
//go:linkname export_googlesql_public_simple_catalog_TimeZoneInfo_Description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_Description
func export_googlesql_public_simple_catalog_TimeZoneInfo_Description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneInfo_NextTransition
//go:linkname export_googlesql_public_simple_catalog_TimeZoneInfo_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_NextTransition
func export_googlesql_public_simple_catalog_TimeZoneInfo_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_simple_catalog_TimeZoneInfo_PrevTransition
//go:linkname export_googlesql_public_simple_catalog_TimeZoneInfo_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneInfo_PrevTransition
func export_googlesql_public_simple_catalog_TimeZoneInfo_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_simple_catalog_TimeZoneLibC_BreakTime
//go:linkname export_googlesql_public_simple_catalog_TimeZoneLibC_BreakTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_BreakTime
func export_googlesql_public_simple_catalog_TimeZoneLibC_BreakTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneLibC_MakeTime
//go:linkname export_googlesql_public_simple_catalog_TimeZoneLibC_MakeTime github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_MakeTime
func export_googlesql_public_simple_catalog_TimeZoneLibC_MakeTime(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneLibC_Version
//go:linkname export_googlesql_public_simple_catalog_TimeZoneLibC_Version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_Version
func export_googlesql_public_simple_catalog_TimeZoneLibC_Version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_TimeZoneLibC_NextTransition
//go:linkname export_googlesql_public_simple_catalog_TimeZoneLibC_NextTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_NextTransition
func export_googlesql_public_simple_catalog_TimeZoneLibC_NextTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_simple_catalog_TimeZoneLibC_PrevTransition
//go:linkname export_googlesql_public_simple_catalog_TimeZoneLibC_PrevTransition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_TimeZoneLibC_PrevTransition
func export_googlesql_public_simple_catalog_TimeZoneLibC_PrevTransition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 unsafe.Pointer, arg3 *C.char)

//export export_googlesql_public_simple_catalog_time_zone_name
//go:linkname export_googlesql_public_simple_catalog_time_zone_name github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_name
func export_googlesql_public_simple_catalog_time_zone_name(arg0 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_time_zone_lookup
//go:linkname export_googlesql_public_simple_catalog_time_zone_lookup github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup
func export_googlesql_public_simple_catalog_time_zone_lookup(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_time_zone_lookup2
//go:linkname export_googlesql_public_simple_catalog_time_zone_lookup2 github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_lookup2
func export_googlesql_public_simple_catalog_time_zone_lookup2(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_time_zone_next_transition
//go:linkname export_googlesql_public_simple_catalog_time_zone_next_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_next_transition
func export_googlesql_public_simple_catalog_time_zone_next_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_simple_catalog_time_zone_prev_transition
//go:linkname export_googlesql_public_simple_catalog_time_zone_prev_transition github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_prev_transition
func export_googlesql_public_simple_catalog_time_zone_prev_transition(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_simple_catalog_time_zone_version
//go:linkname export_googlesql_public_simple_catalog_time_zone_version github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_version
func export_googlesql_public_simple_catalog_time_zone_version(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_time_zone_description
//go:linkname export_googlesql_public_simple_catalog_time_zone_description github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_time_zone_description
func export_googlesql_public_simple_catalog_time_zone_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_cctz_load_time_zone
//go:linkname export_googlesql_public_simple_catalog_cctz_load_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_load_time_zone
func export_googlesql_public_simple_catalog_cctz_load_time_zone(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_simple_catalog_cctz_utc_time_zone
//go:linkname export_googlesql_public_simple_catalog_cctz_utc_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_utc_time_zone
func export_googlesql_public_simple_catalog_cctz_utc_time_zone(arg0 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_cctz_fixed_time_zone
//go:linkname export_googlesql_public_simple_catalog_cctz_fixed_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_fixed_time_zone
func export_googlesql_public_simple_catalog_cctz_fixed_time_zone(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_cctz_local_time_zone
//go:linkname export_googlesql_public_simple_catalog_cctz_local_time_zone github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_local_time_zone
func export_googlesql_public_simple_catalog_cctz_local_time_zone(arg0 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_cctz_ParsePosixSpec
//go:linkname export_googlesql_public_simple_catalog_cctz_ParsePosixSpec github.com/goccy/go-zetasql/internal/ccall/go-absl/time/go_internal/cctz/time_zone.time_zone_cctz_ParsePosixSpec
func export_googlesql_public_simple_catalog_cctz_ParsePosixSpec(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *C.char)

//export export_googlesql_public_simple_catalog_ParseStatement
//go:linkname export_googlesql_public_simple_catalog_ParseStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseStatement
func export_googlesql_public_simple_catalog_ParseStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseScript
//go:linkname export_googlesql_public_simple_catalog_ParseScript github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseScript
func export_googlesql_public_simple_catalog_ParseScript(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 C.int, arg3 *unsafe.Pointer, arg4 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseNextStatement
//go:linkname export_googlesql_public_simple_catalog_ParseNextStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseNextStatement
func export_googlesql_public_simple_catalog_ParseNextStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.char, arg4 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseNextScriptStatement
//go:linkname export_googlesql_public_simple_catalog_ParseNextScriptStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseNextScriptStatement
func export_googlesql_public_simple_catalog_ParseNextScriptStatement(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *C.char, arg4 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseType
//go:linkname export_googlesql_public_simple_catalog_ParseType github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseType
func export_googlesql_public_simple_catalog_ParseType(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseExpression
//go:linkname export_googlesql_public_simple_catalog_ParseExpression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseExpression
func export_googlesql_public_simple_catalog_ParseExpression(arg0 unsafe.Pointer, arg1 unsafe.Pointer, arg2 *unsafe.Pointer, arg3 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_Unparse
//go:linkname export_googlesql_public_simple_catalog_Unparse github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_Unparse
func export_googlesql_public_simple_catalog_Unparse(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseResumeLocation_FromStringView
//go:linkname export_googlesql_public_simple_catalog_ParseResumeLocation_FromStringView github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseResumeLocation_FromStringView
func export_googlesql_public_simple_catalog_ParseResumeLocation_FromStringView(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_Status_OK
//go:linkname export_googlesql_public_simple_catalog_Status_OK github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_Status_OK
func export_googlesql_public_simple_catalog_Status_OK(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_Status_String
//go:linkname export_googlesql_public_simple_catalog_Status_String github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_Status_String
func export_googlesql_public_simple_catalog_Status_String(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParserOptions_new
//go:linkname export_googlesql_public_simple_catalog_ParserOptions_new github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParserOptions_new
func export_googlesql_public_simple_catalog_ParserOptions_new(arg0 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParserOptions_set_language_options
//go:linkname export_googlesql_public_simple_catalog_ParserOptions_set_language_options github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParserOptions_set_language_options
func export_googlesql_public_simple_catalog_ParserOptions_set_language_options(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParserOptions_language_options
//go:linkname export_googlesql_public_simple_catalog_ParserOptions_language_options github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParserOptions_language_options
func export_googlesql_public_simple_catalog_ParserOptions_language_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParserOutput_statement
//go:linkname export_googlesql_public_simple_catalog_ParserOutput_statement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParserOutput_statement
func export_googlesql_public_simple_catalog_ParserOutput_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParserOutput_script
//go:linkname export_googlesql_public_simple_catalog_ParserOutput_script github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParserOutput_script
func export_googlesql_public_simple_catalog_ParserOutput_script(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParserOutput_type
//go:linkname export_googlesql_public_simple_catalog_ParserOutput_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParserOutput_type
func export_googlesql_public_simple_catalog_ParserOutput_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParserOutput_expression
//go:linkname export_googlesql_public_simple_catalog_ParserOutput_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParserOutput_expression
func export_googlesql_public_simple_catalog_ParserOutput_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_node_kind
//go:linkname export_googlesql_public_simple_catalog_ASTNode_node_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_node_kind
func export_googlesql_public_simple_catalog_ASTNode_node_kind(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTNode_SingleNodeDebugString
//go:linkname export_googlesql_public_simple_catalog_ASTNode_SingleNodeDebugString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_SingleNodeDebugString
func export_googlesql_public_simple_catalog_ASTNode_SingleNodeDebugString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_set_parent
//go:linkname export_googlesql_public_simple_catalog_ASTNode_set_parent github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_set_parent
func export_googlesql_public_simple_catalog_ASTNode_set_parent(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_parent
//go:linkname export_googlesql_public_simple_catalog_ASTNode_parent github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_parent
func export_googlesql_public_simple_catalog_ASTNode_parent(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_AddChildren
//go:linkname export_googlesql_public_simple_catalog_ASTNode_AddChildren github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_AddChildren
func export_googlesql_public_simple_catalog_ASTNode_AddChildren(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_AddChild
//go:linkname export_googlesql_public_simple_catalog_ASTNode_AddChild github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_AddChild
func export_googlesql_public_simple_catalog_ASTNode_AddChild(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_AddChildFront
//go:linkname export_googlesql_public_simple_catalog_ASTNode_AddChildFront github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_AddChildFront
func export_googlesql_public_simple_catalog_ASTNode_AddChildFront(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_num_children
//go:linkname export_googlesql_public_simple_catalog_ASTNode_num_children github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_num_children
func export_googlesql_public_simple_catalog_ASTNode_num_children(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTNode_child
//go:linkname export_googlesql_public_simple_catalog_ASTNode_child github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_child
func export_googlesql_public_simple_catalog_ASTNode_child(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_mutable_child
//go:linkname export_googlesql_public_simple_catalog_ASTNode_mutable_child github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_mutable_child
func export_googlesql_public_simple_catalog_ASTNode_mutable_child(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_find_child_index
//go:linkname export_googlesql_public_simple_catalog_ASTNode_find_child_index github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_find_child_index
func export_googlesql_public_simple_catalog_ASTNode_find_child_index(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.int)

//export export_googlesql_public_simple_catalog_ASTNode_DebugString
//go:linkname export_googlesql_public_simple_catalog_ASTNode_DebugString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_DebugString
func export_googlesql_public_simple_catalog_ASTNode_DebugString(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_set_start_location
//go:linkname export_googlesql_public_simple_catalog_ASTNode_set_start_location github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_set_start_location
func export_googlesql_public_simple_catalog_ASTNode_set_start_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_set_end_location
//go:linkname export_googlesql_public_simple_catalog_ASTNode_set_end_location github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_set_end_location
func export_googlesql_public_simple_catalog_ASTNode_set_end_location(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_IsTableExpression
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsTableExpression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsTableExpression
func export_googlesql_public_simple_catalog_ASTNode_IsTableExpression(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsQueryExpression
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsQueryExpression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsQueryExpression
func export_googlesql_public_simple_catalog_ASTNode_IsQueryExpression(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsExpression
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsExpression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsExpression
func export_googlesql_public_simple_catalog_ASTNode_IsExpression(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsType
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsType github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsType
func export_googlesql_public_simple_catalog_ASTNode_IsType(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsLeaf
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsLeaf github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsLeaf
func export_googlesql_public_simple_catalog_ASTNode_IsLeaf(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsStatement
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsStatement
func export_googlesql_public_simple_catalog_ASTNode_IsStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsScriptStatement
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsScriptStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsScriptStatement
func export_googlesql_public_simple_catalog_ASTNode_IsScriptStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsLoopStatement
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsLoopStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsLoopStatement
func export_googlesql_public_simple_catalog_ASTNode_IsLoopStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsSqlStatement
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsSqlStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsSqlStatement
func export_googlesql_public_simple_catalog_ASTNode_IsSqlStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsDdlStatement
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsDdlStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsDdlStatement
func export_googlesql_public_simple_catalog_ASTNode_IsDdlStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsCreateStatement
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsCreateStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsCreateStatement
func export_googlesql_public_simple_catalog_ASTNode_IsCreateStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_IsAlterStatement
//go:linkname export_googlesql_public_simple_catalog_ASTNode_IsAlterStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_IsAlterStatement
func export_googlesql_public_simple_catalog_ASTNode_IsAlterStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTNode_GetNodeKindString
//go:linkname export_googlesql_public_simple_catalog_ASTNode_GetNodeKindString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_GetNodeKindString
func export_googlesql_public_simple_catalog_ASTNode_GetNodeKindString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_GetParseLocationRange
//go:linkname export_googlesql_public_simple_catalog_ASTNode_GetParseLocationRange github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_GetParseLocationRange
func export_googlesql_public_simple_catalog_ASTNode_GetParseLocationRange(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_GetLocationString
//go:linkname export_googlesql_public_simple_catalog_ASTNode_GetLocationString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_GetLocationString
func export_googlesql_public_simple_catalog_ASTNode_GetLocationString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNode_NodeKindToString
//go:linkname export_googlesql_public_simple_catalog_ASTNode_NodeKindToString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNode_NodeKindToString
func export_googlesql_public_simple_catalog_ASTNode_NodeKindToString(arg0 C.int, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseLocationPoint_filename
//go:linkname export_googlesql_public_simple_catalog_ParseLocationPoint_filename github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseLocationPoint_filename
func export_googlesql_public_simple_catalog_ParseLocationPoint_filename(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseLocationPoint_GetByteOffset
//go:linkname export_googlesql_public_simple_catalog_ParseLocationPoint_GetByteOffset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseLocationPoint_GetByteOffset
func export_googlesql_public_simple_catalog_ParseLocationPoint_GetByteOffset(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ParseLocationPoint_GetString
//go:linkname export_googlesql_public_simple_catalog_ParseLocationPoint_GetString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseLocationPoint_GetString
func export_googlesql_public_simple_catalog_ParseLocationPoint_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseLocationRange_start
//go:linkname export_googlesql_public_simple_catalog_ParseLocationRange_start github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseLocationRange_start
func export_googlesql_public_simple_catalog_ParseLocationRange_start(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseLocationRange_end
//go:linkname export_googlesql_public_simple_catalog_ParseLocationRange_end github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseLocationRange_end
func export_googlesql_public_simple_catalog_ParseLocationRange_end(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ParseLocationRange_GetString
//go:linkname export_googlesql_public_simple_catalog_ParseLocationRange_GetString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ParseLocationRange_GetString
func export_googlesql_public_simple_catalog_ParseLocationRange_GetString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTQueryStatement_query
//go:linkname export_googlesql_public_simple_catalog_ASTQueryStatement_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQueryStatement_query
func export_googlesql_public_simple_catalog_ASTQueryStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTQueryExpression_set_parenthesized
//go:linkname export_googlesql_public_simple_catalog_ASTQueryExpression_set_parenthesized github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQueryExpression_set_parenthesized
func export_googlesql_public_simple_catalog_ASTQueryExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTQueryExpression_parenthesized
//go:linkname export_googlesql_public_simple_catalog_ASTQueryExpression_parenthesized github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQueryExpression_parenthesized
func export_googlesql_public_simple_catalog_ASTQueryExpression_parenthesized(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTQuery_set_is_nested
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_set_is_nested github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_set_is_nested
func export_googlesql_public_simple_catalog_ASTQuery_set_is_nested(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTQuery_is_nested
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_is_nested github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_is_nested
func export_googlesql_public_simple_catalog_ASTQuery_is_nested(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTQuery_set_is_pivot_input
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_set_is_pivot_input github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_set_is_pivot_input
func export_googlesql_public_simple_catalog_ASTQuery_set_is_pivot_input(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTQuery_is_pivot_input
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_is_pivot_input github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_is_pivot_input
func export_googlesql_public_simple_catalog_ASTQuery_is_pivot_input(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTQuery_with_clause
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_with_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_with_clause
func export_googlesql_public_simple_catalog_ASTQuery_with_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTQuery_query_expr
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_query_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_query_expr
func export_googlesql_public_simple_catalog_ASTQuery_query_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTQuery_order_by
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_order_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_order_by
func export_googlesql_public_simple_catalog_ASTQuery_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTQuery_limit_offset
//go:linkname export_googlesql_public_simple_catalog_ASTQuery_limit_offset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQuery_limit_offset
func export_googlesql_public_simple_catalog_ASTQuery_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_set_distinct
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_set_distinct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_set_distinct
func export_googlesql_public_simple_catalog_ASTSelect_set_distinct(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTSelect_distinct
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_distinct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_distinct
func export_googlesql_public_simple_catalog_ASTSelect_distinct(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTSelect_hint
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_hint
func export_googlesql_public_simple_catalog_ASTSelect_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_select_as
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_select_as github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_select_as
func export_googlesql_public_simple_catalog_ASTSelect_select_as(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_select_list
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_select_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_select_list
func export_googlesql_public_simple_catalog_ASTSelect_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_from_clause
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_from_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_from_clause
func export_googlesql_public_simple_catalog_ASTSelect_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_where_clause
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_where_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_where_clause
func export_googlesql_public_simple_catalog_ASTSelect_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_group_by
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_group_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_group_by
func export_googlesql_public_simple_catalog_ASTSelect_group_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_having
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_having github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_having
func export_googlesql_public_simple_catalog_ASTSelect_having(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_qualify
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_qualify github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_qualify
func export_googlesql_public_simple_catalog_ASTSelect_qualify(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_window_clause
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_window_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_window_clause
func export_googlesql_public_simple_catalog_ASTSelect_window_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelect_anonymization_options
//go:linkname export_googlesql_public_simple_catalog_ASTSelect_anonymization_options github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelect_anonymization_options
func export_googlesql_public_simple_catalog_ASTSelect_anonymization_options(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelectList_column_num
//go:linkname export_googlesql_public_simple_catalog_ASTSelectList_column_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectList_column_num
func export_googlesql_public_simple_catalog_ASTSelectList_column_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTSelectList_column
//go:linkname export_googlesql_public_simple_catalog_ASTSelectList_column github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectList_column
func export_googlesql_public_simple_catalog_ASTSelectList_column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelectColumn_expression
//go:linkname export_googlesql_public_simple_catalog_ASTSelectColumn_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectColumn_expression
func export_googlesql_public_simple_catalog_ASTSelectColumn_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelectColumn_alias
//go:linkname export_googlesql_public_simple_catalog_ASTSelectColumn_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectColumn_alias
func export_googlesql_public_simple_catalog_ASTSelectColumn_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExpression_set_parenthesized
//go:linkname export_googlesql_public_simple_catalog_ASTExpression_set_parenthesized github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExpression_set_parenthesized
func export_googlesql_public_simple_catalog_ASTExpression_set_parenthesized(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTExpression_parenthesized
//go:linkname export_googlesql_public_simple_catalog_ASTExpression_parenthesized github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExpression_parenthesized
func export_googlesql_public_simple_catalog_ASTExpression_parenthesized(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTExpression_IsAllowedInComparison
//go:linkname export_googlesql_public_simple_catalog_ASTExpression_IsAllowedInComparison github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExpression_IsAllowedInComparison
func export_googlesql_public_simple_catalog_ASTExpression_IsAllowedInComparison(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTLeaf_image
//go:linkname export_googlesql_public_simple_catalog_ASTLeaf_image github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLeaf_image
func export_googlesql_public_simple_catalog_ASTLeaf_image(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLeaf_set_image
//go:linkname export_googlesql_public_simple_catalog_ASTLeaf_set_image github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLeaf_set_image
func export_googlesql_public_simple_catalog_ASTLeaf_set_image(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIntLiteral_is_hex
//go:linkname export_googlesql_public_simple_catalog_ASTIntLiteral_is_hex github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIntLiteral_is_hex
func export_googlesql_public_simple_catalog_ASTIntLiteral_is_hex(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTIdentifier_GetAsString
//go:linkname export_googlesql_public_simple_catalog_ASTIdentifier_GetAsString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIdentifier_GetAsString
func export_googlesql_public_simple_catalog_ASTIdentifier_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIdentifier_SetIdentifier
//go:linkname export_googlesql_public_simple_catalog_ASTIdentifier_SetIdentifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIdentifier_SetIdentifier
func export_googlesql_public_simple_catalog_ASTIdentifier_SetIdentifier(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlias_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTAlias_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlias_identifier
func export_googlesql_public_simple_catalog_ASTAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlias_GetAsString
//go:linkname export_googlesql_public_simple_catalog_ASTAlias_GetAsString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlias_GetAsString
func export_googlesql_public_simple_catalog_ASTAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPathExpression_num_names
//go:linkname export_googlesql_public_simple_catalog_ASTPathExpression_num_names github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPathExpression_num_names
func export_googlesql_public_simple_catalog_ASTPathExpression_num_names(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTPathExpression_name
//go:linkname export_googlesql_public_simple_catalog_ASTPathExpression_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPathExpression_name
func export_googlesql_public_simple_catalog_ASTPathExpression_name(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPathExpression_ToIdentifierPathString
//go:linkname export_googlesql_public_simple_catalog_ASTPathExpression_ToIdentifierPathString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPathExpression_ToIdentifierPathString
func export_googlesql_public_simple_catalog_ASTPathExpression_ToIdentifierPathString(arg0 unsafe.Pointer, arg1 C.uint32_t, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_path_expr
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_path_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_path_expr
func export_googlesql_public_simple_catalog_ASTTablePathExpression_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_unnest_expr
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_unnest_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_unnest_expr
func export_googlesql_public_simple_catalog_ASTTablePathExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_hint
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_hint
func export_googlesql_public_simple_catalog_ASTTablePathExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_with_offset
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_with_offset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_with_offset
func export_googlesql_public_simple_catalog_ASTTablePathExpression_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_pivot_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_pivot_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_pivot_clause
func export_googlesql_public_simple_catalog_ASTTablePathExpression_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_unpivot_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_unpivot_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_unpivot_clause
func export_googlesql_public_simple_catalog_ASTTablePathExpression_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_for_system_time
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_for_system_time github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_for_system_time
func export_googlesql_public_simple_catalog_ASTTablePathExpression_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_sample_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_sample_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_sample_clause
func export_googlesql_public_simple_catalog_ASTTablePathExpression_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTablePathExpression_alias
//go:linkname export_googlesql_public_simple_catalog_ASTTablePathExpression_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTablePathExpression_alias
func export_googlesql_public_simple_catalog_ASTTablePathExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFromClause_table_expression
//go:linkname export_googlesql_public_simple_catalog_ASTFromClause_table_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFromClause_table_expression
func export_googlesql_public_simple_catalog_ASTFromClause_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWhereClause_expression
//go:linkname export_googlesql_public_simple_catalog_ASTWhereClause_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWhereClause_expression
func export_googlesql_public_simple_catalog_ASTWhereClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBooleanLiteral_set_value
//go:linkname export_googlesql_public_simple_catalog_ASTBooleanLiteral_set_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBooleanLiteral_set_value
func export_googlesql_public_simple_catalog_ASTBooleanLiteral_set_value(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTBooleanLiteral_value
//go:linkname export_googlesql_public_simple_catalog_ASTBooleanLiteral_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBooleanLiteral_value
func export_googlesql_public_simple_catalog_ASTBooleanLiteral_value(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAndExpr_conjuncts_num
//go:linkname export_googlesql_public_simple_catalog_ASTAndExpr_conjuncts_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAndExpr_conjuncts_num
func export_googlesql_public_simple_catalog_ASTAndExpr_conjuncts_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTAndExpr_conjunct
//go:linkname export_googlesql_public_simple_catalog_ASTAndExpr_conjunct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAndExpr_conjunct
func export_googlesql_public_simple_catalog_ASTAndExpr_conjunct(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBinaryExpression_set_op
//go:linkname export_googlesql_public_simple_catalog_ASTBinaryExpression_set_op github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBinaryExpression_set_op
func export_googlesql_public_simple_catalog_ASTBinaryExpression_set_op(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTBinaryExpression_op
//go:linkname export_googlesql_public_simple_catalog_ASTBinaryExpression_op github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBinaryExpression_op
func export_googlesql_public_simple_catalog_ASTBinaryExpression_op(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTBinaryExpression_set_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTBinaryExpression_set_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBinaryExpression_set_is_not
func export_googlesql_public_simple_catalog_ASTBinaryExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTBinaryExpression_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTBinaryExpression_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBinaryExpression_is_not
func export_googlesql_public_simple_catalog_ASTBinaryExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTBinaryExpression_lhs
//go:linkname export_googlesql_public_simple_catalog_ASTBinaryExpression_lhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBinaryExpression_lhs
func export_googlesql_public_simple_catalog_ASTBinaryExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBinaryExpression_rhs
//go:linkname export_googlesql_public_simple_catalog_ASTBinaryExpression_rhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBinaryExpression_rhs
func export_googlesql_public_simple_catalog_ASTBinaryExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBinaryExpression_GetSQLForOperator
//go:linkname export_googlesql_public_simple_catalog_ASTBinaryExpression_GetSQLForOperator github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBinaryExpression_GetSQLForOperator
func export_googlesql_public_simple_catalog_ASTBinaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStringLiteral_string_value
//go:linkname export_googlesql_public_simple_catalog_ASTStringLiteral_string_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStringLiteral_string_value
func export_googlesql_public_simple_catalog_ASTStringLiteral_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStringLiteral_set_string_value
//go:linkname export_googlesql_public_simple_catalog_ASTStringLiteral_set_string_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStringLiteral_set_string_value
func export_googlesql_public_simple_catalog_ASTStringLiteral_set_string_value(arg0 unsafe.Pointer, arg1 unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOrExpr_disjuncts_num
//go:linkname export_googlesql_public_simple_catalog_ASTOrExpr_disjuncts_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrExpr_disjuncts_num
func export_googlesql_public_simple_catalog_ASTOrExpr_disjuncts_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTOrExpr_disjunct
//go:linkname export_googlesql_public_simple_catalog_ASTOrExpr_disjunct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrExpr_disjunct
func export_googlesql_public_simple_catalog_ASTOrExpr_disjunct(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGroupingItem_expression
//go:linkname export_googlesql_public_simple_catalog_ASTGroupingItem_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGroupingItem_expression
func export_googlesql_public_simple_catalog_ASTGroupingItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGroupingItem_rollup
//go:linkname export_googlesql_public_simple_catalog_ASTGroupingItem_rollup github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGroupingItem_rollup
func export_googlesql_public_simple_catalog_ASTGroupingItem_rollup(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGroupBy_hint
//go:linkname export_googlesql_public_simple_catalog_ASTGroupBy_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGroupBy_hint
func export_googlesql_public_simple_catalog_ASTGroupBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGroupBy_grouping_items_num
//go:linkname export_googlesql_public_simple_catalog_ASTGroupBy_grouping_items_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGroupBy_grouping_items_num
func export_googlesql_public_simple_catalog_ASTGroupBy_grouping_items_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTGroupBy_grouping_item
//go:linkname export_googlesql_public_simple_catalog_ASTGroupBy_grouping_item github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGroupBy_grouping_item
func export_googlesql_public_simple_catalog_ASTGroupBy_grouping_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGroupBy_all
//go:linkname export_googlesql_public_simple_catalog_ASTGroupBy_all github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGroupBy_all
func export_googlesql_public_simple_catalog_ASTGroupBy_all(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOrderingExpression_set_ordering_spec
//go:linkname export_googlesql_public_simple_catalog_ASTOrderingExpression_set_ordering_spec github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderingExpression_set_ordering_spec
func export_googlesql_public_simple_catalog_ASTOrderingExpression_set_ordering_spec(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTOrderingExpression_ordering_spec
//go:linkname export_googlesql_public_simple_catalog_ASTOrderingExpression_ordering_spec github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderingExpression_ordering_spec
func export_googlesql_public_simple_catalog_ASTOrderingExpression_ordering_spec(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTOrderingExpression_expression
//go:linkname export_googlesql_public_simple_catalog_ASTOrderingExpression_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderingExpression_expression
func export_googlesql_public_simple_catalog_ASTOrderingExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOrderingExpression_collate
//go:linkname export_googlesql_public_simple_catalog_ASTOrderingExpression_collate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderingExpression_collate
func export_googlesql_public_simple_catalog_ASTOrderingExpression_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOrderingExpression_null_order
//go:linkname export_googlesql_public_simple_catalog_ASTOrderingExpression_null_order github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderingExpression_null_order
func export_googlesql_public_simple_catalog_ASTOrderingExpression_null_order(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOrderBy_hint
//go:linkname export_googlesql_public_simple_catalog_ASTOrderBy_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderBy_hint
func export_googlesql_public_simple_catalog_ASTOrderBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOrderBy_ordering_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTOrderBy_ordering_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderBy_ordering_expressions_num
func export_googlesql_public_simple_catalog_ASTOrderBy_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTOrderBy_ordering_expression
//go:linkname export_googlesql_public_simple_catalog_ASTOrderBy_ordering_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOrderBy_ordering_expression
func export_googlesql_public_simple_catalog_ASTOrderBy_ordering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLimitOffset_limit
//go:linkname export_googlesql_public_simple_catalog_ASTLimitOffset_limit github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLimitOffset_limit
func export_googlesql_public_simple_catalog_ASTLimitOffset_limit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLimitOffset_offset
//go:linkname export_googlesql_public_simple_catalog_ASTLimitOffset_offset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLimitOffset_offset
func export_googlesql_public_simple_catalog_ASTLimitOffset_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOnClause_expression
//go:linkname export_googlesql_public_simple_catalog_ASTOnClause_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOnClause_expression
func export_googlesql_public_simple_catalog_ASTOnClause_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAliasedQuery_alias
//go:linkname export_googlesql_public_simple_catalog_ASTAliasedQuery_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAliasedQuery_alias
func export_googlesql_public_simple_catalog_ASTAliasedQuery_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAliasedQuery_query
//go:linkname export_googlesql_public_simple_catalog_ASTAliasedQuery_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAliasedQuery_query
func export_googlesql_public_simple_catalog_ASTAliasedQuery_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_set_join_type
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_set_join_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_set_join_type
func export_googlesql_public_simple_catalog_ASTJoin_set_join_type(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_join_type
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_join_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_join_type
func export_googlesql_public_simple_catalog_ASTJoin_join_type(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_set_join_hint
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_set_join_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_set_join_hint
func export_googlesql_public_simple_catalog_ASTJoin_set_join_hint(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_join_hint
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_join_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_join_hint
func export_googlesql_public_simple_catalog_ASTJoin_join_hint(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_set_natural
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_set_natural github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_set_natural
func export_googlesql_public_simple_catalog_ASTJoin_set_natural(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_natural
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_natural github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_natural
func export_googlesql_public_simple_catalog_ASTJoin_natural(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTJoin_set_unmatched_join_count
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_set_unmatched_join_count github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_set_unmatched_join_count
func export_googlesql_public_simple_catalog_ASTJoin_set_unmatched_join_count(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_unmatched_join_count
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_unmatched_join_count github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_unmatched_join_count
func export_googlesql_public_simple_catalog_ASTJoin_unmatched_join_count(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_set_transformation_needed
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_set_transformation_needed github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_set_transformation_needed
func export_googlesql_public_simple_catalog_ASTJoin_set_transformation_needed(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_transformation_needed
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_transformation_needed github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_transformation_needed
func export_googlesql_public_simple_catalog_ASTJoin_transformation_needed(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTJoin_set_contains_comma_join
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_set_contains_comma_join github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_set_contains_comma_join
func export_googlesql_public_simple_catalog_ASTJoin_set_contains_comma_join(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTJoin_contains_comma_join
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_contains_comma_join github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_contains_comma_join
func export_googlesql_public_simple_catalog_ASTJoin_contains_comma_join(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTJoin_lhs
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_lhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_lhs
func export_googlesql_public_simple_catalog_ASTJoin_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_rhs
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_rhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_rhs
func export_googlesql_public_simple_catalog_ASTJoin_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_hint
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_hint
func export_googlesql_public_simple_catalog_ASTJoin_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_on_clause
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_on_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_on_clause
func export_googlesql_public_simple_catalog_ASTJoin_on_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_using_clause
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_using_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_using_clause
func export_googlesql_public_simple_catalog_ASTJoin_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_JoinParseError_error_node
//go:linkname export_googlesql_public_simple_catalog_JoinParseError_error_node github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_JoinParseError_error_node
func export_googlesql_public_simple_catalog_JoinParseError_error_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_JoinParseError_message
//go:linkname export_googlesql_public_simple_catalog_JoinParseError_message github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_JoinParseError_message
func export_googlesql_public_simple_catalog_JoinParseError_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_parse_error
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_parse_error github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_parse_error
func export_googlesql_public_simple_catalog_ASTJoin_parse_error(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_GetSQLForJoinType
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_GetSQLForJoinType github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_GetSQLForJoinType
func export_googlesql_public_simple_catalog_ASTJoin_GetSQLForJoinType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTJoin_GetSQLForJoinHint
//go:linkname export_googlesql_public_simple_catalog_ASTJoin_GetSQLForJoinHint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTJoin_GetSQLForJoinHint
func export_googlesql_public_simple_catalog_ASTJoin_GetSQLForJoinHint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithClause_set_recursive
//go:linkname export_googlesql_public_simple_catalog_ASTWithClause_set_recursive github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithClause_set_recursive
func export_googlesql_public_simple_catalog_ASTWithClause_set_recursive(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTWithClause_recursive
//go:linkname export_googlesql_public_simple_catalog_ASTWithClause_recursive github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithClause_recursive
func export_googlesql_public_simple_catalog_ASTWithClause_recursive(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTWithClause_with_num
//go:linkname export_googlesql_public_simple_catalog_ASTWithClause_with_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithClause_with_num
func export_googlesql_public_simple_catalog_ASTWithClause_with_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTWithClause_with
//go:linkname export_googlesql_public_simple_catalog_ASTWithClause_with github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithClause_with
func export_googlesql_public_simple_catalog_ASTWithClause_with(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithClauseEntry_alias
//go:linkname export_googlesql_public_simple_catalog_ASTWithClauseEntry_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithClauseEntry_alias
func export_googlesql_public_simple_catalog_ASTWithClauseEntry_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithClauseEntry_query
//go:linkname export_googlesql_public_simple_catalog_ASTWithClauseEntry_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithClauseEntry_query
func export_googlesql_public_simple_catalog_ASTWithClauseEntry_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHaving_expression
//go:linkname export_googlesql_public_simple_catalog_ASTHaving_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHaving_expression
func export_googlesql_public_simple_catalog_ASTHaving_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTType_type_parameters
//go:linkname export_googlesql_public_simple_catalog_ASTType_type_parameters github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTType_type_parameters
func export_googlesql_public_simple_catalog_ASTType_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTType_collate
//go:linkname export_googlesql_public_simple_catalog_ASTType_collate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTType_collate
func export_googlesql_public_simple_catalog_ASTType_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSimpleType_type_name
//go:linkname export_googlesql_public_simple_catalog_ASTSimpleType_type_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSimpleType_type_name
func export_googlesql_public_simple_catalog_ASTSimpleType_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTArrayType_element_type
//go:linkname export_googlesql_public_simple_catalog_ASTArrayType_element_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTArrayType_element_type
func export_googlesql_public_simple_catalog_ASTArrayType_element_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructField_name
//go:linkname export_googlesql_public_simple_catalog_ASTStructField_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructField_name
func export_googlesql_public_simple_catalog_ASTStructField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructField_type
//go:linkname export_googlesql_public_simple_catalog_ASTStructField_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructField_type
func export_googlesql_public_simple_catalog_ASTStructField_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructType_struct_fields_num
//go:linkname export_googlesql_public_simple_catalog_ASTStructType_struct_fields_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructType_struct_fields_num
func export_googlesql_public_simple_catalog_ASTStructType_struct_fields_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTStructType_struct_field
//go:linkname export_googlesql_public_simple_catalog_ASTStructType_struct_field github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructType_struct_field
func export_googlesql_public_simple_catalog_ASTStructType_struct_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCastExpression_set_is_safe_cast
//go:linkname export_googlesql_public_simple_catalog_ASTCastExpression_set_is_safe_cast github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCastExpression_set_is_safe_cast
func export_googlesql_public_simple_catalog_ASTCastExpression_set_is_safe_cast(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCastExpression_is_safe_cast
//go:linkname export_googlesql_public_simple_catalog_ASTCastExpression_is_safe_cast github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCastExpression_is_safe_cast
func export_googlesql_public_simple_catalog_ASTCastExpression_is_safe_cast(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCastExpression_expr
//go:linkname export_googlesql_public_simple_catalog_ASTCastExpression_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCastExpression_expr
func export_googlesql_public_simple_catalog_ASTCastExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCastExpression_type
//go:linkname export_googlesql_public_simple_catalog_ASTCastExpression_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCastExpression_type
func export_googlesql_public_simple_catalog_ASTCastExpression_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCastExpression_format
//go:linkname export_googlesql_public_simple_catalog_ASTCastExpression_format github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCastExpression_format
func export_googlesql_public_simple_catalog_ASTCastExpression_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelectAs_set_as_mode
//go:linkname export_googlesql_public_simple_catalog_ASTSelectAs_set_as_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectAs_set_as_mode
func export_googlesql_public_simple_catalog_ASTSelectAs_set_as_mode(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTSelectAs_as_mode
//go:linkname export_googlesql_public_simple_catalog_ASTSelectAs_as_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectAs_as_mode
func export_googlesql_public_simple_catalog_ASTSelectAs_as_mode(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTSelectAs_type_name
//go:linkname export_googlesql_public_simple_catalog_ASTSelectAs_type_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectAs_type_name
func export_googlesql_public_simple_catalog_ASTSelectAs_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSelectAs_is_select_as_struct
//go:linkname export_googlesql_public_simple_catalog_ASTSelectAs_is_select_as_struct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectAs_is_select_as_struct
func export_googlesql_public_simple_catalog_ASTSelectAs_is_select_as_struct(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTSelectAs_is_select_as_value
//go:linkname export_googlesql_public_simple_catalog_ASTSelectAs_is_select_as_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSelectAs_is_select_as_value
func export_googlesql_public_simple_catalog_ASTSelectAs_is_select_as_value(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTRollup_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTRollup_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRollup_expressions_num
func export_googlesql_public_simple_catalog_ASTRollup_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTRollup_expression
//go:linkname export_googlesql_public_simple_catalog_ASTRollup_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRollup_expression
func export_googlesql_public_simple_catalog_ASTRollup_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_set_null_handling_modifier
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_set_null_handling_modifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_set_null_handling_modifier
func export_googlesql_public_simple_catalog_ASTFunctionCall_set_null_handling_modifier(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_null_handling_modifier
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_null_handling_modifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_null_handling_modifier
func export_googlesql_public_simple_catalog_ASTFunctionCall_null_handling_modifier(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_set_distinct
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_set_distinct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_set_distinct
func export_googlesql_public_simple_catalog_ASTFunctionCall_set_distinct(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_distinct
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_distinct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_distinct
func export_googlesql_public_simple_catalog_ASTFunctionCall_distinct(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_set_is_current_date_time_without_parentheses
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_set_is_current_date_time_without_parentheses github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_set_is_current_date_time_without_parentheses
func export_googlesql_public_simple_catalog_ASTFunctionCall_set_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_is_current_date_time_without_parentheses
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_is_current_date_time_without_parentheses github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_is_current_date_time_without_parentheses
func export_googlesql_public_simple_catalog_ASTFunctionCall_is_current_date_time_without_parentheses(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_function
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_function github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_function
func export_googlesql_public_simple_catalog_ASTFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_having_modifier
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_having_modifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_having_modifier
func export_googlesql_public_simple_catalog_ASTFunctionCall_having_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_clamped_between_modifier
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_clamped_between_modifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_clamped_between_modifier
func export_googlesql_public_simple_catalog_ASTFunctionCall_clamped_between_modifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_order_by
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_order_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_order_by
func export_googlesql_public_simple_catalog_ASTFunctionCall_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_limit_offset
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_limit_offset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_limit_offset
func export_googlesql_public_simple_catalog_ASTFunctionCall_limit_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_hint
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_hint
func export_googlesql_public_simple_catalog_ASTFunctionCall_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_with_group_rows
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_with_group_rows github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_with_group_rows
func export_googlesql_public_simple_catalog_ASTFunctionCall_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_arguments_num
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_arguments_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_arguments_num
func export_googlesql_public_simple_catalog_ASTFunctionCall_arguments_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_argument
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_argument
func export_googlesql_public_simple_catalog_ASTFunctionCall_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCall_HasModifiers
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCall_HasModifiers github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCall_HasModifiers
func export_googlesql_public_simple_catalog_ASTFunctionCall_HasModifiers(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTArrayConstructor_type
//go:linkname export_googlesql_public_simple_catalog_ASTArrayConstructor_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTArrayConstructor_type
func export_googlesql_public_simple_catalog_ASTArrayConstructor_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTArrayConstructor_elements_num
//go:linkname export_googlesql_public_simple_catalog_ASTArrayConstructor_elements_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTArrayConstructor_elements_num
func export_googlesql_public_simple_catalog_ASTArrayConstructor_elements_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTArrayConstructor_element
//go:linkname export_googlesql_public_simple_catalog_ASTArrayConstructor_element github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTArrayConstructor_element
func export_googlesql_public_simple_catalog_ASTArrayConstructor_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructConstructorArg_expression
//go:linkname export_googlesql_public_simple_catalog_ASTStructConstructorArg_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructConstructorArg_expression
func export_googlesql_public_simple_catalog_ASTStructConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructConstructorArg_alias
//go:linkname export_googlesql_public_simple_catalog_ASTStructConstructorArg_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructConstructorArg_alias
func export_googlesql_public_simple_catalog_ASTStructConstructorArg_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructConstructorWithParens_field_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTStructConstructorWithParens_field_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructConstructorWithParens_field_expressions_num
func export_googlesql_public_simple_catalog_ASTStructConstructorWithParens_field_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTStructConstructorWithParens_field_expression
//go:linkname export_googlesql_public_simple_catalog_ASTStructConstructorWithParens_field_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructConstructorWithParens_field_expression
func export_googlesql_public_simple_catalog_ASTStructConstructorWithParens_field_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_struct_type
//go:linkname export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_struct_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructConstructorWithKeyword_struct_type
func export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_struct_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_fields_num
//go:linkname export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_fields_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructConstructorWithKeyword_fields_num
func export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_fields_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_field
//go:linkname export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_field github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructConstructorWithKeyword_field
func export_googlesql_public_simple_catalog_ASTStructConstructorWithKeyword_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInExpression_set_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTInExpression_set_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInExpression_set_is_not
func export_googlesql_public_simple_catalog_ASTInExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTInExpression_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTInExpression_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInExpression_is_not
func export_googlesql_public_simple_catalog_ASTInExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTInExpression_lhs
//go:linkname export_googlesql_public_simple_catalog_ASTInExpression_lhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInExpression_lhs
func export_googlesql_public_simple_catalog_ASTInExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInExpression_hint
//go:linkname export_googlesql_public_simple_catalog_ASTInExpression_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInExpression_hint
func export_googlesql_public_simple_catalog_ASTInExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInExpression_in_list
//go:linkname export_googlesql_public_simple_catalog_ASTInExpression_in_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInExpression_in_list
func export_googlesql_public_simple_catalog_ASTInExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInExpression_query
//go:linkname export_googlesql_public_simple_catalog_ASTInExpression_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInExpression_query
func export_googlesql_public_simple_catalog_ASTInExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInExpression_unnest_expr
//go:linkname export_googlesql_public_simple_catalog_ASTInExpression_unnest_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInExpression_unnest_expr
func export_googlesql_public_simple_catalog_ASTInExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInList_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTInList_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInList_list_num
func export_googlesql_public_simple_catalog_ASTInList_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTInList_list
//go:linkname export_googlesql_public_simple_catalog_ASTInList_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInList_list
func export_googlesql_public_simple_catalog_ASTInList_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBetweenExpression_set_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTBetweenExpression_set_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBetweenExpression_set_is_not
func export_googlesql_public_simple_catalog_ASTBetweenExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTBetweenExpression_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTBetweenExpression_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBetweenExpression_is_not
func export_googlesql_public_simple_catalog_ASTBetweenExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTBetweenExpression_lhs
//go:linkname export_googlesql_public_simple_catalog_ASTBetweenExpression_lhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBetweenExpression_lhs
func export_googlesql_public_simple_catalog_ASTBetweenExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBetweenExpression_low
//go:linkname export_googlesql_public_simple_catalog_ASTBetweenExpression_low github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBetweenExpression_low
func export_googlesql_public_simple_catalog_ASTBetweenExpression_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBetweenExpression_high
//go:linkname export_googlesql_public_simple_catalog_ASTBetweenExpression_high github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBetweenExpression_high
func export_googlesql_public_simple_catalog_ASTBetweenExpression_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_set_type_kind
//go:linkname export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_set_type_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDateOrTimeLiteral_set_type_kind
func export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_set_type_kind(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_type_kind
//go:linkname export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_type_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDateOrTimeLiteral_type_kind
func export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_type_kind(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_string_literal
//go:linkname export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_string_literal github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDateOrTimeLiteral_string_literal
func export_googlesql_public_simple_catalog_ASTDateOrTimeLiteral_string_literal(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCaseValueExpression_arguments_num
//go:linkname export_googlesql_public_simple_catalog_ASTCaseValueExpression_arguments_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCaseValueExpression_arguments_num
func export_googlesql_public_simple_catalog_ASTCaseValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTCaseValueExpression_argument
//go:linkname export_googlesql_public_simple_catalog_ASTCaseValueExpression_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCaseValueExpression_argument
func export_googlesql_public_simple_catalog_ASTCaseValueExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCaseNoValueExpression_arguments_num
//go:linkname export_googlesql_public_simple_catalog_ASTCaseNoValueExpression_arguments_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCaseNoValueExpression_arguments_num
func export_googlesql_public_simple_catalog_ASTCaseNoValueExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTCaseNoValueExpression_argument
//go:linkname export_googlesql_public_simple_catalog_ASTCaseNoValueExpression_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCaseNoValueExpression_argument
func export_googlesql_public_simple_catalog_ASTCaseNoValueExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTArrayElement_array
//go:linkname export_googlesql_public_simple_catalog_ASTArrayElement_array github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTArrayElement_array
func export_googlesql_public_simple_catalog_ASTArrayElement_array(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTArrayElement_position
//go:linkname export_googlesql_public_simple_catalog_ASTArrayElement_position github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTArrayElement_position
func export_googlesql_public_simple_catalog_ASTArrayElement_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_set_is_left_shift
//go:linkname export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_set_is_left_shift github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBitwiseShiftExpression_set_is_left_shift
func export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_set_is_left_shift(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_is_left_shift
//go:linkname export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_is_left_shift github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBitwiseShiftExpression_is_left_shift
func export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_is_left_shift(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_lhs
//go:linkname export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_lhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBitwiseShiftExpression_lhs
func export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_rhs
//go:linkname export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_rhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBitwiseShiftExpression_rhs
func export_googlesql_public_simple_catalog_ASTBitwiseShiftExpression_rhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCollate_collation_name
//go:linkname export_googlesql_public_simple_catalog_ASTCollate_collation_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCollate_collation_name
func export_googlesql_public_simple_catalog_ASTCollate_collation_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDotGeneralizedField_expr
//go:linkname export_googlesql_public_simple_catalog_ASTDotGeneralizedField_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDotGeneralizedField_expr
func export_googlesql_public_simple_catalog_ASTDotGeneralizedField_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDotGeneralizedField_path
//go:linkname export_googlesql_public_simple_catalog_ASTDotGeneralizedField_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDotGeneralizedField_path
func export_googlesql_public_simple_catalog_ASTDotGeneralizedField_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDotIdentifier_expr
//go:linkname export_googlesql_public_simple_catalog_ASTDotIdentifier_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDotIdentifier_expr
func export_googlesql_public_simple_catalog_ASTDotIdentifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDotIdentifier_name
//go:linkname export_googlesql_public_simple_catalog_ASTDotIdentifier_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDotIdentifier_name
func export_googlesql_public_simple_catalog_ASTDotIdentifier_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDotStar_expr
//go:linkname export_googlesql_public_simple_catalog_ASTDotStar_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDotStar_expr
func export_googlesql_public_simple_catalog_ASTDotStar_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDotStarWithModifiers_expr
//go:linkname export_googlesql_public_simple_catalog_ASTDotStarWithModifiers_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDotStarWithModifiers_expr
func export_googlesql_public_simple_catalog_ASTDotStarWithModifiers_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDotStarWithModifiers_modifiers
//go:linkname export_googlesql_public_simple_catalog_ASTDotStarWithModifiers_modifiers github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDotStarWithModifiers_modifiers
func export_googlesql_public_simple_catalog_ASTDotStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExpressionSubquery_set_modifier
//go:linkname export_googlesql_public_simple_catalog_ASTExpressionSubquery_set_modifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExpressionSubquery_set_modifier
func export_googlesql_public_simple_catalog_ASTExpressionSubquery_set_modifier(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTExpressionSubquery_modifier
//go:linkname export_googlesql_public_simple_catalog_ASTExpressionSubquery_modifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExpressionSubquery_modifier
func export_googlesql_public_simple_catalog_ASTExpressionSubquery_modifier(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTExpressionSubquery_hint
//go:linkname export_googlesql_public_simple_catalog_ASTExpressionSubquery_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExpressionSubquery_hint
func export_googlesql_public_simple_catalog_ASTExpressionSubquery_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExpressionSubquery_query
//go:linkname export_googlesql_public_simple_catalog_ASTExpressionSubquery_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExpressionSubquery_query
func export_googlesql_public_simple_catalog_ASTExpressionSubquery_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExtractExpression_lhs_expr
//go:linkname export_googlesql_public_simple_catalog_ASTExtractExpression_lhs_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExtractExpression_lhs_expr
func export_googlesql_public_simple_catalog_ASTExtractExpression_lhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExtractExpression_rhs_expr
//go:linkname export_googlesql_public_simple_catalog_ASTExtractExpression_rhs_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExtractExpression_rhs_expr
func export_googlesql_public_simple_catalog_ASTExtractExpression_rhs_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExtractExpression_time_zone_expr
//go:linkname export_googlesql_public_simple_catalog_ASTExtractExpression_time_zone_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExtractExpression_time_zone_expr
func export_googlesql_public_simple_catalog_ASTExtractExpression_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHavingModifier_set_modifier_kind
//go:linkname export_googlesql_public_simple_catalog_ASTHavingModifier_set_modifier_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHavingModifier_set_modifier_kind
func export_googlesql_public_simple_catalog_ASTHavingModifier_set_modifier_kind(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTHavingModifier_modifier_kind
//go:linkname export_googlesql_public_simple_catalog_ASTHavingModifier_modifier_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHavingModifier_modifier_kind
func export_googlesql_public_simple_catalog_ASTHavingModifier_modifier_kind(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTHavingModifier_expr
//go:linkname export_googlesql_public_simple_catalog_ASTHavingModifier_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHavingModifier_expr
func export_googlesql_public_simple_catalog_ASTHavingModifier_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIntervalExpr_interval_value
//go:linkname export_googlesql_public_simple_catalog_ASTIntervalExpr_interval_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIntervalExpr_interval_value
func export_googlesql_public_simple_catalog_ASTIntervalExpr_interval_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIntervalExpr_date_part_name
//go:linkname export_googlesql_public_simple_catalog_ASTIntervalExpr_date_part_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIntervalExpr_date_part_name
func export_googlesql_public_simple_catalog_ASTIntervalExpr_date_part_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIntervalExpr_date_part_name_to
//go:linkname export_googlesql_public_simple_catalog_ASTIntervalExpr_date_part_name_to github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIntervalExpr_date_part_name_to
func export_googlesql_public_simple_catalog_ASTIntervalExpr_date_part_name_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNamedArgument_name
//go:linkname export_googlesql_public_simple_catalog_ASTNamedArgument_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNamedArgument_name
func export_googlesql_public_simple_catalog_ASTNamedArgument_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNamedArgument_expr
//go:linkname export_googlesql_public_simple_catalog_ASTNamedArgument_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNamedArgument_expr
func export_googlesql_public_simple_catalog_ASTNamedArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNullOrder_set_nulls_first
//go:linkname export_googlesql_public_simple_catalog_ASTNullOrder_set_nulls_first github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNullOrder_set_nulls_first
func export_googlesql_public_simple_catalog_ASTNullOrder_set_nulls_first(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTNullOrder_nulls_first
//go:linkname export_googlesql_public_simple_catalog_ASTNullOrder_nulls_first github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNullOrder_nulls_first
func export_googlesql_public_simple_catalog_ASTNullOrder_nulls_first(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTOnOrUsingClauseList_on_or_using_clause_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTOnOrUsingClauseList_on_or_using_clause_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOnOrUsingClauseList_on_or_using_clause_list_num
func export_googlesql_public_simple_catalog_ASTOnOrUsingClauseList_on_or_using_clause_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTOnUsingClauseList_on_or_using_clause_list
//go:linkname export_googlesql_public_simple_catalog_ASTOnUsingClauseList_on_or_using_clause_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOnUsingClauseList_on_or_using_clause_list
func export_googlesql_public_simple_catalog_ASTOnUsingClauseList_on_or_using_clause_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTParenthesizedJoin_join
//go:linkname export_googlesql_public_simple_catalog_ASTParenthesizedJoin_join github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTParenthesizedJoin_join
func export_googlesql_public_simple_catalog_ASTParenthesizedJoin_join(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTParenthesizedJoin_sample_clause
//go:linkname export_googlesql_public_simple_catalog_ASTParenthesizedJoin_sample_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTParenthesizedJoin_sample_clause
func export_googlesql_public_simple_catalog_ASTParenthesizedJoin_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPartitionBy_hint
//go:linkname export_googlesql_public_simple_catalog_ASTPartitionBy_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPartitionBy_hint
func export_googlesql_public_simple_catalog_ASTPartitionBy_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPartitionBy_partitioning_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTPartitionBy_partitioning_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPartitionBy_partitioning_expressions_num
func export_googlesql_public_simple_catalog_ASTPartitionBy_partitioning_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTPartitionBy_partitioning_expression
//go:linkname export_googlesql_public_simple_catalog_ASTPartitionBy_partitioning_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPartitionBy_partitioning_expression
func export_googlesql_public_simple_catalog_ASTPartitionBy_partitioning_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetOperation_set_op_type
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_set_op_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_set_op_type
func export_googlesql_public_simple_catalog_ASTSetOperation_set_op_type(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTSetOperation_op_type
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_op_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_op_type
func export_googlesql_public_simple_catalog_ASTSetOperation_op_type(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTSetOperation_set_distinct
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_set_distinct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_set_distinct
func export_googlesql_public_simple_catalog_ASTSetOperation_set_distinct(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTSetOperation_distinct
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_distinct github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_distinct
func export_googlesql_public_simple_catalog_ASTSetOperation_distinct(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTSetOperation_hint
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_hint
func export_googlesql_public_simple_catalog_ASTSetOperation_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetOperation_inputs_num
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_inputs_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_inputs_num
func export_googlesql_public_simple_catalog_ASTSetOperation_inputs_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTSetOperation_input
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_input github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_input
func export_googlesql_public_simple_catalog_ASTSetOperation_input(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetOperation_GetSQLForOperation
//go:linkname export_googlesql_public_simple_catalog_ASTSetOperation_GetSQLForOperation github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOperation_GetSQLForOperation
func export_googlesql_public_simple_catalog_ASTSetOperation_GetSQLForOperation(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStarExceptList_identifiers_num
//go:linkname export_googlesql_public_simple_catalog_ASTStarExceptList_identifiers_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarExceptList_identifiers_num
func export_googlesql_public_simple_catalog_ASTStarExceptList_identifiers_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTStarExpcetList_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTStarExpcetList_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarExpcetList_identifier
func export_googlesql_public_simple_catalog_ASTStarExpcetList_identifier(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStarModifiers_except_list
//go:linkname export_googlesql_public_simple_catalog_ASTStarModifiers_except_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarModifiers_except_list
func export_googlesql_public_simple_catalog_ASTStarModifiers_except_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStarModifiers_replace_items_num
//go:linkname export_googlesql_public_simple_catalog_ASTStarModifiers_replace_items_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarModifiers_replace_items_num
func export_googlesql_public_simple_catalog_ASTStarModifiers_replace_items_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTStarModifiers_replace_item
//go:linkname export_googlesql_public_simple_catalog_ASTStarModifiers_replace_item github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarModifiers_replace_item
func export_googlesql_public_simple_catalog_ASTStarModifiers_replace_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStarReplaceItem_expression
//go:linkname export_googlesql_public_simple_catalog_ASTStarReplaceItem_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarReplaceItem_expression
func export_googlesql_public_simple_catalog_ASTStarReplaceItem_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStarReplaceItem_alias
//go:linkname export_googlesql_public_simple_catalog_ASTStarReplaceItem_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarReplaceItem_alias
func export_googlesql_public_simple_catalog_ASTStarReplaceItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStarWithModifiers_modifiers
//go:linkname export_googlesql_public_simple_catalog_ASTStarWithModifiers_modifiers github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStarWithModifiers_modifiers
func export_googlesql_public_simple_catalog_ASTStarWithModifiers_modifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableSubquery_subquery
//go:linkname export_googlesql_public_simple_catalog_ASTTableSubquery_subquery github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableSubquery_subquery
func export_googlesql_public_simple_catalog_ASTTableSubquery_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableSubquery_pivot_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTableSubquery_pivot_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableSubquery_pivot_clause
func export_googlesql_public_simple_catalog_ASTTableSubquery_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableSubquery_unpivot_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTableSubquery_unpivot_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableSubquery_unpivot_clause
func export_googlesql_public_simple_catalog_ASTTableSubquery_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableSubquery_sample_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTableSubquery_sample_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableSubquery_sample_clause
func export_googlesql_public_simple_catalog_ASTTableSubquery_sample_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableSubquery_alias
//go:linkname export_googlesql_public_simple_catalog_ASTTableSubquery_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableSubquery_alias
func export_googlesql_public_simple_catalog_ASTTableSubquery_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnaryExpression_set_op
//go:linkname export_googlesql_public_simple_catalog_ASTUnaryExpression_set_op github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnaryExpression_set_op
func export_googlesql_public_simple_catalog_ASTUnaryExpression_set_op(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTUnaryExpression_op
//go:linkname export_googlesql_public_simple_catalog_ASTUnaryExpression_op github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnaryExpression_op
func export_googlesql_public_simple_catalog_ASTUnaryExpression_op(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTUnaryExpression_operand
//go:linkname export_googlesql_public_simple_catalog_ASTUnaryExpression_operand github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnaryExpression_operand
func export_googlesql_public_simple_catalog_ASTUnaryExpression_operand(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnaryExpression_GetSQLForOperator
//go:linkname export_googlesql_public_simple_catalog_ASTUnaryExpression_GetSQLForOperator github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnaryExpression_GetSQLForOperator
func export_googlesql_public_simple_catalog_ASTUnaryExpression_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnnestExpression_expression
//go:linkname export_googlesql_public_simple_catalog_ASTUnnestExpression_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnnestExpression_expression
func export_googlesql_public_simple_catalog_ASTUnnestExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowClause_windows_num
//go:linkname export_googlesql_public_simple_catalog_ASTWindowClause_windows_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowClause_windows_num
func export_googlesql_public_simple_catalog_ASTWindowClause_windows_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTWindowClause_window
//go:linkname export_googlesql_public_simple_catalog_ASTWindowClause_window github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowClause_window
func export_googlesql_public_simple_catalog_ASTWindowClause_window(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowDefinition_name
//go:linkname export_googlesql_public_simple_catalog_ASTWindowDefinition_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowDefinition_name
func export_googlesql_public_simple_catalog_ASTWindowDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowDefinition_window_spec
//go:linkname export_googlesql_public_simple_catalog_ASTWindowDefinition_window_spec github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowDefinition_window_spec
func export_googlesql_public_simple_catalog_ASTWindowDefinition_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowFrame_start_expr
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrame_start_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrame_start_expr
func export_googlesql_public_simple_catalog_ASTWindowFrame_start_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowFrame_end_expr
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrame_end_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrame_end_expr
func export_googlesql_public_simple_catalog_ASTWindowFrame_end_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowFrame_set_unit
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrame_set_unit github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrame_set_unit
func export_googlesql_public_simple_catalog_ASTWindowFrame_set_unit(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTWindowFrame_frame_unit
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrame_frame_unit github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrame_frame_unit
func export_googlesql_public_simple_catalog_ASTWindowFrame_frame_unit(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTWindowFrame_GetFrameUnitString
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrame_GetFrameUnitString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrame_GetFrameUnitString
func export_googlesql_public_simple_catalog_ASTWindowFrame_GetFrameUnitString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowFrameExpr_set_boundary_type
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrameExpr_set_boundary_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrameExpr_set_boundary_type
func export_googlesql_public_simple_catalog_ASTWindowFrameExpr_set_boundary_type(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTWindowFrameExpr_boundary_type
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrameExpr_boundary_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrameExpr_boundary_type
func export_googlesql_public_simple_catalog_ASTWindowFrameExpr_boundary_type(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTWindowFrameExpr_expression
//go:linkname export_googlesql_public_simple_catalog_ASTWindowFrameExpr_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowFrameExpr_expression
func export_googlesql_public_simple_catalog_ASTWindowFrameExpr_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_set_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_set_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_set_is_not
func export_googlesql_public_simple_catalog_ASTLikeExpression_set_is_not(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_is_not
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_is_not github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_is_not
func export_googlesql_public_simple_catalog_ASTLikeExpression_is_not(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_lhs
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_lhs github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_lhs
func export_googlesql_public_simple_catalog_ASTLikeExpression_lhs(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_op
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_op github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_op
func export_googlesql_public_simple_catalog_ASTLikeExpression_op(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_hint
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_hint
func export_googlesql_public_simple_catalog_ASTLikeExpression_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_in_list
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_in_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_in_list
func export_googlesql_public_simple_catalog_ASTLikeExpression_in_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_query
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_query
func export_googlesql_public_simple_catalog_ASTLikeExpression_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLikeExpression_unnest_expr
//go:linkname export_googlesql_public_simple_catalog_ASTLikeExpression_unnest_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLikeExpression_unnest_expr
func export_googlesql_public_simple_catalog_ASTLikeExpression_unnest_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowSpecification_base_window_name
//go:linkname export_googlesql_public_simple_catalog_ASTWindowSpecification_base_window_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowSpecification_base_window_name
func export_googlesql_public_simple_catalog_ASTWindowSpecification_base_window_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowSpecification_partition_by
//go:linkname export_googlesql_public_simple_catalog_ASTWindowSpecification_partition_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowSpecification_partition_by
func export_googlesql_public_simple_catalog_ASTWindowSpecification_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowSpecification_order_by
//go:linkname export_googlesql_public_simple_catalog_ASTWindowSpecification_order_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowSpecification_order_by
func export_googlesql_public_simple_catalog_ASTWindowSpecification_order_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWindowSpecification_window_frame
//go:linkname export_googlesql_public_simple_catalog_ASTWindowSpecification_window_frame github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWindowSpecification_window_frame
func export_googlesql_public_simple_catalog_ASTWindowSpecification_window_frame(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithOffset_alias
//go:linkname export_googlesql_public_simple_catalog_ASTWithOffset_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithOffset_alias
func export_googlesql_public_simple_catalog_ASTWithOffset_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAnySomeAllOp_set_op
//go:linkname export_googlesql_public_simple_catalog_ASTAnySomeAllOp_set_op github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnySomeAllOp_set_op
func export_googlesql_public_simple_catalog_ASTAnySomeAllOp_set_op(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAnySomeAllOp_op
//go:linkname export_googlesql_public_simple_catalog_ASTAnySomeAllOp_op github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnySomeAllOp_op
func export_googlesql_public_simple_catalog_ASTAnySomeAllOp_op(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTAnySomeAllOp_GetSQLForOperator
//go:linkname export_googlesql_public_simple_catalog_ASTAnySomeAllOp_GetSQLForOperator github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnySomeAllOp_GetSQLForOperator
func export_googlesql_public_simple_catalog_ASTAnySomeAllOp_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStatementList_set_variable_declarations_allowed
//go:linkname export_googlesql_public_simple_catalog_ASTStatementList_set_variable_declarations_allowed github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStatementList_set_variable_declarations_allowed
func export_googlesql_public_simple_catalog_ASTStatementList_set_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTStatementList_variable_declarations_allowed
//go:linkname export_googlesql_public_simple_catalog_ASTStatementList_variable_declarations_allowed github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStatementList_variable_declarations_allowed
func export_googlesql_public_simple_catalog_ASTStatementList_variable_declarations_allowed(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTStatementList_statement_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTStatementList_statement_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStatementList_statement_list_num
func export_googlesql_public_simple_catalog_ASTStatementList_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTStatementList_statement_list
//go:linkname export_googlesql_public_simple_catalog_ASTStatementList_statement_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStatementList_statement_list
func export_googlesql_public_simple_catalog_ASTStatementList_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHintedStatement_hint
//go:linkname export_googlesql_public_simple_catalog_ASTHintedStatement_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHintedStatement_hint
func export_googlesql_public_simple_catalog_ASTHintedStatement_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHintedStatement_statement
//go:linkname export_googlesql_public_simple_catalog_ASTHintedStatement_statement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHintedStatement_statement
func export_googlesql_public_simple_catalog_ASTHintedStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExplainStatement_statement
//go:linkname export_googlesql_public_simple_catalog_ASTExplainStatement_statement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExplainStatement_statement
func export_googlesql_public_simple_catalog_ASTExplainStatement_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDescribeStatement_optional_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTDescribeStatement_optional_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDescribeStatement_optional_identifier
func export_googlesql_public_simple_catalog_ASTDescribeStatement_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDescribeStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDescribeStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDescribeStatement_name
func export_googlesql_public_simple_catalog_ASTDescribeStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDescribeStatement_optional_from_name
//go:linkname export_googlesql_public_simple_catalog_ASTDescribeStatement_optional_from_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDescribeStatement_optional_from_name
func export_googlesql_public_simple_catalog_ASTDescribeStatement_optional_from_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTShowStatement_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTShowStatement_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTShowStatement_identifier
func export_googlesql_public_simple_catalog_ASTShowStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTShowStatement_optional_name
//go:linkname export_googlesql_public_simple_catalog_ASTShowStatement_optional_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTShowStatement_optional_name
func export_googlesql_public_simple_catalog_ASTShowStatement_optional_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTShowStatement_optional_like_string
//go:linkname export_googlesql_public_simple_catalog_ASTShowStatement_optional_like_string github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTShowStatement_optional_like_string
func export_googlesql_public_simple_catalog_ASTShowStatement_optional_like_string(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTransactionIsolationLevel_identifier1
//go:linkname export_googlesql_public_simple_catalog_ASTTransactionIsolationLevel_identifier1 github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTransactionIsolationLevel_identifier1
func export_googlesql_public_simple_catalog_ASTTransactionIsolationLevel_identifier1(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTransactionIsolationLevel_identifier2
//go:linkname export_googlesql_public_simple_catalog_ASTTransactionIsolationLevel_identifier2 github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTransactionIsolationLevel_identifier2
func export_googlesql_public_simple_catalog_ASTTransactionIsolationLevel_identifier2(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTransactionReadWriteMode_set_mode
//go:linkname export_googlesql_public_simple_catalog_ASTTransactionReadWriteMode_set_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTransactionReadWriteMode_set_mode
func export_googlesql_public_simple_catalog_ASTTransactionReadWriteMode_set_mode(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTTransactionReadWriteMode_mode
//go:linkname export_googlesql_public_simple_catalog_ASTTransactionReadWriteMode_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTransactionReadWriteMode_mode
func export_googlesql_public_simple_catalog_ASTTransactionReadWriteMode_mode(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTTransactionModeList_elements_num
//go:linkname export_googlesql_public_simple_catalog_ASTTransactionModeList_elements_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTransactionModeList_elements_num
func export_googlesql_public_simple_catalog_ASTTransactionModeList_elements_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTTransactionModeList_element
//go:linkname export_googlesql_public_simple_catalog_ASTTransactionModeList_element github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTransactionModeList_element
func export_googlesql_public_simple_catalog_ASTTransactionModeList_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBeginStatement_mode_list
//go:linkname export_googlesql_public_simple_catalog_ASTBeginStatement_mode_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBeginStatement_mode_list
func export_googlesql_public_simple_catalog_ASTBeginStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetTransactionStatement_mode_list
//go:linkname export_googlesql_public_simple_catalog_ASTSetTransactionStatement_mode_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetTransactionStatement_mode_list
func export_googlesql_public_simple_catalog_ASTSetTransactionStatement_mode_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStartBatchStatement_batch_type
//go:linkname export_googlesql_public_simple_catalog_ASTStartBatchStatement_batch_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStartBatchStatement_batch_type
func export_googlesql_public_simple_catalog_ASTStartBatchStatement_batch_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDdlStatement_GetDdlTarget
//go:linkname export_googlesql_public_simple_catalog_ASTDdlStatement_GetDdlTarget github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDdlStatement_GetDdlTarget
func export_googlesql_public_simple_catalog_ASTDdlStatement_GetDdlTarget(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropEntityStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropEntityStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropEntityStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropEntityStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropEntityStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropEntityStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropEntityStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropEntityStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropEntityStatement_entity_type
//go:linkname export_googlesql_public_simple_catalog_ASTDropEntityStatement_entity_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropEntityStatement_entity_type
func export_googlesql_public_simple_catalog_ASTDropEntityStatement_entity_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropEntityStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropEntityStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropEntityStatement_name
func export_googlesql_public_simple_catalog_ASTDropEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropFunctionStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropFunctionStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropFunctionStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropFunctionStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropFunctionStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropFunctionStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropFunctionStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropFunctionStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropFunctionStatement_name
func export_googlesql_public_simple_catalog_ASTDropFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropFunctionStatement_parameters
//go:linkname export_googlesql_public_simple_catalog_ASTDropFunctionStatement_parameters github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropFunctionStatement_parameters
func export_googlesql_public_simple_catalog_ASTDropFunctionStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropTableFunctionStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropTableFunctionStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropTableFunctionStatement_name
func export_googlesql_public_simple_catalog_ASTDropTableFunctionStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword
func export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_has_access_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_has_access_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropAllRowAccessPoliciesStatement_has_access_keyword
func export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_table_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_table_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropAllRowAccessPoliciesStatement_table_name
func export_googlesql_public_simple_catalog_ASTDropAllRowAccessPoliciesStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropMaterializedViewStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropMaterializedViewStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropMaterializedViewStatement_name
func export_googlesql_public_simple_catalog_ASTDropMaterializedViewStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropSnapshotTableStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropSnapshotTableStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropSnapshotTableStatement_name
func export_googlesql_public_simple_catalog_ASTDropSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropSearchIndexStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropSearchIndexStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropSearchIndexStatement_name
func export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_table_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_table_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropSearchIndexStatement_table_name
func export_googlesql_public_simple_catalog_ASTDropSearchIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRenameStatement_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTRenameStatement_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameStatement_identifier
func export_googlesql_public_simple_catalog_ASTRenameStatement_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRenameStatement_old_name
//go:linkname export_googlesql_public_simple_catalog_ASTRenameStatement_old_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameStatement_old_name
func export_googlesql_public_simple_catalog_ASTRenameStatement_old_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRenameStatement_new_name
//go:linkname export_googlesql_public_simple_catalog_ASTRenameStatement_new_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameStatement_new_name
func export_googlesql_public_simple_catalog_ASTRenameStatement_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTImportStatement_set_import_kind
//go:linkname export_googlesql_public_simple_catalog_ASTImportStatement_set_import_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTImportStatement_set_import_kind
func export_googlesql_public_simple_catalog_ASTImportStatement_set_import_kind(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTImportStatement_import_kind
//go:linkname export_googlesql_public_simple_catalog_ASTImportStatement_import_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTImportStatement_import_kind
func export_googlesql_public_simple_catalog_ASTImportStatement_import_kind(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTImportStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTImportStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTImportStatement_name
func export_googlesql_public_simple_catalog_ASTImportStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTImportStatement_string_value
//go:linkname export_googlesql_public_simple_catalog_ASTImportStatement_string_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTImportStatement_string_value
func export_googlesql_public_simple_catalog_ASTImportStatement_string_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTImportStatement_alias
//go:linkname export_googlesql_public_simple_catalog_ASTImportStatement_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTImportStatement_alias
func export_googlesql_public_simple_catalog_ASTImportStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTImportStatement_into_alias
//go:linkname export_googlesql_public_simple_catalog_ASTImportStatement_into_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTImportStatement_into_alias
func export_googlesql_public_simple_catalog_ASTImportStatement_into_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTImportStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTImportStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTImportStatement_options_list
func export_googlesql_public_simple_catalog_ASTImportStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTModuleStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTModuleStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTModuleStatement_name
func export_googlesql_public_simple_catalog_ASTModuleStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTModuleStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTModuleStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTModuleStatement_options_list
func export_googlesql_public_simple_catalog_ASTModuleStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithConnectionClause_connection_clause
//go:linkname export_googlesql_public_simple_catalog_ASTWithConnectionClause_connection_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithConnectionClause_connection_clause
func export_googlesql_public_simple_catalog_ASTWithConnectionClause_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIntoAlias_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTIntoAlias_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIntoAlias_identifier
func export_googlesql_public_simple_catalog_ASTIntoAlias_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIntoAlias_GetAsString
//go:linkname export_googlesql_public_simple_catalog_ASTIntoAlias_GetAsString github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIntoAlias_GetAsString
func export_googlesql_public_simple_catalog_ASTIntoAlias_GetAsString(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression
//go:linkname export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression
func export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_unnest_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias
//go:linkname export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias
func export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_optional_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset
//go:linkname export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset
func export_googlesql_public_simple_catalog_ASTUnnestExpressionWithOptAliasAndOffset_optional_with_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotExpression_expression
//go:linkname export_googlesql_public_simple_catalog_ASTPivotExpression_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotExpression_expression
func export_googlesql_public_simple_catalog_ASTPivotExpression_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotExpression_alias
//go:linkname export_googlesql_public_simple_catalog_ASTPivotExpression_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotExpression_alias
func export_googlesql_public_simple_catalog_ASTPivotExpression_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotValue_value
//go:linkname export_googlesql_public_simple_catalog_ASTPivotValue_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotValue_value
func export_googlesql_public_simple_catalog_ASTPivotValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotValue_alias
//go:linkname export_googlesql_public_simple_catalog_ASTPivotValue_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotValue_alias
func export_googlesql_public_simple_catalog_ASTPivotValue_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotExpressionList_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTPivotExpressionList_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotExpressionList_expressions_num
func export_googlesql_public_simple_catalog_ASTPivotExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTPivotExpressionList_expression
//go:linkname export_googlesql_public_simple_catalog_ASTPivotExpressionList_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotExpressionList_expression
func export_googlesql_public_simple_catalog_ASTPivotExpressionList_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotValueList_values_num
//go:linkname export_googlesql_public_simple_catalog_ASTPivotValueList_values_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotValueList_values_num
func export_googlesql_public_simple_catalog_ASTPivotValueList_values_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTPivotValueList_value
//go:linkname export_googlesql_public_simple_catalog_ASTPivotValueList_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotValueList_value
func export_googlesql_public_simple_catalog_ASTPivotValueList_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotClause_pivot_expressions
//go:linkname export_googlesql_public_simple_catalog_ASTPivotClause_pivot_expressions github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotClause_pivot_expressions
func export_googlesql_public_simple_catalog_ASTPivotClause_pivot_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotClause_for_expression
//go:linkname export_googlesql_public_simple_catalog_ASTPivotClause_for_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotClause_for_expression
func export_googlesql_public_simple_catalog_ASTPivotClause_for_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotClause_pivot_values
//go:linkname export_googlesql_public_simple_catalog_ASTPivotClause_pivot_values github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotClause_pivot_values
func export_googlesql_public_simple_catalog_ASTPivotClause_pivot_values(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPivotClause_output_alias
//go:linkname export_googlesql_public_simple_catalog_ASTPivotClause_output_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPivotClause_output_alias
func export_googlesql_public_simple_catalog_ASTPivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotInItem_unpivot_columns
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotInItem_unpivot_columns github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotInItem_unpivot_columns
func export_googlesql_public_simple_catalog_ASTUnpivotInItem_unpivot_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotInItem_alias
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotInItem_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotInItem_alias
func export_googlesql_public_simple_catalog_ASTUnpivotInItem_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotInItemList_in_items_num
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotInItemList_in_items_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotInItemList_in_items_num
func export_googlesql_public_simple_catalog_ASTUnpivotInItemList_in_items_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTUnpivotInItemList_in_item
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotInItemList_in_item github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotInItemList_in_item
func export_googlesql_public_simple_catalog_ASTUnpivotInItemList_in_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotClause_set_null_filter
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotClause_set_null_filter github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotClause_set_null_filter
func export_googlesql_public_simple_catalog_ASTUnpivotClause_set_null_filter(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTUnpivotClause_null_filter
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotClause_null_filter github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotClause_null_filter
func export_googlesql_public_simple_catalog_ASTUnpivotClause_null_filter(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_output_value_columns
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_output_value_columns github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotClause_unpivot_output_value_columns
func export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_output_value_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_output_name_column
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_output_name_column github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotClause_unpivot_output_name_column
func export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_output_name_column(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_in_items
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_in_items github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotClause_unpivot_in_items
func export_googlesql_public_simple_catalog_ASTUnpivotClause_unpivot_in_items(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotClause_output_alias
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotClause_output_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotClause_output_alias
func export_googlesql_public_simple_catalog_ASTUnpivotClause_output_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUsingClause_keys_num
//go:linkname export_googlesql_public_simple_catalog_ASTUsingClause_keys_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUsingClause_keys_num
func export_googlesql_public_simple_catalog_ASTUsingClause_keys_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTUsingClause_key
//go:linkname export_googlesql_public_simple_catalog_ASTUsingClause_key github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUsingClause_key
func export_googlesql_public_simple_catalog_ASTUsingClause_key(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForSystemTime_expression
//go:linkname export_googlesql_public_simple_catalog_ASTForSystemTime_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForSystemTime_expression
func export_googlesql_public_simple_catalog_ASTForSystemTime_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTQualify_expression
//go:linkname export_googlesql_public_simple_catalog_ASTQualify_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTQualify_expression
func export_googlesql_public_simple_catalog_ASTQualify_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTClampedBetweenModifier_low
//go:linkname export_googlesql_public_simple_catalog_ASTClampedBetweenModifier_low github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTClampedBetweenModifier_low
func export_googlesql_public_simple_catalog_ASTClampedBetweenModifier_low(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTClampedBetweenModifier_high
//go:linkname export_googlesql_public_simple_catalog_ASTClampedBetweenModifier_high github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTClampedBetweenModifier_high
func export_googlesql_public_simple_catalog_ASTClampedBetweenModifier_high(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFormatClause_format
//go:linkname export_googlesql_public_simple_catalog_ASTFormatClause_format github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFormatClause_format
func export_googlesql_public_simple_catalog_ASTFormatClause_format(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFormatClause_time_zone_expr
//go:linkname export_googlesql_public_simple_catalog_ASTFormatClause_time_zone_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFormatClause_time_zone_expr
func export_googlesql_public_simple_catalog_ASTFormatClause_time_zone_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPathExpressionList_path_expression_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTPathExpressionList_path_expression_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPathExpressionList_path_expression_list_num
func export_googlesql_public_simple_catalog_ASTPathExpressionList_path_expression_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTPathExpressionList_path_expression_list
//go:linkname export_googlesql_public_simple_catalog_ASTPathExpressionList_path_expression_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPathExpressionList_path_expression_list
func export_googlesql_public_simple_catalog_ASTPathExpressionList_path_expression_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTParameterExpr_set_position
//go:linkname export_googlesql_public_simple_catalog_ASTParameterExpr_set_position github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTParameterExpr_set_position
func export_googlesql_public_simple_catalog_ASTParameterExpr_set_position(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTParameterExpr_position
//go:linkname export_googlesql_public_simple_catalog_ASTParameterExpr_position github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTParameterExpr_position
func export_googlesql_public_simple_catalog_ASTParameterExpr_position(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTParameterExpr_name
//go:linkname export_googlesql_public_simple_catalog_ASTParameterExpr_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTParameterExpr_name
func export_googlesql_public_simple_catalog_ASTParameterExpr_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSystemVariableExpr_path
//go:linkname export_googlesql_public_simple_catalog_ASTSystemVariableExpr_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSystemVariableExpr_path
func export_googlesql_public_simple_catalog_ASTSystemVariableExpr_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithGroupRows_subquery
//go:linkname export_googlesql_public_simple_catalog_ASTWithGroupRows_subquery github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithGroupRows_subquery
func export_googlesql_public_simple_catalog_ASTWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLambda_argument_list
//go:linkname export_googlesql_public_simple_catalog_ASTLambda_argument_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLambda_argument_list
func export_googlesql_public_simple_catalog_ASTLambda_argument_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLambda_body
//go:linkname export_googlesql_public_simple_catalog_ASTLambda_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLambda_body
func export_googlesql_public_simple_catalog_ASTLambda_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_window_spec
//go:linkname export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_window_spec github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnalyticFunctionCall_window_spec
func export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_window_spec(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_function
//go:linkname export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_function github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnalyticFunctionCall_function
func export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_function_with_group_rows
//go:linkname export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_function_with_group_rows github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnalyticFunctionCall_function_with_group_rows
func export_googlesql_public_simple_catalog_ASTAnalyticFunctionCall_function_with_group_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCallWithGroupRows_function
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCallWithGroupRows_function github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCallWithGroupRows_function
func export_googlesql_public_simple_catalog_ASTFunctionCallWithGroupRows_function(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionCallWithGroupRows_subquery
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionCallWithGroupRows_subquery github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionCallWithGroupRows_subquery
func export_googlesql_public_simple_catalog_ASTFunctionCallWithGroupRows_subquery(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTClusterBy_clustering_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTClusterBy_clustering_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTClusterBy_clustering_expressions_num
func export_googlesql_public_simple_catalog_ASTClusterBy_clustering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTClusterBy_clustering_expression
//go:linkname export_googlesql_public_simple_catalog_ASTClusterBy_clustering_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTClusterBy_clustering_expression
func export_googlesql_public_simple_catalog_ASTClusterBy_clustering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNewConstructorArg_expression
//go:linkname export_googlesql_public_simple_catalog_ASTNewConstructorArg_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNewConstructorArg_expression
func export_googlesql_public_simple_catalog_ASTNewConstructorArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNewConstructorArg_optional_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTNewConstructorArg_optional_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNewConstructorArg_optional_identifier
func export_googlesql_public_simple_catalog_ASTNewConstructorArg_optional_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNewConstructorArg_optional_path_expression
//go:linkname export_googlesql_public_simple_catalog_ASTNewConstructorArg_optional_path_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNewConstructorArg_optional_path_expression
func export_googlesql_public_simple_catalog_ASTNewConstructorArg_optional_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNewConstructor_type_name
//go:linkname export_googlesql_public_simple_catalog_ASTNewConstructor_type_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNewConstructor_type_name
func export_googlesql_public_simple_catalog_ASTNewConstructor_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTNewConstructor_arguments_num
//go:linkname export_googlesql_public_simple_catalog_ASTNewConstructor_arguments_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNewConstructor_arguments_num
func export_googlesql_public_simple_catalog_ASTNewConstructor_arguments_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTNewConstructor_argument
//go:linkname export_googlesql_public_simple_catalog_ASTNewConstructor_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTNewConstructor_argument
func export_googlesql_public_simple_catalog_ASTNewConstructor_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOptionsList_options_entries_num
//go:linkname export_googlesql_public_simple_catalog_ASTOptionsList_options_entries_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOptionsList_options_entries_num
func export_googlesql_public_simple_catalog_ASTOptionsList_options_entries_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTOptionsList_options_entry
//go:linkname export_googlesql_public_simple_catalog_ASTOptionsList_options_entry github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOptionsList_options_entry
func export_googlesql_public_simple_catalog_ASTOptionsList_options_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOptionsEntry_name
//go:linkname export_googlesql_public_simple_catalog_ASTOptionsEntry_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOptionsEntry_name
func export_googlesql_public_simple_catalog_ASTOptionsEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTOptionsEntry_value
//go:linkname export_googlesql_public_simple_catalog_ASTOptionsEntry_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTOptionsEntry_value
func export_googlesql_public_simple_catalog_ASTOptionsEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_set_scope
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_set_scope github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_set_scope
func export_googlesql_public_simple_catalog_ASTCreateStatement_set_scope(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_scope
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_scope github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_scope
func export_googlesql_public_simple_catalog_ASTCreateStatement_scope(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_set_is_or_replace
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_set_is_or_replace github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_set_is_or_replace
func export_googlesql_public_simple_catalog_ASTCreateStatement_set_is_or_replace(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_is_or_replace
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_is_or_replace github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_is_or_replace
func export_googlesql_public_simple_catalog_ASTCreateStatement_is_or_replace(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_set_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_set_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_set_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTCreateStatement_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTCreateStatement_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_is_default_scope
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_is_default_scope github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_is_default_scope
func export_googlesql_public_simple_catalog_ASTCreateStatement_is_default_scope(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_is_private
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_is_private github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_is_private
func export_googlesql_public_simple_catalog_ASTCreateStatement_is_private(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_is_public
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_is_public github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_is_public
func export_googlesql_public_simple_catalog_ASTCreateStatement_is_public(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateStatement_is_temp
//go:linkname export_googlesql_public_simple_catalog_ASTCreateStatement_is_temp github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateStatement_is_temp
func export_googlesql_public_simple_catalog_ASTCreateStatement_is_temp(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_set_procedure_parameter_mode
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_set_procedure_parameter_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_set_procedure_parameter_mode
func export_googlesql_public_simple_catalog_ASTFunctionParameter_set_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_procedure_parameter_mode
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_procedure_parameter_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_procedure_parameter_mode
func export_googlesql_public_simple_catalog_ASTFunctionParameter_procedure_parameter_mode(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_set_is_not_aggregate
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_set_is_not_aggregate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_set_is_not_aggregate
func export_googlesql_public_simple_catalog_ASTFunctionParameter_set_is_not_aggregate(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_is_not_aggregate
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_is_not_aggregate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_is_not_aggregate
func export_googlesql_public_simple_catalog_ASTFunctionParameter_is_not_aggregate(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_name
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_name
func export_googlesql_public_simple_catalog_ASTFunctionParameter_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_type
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_type
func export_googlesql_public_simple_catalog_ASTFunctionParameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_templated_parameter_type
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_templated_parameter_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_templated_parameter_type
func export_googlesql_public_simple_catalog_ASTFunctionParameter_templated_parameter_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_tvf_schema
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_tvf_schema github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_tvf_schema
func export_googlesql_public_simple_catalog_ASTFunctionParameter_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_alias
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_alias
func export_googlesql_public_simple_catalog_ASTFunctionParameter_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_default_value
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_default_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_default_value
func export_googlesql_public_simple_catalog_ASTFunctionParameter_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_IsTableParameter
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_IsTableParameter github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_IsTableParameter
func export_googlesql_public_simple_catalog_ASTFunctionParameter_IsTableParameter(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTFunctionParameter_IsTemplated
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameter_IsTemplated github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameter_IsTemplated
func export_googlesql_public_simple_catalog_ASTFunctionParameter_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTFunctionParameters_parameter_entries_num
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameters_parameter_entries_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameters_parameter_entries_num
func export_googlesql_public_simple_catalog_ASTFunctionParameters_parameter_entries_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTFunctionParameters_parameter_entry
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionParameters_parameter_entry github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionParameters_parameter_entry
func export_googlesql_public_simple_catalog_ASTFunctionParameters_parameter_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionDeclaration_name
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionDeclaration_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionDeclaration_name
func export_googlesql_public_simple_catalog_ASTFunctionDeclaration_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionDeclaration_parameters
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionDeclaration_parameters github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionDeclaration_parameters
func export_googlesql_public_simple_catalog_ASTFunctionDeclaration_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFunctionDeclaration_IsTemplated
//go:linkname export_googlesql_public_simple_catalog_ASTFunctionDeclaration_IsTemplated github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFunctionDeclaration_IsTemplated
func export_googlesql_public_simple_catalog_ASTFunctionDeclaration_IsTemplated(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTSqlFunctionBody_expression
//go:linkname export_googlesql_public_simple_catalog_ASTSqlFunctionBody_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSqlFunctionBody_expression
func export_googlesql_public_simple_catalog_ASTSqlFunctionBody_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFArgument_expr
//go:linkname export_googlesql_public_simple_catalog_ASTTVFArgument_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFArgument_expr
func export_googlesql_public_simple_catalog_ASTTVFArgument_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFArgument_table_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTVFArgument_table_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFArgument_table_clause
func export_googlesql_public_simple_catalog_ASTTVFArgument_table_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFArgument_model_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTVFArgument_model_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFArgument_model_clause
func export_googlesql_public_simple_catalog_ASTTVFArgument_model_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFArgument_connection_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTVFArgument_connection_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFArgument_connection_clause
func export_googlesql_public_simple_catalog_ASTTVFArgument_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFArgument_descriptor
//go:linkname export_googlesql_public_simple_catalog_ASTTVFArgument_descriptor github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFArgument_descriptor
func export_googlesql_public_simple_catalog_ASTTVFArgument_descriptor(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVF_name
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_name
func export_googlesql_public_simple_catalog_ASTTVF_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVF_hint
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_hint
func export_googlesql_public_simple_catalog_ASTTVF_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVF_alias
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_alias
func export_googlesql_public_simple_catalog_ASTTVF_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVF_pivot_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_pivot_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_pivot_clause
func export_googlesql_public_simple_catalog_ASTTVF_pivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVF_unpivot_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_unpivot_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_unpivot_clause
func export_googlesql_public_simple_catalog_ASTTVF_unpivot_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVF_sample
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_sample github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_sample
func export_googlesql_public_simple_catalog_ASTTVF_sample(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVF_argument_entries_num
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_argument_entries_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_argument_entries_num
func export_googlesql_public_simple_catalog_ASTTVF_argument_entries_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTTVF_argument_entry
//go:linkname export_googlesql_public_simple_catalog_ASTTVF_argument_entry github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVF_argument_entry
func export_googlesql_public_simple_catalog_ASTTVF_argument_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableClause_table_path
//go:linkname export_googlesql_public_simple_catalog_ASTTableClause_table_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableClause_table_path
func export_googlesql_public_simple_catalog_ASTTableClause_table_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableClause_tvf
//go:linkname export_googlesql_public_simple_catalog_ASTTableClause_tvf github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableClause_tvf
func export_googlesql_public_simple_catalog_ASTTableClause_tvf(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTModelClause_model_path
//go:linkname export_googlesql_public_simple_catalog_ASTModelClause_model_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTModelClause_model_path
func export_googlesql_public_simple_catalog_ASTModelClause_model_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTConnectionClause_connection_path
//go:linkname export_googlesql_public_simple_catalog_ASTConnectionClause_connection_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTConnectionClause_connection_path
func export_googlesql_public_simple_catalog_ASTConnectionClause_connection_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableDataSource_path_expr
//go:linkname export_googlesql_public_simple_catalog_ASTTableDataSource_path_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableDataSource_path_expr
func export_googlesql_public_simple_catalog_ASTTableDataSource_path_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableDataSource_for_system_time
//go:linkname export_googlesql_public_simple_catalog_ASTTableDataSource_for_system_time github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableDataSource_for_system_time
func export_googlesql_public_simple_catalog_ASTTableDataSource_for_system_time(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableDataSource_where_clause
//go:linkname export_googlesql_public_simple_catalog_ASTTableDataSource_where_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableDataSource_where_clause
func export_googlesql_public_simple_catalog_ASTTableDataSource_where_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCloneDataSourceList_data_sources_num
//go:linkname export_googlesql_public_simple_catalog_ASTCloneDataSourceList_data_sources_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCloneDataSourceList_data_sources_num
func export_googlesql_public_simple_catalog_ASTCloneDataSourceList_data_sources_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTCloneDataSourceList_data_source
//go:linkname export_googlesql_public_simple_catalog_ASTCloneDataSourceList_data_source github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCloneDataSourceList_data_source
func export_googlesql_public_simple_catalog_ASTCloneDataSourceList_data_source(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCloneDataStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTCloneDataStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCloneDataStatement_target_path
func export_googlesql_public_simple_catalog_ASTCloneDataStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCloneDataStatement_data_source_list
//go:linkname export_googlesql_public_simple_catalog_ASTCloneDataStatement_data_source_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCloneDataStatement_data_source_list
func export_googlesql_public_simple_catalog_ASTCloneDataStatement_data_source_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateConstantStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateConstantStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateConstantStatement_name
func export_googlesql_public_simple_catalog_ASTCreateConstantStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateConstantStatement_expr
//go:linkname export_googlesql_public_simple_catalog_ASTCreateConstantStatement_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateConstantStatement_expr
func export_googlesql_public_simple_catalog_ASTCreateConstantStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateDatabaseStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateDatabaseStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateDatabaseStatement_name
func export_googlesql_public_simple_catalog_ASTCreateDatabaseStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateDatabaseStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateDatabaseStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateDatabaseStatement_options_list
func export_googlesql_public_simple_catalog_ASTCreateDatabaseStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateProcedureStatement_name
func export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_parameters
//go:linkname export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_parameters github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateProcedureStatement_parameters
func export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateProcedureStatement_options_list
func export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_body
//go:linkname export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateProcedureStatement_body
func export_googlesql_public_simple_catalog_ASTCreateProcedureStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateSchemaStatement_name
func export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_collate
//go:linkname export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_collate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateSchemaStatement_collate
func export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateSchemaStatement_options_list
func export_googlesql_public_simple_catalog_ASTCreateSchemaStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTransformClause_select_list
//go:linkname export_googlesql_public_simple_catalog_ASTTransformClause_select_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTransformClause_select_list
func export_googlesql_public_simple_catalog_ASTTransformClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateModelStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateModelStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateModelStatement_name
func export_googlesql_public_simple_catalog_ASTCreateModelStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateModelStatement_transform_clause
//go:linkname export_googlesql_public_simple_catalog_ASTCreateModelStatement_transform_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateModelStatement_transform_clause
func export_googlesql_public_simple_catalog_ASTCreateModelStatement_transform_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateModelStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateModelStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateModelStatement_options_list
func export_googlesql_public_simple_catalog_ASTCreateModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateModelStatement_query
//go:linkname export_googlesql_public_simple_catalog_ASTCreateModelStatement_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateModelStatement_query
func export_googlesql_public_simple_catalog_ASTCreateModelStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIndexItemList_ordering_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTIndexItemList_ordering_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIndexItemList_ordering_expressions_num
func export_googlesql_public_simple_catalog_ASTIndexItemList_ordering_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTIndexItemList_ordering_expression
//go:linkname export_googlesql_public_simple_catalog_ASTIndexItemList_ordering_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIndexItemList_ordering_expression
func export_googlesql_public_simple_catalog_ASTIndexItemList_ordering_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIndexStoringExpressionList_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTIndexStoringExpressionList_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIndexStoringExpressionList_expressions_num
func export_googlesql_public_simple_catalog_ASTIndexStoringExpressionList_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTIndexStoringExpressionList_expression
//go:linkname export_googlesql_public_simple_catalog_ASTIndexStoringExpressionList_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIndexStoringExpressionList_expression
func export_googlesql_public_simple_catalog_ASTIndexStoringExpressionList_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIndexUnnestExpressionList_unnest_expressions_num
//go:linkname export_googlesql_public_simple_catalog_ASTIndexUnnestExpressionList_unnest_expressions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIndexUnnestExpressionList_unnest_expressions_num
func export_googlesql_public_simple_catalog_ASTIndexUnnestExpressionList_unnest_expressions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTIndexUnnestExpressionList_unnest_expression
//go:linkname export_googlesql_public_simple_catalog_ASTIndexUnnestExpressionList_unnest_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIndexUnnestExpressionList_unnest_expression
func export_googlesql_public_simple_catalog_ASTIndexUnnestExpressionList_unnest_expression(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_set_is_unique
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_set_is_unique github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_set_is_unique
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_set_is_unique(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_is_unique
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_is_unique github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_is_unique
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_is_unique(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_set_is_search
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_set_is_search github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_set_is_search
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_set_is_search(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_is_search
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_is_search github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_is_search
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_is_search(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_name
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_table_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_table_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_table_name
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_table_alias
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_table_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_optional_table_alias
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_table_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_index_unnest_expression_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_index_unnest_expression_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_optional_index_unnest_expression_list
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_index_unnest_expression_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_index_item_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_index_item_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_index_item_list
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_index_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_index_storing_expressions
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_index_storing_expressions github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_optional_index_storing_expressions
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_optional_index_storing_expressions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateIndexStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateIndexStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateIndexStatement_options_list
func export_googlesql_public_simple_catalog_ASTCreateIndexStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExportDataStatement_with_connection_clause
//go:linkname export_googlesql_public_simple_catalog_ASTExportDataStatement_with_connection_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExportDataStatement_with_connection_clause
func export_googlesql_public_simple_catalog_ASTExportDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExportDataStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTExportDataStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExportDataStatement_options_list
func export_googlesql_public_simple_catalog_ASTExportDataStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExportDataStatement_query
//go:linkname export_googlesql_public_simple_catalog_ASTExportDataStatement_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExportDataStatement_query
func export_googlesql_public_simple_catalog_ASTExportDataStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExportModelStatement_model_name_path
//go:linkname export_googlesql_public_simple_catalog_ASTExportModelStatement_model_name_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExportModelStatement_model_name_path
func export_googlesql_public_simple_catalog_ASTExportModelStatement_model_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExportModelStatement_with_connection_clause
//go:linkname export_googlesql_public_simple_catalog_ASTExportModelStatement_with_connection_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExportModelStatement_with_connection_clause
func export_googlesql_public_simple_catalog_ASTExportModelStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExportModelStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTExportModelStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExportModelStatement_options_list
func export_googlesql_public_simple_catalog_ASTExportModelStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCallStatement_procedure_name
//go:linkname export_googlesql_public_simple_catalog_ASTCallStatement_procedure_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCallStatement_procedure_name
func export_googlesql_public_simple_catalog_ASTCallStatement_procedure_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCallStatement_arguments_num
//go:linkname export_googlesql_public_simple_catalog_ASTCallStatement_arguments_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCallStatement_arguments_num
func export_googlesql_public_simple_catalog_ASTCallStatement_arguments_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTCallStatement_argument
//go:linkname export_googlesql_public_simple_catalog_ASTCallStatement_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCallStatement_argument
func export_googlesql_public_simple_catalog_ASTCallStatement_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDefineTableStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDefineTableStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDefineTableStatement_name
func export_googlesql_public_simple_catalog_ASTDefineTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDefineTableStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTDefineTableStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDefineTableStatement_options_list
func export_googlesql_public_simple_catalog_ASTDefineTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithPartitionColumnsClause_table_element_list
//go:linkname export_googlesql_public_simple_catalog_ASTWithPartitionColumnsClause_table_element_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithPartitionColumnsClause_table_element_list
func export_googlesql_public_simple_catalog_ASTWithPartitionColumnsClause_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateSnapshotTableStatement_name
func export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_clone_data_source
//go:linkname export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_clone_data_source github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateSnapshotTableStatement_clone_data_source
func export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateSnapshotTableStatement_options_list
func export_googlesql_public_simple_catalog_ASTCreateSnapshotTableStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTypeParameterList_parameters_num
//go:linkname export_googlesql_public_simple_catalog_ASTTypeParameterList_parameters_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTypeParameterList_parameters_num
func export_googlesql_public_simple_catalog_ASTTypeParameterList_parameters_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTTypeParameterList_parameter
//go:linkname export_googlesql_public_simple_catalog_ASTTypeParameterList_parameter github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTypeParameterList_parameter
func export_googlesql_public_simple_catalog_ASTTypeParameterList_parameter(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFSchema_columns_num
//go:linkname export_googlesql_public_simple_catalog_ASTTVFSchema_columns_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFSchema_columns_num
func export_googlesql_public_simple_catalog_ASTTVFSchema_columns_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTTVFSchema_column
//go:linkname export_googlesql_public_simple_catalog_ASTTVFSchema_column github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFSchema_column
func export_googlesql_public_simple_catalog_ASTTVFSchema_column(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFSchemaColumn_name
//go:linkname export_googlesql_public_simple_catalog_ASTTVFSchemaColumn_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFSchemaColumn_name
func export_googlesql_public_simple_catalog_ASTTVFSchemaColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTVFSchemaColumn_type
//go:linkname export_googlesql_public_simple_catalog_ASTTVFSchemaColumn_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTVFSchemaColumn_type
func export_googlesql_public_simple_catalog_ASTTVFSchemaColumn_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableAndColumnInfo_table_name
//go:linkname export_googlesql_public_simple_catalog_ASTTableAndColumnInfo_table_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableAndColumnInfo_table_name
func export_googlesql_public_simple_catalog_ASTTableAndColumnInfo_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableAndColumnInfo_column_list
//go:linkname export_googlesql_public_simple_catalog_ASTTableAndColumnInfo_column_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableAndColumnInfo_column_list
func export_googlesql_public_simple_catalog_ASTTableAndColumnInfo_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableAndColumnInfoList_table_and_column_info_entries_num
//go:linkname export_googlesql_public_simple_catalog_ASTTableAndColumnInfoList_table_and_column_info_entries_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableAndColumnInfoList_table_and_column_info_entries_num
func export_googlesql_public_simple_catalog_ASTTableAndColumnInfoList_table_and_column_info_entries_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTTableAndColumnInfoList_table_and_column_info_entry
//go:linkname export_googlesql_public_simple_catalog_ASTTableAndColumnInfoList_table_and_column_info_entry github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableAndColumnInfoList_table_and_column_info_entry
func export_googlesql_public_simple_catalog_ASTTableAndColumnInfoList_table_and_column_info_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTemplatedParameterType_set_kind
//go:linkname export_googlesql_public_simple_catalog_ASTTemplatedParameterType_set_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTemplatedParameterType_set_kind
func export_googlesql_public_simple_catalog_ASTTemplatedParameterType_set_kind(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTTemplatedParameterType_kind
//go:linkname export_googlesql_public_simple_catalog_ASTTemplatedParameterType_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTemplatedParameterType_kind
func export_googlesql_public_simple_catalog_ASTTemplatedParameterType_kind(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTAnalyzeStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTAnalyzeStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnalyzeStatement_options_list
func export_googlesql_public_simple_catalog_ASTAnalyzeStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAnalyzeStatement_table_and_column_info_list
//go:linkname export_googlesql_public_simple_catalog_ASTAnalyzeStatement_table_and_column_info_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAnalyzeStatement_table_and_column_info_list
func export_googlesql_public_simple_catalog_ASTAnalyzeStatement_table_and_column_info_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAssertStatement_expr
//go:linkname export_googlesql_public_simple_catalog_ASTAssertStatement_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAssertStatement_expr
func export_googlesql_public_simple_catalog_ASTAssertStatement_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAssertStatement_description
//go:linkname export_googlesql_public_simple_catalog_ASTAssertStatement_description github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAssertStatement_description
func export_googlesql_public_simple_catalog_ASTAssertStatement_description(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAssertRowsModified_num_rows
//go:linkname export_googlesql_public_simple_catalog_ASTAssertRowsModified_num_rows github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAssertRowsModified_num_rows
func export_googlesql_public_simple_catalog_ASTAssertRowsModified_num_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTReturningClause_select_list
//go:linkname export_googlesql_public_simple_catalog_ASTReturningClause_select_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTReturningClause_select_list
func export_googlesql_public_simple_catalog_ASTReturningClause_select_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTReturningClause_action_alias
//go:linkname export_googlesql_public_simple_catalog_ASTReturningClause_action_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTReturningClause_action_alias
func export_googlesql_public_simple_catalog_ASTReturningClause_action_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDeleteStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTDeleteStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDeleteStatement_target_path
func export_googlesql_public_simple_catalog_ASTDeleteStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDeleteStatement_alias
//go:linkname export_googlesql_public_simple_catalog_ASTDeleteStatement_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDeleteStatement_alias
func export_googlesql_public_simple_catalog_ASTDeleteStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDeleteStatement_offset
//go:linkname export_googlesql_public_simple_catalog_ASTDeleteStatement_offset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDeleteStatement_offset
func export_googlesql_public_simple_catalog_ASTDeleteStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDeleteStatement_where
//go:linkname export_googlesql_public_simple_catalog_ASTDeleteStatement_where github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDeleteStatement_where
func export_googlesql_public_simple_catalog_ASTDeleteStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDeleteStatement_assert_rows_modified
//go:linkname export_googlesql_public_simple_catalog_ASTDeleteStatement_assert_rows_modified github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDeleteStatement_assert_rows_modified
func export_googlesql_public_simple_catalog_ASTDeleteStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDeleteStatement_returning
//go:linkname export_googlesql_public_simple_catalog_ASTDeleteStatement_returning github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDeleteStatement_returning
func export_googlesql_public_simple_catalog_ASTDeleteStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPrimaryKeyColumnAttribute_set_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTPrimaryKeyColumnAttribute_set_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrimaryKeyColumnAttribute_set_enforced
func export_googlesql_public_simple_catalog_ASTPrimaryKeyColumnAttribute_set_enforced(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTPrimaryKeyColumnAttribute_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTPrimaryKeyColumnAttribute_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrimaryKeyColumnAttribute_enforced
func export_googlesql_public_simple_catalog_ASTPrimaryKeyColumnAttribute_enforced(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTForeignKeyColumnAttribute_constraint_name
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyColumnAttribute_constraint_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyColumnAttribute_constraint_name
func export_googlesql_public_simple_catalog_ASTForeignKeyColumnAttribute_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForeignKeyColumnAttribute_reference
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyColumnAttribute_reference github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyColumnAttribute_reference
func export_googlesql_public_simple_catalog_ASTForeignKeyColumnAttribute_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnAttributeList_values_num
//go:linkname export_googlesql_public_simple_catalog_ASTColumnAttributeList_values_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnAttributeList_values_num
func export_googlesql_public_simple_catalog_ASTColumnAttributeList_values_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTColumnAttributeList_value
//go:linkname export_googlesql_public_simple_catalog_ASTColumnAttributeList_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnAttributeList_value
func export_googlesql_public_simple_catalog_ASTColumnAttributeList_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructColumnField_name
//go:linkname export_googlesql_public_simple_catalog_ASTStructColumnField_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructColumnField_name
func export_googlesql_public_simple_catalog_ASTStructColumnField_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructColumnField_schema
//go:linkname export_googlesql_public_simple_catalog_ASTStructColumnField_schema github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructColumnField_schema
func export_googlesql_public_simple_catalog_ASTStructColumnField_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_set_stored_mode
//go:linkname export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_set_stored_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGeneratedColumnInfo_set_stored_mode
func export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_set_stored_mode(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_stored_mode
//go:linkname export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_stored_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGeneratedColumnInfo_stored_mode
func export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_stored_mode(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_expression
//go:linkname export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGeneratedColumnInfo_expression
func export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_GetSqlForStoredMode
//go:linkname export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_GetSqlForStoredMode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGeneratedColumnInfo_GetSqlForStoredMode
func export_googlesql_public_simple_catalog_ASTGeneratedColumnInfo_GetSqlForStoredMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnDefinition_name
//go:linkname export_googlesql_public_simple_catalog_ASTColumnDefinition_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnDefinition_name
func export_googlesql_public_simple_catalog_ASTColumnDefinition_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnDefinition_schema
//go:linkname export_googlesql_public_simple_catalog_ASTColumnDefinition_schema github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnDefinition_schema
func export_googlesql_public_simple_catalog_ASTColumnDefinition_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableElementList_elements_num
//go:linkname export_googlesql_public_simple_catalog_ASTTableElementList_elements_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableElementList_elements_num
func export_googlesql_public_simple_catalog_ASTTableElementList_elements_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTTableElementList_element
//go:linkname export_googlesql_public_simple_catalog_ASTTableElementList_element github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableElementList_element
func export_googlesql_public_simple_catalog_ASTTableElementList_element(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnList_identifiers_num
//go:linkname export_googlesql_public_simple_catalog_ASTColumnList_identifiers_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnList_identifiers_num
func export_googlesql_public_simple_catalog_ASTColumnList_identifiers_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTColumnList_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTColumnList_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnList_identifier
func export_googlesql_public_simple_catalog_ASTColumnList_identifier(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnPosition_set_type
//go:linkname export_googlesql_public_simple_catalog_ASTColumnPosition_set_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnPosition_set_type
func export_googlesql_public_simple_catalog_ASTColumnPosition_set_type(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTColumnPosition_type
//go:linkname export_googlesql_public_simple_catalog_ASTColumnPosition_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnPosition_type
func export_googlesql_public_simple_catalog_ASTColumnPosition_type(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTColumnPosition_identifier
//go:linkname export_googlesql_public_simple_catalog_ASTColumnPosition_identifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnPosition_identifier
func export_googlesql_public_simple_catalog_ASTColumnPosition_identifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertValuesRow_values_num
//go:linkname export_googlesql_public_simple_catalog_ASTInsertValuesRow_values_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertValuesRow_values_num
func export_googlesql_public_simple_catalog_ASTInsertValuesRow_values_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTInsertValuesRow_value
//go:linkname export_googlesql_public_simple_catalog_ASTInsertValuesRow_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertValuesRow_value
func export_googlesql_public_simple_catalog_ASTInsertValuesRow_value(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertValuesRowList_rows_num
//go:linkname export_googlesql_public_simple_catalog_ASTInsertValuesRowList_rows_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertValuesRowList_rows_num
func export_googlesql_public_simple_catalog_ASTInsertValuesRowList_rows_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTInsertValuesRowList_row
//go:linkname export_googlesql_public_simple_catalog_ASTInsertValuesRowList_row github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertValuesRowList_row
func export_googlesql_public_simple_catalog_ASTInsertValuesRowList_row(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_set_deprecated_parse_progress
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_set_deprecated_parse_progress github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_set_deprecated_parse_progress
func export_googlesql_public_simple_catalog_ASTInsertStatement_set_deprecated_parse_progress(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_deprecated_parse_progress
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_deprecated_parse_progress github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_deprecated_parse_progress
func export_googlesql_public_simple_catalog_ASTInsertStatement_deprecated_parse_progress(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_set_insert_mode
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_set_insert_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_set_insert_mode
func export_googlesql_public_simple_catalog_ASTInsertStatement_set_insert_mode(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_insert_mode
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_insert_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_insert_mode
func export_googlesql_public_simple_catalog_ASTInsertStatement_insert_mode(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_target_path
func export_googlesql_public_simple_catalog_ASTInsertStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_column_list
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_column_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_column_list
func export_googlesql_public_simple_catalog_ASTInsertStatement_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_rows
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_rows github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_rows
func export_googlesql_public_simple_catalog_ASTInsertStatement_rows(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_query
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_query
func export_googlesql_public_simple_catalog_ASTInsertStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_assert_rows_modified
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_assert_rows_modified github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_assert_rows_modified
func export_googlesql_public_simple_catalog_ASTInsertStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_returning
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_returning github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_returning
func export_googlesql_public_simple_catalog_ASTInsertStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTInsertStatement_GetSQLForInsertMode
//go:linkname export_googlesql_public_simple_catalog_ASTInsertStatement_GetSQLForInsertMode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTInsertStatement_GetSQLForInsertMode
func export_googlesql_public_simple_catalog_ASTInsertStatement_GetSQLForInsertMode(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateSetValue_path
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateSetValue_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateSetValue_path
func export_googlesql_public_simple_catalog_ASTUpdateSetValue_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateSetValue_value
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateSetValue_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateSetValue_value
func export_googlesql_public_simple_catalog_ASTUpdateSetValue_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateItem_set_value
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateItem_set_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateItem_set_value
func export_googlesql_public_simple_catalog_ASTUpdateItem_set_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateItem_insert_statement
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateItem_insert_statement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateItem_insert_statement
func export_googlesql_public_simple_catalog_ASTUpdateItem_insert_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateItem_delete_statement
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateItem_delete_statement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateItem_delete_statement
func export_googlesql_public_simple_catalog_ASTUpdateItem_delete_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateItem_update_statement
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateItem_update_statement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateItem_update_statement
func export_googlesql_public_simple_catalog_ASTUpdateItem_update_statement(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateItemList_update_items_num
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateItemList_update_items_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateItemList_update_items_num
func export_googlesql_public_simple_catalog_ASTUpdateItemList_update_items_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTUpdateItemList_update_item
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateItemList_update_item github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateItemList_update_item
func export_googlesql_public_simple_catalog_ASTUpdateItemList_update_item(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_target_path
func export_googlesql_public_simple_catalog_ASTUpdateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_alias
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_alias
func export_googlesql_public_simple_catalog_ASTUpdateStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_offset
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_offset github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_offset
func export_googlesql_public_simple_catalog_ASTUpdateStatement_offset(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_update_item_list
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_update_item_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_update_item_list
func export_googlesql_public_simple_catalog_ASTUpdateStatement_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_from_clause
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_from_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_from_clause
func export_googlesql_public_simple_catalog_ASTUpdateStatement_from_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_where
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_where github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_where
func export_googlesql_public_simple_catalog_ASTUpdateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_assert_rows_modified
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_assert_rows_modified github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_assert_rows_modified
func export_googlesql_public_simple_catalog_ASTUpdateStatement_assert_rows_modified(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUpdateStatement_returning
//go:linkname export_googlesql_public_simple_catalog_ASTUpdateStatement_returning github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUpdateStatement_returning
func export_googlesql_public_simple_catalog_ASTUpdateStatement_returning(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTruncateStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTTruncateStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTruncateStatement_target_path
func export_googlesql_public_simple_catalog_ASTTruncateStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTruncateStatement_where
//go:linkname export_googlesql_public_simple_catalog_ASTTruncateStatement_where github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTruncateStatement_where
func export_googlesql_public_simple_catalog_ASTTruncateStatement_where(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeAction_set_action_type
//go:linkname export_googlesql_public_simple_catalog_ASTMergeAction_set_action_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeAction_set_action_type
func export_googlesql_public_simple_catalog_ASTMergeAction_set_action_type(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTMergeAction_action_type
//go:linkname export_googlesql_public_simple_catalog_ASTMergeAction_action_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeAction_action_type
func export_googlesql_public_simple_catalog_ASTMergeAction_action_type(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTMergeAction_insert_column_list
//go:linkname export_googlesql_public_simple_catalog_ASTMergeAction_insert_column_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeAction_insert_column_list
func export_googlesql_public_simple_catalog_ASTMergeAction_insert_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeAction_insert_row
//go:linkname export_googlesql_public_simple_catalog_ASTMergeAction_insert_row github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeAction_insert_row
func export_googlesql_public_simple_catalog_ASTMergeAction_insert_row(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeAction_update_item_list
//go:linkname export_googlesql_public_simple_catalog_ASTMergeAction_update_item_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeAction_update_item_list
func export_googlesql_public_simple_catalog_ASTMergeAction_update_item_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeWhenClause_set_match_type
//go:linkname export_googlesql_public_simple_catalog_ASTMergeWhenClause_set_match_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeWhenClause_set_match_type
func export_googlesql_public_simple_catalog_ASTMergeWhenClause_set_match_type(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTMergeWhenClause_match_type
//go:linkname export_googlesql_public_simple_catalog_ASTMergeWhenClause_match_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeWhenClause_match_type
func export_googlesql_public_simple_catalog_ASTMergeWhenClause_match_type(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTMergeWhenClause_search_condition
//go:linkname export_googlesql_public_simple_catalog_ASTMergeWhenClause_search_condition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeWhenClause_search_condition
func export_googlesql_public_simple_catalog_ASTMergeWhenClause_search_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeWhenClause_action
//go:linkname export_googlesql_public_simple_catalog_ASTMergeWhenClause_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeWhenClause_action
func export_googlesql_public_simple_catalog_ASTMergeWhenClause_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeWhenClause_GetSQLForMatchType
//go:linkname export_googlesql_public_simple_catalog_ASTMergeWhenClause_GetSQLForMatchType github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeWhenClause_GetSQLForMatchType
func export_googlesql_public_simple_catalog_ASTMergeWhenClause_GetSQLForMatchType(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeWhenClauseList_clause_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTMergeWhenClauseList_clause_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeWhenClauseList_clause_list_num
func export_googlesql_public_simple_catalog_ASTMergeWhenClauseList_clause_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTMergeWhenClauseList_clause_list
//go:linkname export_googlesql_public_simple_catalog_ASTMergeWhenClauseList_clause_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeWhenClauseList_clause_list
func export_googlesql_public_simple_catalog_ASTMergeWhenClauseList_clause_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTMergeStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeStatement_target_path
func export_googlesql_public_simple_catalog_ASTMergeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeStatement_alias
//go:linkname export_googlesql_public_simple_catalog_ASTMergeStatement_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeStatement_alias
func export_googlesql_public_simple_catalog_ASTMergeStatement_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeStatement_table_expression
//go:linkname export_googlesql_public_simple_catalog_ASTMergeStatement_table_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeStatement_table_expression
func export_googlesql_public_simple_catalog_ASTMergeStatement_table_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeStatement_merge_condition
//go:linkname export_googlesql_public_simple_catalog_ASTMergeStatement_merge_condition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeStatement_merge_condition
func export_googlesql_public_simple_catalog_ASTMergeStatement_merge_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTMergeStatement_when_clauses
//go:linkname export_googlesql_public_simple_catalog_ASTMergeStatement_when_clauses github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTMergeStatement_when_clauses
func export_googlesql_public_simple_catalog_ASTMergeStatement_when_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPrivilege_privilege_action
//go:linkname export_googlesql_public_simple_catalog_ASTPrivilege_privilege_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrivilege_privilege_action
func export_googlesql_public_simple_catalog_ASTPrivilege_privilege_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPrivilege_paths
//go:linkname export_googlesql_public_simple_catalog_ASTPrivilege_paths github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrivilege_paths
func export_googlesql_public_simple_catalog_ASTPrivilege_paths(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPrivileges_privileges_num
//go:linkname export_googlesql_public_simple_catalog_ASTPrivileges_privileges_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrivileges_privileges_num
func export_googlesql_public_simple_catalog_ASTPrivileges_privileges_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTPrivileges_privilege
//go:linkname export_googlesql_public_simple_catalog_ASTPrivileges_privilege github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrivileges_privilege
func export_googlesql_public_simple_catalog_ASTPrivileges_privilege(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPrivileges_is_all_privileges
//go:linkname export_googlesql_public_simple_catalog_ASTPrivileges_is_all_privileges github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrivileges_is_all_privileges
func export_googlesql_public_simple_catalog_ASTPrivileges_is_all_privileges(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTGranteeList_grantee_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTGranteeList_grantee_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGranteeList_grantee_list_num
func export_googlesql_public_simple_catalog_ASTGranteeList_grantee_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTGranteeList_grantee_list
//go:linkname export_googlesql_public_simple_catalog_ASTGranteeList_grantee_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGranteeList_grantee_list
func export_googlesql_public_simple_catalog_ASTGranteeList_grantee_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGrantStatement_privileges
//go:linkname export_googlesql_public_simple_catalog_ASTGrantStatement_privileges github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGrantStatement_privileges
func export_googlesql_public_simple_catalog_ASTGrantStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGrantStatement_target_type
//go:linkname export_googlesql_public_simple_catalog_ASTGrantStatement_target_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGrantStatement_target_type
func export_googlesql_public_simple_catalog_ASTGrantStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGrantStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTGrantStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGrantStatement_target_path
func export_googlesql_public_simple_catalog_ASTGrantStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGrantStatement_grantee_list
//go:linkname export_googlesql_public_simple_catalog_ASTGrantStatement_grantee_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGrantStatement_grantee_list
func export_googlesql_public_simple_catalog_ASTGrantStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRevokeStatement_privileges
//go:linkname export_googlesql_public_simple_catalog_ASTRevokeStatement_privileges github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRevokeStatement_privileges
func export_googlesql_public_simple_catalog_ASTRevokeStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRevokeStatement_target_type
//go:linkname export_googlesql_public_simple_catalog_ASTRevokeStatement_target_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRevokeStatement_target_type
func export_googlesql_public_simple_catalog_ASTRevokeStatement_target_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRevokeStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTRevokeStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRevokeStatement_target_path
func export_googlesql_public_simple_catalog_ASTRevokeStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRevokeStatement_grantee_list
//go:linkname export_googlesql_public_simple_catalog_ASTRevokeStatement_grantee_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRevokeStatement_grantee_list
func export_googlesql_public_simple_catalog_ASTRevokeStatement_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRepeatableClause_argument
//go:linkname export_googlesql_public_simple_catalog_ASTRepeatableClause_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRepeatableClause_argument
func export_googlesql_public_simple_catalog_ASTRepeatableClause_argument(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFilterFieldsArg_set_filter_type
//go:linkname export_googlesql_public_simple_catalog_ASTFilterFieldsArg_set_filter_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFilterFieldsArg_set_filter_type
func export_googlesql_public_simple_catalog_ASTFilterFieldsArg_set_filter_type(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTFilterFieldsArg_filter_type
//go:linkname export_googlesql_public_simple_catalog_ASTFilterFieldsArg_filter_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFilterFieldsArg_filter_type
func export_googlesql_public_simple_catalog_ASTFilterFieldsArg_filter_type(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTFilterFieldsArg_path_expression
//go:linkname export_googlesql_public_simple_catalog_ASTFilterFieldsArg_path_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFilterFieldsArg_path_expression
func export_googlesql_public_simple_catalog_ASTFilterFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFilterFieldsArg_GetSQLForOperator
//go:linkname export_googlesql_public_simple_catalog_ASTFilterFieldsArg_GetSQLForOperator github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFilterFieldsArg_GetSQLForOperator
func export_googlesql_public_simple_catalog_ASTFilterFieldsArg_GetSQLForOperator(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTReplaceFieldsArg_expression
//go:linkname export_googlesql_public_simple_catalog_ASTReplaceFieldsArg_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTReplaceFieldsArg_expression
func export_googlesql_public_simple_catalog_ASTReplaceFieldsArg_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTReplaceFieldsArg_path_expression
//go:linkname export_googlesql_public_simple_catalog_ASTReplaceFieldsArg_path_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTReplaceFieldsArg_path_expression
func export_googlesql_public_simple_catalog_ASTReplaceFieldsArg_path_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_expr
//go:linkname export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_expr github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTReplaceFieldsExpression_expr
func export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_expr(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_arguments_num
//go:linkname export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_arguments_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTReplaceFieldsExpression_arguments_num
func export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_arguments_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_argument
//go:linkname export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTReplaceFieldsExpression_argument
func export_googlesql_public_simple_catalog_ASTReplaceFieldsExpression_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleSize_set_unit
//go:linkname export_googlesql_public_simple_catalog_ASTSampleSize_set_unit github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleSize_set_unit
func export_googlesql_public_simple_catalog_ASTSampleSize_set_unit(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTSampleSize_unit
//go:linkname export_googlesql_public_simple_catalog_ASTSampleSize_unit github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleSize_unit
func export_googlesql_public_simple_catalog_ASTSampleSize_unit(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTSampleSize_size
//go:linkname export_googlesql_public_simple_catalog_ASTSampleSize_size github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleSize_size
func export_googlesql_public_simple_catalog_ASTSampleSize_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleSize_partition_by
//go:linkname export_googlesql_public_simple_catalog_ASTSampleSize_partition_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleSize_partition_by
func export_googlesql_public_simple_catalog_ASTSampleSize_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleSize_GetSQLForUnit
//go:linkname export_googlesql_public_simple_catalog_ASTSampleSize_GetSQLForUnit github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleSize_GetSQLForUnit
func export_googlesql_public_simple_catalog_ASTSampleSize_GetSQLForUnit(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWithWeight_alias
//go:linkname export_googlesql_public_simple_catalog_ASTWithWeight_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWithWeight_alias
func export_googlesql_public_simple_catalog_ASTWithWeight_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleSuffix_weight
//go:linkname export_googlesql_public_simple_catalog_ASTSampleSuffix_weight github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleSuffix_weight
func export_googlesql_public_simple_catalog_ASTSampleSuffix_weight(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleSuffix_repeat
//go:linkname export_googlesql_public_simple_catalog_ASTSampleSuffix_repeat github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleSuffix_repeat
func export_googlesql_public_simple_catalog_ASTSampleSuffix_repeat(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleClause_sample_method
//go:linkname export_googlesql_public_simple_catalog_ASTSampleClause_sample_method github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleClause_sample_method
func export_googlesql_public_simple_catalog_ASTSampleClause_sample_method(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleClause_sample_size
//go:linkname export_googlesql_public_simple_catalog_ASTSampleClause_sample_size github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleClause_sample_size
func export_googlesql_public_simple_catalog_ASTSampleClause_sample_size(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSampleClause_sample_suffix
//go:linkname export_googlesql_public_simple_catalog_ASTSampleClause_sample_suffix github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSampleClause_sample_suffix
func export_googlesql_public_simple_catalog_ASTSampleClause_sample_suffix(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterAction_GetSQLForAlterAction
//go:linkname export_googlesql_public_simple_catalog_ASTAlterAction_GetSQLForAlterAction github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterAction_GetSQLForAlterAction
func export_googlesql_public_simple_catalog_ASTAlterAction_GetSQLForAlterAction(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetOptionsAction_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTSetOptionsAction_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetOptionsAction_options_list
func export_googlesql_public_simple_catalog_ASTSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetAsAction_json_body
//go:linkname export_googlesql_public_simple_catalog_ASTSetAsAction_json_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetAsAction_json_body
func export_googlesql_public_simple_catalog_ASTSetAsAction_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetAsAction_text_body
//go:linkname export_googlesql_public_simple_catalog_ASTSetAsAction_text_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetAsAction_text_body
func export_googlesql_public_simple_catalog_ASTSetAsAction_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAddConstraintAction_set_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAddConstraintAction_set_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddConstraintAction_set_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTAddConstraintAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAddConstraintAction_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAddConstraintAction_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddConstraintAction_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTAddConstraintAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAddConstraintAction_constraint
//go:linkname export_googlesql_public_simple_catalog_ASTAddConstraintAction_constraint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddConstraintAction_constraint
func export_googlesql_public_simple_catalog_ASTAddConstraintAction_constraint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropPrimaryKeyAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropPrimaryKeyAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropPrimaryKeyAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropPrimaryKeyAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropPrimaryKeyAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropPrimaryKeyAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropPrimaryKeyAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropPrimaryKeyAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropConstraintAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropConstraintAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropConstraintAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropConstraintAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropConstraintAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropConstraintAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropConstraintAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropConstraintAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropConstraintAction_constraint_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropConstraintAction_constraint_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropConstraintAction_constraint_name
func export_googlesql_public_simple_catalog_ASTDropConstraintAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintEnforcementAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintEnforcementAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_set_is_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_set_is_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintEnforcementAction_set_is_enforced
func export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_set_is_enforced(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_is_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_is_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintEnforcementAction_is_enforced
func export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_is_enforced(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_constraint_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_constraint_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintEnforcementAction_constraint_name
func export_googlesql_public_simple_catalog_ASTAlterConstraintEnforcementAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintSetOptionsAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintSetOptionsAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_constraint_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_constraint_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintSetOptionsAction_constraint_name
func export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterConstraintSetOptionsAction_options_list
func export_googlesql_public_simple_catalog_ASTAlterConstraintSetOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAddColumnAction_set_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAddColumnAction_set_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddColumnAction_set_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTAddColumnAction_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAddColumnAction_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAddColumnAction_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddColumnAction_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTAddColumnAction_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAddColumnAction_column_definition
//go:linkname export_googlesql_public_simple_catalog_ASTAddColumnAction_column_definition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddColumnAction_column_definition
func export_googlesql_public_simple_catalog_ASTAddColumnAction_column_definition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAddColumnAction_column_position
//go:linkname export_googlesql_public_simple_catalog_ASTAddColumnAction_column_position github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddColumnAction_column_position
func export_googlesql_public_simple_catalog_ASTAddColumnAction_column_position(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAddColumnAction_fill_expression
//go:linkname export_googlesql_public_simple_catalog_ASTAddColumnAction_fill_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddColumnAction_fill_expression
func export_googlesql_public_simple_catalog_ASTAddColumnAction_fill_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropColumnAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropColumnAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropColumnAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropColumnAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropColumnAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropColumnAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropColumnAction_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropColumnAction_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropColumnAction_column_name
func export_googlesql_public_simple_catalog_ASTDropColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRenameColumnAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTRenameColumnAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameColumnAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTRenameColumnAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTRenameColumnAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTRenameColumnAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameColumnAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTRenameColumnAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTRenameColumnAction_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTRenameColumnAction_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameColumnAction_column_name
func export_googlesql_public_simple_catalog_ASTRenameColumnAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRenameColumnAction_new_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTRenameColumnAction_new_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameColumnAction_new_column_name
func export_googlesql_public_simple_catalog_ASTRenameColumnAction_new_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnTypeAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnTypeAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnTypeAction_column_name
func export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_schema
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_schema github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnTypeAction_schema
func export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_collate
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_collate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnTypeAction_collate
func export_googlesql_public_simple_catalog_ASTAlterColumnTypeAction_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnOptionsAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnOptionsAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnOptionsAction_column_name
func export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnOptionsAction_options_list
func export_googlesql_public_simple_catalog_ASTAlterColumnOptionsAction_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnSetDefaultAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnSetDefaultAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnSetDefaultAction_column_name
func export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_default_expression
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_default_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnSetDefaultAction_default_expression
func export_googlesql_public_simple_catalog_ASTAlterColumnSetDefaultAction_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnDropDefaultAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnDropDefaultAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnDropDefaultAction_column_name
func export_googlesql_public_simple_catalog_ASTAlterColumnDropDefaultAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnDropNotNullAction_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnDropNotNullAction_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_column_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_column_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterColumnDropNotNullAction_column_name
func export_googlesql_public_simple_catalog_ASTAlterColumnDropNotNullAction_column_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTGrantToClause_set_has_grant_keyword_and_parens
//go:linkname export_googlesql_public_simple_catalog_ASTGrantToClause_set_has_grant_keyword_and_parens github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGrantToClause_set_has_grant_keyword_and_parens
func export_googlesql_public_simple_catalog_ASTGrantToClause_set_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTGrantToClause_has_grant_keyword_and_parens
//go:linkname export_googlesql_public_simple_catalog_ASTGrantToClause_has_grant_keyword_and_parens github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGrantToClause_has_grant_keyword_and_parens
func export_googlesql_public_simple_catalog_ASTGrantToClause_has_grant_keyword_and_parens(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTGrantToClause_grantee_list
//go:linkname export_googlesql_public_simple_catalog_ASTGrantToClause_grantee_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTGrantToClause_grantee_list
func export_googlesql_public_simple_catalog_ASTGrantToClause_grantee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRestrictToClause_restrictee_list
//go:linkname export_googlesql_public_simple_catalog_ASTRestrictToClause_restrictee_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRestrictToClause_restrictee_list
func export_googlesql_public_simple_catalog_ASTRestrictToClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_set_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_set_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddToRestricteeListClause_set_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_set_is_if_not_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_is_if_not_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_is_if_not_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddToRestricteeListClause_is_if_not_exists
func export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_is_if_not_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_restrictee_list
//go:linkname export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_restrictee_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAddToRestricteeListClause_restrictee_list
func export_googlesql_public_simple_catalog_ASTAddToRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRemoveFromRestricteeListClause_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRemoveFromRestricteeListClause_is_if_exists
func export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_restrictee_list
//go:linkname export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_restrictee_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRemoveFromRestricteeListClause_restrictee_list
func export_googlesql_public_simple_catalog_ASTRemoveFromRestricteeListClause_restrictee_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTFilterUsingClause_set_has_filter_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTFilterUsingClause_set_has_filter_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFilterUsingClause_set_has_filter_keyword
func export_googlesql_public_simple_catalog_ASTFilterUsingClause_set_has_filter_keyword(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTFilterUsingClause_has_filter_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTFilterUsingClause_has_filter_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFilterUsingClause_has_filter_keyword
func export_googlesql_public_simple_catalog_ASTFilterUsingClause_has_filter_keyword(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTFilterUsingClause_predicate
//go:linkname export_googlesql_public_simple_catalog_ASTFilterUsingClause_predicate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTFilterUsingClause_predicate
func export_googlesql_public_simple_catalog_ASTFilterUsingClause_predicate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRevokeFromClause_set_is_revoke_from_all
//go:linkname export_googlesql_public_simple_catalog_ASTRevokeFromClause_set_is_revoke_from_all github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRevokeFromClause_set_is_revoke_from_all
func export_googlesql_public_simple_catalog_ASTRevokeFromClause_set_is_revoke_from_all(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTRevokeFromClause_is_revoke_from_all
//go:linkname export_googlesql_public_simple_catalog_ASTRevokeFromClause_is_revoke_from_all github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRevokeFromClause_is_revoke_from_all
func export_googlesql_public_simple_catalog_ASTRevokeFromClause_is_revoke_from_all(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTRevokeFromClause_revoke_from_list
//go:linkname export_googlesql_public_simple_catalog_ASTRevokeFromClause_revoke_from_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRevokeFromClause_revoke_from_list
func export_googlesql_public_simple_catalog_ASTRevokeFromClause_revoke_from_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRenameToClause_new_name
//go:linkname export_googlesql_public_simple_catalog_ASTRenameToClause_new_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRenameToClause_new_name
func export_googlesql_public_simple_catalog_ASTRenameToClause_new_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSetCollateClause_collate
//go:linkname export_googlesql_public_simple_catalog_ASTSetCollateClause_collate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSetCollateClause_collate
func export_googlesql_public_simple_catalog_ASTSetCollateClause_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterActionList_actions_num
//go:linkname export_googlesql_public_simple_catalog_ASTAlterActionList_actions_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterActionList_actions_num
func export_googlesql_public_simple_catalog_ASTAlterActionList_actions_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTAlterActionList_action
//go:linkname export_googlesql_public_simple_catalog_ASTAlterActionList_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterActionList_action
func export_googlesql_public_simple_catalog_ASTAlterActionList_action(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterAllRowAccessPoliciesStatement_table_name_path
//go:linkname export_googlesql_public_simple_catalog_ASTAlterAllRowAccessPoliciesStatement_table_name_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterAllRowAccessPoliciesStatement_table_name_path
func export_googlesql_public_simple_catalog_ASTAlterAllRowAccessPoliciesStatement_table_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterAllRowAccessPoliciesStatement_alter_action
//go:linkname export_googlesql_public_simple_catalog_ASTAlterAllRowAccessPoliciesStatement_alter_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterAllRowAccessPoliciesStatement_alter_action
func export_googlesql_public_simple_catalog_ASTAlterAllRowAccessPoliciesStatement_alter_action(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForeignKeyActions_set_udpate_action
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyActions_set_udpate_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyActions_set_udpate_action
func export_googlesql_public_simple_catalog_ASTForeignKeyActions_set_udpate_action(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTForeignKeyActions_udpate_action
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyActions_udpate_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyActions_udpate_action
func export_googlesql_public_simple_catalog_ASTForeignKeyActions_udpate_action(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTForeignKeyActions_set_delete_action
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyActions_set_delete_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyActions_set_delete_action
func export_googlesql_public_simple_catalog_ASTForeignKeyActions_set_delete_action(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTForeignKeyActions_delete_action
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyActions_delete_action github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyActions_delete_action
func export_googlesql_public_simple_catalog_ASTForeignKeyActions_delete_action(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTForeignKeyReference_set_match
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyReference_set_match github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyReference_set_match
func export_googlesql_public_simple_catalog_ASTForeignKeyReference_set_match(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTForeignKeyReference_match
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyReference_match github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyReference_match
func export_googlesql_public_simple_catalog_ASTForeignKeyReference_match(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTForeignKeyReference_set_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyReference_set_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyReference_set_enforced
func export_googlesql_public_simple_catalog_ASTForeignKeyReference_set_enforced(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTForeignKeyReference_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyReference_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyReference_enforced
func export_googlesql_public_simple_catalog_ASTForeignKeyReference_enforced(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTForeignKeyReference_table_name
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyReference_table_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyReference_table_name
func export_googlesql_public_simple_catalog_ASTForeignKeyReference_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForeignKeyReference_column_list
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyReference_column_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyReference_column_list
func export_googlesql_public_simple_catalog_ASTForeignKeyReference_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForeignKeyReference_actions
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKeyReference_actions github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKeyReference_actions
func export_googlesql_public_simple_catalog_ASTForeignKeyReference_actions(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTScript_statement_list_node
//go:linkname export_googlesql_public_simple_catalog_ASTScript_statement_list_node github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTScript_statement_list_node
func export_googlesql_public_simple_catalog_ASTScript_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTScript_statement_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTScript_statement_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTScript_statement_list_num
func export_googlesql_public_simple_catalog_ASTScript_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTScript_statement_list
//go:linkname export_googlesql_public_simple_catalog_ASTScript_statement_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTScript_statement_list
func export_googlesql_public_simple_catalog_ASTScript_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTElseifClause_condition
//go:linkname export_googlesql_public_simple_catalog_ASTElseifClause_condition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTElseifClause_condition
func export_googlesql_public_simple_catalog_ASTElseifClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTElseifClause_body
//go:linkname export_googlesql_public_simple_catalog_ASTElseifClause_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTElseifClause_body
func export_googlesql_public_simple_catalog_ASTElseifClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTElseifClause_if_stmt
//go:linkname export_googlesql_public_simple_catalog_ASTElseifClause_if_stmt github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTElseifClause_if_stmt
func export_googlesql_public_simple_catalog_ASTElseifClause_if_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTElseifClauseList_elseif_clauses_num
//go:linkname export_googlesql_public_simple_catalog_ASTElseifClauseList_elseif_clauses_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTElseifClauseList_elseif_clauses_num
func export_googlesql_public_simple_catalog_ASTElseifClauseList_elseif_clauses_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTElseifClauseList_elseif_clause
//go:linkname export_googlesql_public_simple_catalog_ASTElseifClauseList_elseif_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTElseifClauseList_elseif_clause
func export_googlesql_public_simple_catalog_ASTElseifClauseList_elseif_clause(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIfStatement_condition
//go:linkname export_googlesql_public_simple_catalog_ASTIfStatement_condition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIfStatement_condition
func export_googlesql_public_simple_catalog_ASTIfStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIfStatement_then_list
//go:linkname export_googlesql_public_simple_catalog_ASTIfStatement_then_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIfStatement_then_list
func export_googlesql_public_simple_catalog_ASTIfStatement_then_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIfStatement_elseif_clauses
//go:linkname export_googlesql_public_simple_catalog_ASTIfStatement_elseif_clauses github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIfStatement_elseif_clauses
func export_googlesql_public_simple_catalog_ASTIfStatement_elseif_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTIfStatement_else_list
//go:linkname export_googlesql_public_simple_catalog_ASTIfStatement_else_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIfStatement_else_list
func export_googlesql_public_simple_catalog_ASTIfStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWhenThenClause_condition
//go:linkname export_googlesql_public_simple_catalog_ASTWhenThenClause_condition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWhenThenClause_condition
func export_googlesql_public_simple_catalog_ASTWhenThenClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWhenThenClause_body
//go:linkname export_googlesql_public_simple_catalog_ASTWhenThenClause_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWhenThenClause_body
func export_googlesql_public_simple_catalog_ASTWhenThenClause_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWhenThenClause_case_stmt
//go:linkname export_googlesql_public_simple_catalog_ASTWhenThenClause_case_stmt github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWhenThenClause_case_stmt
func export_googlesql_public_simple_catalog_ASTWhenThenClause_case_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTWhenThenClauseList_when_then_clauses_num
//go:linkname export_googlesql_public_simple_catalog_ASTWhenThenClauseList_when_then_clauses_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWhenThenClauseList_when_then_clauses_num
func export_googlesql_public_simple_catalog_ASTWhenThenClauseList_when_then_clauses_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTWhenThenClauseList_when_then_clause
//go:linkname export_googlesql_public_simple_catalog_ASTWhenThenClauseList_when_then_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWhenThenClauseList_when_then_clause
func export_googlesql_public_simple_catalog_ASTWhenThenClauseList_when_then_clause(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCaseStatement_expression
//go:linkname export_googlesql_public_simple_catalog_ASTCaseStatement_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCaseStatement_expression
func export_googlesql_public_simple_catalog_ASTCaseStatement_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCaseStatement_when_then_clauses
//go:linkname export_googlesql_public_simple_catalog_ASTCaseStatement_when_then_clauses github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCaseStatement_when_then_clauses
func export_googlesql_public_simple_catalog_ASTCaseStatement_when_then_clauses(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCaseStatement_else_list
//go:linkname export_googlesql_public_simple_catalog_ASTCaseStatement_else_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCaseStatement_else_list
func export_googlesql_public_simple_catalog_ASTCaseStatement_else_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHint_num_shards_hint
//go:linkname export_googlesql_public_simple_catalog_ASTHint_num_shards_hint github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHint_num_shards_hint
func export_googlesql_public_simple_catalog_ASTHint_num_shards_hint(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHint_hint_entries_num
//go:linkname export_googlesql_public_simple_catalog_ASTHint_hint_entries_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHint_hint_entries_num
func export_googlesql_public_simple_catalog_ASTHint_hint_entries_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTHint_hint_entry
//go:linkname export_googlesql_public_simple_catalog_ASTHint_hint_entry github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHint_hint_entry
func export_googlesql_public_simple_catalog_ASTHint_hint_entry(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHintEntry_qualifier
//go:linkname export_googlesql_public_simple_catalog_ASTHintEntry_qualifier github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHintEntry_qualifier
func export_googlesql_public_simple_catalog_ASTHintEntry_qualifier(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHintEntry_name
//go:linkname export_googlesql_public_simple_catalog_ASTHintEntry_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHintEntry_name
func export_googlesql_public_simple_catalog_ASTHintEntry_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTHintEntry_value
//go:linkname export_googlesql_public_simple_catalog_ASTHintEntry_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTHintEntry_value
func export_googlesql_public_simple_catalog_ASTHintEntry_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUnpivotInItemLabel_label
//go:linkname export_googlesql_public_simple_catalog_ASTUnpivotInItemLabel_label github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUnpivotInItemLabel_label
func export_googlesql_public_simple_catalog_ASTUnpivotInItemLabel_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDescriptor_columns
//go:linkname export_googlesql_public_simple_catalog_ASTDescriptor_columns github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDescriptor_columns
func export_googlesql_public_simple_catalog_ASTDescriptor_columns(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnSchema_type_parameters
//go:linkname export_googlesql_public_simple_catalog_ASTColumnSchema_type_parameters github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnSchema_type_parameters
func export_googlesql_public_simple_catalog_ASTColumnSchema_type_parameters(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnSchema_generated_column_info
//go:linkname export_googlesql_public_simple_catalog_ASTColumnSchema_generated_column_info github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnSchema_generated_column_info
func export_googlesql_public_simple_catalog_ASTColumnSchema_generated_column_info(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnSchema_default_expression
//go:linkname export_googlesql_public_simple_catalog_ASTColumnSchema_default_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnSchema_default_expression
func export_googlesql_public_simple_catalog_ASTColumnSchema_default_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnSchema_collate
//go:linkname export_googlesql_public_simple_catalog_ASTColumnSchema_collate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnSchema_collate
func export_googlesql_public_simple_catalog_ASTColumnSchema_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnSchema_attributes
//go:linkname export_googlesql_public_simple_catalog_ASTColumnSchema_attributes github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnSchema_attributes
func export_googlesql_public_simple_catalog_ASTColumnSchema_attributes(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnSchema_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTColumnSchema_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnSchema_options_list
func export_googlesql_public_simple_catalog_ASTColumnSchema_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTColumnSchema_ContainsAttribute
//go:linkname export_googlesql_public_simple_catalog_ASTColumnSchema_ContainsAttribute github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTColumnSchema_ContainsAttribute
func export_googlesql_public_simple_catalog_ASTColumnSchema_ContainsAttribute(arg0 unsafe.Pointer, arg1 C.int, arg2 *C.char)

//export export_googlesql_public_simple_catalog_ASTSimpleColumnSchema_type_name
//go:linkname export_googlesql_public_simple_catalog_ASTSimpleColumnSchema_type_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSimpleColumnSchema_type_name
func export_googlesql_public_simple_catalog_ASTSimpleColumnSchema_type_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTArrayColumnSchema_element_schema
//go:linkname export_googlesql_public_simple_catalog_ASTArrayColumnSchema_element_schema github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTArrayColumnSchema_element_schema
func export_googlesql_public_simple_catalog_ASTArrayColumnSchema_element_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTTableConstraint_constraint_name
//go:linkname export_googlesql_public_simple_catalog_ASTTableConstraint_constraint_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTTableConstraint_constraint_name
func export_googlesql_public_simple_catalog_ASTTableConstraint_constraint_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPrimaryKey_set_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTPrimaryKey_set_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrimaryKey_set_enforced
func export_googlesql_public_simple_catalog_ASTPrimaryKey_set_enforced(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTPrimaryKey_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTPrimaryKey_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrimaryKey_enforced
func export_googlesql_public_simple_catalog_ASTPrimaryKey_enforced(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTPrimaryKey_element_list
//go:linkname export_googlesql_public_simple_catalog_ASTPrimaryKey_element_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrimaryKey_element_list
func export_googlesql_public_simple_catalog_ASTPrimaryKey_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTPrimaryKey_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTPrimaryKey_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTPrimaryKey_options_list
func export_googlesql_public_simple_catalog_ASTPrimaryKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForeignKey_column_list
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKey_column_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKey_column_list
func export_googlesql_public_simple_catalog_ASTForeignKey_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForeignKey_reference
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKey_reference github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKey_reference
func export_googlesql_public_simple_catalog_ASTForeignKey_reference(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForeignKey_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTForeignKey_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForeignKey_options_list
func export_googlesql_public_simple_catalog_ASTForeignKey_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCheckConstraint_set_is_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTCheckConstraint_set_is_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCheckConstraint_set_is_enforced
func export_googlesql_public_simple_catalog_ASTCheckConstraint_set_is_enforced(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCheckConstraint_is_enforced
//go:linkname export_googlesql_public_simple_catalog_ASTCheckConstraint_is_enforced github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCheckConstraint_is_enforced
func export_googlesql_public_simple_catalog_ASTCheckConstraint_is_enforced(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCheckConstraint_expression
//go:linkname export_googlesql_public_simple_catalog_ASTCheckConstraint_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCheckConstraint_expression
func export_googlesql_public_simple_catalog_ASTCheckConstraint_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCheckConstraint_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCheckConstraint_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCheckConstraint_options_list
func export_googlesql_public_simple_catalog_ASTCheckConstraint_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDescriptorColumn_name
//go:linkname export_googlesql_public_simple_catalog_ASTDescriptorColumn_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDescriptorColumn_name
func export_googlesql_public_simple_catalog_ASTDescriptorColumn_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDescriptorColumnList_descriptor_column_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTDescriptorColumnList_descriptor_column_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDescriptorColumnList_descriptor_column_list_num
func export_googlesql_public_simple_catalog_ASTDescriptorColumnList_descriptor_column_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTDescriptorColumnList_descriptor_column_list
//go:linkname export_googlesql_public_simple_catalog_ASTDescriptorColumnList_descriptor_column_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDescriptorColumnList_descriptor_column_list
func export_googlesql_public_simple_catalog_ASTDescriptorColumnList_descriptor_column_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateEntityStatement_type
//go:linkname export_googlesql_public_simple_catalog_ASTCreateEntityStatement_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateEntityStatement_type
func export_googlesql_public_simple_catalog_ASTCreateEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateEntityStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateEntityStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateEntityStatement_name
func export_googlesql_public_simple_catalog_ASTCreateEntityStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateEntityStatement_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateEntityStatement_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateEntityStatement_options_list
func export_googlesql_public_simple_catalog_ASTCreateEntityStatement_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateEntityStatement_json_body
//go:linkname export_googlesql_public_simple_catalog_ASTCreateEntityStatement_json_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateEntityStatement_json_body
func export_googlesql_public_simple_catalog_ASTCreateEntityStatement_json_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateEntityStatement_text_body
//go:linkname export_googlesql_public_simple_catalog_ASTCreateEntityStatement_text_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateEntityStatement_text_body
func export_googlesql_public_simple_catalog_ASTCreateEntityStatement_text_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRaiseStatement_message
//go:linkname export_googlesql_public_simple_catalog_ASTRaiseStatement_message github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRaiseStatement_message
func export_googlesql_public_simple_catalog_ASTRaiseStatement_message(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRaiseStatement_is_rethrow
//go:linkname export_googlesql_public_simple_catalog_ASTRaiseStatement_is_rethrow github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRaiseStatement_is_rethrow
func export_googlesql_public_simple_catalog_ASTRaiseStatement_is_rethrow(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTExceptionHandler_statement_list
//go:linkname export_googlesql_public_simple_catalog_ASTExceptionHandler_statement_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExceptionHandler_statement_list
func export_googlesql_public_simple_catalog_ASTExceptionHandler_statement_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExceptionHandlerList_exception_handler_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTExceptionHandlerList_exception_handler_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExceptionHandlerList_exception_handler_list_num
func export_googlesql_public_simple_catalog_ASTExceptionHandlerList_exception_handler_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTExceptionHandlerList_exception_handler_list
//go:linkname export_googlesql_public_simple_catalog_ASTExceptionHandlerList_exception_handler_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExceptionHandlerList_exception_handler_list
func export_googlesql_public_simple_catalog_ASTExceptionHandlerList_exception_handler_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBeginEndBlock_label
//go:linkname export_googlesql_public_simple_catalog_ASTBeginEndBlock_label github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBeginEndBlock_label
func export_googlesql_public_simple_catalog_ASTBeginEndBlock_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list_node
//go:linkname export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list_node github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBeginEndBlock_statement_list_node
func export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list_node(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBeginEndBlock_handler_list
//go:linkname export_googlesql_public_simple_catalog_ASTBeginEndBlock_handler_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBeginEndBlock_handler_list
func export_googlesql_public_simple_catalog_ASTBeginEndBlock_handler_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBeginEndBlock_statement_list_num
func export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list
//go:linkname export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBeginEndBlock_statement_list
func export_googlesql_public_simple_catalog_ASTBeginEndBlock_statement_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBeginEndBlock_has_exception_handler
//go:linkname export_googlesql_public_simple_catalog_ASTBeginEndBlock_has_exception_handler github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBeginEndBlock_has_exception_handler
func export_googlesql_public_simple_catalog_ASTBeginEndBlock_has_exception_handler(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTIdentifierList_identifier_list_num
//go:linkname export_googlesql_public_simple_catalog_ASTIdentifierList_identifier_list_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIdentifierList_identifier_list_num
func export_googlesql_public_simple_catalog_ASTIdentifierList_identifier_list_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTIdentifierList_identifier_list
//go:linkname export_googlesql_public_simple_catalog_ASTIdentifierList_identifier_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTIdentifierList_identifier_list
func export_googlesql_public_simple_catalog_ASTIdentifierList_identifier_list(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTVariableDeclaration_variable_list
//go:linkname export_googlesql_public_simple_catalog_ASTVariableDeclaration_variable_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTVariableDeclaration_variable_list
func export_googlesql_public_simple_catalog_ASTVariableDeclaration_variable_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTVariableDeclaration_type
//go:linkname export_googlesql_public_simple_catalog_ASTVariableDeclaration_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTVariableDeclaration_type
func export_googlesql_public_simple_catalog_ASTVariableDeclaration_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTVariableDeclaration_default_value
//go:linkname export_googlesql_public_simple_catalog_ASTVariableDeclaration_default_value github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTVariableDeclaration_default_value
func export_googlesql_public_simple_catalog_ASTVariableDeclaration_default_value(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUntilClause_condition
//go:linkname export_googlesql_public_simple_catalog_ASTUntilClause_condition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUntilClause_condition
func export_googlesql_public_simple_catalog_ASTUntilClause_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTUntilClause_repeat_stmt
//go:linkname export_googlesql_public_simple_catalog_ASTUntilClause_repeat_stmt github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTUntilClause_repeat_stmt
func export_googlesql_public_simple_catalog_ASTUntilClause_repeat_stmt(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBreakContinueStatement_label
//go:linkname export_googlesql_public_simple_catalog_ASTBreakContinueStatement_label github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBreakContinueStatement_label
func export_googlesql_public_simple_catalog_ASTBreakContinueStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTBreakContinueStatement_set_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTBreakContinueStatement_set_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBreakContinueStatement_set_keyword
func export_googlesql_public_simple_catalog_ASTBreakContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTBreakContinueStatement_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTBreakContinueStatement_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBreakContinueStatement_keyword
func export_googlesql_public_simple_catalog_ASTBreakContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTBreakStatement_set_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTBreakStatement_set_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBreakStatement_set_keyword
func export_googlesql_public_simple_catalog_ASTBreakStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTBreakStatement_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTBreakStatement_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTBreakStatement_keyword
func export_googlesql_public_simple_catalog_ASTBreakStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTContinueStatement_set_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTContinueStatement_set_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTContinueStatement_set_keyword
func export_googlesql_public_simple_catalog_ASTContinueStatement_set_keyword(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTContinueStatement_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTContinueStatement_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTContinueStatement_keyword
func export_googlesql_public_simple_catalog_ASTContinueStatement_keyword(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropPrivilegeRestrictionStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropPrivilegeRestrictionStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_privileges
//go:linkname export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_privileges github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropPrivilegeRestrictionStatement_privileges
func export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_object_type
//go:linkname export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_object_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropPrivilegeRestrictionStatement_object_type
func export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_name_path
//go:linkname export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_name_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropPrivilegeRestrictionStatement_name_path
func export_googlesql_public_simple_catalog_ASTDropPrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropRowAccessPolicyStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropRowAccessPolicyStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_table_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_table_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropRowAccessPolicyStatement_table_name
func export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropRowAccessPolicyStatement_name
func export_googlesql_public_simple_catalog_ASTDropRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_privileges
//go:linkname export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_privileges github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreatePrivilegeRestrictionStatement_privileges
func export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_object_type
//go:linkname export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_object_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreatePrivilegeRestrictionStatement_object_type
func export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_name_path
//go:linkname export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_name_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreatePrivilegeRestrictionStatement_name_path
func export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_name_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_restrict_to
//go:linkname export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_restrict_to github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreatePrivilegeRestrictionStatement_restrict_to
func export_googlesql_public_simple_catalog_ASTCreatePrivilegeRestrictionStatement_restrict_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_set_has_access_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_set_has_access_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateRowAccessPolicyStatement_set_has_access_keyword
func export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_set_has_access_keyword(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_has_access_keyword
//go:linkname export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_has_access_keyword github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateRowAccessPolicyStatement_has_access_keyword
func export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_has_access_keyword(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_target_path
//go:linkname export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_target_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateRowAccessPolicyStatement_target_path
func export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_target_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_grant_to
//go:linkname export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_grant_to github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateRowAccessPolicyStatement_grant_to
func export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_grant_to(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_filter_using
//go:linkname export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_filter_using github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateRowAccessPolicyStatement_filter_using
func export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_filter_using(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateRowAccessPolicyStatement_name
func export_googlesql_public_simple_catalog_ASTCreateRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTDropStatement_set_drop_mode
//go:linkname export_googlesql_public_simple_catalog_ASTDropStatement_set_drop_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropStatement_set_drop_mode
func export_googlesql_public_simple_catalog_ASTDropStatement_set_drop_mode(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropStatement_drop_mode
//go:linkname export_googlesql_public_simple_catalog_ASTDropStatement_drop_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropStatement_drop_mode
func export_googlesql_public_simple_catalog_ASTDropStatement_drop_mode(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTDropStatement_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropStatement_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropStatement_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropStatement_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropStatement_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTDropStatement_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropStatement_is_if_exists
func export_googlesql_public_simple_catalog_ASTDropStatement_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTDropStatement_set_schema_object_kind
//go:linkname export_googlesql_public_simple_catalog_ASTDropStatement_set_schema_object_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropStatement_set_schema_object_kind
func export_googlesql_public_simple_catalog_ASTDropStatement_set_schema_object_kind(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTDropStatement_schema_object_kind
//go:linkname export_googlesql_public_simple_catalog_ASTDropStatement_schema_object_kind github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropStatement_schema_object_kind
func export_googlesql_public_simple_catalog_ASTDropStatement_schema_object_kind(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTDropStatemnt_name
//go:linkname export_googlesql_public_simple_catalog_ASTDropStatemnt_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTDropStatemnt_name
func export_googlesql_public_simple_catalog_ASTDropStatemnt_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSingleAssignment_variable
//go:linkname export_googlesql_public_simple_catalog_ASTSingleAssignment_variable github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSingleAssignment_variable
func export_googlesql_public_simple_catalog_ASTSingleAssignment_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSingleAssignment_expression
//go:linkname export_googlesql_public_simple_catalog_ASTSingleAssignment_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSingleAssignment_expression
func export_googlesql_public_simple_catalog_ASTSingleAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTParameterAssignment_parameter
//go:linkname export_googlesql_public_simple_catalog_ASTParameterAssignment_parameter github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTParameterAssignment_parameter
func export_googlesql_public_simple_catalog_ASTParameterAssignment_parameter(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTParameterAssignment_expression
//go:linkname export_googlesql_public_simple_catalog_ASTParameterAssignment_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTParameterAssignment_expression
func export_googlesql_public_simple_catalog_ASTParameterAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSystemVariableAssignment_system_variable
//go:linkname export_googlesql_public_simple_catalog_ASTSystemVariableAssignment_system_variable github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSystemVariableAssignment_system_variable
func export_googlesql_public_simple_catalog_ASTSystemVariableAssignment_system_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTSystemVariableAssignment_expression
//go:linkname export_googlesql_public_simple_catalog_ASTSystemVariableAssignment_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTSystemVariableAssignment_expression
func export_googlesql_public_simple_catalog_ASTSystemVariableAssignment_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAssignmentFromStruct_variables
//go:linkname export_googlesql_public_simple_catalog_ASTAssignmentFromStruct_variables github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAssignmentFromStruct_variables
func export_googlesql_public_simple_catalog_ASTAssignmentFromStruct_variables(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAssignmentFromStruct_struct_expression
//go:linkname export_googlesql_public_simple_catalog_ASTAssignmentFromStruct_struct_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAssignmentFromStruct_struct_expression
func export_googlesql_public_simple_catalog_ASTAssignmentFromStruct_struct_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStmtBase_name
func export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_table_element_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_table_element_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStmtBase_table_element_list
func export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_table_element_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStmtBase_options_list
func export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_like_table_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_like_table_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStmtBase_like_table_name
func export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_like_table_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_collate
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_collate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStmtBase_collate
func export_googlesql_public_simple_catalog_ASTCreateTableStmtBase_collate(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStatement_clone_data_source
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStatement_clone_data_source github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStatement_clone_data_source
func export_googlesql_public_simple_catalog_ASTCreateTableStatement_clone_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStatement_copy_data_source
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStatement_copy_data_source github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStatement_copy_data_source
func export_googlesql_public_simple_catalog_ASTCreateTableStatement_copy_data_source(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStatement_partition_by
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStatement_partition_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStatement_partition_by
func export_googlesql_public_simple_catalog_ASTCreateTableStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStatement_cluster_by
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStatement_cluster_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStatement_cluster_by
func export_googlesql_public_simple_catalog_ASTCreateTableStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableStatement_query
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableStatement_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableStatement_query
func export_googlesql_public_simple_catalog_ASTCreateTableStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateExternalTableStatement_with_partition_columns_clause
//go:linkname export_googlesql_public_simple_catalog_ASTCreateExternalTableStatement_with_partition_columns_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateExternalTableStatement_with_partition_columns_clause
func export_googlesql_public_simple_catalog_ASTCreateExternalTableStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateExternalTableStatement_with_connection_clause
//go:linkname export_googlesql_public_simple_catalog_ASTCreateExternalTableStatement_with_connection_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateExternalTableStatement_with_connection_clause
func export_googlesql_public_simple_catalog_ASTCreateExternalTableStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_name
//go:linkname export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateViewStatementBase_name
func export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_column_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_column_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateViewStatementBase_column_list
func export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_column_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateViewStatementBase_options_list
func export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_query
//go:linkname export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateViewStatementBase_query
func export_googlesql_public_simple_catalog_ASTCreateViewStatementBase_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateMaterializedViewStatement_partition_by
//go:linkname export_googlesql_public_simple_catalog_ASTCreateMaterializedViewStatement_partition_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateMaterializedViewStatement_partition_by
func export_googlesql_public_simple_catalog_ASTCreateMaterializedViewStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateMaterializedViewStatement_cluster_by
//go:linkname export_googlesql_public_simple_catalog_ASTCreateMaterializedViewStatement_cluster_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateMaterializedViewStatement_cluster_by
func export_googlesql_public_simple_catalog_ASTCreateMaterializedViewStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLoopStatement_label
//go:linkname export_googlesql_public_simple_catalog_ASTLoopStatement_label github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLoopStatement_label
func export_googlesql_public_simple_catalog_ASTLoopStatement_label(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLoopStatement_body
//go:linkname export_googlesql_public_simple_catalog_ASTLoopStatement_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLoopStatement_body
func export_googlesql_public_simple_catalog_ASTLoopStatement_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLoopStatement_IsLoopStatement
//go:linkname export_googlesql_public_simple_catalog_ASTLoopStatement_IsLoopStatement github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLoopStatement_IsLoopStatement
func export_googlesql_public_simple_catalog_ASTLoopStatement_IsLoopStatement(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTWhileStatement_condition
//go:linkname export_googlesql_public_simple_catalog_ASTWhileStatement_condition github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTWhileStatement_condition
func export_googlesql_public_simple_catalog_ASTWhileStatement_condition(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTRepeatStatement_until_clause
//go:linkname export_googlesql_public_simple_catalog_ASTRepeatStatement_until_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTRepeatStatement_until_clause
func export_googlesql_public_simple_catalog_ASTRepeatStatement_until_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForInStatement_variable
//go:linkname export_googlesql_public_simple_catalog_ASTForInStatement_variable github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForInStatement_variable
func export_googlesql_public_simple_catalog_ASTForInStatement_variable(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTForInStatement_query
//go:linkname export_googlesql_public_simple_catalog_ASTForInStatement_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTForInStatement_query
func export_googlesql_public_simple_catalog_ASTForInStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterStatementBase_set_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterStatementBase_set_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterStatementBase_set_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterStatementBase_set_is_if_exists(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAlterStatementBase_is_if_exists
//go:linkname export_googlesql_public_simple_catalog_ASTAlterStatementBase_is_if_exists github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterStatementBase_is_if_exists
func export_googlesql_public_simple_catalog_ASTAlterStatementBase_is_if_exists(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTAlterStatementBase_path
//go:linkname export_googlesql_public_simple_catalog_ASTAlterStatementBase_path github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterStatementBase_path
func export_googlesql_public_simple_catalog_ASTAlterStatementBase_path(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterStatementBase_action_list
//go:linkname export_googlesql_public_simple_catalog_ASTAlterStatementBase_action_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterStatementBase_action_list
func export_googlesql_public_simple_catalog_ASTAlterStatementBase_action_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterPrivilegeRestrictionStatement_privileges
//go:linkname export_googlesql_public_simple_catalog_ASTAlterPrivilegeRestrictionStatement_privileges github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterPrivilegeRestrictionStatement_privileges
func export_googlesql_public_simple_catalog_ASTAlterPrivilegeRestrictionStatement_privileges(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterPrivilegeRestrictionStatement_object_type
//go:linkname export_googlesql_public_simple_catalog_ASTAlterPrivilegeRestrictionStatement_object_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterPrivilegeRestrictionStatement_object_type
func export_googlesql_public_simple_catalog_ASTAlterPrivilegeRestrictionStatement_object_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterRowAccessPolicyStatement_name
//go:linkname export_googlesql_public_simple_catalog_ASTAlterRowAccessPolicyStatement_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterRowAccessPolicyStatement_name
func export_googlesql_public_simple_catalog_ASTAlterRowAccessPolicyStatement_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAlterEntityStatement_type
//go:linkname export_googlesql_public_simple_catalog_ASTAlterEntityStatement_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAlterEntityStatement_type
func export_googlesql_public_simple_catalog_ASTAlterEntityStatement_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_set_determinism_level
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_set_determinism_level github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_set_determinism_level
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_set_determinism_level(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_determinism_level
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_determinism_level github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_determinism_level
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_determinism_level(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_set_sql_security
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_set_sql_security github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_set_sql_security
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_set_sql_security(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_sql_security
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_sql_security github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_sql_security
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_sql_security(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_function_declaration
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_function_declaration github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_function_declaration
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_function_declaration(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_language
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_language github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_language
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_language(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_code
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_code github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_code
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_code(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStmtBase_options_list
func export_googlesql_public_simple_catalog_ASTCreateFunctionStmtBase_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_set_is_aggregate
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_set_is_aggregate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStatement_set_is_aggregate
func export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_set_is_aggregate(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_is_aggregate
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_is_aggregate github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStatement_is_aggregate
func export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_is_aggregate(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_set_is_remote
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_set_is_remote github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStatement_set_is_remote
func export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_set_is_remote(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_is_remote
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_is_remote github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStatement_is_remote
func export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_is_remote(arg0 unsafe.Pointer, arg1 *C.char)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_return_type
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_return_type github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStatement_return_type
func export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_return_type(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_sql_function_body
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_sql_function_body github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStatement_sql_function_body
func export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_sql_function_body(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_with_connection_clause
//go:linkname export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_with_connection_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateFunctionStatement_with_connection_clause
func export_googlesql_public_simple_catalog_ASTCreateFunctionStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableFunctionStatement_return_tvf_schema
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableFunctionStatement_return_tvf_schema github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableFunctionStatement_return_tvf_schema
func export_googlesql_public_simple_catalog_ASTCreateTableFunctionStatement_return_tvf_schema(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTCreateTableFunctionStatement_query
//go:linkname export_googlesql_public_simple_catalog_ASTCreateTableFunctionStatement_query github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTCreateTableFunctionStatement_query
func export_googlesql_public_simple_catalog_ASTCreateTableFunctionStatement_query(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTStructColumnSchema_struct_fields_num
//go:linkname export_googlesql_public_simple_catalog_ASTStructColumnSchema_struct_fields_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructColumnSchema_struct_fields_num
func export_googlesql_public_simple_catalog_ASTStructColumnSchema_struct_fields_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTStructColumnSchema_struct_field
//go:linkname export_googlesql_public_simple_catalog_ASTStructColumnSchema_struct_field github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTStructColumnSchema_struct_field
func export_googlesql_public_simple_catalog_ASTStructColumnSchema_struct_field(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExecuteIntoClause_identifiers
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteIntoClause_identifiers github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteIntoClause_identifiers
func export_googlesql_public_simple_catalog_ASTExecuteIntoClause_identifiers(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExecuteUsingArgument_expression
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteUsingArgument_expression github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteUsingArgument_expression
func export_googlesql_public_simple_catalog_ASTExecuteUsingArgument_expression(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExecuteUsingArgument_alias
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteUsingArgument_alias github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteUsingArgument_alias
func export_googlesql_public_simple_catalog_ASTExecuteUsingArgument_alias(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExecuteUsingClause_arguments_num
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteUsingClause_arguments_num github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteUsingClause_arguments_num
func export_googlesql_public_simple_catalog_ASTExecuteUsingClause_arguments_num(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTExecuteUsingClause_argument
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteUsingClause_argument github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteUsingClause_argument
func export_googlesql_public_simple_catalog_ASTExecuteUsingClause_argument(arg0 unsafe.Pointer, arg1 C.int, arg2 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_sql
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_sql github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteImmediateStatement_sql
func export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_sql(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_into_clause
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_into_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteImmediateStatement_into_clause
func export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_into_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_using_clause
//go:linkname export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_using_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTExecuteImmediateStatement_using_clause
func export_googlesql_public_simple_catalog_ASTExecuteImmediateStatement_using_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataFromFilesOptionsList_options_list
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataFromFilesOptionsList_options_list github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataFromFilesOptionsList_options_list
func export_googlesql_public_simple_catalog_ASTAuxLoadDataFromFilesOptionsList_options_list(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_set_insertion_mode
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_set_insertion_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataStatement_set_insertion_mode
func export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_set_insertion_mode(arg0 unsafe.Pointer, arg1 C.int)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_insertion_mode
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_insertion_mode github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataStatement_insertion_mode
func export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_insertion_mode(arg0 unsafe.Pointer, arg1 *C.int)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_partition_by
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_partition_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataStatement_partition_by
func export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_partition_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_cluster_by
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_cluster_by github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataStatement_cluster_by
func export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_cluster_by(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_from_files
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_from_files github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataStatement_from_files
func export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_from_files(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_with_partition_columns_clause
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_with_partition_columns_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataStatement_with_partition_columns_clause
func export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_with_partition_columns_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_with_connection_clause
//go:linkname export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_with_connection_clause github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTAuxLoadDataStatement_with_connection_clause
func export_googlesql_public_simple_catalog_ASTAuxLoadDataStatement_with_connection_clause(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_ASTLabel_name
//go:linkname export_googlesql_public_simple_catalog_ASTLabel_name github.com/goccy/go-zetasql/internal/ccall/go-zetasql/parser/parser.parser_ASTLabel_name
func export_googlesql_public_simple_catalog_ASTLabel_name(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_GoCatalog_new
//go:linkname export_googlesql_public_simple_catalog_GoCatalog_new github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/catalog.catalog_GoCatalog_new
func export_googlesql_public_simple_catalog_GoCatalog_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)

//export export_googlesql_public_simple_catalog_GoTable_new
//go:linkname export_googlesql_public_simple_catalog_GoTable_new github.com/goccy/go-zetasql/internal/ccall/go-zetasql/public/catalog.catalog_GoTable_new
func export_googlesql_public_simple_catalog_GoTable_new(arg0 unsafe.Pointer, arg1 *unsafe.Pointer)
