#ifndef INTERNAL_CCALL_GO_ZETASQL_PARSER_AST_ENUMS_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PARSER_AST_ENUMS_CC_PROTO_EXPORT_H

#include "zetasql/parser/ast_enums.pb.h"
// include sources
#define schemas zetasql_parser_ast_enums_cc_proto_schemas
#define file_default_instances zetasql_parser_ast_enums_cc_proto_file_default_instances
#include "zetasql/parser/ast_enums.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
