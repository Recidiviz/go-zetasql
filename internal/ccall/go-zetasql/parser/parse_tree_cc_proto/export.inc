#ifndef ZETASQL_PARSER_PARSE_TREE_CC_PROTO_EXPORT_H
#define ZETASQL_PARSER_PARSE_TREE_CC_PROTO_EXPORT_H

#include "zetasql/parser/parse_tree.pb.h"
#define schemas go_zetasql_parser_parse_tree_cc_proto_parse_tree_schemas
#define file_default_instances go_zetasql_parser_parse_tree_cc_proto_parse_tree_file_default_instances
#include "zetasql/parser/parse_tree.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/parser/ast_enums_cc_proto/export.inc"
#include "go-zetasql/public/parse_location_range_cc_proto/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
