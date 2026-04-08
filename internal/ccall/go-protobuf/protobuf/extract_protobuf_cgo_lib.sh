#!/usr/bin/env bash
# Build @com_google_protobuf//:protobuf with Bazel in the GoogleSQL submodule, then merge all
# non-test .pic.o objects (plus utf8_range) into lib/$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a.
#
# Runs on Linux and macOS when bazelisk/bazel is installed. Default CGO bindings still compile
# protobuf via amalgamation (export.inc); this archive is for experiments or a future Tier-B
# path. See docs/protobuf-vendoring.md ("Single-owner protobuf") and
# docs/protobuf-single-owner-inventory.md for why link-only protobuf must align Abseil/macro
# policy with the rest of go-googlesql.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/../../../.." && pwd)"
ZETASQL="$REPO_ROOT/internal/cmd/updater/googlesql"
cd "$ZETASQL"

export CC="${CC:-clang}"
export CXX="${CXX:-clang++}"

if ! command -v bazelisk >/dev/null 2>&1 && ! command -v bazel >/dev/null 2>&1; then
  echo "bazelisk or bazel is required" >&2
  exit 1
fi
BAZEL="${BAZEL:-$(command -v bazelisk || command -v bazel)}"

"$BAZEL" build @com_google_protobuf//:protobuf \
  --cxxopt=-std=c++20 --host_cxxopt=-std=c++20 \
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

# Stable -L path for bind_tier_b.go: -L ${SRCDIR}/lib -lprotobuf_cgo
LINK_NAME="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a"
REL="$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a"
ln -sfn "$REL" "$LINK_NAME"
echo "Symlink $LINK_NAME -> $REL"
