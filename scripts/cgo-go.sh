#!/usr/bin/env bash
# Run go build/test for this repo with low peak RAM:
#   - GOMAXPROCS (default 2) limits concurrent Go workers
#   - go -p 1 serializes package builds (big win for CGO / huge bind.cc units)
#   - optional systemd scope MemoryMax (default 22G) when systemd-run works
#     (env: GOOGLESQL_CGO_MEMORY_MAX)
#
# Tune for your machine:
#   GOOGLESQL_CGO_MEMORY_MAX=20G ./scripts/cgo-go.sh test ./...
#   GOMAXPROCS=1 ./scripts/cgo-go.sh build -o /tmp/z.out .
set -euo pipefail

: "${GOMAXPROCS:=2}"
: "${GOOGLESQL_CGO_MEMORY_MAX:=22G}"
export GOMAXPROCS

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$repo_root"

run_with_limit() {
  local -a cmd=(env CGO_ENABLED=1 "$@")
  if command -v systemd-run >/dev/null 2>&1; then
    if systemd-run --user --scope -p "MemoryMax=${GOOGLESQL_CGO_MEMORY_MAX}" --same-dir -- "${cmd[@]}" 2>/dev/null; then
      return 0
    fi
    if systemd-run --scope -p "MemoryMax=${GOOGLESQL_CGO_MEMORY_MAX}" --same-dir -- "${cmd[@]}" 2>/dev/null; then
      return 0
    fi
  fi
  "${cmd[@]}"
}

if [ "${1:-}" = "" ]; then
  echo "Usage: $0 {build|test} [go arguments...]" >&2
  echo "Environment: GOMAXPROCS (default: 2), GOOGLESQL_CGO_MEMORY_MAX (default: 22G for systemd-run)" >&2
  exit 1
fi
sub="$1"
shift

case "$sub" in
  build) run_with_limit go build -tags googlesql,googlesql_unified_prebuilt -p 1 "$@" ;;
  test)  run_with_limit go test  -tags googlesql,googlesql_unified_prebuilt -p 1 -count=1 "$@" ;;
  *)
    echo "Usage: $0 {build|test} [arguments passed to go build or go test]" >&2
    echo "Environment: GOMAXPROCS (default: 2), GOOGLESQL_CGO_MEMORY_MAX (default: 22G for systemd-run)" >&2
    exit 1
    ;;
esac
