#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_SIMPLE_TABLE_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_SIMPLE_TABLE_CC_PROTO_EXPORT_H

#include "googlesql/public/simple_table.pb.h"
// include sources
#define schemas googlesql_public_simple_table_cc_proto_schemas
#define file_default_instances googlesql_public_simple_table_cc_proto_file_default_instances
#include "googlesql/public/simple_table.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-zetasql/public/annotation_cc_proto/export.inc"
#include "go-zetasql/public/simple_value_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
