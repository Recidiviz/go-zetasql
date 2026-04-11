#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PARSER_FLEX_TOKENIZER_EXPORT_DEPS_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PARSER_FLEX_TOKENIZER_EXPORT_DEPS_H

// Dependency-only slice of flex_tokenizer/export.inc (omit .cc) for parser
// amalgamation, which already includes flex_tokenizer.cc inline.
#include "go-googlesql/parser/bison_parser_generated_lib/export.inc"
#include "go-googlesql/parser/bison_parser_mode/export.inc"
#include "go-googlesql/parser/bison_token_codes/export.inc"
#include "go-googlesql/parser/flex_istream/export.inc"
#include "go-googlesql/parser/keywords/export.inc"
#include "go-googlesql/base/check/export.inc"
#include "go-googlesql/base/status/export.inc"
#include "go-googlesql/common/errors/export.inc"
#include "go-googlesql/parser/token_with_location/export.inc"
#include "go-googlesql/public/language_options/export.inc"
#include "go-googlesql/public/parse_location/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
