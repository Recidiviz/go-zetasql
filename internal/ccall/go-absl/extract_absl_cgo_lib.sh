#!/usr/bin/env bash
# Build @com_google_absl cc_library targets via Bazel in the GoogleSQL submodule, then merge
# *.pic.o from the abseil-cpp output tree into lib/$(go env GOOS)_$(go env GOARCH)/libabsl_cgo.a.
#
# Requires: bash, bazelisk or bazel, ar, clang++.
# See docs/prebuilt-cgo.md, docs/prebuilt-absl-overlap.md, docs/native-build-pipeline.md.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/../../.." && pwd)"
GOOGLESQL="$REPO_ROOT/internal/cmd/updater/googlesql"
cd "$GOOGLESQL"

export CC="${CC:-clang}"
export CXX="${CXX:-clang++}"

if ! command -v bazelisk >/dev/null 2>&1 && ! command -v bazel >/dev/null 2>&1; then
  echo "bazelisk or bazel is required" >&2
  exit 1
fi
BAZEL="${BAZEL:-$(command -v bazelisk || command -v bazel)}"

mapfile -t TARGETS < <(
  "$BAZEL" query 'kind(cc_library, @com_google_absl//absl/...)' 2>/dev/null | grep -viE \
    '_test$|/test|benchmark|_benchmark|_test_|_testing|_helpers|mock_|_mock|test_util|test_common' || true
)
if [[ ${#TARGETS[@]} -eq 0 ]]; then
  echo "no absl cc_library targets from bazel query" >&2
  exit 1
fi

echo "Building ${#TARGETS[@]} @com_google_absl cc_library targets..."
"$BAZEL" build "${TARGETS[@]}" \
  --cxxopt=-std=c++20 --host_cxxopt=-std=c++20 \
  --jobs="${BAZEL_JOBS:-8}"

BINROOT="$("$BAZEL" info bazel-bin | tr -d '\r')"
mapfile -t OBJS < <(
  find "$BINROOT" -path '*abseil-cpp*' -name '*.pic.o' 2>/dev/null | grep -Ev 'test|unittest|benchmark' | sort || true
)
if [[ ${#OBJS[@]} -eq 0 ]] || [[ -z "${OBJS[0]:-}" ]]; then
  echo "no absl .pic.o under $BINROOT (abseil-cpp*)" >&2
  exit 1
fi

OUT="$REPO_ROOT/internal/ccall/go-absl/lib/$(go env GOOS)_$(go env GOARCH)/libabsl_cgo.a"
mkdir -p "$(dirname "$OUT")"
rm -f "$OUT"
# shellcheck disable=SC2086
ar crs "$OUT" "${OBJS[@]}"
echo "Wrote $OUT ($(ls -lh "$OUT" | awk '{print $5}'))"

LINK_NAME="$REPO_ROOT/internal/ccall/go-absl/lib/libabsl_cgo.a"
REL="$(go env GOOS)_$(go env GOARCH)/libabsl_cgo.a"
ln -sfn "$REL" "$LINK_NAME"
echo "Symlink $LINK_NAME -> $REL"
