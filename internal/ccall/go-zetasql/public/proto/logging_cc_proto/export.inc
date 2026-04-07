#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_PROTO_LOGGING_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_PROTO_LOGGING_CC_PROTO_EXPORT_H

#include "googlesql/public/proto/logging.pb.h"
// include sources
#define schemas googlesql_public_proto_logging_cc_proto_schemas
#define file_default_instances googlesql_public_proto_logging_cc_proto_file_default_instances
#include "googlesql/public/proto/logging.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
