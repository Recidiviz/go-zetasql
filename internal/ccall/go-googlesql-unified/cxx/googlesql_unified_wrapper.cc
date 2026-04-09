#include "googlesql_unified.h"

extern "C" const char* googlesql_unified_version_string(void) {
#ifdef GOOGLESQL_UNIFIED_INCLUDES_ANALYZER
  return "0.3.0-unified+analyzer";
#else
  return "0.2.0-unified-bootstrap";
#endif
}

extern "C" const char* googlesql_unified_capabilities(void) {
#ifdef GOOGLESQL_UNIFIED_INCLUDES_ANALYZER
  return "proto,base,resolved_ast,analyzer";
#else
  return "proto,base,resolved_ast";
#endif
}
