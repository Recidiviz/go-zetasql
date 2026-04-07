#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TYPE_PARAMETERS_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TYPE_PARAMETERS_CC_PROTO_EXPORT_H

#include "googlesql/public/type_parameters.pb.h"
// include sources
#define schemas googlesql_public_type_parameters_cc_proto_schemas
#define file_default_instances googlesql_public_type_parameters_cc_proto_file_default_instances
#include "googlesql/public/type_parameters.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/public/simple_value_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
