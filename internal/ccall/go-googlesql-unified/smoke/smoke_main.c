#include <googlesql_unified.h>
#include <stdio.h>

int main(void) {
  googlesql_unified_anchor();
  printf("%s\n", googlesql_unified_version_string());
  printf("%s\n", googlesql_unified_capabilities());
  return 0;
}
