#ifndef ZETASQL_SCRIPTING_VARIABLE_CC_PROTO_EXPORT_H
#define ZETASQL_SCRIPTING_VARIABLE_CC_PROTO_EXPORT_H

#include "zetasql/scripting/variable.pb.h"
#define schemas go_zetasql_scripting_variable_cc_proto_variable_schemas
#define file_default_instances go_zetasql_scripting_variable_cc_proto_variable_file_default_instances
#include "zetasql/scripting/variable.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value_cc_proto/export.inc"
#include "go-zetasql/public/type_parameters_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
