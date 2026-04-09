# Prebuilt native libraries + CGO

This document describes the **optional Tier B** path: link a **Bazel-built** `libprotobuf_cgo.a` instead of compiling protobuf via the amalgamation (`export.inc`) in [`internal/ccall/go-protobuf/protobuf`](../internal/ccall/go-protobuf/protobuf). It complements [`tier-b-absl-protobuf.md`](tier-b-absl-protobuf.md) and [`protobuf-vendoring.md`](protobuf-vendoring.md) (*Single-owner protobuf*).

## When to use it

- You want **incremental native work** to live in **Bazel + `ar` archives** under `internal/ccall/go-protobuf/protobuf/lib/`, with Go doing **link-only** for the protobuf shard (`bind_tier_b.go`).
- You accept **experimental** status: full-repo `-tags googlesql,googlesql_tier_b` builds may still hit link errors until the unified Abseil/protobuf story is complete end-to-end.

**Default:** omit `googlesql_tier_b`; `bind_linux.go` / `bind_darwin.go` compile amalgamation (CI and `go get` behavior).

## Prerequisites

- **bazelisk** or **bazel** on `PATH`
- Populated GoogleSQL submodule / Bazel cache at [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) (see updater docs)
- **clang++** for the extract script

## Build the archive

From the repository root:

```bash
make prebuilt-libs
```

This runs [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) and writes:

- `internal/ccall/go-protobuf/protobuf/lib/$GOOS_$GOARCH/libprotobuf_cgo.a`
- Symlink `internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a`

Archives are **gitignored** (`*.a`); each developer/CI agent builds locally.

## Verify before testing

```bash
make verify-prebuilt-protobuf
```

Or: `bash scripts/verify-prebuilt-protobuf.sh`

## Environment variables

| Variable | Role |
|----------|------|
| `GOOGLESQL_PREBUILT_PREFIX` | Optional install root for future consolidated headers/libs (see [`contrib/googlesql.pc.example`](../contrib/googlesql.pc.example)). Tier B protobuf today uses **fixed paths** under `internal/ccall/go-protobuf/protobuf/lib/`. |
| `PKG_CONFIG_PATH` | When using **pkg-config** for a consolidated layout, prepend the directory containing `googlesql.pc`. |

For **mold** (Linux), match [`Makefile`](../Makefile) `local/test` and set if the linker rejects unknown flags:

```bash
export CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold'
```

## Makefile targets

| Target | Purpose |
|--------|---------|
| `make prebuilt-libs` | Build `libprotobuf_cgo.a` via Bazel + `ar` (same as `extract-protobuf-lib`) |
| `make verify-prebuilt-protobuf` | Fail fast if the archive for the current `GOOS_GOARCH` is missing |
| `make local/build-prebuilt` | `go build` with `-tags googlesql,googlesql_tier_b` (after verify) |
| `make local/test-prebuilt` | `go test` with Tier B tags (after verify); respects `TESTPKG` |
| `make local/test-tier-b` | Tier B tests **without** verify (may link-fail if archive missing) |

## Generator: unified `absl` / `google`

[`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) sets `cclib.global_exclude_replace_names: [absl, google]` so generated `bind.cc` files omit per-shard `#define absl …` / `#define google …` where the generator applies global excludes—required for a single link domain with Bazel-built protobuf. After changing this block, run `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) and fix any compile fallout.

## Downstream repositories

**go-googlesqlite** and **bigquery-emulator** depend on this module via `require` + `replace`. If you enable Tier B here:

1. Use the **same** `replace` path or version of `github.com/vantaboard/go-googlesql`.
2. Build with **identical** tags: `-tags googlesql,googlesql_tier_b`.
3. Run **`make prebuilt-libs`** (or copy the resulting `lib/` tree) in the **go-googlesql** checkout that `replace` points to—downstream does **not** build `libprotobuf_cgo.a` for you.
4. Align **`CGO_CFLAGS`**, **`CGO_LDFLAGS`**, and **`CGO_LDFLAGS_ALLOW`** with this repo’s [`Makefile`](../Makefile) when running `go test` / `go build` outside Make.

## Artifact matrix (CI vs local)

| Context | Prebuilt `libprotobuf_cgo.a` | Tags |
|---------|------------------------------|------|
| Default **GitHub Actions** ([`go.yml`](../.github/workflows/go.yml)) | Not used; compile amalgamation | `googlesql` (implicit via build) |
| **Manual Tier B workflow** ([`go-tier-b-prebuilt.yml`](../.github/workflows/go-tier-b-prebuilt.yml)) | Built on the runner with Bazel, then `make local/test-prebuilt` | `googlesql,googlesql_tier_b` |
| **Local dev** | Run `make prebuilt-libs` per `GOOS_GOARCH` when experimenting | choose default or Tier B |

Published binary releases of `.a` files are **not** part of the module; archives stay gitignored and are produced on demand.

## Related files

- [`bind_tier_b.go`](../internal/ccall/go-protobuf/protobuf/bind_tier_b.go) — link-only CGO for protobuf when `googlesql_tier_b` is set
- [`Dockerfile.prebaked`](../Dockerfile.prebaked) — skeleton image for future prefix-based workflows
- [`docs/native-build-pipeline.md`](native-build-pipeline.md) — native artifact pipeline and shard ordering notes
