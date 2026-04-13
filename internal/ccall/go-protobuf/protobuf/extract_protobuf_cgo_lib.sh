#!/usr/bin/env bash
# Build @com_google_protobuf//:protobuf and :cmake_wkt_cc_proto with Bazel in the GoogleSQL
# submodule, then merge all non-test .pic.o objects from protobuf (incl. WKT from
# _objs/cmake_wkt_cc_proto), utf8_range, and Abseil (protobuf's deps) into
# lib/$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a. Abseil objects are required: protobuf
# .pic.o reference absl:: symbols that would otherwise stay undefined at link time.
#
# Version note: this uses MODULE.bazel's `protobuf` (e.g. 29.x). Vendored internal/ccall/protobuf and
# generated googlesql *.pb.h target ~4.23.x. The default prebuilt bind path must keep the same protobuf
# C++ ABI as this archive — see internal/ccall/go-protobuf/protobuf/bind_linux.go,
# bind_darwin.go, and docs/protobuf-vendoring.md.
#
# Runs on Linux and macOS when bazelisk/bazel is installed. This archive is the default protobuf
# CGO path for the repo. See docs/protobuf-vendoring.md ("Single-owner protobuf") and
# docs/protobuf-single-owner-inventory.md for why link-only protobuf must align Abseil/macro
# policy with the rest of go-googlesql.
#
# DescriptorPool::Tables: internal/cmd/updater/googlesql/MODULE.bazel patches protobuf 29.0
# (patches/protobuf_descriptor_googlesql_tables.patch) so descriptor.cc uses std::map / std::unordered_*
# instead of absl::flat_hash_* for unified-prebuilt + libgooglesql; vendored
# internal/ccall/protobuf/google/protobuf/descriptor.cc must match that patch.
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
# :cmake_wkt_cc_proto. Without those .pic.o files, prebuilt links miss GetMetadata, descriptor tables,
# and Cord helpers for well-known types.
# Build //src/google/protobuf:protobuf explicitly: the repo root :protobuf target is an alias to a
# layering stub and does not compile descriptor.cc; we need _objs/protobuf/*.pic.o for libprotobuf_cgo.a.
"$BAZEL" build @com_google_protobuf//src/google/protobuf:protobuf \
  @com_google_protobuf//:protobuf \
  @com_google_protobuf//src/google/protobuf:cmake_wkt_cc_proto \
  --cxxopt=-std=c++20 --host_cxxopt=-std=c++20 \
  --jobs="${BAZEL_JOBS:-8}"

# Abseil .cc bodies used by go-absl amalgamation shards are not always present in protobuf's
# transitive .pic.o closure; build them explicitly so collect_protobuf_pic_o can merge the
# matching *_*.pic.o members (see docs/cgo-consolidation.md, prebuilt expansion).
"$BAZEL" build \
  @com_google_absl//absl/log:flags \
  @com_google_absl//absl/strings:cordz_sample_token \
  @com_google_absl//absl/debugging:failure_signal_handler \
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
# Exclude google/protobuf/compiler/** — protoc backends (rust, csharp, java, ...) are not in the
# runtime :protobuf link closure; merging their .pic.o pulls undefined symbols (e.g.
# google::protobuf::File::ReadFileToString from crate_mapping.cc).
# Exclude Abseil test-only objects (e.g. status_matchers) that reference gtest — otherwise
# `-Wl,--whole-archive -lprotobuf_cgo` pulls them in and the link requires libgtest.
#
# cctz IANA zone: time_zone_*.pic.o and zone_info_source.pic.o merge into libprotobuf_cgo.a (Option A).
# go-absl/time/.../cctz/time_zone bind.cc must not also #include those .cc bodies — use
# cclib.exclude_amalgamation_sources in internal/cmd/generator/config.yaml and regenerate bind.cc.
OBJS=$(
  collect_protobuf_pic_o \
    | grep -Ev 'test|unittest|benchmark' \
    | grep -Ev 'status_matchers|gmock|gtest|googletest|googlemock' \
    | grep -Ev '/_objs/(timestamp|duration|any|wrappers|struct|empty|field_mask|source_context|type|api)_proto/' \
    | grep -Ev '/google/protobuf/compiler/' \
    | sort -u || true
)
if [[ -z "${OBJS// }" ]]; then
  echo "no protobuf .pic.o under $BINROOT/external" >&2
  exit 1
fi

OUT="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a"
mkdir -p "$(dirname "$OUT")"
rm -f "$OUT"
# ar stores only member basenames. Bazel outputs multiple distinct paths whose basename is
# identical (e.g. absl/flags/_objs/commandlineflag{,_internal}/commandlineflag.pic.o). Merging
# those into one archive yields duplicate member names; the linker can resolve the wrong object
# under -Wl,--whole-archive and Abseil flag / SwissTable state becomes inconsistent (SIGSEGV in
# absl::flags_internal::FlagRegistry::RegisterFlag). Stage each .o with a unique filename first.
STAGE="$(mktemp -d "${TMPDIR:-/tmp}/libprotobuf_cgo_objs.XXXXXX")"
trap 'rm -rf "$STAGE"' EXIT
i=0
for obj in ${OBJS}; do
  i=$((i + 1))
  base="$(basename "$obj")"
  parent="$(basename "$(dirname "$obj")")"
  cp -f "$obj" "$STAGE/${i}_${parent}_${base}"
done
# shellcheck disable=SC2086
ar crs "$OUT" "$STAGE"/*.o
echo "Wrote $OUT ($(ls -lh "$OUT" | awk '{print $5}'))"

# Stable -L path for the default protobuf bind files: -L ${SRCDIR}/lib -lprotobuf_cgo
LINK_NAME="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a"
REL="$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a"
ln -sfn "$REL" "$LINK_NAME"
echo "Symlink $LINK_NAME -> $REL"

# Copy libc++/libc++abi from the same Bazel LLVM toolchain that built Abseil/protobuf .pic.o. Linking
# those objects against the host's /usr/lib/llvm-*/lib/libc++.a can fail (e.g. std::__1::__hash_memory
# with a mismatched [abi:ne...] tag). The default protobuf bind on Linux uses these static libs.
LIB_DIR="$(dirname "$OUT")"
OUTPUT_BASE="$("$BAZEL" info output_base | tr -d '\r')"
if [[ "$(go env GOOS)" == "linux" ]]; then
  LLVM_LIBCPP="$(find "$OUTPUT_BASE/external" -name libc++.a -path '*llvm_toolchain_llvm*' -print -quit 2>/dev/null || true)"
  if [[ -n "$LLVM_LIBCPP" ]]; then
    LLVM_DIR="$(dirname "$LLVM_LIBCPP")"
    cp -f "$LLVM_DIR/libc++.a" "$LIB_DIR/libcxx_prebuilt.a"
    cp -f "$LLVM_DIR/libc++abi.a" "$LIB_DIR/libcxxabi_prebuilt.a"
    echo "Copied Bazel LLVM libc++/libc++abi to $LIB_DIR (libcxx_prebuilt.a, libcxxabi_prebuilt.a)"
    ln -sfn "$(go env GOOS)_$(go env GOARCH)/libcxx_prebuilt.a" "$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/libcxx_prebuilt.a"
    ln -sfn "$(go env GOOS)_$(go env GOARCH)/libcxxabi_prebuilt.a" "$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/libcxxabi_prebuilt.a"
    echo "Symlinks lib/libcxx_prebuilt.a and lib/libcxxabi_prebuilt.a -> $(go env GOOS)_$(go env GOARCH)/"
  else
    echo "warning: could not find Bazel llvm_toolchain libc++.a under $OUTPUT_BASE/external" >&2
  fi
fi
