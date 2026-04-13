#ifndef INTERNAL_CCALL_GO_ABSL_BASE_BASE_EXPORT_H
#define INTERNAL_CCALL_GO_ABSL_BASE_BASE_EXPORT_H

#include "absl/base/call_once.h"
#include "absl/base/casts.h"
#include "absl/base/internal/cycleclock.h"
#include "absl/base/internal/low_level_scheduling.h"
#include "absl/base/internal/per_thread_tls.h"
#include "absl/base/internal/spinlock.h"
#include "absl/base/internal/sysinfo.h"
#include "absl/base/internal/thread_identity.h"
#include "absl/base/internal/tsan_mutex_interface.h"
#include "absl/base/internal/unscaledcycleclock.h"
// include sources
#include "absl/base/internal/cycleclock.cc"
#include "absl/base/internal/spinlock.cc"
#include "absl/base/internal/sysinfo.cc"
#include "absl/base/internal/thread_identity.cc"
#include "absl/base/internal/unscaledcycleclock.cc"
// include dependencies
#include "go-absl/base/atomic_hook/export.inc"
#include "go-absl/base/base_internal/export.inc"
#include "go-absl/base/config/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/cycleclock_internal/export.inc"
#include "go-absl/base/dynamic_annotations/export.inc"
#include "go-absl/base/log_severity/export.inc"
#include "go-absl/base/nullability/export.inc"
#include "go-absl/base/raw_logging_internal/export.inc"
#include "go-absl/base/spinlock_wait/export.inc"
#include "go-absl/meta/type_traits/export.inc"

#endif
