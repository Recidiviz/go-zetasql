#ifndef INTERNAL_CCALL_GO_ZETASQL_PUBLIC_COLLATION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_PUBLIC_COLLATION_CC_PROTO_EXPORT_H

#include "googlesql/public/collation.pb.h"
// include sources
#define schemas googlesql_public_collation_cc_proto_schemas
#define file_default_instances googlesql_public_collation_cc_proto_file_default_instances
#include "googlesql/public/collation.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies

#endif
