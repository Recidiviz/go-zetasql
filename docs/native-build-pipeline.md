# Native build pipeline (prebuilt `.a` artifacts)

This note maps **which C++ surfaces** move first when evolving from per-package CGO compilation toward **prebuilt archives** (Bazel or CMake). It is a companion to [`prebuilt-cgo.md`](prebuilt-cgo.md) and [`tier-b-absl-protobuf.md`](tier-b-absl-protobuf.md).

## Primary pipeline (today): Bazel in the GoogleSQL submodule

[`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) runs:

```bash
bazel build @com_google_protobuf//:protobuf
```

then merges `*.pic.o` from `com_google_protobuf` and `utf8_range` into `libprotobuf_cgo.a`.

### Where outputs land (repo paths)

After `make prebuilt-libs` (or CI equivalents), static archives live under:

- **Protobuf Tier B:** `internal/ccall/go-protobuf/protobuf/lib/<GOOS_GOARCH>/libprotobuf_cgo.a` and a symlink `internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a` when the extract script creates it.
- **Abseil Tier B:** `internal/ccall/go-absl/lib/<GOOS_GOARCH>/libabsl_cgo.a` (see [`extract_absl_cgo_lib.sh`](../internal/ccall/go-absl/extract_absl_cgo_lib.sh)).
- **Unified GoogleSQL:** `internal/ccall/go-googlesql-unified/lib/<GOOS_GOARCH>/libgooglesql.a` (see [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh)).

Archives are **gitignored**; release tarballs preserve the `internal/ccall/.../lib/` tree (see [`prebuilt-cgo.md`](prebuilt-cgo.md#release-tarballs-linux_amd64)).

**Why Bazel first:** The submodule already uses the same dependency graph as upstream GoogleSQL; protobuf is the largest shared hub and is the first Tier B target.

### Single CGO owner and duplicate symbols

Tier B reduces **compile** duplication by linking one Bazel-built archive per hub (protobuf, Abseil, unified googlesql). Multiple CGO packages still participate in one link; until every shard is migrated, [`Makefile`](../Makefile) may pass `-Wl,--allow-multiple-definition` as a transitional measure. **Protobuf vs Abseil Tier B:** `libprotobuf_cgo.a` already embeds Abseil objects—do not link `libabsl_cgo.a` in the same build without the policy in [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). Namespace / macro alignment for generated `bind.cc` is summarized in [`protobuf-vendoring.md`](protobuf-vendoring.md) and [`link-only-cgo-migration.md`](link-only-cgo-migration.md).

### Amalgamation (legacy default for protobuf)

**Legacy** here means the **default** protobuf CGO path when **`googlesql_tier_b` is not set:** [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) / [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go) compile the amalgamation bundle. Opting into Tier B selects [`bind_tier_b.go`](../internal/ccall/go-protobuf/protobuf/bind_tier_b.go) instead (`//go:build googlesql_tier_b`). CI’s default [`go.yml`](../.github/workflows/go.yml) uses the amalgamation path; Tier B is validated in manual / scheduled workflows ([`prebuilt-cgo.md`](prebuilt-cgo.md)).

## Suggested shard order for future consolidation

| Phase | Content | Notes |
|-------|---------|--------|
| 1 | **Protobuf + utf8_range** | Implemented by `make prebuilt-libs` / `bind_tier_b.go`. |
| 2 | **Abseil** | **`make prebuilt-libs-absl`** → `libabsl_cgo.a`. **Incremental rollout:** [`meta/type_traits`](../internal/ccall/go-absl/meta/type_traits), [`base/config`](../internal/ccall/go-absl/base/config), [`utility/utility`](../internal/ccall/go-absl/utility/utility) use `bind_tier_b_absl.go` + `googlesql_tier_b_absl`. Overlap / multi-package link: [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). Consolidated single-owner option: below. |
| 3 | **googlesql public / analyzer** | Large `export.inc` bundles; consolidating requires a stable C bridge ABI (see [`templates/bind.cc.tmpl`](../internal/cmd/generator/templates/bind.cc.tmpl)). |
| 3b | **Unified `libgooglesql.a` (bootstrap)** | [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) + [`docs/libgooglesql-unified.md`](libgooglesql-unified.md): Bazel `*.pic.o` from configurable targets (default several `//googlesql/base:*` libs) plus a C anchor. Expand targets toward `//googlesql/public:analyzer` when the Bazel graph is available. |
| 4 | **Parser / flex** | Depends on phase 3 includes and generated sources. |
| 4b | **Generator link-only `bind.cc`** | Opt-in `cclib.link_only_bind_packages` in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) + [`link-only-cgo-migration.md`](link-only-cgo-migration.md). **Production opt-in** for `googlesql/public/*` is gated on namespace-aligned prebuilt objects (see **Namespace alignment** in that doc); generator templates and unified ABI (`googlesql_unified_capabilities`) support the rollout. |

Detailed duplicate-symbol inventory: [`protobuf-single-owner-inventory.md`](protobuf-single-owner-inventory.md).

### Rollout strategy (Abseil)

- **Option A — incremental:** Add `//go:build !googlesql_tier_b_absl` to `bind_linux.go` / `bind_darwin.go` and `bind_tier_b_absl.go` per `go-absl` package (same pattern as the pilot), then extend [`internal/cmd/generator`](../internal/cmd/generator) to omit Abseil `.cc` bodies when a tag is set—many files, predictable edits.
- **Option B — consolidated:** Introduce one package (e.g. `internal/ccall/go-absl/prebuilt`) that links `libabsl_cgo.a` once; other packages blank-import it and stop compiling Abseil in their `bind.cc`—fewer linker inputs, larger refactor.

## Install prefix layout

Future consolidated installs (multiple `.a` + headers) should follow a single **prefix** so **pkg-config** can drive `CGO_CFLAGS` / `CGO_LDFLAGS`:

- `$(prefix)/lib/libgooglesql.a` (bootstrap: [`internal/ccall/go-googlesql-unified/lib`](../internal/ccall/go-googlesql-unified/lib); see [`libgooglesql-unified.md`](libgooglesql-unified.md))
- `$(prefix)/include/...`
- `$(prefix)/lib/pkgconfig/googlesql.pc`

See [`contrib/googlesql.pc.example`](../contrib/googlesql.pc.example) and [`Dockerfile.prebaked`](../Dockerfile.prebaked).

## Link flags

[`Makefile`](../Makefile) passes `-Wl,--allow-multiple-definition` while multiple CGO translation units still overlap. **Goal:** remove that flag for protobuf-related duplicates once a single owner exists; do not rely on it for correctness long term (see stack upgrade command notes on runtime risk).
