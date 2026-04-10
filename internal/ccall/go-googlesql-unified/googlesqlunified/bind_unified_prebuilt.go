//go:build googlesql_unified_prebuilt && (linux || darwin)

package googlesqlunified

// Link libgooglesql.a from internal/ccall/go-googlesql-unified/lib (see docs/libgooglesql-unified.md).
// v1 archive is GoogleSQL .o + C anchor; you may still need protobuf/abseil archives for full APIs.

/*
#cgo CFLAGS: -std=c11
#cgo linux LDFLAGS: -L${SRCDIR}/../lib -lgooglesql -lz -ldl -lpthread
#cgo darwin LDFLAGS: -L${SRCDIR}/../lib -lgooglesql -lz -lc++

void googlesql_unified_anchor(void);
char* googlesql_unified_version_string(void);
char* googlesql_unified_capabilities(void);
*/
import "C"

import (
	// Ensure libprotobuf_cgo.a C++ runtime initializes before libgooglesql.a static
	// constructors (descriptor registration / DescriptorPool::Tables). Without this edge,
	// Go package init order vs sibling imports is undefined and we observed startup SIGSEGV in
	// absl::raw_hash_set during DescriptorPool::Tables construction (see
	// docs/unified-prebuilt-root-segfault-investigation.md).
	_ "github.com/vantaboard/go-googlesql/internal/ccall/go-protobuf/protobuf"
)

// Link ensures the archive is pulled into the final link.
var _ = C.googlesql_unified_anchor
var _ = C.googlesql_unified_version_string
var _ = C.googlesql_unified_capabilities
