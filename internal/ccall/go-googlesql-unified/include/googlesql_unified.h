/* Unified libgooglesql.a — stable C ABI for external link tests.
 * See docs/libgooglesql-unified.md. */

#ifndef GOOGLESQL_UNIFIED_H_
#define GOOGLESQL_UNIFIED_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Smoke / link anchor; always defined when the unified archive is built. */
void googlesql_unified_anchor(void);

/* Human-readable build label (wrapper in cxx/googlesql_unified_wrapper.cc). */
const char* googlesql_unified_version_string(void);

/* Comma-separated feature tags for the unified archive (e.g. proto,base,root_api). */
const char* googlesql_unified_capabilities(void);

#ifdef __cplusplus
}
#endif

#endif /* GOOGLESQL_UNIFIED_H_ */
