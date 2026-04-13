# Changelog

All notable changes to this project are documented here. The format is loosely based on Keep a Changelog.

## [Unreleased]

### Documentation

- **Stack releases:** [`docs/stack-release-policy.md`](docs/stack-release-policy.md) — align `go-googlesql` tags, default prebuilt tarballs, downstream module bumps, and `GO_GOOGLESQL_BASE`.

### Tooling

- **Downstream CI:** [`scripts/ci-download-or-build-default-prebuilts.sh`](scripts/ci-download-or-build-default-prebuilts.sh) — downloads the default prebuilt tarball for a tagged `go-googlesql` release on Linux amd64, or builds protobuf + unified prebuilts via Task/Bazel when needed; referenced from [`docs/stack-release-policy.md`](docs/stack-release-policy.md) and [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md).
- **GoogleSQL upstream:** Pinned tag in [`internal/cmd/updater/googlesql.ref`](internal/cmd/updater/googlesql.ref); Docker-based updater (`make -C internal/cmd/updater update`) replaces the Git submodule; [`scripts/ensure-googlesql-workspace.sh`](scripts/ensure-googlesql-workspace.sh) clones the tag for CI/Bazel. Root [`go.mod`](go.mod) includes updater/generator dependencies (nested `go.mod` files removed).
- **Build automation:** root `Makefile` removed in favor of [`Taskfile.yml`](Taskfile.yml) ([Task](https://taskfile.dev/)); shared CGO env in [`.envrc`](.envrc) (direnv) and [`scripts/go-googlesql-env.sh`](scripts/go-googlesql-env.sh) (sourced by `.envrc` and Task). CI workflows install Task via `arduino/setup-task@v2`.
- **CGO consolidation:** [`docs/cgo-consolidation.md`](docs/cgo-consolidation.md) defines the shard-reduction program; [`scripts/cgo-shard-inventory.sh`](scripts/cgo-shard-inventory.sh) (`--summary` / `--check`) enforces that link-only `bind.cc` files never `#include` amalgamated `.cc` bodies. Wired into `.github/workflows/go.yml`.

### Tier B / Phase 5 (CI, artifacts, docs)

- **CI:** Shared Bazel disk cache key across default protobuf prebuilts, Tier B Abseil, unified prebuilt, release prebuilts, and consumer workflows (`internal/cmd/updater/googlesql.ref`, `internal/cmd/updater/Dockerfile`, `go.mod`, `go.sum`). GoogleSQL workspace: `scripts/ensure-googlesql-workspace.sh`. Inventory: [`docs/ci-bazel-cache.md`](docs/ci-bazel-cache.md).
- **Artifacts:** Tagged releases publish **`go-googlesql-prebuilts-default-linux_amd64-<tag>.tar.gz`** (protobuf + unified `lib/` trees + manifest) and `SHA256SUMS` (workflow: `.github/workflows/release-prebuilts.yml`). Packaging: `scripts/package-default-prebuilts.sh`; Task: `task package:default-prebuilts-tarball`. Protobuf-only tarballs remain available via `scripts/package-protobuf-prebuilt.sh` for narrow **`task test:protobuf-cgo`** workflows.
- **Consumer validation:** `.github/workflows/go-prebuilt-consumer.yml` runs a **no-Bazel** job that extracts the default bundle and runs **`task test:local TESTPKG=./`**.
- **Docs:** README build matrix; expanded [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md), [`docs/native-build-pipeline.md`](docs/native-build-pipeline.md).

**Integrators:** Pin the Go module to the same semver as the Git tag whose prebuilt tarball you use; verify checksums from `SHA256SUMS`. Downstream checklist: [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md#phase-5-checklist-dependent-repos).
