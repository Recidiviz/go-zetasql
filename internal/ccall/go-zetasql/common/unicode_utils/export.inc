#ifndef INTERNAL_CCALL_GO_ZETASQL_COMMON_UNICODE_UTILS_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_COMMON_UNICODE_UTILS_EXPORT_H

#include "zetasql/common/unicode_utils.h"
// include sources
#ifndef ZETASQL_OMIT_UNICODE_UTILS_CC
#include "zetasql/common/unicode_utils.cc"
#endif
// include dependencies
#include "go-zetasql/base/base/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/log/log/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-icu/icu/export.inc"

#endif
