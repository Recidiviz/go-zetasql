# CI: caches and Bazel workflows

This document is the **single inventory** for GitHub Actions caching related to **Go**, **C++ (ccache)**, and **Bazel** in this repository. Use it when debugging slow CI, cache misses, or skew after bumping [`internal/cmd/updater/googlesql.ref`](../internal/cmd/updater/googlesql.ref) or the cloned workspace’s `MODULE.bazel`.

## Workflows

| Workflow | Trigger | Bazel | `actions/cache` (Bazel) | `actions/cache` (ccache) | Notes |
|----------|---------|-------|---------------------------|---------------------------|--------|
| [`go.yml`](../.github/workflows/go.yml) | `push` / `pull_request` to `main` | Yes | Yes (`~/.cache/bazel`) | Yes (`.ccache`, key from `go.sum` / `go.mod`) | Default protobuf prebuilt path: `task prebuilt:protobuf` → `task test:local`. |
| [`go-tier-b-prebuilt.yml`](../.github/workflows/go-tier-b-prebuilt.yml) | `workflow_dispatch` | Yes | Yes (`~/.cache/bazel`) | No | Focused default protobuf prebuilt verification: `task prebuilt:protobuf` → `task test:local TESTPKG=./internal/ccall/go-protobuf/protobuf/`. |
| [`go-tier-b-absl-prebuilt.yml`](../.github/workflows/go-tier-b-absl-prebuilt.yml) | `workflow_dispatch` | Yes | Yes (`~/.cache/bazel`) | No | Abseil Tier B pilot. |
| [`go-googlesql-unified-prebuilt.yml`](../.github/workflows/go-googlesql-unified-prebuilt.yml) | `workflow_dispatch`, weekly cron | Yes | Yes (`~/.cache/bazel`) | No | Unified `libgooglesql.a` smoke build. |
| [`go-prebuilt-consumer.yml`](../.github/workflows/go-prebuilt-consumer.yml) | `workflow_dispatch`, weekly cron | **No** on consumer job | — | No | Validates **prebuilts without Bazel** (artifact from producer job). |
| [`release-prebuilts.yml`](../.github/workflows/release-prebuilts.yml) | `push` tags `v*` | Yes | Yes | No | Attaches the default protobuf prebuilt tarball + `SHA256SUMS` to the GitHub Release. |
| [`release.yml`](../.github/workflows/release.yml) | `push` tags `v*` | No (Docker Buildx) | — | GHA cache (`type=gha`) | Container images only; separate from native prebuilts. |

**Bazelisk** is installed in workflows that invoke Bazel (`go install github.com/bazelbuild/bazelisk@v1.20.0`). Workflows run [`scripts/ensure-googlesql-workspace.sh`](../scripts/ensure-googlesql-workspace.sh) so [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) exists at the pinned tag; Bazel’s version comes from `.bazelversion` inside that clone after `ensure-googlesql-workspace.sh` runs.

## Cache key segments

### Go module cache (`actions/setup-go` with `cache: true`)

- **Keys:** derived by `actions/setup-go` from `go.sum` (and `cache-dependency-path` where set).
- **Scope:** Speeds `go mod download` / tool install only.

### ccache (`go.yml`)

- **Path:** `${{ github.workspace }}/.ccache`
- **Key:** `ccache-${{ runner.os }}-${{ hashFiles('go.sum', 'go.mod') }}`
- **Restore prefix:** `ccache-${{ runner.os }}-`
- **Intent:** Incremental C++ compiles for the default protobuf prebuilt flow across PRs that do not change module deps.

### Bazel disk cache (Tier B / unified / release prebuilts)

- **Path:** `~/.cache/bazel`
- **Key segments:** `runner.os`, fixed workflow family prefix, and **`hashFiles`** on:
  - `internal/cmd/updater/googlesql.ref`
  - `internal/cmd/updater/Dockerfile`
  - `go.mod`
  - `go.sum`
- **Restore prefix:** same OS + family prefix without the hash (partial restore on lockfile bumps).

Unrelated **documentation-only** changes should **not** change these hashes; doc edits under `.github/` or `docs/` do not invalidate the Bazel cache key.

## Cold vs warm expectations (order of magnitude)

Exact times depend on GitHub-hosted runner load and cache hit rate.

| Job type | Cold (no or partial Bazel cache) | Warm (full Bazel + action cache hit) |
|----------|-----------------------------------|----------------------------------------|
| `go.yml` Test | Several minutes (first full CGO + ccache cold) | Often faster; ccache + Go cache hot |
| Tier B `task prebuilt:protobuf` | **Tens of minutes to ~2h** (first Bazel analysis + C++ builds) | Much faster; dominated by invalidation scope |
| Unified prebuilt smoke | Similar to Tier B for first Bazel graph | Similar improvement when cache hits |

Use **`workflow_dispatch`** on Tier B workflows before releases or after changing extract scripts. Weekly **cron** on unified (and consumer) workflows keeps the **Bazel** cache warm for the cloned GoogleSQL workspace graph.

## Failure modes and fallback

| Symptom | Likely cause | Mitigation |
|---------|----------------|------------|
| Bazel analysis errors after bumping `googlesql.ref` | Lockfile / module resolution drift | Run `scripts/ensure-googlesql-workspace.sh`, then `cd internal/cmd/updater/googlesql && bazelisk build …`; refresh `MODULE.bazel.lock` in that clone if policy allows. |
| Spurious compile failures after cache restore | Rare cache corruption or toolchain skew | Re-run job; if persistent, **bump** the cache key by changing the hashed files legitimately (e.g. lockfile) or temporarily add a **version suffix** in the workflow key (last resort). |
| “Works locally, fails in CI” | Different `BAZEL_JOBS`, OS, or missing `clang` | Match CI env; see workflow `env` blocks. |

Do **not** commit `~/.cache/bazel` into the repo; CI restore/save is the supported reuse path.

## Related

- [`prebuilt-cgo.md`](prebuilt-cgo.md) — artifact layout and tags.
- [`native-build-pipeline.md`](native-build-pipeline.md) — Bazel → static archives.
