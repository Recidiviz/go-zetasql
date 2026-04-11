#ifndef googlesql_bind_cc
#define googlesql_bind_cc

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

#endif /* googlesql_bind_cc */
