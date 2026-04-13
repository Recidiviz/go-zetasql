#ifndef googlesql_bridge_h
#define googlesql_bridge_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdint.h>
#undef GO_EXPORT
#define GO_EXPORT(API) export_googlesql_public_analyzer_ ## API
#include "../go-googlesql/public/analyzer/bridge_extern.h"
#undef GO_EXPORT
#define GO_EXPORT(API) export_googlesql_public_catalog_ ## API
#include "../go-googlesql/public/catalog/bridge_extern.h"
#undef GO_EXPORT
#define GO_EXPORT(API) export_googlesql_public_simple_catalog_ ## API
#include "../go-googlesql/public/simple_catalog/bridge_extern.h"
#undef GO_EXPORT
#define GO_EXPORT(API) export_googlesql_public_sql_formatter_ ## API
#include "../go-googlesql/public/sql_formatter/bridge_extern.h"

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* googlesql_bridge_h */
