#ifndef ZETASQL_PUBLIC_SIMPLE_TABLE_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_SIMPLE_TABLE_CC_PROTO_EXPORT_H

#include "zetasql/public/simple_table.pb.h"
#define schemas go_zetasql_public_simple_table_cc_proto_simple_table_schemas
#define file_default_instances go_zetasql_public_simple_table_cc_proto_simple_table_file_default_instances
#include "zetasql/public/simple_table.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/annotation_cc_proto/export.inc"
#include "go-zetasql/public/simple_value_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
