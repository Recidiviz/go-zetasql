#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_CAST_DATE_TIME_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_CAST_DATE_TIME_EXPORT_H

#include "zetasql/public/functions/cast_date_time.h"
// include sources
#define powers_of_ten zetasql_public_functions_cast_date_time_powers_of_ten
#define kNaiveNumSecondsPerMinute zetasql_public_functions_cast_date_time_kNaiveNumSecondsPerMinute
#define kNaiveNumSecondsPerHour zetasql_public_functions_cast_date_time_kNaiveNumSecondsPerHour
#define kNaiveNumSecondsPerDay zetasql_public_functions_cast_date_time_kNaiveNumSecondsPerDay
#define kNaiveNumMicrosPerDay zetasql_public_functions_cast_date_time_kNaiveNumMicrosPerDay
#include "zetasql/public/functions/cast_date_time.cc"
#undef kNaiveNumMicrosPerDay
#undef kNaiveNumSecondsPerDay
#undef kNaiveNumSecondsPerHour
#undef kNaiveNumSecondsPerMinute
#undef powers_of_ten
// include dependencies
#include "go-zetasql/public/functions/date_time_util/export.inc"
#include "go-zetasql/public/functions/datetime_cc_proto/export.inc"
#include "go-zetasql/public/functions/input_format_string_max_width/export.inc"
#include "go-zetasql/public/functions/parse_date_time_utils/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/general_trie/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/mathutil/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-icu/icu/export.inc"

#endif
