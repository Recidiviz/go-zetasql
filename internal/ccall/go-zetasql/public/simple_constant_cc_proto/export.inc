#ifndef ZETASQL_PUBLIC_SIMPLE_CONSTANT_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_SIMPLE_CONSTANT_CC_PROTO_EXPORT_H

#include "zetasql/public/simple_constant.pb.h"
#define schemas go_zetasql_public_simple_constant_cc_proto_simple_constant_schemas
#define file_default_instances go_zetasql_public_simple_constant_cc_proto_simple_constant_file_default_instances
#include "zetasql/public/simple_constant.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/value_cc_proto/export.inc"

#include "go-protobuf/protobuf/export.inc"

#endif
