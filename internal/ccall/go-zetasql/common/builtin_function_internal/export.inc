#ifndef INTERNAL_CCALL_GO_ZETASQL_COMMON_BUILTIN_FUNCTION_INTERNAL_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_COMMON_BUILTIN_FUNCTION_INTERNAL_EXPORT_H

#include "zetasql/common/builtin_function_internal.h"
// include sources
#define SetDefinitionForInlining zetasql_common_builtin_function_internal_array_SetDefinitionForInlining
#include "zetasql/common/builtin_function_array.cc"
#undef SetDefinitionForInlining
#include "zetasql/common/builtin_function_internal_1.cc"
#include "zetasql/common/builtin_function_internal_2.cc"
#define SetDefinitionForInlining zetasql_common_builtin_function_internal_internal3_SetDefinitionForInlining
#include "zetasql/common/builtin_function_internal_3.cc"
#undef SetDefinitionForInlining
#include "zetasql/common/builtin_function_range.cc"
// include dependencies
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/proto/anon_output_with_report_cc_proto/export.inc"
#include "go-zetasql/proto/options_cc_proto/export.inc"
#include "go-zetasql/public/anon_function/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/public/builtin_function_options/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/cycle_detector/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value/export.inc"
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/differential_privacy_cc_proto/export.inc"
#include "go-zetasql/public/functions/string_format/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/flat_hash_set/export.inc"
#include "go-absl/functional/bind_front/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-google/type/date_cc_proto/export.inc"
#include "go-google/type/timeofday_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
