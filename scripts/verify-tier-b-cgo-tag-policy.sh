#!/usr/bin/env bash
# Documents supported combinations of CGO Tier B build tags.
# Canonical policy: docs/prebuilt-absl-overlap.md
# Exits 0 unless VERIFY_TIER_B_CGO_POLICY_ENFORCE=1 is set (reserved for future enforcement).
set -euo pipefail
cat <<'EOF'
Supported / unsupported Tier B tag combinations (go-googlesql)

  googlesql (default; no Tier B tags)
    Amalgamation path. Does not link libprotobuf_cgo.a or libabsl_cgo.a.

  googlesql + googlesql_tier_b
    Link libprotobuf_cgo.a; Abseil object code is embedded in that archive.
    Requires protobuf vendor/codegen aligned with Bazel @com_google_protobuf.

  googlesql + googlesql_tier_b_absl
    Link libabsl_cgo.a for migrated go-absl packages; use default protobuf (no googlesql_tier_b).

  googlesql + googlesql_unified_prebuilt
    Link libgooglesql.a (partial stack / smoke). See docs/libgooglesql-unified.md.

Unsupported in one binary (duplicate or inconsistent native objects):
  googlesql_tier_b + googlesql_tier_b_absl
  googlesql_unified_prebuilt + googlesql_tier_b (and/or careless overlap with Tier B Abseil archives)
    Without an audited single-owner / dedup plan — see docs/prebuilt-absl-overlap.md

Full matrix: docs/prebuilt-absl-overlap.md (canonical).
EOF

if [[ "${VERIFY_TIER_B_CGO_POLICY_ENFORCE:-}" == "1" ]]; then
  echo "verify-tier-b-cgo-tag-policy: VERIFY_TIER_B_CGO_POLICY_ENFORCE=1 is reserved for future automated checks (e.g. scanning CI or build scripts for forbidden tag pairs). Not implemented yet; exiting 0." >&2
fi
exit 0
