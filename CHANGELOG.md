# Changelog

All notable changes to this project are documented here. The format is loosely based on Keep a Changelog.

## [Unreleased]

### Tier B / Phase 5 (CI, artifacts, docs)

- **CI:** Shared Bazel disk cache key across Tier B protobuf, Tier B Abseil, unified prebuilt, release prebuilts, and consumer workflows (`internal/cmd/updater/googlesql/MODULE.bazel`, `MODULE.bazel.lock`, `.bazelversion`). Inventory: [`docs/ci-bazel-cache.md`](docs/ci-bazel-cache.md).
- **Artifacts:** Tagged releases may include `go-googlesql-prebuilts-protobuf-linux_amd64-<tag>.tar.gz` and `SHA256SUMS` (workflow: `.github/workflows/release-prebuilts.yml`). Packaging script: `scripts/package-tier-b-protobuf-prebuilt.sh`; Make target: `make package-tier-b-protobuf-tarball`.
- **Consumer validation:** `.github/workflows/go-prebuilt-consumer.yml` runs a **no-Bazel** job that tests with prebuilts only.
- **Docs:** README build matrix; expanded [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md), [`docs/native-build-pipeline.md`](docs/native-build-pipeline.md).

**Integrators:** Pin the Go module to the same semver as the Git tag whose prebuilt tarball you use; verify checksums from `SHA256SUMS`. Downstream checklist: [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md#phase-5-checklist-dependent-repos).
