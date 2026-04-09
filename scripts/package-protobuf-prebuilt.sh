#!/usr/bin/env bash
# Package the default protobuf prebuilt tree for release artifacts or CI handoff.
# Preserves paths: internal/ccall/go-protobuf/protobuf/lib/<GOOS_GOARCH>/libprotobuf_cgo.a
# Usage: run from repo root after `make prebuilt-libs`. Optional: OUTPUT_NAME override.
set -euo pipefail
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
LIB_DIR="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib"
if [[ ! -d "$LIB_DIR/$GOOS_GOARCH" ]] || [[ ! -f "$LIB_DIR/$GOOS_GOARCH/libprotobuf_cgo.a" ]]; then
	echo "error: expected prebuilt at $LIB_DIR/$GOOS_GOARCH/libprotobuf_cgo.a" >&2
	echo "Run: make prebuilt-libs" >&2
	exit 1
fi
OUT="${OUTPUT_NAME:-go-googlesql-prebuilts-protobuf-${GOOS_GOARCH}.tar.gz}"
tar -C "$REPO_ROOT" -czf "$REPO_ROOT/$OUT" internal/ccall/go-protobuf/protobuf/lib
echo "wrote $REPO_ROOT/$OUT"
ls -la "$REPO_ROOT/$OUT"
