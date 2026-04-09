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

The extract script runs Bazel on **`@com_google_protobuf//:protobuf`** and **`@com_google_protobuf//src/google/protobuf:cmake_wkt_cc_proto`**, then merges **`*.pic.o`** from the Bazel `external/protobuf~` tree (including well-known types from `_objs/cmake_wkt_cc_proto/`), **`utf8_range`**, and **`abseil-cpp~`** (protobuf depends on Abseil; those objects must be in the archive or the link reports undefined `absl::` symbols). Per-target `*_proto` object dirs that duplicate `cmake_wkt_cc_proto` (e.g. `timestamp_proto`) are excluded so the archive does not contain two definitions of the same WKT `.pb.cc` compilation.

**Protobuf version / codegen alignment:** `libprotobuf_cgo.a` must match the **same** major protobuf and **same** `protoc` codegen conventions as the vendored headers and generated `*.pb.cc` under [`internal/ccall/protobuf`](../internal/ccall/protobuf) and the GoogleSQL amalgamation. Newer protobuf releases changed WKT codegen (for example, out-of-line `Arena::CreateMaybeMessage<google::protobuf::Timestamp>` in `timestamp.pb.cc` may disappear). If Bazel resolves `@com_google_protobuf` to a newer revision than the tree’s vendored protos, Tier-B links can still report undefined `google::protobuf::*` symbols even with a complete archive. Fix by pinning the Bazel module to the repo’s expected protobuf version, refreshing vendored generated code, or treating full `go test` with `googlesql_tier_b` as unsupported until that alignment is intentional.

**Alignment workflow (upgrade path):**

1. `make sync-protobuf-vendor-from-bazel` — copies `google/protobuf` runtime from the Bazel external tree into `internal/ccall/protobuf/`.
2. `go run ./internal/cmd/vendorpatch` — reapplies amalgamation guards and `patches/*.patch` (rebase patches when upstream drifts).
3. `make regenerate-googlesql-cpp-protos` — regenerates `internal/ccall/googlesql/**/*.pb.{h,cc}` with Bazel-built `protoc`.
4. `make verify-protobuf-tier-b-alignment` — optional; set `VERIFY_PROTOBUF_TIER_B_STRICT=1` to fail CI if the vendored `GOOGLE_PROTOBUF_VERSION` is still below the protobuf 5.29 line.

See also [link-only-cgo-migration.md](link-only-cgo-migration.md) for the long-term “no amalgamation” generator path.

Bazel uses **Clang + libc++** for those objects; [`bind_tier_b.go`](../internal/ccall/go-protobuf/protobuf/bind_tier_b.go) links **`-lc++ -lc++abi`** on Linux and searches common **`/usr/lib/llvm-*/lib`** paths so `-lc++` resolves (install **`libc++` / `libc++abi`** from your distro or LLVM if the link still fails with “cannot find -lc++”). If you see undefined **`std::__1::__hash_memory`**, the link is missing libc++ for objects built with `-stdlib=libc++`; ensure **`CGO_CXXFLAGS=-stdlib=libc++`** for all CGO C++ (see below) and that **`-lc++`** appears on the link line after **`-lprotobuf_cgo`**.

**ABI:** Vendored / amalgamated C++ that calls into `google::protobuf` templates must use the **same** standard library as `libprotobuf_cgo.a`. By default, Clang uses **libstdc++** (`std::__cxx11::` mangling); Bazel’s archive uses **libc++** (`std::__1::`). Without alignment you get undefined references to protobuf internals (e.g. `ArenaStringPtr::Set`, `RepeatedPtrFieldBase::AddOutOfLineHelper`). Set for Tier B builds:

```bash
export CGO_CXXFLAGS=-stdlib=libc++
```

[`Makefile`](../Makefile) **`local/test-prebuilt`**, **`local/build-prebuilt`**, and **`local/test-tier-b`** set **`CGO_CXXFLAGS_TIER_B`** (default `-stdlib=libc++`) automatically. Override only if you know your Bazel archive was built with a different `-stdlib`.

## Verify before testing

```bash
make verify-prebuilt-protobuf
```

Or: `bash scripts/verify-prebuilt-protobuf.sh`

## Abseil prebuilt (`libabsl_cgo.a`)

Build a merged Bazel `*.pic.o` archive for **`@com_google_absl`** (same submodule as protobuf extract):

```bash
make prebuilt-libs-absl
```

Writes:

- `internal/ccall/go-absl/lib/$GOOS_$GOARCH/libabsl_cgo.a`
- Symlink `internal/ccall/go-absl/lib/libabsl_cgo.a`

Verify:

```bash
make verify-prebuilt-absl
```

**Build tag `googlesql_tier_b_absl`** — link-only CGO for packages that ship `bind_tier_b_absl.go`. **Migrated packages (expand over time):** [`meta/type_traits`](../internal/ccall/go-absl/meta/type_traits); [`types/any`](../internal/ccall/go-absl/types/any), [`types/bad_any_cast`](../internal/ccall/go-absl/types/bad_any_cast), [`types/bad_any_cast_impl`](../internal/ccall/go-absl/types/bad_any_cast_impl), [`types/bad_optional_access`](../internal/ccall/go-absl/types/bad_optional_access), [`types/bad_variant_access`](../internal/ccall/go-absl/types/bad_variant_access), [`types/compare`](../internal/ccall/go-absl/types/compare), [`types/optional`](../internal/ccall/go-absl/types/optional), [`types/span`](../internal/ccall/go-absl/types/span), [`types/variant`](../internal/ccall/go-absl/types/variant); [`base/config`](../internal/ccall/go-absl/base/config), [`base/core_headers`](../internal/ccall/go-absl/base/core_headers), [`base/endian`](../internal/ccall/go-absl/base/endian), [`base/errno_saver`](../internal/ccall/go-absl/base/errno_saver), [`base/prefetch`](../internal/ccall/go-absl/base/prefetch); [`utility/utility`](../internal/ccall/go-absl/utility/utility). Use **`make local/test-prebuilt-absl`** / **`make local/build-prebuilt-absl`** (defaults list all migrated paths; override `TESTPKG_PREBUILT_ABSL` / `BUILDPKG_ABSL`).

### Stress build notes (widening `BUILDPKG_ABSL`)

Local checks used:

- `./internal/ccall/go-absl/meta/...` — builds cleanly (only `type_traits` is a leaf package today).
- `./internal/ccall/go-absl/types/...` — builds cleanly; all nine `types/*` packages use link-only `bind_tier_b_absl.go` when migrated.
- `./internal/ccall/go-absl/base/...` — builds cleanly alongside migrated link-only packages; other `base/*` shards still compile `bind.cc` when the tag is set.
- `./internal/ccall/go-absl/...` — **fails** on a few packages that pull **GoogleMock** (`#include <gmock/gmock.h>`), e.g. `log/scoped_mock_log`, `random/.../mock_*`. That is a **test/mock header** dependency gap, not missing `bind_tier_b_absl.go` on ordinary Abseil shards. Do not expect a full-tree `go build` until gmock is wired or those packages are excluded from the pattern.

**Full-tree strategy (choose one):**

| Approach | When to use |
|----------|-------------|
| **Exclude mock-only packages** | Default recommendation. Stress most of the tree with a pattern that omits gmock-dependent dirs, e.g. build `meta/...`, `types/...`, `base/...`, `utility/...`, and other subtrees explicitly instead of a single `./go-absl/...`. To approximate “all packages minus mocks”, run `go list` with `-f` and drop paths matching `mock`, `scoped_mock_log`, `mocking_bit_gen`, `mock_distributions`, `mock_overload_set`. |
| **Add gmock to CGO** | Only if you need a literal `go build ./internal/ccall/go-absl/...` with zero exclusions: vendor or `-I` to googletest’s `googlemock/include`, link `gmock`/`gtest` as needed. High maintenance; prefer exclusions until a product requires full closure. |

**Overlap with protobuf Tier B:** `libprotobuf_cgo.a` already embeds Abseil object code. Do **not** combine `googlesql_tier_b` and `googlesql_tier_b_absl` in one link without a dedup policy—see [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md).

### Adding another `go-absl/...` package (manual)

1. Add `//go:build !googlesql_tier_b_absl` to **`bind_linux.go`** and **`bind_darwin.go`** (first line, before `package`).
2. Add **`bind_tier_b_absl.go`** next to them. For packages **three levels** under `go-absl/` (e.g. `foo/bar/baz`), include paths match the pilot:

```go
//go:build googlesql_tier_b_absl && (linux || darwin)

package yourpkg

/*
#cgo CXXFLAGS: -std=c++20
#cgo CXXFLAGS: -I${SRCDIR}/../../../
#cgo CXXFLAGS: -I${SRCDIR}/../../../protobuf
#cgo CXXFLAGS: -I${SRCDIR}/../../../utf8_range
#cgo linux LDFLAGS: -L${SRCDIR}/../../lib -labsl_cgo -lz -lstdc++ -ldl -lpthread
#cgo darwin LDFLAGS: -L${SRCDIR}/../../lib -labsl_cgo -lz -lc++

void __go_googlesql_tier_b_absl_<unique_suffix>_anchor(void) {}
*/
import "C"
```

3. If depth under `go-absl/` differs, adjust `${SRCDIR}/..` segments so `${SRCDIR}/../../lib` resolves to [`internal/ccall/go-absl/lib`](../internal/ccall/go-absl/lib).
4. Append the package path to **`TESTPKG_PREBUILT_ABSL`** / **`BUILDPKG_ABSL`** in the [`Makefile`](../Makefile).

A parameterized template lives at [`internal/cmd/generator/templates/bind_tier_b_absl.go.tmpl`](../internal/cmd/generator/templates/bind_tier_b_absl.go.tmpl). Fields: **`Package`** (Go package name), **`AnchorSuffix`** (unique identifier, e.g. `base_config`), **`IncludeRel`** (path segments from the package dir to `internal/ccall/`, e.g. `../../../`), **`LibRel`** (to [`go-absl/lib`](../internal/ccall/go-absl/lib), e.g. `../../lib`). Render with `text/template` or copy an existing migrated `bind_tier_b_absl.go` and adjust.

**Generator:** set **`emit_tier_b_absl_go: true`** in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) and run the generator from [`internal/cmd/generator`](../internal/cmd/generator): it emits **`bind_tier_b_absl.go`** and prepends **`//go:build !googlesql_tier_b_absl`** to generated **`bind_linux.go`** / **`bind_darwin.go`** for each package under **`internal/ccall/go-absl/`**. Default is **`false`** so normal regeneration does not change Tier B–ready trees until you opt in.

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
| `make prebuilt-libs-absl` | Build `libabsl_cgo.a` (same as `extract-absl-lib`) |
| `make verify-prebuilt-absl` | Fail fast if `libabsl_cgo.a` for current `GOOS_GOARCH` is missing |
| `make local/build-prebuilt-absl` | `go build` with `-tags googlesql,googlesql_tier_b_absl` (pilot path by default) |
| `make local/test-prebuilt-absl` | `go test` with Abseil Tier B tags (pilot path: `TESTPKG_PREBUILT_ABSL`) |
| `make prebuilt-libs-googlesql-unified` | Build [`libgooglesql.a`](../internal/ccall/go-googlesql-unified/lib) from GoogleSQL Bazel targets + C anchor (see [`libgooglesql-unified.md`](libgooglesql-unified.md)) |
| `make verify-prebuilt-googlesql-unified` | Fail fast if `libgooglesql.a` for current `GOOS_GOARCH` is missing |
| `make local/build-prebuilt-googlesql-unified` | `go build` with `-tags googlesql,googlesql_unified_prebuilt` on the unified CGO owner package (after verify) |
| `make smoke-link-googlesql-unified` | Compile and run [`smoke/smoke_main.c`](../internal/ccall/go-googlesql-unified/smoke/smoke_main.c) against `libgooglesql.a` (after verify) |

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
| **Manual Abseil Tier B** ([`go-tier-b-absl-prebuilt.yml`](../.github/workflows/go-tier-b-absl-prebuilt.yml)) | Builds `libabsl_cgo.a`, then `make local/test-prebuilt-absl` | `googlesql,googlesql_tier_b_absl` |
| **Local dev** | Run `make prebuilt-libs` / `make prebuilt-libs-absl` per `GOOS_GOARCH` when experimenting | choose default or Tier B tags |

Published binary releases of `.a` files are **not** part of the module; archives stay gitignored and are produced on demand.

## Related files

- [`extract_absl_cgo_lib.sh`](../internal/ccall/go-absl/extract_absl_cgo_lib.sh) — Bazel Abseil → `libabsl_cgo.a`
- [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md) — overlap with `libprotobuf_cgo.a`
- [`bind_tier_b.go`](../internal/ccall/go-protobuf/protobuf/bind_tier_b.go) — link-only CGO for protobuf when `googlesql_tier_b` is set
- [`Dockerfile.prebaked`](../Dockerfile.prebaked) — skeleton image for future prefix-based workflows
- [`docs/native-build-pipeline.md`](native-build-pipeline.md) — native artifact pipeline and shard ordering notes
