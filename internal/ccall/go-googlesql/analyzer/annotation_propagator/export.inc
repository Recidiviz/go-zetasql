#ifndef INTERNAL_CCALL_GO_GOOGLESQL_ANALYZER_ANNOTATION_PROPAGATOR_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_ANALYZER_ANNOTATION_PROPAGATOR_EXPORT_H

#include "googlesql/analyzer/annotation_propagator.h"
// include sources
#define CheckAndPropagateAnnotationsImpl googlesql_analyzer_annotation_propagator_annot_prop_CheckAndPropagateAnnotationsImpl
#include "googlesql/analyzer/annotation_propagator.cc"
#undef CheckAndPropagateAnnotationsImpl
// include dependencies
#include "go-googlesql/base/check/export.inc"
#include "go-googlesql/base/ret_check/export.inc"
#include "go-googlesql/base/status/export.inc"
#include "go-googlesql/parser/parse_tree/export.inc"
#include "go-googlesql/public/analyzer_options/export.inc"
#include "go-googlesql/public/function_headers/export.inc"
#include "go-googlesql/public/options_cc_proto/export.inc"
#include "go-googlesql/public/sql_function/export.inc"
#include "go-googlesql/public/templated_sql_function/export.inc"
#include "go-googlesql/public/annotation/collation/export.inc"
#include "go-googlesql/public/types/types/export.inc"
#include "go-googlesql/resolved_ast/resolved_ast/export.inc"
#include "go-googlesql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/status/status/export.inc"

#endif
