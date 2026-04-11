#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PROTO_FUNCTION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PROTO_FUNCTION_CC_PROTO_EXPORT_H

#include "googlesql/proto/function.pb.h"
// include sources
#define schemas googlesql_proto_function_cc_proto_googlesql_proto_function_pb_schemas
#define file_default_instances googlesql_proto_function_cc_proto_googlesql_proto_function_pb_file_default_instances
#include "googlesql/proto/function.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-googlesql/public/type_cc_proto/export.inc"
#include "go-googlesql/public/value_cc_proto/export.inc"
#include "go-googlesql/public/options_cc_proto/export.inc"
#include "go-googlesql/public/simple_table_cc_proto/export.inc"
#include "go-googlesql/public/simple_value_cc_proto/export.inc"
#include "go-googlesql/public/function_cc_proto/export.inc"
#include "go-googlesql/public/builtin_function_cc_proto/export.inc"
#include "go-googlesql/public/parse_resume_location_cc_proto/export.inc"
#include "go-googlesql/public/annotation_cc_proto/export.inc"
#include "go-googlesql/public/deprecation_warning_cc_proto/export.inc"
#include "go-googlesql/public/error_location_cc_proto/export.inc"
#include "go-googlesql/public/parse_location_range_cc_proto/export.inc"
#include "go-googlesql/resolved_ast/serialization_cc_proto/export.inc"

#endif
