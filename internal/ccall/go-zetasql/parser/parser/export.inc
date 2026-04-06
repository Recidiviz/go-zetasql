#ifndef INTERNAL_CCALL_GO_ZETASQL_PARSER_PARSER_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PARSER_PARSER_EXPORT_H

#include "zetasql/parser/ast_node.h"
#include "zetasql/parser/ast_node_kind.h"
#include "zetasql/parser/parse_tree.h"
#include "zetasql/parser/parse_tree_decls.h"
#include "zetasql/parser/parse_tree_errors.h"
#include "zetasql/parser/parse_tree_visitor.h"
#include "zetasql/parser/parser.h"
#include "zetasql/parser/parser_runtime_info.h"
#include "zetasql/parser/statement_properties.h"
#include "zetasql/parser/unparser.h"
#include "zetasql/parser/visit_result.h"
// include sources
#include "zetasql/parser/ast_node_internal.h"
#include "zetasql/parser/flex_tokenizer.h"
#include "zetasql/parser/bison_parser.bison.cc"
// bison_parser.bison.cc defines yylex as a macro; must clear before any flex_tokenizer / FlexLexer.h.
#undef yylex
#include "zetasql/parser/join_processor.cc"
// TextMapper (Bazel :tm_parser). tm_lexer.cc is compiled via flex_tokenizer/export.inc → tm_lexer/export.inc.
#include "zetasql/parser/textmapper_lexer_adapter.cc"
// parser_internal.h is include-guarded; the first include came from bison_parser.bison.cc with
// PARSER_LA_IS_EMPTY() => yyla.empty(). tm_parser.cc uses Textmapper lookahead (`next_symbol_`).
#undef PARSER_LA_IS_EMPTY
#undef TM_PARSER_LA_IS_EMPTY
#define PARSER_LA_IS_EMPTY() (next_symbol_.symbol == noToken)
#define TM_PARSER_LA_IS_EMPTY() (next_symbol_.symbol == noToken)
#undef ABORT_CHECK
#define ABORT_CHECK(location, condition, msg)                   \
  do {                                                          \
    if (ABSL_PREDICT_FALSE(!(condition))) {                     \
      (void)MakeSyntaxError(                                    \
          location, absl::StrCat("Internal Error: ", (msg)));     \
      YYABORT;                                                  \
    }                                                           \
  } while (0)
#undef OVERRIDE_CURRENT_TOKEN_LOOKBACK
#define OVERRIDE_CURRENT_TOKEN_LOOKBACK(location, new_token_kind)          \
  ABORT_CHECK(location, PARSER_LA_IS_EMPTY(),                              \
              "The parser lookahead buffer must be empty to override the " \
              "current token");                                            \
  absl::Status s = OverrideCurrentTokenLookback(                           \
      tokenizer, zetasql::TokenKinds::new_token_kind);                   \
  ABORT_CHECK(location, s.ok(), s.ToString());
#undef TM_OVERRIDE_CURRENT_TOKEN_LOOKBACK
#define TM_OVERRIDE_CURRENT_TOKEN_LOOKBACK(location, new_token_kind)       \
  ABORT_CHECK(location, TM_PARSER_LA_IS_EMPTY(),                           \
              "The parser lookahead buffer must be empty to override the " \
              "current token");                                            \
  absl::Status s_tm_override = OverrideCurrentTokenLookback(               \
      tokenizer, zetasql::TokenKinds::new_token_kind);                     \
  ABORT_CHECK(location, s_tm_override.ok(), s_tm_override.ToString());
#include "zetasql/parser/tm_parser.cc"
// utf8_validity.cc: single copy via blank-import utf8_range_link (see go-protobuf/protobuf/export.inc).
// Flex-generated yyalloc helpers use global Legacyalloc names; root analyzer and parser/ CGO packages
// both amalgamate flex_tokenizer.flex.cc — prefix so the final link does not duplicate symbols.
#ifdef ZETASQL_GO_FLEX_LEGACY_IN_PARSER_PKG
#define Legacyalloc zetasql_go_parser_pkg_Legacyalloc
#define Legacyrealloc zetasql_go_parser_pkg_Legacyrealloc
#define Legacyfree zetasql_go_parser_pkg_Legacyfree
#else
#define Legacyalloc zetasql_go_root_Legacyalloc
#define Legacyrealloc zetasql_go_root_Legacyrealloc
#define Legacyfree zetasql_go_root_Legacyfree
#endif
// ICU may define COLON as a macro; it breaks `Tokens::COLON` in flex rules.
#undef COLON
#include "zetasql/parser/flex_tokenizer.flex.cc"
#include "zetasql/parser/bison_parser.cc"
#include "zetasql/parser/flex_tokenizer.cc"
#include "zetasql/parser/bison_parser.h"
#include "zetasql/parser/parser.cc"
#include "zetasql/parser/unparser.cc"
// include dependencies
#include "go-zetasql/parser/ast_enums_cc_proto/export.inc"
#include "go-zetasql/parser/bison_parser_generated_lib/export.inc"
#include "go-zetasql/parser/bison_parser_mode/export.inc"
#include "go-zetasql/parser/flex_istream/export.inc"
#include "go-zetasql/parser/keywords/export.inc"
#include "go-zetasql/parser/lookahead_transformer/export.inc"
#include "go-zetasql/parser/parse_tree/export.inc"
#include "go-zetasql/parser/token/export.inc"
#include "go-zetasql/parser/token_codes/export.inc"
#include "go-zetasql/parser/token_with_location/export.inc"
#include "go-zetasql/base/base/export.inc"
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/arena_allocator/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/map_util/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/base/strings/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/common/thread_stack/export.inc"
#include "go-zetasql/common/timer_util/export.inc"
#include "go-zetasql/common/utf_util/export.inc"
#include "go-zetasql/parser/macros/macro_catalog/export.inc"
#include "go-zetasql/parser/macros/macro_expander/export.inc"
#include "go-zetasql/proto/internal_error_location_cc_proto/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-zetasql/public/id_string/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-zetasql/public/parse_resume_location/export.inc"
#include "go-zetasql/public/strings/export.inc"
#include "go-zetasql/public/type/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/proto/logging_cc_proto/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/flat_hash_map/export.inc"
#include "go-absl/container/inlined_vector/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/log/log/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/time/time/export.inc"
#include "go-absl/types/span/export.inc"
#include "go-absl/types/variant/export.inc"
#include "go-re2/re2/export.inc"

#endif
