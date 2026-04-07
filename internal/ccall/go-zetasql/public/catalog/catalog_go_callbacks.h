// Declarations for Go-exported callbacks in internal/ccall/go-zetasql/callback_{linux,darwin}.go
// (package googlesql). Prototypes must match cgo's generated declarations (including
// non-const char* returns) or the catalog TU conflicts with cgo-gcc-export-header-prolog
// when the root package is built. GoSlice is defined by cgo; do not typedef it here.

#ifndef GOOGLESQL_PUBLIC_CATALOG_CATALOG_GO_CALLBACKS_H_
#define GOOGLESQL_PUBLIC_CATALOG_CATALOG_GO_CALLBACKS_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

char* GoCatalog_FullName(void* v);
void GoCatalog_FindTable(void* v, void* pathPtr, void** table, char** ret);
void GoCatalog_FindModel(void* v, void* pathPtr, void** model, char** ret);
void GoCatalog_FindConnection(void* v, void* pathPtr, void** conn, char** ret);
void GoCatalog_FindFunction(void* v, void* pathPtr, void** fn, char** ret);
void GoCatalog_FindTableValuedFunction(void* v, void* pathPtr, void** fn, char** ret);
void GoCatalog_FindProcedure(void* v, void* pathPtr, void** proc, char** ret);
void GoCatalog_FindType(void* v, void* pathPtr, void** typ, char** ret);
void GoCatalog_FindConstant(void* v, void* pathPtr, int* numNamesConsumed, void** constant,
                            char** ret);
void GoCatalog_FindConversion(void* v, void* from_type, void* to_type, void** conv, char** ret);
void GoCatalog_ExtendedTypeSuperTypes(void* v, void* type, void** list, char** ret);
char* GoCatalog_SuggestTable(void* v, void* pathPtr);
char* GoCatalog_SuggestModel(void* v, void* pathPtr);
char* GoCatalog_SuggestFunction(void* v, void* pathPtr);
char* GoCatalog_SuggestTableValuedFunction(void* v, void* pathPtr);
char* GoCatalog_SuggestConstant(void* v, void* pathPtr);

char* GoTable_Name(void* v);
char* GoTable_FullName(void* v);
int GoTable_NumColumns(void* v);
void* GoTable_Column(void* v, int idx);
void* GoTable_PrimaryKey(void* v);
void* GoTable_FindColumnByName(void* v, char* name);
int GoTable_IsValueTable(void* v);
int64_t GoTable_SerializationID(void* v);
void GoTable_CreateEvaluatorTableIterator(void* v, void* columnIdxsPtr, void** iter, char** ret);
void* GoTable_AnonymizationInfo(void* v);
int GoTable_SupportsAnonymization(void* v);
char* GoTable_TableTypeName(void* v, int mode);

#ifdef __cplusplus
}
#endif

#endif  // GOOGLESQL_PUBLIC_CATALOG_CATALOG_GO_CALLBACKS_H_
