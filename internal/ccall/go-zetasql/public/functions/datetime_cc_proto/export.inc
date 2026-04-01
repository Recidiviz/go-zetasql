#ifndef ZETASQL_PUBLIC_FUNCTIONS_DATETIME_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_FUNCTIONS_DATETIME_CC_PROTO_EXPORT_H

#include "zetasql/public/functions/datetime.pb.h"
#define schemas go_zetasql_public_functions_datetime_cc_proto_datetime_schemas
#define file_default_instances go_zetasql_public_functions_datetime_cc_proto_datetime_file_default_instances
#include "zetasql/public/functions/datetime.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-protobuf/protobuf/export.inc"

#endif
