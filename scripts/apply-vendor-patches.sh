#!/usr/bin/env bash
# Apply mechanical vendored-tree patches: protobuf port_def/port_undef amalgamation,
# then optional git apply of internal/ccall/protobuf/patches/*.patch (requires git).
# See docs/protobuf-vendoring.md.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
exec go run "${root}/internal/cmd/vendorpatch"
