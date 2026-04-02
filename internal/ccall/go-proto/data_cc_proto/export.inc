#ifndef INTERNAL_CCALL_GO_PROTO_DATA_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_PROTO_DATA_CC_PROTO_EXPORT_H

#include "proto/data.pb.h"
// include sources
#define schemas proto_data_cc_proto_schemas
#define file_default_instances proto_data_cc_proto_file_default_instances
#include "proto/data.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-proto/confidence_interval_cc_proto/export.inc"
#include "go-protobuf/protobuf/export.inc"

#endif
