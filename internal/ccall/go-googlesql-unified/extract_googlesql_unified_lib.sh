#!/usr/bin/env bash
# Build one or more //googlesql/... cc_library / cc_proto_library targets in the GoogleSQL submodule,
# collect googlesql *.pic.o, add the C anchor object, and write lib/$(go env GOOS)_$(go env GOARCH)/libgooglesql.a
#
# Default labels are read from default_bazel_targets.txt (base + cc_proto closure toward AST/resolved_ast
# plus the root parser/analyzer/catalog/formatter slice used by the top-level Go package tests).
# //googlesql/public:analyzer and //googlesql/parser:* still need Textmapper — see docs/libgooglesql-unified.md.
# Override with GOOGLESQL_UNIFIED_BAZEL_TARGETS.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/../../.." && pwd)"
GOOGLESQL="$REPO_ROOT/internal/cmd/updater/googlesql"
C_ANCHOR_SRC="$REPO_ROOT/internal/ccall/go-googlesql-unified/c/googlesql_unified_anchor.c"
WRAPPER_SRC="$REPO_ROOT/internal/ccall/go-googlesql-unified/cxx/googlesql_unified_wrapper.cc"
INCLUDE_DIR="$REPO_ROOT/internal/ccall/go-googlesql-unified/include"
OUT_DIR="$REPO_ROOT/internal/ccall/go-googlesql-unified/lib"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
OUT="$OUT_DIR/$GOOS_GOARCH/libgooglesql.a"

export CC="${CC:-clang}"
export CXX="${CXX:-clang++}"

if ! command -v bazelisk >/dev/null 2>&1 && ! command -v bazel >/dev/null 2>&1; then
  echo "bazelisk or bazel is required" >&2
  exit 1
fi
BAZEL="${BAZEL:-$(command -v bazelisk || command -v bazel)}"
REPO_GOPROXY="${GOOGLESQL_UNIFIED_GOPROXY:-https://proxy.golang.org,direct}"

if [[ ! -f "$C_ANCHOR_SRC" ]] || [[ ! -f "$WRAPPER_SRC" ]]; then
  echo "missing anchor or wrapper source" >&2
  exit 1
fi

# Space-separated list of Bazel labels (googlesql module). Default: read from
# default_bazel_targets.txt (version-controlled base + cc_proto closure toward AST/protobuf and
# the first root API slice; //googlesql/parser:* and //googlesql/public:analyzer require Textmapper
# in the Bazel workspace). Override
# with GOOGLESQL_UNIFIED_BAZEL_TARGETS.
DEFAULT_TARGETS_FILE="$(cd "$(dirname "$0")" && pwd)/default_bazel_targets.txt"
if [[ -n "${GOOGLESQL_UNIFIED_BAZEL_TARGETS:-}" ]]; then
  TARGETS="$GOOGLESQL_UNIFIED_BAZEL_TARGETS"
elif [[ -f "$DEFAULT_TARGETS_FILE" ]]; then
  TARGETS="$(grep -v '^[[:space:]]*#' "$DEFAULT_TARGETS_FILE" | grep -v '^[[:space:]]*$' | tr '\n' ' ')"
else
  TARGETS="//googlesql/base:logging //googlesql/base:status //googlesql/base:check //googlesql/base:ret_check //googlesql/base:map_util //googlesql/base:arena //googlesql/base:strings //googlesql/base:stl_util //googlesql/base:base //googlesql/base:endian"
fi
EXTERNAL_TARGETS=(
  "@com_google_googleapis//google/type:date_cc_proto"
  "@com_google_googleapis//google/type:timeofday_cc_proto"
  "@com_google_googleapis//google/rpc:status_cc_proto"
)

cd "$GOOGLESQL"

WORK="$(mktemp -d)"
cleanup() { rm -rf "$WORK"; }
trap cleanup EXIT

echo "Building GoogleSQL targets: $TARGETS"
# shellcheck disable=SC2086
"$BAZEL" build $TARGETS "${EXTERNAL_TARGETS[@]}" \
  --cxxopt=-std=c++20 --host_cxxopt=-std=c++20 \
  --repo_env=GOPROXY="$REPO_GOPROXY" \
  --jobs="${BAZEL_JOBS:-8}"

BINROOT="$("$BAZEL" info bazel-bin | tr -d '\r')"

# Collect the full googlesql *.pic.o set after a successful build, plus the external dependency
# object roots that the root parser/analyzer slice now expects libgooglesql.a to own. We
# intentionally keep protobuf/absl out of this archive to preserve their existing single-owner
# prebuilts.
SEARCH_ROOTS=(
  "$BINROOT/googlesql"
  "$BINROOT/external/re2~"
  "$BINROOT/external/googleapis~"
  "$BINROOT/external/nlohmann_json~"
  "$BINROOT/external/boringssl~"
  "$BINROOT/external/_main~googlesql_http_archive_deps~icu"
  "$BINROOT/external/_main~googlesql_http_archive_deps~com_google_cc_differential_privacy"
  "$BINROOT/external/_main~googlesql_http_archive_deps~com_google_differential_privacy"
)
# Drop Abseil, protobuf runtime, and utf8_range object files: they are owned by
# libprotobuf_cgo.a (see extract_protobuf_cgo_lib.sh). Merging the same *.pic.o into
# libgooglesql.a duplicates thousands of T/t symbols; the link uses
# -Wl,--allow-multiple-definition and picks arbitrary ELF definitions → ODR violations
# and crashes during protobuf DescriptorPool / Abseil SwissTable static init.
filter_non_googlesql_runtime_pic_o() {
  grep -Ev 'test|unittest|benchmark' |
    grep -Ev '/abseil-cpp|abseil-cpp~|/abseil~|/protobuf~|/com_google_protobuf|utf8_range|/utf8_range~' |
    grep -Ev 'status_matchers|gmock|gtest|googletest|googlemock' |
    grep -Ev '/google/protobuf/compiler/'
}
mapfile -t OBJS < <(
  for root in "${SEARCH_ROOTS[@]}"; do
    [[ -d "$root" ]] || continue
    find "$root" -name '*.pic.o' 2>/dev/null
  done | filter_non_googlesql_runtime_pic_o | sort -u || true
)
ICU_STATIC_ARCHIVES=()
for archive in \
  "$BINROOT/external/_main~googlesql_http_archive_deps~icu/icu/lib/libicuuc.a" \
  "$BINROOT/external/_main~googlesql_http_archive_deps~icu/icu/lib/libicui18n.a" \
  "$BINROOT/external/_main~googlesql_http_archive_deps~icu/icu/lib/libicudata.a"
do
  [[ -f "$archive" ]] && ICU_STATIC_ARCHIVES+=("$archive")
done
if [[ ${#OBJS[@]} -eq 0 ]] || [[ -z "${OBJS[0]:-}" ]]; then
  echo "no googlesql .pic.o under $BINROOT/googlesql (did the build produce objects?)" >&2
  exit 1
fi
for archive in "${ICU_STATIC_ARCHIVES[@]}"; do
  extract_dir="$WORK/$(basename "$archive" .a)"
  mkdir -p "$extract_dir"
  (
    cd "$extract_dir"
    ar x "$archive"
  )
  mapfile -t ICU_OBJS < <(rg --files "$extract_dir" | rg '\.(ao|o)$' || true)
  if [[ ${#ICU_OBJS[@]} -gt 0 ]]; then
    OBJS+=("${ICU_OBJS[@]}")
  fi
done

echo "Compiling C anchor and C++ wrapper..."
WRAPPER_DEFS=()
if echo " $TARGETS " | grep -q '//googlesql/public:analyzer'; then
  WRAPPER_DEFS+=(-DGOOGLESQL_UNIFIED_INCLUDES_ANALYZER=1)
fi
"$CC" -c -o "$WORK/googlesql_unified_anchor.o" "$C_ANCHOR_SRC"
# shellcheck disable=SC2086
"$CXX" -std=c++20 -c -o "$WORK/googlesql_unified_wrapper.o" -I"$INCLUDE_DIR" "${WRAPPER_DEFS[@]}" "$WRAPPER_SRC"

mkdir -p "$(dirname "$OUT")"
rm -f "$OUT"
# shellcheck disable=SC2086
ar crs "$OUT" "${OBJS[@]}" "$WORK/googlesql_unified_anchor.o" "$WORK/googlesql_unified_wrapper.o"
echo "Wrote $OUT ($(ls -lh "$OUT" | awk '{print $5}'))"

LINK_NAME="$OUT_DIR/libgooglesql.a"
REL="$GOOS_GOARCH/libgooglesql.a"
ln -sfn "$REL" "$LINK_NAME"
echo "Symlink $LINK_NAME -> $REL"
