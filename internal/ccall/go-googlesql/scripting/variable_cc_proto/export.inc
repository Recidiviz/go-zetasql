#ifndef INTERNAL_CCALL_GO_GOOGLESQL_SCRIPTING_VARIABLE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_SCRIPTING_VARIABLE_CC_PROTO_EXPORT_H

#include "googlesql/scripting/variable.pb.h"
// include sources
#define schemas googlesql_scripting_variable_cc_proto_googlesql_scripting_variable_pb_schemas
#define file_default_instances googlesql_scripting_variable_cc_proto_googlesql_scripting_variable_pb_file_default_instances
#include "googlesql/scripting/variable.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-googlesql/public/type_cc_proto/export.inc"
#include "go-googlesql/public/value_cc_proto/export.inc"
#include "go-googlesql/public/type_parameters_cc_proto/export.inc"

#endif
