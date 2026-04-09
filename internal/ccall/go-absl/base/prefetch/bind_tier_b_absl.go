//go:build googlesql_tier_b_absl && (linux || darwin)

package prefetch

// Link Bazel-built libabsl_cgo.a instead of compiling bind.cc for this package.
// See docs/prebuilt-absl-overlap.md.

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../../
#cgo CXXFLAGS: -I${SRCDIR}/../../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../../utf8_range
#cgo linux LDFLAGS: -L${SRCDIR}/../../lib -labsl_cgo -lz -lstdc++ -ldl -lpthread
#cgo darwin LDFLAGS: -L${SRCDIR}/../../lib -labsl_cgo -lz -lc++

void __go_googlesql_tier_b_absl_base_prefetch_anchor(void) {}
*/
import "C"
