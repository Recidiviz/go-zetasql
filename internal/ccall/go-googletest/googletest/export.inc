#ifndef INTERNAL_CCALL_GO_GOOGLETEST_GOOGLETEST_EXPORT_H
#define INTERNAL_CCALL_GO_GOOGLETEST_GOOGLETEST_EXPORT_H
// GoogleTest is not vendored into the CGO amalgamation. Upstream Bazel targets
// may list @com_google_googletest//:gtest; generated export.inc chains reference
// this header so builds remain consistent.
#endif
