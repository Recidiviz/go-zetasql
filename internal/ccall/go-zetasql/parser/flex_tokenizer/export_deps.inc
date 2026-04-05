#ifndef INTERNAL_CCALL_GO_ZETASQL_PARSER_FLEX_TOKENIZER_EXPORT_DEPS_H
#define INTERNAL_CCALL_GO_ZETASQL_PARSER_FLEX_TOKENIZER_EXPORT_DEPS_H

// Dependency-only slice of flex_tokenizer/export.inc (omit .cc) for parser
// amalgamation, which already includes flex_tokenizer.cc inline.
#include "go-zetasql/parser/bison_parser_generated_lib/export.inc"
#include "go-zetasql/parser/bison_parser_mode/export.inc"
#include "go-zetasql/parser/bison_token_codes/export.inc"
#include "go-zetasql/parser/flex_istream/export.inc"
#include "go-zetasql/parser/keywords/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/macros/token_with_location/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
