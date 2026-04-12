#!/usr/bin/env bash
# Regenerate C++ protobuf outputs under internal/ccall:
#   - googlesql/**/*.pb.{h,cc}   (excludes testdata/)
#   - googleapis/**/*.pb.{h,cc}  (when .proto files are present)
#   - proto/**/*.pb.{h,cc}       (differential-privacy protos under internal/ccall/proto)
#
# Uses the same protoc as MODULE.bazel @com_google_protobuf when PROTOC is unset: builds
# @com_google_protobuf//:protoc in internal/cmd/updater/googlesql, or uses .cache-protoc /
# PROTOC from the environment.
#
# Note: *.proto under internal/ccall are gitignored; sync them from the GoogleSQL submodule /
# updater (see docs/protobuf-vendoring.md) before running this script.
#
# Usage (from repo root): bash scripts/regenerate-ccall-cpp-protos.sh
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
GOOGLESQL="$REPO_ROOT/internal/cmd/updater/googlesql"
cd "$REPO_ROOT"

CCALL="$REPO_ROOT/internal/ccall"
PROTOS=()

append_protos_from_find() {
	local f
	while IFS= read -r -d '' f; do
		PROTOS+=("$f")
	done < <("$@" -print0)
}

if [[ -d "$CCALL/googlesql" ]]; then
	append_protos_from_find find "$CCALL/googlesql" -name '*.proto' ! -path '*/testdata/*'
fi
if [[ -d "$CCALL/googleapis" ]]; then
	append_protos_from_find find "$CCALL/googleapis" -name '*.proto'
fi
if [[ -d "$CCALL/proto" ]]; then
	append_protos_from_find find "$CCALL/proto" -name '*.proto'
fi

if [[ ${#PROTOS[@]} -eq 0 ]]; then
	echo "No .proto files found under:" >&2
	echo "  $CCALL/googlesql  (excluding testdata)" >&2
	echo "  $CCALL/googleapis" >&2
	echo "  $CCALL/proto" >&2
	echo "Sync sources from the updater / submodule, then re-run." >&2
	exit 1
fi

if [[ -n "${PROTOC:-}" ]]; then
	:
elif [[ -x "${REPO_ROOT}/.cache-protoc" ]]; then
	PROTOC="${REPO_ROOT}/.cache-protoc"
else
	if ! command -v bazelisk >/dev/null 2>&1 && ! command -v bazel >/dev/null 2>&1; then
		echo "Set PROTOC=... or install bazelisk/bazel to build protoc" >&2
		exit 1
	fi
	BAZEL="${BAZEL:-$(command -v bazelisk || command -v bazel)}"
	(cd "$GOOGLESQL" && "$BAZEL" build @com_google_protobuf//:protoc --cxxopt=-std=c++20 --host_cxxopt=-std=c++20)
	BINROOT="$(cd "$GOOGLESQL" && "$BAZEL" info bazel-bin | tr -d '\r')"
	PROTOC="$BINROOT/external/protobuf~/protoc"
	if [[ ! -x "$PROTOC" ]]; then
		PROTOC="$BINROOT/external/com_google_protobuf/protoc"
	fi
fi
if [[ ! -x "$PROTOC" ]]; then
	echo "protoc not executable: $PROTOC" >&2
	exit 1
fi
echo "Using protoc: $PROTOC"

PROTO_RELPATHS=()
local_path=""
for f in "${PROTOS[@]}"; do
	local_path="${f#"$CCALL"/}"
	if [[ "$local_path" == "$f" ]]; then
		echo "Proto path not under $CCALL: $f" >&2
		exit 1
	fi
	PROTO_RELPATHS+=("$local_path")
done

"$PROTOC" \
	-I "$CCALL" \
	-I "$CCALL/protobuf" \
	--cpp_out="$CCALL" \
	"${PROTO_RELPATHS[@]}"

echo "Regenerated ${#PROTOS[@]} proto(s) under internal/ccall (googlesql, googleapis, proto)."
