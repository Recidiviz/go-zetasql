#ifndef INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_TYPE_ANNOTATION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_PUBLIC_TYPE_ANNOTATION_CC_PROTO_EXPORT_H

#include "googlesql/public/type_annotation.pb.h"
// include sources
#define schemas googlesql_public_type_annotation_cc_proto_schemas
#define file_default_instances googlesql_public_type_annotation_cc_proto_file_default_instances
#include "googlesql/public/type_annotation.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-googlesql/public/proto/type_annotation_cc_proto/export.inc"

#endif
