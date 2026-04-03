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

// resolved_ast_rewrite_visitor.h GENERATED FROM resolved_ast_rewrite_visitor.h.template

#ifndef ZETASQL_RESOLVED_AST_RESOLVED_AST_REWRITER_VISITOR_H_
#define ZETASQL_RESOLVED_AST_RESOLVED_AST_REWRITER_VISITOR_H_

#include <algorithm>
#include <memory>
#include <stack>
#include <type_traits>
#include <utility>
#include <vector>

#include "zetasql/common/thread_stack.h"
#include "zetasql/resolved_ast/resolved_ast.h"
#include "zetasql/resolved_ast/resolved_ast_builder.h"
#include "zetasql/resolved_ast/resolved_node.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "zetasql/base/ret_check.h"

namespace zetasql {

// A visitor used to perform a deep transform of a resolved AST in place.
//
// The key feature of this visitor is that it operates on
// unique_ptr<const ResolvedNode>. So, each operatation is given ownership of
// the input object, and require to return ownership of another object. The
// "no-op" case is therefore to just return the input.
//
// Each concrete node ResolvedNodeX has an associated PreVisit and PostVisit
// virtual function:
//
//   Status PreVisitResolvedX(const ResolvedNodeX& node);
//   StatusOr<unique_ptr<const ResolvedX>>
//       PostVisitResolvedX(unique_ptr<const ResolvedNodeX*> node);
//
// PreVisitX is called before a node or its children are copied, it
//   is useful in cases where you need to keep some state about an object
//   before it is modified, or whether to know if you are in a particular
//   subtree. However, it is rarely needed in practice.
//
// PostVisitX is the main mechanism for transforming a node. It is called after
//   all children have been visit/copied.
//
// THERE IS NO NEED TO PROCESS CHILD NODES!
//
// In general a Builder should be used to transform the node "in place".
//
// A typical usage will have the form:
//
// class MyVisitor : public ResolvedASTRewriteVisitor {
//   absl::StatusOr<std::unique_ptr<const ResolvedNode>>
//   VisitResolvedX(std::unique_ptr<const ResolvedNodeX> node) override {
//     ResolvedXBuilder builder = ToBuilder(std::move(node));
//     // Take ownership of a child ...
//     ResolvedChildBuilder child_a = ToBuilder(builder.release_child_a());
//     // ... modify the child ...
//     child_a.set_x(...);
//     ...
//     // ... put it back.
//     builder.set_child_a(std::move(child_a).Build());
//     ...
//     return std::move(builder).Build();
//   }
// };
//
// Pointer Stability:
//   The rewrite visitor does not change the underlying objects, including
//   the pointers. However, subclasses may not make this guarantee, they
//   may delete or add new nodes etc. So, while pointers may look stable, this
//   should not be relied on.
//
// Differences with ResolvedASTDeepCopyVisitor:
//   The RewriteVisitor is currently not quite as general purpose as
//   DeepCopyVisitor. In particular, there is no way to override or prevent
//   the actual copying of children, this is baked into the interface.
//
class ResolvedASTRewriteVisitor {
 public:
  virtual ~ResolvedASTRewriteVisitor() = default;

  // Invoke the visitor on the given node. This will transform the input
  // node in place. In the case of an error, the state of the input resolved
  // AST is undefined.
  template <typename ExpectedReturnT = ResolvedNode>
  absl::StatusOr<std::unique_ptr<const ExpectedReturnT>> VisitAll(
      std::unique_ptr<const ResolvedNode> node) {
    return Dispatch<ExpectedReturnT>(std::move(node));
  }

 protected:
  virtual absl::Status PreVisitResolvedLiteral(
      const ResolvedLiteral&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedLiteral (
      std::unique_ptr<const ResolvedLiteral> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedParameter(
      const ResolvedParameter&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedParameter (
      std::unique_ptr<const ResolvedParameter> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExpressionColumn(
      const ResolvedExpressionColumn&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExpressionColumn (
      std::unique_ptr<const ResolvedExpressionColumn> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCatalogColumnRef(
      const ResolvedCatalogColumnRef&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCatalogColumnRef (
      std::unique_ptr<const ResolvedCatalogColumnRef> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedColumnRef(
      const ResolvedColumnRef&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedColumnRef (
      std::unique_ptr<const ResolvedColumnRef> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGroupingSetMultiColumn(
      const ResolvedGroupingSetMultiColumn&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGroupingSetMultiColumn (
      std::unique_ptr<const ResolvedGroupingSetMultiColumn> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedConstant(
      const ResolvedConstant&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedConstant (
      std::unique_ptr<const ResolvedConstant> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSystemVariable(
      const ResolvedSystemVariable&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSystemVariable (
      std::unique_ptr<const ResolvedSystemVariable> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedInlineLambda(
      const ResolvedInlineLambda&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedInlineLambda (
      std::unique_ptr<const ResolvedInlineLambda> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSequence(
      const ResolvedSequence&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSequence (
      std::unique_ptr<const ResolvedSequence> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFilterFieldArg(
      const ResolvedFilterFieldArg&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFilterFieldArg (
      std::unique_ptr<const ResolvedFilterFieldArg> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFilterField(
      const ResolvedFilterField&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFilterField (
      std::unique_ptr<const ResolvedFilterField> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFunctionCall(
      const ResolvedFunctionCall&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFunctionCall (
      std::unique_ptr<const ResolvedFunctionCall> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAggregateFunctionCall(
      const ResolvedAggregateFunctionCall&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAggregateFunctionCall (
      std::unique_ptr<const ResolvedAggregateFunctionCall> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAnalyticFunctionCall(
      const ResolvedAnalyticFunctionCall&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAnalyticFunctionCall (
      std::unique_ptr<const ResolvedAnalyticFunctionCall> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExtendedCastElement(
      const ResolvedExtendedCastElement&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExtendedCastElement (
      std::unique_ptr<const ResolvedExtendedCastElement> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExtendedCast(
      const ResolvedExtendedCast&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExtendedCast (
      std::unique_ptr<const ResolvedExtendedCast> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCast(
      const ResolvedCast&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCast (
      std::unique_ptr<const ResolvedCast> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedMakeStruct(
      const ResolvedMakeStruct&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedMakeStruct (
      std::unique_ptr<const ResolvedMakeStruct> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedMakeProto(
      const ResolvedMakeProto&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedMakeProto (
      std::unique_ptr<const ResolvedMakeProto> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedMakeProtoField(
      const ResolvedMakeProtoField&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedMakeProtoField (
      std::unique_ptr<const ResolvedMakeProtoField> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGetStructField(
      const ResolvedGetStructField&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGetStructField (
      std::unique_ptr<const ResolvedGetStructField> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGetProtoField(
      const ResolvedGetProtoField&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGetProtoField (
      std::unique_ptr<const ResolvedGetProtoField> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGetJsonField(
      const ResolvedGetJsonField&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGetJsonField (
      std::unique_ptr<const ResolvedGetJsonField> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFlatten(
      const ResolvedFlatten&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFlatten (
      std::unique_ptr<const ResolvedFlatten> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFlattenedArg(
      const ResolvedFlattenedArg&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFlattenedArg (
      std::unique_ptr<const ResolvedFlattenedArg> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedReplaceFieldItem(
      const ResolvedReplaceFieldItem&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedReplaceFieldItem (
      std::unique_ptr<const ResolvedReplaceFieldItem> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedReplaceField(
      const ResolvedReplaceField&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedReplaceField (
      std::unique_ptr<const ResolvedReplaceField> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSubqueryExpr(
      const ResolvedSubqueryExpr&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSubqueryExpr (
      std::unique_ptr<const ResolvedSubqueryExpr> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWithExpr(
      const ResolvedWithExpr&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWithExpr (
      std::unique_ptr<const ResolvedWithExpr> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExecuteAsRoleScan(
      const ResolvedExecuteAsRoleScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExecuteAsRoleScan (
      std::unique_ptr<const ResolvedExecuteAsRoleScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedModel(
      const ResolvedModel&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedModel (
      std::unique_ptr<const ResolvedModel> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedConnection(
      const ResolvedConnection&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedConnection (
      std::unique_ptr<const ResolvedConnection> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDescriptor(
      const ResolvedDescriptor&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDescriptor (
      std::unique_ptr<const ResolvedDescriptor> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSingleRowScan(
      const ResolvedSingleRowScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSingleRowScan (
      std::unique_ptr<const ResolvedSingleRowScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedTableScan(
      const ResolvedTableScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedTableScan (
      std::unique_ptr<const ResolvedTableScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedJoinScan(
      const ResolvedJoinScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedJoinScan (
      std::unique_ptr<const ResolvedJoinScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedArrayScan(
      const ResolvedArrayScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedArrayScan (
      std::unique_ptr<const ResolvedArrayScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedColumnHolder(
      const ResolvedColumnHolder&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedColumnHolder (
      std::unique_ptr<const ResolvedColumnHolder> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFilterScan(
      const ResolvedFilterScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFilterScan (
      std::unique_ptr<const ResolvedFilterScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGroupingCall(
      const ResolvedGroupingCall&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGroupingCall (
      std::unique_ptr<const ResolvedGroupingCall> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGroupingSet(
      const ResolvedGroupingSet&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGroupingSet (
      std::unique_ptr<const ResolvedGroupingSet> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRollup(
      const ResolvedRollup&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRollup (
      std::unique_ptr<const ResolvedRollup> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCube(
      const ResolvedCube&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCube (
      std::unique_ptr<const ResolvedCube> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAggregateScan(
      const ResolvedAggregateScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAggregateScan (
      std::unique_ptr<const ResolvedAggregateScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAnonymizedAggregateScan(
      const ResolvedAnonymizedAggregateScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAnonymizedAggregateScan (
      std::unique_ptr<const ResolvedAnonymizedAggregateScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDifferentialPrivacyAggregateScan(
      const ResolvedDifferentialPrivacyAggregateScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDifferentialPrivacyAggregateScan (
      std::unique_ptr<const ResolvedDifferentialPrivacyAggregateScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAggregationThresholdAggregateScan(
      const ResolvedAggregationThresholdAggregateScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAggregationThresholdAggregateScan (
      std::unique_ptr<const ResolvedAggregationThresholdAggregateScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSetOperationItem(
      const ResolvedSetOperationItem&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSetOperationItem (
      std::unique_ptr<const ResolvedSetOperationItem> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSetOperationScan(
      const ResolvedSetOperationScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSetOperationScan (
      std::unique_ptr<const ResolvedSetOperationScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedOrderByScan(
      const ResolvedOrderByScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedOrderByScan (
      std::unique_ptr<const ResolvedOrderByScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedLimitOffsetScan(
      const ResolvedLimitOffsetScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedLimitOffsetScan (
      std::unique_ptr<const ResolvedLimitOffsetScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWithRefScan(
      const ResolvedWithRefScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWithRefScan (
      std::unique_ptr<const ResolvedWithRefScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAnalyticScan(
      const ResolvedAnalyticScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAnalyticScan (
      std::unique_ptr<const ResolvedAnalyticScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSampleScan(
      const ResolvedSampleScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSampleScan (
      std::unique_ptr<const ResolvedSampleScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedComputedColumn(
      const ResolvedComputedColumn&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedComputedColumn (
      std::unique_ptr<const ResolvedComputedColumn> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedOrderByItem(
      const ResolvedOrderByItem&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedOrderByItem (
      std::unique_ptr<const ResolvedOrderByItem> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedColumnAnnotations(
      const ResolvedColumnAnnotations&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedColumnAnnotations (
      std::unique_ptr<const ResolvedColumnAnnotations> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGeneratedColumnInfo(
      const ResolvedGeneratedColumnInfo&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGeneratedColumnInfo (
      std::unique_ptr<const ResolvedGeneratedColumnInfo> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedColumnDefaultValue(
      const ResolvedColumnDefaultValue&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedColumnDefaultValue (
      std::unique_ptr<const ResolvedColumnDefaultValue> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedColumnDefinition(
      const ResolvedColumnDefinition&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedColumnDefinition (
      std::unique_ptr<const ResolvedColumnDefinition> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedPrimaryKey(
      const ResolvedPrimaryKey&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedPrimaryKey (
      std::unique_ptr<const ResolvedPrimaryKey> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedForeignKey(
      const ResolvedForeignKey&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedForeignKey (
      std::unique_ptr<const ResolvedForeignKey> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCheckConstraint(
      const ResolvedCheckConstraint&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCheckConstraint (
      std::unique_ptr<const ResolvedCheckConstraint> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedOutputColumn(
      const ResolvedOutputColumn&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedOutputColumn (
      std::unique_ptr<const ResolvedOutputColumn> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedProjectScan(
      const ResolvedProjectScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedProjectScan (
      std::unique_ptr<const ResolvedProjectScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedTVFScan(
      const ResolvedTVFScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedTVFScan (
      std::unique_ptr<const ResolvedTVFScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGroupRowsScan(
      const ResolvedGroupRowsScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGroupRowsScan (
      std::unique_ptr<const ResolvedGroupRowsScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFunctionArgument(
      const ResolvedFunctionArgument&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFunctionArgument (
      std::unique_ptr<const ResolvedFunctionArgument> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExplainStmt(
      const ResolvedExplainStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExplainStmt (
      std::unique_ptr<const ResolvedExplainStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedQueryStmt(
      const ResolvedQueryStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedQueryStmt (
      std::unique_ptr<const ResolvedQueryStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateDatabaseStmt(
      const ResolvedCreateDatabaseStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateDatabaseStmt (
      std::unique_ptr<const ResolvedCreateDatabaseStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedIndexItem(
      const ResolvedIndexItem&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedIndexItem (
      std::unique_ptr<const ResolvedIndexItem> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedUnnestItem(
      const ResolvedUnnestItem&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedUnnestItem (
      std::unique_ptr<const ResolvedUnnestItem> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateIndexStmt(
      const ResolvedCreateIndexStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateIndexStmt (
      std::unique_ptr<const ResolvedCreateIndexStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateSchemaStmt(
      const ResolvedCreateSchemaStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateSchemaStmt (
      std::unique_ptr<const ResolvedCreateSchemaStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateTableStmt(
      const ResolvedCreateTableStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateTableStmt (
      std::unique_ptr<const ResolvedCreateTableStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateTableAsSelectStmt(
      const ResolvedCreateTableAsSelectStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateTableAsSelectStmt (
      std::unique_ptr<const ResolvedCreateTableAsSelectStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateModelAliasedQuery(
      const ResolvedCreateModelAliasedQuery&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateModelAliasedQuery (
      std::unique_ptr<const ResolvedCreateModelAliasedQuery> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateModelStmt(
      const ResolvedCreateModelStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateModelStmt (
      std::unique_ptr<const ResolvedCreateModelStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateViewStmt(
      const ResolvedCreateViewStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateViewStmt (
      std::unique_ptr<const ResolvedCreateViewStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWithPartitionColumns(
      const ResolvedWithPartitionColumns&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWithPartitionColumns (
      std::unique_ptr<const ResolvedWithPartitionColumns> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateSnapshotTableStmt(
      const ResolvedCreateSnapshotTableStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateSnapshotTableStmt (
      std::unique_ptr<const ResolvedCreateSnapshotTableStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateExternalTableStmt(
      const ResolvedCreateExternalTableStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateExternalTableStmt (
      std::unique_ptr<const ResolvedCreateExternalTableStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExportModelStmt(
      const ResolvedExportModelStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExportModelStmt (
      std::unique_ptr<const ResolvedExportModelStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExportDataStmt(
      const ResolvedExportDataStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExportDataStmt (
      std::unique_ptr<const ResolvedExportDataStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExportMetadataStmt(
      const ResolvedExportMetadataStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExportMetadataStmt (
      std::unique_ptr<const ResolvedExportMetadataStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDefineTableStmt(
      const ResolvedDefineTableStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDefineTableStmt (
      std::unique_ptr<const ResolvedDefineTableStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDescribeStmt(
      const ResolvedDescribeStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDescribeStmt (
      std::unique_ptr<const ResolvedDescribeStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedShowStmt(
      const ResolvedShowStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedShowStmt (
      std::unique_ptr<const ResolvedShowStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedBeginStmt(
      const ResolvedBeginStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedBeginStmt (
      std::unique_ptr<const ResolvedBeginStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSetTransactionStmt(
      const ResolvedSetTransactionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSetTransactionStmt (
      std::unique_ptr<const ResolvedSetTransactionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCommitStmt(
      const ResolvedCommitStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCommitStmt (
      std::unique_ptr<const ResolvedCommitStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRollbackStmt(
      const ResolvedRollbackStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRollbackStmt (
      std::unique_ptr<const ResolvedRollbackStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedStartBatchStmt(
      const ResolvedStartBatchStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedStartBatchStmt (
      std::unique_ptr<const ResolvedStartBatchStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRunBatchStmt(
      const ResolvedRunBatchStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRunBatchStmt (
      std::unique_ptr<const ResolvedRunBatchStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAbortBatchStmt(
      const ResolvedAbortBatchStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAbortBatchStmt (
      std::unique_ptr<const ResolvedAbortBatchStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropStmt(
      const ResolvedDropStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropStmt (
      std::unique_ptr<const ResolvedDropStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropMaterializedViewStmt(
      const ResolvedDropMaterializedViewStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropMaterializedViewStmt (
      std::unique_ptr<const ResolvedDropMaterializedViewStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropSnapshotTableStmt(
      const ResolvedDropSnapshotTableStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropSnapshotTableStmt (
      std::unique_ptr<const ResolvedDropSnapshotTableStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRecursiveRefScan(
      const ResolvedRecursiveRefScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRecursiveRefScan (
      std::unique_ptr<const ResolvedRecursiveRefScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRecursiveScan(
      const ResolvedRecursiveScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRecursiveScan (
      std::unique_ptr<const ResolvedRecursiveScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWithScan(
      const ResolvedWithScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWithScan (
      std::unique_ptr<const ResolvedWithScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWithEntry(
      const ResolvedWithEntry&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWithEntry (
      std::unique_ptr<const ResolvedWithEntry> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedOption(
      const ResolvedOption&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedOption (
      std::unique_ptr<const ResolvedOption> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWindowPartitioning(
      const ResolvedWindowPartitioning&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWindowPartitioning (
      std::unique_ptr<const ResolvedWindowPartitioning> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWindowOrdering(
      const ResolvedWindowOrdering&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWindowOrdering (
      std::unique_ptr<const ResolvedWindowOrdering> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWindowFrame(
      const ResolvedWindowFrame&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWindowFrame (
      std::unique_ptr<const ResolvedWindowFrame> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAnalyticFunctionGroup(
      const ResolvedAnalyticFunctionGroup&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAnalyticFunctionGroup (
      std::unique_ptr<const ResolvedAnalyticFunctionGroup> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedWindowFrameExpr(
      const ResolvedWindowFrameExpr&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedWindowFrameExpr (
      std::unique_ptr<const ResolvedWindowFrameExpr> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDMLValue(
      const ResolvedDMLValue&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDMLValue (
      std::unique_ptr<const ResolvedDMLValue> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDMLDefault(
      const ResolvedDMLDefault&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDMLDefault (
      std::unique_ptr<const ResolvedDMLDefault> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAssertStmt(
      const ResolvedAssertStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAssertStmt (
      std::unique_ptr<const ResolvedAssertStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAssertRowsModified(
      const ResolvedAssertRowsModified&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAssertRowsModified (
      std::unique_ptr<const ResolvedAssertRowsModified> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedInsertRow(
      const ResolvedInsertRow&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedInsertRow (
      std::unique_ptr<const ResolvedInsertRow> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedInsertStmt(
      const ResolvedInsertStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedInsertStmt (
      std::unique_ptr<const ResolvedInsertStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDeleteStmt(
      const ResolvedDeleteStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDeleteStmt (
      std::unique_ptr<const ResolvedDeleteStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedUpdateItem(
      const ResolvedUpdateItem&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedUpdateItem (
      std::unique_ptr<const ResolvedUpdateItem> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedUpdateArrayItem(
      const ResolvedUpdateArrayItem&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedUpdateArrayItem (
      std::unique_ptr<const ResolvedUpdateArrayItem> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedUpdateStmt(
      const ResolvedUpdateStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedUpdateStmt (
      std::unique_ptr<const ResolvedUpdateStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedMergeWhen(
      const ResolvedMergeWhen&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedMergeWhen (
      std::unique_ptr<const ResolvedMergeWhen> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedMergeStmt(
      const ResolvedMergeStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedMergeStmt (
      std::unique_ptr<const ResolvedMergeStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedTruncateStmt(
      const ResolvedTruncateStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedTruncateStmt (
      std::unique_ptr<const ResolvedTruncateStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedObjectUnit(
      const ResolvedObjectUnit&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedObjectUnit (
      std::unique_ptr<const ResolvedObjectUnit> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedPrivilege(
      const ResolvedPrivilege&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedPrivilege (
      std::unique_ptr<const ResolvedPrivilege> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGrantStmt(
      const ResolvedGrantStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGrantStmt (
      std::unique_ptr<const ResolvedGrantStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRevokeStmt(
      const ResolvedRevokeStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRevokeStmt (
      std::unique_ptr<const ResolvedRevokeStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterDatabaseStmt(
      const ResolvedAlterDatabaseStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterDatabaseStmt (
      std::unique_ptr<const ResolvedAlterDatabaseStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterMaterializedViewStmt(
      const ResolvedAlterMaterializedViewStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterMaterializedViewStmt (
      std::unique_ptr<const ResolvedAlterMaterializedViewStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterApproxViewStmt(
      const ResolvedAlterApproxViewStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterApproxViewStmt (
      std::unique_ptr<const ResolvedAlterApproxViewStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterSchemaStmt(
      const ResolvedAlterSchemaStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterSchemaStmt (
      std::unique_ptr<const ResolvedAlterSchemaStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterModelStmt(
      const ResolvedAlterModelStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterModelStmt (
      std::unique_ptr<const ResolvedAlterModelStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterTableStmt(
      const ResolvedAlterTableStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterTableStmt (
      std::unique_ptr<const ResolvedAlterTableStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterViewStmt(
      const ResolvedAlterViewStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterViewStmt (
      std::unique_ptr<const ResolvedAlterViewStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSetOptionsAction(
      const ResolvedSetOptionsAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSetOptionsAction (
      std::unique_ptr<const ResolvedSetOptionsAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterSubEntityAction(
      const ResolvedAlterSubEntityAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterSubEntityAction (
      std::unique_ptr<const ResolvedAlterSubEntityAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAddSubEntityAction(
      const ResolvedAddSubEntityAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAddSubEntityAction (
      std::unique_ptr<const ResolvedAddSubEntityAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropSubEntityAction(
      const ResolvedDropSubEntityAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropSubEntityAction (
      std::unique_ptr<const ResolvedDropSubEntityAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAddColumnAction(
      const ResolvedAddColumnAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAddColumnAction (
      std::unique_ptr<const ResolvedAddColumnAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAddConstraintAction(
      const ResolvedAddConstraintAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAddConstraintAction (
      std::unique_ptr<const ResolvedAddConstraintAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropConstraintAction(
      const ResolvedDropConstraintAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropConstraintAction (
      std::unique_ptr<const ResolvedDropConstraintAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropPrimaryKeyAction(
      const ResolvedDropPrimaryKeyAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropPrimaryKeyAction (
      std::unique_ptr<const ResolvedDropPrimaryKeyAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterColumnOptionsAction(
      const ResolvedAlterColumnOptionsAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterColumnOptionsAction (
      std::unique_ptr<const ResolvedAlterColumnOptionsAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterColumnDropNotNullAction(
      const ResolvedAlterColumnDropNotNullAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterColumnDropNotNullAction (
      std::unique_ptr<const ResolvedAlterColumnDropNotNullAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterColumnSetDataTypeAction(
      const ResolvedAlterColumnSetDataTypeAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterColumnSetDataTypeAction (
      std::unique_ptr<const ResolvedAlterColumnSetDataTypeAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterColumnSetDefaultAction(
      const ResolvedAlterColumnSetDefaultAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterColumnSetDefaultAction (
      std::unique_ptr<const ResolvedAlterColumnSetDefaultAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterColumnDropDefaultAction(
      const ResolvedAlterColumnDropDefaultAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterColumnDropDefaultAction (
      std::unique_ptr<const ResolvedAlterColumnDropDefaultAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropColumnAction(
      const ResolvedDropColumnAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropColumnAction (
      std::unique_ptr<const ResolvedDropColumnAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRenameColumnAction(
      const ResolvedRenameColumnAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRenameColumnAction (
      std::unique_ptr<const ResolvedRenameColumnAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSetAsAction(
      const ResolvedSetAsAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSetAsAction (
      std::unique_ptr<const ResolvedSetAsAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedSetCollateClause(
      const ResolvedSetCollateClause&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedSetCollateClause (
      std::unique_ptr<const ResolvedSetCollateClause> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterTableSetOptionsStmt(
      const ResolvedAlterTableSetOptionsStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterTableSetOptionsStmt (
      std::unique_ptr<const ResolvedAlterTableSetOptionsStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRenameStmt(
      const ResolvedRenameStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRenameStmt (
      std::unique_ptr<const ResolvedRenameStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreatePrivilegeRestrictionStmt(
      const ResolvedCreatePrivilegeRestrictionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreatePrivilegeRestrictionStmt (
      std::unique_ptr<const ResolvedCreatePrivilegeRestrictionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateRowAccessPolicyStmt(
      const ResolvedCreateRowAccessPolicyStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateRowAccessPolicyStmt (
      std::unique_ptr<const ResolvedCreateRowAccessPolicyStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropPrivilegeRestrictionStmt(
      const ResolvedDropPrivilegeRestrictionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropPrivilegeRestrictionStmt (
      std::unique_ptr<const ResolvedDropPrivilegeRestrictionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropRowAccessPolicyStmt(
      const ResolvedDropRowAccessPolicyStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropRowAccessPolicyStmt (
      std::unique_ptr<const ResolvedDropRowAccessPolicyStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropIndexStmt(
      const ResolvedDropIndexStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropIndexStmt (
      std::unique_ptr<const ResolvedDropIndexStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedGrantToAction(
      const ResolvedGrantToAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedGrantToAction (
      std::unique_ptr<const ResolvedGrantToAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRestrictToAction(
      const ResolvedRestrictToAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRestrictToAction (
      std::unique_ptr<const ResolvedRestrictToAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAddToRestricteeListAction(
      const ResolvedAddToRestricteeListAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAddToRestricteeListAction (
      std::unique_ptr<const ResolvedAddToRestricteeListAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRemoveFromRestricteeListAction(
      const ResolvedRemoveFromRestricteeListAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRemoveFromRestricteeListAction (
      std::unique_ptr<const ResolvedRemoveFromRestricteeListAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFilterUsingAction(
      const ResolvedFilterUsingAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFilterUsingAction (
      std::unique_ptr<const ResolvedFilterUsingAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRevokeFromAction(
      const ResolvedRevokeFromAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRevokeFromAction (
      std::unique_ptr<const ResolvedRevokeFromAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRenameToAction(
      const ResolvedRenameToAction&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRenameToAction (
      std::unique_ptr<const ResolvedRenameToAction> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterPrivilegeRestrictionStmt(
      const ResolvedAlterPrivilegeRestrictionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterPrivilegeRestrictionStmt (
      std::unique_ptr<const ResolvedAlterPrivilegeRestrictionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterRowAccessPolicyStmt(
      const ResolvedAlterRowAccessPolicyStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterRowAccessPolicyStmt (
      std::unique_ptr<const ResolvedAlterRowAccessPolicyStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterAllRowAccessPoliciesStmt(
      const ResolvedAlterAllRowAccessPoliciesStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterAllRowAccessPoliciesStmt (
      std::unique_ptr<const ResolvedAlterAllRowAccessPoliciesStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateConstantStmt(
      const ResolvedCreateConstantStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateConstantStmt (
      std::unique_ptr<const ResolvedCreateConstantStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateFunctionStmt(
      const ResolvedCreateFunctionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateFunctionStmt (
      std::unique_ptr<const ResolvedCreateFunctionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedArgumentDef(
      const ResolvedArgumentDef&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedArgumentDef (
      std::unique_ptr<const ResolvedArgumentDef> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedArgumentRef(
      const ResolvedArgumentRef&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedArgumentRef (
      std::unique_ptr<const ResolvedArgumentRef> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateTableFunctionStmt(
      const ResolvedCreateTableFunctionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateTableFunctionStmt (
      std::unique_ptr<const ResolvedCreateTableFunctionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedRelationArgumentScan(
      const ResolvedRelationArgumentScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedRelationArgumentScan (
      std::unique_ptr<const ResolvedRelationArgumentScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedArgumentList(
      const ResolvedArgumentList&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedArgumentList (
      std::unique_ptr<const ResolvedArgumentList> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedFunctionSignatureHolder(
      const ResolvedFunctionSignatureHolder&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedFunctionSignatureHolder (
      std::unique_ptr<const ResolvedFunctionSignatureHolder> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropFunctionStmt(
      const ResolvedDropFunctionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropFunctionStmt (
      std::unique_ptr<const ResolvedDropFunctionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedDropTableFunctionStmt(
      const ResolvedDropTableFunctionStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedDropTableFunctionStmt (
      std::unique_ptr<const ResolvedDropTableFunctionStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCallStmt(
      const ResolvedCallStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCallStmt (
      std::unique_ptr<const ResolvedCallStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedImportStmt(
      const ResolvedImportStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedImportStmt (
      std::unique_ptr<const ResolvedImportStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedModuleStmt(
      const ResolvedModuleStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedModuleStmt (
      std::unique_ptr<const ResolvedModuleStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAggregateHavingModifier(
      const ResolvedAggregateHavingModifier&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAggregateHavingModifier (
      std::unique_ptr<const ResolvedAggregateHavingModifier> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateMaterializedViewStmt(
      const ResolvedCreateMaterializedViewStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateMaterializedViewStmt (
      std::unique_ptr<const ResolvedCreateMaterializedViewStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateApproxViewStmt(
      const ResolvedCreateApproxViewStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateApproxViewStmt (
      std::unique_ptr<const ResolvedCreateApproxViewStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateProcedureStmt(
      const ResolvedCreateProcedureStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateProcedureStmt (
      std::unique_ptr<const ResolvedCreateProcedureStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExecuteImmediateArgument(
      const ResolvedExecuteImmediateArgument&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExecuteImmediateArgument (
      std::unique_ptr<const ResolvedExecuteImmediateArgument> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedExecuteImmediateStmt(
      const ResolvedExecuteImmediateStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedExecuteImmediateStmt (
      std::unique_ptr<const ResolvedExecuteImmediateStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAssignmentStmt(
      const ResolvedAssignmentStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAssignmentStmt (
      std::unique_ptr<const ResolvedAssignmentStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCreateEntityStmt(
      const ResolvedCreateEntityStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCreateEntityStmt (
      std::unique_ptr<const ResolvedCreateEntityStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAlterEntityStmt(
      const ResolvedAlterEntityStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAlterEntityStmt (
      std::unique_ptr<const ResolvedAlterEntityStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedPivotColumn(
      const ResolvedPivotColumn&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedPivotColumn (
      std::unique_ptr<const ResolvedPivotColumn> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedPivotScan(
      const ResolvedPivotScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedPivotScan (
      std::unique_ptr<const ResolvedPivotScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedReturningClause(
      const ResolvedReturningClause&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedReturningClause (
      std::unique_ptr<const ResolvedReturningClause> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedUnpivotArg(
      const ResolvedUnpivotArg&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedUnpivotArg (
      std::unique_ptr<const ResolvedUnpivotArg> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedUnpivotScan(
      const ResolvedUnpivotScan&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedUnpivotScan (
      std::unique_ptr<const ResolvedUnpivotScan> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedCloneDataStmt(
      const ResolvedCloneDataStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedCloneDataStmt (
      std::unique_ptr<const ResolvedCloneDataStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedTableAndColumnInfo(
      const ResolvedTableAndColumnInfo&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedTableAndColumnInfo (
      std::unique_ptr<const ResolvedTableAndColumnInfo> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAnalyzeStmt(
      const ResolvedAnalyzeStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAnalyzeStmt (
      std::unique_ptr<const ResolvedAnalyzeStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAuxLoadDataPartitionFilter(
      const ResolvedAuxLoadDataPartitionFilter&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAuxLoadDataPartitionFilter (
      std::unique_ptr<const ResolvedAuxLoadDataPartitionFilter> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedAuxLoadDataStmt(
      const ResolvedAuxLoadDataStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedAuxLoadDataStmt (
      std::unique_ptr<const ResolvedAuxLoadDataStmt> node) {
    return node;
  }

  virtual absl::Status PreVisitResolvedUndropStmt(
      const ResolvedUndropStmt&) {
    return absl::OkStatus();
  }

  virtual absl::StatusOr<std::unique_ptr<const ResolvedNode>>
  PostVisitResolvedUndropStmt (
      std::unique_ptr<const ResolvedUndropStmt> node) {
    return node;
  }

 private:
  template <typename ExpectedReturnT>
  static absl::StatusOr<std::unique_ptr<const ExpectedReturnT>> VerifyType(
    absl::StatusOr<std::unique_ptr<const ResolvedNode>> input) {
      if constexpr (std::is_same<ExpectedReturnT, ResolvedNode>()) {
        return input;
      } else {
        if (!input.ok()) {
          return std::move(input).status();
        }
        const ResolvedNode* input_node = (*input).get();
        ZETASQL_RET_CHECK(input_node != nullptr);
        ZETASQL_RET_CHECK(input_node->template Is<ExpectedReturnT>());
        return absl::WrapUnique<const ExpectedReturnT>(
            (*std::move(input)).release()->template GetAs<ExpectedReturnT>());
      }
    }

  // Helper function to dispatch a vector of nodes.
  template<typename ResolvedNodeT>
  absl::StatusOr<std::vector<std::unique_ptr<const ResolvedNodeT>>>
  DispatchNodeList(std::vector<std::unique_ptr<const ResolvedNodeT>> nodes);

  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedLiteral> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedParameter> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExpressionColumn> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCatalogColumnRef> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedColumnRef> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGroupingSetMultiColumn> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedConstant> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSystemVariable> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedInlineLambda> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSequence> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFilterFieldArg> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFilterField> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFunctionCall> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAggregateFunctionCall> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAnalyticFunctionCall> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExtendedCastElement> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExtendedCast> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCast> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedMakeStruct> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedMakeProto> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedMakeProtoField> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGetStructField> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGetProtoField> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGetJsonField> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFlatten> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFlattenedArg> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedReplaceFieldItem> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedReplaceField> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSubqueryExpr> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWithExpr> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExecuteAsRoleScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedModel> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedConnection> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDescriptor> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSingleRowScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedTableScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedJoinScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedArrayScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedColumnHolder> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFilterScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGroupingCall> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGroupingSet> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRollup> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCube> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAggregateScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAnonymizedAggregateScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDifferentialPrivacyAggregateScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAggregationThresholdAggregateScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSetOperationItem> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSetOperationScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedOrderByScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedLimitOffsetScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWithRefScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAnalyticScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSampleScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedComputedColumn> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedOrderByItem> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedColumnAnnotations> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGeneratedColumnInfo> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedColumnDefaultValue> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedColumnDefinition> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedPrimaryKey> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedForeignKey> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCheckConstraint> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedOutputColumn> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedProjectScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedTVFScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGroupRowsScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFunctionArgument> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExplainStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedQueryStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateDatabaseStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedIndexItem> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedUnnestItem> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateIndexStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateSchemaStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateTableStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateTableAsSelectStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateModelAliasedQuery> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateModelStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateViewStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWithPartitionColumns> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateSnapshotTableStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateExternalTableStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExportModelStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExportDataStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExportMetadataStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDefineTableStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDescribeStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedShowStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedBeginStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSetTransactionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCommitStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRollbackStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedStartBatchStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRunBatchStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAbortBatchStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropMaterializedViewStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropSnapshotTableStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRecursiveRefScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRecursiveScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWithScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWithEntry> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedOption> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWindowPartitioning> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWindowOrdering> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWindowFrame> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAnalyticFunctionGroup> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedWindowFrameExpr> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDMLValue> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDMLDefault> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAssertStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAssertRowsModified> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedInsertRow> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedInsertStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDeleteStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedUpdateItem> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedUpdateArrayItem> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedUpdateStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedMergeWhen> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedMergeStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedTruncateStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedObjectUnit> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedPrivilege> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGrantStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRevokeStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterDatabaseStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterMaterializedViewStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterApproxViewStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterSchemaStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterModelStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterTableStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterViewStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSetOptionsAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterSubEntityAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAddSubEntityAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropSubEntityAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAddColumnAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAddConstraintAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropConstraintAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropPrimaryKeyAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterColumnOptionsAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterColumnDropNotNullAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterColumnSetDataTypeAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterColumnSetDefaultAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterColumnDropDefaultAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropColumnAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRenameColumnAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSetAsAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedSetCollateClause> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterTableSetOptionsStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRenameStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreatePrivilegeRestrictionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateRowAccessPolicyStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropPrivilegeRestrictionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropRowAccessPolicyStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropIndexStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedGrantToAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRestrictToAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAddToRestricteeListAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRemoveFromRestricteeListAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFilterUsingAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRevokeFromAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRenameToAction> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterPrivilegeRestrictionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterRowAccessPolicyStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterAllRowAccessPoliciesStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateConstantStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateFunctionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedArgumentDef> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedArgumentRef> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateTableFunctionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedRelationArgumentScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedArgumentList> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedFunctionSignatureHolder> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropFunctionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedDropTableFunctionStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCallStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedImportStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedModuleStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAggregateHavingModifier> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateMaterializedViewStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateApproxViewStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateProcedureStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExecuteImmediateArgument> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedExecuteImmediateStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAssignmentStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCreateEntityStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAlterEntityStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedPivotColumn> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedPivotScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedReturningClause> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedUnpivotArg> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedUnpivotScan> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedCloneDataStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedTableAndColumnInfo> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAnalyzeStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAuxLoadDataPartitionFilter> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedAuxLoadDataStmt> node);
  absl::StatusOr<std::unique_ptr<const ResolvedNode>> DefaultVisit(
      std::unique_ptr<const ResolvedUndropStmt> node);
  template <typename TypeName>
  std::unique_ptr<const TypeName> CastUniquePtr(std::unique_ptr<const ResolvedNode> node) {
    return absl::WrapUnique(static_cast<const TypeName*>(node.release()));
  }

  template <typename ExpectedReturnT>
  absl::StatusOr<std::unique_ptr<const ExpectedReturnT>> Dispatch(
      std::unique_ptr<const ResolvedNode> node) {
    ZETASQL_RETURN_IF_NOT_ENOUGH_STACK("Resolved AST nested too deeply.");
    ZETASQL_RET_CHECK(node != nullptr);
    absl::StatusOr<std::unique_ptr<const ResolvedNode>> visited_node;
    switch(node->node_kind()) {
      case ResolvedLiteral::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedLiteral>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedLiteral>(std::move(node)));
        }
        break;
      }
      case ResolvedParameter::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedParameter>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedParameter>(std::move(node)));
        }
        break;
      }
      case ResolvedExpressionColumn::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExpressionColumn>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExpressionColumn>(std::move(node)));
        }
        break;
      }
      case ResolvedCatalogColumnRef::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCatalogColumnRef>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCatalogColumnRef>(std::move(node)));
        }
        break;
      }
      case ResolvedColumnRef::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedColumnRef>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedColumnRef>(std::move(node)));
        }
        break;
      }
      case ResolvedGroupingSetMultiColumn::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGroupingSetMultiColumn>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGroupingSetMultiColumn>(std::move(node)));
        }
        break;
      }
      case ResolvedConstant::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedConstant>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedConstant>(std::move(node)));
        }
        break;
      }
      case ResolvedSystemVariable::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSystemVariable>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSystemVariable>(std::move(node)));
        }
        break;
      }
      case ResolvedInlineLambda::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedInlineLambda>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedInlineLambda>(std::move(node)));
        }
        break;
      }
      case ResolvedSequence::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSequence>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSequence>(std::move(node)));
        }
        break;
      }
      case ResolvedFilterFieldArg::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFilterFieldArg>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFilterFieldArg>(std::move(node)));
        }
        break;
      }
      case ResolvedFilterField::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFilterField>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFilterField>(std::move(node)));
        }
        break;
      }
      case ResolvedFunctionCall::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFunctionCall>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFunctionCall>(std::move(node)));
        }
        break;
      }
      case ResolvedAggregateFunctionCall::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAggregateFunctionCall>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAggregateFunctionCall>(std::move(node)));
        }
        break;
      }
      case ResolvedAnalyticFunctionCall::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAnalyticFunctionCall>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAnalyticFunctionCall>(std::move(node)));
        }
        break;
      }
      case ResolvedExtendedCastElement::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExtendedCastElement>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExtendedCastElement>(std::move(node)));
        }
        break;
      }
      case ResolvedExtendedCast::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExtendedCast>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExtendedCast>(std::move(node)));
        }
        break;
      }
      case ResolvedCast::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCast>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCast>(std::move(node)));
        }
        break;
      }
      case ResolvedMakeStruct::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedMakeStruct>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedMakeStruct>(std::move(node)));
        }
        break;
      }
      case ResolvedMakeProto::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedMakeProto>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedMakeProto>(std::move(node)));
        }
        break;
      }
      case ResolvedMakeProtoField::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedMakeProtoField>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedMakeProtoField>(std::move(node)));
        }
        break;
      }
      case ResolvedGetStructField::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGetStructField>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGetStructField>(std::move(node)));
        }
        break;
      }
      case ResolvedGetProtoField::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGetProtoField>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGetProtoField>(std::move(node)));
        }
        break;
      }
      case ResolvedGetJsonField::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGetJsonField>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGetJsonField>(std::move(node)));
        }
        break;
      }
      case ResolvedFlatten::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFlatten>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFlatten>(std::move(node)));
        }
        break;
      }
      case ResolvedFlattenedArg::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFlattenedArg>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFlattenedArg>(std::move(node)));
        }
        break;
      }
      case ResolvedReplaceFieldItem::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedReplaceFieldItem>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedReplaceFieldItem>(std::move(node)));
        }
        break;
      }
      case ResolvedReplaceField::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedReplaceField>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedReplaceField>(std::move(node)));
        }
        break;
      }
      case ResolvedSubqueryExpr::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSubqueryExpr>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSubqueryExpr>(std::move(node)));
        }
        break;
      }
      case ResolvedWithExpr::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWithExpr>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWithExpr>(std::move(node)));
        }
        break;
      }
      case ResolvedExecuteAsRoleScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExecuteAsRoleScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExecuteAsRoleScan>(std::move(node)));
        }
        break;
      }
      case ResolvedModel::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedModel>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedModel>(std::move(node)));
        }
        break;
      }
      case ResolvedConnection::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedConnection>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedConnection>(std::move(node)));
        }
        break;
      }
      case ResolvedDescriptor::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDescriptor>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDescriptor>(std::move(node)));
        }
        break;
      }
      case ResolvedSingleRowScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSingleRowScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSingleRowScan>(std::move(node)));
        }
        break;
      }
      case ResolvedTableScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedTableScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedTableScan>(std::move(node)));
        }
        break;
      }
      case ResolvedJoinScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedJoinScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedJoinScan>(std::move(node)));
        }
        break;
      }
      case ResolvedArrayScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedArrayScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedArrayScan>(std::move(node)));
        }
        break;
      }
      case ResolvedColumnHolder::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedColumnHolder>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedColumnHolder>(std::move(node)));
        }
        break;
      }
      case ResolvedFilterScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFilterScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFilterScan>(std::move(node)));
        }
        break;
      }
      case ResolvedGroupingCall::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGroupingCall>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGroupingCall>(std::move(node)));
        }
        break;
      }
      case ResolvedGroupingSet::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGroupingSet>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGroupingSet>(std::move(node)));
        }
        break;
      }
      case ResolvedRollup::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRollup>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRollup>(std::move(node)));
        }
        break;
      }
      case ResolvedCube::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCube>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCube>(std::move(node)));
        }
        break;
      }
      case ResolvedAggregateScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAggregateScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAggregateScan>(std::move(node)));
        }
        break;
      }
      case ResolvedAnonymizedAggregateScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAnonymizedAggregateScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAnonymizedAggregateScan>(std::move(node)));
        }
        break;
      }
      case ResolvedDifferentialPrivacyAggregateScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDifferentialPrivacyAggregateScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDifferentialPrivacyAggregateScan>(std::move(node)));
        }
        break;
      }
      case ResolvedAggregationThresholdAggregateScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAggregationThresholdAggregateScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAggregationThresholdAggregateScan>(std::move(node)));
        }
        break;
      }
      case ResolvedSetOperationItem::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSetOperationItem>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSetOperationItem>(std::move(node)));
        }
        break;
      }
      case ResolvedSetOperationScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSetOperationScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSetOperationScan>(std::move(node)));
        }
        break;
      }
      case ResolvedOrderByScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedOrderByScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedOrderByScan>(std::move(node)));
        }
        break;
      }
      case ResolvedLimitOffsetScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedLimitOffsetScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedLimitOffsetScan>(std::move(node)));
        }
        break;
      }
      case ResolvedWithRefScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWithRefScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWithRefScan>(std::move(node)));
        }
        break;
      }
      case ResolvedAnalyticScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAnalyticScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAnalyticScan>(std::move(node)));
        }
        break;
      }
      case ResolvedSampleScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSampleScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSampleScan>(std::move(node)));
        }
        break;
      }
      case ResolvedComputedColumn::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedComputedColumn>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedComputedColumn>(std::move(node)));
        }
        break;
      }
      case ResolvedOrderByItem::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedOrderByItem>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedOrderByItem>(std::move(node)));
        }
        break;
      }
      case ResolvedColumnAnnotations::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedColumnAnnotations>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedColumnAnnotations>(std::move(node)));
        }
        break;
      }
      case ResolvedGeneratedColumnInfo::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGeneratedColumnInfo>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGeneratedColumnInfo>(std::move(node)));
        }
        break;
      }
      case ResolvedColumnDefaultValue::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedColumnDefaultValue>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedColumnDefaultValue>(std::move(node)));
        }
        break;
      }
      case ResolvedColumnDefinition::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedColumnDefinition>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedColumnDefinition>(std::move(node)));
        }
        break;
      }
      case ResolvedPrimaryKey::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedPrimaryKey>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedPrimaryKey>(std::move(node)));
        }
        break;
      }
      case ResolvedForeignKey::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedForeignKey>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedForeignKey>(std::move(node)));
        }
        break;
      }
      case ResolvedCheckConstraint::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCheckConstraint>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCheckConstraint>(std::move(node)));
        }
        break;
      }
      case ResolvedOutputColumn::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedOutputColumn>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedOutputColumn>(std::move(node)));
        }
        break;
      }
      case ResolvedProjectScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedProjectScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedProjectScan>(std::move(node)));
        }
        break;
      }
      case ResolvedTVFScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedTVFScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedTVFScan>(std::move(node)));
        }
        break;
      }
      case ResolvedGroupRowsScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGroupRowsScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGroupRowsScan>(std::move(node)));
        }
        break;
      }
      case ResolvedFunctionArgument::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFunctionArgument>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFunctionArgument>(std::move(node)));
        }
        break;
      }
      case ResolvedExplainStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExplainStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExplainStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedQueryStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedQueryStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedQueryStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateDatabaseStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateDatabaseStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateDatabaseStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedIndexItem::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedIndexItem>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedIndexItem>(std::move(node)));
        }
        break;
      }
      case ResolvedUnnestItem::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedUnnestItem>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedUnnestItem>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateIndexStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateIndexStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateIndexStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateSchemaStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateSchemaStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateSchemaStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateTableStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateTableStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateTableStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateTableAsSelectStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateTableAsSelectStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateTableAsSelectStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateModelAliasedQuery::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateModelAliasedQuery>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateModelAliasedQuery>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateModelStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateModelStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateModelStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateViewStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateViewStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateViewStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedWithPartitionColumns::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWithPartitionColumns>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWithPartitionColumns>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateSnapshotTableStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateSnapshotTableStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateSnapshotTableStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateExternalTableStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateExternalTableStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateExternalTableStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedExportModelStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExportModelStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExportModelStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedExportDataStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExportDataStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExportDataStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedExportMetadataStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExportMetadataStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExportMetadataStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDefineTableStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDefineTableStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDefineTableStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDescribeStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDescribeStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDescribeStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedShowStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedShowStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedShowStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedBeginStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedBeginStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedBeginStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedSetTransactionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSetTransactionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSetTransactionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCommitStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCommitStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCommitStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedRollbackStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRollbackStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRollbackStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedStartBatchStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedStartBatchStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedStartBatchStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedRunBatchStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRunBatchStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRunBatchStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAbortBatchStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAbortBatchStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAbortBatchStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDropStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDropMaterializedViewStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropMaterializedViewStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropMaterializedViewStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDropSnapshotTableStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropSnapshotTableStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropSnapshotTableStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedRecursiveRefScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRecursiveRefScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRecursiveRefScan>(std::move(node)));
        }
        break;
      }
      case ResolvedRecursiveScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRecursiveScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRecursiveScan>(std::move(node)));
        }
        break;
      }
      case ResolvedWithScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWithScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWithScan>(std::move(node)));
        }
        break;
      }
      case ResolvedWithEntry::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWithEntry>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWithEntry>(std::move(node)));
        }
        break;
      }
      case ResolvedOption::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedOption>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedOption>(std::move(node)));
        }
        break;
      }
      case ResolvedWindowPartitioning::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWindowPartitioning>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWindowPartitioning>(std::move(node)));
        }
        break;
      }
      case ResolvedWindowOrdering::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWindowOrdering>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWindowOrdering>(std::move(node)));
        }
        break;
      }
      case ResolvedWindowFrame::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWindowFrame>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWindowFrame>(std::move(node)));
        }
        break;
      }
      case ResolvedAnalyticFunctionGroup::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAnalyticFunctionGroup>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAnalyticFunctionGroup>(std::move(node)));
        }
        break;
      }
      case ResolvedWindowFrameExpr::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedWindowFrameExpr>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedWindowFrameExpr>(std::move(node)));
        }
        break;
      }
      case ResolvedDMLValue::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDMLValue>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDMLValue>(std::move(node)));
        }
        break;
      }
      case ResolvedDMLDefault::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDMLDefault>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDMLDefault>(std::move(node)));
        }
        break;
      }
      case ResolvedAssertStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAssertStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAssertStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAssertRowsModified::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAssertRowsModified>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAssertRowsModified>(std::move(node)));
        }
        break;
      }
      case ResolvedInsertRow::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedInsertRow>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedInsertRow>(std::move(node)));
        }
        break;
      }
      case ResolvedInsertStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedInsertStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedInsertStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDeleteStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDeleteStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDeleteStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedUpdateItem::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedUpdateItem>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedUpdateItem>(std::move(node)));
        }
        break;
      }
      case ResolvedUpdateArrayItem::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedUpdateArrayItem>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedUpdateArrayItem>(std::move(node)));
        }
        break;
      }
      case ResolvedUpdateStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedUpdateStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedUpdateStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedMergeWhen::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedMergeWhen>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedMergeWhen>(std::move(node)));
        }
        break;
      }
      case ResolvedMergeStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedMergeStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedMergeStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedTruncateStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedTruncateStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedTruncateStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedObjectUnit::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedObjectUnit>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedObjectUnit>(std::move(node)));
        }
        break;
      }
      case ResolvedPrivilege::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedPrivilege>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedPrivilege>(std::move(node)));
        }
        break;
      }
      case ResolvedGrantStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGrantStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGrantStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedRevokeStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRevokeStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRevokeStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterDatabaseStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterDatabaseStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterDatabaseStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterMaterializedViewStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterMaterializedViewStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterMaterializedViewStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterApproxViewStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterApproxViewStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterApproxViewStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterSchemaStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterSchemaStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterSchemaStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterModelStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterModelStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterModelStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterTableStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterTableStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterTableStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterViewStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterViewStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterViewStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedSetOptionsAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSetOptionsAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSetOptionsAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterSubEntityAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterSubEntityAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterSubEntityAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAddSubEntityAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAddSubEntityAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAddSubEntityAction>(std::move(node)));
        }
        break;
      }
      case ResolvedDropSubEntityAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropSubEntityAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropSubEntityAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAddColumnAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAddColumnAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAddColumnAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAddConstraintAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAddConstraintAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAddConstraintAction>(std::move(node)));
        }
        break;
      }
      case ResolvedDropConstraintAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropConstraintAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropConstraintAction>(std::move(node)));
        }
        break;
      }
      case ResolvedDropPrimaryKeyAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropPrimaryKeyAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropPrimaryKeyAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterColumnOptionsAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterColumnOptionsAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterColumnOptionsAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterColumnDropNotNullAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterColumnDropNotNullAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterColumnDropNotNullAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterColumnSetDataTypeAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterColumnSetDataTypeAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterColumnSetDataTypeAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterColumnSetDefaultAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterColumnSetDefaultAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterColumnSetDefaultAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterColumnDropDefaultAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterColumnDropDefaultAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterColumnDropDefaultAction>(std::move(node)));
        }
        break;
      }
      case ResolvedDropColumnAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropColumnAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropColumnAction>(std::move(node)));
        }
        break;
      }
      case ResolvedRenameColumnAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRenameColumnAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRenameColumnAction>(std::move(node)));
        }
        break;
      }
      case ResolvedSetAsAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSetAsAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSetAsAction>(std::move(node)));
        }
        break;
      }
      case ResolvedSetCollateClause::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedSetCollateClause>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedSetCollateClause>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterTableSetOptionsStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterTableSetOptionsStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterTableSetOptionsStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedRenameStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRenameStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRenameStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreatePrivilegeRestrictionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreatePrivilegeRestrictionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreatePrivilegeRestrictionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateRowAccessPolicyStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateRowAccessPolicyStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateRowAccessPolicyStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDropPrivilegeRestrictionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropPrivilegeRestrictionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropPrivilegeRestrictionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDropRowAccessPolicyStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropRowAccessPolicyStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropRowAccessPolicyStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDropIndexStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropIndexStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropIndexStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedGrantToAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedGrantToAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedGrantToAction>(std::move(node)));
        }
        break;
      }
      case ResolvedRestrictToAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRestrictToAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRestrictToAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAddToRestricteeListAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAddToRestricteeListAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAddToRestricteeListAction>(std::move(node)));
        }
        break;
      }
      case ResolvedRemoveFromRestricteeListAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRemoveFromRestricteeListAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRemoveFromRestricteeListAction>(std::move(node)));
        }
        break;
      }
      case ResolvedFilterUsingAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFilterUsingAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFilterUsingAction>(std::move(node)));
        }
        break;
      }
      case ResolvedRevokeFromAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRevokeFromAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRevokeFromAction>(std::move(node)));
        }
        break;
      }
      case ResolvedRenameToAction::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRenameToAction>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRenameToAction>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterPrivilegeRestrictionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterPrivilegeRestrictionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterPrivilegeRestrictionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterRowAccessPolicyStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterRowAccessPolicyStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterRowAccessPolicyStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterAllRowAccessPoliciesStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterAllRowAccessPoliciesStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterAllRowAccessPoliciesStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateConstantStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateConstantStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateConstantStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateFunctionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateFunctionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateFunctionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedArgumentDef::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedArgumentDef>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedArgumentDef>(std::move(node)));
        }
        break;
      }
      case ResolvedArgumentRef::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedArgumentRef>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedArgumentRef>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateTableFunctionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateTableFunctionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateTableFunctionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedRelationArgumentScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedRelationArgumentScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedRelationArgumentScan>(std::move(node)));
        }
        break;
      }
      case ResolvedArgumentList::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedArgumentList>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedArgumentList>(std::move(node)));
        }
        break;
      }
      case ResolvedFunctionSignatureHolder::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedFunctionSignatureHolder>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedFunctionSignatureHolder>(std::move(node)));
        }
        break;
      }
      case ResolvedDropFunctionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropFunctionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropFunctionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedDropTableFunctionStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedDropTableFunctionStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedDropTableFunctionStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCallStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCallStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCallStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedImportStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedImportStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedImportStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedModuleStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedModuleStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedModuleStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAggregateHavingModifier::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAggregateHavingModifier>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAggregateHavingModifier>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateMaterializedViewStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateMaterializedViewStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateMaterializedViewStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateApproxViewStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateApproxViewStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateApproxViewStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateProcedureStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateProcedureStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateProcedureStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedExecuteImmediateArgument::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExecuteImmediateArgument>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExecuteImmediateArgument>(std::move(node)));
        }
        break;
      }
      case ResolvedExecuteImmediateStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedExecuteImmediateStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedExecuteImmediateStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAssignmentStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAssignmentStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAssignmentStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedCreateEntityStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCreateEntityStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCreateEntityStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAlterEntityStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAlterEntityStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAlterEntityStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedPivotColumn::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedPivotColumn>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedPivotColumn>(std::move(node)));
        }
        break;
      }
      case ResolvedPivotScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedPivotScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedPivotScan>(std::move(node)));
        }
        break;
      }
      case ResolvedReturningClause::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedReturningClause>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedReturningClause>(std::move(node)));
        }
        break;
      }
      case ResolvedUnpivotArg::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedUnpivotArg>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedUnpivotArg>(std::move(node)));
        }
        break;
      }
      case ResolvedUnpivotScan::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedUnpivotScan>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedUnpivotScan>(std::move(node)));
        }
        break;
      }
      case ResolvedCloneDataStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedCloneDataStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedCloneDataStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedTableAndColumnInfo::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedTableAndColumnInfo>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedTableAndColumnInfo>(std::move(node)));
        }
        break;
      }
      case ResolvedAnalyzeStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAnalyzeStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAnalyzeStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedAuxLoadDataPartitionFilter::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAuxLoadDataPartitionFilter>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAuxLoadDataPartitionFilter>(std::move(node)));
        }
        break;
      }
      case ResolvedAuxLoadDataStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedAuxLoadDataStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedAuxLoadDataStmt>(std::move(node)));
        }
        break;
      }
      case ResolvedUndropStmt::TYPE: {
        if constexpr (std::is_base_of_v<ResolvedNode,
                                        ResolvedUndropStmt>) {
          visited_node = DefaultVisit(CastUniquePtr<ResolvedUndropStmt>(std::move(node)));
        }
        break;
      }
      default:
        ZETASQL_RET_CHECK_FAIL() << "could not dispatch node of type "
                         << node->node_kind_string();
        break;
    }
    return VerifyType<ExpectedReturnT>(std::move(visited_node));
  }
};

}  // namespace zetasql

#endif  // ZETASQL_RESOLVED_AST_RESOLVED_AST_REWRITER_VISITOR_H_