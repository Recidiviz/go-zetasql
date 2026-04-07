#ifndef INTERNAL_CCALL_GO_ZETASQL_RESOLVED_AST_RESOLVED_NODE_KIND_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_RESOLVED_AST_RESOLVED_NODE_KIND_CC_PROTO_EXPORT_H

#include "googlesql/resolved_ast/resolved_node_kind.pb.h"
// include sources
#define schemas googlesql_resolved_ast_resolved_node_kind_cc_proto_schemas
#define file_default_instances googlesql_resolved_ast_resolved_node_kind_cc_proto_file_default_instances
#include "googlesql/resolved_ast/resolved_node_kind.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
