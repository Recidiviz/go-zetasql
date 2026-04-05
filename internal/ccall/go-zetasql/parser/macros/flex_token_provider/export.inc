#ifndef INTERNAL_CCALL_GO_ZETASQL_PARSER_MACROS_FLEX_TOKEN_PROVIDER_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PARSER_MACROS_FLEX_TOKEN_PROVIDER_EXPORT_H

#include "zetasql/parser/macros/flex_token_provider.h"
// include sources
#include "zetasql/parser/macros/flex_token_provider.cc"
// include dependencies
#include "go-zetasql/parser/macros/token_with_location/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/bison_parser_mode/export.inc"
#include "go-zetasql/parser/bison_token_codes/export.inc"
#ifdef ZETASQL_PARSER_AMALGAMATION_HAS_FLEX
#include "go-zetasql/parser/flex_tokenizer/export_deps.inc"
#else
#include "go-zetasql/parser/flex_tokenizer/export.inc"
#endif
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
