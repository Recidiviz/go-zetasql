#ifndef INTERNAL_CCALL_GO_GOOGLESQL_ANALYZER_REWRITE_RESOLVED_AST_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLESQL_ANALYZER_REWRITE_RESOLVED_AST_EXPORT_H

#include "googlesql/analyzer/rewrite_resolved_ast.h"
// include sources
#include "googlesql/analyzer/rewrite_resolved_ast.cc"
// include dependencies
#include "go-googlesql/analyzer/analyzer_output_mutator/export.inc"
#include "go-googlesql/analyzer/builtin_only_catalog/export.inc"
#include "go-googlesql/analyzer/rewriters/registration/export.inc"
#include "go-googlesql/analyzer/rewriters/rewriter_relevance_checker/export.inc"
#include "go-googlesql/analyzer/rewriters/templated_function_call_rewriter/export.inc"
#include "go-googlesql/base/logging/export.inc"
#include "go-googlesql/base/ret_check/export.inc"
#include "go-googlesql/base/status/export.inc"
#include "go-googlesql/common/errors/export.inc"
#include "go-googlesql/common/internal_analyzer_options/export.inc"
#include "go-googlesql/common/timer_util/export.inc"
#include "go-googlesql/public/analyzer_options/export.inc"
#include "go-googlesql/public/analyzer_output/export.inc"
#include "go-googlesql/public/catalog/export.inc"
#include "go-googlesql/public/language_options/export.inc"
#include "go-googlesql/public/options_cc_proto/export.inc"
#include "go-googlesql/public/rewriter_interface/export.inc"
#include "go-googlesql/public/types/types/export.inc"
#include "go-googlesql/resolved_ast/resolved_ast/export.inc"
#include "go-googlesql/resolved_ast/validator/export.inc"
#include "go-absl/algorithm/container/export.inc"
#include "go-absl/cleanup/cleanup/export.inc"
#include "go-absl/container/btree/export.inc"
#include "go-absl/status/status/export.inc"
#include "go-absl/strings/strings/export.inc"

#endif
