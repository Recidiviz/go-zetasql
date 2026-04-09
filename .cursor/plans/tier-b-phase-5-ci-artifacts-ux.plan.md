---
name: Tier B Phase 5 — CI, artifacts, docs, downstream
overview: Reliable Bazel-backed CI with cache reuse; prebuilt `.a` artifacts and clear build tags for contributors without Bazel; README and prebuilt/native docs positioning amalgamation as legacy; align go-googlesqlite and bigquery-emulator once the Tier B contract is stable.
todos:
  - id: phase5-ci-inventory-cache
    content: Inventory workflows (go.yml, Tier B / unified prebuilt YAMLs, release.yml); document cache keys and cold vs warm CI times for Tier B jobs
    status: completed
  - id: phase5-bazel-cache-standardize
    content: Standardize Bazel cache restore/save (or remote cache) on every Bazel job; document cache failure fallback; optional split analysis vs full build
    status: completed
  - id: phase5-prebuilt-artifacts-ci
    content: Align prebuilt artifact names, triples, layout, and extraction scripts with CI outputs; add SHA256SUMS (or equivalent) for release/nightly sets
    status: completed
  - id: phase5-no-bazel-consumer-gate
    content: Add or extend a CI job — no Bazel, prebuilts in documented paths, go test/build with default prebuilt-oriented tags; decide required vs optional and flip to required when stable
    status: completed
  - id: phase5-publishing-channel
    content: Choose/implement primary channel (e.g. tagged GitHub Release assets per platform); wire release workflow if needed; document URLs in README/prebuilt docs
    status: completed
  - id: phase5-readme-ux
    content: README — quick start (prebuilt-first), build matrix table, links to prebuilt-cgo.md and native-build-pipeline.md
    status: completed
  - id: phase5-docs-native-pipeline
    content: Update docs/native-build-pipeline.md — Bazel to static archives, CGO/single-owner overlap, legacy amalgamation subsection
    status: completed
  - id: phase5-docs-prebuilt-cgo
    content: Update docs/prebuilt-cgo.md — default tags with prebuilts, path without prebuilts, amalgamation as legacy
    status: completed
  - id: phase5-docs-cross-cutting
    content: Cross-cutting docs — troubleshooting (missing .a, arch, mixed tags); version/tarball to git tag mapping
    status: completed
  - id: phase5-downstream-googlesqlite
    content: go-googlesqlite — bump module, align tags/CGO, CI for prebuilt path, sqlite caveats in docs
    status: completed
  - id: phase5-downstream-emulator-ui
    content: bigquery-emulator (and UI if applicable) — same alignment, integration tests vs prebuilts, release notes on contract changes; READMEs point at Phase 5 docs
    status: pending
  - id: phase5-exit-criteria
    content: Verify exit criteria — prebuilt quick path on clean machine, amalgamation gated behind explicit legacy tag, stable contract for downstream PRs (changelog for integrators)
    status: completed
isProject: false
---

# Phase 5 — Tier B (no amalgamation): CI, artifacts, docs, downstream

**Roadmap:** go-googlesql “Tier B without amalgamation”  
**Repository:** `go-googlesql` (`/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql`)  
**Phase focus:** Ship a contributor-friendly default (prebuilt static libs + clear tags), keep amalgamation explicitly legacy, align dependent repos once the contract is stable.

---

## Objectives

1. **CI** — Reliable Bazel-backed builds with cache reuse; optional paths to consume **prebuilt `.a` artifacts** for users **without** a local Bazel install.
2. **Docs & UX** — README, `native-build-pipeline.md`, and `prebuilt-cgo.md` describe **default build tags when prebuilts are present**, position **amalgamation as legacy** (behind an explicit flag), and reduce time-to-first-successful-build for new contributors.
3. **Downstream** — After the Tier B / prebuilt contract is stable, align **go-googlesqlite** and **bigquery-emulator** (and **bigquery-emulator-ui** if applicable) with the same tags and artifact assumptions.

---

## Exit criteria (definition of done)

| Criterion | Verification |
|-----------|----------------|
| New contributors can build with **prebuilts in minutes** (clone → deps → `go test`/build, no Bazel required if using published artifacts) | Documented quick path + CI or manual smoke on a clean machine |
| **Amalgamation is gated** behind an **explicit legacy build tag** (not the default path) | Default docs and examples do not require amalgamation; legacy tag documented once |
| Prebuilt / Tier B **contract** is stable enough for downstream PRs | Versioned or tagged artifact layout; changelog note for integrators |

---

## To-dos (master checklist)

Use this list for overall progress; detailed steps stay in the sections below.

### 1. CI — inventory, cache, reproducibility

- [ ] Inventory workflows (`go.yml`, Tier B / unified prebuilt YAMLs, `release.yml`); document cache keys and cold vs warm times.
- [ ] Standardize Bazel cache restore/save (or remote cache) on every Bazel job; optional split analysis vs full build; document cache failure fallback.
- [ ] Align prebuilt artifact names, triples, layout, and extraction scripts with CI outputs; add `SHA256SUMS` (or equivalent) for release/nightly sets.

### 2. CI — “no Bazel” consumer gate

- [ ] Add or extend a job: no Bazel, prebuilts in documented paths, `go test`/build with default prebuilt-oriented tags; decide required vs optional and flip to required when stable.

### 3. Publishing

- [ ] Choose/implement primary user-facing channel (recommended: tagged GitHub Release assets per platform); wire release workflow if not already; document URLs next to README/prebuilt docs.

### 4. Documentation

- [ ] README: quick start (prebuilt-first), build matrix table, links to `prebuilt-cgo.md` / `native-build-pipeline.md`.
- [ ] `docs/native-build-pipeline.md`: Bazel → static archives, CGO/single-owner overlap, legacy amalgamation subsection.
- [ ] `docs/prebuilt-cgo.md`: default tags with prebuilts, path without prebuilts, amalgamation as legacy.
- [ ] Cross-cutting: troubleshooting, version/tarball ↔ git tag mapping.

### 5. Downstream (after contract stable)

- [ ] **go-googlesqlite:** bump module, align tags/CGO, CI for prebuilt path, sqlite caveats in docs.
- [ ] **bigquery-emulator** (and UI if embedded): same alignment, integration tests vs prebuilts, release notes on contract changes.
- [ ] Shared: each README points at Phase 5 docs; open issues only for gaps.

---

## CI plan

### 1. Inventory and baseline

- [ ] Confirm which workflows already implement **Bazel remote/cache** (e.g. `actions/cache`, Bazelisk + disk cache, or repository rules). Existing candidates in-repo: `.github/workflows/go.yml`, `go-tier-b-prebuilt.yml`, `go-tier-b-absl-prebuilt.yml`, `go-googlesql-unified-prebuilt.yml`, `release.yml`.
- [ ] Document **cache keys**: OS, Bazel version, lockfiles / `MODULE.bazel` / `WORKSPACE` hashes, and any ` --disk_cache` or remote endpoints used in CI.
- [ ] Measure **cold vs warm** CI time for the Tier B / unified prebuilt jobs to set expectations.

### 2. Bazel cache in workflows (standardize)

- [ ] **Primary build jobs:** Ensure every Bazel-invoking job restores/saves a cache (or uses org-level remote cache if available). Prefer **deterministic key segments** so unrelated doc changes do not invalidate the entire cache.
- [ ] **Optional:** Split “analysis-only” vs “full build” if needed to keep PR feedback fast; cache should still apply to both where possible.
- [ ] **Failure mode:** On cache corruption or version skew, document fallback: clear cache key or bump Bazel version in a controlled way.

### 3. Prebuilt artifact generation in CI

- [ ] Align artifact names, triples (e.g. `linux_amd64`), and directory layout with **docs** (`prebuilt-cgo.md`, `native-build-pipeline.md`) and extraction scripts under `internal/ccall/**`.
- [ ] Ensure CI produces the same **static `.a` (and headers if applicable)** that users download, or a **single tarball** per platform containing the expected layout.
- [ ] Add a **checksum file** (e.g. `SHA256SUMS`) for any release or nightly artifact set.

### 4. CI gates for “no Bazel” consumer path

- [ ] Add (or extend) a job that: checks out repo, **does not** run Bazel, places prebuilts in the documented location, runs `go test` / build with **default prebuilt-oriented tags**.
- [ ] Keep this job **optional** or **required** per team policy; if optional initially, mark as required once stable.

---

## Artifact publishing options

| Option | Role | Pros | Cons / notes |
|--------|------|------|----------------|
| **GitHub Actions cache** | Speed up CI only | Low friction, no public hosting | Not for end-user download; scoped to workflow/repo |
| **GitHub Releases** (tagged) | **User-downloadable prebuilt `.a`** | Versioned, stable URLs, good for “minutes to build” story | Manual or release workflow; attach `SHA256SUMS` |
| **Pre-release / nightly** | Bleeding-edge testers | Faster iteration | Must be clearly labeled; may break without semver |
| **GitHub Actions artifacts** (workflow `actions/upload-artifact`) | CI artifacts between jobs; short retention | Good for PR validation | Retention limits; not a long-term CDN for users |
| **Org artifact registry** (optional future) | Large binaries, internal mirrors | Scales beyond GitHub limits | Extra infra and auth |

**Recommendation for Phase 5:** Ship **tagged GitHub Release assets** for supported platforms as the primary “no Bazel” path; use **Actions cache** (and optional **workflow artifacts**) for CI speed; document **exact paths** and **tags** next to each release in README / prebuilt docs.

---

## Documentation checklist

### README

- [ ] **Quick start** assumes **prebuilts when available** (download + env vars / paths as documented).
- [ ] **Build matrix** table: default (prebuilt), Tier B tags, legacy amalgamation flag — one glance clarity.
- [ ] Link to `docs/prebuilt-cgo.md` and `docs/native-build-pipeline.md` for depth.

### `docs/native-build-pipeline.md`

- [ ] Describe **Bazel → static archives** flow and where outputs land relative to the Go tree.
- [ ] Call out **single CGO owner** / duplicate-symbol constraints where Tier B and protobuf/Abseil overlap (consistent with `prebuilt-absl-overlap.md`).
- [ ] **Amalgamation:** single subsection marked **legacy**, with explicit build tag and “when you still need it.”

### `docs/prebuilt-cgo.md`

- [ ] **Default tags when prebuilts are present** — canonical list; match CI and release layout.
- [ ] **Without prebuilts:** point to Bazel or full native pipeline; time/cost expectations.
- [ ] **Amalgamation:** described as **legacy**, not the default path for new work.

### Cross-cutting

- [ ] **Troubleshooting:** missing `.a`, wrong architecture, mixed tags causing link errors.
- [ ] **Versioning:** how prebuilt tarball version maps to git tag / module version.

---

## Downstream checklist (after contract stable)

**Prerequisites:** Phase 5 CI publishes reproducible artifacts; README + `prebuilt-cgo.md` list stable tags and env vars; at least one green “no Bazel + prebuilts” CI job in `go-googlesql`.

### go-googlesqlite

- [ ] Bump / pin `go-googlesql` module version once artifacts and tags are stable.
- [ ] Align **CGO flags** and **build tags** with go-googlesql defaults (prebuilt-first).
- [ ] Add or update CI to test **prebuilt path** (optional: matrix with/without Bazel).
- [ ] Document any **sqlite-specific** caveats (single `.a` owner, symbol collisions).

### bigquery-emulator (and UI if it embeds the stack)

- [ ] Same module/tag alignment as above.
- [ ] Integration tests that run against **published prebuilts** or vendored copies per project policy.
- [ ] Release notes for consumers when the native contract changes.

### Shared exit for downstream

- [ ] Each repo’s README points to go-googlesql **Phase 5** docs for the canonical build story.
- [ ] Open tracking issues only for **gaps** (e.g. extra platform, merged archive) rather than duplicating full pipeline docs.

---

## Sequencing suggestion

1. **Stabilize CI** — Bazel cache everywhere it matters; prebuilt jobs reproducible.  
2. **Publish artifacts** — Release workflow + checksums + documented layout.  
3. **Docs pass** — README + two doc files + legacy amalgamation flag clearly separated.  
4. **Downstream PRs** — go-googlesqlite, then bigquery-emulator (order by dependency).

---

## Risks and mitigations

| Risk | Mitigation |
|------|------------|
| Duplicate Abseil/protobuf symbols when mixing tags | Keep `prebuilt-absl-overlap.md` policy visible; CI “no mixed unsupported tags” where feasible |
| Binary size / many platforms | Start with **linux_amd64** + one dev platform; expand releases deliberately |
| Doc drift from CI | Single source of truth for paths/tags in docs; CI job mirrors documented env |

---

## References (in-repo)

- `.github/workflows/go-tier-b-prebuilt.yml`, `go-tier-b-absl-prebuilt.yml`, `go-googlesql-unified-prebuilt.yml`, `go.yml`, `release.yml`
- `docs/prebuilt-cgo.md`, `docs/native-build-pipeline.md`, `docs/prebuilt-absl-overlap.md`, `docs/libgooglesql-unified.md`
- `internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh` (and related extraction scripts)