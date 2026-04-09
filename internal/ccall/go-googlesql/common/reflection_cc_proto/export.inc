#ifndef INTERNAL_CCALL_GO_GOOGLESQL_COMMON_REFLECTION_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_COMMON_REFLECTION_CC_PROTO_EXPORT_H

#include "googlesql/common/reflection.pb.h"
// include sources
#define schemas googlesql_common_reflection_schemas
#define file_default_instances googlesql_common_reflection_file_default_instances
#include "googlesql/common/reflection.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies

#endif
