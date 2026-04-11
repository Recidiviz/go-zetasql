#ifndef INTERNAL_CCALL_GO_GOOGLESQL_RESOLVED_AST_RESOLVED_AST_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_RESOLVED_AST_RESOLVED_AST_CC_PROTO_EXPORT_H

#include "googlesql/resolved_ast/resolved_ast.pb.h"
// include sources
#define schemas googlesql_resolved_ast_resolved_ast_cc_proto_googlesql_resolved_ast_resolved_ast_pb_schemas
#define file_default_instances googlesql_resolved_ast_resolved_ast_cc_proto_googlesql_resolved_ast_resolved_ast_pb_file_default_instances
#include "googlesql/resolved_ast/resolved_ast.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-googlesql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-googlesql/public/type_parameters_cc_proto/export.inc"
#include "go-googlesql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-googlesql/proto/function_cc_proto/export.inc"

#endif
