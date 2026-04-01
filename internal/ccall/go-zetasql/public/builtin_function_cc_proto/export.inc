#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_BUILTIN_FUNCTION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_BUILTIN_FUNCTION_CC_PROTO_EXPORT_H

#include "zetasql/public/builtin_function.pb.h"
// include sources
#define schemas zetasql_public_builtin_function_cc_proto_schemas
#define file_default_instances zetasql_public_builtin_function_cc_proto_file_default_instances
#include "zetasql/public/builtin_function.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
