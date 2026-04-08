#ifndef INTERNAL_CCALL_GO_ZETASQL_PARSER_PARSE_TREE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PARSER_PARSE_TREE_CC_PROTO_EXPORT_H

#include "googlesql/parser/parse_tree.pb.h"
// include sources
#define schemas googlesql_parser_parse_tree_cc_proto_schemas
#define file_default_instances googlesql_parser_parse_tree_cc_proto_file_default_instances
#include "googlesql/parser/parse_tree.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/parser/ast_enums_cc_proto/export.inc"
#include "go-zetasql/public/parse_location_range_cc_proto/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"

#endif
