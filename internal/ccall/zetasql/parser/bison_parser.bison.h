// A Bison parser, made by GNU Bison 3.6.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_ZETASQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
# define YY_ZETASQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
// "%code requires" blocks.
#line 17 "zetasql/parser/bison_parser.y"

// Bison parser for ZetaSQL. This works in conjunction with
// zetasql::parser::BisonParser.
//
// To debug the state machine in case of conflicts, run (locally):
// $ bison bison_parser.y -r all --report-file=$HOME/bison_report.txt
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


#line 211 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h"


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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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
#line 340 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h"




  /// A Bison parser.
  class BisonParserImpl
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
#line 481 "zetasql/parser/bison_parser.y"

  bool boolean;
  int64_t int64_val;
  zetasql::TypeKind type_kind;
  zetasql::ASTFunctionCall::NullHandlingModifier null_handling_modifier;
  zetasql::ASTWindowFrame::FrameUnit frame_unit;
  zetasql::ASTTemplatedParameterType::TemplatedTypeKind
      templated_parameter_kind;
  zetasql::ASTBinaryExpression::Op binary_op;
  zetasql::ASTUnaryExpression::Op unary_op;
  zetasql::ASTSetOperation::OperationType set_operation_type;
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

  // Not owned. The allocated nodes are all owned by the parser.
  // Nodes should use the most specific type available.
  zetasql::ASTForeignKeyReference* foreign_key_reference;
  zetasql::ASTSetOperation* query_set_operation;
  zetasql::ASTInsertValuesRowList* insert_values_row_list;
  zetasql::ASTQuery* query;
  zetasql::ASTExpression* expression;
  zetasql::ASTExpressionSubquery* expression_subquery;
  zetasql::ASTFunctionCall* function_call;
  zetasql::ASTIdentifier* identifier;
  zetasql::ASTInsertStatement* insert_statement;
  zetasql::ASTNode* node;
  zetasql::ASTStatementList* statement_list;
  SeparatedIdentifierTmpNode* slashed_identifier;
  zetasql::ASTPivotClause* pivot_clause;
  zetasql::ASTUnpivotClause* unpivot_clause;
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

#line 436 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h"

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

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of input"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    STRING_LITERAL = 258,          // "string literal"
    BYTES_LITERAL = 259,           // "bytes literal"
    INTEGER_LITERAL = 260,         // "integer literal"
    FLOATING_POINT_LITERAL = 261,  // "floating point literal"
    IDENTIFIER = 262,              // "identifier"
    LABEL = 263,                   // "label"
    COMMENT = 264,                 // "comment"
    KW_NOT_EQUALS_C_STYLE = 265,   // "!="
    KW_NOT_EQUALS_SQL_STYLE = 266, // "<>"
    KW_LESS_EQUALS = 267,          // "<="
    KW_GREATER_EQUALS = 268,       // ">="
    KW_DOUBLE_AT = 269,            // "@@"
    KW_CONCAT_OP = 270,            // "||"
    KW_DOT_STAR = 271,             // ".*"
    KW_OPEN_HINT = 272,            // "@{"
    KW_OPEN_INTEGER_HINT = 273,    // "@n"
    KW_SHIFT_LEFT = 274,           // "<<"
    KW_SHIFT_RIGHT = 275,          // ">>"
    KW_NAMED_ARGUMENT_ASSIGNMENT = 276, // "=>"
    KW_LAMBDA_ARROW = 277,         // "->"
    UNARY_NOT_PRECEDENCE = 278,    // UNARY_NOT_PRECEDENCE
    UNARY_PRECEDENCE = 279,        // UNARY_PRECEDENCE
    DOUBLE_AT_PRECEDENCE = 280,    // DOUBLE_AT_PRECEDENCE
    PRIMARY_PRECEDENCE = 281,      // PRIMARY_PRECEDENCE
    KW_ALL = 282,                  // "ALL"
    KW_AND = 283,                  // "AND"
    KW_AND_FOR_BETWEEN = 284,      // "AND for BETWEEN"
    KW_ANY = 285,                  // "ANY"
    KW_ARRAY = 286,                // "ARRAY"
    KW_AS = 287,                   // "AS"
    KW_ASC = 288,                  // "ASC"
    KW_ASSERT_ROWS_MODIFIED = 289, // "ASSERT_ROWS_MODIFIED"
    KW_AT = 290,                   // "AT"
    KW_BETWEEN = 291,              // "BETWEEN"
    KW_BY = 292,                   // "BY"
    KW_CASE = 293,                 // "CASE"
    KW_CAST = 294,                 // "CAST"
    KW_COLLATE = 295,              // "COLLATE"
    KW_CREATE = 296,               // "CREATE"
    KW_CROSS = 297,                // "CROSS"
    KW_CURRENT = 298,              // "CURRENT"
    KW_DEFAULT = 299,              // "DEFAULT"
    KW_DEFINE = 300,               // "DEFINE"
    KW_DESC = 301,                 // "DESC"
    KW_DISTINCT = 302,             // "DISTINCT"
    KW_ELSE = 303,                 // "ELSE"
    KW_END = 304,                  // "END"
    KW_ENUM = 305,                 // "ENUM"
    KW_EXCEPT_IN_SET_OP = 306,     // "EXCEPT in set operation"
    KW_EXCEPT = 307,               // "EXCEPT"
    KW_EXISTS = 308,               // "EXISTS"
    KW_EXTRACT = 309,              // "EXTRACT"
    KW_FALSE = 310,                // "FALSE"
    KW_FOLLOWING = 311,            // "FOLLOWING"
    KW_FROM = 312,                 // "FROM"
    KW_FULL = 313,                 // "FULL"
    KW_GROUP = 314,                // "GROUP"
    KW_GROUPING = 315,             // "GROUPING"
    KW_HASH = 316,                 // "HASH"
    KW_HAVING = 317,               // "HAVING"
    KW_IF = 318,                   // "IF"
    KW_IGNORE = 319,               // "IGNORE"
    KW_IN = 320,                   // "IN"
    KW_INNER = 321,                // "INNER"
    KW_INTERSECT = 322,            // "INTERSECT"
    KW_INTERVAL = 323,             // "INTERVAL"
    KW_INTO = 324,                 // "INTO"
    KW_IS = 325,                   // "IS"
    KW_JOIN = 326,                 // "JOIN"
    KW_LEFT = 327,                 // "LEFT"
    KW_LIKE = 328,                 // "LIKE"
    KW_LIMIT = 329,                // "LIMIT"
    KW_LOOKUP = 330,               // "LOOKUP"
    KW_MERGE = 331,                // "MERGE"
    KW_NATURAL = 332,              // "NATURAL"
    KW_NEW = 333,                  // "NEW"
    KW_NO = 334,                   // "NO"
    KW_NOT = 335,                  // "NOT"
    KW_NULL = 336,                 // "NULL"
    KW_NULLS = 337,                // "NULLS"
    KW_ON = 338,                   // "ON"
    KW_OR = 339,                   // "OR"
    KW_ORDER = 340,                // "ORDER"
    KW_OUTER = 341,                // "OUTER"
    KW_OVER = 342,                 // "OVER"
    KW_PARTITION = 343,            // "PARTITION"
    KW_PRECEDING = 344,            // "PRECEDING"
    KW_PROTO = 345,                // "PROTO"
    KW_RANGE = 346,                // "RANGE"
    KW_RECURSIVE = 347,            // "RECURSIVE"
    KW_RESPECT = 348,              // "RESPECT"
    KW_RIGHT = 349,                // "RIGHT"
    KW_ROLLUP = 350,               // "ROLLUP"
    KW_ROWS = 351,                 // "ROWS"
    KW_SELECT = 352,               // "SELECT"
    KW_SET = 353,                  // "SET"
    KW_STRUCT = 354,               // "STRUCT"
    KW_TABLESAMPLE = 355,          // "TABLESAMPLE"
    KW_THEN = 356,                 // "THEN"
    KW_TO = 357,                   // "TO"
    KW_TRUE = 358,                 // "TRUE"
    KW_UNBOUNDED = 359,            // "UNBOUNDED"
    KW_UNION = 360,                // "UNION"
    KW_USING = 361,                // "USING"
    KW_WHEN = 362,                 // "WHEN"
    KW_WHERE = 363,                // "WHERE"
    KW_WINDOW = 364,               // "WINDOW"
    KW_WITH = 365,                 // "WITH"
    KW_WITH_STARTING_WITH_EXPRESSION = 366, // "WITH starting with expression"
    KW_UNNEST = 367,               // "UNNEST"
    KW_CONTAINS = 368,             // "CONTAINS"
    KW_CUBE = 369,                 // "CUBE"
    KW_ESCAPE = 370,               // "ESCAPE"
    KW_EXCLUDE = 371,              // "EXCLUDE"
    KW_FETCH = 372,                // "FETCH"
    KW_FOR = 373,                  // "FOR"
    KW_GROUPS = 374,               // "GROUPS"
    KW_LATERAL = 375,              // "LATERAL"
    KW_OF = 376,                   // "OF"
    KW_SOME = 377,                 // "SOME"
    KW_TREAT = 378,                // "TREAT"
    KW_WITHIN = 379,               // "WITHIN"
    KW_QUALIFY_RESERVED = 380,     // KW_QUALIFY_RESERVED
    KW_NOT_SPECIAL = 381,          // "NOT_SPECIAL"
    KW_ABORT = 382,                // "ABORT"
    KW_ACCESS = 383,               // "ACCESS"
    KW_ACTION = 384,               // "ACTION"
    KW_ADD = 385,                  // "ADD"
    KW_AGGREGATE = 386,            // "AGGREGATE"
    KW_ALTER = 387,                // "ALTER"
    KW_ANONYMIZATION = 388,        // "ANONYMIZATION"
    KW_ANALYZE = 389,              // "ANALYZE"
    KW_ASSERT = 390,               // "ASSERT"
    KW_BATCH = 391,                // "BATCH"
    KW_BEGIN = 392,                // "BEGIN"
    KW_BIGDECIMAL = 393,           // "BIGDECIMAL"
    KW_BIGNUMERIC = 394,           // "BIGNUMERIC"
    KW_BREAK = 395,                // "BREAK"
    KW_CALL = 396,                 // "CALL"
    KW_CASCADE = 397,              // "CASCADE"
    KW_CHECK = 398,                // "CHECK"
    KW_CLAMPED = 399,              // "CLAMPED"
    KW_CLONE = 400,                // "CLONE"
    KW_COPY = 401,                 // "COPY"
    KW_CLUSTER = 402,              // "CLUSTER"
    KW_COLUMN = 403,               // "COLUMN"
    KW_COLUMNS = 404,              // "COLUMNS"
    KW_COMMIT = 405,               // "COMMIT"
    KW_CONNECTION = 406,           // "CONNECTION"
    KW_CONTINUE = 407,             // "CONTINUE"
    KW_CONSTANT = 408,             // "CONSTANT"
    KW_CONSTRAINT = 409,           // "CONSTRAINT"
    KW_DATA = 410,                 // "DATA"
    KW_DATABASE = 411,             // "DATABASE"
    KW_DATE = 412,                 // "DATE"
    KW_DATETIME = 413,             // "DATETIME"
    KW_DECIMAL = 414,              // "DECIMAL"
    KW_DECLARE = 415,              // "DECLARE"
    KW_DEFINER = 416,              // "DEFINER"
    KW_DELETE = 417,               // "DELETE"
    KW_DELETION = 418,             // "DELETION"
    KW_DESCRIBE = 419,             // "DESCRIBE"
    KW_DESCRIPTOR = 420,           // "DESCRIPTOR"
    KW_DETERMINISTIC = 421,        // "DETERMINISTIC"
    KW_DO = 422,                   // "DO"
    KW_DROP = 423,                 // "DROP"
    KW_ENFORCED = 424,             // "ENFORCED"
    KW_ELSEIF = 425,               // "ELSEIF"
    KW_EXECUTE = 426,              // "EXECUTE"
    KW_EXPLAIN = 427,              // "EXPLAIN"
    KW_EXPORT = 428,               // "EXPORT"
    KW_EXTERNAL = 429,             // "EXTERNAL"
    KW_FILES = 430,                // "FILES"
    KW_FILTER = 431,               // "FILTER"
    KW_FILTER_FIELDS = 432,        // "FILTER_FIELDS"
    KW_FILL = 433,                 // "FILL"
    KW_FIRST = 434,                // "FIRST"
    KW_FOREIGN = 435,              // "FOREIGN"
    KW_FORMAT = 436,               // "FORMAT"
    KW_FUNCTION = 437,             // "FUNCTION"
    KW_GENERATED = 438,            // "GENERATED"
    KW_GRANT = 439,                // "GRANT"
    KW_GROUP_ROWS = 440,           // "GROUP_ROWS"
    KW_HIDDEN = 441,               // "HIDDEN"
    KW_IMMEDIATE = 442,            // "IMMEDIATE"
    KW_IMMUTABLE = 443,            // "IMMUTABLE"
    KW_IMPORT = 444,               // "IMPORT"
    KW_INCLUDE = 445,              // "INCLUDE"
    KW_INDEX = 446,                // "INDEX"
    KW_INOUT = 447,                // "INOUT"
    KW_INSERT = 448,               // "INSERT"
    KW_INVOKER = 449,              // "INVOKER"
    KW_ITERATE = 450,              // "ITERATE"
    KW_ISOLATION = 451,            // "ISOLATION"
    KW_JSON = 452,                 // "JSON"
    KW_KEY = 453,                  // "KEY"
    KW_LANGUAGE = 454,             // "LANGUAGE"
    KW_LAST = 455,                 // "LAST"
    KW_LEAVE = 456,                // "LEAVE"
    KW_LEVEL = 457,                // "LEVEL"
    KW_LOAD = 458,                 // "LOAD"
    KW_LOOP = 459,                 // "LOOP"
    KW_MATCH = 460,                // "MATCH"
    KW_MATCHED = 461,              // "MATCHED"
    KW_MATERIALIZED = 462,         // "MATERIALIZED"
    KW_MAX = 463,                  // "MAX"
    KW_MESSAGE = 464,              // "MESSAGE"
    KW_MIN = 465,                  // "MIN"
    KW_MODEL = 466,                // "MODEL"
    KW_MODULE = 467,               // "MODULE"
    KW_NUMERIC = 468,              // "NUMERIC"
    KW_OFFSET = 469,               // "OFFSET"
    KW_ONLY = 470,                 // "ONLY"
    KW_OPTIONS = 471,              // "OPTIONS"
    KW_OUT = 472,                  // "OUT"
    KW_OVERWRITE = 473,            // "OVERWRITE"
    KW_PERCENT = 474,              // "PERCENT"
    KW_PIVOT = 475,                // "PIVOT"
    KW_POLICIES = 476,             // "POLICIES"
    KW_POLICY = 477,               // "POLICY"
    KW_PRIMARY = 478,              // "PRIMARY"
    KW_PRIVATE = 479,              // "PRIVATE"
    KW_PRIVILEGE = 480,            // "PRIVILEGE"
    KW_PRIVILEGES = 481,           // "PRIVILEGES"
    KW_PROCEDURE = 482,            // "PROCEDURE"
    KW_PUBLIC = 483,               // "PUBLIC"
    KW_QUALIFY_NONRESERVED = 484,  // KW_QUALIFY_NONRESERVED
    KW_RAISE = 485,                // "RAISE"
    KW_READ = 486,                 // "READ"
    KW_REFERENCES = 487,           // "REFERENCES"
    KW_REMOTE = 488,               // "REMOTE"
    KW_REMOVE = 489,               // "REMOVE"
    KW_RENAME = 490,               // "RENAME"
    KW_REPEAT = 491,               // "REPEAT"
    KW_REPEATABLE = 492,           // "REPEATABLE"
    KW_REPLACE = 493,              // "REPLACE"
    KW_REPLACE_FIELDS = 494,       // "REPLACE_FIELDS"
    KW_REPORT = 495,               // "REPORT"
    KW_RESTRICT = 496,             // "RESTRICT"
    KW_RESTRICTION = 497,          // "RESTRICTION"
    KW_RETURN = 498,               // "RETURN"
    KW_RETURNS = 499,              // "RETURNS"
    KW_REVOKE = 500,               // "REVOKE"
    KW_ROLLBACK = 501,             // "ROLLBACK"
    KW_ROW = 502,                  // "ROW"
    KW_RUN = 503,                  // "RUN"
    KW_SAFE_CAST = 504,            // "SAFE_CAST"
    KW_SCHEMA = 505,               // "SCHEMA"
    KW_SEARCH = 506,               // "SEARCH"
    KW_SECURITY = 507,             // "SECURITY"
    KW_SHOW = 508,                 // "SHOW"
    KW_SIMPLE = 509,               // "SIMPLE"
    KW_SNAPSHOT = 510,             // "SNAPSHOT"
    KW_SOURCE = 511,               // "SOURCE"
    KW_SQL = 512,                  // "SQL"
    KW_STABLE = 513,               // "STABLE"
    KW_START = 514,                // "START"
    KW_STORED = 515,               // "STORED"
    KW_STORING = 516,              // "STORING"
    KW_SYSTEM = 517,               // "SYSTEM"
    KW_SYSTEM_TIME = 518,          // "SYSTEM_TIME"
    KW_TABLE = 519,                // "TABLE"
    KW_TARGET = 520,               // "TARGET"
    KW_TRANSFORM = 521,            // "TRANSFORM"
    KW_TEMP = 522,                 // "TEMP"
    KW_TEMPORARY = 523,            // "TEMPORARY"
    KW_TIME = 524,                 // "TIME"
    KW_TIMESTAMP = 525,            // "TIMESTAMP"
    KW_TRANSACTION = 526,          // "TRANSACTION"
    KW_TRUNCATE = 527,             // "TRUNCATE"
    KW_TYPE = 528,                 // "TYPE"
    KW_UNIQUE = 529,               // "UNIQUE"
    KW_UNKNOWN = 530,              // "UNKNOWN"
    KW_UNPIVOT = 531,              // "UNPIVOT"
    KW_UNTIL = 532,                // "UNTIL"
    KW_UPDATE = 533,               // "UPDATE"
    KW_VALUE = 534,                // "VALUE"
    KW_VALUES = 535,               // "VALUES"
    KW_VOLATILE = 536,             // "VOLATILE"
    KW_VIEW = 537,                 // "VIEW"
    KW_VIEWS = 538,                // "VIEWS"
    KW_WEIGHT = 539,               // "WEIGHT"
    KW_WHILE = 540,                // "WHILE"
    KW_WRITE = 541,                // "WRITE"
    KW_ZONE = 542,                 // "ZONE"
    KW_EXCEPTION = 543,            // "EXCEPTION"
    KW_ERROR = 544,                // "ERROR"
    KW_INTERLEAVE = 545,           // "INTERLEAVE"
    KW_NULL_FILTERED = 546,        // "NULL_FILTERED"
    KW_PARENT = 547,               // "PARENT"
    KW_CURRENT_DATETIME_FUNCTION = 548, // KW_CURRENT_DATETIME_FUNCTION
    MODE_STATEMENT = 549,          // MODE_STATEMENT
    MODE_SCRIPT = 550,             // MODE_SCRIPT
    MODE_NEXT_STATEMENT = 551,     // MODE_NEXT_STATEMENT
    MODE_NEXT_SCRIPT_STATEMENT = 552, // MODE_NEXT_SCRIPT_STATEMENT
    MODE_NEXT_STATEMENT_KIND = 553, // MODE_NEXT_STATEMENT_KIND
    MODE_EXPRESSION = 554,         // MODE_EXPRESSION
    MODE_TYPE = 555                // MODE_TYPE
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 324, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of input"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_STRING_LITERAL = 3,                    // "string literal"
        S_BYTES_LITERAL = 4,                     // "bytes literal"
        S_INTEGER_LITERAL = 5,                   // "integer literal"
        S_FLOATING_POINT_LITERAL = 6,            // "floating point literal"
        S_IDENTIFIER = 7,                        // "identifier"
        S_LABEL = 8,                             // "label"
        S_COMMENT = 9,                           // "comment"
        S_10_ = 10,                              // "*"
        S_11_ = 11,                              // ","
        S_12_ = 12,                              // ";"
        S_13_ = 13,                              // "("
        S_14_ = 14,                              // ")"
        S_15_ = 15,                              // "="
        S_KW_NOT_EQUALS_C_STYLE = 16,            // "!="
        S_KW_NOT_EQUALS_SQL_STYLE = 17,          // "<>"
        S_18_ = 18,                              // "<"
        S_KW_LESS_EQUALS = 19,                   // "<="
        S_20_ = 20,                              // ">"
        S_KW_GREATER_EQUALS = 21,                // ">="
        S_22_ = 22,                              // "|"
        S_23_ = 23,                              // "^"
        S_24_ = 24,                              // "&"
        S_25_ = 25,                              // "["
        S_26_ = 26,                              // "]"
        S_27_ = 27,                              // "@"
        S_KW_DOUBLE_AT = 28,                     // "@@"
        S_KW_CONCAT_OP = 29,                     // "||"
        S_30_ = 30,                              // "+"
        S_31_ = 31,                              // "-"
        S_32_ = 32,                              // "/"
        S_33_ = 33,                              // "~"
        S_34_ = 34,                              // "."
        S_KW_DOT_STAR = 35,                      // ".*"
        S_KW_OPEN_HINT = 36,                     // "@{"
        S_37_ = 37,                              // "}"
        S_38_ = 38,                              // "?"
        S_KW_OPEN_INTEGER_HINT = 39,             // "@n"
        S_KW_SHIFT_LEFT = 40,                    // "<<"
        S_KW_SHIFT_RIGHT = 41,                   // ">>"
        S_KW_NAMED_ARGUMENT_ASSIGNMENT = 42,     // "=>"
        S_KW_LAMBDA_ARROW = 43,                  // "->"
        S_44_ = 44,                              // ":"
        S_45_ = 45,                              // "{"
        S_UNARY_NOT_PRECEDENCE = 46,             // UNARY_NOT_PRECEDENCE
        S_UNARY_PRECEDENCE = 47,                 // UNARY_PRECEDENCE
        S_DOUBLE_AT_PRECEDENCE = 48,             // DOUBLE_AT_PRECEDENCE
        S_PRIMARY_PRECEDENCE = 49,               // PRIMARY_PRECEDENCE
        S_KW_ALL = 50,                           // "ALL"
        S_KW_AND = 51,                           // "AND"
        S_KW_AND_FOR_BETWEEN = 52,               // "AND for BETWEEN"
        S_KW_ANY = 53,                           // "ANY"
        S_KW_ARRAY = 54,                         // "ARRAY"
        S_KW_AS = 55,                            // "AS"
        S_KW_ASC = 56,                           // "ASC"
        S_KW_ASSERT_ROWS_MODIFIED = 57,          // "ASSERT_ROWS_MODIFIED"
        S_KW_AT = 58,                            // "AT"
        S_KW_BETWEEN = 59,                       // "BETWEEN"
        S_KW_BY = 60,                            // "BY"
        S_KW_CASE = 61,                          // "CASE"
        S_KW_CAST = 62,                          // "CAST"
        S_KW_COLLATE = 63,                       // "COLLATE"
        S_KW_CREATE = 64,                        // "CREATE"
        S_KW_CROSS = 65,                         // "CROSS"
        S_KW_CURRENT = 66,                       // "CURRENT"
        S_KW_DEFAULT = 67,                       // "DEFAULT"
        S_KW_DEFINE = 68,                        // "DEFINE"
        S_KW_DESC = 69,                          // "DESC"
        S_KW_DISTINCT = 70,                      // "DISTINCT"
        S_KW_ELSE = 71,                          // "ELSE"
        S_KW_END = 72,                           // "END"
        S_KW_ENUM = 73,                          // "ENUM"
        S_KW_EXCEPT_IN_SET_OP = 74,              // "EXCEPT in set operation"
        S_KW_EXCEPT = 75,                        // "EXCEPT"
        S_KW_EXISTS = 76,                        // "EXISTS"
        S_KW_EXTRACT = 77,                       // "EXTRACT"
        S_KW_FALSE = 78,                         // "FALSE"
        S_KW_FOLLOWING = 79,                     // "FOLLOWING"
        S_KW_FROM = 80,                          // "FROM"
        S_KW_FULL = 81,                          // "FULL"
        S_KW_GROUP = 82,                         // "GROUP"
        S_KW_GROUPING = 83,                      // "GROUPING"
        S_KW_HASH = 84,                          // "HASH"
        S_KW_HAVING = 85,                        // "HAVING"
        S_KW_IF = 86,                            // "IF"
        S_KW_IGNORE = 87,                        // "IGNORE"
        S_KW_IN = 88,                            // "IN"
        S_KW_INNER = 89,                         // "INNER"
        S_KW_INTERSECT = 90,                     // "INTERSECT"
        S_KW_INTERVAL = 91,                      // "INTERVAL"
        S_KW_INTO = 92,                          // "INTO"
        S_KW_IS = 93,                            // "IS"
        S_KW_JOIN = 94,                          // "JOIN"
        S_KW_LEFT = 95,                          // "LEFT"
        S_KW_LIKE = 96,                          // "LIKE"
        S_KW_LIMIT = 97,                         // "LIMIT"
        S_KW_LOOKUP = 98,                        // "LOOKUP"
        S_KW_MERGE = 99,                         // "MERGE"
        S_KW_NATURAL = 100,                      // "NATURAL"
        S_KW_NEW = 101,                          // "NEW"
        S_KW_NO = 102,                           // "NO"
        S_KW_NOT = 103,                          // "NOT"
        S_KW_NULL = 104,                         // "NULL"
        S_KW_NULLS = 105,                        // "NULLS"
        S_KW_ON = 106,                           // "ON"
        S_KW_OR = 107,                           // "OR"
        S_KW_ORDER = 108,                        // "ORDER"
        S_KW_OUTER = 109,                        // "OUTER"
        S_KW_OVER = 110,                         // "OVER"
        S_KW_PARTITION = 111,                    // "PARTITION"
        S_KW_PRECEDING = 112,                    // "PRECEDING"
        S_KW_PROTO = 113,                        // "PROTO"
        S_KW_RANGE = 114,                        // "RANGE"
        S_KW_RECURSIVE = 115,                    // "RECURSIVE"
        S_KW_RESPECT = 116,                      // "RESPECT"
        S_KW_RIGHT = 117,                        // "RIGHT"
        S_KW_ROLLUP = 118,                       // "ROLLUP"
        S_KW_ROWS = 119,                         // "ROWS"
        S_KW_SELECT = 120,                       // "SELECT"
        S_KW_SET = 121,                          // "SET"
        S_KW_STRUCT = 122,                       // "STRUCT"
        S_KW_TABLESAMPLE = 123,                  // "TABLESAMPLE"
        S_KW_THEN = 124,                         // "THEN"
        S_KW_TO = 125,                           // "TO"
        S_KW_TRUE = 126,                         // "TRUE"
        S_KW_UNBOUNDED = 127,                    // "UNBOUNDED"
        S_KW_UNION = 128,                        // "UNION"
        S_KW_USING = 129,                        // "USING"
        S_KW_WHEN = 130,                         // "WHEN"
        S_KW_WHERE = 131,                        // "WHERE"
        S_KW_WINDOW = 132,                       // "WINDOW"
        S_KW_WITH = 133,                         // "WITH"
        S_KW_WITH_STARTING_WITH_EXPRESSION = 134, // "WITH starting with expression"
        S_KW_UNNEST = 135,                       // "UNNEST"
        S_KW_CONTAINS = 136,                     // "CONTAINS"
        S_KW_CUBE = 137,                         // "CUBE"
        S_KW_ESCAPE = 138,                       // "ESCAPE"
        S_KW_EXCLUDE = 139,                      // "EXCLUDE"
        S_KW_FETCH = 140,                        // "FETCH"
        S_KW_FOR = 141,                          // "FOR"
        S_KW_GROUPS = 142,                       // "GROUPS"
        S_KW_LATERAL = 143,                      // "LATERAL"
        S_KW_OF = 144,                           // "OF"
        S_KW_SOME = 145,                         // "SOME"
        S_KW_TREAT = 146,                        // "TREAT"
        S_KW_WITHIN = 147,                       // "WITHIN"
        S_KW_QUALIFY_RESERVED = 148,             // KW_QUALIFY_RESERVED
        S_KW_NOT_SPECIAL = 149,                  // "NOT_SPECIAL"
        S_KW_ABORT = 150,                        // "ABORT"
        S_KW_ACCESS = 151,                       // "ACCESS"
        S_KW_ACTION = 152,                       // "ACTION"
        S_KW_ADD = 153,                          // "ADD"
        S_KW_AGGREGATE = 154,                    // "AGGREGATE"
        S_KW_ALTER = 155,                        // "ALTER"
        S_KW_ANONYMIZATION = 156,                // "ANONYMIZATION"
        S_KW_ANALYZE = 157,                      // "ANALYZE"
        S_KW_ASSERT = 158,                       // "ASSERT"
        S_KW_BATCH = 159,                        // "BATCH"
        S_KW_BEGIN = 160,                        // "BEGIN"
        S_KW_BIGDECIMAL = 161,                   // "BIGDECIMAL"
        S_KW_BIGNUMERIC = 162,                   // "BIGNUMERIC"
        S_KW_BREAK = 163,                        // "BREAK"
        S_KW_CALL = 164,                         // "CALL"
        S_KW_CASCADE = 165,                      // "CASCADE"
        S_KW_CHECK = 166,                        // "CHECK"
        S_KW_CLAMPED = 167,                      // "CLAMPED"
        S_KW_CLONE = 168,                        // "CLONE"
        S_KW_COPY = 169,                         // "COPY"
        S_KW_CLUSTER = 170,                      // "CLUSTER"
        S_KW_COLUMN = 171,                       // "COLUMN"
        S_KW_COLUMNS = 172,                      // "COLUMNS"
        S_KW_COMMIT = 173,                       // "COMMIT"
        S_KW_CONNECTION = 174,                   // "CONNECTION"
        S_KW_CONTINUE = 175,                     // "CONTINUE"
        S_KW_CONSTANT = 176,                     // "CONSTANT"
        S_KW_CONSTRAINT = 177,                   // "CONSTRAINT"
        S_KW_DATA = 178,                         // "DATA"
        S_KW_DATABASE = 179,                     // "DATABASE"
        S_KW_DATE = 180,                         // "DATE"
        S_KW_DATETIME = 181,                     // "DATETIME"
        S_KW_DECIMAL = 182,                      // "DECIMAL"
        S_KW_DECLARE = 183,                      // "DECLARE"
        S_KW_DEFINER = 184,                      // "DEFINER"
        S_KW_DELETE = 185,                       // "DELETE"
        S_KW_DELETION = 186,                     // "DELETION"
        S_KW_DESCRIBE = 187,                     // "DESCRIBE"
        S_KW_DESCRIPTOR = 188,                   // "DESCRIPTOR"
        S_KW_DETERMINISTIC = 189,                // "DETERMINISTIC"
        S_KW_DO = 190,                           // "DO"
        S_KW_DROP = 191,                         // "DROP"
        S_KW_ENFORCED = 192,                     // "ENFORCED"
        S_KW_ELSEIF = 193,                       // "ELSEIF"
        S_KW_EXECUTE = 194,                      // "EXECUTE"
        S_KW_EXPLAIN = 195,                      // "EXPLAIN"
        S_KW_EXPORT = 196,                       // "EXPORT"
        S_KW_EXTERNAL = 197,                     // "EXTERNAL"
        S_KW_FILES = 198,                        // "FILES"
        S_KW_FILTER = 199,                       // "FILTER"
        S_KW_FILTER_FIELDS = 200,                // "FILTER_FIELDS"
        S_KW_FILL = 201,                         // "FILL"
        S_KW_FIRST = 202,                        // "FIRST"
        S_KW_FOREIGN = 203,                      // "FOREIGN"
        S_KW_FORMAT = 204,                       // "FORMAT"
        S_KW_FUNCTION = 205,                     // "FUNCTION"
        S_KW_GENERATED = 206,                    // "GENERATED"
        S_KW_GRANT = 207,                        // "GRANT"
        S_KW_GROUP_ROWS = 208,                   // "GROUP_ROWS"
        S_KW_HIDDEN = 209,                       // "HIDDEN"
        S_KW_IMMEDIATE = 210,                    // "IMMEDIATE"
        S_KW_IMMUTABLE = 211,                    // "IMMUTABLE"
        S_KW_IMPORT = 212,                       // "IMPORT"
        S_KW_INCLUDE = 213,                      // "INCLUDE"
        S_KW_INDEX = 214,                        // "INDEX"
        S_KW_INOUT = 215,                        // "INOUT"
        S_KW_INSERT = 216,                       // "INSERT"
        S_KW_INVOKER = 217,                      // "INVOKER"
        S_KW_ITERATE = 218,                      // "ITERATE"
        S_KW_ISOLATION = 219,                    // "ISOLATION"
        S_KW_JSON = 220,                         // "JSON"
        S_KW_KEY = 221,                          // "KEY"
        S_KW_LANGUAGE = 222,                     // "LANGUAGE"
        S_KW_LAST = 223,                         // "LAST"
        S_KW_LEAVE = 224,                        // "LEAVE"
        S_KW_LEVEL = 225,                        // "LEVEL"
        S_KW_LOAD = 226,                         // "LOAD"
        S_KW_LOOP = 227,                         // "LOOP"
        S_KW_MATCH = 228,                        // "MATCH"
        S_KW_MATCHED = 229,                      // "MATCHED"
        S_KW_MATERIALIZED = 230,                 // "MATERIALIZED"
        S_KW_MAX = 231,                          // "MAX"
        S_KW_MESSAGE = 232,                      // "MESSAGE"
        S_KW_MIN = 233,                          // "MIN"
        S_KW_MODEL = 234,                        // "MODEL"
        S_KW_MODULE = 235,                       // "MODULE"
        S_KW_NUMERIC = 236,                      // "NUMERIC"
        S_KW_OFFSET = 237,                       // "OFFSET"
        S_KW_ONLY = 238,                         // "ONLY"
        S_KW_OPTIONS = 239,                      // "OPTIONS"
        S_KW_OUT = 240,                          // "OUT"
        S_KW_OVERWRITE = 241,                    // "OVERWRITE"
        S_KW_PERCENT = 242,                      // "PERCENT"
        S_KW_PIVOT = 243,                        // "PIVOT"
        S_KW_POLICIES = 244,                     // "POLICIES"
        S_KW_POLICY = 245,                       // "POLICY"
        S_KW_PRIMARY = 246,                      // "PRIMARY"
        S_KW_PRIVATE = 247,                      // "PRIVATE"
        S_KW_PRIVILEGE = 248,                    // "PRIVILEGE"
        S_KW_PRIVILEGES = 249,                   // "PRIVILEGES"
        S_KW_PROCEDURE = 250,                    // "PROCEDURE"
        S_KW_PUBLIC = 251,                       // "PUBLIC"
        S_KW_QUALIFY_NONRESERVED = 252,          // KW_QUALIFY_NONRESERVED
        S_KW_RAISE = 253,                        // "RAISE"
        S_KW_READ = 254,                         // "READ"
        S_KW_REFERENCES = 255,                   // "REFERENCES"
        S_KW_REMOTE = 256,                       // "REMOTE"
        S_KW_REMOVE = 257,                       // "REMOVE"
        S_KW_RENAME = 258,                       // "RENAME"
        S_KW_REPEAT = 259,                       // "REPEAT"
        S_KW_REPEATABLE = 260,                   // "REPEATABLE"
        S_KW_REPLACE = 261,                      // "REPLACE"
        S_KW_REPLACE_FIELDS = 262,               // "REPLACE_FIELDS"
        S_KW_REPORT = 263,                       // "REPORT"
        S_KW_RESTRICT = 264,                     // "RESTRICT"
        S_KW_RESTRICTION = 265,                  // "RESTRICTION"
        S_KW_RETURN = 266,                       // "RETURN"
        S_KW_RETURNS = 267,                      // "RETURNS"
        S_KW_REVOKE = 268,                       // "REVOKE"
        S_KW_ROLLBACK = 269,                     // "ROLLBACK"
        S_KW_ROW = 270,                          // "ROW"
        S_KW_RUN = 271,                          // "RUN"
        S_KW_SAFE_CAST = 272,                    // "SAFE_CAST"
        S_KW_SCHEMA = 273,                       // "SCHEMA"
        S_KW_SEARCH = 274,                       // "SEARCH"
        S_KW_SECURITY = 275,                     // "SECURITY"
        S_KW_SHOW = 276,                         // "SHOW"
        S_KW_SIMPLE = 277,                       // "SIMPLE"
        S_KW_SNAPSHOT = 278,                     // "SNAPSHOT"
        S_KW_SOURCE = 279,                       // "SOURCE"
        S_KW_SQL = 280,                          // "SQL"
        S_KW_STABLE = 281,                       // "STABLE"
        S_KW_START = 282,                        // "START"
        S_KW_STORED = 283,                       // "STORED"
        S_KW_STORING = 284,                      // "STORING"
        S_KW_SYSTEM = 285,                       // "SYSTEM"
        S_KW_SYSTEM_TIME = 286,                  // "SYSTEM_TIME"
        S_KW_TABLE = 287,                        // "TABLE"
        S_KW_TARGET = 288,                       // "TARGET"
        S_KW_TRANSFORM = 289,                    // "TRANSFORM"
        S_KW_TEMP = 290,                         // "TEMP"
        S_KW_TEMPORARY = 291,                    // "TEMPORARY"
        S_KW_TIME = 292,                         // "TIME"
        S_KW_TIMESTAMP = 293,                    // "TIMESTAMP"
        S_KW_TRANSACTION = 294,                  // "TRANSACTION"
        S_KW_TRUNCATE = 295,                     // "TRUNCATE"
        S_KW_TYPE = 296,                         // "TYPE"
        S_KW_UNIQUE = 297,                       // "UNIQUE"
        S_KW_UNKNOWN = 298,                      // "UNKNOWN"
        S_KW_UNPIVOT = 299,                      // "UNPIVOT"
        S_KW_UNTIL = 300,                        // "UNTIL"
        S_KW_UPDATE = 301,                       // "UPDATE"
        S_KW_VALUE = 302,                        // "VALUE"
        S_KW_VALUES = 303,                       // "VALUES"
        S_KW_VOLATILE = 304,                     // "VOLATILE"
        S_KW_VIEW = 305,                         // "VIEW"
        S_KW_VIEWS = 306,                        // "VIEWS"
        S_KW_WEIGHT = 307,                       // "WEIGHT"
        S_KW_WHILE = 308,                        // "WHILE"
        S_KW_WRITE = 309,                        // "WRITE"
        S_KW_ZONE = 310,                         // "ZONE"
        S_KW_EXCEPTION = 311,                    // "EXCEPTION"
        S_KW_ERROR = 312,                        // "ERROR"
        S_KW_INTERLEAVE = 313,                   // "INTERLEAVE"
        S_KW_NULL_FILTERED = 314,                // "NULL_FILTERED"
        S_KW_PARENT = 315,                       // "PARENT"
        S_KW_CURRENT_DATETIME_FUNCTION = 316,    // KW_CURRENT_DATETIME_FUNCTION
        S_MODE_STATEMENT = 317,                  // MODE_STATEMENT
        S_MODE_SCRIPT = 318,                     // MODE_SCRIPT
        S_MODE_NEXT_STATEMENT = 319,             // MODE_NEXT_STATEMENT
        S_MODE_NEXT_SCRIPT_STATEMENT = 320,      // MODE_NEXT_SCRIPT_STATEMENT
        S_MODE_NEXT_STATEMENT_KIND = 321,        // MODE_NEXT_STATEMENT_KIND
        S_MODE_EXPRESSION = 322,                 // MODE_EXPRESSION
        S_MODE_TYPE = 323,                       // MODE_TYPE
        S_YYACCEPT = 324,                        // $accept
        S_start_mode = 325,                      // start_mode
        S_opt_semicolon = 326,                   // opt_semicolon
        S_sql_statement = 327,                   // sql_statement
        S_next_script_statement = 328,           // next_script_statement
        S_next_statement = 329,                  // next_statement
        S_unterminated_statement = 330,          // unterminated_statement
        S_unterminated_sql_statement = 331,      // unterminated_sql_statement
        S_unterminated_script_statement = 332,   // unterminated_script_statement
        S_terminated_statement = 333,            // terminated_statement
        S_sql_statement_body = 334,              // sql_statement_body
        S_query_statement = 335,                 // query_statement
        S_alter_action = 336,                    // alter_action
        S_alter_action_list = 337,               // alter_action_list
        S_privilege_restriction_alter_action = 338, // privilege_restriction_alter_action
        S_privilege_restriction_alter_action_list = 339, // privilege_restriction_alter_action_list
        S_row_access_policy_alter_action = 340,  // row_access_policy_alter_action
        S_row_access_policy_alter_action_list = 341, // row_access_policy_alter_action_list
        S_schema_object_kind = 342,              // schema_object_kind
        S_alter_statement = 343,                 // alter_statement
        S_opt_transform_clause = 344,            // opt_transform_clause
        S_assert_statement = 345,                // assert_statement
        S_opt_description = 346,                 // opt_description
        S_analyze_statement = 347,               // analyze_statement
        S_opt_table_and_column_info_list = 348,  // opt_table_and_column_info_list
        S_table_and_column_info_list = 349,      // table_and_column_info_list
        S_table_and_column_info = 350,           // table_and_column_info
        S_transaction_mode = 351,                // transaction_mode
        S_transaction_mode_list = 352,           // transaction_mode_list
        S_opt_transaction_mode_list = 353,       // opt_transaction_mode_list
        S_begin_statement = 354,                 // begin_statement
        S_begin_transaction_keywords = 355,      // begin_transaction_keywords
        S_transaction_keyword = 356,             // transaction_keyword
        S_opt_transaction_keyword = 357,         // opt_transaction_keyword
        S_set_statement = 358,                   // set_statement
        S_commit_statement = 359,                // commit_statement
        S_rollback_statement = 360,              // rollback_statement
        S_start_batch_statement = 361,           // start_batch_statement
        S_run_batch_statement = 362,             // run_batch_statement
        S_abort_batch_statement = 363,           // abort_batch_statement
        S_create_constant_statement = 364,       // create_constant_statement
        S_create_database_statement = 365,       // create_database_statement
        S_create_function_statement = 366,       // create_function_statement
        S_opt_aggregate = 367,                   // opt_aggregate
        S_opt_not_aggregate = 368,               // opt_not_aggregate
        S_function_declaration = 369,            // function_declaration
        S_function_parameter = 370,              // function_parameter
        S_function_parameters_prefix = 371,      // function_parameters_prefix
        S_function_parameters = 372,             // function_parameters
        S_unlabeled_begin_end_block_or_language_as_code = 373, // unlabeled_begin_end_block_or_language_as_code
        S_create_procedure_statement = 374,      // create_procedure_statement
        S_procedure_parameters_prefix = 375,     // procedure_parameters_prefix
        S_procedure_parameters = 376,            // procedure_parameters
        S_procedure_parameter_termination = 377, // procedure_parameter_termination
        S_procedure_parameter = 378,             // procedure_parameter
        S_opt_procedure_parameter_mode = 379,    // opt_procedure_parameter_mode
        S_opt_returns = 380,                     // opt_returns
        S_opt_function_returns = 381,            // opt_function_returns
        S_opt_determinism_level = 382,           // opt_determinism_level
        S_opt_language = 383,                    // opt_language
        S_remote_with_connection_clause = 384,   // remote_with_connection_clause
        S_opt_remote_with_connection_clause = 385, // opt_remote_with_connection_clause
        S_opt_language_or_remote_with_connection = 386, // opt_language_or_remote_with_connection
        S_opt_sql_security_clause = 387,         // opt_sql_security_clause
        S_sql_security_clause_kind = 388,        // sql_security_clause_kind
        S_as_sql_function_body_or_string = 389,  // as_sql_function_body_or_string
        S_opt_as_sql_function_body_or_string = 390, // opt_as_sql_function_body_or_string
        S_opt_as_code = 391,                     // opt_as_code
        S_path_expression_or_string = 392,       // path_expression_or_string
        S_sql_function_body = 393,               // sql_function_body
        S_restrict_to_clause = 394,              // restrict_to_clause
        S_opt_restrict_to_clause = 395,          // opt_restrict_to_clause
        S_grant_to_clause = 396,                 // grant_to_clause
        S_create_row_access_policy_grant_to_clause = 397, // create_row_access_policy_grant_to_clause
        S_opt_create_row_access_policy_grant_to_clause = 398, // opt_create_row_access_policy_grant_to_clause
        S_opt_filter = 399,                      // opt_filter
        S_filter_using_clause = 400,             // filter_using_clause
        S_create_privilege_restriction_statement = 401, // create_privilege_restriction_statement
        S_create_row_access_policy_statement = 402, // create_row_access_policy_statement
        S_with_partition_columns_clause = 403,   // with_partition_columns_clause
        S_with_connection_clause = 404,          // with_connection_clause
        S_opt_external_table_with_clauses = 405, // opt_external_table_with_clauses
        S_create_external_table_statement = 406, // create_external_table_statement
        S_create_external_table_function_statement = 407, // create_external_table_function_statement
        S_create_index_statement = 408,          // create_index_statement
        S_create_schema_statement = 409,         // create_schema_statement
        S_create_snapshot_table_statement = 410, // create_snapshot_table_statement
        S_create_table_function_statement = 411, // create_table_function_statement
        S_create_table_statement = 412,          // create_table_statement
        S_append_or_overwrite = 413,             // append_or_overwrite
        S_aux_load_data_from_files_options_list = 414, // aux_load_data_from_files_options_list
        S_aux_load_data_statement = 415,         // aux_load_data_statement
        S_generic_entity_type = 416,             // generic_entity_type
        S_generic_sub_entity_type = 417,         // generic_sub_entity_type
        S_generic_entity_body = 418,             // generic_entity_body
        S_opt_generic_entity_body = 419,         // opt_generic_entity_body
        S_create_entity_statement = 420,         // create_entity_statement
        S_create_model_statement = 421,          // create_model_statement
        S_opt_table_element_list = 422,          // opt_table_element_list
        S_table_element_list = 423,              // table_element_list
        S_table_element_list_prefix = 424,       // table_element_list_prefix
        S_table_element = 425,                   // table_element
        S_table_column_definition = 426,         // table_column_definition
        S_table_column_schema = 427,             // table_column_schema
        S_simple_column_schema_inner = 428,      // simple_column_schema_inner
        S_array_column_schema_inner = 429,       // array_column_schema_inner
        S_struct_column_field = 430,             // struct_column_field
        S_struct_column_schema_prefix = 431,     // struct_column_schema_prefix
        S_struct_column_schema_inner = 432,      // struct_column_schema_inner
        S_raw_column_schema_inner = 433,         // raw_column_schema_inner
        S_column_schema_inner = 434,             // column_schema_inner
        S_generated_as_keywords = 435,           // generated_as_keywords
        S_stored_mode = 436,                     // stored_mode
        S_generated_column_info = 437,           // generated_column_info
        S_invalid_generated_column = 438,        // invalid_generated_column
        S_default_column_info = 439,             // default_column_info
        S_invalid_default_column = 440,          // invalid_default_column
        S_opt_column_info = 441,                 // opt_column_info
        S_field_schema = 442,                    // field_schema
        S_primary_key_column_attribute = 443,    // primary_key_column_attribute
        S_foreign_key_column_attribute = 444,    // foreign_key_column_attribute
        S_hidden_column_attribute = 445,         // hidden_column_attribute
        S_not_null_column_attribute = 446,       // not_null_column_attribute
        S_column_attribute = 447,                // column_attribute
        S_column_attributes = 448,               // column_attributes
        S_opt_column_attributes = 449,           // opt_column_attributes
        S_opt_field_attributes = 450,            // opt_field_attributes
        S_column_position = 451,                 // column_position
        S_opt_column_position = 452,             // opt_column_position
        S_fill_using_expression = 453,           // fill_using_expression
        S_opt_fill_using_expression = 454,       // opt_fill_using_expression
        S_table_constraint_spec = 455,           // table_constraint_spec
        S_primary_key_element = 456,             // primary_key_element
        S_primary_key_element_list_prefix = 457, // primary_key_element_list_prefix
        S_primary_key_element_list = 458,        // primary_key_element_list
        S_primary_key_spec = 459,                // primary_key_spec
        S_primary_key_or_table_constraint_spec = 460, // primary_key_or_table_constraint_spec
        S_table_constraint_definition = 461,     // table_constraint_definition
        S_foreign_key_reference = 462,           // foreign_key_reference
        S_opt_foreign_key_match = 463,           // opt_foreign_key_match
        S_foreign_key_match_mode = 464,          // foreign_key_match_mode
        S_opt_foreign_key_actions = 465,         // opt_foreign_key_actions
        S_opt_foreign_key_on_update = 466,       // opt_foreign_key_on_update
        S_opt_foreign_key_on_delete = 467,       // opt_foreign_key_on_delete
        S_foreign_key_on_update = 468,           // foreign_key_on_update
        S_foreign_key_on_delete = 469,           // foreign_key_on_delete
        S_foreign_key_action = 470,              // foreign_key_action
        S_opt_constraint_identity = 471,         // opt_constraint_identity
        S_opt_constraint_enforcement = 472,      // opt_constraint_enforcement
        S_constraint_enforcement = 473,          // constraint_enforcement
        S_table_or_table_function = 474,         // table_or_table_function
        S_tvf_schema_column = 475,               // tvf_schema_column
        S_tvf_schema_prefix = 476,               // tvf_schema_prefix
        S_tvf_schema = 477,                      // tvf_schema
        S_opt_recursive = 478,                   // opt_recursive
        S_create_view_statement = 479,           // create_view_statement
        S_as_query = 480,                        // as_query
        S_opt_as_query = 481,                    // opt_as_query
        S_opt_as_query_or_string = 482,          // opt_as_query_or_string
        S_opt_if_not_exists = 483,               // opt_if_not_exists
        S_describe_statement = 484,              // describe_statement
        S_describe_info = 485,                   // describe_info
        S_opt_from_path_expression = 486,        // opt_from_path_expression
        S_explain_statement = 487,               // explain_statement
        S_export_data_statement = 488,           // export_data_statement
        S_export_model_statement = 489,          // export_model_statement
        S_grant_statement = 490,                 // grant_statement
        S_revoke_statement = 491,                // revoke_statement
        S_privileges = 492,                      // privileges
        S_opt_privileges_keyword = 493,          // opt_privileges_keyword
        S_privilege_list = 494,                  // privilege_list
        S_privilege = 495,                       // privilege
        S_privilege_name = 496,                  // privilege_name
        S_rename_statement = 497,                // rename_statement
        S_import_statement = 498,                // import_statement
        S_module_statement = 499,                // module_statement
        S_index_order_by_prefix = 500,           // index_order_by_prefix
        S_index_all_columns = 501,               // index_all_columns
        S_index_order_by = 502,                  // index_order_by
        S_index_unnest_expression_list = 503,    // index_unnest_expression_list
        S_opt_index_unnest_expression_list = 504, // opt_index_unnest_expression_list
        S_index_storing_expression_list_prefix = 505, // index_storing_expression_list_prefix
        S_index_storing_expression_list = 506,   // index_storing_expression_list
        S_index_storing_list = 507,              // index_storing_list
        S_opt_index_storing_list = 508,          // opt_index_storing_list
        S_column_list_prefix = 509,              // column_list_prefix
        S_column_list = 510,                     // column_list
        S_opt_column_list = 511,                 // opt_column_list
        S_grantee_list = 512,                    // grantee_list
        S_grantee_list_with_parens_prefix = 513, // grantee_list_with_parens_prefix
        S_possibly_empty_grantee_list = 514,     // possibly_empty_grantee_list
        S_show_statement = 515,                  // show_statement
        S_show_target = 516,                     // show_target
        S_opt_like_string_literal = 517,         // opt_like_string_literal
        S_opt_like_path_expression = 518,        // opt_like_path_expression
        S_opt_clone_table = 519,                 // opt_clone_table
        S_opt_copy_table = 520,                  // opt_copy_table
        S_all_or_distinct = 521,                 // all_or_distinct
        S_query_set_operation_type = 522,        // query_set_operation_type
        S_query_primary_or_set_operation = 523,  // query_primary_or_set_operation
        S_query_primary_or_set_operation_maybe_expression = 524, // query_primary_or_set_operation_maybe_expression
        S_query = 525,                           // query
        S_query_maybe_expression = 526,          // query_maybe_expression
        S_query_set_operation_prefix = 527,      // query_set_operation_prefix
        S_query_set_operation = 528,             // query_set_operation
        S_query_set_operation_prefix_maybe_expression = 529, // query_set_operation_prefix_maybe_expression
        S_query_set_operation_maybe_expression = 530, // query_set_operation_maybe_expression
        S_query_primary = 531,                   // query_primary
        S_query_primary_maybe_expression = 532,  // query_primary_maybe_expression
        S_select = 533,                          // select
        S_opt_with_anonymization = 534,          // opt_with_anonymization
        S_opt_select_as_clause = 535,            // opt_select_as_clause
        S_extra_identifier_in_hints_name = 536,  // extra_identifier_in_hints_name
        S_identifier_in_hints = 537,             // identifier_in_hints
        S_hint_entry = 538,                      // hint_entry
        S_hint_with_body_prefix = 539,           // hint_with_body_prefix
        S_hint_with_body = 540,                  // hint_with_body
        S_hint = 541,                            // hint
        S_opt_all_or_distinct = 542,             // opt_all_or_distinct
        S_select_list_prefix = 543,              // select_list_prefix
        S_select_list = 544,                     // select_list
        S_star_except_list_prefix = 545,         // star_except_list_prefix
        S_star_except_list = 546,                // star_except_list
        S_star_replace_item = 547,               // star_replace_item
        S_star_modifiers_with_replace_prefix = 548, // star_modifiers_with_replace_prefix
        S_star_modifiers = 549,                  // star_modifiers
        S_select_column = 550,                   // select_column
        S_opt_as_alias = 551,                    // opt_as_alias
        S_opt_as_alias_with_required_as = 552,   // opt_as_alias_with_required_as
        S_opt_as_or_into_alias = 553,            // opt_as_or_into_alias
        S_opt_as = 554,                          // opt_as
        S_opt_natural = 555,                     // opt_natural
        S_opt_outer = 556,                       // opt_outer
        S_int_literal_or_parameter = 557,        // int_literal_or_parameter
        S_cast_int_literal_or_parameter = 558,   // cast_int_literal_or_parameter
        S_possibly_cast_int_literal_or_parameter = 559, // possibly_cast_int_literal_or_parameter
        S_repeatable_clause = 560,               // repeatable_clause
        S_sample_size_value = 561,               // sample_size_value
        S_sample_size_unit = 562,                // sample_size_unit
        S_sample_size = 563,                     // sample_size
        S_opt_repeatable_clause = 564,           // opt_repeatable_clause
        S_opt_sample_clause_suffix = 565,        // opt_sample_clause_suffix
        S_sample_clause = 566,                   // sample_clause
        S_opt_sample_clause = 567,               // opt_sample_clause
        S_pivot_expression = 568,                // pivot_expression
        S_pivot_expression_list = 569,           // pivot_expression_list
        S_pivot_value = 570,                     // pivot_value
        S_pivot_value_list = 571,                // pivot_value_list
        S_pivot_clause = 572,                    // pivot_clause
        S_opt_as_string_or_integer = 573,        // opt_as_string_or_integer
        S_path_expression_list = 574,            // path_expression_list
        S_path_expression_list_with_opt_parens = 575, // path_expression_list_with_opt_parens
        S_path_expression_list_prefix = 576,     // path_expression_list_prefix
        S_path_expression_list_with_parens = 577, // path_expression_list_with_parens
        S_opt_path_expression_list_with_parens = 578, // opt_path_expression_list_with_parens
        S_unpivot_in_item = 579,                 // unpivot_in_item
        S_unpivot_in_item_list_prefix = 580,     // unpivot_in_item_list_prefix
        S_unpivot_in_item_list = 581,            // unpivot_in_item_list
        S_opt_unpivot_nulls_filter = 582,        // opt_unpivot_nulls_filter
        S_unpivot_clause = 583,                  // unpivot_clause
        S_opt_pivot_or_unpivot_clause_and_alias = 584, // opt_pivot_or_unpivot_clause_and_alias
        S_table_subquery = 585,                  // table_subquery
        S_table_clause = 586,                    // table_clause
        S_model_clause = 587,                    // model_clause
        S_connection_clause = 588,               // connection_clause
        S_descriptor_column = 589,               // descriptor_column
        S_descriptor_column_list = 590,          // descriptor_column_list
        S_descriptor_argument = 591,             // descriptor_argument
        S_tvf_argument = 592,                    // tvf_argument
        S_tvf_prefix_no_args = 593,              // tvf_prefix_no_args
        S_tvf_prefix = 594,                      // tvf_prefix
        S_tvf = 595,                             // tvf
        S_table_path_expression_base = 596,      // table_path_expression_base
        S_table_path_expression = 597,           // table_path_expression
        S_table_primary = 598,                   // table_primary
        S_opt_at_system_time = 599,              // opt_at_system_time
        S_on_clause = 600,                       // on_clause
        S_using_clause_prefix = 601,             // using_clause_prefix
        S_using_clause = 602,                    // using_clause
        S_opt_on_or_using_clause_list = 603,     // opt_on_or_using_clause_list
        S_on_or_using_clause_list = 604,         // on_or_using_clause_list
        S_on_or_using_clause = 605,              // on_or_using_clause
        S_join_type = 606,                       // join_type
        S_join_hint = 607,                       // join_hint
        S_join_input = 608,                      // join_input
        S_join = 609,                            // join
        S_from_clause_contents = 610,            // from_clause_contents
        S_opt_from_clause = 611,                 // opt_from_clause
        S_opt_clauses_following_from = 612,      // opt_clauses_following_from
        S_opt_clauses_following_where = 613,     // opt_clauses_following_where
        S_opt_clauses_following_group_by = 614,  // opt_clauses_following_group_by
        S_where_clause = 615,                    // where_clause
        S_opt_where_clause = 616,                // opt_where_clause
        S_rollup_list = 617,                     // rollup_list
        S_grouping_item = 618,                   // grouping_item
        S_group_by_clause_prefix = 619,          // group_by_clause_prefix
        S_group_by_clause = 620,                 // group_by_clause
        S_opt_group_by_clause = 621,             // opt_group_by_clause
        S_having_clause = 622,                   // having_clause
        S_opt_having_clause = 623,               // opt_having_clause
        S_window_definition = 624,               // window_definition
        S_window_clause_prefix = 625,            // window_clause_prefix
        S_opt_window_clause = 626,               // opt_window_clause
        S_opt_qualify_clause = 627,              // opt_qualify_clause
        S_qualify_clause_reserved = 628,         // qualify_clause_reserved
        S_opt_qualify_clause_reserved = 629,     // opt_qualify_clause_reserved
        S_qualify_clause_nonreserved = 630,      // qualify_clause_nonreserved
        S_opt_limit_offset_clause = 631,         // opt_limit_offset_clause
        S_opt_having_modifier = 632,             // opt_having_modifier
        S_opt_clamped_between_modifier = 633,    // opt_clamped_between_modifier
        S_opt_with_report_modifier = 634,        // opt_with_report_modifier
        S_opt_with_report_format = 635,          // opt_with_report_format
        S_opt_null_handling_modifier = 636,      // opt_null_handling_modifier
        S_with_clause_entry = 637,               // with_clause_entry
        S_with_clause = 638,                     // with_clause
        S_opt_with_connection_clause = 639,      // opt_with_connection_clause
        S_with_clause_with_trailing_comma = 640, // with_clause_with_trailing_comma
        S_opt_asc_or_desc = 641,                 // opt_asc_or_desc
        S_opt_null_order = 642,                  // opt_null_order
        S_string_literal_or_parameter = 643,     // string_literal_or_parameter
        S_collate_clause = 644,                  // collate_clause
        S_opt_collate_clause = 645,              // opt_collate_clause
        S_opt_default_collate_clause = 646,      // opt_default_collate_clause
        S_ordering_expression = 647,             // ordering_expression
        S_order_by_clause_prefix = 648,          // order_by_clause_prefix
        S_opt_order_by_clause = 649,             // opt_order_by_clause
        S_parenthesized_in_rhs = 650,            // parenthesized_in_rhs
        S_in_list_two_or_more_prefix = 651,      // in_list_two_or_more_prefix
        S_unnest_expression = 652,               // unnest_expression
        S_unnest_expression_with_opt_alias_and_offset = 653, // unnest_expression_with_opt_alias_and_offset
        S_comparative_operator = 654,            // comparative_operator
        S_additive_operator = 655,               // additive_operator
        S_multiplicative_operator = 656,         // multiplicative_operator
        S_shift_operator = 657,                  // shift_operator
        S_import_type = 658,                     // import_type
        S_any_some_all = 659,                    // any_some_all
        S_like_operator = 660,                   // like_operator
        S_between_operator = 661,                // between_operator
        S_distinct_operator = 662,               // distinct_operator
        S_in_operator = 663,                     // in_operator
        S_is_operator = 664,                     // is_operator
        S_unary_operator = 665,                  // unary_operator
        S_with_expression_variable = 666,        // with_expression_variable
        S_with_expression_variable_prefix = 667, // with_expression_variable_prefix
        S_with_expression = 668,                 // with_expression
        S_expression = 669,                      // expression
        S_path_expression = 670,                 // path_expression
        S_dashed_identifier = 671,               // dashed_identifier
        S_dashed_path_expression = 672,          // dashed_path_expression
        S_maybe_dashed_path_expression = 673,    // maybe_dashed_path_expression
        S_maybe_slashed_or_dashed_path_expression = 674, // maybe_slashed_or_dashed_path_expression
        S_slashed_identifier_separator = 675,    // slashed_identifier_separator
        S_identifier_or_integer = 676,           // identifier_or_integer
        S_slashed_identifier = 677,              // slashed_identifier
        S_slashed_path_expression = 678,         // slashed_path_expression
        S_array_constructor_prefix_no_expressions = 679, // array_constructor_prefix_no_expressions
        S_array_constructor_prefix = 680,        // array_constructor_prefix
        S_array_constructor = 681,               // array_constructor
        S_range_literal = 682,                   // range_literal
        S_date_or_time_literal_kind = 683,       // date_or_time_literal_kind
        S_date_or_time_literal = 684,            // date_or_time_literal
        S_interval_expression = 685,             // interval_expression
        S_parameter_expression = 686,            // parameter_expression
        S_named_parameter_expression = 687,      // named_parameter_expression
        S_type_name = 688,                       // type_name
        S_array_type = 689,                      // array_type
        S_struct_field = 690,                    // struct_field
        S_struct_type_prefix = 691,              // struct_type_prefix
        S_struct_type = 692,                     // struct_type
        S_raw_type = 693,                        // raw_type
        S_type_parameter = 694,                  // type_parameter
        S_type_parameters_prefix = 695,          // type_parameters_prefix
        S_opt_type_parameters = 696,             // opt_type_parameters
        S_type = 697,                            // type
        S_templated_parameter_kind = 698,        // templated_parameter_kind
        S_templated_parameter_type = 699,        // templated_parameter_type
        S_type_or_tvf_schema = 700,              // type_or_tvf_schema
        S_new_constructor_prefix_no_arg = 701,   // new_constructor_prefix_no_arg
        S_new_constructor_arg = 702,             // new_constructor_arg
        S_new_constructor_prefix = 703,          // new_constructor_prefix
        S_new_constructor = 704,                 // new_constructor
        S_braced_constructor_field_value = 705,  // braced_constructor_field_value
        S_braced_constructor_extension = 706,    // braced_constructor_extension
        S_braced_constructor_field = 707,        // braced_constructor_field
        S_braced_constructor_start = 708,        // braced_constructor_start
        S_braced_constructor_prefix = 709,       // braced_constructor_prefix
        S_braced_constructor = 710,              // braced_constructor
        S_braced_new_constructor = 711,          // braced_new_constructor
        S_case_no_value_expression_prefix = 712, // case_no_value_expression_prefix
        S_case_value_expression_prefix = 713,    // case_value_expression_prefix
        S_case_expression_prefix = 714,          // case_expression_prefix
        S_case_expression = 715,                 // case_expression
        S_opt_at_time_zone = 716,                // opt_at_time_zone
        S_opt_format = 717,                      // opt_format
        S_cast_expression = 718,                 // cast_expression
        S_extract_expression_base = 719,         // extract_expression_base
        S_extract_expression = 720,              // extract_expression
        S_replace_fields_arg = 721,              // replace_fields_arg
        S_replace_fields_prefix = 722,           // replace_fields_prefix
        S_replace_fields_expression = 723,       // replace_fields_expression
        S_function_name_from_keyword = 724,      // function_name_from_keyword
        S_function_call_expression_base = 725,   // function_call_expression_base
        S_function_call_argument = 726,          // function_call_argument
        S_named_argument = 727,                  // named_argument
        S_lambda_argument = 728,                 // lambda_argument
        S_lambda_argument_list = 729,            // lambda_argument_list
        S_function_call_expression_with_args_prefix = 730, // function_call_expression_with_args_prefix
        S_function_call_expression = 731,        // function_call_expression
        S_opt_identifier = 732,                  // opt_identifier
        S_partition_by_clause_prefix = 733,      // partition_by_clause_prefix
        S_opt_partition_by_clause = 734,         // opt_partition_by_clause
        S_partition_by_clause_prefix_no_hint = 735, // partition_by_clause_prefix_no_hint
        S_opt_partition_by_clause_no_hint = 736, // opt_partition_by_clause_no_hint
        S_cluster_by_clause_prefix_no_hint = 737, // cluster_by_clause_prefix_no_hint
        S_opt_cluster_by_clause_no_hint = 738,   // opt_cluster_by_clause_no_hint
        S_opt_ttl_clause = 739,                  // opt_ttl_clause
        S_preceding_or_following = 740,          // preceding_or_following
        S_window_frame_bound = 741,              // window_frame_bound
        S_frame_unit = 742,                      // frame_unit
        S_opt_window_frame_clause = 743,         // opt_window_frame_clause
        S_window_specification = 744,            // window_specification
        S_function_call_expression_with_clauses = 745, // function_call_expression_with_clauses
        S_opt_with_group_rows = 746,             // opt_with_group_rows
        S_opt_over_clause = 747,                 // opt_over_clause
        S_parenthesized_expression = 748,        // parenthesized_expression
        S_struct_constructor_prefix_with_keyword_no_arg = 749, // struct_constructor_prefix_with_keyword_no_arg
        S_struct_constructor_prefix_with_keyword = 750, // struct_constructor_prefix_with_keyword
        S_struct_constructor_arg = 751,          // struct_constructor_arg
        S_struct_constructor_prefix_without_keyword = 752, // struct_constructor_prefix_without_keyword
        S_struct_constructor = 753,              // struct_constructor
        S_expression_subquery = 754,             // expression_subquery
        S_bare_expression_subquery = 755,        // bare_expression_subquery
        S_null_literal = 756,                    // null_literal
        S_boolean_literal = 757,                 // boolean_literal
        S_string_literal = 758,                  // string_literal
        S_bytes_literal = 759,                   // bytes_literal
        S_integer_literal = 760,                 // integer_literal
        S_numeric_literal_prefix = 761,          // numeric_literal_prefix
        S_numeric_literal = 762,                 // numeric_literal
        S_bignumeric_literal_prefix = 763,       // bignumeric_literal_prefix
        S_bignumeric_literal = 764,              // bignumeric_literal
        S_json_literal = 765,                    // json_literal
        S_floating_point_literal = 766,          // floating_point_literal
        S_identifier = 767,                      // identifier
        S_label = 768,                           // label
        S_system_variable_expression = 769,      // system_variable_expression
        S_reserved_keyword_rule = 770,           // reserved_keyword_rule
        S_keyword_as_identifier = 771,           // keyword_as_identifier
        S_opt_or_replace = 772,                  // opt_or_replace
        S_opt_create_scope = 773,                // opt_create_scope
        S_opt_unique = 774,                      // opt_unique
        S_opt_search = 775,                      // opt_search
        S_describe_keyword = 776,                // describe_keyword
        S_opt_hint = 777,                        // opt_hint
        S_options_entry = 778,                   // options_entry
        S_expression_or_proto = 779,             // expression_or_proto
        S_options_list_prefix = 780,             // options_list_prefix
        S_options_list = 781,                    // options_list
        S_opt_options_list = 782,                // opt_options_list
        S_define_table_statement = 783,          // define_table_statement
        S_dml_statement = 784,                   // dml_statement
        S_opt_from_keyword = 785,                // opt_from_keyword
        S_opt_where_expression = 786,            // opt_where_expression
        S_opt_assert_rows_modified = 787,        // opt_assert_rows_modified
        S_opt_returning_clause = 788,            // opt_returning_clause
        S_unambiguous_or_ignore_replace_update = 789, // unambiguous_or_ignore_replace_update
        S_insert_statement_prefix = 790,         // insert_statement_prefix
        S_insert_statement = 791,                // insert_statement
        S_copy_data_source = 792,                // copy_data_source
        S_clone_data_source = 793,               // clone_data_source
        S_clone_data_source_list = 794,          // clone_data_source_list
        S_clone_data_statement = 795,            // clone_data_statement
        S_expression_or_default = 796,           // expression_or_default
        S_insert_values_row_prefix = 797,        // insert_values_row_prefix
        S_insert_values_row = 798,               // insert_values_row
        S_insert_values_list = 799,              // insert_values_list
        S_delete_statement = 800,                // delete_statement
        S_opt_with_offset_and_alias = 801,       // opt_with_offset_and_alias
        S_update_statement = 802,                // update_statement
        S_truncate_statement = 803,              // truncate_statement
        S_nested_dml_statement = 804,            // nested_dml_statement
        S_generalized_path_expression = 805,     // generalized_path_expression
        S_maybe_dashed_generalized_path_expression = 806, // maybe_dashed_generalized_path_expression
        S_generalized_extension_path = 807,      // generalized_extension_path
        S_update_set_value = 808,                // update_set_value
        S_update_item = 809,                     // update_item
        S_update_item_list = 810,                // update_item_list
        S_opt_into = 811,                        // opt_into
        S_opt_by_target = 812,                   // opt_by_target
        S_opt_and_expression = 813,              // opt_and_expression
        S_merge_insert_value_list_or_source_row = 814, // merge_insert_value_list_or_source_row
        S_merge_action = 815,                    // merge_action
        S_merge_when_clause = 816,               // merge_when_clause
        S_merge_when_clause_list = 817,          // merge_when_clause_list
        S_merge_source = 818,                    // merge_source
        S_merge_statement_prefix = 819,          // merge_statement_prefix
        S_merge_statement = 820,                 // merge_statement
        S_call_statement_with_args_prefix = 821, // call_statement_with_args_prefix
        S_call_statement = 822,                  // call_statement
        S_opt_function_parameters = 823,         // opt_function_parameters
        S_opt_if_exists = 824,                   // opt_if_exists
        S_opt_access = 825,                      // opt_access
        S_drop_all_row_access_policies_statement = 826, // drop_all_row_access_policies_statement
        S_on_path_expression = 827,              // on_path_expression
        S_opt_on_path_expression = 828,          // opt_on_path_expression
        S_opt_drop_mode = 829,                   // opt_drop_mode
        S_drop_statement = 830,                  // drop_statement
        S_non_empty_statement_list = 831,        // non_empty_statement_list
        S_unterminated_non_empty_statement_list = 832, // unterminated_non_empty_statement_list
        S_opt_execute_into_clause = 833,         // opt_execute_into_clause
        S_execute_using_argument = 834,          // execute_using_argument
        S_execute_using_argument_list = 835,     // execute_using_argument_list
        S_opt_execute_using_clause = 836,        // opt_execute_using_clause
        S_execute_immediate = 837,               // execute_immediate
        S_script = 838,                          // script
        S_statement_list = 839,                  // statement_list
        S_opt_else = 840,                        // opt_else
        S_elseif_clauses = 841,                  // elseif_clauses
        S_opt_elseif_clauses = 842,              // opt_elseif_clauses
        S_if_statement_unclosed = 843,           // if_statement_unclosed
        S_if_statement = 844,                    // if_statement
        S_when_then_clauses = 845,               // when_then_clauses
        S_opt_expression = 846,                  // opt_expression
        S_case_statement = 847,                  // case_statement
        S_unlabeled_begin_end_block = 848,       // unlabeled_begin_end_block
        S_begin_end_block = 849,                 // begin_end_block
        S_opt_exception_handler = 850,           // opt_exception_handler
        S_opt_default_expression = 851,          // opt_default_expression
        S_identifier_list = 852,                 // identifier_list
        S_variable_declaration = 853,            // variable_declaration
        S_unlabeled_loop_statement = 854,        // unlabeled_loop_statement
        S_loop_statement = 855,                  // loop_statement
        S_unlabeled_while_statement = 856,       // unlabeled_while_statement
        S_while_statement = 857,                 // while_statement
        S_until_clause = 858,                    // until_clause
        S_unlabeled_repeat_statement = 859,      // unlabeled_repeat_statement
        S_repeat_statement = 860,                // repeat_statement
        S_unlabeled_for_in_statement = 861,      // unlabeled_for_in_statement
        S_for_in_statement = 862,                // for_in_statement
        S_break_statement = 863,                 // break_statement
        S_continue_statement = 864,              // continue_statement
        S_return_statement = 865,                // return_statement
        S_raise_statement = 866,                 // raise_statement
        S_next_statement_kind = 867,             // next_statement_kind
        S_next_statement_kind_parenthesized_select = 868, // next_statement_kind_parenthesized_select
        S_next_statement_kind_table = 869,       // next_statement_kind_table
        S_next_statement_kind_create_table_opt_as_or_semicolon = 870, // next_statement_kind_create_table_opt_as_or_semicolon
        S_next_statement_kind_create_modifiers = 871, // next_statement_kind_create_modifiers
        S_next_statement_kind_without_hint = 872, // next_statement_kind_without_hint
        S_spanner_primary_key = 873,             // spanner_primary_key
        S_opt_spanner_index_interleave_clause = 874, // opt_spanner_index_interleave_clause
        S_opt_spanner_interleave_in_parent_clause = 875, // opt_spanner_interleave_in_parent_clause
        S_opt_spanner_table_options = 876,       // opt_spanner_table_options
        S_opt_spanner_null_filtered = 877,       // opt_spanner_null_filtered
        S_spanner_generated_or_default = 878,    // spanner_generated_or_default
        S_opt_spanner_generated_or_default = 879, // opt_spanner_generated_or_default
        S_opt_spanner_not_null_attribute = 880,  // opt_spanner_not_null_attribute
        S_spanner_alter_column_action = 881,     // spanner_alter_column_action
        S_spanner_set_on_delete_action = 882     // spanner_set_on_delete_action
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
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
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value (std::move (that.value))
        , location (std::move (that.location))
      {}
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

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return BisonParserImpl::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

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
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {};

    /// Build a parser object.
    BisonParserImpl (zetasql::parser::ZetaSqlFlexTokenizer* tokenizer_yyarg, zetasql::parser::BisonParser* parser_yyarg, zetasql::ASTNode** ast_node_result_yyarg, zetasql::parser::ASTStatementProperties*
                  ast_statement_properties_yyarg, std::string* error_message_yyarg, zetasql::ParseLocationPoint* error_location_yyarg, bool* move_error_location_past_whitespace_yyarg, int* statement_end_byte_offset_yyarg);
    virtual ~BisonParserImpl ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    BisonParserImpl (const BisonParserImpl&) = delete;
    /// Non copyable.
    BisonParserImpl& operator= (const BisonParserImpl&) = delete;
#endif

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

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);



    class context
    {
    public:
      context (const BisonParserImpl& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const BisonParserImpl& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    BisonParserImpl (const BisonParserImpl&);
    /// Non copyable.
    BisonParserImpl& operator= (const BisonParserImpl&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

    // YYPGOTONTERM-NUM.
    static const short yypgoto_[];

    // YYDEFGOTONTERM-NUM.
    static const short yydefgoto_[];

    // YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOSSTATE-NUM -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const short yystos_[];

    // YYR1YYN -- Symbol number of symbol that rule YYN derives.
    static const short yyr1_[];

    // YYR2YYN -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINEYYN -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
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

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

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

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
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
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
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
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
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
      yylast_ = 32299,     ///< Last index in yytable_.
      yynnts_ = 559,  ///< Number of nonterminal symbols.
      yyfinal_ = 440 ///< Termination state number.
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
#line 2200 "bazel-out/k8-fastbuild/bin/zetasql/parser/bison_parser.bison.h"





#endif // !YY_ZETASQL_BISON_PARSER_BAZEL_OUT_K8_FASTBUILD_BIN_ZETASQL_PARSER_BISON_PARSER_BISON_H_INCLUDED
