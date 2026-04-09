#!/usr/bin/env bash
# Optional nm-based checks for libprotobuf_cgo.a (Tier B). Off by default; set
# VERIFY_LIBPROTOBUF_CGO_SYMBOLS=1 to enable (e.g. in CI when debugging link issues).
set -euo pipefail
if [[ "${VERIFY_LIBPROTOBUF_CGO_SYMBOLS:-}" != "1" ]]; then
	exit 0
fi
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
LIB="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/${GOOS_GOARCH}/libprotobuf_cgo.a"
if [[ ! -f "$LIB" ]]; then
	echo "verify-libprotobuf-cgo-symbols: missing $LIB" >&2
	exit 1
fi
if ! command -v llvm-nm >/dev/null 2>&1; then
	echo "verify-libprotobuf-cgo-symbols: llvm-nm not found" >&2
	exit 1
fi
# Runtime archive must not merge protoc backend .o (e.g. crate_mapping.pic.o).
if ar t "$LIB" 2>/dev/null | grep -Fxq 'crate_mapping.pic.o'; then
	echo "verify-libprotobuf-cgo-symbols: unexpected crate_mapping.pic.o in $LIB (compiler subtree leaked in)" >&2
	exit 1
fi
# Cord entry points should be defined in-archive (not only unresolved).
# llvm-nm on a large .a may SIGPIPE when grep exits early; disable pipefail for this pipeline.
set +o pipefail
if ! llvm-nm -C "$LIB" 2>/dev/null | grep -Fq 'T google::protobuf::MessageLite::ParseFromCord'; then
	set -o pipefail
	echo "verify-libprotobuf-cgo-symbols: missing defined MessageLite::ParseFromCord in $LIB" >&2
	exit 1
fi
set -o pipefail
echo "verify-libprotobuf-cgo-symbols: ok ($LIB)"
