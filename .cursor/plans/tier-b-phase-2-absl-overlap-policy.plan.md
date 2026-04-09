---
name: Tier B Phase 2 — Abseil overlap policy
overview: Codify supported build-tag combinations for a single Abseil owner per link, align docs + verify script + CI (including verify-tier-b-cgo-policy on the Abseil workflow), and document contributor-facing mutual exclusion of googlesql_tier_b vs googlesql_tier_b_absl.
todos:
  - id: docs-single-owner-policy
    content: Stabilize docs/prebuilt-absl-overlap.md and align docs/tier-b-absl-protobuf.md, docs/prebuilt-cgo.md (and libgooglesql-unified.md overlap notes) — one Abseil owner per link, googlesql_tier_b vs googlesql_tier_b_absl mutual exclusion, unsupported combos table.
    status: pending
  - id: verify-script-doc-parity
    content: Re-verify scripts/verify-tier-b-cgo-tag-policy.sh output matches the doc tag matrix after any policy edit; keep lists in sync.
    status: pending
  - id: ci-absl-verify-preflight
    content: Add make verify-tier-b-cgo-policy to .github/workflows/go-tier-b-absl-prebuilt.yml (same preflight banner as go-tier-b-prebuilt.yml) before prebuilt-libs-absl / pilot tests.
    status: pending
  - id: readme-tier-b-pointer
    content: Update README.md or Tier B doc index with pointer to the tag matrix and explicit note that googlesql_tier_b + googlesql_tier_b_absl together is out of scope for Phase 2.
    status: pending
  - id: generators-policy-crosscheck
    content: When editing internal/ccall go-protobuf bind_tier_b.go or go-absl bind_tier_b_absl.go, cross-check tag wiring against docs/prebuilt-absl-overlap.md (mutually exclusive at package level).
    status: pending
  - id: optional-ci-enforcement
    content: "Optional follow-up: extend verification so CI can fail on forbidden tag combinations in go test/build — only after matrix and docs are stable (avoid false positives)."
    status: pending
isProject: false
---

# Phase 2: Abseil overlap policy (Tier B without amalgamation)

## Overview

**Goal:** Establish a single **Abseil owner** in any final link, mirroring the **single-owner protobuf** story (`libprotobuf_cgo.a` via `googlesql_tier_b`). Today `libprotobuf_cgo.a` merges Bazel-built protobuf (and related) objects that **already include Abseil**; linking `libabsl_cgo.a` in the **same** binary without object-level deduplication risks duplicate Abseil symbols.

**Phase 2 focus:** Codify which **build tag combinations** are supported, keep **`googlesql_tier_b_absl`** as the pilot path for **default (amalgamation) protobuf**—i.e. Tier B Abseil **without** Tier B protobuf—and wire **documentation + CI** so supported combinations are explicit and repeatable.

**Non-goals for Phase 2:** Implementing merged archives, object stripping, or enabling `googlesql_tier_b` + `googlesql_tier_b_absl` together (deferred until a product forces it; see `docs/prebuilt-absl-overlap.md`).

---

## Tag matrix (supported / unsupported)

Canonical policy lives in **`docs/prebuilt-absl-overlap.md`**. Summary:

| Tags (with `googlesql` as base) | Link `libabsl_cgo.a`? | Link `libprotobuf_cgo.a` (Tier B protobuf)? | Status |
|--------------------------------|----------------------|---------------------------------------------|--------|
| *(default, no Tier B tags)* | No | No | **Supported** — amalgamation path. |
| `googlesql_tier_b` | No (Abseil comes from protobuf archive) | Yes | **Supported** — protobuf Tier B; Abseil embedded in `libprotobuf_cgo.a`. |
| `googlesql_tier_b_absl` | Yes (migrated `go-absl` packages) | No | **Supported** — Abseil Tier B **pilot** with default protobuf; **do not** also enable `googlesql_tier_b`. |
| `googlesql_tier_b` **and** `googlesql_tier_b_absl` | Would pull both archives | Yes + separate Abseil archive | **Unsupported** — duplicate Abseil objects until dedup or single merged archive. |
| `googlesql_unified_prebuilt` | Per unified doc | N/A (partial stack) | **Supported** with constraints; not a full protobuf/Abseil replacement. |
| `googlesql_unified_prebuilt` **+** `googlesql_tier_b` (and/or careless overlap with Abseil archives) | Risk of duplicate / inconsistent native objects | — | **Unsupported** without audited single-owner plan. |

**Pilot rule:** Use **`googlesql_tier_b_absl`** for experiments and CI that exercise `libabsl_cgo.a` **only** when **not** building with **`googlesql_tier_b`**.

---

## CI integration steps

### Current state

| Asset | Role |
|-------|------|
| `scripts/verify-tier-b-cgo-tag-policy.sh` | Prints supported / unsupported combinations; **exits 0** (documentation / preflight). |
| `Makefile` target `verify-tier-b-cgo-policy` | Invokes the script. |
| `.github/workflows/go-tier-b-prebuilt.yml` | Manual `workflow_dispatch`: runs `verify-protobuf-tier-b-alignment`, **`verify-tier-b-cgo-policy`**, then `prebuilt-libs` + protobuf Tier B test. |
| `.github/workflows/go-tier-b-absl-prebuilt.yml` | Manual `workflow_dispatch`: `prebuilt-libs-absl` + pilot tests; **does not** currently run `verify-tier-b-cgo-policy`. |

### Planned work

1. **Treat policy as the contract** — Keep `docs/prebuilt-absl-overlap.md` and `docs/tier-b-absl-protobuf.md` aligned with the table above; any tag change in generators (`bind_tier_b*.go`) should cross-check this policy.
2. **CI matrix (documentation + execution)**  
   - **Row A — Tier B protobuf:** existing `go-tier-b-prebuilt.yml` (tags `googlesql`, `googlesql_tier_b`).  
   - **Row B — Tier B Abseil pilot:** `go-tier-b-absl-prebuilt.yml` (tags `googlesql`, `googlesql_tier_b_absl`) **without** building Tier B protobuf.  
   - Add **`make verify-tier-b-cgo-policy`** to the Abseil workflow so both manual pipelines print the same policy banner before native builds.
3. **Optional hardening (later sub-step):** If the team wants **enforcement** (not just printing), extend verification so CI can **fail** when a PR introduces a `go build` / test invocation that combines forbidden tags—only after the matrix and docs are stable (avoid false positives on partial packages).
4. **README / contributor path:** Ensure `README.md` (or Tier B doc index) points to the matrix and states that **duplicate Tier B protobuf + Tier B Abseil tags** are out of scope for Phase 2.

---

## Exit criteria

- [ ] **Written policy** is stable and single-sourced: `docs/prebuilt-absl-overlap.md` (and linked `docs/tier-b-absl-protobuf.md`, `docs/prebuilt-cgo.md` sections) explicitly state one Abseil owner per link and the `googlesql_tier_b` vs `googlesql_tier_b_absl` mutual exclusion.
- [ ] **Tag matrix** is duplicated in a machine-readable or CI-visible way: `scripts/verify-tier-b-cgo-tag-policy.sh` output matches the doc table (already aligned; re-verify on any edit).
- [ ] **CI matrix for supported combinations** is documented and runnable:
  - Tier B protobuf path: `go-tier-b-prebuilt.yml`.
  - Tier B Abseil pilot path: `go-tier-b-absl-prebuilt.yml` **including** `verify-tier-b-cgo-policy` preflight.
- [ ] **Pilot semantics** are clear: `googlesql_tier_b_absl` is validated with **default** protobuf (no `googlesql_tier_b`), matching migrated packages listed in `docs/prebuilt-cgo.md` / `docs/prebuilt-absl-overlap.md`.

---

## Risks

| Risk | Mitigation |
|------|------------|
| **Silent duplicate Abseil** if both tags appear in one `go test ./...` | Document forbidden combo; generators keep `bind_tier_b` / `bind_tier_b_absl` mutually exclusive at package level; consider stricter CI checks later. |
| **`libprotobuf_cgo.a` content drifts** (more Abseil embedded over time) | Re-run `nm … libprotobuf_cgo.a \| grep absl` when upgrading Bazel/protobuf; update overlap doc if symbol surface changes. |
| **`-Wl,--allow-multiple-definition`** masks real duplicates | Called out in `docs/prebuilt-absl-overlap.md`; Phase 2 does not remove the flag—track under native-build-pipeline / future merged archive. |
| **Unified prebuilt** combined with Tier B tags | Treat as unsupported overlap until a single-archive or audited merge exists (`docs/libgooglesql-unified.md`). |

---

## File references (go-googlesql)

| Path | Relevance |
|------|-----------|
| `docs/prebuilt-absl-overlap.md` | Primary policy: protobuf archive embeds Abseil; combination rules. |
| `docs/tier-b-absl-protobuf.md` | Tier B tags, Makefile targets, workflow pointers. |
| `docs/prebuilt-cgo.md` | Tier B protobuf + `googlesql_tier_b_absl` pilot list and overlap pointer. |
| `docs/native-build-pipeline.md` | Single-owner / merged-archive direction. |
| `docs/libgooglesql-unified.md` | Unified prebuilt constraints vs Tier B overlap. |
| `scripts/verify-tier-b-cgo-tag-policy.sh` | Supported / unsupported tag list for CI preflight. |
| `Makefile` | `verify-tier-b-cgo-policy`, `local/test-prebuilt`, `local/test-prebuilt-absl`, `prebuilt-libs`, `prebuilt-libs-absl`. |
| `.github/workflows/go-tier-b-prebuilt.yml` | CI row: protobuf Tier B. |
| `.github/workflows/go-tier-b-absl-prebuilt.yml` | CI row: Abseil Tier B pilot. |
| `internal/ccall/go-protobuf/protobuf/bind_tier_b.go` | Tier B protobuf link-only CGO. |
| `internal/ccall/go-absl/**/bind_tier_b_absl.go` | Tier B Abseil link-only CGO (pilot packages). |
| `internal/cmd/updater/googlesql/MODULE.bazel` | Abseil / protobuf Bazel pin (consistency with prebuilts). |

---

## Summary

Phase 2 delivers a **clear, enforced-by-documentation Abseil ownership model**: protobuf Tier B **or** Abseil Tier B pilot, not both, until deduplication exists—plus a **two-row CI story** (protobuf prebuilt workflow + Abseil prebuilt workflow) with shared **`verify-tier-b-cgo-policy`** preflight on both manual pipelines.