#!/usr/bin/env bash
# Link and run a tiny C program against libgooglesql.a (see docs/libgooglesql-unified.md).
set -euo pipefail
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"

bash scripts/verify-prebuilt-googlesql-unified.sh

INC="$REPO_ROOT/internal/ccall/go-googlesql-unified/include"
SMOKE_SRC="$REPO_ROOT/internal/ccall/go-googlesql-unified/smoke/smoke_main.c"
LIBDIR="$REPO_ROOT/internal/ccall/go-googlesql-unified/lib"
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT

: "${CC:=clang}"
"$CC" -std=c11 -I"$INC" -o "$WORK/smoke" "$SMOKE_SRC" \
  -L"$LIBDIR" -lgooglesql -lz -lstdc++ -ldl -lpthread
"$WORK/smoke"
