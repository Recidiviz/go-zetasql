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
    std::unique_ptr<const ResolvedCatalogColumnRef> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCatalogColumnRef(*node));
  ResolvedCatalogColumnRefBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCatalogColumnRef(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingSetMultiColumn> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGroupingSetMultiColumn(*node));
  ResolvedGroupingSetMultiColumnBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingSetMultiColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedInlineLambda> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedInlineLambda(*node));
  ResolvedInlineLambdaBuilder builder = ToBuilder(std::move(node));
  if (!builder.argument_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_argument_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_argument_list(std::move(tmp));
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
  if (builder.body() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_body();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_body(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedInlineLambda(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterFieldArg> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFilterFieldArg(*node));
  return PostVisitResolvedFilterFieldArg(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterField> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFilterField(*node));
  ResolvedFilterFieldBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.filter_field_arg_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedFilterFieldArg>> tmp =
        builder.release_filter_field_arg_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFilterFieldArg>::element_type>(
                 std::move(tmp)));
    builder.set_filter_field_arg_list(std::move(tmp));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFilterField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFunctionCall> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFunctionCall(*node));
  ResolvedFunctionCallBuilder builder = ToBuilder(std::move(node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFunctionCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregateFunctionCall> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAggregateFunctionCall(*node));
  ResolvedAggregateFunctionCallBuilder builder = ToBuilder(std::move(node));
  if (builder.having_modifier() != nullptr) {
    std::unique_ptr<const ResolvedAggregateHavingModifier> tmp =
        builder.release_having_modifier();
    absl::StatusOr<std::unique_ptr<const ResolvedAggregateHavingModifier>> result =
        Dispatch<std::unique_ptr<const ResolvedAggregateHavingModifier>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_having_modifier(*std::move(result));
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
  if (builder.limit() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_limit();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_limit(*std::move(result));
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
  if (!builder.group_by_hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_group_by_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_hint_list(std::move(tmp));
  }
  if (!builder.group_by_aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_group_by_aggregate_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_aggregate_list(std::move(tmp));
  }
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
  return PostVisitResolvedAggregateFunctionCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMakeStruct> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMakeStruct(*node));
  ResolvedMakeStructBuilder builder = ToBuilder(std::move(node));
  if (!builder.field_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_field_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_field_list(std::move(tmp));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMakeStruct(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetJsonField> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGetJsonField(*node));
  ResolvedGetJsonFieldBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedGetJsonField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetRowField> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGetRowField(*node));
  ResolvedGetRowFieldBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedGetRowField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedReplaceField> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedReplaceField(*node));
  ResolvedReplaceFieldBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.replace_field_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedReplaceFieldItem>> tmp =
        builder.release_replace_field_item_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedReplaceFieldItem>::element_type>(
                 std::move(tmp)));
    builder.set_replace_field_item_list(std::move(tmp));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedReplaceField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSubqueryExpr> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSubqueryExpr(*node));
  ResolvedSubqueryExprBuilder builder = ToBuilder(std::move(node));
  if (!builder.parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_parameter_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_parameter_list(std::move(tmp));
  }
  if (builder.in_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_in_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_in_expr(*std::move(result));
  }
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
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSubqueryExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExecuteAsRoleScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExecuteAsRoleScan(*node));
  ResolvedExecuteAsRoleScanBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedExecuteAsRoleScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUnsetArgumentScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUnsetArgumentScan(*node));
  ResolvedUnsetArgumentScanBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedUnsetArgumentScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedJoinScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedJoinScan(*node));
  ResolvedJoinScanBuilder builder = ToBuilder(std::move(node));
  if (builder.left_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_left_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_left_scan(*std::move(result));
  }
  if (builder.right_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_right_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_right_scan(*std::move(result));
  }
  if (builder.join_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_join_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_join_expr(*std::move(result));
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
  return PostVisitResolvedJoinScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArrayScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedArrayScan(*node));
  ResolvedArrayScanBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.array_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_array_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_array_expr_list(std::move(tmp));
  }
  if (!builder.element_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_element_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_element_column_list(std::move(tmp));
  }
  if (builder.array_offset_column() != nullptr) {
    std::unique_ptr<const ResolvedColumnHolder> tmp =
        builder.release_array_offset_column();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnHolder>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnHolder>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_array_offset_column(*std::move(result));
  }
  if (builder.join_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_join_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_join_expr(*std::move(result));
  }
  if (builder.array_zip_mode() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_array_zip_mode();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_array_zip_mode(*std::move(result));
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
  return PostVisitResolvedArrayScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDifferentialPrivacyAggregateScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDifferentialPrivacyAggregateScan(*node));
  ResolvedDifferentialPrivacyAggregateScanBuilder builder = ToBuilder(std::move(node));
  if (builder.group_selection_threshold_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_group_selection_threshold_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_group_selection_threshold_expr(*std::move(result));
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
  return PostVisitResolvedDifferentialPrivacyAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGeneratedColumnInfo> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGeneratedColumnInfo(*node));
  ResolvedGeneratedColumnInfoBuilder builder = ToBuilder(std::move(node));
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
  if (builder.identity_column_info() != nullptr) {
    std::unique_ptr<const ResolvedIdentityColumnInfo> tmp =
        builder.release_identity_column_info();
    absl::StatusOr<std::unique_ptr<const ResolvedIdentityColumnInfo>> result =
        Dispatch<std::unique_ptr<const ResolvedIdentityColumnInfo>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_identity_column_info(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGeneratedColumnInfo(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOutputSchema> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedOutputSchema(*node));
  ResolvedOutputSchemaBuilder builder = ToBuilder(std::move(node));
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOutputSchema(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedProjectScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedProjectScan(*node));
  ResolvedProjectScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_expr_list(std::move(tmp));
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
  return PostVisitResolvedProjectScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExplainStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExplainStmt(*node));
  ResolvedExplainStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.statement() != nullptr) {
    std::unique_ptr<const ResolvedStatement> tmp =
        builder.release_statement();
    absl::StatusOr<std::unique_ptr<const ResolvedStatement>> result =
        Dispatch<std::unique_ptr<const ResolvedStatement>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_statement(*std::move(result));
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
  return PostVisitResolvedExplainStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGeneralizedQueryStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGeneralizedQueryStmt(*node));
  ResolvedGeneralizedQueryStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.output_schema() != nullptr) {
    std::unique_ptr<const ResolvedOutputSchema> tmp =
        builder.release_output_schema();
    absl::StatusOr<std::unique_ptr<const ResolvedOutputSchema>> result =
        Dispatch<std::unique_ptr<const ResolvedOutputSchema>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_output_schema(*std::move(result));
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
  return PostVisitResolvedGeneralizedQueryStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateWithEntryStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateWithEntryStmt(*node));
  ResolvedCreateWithEntryStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.with_entry() != nullptr) {
    std::unique_ptr<const ResolvedWithEntry> tmp =
        builder.release_with_entry();
    absl::StatusOr<std::unique_ptr<const ResolvedWithEntry>> result =
        Dispatch<std::unique_ptr<const ResolvedWithEntry>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_with_entry(*std::move(result));
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
  return PostVisitResolvedCreateWithEntryStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateTableAsSelectStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateTableAsSelectStmt(*node));
  ResolvedCreateTableAsSelectStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedCreateTableAsSelectStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateViewStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateViewStmt(*node));
  ResolvedCreateViewStmtBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithPartitionColumns> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWithPartitionColumns(*node));
  ResolvedWithPartitionColumnsBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithPartitionColumns(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateSnapshotTableStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateSnapshotTableStmt(*node));
  ResolvedCreateSnapshotTableStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedCreateSnapshotTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExportModelStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExportModelStmt(*node));
  ResolvedExportModelStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedExportModelStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDescribeStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDescribeStmt(*node));
  ResolvedDescribeStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedDescribeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedShowStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedShowStmt(*node));
  ResolvedShowStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.like_expr() != nullptr) {
    std::unique_ptr<const ResolvedLiteral> tmp =
        builder.release_like_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedLiteral>> result =
        Dispatch<std::unique_ptr<const ResolvedLiteral>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_like_expr(*std::move(result));
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
  return PostVisitResolvedShowStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCommitStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCommitStmt(*node));
  ResolvedCommitStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedCommitStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRollbackStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRollbackStmt(*node));
  ResolvedRollbackStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedRollbackStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRunBatchStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRunBatchStmt(*node));
  ResolvedRunBatchStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedRunBatchStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRecursiveScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRecursiveScan(*node));
  ResolvedRecursiveScanBuilder builder = ToBuilder(std::move(node));
  if (builder.non_recursive_term() != nullptr) {
    std::unique_ptr<const ResolvedSetOperationItem> tmp =
        builder.release_non_recursive_term();
    absl::StatusOr<std::unique_ptr<const ResolvedSetOperationItem>> result =
        Dispatch<std::unique_ptr<const ResolvedSetOperationItem>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_non_recursive_term(*std::move(result));
  }
  if (builder.recursive_term() != nullptr) {
    std::unique_ptr<const ResolvedSetOperationItem> tmp =
        builder.release_recursive_term();
    absl::StatusOr<std::unique_ptr<const ResolvedSetOperationItem>> result =
        Dispatch<std::unique_ptr<const ResolvedSetOperationItem>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_recursive_term(*std::move(result));
  }
  if (builder.recursion_depth_modifier() != nullptr) {
    std::unique_ptr<const ResolvedRecursionDepthModifier> tmp =
        builder.release_recursion_depth_modifier();
    absl::StatusOr<std::unique_ptr<const ResolvedRecursionDepthModifier>> result =
        Dispatch<std::unique_ptr<const ResolvedRecursionDepthModifier>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_recursion_depth_modifier(*std::move(result));
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
  return PostVisitResolvedRecursiveScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowFrame> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWindowFrame(*node));
  ResolvedWindowFrameBuilder builder = ToBuilder(std::move(node));
  if (builder.start_expr() != nullptr) {
    std::unique_ptr<const ResolvedWindowFrameExpr> tmp =
        builder.release_start_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedWindowFrameExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedWindowFrameExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_start_expr(*std::move(result));
  }
  if (builder.end_expr() != nullptr) {
    std::unique_ptr<const ResolvedWindowFrameExpr> tmp =
        builder.release_end_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedWindowFrameExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedWindowFrameExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_end_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWindowFrame(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedInsertRow> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedInsertRow(*node));
  ResolvedInsertRowBuilder builder = ToBuilder(std::move(node));
  if (!builder.value_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedDMLValue>> tmp =
        builder.release_value_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedDMLValue>::element_type>(
                 std::move(tmp)));
    builder.set_value_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedInsertRow(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateItemElement> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUpdateItemElement(*node));
  ResolvedUpdateItemElementBuilder builder = ToBuilder(std::move(node));
  if (builder.subscript() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_subscript();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_subscript(*std::move(result));
  }
  if (builder.update_item() != nullptr) {
    std::unique_ptr<const ResolvedUpdateItem> tmp =
        builder.release_update_item();
    absl::StatusOr<std::unique_ptr<const ResolvedUpdateItem>> result =
        Dispatch<std::unique_ptr<const ResolvedUpdateItem>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_update_item(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateItemElement(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRevokeStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRevokeStmt(*node));
  ResolvedRevokeStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_privilege_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_privilege_list(std::move(tmp));
  }
  if (!builder.grantee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_grantee_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_grantee_expr_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRevokeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterDatabaseStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterDatabaseStmt(*node));
  ResolvedAlterDatabaseStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterDatabaseStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterIndexStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterIndexStmt(*node));
  ResolvedAlterIndexStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterIndexStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterMaterializedViewStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterMaterializedViewStmt(*node));
  ResolvedAlterMaterializedViewStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterMaterializedViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterModelStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterModelStmt(*node));
  ResolvedAlterModelStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterModelStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterTableStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterTableStmt(*node));
  ResolvedAlterTableStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddConstraintAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAddConstraintAction(*node));
  ResolvedAddConstraintActionBuilder builder = ToBuilder(std::move(node));
  if (builder.constraint() != nullptr) {
    std::unique_ptr<const ResolvedConstraint> tmp =
        builder.release_constraint();
    absl::StatusOr<std::unique_ptr<const ResolvedConstraint>> result =
        Dispatch<std::unique_ptr<const ResolvedConstraint>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_constraint(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddConstraintAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterTableSetOptionsStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterTableSetOptionsStmt(*node));
  ResolvedAlterTableSetOptionsStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterTableSetOptionsStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateRowAccessPolicyStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateRowAccessPolicyStmt(*node));
  ResolvedCreateRowAccessPolicyStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.grantee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_grantee_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_grantee_expr_list(std::move(tmp));
  }
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
  if (builder.predicate() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_predicate();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_predicate(*std::move(result));
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
  return PostVisitResolvedCreateRowAccessPolicyStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropPrivilegeRestrictionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropPrivilegeRestrictionStmt(*node));
  ResolvedDropPrivilegeRestrictionStmtBuilder builder = ToBuilder(std::move(node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropPrivilegeRestrictionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGrantToAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGrantToAction(*node));
  ResolvedGrantToActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.grantee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_grantee_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_grantee_expr_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGrantToAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRemoveFromRestricteeListAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRemoveFromRestricteeListAction(*node));
  ResolvedRemoveFromRestricteeListActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.restrictee_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_restrictee_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_restrictee_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRemoveFromRestricteeListAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRelationArgumentScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRelationArgumentScan(*node));
  ResolvedRelationArgumentScanBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedRelationArgumentScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCallStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCallStmt(*node));
  ResolvedCallStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_argument_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
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
  return PostVisitResolvedCallStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedImportStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedImportStmt(*node));
  ResolvedImportStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedImportStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateApproxViewStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateApproxViewStmt(*node));
  ResolvedCreateApproxViewStmtBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateApproxViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateProcedureStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateProcedureStmt(*node));
  ResolvedCreateProcedureStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
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
  return PostVisitResolvedCreateProcedureStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateEntityStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateEntityStmt(*node));
  ResolvedCreateEntityStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedCreateEntityStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterEntityStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterEntityStmt(*node));
  ResolvedAlterEntityStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterEntityStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUnpivotArg> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUnpivotArg(*node));
  ResolvedUnpivotArgBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUnpivotArg(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizeScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizeScan(*node));
  ResolvedMatchRecognizeScanBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.analytic_function_group_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAnalyticFunctionGroup>> tmp =
        builder.release_analytic_function_group_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAnalyticFunctionGroup>::element_type>(
                 std::move(tmp)));
    builder.set_analytic_function_group_list(std::move(tmp));
  }
  if (!builder.pattern_variable_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMatchRecognizeVariableDefinition>> tmp =
        builder.release_pattern_variable_definition_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMatchRecognizeVariableDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_pattern_variable_definition_list(std::move(tmp));
  }
  if (builder.pattern() != nullptr) {
    std::unique_ptr<const ResolvedMatchRecognizePatternExpr> tmp =
        builder.release_pattern();
    absl::StatusOr<std::unique_ptr<const ResolvedMatchRecognizePatternExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedMatchRecognizePatternExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_pattern(*std::move(result));
  }
  if (!builder.measure_group_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMeasureGroup>> tmp =
        builder.release_measure_group_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMeasureGroup>::element_type>(
                 std::move(tmp)));
    builder.set_measure_group_list(std::move(tmp));
  }
  builder.set_match_number_column(DefaultVisit(builder.match_number_column()));
  builder.set_match_row_number_column(DefaultVisit(builder.match_row_number_column()));
  builder.set_classifier_column(DefaultVisit(builder.classifier_column()));
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
  return PostVisitResolvedMatchRecognizeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternVariableRef> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternVariableRef(*node));
  return PostVisitResolvedMatchRecognizePatternVariableRef(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCloneDataStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCloneDataStmt(*node));
  ResolvedCloneDataStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.target_table() != nullptr) {
    std::unique_ptr<const ResolvedTableScan> tmp =
        builder.release_target_table();
    absl::StatusOr<std::unique_ptr<const ResolvedTableScan>> result =
        Dispatch<std::unique_ptr<const ResolvedTableScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_target_table(*std::move(result));
  }
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
  return PostVisitResolvedCloneDataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyzeStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAnalyzeStmt(*node));
  ResolvedAnalyzeStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.table_and_column_index_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedTableAndColumnInfo>> tmp =
        builder.release_table_and_column_index_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedTableAndColumnInfo>::element_type>(
                 std::move(tmp)));
    builder.set_table_and_column_index_list(std::move(tmp));
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
  return PostVisitResolvedAnalyzeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPropertyDefinition> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphPropertyDefinition(*node));
  ResolvedGraphPropertyDefinitionBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedGraphPropertyDefinition(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphDynamicLabelSpecification> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphDynamicLabelSpecification(*node));
  ResolvedGraphDynamicLabelSpecificationBuilder builder = ToBuilder(std::move(node));
  if (builder.label_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_label_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_label_expr(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphDynamicLabelSpecification(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphTableScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphTableScan(*node));
  ResolvedGraphTableScanBuilder builder = ToBuilder(std::move(node));
  if (builder.input_scan() != nullptr) {
    std::unique_ptr<const ResolvedGraphScanBase> tmp =
        builder.release_input_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphScanBase>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphScanBase>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_input_scan(*std::move(result));
  }
  if (!builder.shape_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_shape_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_shape_expr_list(std::move(tmp));
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
  return PostVisitResolvedGraphTableScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathSearchPrefix> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathSearchPrefix(*node));
  ResolvedGraphPathSearchPrefixBuilder builder = ToBuilder(std::move(node));
  if (builder.path_count() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_path_count();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_path_count(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPathSearchPrefix(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementProperty> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementProperty(*node));
  ResolvedGraphElementPropertyBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedGraphElementProperty(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathCost> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathCost(*node));
  ResolvedGraphPathCostBuilder builder = ToBuilder(std::move(node));
  builder.set_cost_supertype(DefaultVisit(builder.cost_supertype()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPathCost(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeIfScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPipeIfScan(*node));
  ResolvedPipeIfScanBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.if_case_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPipeIfCase>> tmp =
        builder.release_if_case_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPipeIfCase>::element_type>(
                 std::move(tmp)));
    builder.set_if_case_list(std::move(tmp));
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
  return PostVisitResolvedPipeIfScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGeneralizedQuerySubpipeline> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGeneralizedQuerySubpipeline(*node));
  ResolvedGeneralizedQuerySubpipelineBuilder builder = ToBuilder(std::move(node));
  if (builder.subpipeline() != nullptr) {
    std::unique_ptr<const ResolvedSubpipeline> tmp =
        builder.release_subpipeline();
    absl::StatusOr<std::unique_ptr<const ResolvedSubpipeline>> result =
        Dispatch<std::unique_ptr<const ResolvedSubpipeline>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_subpipeline(*std::move(result));
  }
  if (builder.output_schema() != nullptr) {
    std::unique_ptr<const ResolvedOutputSchema> tmp =
        builder.release_output_schema();
    absl::StatusOr<std::unique_ptr<const ResolvedOutputSchema>> result =
        Dispatch<std::unique_ptr<const ResolvedOutputSchema>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_output_schema(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGeneralizedQuerySubpipeline(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedLockMode> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedLockMode(*node));
  return PostVisitResolvedLockMode(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateSequenceStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateSequenceStmt(*node));
  ResolvedCreateSequenceStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedCreateSequenceStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterSequenceStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterSequenceStmt(*node));
  ResolvedAlterSequenceStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterSequenceStmt(std::move(built));
}

}  // namespace googlesql