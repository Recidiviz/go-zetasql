#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TEMPLATED_SQL_TVF_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TEMPLATED_SQL_TVF_EXPORT_H

#include "zetasql/public/templated_sql_tvf.h"
// include sources
#define module_initialization_complete zetasql_public_templated_sql_tvf_module_initialization_complete
#include "zetasql/public/templated_sql_tvf.cc"
#undef module_initialization_complete
// include dependencies
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/cycle_detector/export.inc"
#include "go-zetasql/public/deprecation_warning_cc_proto/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/function/export.inc"
#include "go-zetasql/public/function_cc_proto/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/simple_table_cc_proto/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/analyzer/name_scope/export.inc"
#include "go-zetasql/analyzer/resolver/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/status_payload_utils/export.inc"
#include "go-zetasql/parser/parser/export.inc"
#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
