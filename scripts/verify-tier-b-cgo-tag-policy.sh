#!/usr/bin/env bash
# Documents supported combinations of CGO Tier B build tags (see docs/prebuilt-absl-overlap.md).
# Exits 0 always; intended for CI documentation / preflight.
set -euo pipefail
cat <<'EOF'
Supported tag combinations (go-googlesql):

  googlesql
    Default amalgamation build.

  googlesql + googlesql_tier_b
    Link libprotobuf_cgo.a; requires protobuf vendor/codegen aligned with Bazel @com_google_protobuf.

  googlesql + googlesql_tier_b_absl
    Link libabsl_cgo.a for migrated go-absl packages; do not combine with googlesql_tier_b in the
    same binary (duplicate Abseil objects — see prebuilt-absl-overlap.md).

  googlesql + googlesql_unified_prebuilt
    Link libgooglesql.a from extract_googlesql_unified_lib.sh (smoke / partial stack).

Unsupported in one link:
  googlesql_tier_b + googlesql_tier_b_absl
  googlesql_unified_prebuilt + googlesql_tier_b (without a dedup / single-archive plan)
EOF
