# Prebuilt native libraries + CGO

This document describes the **default protobuf path**: link a **Bazel-built** `libprotobuf_cgo.a` instead of the **removed** vendored single-TU amalgamation that used to live under [`internal/ccall/go-protobuf/protobuf`](../internal/ccall/go-protobuf/protobuf). It complements [`tier-b-absl-protobuf.md`](tier-b-absl-protobuf.md) and [`protobuf-vendoring.md`](protobuf-vendoring.md) (*Single-owner protobuf*).

## Default tags when prebuilts are present

| Goal | Tags | Preconditions |
|------|------|----------------|
| **GoogleSQL CGO (default)** | `-tags googlesql,googlesql_unified_prebuilt` | `libprotobuf_cgo.a` and `libgooglesql.a` (see [`libgooglesql-unified.md`](libgooglesql-unified.md)) |
| **Tier B Abseil (pilot)** | `-tags googlesql,googlesql_tier_b_absl` | `libabsl_cgo.a` under `internal/ccall/go-absl/lib/` — **not** combined with the default **`libprotobuf_cgo.a`** link in one binary ([prebuilt-absl-overlap.md](prebuilt-absl-overlap.md)) |
| **Protobuf package only (CI)** | `-tags googlesql,googlesql_unified_prebuilt` | `libprotobuf_cgo.a` only — `task test:protobuf-cgo` |

**Full GoogleSQL CGO:** **Unified prebuilt + link-only** binds — see [`link-only-cgo-migration.md`](link-only-cgo-migration.md).

Set **`CGO_CXXFLAGS=-stdlib=libc++`** (or rely on [`Taskfile.yml`](../Taskfile.yml) `CGO_CXXFLAGS_PREBUILT` for unified / local test targets) so the C++ standard library matches the Bazel-built archive.

**Without prebuilts / first-time setup:** run `task prebuilt:protobuf` (requires Bazelisk, [`scripts/ensure-googlesql-workspace.sh`](../scripts/ensure-googlesql-workspace.sh) or an updater Docker export, and time for a cold Bazel build—often tens of minutes). Alternatively download a **release tarball** (below) and extract into the repo root. Full native pipeline: [`native-build-pipeline.md`](native-build-pipeline.md).

**Removed path:** protobuf amalgamation is no longer the supported default. The normal `bind_linux.go` / `bind_darwin.go` files now link the prebuilt archive directly.

## When to use it

- You want the repository’s **default protobuf build path** to come from **Bazel + `ar` archives** under `internal/ccall/go-protobuf/protobuf/lib/`, with Go doing **link-only** for the protobuf shard in the normal platform bind files.
- You are working on the broader “single owner” prebuilt migration and need the protobuf hub to stay aligned with unified/prebuilt GoogleSQL work.

**Default GoogleSQL CGO:** use `-tags googlesql,googlesql_unified_prebuilt` with both archives built (`task prebuilt:protobuf` and `task prebuilt:googlesql-unified`). `googlesql_tier_b` remains a deprecated compatibility alias for older scripts; it does not select a different protobuf implementation.

## Prerequisites

- **bazelisk** or **bazel** on `PATH`
- GoogleSQL workspace at [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) ([`googlesql.ref`](../internal/cmd/updater/googlesql.ref)) and optional updater cache under [`internal/cmd/updater/cache/`](../internal/cmd/updater/cache/)
- **clang++** for the extract script

## Build the archive

From the repository root:

```bash
task prebuilt:protobuf
```

This runs [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) and writes:

- `internal/ccall/go-protobuf/protobuf/lib/$GOOS_$GOARCH/libprotobuf_cgo.a`
- Symlink `internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a`
- **Linux:** `libcxx_prebuilt.a` and `libcxxabi_prebuilt.a` (copies of **libc++** / **libc++abi** from the same Bazel **llvm_toolchain** that compiled the merged `.pic.o` objects), plus symlinks under `lib/`

Archives are **gitignored** (`*.a`); each developer/CI agent builds locally.

**After changing [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh):** run **`task prebuilt:protobuf`** (or the script directly), then **`task verify:prebuilt-protobuf`** and a smoke test (e.g. **`task test:local TESTPKG=./`**). Without a fresh **`libprotobuf_cgo.a`**, links can miss new **`*.pic.o`** members (for example explicit **`@com_google_absl//absl/...`** builds merged into the archive for go-absl **`exclude_amalgamation_sources`** — see [cgo-consolidation.md](cgo-consolidation.md) **Ninth follow-up**).

The extract script runs Bazel on **`@com_google_protobuf//:protobuf`** and **`@com_google_protobuf//src/google/protobuf:cmake_wkt_cc_proto`**, then merges **`*.pic.o`** from the Bazel `external/protobuf~` tree (including well-known types from `_objs/cmake_wkt_cc_proto/`), **`utf8_range`**, and **`abseil-cpp~`** (protobuf depends on Abseil; those objects must be in the archive or the link reports undefined `absl::` symbols). Additional Abseil targets are built explicitly when the script lists them (see script header comments and [cgo-consolidation.md](cgo-consolidation.md)). Paths under **`google/protobuf/compiler/`** are **excluded** (protoc backends such as `compiler/rust/*.pic.o` are not runtime protobuf and pull stray references, e.g. to `google::protobuf::File::ReadFileToString`). Per-target `*_proto` object dirs that duplicate `cmake_wkt_cc_proto` (e.g. `timestamp_proto`) are excluded so the archive does not contain two definitions of the same WKT `.pb.cc` compilation.

**Protobuf version / codegen alignment:** `libprotobuf_cgo.a` must match the **same** major protobuf and **same** `protoc` codegen conventions as the vendored headers and generated `*.pb.cc` under [`internal/ccall/protobuf`](../internal/ccall/protobuf) and the GoogleSQL consumers that include those headers. Newer protobuf releases changed WKT codegen (for example, out-of-line `Arena::CreateMaybeMessage<google::protobuf::Timestamp>` in `timestamp.pb.cc` may disappear). If Bazel resolves `@com_google_protobuf` to a newer revision than the tree’s vendored protos, default prebuilt links can still report undefined `google::protobuf::*` symbols even with a complete archive. Fix by pinning the Bazel module to the repo’s expected protobuf version, refreshing vendored generated code, or treating the checkout as out of alignment until that work is intentional.

**Alignment workflow (upgrade path):**

1. `task sync:protobuf-vendor-from-bazel` — copies `google/protobuf` runtime from the Bazel external tree into `internal/ccall/protobuf/`.
2. `go run ./internal/cmd/vendorpatch` — reapplies amalgamation guards and `patches/*.patch` (rebase patches when upstream drifts).
3. `task regenerate:ccall-cpp-protos` — regenerates `internal/ccall` `*.pb.{h,cc}` for googlesql, googleapis, and `proto/` trees (`task regenerate:googlesql-cpp-protos` is the same) using Bazel-built `protoc`.
4. `task verify:protobuf-tier-b` — optional; set `VERIFY_PROTOBUF_TIER_B_STRICT=1` to fail CI if the vendored `GOOGLE_PROTOBUF_VERSION` is still below the protobuf 5.29 line.

See also [link-only-cgo-migration.md](link-only-cgo-migration.md) for the long-term “no amalgamation” generator path.

Bazel uses **Clang + libc++** for those objects. On **Linux**, the default protobuf bind links the **copied** static libraries **`libcxx_prebuilt.a`** and **`libcxxabi_prebuilt.a`** (same LLVM toolchain as the Bazel build) in a **`--start-group` / `--end-group`** pair after **`libprotobuf_cgo.a`**. Using the host’s **`-lc++`** alone can fail: Abseil `.pic.o` inside the archive may reference **`std::__1::__hash_memory`** with a libc++ **ABI tag** that does not match the distro’s `/usr/lib/llvm-*/lib/libc++.a`, even when **`CGO_CXXFLAGS=-stdlib=libc++`** is set everywhere.

**Abseil inline namespace:** vendored [`internal/ccall/absl/base/options.h`](../internal/ccall/absl/base/options.h) must match BCR **abseil-cpp** (e.g. **`lts_20240722`**) so amalgamation TUs and `libprotobuf_cgo.a` agree on **`absl::Cord`** / **`MessageLite::{Parse,Serialize}*Cord`** mangling.

**ABI:** Vendored / amalgamated C++ that calls into `google::protobuf` templates must use the **same** standard library as `libprotobuf_cgo.a`. By default, Clang uses **libstdc++** (`std::__cxx11::` mangling); Bazel’s archive uses **libc++** (`std::__1::`). Without alignment you get undefined references to protobuf internals (e.g. `ArenaStringPtr::Set`, `RepeatedPtrFieldBase::AddOutOfLineHelper`). Set for Tier B builds:

```bash
export CGO_CXXFLAGS=-stdlib=libc++
```

[`Taskfile.yml`](../Taskfile.yml) **`local/test`** and **`local/build`** set **`CGO_CXXFLAGS_PREBUILT`** (default `-stdlib=libc++`) automatically. Override only if you know your Bazel archive was built with a different `-stdlib`.

## Verify before testing

```bash
task verify:prebuilt-protobuf
```

Or: `bash scripts/verify-prebuilt-protobuf.sh`

## Abseil prebuilt (`libabsl_cgo.a`)

Build a merged Bazel `*.pic.o` archive for **`@com_google_absl`** (same `internal/cmd/updater/googlesql` workspace as protobuf extract):

```bash
task prebuilt:absl
```

Writes:

- `internal/ccall/go-absl/lib/$GOOS_$GOARCH/libabsl_cgo.a`
- Symlink `internal/ccall/go-absl/lib/libabsl_cgo.a`

Verify:

```bash
task verify:prebuilt-absl
```

**Build tag `googlesql_tier_b_absl`** — link-only CGO for packages that ship `bind_tier_b_absl.go`. **Migrated packages (expand over time):** [`meta/type_traits`](../internal/ccall/go-absl/meta/type_traits); [`types/any`](../internal/ccall/go-absl/types/any), [`types/bad_any_cast`](../internal/ccall/go-absl/types/bad_any_cast), [`types/bad_any_cast_impl`](../internal/ccall/go-absl/types/bad_any_cast_impl), [`types/bad_optional_access`](../internal/ccall/go-absl/types/bad_optional_access), [`types/bad_variant_access`](../internal/ccall/go-absl/types/bad_variant_access), [`types/compare`](../internal/ccall/go-absl/types/compare), [`types/optional`](../internal/ccall/go-absl/types/optional), [`types/span`](../internal/ccall/go-absl/types/span), [`types/variant`](../internal/ccall/go-absl/types/variant); [`base/config`](../internal/ccall/go-absl/base/config), [`base/core_headers`](../internal/ccall/go-absl/base/core_headers), [`base/endian`](../internal/ccall/go-absl/base/endian), [`base/errno_saver`](../internal/ccall/go-absl/base/errno_saver), [`base/prefetch`](../internal/ccall/go-absl/base/prefetch); [`utility/utility`](../internal/ccall/go-absl/utility/utility). Use **`task test:tier-b-absl`** / **`task build:tier-b-absl`** (defaults list all migrated paths; override `TESTPKG_PREBUILT_ABSL` / `BUILDPKG_ABSL`).

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

**Overlap with default protobuf prebuilts:** `libprotobuf_cgo.a` already embeds Abseil object code. Do **not** combine the default protobuf owner (with or without the deprecated `googlesql_tier_b` alias) and `googlesql_tier_b_absl` in one link without a dedup policy—see [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md).

**Tag policy preflight:** `task verify:tier-b-cgo-policy` prints supported and unsupported tag combinations ([`scripts/verify-tier-b-cgo-tag-policy.sh`](../scripts/verify-tier-b-cgo-tag-policy.sh)); the canonical table lives in **`prebuilt-absl-overlap.md`**. Run it before local Tier B builds or when changing CI workflows.

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
4. Append the package path to **`TESTPKG_PREBUILT_ABSL`** / **`BUILDPKG_ABSL`** in [`Taskfile.yml`](../Taskfile.yml) (`vars`).

A parameterized template lives at [`internal/cmd/generator/templates/bind_tier_b_absl.go.tmpl`](../internal/cmd/generator/templates/bind_tier_b_absl.go.tmpl). Fields: **`Package`** (Go package name), **`AnchorSuffix`** (unique identifier, e.g. `base_config`), **`IncludeRel`** (path segments from the package dir to `internal/ccall/`, e.g. `../../../`), **`LibRel`** (to [`go-absl/lib`](../internal/ccall/go-absl/lib), e.g. `../../lib`). Render with `text/template` or copy an existing migrated `bind_tier_b_absl.go` and adjust.

**Generator:** set **`emit_tier_b_absl_go: true`** in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) and run the generator from [`internal/cmd/generator`](../internal/cmd/generator): it emits **`bind_tier_b_absl.go`** and prepends **`//go:build !googlesql_tier_b_absl`** to generated **`bind_linux.go`** / **`bind_darwin.go`** for each package under **`internal/ccall/go-absl/`**. Default is **`false`** so normal regeneration does not change Tier B–ready trees until you opt in.

## Downstream bootstrap (no Task / no direnv)

Downstream shells must mirror Task’s exports: **`CGO_LDFLAGS_ALLOW`**, **`CGO_LDFLAGS`**, **`CGO_CXXFLAGS`**, not only `CGO_LDFLAGS_*_LIST` from [`scripts/go-googlesql-env.sh`](../scripts/go-googlesql-env.sh). Use:

```bash
export GO_GOOGLESQL_ROOT=/path/to/go-googlesql   # optional if using the script from that repo
source "$GO_GOOGLESQL_ROOT/scripts/go-googlesql-stack-bootstrap.sh"
# then: go test -tags googlesql,googlesql_unified_prebuilt ...
```

**CI on downstream forks:** After checking out **`vantaboard/go-googlesql`** at the same version as `go.mod`, run [`scripts/ci-download-or-build-default-prebuilts.sh`](../scripts/ci-download-or-build-default-prebuilts.sh) once, then bootstrap + `go test` / `go build` (see [`docs/stack-release-policy.md`](stack-release-policy.md#ci)).

See also [Downstream repositories](#downstream-repositories) and [`README.md`](../README.md#development).

## Environment variables

| Variable | Role |
|----------|------|
| `GOOGLESQL_PREBUILT_PREFIX` | Optional install root for future consolidated headers/libs (see [`contrib/googlesql.pc.example`](../contrib/googlesql.pc.example)). Default protobuf prebuilts today use **fixed paths** under `internal/ccall/go-protobuf/protobuf/lib/`. |
| `PKG_CONFIG_PATH` | When using **pkg-config** for a consolidated layout, prepend the directory containing `googlesql.pc`. |

For **mold** (Linux), match [`Taskfile.yml`](../Taskfile.yml) `test:local` and set if the linker rejects unknown flags:

```bash
export CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold'
```

## Taskfile targets

| Task | Purpose |
|------|---------|
| `task prebuilt:protobuf` | Build `libprotobuf_cgo.a` via Bazel + `ar` (same as `extract-protobuf-lib`) |
| `task verify:prebuilt-protobuf` | Fail fast if the archive for the current `GOOS_GOARCH` is missing |
| `task build:local` | `go build` with `googlesql,googlesql_unified_prebuilt` after protobuf + unified prebuilt verify |
| `task test:local` | Full-module `go test` (same tags and verifies; `TESTPKG` / `GO_TEST_FLAGS` supported) |
| `task test:protobuf-cgo` | Protobuf shard only: verify protobuf prebuilt, test `internal/ccall/go-protobuf/protobuf/` (no `libgooglesql.a` required) |
| `task prebuilt:absl` | Build `libabsl_cgo.a` (same as `extract-absl-lib`) |
| `task verify:prebuilt-absl` | Fail fast if `libabsl_cgo.a` for current `GOOS_GOARCH` is missing |
| `task build:tier-b-absl` | `go build` with `-tags googlesql,googlesql_tier_b_absl` (pilot path by default) |
| `task test:tier-b-absl` | `go test` with Abseil Tier B tags (pilot path: `TESTPKG_PREBUILT_ABSL`) |
| `task prebuilt:googlesql-unified` | Build [`libgooglesql.a`](../internal/ccall/go-googlesql-unified/lib) from GoogleSQL Bazel targets + C anchor (see [`libgooglesql-unified.md`](libgooglesql-unified.md)) |
| `task verify:prebuilt-googlesql-unified` | Fail fast if `libgooglesql.a` for current `GOOS_GOARCH` is missing |
| `task build:googlesql-unified` | `go build` with `-tags googlesql,googlesql_unified_prebuilt` on the unified CGO owner package (after verify) |
| `task smoke:googlesql-unified` | Compile and run [`smoke/smoke_main.c`](../internal/ccall/go-googlesql-unified/smoke/smoke_main.c) against `libgooglesql.a` (after verify) |

## Generator: unified `absl` / `google`

[`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) sets `cclib.global_exclude_replace_names: [absl, google]` so generated `bind.cc` files omit per-shard `#define absl …` / `#define google …` where the generator applies global excludes—required for a single link domain with Bazel-built protobuf. After changing this block, run **`go run ./internal/cmd/generator`** from the repo root and fix any compile fallout.

## Downstream repositories

**go-googlesqlite** and **bigquery-emulator** depend on this module via `require` + `replace`. If you enable Tier B here:

1. Use the **same** `replace` path or version of `github.com/vantaboard/go-googlesql`.
2. Build with **identical** tags: `-tags googlesql,googlesql_unified_prebuilt` for the default GoogleSQL CGO path.
3. Run **`task prebuilt:protobuf`** and **`task prebuilt:googlesql-unified`** (or extract the **default release tarball** below) in the **go-googlesql** checkout that `replace` points to—downstream does **not** build those archives for you.
4. Align **`CGO_CFLAGS`**, **`CGO_LDFLAGS`**, and **`CGO_LDFLAGS_ALLOW`** with this repo’s [`Taskfile.yml`](../Taskfile.yml) when running `go test` / `go build` outside Task.

### Phase 5 checklist (dependent repos)

Use this when aligning **go-googlesqlite**, **bigquery-emulator**, or **bigquery-emulator-ui** with the Tier B contract:

- [ ] Bump / pin the `go-googlesql` module to a version that matches your **release prebuilts** or source tree.
- [ ] Mirror **build tags** and **`CGO_CXXFLAGS`** / **`CGO_LDFLAGS`** / **`CGO_LDFLAGS_ALLOW`** with this repo’s default protobuf prebuilt settings.
- [ ] Add CI that either runs **`task prebuilt:protobuf`** + **`task prebuilt:googlesql-unified`** (Bazel available) or **downloads and extracts** the matching **`go-googlesql-prebuilts-default-linux_amd64-<tag>.tar.gz`** before `go test`.
- [ ] Document **sqlite- or product-specific** caveats (linker, single archive owner) in the downstream README and link here—avoid duplicating the full pipeline; open issues only for **gaps** (extra platform, etc.).
- [ ] For user-visible native contract changes, add **release notes** pointing at this repository’s tag and [`CHANGELOG.md`](../CHANGELOG.md).

## Release tarballs (`linux_amd64`)

Tagged releases ship a **default unified-prebuilt stack** archive alongside the module (not imported via `go get`):

- **Asset name:** `go-googlesql-prebuilts-default-linux_amd64-<tag>.tar.gz` (e.g. `<tag>` = `v1.2.3`)
- **Contents:** `internal/ccall/go-protobuf/protobuf/lib/` (same as `task prebuilt:protobuf`) **and** `internal/ccall/go-googlesql-unified/lib/` (same as `task prebuilt:googlesql-unified`), plus `go-googlesql-prebuilts-manifest.json` (tag, sha, `GOOS_GOARCH`, schema).
- **Checksums:** `SHA256SUMS` on the same [GitHub Release](https://github.com/vantaboard/go-googlesql/releases)
- **Workflow:** [`.github/workflows/release-prebuilts.yml`](../.github/workflows/release-prebuilts.yml) (runs on `push` of `v*` tags)
- **Packaging:** `bash scripts/package-default-prebuilts.sh` or **`task package:default-prebuilts-tarball`**

**Protobuf-only tarball** (narrow CI / debugging): `bash scripts/package-protobuf-prebuilt.sh` still produces `go-googlesql-prebuilts-protobuf-${GOOS_GOARCH}.tar.gz` with only the protobuf `lib/` tree—use for **`task test:protobuf-cgo`**, not for full **`googlesql,googlesql_unified_prebuilt`** links without also supplying `libgooglesql.a`.

**Install (default stack):**

```bash
# From repo root after verifying SHA256SUMS
tar -xzf go-googlesql-prebuilts-default-linux_amd64-vX.Y.Z.tar.gz
task verify:prebuilt-protobuf
task verify:prebuilt-googlesql-unified
task test:local TESTPKG=./
```

## Versioning (tarball ↔ git ↔ module)

| Artifact | Maps to |
|----------|---------|
| Release filename `...-<tag>.tar.gz` | Git tag `tag` (e.g. `v1.2.3`) |
| Go module version | `go.mod` / `github.com/vantaboard/go-googlesql` **semver** matching the tag you depend on in `require` |
| Prebuilt archive bytes | Built from that tag’s tree; **verify** `SHA256SUMS` when downloading |

Downstream apps should pin the **same** module version and unpack the matching release asset (or rebuild with `task prebuilt:protobuf` **and** `task prebuilt:googlesql-unified` on that checkout).

## Artifact matrix (CI vs local)

| Context | Prebuilt `libprotobuf_cgo.a` | Tags |
|---------|------------------------------|------|
| Default **GitHub Actions** ([`go.yml`](../.github/workflows/go.yml)) | Protobuf + `libgooglesql.a` built on the runner, then `task test:local` | `googlesql,googlesql_unified_prebuilt` |
| **Manual default-prebuilt workflow** ([`go-tier-b-prebuilt.yml`](../.github/workflows/go-tier-b-prebuilt.yml)) | Built on the runner with Bazel, then `task test:protobuf-cgo` | `googlesql,googlesql_unified_prebuilt` |
| **Manual Abseil Tier B** ([`go-tier-b-absl-prebuilt.yml`](../.github/workflows/go-tier-b-absl-prebuilt.yml)) | Builds `libabsl_cgo.a`, then `task test:tier-b-absl` | `googlesql,googlesql_tier_b_absl` |
| **Consumer gate (no Bazel)** ([`go-prebuilt-consumer.yml`](../.github/workflows/go-prebuilt-consumer.yml)) | Default bundle artifact; extract then `task verify:*` + `task test:local TESTPKG=./` | `googlesql,googlesql_unified_prebuilt` |
| **GitHub Release** ([`release-prebuilts.yml`](../.github/workflows/release-prebuilts.yml)) | Published **default** tarball per `v*` tag | N/A (download + extract) |
| **Local dev** | Run `task prebuilt:protobuf` + `task prebuilt:googlesql-unified` (and `task prebuilt:absl` for Tier B) | `googlesql,googlesql_unified_prebuilt` or pilot tags |

Static `.a` files remain **gitignored**; published **tarballs** are optional release assets, not part of the Go module zip.

## Troubleshooting

| Symptom | What to check |
|---------|----------------|
| `prebuilt protobuf archive not found` | Run `task prebuilt:protobuf` or extract release tarball so `internal/ccall/go-protobuf/protobuf/lib/<GOOS_GOARCH>/libprotobuf_cgo.a` exists. |
| `prebuilt libc++ copy missing` / `libcxx_prebuilt.a` (Linux) | Re-run `task prebuilt:protobuf`; the extract script copies Bazel **llvm_toolchain** `libc++.a` / `libc++abi.a` next to `libprotobuf_cgo.a`. Release tarballs include the whole `lib/` tree. |
| Wrong architecture | Archive is built for the machine that ran Bazel (`go env GOOS GOARCH`). Do not use a `linux_amd64` `.a` on `darwin_arm64`. |
| Link errors after enabling `googlesql_tier_b_absl` in a binary that also uses default protobuf | The default protobuf owner already links `libprotobuf_cgo.a` and embeds Abseil; do not mix that with `googlesql_tier_b_absl` unless the final link is known not to import `go-protobuf`. See [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). |
| Undefined `std::__1::` vs `std::__cxx11::` | Set `CGO_CXXFLAGS=-stdlib=libc++` for the default protobuf prebuilt path (Bazel uses libc++). |
| Undefined `std::__1::__hash_memory` / `[abi:ne…]` on libc++ symbols from `time_zone_impl.pic.o` / `cord_analysis.pic.o` | Host `-lc++` does not match the libc++ ABI used when Bazel built Abseil. Ensure **`libcxx_prebuilt.a`** / **`libcxxabi_prebuilt.a`** are present and linked by the default protobuf bind; rebuild prebuilts on this machine. |
| Undefined Cord / `MessageLite::*Cord` while `llvm-nm` shows them **`T`** in `libprotobuf_cgo.a` | Often **Abseil inline namespace** mismatch (`absl::Cord` vs `absl::lts_20240722::Cord`). Align [`internal/ccall/absl/base/options.h`](../internal/ccall/absl/base/options.h) with BCR abseil-cpp (see **Abseil inline namespace** above). |
| Undefined `google::protobuf::File::ReadFileToString` from archive members like **`crate_mapping.pic.o`** | The extract `find` was too broad; **`google/protobuf/compiler/**`** objects must not be merged (protoc backends). Current script excludes that path; rebuild **`libprotobuf_cgo.a`**. |
| `nm` / `llvm-nm` spot checks | `llvm-nm -C internal/ccall/go-protobuf/protobuf/lib/<GOOS_GOARCH>/libprotobuf_cgo.a \| rg 'ParseFromCord\|crate_mapping\|compiler/'`. Optional: `VERIFY_LIBPROTOBUF_CGO_SYMBOLS=1 bash scripts/verify-libprotobuf-cgo-symbols.sh`. |
| Drift between Bazel protobuf and vendored headers | Run `task verify:protobuf-tier-b`; follow alignment steps in **Protobuf version / codegen alignment** above. |

## Related files

- [`extract_absl_cgo_lib.sh`](../internal/ccall/go-absl/extract_absl_cgo_lib.sh) — Bazel Abseil → `libabsl_cgo.a`
- [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md) — overlap with `libprotobuf_cgo.a`
- [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) / [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go) — default link-only CGO for protobuf
- [`Dockerfile.prebaked`](../Dockerfile.prebaked) — skeleton image for future prefix-based workflows
- [`docs/native-build-pipeline.md`](native-build-pipeline.md) — native artifact pipeline and shard ordering notes
