//go:build zetasql_tier_b && (linux || darwin)

package protobuf

// Tier B: link Bazel-built libprotobuf_cgo.a instead of compiling export.inc here.
// Build the archive: `make extract-protobuf-lib` from repo root (requires bazelisk, submodule cache).
// The extract script writes lib/$GOOS_$GOARCH/libprotobuf_cgo.a and symlinks lib/libprotobuf_cgo.a.
//
// This path does not yet provide GO_ZETASQL_PB_EXPORT / export_protobuf_* symbols from the
// amalgamation — use together with generator global_exclude_replace_names and a full unified
// link story (see docs/tier-b-absl-protobuf.md). The anchor only forces libprotobuf_cgo.a into the link.

/*
#cgo CXXFLAGS: -std=c++17
#cgo CXXFLAGS: -I${SRCDIR}/../../
#cgo CXXFLAGS: -I${SRCDIR}/../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../utf8_range
#cgo linux LDFLAGS: -L${SRCDIR}/lib -lprotobuf_cgo -lz -lstdc++ -ldl
#cgo darwin LDFLAGS: -L${SRCDIR}/lib -lprotobuf_cgo -lz -lc++

void __go_zetasql_tier_b_protobuf_anchor(void) {}
*/
import "C"

import (
	_ "github.com/goccy/go-zetasql/internal/ccall/utf8_range_link"
)
