#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_ERROR_LOCATION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_ERROR_LOCATION_CC_PROTO_EXPORT_H

#include "zetasql/public/error_location.pb.h"
// include sources
#define schemas zetasql_public_error_location_cc_proto_schemas
#define file_default_instances zetasql_public_error_location_cc_proto_file_default_instances
#include "zetasql/public/error_location.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
