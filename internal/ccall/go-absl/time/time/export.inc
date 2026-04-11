#ifndef INTERNAL_CCALL_GO_ABSL_TIME_TIME_EXPORT_H
#define INTERNAL_CCALL_GO_ABSL_TIME_TIME_EXPORT_H

#include "absl/time/civil_time.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"
// include sources
#include "absl/time/civil_time.cc"
#include "absl/time/clock.cc"
#include "absl/time/duration.cc"
#include "absl/time/format.cc"
#define unix_epoch absl_time_time_absl_time_time_unix_epoch
#include "absl/time/time.cc"
#undef unix_epoch
// include dependencies
#include "go-absl/base/base/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/numeric/int128/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/go_internal/cctz/civil_time/export.inc"
#include "go-absl/time/go_internal/cctz/time_zone/export.inc"
#include "go-absl/types/optional/export.inc"

#endif
