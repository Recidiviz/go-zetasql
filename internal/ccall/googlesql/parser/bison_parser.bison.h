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
 ** \file bazel-out/k8-fastbuild/bin/googlesql/parser/bison_parser.bison.h
 ** Define the googlesql_bison_parser::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_GOOGLESQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
# define YY_GOOGLESQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
// //                    "%code requires" blocks.
#line 17 "googlesql/parser/bison_parser.y" // lalr1.cc:401

// Bison parser for ZetaSQL. This works in conjunction with
// googlesql::parser::BisonParser.
//
// To debug the state machine in case of conflicts, run (locally):
// $ bison bison_parser.y -Wprecedence -Wcounterexamples -b tmp_prefix -r all \
//     --report-file=$HOME/bison_report.txt
// (Do NOT set the --report-file to a path on citc, because then the file will
// be truncated at 1MB for some reason.)

#include "googlesql/parser/location.hh"
#include "googlesql/parser/bison_parser.h"
#include "googlesql/parser/join_processor.h"
#include "googlesql/parser/parse_tree.h"
#include "googlesql/parser/parser_internal.h"
#include "googlesql/parser/statement_properties.h"
#include "googlesql/public/strings.h"
#include "googlesql/base/case.h"
#include "absl/memory/memory.h"
#include "absl/strings/match.h"
#include "absl/strings/str_join.h"
#include "absl/strings/str_format.h"
#include "absl/status/status.h"

#define YYINITDEPTH 50
#ifndef YYDEBUG
#define YYDEBUG 0
#endif


#line 79 "bazel-out/k8-fastbuild/bin/googlesql/parser/bison_parser.bison.h" // lalr1.cc:401


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
# include "location.hh"


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


namespace googlesql_bison_parser {
#line 190 "bazel-out/k8-fastbuild/bin/googlesql/parser/bison_parser.bison.h" // lalr1.cc:401



  /// A Bison parser.
  class BisonParserImpl
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 262 "googlesql/parser/bison_parser.y" // lalr1.cc:401

  bool boolean;
  int64_t int64_val;
  googlesql::TypeKind type_kind;
  googlesql::ASTFunctionCall::NullHandlingModifier null_handling_modifier;
  googlesql::ASTWindowFrame::FrameUnit frame_unit;
  googlesql::ASTTemplatedParameterType::TemplatedTypeKind
      templated_parameter_kind;
  googlesql::ASTBinaryExpression::Op binary_op;
  googlesql::ASTUnaryExpression::Op unary_op;
  googlesql::ASTJoin::JoinType join_type;
  googlesql::ASTJoin::JoinHint join_hint;
  googlesql::ASTSampleSize::Unit sample_size_unit;
  googlesql::ASTInsertStatement::InsertMode insert_mode;
  googlesql::ASTNodeKind ast_node_kind;
  googlesql::ASTUnpivotClause::NullFilter opt_unpivot_nulls_filter;
  googlesql::parser_internal::NotKeywordPresence not_keyword_presence;
  googlesql::parser_internal::AllOrDistinctKeyword all_or_distinct_keyword;
  googlesql::SchemaObjectKind schema_object_kind_keyword;
  googlesql::parser_internal::PrecedingOrFollowingKeyword
      preceding_or_following_keyword;
  googlesql::parser_internal::TableOrTableFunctionKeywords
      table_or_table_function_keywords;
  googlesql::parser_internal::IndexTypeKeywords
      index_type_keywords;
  googlesql::parser_internal::ShiftOperator shift_operator;
  googlesql::parser_internal::ImportType import_type;
  googlesql::ASTAuxLoadDataStatement::InsertionMode insertion_mode;
  googlesql::ASTCreateStatement::Scope create_scope;
  googlesql::ASTCreateStatement::SqlSecurity sql_security;
  googlesql::ASTCreateStatement::SqlSecurity external_security;
  googlesql::ASTDropStatement::DropMode drop_mode;
  googlesql::ASTForeignKeyReference::Match foreign_key_match;
  googlesql::ASTForeignKeyActions::Action foreign_key_action;
  googlesql::ASTFunctionParameter::ProcedureParameterMode parameter_mode;
  googlesql::ASTCreateFunctionStmtBase::DeterminismLevel determinism_level;
  googlesql::ASTGeneratedColumnInfo::StoredMode stored_mode;
  googlesql::ASTOrderingExpression::OrderingSpec ordering_spec;
  googlesql::ASTSelectWith* select_with;
  googlesql::ASTSetOperationColumnMatchMode* column_match_mode;
  googlesql::ASTSetOperationColumnPropagationMode* column_propagation_mode;

  // Not owned. The allocated nodes are all owned by the parser.
  // Nodes should use the most specific type available.
  googlesql::ASTForeignKeyReference* foreign_key_reference;
  googlesql::ASTSetOperation* query_set_operation;
  googlesql::ASTInsertValuesRowList* insert_values_row_list;
  googlesql::ASTQuery* query;
  googlesql::ASTExpression* expression;
  googlesql::ASTExpressionSubquery* expression_subquery;
  googlesql::ASTFunctionCall* function_call;
  googlesql::ASTAlias* alias;
  googlesql::ASTIdentifier* identifier;
  googlesql::ASTInsertStatement* insert_statement;
  googlesql::ASTNode* node;
  googlesql::ASTStatementList* statement_list;
  googlesql::parser_internal::SeparatedIdentifierTmpNode* slashed_identifier;
  googlesql::ASTPivotClause* pivot_clause;
  googlesql::ASTUnpivotClause* unpivot_clause;
  googlesql::ASTSetOperationType* set_operation_type;
  googlesql::ASTSetOperationAllOrDistinct* set_operation_all_or_distinct;
  struct {
    googlesql::ASTPivotClause* pivot_clause;
    googlesql::ASTUnpivotClause* unpivot_clause;
    googlesql::ASTAlias* alias;
  } pivot_or_unpivot_clause_and_alias;
  struct {
    googlesql::ASTNode* where;
    googlesql::ASTNode* group_by;
    googlesql::ASTNode* having;
    googlesql::ASTNode* qualify;
    googlesql::ASTNode* window;
  } clauses_following_from;
  struct {
    googlesql::ASTExpression* default_expression;
    googlesql::ASTGeneratedColumnInfo* generated_column_info;
  } generated_or_default_column_info;
  struct {
    googlesql::ASTWithPartitionColumnsClause* with_partition_columns_clause;
    googlesql::ASTWithConnectionClause* with_connection_clause;
  } external_table_with_clauses;
  struct {
    googlesql::ASTIdentifier* language;
    bool is_remote;
    googlesql::ASTWithConnectionClause* with_connection_clause;
  } language_or_remote_with_connection;
  struct {
    googlesql::ASTScript* body;
    googlesql::ASTIdentifier* language;
    googlesql::ASTNode* code;
  } begin_end_block_or_language_as_code;
  struct {
    googlesql::ASTExpression* maybe_dashed_path_expression;
    bool is_temp_table;
  } path_expression_with_scope;
  struct {
    googlesql::ASTSetOperationColumnMatchMode* column_match_mode;
    googlesql::ASTColumnList* column_list;
  } column_match_suffix;
  struct {
    googlesql::ASTQuery* query;
    googlesql::ASTPathExpression* replica_source;
  } query_or_replica_source_info;

#line 307 "bazel-out/k8-fastbuild/bin/googlesql/parser/bison_parser.bison.h" // lalr1.cc:401
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

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
        LABEL = 266,
        COMMENT = 267,
        KW_NOT_EQUALS_C_STYLE = 268,
        KW_NOT_EQUALS_SQL_STYLE = 269,
        KW_LESS_EQUALS = 270,
        KW_GREATER_EQUALS = 271,
        KW_DOUBLE_AT = 272,
        KW_CONCAT_OP = 273,
        KW_DOT_STAR = 274,
        KW_OPEN_HINT = 275,
        KW_OPEN_INTEGER_HINT = 276,
        KW_SHIFT_LEFT = 277,
        KW_SHIFT_RIGHT = 278,
        KW_NAMED_ARGUMENT_ASSIGNMENT = 279,
        KW_LAMBDA_ARROW = 280,
        UNARY_NOT_PRECEDENCE = 281,
        UNARY_PRECEDENCE = 282,
        DOUBLE_AT_PRECEDENCE = 283,
        PRIMARY_PRECEDENCE = 284,
        SENTINEL_RESERVED_KW_START = 285,
        KW_ALL = 286,
        KW_AND = 287,
        KW_AND_FOR_BETWEEN = 288,
        KW_ANY = 289,
        KW_ARRAY = 290,
        KW_AS = 291,
        KW_ASC = 292,
        KW_ASSERT_ROWS_MODIFIED = 293,
        KW_AT = 294,
        KW_BETWEEN = 295,
        KW_BY = 296,
        KW_CASE = 297,
        KW_CAST = 298,
        KW_COLLATE = 299,
        KW_CREATE = 300,
        KW_CROSS = 301,
        KW_CURRENT = 302,
        KW_DEFAULT = 303,
        KW_DEFINE = 304,
        KW_DESC = 305,
        KW_DISTINCT = 306,
        KW_ELSE = 307,
        KW_END = 308,
        KW_ENUM = 309,
        KW_EXCEPT = 310,
        KW_EXISTS = 311,
        KW_EXTRACT = 312,
        KW_FALSE = 313,
        KW_FOLLOWING = 314,
        KW_FROM = 315,
        KW_FULL = 316,
        KW_FULL_IN_SET_OP = 317,
        KW_GROUP = 318,
        KW_GROUPING = 319,
        KW_HASH = 320,
        KW_HAVING = 321,
        KW_IF = 322,
        KW_IGNORE = 323,
        KW_IN = 324,
        KW_INNER = 325,
        KW_INTERSECT = 326,
        KW_INTERVAL = 327,
        KW_INTO = 328,
        KW_IS = 329,
        KW_JOIN = 330,
        KW_LEFT = 331,
        KW_LEFT_IN_SET_OP = 332,
        KW_LIKE = 333,
        KW_LIMIT = 334,
        KW_LOOKUP = 335,
        KW_MERGE = 336,
        KW_NATURAL = 337,
        KW_NEW = 338,
        KW_NO = 339,
        KW_NOT = 340,
        KW_NULL = 341,
        KW_NULLS = 342,
        KW_ON = 343,
        KW_OR = 344,
        KW_ORDER = 345,
        KW_OUTER = 346,
        KW_OVER = 347,
        KW_PARTITION = 348,
        KW_PRECEDING = 349,
        KW_PROTO = 350,
        KW_RANGE = 351,
        KW_RECURSIVE = 352,
        KW_RESPECT = 353,
        KW_RIGHT = 354,
        KW_ROLLUP = 355,
        KW_ROWS = 356,
        KW_SELECT = 357,
        KW_SET = 358,
        KW_STRUCT = 359,
        KW_TABLESAMPLE = 360,
        KW_THEN = 361,
        KW_TO = 362,
        KW_TRUE = 363,
        KW_UNBOUNDED = 364,
        KW_UNION = 365,
        KW_USING = 366,
        KW_WHEN = 367,
        KW_WHERE = 368,
        KW_WINDOW = 369,
        KW_WITH = 370,
        KW_UNNEST = 371,
        KW_CONTAINS = 372,
        KW_CUBE = 373,
        KW_ESCAPE = 374,
        KW_EXCLUDE = 375,
        KW_FETCH = 376,
        KW_FOR = 377,
        KW_GROUPS = 378,
        KW_LATERAL = 379,
        KW_OF = 380,
        KW_SOME = 381,
        KW_TREAT = 382,
        KW_WITHIN = 383,
        KW_QUALIFY_RESERVED = 384,
        SENTINEL_RESERVED_KW_END = 385,
        KW_WITH_STARTING_WITH_EXPRESSION = 386,
        KW_EXCEPT_IN_SET_OP = 387,
        KW_NOT_SPECIAL = 388,
        SENTINEL_NONRESERVED_KW_START = 389,
        KW_ABORT = 390,
        KW_ACCESS = 391,
        KW_ACTION = 392,
        KW_ADD = 393,
        KW_AGGREGATE = 394,
        KW_ALTER = 395,
        KW_ANALYZE = 396,
        KW_APPROX = 397,
        KW_ARE = 398,
        KW_ASSERT = 399,
        KW_BATCH = 400,
        KW_BEGIN = 401,
        KW_BIGDECIMAL = 402,
        KW_BIGNUMERIC = 403,
        KW_BREAK = 404,
        KW_CALL = 405,
        KW_CASCADE = 406,
        KW_CHECK = 407,
        KW_CLAMPED = 408,
        KW_CLONE = 409,
        KW_COPY = 410,
        KW_CLUSTER = 411,
        KW_COLUMN = 412,
        KW_COLUMNS = 413,
        KW_COMMIT = 414,
        KW_CONNECTION = 415,
        KW_CONTINUE = 416,
        KW_CONSTANT = 417,
        KW_CONSTRAINT = 418,
        KW_DATA = 419,
        KW_DATABASE = 420,
        KW_DATE = 421,
        KW_DATETIME = 422,
        KW_DECIMAL = 423,
        KW_DECLARE = 424,
        KW_DEFINER = 425,
        KW_DELETE = 426,
        KW_DELETION = 427,
        KW_DESCRIBE = 428,
        KW_DESCRIPTOR = 429,
        KW_DETERMINISTIC = 430,
        KW_DO = 431,
        KW_DROP = 432,
        KW_ENFORCED = 433,
        KW_ELSEIF = 434,
        KW_EXECUTE = 435,
        KW_EXPLAIN = 436,
        KW_EXPORT = 437,
        KW_EXTERNAL = 438,
        KW_FILES = 439,
        KW_FILTER = 440,
        KW_FILL = 441,
        KW_FIRST = 442,
        KW_FOREIGN = 443,
        KW_FORMAT = 444,
        KW_FUNCTION = 445,
        KW_GENERATED = 446,
        KW_GRANT = 447,
        KW_GROUP_ROWS = 448,
        KW_HIDDEN = 449,
        KW_IMMEDIATE = 450,
        KW_IMMUTABLE = 451,
        KW_IMPORT = 452,
        KW_INCLUDE = 453,
        KW_INDEX = 454,
        KW_INOUT = 455,
        KW_INPUT = 456,
        KW_INSERT = 457,
        KW_INVOKER = 458,
        KW_ITERATE = 459,
        KW_ISOLATION = 460,
        KW_JSON = 461,
        KW_KEY = 462,
        KW_LANGUAGE = 463,
        KW_LAST = 464,
        KW_LEAVE = 465,
        KW_LEVEL = 466,
        KW_LOAD = 467,
        KW_LOOP = 468,
        KW_MACRO = 469,
        KW_MATCH = 470,
        KW_MATCHED = 471,
        KW_MATERIALIZED = 472,
        KW_MAX = 473,
        KW_MESSAGE = 474,
        KW_METADATA = 475,
        KW_MIN = 476,
        KW_MODEL = 477,
        KW_MODULE = 478,
        KW_NUMERIC = 479,
        KW_OFFSET = 480,
        KW_ONLY = 481,
        KW_OPTIONS = 482,
        KW_OUT = 483,
        KW_OUTPUT = 484,
        KW_OVERWRITE = 485,
        KW_PARTITIONS = 486,
        KW_PERCENT = 487,
        KW_PIVOT = 488,
        KW_POLICIES = 489,
        KW_POLICY = 490,
        KW_PRIMARY = 491,
        KW_PRIVATE = 492,
        KW_PRIVILEGE = 493,
        KW_PRIVILEGES = 494,
        KW_PROCEDURE = 495,
        KW_PUBLIC = 496,
        KW_QUALIFY_NONRESERVED = 497,
        KW_RAISE = 498,
        KW_READ = 499,
        KW_REFERENCES = 500,
        KW_REMOTE = 501,
        KW_REMOVE = 502,
        KW_RENAME = 503,
        KW_REPEAT = 504,
        KW_REPEATABLE = 505,
        KW_REPLACE = 506,
        KW_REPLACE_FIELDS = 507,
        KW_REPLICA = 508,
        KW_REPORT = 509,
        KW_RESTRICT = 510,
        KW_RESTRICTION = 511,
        KW_RETURN = 512,
        KW_RETURNS = 513,
        KW_REVOKE = 514,
        KW_ROLLBACK = 515,
        KW_ROW = 516,
        KW_RUN = 517,
        KW_SAFE_CAST = 518,
        KW_SCHEMA = 519,
        KW_SEARCH = 520,
        KW_SECURITY = 521,
        KW_SEQUENCE = 522,
        KW_SETS = 523,
        KW_SHOW = 524,
        KW_SIMPLE = 525,
        KW_SNAPSHOT = 526,
        KW_SOURCE = 527,
        KW_SQL = 528,
        KW_STABLE = 529,
        KW_START = 530,
        KW_STORED = 531,
        KW_STORING = 532,
        KW_SYSTEM = 533,
        KW_SYSTEM_TIME = 534,
        KW_TABLE = 535,
        KW_TABLES = 536,
        KW_TARGET = 537,
        KW_TRANSFORM = 538,
        KW_TEMP = 539,
        KW_TEMPORARY = 540,
        KW_TIME = 541,
        KW_TIMESTAMP = 542,
        KW_TRANSACTION = 543,
        KW_TRUNCATE = 544,
        KW_TYPE = 545,
        KW_UNDROP = 546,
        KW_UNIQUE = 547,
        KW_UNKNOWN = 548,
        KW_UNPIVOT = 549,
        KW_UNTIL = 550,
        KW_UPDATE = 551,
        KW_VALUE = 552,
        KW_VALUES = 553,
        KW_VECTOR = 554,
        KW_VOLATILE = 555,
        KW_VIEW = 556,
        KW_VIEWS = 557,
        KW_WEIGHT = 558,
        KW_WHILE = 559,
        KW_WRITE = 560,
        KW_ZONE = 561,
        KW_EXCEPTION = 562,
        KW_ERROR = 563,
        KW_CORRESPONDING = 564,
        KW_STRICT = 565,
        KW_INTERLEAVE = 566,
        KW_NULL_FILTERED = 567,
        KW_PARENT = 568,
        SENTINEL_NONRESERVED_KW_END = 569,
        KW_CURRENT_DATETIME_FUNCTION = 570,
        MACRO_BODY_TOKEN = 571,
        MODE_STATEMENT = 572,
        MODE_SCRIPT = 573,
        MODE_NEXT_STATEMENT = 574,
        MODE_NEXT_SCRIPT_STATEMENT = 575,
        MODE_NEXT_STATEMENT_KIND = 576,
        MODE_EXPRESSION = 577,
        MODE_TYPE = 578
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
    BisonParserImpl (googlesql::parser::ZetaSqlFlexTokenizer* tokenizer_yyarg, googlesql::parser::BisonParser* parser_yyarg, googlesql::ASTNode** ast_node_result_yyarg, googlesql::parser::ASTStatementProperties*
                  ast_statement_properties_yyarg, std::string* error_message_yyarg, googlesql::ParseLocationPoint* error_location_yyarg, bool* move_error_location_past_whitespace_yyarg, int* statement_end_byte_offset_yyarg);
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
      yylast_ = 35560,     ///< Last index in yytable_.
      yynnts_ = 595,  ///< Number of nonterminal symbols.
      yyfinal_ = 465, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 347  ///< Number of tokens.
    };


    // User arguments.
    googlesql::parser::ZetaSqlFlexTokenizer* tokenizer;
    googlesql::parser::BisonParser* parser;
    googlesql::ASTNode** ast_node_result;
    googlesql::parser::ASTStatementProperties*
                  ast_statement_properties;
    std::string* error_message;
    googlesql::ParseLocationPoint* error_location;
    bool* move_error_location_past_whitespace;
    int* statement_end_byte_offset;
  };



} // googlesql_bison_parser
#line 1148 "bazel-out/k8-fastbuild/bin/googlesql/parser/bison_parser.bison.h" // lalr1.cc:401




#endif // !YY_GOOGLESQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
