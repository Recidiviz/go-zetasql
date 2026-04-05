// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h
 ** Define the zetasql_bison_parser::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_ZETASQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
# define YY_ZETASQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
// //                    "%code requires" blocks.
#line 17 "zetasql/parser/bison_parser.y" // lalr1.cc:401

// Bison parser for ZetaSQL. This works in conjunction with
// zetasql::parser::BisonParser.
//
// To debug the state machine in case of conflicts, run (locally):
// $ bison bison_parser.y -Wprecedence -Wcounterexamples -b tmp_prefix -r all \
//     --report-file=$HOME/bison_report.txt
// (Do NOT set the --report-file to a path on citc, because then the file will
// be truncated at 1MB for some reason.)

#include <cstdint>

#include "zetasql/parser/bison_parser.h"
#include "zetasql/parser/join_processor.h"
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/parser_internal.h"
#include "zetasql/parser/statement_properties.h"
#include "zetasql/public/parse_location.h"
#include "zetasql/public/strings.h"
#include "zetasql/base/case.h"
#include "absl/memory/memory.h"
#include "absl/strings/match.h"
#include "absl/strings/str_join.h"
#include "absl/strings/str_format.h"
#include "absl/status/status.h"

#define YYINITDEPTH 50
#ifndef YYDEBUG
#define YYDEBUG 0
#endif

// Define the handling of our custom ParseLocationRange.
# define YYLLOC_DEFAULT(Cur, Rhs, N)           \
do                                             \
  if (N)                                       \
  {                                            \
    (Cur).set_start(YYRHSLOC(Rhs, 1).start()); \
    (Cur).set_end(YYRHSLOC(Rhs, N).end());     \
  }                                            \
  else                                         \
  {                                            \
    (Cur).set_start(YYRHSLOC(Rhs, 0).end());   \
    (Cur).set_end(YYRHSLOC(Rhs, 0).end());     \
  }                                            \
while (0)

#line 95 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace zetasql_bison_parser {
#line 206 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401



  /// A Bison parser.
  class BisonParserImpl
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 249 "zetasql/parser/bison_parser.y" // lalr1.cc:401

  bool boolean;
  int64_t int64_val;
  struct {
    const char* str;
    size_t len;
  } string_view;
  const char* string_constant;
  zetasql::TypeKind type_kind;
  zetasql::ASTFunctionCall::NullHandlingModifier null_handling_modifier;
  zetasql::ASTWindowFrame::FrameUnit frame_unit;
  zetasql::ASTTemplatedParameterType::TemplatedTypeKind
      templated_parameter_kind;
  zetasql::ASTBinaryExpression::Op binary_op;
  zetasql::ASTUnaryExpression::Op unary_op;
  zetasql::ASTOptionsEntry::AssignmentOp options_assignment_op;
  zetasql::ASTJoin::JoinType join_type;
  zetasql::ASTJoin::JoinHint join_hint;
  zetasql::ASTSampleSize::Unit sample_size_unit;
  zetasql::ASTInsertStatement::InsertMode insert_mode;
  zetasql::ASTNodeKind ast_node_kind;
  zetasql::ASTUnpivotClause::NullFilter opt_unpivot_nulls_filter;
  zetasql::parser_internal::NotKeywordPresence not_keyword_presence;
  zetasql::parser_internal::AllOrDistinctKeyword all_or_distinct_keyword;
  zetasql::SchemaObjectKind schema_object_kind_keyword;
  zetasql::parser_internal::PrecedingOrFollowingKeyword
      preceding_or_following_keyword;
  zetasql::parser_internal::TableOrTableFunctionKeywords
      table_or_table_function_keywords;
  zetasql::parser_internal::IndexTypeKeywords
      index_type_keywords;
  zetasql::parser_internal::ShiftOperator shift_operator;
  zetasql::parser_internal::ImportType import_type;
  zetasql::ASTAuxLoadDataStatement::InsertionMode insertion_mode;
  zetasql::ASTCreateStatement::Scope create_scope;
  zetasql::ASTCreateStatement::SqlSecurity sql_security;
  zetasql::ASTCreateStatement::SqlSecurity external_security;
  zetasql::ASTDropStatement::DropMode drop_mode;
  zetasql::ASTForeignKeyReference::Match foreign_key_match;
  zetasql::ASTForeignKeyActions::Action foreign_key_action;
  zetasql::ASTFunctionParameter::ProcedureParameterMode parameter_mode;
  zetasql::ASTCreateFunctionStmtBase::DeterminismLevel determinism_level;
  zetasql::ASTGeneratedColumnInfo::StoredMode stored_mode;
  zetasql::ASTGeneratedColumnInfo::GeneratedMode generated_mode;
  zetasql::ASTOrderingExpression::OrderingSpec ordering_spec;
  zetasql::ASTSelectWith* select_with;
  zetasql::ASTSetOperationColumnMatchMode* column_match_mode;
  zetasql::ASTSetOperationColumnPropagationMode* column_propagation_mode;

  // Not owned. The allocated nodes are all owned by the parser.
  // Nodes should use the most specific type available.
  zetasql::ASTForeignKeyReference* foreign_key_reference;
  zetasql::ASTSetOperation* query_set_operation;
  zetasql::ASTInsertValuesRowList* insert_values_row_list;
  zetasql::ASTQuery* query;
  zetasql::ASTExpression* expression;
  zetasql::ASTExpressionSubquery* expression_subquery;
  zetasql::ASTFunctionCall* function_call;
  zetasql::ASTAlias* alias;
  zetasql::ASTIdentifier* identifier;
  zetasql::ASTInsertStatement* insert_statement;
  zetasql::ASTNode* node;
  zetasql::ASTStatementList* statement_list;
  zetasql::parser_internal::SeparatedIdentifierTmpNode* slashed_identifier;
  zetasql::ASTPivotClause* pivot_clause;
  zetasql::ASTUnpivotClause* unpivot_clause;
  zetasql::ASTSetOperationType* set_operation_type;
  zetasql::ASTSetOperationAllOrDistinct* set_operation_all_or_distinct;
  zetasql::ASTBytesLiteral* bytes_literal;
  zetasql::ASTBytesLiteralComponent* bytes_literal_component;
  zetasql::ASTStringLiteral* string_literal;
  zetasql::ASTStringLiteralComponent* string_literal_component;
  struct {
    zetasql::ASTPivotClause* pivot_clause;
    zetasql::ASTUnpivotClause* unpivot_clause;
    zetasql::ASTAlias* alias;
  } pivot_or_unpivot_clause_and_alias;
  struct {
    zetasql::ASTNode* where;
    zetasql::ASTNode* group_by;
    zetasql::ASTNode* having;
    zetasql::ASTNode* qualify;
    zetasql::ASTNode* window;
  } clauses_following_from;
  struct {
    zetasql::ASTExpression* default_expression;
    zetasql::ASTGeneratedColumnInfo* generated_column_info;
  } generated_or_default_column_info;
  struct {
    zetasql::ASTWithPartitionColumnsClause* with_partition_columns_clause;
    zetasql::ASTWithConnectionClause* with_connection_clause;
  } external_table_with_clauses;
  struct {
    zetasql::ASTIdentifier* language;
    bool is_remote;
    zetasql::ASTWithConnectionClause* with_connection_clause;
  } language_or_remote_with_connection;
  struct {
    zetasql::ASTIdentifier* language;
    zetasql::ASTNode* options;
  } language_options_set;
  struct {
    zetasql::ASTNode* options;
    zetasql::ASTNode* body;
  } options_body_set;
  struct {
    zetasql::ASTScript* body;
    zetasql::ASTIdentifier* language;
    zetasql::ASTNode* code;
  } begin_end_block_or_language_as_code;
  struct {
    zetasql::ASTExpression* maybe_dashed_path_expression;
    bool is_temp_table;
  } path_expression_with_scope;
  struct {
    zetasql::ASTSetOperationColumnMatchMode* column_match_mode;
    zetasql::ASTColumnList* column_list;
  } column_match_suffix;
  struct {
    zetasql::ASTQuery* query;
    zetasql::ASTPathExpression* replica_source;
  } query_or_replica_source_info;
  struct {
    zetasql::ASTNode* hint;
  } group_by_preamble;
  zetasql::ASTStructBracedConstructor* struct_braced_constructor;
  zetasql::ASTBracedConstructor* braced_constructor;
  zetasql::ASTBracedConstructorField* braced_constructor_field;
  zetasql::ASTBracedConstructorFieldValue* braced_constructor_field_value;

#line 349 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef zetasql::ParseLocationRange location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        YYEOF = 0,
        DOLLAR_SIGN = 258,
        MACRO_INVOCATION = 259,
        MACRO_ARGUMENT_REFERENCE = 260,
        STRING_LITERAL = 261,
        BYTES_LITERAL = 262,
        INTEGER_LITERAL = 263,
        FLOATING_POINT_LITERAL = 264,
        IDENTIFIER = 265,
        BACKSLASH = 266,
        SCRIPT_LABEL = 267,
        COMMENT = 268,
        KW_ADD_ASSIGN = 269,
        KW_SUB_ASSIGN = 270,
        KW_NOT_EQUALS_C_STYLE = 271,
        KW_NOT_EQUALS_SQL_STYLE = 272,
        KW_LESS_EQUALS = 273,
        KW_GREATER_EQUALS = 274,
        KW_DOUBLE_AT = 275,
        KW_CONCAT_OP = 276,
        KW_OPEN_HINT = 277,
        KW_OPEN_INTEGER_HINT = 278,
        OPEN_INTEGER_PREFIX_HINT = 279,
        KW_SHIFT_LEFT = 280,
        KW_SHIFT_RIGHT = 281,
        KW_NAMED_ARGUMENT_ASSIGNMENT = 282,
        KW_LAMBDA_ARROW = 283,
        UNARY_NOT_PRECEDENCE = 284,
        UNARY_PRECEDENCE = 285,
        DOUBLE_AT_PRECEDENCE = 286,
        PRIMARY_PRECEDENCE = 287,
        SENTINEL_RESERVED_KW_START = 288,
        KW_ALL = 289,
        KW_AND = 290,
        KW_ANY = 291,
        KW_ARRAY = 292,
        KW_AS = 293,
        KW_ASC = 294,
        KW_ASSERT_ROWS_MODIFIED = 295,
        KW_AT = 296,
        KW_BETWEEN = 297,
        KW_BY = 298,
        KW_CASE = 299,
        KW_CAST = 300,
        KW_COLLATE = 301,
        KW_CREATE = 302,
        KW_CROSS = 303,
        KW_CURRENT = 304,
        KW_DEFAULT = 305,
        KW_DEFINE_FOR_MACROS = 306,
        KW_DEFINE = 307,
        KW_DESC = 308,
        KW_DISTINCT = 309,
        KW_ELSE = 310,
        KW_END = 311,
        KW_ENUM = 312,
        KW_EXCEPT = 313,
        KW_EXISTS = 314,
        KW_EXTRACT = 315,
        KW_FALSE = 316,
        KW_FOLLOWING = 317,
        KW_FROM = 318,
        KW_FULL = 319,
        KW_GROUP = 320,
        KW_GROUPING = 321,
        KW_HASH = 322,
        KW_HAVING = 323,
        KW_IF = 324,
        KW_IGNORE = 325,
        KW_IN = 326,
        KW_INNER = 327,
        KW_INTERSECT = 328,
        KW_INTERVAL = 329,
        KW_INTO = 330,
        KW_IS = 331,
        KW_JOIN = 332,
        KW_LEFT = 333,
        KW_LIKE = 334,
        KW_LIMIT = 335,
        KW_LOOKUP = 336,
        KW_MERGE = 337,
        KW_NATURAL = 338,
        KW_NEW = 339,
        KW_NO = 340,
        KW_NOT = 341,
        KW_NULL = 342,
        KW_NULLS = 343,
        KW_ON = 344,
        KW_OR = 345,
        KW_ORDER = 346,
        KW_OUTER = 347,
        KW_OVER = 348,
        KW_PARTITION = 349,
        KW_PRECEDING = 350,
        KW_PROTO = 351,
        KW_RANGE = 352,
        KW_RECURSIVE = 353,
        KW_RESPECT = 354,
        KW_RIGHT = 355,
        KW_ROLLUP = 356,
        KW_ROWS = 357,
        KW_SELECT = 358,
        KW_SET = 359,
        KW_STRUCT = 360,
        KW_TABLESAMPLE = 361,
        KW_THEN = 362,
        KW_TO = 363,
        KW_TRUE = 364,
        KW_UNBOUNDED = 365,
        KW_UNION = 366,
        KW_USING = 367,
        KW_WHEN = 368,
        KW_WHERE = 369,
        KW_WINDOW = 370,
        KW_WITH = 371,
        KW_UNNEST = 372,
        KW_CONTAINS = 373,
        KW_CUBE = 374,
        KW_ESCAPE = 375,
        KW_EXCLUDE = 376,
        KW_FETCH = 377,
        KW_FOR = 378,
        KW_GROUPS = 379,
        KW_LATERAL = 380,
        KW_OF = 381,
        KW_SOME = 382,
        KW_TREAT = 383,
        KW_WITHIN = 384,
        KW_QUALIFY_RESERVED = 385,
        SENTINEL_RESERVED_KW_END = 386,
        SENTINEL_LB_TOKEN_START = 387,
        LB_OPEN_STATEMENT_BLOCK = 388,
        LB_BEGIN_AT_STATEMENT_START = 389,
        LB_EXPLAIN_SQL_STATEMENT = 390,
        LB_END_OF_STATEMENT_LEVEL_HINT = 391,
        LB_DOT_IN_PATH_EXPRESSION = 392,
        LB_OPEN_NESTED_DML = 393,
        LB_OPEN_TYPE_TEMPLATE = 394,
        LB_CLOSE_TYPE_TEMPLATE = 395,
        LB_WITH_IN_SELECT_WITH_OPTIONS = 396,
        SENTINEL_LB_TOKEN_END = 397,
        KW_WITH_STARTING_WITH_GROUP_ROWS = 398,
        KW_WITH_STARTING_WITH_EXPRESSION = 399,
        KW_EXCEPT_IN_SET_OP = 400,
        KW_FULL_IN_SET_OP = 401,
        KW_LEFT_IN_SET_OP = 402,
        KW_REPLACE_AFTER_INSERT = 403,
        KW_UPDATE_AFTER_INSERT = 404,
        KW_NOT_SPECIAL = 405,
        KW_OPTIONS_IN_SELECT_WITH_OPTIONS = 406,
        INVALID_LITERAL_PRECEDING_IDENTIFIER_NO_SPACE = 407,
        DECIMAL_INTEGER_LITERAL = 408,
        HEX_INTEGER_LITERAL = 409,
        EXP_IN_FLOAT_NO_SIGN = 410,
        STANDALONE_EXPONENT_SIGN = 411,
        SENTINEL_NONRESERVED_KW_START = 412,
        KW_ABORT = 413,
        KW_ACCESS = 414,
        KW_ACTION = 415,
        KW_ADD = 416,
        KW_AGGREGATE = 417,
        KW_ALTER = 418,
        KW_ALWAYS = 419,
        KW_ANALYZE = 420,
        KW_APPROX = 421,
        KW_ARE = 422,
        KW_ASSERT = 423,
        KW_BATCH = 424,
        KW_BEGIN = 425,
        KW_BIGDECIMAL = 426,
        KW_BIGNUMERIC = 427,
        KW_BREAK = 428,
        KW_CALL = 429,
        KW_CASCADE = 430,
        KW_CHECK = 431,
        KW_CLAMPED = 432,
        KW_CLONE = 433,
        KW_COPY = 434,
        KW_CLUSTER = 435,
        KW_COLUMN = 436,
        KW_COLUMNS = 437,
        KW_COMMIT = 438,
        KW_CONNECTION = 439,
        KW_CONTINUE = 440,
        KW_CONSTANT = 441,
        KW_CONSTRAINT = 442,
        KW_CYCLE = 443,
        KW_DATA = 444,
        KW_DATABASE = 445,
        KW_DATE = 446,
        KW_DATETIME = 447,
        KW_DECIMAL = 448,
        KW_DECLARE = 449,
        KW_DEFINER = 450,
        KW_DELETE = 451,
        KW_DELETION = 452,
        KW_DEPTH = 453,
        KW_DESCRIBE = 454,
        KW_DESCRIPTOR = 455,
        KW_DETERMINISTIC = 456,
        KW_DO = 457,
        KW_DROP = 458,
        KW_ENFORCED = 459,
        KW_ELSEIF = 460,
        KW_EXECUTE = 461,
        KW_EXPLAIN = 462,
        KW_EXPORT = 463,
        KW_EXTEND = 464,
        KW_EXTERNAL = 465,
        KW_FILES = 466,
        KW_FILTER = 467,
        KW_FILL = 468,
        KW_FIRST = 469,
        KW_FOREIGN = 470,
        KW_FORMAT = 471,
        KW_FUNCTION = 472,
        KW_GENERATED = 473,
        KW_GRANT = 474,
        KW_GROUP_ROWS = 475,
        KW_HIDDEN = 476,
        KW_IDENTITY = 477,
        KW_IMMEDIATE = 478,
        KW_IMMUTABLE = 479,
        KW_IMPORT = 480,
        KW_INCLUDE = 481,
        KW_INCREMENT = 482,
        KW_INDEX = 483,
        KW_INOUT = 484,
        KW_INPUT = 485,
        KW_INSERT = 486,
        KW_INVOKER = 487,
        KW_ITERATE = 488,
        KW_ISOLATION = 489,
        KW_JSON = 490,
        KW_KEY = 491,
        KW_LANGUAGE = 492,
        KW_LAST = 493,
        KW_LEAVE = 494,
        KW_LEVEL = 495,
        KW_LOAD = 496,
        KW_LOOP = 497,
        KW_MACRO = 498,
        KW_MAP = 499,
        KW_MATCH = 500,
        KW_MATCHED = 501,
        KW_MATERIALIZED = 502,
        KW_MAX = 503,
        KW_MAXVALUE = 504,
        KW_MESSAGE = 505,
        KW_METADATA = 506,
        KW_MIN = 507,
        KW_MINVALUE = 508,
        KW_MODEL = 509,
        KW_MODULE = 510,
        KW_NUMERIC = 511,
        KW_OFFSET = 512,
        KW_ONLY = 513,
        KW_OPTIONS = 514,
        KW_OUT = 515,
        KW_OUTPUT = 516,
        KW_OVERWRITE = 517,
        KW_PARTITIONS = 518,
        KW_PERCENT = 519,
        KW_PIVOT = 520,
        KW_POLICIES = 521,
        KW_POLICY = 522,
        KW_PRIMARY = 523,
        KW_PRIVATE = 524,
        KW_PRIVILEGE = 525,
        KW_PRIVILEGES = 526,
        KW_PROCEDURE = 527,
        KW_PROJECT = 528,
        KW_PUBLIC = 529,
        KW_QUALIFY_NONRESERVED = 530,
        KW_RAISE = 531,
        KW_READ = 532,
        KW_REFERENCES = 533,
        KW_REMOTE = 534,
        KW_REMOVE = 535,
        KW_RENAME = 536,
        KW_REPEAT = 537,
        KW_REPEATABLE = 538,
        KW_REPLACE = 539,
        KW_REPLACE_FIELDS = 540,
        KW_REPLICA = 541,
        KW_REPORT = 542,
        KW_RESTRICT = 543,
        KW_RESTRICTION = 544,
        KW_RETURN = 545,
        KW_RETURNS = 546,
        KW_REVOKE = 547,
        KW_ROLLBACK = 548,
        KW_ROW = 549,
        KW_RUN = 550,
        KW_SAFE_CAST = 551,
        KW_SCHEMA = 552,
        KW_SEARCH = 553,
        KW_SECURITY = 554,
        KW_SEQUENCE = 555,
        KW_SETS = 556,
        KW_SHOW = 557,
        KW_SIMPLE = 558,
        KW_SNAPSHOT = 559,
        KW_SOURCE = 560,
        KW_SQL = 561,
        KW_STABLE = 562,
        KW_START = 563,
        KW_STORED = 564,
        KW_STORING = 565,
        KW_SYSTEM = 566,
        KW_SYSTEM_TIME = 567,
        KW_TABLE = 568,
        KW_TABLES = 569,
        KW_TARGET = 570,
        KW_TRANSFORM = 571,
        KW_TEMP = 572,
        KW_TEMPORARY = 573,
        KW_TIME = 574,
        KW_TIMESTAMP = 575,
        KW_TRANSACTION = 576,
        KW_TRUNCATE = 577,
        KW_TYPE = 578,
        KW_UNDROP = 579,
        KW_UNIQUE = 580,
        KW_UNKNOWN = 581,
        KW_UNPIVOT = 582,
        KW_UNTIL = 583,
        KW_UPDATE = 584,
        KW_VALUE = 585,
        KW_VALUES = 586,
        KW_VECTOR = 587,
        KW_VOLATILE = 588,
        KW_VIEW = 589,
        KW_VIEWS = 590,
        KW_WEIGHT = 591,
        KW_WHILE = 592,
        KW_WRITE = 593,
        KW_ZONE = 594,
        KW_EXCEPTION = 595,
        KW_ERROR = 596,
        KW_CORRESPONDING = 597,
        KW_STRICT = 598,
        KW_INTERLEAVE = 599,
        KW_NULL_FILTERED = 600,
        KW_PARENT = 601,
        SENTINEL_NONRESERVED_KW_END = 602,
        KW_CURRENT_DATETIME_FUNCTION = 603,
        MACRO_BODY_TOKEN = 604,
        MODE_STATEMENT = 605,
        MODE_SCRIPT = 606,
        MODE_NEXT_STATEMENT = 607,
        MODE_NEXT_SCRIPT_STATEMENT = 608,
        MODE_NEXT_STATEMENT_KIND = 609,
        MODE_EXPRESSION = 610,
        MODE_TYPE = 611
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned short token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);
      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    YY_MOVE_REF (location_type) l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    YY_RVREF (semantic_type) v,
                    YY_RVREF (location_type) l);

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {};

    /// Build a parser object.
    BisonParserImpl (zetasql::parser::DisambiguatorLexer* tokenizer_yyarg, zetasql::parser::BisonParser* parser_yyarg, zetasql::ASTNode** ast_node_result_yyarg, zetasql::parser::ASTStatementProperties*
                  ast_statement_properties_yyarg, std::string* error_message_yyarg, zetasql::ParseLocationPoint* error_location_yyarg, int* statement_end_byte_offset_yyarg);
    virtual ~BisonParserImpl ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);



  private:
    /// This class is not copyable.
    BisonParserImpl (const BisonParserImpl&);
    BisonParserImpl& operator= (const BisonParserImpl&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned short yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned short yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned short yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 38406,     ///< Last index in yytable_.
      yynnts_ = 642,  ///< Number of nonterminal symbols.
      yyfinal_ = 507, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 381  ///< Number of tokens.
    };


    // User arguments.
    zetasql::parser::DisambiguatorLexer* tokenizer;
    zetasql::parser::BisonParser* parser;
    zetasql::ASTNode** ast_node_result;
    zetasql::parser::ASTStatementProperties*
                  ast_statement_properties;
    std::string* error_message;
    zetasql::ParseLocationPoint* error_location;
    int* statement_end_byte_offset;
  };



} // zetasql_bison_parser
#line 1222 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401




#endif // !YY_ZETASQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
