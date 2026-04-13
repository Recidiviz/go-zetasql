#!/usr/bin/env bash
# Export Bazel output_base/external, execution_root (for bazel-bin), and googlesql sources
# into a host-mounted directory (default /tmp) for internal/cmd/updater/main.go.
set -euo pipefail

DEST="${1:-/tmp}"
if [[ ! -f /bazel-meta/output_base.txt ]] || [[ ! -f /bazel-meta/execution_root.txt ]]; then
  echo "export.sh: missing /bazel-meta/*.txt (run inside the googlesql-updater image)" >&2
  exit 1
fi
OUTPUT_BASE=$(tr -d '\n\r' </bazel-meta/output_base.txt)
EXEC_ROOT=$(tr -d '\n\r' </bazel-meta/execution_root.txt)

mkdir -p "${DEST}/external"
cp -a "${OUTPUT_BASE}/external/." "${DEST}/external/"

mkdir -p "${DEST}/execroot/googlesql"
cp -a "${EXEC_ROOT}/." "${DEST}/execroot/googlesql/"

mkdir -p "${DEST}/googlesql"
cp -a /googlesql/googlesql "${DEST}/googlesql/"
