#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_NORMALIZE_MODE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_NORMALIZE_MODE_CC_PROTO_EXPORT_H

#include "googlesql/public/functions/normalize_mode.pb.h"
// include sources
#define schemas googlesql_public_functions_normalize_mode_cc_proto_schemas
#define file_default_instances googlesql_public_functions_normalize_mode_cc_proto_file_default_instances
#include "googlesql/public/functions/normalize_mode.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
