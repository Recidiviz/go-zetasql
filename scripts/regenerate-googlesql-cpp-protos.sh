#!/usr/bin/env bash
# Regenerate internal/ccall/googlesql/**/*.pb.{h,cc} using protoc from the same revision as
# MODULE.bazel @com_google_protobuf (protobuf 29.x today). Requires a matching vendored
# internal/ccall/protobuf runtime (see scripts/sync-protobuf-cpp-runtime-from-bazel.sh).
#
# PROTOC may be set to a host protoc; otherwise builds @com_google_protobuf//:protoc in the
# GoogleSQL submodule and uses the binary from bazel-bin.
#
# Usage (from repo root): bash scripts/regenerate-googlesql-cpp-protos.sh
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
GOOGLESQL="$REPO_ROOT/internal/cmd/updater/googlesql"
cd "$REPO_ROOT"

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

mapfile -t PROTOS < <(find "$REPO_ROOT/internal/ccall/googlesql" -name '*.proto' | sort)

# -I internal/ccall: googlesql/... imports
# -I internal/ccall/protobuf: google/protobuf/*.proto
"$PROTOC" \
	-I "$REPO_ROOT/internal/ccall" \
	-I "$REPO_ROOT/internal/ccall/protobuf" \
	--cpp_out="$REPO_ROOT/internal/ccall" \
	"${PROTOS[@]}"

echo "Regenerated ${#PROTOS[@]} proto(s) under internal/ccall/googlesql"
