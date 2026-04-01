#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_DEPRECATION_WARNING_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_DEPRECATION_WARNING_CC_PROTO_EXPORT_H

#include "zetasql/public/deprecation_warning.pb.h"
// include sources
#define schemas zetasql_public_deprecation_warning_cc_proto_schemas
#define file_default_instances zetasql_public_deprecation_warning_cc_proto_file_default_instances
#include "zetasql/public/deprecation_warning.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-zetasql/public/error_location_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
