#!/usr/bin/env bash
# Build one or more //googlesql/... cc_library targets in the GoogleSQL submodule, collect
# googlesql *.pic.o, add the C anchor object, and write lib/$(go env GOOS)_$(go env GOARCH)/libgooglesql.a
#
# Default targets avoid //googlesql/public:analyzer until the full Bazel graph is available
# (parser gen may need private module access). Override with GOOGLESQL_UNIFIED_BAZEL_TARGETS.
# See docs/libgooglesql-unified.md
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/../../.." && pwd)"
GOOGLESQL="$REPO_ROOT/internal/cmd/updater/googlesql"
C_ANCHOR_SRC="$REPO_ROOT/internal/ccall/go-googlesql-unified/c/googlesql_unified_anchor.c"
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

if [[ ! -f "$C_ANCHOR_SRC" ]]; then
  echo "missing anchor source: $C_ANCHOR_SRC" >&2
  exit 1
fi

# Space-separated list of Bazel labels (googlesql module).
TARGETS="${GOOGLESQL_UNIFIED_BAZEL_TARGETS:-//googlesql/base:logging}"

cd "$GOOGLESQL"

WORK="$(mktemp -d)"
cleanup() { rm -rf "$WORK"; }
trap cleanup EXIT
MARKER="$WORK/before_build"
touch "$MARKER"

echo "Building GoogleSQL targets: $TARGETS"
# shellcheck disable=SC2086
"$BAZEL" build $TARGETS \
  --cxxopt=-std=c++20 --host_cxxopt=-std=c++20 \
  --jobs="${BAZEL_JOBS:-8}"

BINROOT="$("$BAZEL" info bazel-bin | tr -d '\r')"

# Prefer objects produced or refreshed by this build (avoids stale *.pic.o from older analyses).
mapfile -t OBJS < <(
  find "$BINROOT/googlesql" -name '*.pic.o' -newer "$MARKER" 2>/dev/null | grep -Ev 'test|unittest|benchmark' | sort || true
)
if [[ ${#OBJS[@]} -eq 0 ]]; then
  mapfile -t OBJS < <(
    find "$BINROOT/googlesql" -name '*.pic.o' 2>/dev/null | grep -Ev 'test|unittest|benchmark' | sort || true
  )
fi
if [[ ${#OBJS[@]} -eq 0 ]] || [[ -z "${OBJS[0]:-}" ]]; then
  echo "no googlesql .pic.o under $BINROOT/googlesql (did the build produce objects?)" >&2
  exit 1
fi

echo "Compiling C anchor..."
"$CC" -c -o "$WORK/googlesql_unified_anchor.o" "$C_ANCHOR_SRC"

mkdir -p "$(dirname "$OUT")"
rm -f "$OUT"
# shellcheck disable=SC2086
ar crs "$OUT" "${OBJS[@]}" "$WORK/googlesql_unified_anchor.o"
echo "Wrote $OUT ($(ls -lh "$OUT" | awk '{print $5}'))"

LINK_NAME="$OUT_DIR/libgooglesql.a"
REL="$GOOS_GOARCH/libgooglesql.a"
ln -sfn "$REL" "$LINK_NAME"
echo "Symlink $LINK_NAME -> $REL"
