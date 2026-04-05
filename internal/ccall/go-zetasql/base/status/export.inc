#ifndef INTERNAL_CCALL_GO_ZETASQL_BASE_STATUS_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_BASE_STATUS_EXPORT_H

#include "zetasql/base/canonical_errors.h"
#include "zetasql/base/status.h"
#include "zetasql/base/status_builder.h"
#include "zetasql/base/status_macros.h"
#include "zetasql/base/status_payload.h"
// include sources
#include "zetasql/base/status_builder.cc"
#include "zetasql/base/status_payload.cc"
// include dependencies
#include "go-zetasql/base/logging/export.inc"
#include "go-zetasql/base/source_location/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/base/log_severity/export.inc"
#include "go-absl/log/log/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/cord/export.inc"

#endif
