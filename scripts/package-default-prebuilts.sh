#!/usr/bin/env bash
# Package the default unified-prebuilt native trees for release artifacts or CI handoff.
# Includes:
#   - internal/ccall/go-protobuf/protobuf/lib/  (libprotobuf_cgo.a, libc++ copies on Linux)
#   - internal/ccall/go-googlesql-unified/lib/ (libgooglesql.a)
# Plus go-googlesql-prebuilts-manifest.json at repo root (tag, sha, GOOS_GOARCH).
#
# Preconditions: `task prebuilt:protobuf` and `task prebuilt:googlesql-unified` (or CI equivalent).
# Usage: run from repo root. Optional: OUTPUT_NAME, GIT_TAG, GIT_SHA (else from git / env).
set -euo pipefail
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
PROTO_DIR="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib"
UNI_DIR="$REPO_ROOT/internal/ccall/go-googlesql-unified/lib"
if [[ ! -d "$PROTO_DIR/$GOOS_GOARCH" ]] || [[ ! -f "$PROTO_DIR/$GOOS_GOARCH/libprotobuf_cgo.a" ]]; then
	echo "error: expected protobuf prebuilt at $PROTO_DIR/$GOOS_GOARCH/libprotobuf_cgo.a" >&2
	echo "Run: task prebuilt:protobuf" >&2
	exit 1
fi
if [[ ! -d "$UNI_DIR/$GOOS_GOARCH" ]] || [[ ! -f "$UNI_DIR/$GOOS_GOARCH/libgooglesql.a" ]]; then
	echo "error: expected unified prebuilt at $UNI_DIR/$GOOS_GOARCH/libgooglesql.a" >&2
	echo "Run: task prebuilt:googlesql-unified" >&2
	exit 1
fi

GIT_TAG="${GIT_TAG:-${GITHUB_REF_NAME:-}}"
if [[ -z "$GIT_TAG" ]] && git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
	GIT_TAG="$(git describe --tags --always --dirty 2>/dev/null || true)"
fi
GIT_SHA="${GIT_SHA:-${GITHUB_SHA:-}}"
if [[ -z "$GIT_SHA" ]] && git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
	GIT_SHA="$(git rev-parse HEAD 2>/dev/null || true)"
fi
BUILT_AT="$(date -u +"%Y-%m-%dT%H:%M:%SZ")"

MANIFEST="$REPO_ROOT/go-googlesql-prebuilts-manifest.json"
cat >"$MANIFEST" <<EOF
{
  "schema_version": 1,
  "artifact": "go-googlesql-default-prebuilts",
  "goos_goarch": "$GOOS_GOARCH",
  "git_tag": "${GIT_TAG:-unknown}",
  "git_sha": "${GIT_SHA:-unknown}",
  "built_at": "$BUILT_AT",
  "paths": [
    "internal/ccall/go-protobuf/protobuf/lib",
    "internal/ccall/go-googlesql-unified/lib"
  ],
  "build_tags": "googlesql,googlesql_unified_prebuilt"
}
EOF

OUT="${OUTPUT_NAME:-go-googlesql-prebuilts-default-${GOOS_GOARCH}.tar.gz}"
tar -C "$REPO_ROOT" -czf "$REPO_ROOT/$OUT" \
	internal/ccall/go-protobuf/protobuf/lib \
	internal/ccall/go-googlesql-unified/lib \
	go-googlesql-prebuilts-manifest.json
rm -f "$MANIFEST"
echo "wrote $REPO_ROOT/$OUT"
ls -la "$REPO_ROOT/$OUT"
