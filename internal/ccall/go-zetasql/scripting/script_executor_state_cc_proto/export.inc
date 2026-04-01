#ifndef ZETASQL_SCRIPTING_SCRIPT_EXECUTOR_STATE_CC_PROTO_EXPORT_H
#define ZETASQL_SCRIPTING_SCRIPT_EXECUTOR_STATE_CC_PROTO_EXPORT_H

#include "zetasql/scripting/script_executor_state.pb.h"
#define schemas go_zetasql_scripting_script_executor_state_cc_proto_script_executor_state_schemas
#define file_default_instances go_zetasql_scripting_script_executor_state_cc_proto_script_executor_state_file_default_instances
#include "zetasql/scripting/script_executor_state.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/proto/function_cc_proto/export.inc"
#include "go-zetasql/scripting/variable_cc_proto/export.inc"
#include "go-zetasql/scripting/script_exception_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
