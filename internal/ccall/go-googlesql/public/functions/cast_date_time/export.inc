#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_FUNCTIONS_CAST_DATE_TIME_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_FUNCTIONS_CAST_DATE_TIME_EXPORT_H

#include "googlesql/public/functions/cast_date_time.h"
// include sources
#define powers_of_ten googlesql_public_functions_cast_date_time_googlesql_public_functions_cast_date_time_powers_of_ten
#define kNaiveNumSecondsPerMinute googlesql_public_functions_cast_date_time_googlesql_public_functions_cast_date_time_kNaiveNumSecondsPerMinute
#define kNaiveNumSecondsPerHour googlesql_public_functions_cast_date_time_googlesql_public_functions_cast_date_time_kNaiveNumSecondsPerHour
#define kNaiveNumSecondsPerDay googlesql_public_functions_cast_date_time_googlesql_public_functions_cast_date_time_kNaiveNumSecondsPerDay
#define kNaiveNumMicrosPerDay googlesql_public_functions_cast_date_time_googlesql_public_functions_cast_date_time_kNaiveNumMicrosPerDay
#include "googlesql/public/functions/cast_date_time.cc"
#undef kNaiveNumMicrosPerDay
#undef kNaiveNumSecondsPerDay
#undef kNaiveNumSecondsPerHour
#undef kNaiveNumSecondsPerMinute
#undef powers_of_ten
// include dependencies
#include "go-googlesql/public/functions/date_time_util/export.inc"
#include "go-googlesql/public/functions/datetime_cc_proto/export.inc"
#include "go-googlesql/public/functions/input_format_string_max_width/export.inc"
#include "go-googlesql/public/functions/parse_date_time_utils/export.inc"
#include "go-googlesql/base/base/export.inc"
#include "go-googlesql/base/general_trie/export.inc"
#include "go-googlesql/base/map_util/export.inc"
#include "go-googlesql/base/mathutil/export.inc"
#include "go-googlesql/base/ret_check/export.inc"
#include "go-googlesql/base/status/export.inc"
#include "go-googlesql/common/errors/export.inc"
#include "go-googlesql/common/utf_util/export.inc"
#include "go-googlesql/public/civil_time/export.inc"
#include "go-googlesql/public/pico_time/export.inc"
#include "go-googlesql/public/strings/export.inc"
#include "go-googlesql/public/type/export.inc"
#include "go-googlesql/public/type_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-icu/icu/export.inc"

#endif
