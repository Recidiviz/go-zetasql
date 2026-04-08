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

// resolved_ast_comparator.h GENERATED FROM resolved_ast_comparator.h.template
#ifndef ZETASQL_RESOLVED_AST_RESOLVED_AST_COMPARATOR_H_
#define ZETASQL_RESOLVED_AST_RESOLVED_AST_COMPARATOR_H_

#include "googlesql/legacy_zetasql/resolved_ast/resolved_ast.h"
#include "googlesql/legacy_zetasql/resolved_ast/resolved_node.h"
#include "googlesql/legacy_zetasql/resolved_ast/resolved_column.h"
#include "absl/status/statusor.h"

namespace zetasql {

class ResolvedASTComparator {
 public:
  ResolvedASTComparator(const ResolvedASTComparator&) = delete;
  ResolvedASTComparator& operator=(const ResolvedASTComparator&) = delete;

  // Compares any two given nodes for equality. While comparing :
  // * We check the two nodes are of the same node_kind.
  // * We check the two nodes have the same structure of the tree (recursively
  //   matching the node kinds).
  // * We check for each node in the tree that all field values are equal.
  static absl::StatusOr<bool> CompareResolvedAST(const ResolvedNode* node1,
                                                 const ResolvedNode* node2);
 private:
  // Status object returned when the stack overflows.
  static absl::Status* stack_overflow_status_;

  static void InitStackOverflowStatus();

  static absl::StatusOr<bool> CompareResolvedLiteral(const ResolvedLiteral* node1,
                                                   const ResolvedLiteral* node2);
  static absl::StatusOr<bool> CompareResolvedParameter(const ResolvedParameter* node1,
                                                   const ResolvedParameter* node2);
  static absl::StatusOr<bool> CompareResolvedExpressionColumn(const ResolvedExpressionColumn* node1,
                                                   const ResolvedExpressionColumn* node2);
  static absl::StatusOr<bool> CompareResolvedCatalogColumnRef(const ResolvedCatalogColumnRef* node1,
                                                   const ResolvedCatalogColumnRef* node2);
  static absl::StatusOr<bool> CompareResolvedColumnRef(const ResolvedColumnRef* node1,
                                                   const ResolvedColumnRef* node2);
  static absl::StatusOr<bool> CompareResolvedGroupingSetMultiColumn(const ResolvedGroupingSetMultiColumn* node1,
                                                   const ResolvedGroupingSetMultiColumn* node2);
  static absl::StatusOr<bool> CompareResolvedConstant(const ResolvedConstant* node1,
                                                   const ResolvedConstant* node2);
  static absl::StatusOr<bool> CompareResolvedSystemVariable(const ResolvedSystemVariable* node1,
                                                   const ResolvedSystemVariable* node2);
  static absl::StatusOr<bool> CompareResolvedInlineLambda(const ResolvedInlineLambda* node1,
                                                   const ResolvedInlineLambda* node2);
  static absl::StatusOr<bool> CompareResolvedSequence(const ResolvedSequence* node1,
                                                   const ResolvedSequence* node2);
  static absl::StatusOr<bool> CompareResolvedFilterFieldArg(const ResolvedFilterFieldArg* node1,
                                                   const ResolvedFilterFieldArg* node2);
  static absl::StatusOr<bool> CompareResolvedFilterField(const ResolvedFilterField* node1,
                                                   const ResolvedFilterField* node2);
  static absl::StatusOr<bool> CompareResolvedFunctionCall(const ResolvedFunctionCall* node1,
                                                   const ResolvedFunctionCall* node2);
  static absl::StatusOr<bool> CompareResolvedAggregateFunctionCall(const ResolvedAggregateFunctionCall* node1,
                                                   const ResolvedAggregateFunctionCall* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyticFunctionCall(const ResolvedAnalyticFunctionCall* node1,
                                                   const ResolvedAnalyticFunctionCall* node2);
  static absl::StatusOr<bool> CompareResolvedExtendedCastElement(const ResolvedExtendedCastElement* node1,
                                                   const ResolvedExtendedCastElement* node2);
  static absl::StatusOr<bool> CompareResolvedExtendedCast(const ResolvedExtendedCast* node1,
                                                   const ResolvedExtendedCast* node2);
  static absl::StatusOr<bool> CompareResolvedCast(const ResolvedCast* node1,
                                                   const ResolvedCast* node2);
  static absl::StatusOr<bool> CompareResolvedMakeStruct(const ResolvedMakeStruct* node1,
                                                   const ResolvedMakeStruct* node2);
  static absl::StatusOr<bool> CompareResolvedMakeProto(const ResolvedMakeProto* node1,
                                                   const ResolvedMakeProto* node2);
  static absl::StatusOr<bool> CompareResolvedMakeProtoField(const ResolvedMakeProtoField* node1,
                                                   const ResolvedMakeProtoField* node2);
  static absl::StatusOr<bool> CompareResolvedGetStructField(const ResolvedGetStructField* node1,
                                                   const ResolvedGetStructField* node2);
  static absl::StatusOr<bool> CompareResolvedGetProtoField(const ResolvedGetProtoField* node1,
                                                   const ResolvedGetProtoField* node2);
  static absl::StatusOr<bool> CompareResolvedGetJsonField(const ResolvedGetJsonField* node1,
                                                   const ResolvedGetJsonField* node2);
  static absl::StatusOr<bool> CompareResolvedFlatten(const ResolvedFlatten* node1,
                                                   const ResolvedFlatten* node2);
  static absl::StatusOr<bool> CompareResolvedFlattenedArg(const ResolvedFlattenedArg* node1,
                                                   const ResolvedFlattenedArg* node2);
  static absl::StatusOr<bool> CompareResolvedReplaceFieldItem(const ResolvedReplaceFieldItem* node1,
                                                   const ResolvedReplaceFieldItem* node2);
  static absl::StatusOr<bool> CompareResolvedReplaceField(const ResolvedReplaceField* node1,
                                                   const ResolvedReplaceField* node2);
  static absl::StatusOr<bool> CompareResolvedGetProtoOneof(const ResolvedGetProtoOneof* node1,
                                                   const ResolvedGetProtoOneof* node2);
  static absl::StatusOr<bool> CompareResolvedSubqueryExpr(const ResolvedSubqueryExpr* node1,
                                                   const ResolvedSubqueryExpr* node2);
  static absl::StatusOr<bool> CompareResolvedWithExpr(const ResolvedWithExpr* node1,
                                                   const ResolvedWithExpr* node2);
  static absl::StatusOr<bool> CompareResolvedExecuteAsRoleScan(const ResolvedExecuteAsRoleScan* node1,
                                                   const ResolvedExecuteAsRoleScan* node2);
  static absl::StatusOr<bool> CompareResolvedModel(const ResolvedModel* node1,
                                                   const ResolvedModel* node2);
  static absl::StatusOr<bool> CompareResolvedConnection(const ResolvedConnection* node1,
                                                   const ResolvedConnection* node2);
  static absl::StatusOr<bool> CompareResolvedDescriptor(const ResolvedDescriptor* node1,
                                                   const ResolvedDescriptor* node2);
  static absl::StatusOr<bool> CompareResolvedSingleRowScan(const ResolvedSingleRowScan* node1,
                                                   const ResolvedSingleRowScan* node2);
  static absl::StatusOr<bool> CompareResolvedTableScan(const ResolvedTableScan* node1,
                                                   const ResolvedTableScan* node2);
  static absl::StatusOr<bool> CompareResolvedJoinScan(const ResolvedJoinScan* node1,
                                                   const ResolvedJoinScan* node2);
  static absl::StatusOr<bool> CompareResolvedArrayScan(const ResolvedArrayScan* node1,
                                                   const ResolvedArrayScan* node2);
  static absl::StatusOr<bool> CompareResolvedColumnHolder(const ResolvedColumnHolder* node1,
                                                   const ResolvedColumnHolder* node2);
  static absl::StatusOr<bool> CompareResolvedFilterScan(const ResolvedFilterScan* node1,
                                                   const ResolvedFilterScan* node2);
  static absl::StatusOr<bool> CompareResolvedGroupingCall(const ResolvedGroupingCall* node1,
                                                   const ResolvedGroupingCall* node2);
  static absl::StatusOr<bool> CompareResolvedGroupingSet(const ResolvedGroupingSet* node1,
                                                   const ResolvedGroupingSet* node2);
  static absl::StatusOr<bool> CompareResolvedRollup(const ResolvedRollup* node1,
                                                   const ResolvedRollup* node2);
  static absl::StatusOr<bool> CompareResolvedCube(const ResolvedCube* node1,
                                                   const ResolvedCube* node2);
  static absl::StatusOr<bool> CompareResolvedAggregateScan(const ResolvedAggregateScan* node1,
                                                   const ResolvedAggregateScan* node2);
  static absl::StatusOr<bool> CompareResolvedAnonymizedAggregateScan(const ResolvedAnonymizedAggregateScan* node1,
                                                   const ResolvedAnonymizedAggregateScan* node2);
  static absl::StatusOr<bool> CompareResolvedDifferentialPrivacyAggregateScan(const ResolvedDifferentialPrivacyAggregateScan* node1,
                                                   const ResolvedDifferentialPrivacyAggregateScan* node2);
  static absl::StatusOr<bool> CompareResolvedAggregationThresholdAggregateScan(const ResolvedAggregationThresholdAggregateScan* node1,
                                                   const ResolvedAggregationThresholdAggregateScan* node2);
  static absl::StatusOr<bool> CompareResolvedSetOperationItem(const ResolvedSetOperationItem* node1,
                                                   const ResolvedSetOperationItem* node2);
  static absl::StatusOr<bool> CompareResolvedSetOperationScan(const ResolvedSetOperationScan* node1,
                                                   const ResolvedSetOperationScan* node2);
  static absl::StatusOr<bool> CompareResolvedOrderByScan(const ResolvedOrderByScan* node1,
                                                   const ResolvedOrderByScan* node2);
  static absl::StatusOr<bool> CompareResolvedLimitOffsetScan(const ResolvedLimitOffsetScan* node1,
                                                   const ResolvedLimitOffsetScan* node2);
  static absl::StatusOr<bool> CompareResolvedWithRefScan(const ResolvedWithRefScan* node1,
                                                   const ResolvedWithRefScan* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyticScan(const ResolvedAnalyticScan* node1,
                                                   const ResolvedAnalyticScan* node2);
  static absl::StatusOr<bool> CompareResolvedSampleScan(const ResolvedSampleScan* node1,
                                                   const ResolvedSampleScan* node2);
  static absl::StatusOr<bool> CompareResolvedComputedColumn(const ResolvedComputedColumn* node1,
                                                   const ResolvedComputedColumn* node2);
  static absl::StatusOr<bool> CompareResolvedDeferredComputedColumn(const ResolvedDeferredComputedColumn* node1,
                                                   const ResolvedDeferredComputedColumn* node2);
  static absl::StatusOr<bool> CompareResolvedOrderByItem(const ResolvedOrderByItem* node1,
                                                   const ResolvedOrderByItem* node2);
  static absl::StatusOr<bool> CompareResolvedColumnAnnotations(const ResolvedColumnAnnotations* node1,
                                                   const ResolvedColumnAnnotations* node2);
  static absl::StatusOr<bool> CompareResolvedGeneratedColumnInfo(const ResolvedGeneratedColumnInfo* node1,
                                                   const ResolvedGeneratedColumnInfo* node2);
  static absl::StatusOr<bool> CompareResolvedColumnDefaultValue(const ResolvedColumnDefaultValue* node1,
                                                   const ResolvedColumnDefaultValue* node2);
  static absl::StatusOr<bool> CompareResolvedColumnDefinition(const ResolvedColumnDefinition* node1,
                                                   const ResolvedColumnDefinition* node2);
  static absl::StatusOr<bool> CompareResolvedPrimaryKey(const ResolvedPrimaryKey* node1,
                                                   const ResolvedPrimaryKey* node2);
  static absl::StatusOr<bool> CompareResolvedForeignKey(const ResolvedForeignKey* node1,
                                                   const ResolvedForeignKey* node2);
  static absl::StatusOr<bool> CompareResolvedCheckConstraint(const ResolvedCheckConstraint* node1,
                                                   const ResolvedCheckConstraint* node2);
  static absl::StatusOr<bool> CompareResolvedOutputColumn(const ResolvedOutputColumn* node1,
                                                   const ResolvedOutputColumn* node2);
  static absl::StatusOr<bool> CompareResolvedOutputSchema(const ResolvedOutputSchema* node1,
                                                   const ResolvedOutputSchema* node2);
  static absl::StatusOr<bool> CompareResolvedProjectScan(const ResolvedProjectScan* node1,
                                                   const ResolvedProjectScan* node2);
  static absl::StatusOr<bool> CompareResolvedTVFScan(const ResolvedTVFScan* node1,
                                                   const ResolvedTVFScan* node2);
  static absl::StatusOr<bool> CompareResolvedGroupRowsScan(const ResolvedGroupRowsScan* node1,
                                                   const ResolvedGroupRowsScan* node2);
  static absl::StatusOr<bool> CompareResolvedFunctionArgument(const ResolvedFunctionArgument* node1,
                                                   const ResolvedFunctionArgument* node2);
  static absl::StatusOr<bool> CompareResolvedExplainStmt(const ResolvedExplainStmt* node1,
                                                   const ResolvedExplainStmt* node2);
  static absl::StatusOr<bool> CompareResolvedQueryStmt(const ResolvedQueryStmt* node1,
                                                   const ResolvedQueryStmt* node2);
  static absl::StatusOr<bool> CompareResolvedGeneralizedQueryStmt(const ResolvedGeneralizedQueryStmt* node1,
                                                   const ResolvedGeneralizedQueryStmt* node2);
  static absl::StatusOr<bool> CompareResolvedMultiStmt(const ResolvedMultiStmt* node1,
                                                   const ResolvedMultiStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateWithEntryStmt(const ResolvedCreateWithEntryStmt* node1,
                                                   const ResolvedCreateWithEntryStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateDatabaseStmt(const ResolvedCreateDatabaseStmt* node1,
                                                   const ResolvedCreateDatabaseStmt* node2);
  static absl::StatusOr<bool> CompareResolvedIndexItem(const ResolvedIndexItem* node1,
                                                   const ResolvedIndexItem* node2);
  static absl::StatusOr<bool> CompareResolvedUnnestItem(const ResolvedUnnestItem* node1,
                                                   const ResolvedUnnestItem* node2);
  static absl::StatusOr<bool> CompareResolvedCreateIndexStmt(const ResolvedCreateIndexStmt* node1,
                                                   const ResolvedCreateIndexStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateSchemaStmt(const ResolvedCreateSchemaStmt* node1,
                                                   const ResolvedCreateSchemaStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateExternalSchemaStmt(const ResolvedCreateExternalSchemaStmt* node1,
                                                   const ResolvedCreateExternalSchemaStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateTableStmt(const ResolvedCreateTableStmt* node1,
                                                   const ResolvedCreateTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateTableAsSelectStmt(const ResolvedCreateTableAsSelectStmt* node1,
                                                   const ResolvedCreateTableAsSelectStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateModelAliasedQuery(const ResolvedCreateModelAliasedQuery* node1,
                                                   const ResolvedCreateModelAliasedQuery* node2);
  static absl::StatusOr<bool> CompareResolvedCreateModelStmt(const ResolvedCreateModelStmt* node1,
                                                   const ResolvedCreateModelStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateViewStmt(const ResolvedCreateViewStmt* node1,
                                                   const ResolvedCreateViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedWithPartitionColumns(const ResolvedWithPartitionColumns* node1,
                                                   const ResolvedWithPartitionColumns* node2);
  static absl::StatusOr<bool> CompareResolvedCreateSnapshotTableStmt(const ResolvedCreateSnapshotTableStmt* node1,
                                                   const ResolvedCreateSnapshotTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateExternalTableStmt(const ResolvedCreateExternalTableStmt* node1,
                                                   const ResolvedCreateExternalTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedExportModelStmt(const ResolvedExportModelStmt* node1,
                                                   const ResolvedExportModelStmt* node2);
  static absl::StatusOr<bool> CompareResolvedExportDataStmt(const ResolvedExportDataStmt* node1,
                                                   const ResolvedExportDataStmt* node2);
  static absl::StatusOr<bool> CompareResolvedExportMetadataStmt(const ResolvedExportMetadataStmt* node1,
                                                   const ResolvedExportMetadataStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDefineTableStmt(const ResolvedDefineTableStmt* node1,
                                                   const ResolvedDefineTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDescribeStmt(const ResolvedDescribeStmt* node1,
                                                   const ResolvedDescribeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedShowStmt(const ResolvedShowStmt* node1,
                                                   const ResolvedShowStmt* node2);
  static absl::StatusOr<bool> CompareResolvedBeginStmt(const ResolvedBeginStmt* node1,
                                                   const ResolvedBeginStmt* node2);
  static absl::StatusOr<bool> CompareResolvedSetTransactionStmt(const ResolvedSetTransactionStmt* node1,
                                                   const ResolvedSetTransactionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCommitStmt(const ResolvedCommitStmt* node1,
                                                   const ResolvedCommitStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRollbackStmt(const ResolvedRollbackStmt* node1,
                                                   const ResolvedRollbackStmt* node2);
  static absl::StatusOr<bool> CompareResolvedStartBatchStmt(const ResolvedStartBatchStmt* node1,
                                                   const ResolvedStartBatchStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRunBatchStmt(const ResolvedRunBatchStmt* node1,
                                                   const ResolvedRunBatchStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAbortBatchStmt(const ResolvedAbortBatchStmt* node1,
                                                   const ResolvedAbortBatchStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropStmt(const ResolvedDropStmt* node1,
                                                   const ResolvedDropStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropMaterializedViewStmt(const ResolvedDropMaterializedViewStmt* node1,
                                                   const ResolvedDropMaterializedViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropSnapshotTableStmt(const ResolvedDropSnapshotTableStmt* node1,
                                                   const ResolvedDropSnapshotTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRecursiveRefScan(const ResolvedRecursiveRefScan* node1,
                                                   const ResolvedRecursiveRefScan* node2);
  static absl::StatusOr<bool> CompareResolvedRecursionDepthModifier(const ResolvedRecursionDepthModifier* node1,
                                                   const ResolvedRecursionDepthModifier* node2);
  static absl::StatusOr<bool> CompareResolvedRecursiveScan(const ResolvedRecursiveScan* node1,
                                                   const ResolvedRecursiveScan* node2);
  static absl::StatusOr<bool> CompareResolvedWithScan(const ResolvedWithScan* node1,
                                                   const ResolvedWithScan* node2);
  static absl::StatusOr<bool> CompareResolvedWithEntry(const ResolvedWithEntry* node1,
                                                   const ResolvedWithEntry* node2);
  static absl::StatusOr<bool> CompareResolvedOption(const ResolvedOption* node1,
                                                   const ResolvedOption* node2);
  static absl::StatusOr<bool> CompareResolvedWindowPartitioning(const ResolvedWindowPartitioning* node1,
                                                   const ResolvedWindowPartitioning* node2);
  static absl::StatusOr<bool> CompareResolvedWindowOrdering(const ResolvedWindowOrdering* node1,
                                                   const ResolvedWindowOrdering* node2);
  static absl::StatusOr<bool> CompareResolvedWindowFrame(const ResolvedWindowFrame* node1,
                                                   const ResolvedWindowFrame* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyticFunctionGroup(const ResolvedAnalyticFunctionGroup* node1,
                                                   const ResolvedAnalyticFunctionGroup* node2);
  static absl::StatusOr<bool> CompareResolvedWindowFrameExpr(const ResolvedWindowFrameExpr* node1,
                                                   const ResolvedWindowFrameExpr* node2);
  static absl::StatusOr<bool> CompareResolvedDMLValue(const ResolvedDMLValue* node1,
                                                   const ResolvedDMLValue* node2);
  static absl::StatusOr<bool> CompareResolvedDMLDefault(const ResolvedDMLDefault* node1,
                                                   const ResolvedDMLDefault* node2);
  static absl::StatusOr<bool> CompareResolvedAssertStmt(const ResolvedAssertStmt* node1,
                                                   const ResolvedAssertStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAssertRowsModified(const ResolvedAssertRowsModified* node1,
                                                   const ResolvedAssertRowsModified* node2);
  static absl::StatusOr<bool> CompareResolvedOnConflictClause(const ResolvedOnConflictClause* node1,
                                                   const ResolvedOnConflictClause* node2);
  static absl::StatusOr<bool> CompareResolvedInsertRow(const ResolvedInsertRow* node1,
                                                   const ResolvedInsertRow* node2);
  static absl::StatusOr<bool> CompareResolvedInsertStmt(const ResolvedInsertStmt* node1,
                                                   const ResolvedInsertStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDeleteStmt(const ResolvedDeleteStmt* node1,
                                                   const ResolvedDeleteStmt* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateItem(const ResolvedUpdateItem* node1,
                                                   const ResolvedUpdateItem* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateArrayItem(const ResolvedUpdateArrayItem* node1,
                                                   const ResolvedUpdateArrayItem* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateStmt(const ResolvedUpdateStmt* node1,
                                                   const ResolvedUpdateStmt* node2);
  static absl::StatusOr<bool> CompareResolvedMergeWhen(const ResolvedMergeWhen* node1,
                                                   const ResolvedMergeWhen* node2);
  static absl::StatusOr<bool> CompareResolvedMergeStmt(const ResolvedMergeStmt* node1,
                                                   const ResolvedMergeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedTruncateStmt(const ResolvedTruncateStmt* node1,
                                                   const ResolvedTruncateStmt* node2);
  static absl::StatusOr<bool> CompareResolvedObjectUnit(const ResolvedObjectUnit* node1,
                                                   const ResolvedObjectUnit* node2);
  static absl::StatusOr<bool> CompareResolvedPrivilege(const ResolvedPrivilege* node1,
                                                   const ResolvedPrivilege* node2);
  static absl::StatusOr<bool> CompareResolvedGrantStmt(const ResolvedGrantStmt* node1,
                                                   const ResolvedGrantStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRevokeStmt(const ResolvedRevokeStmt* node1,
                                                   const ResolvedRevokeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterDatabaseStmt(const ResolvedAlterDatabaseStmt* node1,
                                                   const ResolvedAlterDatabaseStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterIndexStmt(const ResolvedAlterIndexStmt* node1,
                                                   const ResolvedAlterIndexStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterMaterializedViewStmt(const ResolvedAlterMaterializedViewStmt* node1,
                                                   const ResolvedAlterMaterializedViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterApproxViewStmt(const ResolvedAlterApproxViewStmt* node1,
                                                   const ResolvedAlterApproxViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterSchemaStmt(const ResolvedAlterSchemaStmt* node1,
                                                   const ResolvedAlterSchemaStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterExternalSchemaStmt(const ResolvedAlterExternalSchemaStmt* node1,
                                                   const ResolvedAlterExternalSchemaStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterModelStmt(const ResolvedAlterModelStmt* node1,
                                                   const ResolvedAlterModelStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterTableStmt(const ResolvedAlterTableStmt* node1,
                                                   const ResolvedAlterTableStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterViewStmt(const ResolvedAlterViewStmt* node1,
                                                   const ResolvedAlterViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedSetOptionsAction(const ResolvedSetOptionsAction* node1,
                                                   const ResolvedSetOptionsAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterSubEntityAction(const ResolvedAlterSubEntityAction* node1,
                                                   const ResolvedAlterSubEntityAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddSubEntityAction(const ResolvedAddSubEntityAction* node1,
                                                   const ResolvedAddSubEntityAction* node2);
  static absl::StatusOr<bool> CompareResolvedDropSubEntityAction(const ResolvedDropSubEntityAction* node1,
                                                   const ResolvedDropSubEntityAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddColumnAction(const ResolvedAddColumnAction* node1,
                                                   const ResolvedAddColumnAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddColumnIdentifierAction(const ResolvedAddColumnIdentifierAction* node1,
                                                   const ResolvedAddColumnIdentifierAction* node2);
  static absl::StatusOr<bool> CompareResolvedRebuildAction(const ResolvedRebuildAction* node1,
                                                   const ResolvedRebuildAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddConstraintAction(const ResolvedAddConstraintAction* node1,
                                                   const ResolvedAddConstraintAction* node2);
  static absl::StatusOr<bool> CompareResolvedDropConstraintAction(const ResolvedDropConstraintAction* node1,
                                                   const ResolvedDropConstraintAction* node2);
  static absl::StatusOr<bool> CompareResolvedDropPrimaryKeyAction(const ResolvedDropPrimaryKeyAction* node1,
                                                   const ResolvedDropPrimaryKeyAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnOptionsAction(const ResolvedAlterColumnOptionsAction* node1,
                                                   const ResolvedAlterColumnOptionsAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnDropNotNullAction(const ResolvedAlterColumnDropNotNullAction* node1,
                                                   const ResolvedAlterColumnDropNotNullAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnDropGeneratedAction(const ResolvedAlterColumnDropGeneratedAction* node1,
                                                   const ResolvedAlterColumnDropGeneratedAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnSetDataTypeAction(const ResolvedAlterColumnSetDataTypeAction* node1,
                                                   const ResolvedAlterColumnSetDataTypeAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnSetDefaultAction(const ResolvedAlterColumnSetDefaultAction* node1,
                                                   const ResolvedAlterColumnSetDefaultAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterColumnDropDefaultAction(const ResolvedAlterColumnDropDefaultAction* node1,
                                                   const ResolvedAlterColumnDropDefaultAction* node2);
  static absl::StatusOr<bool> CompareResolvedDropColumnAction(const ResolvedDropColumnAction* node1,
                                                   const ResolvedDropColumnAction* node2);
  static absl::StatusOr<bool> CompareResolvedRenameColumnAction(const ResolvedRenameColumnAction* node1,
                                                   const ResolvedRenameColumnAction* node2);
  static absl::StatusOr<bool> CompareResolvedSetAsAction(const ResolvedSetAsAction* node1,
                                                   const ResolvedSetAsAction* node2);
  static absl::StatusOr<bool> CompareResolvedSetCollateClause(const ResolvedSetCollateClause* node1,
                                                   const ResolvedSetCollateClause* node2);
  static absl::StatusOr<bool> CompareResolvedAlterTableSetOptionsStmt(const ResolvedAlterTableSetOptionsStmt* node1,
                                                   const ResolvedAlterTableSetOptionsStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRenameStmt(const ResolvedRenameStmt* node1,
                                                   const ResolvedRenameStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreatePrivilegeRestrictionStmt(const ResolvedCreatePrivilegeRestrictionStmt* node1,
                                                   const ResolvedCreatePrivilegeRestrictionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateRowAccessPolicyStmt(const ResolvedCreateRowAccessPolicyStmt* node1,
                                                   const ResolvedCreateRowAccessPolicyStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropPrivilegeRestrictionStmt(const ResolvedDropPrivilegeRestrictionStmt* node1,
                                                   const ResolvedDropPrivilegeRestrictionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropRowAccessPolicyStmt(const ResolvedDropRowAccessPolicyStmt* node1,
                                                   const ResolvedDropRowAccessPolicyStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropIndexStmt(const ResolvedDropIndexStmt* node1,
                                                   const ResolvedDropIndexStmt* node2);
  static absl::StatusOr<bool> CompareResolvedGrantToAction(const ResolvedGrantToAction* node1,
                                                   const ResolvedGrantToAction* node2);
  static absl::StatusOr<bool> CompareResolvedRestrictToAction(const ResolvedRestrictToAction* node1,
                                                   const ResolvedRestrictToAction* node2);
  static absl::StatusOr<bool> CompareResolvedAddToRestricteeListAction(const ResolvedAddToRestricteeListAction* node1,
                                                   const ResolvedAddToRestricteeListAction* node2);
  static absl::StatusOr<bool> CompareResolvedRemoveFromRestricteeListAction(const ResolvedRemoveFromRestricteeListAction* node1,
                                                   const ResolvedRemoveFromRestricteeListAction* node2);
  static absl::StatusOr<bool> CompareResolvedFilterUsingAction(const ResolvedFilterUsingAction* node1,
                                                   const ResolvedFilterUsingAction* node2);
  static absl::StatusOr<bool> CompareResolvedRevokeFromAction(const ResolvedRevokeFromAction* node1,
                                                   const ResolvedRevokeFromAction* node2);
  static absl::StatusOr<bool> CompareResolvedRenameToAction(const ResolvedRenameToAction* node1,
                                                   const ResolvedRenameToAction* node2);
  static absl::StatusOr<bool> CompareResolvedAlterPrivilegeRestrictionStmt(const ResolvedAlterPrivilegeRestrictionStmt* node1,
                                                   const ResolvedAlterPrivilegeRestrictionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterRowAccessPolicyStmt(const ResolvedAlterRowAccessPolicyStmt* node1,
                                                   const ResolvedAlterRowAccessPolicyStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterAllRowAccessPoliciesStmt(const ResolvedAlterAllRowAccessPoliciesStmt* node1,
                                                   const ResolvedAlterAllRowAccessPoliciesStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateConstantStmt(const ResolvedCreateConstantStmt* node1,
                                                   const ResolvedCreateConstantStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateFunctionStmt(const ResolvedCreateFunctionStmt* node1,
                                                   const ResolvedCreateFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedArgumentDef(const ResolvedArgumentDef* node1,
                                                   const ResolvedArgumentDef* node2);
  static absl::StatusOr<bool> CompareResolvedArgumentRef(const ResolvedArgumentRef* node1,
                                                   const ResolvedArgumentRef* node2);
  static absl::StatusOr<bool> CompareResolvedCreateTableFunctionStmt(const ResolvedCreateTableFunctionStmt* node1,
                                                   const ResolvedCreateTableFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedRelationArgumentScan(const ResolvedRelationArgumentScan* node1,
                                                   const ResolvedRelationArgumentScan* node2);
  static absl::StatusOr<bool> CompareResolvedArgumentList(const ResolvedArgumentList* node1,
                                                   const ResolvedArgumentList* node2);
  static absl::StatusOr<bool> CompareResolvedFunctionSignatureHolder(const ResolvedFunctionSignatureHolder* node1,
                                                   const ResolvedFunctionSignatureHolder* node2);
  static absl::StatusOr<bool> CompareResolvedDropFunctionStmt(const ResolvedDropFunctionStmt* node1,
                                                   const ResolvedDropFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedDropTableFunctionStmt(const ResolvedDropTableFunctionStmt* node1,
                                                   const ResolvedDropTableFunctionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCallStmt(const ResolvedCallStmt* node1,
                                                   const ResolvedCallStmt* node2);
  static absl::StatusOr<bool> CompareResolvedImportStmt(const ResolvedImportStmt* node1,
                                                   const ResolvedImportStmt* node2);
  static absl::StatusOr<bool> CompareResolvedModuleStmt(const ResolvedModuleStmt* node1,
                                                   const ResolvedModuleStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAggregateHavingModifier(const ResolvedAggregateHavingModifier* node1,
                                                   const ResolvedAggregateHavingModifier* node2);
  static absl::StatusOr<bool> CompareResolvedCreateMaterializedViewStmt(const ResolvedCreateMaterializedViewStmt* node1,
                                                   const ResolvedCreateMaterializedViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateApproxViewStmt(const ResolvedCreateApproxViewStmt* node1,
                                                   const ResolvedCreateApproxViewStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateProcedureStmt(const ResolvedCreateProcedureStmt* node1,
                                                   const ResolvedCreateProcedureStmt* node2);
  static absl::StatusOr<bool> CompareResolvedExecuteImmediateArgument(const ResolvedExecuteImmediateArgument* node1,
                                                   const ResolvedExecuteImmediateArgument* node2);
  static absl::StatusOr<bool> CompareResolvedExecuteImmediateStmt(const ResolvedExecuteImmediateStmt* node1,
                                                   const ResolvedExecuteImmediateStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAssignmentStmt(const ResolvedAssignmentStmt* node1,
                                                   const ResolvedAssignmentStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreateEntityStmt(const ResolvedCreateEntityStmt* node1,
                                                   const ResolvedCreateEntityStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterEntityStmt(const ResolvedAlterEntityStmt* node1,
                                                   const ResolvedAlterEntityStmt* node2);
  static absl::StatusOr<bool> CompareResolvedPivotColumn(const ResolvedPivotColumn* node1,
                                                   const ResolvedPivotColumn* node2);
  static absl::StatusOr<bool> CompareResolvedPivotScan(const ResolvedPivotScan* node1,
                                                   const ResolvedPivotScan* node2);
  static absl::StatusOr<bool> CompareResolvedReturningClause(const ResolvedReturningClause* node1,
                                                   const ResolvedReturningClause* node2);
  static absl::StatusOr<bool> CompareResolvedUnpivotArg(const ResolvedUnpivotArg* node1,
                                                   const ResolvedUnpivotArg* node2);
  static absl::StatusOr<bool> CompareResolvedUnpivotScan(const ResolvedUnpivotScan* node1,
                                                   const ResolvedUnpivotScan* node2);
  static absl::StatusOr<bool> CompareResolvedMatchRecognizeScan(const ResolvedMatchRecognizeScan* node1,
                                                   const ResolvedMatchRecognizeScan* node2);
  static absl::StatusOr<bool> CompareResolvedMeasureGroup(const ResolvedMeasureGroup* node1,
                                                   const ResolvedMeasureGroup* node2);
  static absl::StatusOr<bool> CompareResolvedMatchRecognizeVariableDefinition(const ResolvedMatchRecognizeVariableDefinition* node1,
                                                   const ResolvedMatchRecognizeVariableDefinition* node2);
  static absl::StatusOr<bool> CompareResolvedMatchRecognizePatternEmpty(const ResolvedMatchRecognizePatternEmpty* node1,
                                                   const ResolvedMatchRecognizePatternEmpty* node2);
  static absl::StatusOr<bool> CompareResolvedMatchRecognizePatternAnchor(const ResolvedMatchRecognizePatternAnchor* node1,
                                                   const ResolvedMatchRecognizePatternAnchor* node2);
  static absl::StatusOr<bool> CompareResolvedMatchRecognizePatternVariableRef(const ResolvedMatchRecognizePatternVariableRef* node1,
                                                   const ResolvedMatchRecognizePatternVariableRef* node2);
  static absl::StatusOr<bool> CompareResolvedMatchRecognizePatternOperation(const ResolvedMatchRecognizePatternOperation* node1,
                                                   const ResolvedMatchRecognizePatternOperation* node2);
  static absl::StatusOr<bool> CompareResolvedMatchRecognizePatternQuantification(const ResolvedMatchRecognizePatternQuantification* node1,
                                                   const ResolvedMatchRecognizePatternQuantification* node2);
  static absl::StatusOr<bool> CompareResolvedCloneDataStmt(const ResolvedCloneDataStmt* node1,
                                                   const ResolvedCloneDataStmt* node2);
  static absl::StatusOr<bool> CompareResolvedTableAndColumnInfo(const ResolvedTableAndColumnInfo* node1,
                                                   const ResolvedTableAndColumnInfo* node2);
  static absl::StatusOr<bool> CompareResolvedAnalyzeStmt(const ResolvedAnalyzeStmt* node1,
                                                   const ResolvedAnalyzeStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAuxLoadDataPartitionFilter(const ResolvedAuxLoadDataPartitionFilter* node1,
                                                   const ResolvedAuxLoadDataPartitionFilter* node2);
  static absl::StatusOr<bool> CompareResolvedAuxLoadDataStmt(const ResolvedAuxLoadDataStmt* node1,
                                                   const ResolvedAuxLoadDataStmt* node2);
  static absl::StatusOr<bool> CompareResolvedCreatePropertyGraphStmt(const ResolvedCreatePropertyGraphStmt* node1,
                                                   const ResolvedCreatePropertyGraphStmt* node2);
  static absl::StatusOr<bool> CompareResolvedGraphElementTable(const ResolvedGraphElementTable* node1,
                                                   const ResolvedGraphElementTable* node2);
  static absl::StatusOr<bool> CompareResolvedGraphNodeTableReference(const ResolvedGraphNodeTableReference* node1,
                                                   const ResolvedGraphNodeTableReference* node2);
  static absl::StatusOr<bool> CompareResolvedGraphElementLabel(const ResolvedGraphElementLabel* node1,
                                                   const ResolvedGraphElementLabel* node2);
  static absl::StatusOr<bool> CompareResolvedGraphPropertyDeclaration(const ResolvedGraphPropertyDeclaration* node1,
                                                   const ResolvedGraphPropertyDeclaration* node2);
  static absl::StatusOr<bool> CompareResolvedGraphPropertyDefinition(const ResolvedGraphPropertyDefinition* node1,
                                                   const ResolvedGraphPropertyDefinition* node2);
  static absl::StatusOr<bool> CompareResolvedGraphRefScan(const ResolvedGraphRefScan* node1,
                                                   const ResolvedGraphRefScan* node2);
  static absl::StatusOr<bool> CompareResolvedGraphLinearScan(const ResolvedGraphLinearScan* node1,
                                                   const ResolvedGraphLinearScan* node2);
  static absl::StatusOr<bool> CompareResolvedGraphTableScan(const ResolvedGraphTableScan* node1,
                                                   const ResolvedGraphTableScan* node2);
  static absl::StatusOr<bool> CompareResolvedGraphScan(const ResolvedGraphScan* node1,
                                                   const ResolvedGraphScan* node2);
  static absl::StatusOr<bool> CompareResolvedGraphPathPatternQuantifier(const ResolvedGraphPathPatternQuantifier* node1,
                                                   const ResolvedGraphPathPatternQuantifier* node2);
  static absl::StatusOr<bool> CompareResolvedGraphPathSearchPrefix(const ResolvedGraphPathSearchPrefix* node1,
                                                   const ResolvedGraphPathSearchPrefix* node2);
  static absl::StatusOr<bool> CompareResolvedGraphNodeScan(const ResolvedGraphNodeScan* node1,
                                                   const ResolvedGraphNodeScan* node2);
  static absl::StatusOr<bool> CompareResolvedGraphEdgeScan(const ResolvedGraphEdgeScan* node1,
                                                   const ResolvedGraphEdgeScan* node2);
  static absl::StatusOr<bool> CompareResolvedGraphGetElementProperty(const ResolvedGraphGetElementProperty* node1,
                                                   const ResolvedGraphGetElementProperty* node2);
  static absl::StatusOr<bool> CompareResolvedGraphLabelNaryExpr(const ResolvedGraphLabelNaryExpr* node1,
                                                   const ResolvedGraphLabelNaryExpr* node2);
  static absl::StatusOr<bool> CompareResolvedGraphLabel(const ResolvedGraphLabel* node1,
                                                   const ResolvedGraphLabel* node2);
  static absl::StatusOr<bool> CompareResolvedGraphWildCardLabel(const ResolvedGraphWildCardLabel* node1,
                                                   const ResolvedGraphWildCardLabel* node2);
  static absl::StatusOr<bool> CompareResolvedGraphElementIdentifier(const ResolvedGraphElementIdentifier* node1,
                                                   const ResolvedGraphElementIdentifier* node2);
  static absl::StatusOr<bool> CompareResolvedGraphElementProperty(const ResolvedGraphElementProperty* node1,
                                                   const ResolvedGraphElementProperty* node2);
  static absl::StatusOr<bool> CompareResolvedGraphMakeElement(const ResolvedGraphMakeElement* node1,
                                                   const ResolvedGraphMakeElement* node2);
  static absl::StatusOr<bool> CompareResolvedArrayAggregate(const ResolvedArrayAggregate* node1,
                                                   const ResolvedArrayAggregate* node2);
  static absl::StatusOr<bool> CompareResolvedGraphMakeArrayVariable(const ResolvedGraphMakeArrayVariable* node1,
                                                   const ResolvedGraphMakeArrayVariable* node2);
  static absl::StatusOr<bool> CompareResolvedGraphPathMode(const ResolvedGraphPathMode* node1,
                                                   const ResolvedGraphPathMode* node2);
  static absl::StatusOr<bool> CompareResolvedGraphPathScan(const ResolvedGraphPathScan* node1,
                                                   const ResolvedGraphPathScan* node2);
  static absl::StatusOr<bool> CompareResolvedGraphIsLabeledPredicate(const ResolvedGraphIsLabeledPredicate* node1,
                                                   const ResolvedGraphIsLabeledPredicate* node2);
  static absl::StatusOr<bool> CompareResolvedUndropStmt(const ResolvedUndropStmt* node1,
                                                   const ResolvedUndropStmt* node2);
  static absl::StatusOr<bool> CompareResolvedIdentityColumnInfo(const ResolvedIdentityColumnInfo* node1,
                                                   const ResolvedIdentityColumnInfo* node2);
  static absl::StatusOr<bool> CompareResolvedStaticDescribeScan(const ResolvedStaticDescribeScan* node1,
                                                   const ResolvedStaticDescribeScan* node2);
  static absl::StatusOr<bool> CompareResolvedAssertScan(const ResolvedAssertScan* node1,
                                                   const ResolvedAssertScan* node2);
  static absl::StatusOr<bool> CompareResolvedLogScan(const ResolvedLogScan* node1,
                                                   const ResolvedLogScan* node2);
  static absl::StatusOr<bool> CompareResolvedPipeIfScan(const ResolvedPipeIfScan* node1,
                                                   const ResolvedPipeIfScan* node2);
  static absl::StatusOr<bool> CompareResolvedPipeIfCase(const ResolvedPipeIfCase* node1,
                                                   const ResolvedPipeIfCase* node2);
  static absl::StatusOr<bool> CompareResolvedPipeForkScan(const ResolvedPipeForkScan* node1,
                                                   const ResolvedPipeForkScan* node2);
  static absl::StatusOr<bool> CompareResolvedPipeTeeScan(const ResolvedPipeTeeScan* node1,
                                                   const ResolvedPipeTeeScan* node2);
  static absl::StatusOr<bool> CompareResolvedPipeExportDataScan(const ResolvedPipeExportDataScan* node1,
                                                   const ResolvedPipeExportDataScan* node2);
  static absl::StatusOr<bool> CompareResolvedPipeCreateTableScan(const ResolvedPipeCreateTableScan* node1,
                                                   const ResolvedPipeCreateTableScan* node2);
  static absl::StatusOr<bool> CompareResolvedPipeInsertScan(const ResolvedPipeInsertScan* node1,
                                                   const ResolvedPipeInsertScan* node2);
  static absl::StatusOr<bool> CompareResolvedSubpipeline(const ResolvedSubpipeline* node1,
                                                   const ResolvedSubpipeline* node2);
  static absl::StatusOr<bool> CompareResolvedSubpipelineInputScan(const ResolvedSubpipelineInputScan* node1,
                                                   const ResolvedSubpipelineInputScan* node2);
  static absl::StatusOr<bool> CompareResolvedGeneralizedQuerySubpipeline(const ResolvedGeneralizedQuerySubpipeline* node1,
                                                   const ResolvedGeneralizedQuerySubpipeline* node2);
  static absl::StatusOr<bool> CompareResolvedBarrierScan(const ResolvedBarrierScan* node1,
                                                   const ResolvedBarrierScan* node2);
  static absl::StatusOr<bool> CompareResolvedCreateConnectionStmt(const ResolvedCreateConnectionStmt* node1,
                                                   const ResolvedCreateConnectionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedAlterConnectionStmt(const ResolvedAlterConnectionStmt* node1,
                                                   const ResolvedAlterConnectionStmt* node2);
  static absl::StatusOr<bool> CompareResolvedLockMode(const ResolvedLockMode* node1,
                                                   const ResolvedLockMode* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateFieldItem(const ResolvedUpdateFieldItem* node1,
                                                   const ResolvedUpdateFieldItem* node2);
  static absl::StatusOr<bool> CompareResolvedUpdateConstructor(const ResolvedUpdateConstructor* node1,
                                                   const ResolvedUpdateConstructor* node2);
};

}  // namespace zetasql

#endif  // ZETASQL_RESOLVED_AST_RESOLVED_AST_COMPARATOR_H_