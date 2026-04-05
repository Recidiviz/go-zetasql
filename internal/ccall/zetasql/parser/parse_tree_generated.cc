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

#include "zetasql/parser/parse_tree.h"

#include <string>

#include "zetasql/base/logging.h"
#include "zetasql/parser/ast_node_kind.h"
#include "absl/container/flat_hash_map.h"
#include "zetasql/base/map_util.h"

namespace zetasql {

// Creates a map of ASTNodeKind to a string representation of the node type's
// name. Access this map through GetNodeNamesMap().
static absl::flat_hash_map<ASTNodeKind, std::string> CreateNodeNamesMap() {
  absl::flat_hash_map<ASTNodeKind, std::string> map;
  map[AST_FAKE] = "Fake";  // For testing purposes only.

  map[AST_QUERY_STATEMENT] = "QueryStatement";
  map[AST_ALIASED_QUERY_EXPRESSION] = "AliasedQueryExpression";
  map[AST_QUERY] = "Query";
  map[AST_FROM_QUERY] = "FromQuery";
  map[AST_PIPE_EXTEND] = "PipeExtend";
  map[AST_PIPE_RENAME_ITEM] = "PipeRenameItem";
  map[AST_PIPE_RENAME] = "PipeRename";
  map[AST_PIPE_AGGREGATE] = "PipeAggregate";
  map[AST_PIPE_SET_OPERATION] = "PipeSetOperation";
  map[AST_PIPE_JOIN] = "PipeJoin";
  map[AST_PIPE_CALL] = "PipeCall";
  map[AST_PIPE_WINDOW] = "PipeWindow";
  map[AST_PIPE_WHERE] = "PipeWhere";
  map[AST_PIPE_SELECT] = "PipeSelect";
  map[AST_PIPE_LIMIT_OFFSET] = "PipeLimitOffset";
  map[AST_PIPE_ORDER_BY] = "PipeOrderBy";
  map[AST_PIPE_DISTINCT] = "PipeDistinct";
  map[AST_PIPE_TABLESAMPLE] = "PipeTablesample";
  map[AST_PIPE_AS] = "PipeAs";
  map[AST_PIPE_STATIC_DESCRIBE] = "PipeStaticDescribe";
  map[AST_PIPE_ASSERT] = "PipeAssert";
  map[AST_PIPE_DROP] = "PipeDrop";
  map[AST_PIPE_SET_ITEM] = "PipeSetItem";
  map[AST_PIPE_SET] = "PipeSet";
  map[AST_PIPE_PIVOT] = "PipePivot";
  map[AST_PIPE_UNPIVOT] = "PipeUnpivot";
  map[AST_SELECT] = "Select";
  map[AST_SELECT_LIST] = "SelectList";
  map[AST_SELECT_COLUMN] = "SelectColumn";
  map[AST_INT_LITERAL] = "IntLiteral";
  map[AST_IDENTIFIER] = "Identifier";
  map[AST_ALIAS] = "Alias";
  map[AST_PATH_EXPRESSION] = "PathExpression";
  map[AST_TABLE_PATH_EXPRESSION] = "TablePathExpression";
  map[AST_PIPE_JOIN_LHS_PLACEHOLDER] = "PipeJoinLhsPlaceholder";
  map[AST_FROM_CLAUSE] = "FromClause";
  map[AST_WHERE_CLAUSE] = "WhereClause";
  map[AST_BOOLEAN_LITERAL] = "BooleanLiteral";
  map[AST_AND_EXPR] = "AndExpr";
  map[AST_BINARY_EXPRESSION] = "BinaryExpression";
  map[AST_STRING_LITERAL] = "StringLiteral";
  map[AST_STRING_LITERAL_COMPONENT] = "StringLiteralComponent";
  map[AST_STAR] = "Star";
  map[AST_OR_EXPR] = "OrExpr";
  map[AST_ORDERING_EXPRESSION] = "OrderingExpression";
  map[AST_ORDER_BY] = "OrderBy";
  map[AST_GROUPING_ITEM_ORDER] = "GroupingItemOrder";
  map[AST_GROUPING_ITEM] = "GroupingItem";
  map[AST_GROUP_BY] = "GroupBy";
  map[AST_GROUP_BY_ALL] = "GroupByAll";
  map[AST_LIMIT_OFFSET] = "LimitOffset";
  map[AST_FLOAT_LITERAL] = "FloatLiteral";
  map[AST_NULL_LITERAL] = "NullLiteral";
  map[AST_ON_CLAUSE] = "OnClause";
  map[AST_ALIASED_QUERY] = "AliasedQuery";
  map[AST_JOIN] = "Join";
  map[AST_WITH_CLAUSE] = "WithClause";
  map[AST_HAVING] = "Having";
  map[AST_SIMPLE_TYPE] = "SimpleType";
  map[AST_ARRAY_TYPE] = "ArrayType";
  map[AST_STRUCT_FIELD] = "StructField";
  map[AST_STRUCT_TYPE] = "StructType";
  map[AST_FUNCTION_TYPE_ARG_LIST] = "FunctionTypeArgList";
  map[AST_FUNCTION_TYPE] = "FunctionType";
  map[AST_CAST_EXPRESSION] = "CastExpression";
  map[AST_SELECT_AS] = "SelectAs";
  map[AST_ROLLUP] = "Rollup";
  map[AST_CUBE] = "Cube";
  map[AST_GROUPING_SET] = "GroupingSet";
  map[AST_GROUPING_SET_LIST] = "GroupingSetList";
  map[AST_EXPRESSION_WITH_ALIAS] = "ExpressionWithAlias";
  map[AST_FUNCTION_CALL] = "FunctionCall";
  map[AST_ARRAY_CONSTRUCTOR] = "ArrayConstructor";
  map[AST_STRUCT_CONSTRUCTOR_ARG] = "StructConstructorArg";
  map[AST_STRUCT_CONSTRUCTOR_WITH_PARENS] = "StructConstructorWithParens";
  map[AST_STRUCT_CONSTRUCTOR_WITH_KEYWORD] = "StructConstructorWithKeyword";
  map[AST_IN_EXPRESSION] = "InExpression";
  map[AST_IN_LIST] = "InList";
  map[AST_BETWEEN_EXPRESSION] = "BetweenExpression";
  map[AST_NUMERIC_LITERAL] = "NumericLiteral";
  map[AST_BIGNUMERIC_LITERAL] = "BigNumericLiteral";
  map[AST_BYTES_LITERAL] = "BytesLiteral";
  map[AST_BYTES_LITERAL_COMPONENT] = "BytesLiteralComponent";
  map[AST_DATE_OR_TIME_LITERAL] = "DateOrTimeLiteral";
  map[AST_MAX_LITERAL] = "MaxLiteral";
  map[AST_JSON_LITERAL] = "JSONLiteral";
  map[AST_CASE_VALUE_EXPRESSION] = "CaseValueExpression";
  map[AST_CASE_NO_VALUE_EXPRESSION] = "CaseNoValueExpression";
  map[AST_ARRAY_ELEMENT] = "ArrayElement";
  map[AST_BITWISE_SHIFT_EXPRESSION] = "BitwiseShiftExpression";
  map[AST_COLLATE] = "Collate";
  map[AST_DOT_GENERALIZED_FIELD] = "DotGeneralizedField";
  map[AST_DOT_IDENTIFIER] = "DotIdentifier";
  map[AST_DOT_STAR] = "DotStar";
  map[AST_DOT_STAR_WITH_MODIFIERS] = "DotStarWithModifiers";
  map[AST_EXPRESSION_SUBQUERY] = "ExpressionSubquery";
  map[AST_EXTRACT_EXPRESSION] = "ExtractExpression";
  map[AST_HAVING_MODIFIER] = "HavingModifier";
  map[AST_INTERVAL_EXPR] = "IntervalExpr";
  map[AST_SEQUENCE_ARG] = "SequenceArg";
  map[AST_NAMED_ARGUMENT] = "NamedArgument";
  map[AST_NULL_ORDER] = "NullOrder";
  map[AST_ON_OR_USING_CLAUSE_LIST] = "OnOrUsingClauseList";
  map[AST_PARENTHESIZED_JOIN] = "ParenthesizedJoin";
  map[AST_PARTITION_BY] = "PartitionBy";
  map[AST_SET_OPERATION] = "SetOperation";
  map[AST_SET_OPERATION_METADATA_LIST] = "SetOperationMetadataList";
  map[AST_SET_OPERATION_ALL_OR_DISTINCT] = "SetOperationAllOrDistinct";
  map[AST_SET_OPERATION_TYPE] = "SetOperationType";
  map[AST_SET_OPERATION_COLUMN_MATCH_MODE] = "SetOperationColumnMatchMode";
  map[AST_SET_OPERATION_COLUMN_PROPAGATION_MODE] = "SetOperationColumnPropagationMode";
  map[AST_SET_OPERATION_METADATA] = "SetOperationMetadata";
  map[AST_STAR_EXCEPT_LIST] = "StarExceptList";
  map[AST_STAR_MODIFIERS] = "StarModifiers";
  map[AST_STAR_REPLACE_ITEM] = "StarReplaceItem";
  map[AST_STAR_WITH_MODIFIERS] = "StarWithModifiers";
  map[AST_TABLE_SUBQUERY] = "TableSubquery";
  map[AST_UNARY_EXPRESSION] = "UnaryExpression";
  map[AST_EXPRESSION_WITH_OPT_ALIAS] = "ExpressionWithOptAlias";
  map[AST_UNNEST_EXPRESSION] = "UnnestExpression";
  map[AST_WINDOW_CLAUSE] = "WindowClause";
  map[AST_WINDOW_DEFINITION] = "WindowDefinition";
  map[AST_WINDOW_FRAME] = "WindowFrame";
  map[AST_WINDOW_FRAME_EXPR] = "WindowFrameExpr";
  map[AST_LIKE_EXPRESSION] = "LikeExpression";
  map[AST_WINDOW_SPECIFICATION] = "WindowSpecification";
  map[AST_WITH_OFFSET] = "WithOffset";
  map[AST_ANY_SOME_ALL_OP] = "AnySomeAllOp";
  map[AST_STATEMENT_LIST] = "StatementList";
  map[AST_HINTED_STATEMENT] = "HintedStatement";
  map[AST_EXPLAIN_STATEMENT] = "ExplainStatement";
  map[AST_DESCRIBE_STATEMENT] = "DescribeStatement";
  map[AST_SHOW_STATEMENT] = "ShowStatement";
  map[AST_TRANSACTION_ISOLATION_LEVEL] = "TransactionIsolationLevel";
  map[AST_TRANSACTION_READ_WRITE_MODE] = "TransactionReadWriteMode";
  map[AST_TRANSACTION_MODE_LIST] = "TransactionModeList";
  map[AST_BEGIN_STATEMENT] = "BeginStatement";
  map[AST_SET_TRANSACTION_STATEMENT] = "SetTransactionStatement";
  map[AST_COMMIT_STATEMENT] = "CommitStatement";
  map[AST_ROLLBACK_STATEMENT] = "RollbackStatement";
  map[AST_START_BATCH_STATEMENT] = "StartBatchStatement";
  map[AST_RUN_BATCH_STATEMENT] = "RunBatchStatement";
  map[AST_ABORT_BATCH_STATEMENT] = "AbortBatchStatement";
  map[AST_DROP_ENTITY_STATEMENT] = "DropEntityStatement";
  map[AST_DROP_FUNCTION_STATEMENT] = "DropFunctionStatement";
  map[AST_DROP_TABLE_FUNCTION_STATEMENT] = "DropTableFunctionStatement";
  map[AST_DROP_ALL_ROW_ACCESS_POLICIES_STATEMENT] = "DropAllRowAccessPoliciesStatement";
  map[AST_DROP_MATERIALIZED_VIEW_STATEMENT] = "DropMaterializedViewStatement";
  map[AST_DROP_SNAPSHOT_TABLE_STATEMENT] = "DropSnapshotTableStatement";
  map[AST_DROP_SEARCH_INDEX_STATEMENT] = "DropSearchIndexStatement";
  map[AST_DROP_VECTOR_INDEX_STATEMENT] = "DropVectorIndexStatement";
  map[AST_RENAME_STATEMENT] = "RenameStatement";
  map[AST_IMPORT_STATEMENT] = "ImportStatement";
  map[AST_MODULE_STATEMENT] = "ModuleStatement";
  map[AST_WITH_CONNECTION_CLAUSE] = "WithConnectionClause";
  map[AST_INTO_ALIAS] = "IntoAlias";
  map[AST_UNNEST_EXPRESSION_WITH_OPT_ALIAS_AND_OFFSET] = "UnnestExpressionWithOptAliasAndOffset";
  map[AST_PIVOT_EXPRESSION] = "PivotExpression";
  map[AST_PIVOT_VALUE] = "PivotValue";
  map[AST_PIVOT_EXPRESSION_LIST] = "PivotExpressionList";
  map[AST_PIVOT_VALUE_LIST] = "PivotValueList";
  map[AST_PIVOT_CLAUSE] = "PivotClause";
  map[AST_UNPIVOT_IN_ITEM] = "UnpivotInItem";
  map[AST_UNPIVOT_IN_ITEM_LIST] = "UnpivotInItemList";
  map[AST_UNPIVOT_CLAUSE] = "UnpivotClause";
  map[AST_USING_CLAUSE] = "UsingClause";
  map[AST_FOR_SYSTEM_TIME] = "ForSystemTime";
  map[AST_MATCH_RECOGNIZE_CLAUSE] = "MatchRecognizeClause";
  map[AST_ROW_PATTERN_VARIABLE] = "RowPatternVariable";
  map[AST_ROW_PATTERN_OPERATION] = "RowPatternOperation";
  map[AST_QUALIFY] = "Qualify";
  map[AST_CLAMPED_BETWEEN_MODIFIER] = "ClampedBetweenModifier";
  map[AST_WITH_REPORT_MODIFIER] = "WithReportModifier";
  map[AST_FORMAT_CLAUSE] = "FormatClause";
  map[AST_PATH_EXPRESSION_LIST] = "PathExpressionList";
  map[AST_PARAMETER_EXPR] = "ParameterExpr";
  map[AST_SYSTEM_VARIABLE_EXPR] = "SystemVariableExpr";
  map[AST_WITH_GROUP_ROWS] = "WithGroupRows";
  map[AST_LAMBDA] = "Lambda";
  map[AST_ANALYTIC_FUNCTION_CALL] = "AnalyticFunctionCall";
  map[AST_FUNCTION_CALL_WITH_GROUP_ROWS] = "FunctionCallWithGroupRows";
  map[AST_CLUSTER_BY] = "ClusterBy";
  map[AST_NEW_CONSTRUCTOR_ARG] = "NewConstructorArg";
  map[AST_NEW_CONSTRUCTOR] = "NewConstructor";
  map[AST_BRACED_CONSTRUCTOR_LHS] = "BracedConstructorLhs";
  map[AST_BRACED_CONSTRUCTOR_FIELD_VALUE] = "BracedConstructorFieldValue";
  map[AST_BRACED_CONSTRUCTOR_FIELD] = "BracedConstructorField";
  map[AST_BRACED_CONSTRUCTOR] = "BracedConstructor";
  map[AST_BRACED_NEW_CONSTRUCTOR] = "BracedNewConstructor";
  map[AST_STRUCT_BRACED_CONSTRUCTOR] = "StructBracedConstructor";
  map[AST_OPTIONS_LIST] = "OptionsList";
  map[AST_OPTIONS_ENTRY] = "OptionsEntry";
  map[AST_FUNCTION_PARAMETER] = "FunctionParameter";
  map[AST_FUNCTION_PARAMETERS] = "FunctionParameters";
  map[AST_FUNCTION_DECLARATION] = "FunctionDeclaration";
  map[AST_SQL_FUNCTION_BODY] = "SqlFunctionBody";
  map[AST_TVF_ARGUMENT] = "TVFArgument";
  map[AST_TVF] = "TVF";
  map[AST_TABLE_CLAUSE] = "TableClause";
  map[AST_MODEL_CLAUSE] = "ModelClause";
  map[AST_CONNECTION_CLAUSE] = "ConnectionClause";
  map[AST_CLONE_DATA_SOURCE] = "CloneDataSource";
  map[AST_COPY_DATA_SOURCE] = "CopyDataSource";
  map[AST_CLONE_DATA_SOURCE_LIST] = "CloneDataSourceList";
  map[AST_CLONE_DATA_STATEMENT] = "CloneDataStatement";
  map[AST_CREATE_CONNECTION_STATEMENT] = "CreateConnectionStatement";
  map[AST_CREATE_CONSTANT_STATEMENT] = "CreateConstantStatement";
  map[AST_CREATE_DATABASE_STATEMENT] = "CreateDatabaseStatement";
  map[AST_CREATE_PROCEDURE_STATEMENT] = "CreateProcedureStatement";
  map[AST_CREATE_SCHEMA_STATEMENT] = "CreateSchemaStatement";
  map[AST_CREATE_EXTERNAL_SCHEMA_STATEMENT] = "CreateExternalSchemaStatement";
  map[AST_ALIASED_QUERY_LIST] = "AliasedQueryList";
  map[AST_TRANSFORM_CLAUSE] = "TransformClause";
  map[AST_CREATE_MODEL_STATEMENT] = "CreateModelStatement";
  map[AST_INDEX_ALL_COLUMNS] = "IndexAllColumns";
  map[AST_INDEX_ITEM_LIST] = "IndexItemList";
  map[AST_INDEX_STORING_EXPRESSION_LIST] = "IndexStoringExpressionList";
  map[AST_INDEX_UNNEST_EXPRESSION_LIST] = "IndexUnnestExpressionList";
  map[AST_CREATE_INDEX_STATEMENT] = "CreateIndexStatement";
  map[AST_EXPORT_DATA_STATEMENT] = "ExportDataStatement";
  map[AST_EXPORT_MODEL_STATEMENT] = "ExportModelStatement";
  map[AST_EXPORT_METADATA_STATEMENT] = "ExportMetadataStatement";
  map[AST_CALL_STATEMENT] = "CallStatement";
  map[AST_DEFINE_TABLE_STATEMENT] = "DefineTableStatement";
  map[AST_WITH_PARTITION_COLUMNS_CLAUSE] = "WithPartitionColumnsClause";
  map[AST_CREATE_SNAPSHOT_STATEMENT] = "CreateSnapshotStatement";
  map[AST_CREATE_SNAPSHOT_TABLE_STATEMENT] = "CreateSnapshotTableStatement";
  map[AST_TYPE_PARAMETER_LIST] = "TypeParameterList";
  map[AST_TVF_SCHEMA] = "TVFSchema";
  map[AST_TVF_SCHEMA_COLUMN] = "TVFSchemaColumn";
  map[AST_TABLE_AND_COLUMN_INFO] = "TableAndColumnInfo";
  map[AST_TABLE_AND_COLUMN_INFO_LIST] = "TableAndColumnInfoList";
  map[AST_TEMPLATED_PARAMETER_TYPE] = "TemplatedParameterType";
  map[AST_DEFAULT_LITERAL] = "DefaultLiteral";
  map[AST_ANALYZE_STATEMENT] = "AnalyzeStatement";
  map[AST_ASSERT_STATEMENT] = "AssertStatement";
  map[AST_ASSERT_ROWS_MODIFIED] = "AssertRowsModified";
  map[AST_RETURNING_CLAUSE] = "ReturningClause";
  map[AST_DELETE_STATEMENT] = "DeleteStatement";
  map[AST_NOT_NULL_COLUMN_ATTRIBUTE] = "NotNullColumnAttribute";
  map[AST_HIDDEN_COLUMN_ATTRIBUTE] = "HiddenColumnAttribute";
  map[AST_PRIMARY_KEY_COLUMN_ATTRIBUTE] = "PrimaryKeyColumnAttribute";
  map[AST_FOREIGN_KEY_COLUMN_ATTRIBUTE] = "ForeignKeyColumnAttribute";
  map[AST_COLUMN_ATTRIBUTE_LIST] = "ColumnAttributeList";
  map[AST_STRUCT_COLUMN_FIELD] = "StructColumnField";
  map[AST_GENERATED_COLUMN_INFO] = "GeneratedColumnInfo";
  map[AST_COLUMN_DEFINITION] = "ColumnDefinition";
  map[AST_TABLE_ELEMENT_LIST] = "TableElementList";
  map[AST_COLUMN_LIST] = "ColumnList";
  map[AST_COLUMN_POSITION] = "ColumnPosition";
  map[AST_INSERT_VALUES_ROW] = "InsertValuesRow";
  map[AST_INSERT_VALUES_ROW_LIST] = "InsertValuesRowList";
  map[AST_INSERT_STATEMENT] = "InsertStatement";
  map[AST_UPDATE_SET_VALUE] = "UpdateSetValue";
  map[AST_UPDATE_ITEM] = "UpdateItem";
  map[AST_UPDATE_ITEM_LIST] = "UpdateItemList";
  map[AST_UPDATE_STATEMENT] = "UpdateStatement";
  map[AST_TRUNCATE_STATEMENT] = "TruncateStatement";
  map[AST_MERGE_ACTION] = "MergeAction";
  map[AST_MERGE_WHEN_CLAUSE] = "MergeWhenClause";
  map[AST_MERGE_WHEN_CLAUSE_LIST] = "MergeWhenClauseList";
  map[AST_MERGE_STATEMENT] = "MergeStatement";
  map[AST_PRIVILEGE] = "Privilege";
  map[AST_PRIVILEGES] = "Privileges";
  map[AST_GRANTEE_LIST] = "GranteeList";
  map[AST_GRANT_STATEMENT] = "GrantStatement";
  map[AST_REVOKE_STATEMENT] = "RevokeStatement";
  map[AST_REPEATABLE_CLAUSE] = "RepeatableClause";
  map[AST_FILTER_FIELDS_ARG] = "FilterFieldsArg";
  map[AST_REPLACE_FIELDS_ARG] = "ReplaceFieldsArg";
  map[AST_REPLACE_FIELDS_EXPRESSION] = "ReplaceFieldsExpression";
  map[AST_SAMPLE_SIZE] = "SampleSize";
  map[AST_WITH_WEIGHT] = "WithWeight";
  map[AST_SAMPLE_SUFFIX] = "SampleSuffix";
  map[AST_SAMPLE_CLAUSE] = "SampleClause";
  map[AST_SET_OPTIONS_ACTION] = "SetOptionsAction";
  map[AST_SET_AS_ACTION] = "SetAsAction";
  map[AST_ADD_CONSTRAINT_ACTION] = "AddConstraintAction";
  map[AST_DROP_PRIMARY_KEY_ACTION] = "DropPrimaryKeyAction";
  map[AST_DROP_CONSTRAINT_ACTION] = "DropConstraintAction";
  map[AST_ALTER_CONSTRAINT_ENFORCEMENT_ACTION] = "AlterConstraintEnforcementAction";
  map[AST_ALTER_CONSTRAINT_SET_OPTIONS_ACTION] = "AlterConstraintSetOptionsAction";
  map[AST_ADD_COLUMN_ACTION] = "AddColumnAction";
  map[AST_DROP_COLUMN_ACTION] = "DropColumnAction";
  map[AST_RENAME_COLUMN_ACTION] = "RenameColumnAction";
  map[AST_ALTER_COLUMN_TYPE_ACTION] = "AlterColumnTypeAction";
  map[AST_ALTER_COLUMN_OPTIONS_ACTION] = "AlterColumnOptionsAction";
  map[AST_ALTER_COLUMN_SET_DEFAULT_ACTION] = "AlterColumnSetDefaultAction";
  map[AST_ALTER_COLUMN_DROP_DEFAULT_ACTION] = "AlterColumnDropDefaultAction";
  map[AST_ALTER_COLUMN_DROP_NOT_NULL_ACTION] = "AlterColumnDropNotNullAction";
  map[AST_ALTER_COLUMN_DROP_GENERATED_ACTION] = "AlterColumnDropGeneratedAction";
  map[AST_GRANT_TO_CLAUSE] = "GrantToClause";
  map[AST_RESTRICT_TO_CLAUSE] = "RestrictToClause";
  map[AST_ADD_TO_RESTRICTEE_LIST_CLAUSE] = "AddToRestricteeListClause";
  map[AST_REMOVE_FROM_RESTRICTEE_LIST_CLAUSE] = "RemoveFromRestricteeListClause";
  map[AST_FILTER_USING_CLAUSE] = "FilterUsingClause";
  map[AST_REVOKE_FROM_CLAUSE] = "RevokeFromClause";
  map[AST_RENAME_TO_CLAUSE] = "RenameToClause";
  map[AST_SET_COLLATE_CLAUSE] = "SetCollateClause";
  map[AST_ALTER_SUB_ENTITY_ACTION] = "AlterSubEntityAction";
  map[AST_ADD_SUB_ENTITY_ACTION] = "AddSubEntityAction";
  map[AST_DROP_SUB_ENTITY_ACTION] = "DropSubEntityAction";
  map[AST_ADD_TTL_ACTION] = "AddTtlAction";
  map[AST_REPLACE_TTL_ACTION] = "ReplaceTtlAction";
  map[AST_DROP_TTL_ACTION] = "DropTtlAction";
  map[AST_ALTER_ACTION_LIST] = "AlterActionList";
  map[AST_ALTER_ALL_ROW_ACCESS_POLICIES_STATEMENT] = "AlterAllRowAccessPoliciesStatement";
  map[AST_FOREIGN_KEY_ACTIONS] = "ForeignKeyActions";
  map[AST_FOREIGN_KEY_REFERENCE] = "ForeignKeyReference";
  map[AST_SCRIPT] = "Script";
  map[AST_ELSEIF_CLAUSE] = "ElseifClause";
  map[AST_ELSEIF_CLAUSE_LIST] = "ElseifClauseList";
  map[AST_IF_STATEMENT] = "IfStatement";
  map[AST_WHEN_THEN_CLAUSE] = "WhenThenClause";
  map[AST_WHEN_THEN_CLAUSE_LIST] = "WhenThenClauseList";
  map[AST_CASE_STATEMENT] = "CaseStatement";
  map[AST_HINT] = "Hint";
  map[AST_HINT_ENTRY] = "HintEntry";
  map[AST_UNPIVOT_IN_ITEM_LABEL] = "UnpivotInItemLabel";
  map[AST_DESCRIPTOR] = "Descriptor";
  map[AST_SIMPLE_COLUMN_SCHEMA] = "SimpleColumnSchema";
  map[AST_ARRAY_COLUMN_SCHEMA] = "ArrayColumnSchema";
  map[AST_RANGE_COLUMN_SCHEMA] = "RangeColumnSchema";
  map[AST_PRIMARY_KEY_ELEMENT] = "PrimaryKeyElement";
  map[AST_PRIMARY_KEY_ELEMENT_LIST] = "PrimaryKeyElementList";
  map[AST_PRIMARY_KEY] = "PrimaryKey";
  map[AST_FOREIGN_KEY] = "ForeignKey";
  map[AST_CHECK_CONSTRAINT] = "CheckConstraint";
  map[AST_DESCRIPTOR_COLUMN] = "DescriptorColumn";
  map[AST_DESCRIPTOR_COLUMN_LIST] = "DescriptorColumnList";
  map[AST_CREATE_ENTITY_STATEMENT] = "CreateEntityStatement";
  map[AST_RAISE_STATEMENT] = "RaiseStatement";
  map[AST_EXCEPTION_HANDLER] = "ExceptionHandler";
  map[AST_EXCEPTION_HANDLER_LIST] = "ExceptionHandlerList";
  map[AST_BEGIN_END_BLOCK] = "BeginEndBlock";
  map[AST_IDENTIFIER_LIST] = "IdentifierList";
  map[AST_VARIABLE_DECLARATION] = "VariableDeclaration";
  map[AST_UNTIL_CLAUSE] = "UntilClause";
  map[AST_BREAK_STATEMENT] = "BreakStatement";
  map[AST_CONTINUE_STATEMENT] = "ContinueStatement";
  map[AST_DROP_PRIVILEGE_RESTRICTION_STATEMENT] = "DropPrivilegeRestrictionStatement";
  map[AST_DROP_ROW_ACCESS_POLICY_STATEMENT] = "DropRowAccessPolicyStatement";
  map[AST_CREATE_PRIVILEGE_RESTRICTION_STATEMENT] = "CreatePrivilegeRestrictionStatement";
  map[AST_CREATE_ROW_ACCESS_POLICY_STATEMENT] = "CreateRowAccessPolicyStatement";
  map[AST_DROP_STATEMENT] = "DropStatement";
  map[AST_RETURN_STATEMENT] = "ReturnStatement";
  map[AST_SINGLE_ASSIGNMENT] = "SingleAssignment";
  map[AST_PARAMETER_ASSIGNMENT] = "ParameterAssignment";
  map[AST_SYSTEM_VARIABLE_ASSIGNMENT] = "SystemVariableAssignment";
  map[AST_ASSIGNMENT_FROM_STRUCT] = "AssignmentFromStruct";
  map[AST_CREATE_TABLE_STATEMENT] = "CreateTableStatement";
  map[AST_CREATE_EXTERNAL_TABLE_STATEMENT] = "CreateExternalTableStatement";
  map[AST_CREATE_VIEW_STATEMENT] = "CreateViewStatement";
  map[AST_CREATE_MATERIALIZED_VIEW_STATEMENT] = "CreateMaterializedViewStatement";
  map[AST_CREATE_APPROX_VIEW_STATEMENT] = "CreateApproxViewStatement";
  map[AST_WHILE_STATEMENT] = "WhileStatement";
  map[AST_REPEAT_STATEMENT] = "RepeatStatement";
  map[AST_FOR_IN_STATEMENT] = "ForInStatement";
  map[AST_ALTER_CONNECTION_STATEMENT] = "AlterConnectionStatement";
  map[AST_ALTER_DATABASE_STATEMENT] = "AlterDatabaseStatement";
  map[AST_ALTER_SCHEMA_STATEMENT] = "AlterSchemaStatement";
  map[AST_ALTER_EXTERNAL_SCHEMA_STATEMENT] = "AlterExternalSchemaStatement";
  map[AST_ALTER_TABLE_STATEMENT] = "AlterTableStatement";
  map[AST_ALTER_VIEW_STATEMENT] = "AlterViewStatement";
  map[AST_ALTER_MATERIALIZED_VIEW_STATEMENT] = "AlterMaterializedViewStatement";
  map[AST_ALTER_APPROX_VIEW_STATEMENT] = "AlterApproxViewStatement";
  map[AST_ALTER_MODEL_STATEMENT] = "AlterModelStatement";
  map[AST_ALTER_PRIVILEGE_RESTRICTION_STATEMENT] = "AlterPrivilegeRestrictionStatement";
  map[AST_ALTER_ROW_ACCESS_POLICY_STATEMENT] = "AlterRowAccessPolicyStatement";
  map[AST_ALTER_ENTITY_STATEMENT] = "AlterEntityStatement";
  map[AST_CREATE_FUNCTION_STATEMENT] = "CreateFunctionStatement";
  map[AST_CREATE_TABLE_FUNCTION_STATEMENT] = "CreateTableFunctionStatement";
  map[AST_STRUCT_COLUMN_SCHEMA] = "StructColumnSchema";
  map[AST_INFERRED_TYPE_COLUMN_SCHEMA] = "InferredTypeColumnSchema";
  map[AST_EXECUTE_INTO_CLAUSE] = "ExecuteIntoClause";
  map[AST_EXECUTE_USING_ARGUMENT] = "ExecuteUsingArgument";
  map[AST_EXECUTE_USING_CLAUSE] = "ExecuteUsingClause";
  map[AST_EXECUTE_IMMEDIATE_STATEMENT] = "ExecuteImmediateStatement";
  map[AST_AUX_LOAD_DATA_FROM_FILES_OPTIONS_LIST] = "AuxLoadDataFromFilesOptionsList";
  map[AST_AUX_LOAD_DATA_PARTITIONS_CLAUSE] = "AuxLoadDataPartitionsClause";
  map[AST_AUX_LOAD_DATA_STATEMENT] = "AuxLoadDataStatement";
  map[AST_LABEL] = "Label";
  map[AST_WITH_EXPRESSION] = "WithExpression";
  map[AST_TTL_CLAUSE] = "TtlClause";
  map[AST_LOCATION] = "Location";
  map[AST_INPUT_OUTPUT_CLAUSE] = "InputOutputClause";
  map[AST_SPANNER_TABLE_OPTIONS] = "SpannerTableOptions";
  map[AST_SPANNER_INTERLEAVE_CLAUSE] = "SpannerInterleaveClause";
  map[AST_SPANNER_ALTER_COLUMN_ACTION] = "SpannerAlterColumnAction";
  map[AST_SPANNER_SET_ON_DELETE_ACTION] = "SpannerSetOnDeleteAction";
  map[AST_RANGE_LITERAL] = "RangeLiteral";
  map[AST_RANGE_TYPE] = "RangeType";
  map[AST_SELECT_WITH] = "SelectWith";
  map[AST_COLUMN_WITH_OPTIONS] = "ColumnWithOptions";
  map[AST_COLUMN_WITH_OPTIONS_LIST] = "ColumnWithOptionsList";
  map[AST_MACRO_BODY] = "MacroBody";
  map[AST_DEFINE_MACRO_STATEMENT] = "DefineMacroStatement";
  map[AST_UNDROP_STATEMENT] = "UndropStatement";
  map[AST_IDENTITY_COLUMN_INFO] = "IdentityColumnInfo";
  map[AST_IDENTITY_COLUMN_START_WITH] = "IdentityColumnStartWith";
  map[AST_IDENTITY_COLUMN_INCREMENT_BY] = "IdentityColumnIncrementBy";
  map[AST_IDENTITY_COLUMN_MAX_VALUE] = "IdentityColumnMaxValue";
  map[AST_IDENTITY_COLUMN_MIN_VALUE] = "IdentityColumnMinValue";
  map[AST_ALIASED_QUERY_MODIFIERS] = "AliasedQueryModifiers";
  map[AST_INT_OR_UNBOUNDED] = "IntOrUnbounded";
  map[AST_RECURSION_DEPTH_MODIFIER] = "RecursionDepthModifier";
  map[AST_MAP_TYPE] = "MapType";

  for (int kind = kFirstASTNodeKind; kind <= kLastASTNodeKind;
       ++kind) {
    ABSL_DCHECK(map.contains(static_cast<ASTNodeKind>(kind))) << "kind=" << kind;
  }
  return map;
}

// Returns a map of ASTNodeKind to a string representation of the node type's
// name.
static const absl::flat_hash_map<ASTNodeKind, std::string>& GetNodeNamesMap() {
  static const absl::flat_hash_map<ASTNodeKind, std::string>& map =
      *new auto(CreateNodeNamesMap());
  return map;
}

std::string ASTNode::NodeKindToString(ASTNodeKind node_kind) {
  // Subtle: we must ensure that default_value outlives the FindWithDefault
  // call.
  const std::string default_value = "<UNKNOWN NODE KIND>";

  return
zetasql_base::FindWithDefault(
      GetNodeNamesMap(), node_kind, default_value);
}

}  // namespace zetasql