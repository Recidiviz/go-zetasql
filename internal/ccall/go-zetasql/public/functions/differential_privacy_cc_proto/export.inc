#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_DIFFERENTIAL_PRIVACY_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_DIFFERENTIAL_PRIVACY_CC_PROTO_EXPORT_H

#include "zetasql/public/functions/differential_privacy.pb.h"
// include sources
#define schemas zetasql_public_functions_differential_privacy_cc_proto_schemas
#define file_default_instances zetasql_public_functions_differential_privacy_cc_proto_file_default_instances
#include "zetasql/public/functions/differential_privacy.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/proto/anon_output_with_report_cc_proto/export.inc"
#include "go-zetasql/public/type_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
