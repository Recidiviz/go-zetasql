#ifndef ZETASQL_PUBLIC_TYPE_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_TYPE_CC_PROTO_EXPORT_H

#include "zetasql/public/type.pb.h"
#define schemas go_zetasql_public_type_cc_proto_type_schemas
#define file_default_instances go_zetasql_public_type_cc_proto_type_file_default_instances
#include "zetasql/public/type.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-protobuf/protobuf/export.inc"

#endif
