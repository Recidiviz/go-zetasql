#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_NUMERIC_PARSER_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_NUMERIC_PARSER_EXPORT_H

#include "googlesql/public/numeric_parser.h"
// include sources
#define PowersAsc googlesql_public_numeric_parser_googlesql_public_numeric_parser_PowersAsc
#include "googlesql/public/numeric_parser.cc"
#undef PowersAsc
// include dependencies
#include "go-googlesql/public/numeric_constants/export.inc"
#include "go-googlesql/base/status/export.inc"
#include "go-googlesql/common/multiprecision_int/export.inc"
#include "go-absl/base/core_headers/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
