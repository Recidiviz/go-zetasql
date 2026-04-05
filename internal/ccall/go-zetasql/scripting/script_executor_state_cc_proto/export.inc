#ifndef INTERNAL_CCALL_GO_ZETASQL_SCRIPTING_SCRIPT_EXECUTOR_STATE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_SCRIPTING_SCRIPT_EXECUTOR_STATE_CC_PROTO_EXPORT_H

#include "zetasql/scripting/script_executor_state.pb.h"
// include sources
#define schemas zetasql_scripting_script_executor_state_cc_proto_schemas
#define file_default_instances zetasql_scripting_script_executor_state_cc_proto_file_default_instances
#include "zetasql/scripting/script_executor_state.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-zetasql/scripting/variable_cc_proto/export.inc"
#include "go-zetasql/proto/script_exception_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
