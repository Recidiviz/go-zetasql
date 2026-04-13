# Native build pipeline (prebuilt `.a` artifacts)

This note maps how **Bazel-built static archives** feed the default Go CGO path. The **primary pipeline is implemented:** protobuf + utf8_range via **`libprotobuf_cgo.a`**, GoogleSQL via **`libgooglesql.a`**, link-only generated binds — see [`prebuilt-cgo.md`](prebuilt-cgo.md) and [`link-only-cgo-migration.md`](link-only-cgo-migration.md). Below, **phase table** entries marked *done* reflect that; remaining rows are **Tier B pilots** or **incremental consolidation** ([cgo-consolidation.md](cgo-consolidation.md)).

## Primary pipeline (today): Bazel in the GoogleSQL submodule

[`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) runs:

```bash
bazel build @com_google_protobuf//:protobuf
```

then merges `*.pic.o` from `com_google_protobuf` and `utf8_range` into `libprotobuf_cgo.a`.

### Where outputs land (repo paths)

After `task prebuilt:protobuf` (or CI equivalents), static archives live under:

- **Protobuf Tier B:** `internal/ccall/go-protobuf/protobuf/lib/<GOOS_GOARCH>/libprotobuf_cgo.a` and a symlink `internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a` when the extract script creates it.
- **Abseil Tier B:** `internal/ccall/go-absl/lib/<GOOS_GOARCH>/libabsl_cgo.a` (see [`extract_absl_cgo_lib.sh`](../internal/ccall/go-absl/extract_absl_cgo_lib.sh)).
- **Unified GoogleSQL:** `internal/ccall/go-googlesql-unified/lib/<GOOS_GOARCH>/libgooglesql.a` (see [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh)).

Archives are **gitignored**; release tarballs preserve the `internal/ccall/.../lib/` tree (see [`prebuilt-cgo.md`](prebuilt-cgo.md#release-tarballs-linux_amd64)).

**Why Bazel first:** The submodule already uses the same dependency graph as upstream GoogleSQL; protobuf is the largest shared hub and is now the default prebuilt target.

### Single CGO owner and duplicate symbols

Tier B reduces **compile** duplication by linking one Bazel-built archive per hub (protobuf, Abseil, unified googlesql). Multiple CGO packages still participate in one link; until every shard is migrated, [`Taskfile.yml`](../Taskfile.yml) may pass `-Wl,--allow-multiple-definition` as a transitional measure. **Protobuf vs Abseil Tier B:** `libprotobuf_cgo.a` already embeds Abseil objects—do not link `libabsl_cgo.a` in the same build without the policy in [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). Namespace / macro alignment for generated `bind.cc` is summarized in [`protobuf-vendoring.md`](protobuf-vendoring.md) and [`link-only-cgo-migration.md`](link-only-cgo-migration.md).

### Amalgamation (removed for protobuf)

The old protobuf amalgamation bind path has been removed from the default Linux/Darwin package. [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) / [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go) now link the protobuf prebuilt archive directly, and CI’s default [`go.yml`](../.github/workflows/go.yml) bootstraps that archive before testing ([`prebuilt-cgo.md`](prebuilt-cgo.md)).

## Shard order (history + what is left)

| Phase | Content | Status |
|-------|---------|--------|
| 1 | **Protobuf + utf8_range** | **Done** — `task prebuilt:protobuf` / default [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) bind files. |
| 2 | **Abseil Tier B pilot** | **Optional** — `task prebuilt:absl` → `libabsl_cgo.a`; isolated packages use `bind_tier_b_absl.go` + `googlesql_tier_b_absl`. Do not mix with default protobuf prebuilt in one link: [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). |
| 3 | **googlesql public / analyzer** | **Default path** uses link-only binds + `libgooglesql.a`; bridge ABI still [`templates/bind.cc.tmpl`](../internal/cmd/generator/templates/bind.cc.tmpl). Further shrink = consolidation playbook. |
| 3b | **Unified `libgooglesql.a`** | **Done** for the supported root slice — [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh), [`libgooglesql-unified.md`](libgooglesql-unified.md); default target list includes analyzer/parser when the workspace builds. |
| 4 | **Parser / flex** | **In** unified archive + link-only shards when using default tags; flex/parser details in [cgo-consolidation.md](cgo-consolidation.md). |
| 4b | **Generator link-only `bind.cc`** | **Default** for `googlesql/*` and packages under `cclib.link_only_bind_packages` — [`link-only-cgo-migration.md`](link-only-cgo-migration.md). |

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

[`Taskfile.yml`](../Taskfile.yml) passes `-Wl,--allow-multiple-definition` while multiple CGO translation units still overlap. **Goal:** remove that flag for protobuf-related duplicates once a single owner exists; do not rely on it for correctness long term (see stack upgrade command notes on runtime risk).
