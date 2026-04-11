#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_ANNOTATION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_ANNOTATION_CC_PROTO_EXPORT_H

#include "googlesql/public/annotation.pb.h"
// include sources
#define schemas googlesql_public_annotation_cc_proto_googlesql_public_annotation_pb_schemas
#define file_default_instances googlesql_public_annotation_cc_proto_googlesql_public_annotation_pb_file_default_instances
#include "googlesql/public/annotation.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-googlesql/public/simple_value_cc_proto/export.inc"

#endif
