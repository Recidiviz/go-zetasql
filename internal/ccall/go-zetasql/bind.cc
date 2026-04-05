#define GO_EXPORT(def) export_zetasql_ ## def
#define U_ICU_ENTRY_POINT_RENAME(x) GO_EXPORT(x)
// Apply namespace macros before _cgo_export.h: the generated header can pull
// nested includes that reach zetasql amalgamation headers; those must see the
// root analyzer zetasql namespace macro (e.g. WarningSink).
#include "root_analyzer_amalgamation_macros.inc"
#define ZETASQL_PARSER_FLEX_TOKENIZER_SUPPRESS_FLEXLEXER_STUBS
// bridge_cc.inc uses GoSlice; bridge.inc includes _cgo_export.h later.
#include "_cgo_export.h"
#include "go-zetasql/public/analyzer/export.inc"
#include "go-zetasql/public/catalog/export.inc"
#include "go-zetasql/public/simple_catalog/export.inc"
#include "go-zetasql/public/sql_formatter/export.inc"
#include "go-zetasql/public/analyzer/bridge.h"
#include "go-zetasql/public/catalog/bridge.h"
#include "go-zetasql/public/simple_catalog/bridge.h"
#include "go-zetasql/public/sql_formatter/bridge.h"
#include "go-zetasql/public/analyzer/bridge_cc.inc"
#include "go-zetasql/public/catalog/bridge_cc.inc"
#include "go-zetasql/public/simple_catalog/bridge_cc.inc"
#include "go-zetasql/public/sql_formatter/bridge_cc.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "go-zetasql/public/analyzer/bridge.inc"
#include "go-zetasql/public/catalog/bridge.inc"
#include "go-zetasql/public/simple_catalog/bridge.inc"
#include "go-zetasql/public/sql_formatter/bridge.inc"

#ifdef __cplusplus
}
#endif /* __cplusplus */

// flex_tokenizer.cc.inc sets YY_DECL to GetNextTokenFlexImpl, so flex never
// emits yyFlexLexer::yylex(). The FlexLexer vtable still needs yylex() (FlexLexer.h).
int ZetaSqlFlexTokenizerBase::yylex() { return 0; }
