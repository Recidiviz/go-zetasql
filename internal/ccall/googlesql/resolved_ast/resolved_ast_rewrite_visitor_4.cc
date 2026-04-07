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
    std::unique_ptr<const ResolvedLiteral> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedLiteral(*node));
  ResolvedLiteralBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedLiteral(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSystemVariable> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSystemVariable(*node));
  ResolvedSystemVariableBuilder builder = ToBuilder(std::move(node));
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSystemVariable(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExtendedCastElement> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExtendedCastElement(*node));
  ResolvedExtendedCastElementBuilder builder = ToBuilder(std::move(node));
  builder.set_from_type(DefaultVisit(builder.from_type()));
  builder.set_to_type(DefaultVisit(builder.to_type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExtendedCastElement(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMakeProto> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMakeProto(*node));
  ResolvedMakeProtoBuilder builder = ToBuilder(std::move(node));
  if (!builder.field_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMakeProtoField>> tmp =
        builder.release_field_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMakeProtoField>::element_type>(
                 std::move(tmp)));
    builder.set_field_list(std::move(tmp));
  }
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMakeProto(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGetProtoField> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGetProtoField(*node));
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
  builder.set_type(DefaultVisit(builder.type()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGetProtoField(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedConnection> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedConnection(*node));
  return PostVisitResolvedConnection(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDescriptor> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDescriptor(*node));
  ResolvedDescriptorBuilder builder = ToBuilder(std::move(node));
  if (!builder.descriptor_column_list().empty()) {
    std::vector<ResolvedColumn> tmp = builder.release_descriptor_column_list();
    for (int i = 0; i < tmp.size(); ++i) {
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_descriptor_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDescriptor(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingCall> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGroupingCall(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingCall(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingSetList> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGroupingSetList(*node));
  ResolvedGroupingSetListBuilder builder = ToBuilder(std::move(node));
  if (!builder.elem_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedGroupingSetBase>> tmp =
        builder.release_elem_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedGroupingSetBase>::element_type>(
                 std::move(tmp)));
    builder.set_elem_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingSetList(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGroupingSet> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGroupingSet(*node));
  ResolvedGroupingSetBuilder builder = ToBuilder(std::move(node));
  if (!builder.group_by_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedColumnRef>> tmp =
        builder.release_group_by_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedColumnRef>::element_type>(
                 std::move(tmp)));
    builder.set_group_by_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGroupingSet(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetOperationItem> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSetOperationItem(*node));
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
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
    }
    builder.set_output_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedSetOperationItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetOperationScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSetOperationScan(*node));
  ResolvedSetOperationScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.input_item_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedSetOperationItem>> tmp =
        builder.release_input_item_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedSetOperationItem>::element_type>(
                 std::move(tmp)));
    builder.set_input_item_list(std::move(tmp));
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
  return PostVisitResolvedSetOperationScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedLimitOffsetScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedLimitOffsetScan(*node));
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
  return PostVisitResolvedLimitOffsetScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyticScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAnalyticScan(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedAnalyticFunctionGroup>::element_type>(
                 std::move(tmp)));
    builder.set_function_group_list(std::move(tmp));
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
  return PostVisitResolvedAnalyticScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOrderByItem> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedOrderByItem(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOrderByItem(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedColumnDefaultValue> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedColumnDefaultValue(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedColumnDefaultValue(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCheckConstraint> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCheckConstraint(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_option_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCheckConstraint(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFunctionArgument> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFunctionArgument(*node));
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
      GOOGLESQL_ASSIGN_OR_RETURN(tmp[i], DefaultVisit(std::move(tmp[i])));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFunctionArgument(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateExternalSchemaStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateExternalSchemaStmt(*node));
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
  return PostVisitResolvedCreateExternalSchemaStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateModelAliasedQuery> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateModelAliasedQuery(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOutputColumn>::element_type>(
                 std::move(tmp)));
    builder.set_output_column_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateModelAliasedQuery(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExportMetadataStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExportMetadataStmt(*node));
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
  return PostVisitResolvedExportMetadataStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSetTransactionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSetTransactionStmt(*node));
  ResolvedSetTransactionStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedSetTransactionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedStartBatchStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedStartBatchStmt(*node));
  ResolvedStartBatchStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedStartBatchStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropStmt(*node));
  ResolvedDropStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedDropStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropMaterializedViewStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropMaterializedViewStmt(*node));
  ResolvedDropMaterializedViewStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedDropMaterializedViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWithScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWithScan(*node));
  ResolvedWithScanBuilder builder = ToBuilder(std::move(node));
  if (!builder.with_entry_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedWithEntry>> tmp =
        builder.release_with_entry_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
  return PostVisitResolvedWithScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedOption> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedOption(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedOption(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAnalyticFunctionGroup> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAnalyticFunctionGroup(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumnBase>::element_type>(
                 std::move(tmp)));
    builder.set_analytic_function_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAnalyticFunctionGroup(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedWindowFrameExpr> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedWindowFrameExpr(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedWindowFrameExpr(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAssertRowsModified> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAssertRowsModified(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAssertRowsModified(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMergeStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMergeStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMergeWhen>::element_type>(
                 std::move(tmp)));
    builder.set_when_clause_list(std::move(tmp));
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
  return PostVisitResolvedMergeStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedTruncateStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedTruncateStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedTruncateStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGrantStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGrantStmt(*node));
  ResolvedGrantStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedGrantStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterViewStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterViewStmt(*node));
  ResolvedAlterViewStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterViewStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddSubEntityAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAddSubEntityAction(*node));
  ResolvedAddSubEntityActionBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAddSubEntityAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRebuildAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRebuildAction(*node));
  return PostVisitResolvedRebuildAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropConstraintAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropConstraintAction(*node));
  return PostVisitResolvedDropConstraintAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnOptionsAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnOptionsAction(*node));
  ResolvedAlterColumnOptionsActionBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAlterColumnOptionsAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnDropGeneratedAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnDropGeneratedAction(*node));
  return PostVisitResolvedAlterColumnDropGeneratedAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterColumnSetDataTypeAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterColumnSetDataTypeAction(*node));
  ResolvedAlterColumnSetDataTypeActionBuilder builder = ToBuilder(std::move(node));
  builder.set_updated_type(DefaultVisit(builder.updated_type()));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAlterColumnSetDataTypeAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRestrictToAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRestrictToAction(*node));
  ResolvedRestrictToActionBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedRestrictToAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAddToRestricteeListAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAddToRestricteeListAction(*node));
  ResolvedAddToRestricteeListActionBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedAddToRestricteeListAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFilterUsingAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFilterUsingAction(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedFilterUsingAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRevokeFromAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRevokeFromAction(*node));
  ResolvedRevokeFromActionBuilder builder = ToBuilder(std::move(node));
  if (!builder.revokee_expr_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_revokee_expr_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedExpr>::element_type>(
                 std::move(tmp)));
    builder.set_revokee_expr_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedRevokeFromAction(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedRenameToAction> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedRenameToAction(*node));
  return PostVisitResolvedRenameToAction(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterRowAccessPolicyStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterRowAccessPolicyStmt(*node));
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
  return PostVisitResolvedAlterRowAccessPolicyStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAlterAllRowAccessPoliciesStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAlterAllRowAccessPoliciesStmt(*node));
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
  return PostVisitResolvedAlterAllRowAccessPoliciesStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedCreateConstantStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedCreateConstantStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedCreateConstantStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedFunctionSignatureHolder> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedFunctionSignatureHolder(*node));
  return PostVisitResolvedFunctionSignatureHolder(std::move(node));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDropFunctionStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDropFunctionStmt(*node));
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedOption>::element_type>(
                 std::move(tmp)));
    builder.set_hint_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedDropFunctionStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedExecuteImmediateArgument> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedExecuteImmediateArgument(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedExecuteImmediateArgument(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPivotColumn> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPivotColumn(*node));
  ResolvedPivotColumnBuilder builder = ToBuilder(std::move(node));
  builder.set_column(DefaultVisit(builder.column()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPivotColumn(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedReturningClause> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedReturningClause(*node));
  ResolvedReturningClauseBuilder builder = ToBuilder(std::move(node));
  if (!builder.output_column_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedOutputColumn>> tmp =
        builder.release_output_column_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedComputedColumn>::element_type>(
                 std::move(tmp)));
    builder.set_expr_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedReturningClause(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizeVariableDefinition> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizeVariableDefinition(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMatchRecognizeVariableDefinition(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedMatchRecognizePatternOperation> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedMatchRecognizePatternOperation(*node));
  ResolvedMatchRecognizePatternOperationBuilder builder = ToBuilder(std::move(node));
  if (!builder.operand_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedMatchRecognizePatternExpr>> tmp =
        builder.release_operand_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
        tmp, DispatchNodeList<
                 std::unique_ptr<const ResolvedMatchRecognizePatternExpr>::element_type>(
                 std::move(tmp)));
    builder.set_operand_list(std::move(tmp));
  }
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedMatchRecognizePatternOperation(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedAuxLoadDataPartitionFilter> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedAuxLoadDataPartitionFilter(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedAuxLoadDataPartitionFilter(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphElementIdentifier> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphElementIdentifier(*node));
  ResolvedGraphElementIdentifierBuilder builder = ToBuilder(std::move(node));
  if (!builder.key_list().empty()) {
    std::vector<std::unique_ptr<const ResolvedExpr>> tmp =
        builder.release_key_list();
    GOOGLESQL_ASSIGN_OR_RETURN(
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphElementIdentifier(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedGraphMakeArrayVariable> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedGraphMakeArrayVariable(*node));
  ResolvedGraphMakeArrayVariableBuilder builder = ToBuilder(std::move(node));
  builder.set_element(DefaultVisit(builder.element()));
  builder.set_array(DefaultVisit(builder.array()));
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedGraphMakeArrayVariable(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUndropStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUndropStmt(*node));
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
  return PostVisitResolvedUndropStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedDescribeScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedDescribeScan(*node));
  ResolvedDescribeScanBuilder builder = ToBuilder(std::move(node));
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
  if (builder.describe_expr() != nullptr) {
    std::unique_ptr<const ResolvedComputedColumn> tmp =
        builder.release_describe_expr();
    absl::StatusOr<std::unique_ptr<const ResolvedComputedColumn>> result =
        Dispatch<std::unique_ptr<const ResolvedComputedColumn>::element_type>(
            std::move(tmp));
    if (!result.ok()) {
      return std::move(result).status();
    }
    builder.set_describe_expr(*std::move(result));
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
  return PostVisitResolvedDescribeScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeIfCase> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPipeIfCase(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedPipeIfCase(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedPipeExportDataScan> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedPipeExportDataScan(*node));
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
  return PostVisitResolvedPipeExportDataScan(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedSubpipelineStmt> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedSubpipelineStmt(*node));
  ResolvedSubpipelineStmtBuilder builder = ToBuilder(std::move(node));
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
  return PostVisitResolvedSubpipelineStmt(std::move(built));
}

absl::StatusOr<std::unique_ptr<const ResolvedNode>>
ResolvedASTRewriteVisitor::DefaultVisit(
    std::unique_ptr<const ResolvedUpdateFieldItem> node) {
  GOOGLESQL_RETURN_IF_ERROR(PreVisitResolvedUpdateFieldItem(*node));
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
  GOOGLESQL_ASSIGN_OR_RETURN(auto built, std::move(builder).Build());
  return PostVisitResolvedUpdateFieldItem(std::move(built));
}

}  // namespace googlesql