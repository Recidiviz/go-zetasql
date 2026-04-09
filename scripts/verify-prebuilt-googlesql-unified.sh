#!/usr/bin/env bash
# Fail fast if unified libgooglesql.a is missing (see docs/libgooglesql-unified.md).
set -euo pipefail
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
LIB="$REPO_ROOT/internal/ccall/go-googlesql-unified/lib/${GOOS_GOARCH}/libgooglesql.a"
if [[ ! -f "$LIB" ]]; then
	echo "prebuilt libgooglesql.a not found: $LIB" >&2
	echo "Build it with: make prebuilt-libs-googlesql-unified  (requires bazelisk/bazel and a populated submodule)" >&2
	exit 1
fi
echo "ok: $LIB"
