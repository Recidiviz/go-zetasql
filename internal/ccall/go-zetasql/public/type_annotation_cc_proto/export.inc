#ifndef ZETASQL_PUBLIC_TYPE_ANNOTATION_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_TYPE_ANNOTATION_CC_PROTO_EXPORT_H

#include "zetasql/public/type_annotation.pb.h"
#define schemas go_zetasql_public_type_annotation_cc_proto_type_annotation_schemas
#define file_default_instances go_zetasql_public_type_annotation_cc_proto_type_annotation_file_default_instances
#include "zetasql/public/type_annotation.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/public/proto/type_annotation_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
