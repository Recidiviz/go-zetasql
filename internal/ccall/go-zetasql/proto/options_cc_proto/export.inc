#ifndef INTERNAL_CCALL_GO_ZETASQL_PROTO_OPTIONS_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PROTO_OPTIONS_CC_PROTO_EXPORT_H

#include "googlesql/proto/options.pb.h"
// include sources
#define schemas googlesql_proto_options_cc_proto_schemas
#define file_default_instances googlesql_proto_options_cc_proto_file_default_instances
#include "googlesql/proto/options.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"

#endif
