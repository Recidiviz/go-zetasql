#!/usr/bin/env bash
# Sync vendored internal/ccall/protobuf/google/protobuf from the Bazel @com_google_protobuf
# checkout used by internal/cmd/updater/googlesql (MODULE.bazel). Run after `bazel build
# @com_google_protobuf//:protobuf` so the external tree exists.
#
# After rsync you MUST:
#   1. go run ./internal/cmd/vendorpatch              # amalgamation + patches/*.patch
#   2. Rebase or drop stale patches under internal/ccall/protobuf/patches/ if git apply fails.
#   3. bash scripts/regenerate-ccall-cpp-protos.sh
#
# Protobuf 29+ changes port_def.inc layout; amalgamation guards in vendorpatch must match.
# See docs/prebuilt-cgo.md (protobuf alignment) and docs/protobuf-vendoring.md.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
GOOGLESQL="$REPO_ROOT/internal/cmd/updater/googlesql"
DEST="$REPO_ROOT/internal/ccall/protobuf/google/protobuf"

if ! command -v bazelisk >/dev/null 2>&1 && ! command -v bazel >/dev/null 2>&1; then
	echo "bazelisk or bazel is required" >&2
	exit 1
fi
BAZEL="${BAZEL:-$(command -v bazelisk || command -v bazel)}"

cd "$GOOGLESQL"
OUTPUT_BASE="$("$BAZEL" info output_base | tr -d '\r')"
PROTO_SRC=""
for d in "$OUTPUT_BASE/external/protobuf~" "$OUTPUT_BASE/external/com_google_protobuf"; do
	if [[ -d "$d/src/google/protobuf" ]]; then
		PROTO_SRC="$d/src/google/protobuf"
		break
	fi
done
if [[ -z "$PROTO_SRC" ]]; then
	echo "Could not find Bazel protobuf src under \$OUTPUT_BASE/external (build @com_google_protobuf//:protobuf first)" >&2
	exit 1
fi

echo "Syncing $PROTO_SRC/ -> $DEST/"
rsync -a "$PROTO_SRC/" "$DEST/"
echo "Done. Next: (cd $REPO_ROOT && go run ./internal/cmd/vendorpatch)"
