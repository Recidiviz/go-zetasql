#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_UNSUPPORTED_FIELDS_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FUNCTIONS_UNSUPPORTED_FIELDS_CC_PROTO_EXPORT_H

#include "zetasql/public/functions/unsupported_fields.pb.h"
// include sources
// Avoid duplicate `schemas` / `file_default_instances` when amalgamated with
// simple_token_list.pb.cc in the same translation unit.
#define schemas zetasql_public_functions_unsupported_fields_cc_proto_schemas
#define file_default_instances \
  zetasql_public_functions_unsupported_fields_cc_proto_file_default_instances
#include "zetasql/public/functions/unsupported_fields.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
