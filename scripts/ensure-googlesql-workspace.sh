#!/usr/bin/env bash
# Clone or update google/googlesql at internal/cmd/updater/googlesql.ref into
# internal/cmd/updater/googlesql (Bazel workspace for prebuilts and scripts).
set -euo pipefail
ROOT="$(git rev-parse --show-toplevel 2>/dev/null || true)"
if [[ -z "$ROOT" ]]; then
	ROOT="$(cd "$(dirname "$0")/.." && pwd)"
fi
REF_FILE="${ROOT}/internal/cmd/updater/googlesql.ref"
TARGET="${ROOT}/internal/cmd/updater/googlesql"
REF=$(tr -d ' \n\r' <"${REF_FILE}")

if [[ -d "${TARGET}/.git" ]]; then
	git -C "${TARGET}" fetch --depth 1 origin "refs/tags/${REF}:refs/tags/${REF}" 2>/dev/null || \
		git -C "${TARGET}" fetch --depth 1 origin tag "${REF}" || true
	git -C "${TARGET}" checkout -q "${REF}"
	exit 0
fi

rm -rf "${TARGET}"
mkdir -p "$(dirname "${TARGET}")"
git clone --depth 1 --branch "${REF}" https://github.com/google/googlesql.git "${TARGET}"
