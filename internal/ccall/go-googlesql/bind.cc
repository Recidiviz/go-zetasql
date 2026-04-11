#ifndef googlesql_bind_cc
#define googlesql_bind_cc

#if !defined(GOOGLESQL_LINK_ONLY_BIND) && !defined(GOOGLESQL_UNIFIED_PREBUILT_THIN_BIND_CC)

#define GO_EXPORT(def) export_googlesql_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)
// Apply namespace macros before _cgo_export.h: the generated header can pull
// nested includes that reach zetasql amalgamation headers; those must see the
// root analyzer zetasql namespace macro (e.g. WarningSink).
#include "root_analyzer_amalgamation_macros.inc"
// bridge_cc.inc uses GoSlice; bridge.inc includes _cgo_export.h later.
#include "_cgo_export.h"
// internal/ccall/go-googlesql/parser/parser amalgamates these sources; omit from export.inc when
// linking the parser CGO package (avoids duplicate Abseil FLAGS registration).
#define GOOGLESQL_OMIT_PARSER_PACKAGE_DUPLICATE_CC 1
// common/errors/bind.cc already compiles errors.cc; omit from export.inc (same FLAGS issue).
#define GOOGLESQL_OMIT_COMMON_ERRORS_CC_FROM_EXPORT 1
// parser/parser bind amalgamation compiles error_helpers.cc; omit from export.inc here.
#define GOOGLESQL_OMIT_PUBLIC_ERROR_HELPERS_CC_FROM_EXPORT 1
// public/analyzer/bind.cc compiles thread_stack.cc; omit here (duplicate ABSL_FLAG registration).
#define GOOGLESQL_OMIT_THREAD_STACK_CC_FROM_EXPORT 1
// parser/parser bind.cc compiles tokenizer.cc; omit here (duplicate ABSL_FLAG registration).
#define GOOGLESQL_OMIT_TOKENIZER_CC_FROM_EXPORT 1
// common/string_util bind.cc compiles canonicalize_signed_zero_to_string.cc; omit here.
#define GOOGLESQL_OMIT_CANONICALIZE_SIGNED_ZERO_TO_STRING_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles analyzer_options.cc; omit here (duplicate ABSL_FLAG).
#define GOOGLESQL_OMIT_ANALYZER_OPTIONS_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles catalog_helper.cc; omit here (duplicate ABSL_FLAG).
#define GOOGLESQL_OMIT_CATALOG_HELPER_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles proto_util.cc (via public/value); omit here (duplicate ABSL_FLAG).
#define GOOGLESQL_OMIT_PUBLIC_PROTO_UTIL_CC_FROM_EXPORT 1
#define GOOGLESQL_OMIT_PUBLIC_VALUE_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles resolver/*.cc via this export.inc; omit here (duplicate ABSL_FLAG).
#define GOOGLESQL_OMIT_ANALYZER_RESOLVER_EXPORT_SOURCES 1
// public/analyzer bind.cc compiles input_format_string_max_width.cc (via cast_date_time/coercer); omit here.
#define GOOGLESQL_OMIT_INPUT_FORMAT_STRING_MAX_WIDTH_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles format_max_output_width.cc (via string_format); omit here.
#define GOOGLESQL_OMIT_FORMAT_MAX_OUTPUT_WIDTH_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles simple_evaluator_table_iterator.cc; omit here (duplicate ABSL_FLAG).
#define GOOGLESQL_OMIT_SIMPLE_EVALUATOR_TABLE_ITERATOR_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles scripting/parsed_script.cc; omit here (duplicate ABSL_FLAG).
#define GOOGLESQL_OMIT_PARSED_SCRIPT_CC_FROM_EXPORT 1
// public/analyzer bind.cc compiles analyzer/analyzer_output_mutator.cc; omit here (duplicate ABSL_FLAG).
#define GOOGLESQL_OMIT_ANALYZER_OUTPUT_MUTATOR_CC_FROM_EXPORT 1
#include "go-googlesql/public/analyzer/export.inc"
#include "go-googlesql/public/catalog/export.inc"
#include "go-googlesql/public/simple_catalog/export.inc"
#include "go-googlesql/public/sql_formatter/export.inc"
#include "go-googlesql/public/analyzer/bridge.h"
#include "go-googlesql/public/catalog/bridge.h"
#include "go-googlesql/public/simple_catalog/bridge.h"
#include "go-googlesql/public/sql_formatter/bridge.h"
#include "go-googlesql/public/analyzer/bridge_cc.inc"
#include "go-googlesql/public/catalog/bridge_cc.inc"
#include "go-googlesql/public/simple_catalog/bridge_cc.inc"
#include "go-googlesql/public/sql_formatter/bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "go-googlesql/public/analyzer/bridge.inc"
#include "go-googlesql/public/catalog/bridge.inc"
#include "go-googlesql/public/simple_catalog/bridge.inc"
#include "go-googlesql/public/sql_formatter/bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#else /* GOOGLESQL_LINK_ONLY_BIND || GOOGLESQL_UNIFIED_PREBUILT_THIN_BIND_CC */

// Link-only root bind.cc: bridge headers only (no export.inc amalgamation). Implementations
// come from libgooglesql.a when built with -DGOOGLESQL_LINK_ONLY_BIND. See docs/link-only-cgo-migration.md.

#define GO_EXPORT(def) export_googlesql_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)
#include "root_link_only_unified_macros.inc"
#include "_cgo_export.h"
#include "googlesql/public/analyzer.h"
#include "googlesql/public/catalog.h"
#include "googlesql/public/catalog_helper.h"
#include "googlesql/public/property_graph.h"
#include "googlesql/public/cast.h"
#include "googlesql/public/simple_catalog.h"
#include "googlesql/public/simple_property_graph.h"
#include "googlesql/public/table_from_proto.h"
#include "googlesql/public/sql_formatter.h"

#include "go-googlesql/public/analyzer/bridge.h"
#include "go-googlesql/public/catalog/bridge.h"
#include "go-googlesql/public/simple_catalog/bridge.h"
#include "go-googlesql/public/sql_formatter/bridge.h"
#include "go-googlesql/public/analyzer/bridge_cc.inc"
#include "go-googlesql/public/catalog/bridge_cc.inc"
#include "go-googlesql/public/simple_catalog/bridge_cc.inc"
#include "go-googlesql/public/sql_formatter/bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "go-googlesql/public/analyzer/bridge.inc"
#include "go-googlesql/public/catalog/bridge.inc"
#include "go-googlesql/public/simple_catalog/bridge.inc"
#include "go-googlesql/public/sql_formatter/bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* fat vs thin bind.cc */

#endif /* googlesql_bind_cc */
