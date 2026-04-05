#ifndef INTERNAL_CCALL_GO_ZETASQL_PARSER_TOKEN_DISAMBIGUATOR_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PARSER_TOKEN_DISAMBIGUATOR_EXPORT_H

#include "zetasql/parser/token_disambiguator.h"
// include sources
#include "zetasql/parser/token_disambiguator.cc"
// include dependencies
#include "go-zetasql/parser/bison_parser_mode/export.inc"
#include "go-zetasql/parser/bison_token_codes/export.inc"
#ifdef ZETASQL_PARSER_AMALGAMATION_HAS_FLEX
#include "go-zetasql/parser/flex_tokenizer/export_deps.inc"
#else
#include "go-zetasql/parser/flex_tokenizer/export.inc"
#endif
#include "go-zetasql/base/arena/export.inc"
#include "go-zetasql/base/check/export.inc"
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/common/errors/export.inc"
#include "go-zetasql/parser/macros/flex_token_provider/export.inc"
#include "go-zetasql/parser/macros/macro_catalog/export.inc"
#include "go-zetasql/parser/macros/macro_expander/export.inc"
#include "go-zetasql/parser/macros/token_with_location/export.inc"
#include "go-zetasql/public/error_helpers/export.inc"
#include "go-zetasql/public/language_options/export.inc"
#include "go-zetasql/public/parse_location/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/log/log/export.inc"
#include "go-absl/memory/memory/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/status/statusor/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
