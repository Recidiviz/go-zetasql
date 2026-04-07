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
    std::unique_ptr<const ResolvedSequence> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSequence(*node));
  return PostVisitResolvedSequence(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCast> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCast(*node));
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
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCast(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFlattenedArg> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFlattenedArg(*node));
  ResolvedFlattenedArgBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFlattenedArg(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedReplaceFieldItem> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedReplaceFieldItem(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedReplaceFieldItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetProtoOneof> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGetProtoOneof(*node));
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
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGetProtoOneof(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithExpr> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWithExpr(*node));
  ResolvedWithExprBuilder builder = ToBuilder(std::move(node));
  if (!builder.assignment_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_assignment_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedModel> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedModel(*node));
  return PostVisitResolvedModel(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnHolder> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedColumnHolder(*node));
  ResolvedColumnHolderBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnHolder(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFilterScan(*node));
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
  return PostVisitResolvedFilterScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingSetProduct> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGroupingSetProduct(*node));
  ResolvedGroupingSetProductBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_input_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_input_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingSetProduct(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnonymizedAggregateScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAnonymizedAggregateScan(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_anonymization_option_list(std::move(tmp));
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
  return PostVisitResolvedAnonymizedAggregateScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSampleScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSampleScan(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
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
  return PostVisitResolvedSampleScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDeferredComputedColumn> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDeferredComputedColumn(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDeferredComputedColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnAnnotations> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedColumnAnnotations(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  if (!builder.child_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnAnnotations>> tmp =
        builder.release_child_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnAnnotations>::element_type>(
                 std::move(tmp)));
    builder.set_child_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnAnnotations(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedStatementWithPipeOperatorsStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedStatementWithPipeOperatorsStmt(*node));
  ResolvedStatementWithPipeOperatorsStmtBuilder builder = ToBuilder(std::move(node));
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
  if (builder.suffix_subpipeline_sql() != nullptr) {
    std::unique_ptr<const ResolvedStringWithLocation> tmp =
        builder.release_suffix_subpipeline_sql();
    absl::StatusOr<std::unique_ptr<const ResolvedStringWithLocation>> result =
        Dispatch<std::unique_ptr<const ResolvedStringWithLocation>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_suffix_subpipeline_sql(*std::move(result));
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
  return PostVisitResolvedStatementWithPipeOperatorsStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUnnestItem> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUnnestItem(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUnnestItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateExternalTableStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateExternalTableStmt(*node));
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
  return PostVisitResolvedCreateExternalTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAbortBatchStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAbortBatchStmt(*node));
  ResolvedAbortBatchStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAbortBatchStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropSnapshotTableStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropSnapshotTableStmt(*node));
  ResolvedDropSnapshotTableStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedDropSnapshotTableStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRecursiveRefScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRecursiveRefScan(*node));
  ResolvedRecursiveRefScanBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedRecursiveRefScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithEntry> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWithEntry(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWithEntry(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowPartitioning> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWindowPartitioning(*node));
  ResolvedWindowPartitioningBuilder builder = ToBuilder(std::move(node));
  if (!builder.partition_by_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_partition_by_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_partition_by_list(std::move(tmp));
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
  return PostVisitResolvedWindowPartitioning(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDMLValue> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDMLValue(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDMLValue(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOnConflictClause> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedOnConflictClause(*node));
  ResolvedOnConflictClauseBuilder builder = ToBuilder(std::move(node));
  if (!builder.conflict_target_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_conflict_target_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOnConflictClause(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedInsertStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedInsertStmt(*node));
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
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_insert_column_list(std::move(tmp));
  }
  if (!builder.query_parameter_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_query_parameter_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_query_output_column_list(std::move(tmp));
  }
  if (!builder.row_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedInsertRow>> tmp =
        builder.release_row_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_generated_column_expr_list(std::move(tmp));
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
  return PostVisitResolvedInsertStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDeleteStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDeleteStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDeleteStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUpdateStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_generated_column_expr_list(std::move(tmp));
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
  return PostVisitResolvedUpdateStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMergeWhen> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMergeWhen(*node));
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
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateItem>::element_type>(
                 std::move(tmp)));
    builder.set_update_item_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMergeWhen(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedObjectUnit> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedObjectUnit(*node));
  return PostVisitResolvedObjectUnit(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPrivilege> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPrivilege(*node));
  ResolvedPrivilegeBuilder builder = ToBuilder(std::move(node));
  if (!builder.unit_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedObjectUnit>> tmp =
        builder.release_unit_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedObjectUnit>::element_type>(
                 std::move(tmp)));
    builder.set_unit_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPrivilege(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterExternalSchemaStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterExternalSchemaStmt(*node));
  ResolvedAlterExternalSchemaStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterExternalSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnDropNotNullAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnDropNotNullAction(*node));
  return PostVisitResolvedAlterColumnDropNotNullAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnSetDefaultAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnSetDefaultAction(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterColumnSetDefaultAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropColumnAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropColumnAction(*node));
  return PostVisitResolvedDropColumnAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetAsAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSetAsAction(*node));
  return PostVisitResolvedSetAsAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetCollateClause> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSetCollateClause(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetCollateClause(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateFunctionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateFunctionStmt(*node));
  ResolvedCreateFunctionStmtBuilder builder = ToBuilder(std::move(node));
  builder.set_return_type(DefaultVisit(builder.return_type()));
  if (!builder.aggregate_expression_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedComputedColumn>> tmp =
        builder.release_aggregate_expression_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
  return PostVisitResolvedCreateFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArgumentDef> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedArgumentDef(*node));
  ResolvedArgumentDefBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedArgumentDef(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedArgumentList> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedArgumentList(*node));
  ResolvedArgumentListBuilder builder = ToBuilder(std::move(node));
  if (!builder.arg_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedArgumentDef>> tmp =
        builder.release_arg_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedArgumentDef>::element_type>(
                 std::move(tmp)));
    builder.set_arg_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedArgumentList(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropTableFunctionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropTableFunctionStmt(*node));
  ResolvedDropTableFunctionStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedDropTableFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedModuleStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedModuleStmt(*node));
  ResolvedModuleStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedModuleStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateMaterializedViewStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateMaterializedViewStmt(*node));
  ResolvedCreateMaterializedViewStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedCreateMaterializedViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExecuteImmediateStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExecuteImmediateStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExecuteImmediateArgument>::element_type>(
                 std::move(tmp)));
    builder.set_using_argument_list(std::move(tmp));
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
  return PostVisitResolvedExecuteImmediateStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPivotScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPivotScan(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_list(std::move(tmp));
  }
  if (!builder.pivot_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_pivot_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_pivot_value_list(std::move(tmp));
  }
  if (!builder.pivot_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedPivotColumn>> tmp =
        builder.release_pivot_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedPivotColumn>::element_type>(
                 std::move(tmp)));
    builder.set_pivot_column_list(std::move(tmp));
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
  return PostVisitResolvedPivotScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternEmpty> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternEmpty(*node));
  return PostVisitResolvedMatchRecognizePatternEmpty(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternAnchor> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternAnchor(*node));
  return PostVisitResolvedMatchRecognizePatternAnchor(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternQuantification> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternQuantification(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMatchRecognizePatternQuantification(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTableAndColumnInfo> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedTableAndColumnInfo(*node));
  return PostVisitResolvedTableAndColumnInfo(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAuxLoadDataStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAuxLoadDataStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
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
  if (!builder.option_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_option_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_from_files_option_list(std::move(tmp));
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
  return PostVisitResolvedAuxLoadDataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreatePropertyGraphStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreatePropertyGraphStmt(*node));
  ResolvedCreatePropertyGraphStmtBuilder builder = ToBuilder(std::move(node));
  if (!builder.node_table_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphElementTable>> tmp =
        builder.release_node_table_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementTable>::element_type>(
                 std::move(tmp)));
    builder.set_node_table_list(std::move(tmp));
  }
  if (!builder.edge_table_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphElementTable>> tmp =
        builder.release_edge_table_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementTable>::element_type>(
                 std::move(tmp)));
    builder.set_edge_table_list(std::move(tmp));
  }
  if (!builder.label_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphElementLabel>> tmp =
        builder.release_label_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphElementLabel>::element_type>(
                 std::move(tmp)));
    builder.set_label_list(std::move(tmp));
  }
  if (!builder.property_declaration_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphPropertyDeclaration>> tmp =
        builder.release_property_declaration_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphPropertyDeclaration>::element_type>(
                 std::move(tmp)));
    builder.set_property_declaration_list(std::move(tmp));
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
  return PostVisitResolvedCreatePropertyGraphStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementTable> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementTable(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGraphPropertyDefinition>::element_type>(
                 std::move(tmp)));
    builder.set_property_definition_list(std::move(tmp));
  }
  if (builder.dynamic_label() != nullptr) {
    std::unique_ptr<const ResolvedGraphDynamicLabelSpecification> tmp =
        builder.release_dynamic_label();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphDynamicLabelSpecification>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphDynamicLabelSpecification>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_dynamic_label(*std::move(result));
  }
  if (builder.dynamic_properties() != nullptr) {
    std::unique_ptr<const ResolvedGraphDynamicPropertiesSpecification> tmp =
        builder.release_dynamic_properties();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphDynamicPropertiesSpecification>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphDynamicPropertiesSpecification>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_dynamic_properties(*std::move(result));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphElementTable(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementLabel> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementLabel(*node));
  ResolvedGraphElementLabelBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedGraphElementLabel(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPropertyDeclaration> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphPropertyDeclaration(*node));
  ResolvedGraphPropertyDeclarationBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPropertyDeclaration(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphRefScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphRefScan(*node));
  ResolvedGraphRefScanBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedGraphRefScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathPatternQuantifier> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathPatternQuantifier(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphPathPatternQuantifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphEdgeScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphEdgeScan(*node));
  ResolvedGraphEdgeScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.lhs_hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_lhs_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_lhs_hint_list(std::move(tmp));
  }
  if (!builder.rhs_hint_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOption>> tmp =
        builder.release_rhs_hint_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_rhs_hint_list(std::move(tmp));
  }
  if (builder.cost_expr() != nullptr) {
    std::unique_ptr<const ResolvedExpr> tmp =
        builder.release_cost_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedExpr>> result =
        Dispatch<std::unique_ptr<const ResolvedExpr>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_cost_expr(*std::move(result));
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
  return PostVisitResolvedGraphEdgeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathMode> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathMode(*node));
  return PostVisitResolvedGraphPathMode(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphPathScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphPathScan(*node));
  ResolvedGraphPathScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_scan_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGraphPathScanBase>> tmp =
        builder.release_input_scan_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
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
  if (builder.path_cost() != nullptr) {
    std::unique_ptr<const ResolvedGraphPathCost> tmp =
        builder.release_path_cost();
    absl::StatusOr<std::unique_ptr<const ResolvedGraphPathCost>> result =
        Dispatch<std::unique_ptr<const ResolvedGraphPathCost>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_path_cost(*std::move(result));
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
  return PostVisitResolvedGraphPathScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedIdentityColumnInfo> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedIdentityColumnInfo(*node));
  return PostVisitResolvedIdentityColumnInfo(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedStaticDescribeScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedStaticDescribeScan(*node));
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
  return PostVisitResolvedStaticDescribeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedLogScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedLogScan(*node));
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
  return PostVisitResolvedLogScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeTeeScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPipeTeeScan(*node));
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
  return PostVisitResolvedPipeTeeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateConstructor> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUpdateConstructor(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedUpdateFieldItem>::element_type>(
                 std::move(tmp)));
    builder.set_update_field_item_list(std::move(tmp));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateConstructor(std::move(built));
}

absl::StatusOr<ResolvedColumn>
ResolvedASTRewriteVisitor::DefaultVisit(ResolvedColumn column) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedColumn(column));
  return PostVisitResolvedColumn(std::move(column));
}

absl::StatusOr<const Type*>
ResolvedASTRewriteVisitor::DefaultVisit(const Type* type) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitType(type));
  return PostVisitType(type);
}
}  // namespace googlesql