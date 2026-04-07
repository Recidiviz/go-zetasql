//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// resolved_ast_rewrite_visitor.cc GENERATED FROM resolved_ast_rewrite_visitor.cc.template

#include "googlesql/resolved_ast/resolved_ast_rewrite_visitor.h"

#include <algorithm>
#include <memory>
#include <stack>
#include <utility>
#include <vector>

#include "googlesql/resolved_ast/resolved_ast.h"
#include "googlesql/resolved_ast/resolved_ast_builder.h"
#include "googlesql/resolved_ast/resolved_node.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "googlesql/base/ret_check.h"
#include "googlesql/base/status_macros.h"

namespace googlesql {

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedParameter> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedParameter(*node));
  ResolvedParameterBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedParameter(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExpressionColumn> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExpressionColumn(*node));
  ResolvedExpressionColumnBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExpressionColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnRef> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedColumnRef(*node));
  ResolvedColumnRefBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnRef(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedConstant> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedConstant(*node));
  ResolvedConstantBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedConstant(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyticFunctionCall> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAnalyticFunctionCall(*node));
  ResolvedAnalyticFunctionCallBuilder builder = ToBuilder(std::move(node));
  if (builder.window_frame() != nullptr) {
    std::unique_ptr<const ResolvedWindowFrame> tmp =
        builder.release_window_frame();
    absl::StatusOr<std::unique_ptr<const ResolvedWindowFrame>> result =
        Dispatch<std::unique_ptr<const ResolvedWindowFrame>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_window_frame(*std::move(result));
  }
  builder.set_type(DefaultVisit(builder.type()));
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_argument_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.generic_argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedFunctionArgument>> tmp =
        builder.release_generic_argument_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFunctionArgument>::element_type>(
                 std::move(tmp)));
    builder.set_generic_argument_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (builder.where_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_where_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_where_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAnalyticFunctionCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExtendedCast> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExtendedCast(*node));
  ResolvedExtendedCastBuilder builder = ToBuilder(std::move(node));
  if (!builder.element_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExtendedCastElement>> tmp =
        builder.release_element_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExtendedCastElement>::element_type>(
                 std::move(tmp)));
    builder.set_element_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExtendedCast(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMakeProtoField> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMakeProtoField(*node));
  ResolvedMakeProtoFieldBuilder builder = ToBuilder(std::move(node));
  if (builder.expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMakeProtoField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetStructField> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGetStructField(*node));
  ResolvedGetStructFieldBuilder builder = ToBuilder(std::move(node));
  if (builder.expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expr(*std::move(result));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGetStructField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFlatten> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFlatten(*node));
  ResolvedFlattenBuilder builder = ToBuilder(std::move(node));
  if (builder.expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expr(*std::move(result));
  }
  if (!builder.get_field_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_get_field_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_get_field_list(std::move(tmp));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFlatten(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSingleRowScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSingleRowScan(*node));
  ResolvedSingleRowScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSingleRowScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTableScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedTableScan(*node));
  ResolvedTableScanBuilder builder = ToBuilder(std::move(node));
  if (builder.for_system_time_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_for_system_time_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_for_system_time_expr(*std::move(result));
  }
  if (builder.lock_mode() != nullptr) {
    std::unique_ptr<const ResolvedLockMode> tmp =
        builder.release_lock_mode();
    absl::StatusOr<std::unique_ptr<const ResolvedLockMode>> result =
        Dispatch<std::unique_ptr<const ResolvedLockMode>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_lock_mode(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedTableScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRollup> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRollup(*node));
  ResolvedRollupBuilder builder = ToBuilder(std::move(node));
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetMultiColumn>> tmp =
        builder.release_rollup_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetMultiColumn>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRollup(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCube> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCube(*node));
  ResolvedCubeBuilder builder = ToBuilder(std::move(node));
  if (!builder.cube_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetMultiColumn>> tmp =
        builder.release_cube_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetMultiColumn>::element_type>(
                 std::move(tmp)));
    builder.set_cube_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCube(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregateScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAggregateScan(*node));
  ResolvedAggregateScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.group_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_group_by_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_aggregate_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  if (!builder.grouping_set_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_grouping_set_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_set_list(std::move(tmp));
  }
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_rollup_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  if (!builder.grouping_call_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingCall>> tmp =
        builder.release_grouping_call_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingCall>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_call_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregationThresholdAggregateScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAggregationThresholdAggregateScan(*node));
  ResolvedAggregationThresholdAggregateScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.group_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_group_by_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_aggregate_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  if (!builder.grouping_set_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_grouping_set_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_set_list(std::move(tmp));
  }
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_rollup_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  if (!builder.grouping_call_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingCall>> tmp =
        builder.release_grouping_call_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingCall>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_call_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAggregationThresholdAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOrderByScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedOrderByScan(*node));
  ResolvedOrderByScanBuilder builder = ToBuilder(std::move(node));
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.order_by_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOrderByItem>> tmp =
        builder.release_order_by_item_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOrderByItem>::element_type>(
                 std::move(tmp)));
    builder.set_order_by_item_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOrderByScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithRefScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWithRefScan(*node));
  ResolvedWithRefScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithRefScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedComputedColumn> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedComputedColumn(*node));
  ResolvedComputedColumnBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  if (builder.expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedComputedColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnDefinition> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedColumnDefinition(*node));
  ResolvedColumnDefinitionBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  if (builder.annotations() != nullptr) {
    std::unique_ptr<const ResolvedColumnAnnotations> tmp =
        builder.release_annotations();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnAnnotations>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnAnnotations>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_annotations(*std::move(result));
  }
  builder.set_column(DefaultVisit(builder.column()));
  if (builder.generated_column_info() != nullptr) {
    std::unique_ptr<const ResolvedGeneratedColumnInfo> tmp =
        builder.release_generated_column_info();
    absl::StatusOr<std::unique_ptr<const ResolvedGeneratedColumnInfo>> result =
        Dispatch<std::unique_ptr<const ResolvedGeneratedColumnInfo>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_generated_column_info(*std::move(result));
  }
  if (builder.default_value() != nullptr) {
    std::unique_ptr<const ResolvedColumnDefaultValue> tmp =
        builder.release_default_value();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnDefaultValue>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnDefaultValue>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_default_value(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnDefinition(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPrimaryKey> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPrimaryKey(*node));
  ResolvedPrimaryKeyBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPrimaryKey(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedForeignKey> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedForeignKey(*node));
  ResolvedForeignKeyBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedForeignKey(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOutputColumn> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedOutputColumn(*node));
  ResolvedOutputColumnBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOutputColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTVFScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedTVFScan(*node));
  ResolvedTVFScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedFunctionArgument>> tmp =
        builder.release_argument_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFunctionArgument>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedTVFScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupRowsScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGroupRowsScan(*node));
  ResolvedGroupRowsScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_input_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_input_column_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupRowsScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedStringWithLocation> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedStringWithLocation(*node));
  return PostVisitResolvedStringWithLocation(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedQueryStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedQueryStmt(*node));
  ResolvedQueryStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  if (builder.query() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_query();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_query(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedQueryStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMultiStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMultiStmt(*node));
  ResolvedMultiStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.statement_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedStatement>> tmp =
        builder.release_statement_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedStatement>::element_type>(
                 std::move(tmp)));
    builder.set_statement_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMultiStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateDatabaseStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateDatabaseStmt(*node));
  ResolvedCreateDatabaseStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateDatabaseStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedIndexItem> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedIndexItem(*node));
  ResolvedIndexItemBuilder builder = ToBuilder(std::move(node));
  if (builder.column_ref() != nullptr) {
    std::unique_ptr<const ResolvedColumnRef> tmp =
        builder.release_column_ref();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnRef>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnRef>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_column_ref(*std::move(result));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedIndexItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateIndexStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateIndexStmt(*node));
  ResolvedCreateIndexStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.table_scan() != nullptr) {
    std::unique_ptr<const ResolvedTableScan> tmp =
        builder.release_table_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedTableScan>> result =
        Dispatch<std::unique_ptr<const ResolvedTableScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_table_scan(*std::move(result));
  }
  if (!builder.index_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedIndexItem>> tmp =
        builder.release_index_item_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedIndexItem>::element_type>(
                 std::move(tmp)));
    builder.set_index_item_list(std::move(tmp));
  }
  if (!builder.storing_expression_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_storing_expression_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_storing_expression_list(std::move(tmp));
  }
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_partition_by_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.computed_columns_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_computed_columns_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_computed_columns_list(std::move(tmp));
  }
  if (!builder.unnest_expressions_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUnnestItem>> tmp =
        builder.release_unnest_expressions_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUnnestItem>::element_type>(
                 std::move(tmp)));
    builder.set_unnest_expressions_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateIndexStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateSchemaStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateSchemaStmt(*node));
  ResolvedCreateSchemaStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.collation_name() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_collation_name();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_collation_name(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateTableStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateTableStmt(*node));
  ResolvedCreateTableStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.clone_from() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_clone_from();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_clone_from(*std::move(result));
  }
  if (builder.copy_from() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_copy_from();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_copy_from(*std::move(result));
  }
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_partition_by_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.cluster_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_cluster_by_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_cluster_by_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  if (!builder.pseudo_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_pseudo_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_pseudo_column_list(std::move(tmp));
  }
  if (builder.primary_key() != nullptr) {
    std::unique_ptr<const ResolvedPrimaryKey> tmp =
        builder.release_primary_key();
    absl::StatusOr<std::unique_ptr<const ResolvedPrimaryKey>> result =
        Dispatch<std::unique_ptr<const ResolvedPrimaryKey>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_primary_key(*std::move(result));
  }
  if (!builder.foreign_key_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedForeignKey>> tmp =
        builder.release_foreign_key_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedForeignKey>::element_type>(
                 std::move(tmp)));
    builder.set_foreign_key_list(std::move(tmp));
  }
  if (!builder.check_constraint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedCheckConstraint>> tmp =
        builder.release_check_constraint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedCheckConstraint>::element_type>(
                 std::move(tmp)));
    builder.set_check_constraint_list(std::move(tmp));
  }
  if (builder.collation_name() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_collation_name();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_collation_name(*std::move(result));
  }
  if (builder.connection() != nullptr) {
    std::unique_ptr<const ResolvedConnection> tmp =
        builder.release_connection();
    absl::StatusOr<std::unique_ptr<const ResolvedConnection>> result =
        Dispatch<std::unique_ptr<const ResolvedConnection>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_connection(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateModelStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateModelStmt(*node));
  ResolvedCreateModelStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  if (builder.query() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_query();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_query(*std::move(result));
  }
  if (!builder.aliased_query_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedCreateModelAliasedQuery>> tmp =
        builder.release_aliased_query_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedCreateModelAliasedQuery>::element_type>(
                 std::move(tmp)));
    builder.set_aliased_query_list(std::move(tmp));
  }
  if (!builder.transform_input_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_transform_input_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_transform_input_column_list(std::move(tmp));
  }
  if (!builder.transform_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_transform_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_transform_list(std::move(tmp));
  }
  if (!builder.transform_output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_transform_output_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_transform_output_column_list(std::move(tmp));
  }
  if (!builder.transform_analytic_function_group_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAnalyticFunctionGroup>> tmp =
        builder.release_transform_analytic_function_group_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAnalyticFunctionGroup>::element_type>(
                 std::move(tmp)));
    builder.set_transform_analytic_function_group_list(std::move(tmp));
  }
  if (!builder.input_column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_input_column_definition_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_input_column_definition_list(std::move(tmp));
  }
  if (!builder.output_column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_output_column_definition_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_definition_list(std::move(tmp));
  }
  if (builder.connection() != nullptr) {
    std::unique_ptr<const ResolvedConnection> tmp =
        builder.release_connection();
    absl::StatusOr<std::unique_ptr<const ResolvedConnection>> result =
        Dispatch<std::unique_ptr<const ResolvedConnection>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_connection(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateModelStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExportDataStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExportDataStmt(*node));
  ResolvedExportDataStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.connection() != nullptr) {
    std::unique_ptr<const ResolvedConnection> tmp =
        builder.release_connection();
    absl::StatusOr<std::unique_ptr<const ResolvedConnection>> result =
        Dispatch<std::unique_ptr<const ResolvedConnection>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_connection(*std::move(result));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  if (builder.query() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_query();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_query(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExportDataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDefineTableStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDefineTableStmt(*node));
  ResolvedDefineTableStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDefineTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedBeginStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedBeginStmt(*node));
  ResolvedBeginStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedBeginStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRecursionDepthModifier> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRecursionDepthModifier(*node));
  ResolvedRecursionDepthModifierBuilder builder = ToBuilder(std::move(node));
  if (builder.lower_bound() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_lower_bound();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_lower_bound(*std::move(result));
  }
  if (builder.upper_bound() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_upper_bound();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_upper_bound(*std::move(result));
  }
  if (builder.recursion_depth_column() != nullptr) {
    std::unique_ptr<const ResolvedColumnHolder> tmp =
        builder.release_recursion_depth_column();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnHolder>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnHolder>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_recursion_depth_column(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRecursionDepthModifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowOrdering> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWindowOrdering(*node));
  ResolvedWindowOrderingBuilder builder = ToBuilder(std::move(node));
  if (!builder.order_by_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOrderByItem>> tmp =
        builder.release_order_by_item_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOrderByItem>::element_type>(
                 std::move(tmp)));
    builder.set_order_by_item_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWindowOrdering(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDMLDefault> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDMLDefault(*node));
  ResolvedDMLDefaultBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDMLDefault(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssertStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAssertStmt(*node));
  ResolvedAssertStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.expression() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expression();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expression(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssertStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateItem> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUpdateItem(*node));
  ResolvedUpdateItemBuilder builder = ToBuilder(std::move(node));
  if (builder.target() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_target();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_target(*std::move(result));
  }
  if (builder.set_value() != nullptr) {
    std::unique_ptr<const ResolvedDMLValue> tmp =
        builder.release_set_value();
    absl::StatusOr<std::unique_ptr<const ResolvedDMLValue>> result =
        Dispatch<std::unique_ptr<const ResolvedDMLValue>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_set_value(*std::move(result));
  }
  if (builder.element_column() != nullptr) {
    std::unique_ptr<const ResolvedColumnHolder> tmp =
        builder.release_element_column();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnHolder>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnHolder>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_element_column(*std::move(result));
  }
  if (!builder.update_item_element_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateItemElement>> tmp =
        builder.release_update_item_element_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateItemElement>::element_type>(
                 std::move(tmp)));
    builder.set_update_item_element_list(std::move(tmp));
  }
  if (!builder.delete_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedDeleteStmt>> tmp =
        builder.release_delete_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedDeleteStmt>::element_type>(
                 std::move(tmp)));
    builder.set_delete_list(std::move(tmp));
  }
  if (!builder.update_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateStmt>> tmp =
        builder.release_update_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateStmt>::element_type>(
                 std::move(tmp)));
    builder.set_update_list(std::move(tmp));
  }
  if (!builder.insert_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedInsertStmt>> tmp =
        builder.release_insert_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedInsertStmt>::element_type>(
                 std::move(tmp)));
    builder.set_insert_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterApproxViewStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterApproxViewStmt(*node));
  ResolvedAlterApproxViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterApproxViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterSchemaStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterSchemaStmt(*node));
  ResolvedAlterSchemaStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetOptionsAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSetOptionsAction(*node));
  ResolvedSetOptionsActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetOptionsAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterSubEntityAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterSubEntityAction(*node));
  ResolvedAlterSubEntityActionBuilder builder = ToBuilder(std::move(node));
  if (builder.alter_action() != nullptr) {
    std::unique_ptr<const ResolvedAlterAction> tmp =
        builder.release_alter_action();
    absl::StatusOr<std::unique_ptr<const ResolvedAlterAction>> result =
        Dispatch<std::unique_ptr<const ResolvedAlterAction>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_alter_action(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterSubEntityAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropSubEntityAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropSubEntityAction(*node));
  return PostVisitResolvedDropSubEntityAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddColumnAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAddColumnAction(*node));
  ResolvedAddColumnActionBuilder builder = ToBuilder(std::move(node));
  if (builder.column_definition() != nullptr) {
    std::unique_ptr<const ResolvedColumnDefinition> tmp =
        builder.release_column_definition();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnDefinition>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_column_definition(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddColumnAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddColumnIdentifierAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAddColumnIdentifierAction(*node));
  ResolvedAddColumnIdentifierActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.options_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_options_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_options_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddColumnIdentifierAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropPrimaryKeyAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropPrimaryKeyAction(*node));
  return PostVisitResolvedDropPrimaryKeyAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnSetGeneratedAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnSetGeneratedAction(*node));
  ResolvedAlterColumnSetGeneratedActionBuilder builder = ToBuilder(std::move(node));
  if (builder.generated_column_info() != nullptr) {
    std::unique_ptr<const ResolvedGeneratedColumnInfo> tmp =
        builder.release_generated_column_info();
    absl::StatusOr<std::unique_ptr<const ResolvedGeneratedColumnInfo>> result =
        Dispatch<std::unique_ptr<const ResolvedGeneratedColumnInfo>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_generated_column_info(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterColumnSetGeneratedAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnDropDefaultAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnDropDefaultAction(*node));
  return PostVisitResolvedAlterColumnDropDefaultAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRenameColumnAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRenameColumnAction(*node));
  return PostVisitResolvedRenameColumnAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRenameStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRenameStmt(*node));
  ResolvedRenameStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRenameStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreatePrivilegeRestrictionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreatePrivilegeRestrictionStmt(*node));
  ResolvedCreatePrivilegeRestrictionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_column_privilege_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_column_privilege_list(std::move(tmp));
  }
  if (!builder.restrictee_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_restrictee_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_restrictee_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreatePrivilegeRestrictionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropRowAccessPolicyStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropRowAccessPolicyStmt(*node));
  ResolvedDropRowAccessPolicyStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropRowAccessPolicyStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropIndexStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropIndexStmt(*node));
  ResolvedDropIndexStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropIndexStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterPrivilegeRestrictionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterPrivilegeRestrictionStmt(*node));
  ResolvedAlterPrivilegeRestrictionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_column_privilege_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_column_privilege_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterPrivilegeRestrictionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArgumentRef> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedArgumentRef(*node));
  ResolvedArgumentRefBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedArgumentRef(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateTableFunctionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateTableFunctionStmt(*node));
  ResolvedCreateTableFunctionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (builder.query() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_query();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_query(*std::move(result));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateTableFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregateHavingModifier> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAggregateHavingModifier(*node));
  ResolvedAggregateHavingModifierBuilder builder = ToBuilder(std::move(node));
  if (builder.having_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_having_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_having_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAggregateHavingModifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssignmentStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAssignmentStmt(*node));
  ResolvedAssignmentStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.target() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_target();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_target(*std::move(result));
  }
  if (builder.expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expr(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssignmentStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUnpivotScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUnpivotScan(*node));
  ResolvedUnpivotScanBuilder builder = ToBuilder(std::move(node));
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.value_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_value_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_value_column_list(std::move(tmp));
  }
  builder.set_label_column(DefaultVisit(builder.label_column()));
  if (!builder.label_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedLiteral>> tmp =
        builder.release_label_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedLiteral>::element_type>(
                 std::move(tmp)));
    builder.set_label_list(std::move(tmp));
  }
  if (!builder.unpivot_arg_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUnpivotArg>> tmp =
        builder.release_unpivot_arg_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUnpivotArg>::element_type>(
                 std::move(tmp)));
    builder.set_unpivot_arg_list(std::move(tmp));
  }
  if (!builder.projected_input_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_projected_input_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_projected_input_column_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUnpivotScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMeasureGroup> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMeasureGroup(*node));
  ResolvedMeasureGroupBuilder builder = ToBuilder(std::move(node));
  if (builder.pattern_variable_ref() != nullptr) {
    std::unique_ptr<const ResolvedMatchRecognizePatternVariableRef> tmp =
        builder.release_pattern_variable_ref();
    absl::StatusOr<std::unique_ptr<const ResolvedMatchRecognizePatternVariableRef>> result =
        Dispatch<std::unique_ptr<const ResolvedMatchRecognizePatternVariableRef>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_pattern_variable_ref(*std::move(result));
  }
  if (!builder.aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_aggregate_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMeasureGroup(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphNodeTableReference> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphNodeTableReference(*node));
  ResolvedGraphNodeTableReferenceBuilder builder = ToBuilder(std::move(node));
  if (!builder.edge_table_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_edge_table_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_edge_table_column_list(std::move(tmp));
  }
  if (!builder.node_table_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_node_table_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_node_table_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphNodeTableReference(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphDynamicPropertiesSpecification> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphDynamicPropertiesSpecification(*node));
  ResolvedGraphDynamicPropertiesSpecificationBuilder builder = ToBuilder(std::move(node));
  if (builder.property_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_property_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_property_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphDynamicPropertiesSpecification(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphLinearScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphLinearScan(*node));
  ResolvedGraphLinearScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.scan_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedScan>> tmp =
        builder.release_scan_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedScan>::element_type>(
                 std::move(tmp)));
    builder.set_scan_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphLinearScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphCallScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphCallScan(*node));
  ResolvedGraphCallScanBuilder builder = ToBuilder(std::move(node));
  if (builder.subquery() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_subquery();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_subquery(*std::move(result));
  }
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_parameter_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_parameter_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphCallScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphScan(*node));
  ResolvedGraphScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_scan_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphPathScan>> tmp =
        builder.release_input_scan_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphPathScan>::element_type>(
                 std::move(tmp)));
    builder.set_input_scan_list(std::move(tmp));
  }
  if (builder.filter_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_filter_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_filter_expr(*std::move(result));
  }
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphNodeScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphNodeScan(*node));
  ResolvedGraphNodeScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (builder.filter_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_filter_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_filter_expr(*std::move(result));
  }
  if (builder.label_expr() != nullptr) {
    std::unique_ptr<const ResolvedGraphLabelExpr> tmp =
        builder.release_label_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphLabelExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphLabelExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_label_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphNodeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphGetElementProperty> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphGetElementProperty(*node));
  ResolvedGraphGetElementPropertyBuilder builder = ToBuilder(std::move(node));
  if (builder.expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expr(*std::move(result));
  }
  if (builder.property_name() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_property_name();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_property_name(*std::move(result));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphGetElementProperty(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphLabelNaryExpr> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphLabelNaryExpr(*node));
  ResolvedGraphLabelNaryExprBuilder builder = ToBuilder(std::move(node));
  if (!builder.operand_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphLabelExpr>> tmp =
        builder.release_operand_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphLabelExpr>::element_type>(
                 std::move(tmp)));
    builder.set_operand_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphLabelNaryExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphLabel> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphLabel(*node));
  ResolvedGraphLabelBuilder builder = ToBuilder(std::move(node));
  if (builder.label_name() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_label_name();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_label_name(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphLabel(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphWildCardLabel> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphWildCardLabel(*node));
  return PostVisitResolvedGraphWildCardLabel(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphMakeElement> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphMakeElement(*node));
  ResolvedGraphMakeElementBuilder builder = ToBuilder(std::move(node));
  if (builder.identifier() != nullptr) {
    std::unique_ptr<const ResolvedGraphElementIdentifier> tmp =
        builder.release_identifier();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphElementIdentifier>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphElementIdentifier>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_identifier(*std::move(result));
  }
  if (!builder.property_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphElementProperty>> tmp =
        builder.release_property_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementProperty>::element_type>(
                 std::move(tmp)));
    builder.set_property_list(std::move(tmp));
  }
  if (builder.dynamic_labels() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_dynamic_labels();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_dynamic_labels(*std::move(result));
  }
  if (builder.dynamic_properties() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_dynamic_properties();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_dynamic_properties(*std::move(result));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphMakeElement(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArrayAggregate> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedArrayAggregate(*node));
  ResolvedArrayAggregateBuilder builder = ToBuilder(std::move(node));
  if (builder.array() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_array();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_array(*std::move(result));
  }
  builder.set_element_column(DefaultVisit(builder.element_column()));
  if (!builder.pre_aggregate_computed_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_pre_aggregate_computed_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_pre_aggregate_computed_column_list(std::move(tmp));
  }
  if (builder.aggregate() != nullptr) {
    std::unique_ptr<const ResolvedAggregateFunctionCall> tmp =
        builder.release_aggregate();
    absl::StatusOr<std::unique_ptr<const ResolvedAggregateFunctionCall>> result =
        Dispatch<std::unique_ptr<const ResolvedAggregateFunctionCall>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_aggregate(*std::move(result));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedArrayAggregate(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphIsLabeledPredicate> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphIsLabeledPredicate(*node));
  ResolvedGraphIsLabeledPredicateBuilder builder = ToBuilder(std::move(node));
  if (builder.expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_expr(*std::move(result));
  }
  if (builder.label_expr() != nullptr) {
    std::unique_ptr<const ResolvedGraphLabelExpr> tmp =
        builder.release_label_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphLabelExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphLabelExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_label_expr(*std::move(result));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphIsLabeledPredicate(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssertScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAssertScan(*node));
  ResolvedAssertScanBuilder builder = ToBuilder(std::move(node));
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (builder.condition() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_condition();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_condition(*std::move(result));
  }
  if (builder.message() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_message();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_message(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssertScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeForkScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPipeForkScan(*node));
  ResolvedPipeForkScanBuilder builder = ToBuilder(std::move(node));
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.subpipeline_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGeneralizedQuerySubpipeline>> tmp =
        builder.release_subpipeline_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGeneralizedQuerySubpipeline>::element_type>(
                 std::move(tmp)));
    builder.set_subpipeline_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeForkScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeCreateTableScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPipeCreateTableScan(*node));
  ResolvedPipeCreateTableScanBuilder builder = ToBuilder(std::move(node));
  if (builder.create_table_as_select_stmt() != nullptr) {
    std::unique_ptr<const ResolvedCreateTableAsSelectStmt> tmp =
        builder.release_create_table_as_select_stmt();
    absl::StatusOr<std::unique_ptr<const ResolvedCreateTableAsSelectStmt>> result =
        Dispatch<std::unique_ptr<const ResolvedCreateTableAsSelectStmt>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_create_table_as_select_stmt(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeCreateTableScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeInsertScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPipeInsertScan(*node));
  ResolvedPipeInsertScanBuilder builder = ToBuilder(std::move(node));
  if (builder.insert_stmt() != nullptr) {
    std::unique_ptr<const ResolvedInsertStmt> tmp =
        builder.release_insert_stmt();
    absl::StatusOr<std::unique_ptr<const ResolvedInsertStmt>> result =
        Dispatch<std::unique_ptr<const ResolvedInsertStmt>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_insert_stmt(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeInsertScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSubpipeline> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSubpipeline(*node));
  ResolvedSubpipelineBuilder builder = ToBuilder(std::move(node));
  if (builder.scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_scan(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSubpipeline(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSubpipelineInputScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSubpipelineInputScan(*node));
  ResolvedSubpipelineInputScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSubpipelineInputScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedBarrierScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedBarrierScan(*node));
  ResolvedBarrierScanBuilder builder = ToBuilder(std::move(node));
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result), /*propagate_order=*/false);
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedBarrierScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateConnectionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateConnectionStmt(*node));
  ResolvedCreateConnectionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateConnectionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterConnectionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterConnectionStmt(*node));
  ResolvedAlterConnectionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterConnectionStmt(std::move(built));
}

}  // namespace googlesql