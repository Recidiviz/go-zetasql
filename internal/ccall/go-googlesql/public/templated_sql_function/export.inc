#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_TEMPLATED_SQL_FUNCTION_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_TEMPLATED_SQL_FUNCTION_EXPORT_H

#include "googlesql/public/templated_sql_function.h"
// include sources
#define module_initialization_complete googlesql_public_templated_sql_function_googlesql_public_templated_sql_function_module_initialization_complete
#include "googlesql/public/templated_sql_function.cc"
#undef module_initialization_complete
// include dependencies
#include "go-googlesql/public/error_location_cc_proto/export.inc"
#include "go-googlesql/public/function/export.inc"
#include "go-googlesql/public/parse_resume_location/export.inc"
#include "go-googlesql/public/type/export.inc"
#include "go-googlesql/base/base/export.inc"
#include "go-googlesql/base/check/export.inc"
#include "go-googlesql/base/ret_check/export.inc"
#include "go-googlesql/base/status/export.inc"
#include "go-googlesql/proto/function_cc_proto/export.inc"
#include "go-googlesql/proto/internal_error_location_cc_proto/export.inc"
#include "go-googlesql/public/types/types/export.inc"
#include "go-googlesql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
