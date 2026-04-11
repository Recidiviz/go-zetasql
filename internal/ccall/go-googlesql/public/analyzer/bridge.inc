#if 0
static std::unique_ptr<const googlesql::ResolvedArgument> make_unique_argument(void *arg)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case googlesql::RESOLVED_INLINE_LAMBDA:
  case googlesql::RESOLVED_FILTER_FIELD_ARG:
  case googlesql::RESOLVED_EXTENDED_CAST_ELEMENT:
  case googlesql::RESOLVED_EXTENDED_CAST:
  case googlesql::RESOLVED_MAKE_PROTO_FIELD:
  case googlesql::RESOLVED_REPLACE_FIELD_ITEM:
  case googlesql::RESOLVED_MODEL:
  case googlesql::RESOLVED_CONNECTION:
  case googlesql::RESOLVED_DESCRIPTOR:
  case googlesql::RESOLVED_COLUMN_HOLDER:
  case googlesql::RESOLVED_GROUPING_SET:
  case googlesql::RESOLVED_SET_OPERATION_ITEM:
  case googlesql::RESOLVED_COMPUTED_COLUMN:
  case googlesql::RESOLVED_ORDER_BY_ITEM:
  case googlesql::RESOLVED_COLUMN_ANNOTATIONS:
  case googlesql::RESOLVED_GENERATED_COLUMN_INFO:
  case googlesql::RESOLVED_COLUMN_DEFAULT_VALUE:
  case googlesql::RESOLVED_COLUMN_DEFINITION:
  case googlesql::RESOLVED_PRIMARY_KEY:
  case googlesql::RESOLVED_FOREIGN_KEY:
  case googlesql::RESOLVED_CHECK_CONSTRAINT:
  case googlesql::RESOLVED_OUTPUT_COLUMN:
  case googlesql::RESOLVED_FUNCTION_ARGUMENT:
  case googlesql::RESOLVED_INDEX_ITEM:
  case googlesql::RESOLVED_UNNEST_ITEM:
  case googlesql::RESOLVED_WITH_PARTITION_COLUMNS:
  case googlesql::RESOLVED_WITH_ENTRY:
  case googlesql::RESOLVED_OPTION:
  case googlesql::RESOLVED_WINDOW_PARTITIONING:
  case googlesql::RESOLVED_WINDOW_ORDERING:
  case googlesql::RESOLVED_WINDOW_FRAME:
  case googlesql::RESOLVED_ANALYTIC_FUNCTION_GROUP:
  case googlesql::RESOLVED_WINDOW_FRAME_EXPR:
  case googlesql::RESOLVED_DMLVALUE:
  case googlesql::RESOLVED_ASSERT_ROWS_MODIFIED:
  case googlesql::RESOLVED_INSERT_ROW:
  case googlesql::RESOLVED_UPDATE_ITEM:
  case googlesql::RESOLVED_UPDATE_ARRAY_ITEM:
  case googlesql::RESOLVED_MERGE_WHEN:
  case googlesql::RESOLVED_OBJECT_UNIT:
  case googlesql::RESOLVED_PRIVILEGE:
  case googlesql::RESOLVED_SET_OPTIONS_ACTION:
  case googlesql::RESOLVED_ADD_COLUMN_ACTION:
  case googlesql::RESOLVED_ADD_CONSTRAINT_ACTION:
  case googlesql::RESOLVED_DROP_CONSTRAINT_ACTION:
  case googlesql::RESOLVED_DROP_PRIMARY_KEY_ACTION:
  case googlesql::RESOLVED_ALTER_COLUMN_OPTIONS_ACTION:
  case googlesql::RESOLVED_ALTER_COLUMN_DROP_NOT_NULL_ACTION:
  case googlesql::RESOLVED_ALTER_COLUMN_SET_DATA_TYPE_ACTION:
  case googlesql::RESOLVED_ALTER_COLUMN_SET_DEFAULT_ACTION:
  case googlesql::RESOLVED_ALTER_COLUMN_DROP_DEFAULT_ACTION:
  case googlesql::RESOLVED_DROP_COLUMN_ACTION:
  case googlesql::RESOLVED_RENAME_COLUMN_ACTION:
  case googlesql::RESOLVED_SET_AS_ACTION:
  case googlesql::RESOLVED_GRANT_TO_ACTION:
  case googlesql::RESOLVED_RESTRICT_TO_ACTION:
  case googlesql::RESOLVED_ADD_TO_RESTRICTEE_LIST_ACTION:
  case googlesql::RESOLVED_REMOVE_FROM_RESTRICTEE_LIST_ACTION:
  case googlesql::RESOLVED_FILTER_USING_ACTION:
  case googlesql::RESOLVED_REVOKE_FROM_ACTION:
  case googlesql::RESOLVED_RENAME_TO_ACTION:
  case googlesql::RESOLVED_ARGUMENT_DEF:
  case googlesql::RESOLVED_ARGUMENT_LIST:
  case googlesql::RESOLVED_FUNCTION_SIGNATURE_HOLDER:
  case googlesql::RESOLVED_AGGREGATE_HAVING_MODIFIER:
  case googlesql::RESOLVED_EXECUTE_IMMEDIATE_ARGUMENT:
  case googlesql::RESOLVED_PIVOT_COLUMN:
  case googlesql::RESOLVED_RETURNING_CLAUSE:
  case googlesql::RESOLVED_UNPIVOT_ARG:
  case googlesql::RESOLVED_TABLE_AND_COLUMN_INFO:
  default:
    break;
  }
  return nullptr;
}
#endif

static std::unique_ptr<const googlesql::ResolvedAlterAction> make_unique_action(void *arg)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case googlesql::RESOLVED_SET_OPTIONS_ACTION:{
    auto ret = googlesql::MakeResolvedSetOptionsAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSetOptionsAction));
    return ret;
  }
  case googlesql::RESOLVED_ADD_COLUMN_ACTION:{
    auto ret = googlesql::MakeResolvedAddColumnAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAddColumnAction));
    return ret;
  }
  case googlesql::RESOLVED_ADD_CONSTRAINT_ACTION:{
    auto ret = googlesql::MakeResolvedAddConstraintAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAddConstraintAction));
    return ret;
  }
  case googlesql::RESOLVED_DROP_CONSTRAINT_ACTION:{
    auto ret = googlesql::MakeResolvedDropConstraintAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropConstraintAction));
    return ret;
  }
  case googlesql::RESOLVED_DROP_PRIMARY_KEY_ACTION:{
    auto ret = googlesql::MakeResolvedDropPrimaryKeyAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropPrimaryKeyAction));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_COLUMN_OPTIONS_ACTION:{
    auto ret = googlesql::MakeResolvedAlterColumnOptionsAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterColumnOptionsAction));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_COLUMN_DROP_NOT_NULL_ACTION:{
    auto ret = googlesql::MakeResolvedAlterColumnDropNotNullAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterColumnDropNotNullAction));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_COLUMN_SET_DATA_TYPE_ACTION:{
    auto ret = googlesql::MakeResolvedAlterColumnSetDataTypeAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterColumnSetDataTypeAction));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_COLUMN_SET_DEFAULT_ACTION:{
    auto ret = googlesql::MakeResolvedAlterColumnSetDefaultAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterColumnSetDefaultAction));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_COLUMN_DROP_DEFAULT_ACTION:{
    auto ret = googlesql::MakeResolvedAlterColumnDropDefaultAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterColumnDropDefaultAction));
    return ret;
  }
  case googlesql::RESOLVED_DROP_COLUMN_ACTION:{
    auto ret = googlesql::MakeResolvedDropColumnAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropColumnAction));
    return ret;
  }
  case googlesql::RESOLVED_RENAME_COLUMN_ACTION:{
    auto ret = googlesql::MakeResolvedRenameColumnAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRenameColumnAction));
    return ret;
  }
  case googlesql::RESOLVED_SET_AS_ACTION:{
    auto ret = googlesql::MakeResolvedSetAsAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSetAsAction));
    return ret;
  }
  case googlesql::RESOLVED_SET_COLLATE_CLAUSE:{
    auto ret = googlesql::MakeResolvedSetCollateClause();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSetCollateClause));
    return ret;
  }
  case googlesql::RESOLVED_GRANT_TO_ACTION:{
    auto ret = googlesql::MakeResolvedGrantToAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedGrantToAction));
    return ret;
  }
  case googlesql::RESOLVED_RESTRICT_TO_ACTION:{
    auto ret = googlesql::MakeResolvedRestrictToAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRestrictToAction));
    return ret;
  }
  case googlesql::RESOLVED_ADD_TO_RESTRICTEE_LIST_ACTION:{
    auto ret = googlesql::MakeResolvedAddToRestricteeListAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAddToRestricteeListAction));
    return ret;
  }
  case googlesql::RESOLVED_REMOVE_FROM_RESTRICTEE_LIST_ACTION:{
    auto ret = googlesql::MakeResolvedRemoveFromRestricteeListAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRemoveFromRestricteeListAction));
    return ret;
  }
  case googlesql::RESOLVED_FILTER_USING_ACTION:{
    auto ret = googlesql::MakeResolvedFilterUsingAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedFilterUsingAction));
    return ret;
  }
  case googlesql::RESOLVED_REVOKE_FROM_ACTION:{
    auto ret = googlesql::MakeResolvedRevokeFromAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRevokeFromAction));
    return ret;
  }
  case googlesql::RESOLVED_RENAME_TO_ACTION:{
    auto ret = googlesql::MakeResolvedRenameToAction();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRenameToAction));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const googlesql::ResolvedConstraint> make_unique_constraint(void *arg)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case googlesql::RESOLVED_PRIMARY_KEY:{
    auto ret = googlesql::MakeResolvedPrimaryKey();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedPrimaryKey));
    return ret;
  }
  case googlesql::RESOLVED_FOREIGN_KEY:{
    auto ret = googlesql::MakeResolvedForeignKey();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedForeignKey));
    return ret;
  }
  case googlesql::RESOLVED_CHECK_CONSTRAINT:{
    auto ret = googlesql::MakeResolvedCheckConstraint();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCheckConstraint));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const googlesql::ResolvedExpr> make_unique_expr(void *arg)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case googlesql::RESOLVED_LITERAL: {
    std::unique_ptr<googlesql::ResolvedLiteral> ret = googlesql::MakeResolvedLiteral();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedLiteral));
    return ret;
  }
  case googlesql::RESOLVED_PARAMETER:{
    std::unique_ptr<googlesql::ResolvedParameter> ret = googlesql::MakeResolvedParameter();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedParameter));
    return ret;
  }
  case googlesql::RESOLVED_EXPRESSION_COLUMN:{
    std::unique_ptr<googlesql::ResolvedExpressionColumn> ret = googlesql::MakeResolvedExpressionColumn();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedExpressionColumn));
    return ret;
  }
  case googlesql::RESOLVED_COLUMN_REF:{
    std::unique_ptr<googlesql::ResolvedColumnRef> ret = googlesql::MakeResolvedColumnRef();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedColumnRef));
    return ret;
  }
  case googlesql::RESOLVED_CONSTANT:{
    std::unique_ptr<googlesql::ResolvedConstant> ret = googlesql::MakeResolvedConstant();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedConstant));
    return ret;
  }
  case googlesql::RESOLVED_SYSTEM_VARIABLE:{
    std::unique_ptr<googlesql::ResolvedSystemVariable> ret = googlesql::MakeResolvedSystemVariable();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSystemVariable));
    return ret;
  }
  case googlesql::RESOLVED_FILTER_FIELD:{
    std::unique_ptr<googlesql::ResolvedFilterField> ret = googlesql::MakeResolvedFilterField();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedFilterField));
    return ret;
  }
  case googlesql::RESOLVED_FUNCTION_CALL:{
#if 0
    auto call = (googlesql::ResolvedFunctionCall *)node;
    return googlesql::MakeResolvedFunctionCall(
        call->type(),
        call->function(),
        call->signature(),
        call->argument_list(),
        call->generic_argument_list(),
        call->error_mode(),
        call->function_call_info()
    );
#endif
    break;
  }
  case googlesql::RESOLVED_AGGREGATE_FUNCTION_CALL:{
#if 0
    auto call = (googlesql::ResolvedAggregateFunctionCall *)node;
    return googlesql::MakeResolvedAggregateFunctionCall(
        call->type(),
        call->function(),
        call->signature(),
        call->argument_list(),
        call->generic_argument_list(),
        call->error_mode(),
        call->distinct(),
        call->null_handling_modifier(),
        call->having_modifier(),
        call->order_by_item_list(),
        call->limit(),
        call->function_call_info()
    );
#endif
    break;
  }
  case googlesql::RESOLVED_ANALYTIC_FUNCTION_CALL:{
#if 0
    auto call = (googlesql::ResolvedAnalyticFunctionCall *)node;
    return googlesql::MakeResolvedAnalyticFunctionCall(
        call->type(),
        call->function(),
        call->signature(),
        call->argument_list(),
        call->generic_argument_list(),
        call->error_mode(),
        call->distinct(),
        call->null_handling_modifier(),
        call->window_frame()
    );
#endif
    break;
  }
  case googlesql::RESOLVED_CAST:{
    std::unique_ptr<googlesql::ResolvedCast> ret = googlesql::MakeResolvedCast();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCast));
    return ret;
  }
  case googlesql::RESOLVED_MAKE_STRUCT:{
    std::unique_ptr<googlesql::ResolvedMakeStruct> ret = googlesql::MakeResolvedMakeStruct();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedMakeStruct));
    return ret;
  }
  case googlesql::RESOLVED_MAKE_PROTO:{
    std::unique_ptr<googlesql::ResolvedMakeProto> ret = googlesql::MakeResolvedMakeProto();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedMakeProto));
    return ret;
  }
  case googlesql::RESOLVED_GET_STRUCT_FIELD:{
    std::unique_ptr<googlesql::ResolvedGetStructField> ret = googlesql::MakeResolvedGetStructField();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedGetStructField));
    return ret;
  }
  case googlesql::RESOLVED_GET_PROTO_FIELD:{
    std::unique_ptr<googlesql::ResolvedGetProtoField> ret = googlesql::MakeResolvedGetProtoField();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedGetProtoField));
    return ret;
  }
  case googlesql::RESOLVED_GET_JSON_FIELD:{
    std::unique_ptr<googlesql::ResolvedGetJsonField> ret = googlesql::MakeResolvedGetJsonField();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedGetJsonField));
    return ret;
  }
  case googlesql::RESOLVED_FLATTEN:{
    std::unique_ptr<googlesql::ResolvedFlatten> ret = googlesql::MakeResolvedFlatten();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedFlatten));
    return ret;
  }
  case googlesql::RESOLVED_FLATTENED_ARG:{
    std::unique_ptr<googlesql::ResolvedFlattenedArg> ret = googlesql::MakeResolvedFlattenedArg();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedFlattenedArg));
    return ret;
  }
  case googlesql::RESOLVED_REPLACE_FIELD:{
    std::unique_ptr<googlesql::ResolvedReplaceField> ret = googlesql::MakeResolvedReplaceField();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedReplaceField));
    return ret;
  }
  case googlesql::RESOLVED_SUBQUERY_EXPR:{
    std::unique_ptr<googlesql::ResolvedSubqueryExpr> ret = googlesql::MakeResolvedSubqueryExpr();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSubqueryExpr));
    return ret;
  }
  case googlesql::RESOLVED_DMLDEFAULT:{
    std::unique_ptr<googlesql::ResolvedDMLDefault> ret = googlesql::MakeResolvedDMLDefault();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDMLDefault));
    return ret;
  }
  case googlesql::RESOLVED_ARGUMENT_REF:{
    std::unique_ptr<googlesql::ResolvedArgumentRef> ret = googlesql::MakeResolvedArgumentRef();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedArgumentRef));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const googlesql::ResolvedStatement> make_unique_stmt(void *arg)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case googlesql::RESOLVED_EXPLAIN_STMT:{
    std::unique_ptr<googlesql::ResolvedExplainStmt> ret = googlesql::MakeResolvedExplainStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedExplainStmt));
    return ret;
  }
  case googlesql::RESOLVED_QUERY_STMT:{
    std::unique_ptr<googlesql::ResolvedQueryStmt> ret = googlesql::MakeResolvedQueryStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedQueryStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_DATABASE_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateDatabaseStmt> ret = googlesql::MakeResolvedCreateDatabaseStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateDatabaseStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_INDEX_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateIndexStmt> ret = googlesql::MakeResolvedCreateIndexStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateIndexStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_SCHEMA_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateSchemaStmt> ret = googlesql::MakeResolvedCreateSchemaStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateSchemaStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_TABLE_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateTableStmt> ret = googlesql::MakeResolvedCreateTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateTableStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_TABLE_AS_SELECT_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateTableAsSelectStmt> ret = googlesql::MakeResolvedCreateTableAsSelectStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateTableAsSelectStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_MODEL_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateModelStmt> ret = googlesql::MakeResolvedCreateModelStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateModelStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_VIEW_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateViewStmt> ret = googlesql::MakeResolvedCreateViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateViewStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_SNAPSHOT_TABLE_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateSnapshotTableStmt> ret = googlesql::MakeResolvedCreateSnapshotTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateSnapshotTableStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_EXTERNAL_TABLE_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateExternalTableStmt> ret = googlesql::MakeResolvedCreateExternalTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateExternalTableStmt));
    return ret;
  }
  case googlesql::RESOLVED_EXPORT_MODEL_STMT:{
    std::unique_ptr<googlesql::ResolvedExportModelStmt> ret = googlesql::MakeResolvedExportModelStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedExportModelStmt));
    return ret;
  }
  case googlesql::RESOLVED_EXPORT_DATA_STMT:{
    std::unique_ptr<googlesql::ResolvedExportDataStmt> ret = googlesql::MakeResolvedExportDataStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedExportDataStmt));
    return ret;
  }
  case googlesql::RESOLVED_DEFINE_TABLE_STMT:{
    std::unique_ptr<googlesql::ResolvedDefineTableStmt> ret = googlesql::MakeResolvedDefineTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDefineTableStmt));
    return ret;
  }
  case googlesql::RESOLVED_DESCRIBE_STMT:{
    std::unique_ptr<googlesql::ResolvedDescribeStmt> ret = googlesql::MakeResolvedDescribeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDescribeStmt));
    return ret;
  }
  case googlesql::RESOLVED_SHOW_STMT:{
    std::unique_ptr<googlesql::ResolvedShowStmt> ret = googlesql::MakeResolvedShowStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedShowStmt));
    return ret;
  }
  case googlesql::RESOLVED_BEGIN_STMT:{
    std::unique_ptr<googlesql::ResolvedBeginStmt> ret = googlesql::MakeResolvedBeginStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedBeginStmt));
    return ret;
  }
  case googlesql::RESOLVED_SET_TRANSACTION_STMT:{
    std::unique_ptr<googlesql::ResolvedSetTransactionStmt> ret = googlesql::MakeResolvedSetTransactionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSetTransactionStmt));
    return ret;
  }
  case googlesql::RESOLVED_COMMIT_STMT:{
    std::unique_ptr<googlesql::ResolvedCommitStmt> ret = googlesql::MakeResolvedCommitStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCommitStmt));
    return ret;
  }
  case googlesql::RESOLVED_ROLLBACK_STMT:{
    std::unique_ptr<googlesql::ResolvedRollbackStmt> ret = googlesql::MakeResolvedRollbackStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRollbackStmt));
    return ret;
  }
  case googlesql::RESOLVED_START_BATCH_STMT:{
    std::unique_ptr<googlesql::ResolvedStartBatchStmt> ret = googlesql::MakeResolvedStartBatchStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedStartBatchStmt));
    return ret;
  }
  case googlesql::RESOLVED_RUN_BATCH_STMT:{
    std::unique_ptr<googlesql::ResolvedRunBatchStmt> ret = googlesql::MakeResolvedRunBatchStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRunBatchStmt));
    return ret;
  }
  case googlesql::RESOLVED_ABORT_BATCH_STMT:{
    std::unique_ptr<googlesql::ResolvedAbortBatchStmt> ret = googlesql::MakeResolvedAbortBatchStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAbortBatchStmt));
    return ret;
  }
  case googlesql::RESOLVED_DROP_STMT:{
    std::unique_ptr<googlesql::ResolvedDropStmt> ret = googlesql::MakeResolvedDropStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropStmt));
    return ret;
  }
  case googlesql::RESOLVED_DROP_MATERIALIZED_VIEW_STMT:{
    std::unique_ptr<googlesql::ResolvedDropMaterializedViewStmt> ret = googlesql::MakeResolvedDropMaterializedViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropMaterializedViewStmt));
    return ret;
  }
  case googlesql::RESOLVED_DROP_SNAPSHOT_TABLE_STMT:{
    std::unique_ptr<googlesql::ResolvedDropSnapshotTableStmt> ret = googlesql::MakeResolvedDropSnapshotTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropSnapshotTableStmt));
    return ret;
  }
  case googlesql::RESOLVED_ASSERT_STMT:{
    std::unique_ptr<googlesql::ResolvedAssertStmt> ret = googlesql::MakeResolvedAssertStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAssertStmt));
    return ret;
  }
  case googlesql::RESOLVED_INSERT_STMT:{
    std::unique_ptr<googlesql::ResolvedInsertStmt> ret = googlesql::MakeResolvedInsertStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedInsertStmt));
    return ret;
  }
  case googlesql::RESOLVED_DELETE_STMT:{
    std::unique_ptr<googlesql::ResolvedDeleteStmt> ret = googlesql::MakeResolvedDeleteStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDeleteStmt));
    return ret;
  }
  case googlesql::RESOLVED_UPDATE_STMT:{
    std::unique_ptr<googlesql::ResolvedUpdateStmt> ret = googlesql::MakeResolvedUpdateStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedUpdateStmt));
    return ret;
  }
  case googlesql::RESOLVED_MERGE_STMT:{
    std::unique_ptr<googlesql::ResolvedMergeStmt> ret = googlesql::MakeResolvedMergeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedMergeStmt));
    return ret;
  }
  case googlesql::RESOLVED_TRUNCATE_STMT:{
    std::unique_ptr<googlesql::ResolvedTruncateStmt> ret = googlesql::MakeResolvedTruncateStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedTruncateStmt));
    return ret;
  }
  case googlesql::RESOLVED_GRANT_STMT:{
    std::unique_ptr<googlesql::ResolvedGrantStmt> ret = googlesql::MakeResolvedGrantStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedGrantStmt));
    return ret;
  }
  case googlesql::RESOLVED_REVOKE_STMT:{
    std::unique_ptr<googlesql::ResolvedRevokeStmt> ret = googlesql::MakeResolvedRevokeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRevokeStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_DATABASE_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterDatabaseStmt> ret = googlesql::MakeResolvedAlterDatabaseStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterDatabaseStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_MATERIALIZED_VIEW_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterMaterializedViewStmt> ret = googlesql::MakeResolvedAlterMaterializedViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterMaterializedViewStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_SCHEMA_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterSchemaStmt> ret = googlesql::MakeResolvedAlterSchemaStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterSchemaStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_TABLE_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterTableStmt> ret = googlesql::MakeResolvedAlterTableStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterTableStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_VIEW_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterViewStmt> ret = googlesql::MakeResolvedAlterViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterViewStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_TABLE_SET_OPTIONS_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterTableSetOptionsStmt> ret = googlesql::MakeResolvedAlterTableSetOptionsStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterTableSetOptionsStmt));
    return ret;
  }
  case googlesql::RESOLVED_RENAME_STMT:{
    std::unique_ptr<googlesql::ResolvedRenameStmt> ret = googlesql::MakeResolvedRenameStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRenameStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_PRIVILEGE_RESTRICTION_STMT:{
    std::unique_ptr<googlesql::ResolvedCreatePrivilegeRestrictionStmt> ret = googlesql::MakeResolvedCreatePrivilegeRestrictionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreatePrivilegeRestrictionStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_ROW_ACCESS_POLICY_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateRowAccessPolicyStmt> ret = googlesql::MakeResolvedCreateRowAccessPolicyStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateRowAccessPolicyStmt));
    return ret;
  }
  case googlesql::RESOLVED_DROP_PRIVILEGE_RESTRICTION_STMT:{
    std::unique_ptr<googlesql::ResolvedDropPrivilegeRestrictionStmt> ret = googlesql::MakeResolvedDropPrivilegeRestrictionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropPrivilegeRestrictionStmt));
    return ret;
  }
  case googlesql::RESOLVED_DROP_ROW_ACCESS_POLICY_STMT:{
    std::unique_ptr<googlesql::ResolvedDropRowAccessPolicyStmt> ret = googlesql::MakeResolvedDropRowAccessPolicyStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropRowAccessPolicyStmt));
    return ret;
  }
  case googlesql::RESOLVED_DROP_INDEX_STMT:{
    std::unique_ptr<googlesql::ResolvedDropIndexStmt> ret = googlesql::MakeResolvedDropIndexStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropIndexStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_PRIVILEGE_RESTRICTION_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterPrivilegeRestrictionStmt> ret = googlesql::MakeResolvedAlterPrivilegeRestrictionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterPrivilegeRestrictionStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_ROW_ACCESS_POLICY_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterRowAccessPolicyStmt> ret = googlesql::MakeResolvedAlterRowAccessPolicyStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterRowAccessPolicyStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_ALL_ROW_ACCESS_POLICIES_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterAllRowAccessPoliciesStmt> ret = googlesql::MakeResolvedAlterAllRowAccessPoliciesStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterAllRowAccessPoliciesStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_CONSTANT_STMT:{
#if 0
    std::unique_ptr<googlesql::ResolvedCreateConstantStmt> ret = googlesql::MakeResolvedCreateConstantStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateConstantStmt));
    return ret;
#endif
    break;
  }
  case googlesql::RESOLVED_CREATE_FUNCTION_STMT:{
#if 0
    auto stmt = (googlesql::ResolvedCreateFunctionStmt *)node;
    return googlesql::MakeResolvedCreateFunctionStmt(
        stmt->name_path(),
        stmt->create_scope(),
        stmt->has_explicit_return_type(),
        stmt->return_type(),
        stmt->argument_name_list(),
        stmt->signature(),
        stmt->is_aggregate(),
        stmt->language(),
        stmt->code(),
        stmt->aggregate_expression_list(),
        stmt->function_expression(),
        stmt->option_list(),
        stmt->sql_security(),
        stmt->determinism_level(),
        stmt->is_remote(),
        stmt->connection()
    );
#endif
    break;
  }
  case googlesql::RESOLVED_CREATE_TABLE_FUNCTION_STMT:{
#if 0
    std::unique_ptr<googlesql::ResolvedCreateTableFunctionStmt> ret = googlesql::MakeResolvedCreateTableFunctionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateTableFunctionStmt));
    return ret;
#endif
    break;
  }
  case googlesql::RESOLVED_DROP_FUNCTION_STMT:{
    std::unique_ptr<googlesql::ResolvedDropFunctionStmt> ret = googlesql::MakeResolvedDropFunctionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropFunctionStmt));
    return ret;
  }
  case googlesql::RESOLVED_DROP_TABLE_FUNCTION_STMT:{
    std::unique_ptr<googlesql::ResolvedDropTableFunctionStmt> ret = googlesql::MakeResolvedDropTableFunctionStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedDropTableFunctionStmt));
    return ret;
  }
  case googlesql::RESOLVED_CALL_STMT:{
#if 0
    std::unique_ptr<googlesql::ResolvedCallStmt> ret = googlesql::MakeResolvedCallStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCallStmt));
    return ret;
#endif
    break;
  }
  case googlesql::RESOLVED_IMPORT_STMT:{
    std::unique_ptr<googlesql::ResolvedImportStmt> ret = googlesql::MakeResolvedImportStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedImportStmt));
    return ret;
  }
  case googlesql::RESOLVED_MODULE_STMT:{
    std::unique_ptr<googlesql::ResolvedModuleStmt> ret = googlesql::MakeResolvedModuleStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedModuleStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_MATERIALIZED_VIEW_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateMaterializedViewStmt> ret = googlesql::MakeResolvedCreateMaterializedViewStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateMaterializedViewStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_PROCEDURE_STMT:{
#if 0
    std::unique_ptr<googlesql::ResolvedCreateProcedureStmt> ret = googlesql::MakeResolvedCreateProcedureStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateProcedureStmt));
    return ret;
#endif
    break;
  }
  case googlesql::RESOLVED_EXECUTE_IMMEDIATE_STMT:{
    std::unique_ptr<googlesql::ResolvedExecuteImmediateStmt> ret = googlesql::MakeResolvedExecuteImmediateStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedExecuteImmediateStmt));
    return ret;
  }
  case googlesql::RESOLVED_ASSIGNMENT_STMT:{
    std::unique_ptr<googlesql::ResolvedAssignmentStmt> ret = googlesql::MakeResolvedAssignmentStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAssignmentStmt));
    return ret;
  }
  case googlesql::RESOLVED_CREATE_ENTITY_STMT:{
    std::unique_ptr<googlesql::ResolvedCreateEntityStmt> ret = googlesql::MakeResolvedCreateEntityStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCreateEntityStmt));
    return ret;
  }
  case googlesql::RESOLVED_ALTER_ENTITY_STMT:{
    std::unique_ptr<googlesql::ResolvedAlterEntityStmt> ret = googlesql::MakeResolvedAlterEntityStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAlterEntityStmt));
    return ret;
  }
  case googlesql::RESOLVED_CLONE_DATA_STMT:{
    std::unique_ptr<googlesql::ResolvedCloneDataStmt> ret = googlesql::MakeResolvedCloneDataStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedCloneDataStmt));
    return ret;
  }
  case googlesql::RESOLVED_ANALYZE_STMT:{
    std::unique_ptr<googlesql::ResolvedAnalyzeStmt> ret = googlesql::MakeResolvedAnalyzeStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAnalyzeStmt));
    return ret;
  }
  case googlesql::RESOLVED_AUX_LOAD_DATA_STMT:{
    std::unique_ptr<googlesql::ResolvedAuxLoadDataStmt> ret = googlesql::MakeResolvedAuxLoadDataStmt();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAuxLoadDataStmt));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

static std::unique_ptr<const googlesql::ResolvedScan> make_unique_scan(void *arg)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg;
  switch (node->node_kind()) {
  case googlesql::RESOLVED_SINGLE_ROW_SCAN:{
    std::unique_ptr<googlesql::ResolvedSingleRowScan> ret = googlesql::MakeResolvedSingleRowScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSingleRowScan));
    return ret;
  }
  case googlesql::RESOLVED_TABLE_SCAN:{
    std::unique_ptr<googlesql::ResolvedTableScan> ret = googlesql::MakeResolvedTableScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedTableScan));
    return ret;
  }
  case googlesql::RESOLVED_JOIN_SCAN:{
    std::unique_ptr<googlesql::ResolvedJoinScan> ret = googlesql::MakeResolvedJoinScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedJoinScan));
    return ret;
  }
  case googlesql::RESOLVED_ARRAY_SCAN:{
    std::unique_ptr<googlesql::ResolvedArrayScan> ret = googlesql::MakeResolvedArrayScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedArrayScan));
    return ret;
  }
  case googlesql::RESOLVED_FILTER_SCAN:{
    std::unique_ptr<googlesql::ResolvedFilterScan> ret = googlesql::MakeResolvedFilterScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedFilterScan));
    return ret;
  }
  case googlesql::RESOLVED_AGGREGATE_SCAN:{
    std::unique_ptr<googlesql::ResolvedAggregateScan> ret = googlesql::MakeResolvedAggregateScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAggregateScan));
    return ret;
  }
  case googlesql::RESOLVED_ANONYMIZED_AGGREGATE_SCAN:{
    std::unique_ptr<googlesql::ResolvedAnonymizedAggregateScan> ret = googlesql::MakeResolvedAnonymizedAggregateScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAnonymizedAggregateScan));
    return ret;
  }
  case googlesql::RESOLVED_SET_OPERATION_SCAN:{
    std::unique_ptr<googlesql::ResolvedSetOperationScan> ret = googlesql::MakeResolvedSetOperationScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSetOperationScan));
    return ret;
  }
  case googlesql::RESOLVED_ORDER_BY_SCAN:{
    std::unique_ptr<googlesql::ResolvedOrderByScan> ret = googlesql::MakeResolvedOrderByScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedOrderByScan));
    return ret;
  }
  case googlesql::RESOLVED_LIMIT_OFFSET_SCAN:{
    std::unique_ptr<googlesql::ResolvedLimitOffsetScan> ret = googlesql::MakeResolvedLimitOffsetScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedLimitOffsetScan));
    return ret;
  }
  case googlesql::RESOLVED_WITH_REF_SCAN:{
    std::unique_ptr<googlesql::ResolvedWithRefScan> ret = googlesql::MakeResolvedWithRefScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedWithRefScan));
    return ret;
  }
  case googlesql::RESOLVED_ANALYTIC_SCAN:{
    std::unique_ptr<googlesql::ResolvedAnalyticScan> ret = googlesql::MakeResolvedAnalyticScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedAnalyticScan));
    return ret;
  }
  case googlesql::RESOLVED_SAMPLE_SCAN:{
    std::unique_ptr<googlesql::ResolvedSampleScan> ret = googlesql::MakeResolvedSampleScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedSampleScan));
    return ret;
  }
  case googlesql::RESOLVED_PROJECT_SCAN:{
    std::unique_ptr<googlesql::ResolvedProjectScan> ret = googlesql::MakeResolvedProjectScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedProjectScan));
    return ret;
  }
  case googlesql::RESOLVED_TVFSCAN:{
    auto scan = (googlesql::ResolvedTVFScan *)arg;
    std::vector<std::unique_ptr<const googlesql::ResolvedFunctionArgument>> argument_list;
    for (int i = 0; i < scan->argument_list_size(); i++) {
      auto a = googlesql::MakeResolvedFunctionArgument();
      memcpy((void *)a.get(), (void *)scan->argument_list(i), sizeof(googlesql::ResolvedFunctionArgument));
      argument_list.push_back(std::move(a));
    }
    return googlesql::MakeResolvedTVFScan(
      scan->column_list(),
      scan->tvf(),
      scan->signature(),
      std::move(argument_list),
      scan->column_index_list(),
      scan->alias(),
      scan->function_call_signature()
    );
  }
  case googlesql::RESOLVED_GROUP_ROWS_SCAN:{
    auto scan = (googlesql::ResolvedGroupRowsScan *)arg;
    std::vector<std::unique_ptr<const googlesql::ResolvedComputedColumn>> input_column_list;
    for (int i = 0; i < scan->input_column_list_size(); i++) {
      auto col = googlesql::MakeResolvedComputedColumn();
      memcpy((void *)col.get(), (void *)scan->input_column_list(i), sizeof(googlesql::ResolvedComputedColumn));
      input_column_list.push_back(std::move(col));
    }
    return googlesql::MakeResolvedGroupRowsScan(
      scan->column_list(),
      std::move(input_column_list),
      scan->alias()
    );
  }
  case googlesql::RESOLVED_RECURSIVE_REF_SCAN:{
    std::unique_ptr<googlesql::ResolvedRecursiveRefScan> ret = googlesql::MakeResolvedRecursiveRefScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRecursiveRefScan));
    return ret;
  }
  case googlesql::RESOLVED_RECURSIVE_SCAN:{
    std::unique_ptr<googlesql::ResolvedRecursiveScan> ret = googlesql::MakeResolvedRecursiveScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRecursiveScan));
    return ret;
  }
  case googlesql::RESOLVED_WITH_SCAN:{
    std::unique_ptr<googlesql::ResolvedWithScan> ret = googlesql::MakeResolvedWithScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedWithScan));
    return ret;
  }
  case googlesql::RESOLVED_RELATION_ARGUMENT_SCAN:{
    std::unique_ptr<googlesql::ResolvedRelationArgumentScan> ret = googlesql::MakeResolvedRelationArgumentScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedRelationArgumentScan));
    return ret;
  }
  case googlesql::RESOLVED_PIVOT_SCAN:{
    std::unique_ptr<googlesql::ResolvedPivotScan> ret = googlesql::MakeResolvedPivotScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedPivotScan));
    return ret;
  }
  case googlesql::RESOLVED_UNPIVOT_SCAN:{
    std::unique_ptr<googlesql::ResolvedUnpivotScan> ret = googlesql::MakeResolvedUnpivotScan();
    memcpy((void *)ret.get(), (void *)node, sizeof(googlesql::ResolvedUnpivotScan));
    return ret;
  }
  default:
    break;
  }
  return nullptr;
}

void GO_EXPORT(LanguageOptions_new)(void ** arg0){
  *arg0 = (void *)(new googlesql::LanguageOptions());
}

void GO_EXPORT(LanguageOptions_SupportsStatementKind)(void * arg0,int arg1,char* arg2){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg2 = opt->SupportsStatementKind((googlesql::ResolvedNodeKind)arg1);
}

void GO_EXPORT(LanguageOptions_SetSupportedStatementKinds)(void * arg0,void * arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  std::set<googlesql::ResolvedNodeKind> kinds;
  GoSlice *goslice = (GoSlice *)arg1;
  void **data = (void **)goslice->data;
  for (int i = 0; i < goslice->len; i++) {
    kinds.insert((googlesql::ResolvedNodeKind)(uintptr_t)data[i]);
  }
  opt->SetSupportedStatementKinds(kinds);
}

void GO_EXPORT(LanguageOptions_SetSupportsAllStatementKinds)(void * arg0){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->SetSupportsAllStatementKinds();
}

void GO_EXPORT(LanguageOptions_AddSupportedStatementKind)(void * arg0,int arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->AddSupportedStatementKind((googlesql::ResolvedNodeKind)arg1);
}

void GO_EXPORT(LanguageOptions_LanguageFeatureEnabled)(void * arg0,int arg1,char* arg2){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg2 = opt->LanguageFeatureEnabled((googlesql::LanguageFeature)arg1);
}

void GO_EXPORT(LanguageOptions_SetLanguageVersion)(void * arg0,int arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->SetLanguageVersion((googlesql::LanguageVersion)arg1);
}

void GO_EXPORT(LanguageOptions_EnableLanguageFeature)(void * arg0,int arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->EnableLanguageFeature((googlesql::LanguageFeature)arg1);
}

void GO_EXPORT(LanguageOptions_SetEnabledLanguageFeatures)(void * arg0,void * arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  googlesql::LanguageOptions::LanguageFeatureSet features;
  GoSlice *goslice = (GoSlice *)arg1;
  void **data = (void **)goslice->data;
  for (int i = 0; i < goslice->len; i++) {
    features.insert((googlesql::LanguageFeature)(uintptr_t)data[i]);
  }
  opt->SetEnabledLanguageFeatures(features);
}

void GO_EXPORT(LanguageOptions_EnabledLanguageFeatures)(void * arg0,void ** arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  auto features = opt->GetEnabledLanguageFeatures();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  int *data = (int *)malloc(sizeof(int) * features.size());
  int i = 0;
  for (auto it = features.begin(); it != features.end(); it++, i++) {
    data[i] = *it;
  }
  slice->data = (void *)data;
  slice->len = features.size();
  slice->cap = features.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(LanguageOptions_EnabledLanguageFeaturesAsString)(void * arg0,void ** arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg1 = (void *)((new std::string(opt->GetEnabledLanguageFeaturesAsString()))->c_str());
}

void GO_EXPORT(LanguageOptions_DisableAllLanguageFeatures)(void * arg0){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->DisableAllLanguageFeatures();
}

void GO_EXPORT(LanguageOptions_EnableMaximumLanguageFeatures)(void * arg0){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->EnableMaximumLanguageFeatures();
}

void GO_EXPORT(LanguageOptions_EnableMaximumLanguageFeaturesForDevelopment)(void * arg0){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->EnableMaximumLanguageFeaturesForDevelopment();
}

void GO_EXPORT(LanguageOptions_set_name_resolution_mode)(void * arg0,int arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->set_name_resolution_mode((googlesql::NameResolutionMode)arg1);
}

void GO_EXPORT(LanguageOptions_name_resolution_mode)(void * arg0,int* arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg1 = opt->name_resolution_mode();
}

void GO_EXPORT(LanguageOptions_set_product_mode)(void * arg0,int arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->set_product_mode((googlesql::ProductMode)arg1);
}

void GO_EXPORT(LanguageOptions_product_mode)(void * arg0,int* arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg1 = opt->product_mode();
}

void GO_EXPORT(LanguageOptions_SupportsProtoTypes)(void * arg0,char* arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg1 = opt->SupportsProtoTypes();
}

void GO_EXPORT(LanguageOptions_set_error_on_deprecated_syntax)(void * arg0,int arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->set_error_on_deprecated_syntax(arg1);
}

void GO_EXPORT(LanguageOptions_error_on_deprecated_syntax)(void * arg0,char* arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg1 = opt->error_on_deprecated_syntax();
}

void GO_EXPORT(LanguageOptions_SetSupportedGenericEntityTypes)(void * arg0,void * arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  SET_LIST(opt->SetSupportedGenericEntityTypes, std::string, arg1);
}

void GO_EXPORT(LanguageOptions_GenericEntityTypeSupported)(void * arg0,void * arg1,char* arg2){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg2 = opt->GenericEntityTypeSupported((char *)arg1);
}

void GO_EXPORT(LanguageOptions_IsReservedKeyword)(void * arg0,void * arg1,char* arg2){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg2 = opt->IsReservedKeyword((char *)arg1);
}

void GO_EXPORT(LanguageOptions_EnableReservableKeyword)(void * arg0,void * arg1,int arg2,void ** arg3){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->EnableReservableKeyword((char *)arg1, arg2)));
}

void GO_EXPORT(LanguageOptions_EnableAllReservableKeywords)(void * arg0,int arg1){
  googlesql::LanguageOptions *opt = (googlesql::LanguageOptions *)arg0;
  opt->EnableAllReservableKeywords(arg1);
}

void GO_EXPORT(AnalyzerOptions_new)(void ** arg0){
  *arg0 = (void *)(new googlesql::AnalyzerOptions());
}

void GO_EXPORT(AnalyzerOptions_language)(void * arg0,void ** arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = (void *)(new googlesql::LanguageOptions(opt->language()));
}

void GO_EXPORT(AnalyzerOptions_set_language)(void * arg0,void * arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_language(*(googlesql::LanguageOptions *)arg1);
}

void GO_EXPORT(AnalyzerOptions_AddQueryParameter)(void * arg0,void * arg1,void * arg2,void ** arg3){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->AddQueryParameter((char *)arg1, (const googlesql::Type *)arg2)));
}

typedef struct {
  void *name;
  void *type;
} query_param_t;

void GO_EXPORT(AnalyzerOptions_query_parameters)(void * arg0,void ** arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  auto params = opt->query_parameters();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * params.size());
  int idx = 0;
  for (auto it = params.begin(); it != params.end(); it++) {
    query_param_t *param = (query_param_t *)malloc(sizeof(query_param_t));
    param->name = (void *)((new std::string(it->first))->c_str());
    param->type = (void *)it->second;
    data[idx] = (void *)param;
  }
  slice->data = data;
  slice->cap = params.size();
  slice->len = params.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(AnalyzerOptions_clear_query_parameters)(void * arg0){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->clear_query_parameters();
}

void GO_EXPORT(AnalyzerOptions_AddPositionalQueryParameter)(void * arg0,void * arg1,void ** arg2){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg2 = (void *)(new absl::Status(opt->AddPositionalQueryParameter((const googlesql::Type *)arg1)));
}

void GO_EXPORT(AnalyzerOptions_positional_query_parameters)(void * arg0,void ** arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  auto params = opt->positional_query_parameters();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * params.size());
  for (int i = 0; i < params.size(); i++) {
    data[i] = (void *)params[i];
  }
  slice->data = data;
  slice->cap = params.size();
  slice->len = params.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(AnalyzerOptions_clear_positional_query_parameters)(void * arg0){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->clear_positional_query_parameters();
}

void GO_EXPORT(AnalyzerOptions_AddExpressionColumn)(void * arg0,void * arg1,void * arg2,void ** arg3){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->AddExpressionColumn((char *)arg1, (const googlesql::Type *)arg2)));
}

void GO_EXPORT(AnalyzerOptions_SetInScopeExpressionColumn)(void * arg0,void * arg1,void * arg2,void ** arg3){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg3 = (void *)(new absl::Status(opt->SetInScopeExpressionColumn((char *)arg1, (const googlesql::Type *)arg2)));
}

void GO_EXPORT(AnalyzerOptions_expression_columns)(void * arg0,void ** arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  auto columns = opt->expression_columns();
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  void **data = (void **)malloc(sizeof(void *) * columns.size());
  int idx = 0;
  for (auto it = columns.begin(); it != columns.end(); it++) {
    query_param_t *param = (query_param_t *)malloc(sizeof(query_param_t));
    param->name = (void *)((new std::string(it->first))->c_str());
    param->type = (void *)it->second;
    data[idx] = (void *)param;
  }
  slice->data = data;
  slice->cap = columns.size();
  slice->len = columns.size();
  *arg1 = (void *)slice;
}

void GO_EXPORT(AnalyzerOptions_has_in_scope_expression_column)(void * arg0,char* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->has_in_scope_expression_column();
}

void GO_EXPORT(AnalyzerOptions_in_scope_expression_column_name)(void * arg0,void ** arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = (void *)((new std::string(opt->in_scope_expression_column_name()))->c_str());
}

void GO_EXPORT(AnalyzerOptions_in_scope_expression_column_type)(void * arg0,void ** arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = (void *)opt->in_scope_expression_column_type();
}

void GO_EXPORT(AnalyzerOptions_set_error_message_mode)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_error_message_mode((googlesql::ErrorMessageMode)arg1);
}

void GO_EXPORT(AnalyzerOptions_error_message_mode)(void * arg0,int* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->error_message_mode();
}

void GO_EXPORT(AnalyzerOptions_set_statement_context)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_statement_context((googlesql::StatementContext)arg1);
}

void GO_EXPORT(AnalyzerOptions_statement_context)(void * arg0,int* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->statement_context();
}

void GO_EXPORT(AnalyzerOptions_set_parse_location_record_type)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_parse_location_record_type((googlesql::ParseLocationRecordType)arg1);
}

void GO_EXPORT(AnalyzerOptions_parse_location_record_type)(void * arg0,int* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->parse_location_record_type();
}

void GO_EXPORT(AnalyzerOptions_set_create_new_column_for_each_projected_output)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_create_new_column_for_each_projected_output(arg1);
}

void GO_EXPORT(AnalyzerOptions_create_new_column_for_each_projected_output)(void * arg0,char* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->create_new_column_for_each_projected_output();
}

void GO_EXPORT(AnalyzerOptions_set_allow_undeclared_parameters)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_allow_undeclared_parameters(arg1);
}

void GO_EXPORT(AnalyzerOptions_allow_undeclared_parameters)(void * arg0,char* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->allow_undeclared_parameters();
}

void GO_EXPORT(AnalyzerOptions_set_parameter_mode)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_parameter_mode((googlesql::ParameterMode)arg1);
}

void GO_EXPORT(AnalyzerOptions_parameter_mode)(void * arg0,int* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->parameter_mode();
}

void GO_EXPORT(AnalyzerOptions_set_prune_unused_columns)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_prune_unused_columns(arg1);
}

void GO_EXPORT(AnalyzerOptions_prune_unused_columns)(void * arg0,char* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->prune_unused_columns();
}

void GO_EXPORT(AnalyzerOptions_set_preserve_column_aliases)(void * arg0,int arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  opt->set_preserve_column_aliases(arg1);
}

void GO_EXPORT(AnalyzerOptions_preserve_column_aliases)(void * arg0,char* arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = opt->preserve_column_aliases();
}

void GO_EXPORT(AnalyzerOptions_GetParserOptions)(void * arg0,void ** arg1)
{
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = (void *)(new googlesql::ParserOptions(opt->GetParserOptions()));
}

void GO_EXPORT(ValidateAnalyzerOptions)(void * arg0,void ** arg1){
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg0;
  *arg1 = (void *)(new absl::Status(googlesql::ValidateAnalyzerOptions(*opt)));
}

void GO_EXPORT(AnalyzeStatement)(void * arg0,void * arg1,void * arg2,void ** arg3,void ** arg4){
  std::unique_ptr<const googlesql::AnalyzerOutput> out;
  auto typeFactory = new googlesql::TypeFactory(); // FIXME: typeFactory will be leaked.
  absl::Status ret = googlesql::AnalyzeStatement(
    (char *)arg0,
    *(googlesql::AnalyzerOptions *)arg1,
    (googlesql::Catalog *)arg2,
    typeFactory,
    &out
  );
  *(std::unique_ptr<const googlesql::AnalyzerOutput> *)arg3 = std::move(out);
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzeNextStatement)(void * arg0,void * arg1,void * arg2,void ** arg3,char* arg4,void ** arg5)
{
  auto typeFactory = new googlesql::TypeFactory(); // FIXME: typeFactory will be leaked.
  googlesql::ParseResumeLocation *loc = (googlesql::ParseResumeLocation *)arg0;
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg1;
  googlesql::Catalog *cat = (googlesql::Catalog *)arg2;
  std::unique_ptr<const googlesql::AnalyzerOutput> out;
  bool endOfInput;
  absl::Status ret = googlesql::AnalyzeNextStatement(loc, *opt, cat, typeFactory, &out, &endOfInput);
  *(std::unique_ptr<const googlesql::AnalyzerOutput> *)arg3 = std::move(out);
  *arg4 = endOfInput;
  *arg5 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzeExpression)(void * arg0,void * arg1,void * arg2,void ** arg3,void ** arg4)
{
  auto typeFactory = new googlesql::TypeFactory(); // FIXME: typeFactory will be leaked.
  googlesql::AnalyzerOptions *opt = (googlesql::AnalyzerOptions *)arg1;
  googlesql::Catalog *cat = (googlesql::Catalog *)arg2;
  std::unique_ptr<const googlesql::AnalyzerOutput> out;
  absl::Status ret = googlesql::AnalyzeExpression((char *)arg0, *opt, cat, typeFactory, &out);
  *(std::unique_ptr<const googlesql::AnalyzerOutput> *)arg3 = std::move(out);
  *arg4 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzeStatementFromParserAST)(void * arg0,void * arg1,void * arg2,void * arg3,void ** arg4,void ** arg5)
{
  std::unique_ptr<const googlesql::AnalyzerOutput> out;
  auto typeFactory = new googlesql::TypeFactory(); // FIXME: typeFactory will be leaked.
  absl::Status ret = googlesql::AnalyzeStatementFromParserAST(
    *(googlesql::ASTStatement *)arg0,
    *(googlesql::AnalyzerOptions *)arg1,
    (char *)arg2,
    (googlesql::Catalog *)arg3,
    typeFactory,
    &out
  );
  *(std::unique_ptr<const googlesql::AnalyzerOutput> *)arg4 = std::move(out);
  *arg5 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(AnalyzerOutput_resolved_statement)(void * arg0,void ** arg1)
{
  googlesql::AnalyzerOutput *out = (googlesql::AnalyzerOutput *)arg0;
  *arg1 = (void *)out->resolved_statement();
}

void GO_EXPORT(ResolvedNode_node_kind)(void * arg0,int* arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  *arg1 = node->node_kind();
}

void GO_EXPORT(ResolvedNode_IsScan)(void * arg0,char* arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  *arg1 = node->IsScan();
}

void GO_EXPORT(ResolvedNode_IsExpression)(void * arg0,char* arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  *arg1 = node->IsExpression();
}

void GO_EXPORT(ResolvedNode_IsStatement)(void * arg0,char* arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  *arg1 = node->IsStatement();
}

void GO_EXPORT(ResolvedNode_DebugString)(void * arg0,void ** arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  *arg1 = (void *)((new std::string(node->DebugString()))->c_str());
}

void GO_EXPORT(ResolvedNode_GetChildNodes_num)(void * arg0,int* arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  std::vector<const googlesql::ResolvedNode *> child_nodes;
  node->GetChildNodes(&child_nodes);
  *arg1 = child_nodes.size();
}

void GO_EXPORT(ResolvedNode_GetChildNode)(void * arg0,int arg1,void ** arg2)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  std::vector<const googlesql::ResolvedNode *> child_nodes;
  node->GetChildNodes(&child_nodes);
  *arg2 = (void *)child_nodes[arg1];
}

void GO_EXPORT(ResolvedNode_GetParseLocationRangeOrNULL)(void * arg0,void ** arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  *arg1 = (void *)node->GetParseLocationRangeOrNULL();
}

void GO_EXPORT(ResolvedNode_GetTreeDepth)(void * arg0,int* arg1)
{
  googlesql::ResolvedNode *node = (googlesql::ResolvedNode *)arg0;
  *arg1 = node->GetTreeDepth();
}

void GO_EXPORT(ResolvedExpr_type)(void * arg0,void ** arg1)
{
  googlesql::ResolvedExpr *expr = (googlesql::ResolvedExpr *)arg0;
  *arg1 = (void *)expr->type();
}

void GO_EXPORT(ResolvedExpr_set_type)(void * arg0,void * arg1)
{
  googlesql::ResolvedExpr *expr = (googlesql::ResolvedExpr *)arg0;
  expr->set_type((googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedExpr_type_annotation_map)(void * arg0,void ** arg1)
{
  googlesql::ResolvedExpr *expr = (googlesql::ResolvedExpr *)arg0;
  *arg1 = (void *)expr->type_annotation_map();
}

void GO_EXPORT(ResolvedExpr_set_type_annotation_map)(void * arg0,void * arg1)
{
  googlesql::ResolvedExpr *expr = (googlesql::ResolvedExpr *)arg0;
  expr->set_type_annotation_map((googlesql::AnnotationMap *)arg1);
}

void GO_EXPORT(ResolvedLiteral_value)(void * arg0,void ** arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  *arg1 = (void *)(new googlesql::Value(node->value()));
}

void GO_EXPORT(ResolvedLiteral_set_value)(void * arg0,void * arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  node->set_value(*(googlesql::Value *)arg1);
}

void GO_EXPORT(ResolvedLiteral_has_explicit_type)(void * arg0,char* arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  *arg1 = node->has_explicit_type();
}

void GO_EXPORT(ResolvedLiteral_set_has_explicit_type)(void * arg0,int arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  node->set_has_explicit_type(arg1);
}

void GO_EXPORT(ResolvedLiteral_float_literal_id)(void * arg0,int* arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  *arg1 = node->float_literal_id();
}

void GO_EXPORT(ResolvedLiteral_set_float_literal_id)(void * arg0,int arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  node->set_float_literal_id(arg1);
}

void GO_EXPORT(ResolvedLiteral_preserve_in_literal_remover)(void * arg0,char* arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  *arg1 = node->preserve_in_literal_remover();
}

void GO_EXPORT(ResolvedLiteral_set_preserve_in_literal_remover)(void * arg0,int arg1)
{
  googlesql::ResolvedLiteral *node = (googlesql::ResolvedLiteral *)arg0;
  node->set_preserve_in_literal_remover(arg1);
}

void GO_EXPORT(ResolvedParameter_name)(void * arg0,void ** arg1)
{
  googlesql::ResolvedParameter *node = (googlesql::ResolvedParameter *)arg0;
  *arg1 = (void *)node->name().c_str();
}

void GO_EXPORT(ResolvedParameter_set_name)(void * arg0,void * arg1)
{
  googlesql::ResolvedParameter *node = (googlesql::ResolvedParameter *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedParameter_position)(void * arg0,int* arg1)
{
  googlesql::ResolvedParameter *node = (googlesql::ResolvedParameter *)arg0;
  *arg1 = node->position();
}

void GO_EXPORT(ResolvedParameter_set_position)(void * arg0,int arg1)
{
  googlesql::ResolvedParameter *node = (googlesql::ResolvedParameter *)arg0;
  node->set_position(arg1);
}

void GO_EXPORT(ResolvedParameter_is_untyped)(void * arg0,char* arg1)
{
  googlesql::ResolvedParameter *node = (googlesql::ResolvedParameter *)arg0;
  *arg1 = node->is_untyped();
}

void GO_EXPORT(ResolvedParameter_set_is_untyped)(void * arg0,int arg1)
{
  googlesql::ResolvedParameter *node = (googlesql::ResolvedParameter *)arg0;
  node->set_is_untyped(arg1);
}

void GO_EXPORT(ResolvedExpressionColumn_name)(void * arg0,void ** arg1)
{
  googlesql::ResolvedExpressionColumn *node = (googlesql::ResolvedExpressionColumn *)arg0;
  *arg1 = (void *)node->name().c_str();
}

void GO_EXPORT(ResolvedExpressionColumn_set_name)(void * arg0,void * arg1)
{
  googlesql::ResolvedExpressionColumn *node = (googlesql::ResolvedExpressionColumn *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedColumnRef_column)(void * arg0,void ** arg1)
{
  googlesql::ResolvedColumnRef *node = (googlesql::ResolvedColumnRef *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedColumnRef_set_column)(void * arg0,void * arg1)
{
  googlesql::ResolvedColumnRef *node = (googlesql::ResolvedColumnRef *)arg0;
  node->set_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedColumnRef_is_correlated)(void * arg0,char* arg1)
{
  googlesql::ResolvedColumnRef *node = (googlesql::ResolvedColumnRef *)arg0;
  *arg1 = node->is_correlated();
}

void GO_EXPORT(ResolvedColumnRef_set_is_correlated)(void * arg0,int arg1)
{
  googlesql::ResolvedColumnRef *node = (googlesql::ResolvedColumnRef *)arg0;
  node->set_is_correlated(arg1);
}

void GO_EXPORT(ResolvedConstant_constant)(void * arg0,void ** arg1)
{
  googlesql::ResolvedConstant *node = (googlesql::ResolvedConstant *)arg0;
  *arg1 = (void *)node->constant();
}

void GO_EXPORT(ResolvedConstant_set_constant)(void * arg0,void * arg1)
{
  googlesql::ResolvedConstant *node = (googlesql::ResolvedConstant *)arg0;
  node->set_constant((googlesql::Constant *)arg1);
}

void GO_EXPORT(ResolvedSystemVariable_name_path)(void * arg0,void ** arg1)
{
  googlesql::ResolvedSystemVariable *node = (googlesql::ResolvedSystemVariable *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedSystemVariable_set_name_path)(void * arg0,void * arg1)
{
  googlesql::ResolvedSystemVariable *node = (googlesql::ResolvedSystemVariable *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedSystemVariable_add_name_path)(void * arg0,void * arg1)
{
  googlesql::ResolvedSystemVariable *node = (googlesql::ResolvedSystemVariable *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedInlineLambda_argument_list)(void * arg0,void ** arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  GET_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_set_argument_list)(void * arg0,void * arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  SET_LIST(node->set_argument_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_add_argument)(void * arg0,void * arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  node->add_argument_list(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedInlineLambda_parameter_list)(void * arg0,void ** arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  GET_UNIQUE_PTR_LIST(node->parameter_list, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_set_parameter_list)(void * arg0,void * arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_add_parameter)(void * arg0,void * arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInlineLambda_body)(void * arg0,void ** arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  *arg1 = (void *)node->body();
}

void GO_EXPORT(ResolvedInlineLambda_set_body)(void * arg0,void * arg1)
{
  googlesql::ResolvedInlineLambda *node = (googlesql::ResolvedInlineLambda *)arg0;
  node->set_body(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFilterFieldArg_include)(void * arg0,char* arg1){
  googlesql::ResolvedFilterFieldArg *node = (googlesql::ResolvedFilterFieldArg *)arg0;
  *arg1 = node->include();
}

void GO_EXPORT(ResolvedFilterFieldArg_set_include)(void * arg0,int arg1){
  googlesql::ResolvedFilterFieldArg *node = (googlesql::ResolvedFilterFieldArg *)arg0;
  node->set_include(arg1);
}

void GO_EXPORT(ResolvedFilterField_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedFilterField *node = (googlesql::ResolvedFilterField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedFilterField_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedFilterField *node = (googlesql::ResolvedFilterField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFilterField_filter_field_arg_list)(void * arg0,void ** arg1){
  googlesql::ResolvedFilterField *node = (googlesql::ResolvedFilterField *)arg0;
  GET_UNIQUE_PTR_LIST(node->filter_field_arg_list, arg1);
}

void GO_EXPORT(ResolvedFilterField_set_filter_field_arg_list)(void * arg0,void * arg1){
  googlesql::ResolvedFilterField *node = (googlesql::ResolvedFilterField *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_filter_field_arg_list, ResolvedFilterFieldArg, arg1);
}

void GO_EXPORT(ResolvedFilterField_add_filter_field_arg_list)(void * arg0,void * arg1){
  googlesql::ResolvedFilterField *node = (googlesql::ResolvedFilterField *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_filter_field_arg_list, ResolvedFilterFieldArg, arg1);
}

void GO_EXPORT(ResolvedFilterField_reset_cleared_required_fields)(void * arg0,char* arg1){
  googlesql::ResolvedFilterField *node = (googlesql::ResolvedFilterField *)arg0;
  *arg1 = node->reset_cleared_required_fields();
}

void GO_EXPORT(ResolvedFilterField_set_reset_cleared_required_fields)(void * arg0,int arg1){
  googlesql::ResolvedFilterField *node = (googlesql::ResolvedFilterField *)arg0;
  node->set_reset_cleared_required_fields(arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_function)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  *arg1 = (void *)node->function();
}

void GO_EXPORT(ResolvedFunctionCallBase_set_function)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  node->set_function((const googlesql::Function *)arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  *arg1 = (void *)(new googlesql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedFunctionCallBase_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  node->set_signature(*(googlesql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_argument_list)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_generic_argument_list)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->generic_argument_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_generic_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_generic_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_generic_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_generic_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_error_mode)(void * arg0,int* arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  *arg1 = node->error_mode();
}

void GO_EXPORT(ResolvedFunctionCallBase_set_error_mode)(void * arg0,int arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  node->set_error_mode((googlesql::ResolvedFunctionCallBase::ErrorMode)arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_hint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_collation_list)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  GET_LIST(node->collation_list, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_set_collation_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  SET_LIST(node->set_collation_list, googlesql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedFunctionCallBase_add_collation_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCallBase *node = (googlesql::ResolvedFunctionCallBase *)arg0;
  ADD_LIST(node->add_collation_list, googlesql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedFunctionCall_function_call_info)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCall *node = (googlesql::ResolvedFunctionCall *)arg0;
  *arg1 = (void *)node->function_call_info().get();
}

void GO_EXPORT(ResolvedFunctionCall_set_function_call_info)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionCall *node = (googlesql::ResolvedFunctionCall *)arg0;
  auto p = std::make_shared<googlesql::ResolvedFunctionCallInfo>();
  memcpy((void *)p.get(), arg1, sizeof(googlesql::ResolvedFunctionCallInfo));
  node->set_function_call_info(p);
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_distinct)(void * arg0,char* arg1){
  googlesql::ResolvedNonScalarFunctionCallBase *node = (googlesql::ResolvedNonScalarFunctionCallBase *)arg0;
  *arg1 = node->distinct();
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_distinct)(void * arg0,int arg1){
  googlesql::ResolvedNonScalarFunctionCallBase *node = (googlesql::ResolvedNonScalarFunctionCallBase *)arg0;
  node->set_distinct(arg1);
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_null_handling_modifier)(void * arg0,int* arg1){
  googlesql::ResolvedNonScalarFunctionCallBase *node = (googlesql::ResolvedNonScalarFunctionCallBase *)arg0;
  *arg1 = node->null_handling_modifier();
}

void GO_EXPORT(ResolvedNonScalarFunctionCallBase_set_null_handling_modifier)(void * arg0,int arg1){
  googlesql::ResolvedNonScalarFunctionCallBase *node = (googlesql::ResolvedNonScalarFunctionCallBase *)arg0;
  node->set_null_handling_modifier((googlesql::ResolvedNonScalarFunctionCallBase::NullHandlingModifier)arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_having_modifier)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  *arg1 = (void *)node->having_modifier();
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_having_modifier)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  SET_UNIQUE_PTR(node->set_having_modifier, ResolvedAggregateHavingModifier, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_order_by_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  GET_UNIQUE_PTR_LIST(node->order_by_item_list, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_order_by_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_add_order_by_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedAggregateFunctionCall_limit)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  *arg1 = (void *)node->limit();
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_limit)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  node->set_limit(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAggregateFunctionCall_function_call_info)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  *arg1 = (void *)node->function_call_info().get();
}

void GO_EXPORT(ResolvedAggregateFunctionCall_set_function_call_info)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateFunctionCall *node = (googlesql::ResolvedAggregateFunctionCall *)arg0;
  auto p = std::make_shared<googlesql::ResolvedFunctionCallInfo>();
  memcpy((void *)p.get(), arg1, sizeof(googlesql::ResolvedFunctionCallInfo));
  node->set_function_call_info(p);
}

void GO_EXPORT(ResolvedAnalyticFunctionCall_window_frame)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyticFunctionCall *node = (googlesql::ResolvedAnalyticFunctionCall *)arg0;
  *arg1 = (void *)node->window_frame();
}

void GO_EXPORT(ResolvedAnalyticFunctionCall_set_window_frame)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticFunctionCall *node = (googlesql::ResolvedAnalyticFunctionCall *)arg0;
  SET_UNIQUE_PTR(node->set_window_frame, ResolvedWindowFrame, arg1);
}

void GO_EXPORT(ResolvedExtendedCastElement_from_type)(void * arg0,void ** arg1){
  googlesql::ResolvedExtendedCastElement *node = (googlesql::ResolvedExtendedCastElement *)arg0;
  *arg1 = (void *)node->from_type();
}

void GO_EXPORT(ResolvedExtendedCastElement_set_from_type)(void * arg0,void * arg1){
  googlesql::ResolvedExtendedCastElement *node = (googlesql::ResolvedExtendedCastElement *)arg0;
  node->set_from_type((const googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedExtendedCastElement_to_type)(void * arg0,void ** arg1){
  googlesql::ResolvedExtendedCastElement *node = (googlesql::ResolvedExtendedCastElement *)arg0;
  *arg1 = (void *)node->to_type();
}

void GO_EXPORT(ResolvedExtendedCastElement_set_to_type)(void * arg0,void * arg1){
  googlesql::ResolvedExtendedCastElement *node = (googlesql::ResolvedExtendedCastElement *)arg0;
  node->set_to_type((const googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedExtendedCastElement_function)(void * arg0,void ** arg1){
  googlesql::ResolvedExtendedCastElement *node = (googlesql::ResolvedExtendedCastElement *)arg0;
  *arg1 = (void *)node->function();
}

void GO_EXPORT(ResolvedExtendedCastElement_set_function)(void * arg0,void * arg1){
  googlesql::ResolvedExtendedCastElement *node = (googlesql::ResolvedExtendedCastElement *)arg0;
  node->set_function((const googlesql::Function *)arg1);
}

void GO_EXPORT(ResolvedExtendedCast_element_list)(void * arg0,void ** arg1){
  googlesql::ResolvedExtendedCast *node = (googlesql::ResolvedExtendedCast *)arg0;
  GET_UNIQUE_PTR_LIST(node->element_list, arg1);
}

void GO_EXPORT(ResolvedExtendedCast_set_element_list)(void * arg0,void * arg1){
  googlesql::ResolvedExtendedCast *node = (googlesql::ResolvedExtendedCast *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_element_list, ResolvedExtendedCastElement, arg1);
}

void GO_EXPORT(ResolvedExtendedCast_add_element_list)(void * arg0,void * arg1){
  googlesql::ResolvedExtendedCast *node = (googlesql::ResolvedExtendedCast *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_element_list, ResolvedExtendedCastElement, arg1);
}

void GO_EXPORT(ResolvedCast_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedCast_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCast_return_null_on_error)(void * arg0,char* arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  *arg1 = node->return_null_on_error();
}

void GO_EXPORT(ResolvedCast_set_return_null_on_error)(void * arg0,int arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  node->set_return_null_on_error(arg1);
}

void GO_EXPORT(ResolvedCast_extended_cast)(void * arg0,void ** arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  *arg1 = (void *)node->extended_cast();
}

void GO_EXPORT(ResolvedCast_set_extended_cast)(void * arg0,void * arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  SET_UNIQUE_PTR(node->set_extended_cast, ResolvedExtendedCast, arg1);
}

void GO_EXPORT(ResolvedCast_format)(void * arg0,void ** arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  *arg1 = (void *)node->format();
}

void GO_EXPORT(ResolvedCast_set_format)(void * arg0,void * arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  node->set_format(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCast_time_zone)(void * arg0,void ** arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  *arg1 = (void *)node->time_zone();
}

void GO_EXPORT(ResolvedCast_set_time_zone)(void * arg0,void * arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  node->set_time_zone(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCast_type_parameters)(void * arg0,void ** arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  *arg1 = (void *)(new googlesql::TypeParameters(node->type_parameters()));
}

void GO_EXPORT(ResolvedCast_set_type_parameters)(void * arg0,void * arg1){
  googlesql::ResolvedCast *node = (googlesql::ResolvedCast *)arg0;
  node->set_type_parameters(*(googlesql::TypeParameters *)arg1);
}

void GO_EXPORT(ResolvedMakeStruct_field_list)(void * arg0,void ** arg1){
  googlesql::ResolvedMakeStruct *node = (googlesql::ResolvedMakeStruct *)arg0;
  GET_UNIQUE_PTR_LIST(node->field_list, arg1);
}

void GO_EXPORT(ResolvedMakeStruct_set_field_list)(void * arg0,void * arg1){
  googlesql::ResolvedMakeStruct *node = (googlesql::ResolvedMakeStruct *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_field_list, arg1);
}

void GO_EXPORT(ResolvedMakeStruct_add_field_list)(void * arg0,void * arg1){
  googlesql::ResolvedMakeStruct *node = (googlesql::ResolvedMakeStruct *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_field_list, arg1);
}

void GO_EXPORT(ResolvedMakeProto_field_list)(void * arg0,void ** arg1){
  googlesql::ResolvedMakeProto *node = (googlesql::ResolvedMakeProto *)arg0;
  GET_UNIQUE_PTR_LIST(node->field_list, arg1);
}

void GO_EXPORT(ResolvedMakeProto_set_field_list)(void * arg0,void * arg1){
  googlesql::ResolvedMakeProto *node = (googlesql::ResolvedMakeProto *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_field_list, ResolvedMakeProtoField, arg1);
}

void GO_EXPORT(ResolvedMakeProto_add_field_list)(void * arg0,void * arg1){
  googlesql::ResolvedMakeProto *node = (googlesql::ResolvedMakeProto *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_field_list, ResolvedMakeProtoField, arg1);
}

void GO_EXPORT(ResolvedMakeProtoField_format)(void * arg0,int* arg1){
  googlesql::ResolvedMakeProtoField *node = (googlesql::ResolvedMakeProtoField *)arg0;
  *arg1 = node->format();
}

void GO_EXPORT(ResolvedMakeProtoField_set_format)(void * arg0,int arg1){
  googlesql::ResolvedMakeProtoField *node = (googlesql::ResolvedMakeProtoField *)arg0;
  node->set_format((googlesql::FieldFormat::Format)arg1);
}

void GO_EXPORT(ResolvedMakeProtoField_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedMakeProtoField *node = (googlesql::ResolvedMakeProtoField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedMakeProtoField_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedMakeProtoField *node = (googlesql::ResolvedMakeProtoField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetStructField_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedGetStructField *node = (googlesql::ResolvedGetStructField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedGetStructField_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedGetStructField *node = (googlesql::ResolvedGetStructField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetStructField_field_idx)(void * arg0,int* arg1){
  googlesql::ResolvedGetStructField *node = (googlesql::ResolvedGetStructField *)arg0;
  *arg1 = node->field_idx();
}

void GO_EXPORT(ResolvedGetStructField_set_field_idx)(void * arg0,int arg1){
  googlesql::ResolvedGetStructField *node = (googlesql::ResolvedGetStructField *)arg0;
  node->set_field_idx(arg1);
}

void GO_EXPORT(ResolvedGetProtoField_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedGetProtoField_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetProtoField_default_value)(void * arg0,void ** arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  *arg1 = (void *)(new googlesql::Value(node->default_value()));
}

void GO_EXPORT(ResolvedGetProtoField_set_default_value)(void * arg0,void * arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  node->set_default_value(*(googlesql::Value *)arg1);
}

void GO_EXPORT(ResolvedGetProtoField_get_has_bit)(void * arg0,char* arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  *arg1 = node->get_has_bit();
}

void GO_EXPORT(ResolvedGetProtoField_set_get_has_bit)(void * arg0,int arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  node->set_get_has_bit(arg1);
}

void GO_EXPORT(ResolvedGetProtoField_format)(void * arg0,int* arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  *arg1 = node->format();
}

void GO_EXPORT(ResolvedGetProtoField_set_format)(void * arg0,int arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  node->set_format((googlesql::FieldFormat::Format)arg1);
}

void GO_EXPORT(ResolvedGetProtoField_return_default_value_when_unset)(void * arg0,char* arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  *arg1 = node->return_default_value_when_unset();
}

void GO_EXPORT(ResolvedGetProtoField_set_return_default_value_when_unset)(void * arg0,int arg1){
  googlesql::ResolvedGetProtoField *node = (googlesql::ResolvedGetProtoField *)arg0;
  node->set_return_default_value_when_unset(arg1);
}

void GO_EXPORT(ResolvedGetJsonField_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedGetJsonField *node = (googlesql::ResolvedGetJsonField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedGetJsonField_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedGetJsonField *node = (googlesql::ResolvedGetJsonField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGetJsonField_field_name)(void * arg0,void ** arg1){
  googlesql::ResolvedGetJsonField *node = (googlesql::ResolvedGetJsonField *)arg0;
  *arg1 = (void *)((new std::string(node->field_name()))->c_str());
}

void GO_EXPORT(ResolvedGetJsonField_set_field_name)(void * arg0,void * arg1){
  googlesql::ResolvedGetJsonField *node = (googlesql::ResolvedGetJsonField *)arg0;
  node->set_field_name((char *)arg1);
}

void GO_EXPORT(ResolvedFlatten_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedFlatten *node = (googlesql::ResolvedFlatten *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedFlatten_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedFlatten *node = (googlesql::ResolvedFlatten *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFlatten_get_field_list)(void * arg0,void ** arg1){
  googlesql::ResolvedFlatten *node = (googlesql::ResolvedFlatten *)arg0;
  GET_UNIQUE_PTR_LIST(node->get_field_list, arg1);
}

void GO_EXPORT(ResolvedFlatten_set_get_field_list)(void * arg0,void * arg1){
  googlesql::ResolvedFlatten *node = (googlesql::ResolvedFlatten *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_get_field_list, arg1);
}

void GO_EXPORT(ResolvedFlatten_add_get_field_list)(void * arg0,void * arg1){
  googlesql::ResolvedFlatten *node = (googlesql::ResolvedFlatten *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_get_field_list, arg1);
}

void GO_EXPORT(ResolvedReplaceFieldItem_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedReplaceFieldItem *node = (googlesql::ResolvedReplaceFieldItem *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedReplaceFieldItem_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedReplaceFieldItem *node = (googlesql::ResolvedReplaceFieldItem *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedReplaceFieldItem_struct_index_path)(void * arg0,void ** arg1){
  googlesql::ResolvedReplaceFieldItem *node = (googlesql::ResolvedReplaceFieldItem *)arg0;
  GET_INTS(node->struct_index_path, arg1);
}

void GO_EXPORT(ResolvedReplaceFieldItem_set_struct_index_path)(void * arg0,void * arg1){
  googlesql::ResolvedReplaceFieldItem *node = (googlesql::ResolvedReplaceFieldItem *)arg0;
  SET_INTS(node->set_struct_index_path, arg1);
}

void GO_EXPORT(ResolvedReplaceFieldItem_add_struct_index_path)(void * arg0,int arg1){
  googlesql::ResolvedReplaceFieldItem *node = (googlesql::ResolvedReplaceFieldItem *)arg0;
  node->add_struct_index_path(arg1);
}

void GO_EXPORT(ResolvedReplaceField_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedReplaceField *node = (googlesql::ResolvedReplaceField *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedReplaceField_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedReplaceField *node = (googlesql::ResolvedReplaceField *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedReplaceField_replace_field_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedReplaceField *node = (googlesql::ResolvedReplaceField *)arg0;
  GET_UNIQUE_PTR_LIST(node->replace_field_item_list, arg1);
}

void GO_EXPORT(ResolvedReplaceField_set_replace_field_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedReplaceField *node = (googlesql::ResolvedReplaceField *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_replace_field_item_list, ResolvedReplaceFieldItem, arg1);
}

void GO_EXPORT(ResolvedReplaceField_add_replace_field_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedReplaceField *node = (googlesql::ResolvedReplaceField *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_replace_field_item_list, ResolvedReplaceFieldItem, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_subquery_type)(void * arg0,int* arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  *arg1 = node->subquery_type();
}

void GO_EXPORT(ResolvedSubqueryExpr_set_subquery_type)(void * arg0,int arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  node->set_subquery_type((googlesql::ResolvedSubqueryExpr::SubqueryType)arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_parameter_list)(void * arg0,void ** arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  GET_UNIQUE_PTR_LIST(node->parameter_list, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_set_parameter_list)(void * arg0,void * arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_add_parameter_list)(void * arg0,void * arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_in_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  *arg1 = (void *)node->in_expr();
}

void GO_EXPORT(ResolvedSubqueryExpr_set_in_expr)(void * arg0,void * arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  node->set_in_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedSubqueryExpr_in_collation)(void * arg0,void ** arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedCollation(node->in_collation()));
}

void GO_EXPORT(ResolvedSubqueryExpr_set_in_collation)(void * arg0,void * arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  node->set_in_collation(*(googlesql::ResolvedCollation *)arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_subquery)(void * arg0,void ** arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  *arg1 = (void *)node->subquery();
}

void GO_EXPORT(ResolvedSubqueryExpr_set_subquery)(void * arg0,void * arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  node->set_subquery(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedSubqueryExpr_hint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_set_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedSubqueryExpr_add_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedSubqueryExpr *node = (googlesql::ResolvedSubqueryExpr *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedScan_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  GET_LIST(node->column_list, arg1);
}

void GO_EXPORT(ResolvedScan_set_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  SET_LIST(node->set_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedScan_add_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  ADD_LIST(node->add_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedScan_hint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedScan_set_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedScan_add_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedScan_is_ordered)(void * arg0,char* arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  *arg1 = node->is_ordered();
}

void GO_EXPORT(ResolvedScan_set_is_ordered)(void * arg0,int arg1){
  googlesql::ResolvedScan *node = (googlesql::ResolvedScan *)arg0;
  node->set_is_ordered(arg1);
}

void GO_EXPORT(ResolvedModel_model)(void * arg0,void ** arg1){
  googlesql::ResolvedModel *node = (googlesql::ResolvedModel *)arg0;
  *arg1 = (void *)node->model();
}

void GO_EXPORT(ResolvedModel_set_model)(void * arg0,void * arg1){
  googlesql::ResolvedModel *node = (googlesql::ResolvedModel *)arg0;
  node->set_model((const googlesql::Model *)arg1);
}

void GO_EXPORT(ResolvedConnection_connection)(void * arg0,void ** arg1){
  googlesql::ResolvedConnection *node = (googlesql::ResolvedConnection *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedConnection_set_connection)(void * arg0,void * arg1){
  googlesql::ResolvedConnection *node = (googlesql::ResolvedConnection *)arg0;
  node->set_connection((const googlesql::Connection *)arg1);
}

void GO_EXPORT(ResolvedDescriptor_descriptor_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedDescriptor *node = (googlesql::ResolvedDescriptor *)arg0;
  GET_LIST(node->descriptor_column_list, arg1);
}

void GO_EXPORT(ResolvedDescriptor_set_descriptor_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedDescriptor *node = (googlesql::ResolvedDescriptor *)arg0;
  SET_LIST(node->set_descriptor_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedDescriptor_add_descriptor_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedDescriptor *node = (googlesql::ResolvedDescriptor *)arg0;
  ADD_LIST(node->add_descriptor_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedDescriptor_descriptor_column_name_list)(void * arg0,void ** arg1){
  googlesql::ResolvedDescriptor *node = (googlesql::ResolvedDescriptor *)arg0;
  GET_STRS(node->descriptor_column_name_list, arg1);
}

void GO_EXPORT(ResolvedDescriptor_set_descriptor_column_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedDescriptor *node = (googlesql::ResolvedDescriptor *)arg0;
  SET_LIST(node->set_descriptor_column_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedDescriptor_add_descriptor_column_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedDescriptor *node = (googlesql::ResolvedDescriptor *)arg0;
  node->add_descriptor_column_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedTableScan_table)(void * arg0,void ** arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  *arg1 = (void *)node->table();
}

void GO_EXPORT(ResolvedTableScan_set_table)(void * arg0,void * arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  node->set_table((const googlesql::Table *)arg1);
}

void GO_EXPORT(ResolvedTableScan_for_system_time_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  *arg1 = (void *)node->for_system_time_expr();
}

void GO_EXPORT(ResolvedTableScan_set_for_system_time_expr)(void * arg0,void * arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  node->set_for_system_time_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedTableScan_column_index_list)(void * arg0,void ** arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  GET_INTS(node->column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableScan_set_column_index_list)(void * arg0,void * arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  SET_INTS(node->set_column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableScan_add_column_index_list)(void * arg0,int arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  node->add_column_index_list(arg1);
}

void GO_EXPORT(ResolvedTableScan_alias)(void * arg0,void ** arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  *arg1 = (void *)((new std::string(node->alias()))->c_str());
}

void GO_EXPORT(ResolvedTableScan_set_alias)(void * arg0,void * arg1){
  googlesql::ResolvedTableScan *node = (googlesql::ResolvedTableScan *)arg0;
  node->set_alias((char *)arg1);
}

void GO_EXPORT(ResolvedJoinScan_join_type)(void * arg0,int* arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  *arg1 = node->join_type();
}

void GO_EXPORT(ResolvedJoinScan_set_join_type)(void * arg0,int arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  node->set_join_type((googlesql::ResolvedJoinScan::JoinType)arg1);
}

void GO_EXPORT(ResolvedJoinScan_left_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  *arg1 = (void *)node->left_scan();
}

void GO_EXPORT(ResolvedJoinScan_set_left_scan)(void * arg0,void * arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  node->set_left_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedJoinScan_right_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  *arg1 = (void *)node->right_scan();
}

void GO_EXPORT(ResolvedJoinScan_set_right_scan)(void * arg0,void * arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  node->set_right_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedJoinScan_join_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  *arg1 = (void *)node->join_expr();
}

void GO_EXPORT(ResolvedJoinScan_set_join_expr)(void * arg0,void * arg1){
  googlesql::ResolvedJoinScan *node = (googlesql::ResolvedJoinScan *)arg0;
  node->set_join_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedArrayScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedArrayScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedArrayScan_array_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->array_expr();
}

void GO_EXPORT(ResolvedArrayScan_set_array_expr)(void * arg0,void * arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  node->set_array_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedArrayScan_element_column)(void * arg0,void ** arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->element_column()));
}

void GO_EXPORT(ResolvedArrayScan_set_element_column)(void * arg0,void * arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  node->set_element_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedArrayScan_array_offset_column)(void * arg0,void ** arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedArrayScan_set_array_offset_column)(void * arg0,void * arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedArrayScan_join_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  *arg1 = (void *)node->join_expr();
}

void GO_EXPORT(ResolvedArrayScan_set_join_expr)(void * arg0,void * arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  node->set_join_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedArrayScan_is_outer)(void * arg0,char* arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  *arg1 = node->is_outer();
}

void GO_EXPORT(ResolvedArrayScan_set_is_outer)(void * arg0,int arg1){
  googlesql::ResolvedArrayScan *node = (googlesql::ResolvedArrayScan *)arg0;
  node->set_is_outer(arg1);
}

void GO_EXPORT(ResolvedColumnHolder_column)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnHolder *node = (googlesql::ResolvedColumnHolder *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedColumnHolder_set_column)(void * arg0,void * arg1){
  googlesql::ResolvedColumnHolder *node = (googlesql::ResolvedColumnHolder *)arg0;
  node->set_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedFilterScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedFilterScan *node = (googlesql::ResolvedFilterScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedFilterScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedFilterScan *node = (googlesql::ResolvedFilterScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedFilterScan_filter_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedFilterScan *node = (googlesql::ResolvedFilterScan *)arg0;
  *arg1 = (void *)node->filter_expr();
}

void GO_EXPORT(ResolvedFilterScan_set_filter_expr)(void * arg0,void * arg1){
  googlesql::ResolvedFilterScan *node = (googlesql::ResolvedFilterScan *)arg0;
  node->set_filter_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGroupingSet_group_by_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedGroupingSet *node = (googlesql::ResolvedGroupingSet *)arg0;
  GET_UNIQUE_PTR_LIST(node->group_by_column_list, arg1);
}

void GO_EXPORT(ResolvedGroupingSet_set_group_by_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedGroupingSet *node = (googlesql::ResolvedGroupingSet *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_group_by_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedGroupingSet_add_group_by_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedGroupingSet *node = (googlesql::ResolvedGroupingSet *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_group_by_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedAggregateScanBase_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedAggregateScanBase_group_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->group_by_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_set_group_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_add_group_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_collation_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  GET_LIST(node->collation_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_set_collation_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  SET_LIST(node->set_collation_list, googlesql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_add_collation_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  ADD_LIST(node->add_collation_list, googlesql::ResolvedCollation, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_aggregate_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->aggregate_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_set_aggregate_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  SET_UNIQUE_PTR_COMPUTED_COLUMN_BASE_LIST(node->set_aggregate_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScanBase_add_aggregate_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScanBase *node = (googlesql::ResolvedAggregateScanBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_aggregate_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_grouping_set_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateScan *node = (googlesql::ResolvedAggregateScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->grouping_set_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_set_grouping_set_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScan *node = (googlesql::ResolvedAggregateScan *)arg0;
  SET_UNIQUE_PTR_GROUPING_SET_LIST(node->set_grouping_set_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_add_grouping_set_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScan *node = (googlesql::ResolvedAggregateScan *)arg0;
  ADD_UNIQUE_PTR_GROUPING_SET_LIST(node->add_grouping_set_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_rollup_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateScan *node = (googlesql::ResolvedAggregateScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->rollup_column_list, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_set_rollup_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScan *node = (googlesql::ResolvedAggregateScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_rollup_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAggregateScan_add_rollup_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateScan *node = (googlesql::ResolvedAggregateScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_rollup_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_k_threshold_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedAnonymizedAggregateScan *node = (googlesql::ResolvedAnonymizedAggregateScan *)arg0;
  *arg1 = (void *)node->k_threshold_expr();
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_set_k_threshold_expr)(void * arg0,void * arg1){
  googlesql::ResolvedAnonymizedAggregateScan *node = (googlesql::ResolvedAnonymizedAggregateScan *)arg0;
  SET_UNIQUE_PTR(node->set_k_threshold_expr, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_anonymization_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAnonymizedAggregateScan *node = (googlesql::ResolvedAnonymizedAggregateScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->anonymization_option_list, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_set_anonymization_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnonymizedAggregateScan *node = (googlesql::ResolvedAnonymizedAggregateScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_anonymization_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAnonymizedAggregateScan_add_anonymization_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnonymizedAggregateScan *node = (googlesql::ResolvedAnonymizedAggregateScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_anonymization_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedSetOperationItem_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedSetOperationItem *node = (googlesql::ResolvedSetOperationItem *)arg0;
  *arg1 = (void *)node->scan();
}

void GO_EXPORT(ResolvedSetOperationItem_set_scan)(void * arg0,void * arg1){
  googlesql::ResolvedSetOperationItem *node = (googlesql::ResolvedSetOperationItem *)arg0;
  node->set_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedSetOperationItem_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedSetOperationItem *node = (googlesql::ResolvedSetOperationItem *)arg0;
  GET_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedSetOperationItem_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetOperationItem *node = (googlesql::ResolvedSetOperationItem *)arg0;
  SET_LIST(node->set_output_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedSetOperationItem_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetOperationItem *node = (googlesql::ResolvedSetOperationItem *)arg0;
  ADD_LIST(node->add_output_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_op_type)(void * arg0,int* arg1){
  googlesql::ResolvedSetOperationScan *node = (googlesql::ResolvedSetOperationScan *)arg0;
  *arg1 = node->op_type();
}

void GO_EXPORT(ResolvedSetOperationScan_set_op_type)(void * arg0,int arg1){
  googlesql::ResolvedSetOperationScan *node = (googlesql::ResolvedSetOperationScan *)arg0;
  node->set_op_type((googlesql::ResolvedSetOperationScan::SetOperationType)arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_input_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedSetOperationScan *node = (googlesql::ResolvedSetOperationScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->input_item_list, arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_set_input_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetOperationScan *node = (googlesql::ResolvedSetOperationScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_input_item_list, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedSetOperationScan_add_input_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetOperationScan *node = (googlesql::ResolvedSetOperationScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_input_item_list, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedOrderByScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedOrderByScan *node = (googlesql::ResolvedOrderByScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedOrderByScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedOrderByScan *node = (googlesql::ResolvedOrderByScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedOrderByScan_order_by_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedOrderByScan *node = (googlesql::ResolvedOrderByScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->order_by_item_list, arg1);
}

void GO_EXPORT(ResolvedOrderByScan_set_order_by_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedOrderByScan *node = (googlesql::ResolvedOrderByScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedOrderByScan_add_order_by_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedOrderByScan *node = (googlesql::ResolvedOrderByScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedLimitOffsetScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedLimitOffsetScan *node = (googlesql::ResolvedLimitOffsetScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedLimitOffsetScan *node = (googlesql::ResolvedLimitOffsetScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedLimitOffsetScan_limit)(void * arg0,void ** arg1){
  googlesql::ResolvedLimitOffsetScan *node = (googlesql::ResolvedLimitOffsetScan *)arg0;
  *arg1 = (void *)node->limit();
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_limit)(void * arg0,void * arg1){
  googlesql::ResolvedLimitOffsetScan *node = (googlesql::ResolvedLimitOffsetScan *)arg0;
  node->set_limit(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedLimitOffsetScan_offset)(void * arg0,void ** arg1){
  googlesql::ResolvedLimitOffsetScan *node = (googlesql::ResolvedLimitOffsetScan *)arg0;
  *arg1 = (void *)node->offset();
}

void GO_EXPORT(ResolvedLimitOffsetScan_set_offset)(void * arg0,void * arg1){
  googlesql::ResolvedLimitOffsetScan *node = (googlesql::ResolvedLimitOffsetScan *)arg0;
  node->set_offset(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedWithRefScan_with_query_name)(void * arg0,void ** arg1){
  googlesql::ResolvedWithRefScan *node = (googlesql::ResolvedWithRefScan *)arg0;
  *arg1 = (void *)((new std::string(node->with_query_name()))->c_str());
}

void GO_EXPORT(ResolvedWithRefScan_set_with_query_name)(void * arg0,void * arg1){
  googlesql::ResolvedWithRefScan *node = (googlesql::ResolvedWithRefScan *)arg0;
  node->set_with_query_name((char *)arg1);
}

void GO_EXPORT(ResolvedAnalyticScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyticScan *node = (googlesql::ResolvedAnalyticScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedAnalyticScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticScan *node = (googlesql::ResolvedAnalyticScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedAnalyticScan_function_group_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyticScan *node = (googlesql::ResolvedAnalyticScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->function_group_list, arg1);
}

void GO_EXPORT(ResolvedAnalyticScan_set_function_group_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticScan *node = (googlesql::ResolvedAnalyticScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedAnalyticScan_add_function_group_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticScan *node = (googlesql::ResolvedAnalyticScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedSampleScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedSampleScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedSampleScan_method)(void * arg0,void ** arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)((new std::string(node->method()))->c_str());
}

void GO_EXPORT(ResolvedSampleScan_set_method)(void * arg0,void * arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  node->set_method((char *)arg1);
}

void GO_EXPORT(ResolvedSampleScan_size)(void * arg0,void ** arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->size();
}

void GO_EXPORT(ResolvedSampleScan_set_size)(void * arg0,void * arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  node->set_size(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedSampleScan_unit)(void * arg0,int* arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  *arg1 = node->unit();
}

void GO_EXPORT(ResolvedSampleScan_set_unit)(void * arg0,int arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  node->set_unit((googlesql::ResolvedSampleScan::SampleUnit)arg1);
}

void GO_EXPORT(ResolvedSampleScan_repeatable_argument)(void * arg0,void ** arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->repeatable_argument();
}

void GO_EXPORT(ResolvedSampleScan_set_repeatable_argument)(void * arg0,void * arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  node->set_repeatable_argument(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedSampleScan_weight_column)(void * arg0,void ** arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  *arg1 = (void *)node->weight_column();
}

void GO_EXPORT(ResolvedSampleScan_set_weight_column)(void * arg0,void * arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  SET_UNIQUE_PTR(node->set_weight_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedSampleScan_partition_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedSampleScan_set_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedSampleScan_add_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedSampleScan *node = (googlesql::ResolvedSampleScan *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedComputedColumn_column)(void * arg0,void ** arg1){
  googlesql::ResolvedComputedColumn *node = (googlesql::ResolvedComputedColumn *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedComputedColumn_set_column)(void * arg0,void * arg1){
  googlesql::ResolvedComputedColumn *node = (googlesql::ResolvedComputedColumn *)arg0;
  node->set_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedComputedColumn_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedComputedColumn *node = (googlesql::ResolvedComputedColumn *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedComputedColumn_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedComputedColumn *node = (googlesql::ResolvedComputedColumn *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedOrderByItem_column_ref)(void * arg0,void ** arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  *arg1 = (void *)node->column_ref();
}

void GO_EXPORT(ResolvedOrderByItem_set_column_ref)(void * arg0,void * arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  SET_UNIQUE_PTR(node->set_column_ref, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedOrderByItem_collation_name)(void * arg0,void ** arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedOrderByItem_set_collation_name)(void * arg0,void * arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedOrderByItem_is_descending)(void * arg0,char* arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  *arg1 = node->is_descending();
}

void GO_EXPORT(ResolvedOrderByItem_set_is_descending)(void * arg0,int arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  node->set_is_descending(arg1);
}

void GO_EXPORT(ResolvedOrderByItem_null_order)(void * arg0,int* arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  *arg1 = node->null_order();
}

void GO_EXPORT(ResolvedOrderByItem_set_null_order)(void * arg0,int arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  node->set_null_order((googlesql::ResolvedOrderByItem::NullOrderMode)arg1);
}

void GO_EXPORT(ResolvedOrderByItem_collation)(void * arg0,void ** arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedCollation(node->collation()));
}

void GO_EXPORT(ResolvedOrderByItem_set_collation)(void * arg0,void * arg1){
  googlesql::ResolvedOrderByItem *node = (googlesql::ResolvedOrderByItem *)arg0;
  node->set_collation(*(googlesql::ResolvedCollation *)arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_collation_name)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedColumnAnnotations_set_collation_name)(void * arg0,void * arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedColumnAnnotations_not_null)(void * arg0,char* arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  *arg1 = node->not_null();
}

void GO_EXPORT(ResolvedColumnAnnotations_set_not_null)(void * arg0,int arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  node->set_not_null(arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_child_list)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  GET_UNIQUE_PTR_LIST(node->child_list, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_set_child_list)(void * arg0,void * arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_child_list, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_add_child_list)(void * arg0,void * arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_child_list, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedColumnAnnotations_type_parameters)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  *arg1 = (void *)(new googlesql::TypeParameters(node->type_parameters()));
}

void GO_EXPORT(ResolvedColumnAnnotations_set_type_parameters)(void * arg0,void * arg1){
  googlesql::ResolvedColumnAnnotations *node = (googlesql::ResolvedColumnAnnotations *)arg0;
  node->set_type_parameters(*(googlesql::TypeParameters *)arg1);
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_expression)(void * arg0,void ** arg1){
  googlesql::ResolvedGeneratedColumnInfo *node = (googlesql::ResolvedGeneratedColumnInfo *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_set_expression)(void * arg0,void * arg1){
  googlesql::ResolvedGeneratedColumnInfo *node = (googlesql::ResolvedGeneratedColumnInfo *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_stored_mode)(void * arg0,int* arg1){
  googlesql::ResolvedGeneratedColumnInfo *node = (googlesql::ResolvedGeneratedColumnInfo *)arg0;
  *arg1 = node->stored_mode();
}

void GO_EXPORT(ResolvedGeneratedColumnInfo_set_stored_mode)(void * arg0,int arg1){
  googlesql::ResolvedGeneratedColumnInfo *node = (googlesql::ResolvedGeneratedColumnInfo *)arg0;
  node->set_stored_mode((googlesql::ResolvedGeneratedColumnInfo::StoredMode)arg1);
}

void GO_EXPORT(ResolvedColumnDefaultValue_expression)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefaultValue *node = (googlesql::ResolvedColumnDefaultValue *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedColumnDefaultValue_set_expression)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefaultValue *node = (googlesql::ResolvedColumnDefaultValue *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedColumnDefaultValue_sql)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefaultValue *node = (googlesql::ResolvedColumnDefaultValue *)arg0;
  *arg1 = (void *)((new std::string(node->sql()))->c_str());
}

void GO_EXPORT(ResolvedColumnDefaultValue_set_sql)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefaultValue *node = (googlesql::ResolvedColumnDefaultValue *)arg0;
  node->set_sql((char *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_name)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedColumnDefinition_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_type)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ResolvedColumnDefinition_set_type)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  node->set_type((const googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_annotations)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->annotations();
}

void GO_EXPORT(ResolvedColumnDefinition_set_annotations)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  SET_UNIQUE_PTR(node->set_annotations, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_is_hidden)(void * arg0,char* arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  *arg1 = node->is_hidden();
}

void GO_EXPORT(ResolvedColumnDefinition_set_is_hidden)(void * arg0,int arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  node->set_is_hidden(arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_column)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedColumnDefinition_set_column)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  node->set_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_generated_column_info)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->generated_column_info();
}

void GO_EXPORT(ResolvedColumnDefinition_set_generated_column_info)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  SET_UNIQUE_PTR(node->set_generated_column_info, ResolvedGeneratedColumnInfo, arg1);
}

void GO_EXPORT(ResolvedColumnDefinition_default_value)(void * arg0,void ** arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  *arg1 = (void *)node->default_value();
}

void GO_EXPORT(ResolvedColumnDefinition_set_default_value)(void * arg0,void * arg1){
  googlesql::ResolvedColumnDefinition *node = (googlesql::ResolvedColumnDefinition *)arg0;
  SET_UNIQUE_PTR(node->set_default_value, ResolvedColumnDefaultValue, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_column_offset_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  GET_INTS(node->column_offset_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_set_column_offset_list)(void * arg0,void * arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  SET_INTS(node->set_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_add_column_offset_list)(void * arg0,int arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  node->add_column_offset_list(arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_unenforced)(void * arg0,char* arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  *arg1 = node->unenforced();
}

void GO_EXPORT(ResolvedPrimaryKey_set_unenforced)(void * arg0,int arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  node->set_unenforced(arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_constraint_name)(void * arg0,void ** arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  *arg1 = (void *)((new std::string(node->constraint_name()))->c_str());
}

void GO_EXPORT(ResolvedPrimaryKey_set_constraint_name)(void * arg0,void * arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  node->set_constraint_name((char *)arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_column_name_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  GET_STRS(node->column_name_list, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_set_column_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  SET_LIST(node->set_column_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedPrimaryKey_add_column_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedPrimaryKey *node = (googlesql::ResolvedPrimaryKey *)arg0;
  node->add_column_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedForeignKey_constraint_name)(void * arg0,void ** arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  *arg1 = (void *)((new std::string(node->constraint_name()))->c_str());
}

void GO_EXPORT(ResolvedForeignKey_set_constraint_name)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->set_constraint_name((char *)arg1);
}

void GO_EXPORT(ResolvedForeignKey_referencing_column_offset_list)(void * arg0,void ** arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  GET_INTS(node->referencing_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_referencing_column_offset_list)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  SET_INTS(node->set_referencing_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_referencing_column_offset_list)(void * arg0,int arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->add_referencing_column_offset_list(arg1);
}

void GO_EXPORT(ResolvedForeignKey_referenced_table)(void * arg0,void ** arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  *arg1 = (void *)node->referenced_table();
}

void GO_EXPORT(ResolvedForeignKey_set_referenced_table)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->set_referenced_table((const googlesql::Table *)arg1);
}

void GO_EXPORT(ResolvedForeignKey_referenced_column_offset_list)(void * arg0,void ** arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  GET_INTS(node->referenced_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_referenced_column_offset_list)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  SET_INTS(node->set_referenced_column_offset_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_referenced_column_offset_list)(void * arg0,int arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->add_referenced_column_offset_list(arg1);
}

void GO_EXPORT(ResolvedForeignKey_match_mode)(void * arg0,int* arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  *arg1 = node->match_mode();
}

void GO_EXPORT(ResolvedForeignKey_set_match_mode)(void * arg0,int arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->set_match_mode((googlesql::ResolvedForeignKey::MatchMode)arg1);
}

void GO_EXPORT(ResolvedForeignKey_update_action)(void * arg0,int* arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  *arg1 = node->update_action();
}

void GO_EXPORT(ResolvedForeignKey_set_update_action)(void * arg0,int arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->set_update_action((googlesql::ResolvedForeignKey::ActionOperation)arg1);
}

void GO_EXPORT(ResolvedForeignKey_delete_action)(void * arg0,int* arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  *arg1 = node->delete_action();
}

void GO_EXPORT(ResolvedForeignKey_set_delete_action)(void * arg0,int arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->set_delete_action((googlesql::ResolvedForeignKey::ActionOperation)arg1);
}

void GO_EXPORT(ResolvedForeignKey_enforced)(void * arg0,char* arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  *arg1 = node->enforced();
}

void GO_EXPORT(ResolvedForeignKey_set_enforced)(void * arg0,int arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->set_enforced(arg1);
}

void GO_EXPORT(ResolvedForeignKey_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedForeignKey_referencing_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  GET_STRS(node->referencing_column_list, arg1);
}

void GO_EXPORT(ResolvedForeignKey_set_referencing_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  SET_LIST(node->set_referencing_column_list, std::string, arg1);
}

void GO_EXPORT(ResolvedForeignKey_add_referencing_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedForeignKey *node = (googlesql::ResolvedForeignKey *)arg0;
  node->add_referencing_column_list((char *)arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_constraint_name)(void * arg0,void ** arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  *arg1 = (void *)((new std::string(node->constraint_name()))->c_str());
}

void GO_EXPORT(ResolvedCheckConstraint_set_constraint_name)(void * arg0,void * arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  node->set_constraint_name((char *)arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_expression)(void * arg0,void ** arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedCheckConstraint_set_expression)(void * arg0,void * arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCheckConstraint_enforced)(void * arg0,char* arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  *arg1 = node->enforced();
}

void GO_EXPORT(ResolvedCheckConstraint_set_enforced)(void * arg0,int arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  node->set_enforced(arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCheckConstraint_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCheckConstraint *node = (googlesql::ResolvedCheckConstraint *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedOutputColumn_name)(void * arg0,void ** arg1){
  googlesql::ResolvedOutputColumn *node = (googlesql::ResolvedOutputColumn *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedOutputColumn_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedOutputColumn *node = (googlesql::ResolvedOutputColumn *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedOutputColumn_column)(void * arg0,void ** arg1){
  googlesql::ResolvedOutputColumn *node = (googlesql::ResolvedOutputColumn *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedOutputColumn_set_column)(void * arg0,void * arg1){
  googlesql::ResolvedOutputColumn *node = (googlesql::ResolvedOutputColumn *)arg0;
  node->set_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedProjectScan_expr_list)(void * arg0,void ** arg1){
  googlesql::ResolvedProjectScan *node = (googlesql::ResolvedProjectScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->expr_list, arg1);
}

void GO_EXPORT(ResolvedProjectScan_set_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedProjectScan *node = (googlesql::ResolvedProjectScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedProjectScan_add_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedProjectScan *node = (googlesql::ResolvedProjectScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedProjectScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedProjectScan *node = (googlesql::ResolvedProjectScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedProjectScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedProjectScan *node = (googlesql::ResolvedProjectScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedTVFScan_tvf)(void * arg0,void ** arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)node->tvf();
}

void GO_EXPORT(ResolvedTVFScan_set_tvf)(void * arg0,void * arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  node->set_tvf((const googlesql::TableValuedFunction *)arg1);
}

void GO_EXPORT(ResolvedTVFScan_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)node->signature().get();
}

void GO_EXPORT(ResolvedTVFScan_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  googlesql::TVFSignature *sig = (googlesql::TVFSignature *)arg1;
  std::shared_ptr<googlesql::TVFSignature> p = std::make_shared<googlesql::TVFSignature>(
    sig->input_arguments(),
    sig->result_schema(),
    sig->options()
  );
  node->set_signature(p);
}

void GO_EXPORT(ResolvedTVFScan_argument_list)(void * arg0,void ** arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedTVFScan_set_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedTVFScan_add_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_argument_list, ResolvedFunctionArgument, arg1);
}

void GO_EXPORT(ResolvedTVFScan_column_index_list)(void * arg0,void ** arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  GET_INTS(node->column_index_list, arg1);
}

void GO_EXPORT(ResolvedTVFScan_set_column_index_list)(void * arg0,void * arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  SET_INTS(node->set_column_index_list, arg1);
}

void GO_EXPORT(ResolvedTVFScan_add_column_index_list)(void * arg0,int arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  node->add_column_index_list(arg1);
}

void GO_EXPORT(ResolvedTVFScan_alias)(void * arg0,void ** arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)((new std::string(node->alias()))->c_str());
}

void GO_EXPORT(ResolvedTVFScan_set_alias)(void * arg0,void * arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  node->set_alias((char *)arg1);
}

void GO_EXPORT(ResolvedTVFScan_function_call_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  *arg1 = (void *)node->function_call_signature().get();
}

void GO_EXPORT(ResolvedTVFScan_set_function_call_signature)(void * arg0,void * arg1){
  googlesql::ResolvedTVFScan *node = (googlesql::ResolvedTVFScan *)arg0;
  googlesql::FunctionSignature *sig = (googlesql::FunctionSignature *)arg1;
  auto p = std::make_shared<googlesql::FunctionSignature>(*sig, (void *)sig->context_ptr());
  node->set_function_call_signature(p);
}

void GO_EXPORT(ResolvedGroupRowsScan_input_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedGroupRowsScan *node = (googlesql::ResolvedGroupRowsScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->input_column_list, arg1);
}

void GO_EXPORT(ResolvedGroupRowsScan_set_input_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedGroupRowsScan *node = (googlesql::ResolvedGroupRowsScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedGroupRowsScan_add_input_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedGroupRowsScan *node = (googlesql::ResolvedGroupRowsScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedGroupRowsScan_alias)(void * arg0,void ** arg1){
  googlesql::ResolvedGroupRowsScan *node = (googlesql::ResolvedGroupRowsScan *)arg0;
  *arg1 = (void *)((new std::string(node->alias()))->c_str());
}

void GO_EXPORT(ResolvedGroupRowsScan_set_alias)(void * arg0,void * arg1){
  googlesql::ResolvedGroupRowsScan *node = (googlesql::ResolvedGroupRowsScan *)arg0;
  node->set_alias((char *)arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedFunctionArgument_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFunctionArgument_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->scan();
}

void GO_EXPORT(ResolvedFunctionArgument_set_scan)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  node->set_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedFunctionArgument_model)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->model();
}

void GO_EXPORT(ResolvedFunctionArgument_set_model)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_model, ResolvedModel, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_connection)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedFunctionArgument_set_connection)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_descriptor_arg)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->descriptor_arg();
}

void GO_EXPORT(ResolvedFunctionArgument_set_descriptor_arg)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_descriptor_arg, ResolvedDescriptor, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_argument_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  GET_LIST(node->argument_column_list, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_set_argument_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  SET_LIST(node->set_argument_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_add_argument_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  ADD_LIST(node->add_argument_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedFunctionArgument_inline_lambda)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  *arg1 = (void *)node->inline_lambda();
}

void GO_EXPORT(ResolvedFunctionArgument_set_inline_lambda)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionArgument *node = (googlesql::ResolvedFunctionArgument *)arg0;
  SET_UNIQUE_PTR(node->set_inline_lambda, ResolvedInlineLambda, arg1);
}

void GO_EXPORT(ResolvedStatement_hint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedStatement *node = (googlesql::ResolvedStatement *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedStatement_set_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedStatement *node = (googlesql::ResolvedStatement *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedStatement_add_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedStatement *node = (googlesql::ResolvedStatement *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExplainStmt_statement)(void * arg0,void ** arg1){
  googlesql::ResolvedExplainStmt *node = (googlesql::ResolvedExplainStmt *)arg0;
  *arg1 = (void *)node->statement();
}

void GO_EXPORT(ResolvedExplainStmt_set_statement)(void * arg0,void * arg1){
  googlesql::ResolvedExplainStmt *node = (googlesql::ResolvedExplainStmt *)arg0;
  node->set_statement(make_unique_stmt(arg1));
}

void GO_EXPORT(ResolvedQueryStmt_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedQueryStmt *node = (googlesql::ResolvedQueryStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedQueryStmt_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedQueryStmt *node = (googlesql::ResolvedQueryStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedQueryStmt_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedQueryStmt *node = (googlesql::ResolvedQueryStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedQueryStmt_is_value_table)(void * arg0,char* arg1){
  googlesql::ResolvedQueryStmt *node = (googlesql::ResolvedQueryStmt *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedQueryStmt_set_is_value_table)(void * arg0,int arg1){
  googlesql::ResolvedQueryStmt *node = (googlesql::ResolvedQueryStmt *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedQueryStmt_query)(void * arg0,void ** arg1){
  googlesql::ResolvedQueryStmt *node = (googlesql::ResolvedQueryStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedQueryStmt_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedQueryStmt *node = (googlesql::ResolvedQueryStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateDatabaseStmt *node = (googlesql::ResolvedCreateDatabaseStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateDatabaseStmt *node = (googlesql::ResolvedCreateDatabaseStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateDatabaseStmt *node = (googlesql::ResolvedCreateDatabaseStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateDatabaseStmt *node = (googlesql::ResolvedCreateDatabaseStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateDatabaseStmt *node = (googlesql::ResolvedCreateDatabaseStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateDatabaseStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateDatabaseStmt *node = (googlesql::ResolvedCreateDatabaseStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateStatement_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateStatement *node = (googlesql::ResolvedCreateStatement *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedCreateStatement_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateStatement *node = (googlesql::ResolvedCreateStatement *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateStatement_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateStatement *node = (googlesql::ResolvedCreateStatement *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateStatement_create_scope)(void * arg0,int* arg1){
  googlesql::ResolvedCreateStatement *node = (googlesql::ResolvedCreateStatement *)arg0;
  *arg1 = node->create_scope();
}

void GO_EXPORT(ResolvedCreateStatement_set_create_scope)(void * arg0,int arg1){
  googlesql::ResolvedCreateStatement *node = (googlesql::ResolvedCreateStatement *)arg0;
  node->set_create_scope((googlesql::ResolvedCreateStatement::CreateScope)arg1);
}

void GO_EXPORT(ResolvedCreateStatement_create_mode)(void * arg0,int* arg1){
  googlesql::ResolvedCreateStatement *node = (googlesql::ResolvedCreateStatement *)arg0;
  *arg1 = node->create_mode();
}

void GO_EXPORT(ResolvedCreateStatement_set_create_mode)(void * arg0,int arg1){
  googlesql::ResolvedCreateStatement *node = (googlesql::ResolvedCreateStatement *)arg0;
  node->set_create_mode((googlesql::ResolvedCreateStatement::CreateMode)arg1);
}

void GO_EXPORT(ResolvedIndexItem_column_ref)(void * arg0,void ** arg1){
  googlesql::ResolvedIndexItem *node = (googlesql::ResolvedIndexItem *)arg0;
  *arg1 = (void *)node->column_ref();
}

void GO_EXPORT(ResolvedIndexItem_set_column_ref)(void * arg0,void * arg1){
  googlesql::ResolvedIndexItem *node = (googlesql::ResolvedIndexItem *)arg0;
  SET_UNIQUE_PTR(node->set_column_ref, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedIndexItem_descending)(void * arg0,char* arg1){
  googlesql::ResolvedIndexItem *node = (googlesql::ResolvedIndexItem *)arg0;
  *arg1 = node->descending();
}

void GO_EXPORT(ResolvedIndexItem_set_descending)(void * arg0,int arg1){
  googlesql::ResolvedIndexItem *node = (googlesql::ResolvedIndexItem *)arg0;
  node->set_descending(arg1);
}

void GO_EXPORT(ResolvedUnnestItem_array_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedUnnestItem *node = (googlesql::ResolvedUnnestItem *)arg0;
  *arg1 = (void *)node->array_expr();
}

void GO_EXPORT(ResolvedUnnestItem_set_array_expr)(void * arg0,void * arg1){
  googlesql::ResolvedUnnestItem *node = (googlesql::ResolvedUnnestItem *)arg0;
  node->set_array_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUnnestItem_element_column)(void * arg0,void ** arg1){
  googlesql::ResolvedUnnestItem *node = (googlesql::ResolvedUnnestItem *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->element_column()));
}

void GO_EXPORT(ResolvedUnnestItem_set_element_column)(void * arg0,void * arg1){
  googlesql::ResolvedUnnestItem *node = (googlesql::ResolvedUnnestItem *)arg0;
  node->set_element_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedUnnestItem_array_offset_column)(void * arg0,void ** arg1){
  googlesql::ResolvedUnnestItem *node = (googlesql::ResolvedUnnestItem *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedUnnestItem_set_array_offset_column)(void * arg0,void * arg1){
  googlesql::ResolvedUnnestItem *node = (googlesql::ResolvedUnnestItem *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_table_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  GET_STRS(node->table_name_path, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_table_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  SET_LIST(node->set_table_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_table_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  node->add_table_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_is_unique)(void * arg0,char* arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = node->is_unique();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_is_unique)(void * arg0,int arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  node->set_is_unique(arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_is_search)(void * arg0,char* arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = node->is_search();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_is_search)(void * arg0,int arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  node->set_is_search(arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_index_all_columns)(void * arg0,char* arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  *arg1 = node->index_all_columns();
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_index_all_columns)(void * arg0,int arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  node->set_index_all_columns(arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_index_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->index_item_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_index_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_index_item_list, ResolvedIndexItem, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_index_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_index_item_list, ResolvedIndexItem, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_storing_expression_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->storing_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_storing_expression_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_storing_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_storing_expression_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_storing_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_computed_columns_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->computed_columns_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_computed_columns_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_computed_columns_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_computed_columns_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_computed_columns_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_unnest_expressions_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->unnest_expressions_list, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_set_unnest_expressions_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_unnest_expressions_list, ResolvedUnnestItem, arg1);
}

void GO_EXPORT(ResolvedCreateIndexStmt_add_unnest_expressions_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateIndexStmt *node = (googlesql::ResolvedCreateIndexStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_unnest_expressions_list, ResolvedUnnestItem, arg1);
}

void GO_EXPORT(ResolvedCreateSchemaStmt_collation_name)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateSchemaStmt *node = (googlesql::ResolvedCreateSchemaStmt *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedCreateSchemaStmt_set_collation_name)(void * arg0,void * arg1){
  googlesql::ResolvedCreateSchemaStmt *node = (googlesql::ResolvedCreateSchemaStmt *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateSchemaStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateSchemaStmt *node = (googlesql::ResolvedCreateSchemaStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateSchemaStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateSchemaStmt *node = (googlesql::ResolvedCreateSchemaStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateSchemaStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateSchemaStmt *node = (googlesql::ResolvedCreateSchemaStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_column_definition_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_pseudo_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  GET_LIST(node->pseudo_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_pseudo_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  SET_LIST(node->set_pseudo_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_pseudo_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  ADD_LIST(node->add_pseudo_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_primary_key)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->primary_key();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_primary_key)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR(node->set_primary_key, ResolvedPrimaryKey, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_foreign_key_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->foreign_key_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_foreign_key_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_foreign_key_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_check_constraint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->check_constraint_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_check_constraint_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_add_check_constraint_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_is_value_table)(void * arg0,char* arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_is_value_table)(void * arg0,int arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_like_table)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->like_table();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_like_table)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  node->set_like_table((const googlesql::Table *)arg1);
}

void GO_EXPORT(ResolvedCreateTableStmtBase_collation_name)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedCreateTableStmtBase_set_collation_name)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmtBase *node = (googlesql::ResolvedCreateTableStmtBase *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateTableStmt_clone_from)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  *arg1 = (void *)node->clone_from();
}

void GO_EXPORT(ResolvedCreateTableStmt_set_clone_from)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  node->set_clone_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateTableStmt_copy_from)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  *arg1 = (void *)node->copy_from();
}

void GO_EXPORT(ResolvedCreateTableStmt_set_copy_from)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  node->set_copy_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateTableStmt_partition_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_set_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_add_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_cluster_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_set_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableStmt_add_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableStmt *node = (googlesql::ResolvedCreateTableStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_partition_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_cluster_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_query)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateTableAsSelectStmt_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableAsSelectStmt *node = (googlesql::ResolvedCreateTableAsSelectStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateModelStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_query)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateModelStmt_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_input_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_input_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_input_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_input_column_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_input_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_input_column_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_transform_analytic_function_group_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->transform_analytic_function_group_list, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_set_transform_analytic_function_group_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_transform_analytic_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedCreateModelStmt_add_transform_analytic_function_group_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateModelStmt *node = (googlesql::ResolvedCreateModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_transform_analytic_function_group_list, ResolvedAnalyticFunctionGroup, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_has_explicit_columns)(void * arg0,char* arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->has_explicit_columns();
}

void GO_EXPORT(ResolvedCreateViewBase_set_has_explicit_columns)(void * arg0,int arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  node->set_has_explicit_columns(arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_query)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateViewBase_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateViewBase_sql)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  *arg1 = (void *)((new std::string(node->sql()))->c_str());
}

void GO_EXPORT(ResolvedCreateViewBase_set_sql)(void * arg0,void * arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  node->set_sql((char *)arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_sql_security)(void * arg0,int* arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->sql_security();
}

void GO_EXPORT(ResolvedCreateViewBase_set_sql_security)(void * arg0,int arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  node->set_sql_security((googlesql::ResolvedCreateViewBase::SqlSecurity)arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_is_value_table)(void * arg0,char* arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedCreateViewBase_set_is_value_table)(void * arg0,int arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedCreateViewBase_recursive)(void * arg0,char* arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  *arg1 = node->recursive();
}

void GO_EXPORT(ResolvedCreateViewBase_set_recursive)(void * arg0,int arg1){
  googlesql::ResolvedCreateViewBase *node = (googlesql::ResolvedCreateViewBase *)arg0;
  node->set_recursive(arg1);
}

void GO_EXPORT(ResolvedWithPartitionColumns_column_definition_list)(void * arg0,void ** arg1){
  googlesql::ResolvedWithPartitionColumns *node = (googlesql::ResolvedWithPartitionColumns *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedWithPartitionColumns_set_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedWithPartitionColumns *node = (googlesql::ResolvedWithPartitionColumns *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedWithPartitionColumns_add_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedWithPartitionColumns *node = (googlesql::ResolvedWithPartitionColumns *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_clone_from)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateSnapshotTableStmt *node = (googlesql::ResolvedCreateSnapshotTableStmt *)arg0;
  *arg1 = (void *)node->clone_from();
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_set_clone_from)(void * arg0,void * arg1){
  googlesql::ResolvedCreateSnapshotTableStmt *node = (googlesql::ResolvedCreateSnapshotTableStmt *)arg0;
  node->set_clone_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateSnapshotTableStmt *node = (googlesql::ResolvedCreateSnapshotTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateSnapshotTableStmt *node = (googlesql::ResolvedCreateSnapshotTableStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateSnapshotTableStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateSnapshotTableStmt *node = (googlesql::ResolvedCreateSnapshotTableStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_with_partition_columns)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateExternalTableStmt *node = (googlesql::ResolvedCreateExternalTableStmt *)arg0;
  *arg1 = (void *)node->with_partition_columns();
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_set_with_partition_columns)(void * arg0,void * arg1){
  googlesql::ResolvedCreateExternalTableStmt *node = (googlesql::ResolvedCreateExternalTableStmt *)arg0;
  SET_UNIQUE_PTR(node->set_with_partition_columns, ResolvedWithPartitionColumns, arg1);
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_connection)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateExternalTableStmt *node = (googlesql::ResolvedCreateExternalTableStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedCreateExternalTableStmt_set_connection)(void * arg0,void * arg1){
  googlesql::ResolvedCreateExternalTableStmt *node = (googlesql::ResolvedCreateExternalTableStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_model_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  GET_STRS(node->model_name_path, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_set_model_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  SET_LIST(node->set_model_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_add_model_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  node->add_model_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_connection)(void * arg0,void ** arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedExportModelStmt_set_connection)(void * arg0,void * arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportModelStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedExportModelStmt *node = (googlesql::ResolvedExportModelStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_connection)(void * arg0,void ** arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedExportDataStmt_set_connection)(void * arg0,void * arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_is_value_table)(void * arg0,char* arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedExportDataStmt_set_is_value_table)(void * arg0,int arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedExportDataStmt_query)(void * arg0,void ** arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedExportDataStmt_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedExportDataStmt *node = (googlesql::ResolvedExportDataStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedDefineTableStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDefineTableStmt *node = (googlesql::ResolvedDefineTableStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDefineTableStmt *node = (googlesql::ResolvedDefineTableStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDefineTableStmt *node = (googlesql::ResolvedDefineTableStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedDefineTableStmt *node = (googlesql::ResolvedDefineTableStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedDefineTableStmt *node = (googlesql::ResolvedDefineTableStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedDefineTableStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedDefineTableStmt *node = (googlesql::ResolvedDefineTableStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_object_type)(void * arg0,void ** arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedDescribeStmt_set_object_type)(void * arg0,void * arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_from_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  GET_STRS(node->from_name_path, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_set_from_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  SET_LIST(node->set_from_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDescribeStmt_add_from_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDescribeStmt *node = (googlesql::ResolvedDescribeStmt *)arg0;
  node->add_from_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedShowStmt_identifier)(void * arg0,void ** arg1){
  googlesql::ResolvedShowStmt *node = (googlesql::ResolvedShowStmt *)arg0;
  *arg1 = (void *)((new std::string(node->identifier()))->c_str());
}

void GO_EXPORT(ResolvedShowStmt_set_identifier)(void * arg0,void * arg1){
  googlesql::ResolvedShowStmt *node = (googlesql::ResolvedShowStmt *)arg0;
  node->set_identifier((char *)arg1);
}

void GO_EXPORT(ResolvedShowStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedShowStmt *node = (googlesql::ResolvedShowStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedShowStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedShowStmt *node = (googlesql::ResolvedShowStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedShowStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedShowStmt *node = (googlesql::ResolvedShowStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedShowStmt_like_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedShowStmt *node = (googlesql::ResolvedShowStmt *)arg0;
  *arg1 = (void *)node->like_expr();
}

void GO_EXPORT(ResolvedShowStmt_set_like_expr)(void * arg0,void * arg1){
  googlesql::ResolvedShowStmt *node = (googlesql::ResolvedShowStmt *)arg0;
  SET_UNIQUE_PTR(node->set_like_expr, ResolvedLiteral, arg1);
}

void GO_EXPORT(ResolvedBeginStmt_read_write_mode)(void * arg0,int* arg1){
  googlesql::ResolvedBeginStmt *node = (googlesql::ResolvedBeginStmt *)arg0;
  *arg1 = node->read_write_mode();
}

void GO_EXPORT(ResolvedBeginStmt_set_read_write_mode)(void * arg0,int arg1){
  googlesql::ResolvedBeginStmt *node = (googlesql::ResolvedBeginStmt *)arg0;
  node->set_read_write_mode((googlesql::ResolvedBeginStmt::ReadWriteMode)arg1);
}

void GO_EXPORT(ResolvedBeginStmt_isolation_level_list)(void * arg0,void ** arg1){
  googlesql::ResolvedBeginStmt *node = (googlesql::ResolvedBeginStmt *)arg0;
  GET_STRS(node->isolation_level_list, arg1);
}

void GO_EXPORT(ResolvedBeginStmt_set_isolation_level_list)(void * arg0,void * arg1){
  googlesql::ResolvedBeginStmt *node = (googlesql::ResolvedBeginStmt *)arg0;
  SET_LIST(node->set_isolation_level_list, std::string, arg1);
}

void GO_EXPORT(ResolvedBeginStmt_add_isolation_level_list)(void * arg0,void * arg1){
  googlesql::ResolvedBeginStmt *node = (googlesql::ResolvedBeginStmt *)arg0;
  node->add_isolation_level_list((char *)arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_read_write_mode)(void * arg0,int* arg1){
  googlesql::ResolvedSetTransactionStmt *node = (googlesql::ResolvedSetTransactionStmt *)arg0;
  *arg1 = node->read_write_mode();
}

void GO_EXPORT(ResolvedSetTransactionStmt_set_read_write_mode)(void * arg0,int arg1){
  googlesql::ResolvedSetTransactionStmt *node = (googlesql::ResolvedSetTransactionStmt *)arg0;
  node->set_read_write_mode((googlesql::ResolvedSetTransactionStmt::ReadWriteMode)arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_isolation_level_list)(void * arg0,void ** arg1){
  googlesql::ResolvedSetTransactionStmt *node = (googlesql::ResolvedSetTransactionStmt *)arg0;
  GET_STRS(node->isolation_level_list, arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_set_isolation_level_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetTransactionStmt *node = (googlesql::ResolvedSetTransactionStmt *)arg0;
  SET_LIST(node->set_isolation_level_list, std::string, arg1);
}

void GO_EXPORT(ResolvedSetTransactionStmt_add_isolation_level_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetTransactionStmt *node = (googlesql::ResolvedSetTransactionStmt *)arg0;
  node->add_isolation_level_list((char *)arg1);
}

void GO_EXPORT(ResolvedStartBatchStmt_batch_type)(void * arg0,void ** arg1){
  googlesql::ResolvedStartBatchStmt *node = (googlesql::ResolvedStartBatchStmt *)arg0;
  *arg1 = (void *)((new std::string(node->batch_type()))->c_str());
}

void GO_EXPORT(ResolvedStartBatchStmt_set_batch_type)(void * arg0,void * arg1){
  googlesql::ResolvedStartBatchStmt *node = (googlesql::ResolvedStartBatchStmt *)arg0;
  node->set_batch_type((char *)arg1);
}

void GO_EXPORT(ResolvedDropStmt_object_type)(void * arg0,void ** arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedDropStmt_set_object_type)(void * arg0,void * arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedDropStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropStmt_drop_mode)(void * arg0,int* arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  *arg1 = node->drop_mode();
}

void GO_EXPORT(ResolvedDropStmt_set_drop_mode)(void * arg0,int arg1){
  googlesql::ResolvedDropStmt *node = (googlesql::ResolvedDropStmt *)arg0;
  node->set_drop_mode((googlesql::ResolvedDropStmt::DropMode)arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropMaterializedViewStmt *node = (googlesql::ResolvedDropMaterializedViewStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropMaterializedViewStmt *node = (googlesql::ResolvedDropMaterializedViewStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropMaterializedViewStmt *node = (googlesql::ResolvedDropMaterializedViewStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropMaterializedViewStmt *node = (googlesql::ResolvedDropMaterializedViewStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropMaterializedViewStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropMaterializedViewStmt *node = (googlesql::ResolvedDropMaterializedViewStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropSnapshotTableStmt *node = (googlesql::ResolvedDropSnapshotTableStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropSnapshotTableStmt *node = (googlesql::ResolvedDropSnapshotTableStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropSnapshotTableStmt *node = (googlesql::ResolvedDropSnapshotTableStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropSnapshotTableStmt *node = (googlesql::ResolvedDropSnapshotTableStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropSnapshotTableStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropSnapshotTableStmt *node = (googlesql::ResolvedDropSnapshotTableStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedRecursiveScan_op_type)(void * arg0,int* arg1){
  googlesql::ResolvedRecursiveScan *node = (googlesql::ResolvedRecursiveScan *)arg0;
  *arg1 = node->op_type();
}

void GO_EXPORT(ResolvedRecursiveScan_set_op_type)(void * arg0,int arg1){
  googlesql::ResolvedRecursiveScan *node = (googlesql::ResolvedRecursiveScan *)arg0;
  node->set_op_type((googlesql::ResolvedRecursiveScan::RecursiveSetOperationType)arg1);
}

void GO_EXPORT(ResolvedRecursiveScan_non_recursive_term)(void * arg0,void ** arg1){
  googlesql::ResolvedRecursiveScan *node = (googlesql::ResolvedRecursiveScan *)arg0;
  *arg1 = (void *)node->non_recursive_term();
}

void GO_EXPORT(ResolvedRecursiveScan_set_non_recursive_term)(void * arg0,void * arg1){
  googlesql::ResolvedRecursiveScan *node = (googlesql::ResolvedRecursiveScan *)arg0;
  SET_UNIQUE_PTR(node->set_non_recursive_term, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedRecursiveScan_recursive_term)(void * arg0,void ** arg1){
  googlesql::ResolvedRecursiveScan *node = (googlesql::ResolvedRecursiveScan *)arg0;
  *arg1 = (void *)node->recursive_term();
}

void GO_EXPORT(ResolvedRecursiveScan_set_recursive_term)(void * arg0,void * arg1){
  googlesql::ResolvedRecursiveScan *node = (googlesql::ResolvedRecursiveScan *)arg0;
  SET_UNIQUE_PTR(node->set_recursive_term, ResolvedSetOperationItem, arg1);
}

void GO_EXPORT(ResolvedWithScan_with_entry_list)(void * arg0,void ** arg1){
  googlesql::ResolvedWithScan *node = (googlesql::ResolvedWithScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->with_entry_list, arg1);
}

void GO_EXPORT(ResolvedWithScan_set_with_entry_list)(void * arg0,void * arg1){
  googlesql::ResolvedWithScan *node = (googlesql::ResolvedWithScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_with_entry_list, ResolvedWithEntry, arg1);
}

void GO_EXPORT(ResolvedWithScan_add_with_entry_list)(void * arg0,void * arg1){
  googlesql::ResolvedWithScan *node = (googlesql::ResolvedWithScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_with_entry_list, ResolvedWithEntry, arg1);
}

void GO_EXPORT(ResolvedWithScan_query)(void * arg0,void ** arg1){
  googlesql::ResolvedWithScan *node = (googlesql::ResolvedWithScan *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedWithScan_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedWithScan *node = (googlesql::ResolvedWithScan *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedWithScan_recursive)(void * arg0,char* arg1){
  googlesql::ResolvedWithScan *node = (googlesql::ResolvedWithScan *)arg0;
  *arg1 = node->recursive();
}

void GO_EXPORT(ResolvedWithScan_set_recursive)(void * arg0,int arg1){
  googlesql::ResolvedWithScan *node = (googlesql::ResolvedWithScan *)arg0;
  node->set_recursive(arg1);
}

void GO_EXPORT(ResolvedWithEntry_with_query_name)(void * arg0,void ** arg1){
  googlesql::ResolvedWithEntry *node = (googlesql::ResolvedWithEntry *)arg0;
  *arg1 = (void *)((new std::string(node->with_query_name()))->c_str());
}

void GO_EXPORT(ResolvedWithEntry_set_with_query_name)(void * arg0,void * arg1){
  googlesql::ResolvedWithEntry *node = (googlesql::ResolvedWithEntry *)arg0;
  node->set_with_query_name((char *)arg1);
}

void GO_EXPORT(ResolvedWithEntry_with_subquery)(void * arg0,void ** arg1){
  googlesql::ResolvedWithEntry *node = (googlesql::ResolvedWithEntry *)arg0;
  *arg1 = (void *)node->with_subquery();
}

void GO_EXPORT(ResolvedWithEntry_set_with_subquery)(void * arg0,void * arg1){
  googlesql::ResolvedWithEntry *node = (googlesql::ResolvedWithEntry *)arg0;
  node->set_with_subquery(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedOption_qualifier)(void * arg0,void ** arg1){
  googlesql::ResolvedOption *node = (googlesql::ResolvedOption *)arg0;
  *arg1 = (void *)((new std::string(node->qualifier()))->c_str());
}

void GO_EXPORT(ResolvedOption_set_qualifier)(void * arg0,void * arg1){
  googlesql::ResolvedOption *node = (googlesql::ResolvedOption *)arg0;
  node->set_qualifier((char *)arg1);
}

void GO_EXPORT(ResolvedOption_name)(void * arg0,void ** arg1){
  googlesql::ResolvedOption *node = (googlesql::ResolvedOption *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedOption_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedOption *node = (googlesql::ResolvedOption *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedOption_value)(void * arg0,void ** arg1){
  googlesql::ResolvedOption *node = (googlesql::ResolvedOption *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ResolvedOption_set_value)(void * arg0,void * arg1){
  googlesql::ResolvedOption *node = (googlesql::ResolvedOption *)arg0;
  node->set_value(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedWindowPartitioning_partition_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedWindowPartitioning *node = (googlesql::ResolvedWindowPartitioning *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_set_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowPartitioning *node = (googlesql::ResolvedWindowPartitioning *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_partition_by_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_add_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowPartitioning *node = (googlesql::ResolvedWindowPartitioning *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_partition_by_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_hint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedWindowPartitioning *node = (googlesql::ResolvedWindowPartitioning *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_set_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowPartitioning *node = (googlesql::ResolvedWindowPartitioning *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowPartitioning_add_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowPartitioning *node = (googlesql::ResolvedWindowPartitioning *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_order_by_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedWindowOrdering *node = (googlesql::ResolvedWindowOrdering *)arg0;
  GET_UNIQUE_PTR_LIST(node->order_by_item_list, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_set_order_by_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowOrdering *node = (googlesql::ResolvedWindowOrdering *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_add_order_by_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowOrdering *node = (googlesql::ResolvedWindowOrdering *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_order_by_item_list, ResolvedOrderByItem, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_hint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedWindowOrdering *node = (googlesql::ResolvedWindowOrdering *)arg0;
  GET_UNIQUE_PTR_LIST(node->hint_list, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_set_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowOrdering *node = (googlesql::ResolvedWindowOrdering *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowOrdering_add_hint_list)(void * arg0,void * arg1){
  googlesql::ResolvedWindowOrdering *node = (googlesql::ResolvedWindowOrdering *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_hint_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedWindowFrame_frame_unit)(void * arg0,int* arg1){
  googlesql::ResolvedWindowFrame *node = (googlesql::ResolvedWindowFrame *)arg0;
  *arg1 = node->frame_unit();
}

void GO_EXPORT(ResolvedWindowFrame_set_frame_unit)(void * arg0,int arg1){
  googlesql::ResolvedWindowFrame *node = (googlesql::ResolvedWindowFrame *)arg0;
  node->set_frame_unit((googlesql::ResolvedWindowFrame::FrameUnit)arg1);
}

void GO_EXPORT(ResolvedWindowFrame_start_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedWindowFrame *node = (googlesql::ResolvedWindowFrame *)arg0;
  *arg1 = (void *)node->start_expr();
}

void GO_EXPORT(ResolvedWindowFrame_set_start_expr)(void * arg0,void * arg1){
  googlesql::ResolvedWindowFrame *node = (googlesql::ResolvedWindowFrame *)arg0;
  SET_UNIQUE_PTR(node->set_start_expr, ResolvedWindowFrameExpr, arg1);
}

void GO_EXPORT(ResolvedWindowFrame_end_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedWindowFrame *node = (googlesql::ResolvedWindowFrame *)arg0;
  *arg1 = (void *)node->end_expr();
}

void GO_EXPORT(ResolvedWindowFrame_set_end_expr)(void * arg0,void * arg1){
  googlesql::ResolvedWindowFrame *node = (googlesql::ResolvedWindowFrame *)arg0;
  SET_UNIQUE_PTR(node->set_end_expr, ResolvedWindowFrameExpr, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_partition_by)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyticFunctionGroup *node = (googlesql::ResolvedAnalyticFunctionGroup *)arg0;
  *arg1 = (void *)node->partition_by();
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_partition_by)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticFunctionGroup *node = (googlesql::ResolvedAnalyticFunctionGroup *)arg0;
  SET_UNIQUE_PTR(node->set_partition_by, ResolvedWindowPartitioning, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_order_by)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyticFunctionGroup *node = (googlesql::ResolvedAnalyticFunctionGroup *)arg0;
  *arg1 = (void *)node->order_by();
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_order_by)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticFunctionGroup *node = (googlesql::ResolvedAnalyticFunctionGroup *)arg0;
  SET_UNIQUE_PTR(node->set_order_by, ResolvedWindowOrdering, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_analytic_function_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyticFunctionGroup *node = (googlesql::ResolvedAnalyticFunctionGroup *)arg0;
  GET_UNIQUE_PTR_LIST(node->analytic_function_list, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_set_analytic_function_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticFunctionGroup *node = (googlesql::ResolvedAnalyticFunctionGroup *)arg0;
  SET_UNIQUE_PTR_COMPUTED_COLUMN_BASE_LIST(node->set_analytic_function_list, arg1);
}

void GO_EXPORT(ResolvedAnalyticFunctionGroup_add_analytic_function_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyticFunctionGroup *node = (googlesql::ResolvedAnalyticFunctionGroup *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_analytic_function_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedWindowFrameExpr_boundary_type)(void * arg0,int* arg1){
  googlesql::ResolvedWindowFrameExpr *node = (googlesql::ResolvedWindowFrameExpr *)arg0;
  *arg1 = node->boundary_type();
}

void GO_EXPORT(ResolvedWindowFrameExpr_set_boundary_type)(void * arg0,int arg1){
  googlesql::ResolvedWindowFrameExpr *node = (googlesql::ResolvedWindowFrameExpr *)arg0;
  node->set_boundary_type((googlesql::ResolvedWindowFrameExpr::BoundaryType)arg1);
}

void GO_EXPORT(ResolvedWindowFrameExpr_expression)(void * arg0,void ** arg1){
  googlesql::ResolvedWindowFrameExpr *node = (googlesql::ResolvedWindowFrameExpr *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedWindowFrameExpr_set_expression)(void * arg0,void * arg1){
  googlesql::ResolvedWindowFrameExpr *node = (googlesql::ResolvedWindowFrameExpr *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedDMLValue_value)(void * arg0,void ** arg1){
  googlesql::ResolvedDMLValue *node = (googlesql::ResolvedDMLValue *)arg0;
  *arg1 = (void *)node->value();
}

void GO_EXPORT(ResolvedDMLValue_set_value)(void * arg0,void * arg1){
  googlesql::ResolvedDMLValue *node = (googlesql::ResolvedDMLValue *)arg0;
  node->set_value(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAssertStmt_expression)(void * arg0,void ** arg1){
  googlesql::ResolvedAssertStmt *node = (googlesql::ResolvedAssertStmt *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedAssertStmt_set_expression)(void * arg0,void * arg1){
  googlesql::ResolvedAssertStmt *node = (googlesql::ResolvedAssertStmt *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAssertStmt_description)(void * arg0,void ** arg1){
  googlesql::ResolvedAssertStmt *node = (googlesql::ResolvedAssertStmt *)arg0;
  *arg1 = (void *)((new std::string(node->description()))->c_str());
}

void GO_EXPORT(ResolvedAssertStmt_set_description)(void * arg0,void * arg1){
  googlesql::ResolvedAssertStmt *node = (googlesql::ResolvedAssertStmt *)arg0;
  node->set_description((char *)arg1);
}

void GO_EXPORT(ResolvedAssertRowsModified_rows)(void * arg0,void ** arg1){
  googlesql::ResolvedAssertRowsModified *node = (googlesql::ResolvedAssertRowsModified *)arg0;
  *arg1 = (void *)node->rows();
}

void GO_EXPORT(ResolvedAssertRowsModified_set_rows)(void * arg0,void * arg1){
  googlesql::ResolvedAssertRowsModified *node = (googlesql::ResolvedAssertRowsModified *)arg0;
  node->set_rows(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedInsertRow_value_list)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertRow *node = (googlesql::ResolvedInsertRow *)arg0;
  GET_UNIQUE_PTR_LIST(node->value_list, arg1);
}

void GO_EXPORT(ResolvedInsertRow_set_value_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertRow *node = (googlesql::ResolvedInsertRow *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_value_list, ResolvedDMLValue, arg1);
}

void GO_EXPORT(ResolvedInsertRow_add_value_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertRow *node = (googlesql::ResolvedInsertRow *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_value_list, ResolvedDMLValue, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedInsertStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_insert_mode)(void * arg0,int* arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  *arg1 = node->insert_mode();
}

void GO_EXPORT(ResolvedInsertStmt_set_insert_mode)(void * arg0,int arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  node->set_insert_mode((googlesql::ResolvedInsertStmt::InsertMode)arg1);
}

void GO_EXPORT(ResolvedInsertStmt_assert_rows_modified)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ResolvedInsertStmt_set_assert_rows_modified)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR(node->set_assert_rows_modified, ResolvedAssertRowsModified, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_returning)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ResolvedInsertStmt_set_returning)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR(node->set_returning, ResolvedReturningClause, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_insert_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  GET_LIST(node->insert_column_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_insert_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  SET_LIST(node->set_insert_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_insert_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  ADD_LIST(node->add_insert_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_query_parameter_list)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->query_parameter_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_query_parameter_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_query_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_query_parameter_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_query_parameter_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_query)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedInsertStmt_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedInsertStmt_query_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  GET_LIST(node->query_output_column_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_query_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  SET_LIST(node->set_query_output_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_query_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  ADD_LIST(node->add_query_output_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_row_list)(void * arg0,void ** arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->row_list, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_set_row_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_row_list, ResolvedInsertRow, arg1);
}

void GO_EXPORT(ResolvedInsertStmt_add_row_list)(void * arg0,void * arg1){
  googlesql::ResolvedInsertStmt *node = (googlesql::ResolvedInsertStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_row_list, ResolvedInsertRow, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedDeleteStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_assert_rows_modified)(void * arg0,void ** arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ResolvedDeleteStmt_set_assert_rows_modified)(void * arg0,void * arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_assert_rows_modified, ResolvedAssertRowsModified, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_returning)(void * arg0,void ** arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ResolvedDeleteStmt_set_returning)(void * arg0,void * arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_returning, ResolvedReturningClause, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_array_offset_column)(void * arg0,void ** arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedDeleteStmt_set_array_offset_column)(void * arg0,void * arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedDeleteStmt_where_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  *arg1 = (void *)node->where_expr();
}

void GO_EXPORT(ResolvedDeleteStmt_set_where_expr)(void * arg0,void * arg1){
  googlesql::ResolvedDeleteStmt *node = (googlesql::ResolvedDeleteStmt *)arg0;
  node->set_where_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateItem_target)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  *arg1 = (void *)node->target();
}

void GO_EXPORT(ResolvedUpdateItem_set_target)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  node->set_target(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateItem_set_value)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  *arg1 = (void *)node->set_value();
}

void GO_EXPORT(ResolvedUpdateItem_set_set_value)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR(node->set_set_value, ResolvedDMLValue, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_element_column)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  *arg1 = (void *)node->element_column();
}

void GO_EXPORT(ResolvedUpdateItem_set_element_column)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR(node->set_element_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_update_item_element_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->update_item_element_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_update_item_element_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_update_item_element_list, ResolvedUpdateItemElement, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_update_item_element_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_update_item_element_list, ResolvedUpdateItemElement, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_delete_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->delete_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_delete_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_delete_list, ResolvedDeleteStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_delete_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_delete_list, ResolvedDeleteStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_update_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->update_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_update_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_update_list, ResolvedUpdateStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_update_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_update_list, ResolvedUpdateStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_insert_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  GET_UNIQUE_PTR_LIST(node->insert_list, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_set_insert_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_insert_list, ResolvedInsertStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItem_add_insert_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItem *node = (googlesql::ResolvedUpdateItem *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_insert_list, ResolvedInsertStmt, arg1);
}

void GO_EXPORT(ResolvedUpdateItemElement_subscript)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItemElement *node = (googlesql::ResolvedUpdateItemElement *)arg0;
  *arg1 = (void *)node->subscript();
}

void GO_EXPORT(ResolvedUpdateItemElement_set_subscript)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItemElement *node = (googlesql::ResolvedUpdateItemElement *)arg0;
  node->set_subscript(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateItemElement_update_item)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateItemElement *node = (googlesql::ResolvedUpdateItemElement *)arg0;
  *arg1 = (void *)node->update_item();
}

void GO_EXPORT(ResolvedUpdateItemElement_set_update_item)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateItemElement *node = (googlesql::ResolvedUpdateItemElement *)arg0;
  SET_UNIQUE_PTR(node->set_update_item, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedUpdateItemElement_update_item_mode)(void * arg0,int* arg1){
  googlesql::ResolvedUpdateItemElement *node = (googlesql::ResolvedUpdateItemElement *)arg0;
  *arg1 = (int)node->update_item_mode();
}

void GO_EXPORT(ResolvedUpdateItemElement_set_update_item_mode)(void * arg0,int arg1){
  googlesql::ResolvedUpdateItemElement *node = (googlesql::ResolvedUpdateItemElement *)arg0;
  node->set_update_item_mode((googlesql::ResolvedUpdateItemElement::UpdateItemMode)arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedUpdateStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_column_access_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  GET_ENUMS(node->column_access_list, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_set_column_access_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  SET_ENUMS(node->set_column_access_list, googlesql::ResolvedUpdateStmt::ObjectAccess, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_add_column_access_list)(void * arg0,int arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  node->add_column_access_list((googlesql::ResolvedUpdateStmt::ObjectAccess)arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_assert_rows_modified)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->assert_rows_modified();
}

void GO_EXPORT(ResolvedUpdateStmt_set_assert_rows_modified)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_assert_rows_modified, ResolvedAssertRowsModified, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_returning)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->returning();
}

void GO_EXPORT(ResolvedUpdateStmt_set_returning)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_returning, ResolvedReturningClause, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_array_offset_column)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->array_offset_column();
}

void GO_EXPORT(ResolvedUpdateStmt_set_array_offset_column)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_array_offset_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_where_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->where_expr();
}

void GO_EXPORT(ResolvedUpdateStmt_set_where_expr)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  node->set_where_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedUpdateStmt_update_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->update_item_list, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_set_update_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_add_update_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedUpdateStmt_from_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  *arg1 = (void *)node->from_scan();
}

void GO_EXPORT(ResolvedUpdateStmt_set_from_scan)(void * arg0,void * arg1){
  googlesql::ResolvedUpdateStmt *node = (googlesql::ResolvedUpdateStmt *)arg0;
  node->set_from_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedMergeWhen_match_type)(void * arg0,int* arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  *arg1 = node->match_type();
}

void GO_EXPORT(ResolvedMergeWhen_set_match_type)(void * arg0,int arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  node->set_match_type((googlesql::ResolvedMergeWhen::MatchType)arg1);
}

void GO_EXPORT(ResolvedMergeWhen_match_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  *arg1 = (void *)node->match_expr();
}

void GO_EXPORT(ResolvedMergeWhen_set_match_expr)(void * arg0,void * arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  node->set_match_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedMergeWhen_action_type)(void * arg0,int* arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  *arg1 = node->action_type();
}

void GO_EXPORT(ResolvedMergeWhen_set_action_type)(void * arg0,int arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  node->set_action_type((googlesql::ResolvedMergeWhen::ActionType)arg1);
}

void GO_EXPORT(ResolvedMergeWhen_insert_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  GET_LIST(node->insert_column_list, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_set_insert_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  SET_LIST(node->set_insert_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_add_insert_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  ADD_LIST(node->add_insert_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_insert_row)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  *arg1 = (void *)node->insert_row();
}

void GO_EXPORT(ResolvedMergeWhen_set_insert_row)(void * arg0,void * arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  SET_UNIQUE_PTR(node->set_insert_row, ResolvedInsertRow, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_update_item_list)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  GET_UNIQUE_PTR_LIST(node->update_item_list, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_set_update_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedMergeWhen_add_update_item_list)(void * arg0,void * arg1){
  googlesql::ResolvedMergeWhen *node = (googlesql::ResolvedMergeWhen *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_update_item_list, ResolvedUpdateItem, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedMergeStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_column_access_list)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  GET_ENUMS(node->column_access_list, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_set_column_access_list)(void * arg0,void * arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  SET_ENUMS(node->set_column_access_list, googlesql::ResolvedMergeStmt::ObjectAccess, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_add_column_access_list)(void * arg0,int arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  node->add_column_access_list((googlesql::ResolvedMergeStmt::ObjectAccess)arg1);
}

void GO_EXPORT(ResolvedMergeStmt_from_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  *arg1 = (void *)node->from_scan();
}

void GO_EXPORT(ResolvedMergeStmt_set_from_scan)(void * arg0,void * arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  node->set_from_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedMergeStmt_merge_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  *arg1 = (void *)node->merge_expr();
}

void GO_EXPORT(ResolvedMergeStmt_set_merge_expr)(void * arg0,void * arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  node->set_merge_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedMergeStmt_when_clause_list)(void * arg0,void ** arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->when_clause_list, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_set_when_clause_list)(void * arg0,void * arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_when_clause_list, ResolvedMergeWhen, arg1);
}

void GO_EXPORT(ResolvedMergeStmt_add_when_clause_list)(void * arg0,void * arg1){
  googlesql::ResolvedMergeStmt *node = (googlesql::ResolvedMergeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_when_clause_list, ResolvedMergeWhen, arg1);
}

void GO_EXPORT(ResolvedTruncateStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedTruncateStmt *node = (googlesql::ResolvedTruncateStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedTruncateStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedTruncateStmt *node = (googlesql::ResolvedTruncateStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedTruncateStmt_where_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedTruncateStmt *node = (googlesql::ResolvedTruncateStmt *)arg0;
  *arg1 = (void *)node->where_expr();
}

void GO_EXPORT(ResolvedTruncateStmt_set_where_expr)(void * arg0,void * arg1){
  googlesql::ResolvedTruncateStmt *node = (googlesql::ResolvedTruncateStmt *)arg0;
  node->set_where_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedObjectUnit_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedObjectUnit *node = (googlesql::ResolvedObjectUnit *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedObjectUnit_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedObjectUnit *node = (googlesql::ResolvedObjectUnit *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedObjectUnit_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedObjectUnit *node = (googlesql::ResolvedObjectUnit *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedPrivilege_action_type)(void * arg0,void ** arg1){
  googlesql::ResolvedPrivilege *node = (googlesql::ResolvedPrivilege *)arg0;
  *arg1 = (void *)((new std::string(node->action_type()))->c_str());
}

void GO_EXPORT(ResolvedPrivilege_set_action_type)(void * arg0,void * arg1){
  googlesql::ResolvedPrivilege *node = (googlesql::ResolvedPrivilege *)arg0;
  node->set_action_type((char *)arg1);
}

void GO_EXPORT(ResolvedPrivilege_unit_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPrivilege *node = (googlesql::ResolvedPrivilege *)arg0;
  GET_UNIQUE_PTR_LIST(node->unit_list, arg1);
}

void GO_EXPORT(ResolvedPrivilege_set_unit_list)(void * arg0,void * arg1){
  googlesql::ResolvedPrivilege *node = (googlesql::ResolvedPrivilege *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_unit_list, ResolvedObjectUnit, arg1);
}

void GO_EXPORT(ResolvedPrivilege_add_unit_list)(void * arg0,void * arg1){
  googlesql::ResolvedPrivilege *node = (googlesql::ResolvedPrivilege *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_unit_list, ResolvedObjectUnit, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_privilege_list)(void * arg0,void ** arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->privilege_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_object_type)(void * arg0,void ** arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_object_type)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  node->mutable_object_type_list()->clear();
  node->add_object_type_list(std::string((const char *)arg1));
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_grantee_list)(void * arg0,void ** arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_STRS(node->grantee_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_grantee_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_LIST(node->set_grantee_list, std::string, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_grantee_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  node->add_grantee_list((char *)arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_grantee_expr_list)(void * arg0,void ** arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_set_grantee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantOrRevokeStmt_add_grantee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantOrRevokeStmt *node = (googlesql::ResolvedGrantOrRevokeStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_alter_action_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->alter_action_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_alter_action_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  SET_UNIQUE_PTR_ACTION_LIST(node->set_alter_action_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_add_alter_action_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  ADD_UNIQUE_PTR_ACTION_LIST(node->add_alter_action_list, arg1);
}

void GO_EXPORT(ResolvedAlterObjectStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedAlterObjectStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedAlterObjectStmt *node = (googlesql::ResolvedAlterObjectStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedAlterColumnAction_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedAlterColumnAction *node = (googlesql::ResolvedAlterColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedAlterColumnAction_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedAlterColumnAction *node = (googlesql::ResolvedAlterColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedAlterColumnAction_column)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterColumnAction *node = (googlesql::ResolvedAlterColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->column()))->c_str());
}

void GO_EXPORT(ResolvedAlterColumnAction_set_column)(void * arg0,void * arg1){
  googlesql::ResolvedAlterColumnAction *node = (googlesql::ResolvedAlterColumnAction *)arg0;
  node->set_column((char *)arg1);
}

void GO_EXPORT(ResolvedSetOptionsAction_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedSetOptionsAction *node = (googlesql::ResolvedSetOptionsAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedSetOptionsAction_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetOptionsAction *node = (googlesql::ResolvedSetOptionsAction *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedSetOptionsAction_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedSetOptionsAction *node = (googlesql::ResolvedSetOptionsAction *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAddColumnAction_is_if_not_exists)(void * arg0,char* arg1){
  googlesql::ResolvedAddColumnAction *node = (googlesql::ResolvedAddColumnAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ResolvedAddColumnAction_set_is_if_not_exists)(void * arg0,int arg1){
  googlesql::ResolvedAddColumnAction *node = (googlesql::ResolvedAddColumnAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ResolvedAddColumnAction_column_definition)(void * arg0,void ** arg1){
  googlesql::ResolvedAddColumnAction *node = (googlesql::ResolvedAddColumnAction *)arg0;
  *arg1 = (void *)node->column_definition();
}

void GO_EXPORT(ResolvedAddColumnAction_set_column_definition)(void * arg0,void * arg1){
  googlesql::ResolvedAddColumnAction *node = (googlesql::ResolvedAddColumnAction *)arg0;
  SET_UNIQUE_PTR(node->set_column_definition, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedAddConstraintAction_is_if_not_exists)(void * arg0,char* arg1){
  googlesql::ResolvedAddConstraintAction *node = (googlesql::ResolvedAddConstraintAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ResolvedAddConstraintAction_set_is_if_not_exists)(void * arg0,int arg1){
  googlesql::ResolvedAddConstraintAction *node = (googlesql::ResolvedAddConstraintAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ResolvedAddConstraintAction_constraint)(void * arg0,void ** arg1){
  googlesql::ResolvedAddConstraintAction *node = (googlesql::ResolvedAddConstraintAction *)arg0;
  *arg1 = (void *)node->constraint();
}

void GO_EXPORT(ResolvedAddConstraintAction_set_constraint)(void * arg0,void * arg1){
  googlesql::ResolvedAddConstraintAction *node = (googlesql::ResolvedAddConstraintAction *)arg0;
  node->set_constraint(make_unique_constraint(arg1));
}

void GO_EXPORT(ResolvedAddConstraintAction_table)(void * arg0,void ** arg1){
  googlesql::ResolvedAddConstraintAction *node = (googlesql::ResolvedAddConstraintAction *)arg0;
  *arg1 = (void *)node->table();
}

void GO_EXPORT(ResolvedAddConstraintAction_set_table)(void * arg0,void * arg1){
  googlesql::ResolvedAddConstraintAction *node = (googlesql::ResolvedAddConstraintAction *)arg0;
  node->set_table((const googlesql::Table *)arg1);
}

void GO_EXPORT(ResolvedDropConstraintAction_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropConstraintAction *node = (googlesql::ResolvedDropConstraintAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropConstraintAction_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropConstraintAction *node = (googlesql::ResolvedDropConstraintAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropConstraintAction_name)(void * arg0,void ** arg1){
  googlesql::ResolvedDropConstraintAction *node = (googlesql::ResolvedDropConstraintAction *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropConstraintAction_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedDropConstraintAction *node = (googlesql::ResolvedDropConstraintAction *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrimaryKeyAction_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropPrimaryKeyAction *node = (googlesql::ResolvedDropPrimaryKeyAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropPrimaryKeyAction_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropPrimaryKeyAction *node = (googlesql::ResolvedDropPrimaryKeyAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterColumnOptionsAction *node = (googlesql::ResolvedAlterColumnOptionsAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterColumnOptionsAction *node = (googlesql::ResolvedAlterColumnOptionsAction *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterColumnOptionsAction_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterColumnOptionsAction *node = (googlesql::ResolvedAlterColumnOptionsAction *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_type)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterColumnSetDataTypeAction *node = (googlesql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  *arg1 = (void *)node->updated_type();
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_type)(void * arg0,void * arg1){
  googlesql::ResolvedAlterColumnSetDataTypeAction *node = (googlesql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  node->set_updated_type((const googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_type_parameters)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterColumnSetDataTypeAction *node = (googlesql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  *arg1 = (void *)(new googlesql::TypeParameters(node->updated_type_parameters()));
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_type_parameters)(void * arg0,void * arg1){
  googlesql::ResolvedAlterColumnSetDataTypeAction *node = (googlesql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  node->set_updated_type_parameters(*(googlesql::TypeParameters *)arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_updated_annotations)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterColumnSetDataTypeAction *node = (googlesql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  *arg1 = (void *)node->updated_annotations();
}

void GO_EXPORT(ResolvedAlterColumnSetDataTypeAction_set_updated_annotations)(void * arg0,void * arg1){
  googlesql::ResolvedAlterColumnSetDataTypeAction *node = (googlesql::ResolvedAlterColumnSetDataTypeAction *)arg0;
  SET_UNIQUE_PTR(node->set_updated_annotations, ResolvedColumnAnnotations, arg1);
}

void GO_EXPORT(ResolvedAlterColumnSetDefaultAction_default_value)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterColumnSetDefaultAction *node = (googlesql::ResolvedAlterColumnSetDefaultAction *)arg0;
  *arg1 = (void *)node->default_value();
}

void GO_EXPORT(ResolvedAlterColumnSetDefaultAction_set_default_value)(void * arg0,void * arg1){
  googlesql::ResolvedAlterColumnSetDefaultAction *node = (googlesql::ResolvedAlterColumnSetDefaultAction *)arg0;
  SET_UNIQUE_PTR(node->set_default_value, ResolvedColumnDefaultValue, arg1);
}

void GO_EXPORT(ResolvedDropColumnAction_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropColumnAction *node = (googlesql::ResolvedDropColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropColumnAction_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropColumnAction *node = (googlesql::ResolvedDropColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropColumnAction_name)(void * arg0,void ** arg1){
  googlesql::ResolvedDropColumnAction *node = (googlesql::ResolvedDropColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropColumnAction_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedDropColumnAction *node = (googlesql::ResolvedDropColumnAction *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedRenameColumnAction_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedRenameColumnAction *node = (googlesql::ResolvedRenameColumnAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedRenameColumnAction_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedRenameColumnAction *node = (googlesql::ResolvedRenameColumnAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedRenameColumnAction_name)(void * arg0,void ** arg1){
  googlesql::ResolvedRenameColumnAction *node = (googlesql::ResolvedRenameColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedRenameColumnAction_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedRenameColumnAction *node = (googlesql::ResolvedRenameColumnAction *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedRenameColumnAction_new_name)(void * arg0,void ** arg1){
  googlesql::ResolvedRenameColumnAction *node = (googlesql::ResolvedRenameColumnAction *)arg0;
  *arg1 = (void *)((new std::string(node->new_name()))->c_str());
}

void GO_EXPORT(ResolvedRenameColumnAction_set_new_name)(void * arg0,void * arg1){
  googlesql::ResolvedRenameColumnAction *node = (googlesql::ResolvedRenameColumnAction *)arg0;
  node->set_new_name((char *)arg1);
}

void GO_EXPORT(ResolvedSetAsAction_entity_body_json)(void * arg0,void ** arg1){
  googlesql::ResolvedSetAsAction *node = (googlesql::ResolvedSetAsAction *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_json()))->c_str());
}

void GO_EXPORT(ResolvedSetAsAction_set_entity_body_json)(void * arg0,void * arg1){
  googlesql::ResolvedSetAsAction *node = (googlesql::ResolvedSetAsAction *)arg0;
  node->set_entity_body_json((char *)arg1);
}

void GO_EXPORT(ResolvedSetAsAction_entity_body_text)(void * arg0,void ** arg1){
  googlesql::ResolvedSetAsAction *node = (googlesql::ResolvedSetAsAction *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_text()))->c_str());
}

void GO_EXPORT(ResolvedSetAsAction_set_entity_body_text)(void * arg0,void * arg1){
  googlesql::ResolvedSetAsAction *node = (googlesql::ResolvedSetAsAction *)arg0;
  node->set_entity_body_text((char *)arg1);
}

void GO_EXPORT(ResolvedSetCollateClause_collation_name)(void * arg0,void ** arg1){
  googlesql::ResolvedSetCollateClause *node = (googlesql::ResolvedSetCollateClause *)arg0;
  *arg1 = (void *)node->collation_name();
}

void GO_EXPORT(ResolvedSetCollateClause_set_collation_name)(void * arg0,void * arg1){
  googlesql::ResolvedSetCollateClause *node = (googlesql::ResolvedSetCollateClause *)arg0;
  node->set_collation_name(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedAlterTableSetOptionsStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedAlterTableSetOptionsStmt *node = (googlesql::ResolvedAlterTableSetOptionsStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedRenameStmt_object_type)(void * arg0,void ** arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedRenameStmt_set_object_type)(void * arg0,void * arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedRenameStmt_old_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  GET_STRS(node->old_name_path, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_set_old_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  SET_LIST(node->set_old_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_add_old_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  node->add_old_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedRenameStmt_new_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  GET_STRS(node->new_name_path, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_set_new_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  SET_LIST(node->set_new_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedRenameStmt_add_new_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedRenameStmt *node = (googlesql::ResolvedRenameStmt *)arg0;
  node->add_new_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_privilege_list, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_restrictee_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_set_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedCreatePrivilegeRestrictionStmt_add_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreatePrivilegeRestrictionStmt *node = (googlesql::ResolvedCreatePrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_create_mode)(void * arg0,int* arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = node->create_mode();
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_create_mode)(void * arg0,int arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_create_mode((googlesql::ResolvedCreateRowAccessPolicyStmt::CreateMode)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_target_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  GET_STRS(node->target_name_path, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_target_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_LIST(node->set_target_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_target_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->add_target_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_grantee_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  GET_STRS(node->grantee_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_grantee_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_LIST(node->set_grantee_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_grantee_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->add_grantee_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_grantee_expr_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_grantee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_add_grantee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_predicate)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)node->predicate();
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_predicate)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_predicate(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_predicate_str)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->predicate_str()))->c_str());
}

void GO_EXPORT(ResolvedCreateRowAccessPolicyStmt_set_predicate_str)(void * arg0,void * arg1){
  googlesql::ResolvedCreateRowAccessPolicyStmt *node = (googlesql::ResolvedCreateRowAccessPolicyStmt *)arg0;
  node->set_predicate_str((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_privilege_list, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedDropPrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedDropPrivilegeRestrictionStmt *node = (googlesql::ResolvedDropPrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_is_drop_all)(void * arg0,char* arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  *arg1 = node->is_drop_all();
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_is_drop_all)(void * arg0,int arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->set_is_drop_all(arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_target_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  GET_STRS(node->target_name_path, arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_set_target_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  SET_LIST(node->set_target_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropRowAccessPolicyStmt_add_target_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropRowAccessPolicyStmt *node = (googlesql::ResolvedDropRowAccessPolicyStmt *)arg0;
  node->add_target_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropIndexStmt *node = (googlesql::ResolvedDropIndexStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropIndexStmt *node = (googlesql::ResolvedDropIndexStmt *)arg0;
  node->set_is_if_exists(arg1);
  node->set_index_type(googlesql::ResolvedDropIndexStmt::INDEX_SEARCH);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_name)(void * arg0,void ** arg1){
  googlesql::ResolvedDropIndexStmt *node = (googlesql::ResolvedDropIndexStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedDropIndexStmt *node = (googlesql::ResolvedDropIndexStmt *)arg0;
  node->set_name(std::string((const char *)arg1));
  node->set_index_type(googlesql::ResolvedDropIndexStmt::INDEX_SEARCH);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_table_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropIndexStmt *node = (googlesql::ResolvedDropIndexStmt *)arg0;
  GET_STRS(node->table_name_path, arg1);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_set_table_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropIndexStmt *node = (googlesql::ResolvedDropIndexStmt *)arg0;
  SET_LIST(node->set_table_name_path, std::string, arg1);
  node->set_index_type(googlesql::ResolvedDropIndexStmt::INDEX_SEARCH);
}

void GO_EXPORT(ResolvedDropSearchIndexStmt_add_table_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropIndexStmt *node = (googlesql::ResolvedDropIndexStmt *)arg0;
  node->add_table_name_path((char *)arg1);
  node->set_index_type(googlesql::ResolvedDropIndexStmt::INDEX_SEARCH);
}

void GO_EXPORT(ResolvedGrantToAction_grantee_expr_list)(void * arg0,void ** arg1){
  googlesql::ResolvedGrantToAction *node = (googlesql::ResolvedGrantToAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantToAction_set_grantee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantToAction *node = (googlesql::ResolvedGrantToAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedGrantToAction_add_grantee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedGrantToAction *node = (googlesql::ResolvedGrantToAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_grantee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRestrictToAction_restrictee_list)(void * arg0,void ** arg1){
  googlesql::ResolvedRestrictToAction *node = (googlesql::ResolvedRestrictToAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRestrictToAction_set_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedRestrictToAction *node = (googlesql::ResolvedRestrictToAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRestrictToAction_add_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedRestrictToAction *node = (googlesql::ResolvedRestrictToAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_is_if_not_exists)(void * arg0,char* arg1){
  googlesql::ResolvedAddToRestricteeListAction *node = (googlesql::ResolvedAddToRestricteeListAction *)arg0;
  *arg1 = node->is_if_not_exists();
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_set_is_if_not_exists)(void * arg0,int arg1){
  googlesql::ResolvedAddToRestricteeListAction *node = (googlesql::ResolvedAddToRestricteeListAction *)arg0;
  node->set_is_if_not_exists(arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_restrictee_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAddToRestricteeListAction *node = (googlesql::ResolvedAddToRestricteeListAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_set_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedAddToRestricteeListAction *node = (googlesql::ResolvedAddToRestricteeListAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedAddToRestricteeListAction_add_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedAddToRestricteeListAction *node = (googlesql::ResolvedAddToRestricteeListAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedRemoveFromRestricteeListAction *node = (googlesql::ResolvedRemoveFromRestricteeListAction *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedRemoveFromRestricteeListAction *node = (googlesql::ResolvedRemoveFromRestricteeListAction *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_restrictee_list)(void * arg0,void ** arg1){
  googlesql::ResolvedRemoveFromRestricteeListAction *node = (googlesql::ResolvedRemoveFromRestricteeListAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_set_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedRemoveFromRestricteeListAction *node = (googlesql::ResolvedRemoveFromRestricteeListAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedRemoveFromRestricteeListAction_add_restrictee_list)(void * arg0,void * arg1){
  googlesql::ResolvedRemoveFromRestricteeListAction *node = (googlesql::ResolvedRemoveFromRestricteeListAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_restrictee_list, arg1);
}

void GO_EXPORT(ResolvedFilterUsingAction_predicate)(void * arg0,void ** arg1){
  googlesql::ResolvedFilterUsingAction *node = (googlesql::ResolvedFilterUsingAction *)arg0;
  *arg1 = (void *)node->predicate();
}

void GO_EXPORT(ResolvedFilterUsingAction_set_predicate)(void * arg0,void * arg1){
  googlesql::ResolvedFilterUsingAction *node = (googlesql::ResolvedFilterUsingAction *)arg0;
  node->set_predicate(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedFilterUsingAction_predicate_str)(void * arg0,void ** arg1){
  googlesql::ResolvedFilterUsingAction *node = (googlesql::ResolvedFilterUsingAction *)arg0;
  *arg1 = (void *)((new std::string(node->predicate_str()))->c_str());
}

void GO_EXPORT(ResolvedFilterUsingAction_set_predicate_str)(void * arg0,void * arg1){
  googlesql::ResolvedFilterUsingAction *node = (googlesql::ResolvedFilterUsingAction *)arg0;
  node->set_predicate_str((char *)arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_revokee_expr_list)(void * arg0,void ** arg1){
  googlesql::ResolvedRevokeFromAction *node = (googlesql::ResolvedRevokeFromAction *)arg0;
  GET_UNIQUE_PTR_LIST(node->revokee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_set_revokee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedRevokeFromAction *node = (googlesql::ResolvedRevokeFromAction *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_revokee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_add_revokee_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedRevokeFromAction *node = (googlesql::ResolvedRevokeFromAction *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_revokee_expr_list, arg1);
}

void GO_EXPORT(ResolvedRevokeFromAction_is_revoke_from_all)(void * arg0,char* arg1){
  googlesql::ResolvedRevokeFromAction *node = (googlesql::ResolvedRevokeFromAction *)arg0;
  *arg1 = node->is_revoke_from_all();
}

void GO_EXPORT(ResolvedRevokeFromAction_set_is_revoke_from_all)(void * arg0,int arg1){
  googlesql::ResolvedRevokeFromAction *node = (googlesql::ResolvedRevokeFromAction *)arg0;
  node->set_is_revoke_from_all(arg1);
}

void GO_EXPORT(ResolvedRenameToAction_new_path)(void * arg0,void ** arg1){
  googlesql::ResolvedRenameToAction *node = (googlesql::ResolvedRenameToAction *)arg0;
  GET_STRS(node->new_path, arg1);
}

void GO_EXPORT(ResolvedRenameToAction_set_new_path)(void * arg0,void * arg1){
  googlesql::ResolvedRenameToAction *node = (googlesql::ResolvedRenameToAction *)arg0;
  SET_LIST(node->set_new_path, std::string, arg1);
}

void GO_EXPORT(ResolvedRenameToAction_add_new_path)(void * arg0,void * arg1){
  googlesql::ResolvedRenameToAction *node = (googlesql::ResolvedRenameToAction *)arg0;
  node->add_new_path((char *)arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_column_privilege_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterPrivilegeRestrictionStmt *node = (googlesql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_privilege_list, arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_set_column_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterPrivilegeRestrictionStmt *node = (googlesql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_add_column_privilege_list)(void * arg0,void * arg1){
  googlesql::ResolvedAlterPrivilegeRestrictionStmt *node = (googlesql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_privilege_list, ResolvedPrivilege, arg1);
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_object_type)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterPrivilegeRestrictionStmt *node = (googlesql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->object_type()))->c_str());
}

void GO_EXPORT(ResolvedAlterPrivilegeRestrictionStmt_set_object_type)(void * arg0,void * arg1){
  googlesql::ResolvedAlterPrivilegeRestrictionStmt *node = (googlesql::ResolvedAlterPrivilegeRestrictionStmt *)arg0;
  node->set_object_type((char *)arg1);
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_name)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterRowAccessPolicyStmt *node = (googlesql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedAlterRowAccessPolicyStmt *node = (googlesql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterRowAccessPolicyStmt *node = (googlesql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedAlterRowAccessPolicyStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedAlterRowAccessPolicyStmt *node = (googlesql::ResolvedAlterRowAccessPolicyStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedAlterAllRowAccessPoliciesStmt_table_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterAllRowAccessPoliciesStmt *node = (googlesql::ResolvedAlterAllRowAccessPoliciesStmt *)arg0;
  *arg1 = (void *)node->table_scan();
}

void GO_EXPORT(ResolvedAlterAllRowAccessPoliciesStmt_set_table_scan)(void * arg0,void * arg1){
  googlesql::ResolvedAlterAllRowAccessPoliciesStmt *node = (googlesql::ResolvedAlterAllRowAccessPoliciesStmt *)arg0;
  SET_UNIQUE_PTR(node->set_table_scan, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCreateConstantStmt_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateConstantStmt *node = (googlesql::ResolvedCreateConstantStmt *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedCreateConstantStmt_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedCreateConstantStmt *node = (googlesql::ResolvedCreateConstantStmt *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateFunctionStmt_has_explicit_return_type)(void * arg0,char* arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->has_explicit_return_type();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_has_explicit_return_type)(void * arg0,int arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_has_explicit_return_type(arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_return_type)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)node->return_type();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_return_type)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_return_type((const googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_argument_name_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  GET_STRS(node->argument_name_list, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_argument_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  SET_LIST(node->set_argument_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_argument_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->add_argument_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)(new googlesql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_signature(*(googlesql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_is_aggregate)(void * arg0,char* arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->is_aggregate();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_is_aggregate)(void * arg0,int arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_is_aggregate(arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_language)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->language()))->c_str());
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_language)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_language((char *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_code)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->code()))->c_str());
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_code)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_code((char *)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_aggregate_expression_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->aggregate_expression_list, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_aggregate_expression_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_aggregate_expression_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_aggregate_expression_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_aggregate_expression_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_function_expression)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)node->function_expression();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_function_expression)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_function_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateFunctionStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_sql_security)(void * arg0,int* arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->sql_security();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_sql_security)(void * arg0,int arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_sql_security((googlesql::ResolvedCreateFunctionStmt::SqlSecurity)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_determinism_level)(void * arg0,int* arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->determinism_level();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_determinism_level)(void * arg0,int arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_determinism_level((googlesql::ResolvedCreateFunctionStmt::DeterminismLevel)arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_is_remote)(void * arg0,char* arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = node->is_remote();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_is_remote)(void * arg0,int arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  node->set_is_remote(arg1);
}

void GO_EXPORT(ResolvedCreateFunctionStmt_connection)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedCreateFunctionStmt_set_connection)(void * arg0,void * arg1){
  googlesql::ResolvedCreateFunctionStmt *node = (googlesql::ResolvedCreateFunctionStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedArgumentDef_name)(void * arg0,void ** arg1){
  googlesql::ResolvedArgumentDef *node = (googlesql::ResolvedArgumentDef *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedArgumentDef_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedArgumentDef *node = (googlesql::ResolvedArgumentDef *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedArgumentDef_type)(void * arg0,void ** arg1){
  googlesql::ResolvedArgumentDef *node = (googlesql::ResolvedArgumentDef *)arg0;
  *arg1 = (void *)node->type();
}

void GO_EXPORT(ResolvedArgumentDef_set_type)(void * arg0,void * arg1){
  googlesql::ResolvedArgumentDef *node = (googlesql::ResolvedArgumentDef *)arg0;
  node->set_type((const googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedArgumentDef_argument_kind)(void * arg0,int* arg1){
  googlesql::ResolvedArgumentDef *node = (googlesql::ResolvedArgumentDef *)arg0;
  *arg1 = node->argument_kind();
}

void GO_EXPORT(ResolvedArgumentDef_set_argument_kind)(void * arg0,int arg1){
  googlesql::ResolvedArgumentDef *node = (googlesql::ResolvedArgumentDef *)arg0;
  node->set_argument_kind((googlesql::ResolvedArgumentDef::ArgumentKind)arg1);
}

void GO_EXPORT(ResolvedArgumentRef_name)(void * arg0,void ** arg1){
  googlesql::ResolvedArgumentRef *node = (googlesql::ResolvedArgumentRef *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedArgumentRef_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedArgumentRef *node = (googlesql::ResolvedArgumentRef *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedArgumentRef_argument_kind)(void * arg0,int* arg1){
  googlesql::ResolvedArgumentRef *node = (googlesql::ResolvedArgumentRef *)arg0;
  *arg1 = node->argument_kind();
}

void GO_EXPORT(ResolvedArgumentRef_set_argument_kind)(void * arg0,int arg1){
  googlesql::ResolvedArgumentRef *node = (googlesql::ResolvedArgumentRef *)arg0;
  node->set_argument_kind((googlesql::ResolvedArgumentDef::ArgumentKind)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_new)(void * arg0,int arg1,int arg2,void * arg3,void * arg4,int arg5,void * arg6,void * arg7,void * arg8,void *arg9,void * arg10,int arg11,int arg12,void ** arg13)
{
  std::vector<std::unique_ptr<const googlesql::ResolvedOption>> option_list;
  std::vector<std::unique_ptr<const googlesql::ResolvedOption>> *option_list_ref = &option_list;
  UNIQUE_PTR_LIST_TO_VEC(option_list_ref, ResolvedOption, arg6);

  std::vector<std::unique_ptr<const googlesql::ResolvedOutputColumn>> output_column_list;
  std::vector<std::unique_ptr<const googlesql::ResolvedOutputColumn>> *output_column_list_ref = &output_column_list;
  UNIQUE_PTR_LIST_TO_VEC(output_column_list_ref, ResolvedOutputColumn, arg10);

  *(std::unique_ptr<googlesql::ResolvedCreateTableFunctionStmt> *)arg13 = googlesql::MakeResolvedCreateTableFunctionStmt(
    googlesql_public_analyzer_bridge_slice_to_strs(arg0),
    (googlesql::ResolvedCreateStatementEnums::CreateScope)arg1,
    (googlesql::ResolvedCreateStatementEnums::CreateMode)arg2,
    googlesql_public_analyzer_bridge_slice_to_strs(arg3),
    *(googlesql::FunctionSignature *)arg4,
    arg5,
    std::move(option_list),
    (char *)arg7,
    (char *)arg8,
    make_unique_scan(arg9),
    std::move(output_column_list),
    arg11,
    (googlesql::ResolvedCreateStatementEnums::SqlSecurity)arg12
  );
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_argument_name_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  GET_STRS(node->argument_name_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_argument_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  SET_LIST(node->set_argument_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_argument_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->add_argument_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)(new googlesql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_signature(*(googlesql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_has_explicit_return_schema)(void * arg0,char* arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = node->has_explicit_return_schema();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_has_explicit_return_schema)(void * arg0,int arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_has_explicit_return_schema(arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_language)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->language()))->c_str());
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_language)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_language((char *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_code)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)((new std::string(node->code()))->c_str());
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_code)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_code((char *)arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_query)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = (void *)node->query();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_query)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_query(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_is_value_table)(void * arg0,char* arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_is_value_table)(void * arg0,int arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_sql_security)(void * arg0,int* arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  *arg1 = node->sql_security();
}

void GO_EXPORT(ResolvedCreateTableFunctionStmt_set_sql_security)(void * arg0,int arg1){
  googlesql::ResolvedCreateTableFunctionStmt *node = (googlesql::ResolvedCreateTableFunctionStmt *)arg0;
  node->set_sql_security((googlesql::ResolvedCreateTableFunctionStmt::SqlSecurity)arg1);
}

void GO_EXPORT(ResolvedRelationArgumentScan_name)(void * arg0,void ** arg1){
  googlesql::ResolvedRelationArgumentScan *node = (googlesql::ResolvedRelationArgumentScan *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedRelationArgumentScan_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedRelationArgumentScan *node = (googlesql::ResolvedRelationArgumentScan *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedRelationArgumentScan_is_value_table)(void * arg0,char* arg1){
  googlesql::ResolvedRelationArgumentScan *node = (googlesql::ResolvedRelationArgumentScan *)arg0;
  *arg1 = node->is_value_table();
}

void GO_EXPORT(ResolvedRelationArgumentScan_set_is_value_table)(void * arg0,int arg1){
  googlesql::ResolvedRelationArgumentScan *node = (googlesql::ResolvedRelationArgumentScan *)arg0;
  node->set_is_value_table(arg1);
}

void GO_EXPORT(ResolvedArgumentList_arg_list)(void * arg0,void ** arg1){
  googlesql::ResolvedArgumentList *node = (googlesql::ResolvedArgumentList *)arg0;
  GET_UNIQUE_PTR_LIST(node->arg_list, arg1);
}

void GO_EXPORT(ResolvedArgumentList_set_arg_list)(void * arg0,void * arg1){
  googlesql::ResolvedArgumentList *node = (googlesql::ResolvedArgumentList *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_arg_list, ResolvedArgumentDef, arg1);
}

void GO_EXPORT(ResolvedArgumentList_add_arg_list)(void * arg0,void * arg1){
  googlesql::ResolvedArgumentList *node = (googlesql::ResolvedArgumentList *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_arg_list, ResolvedArgumentDef, arg1);
}

void GO_EXPORT(ResolvedFunctionSignatureHolder_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionSignatureHolder *node = (googlesql::ResolvedFunctionSignatureHolder *)arg0;
  *arg1 = (void *)(new googlesql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedFunctionSignatureHolder_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedFunctionSignatureHolder *node = (googlesql::ResolvedFunctionSignatureHolder *)arg0;
  node->set_signature(*(googlesql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_arguments)(void * arg0,void ** arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  *arg1 = (void *)node->arguments();
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_arguments)(void * arg0,void * arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  SET_UNIQUE_PTR(node->set_arguments, ResolvedArgumentList, arg1);
}

void GO_EXPORT(ResolvedDropFunctionStmt_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  *arg1 = (void *)node->signature();
}

void GO_EXPORT(ResolvedDropFunctionStmt_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedDropFunctionStmt *node = (googlesql::ResolvedDropFunctionStmt *)arg0;
  node->set_signature(googlesql::MakeResolvedFunctionSignatureHolder(*(googlesql::FunctionSignature *)arg1));
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_is_if_exists)(void * arg0,char* arg1){
  googlesql::ResolvedDropTableFunctionStmt *node = (googlesql::ResolvedDropTableFunctionStmt *)arg0;
  *arg1 = node->is_if_exists();
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_set_is_if_exists)(void * arg0,int arg1){
  googlesql::ResolvedDropTableFunctionStmt *node = (googlesql::ResolvedDropTableFunctionStmt *)arg0;
  node->set_is_if_exists(arg1);
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedDropTableFunctionStmt *node = (googlesql::ResolvedDropTableFunctionStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropTableFunctionStmt *node = (googlesql::ResolvedDropTableFunctionStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedDropTableFunctionStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedDropTableFunctionStmt *node = (googlesql::ResolvedDropTableFunctionStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedCallStmt_procedure)(void * arg0,void ** arg1){
  googlesql::ResolvedCallStmt *node = (googlesql::ResolvedCallStmt *)arg0;
  *arg1 = (void *)node->procedure();
}

void GO_EXPORT(ResolvedCallStmt_set_procedure)(void * arg0,void * arg1){
  googlesql::ResolvedCallStmt *node = (googlesql::ResolvedCallStmt *)arg0;
  node->set_procedure((const googlesql::Procedure *)arg1);
}

void GO_EXPORT(ResolvedCallStmt_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedCallStmt *node = (googlesql::ResolvedCallStmt *)arg0;
  *arg1 = (void *)(new googlesql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCallStmt_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedCallStmt *node = (googlesql::ResolvedCallStmt *)arg0;
  node->set_signature(*(googlesql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCallStmt_argument_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCallStmt *node = (googlesql::ResolvedCallStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->argument_list, arg1);
}

void GO_EXPORT(ResolvedCallStmt_set_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedCallStmt *node = (googlesql::ResolvedCallStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_argument_list, arg1);
}

void GO_EXPORT(ResolvedCallStmt_add_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedCallStmt *node = (googlesql::ResolvedCallStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_argument_list, arg1);
}

void GO_EXPORT(ResolvedImportStmt_import_kind)(void * arg0,int* arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  *arg1 = node->import_kind();
}

void GO_EXPORT(ResolvedImportStmt_set_import_kind)(void * arg0,int arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  node->set_import_kind((googlesql::ResolvedImportStmt::ImportKind)arg1);
}

void GO_EXPORT(ResolvedImportStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_file_path)(void * arg0,void ** arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  *arg1 = (void *)((new std::string(node->file_path()))->c_str());
}

void GO_EXPORT(ResolvedImportStmt_set_file_path)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  node->set_file_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_alias_path)(void * arg0,void ** arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  GET_STRS(node->alias_path, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_alias_path)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  SET_LIST(node->set_alias_path, std::string, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_alias_path)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  node->add_alias_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_into_alias_path)(void * arg0,void ** arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  GET_STRS(node->into_alias_path, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_into_alias_path)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  SET_LIST(node->set_into_alias_path, std::string, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_into_alias_path)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  node->add_into_alias_path((char *)arg1);
}

void GO_EXPORT(ResolvedImportStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedImportStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedImportStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedImportStmt *node = (googlesql::ResolvedImportStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedModuleStmt *node = (googlesql::ResolvedModuleStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedModuleStmt *node = (googlesql::ResolvedModuleStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedModuleStmt *node = (googlesql::ResolvedModuleStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedModuleStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedModuleStmt *node = (googlesql::ResolvedModuleStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedModuleStmt *node = (googlesql::ResolvedModuleStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedModuleStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedModuleStmt *node = (googlesql::ResolvedModuleStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAggregateHavingModifier_kind)(void * arg0,int* arg1){
  googlesql::ResolvedAggregateHavingModifier *node = (googlesql::ResolvedAggregateHavingModifier *)arg0;
  *arg1 = node->kind();
}

void GO_EXPORT(ResolvedAggregateHavingModifier_set_kind)(void * arg0,int arg1){
  googlesql::ResolvedAggregateHavingModifier *node = (googlesql::ResolvedAggregateHavingModifier *)arg0;
  node->set_kind((googlesql::ResolvedAggregateHavingModifier::HavingModifierKind)arg1);
}

void GO_EXPORT(ResolvedAggregateHavingModifier_having_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedAggregateHavingModifier *node = (googlesql::ResolvedAggregateHavingModifier *)arg0;
  *arg1 = (void *)node->having_expr();
}

void GO_EXPORT(ResolvedAggregateHavingModifier_set_having_expr)(void * arg0,void * arg1){
  googlesql::ResolvedAggregateHavingModifier *node = (googlesql::ResolvedAggregateHavingModifier *)arg0;
  node->set_having_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_column_definition_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_partition_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_cluster_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_set_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateMaterializedViewStmt_add_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateMaterializedViewStmt *node = (googlesql::ResolvedCreateMaterializedViewStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_argument_name_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  GET_STRS(node->argument_name_list, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_argument_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  SET_LIST(node->set_argument_name_list, std::string, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_add_argument_name_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  node->add_argument_name_list((char *)arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_signature)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  *arg1 = (void *)(new googlesql::FunctionSignature(node->signature()));
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_signature)(void * arg0,void * arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  node->set_signature(*(googlesql::FunctionSignature *)arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateProcedureStmt_procedure_body)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  *arg1 = (void *)((new std::string(node->procedure_body()))->c_str());
}

void GO_EXPORT(ResolvedCreateProcedureStmt_set_procedure_body)(void * arg0,void * arg1){
  googlesql::ResolvedCreateProcedureStmt *node = (googlesql::ResolvedCreateProcedureStmt *)arg0;
  node->set_procedure_body((char *)arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_name)(void * arg0,void ** arg1){
  googlesql::ResolvedExecuteImmediateArgument *node = (googlesql::ResolvedExecuteImmediateArgument *)arg0;
  *arg1 = (void *)((new std::string(node->name()))->c_str());
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_set_name)(void * arg0,void * arg1){
  googlesql::ResolvedExecuteImmediateArgument *node = (googlesql::ResolvedExecuteImmediateArgument *)arg0;
  node->set_name((char *)arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_expression)(void * arg0,void ** arg1){
  googlesql::ResolvedExecuteImmediateArgument *node = (googlesql::ResolvedExecuteImmediateArgument *)arg0;
  *arg1 = (void *)node->expression();
}

void GO_EXPORT(ResolvedExecuteImmediateArgument_set_expression)(void * arg0,void * arg1){
  googlesql::ResolvedExecuteImmediateArgument *node = (googlesql::ResolvedExecuteImmediateArgument *)arg0;
  node->set_expression(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_sql)(void * arg0,void ** arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  *arg1 = (void *)node->sql();
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_sql)(void * arg0,void * arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  node->set_sql(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_into_identifier_list)(void * arg0,void ** arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  GET_STRS(node->into_identifier_list, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_into_identifier_list)(void * arg0,void * arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  SET_LIST(node->set_into_identifier_list, std::string, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_add_into_identifier_list)(void * arg0,void * arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  node->add_into_identifier_list((char *)arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_using_argument_list)(void * arg0,void ** arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->using_argument_list, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_set_using_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_using_argument_list, ResolvedExecuteImmediateArgument, arg1);
}

void GO_EXPORT(ResolvedExecuteImmediateStmt_add_using_argument_list)(void * arg0,void * arg1){
  googlesql::ResolvedExecuteImmediateStmt *node = (googlesql::ResolvedExecuteImmediateStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_using_argument_list, ResolvedExecuteImmediateArgument, arg1);
}

void GO_EXPORT(ResolvedAssignmentStmt_target)(void * arg0,void ** arg1){
  googlesql::ResolvedAssignmentStmt *node = (googlesql::ResolvedAssignmentStmt *)arg0;
  *arg1 = (void *)node->target();
}

void GO_EXPORT(ResolvedAssignmentStmt_set_target)(void * arg0,void * arg1){
  googlesql::ResolvedAssignmentStmt *node = (googlesql::ResolvedAssignmentStmt *)arg0;
  node->set_target(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedAssignmentStmt_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedAssignmentStmt *node = (googlesql::ResolvedAssignmentStmt *)arg0;
  *arg1 = (void *)node->expr();
}

void GO_EXPORT(ResolvedAssignmentStmt_set_expr)(void * arg0,void * arg1){
  googlesql::ResolvedAssignmentStmt *node = (googlesql::ResolvedAssignmentStmt *)arg0;
  node->set_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_type)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_type()))->c_str());
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_type)(void * arg0,void * arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  node->set_entity_type((char *)arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_body_json)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_json()))->c_str());
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_body_json)(void * arg0,void * arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  node->set_entity_body_json((char *)arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_entity_body_text)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_body_text()))->c_str());
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_entity_body_text)(void * arg0,void * arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  node->set_entity_body_text((char *)arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedCreateEntityStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedCreateEntityStmt *node = (googlesql::ResolvedCreateEntityStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAlterEntityStmt_entity_type)(void * arg0,void ** arg1){
  googlesql::ResolvedAlterEntityStmt *node = (googlesql::ResolvedAlterEntityStmt *)arg0;
  *arg1 = (void *)((new std::string(node->entity_type()))->c_str());  
}

void GO_EXPORT(ResolvedAlterEntityStmt_set_entity_type)(void * arg0,void * arg1){
  googlesql::ResolvedAlterEntityStmt *node = (googlesql::ResolvedAlterEntityStmt *)arg0;
  node->set_entity_type((char *)arg1);
}

void GO_EXPORT(ResolvedPivotColumn_column)(void * arg0,void ** arg1){
  googlesql::ResolvedPivotColumn *node = (googlesql::ResolvedPivotColumn *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->column()));
}

void GO_EXPORT(ResolvedPivotColumn_set_column)(void * arg0,void * arg1){
  googlesql::ResolvedPivotColumn *node = (googlesql::ResolvedPivotColumn *)arg0;
  node->set_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedPivotColumn_pivot_expr_index)(void * arg0,int* arg1){
  googlesql::ResolvedPivotColumn *node = (googlesql::ResolvedPivotColumn *)arg0;
  *arg1 = node->pivot_expr_index();
}

void GO_EXPORT(ResolvedPivotColumn_set_pivot_expr_index)(void * arg0,int arg1){
  googlesql::ResolvedPivotColumn *node = (googlesql::ResolvedPivotColumn *)arg0;
  node->set_pivot_expr_index(arg1);
}

void GO_EXPORT(ResolvedPivotColumn_pivot_value_index)(void * arg0,int* arg1){
  googlesql::ResolvedPivotColumn *node = (googlesql::ResolvedPivotColumn *)arg0;
  *arg1 = node->pivot_value_index();
}

void GO_EXPORT(ResolvedPivotColumn_set_pivot_value_index)(void * arg0,int arg1){
  googlesql::ResolvedPivotColumn *node = (googlesql::ResolvedPivotColumn *)arg0;
  node->set_pivot_value_index(arg1);
}

void GO_EXPORT(ResolvedPivotScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedPivotScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedPivotScan_group_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->group_by_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_group_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_group_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_group_by_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedPivotScan_pivot_expr_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->pivot_expr_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_pivot_expr_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_pivot_expr_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_for_expr)(void * arg0,void ** arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  *arg1 = (void *)node->for_expr();
}

void GO_EXPORT(ResolvedPivotScan_set_for_expr)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  node->set_for_expr(make_unique_expr(arg1));
}

void GO_EXPORT(ResolvedPivotScan_pivot_value_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->pivot_value_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_value_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_pivot_value_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_value_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_pivot_value_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_pivot_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->pivot_column_list, arg1);
}

void GO_EXPORT(ResolvedPivotScan_set_pivot_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_pivot_column_list, ResolvedPivotColumn, arg1);
}

void GO_EXPORT(ResolvedPivotScan_add_pivot_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedPivotScan *node = (googlesql::ResolvedPivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_pivot_column_list, ResolvedPivotColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedReturningClause_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_action_column)(void * arg0,void ** arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  *arg1 = (void *)node->action_column();
}

void GO_EXPORT(ResolvedReturningClause_set_action_column)(void * arg0,void * arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  SET_UNIQUE_PTR(node->set_action_column, ResolvedColumnHolder, arg1);
}

void GO_EXPORT(ResolvedReturningClause_expr_list)(void * arg0,void ** arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  GET_UNIQUE_PTR_LIST(node->expr_list, arg1);
}

void GO_EXPORT(ResolvedReturningClause_set_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedReturningClause_add_expr_list)(void * arg0,void * arg1){
  googlesql::ResolvedReturningClause *node = (googlesql::ResolvedReturningClause *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_expr_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotArg_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUnpivotArg *node = (googlesql::ResolvedUnpivotArg *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotArg_set_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotArg *node = (googlesql::ResolvedUnpivotArg *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedUnpivotArg_add_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotArg *node = (googlesql::ResolvedUnpivotArg *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_list, ResolvedColumnRef, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_input_scan)(void * arg0,void ** arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  *arg1 = (void *)node->input_scan();
}

void GO_EXPORT(ResolvedUnpivotScan_set_input_scan)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  node->set_input_scan(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedUnpivotScan_value_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  GET_LIST(node->value_column_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_value_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  SET_LIST(node->set_value_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_value_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  ADD_LIST(node->add_value_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_label_column)(void * arg0,void ** arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  *arg1 = (void *)(new googlesql::ResolvedColumn(node->label_column()));
}

void GO_EXPORT(ResolvedUnpivotScan_set_label_column)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  node->set_label_column(*(googlesql::ResolvedColumn *)arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_label_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->label_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_label_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_label_list, ResolvedLiteral, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_label_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_label_list, ResolvedLiteral, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_unpivot_arg_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->unpivot_arg_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_unpivot_arg_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_unpivot_arg_list, ResolvedUnpivotArg, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_unpivot_arg_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_unpivot_arg_list, ResolvedUnpivotArg, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_projected_input_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  GET_UNIQUE_PTR_LIST(node->projected_input_column_list, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_set_projected_input_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_projected_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_add_projected_input_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_projected_input_column_list, ResolvedComputedColumn, arg1);
}

void GO_EXPORT(ResolvedUnpivotScan_include_nulls)(void * arg0,char* arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  *arg1 = node->include_nulls();
}

void GO_EXPORT(ResolvedUnpivotScan_set_include_nulls)(void * arg0,int arg1){
  googlesql::ResolvedUnpivotScan *node = (googlesql::ResolvedUnpivotScan *)arg0;
  node->set_include_nulls(arg1);
}

void GO_EXPORT(ResolvedCloneDataStmt_target_table)(void * arg0,void ** arg1){
  googlesql::ResolvedCloneDataStmt *node = (googlesql::ResolvedCloneDataStmt *)arg0;
  *arg1 = (void *)node->target_table();
}

void GO_EXPORT(ResolvedCloneDataStmt_set_target_table)(void * arg0,void * arg1){
  googlesql::ResolvedCloneDataStmt *node = (googlesql::ResolvedCloneDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_target_table, ResolvedTableScan, arg1);
}

void GO_EXPORT(ResolvedCloneDataStmt_clone_from)(void * arg0,void ** arg1){
  googlesql::ResolvedCloneDataStmt *node = (googlesql::ResolvedCloneDataStmt *)arg0;
  *arg1 = (void *)node->clone_from();
}

void GO_EXPORT(ResolvedCloneDataStmt_set_clone_from)(void * arg0,void * arg1){
  googlesql::ResolvedCloneDataStmt *node = (googlesql::ResolvedCloneDataStmt *)arg0;
  node->set_clone_from(make_unique_scan(arg1));
}

void GO_EXPORT(ResolvedTableAndColumnInfo_table)(void * arg0,void ** arg1){
  googlesql::ResolvedTableAndColumnInfo *node = (googlesql::ResolvedTableAndColumnInfo *)arg0;
  *arg1 = (void *)node->table();
}

void GO_EXPORT(ResolvedTableAndColumnInfo_set_table)(void * arg0,void * arg1){
  googlesql::ResolvedTableAndColumnInfo *node = (googlesql::ResolvedTableAndColumnInfo *)arg0;
  node->set_table((const googlesql::Table *)arg1);
}

void GO_EXPORT(ResolvedTableAndColumnInfo_column_index_list)(void * arg0,void ** arg1){
  googlesql::ResolvedTableAndColumnInfo *node = (googlesql::ResolvedTableAndColumnInfo *)arg0;
  GET_INTS(node->column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableAndColumnInfo_set_column_index_list)(void * arg0,void * arg1){
  googlesql::ResolvedTableAndColumnInfo *node = (googlesql::ResolvedTableAndColumnInfo *)arg0;
  SET_INTS(node->set_column_index_list, arg1);
}

void GO_EXPORT(ResolvedTableAndColumnInfo_add_column_index_list)(void * arg0,int arg1){
  googlesql::ResolvedTableAndColumnInfo *node = (googlesql::ResolvedTableAndColumnInfo *)arg0;
  node->add_column_index_list(arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyzeStmt *node = (googlesql::ResolvedAnalyzeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyzeStmt *node = (googlesql::ResolvedAnalyzeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyzeStmt *node = (googlesql::ResolvedAnalyzeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_table_and_column_index_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAnalyzeStmt *node = (googlesql::ResolvedAnalyzeStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->table_and_column_index_list, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_set_table_and_column_index_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyzeStmt *node = (googlesql::ResolvedAnalyzeStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_table_and_column_index_list, ResolvedTableAndColumnInfo, arg1);
}

void GO_EXPORT(ResolvedAnalyzeStmt_add_table_and_column_index_list)(void * arg0,void * arg1){
  googlesql::ResolvedAnalyzeStmt *node = (googlesql::ResolvedAnalyzeStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_table_and_column_index_list, ResolvedTableAndColumnInfo, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_insertion_mode)(void * arg0,int* arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = node->insertion_mode();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_insertion_mode)(void * arg0,int arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  node->set_insertion_mode((googlesql::ResolvedAuxLoadDataStmt::InsertionMode)arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_name_path)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_STRS(node->name_path, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_LIST(node->set_name_path, std::string, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_name_path)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  node->add_name_path((char *)arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_output_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->output_column_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_output_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_output_column_list, ResolvedOutputColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_column_definition_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->column_definition_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_column_definition_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_column_definition_list, ResolvedColumnDefinition, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_pseudo_column_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_LIST(node->pseudo_column_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_pseudo_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_LIST(node->set_pseudo_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_pseudo_column_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_LIST(node->add_pseudo_column_list, googlesql::ResolvedColumn, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_primary_key)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = (void *)node->primary_key();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_primary_key)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_primary_key, ResolvedPrimaryKey, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_foreign_key_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->foreign_key_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_foreign_key_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_foreign_key_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_foreign_key_list, ResolvedForeignKey, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_check_constraint_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->check_constraint_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_check_constraint_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_check_constraint_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_check_constraint_list, ResolvedCheckConstraint, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_partition_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->partition_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_partition_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_partition_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_cluster_by_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_EXPR_LIST(node->set_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_cluster_by_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_EXPR_LIST(node->add_cluster_by_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->option_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_with_partition_columns)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = (void *)node->with_partition_columns();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_with_partition_columns)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_with_partition_columns, ResolvedWithPartitionColumns, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_connection)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  *arg1 = (void *)node->connection();
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_connection)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR(node->set_connection, ResolvedConnection, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_from_files_option_list)(void * arg0,void ** arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  GET_UNIQUE_PTR_LIST(node->from_files_option_list, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_set_from_files_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  SET_UNIQUE_PTR_LIST(node->set_from_files_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedAuxLoadDataStmt_add_from_files_option_list)(void * arg0,void * arg1){
  googlesql::ResolvedAuxLoadDataStmt *node = (googlesql::ResolvedAuxLoadDataStmt *)arg0;
  ADD_UNIQUE_PTR_LIST(node->add_from_files_option_list, ResolvedOption, arg1);
}

void GO_EXPORT(ResolvedColumn_IsInitialized)(void * arg0,char* arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = col->IsInitialized();
}

void GO_EXPORT(ResolvedColumn_Clear)(void * arg0){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  col->Clear();
}

void GO_EXPORT(ResolvedColumn_DebugString)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->DebugString()))->c_str());
}
  
void GO_EXPORT(ResolvedColumn_ShortDebugString)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->ShortDebugString()))->c_str());
}

void GO_EXPORT(ResolvedColumn_column_id)(void * arg0,int* arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = col->column_id();
}

void GO_EXPORT(ResolvedColumn_table_name)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->table_name()))->c_str());
}

void GO_EXPORT(ResolvedColumn_name)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->name()))->c_str());
}

void GO_EXPORT(ResolvedColumn_table_name_id)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->table_name_id().ToStringView()))->c_str());
}

void GO_EXPORT(ResolvedColumn_name_id)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)((new std::string(col->name_id().ToStringView()))->c_str());
}

void GO_EXPORT(ResolvedColumn_type)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)col->type();
}

void GO_EXPORT(ResolvedColumn_type_annotation_map)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)col->type_annotation_map();
}

void GO_EXPORT(ResolvedColumn_annotated_type)(void * arg0,void ** arg1){
  googlesql::ResolvedColumn *col = (googlesql::ResolvedColumn *)arg0;
  *arg1 = (void *)(new googlesql::AnnotatedType(col->annotated_type()));
}

void GO_EXPORT(ResolvedCollation_Empty)(void * arg0,char* arg1){
  googlesql::ResolvedCollation *col = (googlesql::ResolvedCollation *)arg0;
  *arg1 = col->Empty();
}

void GO_EXPORT(ResolvedCollation_Equals)(void * arg0,void * arg1,char* arg2){
  googlesql::ResolvedCollation *col = (googlesql::ResolvedCollation *)arg0;
  *arg2 = col->Equals(*(googlesql::ResolvedCollation *)arg1);
}

void GO_EXPORT(ResolvedCollation_HasCompatibleStructure)(void * arg0,void * arg1,char* arg2){
  googlesql::ResolvedCollation *col = (googlesql::ResolvedCollation *)arg0;
  *arg2 = col->HasCompatibleStructure((const googlesql::Type *)arg1);
}

void GO_EXPORT(ResolvedCollation_HasCollation)(void * arg0,char* arg1){
  googlesql::ResolvedCollation *col = (googlesql::ResolvedCollation *)arg0;
  *arg1 = col->HasCollation();
}

void GO_EXPORT(ResolvedCollation_CollationName)(void * arg0,void ** arg1){
  googlesql::ResolvedCollation *col = (googlesql::ResolvedCollation *)arg0;
  *arg1 = (void *)((new std::string(col->CollationName()))->c_str());
}

void GO_EXPORT(ResolvedCollation_child_list)(void * arg0,void ** arg1){
  googlesql::ResolvedCollation *col = (googlesql::ResolvedCollation *)arg0;
  GET_LIST(col->child_list, arg1);
}

void GO_EXPORT(ResolvedCollation_DebugString)(void * arg0,void ** arg1){
  googlesql::ResolvedCollation *col = (googlesql::ResolvedCollation *)arg0;
  *arg1 = (void *)((new std::string(col->DebugString()))->c_str());
}

void GO_EXPORT(ResolvedFunctionCallInfo_DebugString)(void * arg0,void ** arg1){
  googlesql::ResolvedFunctionCallInfo *info = (googlesql::ResolvedFunctionCallInfo *)arg0;
  *arg1 = (void *)((new std::string(info->DebugString()))->c_str());
}
