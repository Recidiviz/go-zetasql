#ifndef ZETASQL_PROTO_OPTIONS_CC_PROTO_EXPORT_H
#define ZETASQL_PROTO_OPTIONS_CC_PROTO_EXPORT_H

#include "zetasql/proto/options.pb.h"
#define schemas go_zetasql_proto_options_cc_proto_options_schemas
#define file_default_instances go_zetasql_proto_options_cc_proto_options_file_default_instances
#include "zetasql/proto/options.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/builtin_function_cc_proto/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
