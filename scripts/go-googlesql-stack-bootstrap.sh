#!/usr/bin/env bash
# Bootstrap CGO + linker env for the default stack (googlesql + googlesql_unified_prebuilt).
# Intended for downstream repos (go-googlesqlite, bigquery-emulator) and CI shells that
# do not use go-googlesql's Taskfile or direnv.
#
# Usage (bash):
#   export GO_GOOGLESQL_ROOT=/path/to/go-googlesql   # optional if this file lives in that repo
#   source /path/to/go-googlesql/scripts/go-googlesql-stack-bootstrap.sh
#   cd /path/to/downstream && go test -tags "$GOOGLESQL_BUILD_TAGS" -p 1 -count=1 ./...
#
# This sets the same variables Task uses: CGO_LDFLAGS_ALLOW, CGO_LDFLAGS, CGO_CXXFLAGS,
# CGO_ENABLED, caches under GO_CACHE_ROOT, CC/CXX, GOOGLESQL_BUILD_TAGS.
#
# Note: Sourcing from zsh without BASH_SOURCE can break go-googlesql `.envrc` path
# resolution; prefer `bash -c 'source ... && go test ...'` or run from bash.
set -euo pipefail

_GOOGLESQL_STACK_BOOTSTRAP_DIR="$(cd "$(dirname "${BASH_SOURCE[0]:-$0}")" && pwd)"
export GO_GOOGLESQL_ROOT="${GO_GOOGLESQL_ROOT:-$(cd "$_GOOGLESQL_STACK_BOOTSTRAP_DIR/.." && pwd)}"

# shellcheck disable=SC1091
source "$GO_GOOGLESQL_ROOT/scripts/go-googlesql-env.sh"
go_googlesql_env_export

export CGO_ENABLED=1
export CGO_CXXFLAGS="${CGO_CXXFLAGS:-$CGO_CXXFLAGS_PREBUILT}"
export CGO_LDFLAGS_ALLOW="${CGO_LDFLAGS_ALLOW:-$CGO_LDFLAGS_ALLOW_LIST}"
export CGO_LDFLAGS="${CGO_LDFLAGS:-$CGO_LDFLAGS_BASE}"
