#!/usr/bin/env bash
# Build @com_google_protobuf//:protobuf and :cmake_wkt_cc_proto with Bazel in the GoogleSQL
# submodule, then merge all non-test .pic.o objects from protobuf (incl. WKT from
# _objs/cmake_wkt_cc_proto), utf8_range, and Abseil (protobuf's deps) into
# lib/$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a. Abseil objects are required: protobuf
# .pic.o reference absl:: symbols that would otherwise stay undefined at link time.
#
# Runs on Linux and macOS when bazelisk/bazel is installed. Default CGO bindings still compile
# protobuf via amalgamation (export.inc); this archive is for experiments or a future Tier-B
# path. See docs/protobuf-vendoring.md ("Single-owner protobuf") and
# docs/protobuf-single-owner-inventory.md for why link-only protobuf must align Abseil/macro
# policy with the rest of go-googlesql.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/../../../.." && pwd)"
GOOGLESQL="$REPO_ROOT/internal/cmd/updater/googlesql"
cd "$GOOGLESQL"

export CC="${CC:-clang}"
export CXX="${CXX:-clang++}"

if ! command -v bazelisk >/dev/null 2>&1 && ! command -v bazel >/dev/null 2>&1; then
  echo "bazelisk or bazel is required" >&2
  exit 1
fi
BAZEL="${BAZEL:-$(command -v bazelisk || command -v bazel)}"

# :protobuf is the core library; WKT (.pb.cc for Any, Timestamp, Duration, wrappers, etc.) live in
# :cmake_wkt_cc_proto. Without those .pic.o files, Tier-B links miss GetMetadata, descriptor tables,
# and Cord helpers for well-known types.
"$BAZEL" build @com_google_protobuf//:protobuf \
  @com_google_protobuf//src/google/protobuf:cmake_wkt_cc_proto \
  --cxxopt=-std=c++20 --host_cxxopt=-std=c++20 \
  --jobs="${BAZEL_JOBS:-8}"

BINROOT="$("$BAZEL" info bazel-bin | tr -d '\r')"
# Bazel 7+ module repos use names like external/protobuf~; older layouts used com_google_protobuf.
# utf8_range may live under protobuf/third_party/utf8_range or its own external root.
collect_protobuf_pic_o() {
  local d
  for d in \
    "$BINROOT/external/protobuf~" \
    "$BINROOT/external/com_google_protobuf" \
    "$BINROOT/external/utf8_range" \
    "$BINROOT/external/abseil-cpp~"; do
    [[ -d "$d" ]] || continue
    find "$d" -name '*.pic.o' 2>/dev/null
  done
}
# Bazel also builds per-target *_proto dirs (e.g. timestamp_proto) that duplicate cmake_wkt_cc_proto
# objects — keep only cmake_wkt_cc_proto to avoid duplicate symbols at link time.
OBJS=$(
  collect_protobuf_pic_o \
    | grep -Ev 'test|unittest|benchmark' \
    | grep -Ev '/_objs/(timestamp|duration|any|wrappers|struct|empty|field_mask|source_context|type|api)_proto/' \
    | sort -u || true
)
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
