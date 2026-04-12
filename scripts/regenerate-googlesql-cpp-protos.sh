#!/usr/bin/env bash
# Historical name: regenerates all ccall C++ protos (googlesql, googleapis, proto).
# See scripts/regenerate-ccall-cpp-protos.sh.
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
exec bash "$SCRIPT_DIR/regenerate-ccall-cpp-protos.sh" "$@"
