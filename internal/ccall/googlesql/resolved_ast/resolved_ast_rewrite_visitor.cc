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

namespace zetasql {

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedLiteral> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedLiteral(*node));
  return PostVisitResolvedLiteral(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedParameter> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedParameter(*node));
  return PostVisitResolvedParameter(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExpressionColumn> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExpressionColumn(*node));
  return PostVisitResolvedExpressionColumn(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCatalogColumnRef> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCatalogColumnRef(*node));
  return PostVisitResolvedCatalogColumnRef(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnRef> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedColumnRef(*node));
  ResolvedColumnRefBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnRef(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingSetMultiColumn> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGroupingSetMultiColumn(*node));
  ResolvedGroupingSetMultiColumnBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingSetMultiColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedConstant> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedConstant(*node));
  return PostVisitResolvedConstant(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSystemVariable> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSystemVariable(*node));
  return PostVisitResolvedSystemVariable(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedInlineLambda> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedInlineLambda(*node));
  ResolvedInlineLambdaBuilder builder = ToBuilder(std::move(node));
  if (!builder.argument_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_argument_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_parameter_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedInlineLambda(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSequence> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSequence(*node));
  return PostVisitResolvedSequence(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterFieldArg> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFilterFieldArg(*node));
  return PostVisitResolvedFilterFieldArg(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterField> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFilterField(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFilterFieldArg>::element_type>(
                 std::move(tmp)));
    builder.set_filter_field_arg_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFilterField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFunctionCall> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFunctionCall(*node));
  ResolvedFunctionCallBuilder builder = ToBuilder(std::move(node));
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.generic_argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedFunctionArgument>> tmp =
        builder.release_generic_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFunctionArgument>::element_type>(
                 std::move(tmp)));
    builder.set_generic_argument_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFunctionCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregateFunctionCall> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAggregateFunctionCall(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.group_by_aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_group_by_aggregate_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.generic_argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedFunctionArgument>> tmp =
        builder.release_generic_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFunctionArgument>::element_type>(
                 std::move(tmp)));
    builder.set_generic_argument_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (builder.with_group_rows_subquery() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_with_group_rows_subquery();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_with_group_rows_subquery(*std::move(result));
  }
  if (!builder.with_group_rows_parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_with_group_rows_parameter_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_with_group_rows_parameter_list(std::move(tmp));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAggregateFunctionCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyticFunctionCall> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAnalyticFunctionCall(*node));
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
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.generic_argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedFunctionArgument>> tmp =
        builder.release_generic_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFunctionArgument>::element_type>(
                 std::move(tmp)));
    builder.set_generic_argument_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (builder.with_group_rows_subquery() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_with_group_rows_subquery();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_with_group_rows_subquery(*std::move(result));
  }
  if (!builder.with_group_rows_parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_with_group_rows_parameter_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_with_group_rows_parameter_list(std::move(tmp));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAnalyticFunctionCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExtendedCastElement> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExtendedCastElement(*node));
  return PostVisitResolvedExtendedCastElement(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExtendedCast> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExtendedCast(*node));
  ResolvedExtendedCastBuilder builder = ToBuilder(std::move(node));
  if (!builder.element_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExtendedCastElement>> tmp =
        builder.release_element_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExtendedCastElement>::element_type>(
                 std::move(tmp)));
    builder.set_element_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExtendedCast(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCast> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCast(*node));
  ResolvedCastBuilder builder = ToBuilder(std::move(node));
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
  if (builder.extended_cast() != nullptr) {
    std::unique_ptr<const ResolvedExtendedCast> tmp =
        builder.release_extended_cast();
    absl::StatusOr<std::unique_ptr<const ResolvedExtendedCast>> result =
        Dispatch<std::unique_ptr<const ResolvedExtendedCast>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_extended_cast(*std::move(result));
  }
  if (builder.format() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_format();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_format(*std::move(result));
  }
  if (builder.time_zone() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_time_zone();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_time_zone(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCast(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMakeStruct> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMakeStruct(*node));
  ResolvedMakeStructBuilder builder = ToBuilder(std::move(node));
  if (!builder.field_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_field_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_field_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMakeStruct(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMakeProto> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMakeProto(*node));
  ResolvedMakeProtoBuilder builder = ToBuilder(std::move(node));
  if (!builder.field_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMakeProtoField>> tmp =
        builder.release_field_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMakeProtoField>::element_type>(
                 std::move(tmp)));
    builder.set_field_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMakeProto(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMakeProtoField> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMakeProtoField(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMakeProtoField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetStructField> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGetStructField(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGetStructField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetProtoField> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGetProtoField(*node));
  ResolvedGetProtoFieldBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGetProtoField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetJsonField> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGetJsonField(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGetJsonField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFlatten> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFlatten(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_get_field_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFlatten(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFlattenedArg> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFlattenedArg(*node));
  return PostVisitResolvedFlattenedArg(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedReplaceFieldItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedReplaceFieldItem(*node));
  ResolvedReplaceFieldItemBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedReplaceFieldItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedReplaceField> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedReplaceField(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedReplaceFieldItem>::element_type>(
                 std::move(tmp)));
    builder.set_replace_field_item_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedReplaceField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetProtoOneof> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGetProtoOneof(*node));
  ResolvedGetProtoOneofBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGetProtoOneof(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSubqueryExpr> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSubqueryExpr(*node));
  ResolvedSubqueryExprBuilder builder = ToBuilder(std::move(node));
  if (!builder.parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_parameter_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSubqueryExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithExpr> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWithExpr(*node));
  ResolvedWithExprBuilder builder = ToBuilder(std::move(node));
  if (!builder.assignment_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_assignment_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_assignment_list(std::move(tmp));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExecuteAsRoleScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExecuteAsRoleScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExecuteAsRoleScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedModel> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedModel(*node));
  return PostVisitResolvedModel(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedConnection> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedConnection(*node));
  return PostVisitResolvedConnection(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDescriptor> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDescriptor(*node));
  ResolvedDescriptorBuilder builder = ToBuilder(std::move(node));
  if (!builder.descriptor_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_descriptor_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_descriptor_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDescriptor(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSingleRowScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSingleRowScan(*node));
  ResolvedSingleRowScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSingleRowScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTableScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedTableScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedTableScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedJoinScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedJoinScan(*node));
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
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedJoinScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArrayScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedArrayScan(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_array_expr_list(std::move(tmp));
  }
  if (!builder.element_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_element_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedArrayScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnHolder> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedColumnHolder(*node));
  ResolvedColumnHolderBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnHolder(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFilterScan(*node));
  ResolvedFilterScanBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFilterScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingCall> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGroupingCall(*node));
  ResolvedGroupingCallBuilder builder = ToBuilder(std::move(node));
  if (builder.group_by_column() != nullptr) {
    std::unique_ptr<const ResolvedColumnRef> tmp =
        builder.release_group_by_column();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnRef>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnRef>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_group_by_column(*std::move(result));
  }
  builder.set_output_column(DefaultVisit(builder.output_column()));
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingSet> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGroupingSet(*node));
  ResolvedGroupingSetBuilder builder = ToBuilder(std::move(node));
  if (!builder.group_by_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_group_by_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingSet(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRollup> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRollup(*node));
  ResolvedRollupBuilder builder = ToBuilder(std::move(node));
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetMultiColumn>> tmp =
        builder.release_rollup_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetMultiColumn>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRollup(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCube> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCube(*node));
  ResolvedCubeBuilder builder = ToBuilder(std::move(node));
  if (!builder.cube_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetMultiColumn>> tmp =
        builder.release_cube_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetMultiColumn>::element_type>(
                 std::move(tmp)));
    builder.set_cube_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCube(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregateScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAggregateScan(*node));
  ResolvedAggregateScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_aggregate_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  if (!builder.grouping_set_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_grouping_set_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_set_list(std::move(tmp));
  }
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_rollup_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  if (!builder.grouping_call_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingCall>> tmp =
        builder.release_grouping_call_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingCall>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_call_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnonymizedAggregateScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAnonymizedAggregateScan(*node));
  ResolvedAnonymizedAggregateScanBuilder builder = ToBuilder(std::move(node));
  if (builder.k_threshold_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_k_threshold_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_k_threshold_expr(*std::move(result));
  }
  if (!builder.anonymization_option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_anonymization_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_anonymization_option_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_aggregate_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  if (!builder.grouping_set_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_grouping_set_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_set_list(std::move(tmp));
  }
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_rollup_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  if (!builder.grouping_call_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingCall>> tmp =
        builder.release_grouping_call_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingCall>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_call_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAnonymizedAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDifferentialPrivacyAggregateScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDifferentialPrivacyAggregateScan(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_aggregate_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  if (!builder.grouping_set_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_grouping_set_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_set_list(std::move(tmp));
  }
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_rollup_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  if (!builder.grouping_call_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingCall>> tmp =
        builder.release_grouping_call_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingCall>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_call_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDifferentialPrivacyAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregationThresholdAggregateScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAggregationThresholdAggregateScan(*node));
  ResolvedAggregationThresholdAggregateScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.aggregate_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_aggregate_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  if (!builder.grouping_set_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_grouping_set_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_set_list(std::move(tmp));
  }
  if (!builder.rollup_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_rollup_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_rollup_column_list(std::move(tmp));
  }
  if (!builder.grouping_call_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingCall>> tmp =
        builder.release_grouping_call_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingCall>::element_type>(
                 std::move(tmp)));
    builder.set_grouping_call_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAggregationThresholdAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetOperationItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSetOperationItem(*node));
  ResolvedSetOperationItemBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.output_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_output_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_output_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetOperationItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetOperationScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSetOperationScan(*node));
  ResolvedSetOperationScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedSetOperationItem>> tmp =
        builder.release_input_item_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedSetOperationItem>::element_type>(
                 std::move(tmp)));
    builder.set_input_item_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetOperationScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOrderByScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedOrderByScan(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOrderByItem>::element_type>(
                 std::move(tmp)));
    builder.set_order_by_item_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOrderByScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedLimitOffsetScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedLimitOffsetScan(*node));
  ResolvedLimitOffsetScanBuilder builder = ToBuilder(std::move(node));
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
  if (builder.offset() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_offset();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_offset(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedLimitOffsetScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithRefScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWithRefScan(*node));
  ResolvedWithRefScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithRefScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyticScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAnalyticScan(*node));
  ResolvedAnalyticScanBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.function_group_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAnalyticFunctionGroup>> tmp =
        builder.release_function_group_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAnalyticFunctionGroup>::element_type>(
                 std::move(tmp)));
    builder.set_function_group_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAnalyticScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSampleScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSampleScan(*node));
  ResolvedSampleScanBuilder builder = ToBuilder(std::move(node));
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
  if (builder.size() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_size();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_size(*std::move(result));
  }
  if (builder.repeatable_argument() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_repeatable_argument();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_repeatable_argument(*std::move(result));
  }
  if (builder.weight_column() != nullptr) {
    std::unique_ptr<const ResolvedColumnHolder> tmp =
        builder.release_weight_column();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnHolder>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnHolder>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_weight_column(*std::move(result));
  }
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_partition_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSampleScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedComputedColumn> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedComputedColumn(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedComputedColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDeferredComputedColumn> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDeferredComputedColumn(*node));
  ResolvedDeferredComputedColumnBuilder builder = ToBuilder(std::move(node));
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
  builder.set_side_effect_column(DefaultVisit(builder.side_effect_column()));
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDeferredComputedColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOrderByItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedOrderByItem(*node));
  ResolvedOrderByItemBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOrderByItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnAnnotations> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedColumnAnnotations(*node));
  ResolvedColumnAnnotationsBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.child_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnAnnotations>> tmp =
        builder.release_child_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnAnnotations>::element_type>(
                 std::move(tmp)));
    builder.set_child_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnAnnotations(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGeneratedColumnInfo> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGeneratedColumnInfo(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGeneratedColumnInfo(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnDefaultValue> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedColumnDefaultValue(*node));
  ResolvedColumnDefaultValueBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnDefaultValue(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnDefinition> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedColumnDefinition(*node));
  ResolvedColumnDefinitionBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnDefinition(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPrimaryKey> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPrimaryKey(*node));
  ResolvedPrimaryKeyBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPrimaryKey(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedForeignKey> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedForeignKey(*node));
  ResolvedForeignKeyBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedForeignKey(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCheckConstraint> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCheckConstraint(*node));
  ResolvedCheckConstraintBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCheckConstraint(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOutputColumn> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedOutputColumn(*node));
  ResolvedOutputColumnBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOutputColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOutputSchema> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedOutputSchema(*node));
  ResolvedOutputSchemaBuilder builder = ToBuilder(std::move(node));
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOutputSchema(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedProjectScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedProjectScan(*node));
  ResolvedProjectScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedProjectScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTVFScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedTVFScan(*node));
  ResolvedTVFScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedFunctionArgument>> tmp =
        builder.release_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedFunctionArgument>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedTVFScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupRowsScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGroupRowsScan(*node));
  ResolvedGroupRowsScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_input_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_input_column_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupRowsScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFunctionArgument> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFunctionArgument(*node));
  ResolvedFunctionArgumentBuilder builder = ToBuilder(std::move(node));
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
  if (builder.model() != nullptr) {
    std::unique_ptr<const ResolvedModel> tmp =
        builder.release_model();
    absl::StatusOr<std::unique_ptr<const ResolvedModel>> result =
        Dispatch<std::unique_ptr<const ResolvedModel>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_model(*std::move(result));
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
  if (builder.descriptor_arg() != nullptr) {
    std::unique_ptr<const ResolvedDescriptor> tmp =
        builder.release_descriptor_arg();
    absl::StatusOr<std::unique_ptr<const ResolvedDescriptor>> result =
        Dispatch<std::unique_ptr<const ResolvedDescriptor>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_descriptor_arg(*std::move(result));
  }
  if (!builder.argument_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_argument_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_argument_column_list(std::move(tmp));
  }
  if (builder.inline_lambda() != nullptr) {
    std::unique_ptr<const ResolvedInlineLambda> tmp =
        builder.release_inline_lambda();
    absl::StatusOr<std::unique_ptr<const ResolvedInlineLambda>> result =
        Dispatch<std::unique_ptr<const ResolvedInlineLambda>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_inline_lambda(*std::move(result));
  }
  if (builder.sequence() != nullptr) {
    std::unique_ptr<const ResolvedSequence> tmp =
        builder.release_sequence();
    absl::StatusOr<std::unique_ptr<const ResolvedSequence>> result =
        Dispatch<std::unique_ptr<const ResolvedSequence>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_sequence(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFunctionArgument(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExplainStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExplainStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExplainStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedQueryStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedQueryStmt(*node));
  ResolvedQueryStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedQueryStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGeneralizedQueryStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGeneralizedQueryStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGeneralizedQueryStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMultiStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMultiStmt(*node));
  ResolvedMultiStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.statement_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedStatement>> tmp =
        builder.release_statement_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedStatement>::element_type>(
                 std::move(tmp)));
    builder.set_statement_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMultiStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateWithEntryStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateWithEntryStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateWithEntryStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateDatabaseStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateDatabaseStmt(*node));
  ResolvedCreateDatabaseStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateDatabaseStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedIndexItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedIndexItem(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedIndexItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUnnestItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUnnestItem(*node));
  ResolvedUnnestItemBuilder builder = ToBuilder(std::move(node));
  if (builder.array_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_array_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_array_expr(*std::move(result));
  }
  builder.set_element_column(DefaultVisit(builder.element_column()));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUnnestItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateIndexStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateIndexStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedIndexItem>::element_type>(
                 std::move(tmp)));
    builder.set_index_item_list(std::move(tmp));
  }
  if (!builder.storing_expression_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_storing_expression_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_storing_expression_list(std::move(tmp));
  }
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_partition_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.computed_columns_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_computed_columns_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_computed_columns_list(std::move(tmp));
  }
  if (!builder.unnest_expressions_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUnnestItem>> tmp =
        builder.release_unnest_expressions_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUnnestItem>::element_type>(
                 std::move(tmp)));
    builder.set_unnest_expressions_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateIndexStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateSchemaStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateSchemaStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateExternalSchemaStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateExternalSchemaStmt(*node));
  ResolvedCreateExternalSchemaStmtBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateExternalSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateTableStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateTableStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.cluster_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_cluster_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_cluster_by_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  if (!builder.pseudo_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_pseudo_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedForeignKey>::element_type>(
                 std::move(tmp)));
    builder.set_foreign_key_list(std::move(tmp));
  }
  if (!builder.check_constraint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedCheckConstraint>> tmp =
        builder.release_check_constraint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateTableAsSelectStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateTableAsSelectStmt(*node));
  ResolvedCreateTableAsSelectStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_partition_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.cluster_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_cluster_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_cluster_by_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  if (!builder.pseudo_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_pseudo_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedForeignKey>::element_type>(
                 std::move(tmp)));
    builder.set_foreign_key_list(std::move(tmp));
  }
  if (!builder.check_constraint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedCheckConstraint>> tmp =
        builder.release_check_constraint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateTableAsSelectStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateModelAliasedQuery> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateModelAliasedQuery(*node));
  ResolvedCreateModelAliasedQueryBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateModelAliasedQuery(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateModelStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateModelStmt(*node));
  ResolvedCreateModelStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedCreateModelAliasedQuery>::element_type>(
                 std::move(tmp)));
    builder.set_aliased_query_list(std::move(tmp));
  }
  if (!builder.transform_input_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_transform_input_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_transform_input_column_list(std::move(tmp));
  }
  if (!builder.transform_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_transform_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_transform_list(std::move(tmp));
  }
  if (!builder.transform_output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_transform_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_transform_output_column_list(std::move(tmp));
  }
  if (!builder.transform_analytic_function_group_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAnalyticFunctionGroup>> tmp =
        builder.release_transform_analytic_function_group_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAnalyticFunctionGroup>::element_type>(
                 std::move(tmp)));
    builder.set_transform_analytic_function_group_list(std::move(tmp));
  }
  if (!builder.input_column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_input_column_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_input_column_definition_list(std::move(tmp));
  }
  if (!builder.output_column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_output_column_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateModelStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateViewStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateViewStmt(*node));
  ResolvedCreateViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithPartitionColumns> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWithPartitionColumns(*node));
  ResolvedWithPartitionColumnsBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithPartitionColumns(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateSnapshotTableStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateSnapshotTableStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateSnapshotTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateExternalTableStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateExternalTableStmt(*node));
  ResolvedCreateExternalTableStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.with_partition_columns() != nullptr) {
    std::unique_ptr<const ResolvedWithPartitionColumns> tmp =
        builder.release_with_partition_columns();
    absl::StatusOr<std::unique_ptr<const ResolvedWithPartitionColumns>> result =
        Dispatch<std::unique_ptr<const ResolvedWithPartitionColumns>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_with_partition_columns(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  if (!builder.pseudo_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_pseudo_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedForeignKey>::element_type>(
                 std::move(tmp)));
    builder.set_foreign_key_list(std::move(tmp));
  }
  if (!builder.check_constraint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedCheckConstraint>> tmp =
        builder.release_check_constraint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateExternalTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExportModelStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExportModelStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExportModelStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExportDataStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExportDataStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExportDataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExportMetadataStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExportMetadataStmt(*node));
  ResolvedExportMetadataStmtBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExportMetadataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDefineTableStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDefineTableStmt(*node));
  ResolvedDefineTableStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDefineTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDescribeStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDescribeStmt(*node));
  ResolvedDescribeStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDescribeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedShowStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedShowStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedShowStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedBeginStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedBeginStmt(*node));
  ResolvedBeginStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedBeginStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetTransactionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSetTransactionStmt(*node));
  ResolvedSetTransactionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetTransactionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCommitStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCommitStmt(*node));
  ResolvedCommitStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCommitStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRollbackStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRollbackStmt(*node));
  ResolvedRollbackStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRollbackStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedStartBatchStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedStartBatchStmt(*node));
  ResolvedStartBatchStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedStartBatchStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRunBatchStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRunBatchStmt(*node));
  ResolvedRunBatchStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRunBatchStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAbortBatchStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAbortBatchStmt(*node));
  ResolvedAbortBatchStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAbortBatchStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropStmt(*node));
  ResolvedDropStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropMaterializedViewStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropMaterializedViewStmt(*node));
  ResolvedDropMaterializedViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropMaterializedViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropSnapshotTableStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropSnapshotTableStmt(*node));
  ResolvedDropSnapshotTableStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropSnapshotTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRecursiveRefScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRecursiveRefScan(*node));
  ResolvedRecursiveRefScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRecursiveRefScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRecursionDepthModifier> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRecursionDepthModifier(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRecursionDepthModifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRecursiveScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRecursiveScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRecursiveScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWithScan(*node));
  ResolvedWithScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.with_entry_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedWithEntry>> tmp =
        builder.release_with_entry_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedWithEntry>::element_type>(
                 std::move(tmp)));
    builder.set_with_entry_list(std::move(tmp));
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
    builder.set_query(*std::move(result), /*propagate_order=*/false);
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithEntry> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWithEntry(*node));
  ResolvedWithEntryBuilder builder = ToBuilder(std::move(node));
  if (builder.with_subquery() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_with_subquery();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_with_subquery(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithEntry(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOption> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedOption(*node));
  ResolvedOptionBuilder builder = ToBuilder(std::move(node));
  if (builder.value() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_value();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_value(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOption(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowPartitioning> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWindowPartitioning(*node));
  ResolvedWindowPartitioningBuilder builder = ToBuilder(std::move(node));
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_partition_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWindowPartitioning(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowOrdering> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWindowOrdering(*node));
  ResolvedWindowOrderingBuilder builder = ToBuilder(std::move(node));
  if (!builder.order_by_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOrderByItem>> tmp =
        builder.release_order_by_item_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOrderByItem>::element_type>(
                 std::move(tmp)));
    builder.set_order_by_item_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWindowOrdering(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowFrame> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWindowFrame(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWindowFrame(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyticFunctionGroup> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAnalyticFunctionGroup(*node));
  ResolvedAnalyticFunctionGroupBuilder builder = ToBuilder(std::move(node));
  if (builder.partition_by() != nullptr) {
    std::unique_ptr<const ResolvedWindowPartitioning> tmp =
        builder.release_partition_by();
    absl::StatusOr<std::unique_ptr<const ResolvedWindowPartitioning>> result =
        Dispatch<std::unique_ptr<const ResolvedWindowPartitioning>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_partition_by(*std::move(result));
  }
  if (builder.order_by() != nullptr) {
    std::unique_ptr<const ResolvedWindowOrdering> tmp =
        builder.release_order_by();
    absl::StatusOr<std::unique_ptr<const ResolvedWindowOrdering>> result =
        Dispatch<std::unique_ptr<const ResolvedWindowOrdering>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_order_by(*std::move(result));
  }
  if (!builder.analytic_function_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumnBase>> tmp =
        builder.release_analytic_function_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_analytic_function_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAnalyticFunctionGroup(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowFrameExpr> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedWindowFrameExpr(*node));
  ResolvedWindowFrameExprBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWindowFrameExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDMLValue> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDMLValue(*node));
  ResolvedDMLValueBuilder builder = ToBuilder(std::move(node));
  if (builder.value() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_value();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_value(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDMLValue(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDMLDefault> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDMLDefault(*node));
  return PostVisitResolvedDMLDefault(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssertStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAssertStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssertStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssertRowsModified> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAssertRowsModified(*node));
  ResolvedAssertRowsModifiedBuilder builder = ToBuilder(std::move(node));
  if (builder.rows() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_rows();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_rows(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssertRowsModified(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOnConflictClause> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedOnConflictClause(*node));
  ResolvedOnConflictClauseBuilder builder = ToBuilder(std::move(node));
  if (!builder.conflict_target_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_conflict_target_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_conflict_target_column_list(std::move(tmp));
  }
  if (builder.insert_row_scan() != nullptr) {
    std::unique_ptr<const ResolvedTableScan> tmp =
        builder.release_insert_row_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedTableScan>> result =
        Dispatch<std::unique_ptr<const ResolvedTableScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_insert_row_scan(*std::move(result));
  }
  if (!builder.update_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateItem>> tmp =
        builder.release_update_item_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateItem>::element_type>(
                 std::move(tmp)));
    builder.set_update_item_list(std::move(tmp));
  }
  if (builder.update_where_expression() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_update_where_expression();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_update_where_expression(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOnConflictClause(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedInsertRow> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedInsertRow(*node));
  ResolvedInsertRowBuilder builder = ToBuilder(std::move(node));
  if (!builder.value_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedDMLValue>> tmp =
        builder.release_value_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedDMLValue>::element_type>(
                 std::move(tmp)));
    builder.set_value_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedInsertRow(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedInsertStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedInsertStmt(*node));
  ResolvedInsertStmtBuilder builder = ToBuilder(std::move(node));
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
  if (builder.assert_rows_modified() != nullptr) {
    std::unique_ptr<const ResolvedAssertRowsModified> tmp =
        builder.release_assert_rows_modified();
    absl::StatusOr<std::unique_ptr<const ResolvedAssertRowsModified>> result =
        Dispatch<std::unique_ptr<const ResolvedAssertRowsModified>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_assert_rows_modified(*std::move(result));
  }
  if (builder.returning() != nullptr) {
    std::unique_ptr<const ResolvedReturningClause> tmp =
        builder.release_returning();
    absl::StatusOr<std::unique_ptr<const ResolvedReturningClause>> result =
        Dispatch<std::unique_ptr<const ResolvedReturningClause>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_returning(*std::move(result));
  }
  if (!builder.insert_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_insert_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_insert_column_list(std::move(tmp));
  }
  if (!builder.query_parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_query_parameter_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_query_parameter_list(std::move(tmp));
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
  if (!builder.query_output_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_query_output_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_query_output_column_list(std::move(tmp));
  }
  if (!builder.row_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedInsertRow>> tmp =
        builder.release_row_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedInsertRow>::element_type>(
                 std::move(tmp)));
    builder.set_row_list(std::move(tmp));
  }
  if (builder.on_conflict_clause() != nullptr) {
    std::unique_ptr<const ResolvedOnConflictClause> tmp =
        builder.release_on_conflict_clause();
    absl::StatusOr<std::unique_ptr<const ResolvedOnConflictClause>> result =
        Dispatch<std::unique_ptr<const ResolvedOnConflictClause>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_on_conflict_clause(*std::move(result));
  }
  if (!builder.generated_column_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_generated_column_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_generated_column_expr_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedInsertStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDeleteStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDeleteStmt(*node));
  ResolvedDeleteStmtBuilder builder = ToBuilder(std::move(node));
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
  if (builder.assert_rows_modified() != nullptr) {
    std::unique_ptr<const ResolvedAssertRowsModified> tmp =
        builder.release_assert_rows_modified();
    absl::StatusOr<std::unique_ptr<const ResolvedAssertRowsModified>> result =
        Dispatch<std::unique_ptr<const ResolvedAssertRowsModified>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_assert_rows_modified(*std::move(result));
  }
  if (builder.returning() != nullptr) {
    std::unique_ptr<const ResolvedReturningClause> tmp =
        builder.release_returning();
    absl::StatusOr<std::unique_ptr<const ResolvedReturningClause>> result =
        Dispatch<std::unique_ptr<const ResolvedReturningClause>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_returning(*std::move(result));
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
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDeleteStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUpdateItem(*node));
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
  if (!builder.array_update_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateArrayItem>> tmp =
        builder.release_array_update_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateArrayItem>::element_type>(
                 std::move(tmp)));
    builder.set_array_update_list(std::move(tmp));
  }
  if (!builder.delete_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedDeleteStmt>> tmp =
        builder.release_delete_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedDeleteStmt>::element_type>(
                 std::move(tmp)));
    builder.set_delete_list(std::move(tmp));
  }
  if (!builder.update_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateStmt>> tmp =
        builder.release_update_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateStmt>::element_type>(
                 std::move(tmp)));
    builder.set_update_list(std::move(tmp));
  }
  if (!builder.insert_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedInsertStmt>> tmp =
        builder.release_insert_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedInsertStmt>::element_type>(
                 std::move(tmp)));
    builder.set_insert_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateArrayItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUpdateArrayItem(*node));
  ResolvedUpdateArrayItemBuilder builder = ToBuilder(std::move(node));
  if (builder.offset() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_offset();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_offset(*std::move(result));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateArrayItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUpdateStmt(*node));
  ResolvedUpdateStmtBuilder builder = ToBuilder(std::move(node));
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
  if (builder.assert_rows_modified() != nullptr) {
    std::unique_ptr<const ResolvedAssertRowsModified> tmp =
        builder.release_assert_rows_modified();
    absl::StatusOr<std::unique_ptr<const ResolvedAssertRowsModified>> result =
        Dispatch<std::unique_ptr<const ResolvedAssertRowsModified>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_assert_rows_modified(*std::move(result));
  }
  if (builder.returning() != nullptr) {
    std::unique_ptr<const ResolvedReturningClause> tmp =
        builder.release_returning();
    absl::StatusOr<std::unique_ptr<const ResolvedReturningClause>> result =
        Dispatch<std::unique_ptr<const ResolvedReturningClause>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_returning(*std::move(result));
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
  if (!builder.update_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateItem>> tmp =
        builder.release_update_item_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateItem>::element_type>(
                 std::move(tmp)));
    builder.set_update_item_list(std::move(tmp));
  }
  if (builder.from_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_from_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_from_scan(*std::move(result));
  }
  if (!builder.generated_column_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_generated_column_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_generated_column_expr_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMergeWhen> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMergeWhen(*node));
  ResolvedMergeWhenBuilder builder = ToBuilder(std::move(node));
  if (builder.match_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_match_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_match_expr(*std::move(result));
  }
  if (!builder.insert_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_insert_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_insert_column_list(std::move(tmp));
  }
  if (builder.insert_row() != nullptr) {
    std::unique_ptr<const ResolvedInsertRow> tmp =
        builder.release_insert_row();
    absl::StatusOr<std::unique_ptr<const ResolvedInsertRow>> result =
        Dispatch<std::unique_ptr<const ResolvedInsertRow>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_insert_row(*std::move(result));
  }
  if (!builder.update_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateItem>> tmp =
        builder.release_update_item_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateItem>::element_type>(
                 std::move(tmp)));
    builder.set_update_item_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMergeWhen(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMergeStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMergeStmt(*node));
  ResolvedMergeStmtBuilder builder = ToBuilder(std::move(node));
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
  if (builder.from_scan() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_from_scan();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_from_scan(*std::move(result));
  }
  if (builder.merge_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_merge_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_merge_expr(*std::move(result));
  }
  if (!builder.when_clause_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMergeWhen>> tmp =
        builder.release_when_clause_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMergeWhen>::element_type>(
                 std::move(tmp)));
    builder.set_when_clause_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMergeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTruncateStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedTruncateStmt(*node));
  ResolvedTruncateStmtBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedTruncateStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedObjectUnit> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedObjectUnit(*node));
  return PostVisitResolvedObjectUnit(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPrivilege> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPrivilege(*node));
  ResolvedPrivilegeBuilder builder = ToBuilder(std::move(node));
  if (!builder.unit_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedObjectUnit>> tmp =
        builder.release_unit_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedObjectUnit>::element_type>(
                 std::move(tmp)));
    builder.set_unit_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPrivilege(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGrantStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGrantStmt(*node));
  ResolvedGrantStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_privilege_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_privilege_list(std::move(tmp));
  }
  if (!builder.grantee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_grantee_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_grantee_expr_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGrantStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRevokeStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRevokeStmt(*node));
  ResolvedRevokeStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_privilege_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_privilege_list(std::move(tmp));
  }
  if (!builder.grantee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_grantee_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_grantee_expr_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRevokeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterDatabaseStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterDatabaseStmt(*node));
  ResolvedAlterDatabaseStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterDatabaseStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterIndexStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterIndexStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterIndexStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterMaterializedViewStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterMaterializedViewStmt(*node));
  ResolvedAlterMaterializedViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterMaterializedViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterApproxViewStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterApproxViewStmt(*node));
  ResolvedAlterApproxViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterApproxViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterSchemaStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterSchemaStmt(*node));
  ResolvedAlterSchemaStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterExternalSchemaStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterExternalSchemaStmt(*node));
  ResolvedAlterExternalSchemaStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterExternalSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterModelStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterModelStmt(*node));
  ResolvedAlterModelStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterModelStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterTableStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterTableStmt(*node));
  ResolvedAlterTableStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterViewStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterViewStmt(*node));
  ResolvedAlterViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetOptionsAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSetOptionsAction(*node));
  ResolvedSetOptionsActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetOptionsAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterSubEntityAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterSubEntityAction(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterSubEntityAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddSubEntityAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAddSubEntityAction(*node));
  ResolvedAddSubEntityActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.options_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_options_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_options_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddSubEntityAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropSubEntityAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropSubEntityAction(*node));
  return PostVisitResolvedDropSubEntityAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddColumnAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAddColumnAction(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddColumnAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddColumnIdentifierAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAddColumnIdentifierAction(*node));
  ResolvedAddColumnIdentifierActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.options_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_options_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_options_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddColumnIdentifierAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRebuildAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRebuildAction(*node));
  return PostVisitResolvedRebuildAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddConstraintAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAddConstraintAction(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddConstraintAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropConstraintAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropConstraintAction(*node));
  return PostVisitResolvedDropConstraintAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropPrimaryKeyAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropPrimaryKeyAction(*node));
  return PostVisitResolvedDropPrimaryKeyAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnOptionsAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnOptionsAction(*node));
  ResolvedAlterColumnOptionsActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterColumnOptionsAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnDropNotNullAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnDropNotNullAction(*node));
  return PostVisitResolvedAlterColumnDropNotNullAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnDropGeneratedAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnDropGeneratedAction(*node));
  return PostVisitResolvedAlterColumnDropGeneratedAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnSetDataTypeAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnSetDataTypeAction(*node));
  ResolvedAlterColumnSetDataTypeActionBuilder builder = ToBuilder(std::move(node));
  if (builder.updated_annotations() != nullptr) {
    std::unique_ptr<const ResolvedColumnAnnotations> tmp =
        builder.release_updated_annotations();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnAnnotations>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnAnnotations>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_updated_annotations(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterColumnSetDataTypeAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnSetDefaultAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnSetDefaultAction(*node));
  ResolvedAlterColumnSetDefaultActionBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterColumnSetDefaultAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnDropDefaultAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnDropDefaultAction(*node));
  return PostVisitResolvedAlterColumnDropDefaultAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropColumnAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropColumnAction(*node));
  return PostVisitResolvedDropColumnAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRenameColumnAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRenameColumnAction(*node));
  return PostVisitResolvedRenameColumnAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetAsAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSetAsAction(*node));
  return PostVisitResolvedSetAsAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetCollateClause> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSetCollateClause(*node));
  ResolvedSetCollateClauseBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetCollateClause(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterTableSetOptionsStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterTableSetOptionsStmt(*node));
  ResolvedAlterTableSetOptionsStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterTableSetOptionsStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRenameStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRenameStmt(*node));
  ResolvedRenameStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRenameStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreatePrivilegeRestrictionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreatePrivilegeRestrictionStmt(*node));
  ResolvedCreatePrivilegeRestrictionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_column_privilege_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_column_privilege_list(std::move(tmp));
  }
  if (!builder.restrictee_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_restrictee_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_restrictee_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreatePrivilegeRestrictionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateRowAccessPolicyStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateRowAccessPolicyStmt(*node));
  ResolvedCreateRowAccessPolicyStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.grantee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_grantee_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateRowAccessPolicyStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropPrivilegeRestrictionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropPrivilegeRestrictionStmt(*node));
  ResolvedDropPrivilegeRestrictionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_column_privilege_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_column_privilege_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropPrivilegeRestrictionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropRowAccessPolicyStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropRowAccessPolicyStmt(*node));
  ResolvedDropRowAccessPolicyStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropRowAccessPolicyStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropIndexStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropIndexStmt(*node));
  ResolvedDropIndexStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropIndexStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGrantToAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGrantToAction(*node));
  ResolvedGrantToActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.grantee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_grantee_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_grantee_expr_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGrantToAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRestrictToAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRestrictToAction(*node));
  ResolvedRestrictToActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.restrictee_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_restrictee_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_restrictee_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRestrictToAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddToRestricteeListAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAddToRestricteeListAction(*node));
  ResolvedAddToRestricteeListActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.restrictee_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_restrictee_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_restrictee_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAddToRestricteeListAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRemoveFromRestricteeListAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRemoveFromRestricteeListAction(*node));
  ResolvedRemoveFromRestricteeListActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.restrictee_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_restrictee_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_restrictee_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRemoveFromRestricteeListAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterUsingAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFilterUsingAction(*node));
  ResolvedFilterUsingActionBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFilterUsingAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRevokeFromAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRevokeFromAction(*node));
  ResolvedRevokeFromActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.revokee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_revokee_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_revokee_expr_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRevokeFromAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRenameToAction> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRenameToAction(*node));
  return PostVisitResolvedRenameToAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterPrivilegeRestrictionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterPrivilegeRestrictionStmt(*node));
  ResolvedAlterPrivilegeRestrictionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_privilege_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPrivilege>> tmp =
        builder.release_column_privilege_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPrivilege>::element_type>(
                 std::move(tmp)));
    builder.set_column_privilege_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterPrivilegeRestrictionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterRowAccessPolicyStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterRowAccessPolicyStmt(*node));
  ResolvedAlterRowAccessPolicyStmtBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterRowAccessPolicyStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterAllRowAccessPoliciesStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterAllRowAccessPoliciesStmt(*node));
  ResolvedAlterAllRowAccessPoliciesStmtBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterAllRowAccessPoliciesStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateConstantStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateConstantStmt(*node));
  ResolvedCreateConstantStmtBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateConstantStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateFunctionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateFunctionStmt(*node));
  ResolvedCreateFunctionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.aggregate_expression_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_aggregate_expression_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_expression_list(std::move(tmp));
  }
  if (builder.function_expression() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_function_expression();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_function_expression(*std::move(result));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArgumentDef> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedArgumentDef(*node));
  return PostVisitResolvedArgumentDef(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArgumentRef> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedArgumentRef(*node));
  return PostVisitResolvedArgumentRef(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateTableFunctionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateTableFunctionStmt(*node));
  ResolvedCreateTableFunctionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateTableFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRelationArgumentScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedRelationArgumentScan(*node));
  ResolvedRelationArgumentScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRelationArgumentScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArgumentList> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedArgumentList(*node));
  ResolvedArgumentListBuilder builder = ToBuilder(std::move(node));
  if (!builder.arg_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedArgumentDef>> tmp =
        builder.release_arg_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedArgumentDef>::element_type>(
                 std::move(tmp)));
    builder.set_arg_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedArgumentList(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFunctionSignatureHolder> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedFunctionSignatureHolder(*node));
  return PostVisitResolvedFunctionSignatureHolder(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropFunctionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropFunctionStmt(*node));
  ResolvedDropFunctionStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.arguments() != nullptr) {
    std::unique_ptr<const ResolvedArgumentList> tmp =
        builder.release_arguments();
    absl::StatusOr<std::unique_ptr<const ResolvedArgumentList>> result =
        Dispatch<std::unique_ptr<const ResolvedArgumentList>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_arguments(*std::move(result));
  }
  if (builder.signature() != nullptr) {
    std::unique_ptr<const ResolvedFunctionSignatureHolder> tmp =
        builder.release_signature();
    absl::StatusOr<std::unique_ptr<const ResolvedFunctionSignatureHolder>> result =
        Dispatch<std::unique_ptr<const ResolvedFunctionSignatureHolder>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_signature(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropTableFunctionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedDropTableFunctionStmt(*node));
  ResolvedDropTableFunctionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropTableFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCallStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCallStmt(*node));
  ResolvedCallStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_argument_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCallStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedImportStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedImportStmt(*node));
  ResolvedImportStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedImportStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedModuleStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedModuleStmt(*node));
  ResolvedModuleStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedModuleStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAggregateHavingModifier> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAggregateHavingModifier(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAggregateHavingModifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateMaterializedViewStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateMaterializedViewStmt(*node));
  ResolvedCreateMaterializedViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_partition_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.cluster_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_cluster_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_cluster_by_list(std::move(tmp));
  }
  if (builder.replica_source() != nullptr) {
    std::unique_ptr<const ResolvedScan> tmp =
        builder.release_replica_source();
    absl::StatusOr<std::unique_ptr<const ResolvedScan>> result =
        Dispatch<std::unique_ptr<const ResolvedScan>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_replica_source(*std::move(result));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateMaterializedViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateApproxViewStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateApproxViewStmt(*node));
  ResolvedCreateApproxViewStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateApproxViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateProcedureStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateProcedureStmt(*node));
  ResolvedCreateProcedureStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateProcedureStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExecuteImmediateArgument> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExecuteImmediateArgument(*node));
  ResolvedExecuteImmediateArgumentBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExecuteImmediateArgument(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExecuteImmediateStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedExecuteImmediateStmt(*node));
  ResolvedExecuteImmediateStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.sql() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_sql();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_sql(*std::move(result));
  }
  if (!builder.using_argument_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExecuteImmediateArgument>> tmp =
        builder.release_using_argument_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExecuteImmediateArgument>::element_type>(
                 std::move(tmp)));
    builder.set_using_argument_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExecuteImmediateStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssignmentStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAssignmentStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssignmentStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateEntityStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateEntityStmt(*node));
  ResolvedCreateEntityStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateEntityStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterEntityStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterEntityStmt(*node));
  ResolvedAlterEntityStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterEntityStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPivotColumn> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPivotColumn(*node));
  ResolvedPivotColumnBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPivotColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPivotScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPivotScan(*node));
  ResolvedPivotScanBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.pivot_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_pivot_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_pivot_expr_list(std::move(tmp));
  }
  if (builder.for_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_for_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_for_expr(*std::move(result));
  }
  if (!builder.pivot_value_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_pivot_value_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_pivot_value_list(std::move(tmp));
  }
  if (!builder.pivot_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPivotColumn>> tmp =
        builder.release_pivot_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPivotColumn>::element_type>(
                 std::move(tmp)));
    builder.set_pivot_column_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPivotScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedReturningClause> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedReturningClause(*node));
  ResolvedReturningClauseBuilder builder = ToBuilder(std::move(node));
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  if (builder.action_column() != nullptr) {
    std::unique_ptr<const ResolvedColumnHolder> tmp =
        builder.release_action_column();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnHolder>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnHolder>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_action_column(*std::move(result));
  }
  if (!builder.expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_expr_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_expr_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedReturningClause(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUnpivotArg> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUnpivotArg(*node));
  ResolvedUnpivotArgBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUnpivotArg(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUnpivotScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUnpivotScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_value_column_list(std::move(tmp));
  }
  builder.set_label_column(DefaultVisit(builder.label_column()));
  if (!builder.label_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedLiteral>> tmp =
        builder.release_label_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedLiteral>::element_type>(
                 std::move(tmp)));
    builder.set_label_list(std::move(tmp));
  }
  if (!builder.unpivot_arg_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUnpivotArg>> tmp =
        builder.release_unpivot_arg_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUnpivotArg>::element_type>(
                 std::move(tmp)));
    builder.set_unpivot_arg_list(std::move(tmp));
  }
  if (!builder.projected_input_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_projected_input_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_projected_input_column_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUnpivotScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizeScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizeScan(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (builder.partition_by() != nullptr) {
    std::unique_ptr<const ResolvedWindowPartitioning> tmp =
        builder.release_partition_by();
    absl::StatusOr<std::unique_ptr<const ResolvedWindowPartitioning>> result =
        Dispatch<std::unique_ptr<const ResolvedWindowPartitioning>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_partition_by(*std::move(result));
  }
  if (builder.order_by() != nullptr) {
    std::unique_ptr<const ResolvedWindowOrdering> tmp =
        builder.release_order_by();
    absl::StatusOr<std::unique_ptr<const ResolvedWindowOrdering>> result =
        Dispatch<std::unique_ptr<const ResolvedWindowOrdering>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_order_by(*std::move(result));
  }
  if (!builder.pattern_variable_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMatchRecognizeVariableDefinition>> tmp =
        builder.release_pattern_variable_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
    ZETASQL_ASSIGN_OR_RETURN(
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMatchRecognizeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMeasureGroup> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMeasureGroup(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_aggregate_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMeasureGroup(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizeVariableDefinition> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizeVariableDefinition(*node));
  ResolvedMatchRecognizeVariableDefinitionBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMatchRecognizeVariableDefinition(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternEmpty> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternEmpty(*node));
  return PostVisitResolvedMatchRecognizePatternEmpty(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternAnchor> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternAnchor(*node));
  return PostVisitResolvedMatchRecognizePatternAnchor(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternVariableRef> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternVariableRef(*node));
  return PostVisitResolvedMatchRecognizePatternVariableRef(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternOperation> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternOperation(*node));
  ResolvedMatchRecognizePatternOperationBuilder builder = ToBuilder(std::move(node));
  if (!builder.operand_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMatchRecognizePatternExpr>> tmp =
        builder.release_operand_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMatchRecognizePatternExpr>::element_type>(
                 std::move(tmp)));
    builder.set_operand_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMatchRecognizePatternOperation(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternQuantification> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternQuantification(*node));
  ResolvedMatchRecognizePatternQuantificationBuilder builder = ToBuilder(std::move(node));
  if (builder.operand() != nullptr) {
    std::unique_ptr<const ResolvedMatchRecognizePatternExpr> tmp =
        builder.release_operand();
    absl::StatusOr<std::unique_ptr<const ResolvedMatchRecognizePatternExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedMatchRecognizePatternExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_operand(*std::move(result));
  }
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMatchRecognizePatternQuantification(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCloneDataStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCloneDataStmt(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCloneDataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTableAndColumnInfo> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedTableAndColumnInfo(*node));
  return PostVisitResolvedTableAndColumnInfo(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyzeStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAnalyzeStmt(*node));
  ResolvedAnalyzeStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.table_and_column_index_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedTableAndColumnInfo>> tmp =
        builder.release_table_and_column_index_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedTableAndColumnInfo>::element_type>(
                 std::move(tmp)));
    builder.set_table_and_column_index_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAnalyzeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAuxLoadDataPartitionFilter> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAuxLoadDataPartitionFilter(*node));
  ResolvedAuxLoadDataPartitionFilterBuilder builder = ToBuilder(std::move(node));
  if (builder.filter() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_filter();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_filter(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAuxLoadDataPartitionFilter(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAuxLoadDataStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAuxLoadDataStmt(*node));
  ResolvedAuxLoadDataStmtBuilder builder = ToBuilder(std::move(node));
  if (builder.partition_filter() != nullptr) {
    std::unique_ptr<const ResolvedAuxLoadDataPartitionFilter> tmp =
        builder.release_partition_filter();
    absl::StatusOr<std::unique_ptr<const ResolvedAuxLoadDataPartitionFilter>> result =
        Dispatch<std::unique_ptr<const ResolvedAuxLoadDataPartitionFilter>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_partition_filter(*std::move(result));
  }
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  if (!builder.column_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnDefinition>> tmp =
        builder.release_column_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_column_definition_list(std::move(tmp));
  }
  if (!builder.pseudo_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_pseudo_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedForeignKey>::element_type>(
                 std::move(tmp)));
    builder.set_foreign_key_list(std::move(tmp));
  }
  if (!builder.check_constraint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedCheckConstraint>> tmp =
        builder.release_check_constraint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedCheckConstraint>::element_type>(
                 std::move(tmp)));
    builder.set_check_constraint_list(std::move(tmp));
  }
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_partition_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
  }
  if (!builder.cluster_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_cluster_by_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_cluster_by_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (builder.with_partition_columns() != nullptr) {
    std::unique_ptr<const ResolvedWithPartitionColumns> tmp =
        builder.release_with_partition_columns();
    absl::StatusOr<std::unique_ptr<const ResolvedWithPartitionColumns>> result =
        Dispatch<std::unique_ptr<const ResolvedWithPartitionColumns>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_with_partition_columns(*std::move(result));
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
  if (!builder.from_files_option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_from_files_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_from_files_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAuxLoadDataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreatePropertyGraphStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreatePropertyGraphStmt(*node));
  ResolvedCreatePropertyGraphStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.node_table_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphElementTable>> tmp =
        builder.release_node_table_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementTable>::element_type>(
                 std::move(tmp)));
    builder.set_node_table_list(std::move(tmp));
  }
  if (!builder.edge_table_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphElementTable>> tmp =
        builder.release_edge_table_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementTable>::element_type>(
                 std::move(tmp)));
    builder.set_edge_table_list(std::move(tmp));
  }
  if (!builder.label_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphElementLabel>> tmp =
        builder.release_label_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementLabel>::element_type>(
                 std::move(tmp)));
    builder.set_label_list(std::move(tmp));
  }
  if (!builder.property_declaration_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphPropertyDeclaration>> tmp =
        builder.release_property_declaration_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphPropertyDeclaration>::element_type>(
                 std::move(tmp)));
    builder.set_property_declaration_list(std::move(tmp));
  }
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreatePropertyGraphStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementTable> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementTable(*node));
  ResolvedGraphElementTableBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.key_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_key_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_key_list(std::move(tmp));
  }
  if (builder.source_node_reference() != nullptr) {
    std::unique_ptr<const ResolvedGraphNodeTableReference> tmp =
        builder.release_source_node_reference();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphNodeTableReference>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphNodeTableReference>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_source_node_reference(*std::move(result));
  }
  if (builder.dest_node_reference() != nullptr) {
    std::unique_ptr<const ResolvedGraphNodeTableReference> tmp =
        builder.release_dest_node_reference();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphNodeTableReference>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphNodeTableReference>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_dest_node_reference(*std::move(result));
  }
  if (!builder.property_definition_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphPropertyDefinition>> tmp =
        builder.release_property_definition_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphPropertyDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_property_definition_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphElementTable(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphNodeTableReference> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphNodeTableReference(*node));
  ResolvedGraphNodeTableReferenceBuilder builder = ToBuilder(std::move(node));
  if (!builder.edge_table_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_edge_table_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_edge_table_column_list(std::move(tmp));
  }
  if (!builder.node_table_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_node_table_column_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_node_table_column_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphNodeTableReference(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementLabel> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementLabel(*node));
  return PostVisitResolvedGraphElementLabel(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPropertyDeclaration> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphPropertyDeclaration(*node));
  return PostVisitResolvedGraphPropertyDeclaration(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPropertyDefinition> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphPropertyDefinition(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPropertyDefinition(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphRefScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphRefScan(*node));
  ResolvedGraphRefScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphRefScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphLinearScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphLinearScan(*node));
  ResolvedGraphLinearScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.scan_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedScan>> tmp =
        builder.release_scan_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedScan>::element_type>(
                 std::move(tmp)));
    builder.set_scan_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphLinearScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphTableScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphTableScan(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_shape_expr_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphTableScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphScan(*node));
  ResolvedGraphScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_scan_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphPathScan>> tmp =
        builder.release_input_scan_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathPatternQuantifier> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathPatternQuantifier(*node));
  ResolvedGraphPathPatternQuantifierBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPathPatternQuantifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathSearchPrefix> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathSearchPrefix(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPathSearchPrefix(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphNodeScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphNodeScan(*node));
  ResolvedGraphNodeScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphNodeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphEdgeScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphEdgeScan(*node));
  ResolvedGraphEdgeScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.lhs_hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_lhs_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_lhs_hint_list(std::move(tmp));
  }
  if (!builder.rhs_hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_rhs_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_rhs_hint_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphEdgeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphGetElementProperty> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphGetElementProperty(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphGetElementProperty(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphLabelNaryExpr> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphLabelNaryExpr(*node));
  ResolvedGraphLabelNaryExprBuilder builder = ToBuilder(std::move(node));
  if (!builder.operand_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphLabelExpr>> tmp =
        builder.release_operand_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphLabelExpr>::element_type>(
                 std::move(tmp)));
    builder.set_operand_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphLabelNaryExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphLabel> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphLabel(*node));
  return PostVisitResolvedGraphLabel(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphWildCardLabel> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphWildCardLabel(*node));
  return PostVisitResolvedGraphWildCardLabel(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementIdentifier> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementIdentifier(*node));
  ResolvedGraphElementIdentifierBuilder builder = ToBuilder(std::move(node));
  if (!builder.key_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_key_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_key_list(std::move(tmp));
  }
  if (builder.source_node_identifier() != nullptr) {
    std::unique_ptr<const ResolvedGraphElementIdentifier> tmp =
        builder.release_source_node_identifier();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphElementIdentifier>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphElementIdentifier>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_source_node_identifier(*std::move(result));
  }
  if (builder.dest_node_identifier() != nullptr) {
    std::unique_ptr<const ResolvedGraphElementIdentifier> tmp =
        builder.release_dest_node_identifier();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphElementIdentifier>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphElementIdentifier>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_dest_node_identifier(*std::move(result));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphElementIdentifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementProperty> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementProperty(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphElementProperty(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphMakeElement> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphMakeElement(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementProperty>::element_type>(
                 std::move(tmp)));
    builder.set_property_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphMakeElement(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArrayAggregate> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedArrayAggregate(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedArrayAggregate(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphMakeArrayVariable> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphMakeArrayVariable(*node));
  ResolvedGraphMakeArrayVariableBuilder builder = ToBuilder(std::move(node));
  builder.set_element(DefaultVisit(builder.element()));
  builder.set_array(DefaultVisit(builder.array()));
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphMakeArrayVariable(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathMode> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathMode(*node));
  return PostVisitResolvedGraphPathMode(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathScan(*node));
  ResolvedGraphPathScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_scan_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphPathScanBase>> tmp =
        builder.release_input_scan_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphPathScanBase>::element_type>(
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
  if (builder.path() != nullptr) {
    std::unique_ptr<const ResolvedColumnHolder> tmp =
        builder.release_path();
    absl::StatusOr<std::unique_ptr<const ResolvedColumnHolder>> result =
        Dispatch<std::unique_ptr<const ResolvedColumnHolder>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_path(*std::move(result));
  }
  builder.set_head(DefaultVisit(builder.head()));
  builder.set_tail(DefaultVisit(builder.tail()));
  if (!builder.path_hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_path_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_path_hint_list(std::move(tmp));
  }
  if (builder.quantifier() != nullptr) {
    std::unique_ptr<const ResolvedGraphPathPatternQuantifier> tmp =
        builder.release_quantifier();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphPathPatternQuantifier>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphPathPatternQuantifier>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_quantifier(*std::move(result));
  }
  if (!builder.group_variable_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphMakeArrayVariable>> tmp =
        builder.release_group_variable_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphMakeArrayVariable>::element_type>(
                 std::move(tmp)));
    builder.set_group_variable_list(std::move(tmp));
  }
  if (builder.path_mode() != nullptr) {
    std::unique_ptr<const ResolvedGraphPathMode> tmp =
        builder.release_path_mode();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphPathMode>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphPathMode>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_path_mode(*std::move(result));
  }
  if (builder.search_prefix() != nullptr) {
    std::unique_ptr<const ResolvedGraphPathSearchPrefix> tmp =
        builder.release_search_prefix();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphPathSearchPrefix>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphPathSearchPrefix>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_search_prefix(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPathScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphIsLabeledPredicate> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGraphIsLabeledPredicate(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphIsLabeledPredicate(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUndropStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUndropStmt(*node));
  ResolvedUndropStmtBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUndropStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedIdentityColumnInfo> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedIdentityColumnInfo(*node));
  return PostVisitResolvedIdentityColumnInfo(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedStaticDescribeScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedStaticDescribeScan(*node));
  ResolvedStaticDescribeScanBuilder builder = ToBuilder(std::move(node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedStaticDescribeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssertScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAssertScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssertScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedLogScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedLogScan(*node));
  ResolvedLogScanBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedLogScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeIfScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPipeIfScan(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPipeIfCase>::element_type>(
                 std::move(tmp)));
    builder.set_if_case_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeIfScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeIfCase> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPipeIfCase(*node));
  ResolvedPipeIfCaseBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeIfCase(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeForkScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPipeForkScan(*node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGeneralizedQuerySubpipeline>::element_type>(
                 std::move(tmp)));
    builder.set_subpipeline_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeForkScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeTeeScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPipeTeeScan(*node));
  ResolvedPipeTeeScanBuilder builder = ToBuilder(std::move(node));
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
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGeneralizedQuerySubpipeline>::element_type>(
                 std::move(tmp)));
    builder.set_subpipeline_list(std::move(tmp));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeTeeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeExportDataScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPipeExportDataScan(*node));
  ResolvedPipeExportDataScanBuilder builder = ToBuilder(std::move(node));
  if (builder.export_data_stmt() != nullptr) {
    std::unique_ptr<const ResolvedExportDataStmt> tmp =
        builder.release_export_data_stmt();
    absl::StatusOr<std::unique_ptr<const ResolvedExportDataStmt>> result =
        Dispatch<std::unique_ptr<const ResolvedExportDataStmt>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_export_data_stmt(*std::move(result));
  }
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeExportDataScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeCreateTableScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPipeCreateTableScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeCreateTableScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeInsertScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedPipeInsertScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeInsertScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSubpipeline> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSubpipeline(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSubpipeline(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSubpipelineInputScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedSubpipelineInputScan(*node));
  ResolvedSubpipelineInputScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSubpipelineInputScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGeneralizedQuerySubpipeline> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedGeneralizedQuerySubpipeline(*node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGeneralizedQuerySubpipeline(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedBarrierScan> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedBarrierScan(*node));
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
      ZETASQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_column_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedBarrierScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateConnectionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedCreateConnectionStmt(*node));
  ResolvedCreateConnectionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateConnectionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterConnectionStmt> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedAlterConnectionStmt(*node));
  ResolvedAlterConnectionStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_hint_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  if (!builder.alter_action_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedAlterAction>> tmp =
        builder.release_alter_action_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAlterAction>::element_type>(
                 std::move(tmp)));
    builder.set_alter_action_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterConnectionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedLockMode> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedLockMode(*node));
  return PostVisitResolvedLockMode(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateFieldItem> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUpdateFieldItem(*node));
  ResolvedUpdateFieldItemBuilder builder = ToBuilder(std::move(node));
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
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateFieldItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateConstructor> node) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedUpdateConstructor(*node));
  ResolvedUpdateConstructorBuilder builder = ToBuilder(std::move(node));
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
  if (!builder.update_field_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedUpdateFieldItem>> tmp =
        builder.release_update_field_item_list();
    ZETASQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateFieldItem>::element_type>(
                 std::move(tmp)));
    builder.set_update_field_item_list(std::move(tmp));
  }
  ZETASQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateConstructor(std::move(built));
}

absl::StatusOr<ResolvedColumn>
ResolvedASTRewriteVisitor::DefaultVisit(ResolvedColumn column) {
  ZETASQL_RETURN_IF_ERROR(PreVisitResolvedColumn(column));
  return PostVisitResolvedColumn(std::move(column));
}
}  // namespace zetasql