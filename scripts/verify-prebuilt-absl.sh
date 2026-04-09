#!/usr/bin/env bash
# Fail fast if Tier B Abseil archive is missing (see docs/prebuilt-cgo.md).
set -euo pipefail
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
LIB="$REPO_ROOT/internal/ccall/go-absl/lib/${GOOS_GOARCH}/libabsl_cgo.a"
if [[ ! -f "$LIB" ]]; then
	echo "prebuilt Abseil archive not found: $LIB" >&2
	echo "Build it with: make prebuilt-libs-absl  (requires bazelisk/bazel and a populated submodule)" >&2
	exit 1
fi
echo "ok: $LIB"
