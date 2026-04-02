#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TEMPLATED_SQL_FUNCTION_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TEMPLATED_SQL_FUNCTION_EXPORT_H

#include "zetasql/public/templated_sql_function.h"
// include sources
#define module_initialization_complete zetasql_public_templated_sql_function_module_initialization_complete
#include "zetasql/public/templated_sql_function.cc"
#undef module_initialization_complete
// include dependencies
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
