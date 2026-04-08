#ifndef INTERNAL_CCALL_GO_ZETASQL_LEGACY_ZETASQL_ANALYZER_ALL_REWRITERS_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_LEGACY_ZETASQL_ANALYZER_ALL_REWRITERS_EXPORT_H

#include "googlesql/legacy_zetasql/analyzer/all_rewriters.h"
// include sources
#include "googlesql/legacy_zetasql/analyzer/all_rewriters.cc"
// include dependencies
#include "go-zetasql/analyzer/rewriters/aggregation_threshold_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/anonymization_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/builtin_function_inliner/export.inc"
#include "go-zetasql/analyzer/rewriters/flatten_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/generalized_query_stmt_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/grouping_set_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/insert_dml_values_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/is_first_is_last_function_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/like_any_all_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/map_function_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/match_recognize_function_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/measure_type_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/multiway_unnest_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/nulliferror_function_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/order_by_and_limit_in_aggregate_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/pipe_assert_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/pipe_if_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/pivot_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/registration/export.inc"
#include "go-zetasql/analyzer/rewriters/sql_function_inliner/export.inc"
#include "go-zetasql/analyzer/rewriters/sql_view_inliner/export.inc"
#include "go-zetasql/analyzer/rewriters/typeof_function_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/unpivot_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/update_constructor_rewriter/export.inc"
#include "go-zetasql/analyzer/rewriters/with_expr_rewriter/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-absl/base/base/export.inc"

#endif
