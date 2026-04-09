#!/usr/bin/env bash
# Fail fast if the default protobuf prebuilt archive is missing (see docs/prebuilt-cgo.md).
set -euo pipefail
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
LIB="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/${GOOS_GOARCH}/libprotobuf_cgo.a"
if [[ ! -f "$LIB" ]]; then
	echo "prebuilt protobuf archive not found: $LIB" >&2
	echo "Build it with: make prebuilt-libs  (requires bazelisk/bazel and a populated submodule)" >&2
	exit 1
fi
if [[ "$(go env GOOS)" == "linux" ]]; then
	CXXTIER="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/${GOOS_GOARCH}/libcxx_prebuilt.a"
	if [[ ! -f "$CXXTIER" ]]; then
		echo "prebuilt libc++ copy missing: $CXXTIER" >&2
		echo "Re-run: make prebuilt-libs  (extract script copies Bazel llvm_toolchain libc++)" >&2
		exit 1
	fi
fi
echo "ok: $LIB"
