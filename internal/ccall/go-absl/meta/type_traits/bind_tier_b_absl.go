//go:build googlesql_tier_b_absl && (linux || darwin)

package type_traits

// Link Bazel-built libabsl_cgo.a instead of compiling bind.cc + amalgamation for this package.
// Build the archive: `make prebuilt-libs-absl` from repo root.
// See docs/prebuilt-absl-overlap.md: do not combine with googlesql_tier_b (protobuf) in the same link without a dedup policy.

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../../
#cgo CXXFLAGS: -I${SRCDIR}/../../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../../utf8_range
#cgo linux LDFLAGS: -L${SRCDIR}/../../lib -labsl_cgo -lz -lstdc++ -ldl -lpthread
#cgo darwin LDFLAGS: -L${SRCDIR}/../../lib -labsl_cgo -lz -lc++

void __go_googlesql_tier_b_absl_type_traits_anchor(void) {}
*/
import "C"
