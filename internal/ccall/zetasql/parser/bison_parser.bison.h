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

#include "zetasql/parser/location.hh"
#include "zetasql/parser/bison_parser.h"
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/join_processor.h"
#include "zetasql/parser/statement_properties.h"
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

// Shorthand to call parser->CreateASTNode<>(). The "node_type" must be a
// AST... class from the zetasql namespace. The "..." are the arguments to
// BisonParser::CreateASTNode<>().
#define MAKE_NODE(node_type, ...) \
    parser->CreateASTNode<zetasql::node_type>(__VA_ARGS__);

enum class NotKeywordPresence {
  kPresent,
  kAbsent
};

enum class AllOrDistinctKeyword {
  kAll,
  kDistinct,
  kNone,
};

enum class PrecedingOrFollowingKeyword {
  kPreceding,
  kFollowing
};

enum class ShiftOperator {
  kLeft,
  kRight
};

enum class TableOrTableFunctionKeywords {
  kTableKeyword,
  kTableAndFunctionKeywords
};

enum class ImportType {
  kModule,
  kProto,
};

// This node is used for temporarily aggregating together components of an
// identifier that are separated by various characters, such as slash ("/"),
// dash ("-"), and colon (":") to enable supporting table paths of the form:
// /span/nonprod-test:db.Table without any escaping.  This node exists
// temporarily to hold intermediate values, and will not be part of the final
// parse tree.
class SeparatedIdentifierTmpNode final : public zetasql::ASTNode {
 public:
  static constexpr zetasql::ASTNodeKind kConcreteNodeKind =
      zetasql::AST_FAKE;

  SeparatedIdentifierTmpNode() : ASTNode(kConcreteNodeKind) {}
  void Accept(zetasql::ParseTreeVisitor* visitor, void* data) const override {
    ZETASQL_LOG(FATAL) << "SeparatedIdentifierTmpNode does not support Accept";
  }
  absl::StatusOr<zetasql::VisitResult> Accept(
      zetasql::NonRecursiveParseTreeVisitor* visitor) const override {
    ZETASQL_LOG(FATAL) << "SeparatedIdentifierTmpNode does not support Accept";
  }
  // This is used to represent an unquoted full identifier path that may contain
  // slashes ("/"), dashes ('-'), and colons (":"). This requires special
  // handling because of the ambiguity in the lexer between an identifier and a
  // number. For example:
  // /span/nonprod-5:db-3.Table
  // The lexer takes this to be
  // /,span,/,nonprod,-,5,:,db,-,3.,Table
  // Where tokens like 3. are treated as a FLOATING_POINT_LITERAL, so the
  // natural path separator "." is lost. For more information on this, see the
  // 'slashed_identifier' rule.

  // We represent this as a list of one or more 'PathParts' which are
  // implicitly separated by a dot ('.'). Each may be composed of one or more
  // 'IdParts' which is a list of the tokens that compose a single component of
  // the path (a single identifier) including any slashes, dashes, and/or
  // colons.
  // Thus, the example string above would be represented as the following:
  // {{"/", "span", "/", "nonprod", "-", "5", ":", "db", "-", "3"}, {"Table"}}

  // In order to save memory, these all contain string_view entries (backed by
  // the parser's copy of the input sql).
  // This also uses inlined vectors, because we rarely expect more than a few
  // entries at either level.
  // Note, in the event the size is large, this will allocate directly to the
  // heap, rather than into the arena.
  using IdParts = std::vector<absl::string_view>;
  using PathParts = std::vector<IdParts>;

  void set_path_parts(PathParts path_parts) {
    path_parts_ = std::move(path_parts);
  }

  PathParts&& release_path_parts() {
    return std::move(path_parts_);
  }
  absl::Status InitFields() final {
    {
      FieldLoader fl(this);  // Triggers check that there were no children.
      return fl.Finalize();
    }
  }

  // Returns a vector of identifier ASTNodes from `raw_parts`.
  // `raw_parts` represents a path as a list of lists. Each sublist contains the
  // raw components of an identifier. To form an ASTPathExpression, we
  // concatenate the components of each sublist together to form a single
  // identifier and return a list of these identifiers, which can be used to
  // build an ASTPathExpression.
  static absl::StatusOr<std::vector<zetasql::ASTNode*>> BuildPathParts(
    const zetasql_bison_parser::location& bison_location,
    PathParts raw_parts, zetasql::parser::BisonParser* parser) {
    if(raw_parts.empty()) {
      return absl::InvalidArgumentError(
        "Internal error: Empty slashed path expression");
    }
    std::vector<zetasql::ASTNode*> parts;
    for (int i = 0; i < raw_parts.size(); ++i) {
      SeparatedIdentifierTmpNode::IdParts& raw_id_parts = raw_parts[i];
      if (raw_id_parts.empty()) {
        return absl::InvalidArgumentError(
          "Internal error: Empty dashed identifier part");
      }
      // Trim trailing "." which is leftover from lexing float literals
      // like a/1.b -> {"a", "/", "1.", "b"}
      for (int j = 0; j < raw_id_parts.size(); ++j) {
        absl::string_view& dash_part = raw_id_parts[j];
        if (absl::EndsWith(dash_part, ".")) {
          dash_part.remove_suffix(1);
        }
      }
      parts.push_back(parser->MakeIdentifier(bison_location,
                                             absl::StrJoin(raw_id_parts, "")));
    }
    return parts;
  }

 private:
  PathParts path_parts_;
};


#line 214 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401


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


namespace zetasql_bison_parser {
#line 325 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401



  /// A Bison parser.
  class BisonParserImpl
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 405 "zetasql/parser/bison_parser.y" // lalr1.cc:401

  bool boolean;
  int64_t int64_val;
  zetasql::TypeKind type_kind;
  zetasql::ASTFunctionCall::NullHandlingModifier null_handling_modifier;
  zetasql::ASTWindowFrame::FrameUnit frame_unit;
  zetasql::ASTTemplatedParameterType::TemplatedTypeKind
      templated_parameter_kind;
  zetasql::ASTBinaryExpression::Op binary_op;
  zetasql::ASTUnaryExpression::Op unary_op;
  zetasql::ASTJoin::JoinType join_type;
  zetasql::ASTJoin::JoinHint join_hint;
  zetasql::ASTSampleSize::Unit sample_size_unit;
  zetasql::ASTInsertStatement::InsertMode insert_mode;
  zetasql::ASTNodeKind ast_node_kind;
  zetasql::ASTUnpivotClause::NullFilter opt_unpivot_nulls_filter;
  NotKeywordPresence not_keyword_presence;
  AllOrDistinctKeyword all_or_distinct_keyword;
  zetasql::SchemaObjectKind schema_object_kind_keyword;
  PrecedingOrFollowingKeyword preceding_or_following_keyword;
  TableOrTableFunctionKeywords table_or_table_function_keywords;
  ShiftOperator shift_operator;
  ImportType import_type;
  zetasql::ASTAuxLoadDataStatement::InsertionMode insertion_mode;
  zetasql::ASTCreateStatement::Scope create_scope;
  zetasql::ASTCreateStatement::SqlSecurity sql_security;
  zetasql::ASTDropStatement::DropMode drop_mode;
  zetasql::ASTForeignKeyReference::Match foreign_key_match;
  zetasql::ASTForeignKeyActions::Action foreign_key_action;
  zetasql::ASTFunctionParameter::ProcedureParameterMode parameter_mode;
  zetasql::ASTCreateFunctionStmtBase::DeterminismLevel determinism_level;
  zetasql::ASTGeneratedColumnInfo::StoredMode stored_mode;
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
  SeparatedIdentifierTmpNode* slashed_identifier;
  zetasql::ASTPivotClause* pivot_clause;
  zetasql::ASTUnpivotClause* unpivot_clause;
  zetasql::ASTSetOperationType* set_operation_type;
  zetasql::ASTSetOperationAllOrDistinct* set_operation_all_or_distinct;
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

#line 433 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401
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
        KW_EXCEPT_IN_SET_OP = 310,
        KW_EXCEPT = 311,
        KW_EXISTS = 312,
        KW_EXTRACT = 313,
        KW_FALSE = 314,
        KW_FOLLOWING = 315,
        KW_FROM = 316,
        KW_FULL = 317,
        KW_FULL_IN_SET_OP = 318,
        KW_GROUP = 319,
        KW_GROUPING = 320,
        KW_HASH = 321,
        KW_HAVING = 322,
        KW_IF = 323,
        KW_IGNORE = 324,
        KW_IN = 325,
        KW_INNER = 326,
        KW_INTERSECT = 327,
        KW_INTERVAL = 328,
        KW_INTO = 329,
        KW_IS = 330,
        KW_JOIN = 331,
        KW_LEFT = 332,
        KW_LEFT_IN_SET_OP = 333,
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
        KW_WITH_STARTING_WITH_EXPRESSION = 372,
        KW_UNNEST = 373,
        KW_CONTAINS = 374,
        KW_CUBE = 375,
        KW_ESCAPE = 376,
        KW_EXCLUDE = 377,
        KW_FETCH = 378,
        KW_FOR = 379,
        KW_GROUPS = 380,
        KW_LATERAL = 381,
        KW_OF = 382,
        KW_SOME = 383,
        KW_TREAT = 384,
        KW_WITHIN = 385,
        KW_QUALIFY_RESERVED = 386,
        SENTINEL_RESERVED_KW_END = 387,
        KW_NOT_SPECIAL = 388,
        SENTINEL_NONRESERVED_KW_START = 389,
        KW_ABORT = 390,
        KW_ACCESS = 391,
        KW_ACTION = 392,
        KW_ADD = 393,
        KW_AGGREGATE = 394,
        KW_ALTER = 395,
        KW_ANONYMIZATION = 396,
        KW_ANALYZE = 397,
        KW_APPROX = 398,
        KW_ARE = 399,
        KW_ASSERT = 400,
        KW_BATCH = 401,
        KW_BEGIN = 402,
        KW_BIGDECIMAL = 403,
        KW_BIGNUMERIC = 404,
        KW_BREAK = 405,
        KW_CALL = 406,
        KW_CASCADE = 407,
        KW_CHECK = 408,
        KW_CLAMPED = 409,
        KW_CLONE = 410,
        KW_COPY = 411,
        KW_CLUSTER = 412,
        KW_COLUMN = 413,
        KW_COLUMNS = 414,
        KW_COMMIT = 415,
        KW_CONNECTION = 416,
        KW_CONTINUE = 417,
        KW_CONSTANT = 418,
        KW_CONSTRAINT = 419,
        KW_DATA = 420,
        KW_DATABASE = 421,
        KW_DATE = 422,
        KW_DATETIME = 423,
        KW_DECIMAL = 424,
        KW_DECLARE = 425,
        KW_DEFINER = 426,
        KW_DELETE = 427,
        KW_DELETION = 428,
        KW_DESCRIBE = 429,
        KW_DESCRIPTOR = 430,
        KW_DETERMINISTIC = 431,
        KW_DO = 432,
        KW_DROP = 433,
        KW_ENFORCED = 434,
        KW_ELSEIF = 435,
        KW_EXECUTE = 436,
        KW_EXPLAIN = 437,
        KW_EXPORT = 438,
        KW_EXTERNAL = 439,
        KW_FILES = 440,
        KW_FILTER = 441,
        KW_FILTER_FIELDS = 442,
        KW_FILL = 443,
        KW_FIRST = 444,
        KW_FOREIGN = 445,
        KW_FORMAT = 446,
        KW_FUNCTION = 447,
        KW_GENERATED = 448,
        KW_GRANT = 449,
        KW_GROUP_ROWS = 450,
        KW_HIDDEN = 451,
        KW_IMMEDIATE = 452,
        KW_IMMUTABLE = 453,
        KW_IMPORT = 454,
        KW_INCLUDE = 455,
        KW_INDEX = 456,
        KW_INOUT = 457,
        KW_INPUT = 458,
        KW_INSERT = 459,
        KW_INVOKER = 460,
        KW_ITERATE = 461,
        KW_ISOLATION = 462,
        KW_JSON = 463,
        KW_KEY = 464,
        KW_LANGUAGE = 465,
        KW_LAST = 466,
        KW_LEAVE = 467,
        KW_LEVEL = 468,
        KW_LOAD = 469,
        KW_LOOP = 470,
        KW_MACRO = 471,
        KW_MATCH = 472,
        KW_MATCHED = 473,
        KW_MATERIALIZED = 474,
        KW_MAX = 475,
        KW_MESSAGE = 476,
        KW_MIN = 477,
        KW_MODEL = 478,
        KW_MODULE = 479,
        KW_NUMERIC = 480,
        KW_OFFSET = 481,
        KW_ONLY = 482,
        KW_OPTIONS = 483,
        KW_OUT = 484,
        KW_OUTPUT = 485,
        KW_OVERWRITE = 486,
        KW_PARTITIONS = 487,
        KW_PERCENT = 488,
        KW_PIVOT = 489,
        KW_POLICIES = 490,
        KW_POLICY = 491,
        KW_PRIMARY = 492,
        KW_PRIVATE = 493,
        KW_PRIVILEGE = 494,
        KW_PRIVILEGES = 495,
        KW_PROCEDURE = 496,
        KW_PUBLIC = 497,
        KW_QUALIFY_NONRESERVED = 498,
        KW_RAISE = 499,
        KW_READ = 500,
        KW_REFERENCES = 501,
        KW_REMOTE = 502,
        KW_REMOVE = 503,
        KW_RENAME = 504,
        KW_REPEAT = 505,
        KW_REPEATABLE = 506,
        KW_REPLACE = 507,
        KW_REPLACE_FIELDS = 508,
        KW_REPLICA = 509,
        KW_REPORT = 510,
        KW_RESTRICT = 511,
        KW_RESTRICTION = 512,
        KW_RETURN = 513,
        KW_RETURNS = 514,
        KW_REVOKE = 515,
        KW_ROLLBACK = 516,
        KW_ROW = 517,
        KW_RUN = 518,
        KW_SAFE_CAST = 519,
        KW_SCHEMA = 520,
        KW_SEARCH = 521,
        KW_SECURITY = 522,
        KW_SEQUENCE = 523,
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
        KW_VOLATILE = 554,
        KW_VIEW = 555,
        KW_VIEWS = 556,
        KW_WEIGHT = 557,
        KW_WHILE = 558,
        KW_WRITE = 559,
        KW_ZONE = 560,
        KW_EXCEPTION = 561,
        KW_ERROR = 562,
        KW_CORRESPONDING = 563,
        KW_STRICT = 564,
        KW_INTERLEAVE = 565,
        KW_NULL_FILTERED = 566,
        KW_PARENT = 567,
        SENTINEL_NONRESERVED_KW_END = 568,
        KW_CURRENT_DATETIME_FUNCTION = 569,
        MACRO_BODY_TOKEN = 570,
        MODE_STATEMENT = 571,
        MODE_SCRIPT = 572,
        MODE_NEXT_STATEMENT = 573,
        MODE_NEXT_SCRIPT_STATEMENT = 574,
        MODE_NEXT_STATEMENT_KIND = 575,
        MODE_EXPRESSION = 576,
        MODE_TYPE = 577
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
    BisonParserImpl (zetasql::parser::ZetaSqlFlexTokenizer* tokenizer_yyarg, zetasql::parser::BisonParser* parser_yyarg, zetasql::ASTNode** ast_node_result_yyarg, zetasql::parser::ASTStatementProperties*
                  ast_statement_properties_yyarg, std::string* error_message_yyarg, zetasql::ParseLocationPoint* error_location_yyarg, bool* move_error_location_past_whitespace_yyarg, int* statement_end_byte_offset_yyarg);
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
      yylast_ = 33476,     ///< Last index in yytable_.
      yynnts_ = 581,  ///< Number of nonterminal symbols.
      yyfinal_ = 461, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 346  ///< Number of tokens.
    };


    // User arguments.
    zetasql::parser::ZetaSqlFlexTokenizer* tokenizer;
    zetasql::parser::BisonParser* parser;
    zetasql::ASTNode** ast_node_result;
    zetasql::parser::ASTStatementProperties*
                  ast_statement_properties;
    std::string* error_message;
    zetasql::ParseLocationPoint* error_location;
    bool* move_error_location_past_whitespace;
    int* statement_end_byte_offset;
  };



} // zetasql_bison_parser
#line 1273 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h" // lalr1.cc:401




#endif // !YY_ZETASQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
