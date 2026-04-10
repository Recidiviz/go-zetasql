#ifndef INTERNAL_CCALL_GO_ABSL_TIME_GO_INTERNAL_CCTZ_CIVIL_TIME_EXPORT_H
#define INTERNAL_CCALL_GO_ABSL_TIME_GO_INTERNAL_CCTZ_CIVIL_TIME_EXPORT_H

#include "absl/time/internal/cctz/include/cctz/civil_time.h"
// civil_time_detail.cc is linked from libprotobuf_cgo.a only; including it here duplicates the TU in
// time_zone/time binds and triggers ODR violations under -Wl,--allow-multiple-definition.
// include dependencies
#include "go-absl/base/config/export.inc"

#endif
