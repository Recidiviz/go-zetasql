# Native build pipeline (prebuilt `.a` artifacts)

This note maps **which C++ surfaces** move first when evolving from per-package CGO compilation toward **prebuilt archives** (Bazel or CMake). It is a companion to [`prebuilt-cgo.md`](prebuilt-cgo.md) and [`tier-b-absl-protobuf.md`](tier-b-absl-protobuf.md).

## Primary pipeline (today): Bazel in the GoogleSQL submodule

[`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) runs:

```bash
bazel build @com_google_protobuf//:protobuf
```

then merges `*.pic.o` from `com_google_protobuf` and `utf8_range` into `libprotobuf_cgo.a`.

**Why Bazel first:** The submodule already uses the same dependency graph as upstream GoogleSQL; protobuf is the largest shared hub and is the first Tier B target.

## Suggested shard order for future consolidation

| Phase | Content | Notes |
|-------|---------|--------|
| 1 | **Protobuf + utf8_range** | Implemented by `make prebuilt-libs` / `bind_tier_b.go`. |
| 2 | **Abseil** | **`make prebuilt-libs-absl`** → `libabsl_cgo.a`. **Incremental rollout:** [`meta/type_traits`](../internal/ccall/go-absl/meta/type_traits), [`base/config`](../internal/ccall/go-absl/base/config), [`utility/utility`](../internal/ccall/go-absl/utility/utility) use `bind_tier_b_absl.go` + `googlesql_tier_b_absl`. Overlap / multi-package link: [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). Consolidated single-owner option: below. |
| 3 | **googlesql public / analyzer** | Large `export.inc` bundles; consolidating requires a stable C bridge ABI (see [`templates/bind.cc.tmpl`](../internal/cmd/generator/templates/bind.cc.tmpl)). |
| 4 | **Parser / flex** | Depends on phase 3 includes and generated sources. |

Detailed duplicate-symbol inventory: [`protobuf-single-owner-inventory.md`](protobuf-single-owner-inventory.md).

### Rollout strategy (Abseil)

- **Option A — incremental:** Add `//go:build !googlesql_tier_b_absl` to `bind_linux.go` / `bind_darwin.go` and `bind_tier_b_absl.go` per `go-absl` package (same pattern as the pilot), then extend [`internal/cmd/generator`](../internal/cmd/generator) to omit Abseil `.cc` bodies when a tag is set—many files, predictable edits.
- **Option B — consolidated:** Introduce one package (e.g. `internal/ccall/go-absl/prebuilt`) that links `libabsl_cgo.a` once; other packages blank-import it and stop compiling Abseil in their `bind.cc`—fewer linker inputs, larger refactor.

## Install prefix layout

Future consolidated installs (multiple `.a` + headers) should follow a single **prefix** so **pkg-config** can drive `CGO_CFLAGS` / `CGO_LDFLAGS`:

- `$(prefix)/lib/libgooglesql*.a`
- `$(prefix)/include/...`
- `$(prefix)/lib/pkgconfig/googlesql.pc`

See [`contrib/googlesql.pc.example`](../contrib/googlesql.pc.example) and [`Dockerfile.prebaked`](../Dockerfile.prebaked).

## Link flags

[`Makefile`](../Makefile) passes `-Wl,--allow-multiple-definition` while multiple CGO translation units still overlap. **Goal:** remove that flag for protobuf-related duplicates once a single owner exists; do not rely on it for correctness long term (see stack upgrade command notes on runtime risk).
