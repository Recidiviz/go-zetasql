#ifndef ZETASQL_PUBLIC_SIMPLE_VALUE_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_SIMPLE_VALUE_CC_PROTO_EXPORT_H

#include "zetasql/public/simple_value.pb.h"
#define schemas go_zetasql_public_simple_value_cc_proto_simple_value_schemas
#define file_default_instances go_zetasql_public_simple_value_cc_proto_simple_value_file_default_instances
#include "zetasql/public/simple_value.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-protobuf/protobuf/export.inc"

#endif
