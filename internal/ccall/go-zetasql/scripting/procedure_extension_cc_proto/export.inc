#ifndef INTERNAL_CCALL_GO_ZETASQL_SCRIPTING_PROCEDURE_EXTENSION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_SCRIPTING_PROCEDURE_EXTENSION_CC_PROTO_EXPORT_H

#include "zetasql/scripting/procedure_extension.pb.h"
// include sources
#define schemas zetasql_scripting_procedure_extension_cc_proto_schemas
#define file_default_instances zetasql_scripting_procedure_extension_cc_proto_file_default_instances
#include "zetasql/scripting/procedure_extension.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
