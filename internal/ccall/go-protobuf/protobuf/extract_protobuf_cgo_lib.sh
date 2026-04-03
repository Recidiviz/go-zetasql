#!/usr/bin/env bash
# Build @com_google_protobuf//:protobuf with Bazel in the ZetaSQL submodule, then merge all
# non-test .pic.o objects (plus utf8_range) into lib/$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/../../../.." && pwd)"
ZETASQL="$REPO_ROOT/internal/cmd/updater/zetasql"
cd "$ZETASQL"

export CC="${CC:-clang}"
export CXX="${CXX:-clang++}"

if ! command -v bazelisk >/dev/null 2>&1 && ! command -v bazel >/dev/null 2>&1; then
  echo "bazelisk or bazel is required" >&2
  exit 1
fi
BAZEL="${BAZEL:-$(command -v bazelisk || command -v bazel)}"

"$BAZEL" build @com_google_protobuf//:protobuf \
  --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 \
  --jobs="${BAZEL_JOBS:-8}"

BINROOT="$("$BAZEL" info bazel-bin | tr -d '\r')"
OBJS=$(find "$BINROOT/external/com_google_protobuf" "$BINROOT/external/utf8_range" \
  -name '*.pic.o' 2>/dev/null | grep -Ev 'test|unittest' | sort || true)
if [[ -z "${OBJS// }" ]]; then
  echo "no protobuf .pic.o under $BINROOT/external" >&2
  exit 1
fi

OUT="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a"
mkdir -p "$(dirname "$OUT")"
rm -f "$OUT"
# shellcheck disable=SC2086
ar crs "$OUT" ${OBJS}
echo "Wrote $OUT ($(ls -lh "$OUT" | awk '{print $5}'))"
