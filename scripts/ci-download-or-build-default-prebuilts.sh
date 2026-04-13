#!/usr/bin/env bash
# CI: populate libprotobuf_cgo.a + libgooglesql.a under a go-googlesql checkout.
# linux/amd64: try GitHub Release go-googlesql-prebuilts-default-linux_amd64-<ver>.tar.gz
# else: Task + Bazel (needs task, bazelisk, clang, ensure-googlesql-workspace).
#
# Usage: bash scripts/ci-download-or-build-default-prebuilts.sh /abs/or/rel/path/to/go-googlesql
# Env: GOOGLESQL_VERSION=v0.5.6 (required if checkout is not a matching tag)
set -euo pipefail

if [ -z "${1:-}" ]; then
	echo "usage: ci-download-or-build-default-prebuilts.sh <path-to-go-googlesql-checkout>" >&2
	exit 1
fi
REPO_ROOT="$(cd "$1" && pwd)"
cd "$REPO_ROOT"

VER="${GOOGLESQL_VERSION:-}"
if [ -z "$VER" ]; then
	if [ -n "${GITHUB_REF_NAME:-}" ] && echo "${GITHUB_REF_NAME}" | grep -q '^v'; then
		VER="$GITHUB_REF_NAME"
	else
		VER="$(git describe --tags --exact-match 2>/dev/null || true)"
	fi
fi
if [ -z "$VER" ]; then
	echo "error: set GOOGLESQL_VERSION (e.g. v0.5.6) to match go.mod" >&2
	exit 1
fi

GOOS="$(go env GOOS)"
GOARCH="$(go env GOARCH)"

if [ "$GOOS" = "linux" ] && [ "$GOARCH" = "amd64" ]; then
	url="https://github.com/vantaboard/go-googlesql/releases/download/${VER}/go-googlesql-prebuilts-default-linux_amd64-${VER}.tar.gz"
	tmp="$(mktemp)"
	if curl -fsSL --retry 3 --retry-delay 2 "$url" -o "$tmp"; then
		tar -xzf "$tmp" -C "$REPO_ROOT"
		rm -f "$tmp"
		bash scripts/verify-prebuilt-protobuf.sh
		bash scripts/verify-prebuilt-googlesql-unified.sh
		echo "ok: release tarball for ${VER}"
		exit 0
	fi
	rm -f "$tmp"
fi

echo "Building default prebuilts via Bazel (${VER} on ${GOOS}_${GOARCH})..."
command -v task >/dev/null 2>&1 || {
	echo "error: install Task (https://taskfile.dev)" >&2
	exit 1
}
export CC="${CC:-clang}"
export CXX="${CXX:-clang++}"
bash scripts/ensure-googlesql-workspace.sh
task verify:protobuf-tier-b verify:tier-b-cgo-policy \
	prebuilt:protobuf verify:prebuilt-protobuf \
	prebuilt:googlesql-unified verify:prebuilt-googlesql-unified
