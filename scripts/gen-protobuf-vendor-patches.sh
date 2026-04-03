#!/usr/bin/env bash
# Regenerate internal/ccall/protobuf/patches/01-vendor-delta.patch from the Bazel
# protobuf cache vs the current vendored tree. Baseline = upstream copy + amalgamation
# only (same as a fresh copy + go run ./internal/cmd/vendorpatch -amalgamation-only).
#
# Requires: repository root layout, internal/cmd/updater/cache/.../com_google_protobuf,
#           git, python3, go.
#
# Usage (from repository root):
#   ./scripts/gen-protobuf-vendor-patches.sh
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cache="${root}/internal/cmd/updater/cache/external/com_google_protobuf/src/google/protobuf"
baseline="${root}/.genpatch-baseline/internal/ccall/protobuf/google/protobuf"
vendored="${root}/internal/ccall/protobuf/google/protobuf"

if [[ ! -d "$cache" ]]; then
  echo "error: missing protobuf cache: $cache" >&2
  exit 1
fi

rm -rf "${root}/.genpatch-baseline"
mkdir -p "$baseline"
cp -a "${cache}/." "$baseline/"

(
  cd "$root"
  go run ./internal/cmd/vendorpatch -ccall "${root}/.genpatch-baseline/internal/ccall" -amalgamation-only
)

patch_out="${root}/internal/ccall/protobuf/patches/01-vendor-delta.patch"
(
  cd "$root"
  # Paths must be repo-relative so diff headers match git apply expectations.
  # git diff exits 1 when there are differences.
  raw="$(
    git diff --no-index -- .genpatch-baseline/internal/ccall/protobuf/google/protobuf internal/ccall/protobuf/google/protobuf 2>/dev/null || true
  )"
  printf '%s\n' "$raw" | sed '/^old mode /d; /^new mode /d' \
    | sed 's|^diff --git a/\.genpatch-baseline/internal/ccall/|diff --git a/internal/ccall/|; s|^--- a/\.genpatch-baseline/internal/ccall/|--- a/internal/ccall/|' \
    | python3 -c '
import re, sys
raw = sys.stdin.read()
chunks = re.split(r"(?=^diff --git )", raw, flags=re.M)
out = []
for ch in chunks:
    if not ch.strip():
        continue
    if ch.startswith("diff --git "):
        body = "".join(ch.splitlines(True)[1:])
        if "--- " not in body:
            continue
    out.append(ch)
sys.stdout.write("".join(out))
' > "$patch_out"
)

echo "Wrote $patch_out ($(wc -l < "$patch_out") lines)"
echo "Validate: rm -rf /tmp/pbapply && mkdir -p /tmp/pbapply/internal/ccall && rsync -a ${root}/.genpatch-baseline/internal/ccall/ /tmp/pbapply/internal/ccall/ && (cd /tmp/pbapply && git init -q && git apply \"$patch_out\") && diff -rq /tmp/pbapply/internal/ccall/protobuf/google/protobuf \"$vendored\""
