#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PROTO_SIMPLE_CATALOG_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PROTO_SIMPLE_CATALOG_CC_PROTO_EXPORT_H

#include "googlesql/proto/simple_catalog.pb.h"
// include sources
#define schemas googlesql_proto_simple_catalog_cc_proto_googlesql_proto_simple_catalog_pb_schemas
#define file_default_instances googlesql_proto_simple_catalog_cc_proto_googlesql_proto_simple_catalog_pb_file_default_instances
#include "googlesql/proto/simple_catalog.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-googlesql/public/type_cc_proto/export.inc"
#include "go-googlesql/public/options_cc_proto/export.inc"
#include "go-googlesql/public/function_cc_proto/export.inc"
#include "go-googlesql/public/simple_table_cc_proto/export.inc"
#include "go-googlesql/public/simple_constant_cc_proto/export.inc"
#include "go-googlesql/public/simple_value_cc_proto/export.inc"
#include "go-googlesql/public/value_cc_proto/export.inc"
#include "go-googlesql/public/parse_resume_location_cc_proto/export.inc"
#include "go-googlesql/public/annotation_cc_proto/export.inc"
#include "go-googlesql/public/deprecation_warning_cc_proto/export.inc"
#include "go-googlesql/public/error_location_cc_proto/export.inc"
#include "go-googlesql/public/parse_location_range_cc_proto/export.inc"
#include "go-googlesql/public/builtin_function_cc_proto/export.inc"
#include "go-googlesql/resolved_ast/serialization_cc_proto/export.inc"
#include "go-googlesql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-googlesql/proto/options_cc_proto/export.inc"
#include "go-googlesql/proto/function_cc_proto/export.inc"

#endif
