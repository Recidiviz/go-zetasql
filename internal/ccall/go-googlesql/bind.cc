#define GO_EXPORT(def) export_googlesql_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)
// Apply namespace macros before _cgo_export.h: the generated header can pull
// nested includes that reach zetasql amalgamation headers; those must see the
// root analyzer zetasql namespace macro (e.g. WarningSink).
#include "root_analyzer_amalgamation_macros.inc"
// bridge_cc.inc uses GoSlice; bridge.inc includes _cgo_export.h later.
#include "_cgo_export.h"
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
