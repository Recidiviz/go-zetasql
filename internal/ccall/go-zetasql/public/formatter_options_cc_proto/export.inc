#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FORMATTER_OPTIONS_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_FORMATTER_OPTIONS_CC_PROTO_EXPORT_H

#include "zetasql/public/formatter_options.pb.h"
// include sources
#define schemas zetasql_public_formatter_options_cc_proto_schemas
#define file_default_instances zetasql_public_formatter_options_cc_proto_file_default_instances
#include "zetasql/public/formatter_options.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-protobuf/protobuf/export.inc"

#endif
