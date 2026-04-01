#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_VALUE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_VALUE_CC_PROTO_EXPORT_H

#include "zetasql/public/value.pb.h"
// include sources
#define schemas zetasql_public_value_cc_proto_schemas
#define file_default_instances zetasql_public_value_cc_proto_file_default_instances
#include "zetasql/public/value.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
