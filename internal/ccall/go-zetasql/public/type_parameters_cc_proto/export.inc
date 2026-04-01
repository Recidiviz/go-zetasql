#ifndef ZETASQL_PUBLIC_TYPE_PARAMETERS_CC_PROTO_EXPORT_H
#define ZETASQL_PUBLIC_TYPE_PARAMETERS_CC_PROTO_EXPORT_H

#include "zetasql/public/type_parameters.pb.h"
#define schemas go_zetasql_public_type_parameters_cc_proto_type_parameters_schemas
#define file_default_instances go_zetasql_public_type_parameters_cc_proto_type_parameters_file_default_instances
#include "zetasql/public/type_parameters.pb.cc"
#undef file_default_instances
#undef schemas

#include "go-zetasql/public/simple_value_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
