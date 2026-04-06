#ifndef INTERNAL_CCALL_GO_ZETASQL_ANALYZER_ANNOTATION_PROPAGATOR_EXPORT_H
#define INTERNAL_CCALL_GO_ZETASQL_ANALYZER_ANNOTATION_PROPAGATOR_EXPORT_H

#include "zetasql/analyzer/annotation_propagator.h"
// include sources
#define CheckAndPropagateAnnotationsImpl zetasql_analyzer_annotation_propagator_annot_prop_CheckAndPropagateAnnotationsImpl
#include "zetasql/analyzer/annotation_propagator.cc"
#undef CheckAndPropagateAnnotationsImpl
// include dependencies
#include "go-zetasql/base/ret_check/export.inc"
#include "go-zetasql/base/status/export.inc"
#include "go-zetasql/parser/parse_tree/export.inc"
#include "go-zetasql/public/analyzer_options/export.inc"
#include "go-zetasql/public/options_cc_proto/export.inc"
#include "go-zetasql/public/annotation/collation/export.inc"
#include "go-zetasql/public/types/types/export.inc"
#include "go-zetasql/resolved_ast/resolved_ast/export.inc"
#include "go-zetasql/resolved_ast/resolved_node_kind_cc_proto/export.inc"
#include "go-absl/status/status/export.inc"

#endif
