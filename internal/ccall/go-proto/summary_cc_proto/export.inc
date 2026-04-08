#ifndef INTERNAL_CCALL_GO_PROTO_SUMMARY_CC_PROTO_EXPORT_H
#define INTERNAL_CCALL_GO_PROTO_SUMMARY_CC_PROTO_EXPORT_H

#include "proto/summary.pb.h"
// include sources
#define schemas proto_summary_cc_proto_schemas
#define file_default_instances proto_summary_cc_proto_file_default_instances
#include "proto/summary.pb.cc"
#undef file_default_instances
#undef schemas
// include dependencies
#include "go-proto/data_cc_proto/export.inc"

#endif
