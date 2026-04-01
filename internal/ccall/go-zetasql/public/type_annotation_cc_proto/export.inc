#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TYPE_ANNOTATION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_TYPE_ANNOTATION_CC_PROTO_EXPORT_H

#include "zetasql/public/type_annotation.pb.h"
// include sources
#define schemas zetasql_public_type_annotation_cc_proto_schemas
#define file_default_instances zetasql_public_type_annotation_cc_proto_file_default_instances
#include "zetasql/public/type_annotation.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
