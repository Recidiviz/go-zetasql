# Stack release policy (go-googlesql, go-googlesqlite, bigquery-emulator)

This document ties together **module versions**, **prebuilt archives**, and **Docker base images** for the supported default CGO path: **`googlesql`** + **`googlesql_unified_prebuilt`**, link-only CGO, Bazel-built **`libprotobuf_cgo.a`** and **`libgooglesql.a`**.

## Rules

1. **Single source of truth:** [`github.com/vantaboard/go-googlesql`](https://github.com/vantaboard/go-googlesql) defines Bazel extract scripts, [`Taskfile.yml`](../Taskfile.yml), [`docs/prebuilt-cgo.md`](prebuilt-cgo.md), and release workflows ([`.github/workflows/release-prebuilts.yml`](../.github/workflows/release-prebuilts.yml)).
2. **Git tag = module version:** A stack release uses one **semver Git tag** on `go-googlesql` (e.g. `v0.5.6`). The Go module version in downstream `go.mod` **`require`** lines must match that tag (`v0.5.6`).
3. **Prebuilt tarball = same tag:** GitHub Releases publish **`go-googlesql-prebuilts-default-linux_amd64-<tag>.tar.gz`** (see [Release tarballs](prebuilt-cgo.md#release-tarballs-linux_amd64)) built from that tag. Extract it into a **`go-googlesql`** checkout at the same ref before building downstream with **`replace`**.
4. **SHA256SUMS:** Verify the tarball against **`SHA256SUMS`** on the same GitHub Release before trusting bytes in CI or production mirrors.
5. **Downstream `replace`:** Local development uses `replace github.com/vantaboard/go-googlesql => ../go-googlesql` (and `go-googlesqlite` as needed). The **`../go-googlesql`** tree must contain the prebuilt `lib/` trees from step 3 or from **`task prebuilt:protobuf`** + **`task prebuilt:googlesql-unified`** on that checkout.
6. **Bootstrap env:** Downstream **`go test`** / **`go build`** must apply the same **`CGO_*`** contract as Task: source [`scripts/go-googlesql-stack-bootstrap.sh`](../scripts/go-googlesql-stack-bootstrap.sh) (see [Downstream bootstrap](prebuilt-cgo.md#downstream-bootstrap-no-task--no-direnv)).
7. **`GO_GOOGLESQL_BASE` (bigquery-emulator):** Docker builds that use a prebuilt toolchain image should pin **`GO_GOOGLESQL_BASE`** to an image built from the **same** `go-googlesql` commit or tag as the **`go.mod`** requirement (e.g. `ghcr.io/vantaboard/go-googlesql:<tag>`). Bump it when you bump the Go module.

## Bump order (suggested)

1. Tag and release **`go-googlesql`** (prebuilts workflow attaches the default tarball).
2. Bump **`go-googlesql`** in **`go-googlesqlite`** `go.mod`; run tests with sibling **`replace`** and prebuilts.
3. Bump **`go-googlesql`** / **`go-googlesqlite`** in **`bigquery-emulator`** `go.mod`; align **`GO_GOOGLESQL_BASE`**; run **`make test/linux`** or stack integration tests.

## CI caveat

GitHub Actions for **downstream** repos often test against the **public module** (no prebuilt `.a` in the module zip). That may use a different CGO compile path than the unified-prebuilt sibling workflow. For **release confidence**, gate on local or internal jobs that use **`replace`**, a prebuilt tarball, or **`task test:local`** in `go-googlesql`.
