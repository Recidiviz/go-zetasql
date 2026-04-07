#ifndef INTERNAL_CCALL_GO_ZETASQL_RESOLVED_AST_SERIALIZATION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_RESOLVED_AST_SERIALIZATION_CC_PROTO_EXPORT_H

#include "googlesql/resolved_ast/serialization.pb.h"
// include sources
#define schemas googlesql_resolved_ast_serialization_cc_proto_schemas
#define file_default_instances googlesql_resolved_ast_serialization_cc_proto_file_default_instances
#include "googlesql/resolved_ast/serialization.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value_cc_proto/export.inc"
#include "go-zetasql/public/annotation_cc_proto/export.inc"
#include "go-zetasql/public/parse_location_range_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
