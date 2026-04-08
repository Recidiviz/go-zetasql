#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_BUILTIN_FUNCTION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_BUILTIN_FUNCTION_CC_PROTO_EXPORT_H

#include "googlesql/public/builtin_function.pb.h"
// include sources
#define schemas googlesql_public_builtin_function_cc_proto_schemas
#define file_default_instances googlesql_public_builtin_function_cc_proto_file_default_instances
#include "googlesql/public/builtin_function.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies

#endif
