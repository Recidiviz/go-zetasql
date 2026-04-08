#ifndef INTERNAL_CCALL_GO_GOOGLESQL_SCRIPTING_SCRIPT_EXECUTOR_STATE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_SCRIPTING_SCRIPT_EXECUTOR_STATE_CC_PROTO_EXPORT_H

#include "googlesql/scripting/script_executor_state.pb.h"
// include sources
#define schemas googlesql_scripting_script_executor_state_cc_proto_schemas
#define file_default_instances googlesql_scripting_script_executor_state_cc_proto_file_default_instances
#include "googlesql/scripting/script_executor_state.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-googlesql/proto/function_cc_proto/export.inc"
#include "go-googlesql/scripting/variable_cc_proto/export.inc"
#include "go-googlesql/proto/script_exception_cc_proto/export.inc"

#endif
