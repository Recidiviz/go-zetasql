#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TYPE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TYPE_CC_PROTO_EXPORT_H

#include "zetasql/public/type.pb.h"
// include sources
#define schemas zetasql_public_type_cc_proto_schemas
#define file_default_instances zetasql_public_type_cc_proto_file_default_instances
#include "zetasql/public/type.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
