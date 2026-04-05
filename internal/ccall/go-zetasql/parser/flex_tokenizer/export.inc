#ifndef INTERNAL_CCALL_GO_ZETASQL_PARSER_FLEX_TOKENIZER_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PARSER_FLEX_TOKENIZER_EXPORT_H

#include "zetasql/parser/flex_tokenizer.h"
// include sources
// flex_tokenizer.cc / flex_tokenizer.flex.cc are amalgamated in parser/bind.cc (parser prelude).
// include dependencies
#include "go-zetasql/parser/bison_token_codes/export.inc"
#include "go-zetasql/parser/flex_istream/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-absl/flags/flag/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"
#include "go-absl/strings/str_format/export.inc"

#endif
