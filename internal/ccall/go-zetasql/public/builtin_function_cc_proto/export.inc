#ifndef ZETASQL_PUBLIC_BUILTIN_FUNCTION_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_BUILTIN_FUNCTION_CC_PROTO_EXPORT_H

#include "zetasql/public/builtin_function.pb.h"
#define schemas go_zetasql_public_builtin_function_cc_proto_builtin_function_schemas
#define file_default_instances go_zetasql_public_builtin_function_cc_proto_builtin_function_file_default_instances
#include "zetasql/public/builtin_function.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-protobuf/protobuf/export.inc"

#endif
