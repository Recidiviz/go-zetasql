#ifndef ZETASQL_PUBLIC_COLLATION_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_COLLATION_CC_PROTO_EXPORT_H

#include "zetasql/public/collation.pb.h"
#define schemas go_zetasql_public_collation_cc_proto_collation_schemas
#define file_default_instances go_zetasql_public_collation_cc_proto_collation_file_default_instances
#include "zetasql/public/collation.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-protobuf/protobuf/export.inc"

#endif
