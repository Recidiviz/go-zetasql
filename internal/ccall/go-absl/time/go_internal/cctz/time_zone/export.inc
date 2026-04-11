#ifndef INTERNAL_CCALL_GO_ABSL_TIME_GO_INTERNAL_CCTZ_TIME_ZONE_EXPORT_H
#define INTERNAL_CCALL_GO_ABSL_TIME_GO_INTERNAL_CCTZ_TIME_ZONE_EXPORT_H

#include "absl/time/internal/cctz/include/cctz/time_zone.h"
#include "absl/time/internal/cctz/include/cctz/zone_info_source.h"
// include sources
#include "absl/time/internal/cctz/src/time_zone_fixed.cc"
#include "absl/time/internal/cctz/src/time_zone_fixed.h"
#include "absl/time/internal/cctz/src/time_zone_format.cc"
#include "absl/time/internal/cctz/src/time_zone_if.cc"
#include "absl/time/internal/cctz/src/time_zone_if.h"
#include "absl/time/internal/cctz/src/time_zone_impl.cc"
#include "absl/time/internal/cctz/src/time_zone_impl.h"
#include "absl/time/internal/cctz/src/time_zone_info.cc"
#include "absl/time/internal/cctz/src/time_zone_info.h"
#include "absl/time/internal/cctz/src/time_zone_libc.cc"
#include "absl/time/internal/cctz/src/time_zone_libc.h"
#include "absl/time/internal/cctz/src/time_zone_lookup.cc"
#define kDigits absl_time_internal_cctz_time_zone_absl_time_internal_cctz_src_time_zone_posix_kDigits
#include "absl/time/internal/cctz/src/time_zone_posix.cc"
#undef kDigits
#include "absl/time/internal/cctz/src/time_zone_posix.h"
#include "absl/time/internal/cctz/src/tzfile.h"
#include "absl/time/internal/cctz/src/zone_info_source.cc"
// include dependencies
#include "go-absl/time/go_internal/cctz/civil_time/export.inc"
#include "go-absl/base/config/export.inc"

#endif
