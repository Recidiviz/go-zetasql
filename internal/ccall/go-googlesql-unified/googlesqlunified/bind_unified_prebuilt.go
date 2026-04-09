//go:build googlesql_unified_prebuilt && (linux || darwin)

package googlesqlunified

// Link libgooglesql.a from internal/ccall/go-googlesql-unified/lib (see docs/libgooglesql-unified.md).
// v1 archive is GoogleSQL .o + C anchor; you may still need protobuf/abseil archives for full APIs.

/*
#cgo CFLAGS: -std=c11
#cgo linux LDFLAGS: -L${SRCDIR}/../lib -lgooglesql -lz -lstdc++ -ldl -lpthread
#cgo darwin LDFLAGS: -L${SRCDIR}/../lib -lgooglesql -lz -lc++

void googlesql_unified_anchor(void);
*/
import "C"

// Link ensures the archive is pulled into the final link.
var _ = C.googlesql_unified_anchor
