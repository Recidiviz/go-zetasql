#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_TEMPLATED_SQL_TVF_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_TEMPLATED_SQL_TVF_EXPORT_H

#include "googlesql/public/templated_sql_tvf.h"
// include sources
#define module_initialization_complete googlesql_public_templated_sql_tvf_googlesql_public_templated_sql_tvf_module_initialization_complete
#include "googlesql/public/templated_sql_tvf.cc"
#undef module_initialization_complete
// include dependencies
#include "go-googlesql/public/catalog/export.inc"
#include "go-googlesql/public/cycle_detector/export.inc"
#include "go-googlesql/public/deprecation_warning_cc_proto/export.inc"
#include "go-googlesql/public/error_helpers/export.inc"
#include "go-googlesql/public/error_location_cc_proto/export.inc"
#include "go-googlesql/public/function/export.inc"
#include "go-googlesql/public/function_cc_proto/export.inc"
#include "go-googlesql/public/id_string/export.inc"
#include "go-googlesql/public/options_cc_proto/export.inc"
#include "go-googlesql/public/parse_location/export.inc"
#include "go-googlesql/public/parse_resume_location/export.inc"
#include "go-googlesql/public/simple_table_cc_proto/export.inc"
#include "go-googlesql/public/strings/export.inc"
#include "go-googlesql/public/type/export.inc"
#include "go-googlesql/analyzer/name_scope/export.inc"
#include "go-googlesql/analyzer/resolver/export.inc"
#include "go-googlesql/base/base/export.inc"
#include "go-googlesql/base/map_util/export.inc"
#include "go-googlesql/base/ret_check/export.inc"
#include "go-googlesql/base/status/export.inc"
#include "go-googlesql/common/errors/export.inc"
#include "go-googlesql/common/status_payload_utils/export.inc"
#include "go-googlesql/parser/parser/export.inc"
#include "go-googlesql/proto/function_cc_proto/export.inc"
#include "go-googlesql/proto/internal_error_location_cc_proto/export.inc"
#include "go-googlesql/public/types/types/export.inc"
#include "go-googlesql/resolved_ast/resolved_ast/export.inc"
#include "go-googlesql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-googlesql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
