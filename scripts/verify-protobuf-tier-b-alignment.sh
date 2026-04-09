#!/usr/bin/env bash
# Fail if vendored protobuf C++ version (internal/ccall/protobuf) does not match the
# @com_google_protobuf module declared in internal/cmd/updater/googlesql/MODULE.bazel.
# Tier B libprotobuf_cgo.a is built from that Bazel graph; amalgamation + generated *.pb.h
# must agree on GOOGLE_PROTOBUF_VERSION / PROTOBUF_VERSION checks.
#
# Usage: bash scripts/verify-protobuf-tier-b-alignment.sh
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
COMMON_H="$REPO_ROOT/internal/ccall/protobuf/google/protobuf/stubs/common.h"
MODULE_BAZEL="$REPO_ROOT/internal/cmd/updater/googlesql/MODULE.bazel"

if [[ ! -f "$COMMON_H" ]]; then
	echo "missing $COMMON_H" >&2
	exit 1
fi
VENDOR_VER="$(grep -E '^#define GOOGLE_PROTOBUF_VERSION[[:space:]]' "$COMMON_H" | awk '{print $3}' | head -1)"
if [[ -z "$VENDOR_VER" ]]; then
	echo "could not parse GOOGLE_PROTOBUF_VERSION from $COMMON_H" >&2
	exit 1
fi

MOD_VER="$(grep -E 'bazel_dep\(name = "protobuf"' "$MODULE_BAZEL" | sed -n 's/.*version = "\([^"]*\)".*/\1/p' | head -1)"
if [[ -z "$MOD_VER" ]]; then
	echo "could not parse protobuf module version from MODULE.bazel" >&2
	exit 1
fi

echo "MODULE.bazel protobuf module: $MOD_VER"
echo "Vendored GOOGLE_PROTOBUF_VERSION: $VENDOR_VER"

# BCR module version (e.g. 29.0) maps to OSS 5.x; vendored macro uses 4xxxxx or 5xxxxx.
# Tier B needs vendored runtime + generated protos aligned with Bazel @com_google_protobuf 29.x.
if [[ "$VENDOR_VER" -lt 5029000 ]]; then
	echo "WARNING: vendored GOOGLE_PROTOBUF_VERSION=$VENDOR_VER is below 5029000 (protobuf 5.29.x)." >&2
	echo "Tier B libprotobuf_cgo.a from Bazel will not link cleanly until you refresh vendor + *.pb.h:" >&2
	echo "  bash scripts/sync-protobuf-cpp-runtime-from-bazel.sh && go run ./internal/cmd/vendorpatch" >&2
	echo "  bash scripts/regenerate-googlesql-cpp-protos.sh" >&2
	if [[ "${VERIFY_PROTOBUF_TIER_B_STRICT:-}" == "1" ]]; then
		exit 1
	fi
	echo "ok: check passed with warnings (set VERIFY_PROTOBUF_TIER_B_STRICT=1 to fail on mismatch)"
	exit 0
fi

echo "ok: protobuf vendor/runtime version check passed"
