#ifndef INTERNAL_CCALL_GO_ZETASQL_SCRIPTING_VARIABLE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_SCRIPTING_VARIABLE_CC_PROTO_EXPORT_H

#include "googlesql/scripting/variable.pb.h"
// include sources
#define schemas googlesql_scripting_variable_cc_proto_schemas
#define file_default_instances googlesql_scripting_variable_cc_proto_file_default_instances
#include "googlesql/scripting/variable.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value_cc_proto/export.inc"
#include "go-zetasql/public/type_parameters_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
