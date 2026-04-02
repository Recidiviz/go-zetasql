#ifndef INTERNAL_CCALL_GO_ZETASQL_RESOLVED_AST_RESOLVED_AST_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_RESOLVED_AST_RESOLVED_AST_CC_PROTO_EXPORT_H

#include "zetasql/resolved_ast/resolved_ast.pb.h"
// include sources
#define schemas zetasql_resolved_ast_resolved_ast_cc_proto_schemas
#define file_default_instances zetasql_resolved_ast_resolved_ast_cc_proto_file_default_instances
#include "zetasql/resolved_ast/resolved_ast.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/resolved_ast/resolved_ast_enums_cc_proto/export.inc"
#include "go-zetasql/public/type_parameters_cc_proto/export.inc"
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
