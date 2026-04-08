# Tier B + unified Abseil / protobuf namespaces

This document is the **implementation roadmap** for combining:

1. **Tier B** — link [`libprotobuf_cgo.a`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) built by Bazel in the submodule instead of (or as an alternative to) the vendored [`export.inc`](../internal/ccall/go-protobuf/protobuf/export.inc) amalgamation in `go-protobuf/protobuf`.
2. **One namespace story** — use **plain** `absl::` and `google::protobuf::` everywhere in a single link, so protobuf code compiled in one archive matches headers included from analyzer/parser/other shards.

The naive “drop `#include` of the amalgamation and blank-import `go-protobuf`” approach fails because those shards currently use **`#define absl <fqdn>_absl`** (see [`templates/bind.cc.tmpl`](../internal/cmd/generator/templates/bind.cc.tmpl)), so templates and out-of-line references expect **renamed** Abseil types, while a separately built protobuf TU uses **plain** `absl::`. See [`docs/protobuf-single-owner-inventory.md`](protobuf-single-owner-inventory.md).

## Phase 0 — Tooling in this repo (done / ongoing)

| Piece | Role |
|--------|------|
| [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) | Builds `lib/$GOOS_$GOARCH/libprotobuf_cgo.a` and symlinks `lib/libprotobuf_cgo.a`. |
| [`bind_tier_b.go`](../internal/ccall/go-protobuf/protobuf/bind_tier_b.go) | Build tag **`googlesql_tier_b`**: CGO links `-lprotobuf_cgo` instead of compiling `export.inc` (experimental). |
| [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) / [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go) | Build tag **`!googlesql_tier_b`**: default amalgamation path. |
| Generator [`global_exclude_replace_names`](../internal/cmd/generator/config.yaml) under `cclib` | When set to e.g. `[absl, google]`, **every** generated `bind.cc` omits `#define absl` / `#define google` — **opt-in**, default `[]`. |

## Phase 1 — Build the Bazel archive locally

```bash
# From go-googlesql repo root; requires bazelisk/bazel and populated submodule / cache per updater docs.
make extract-protobuf-lib
```

Confirm `internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a` exists (symlink to `linux_amd64/libprotobuf_cgo.a` or similar).

## Phase 2 — Try Tier B link for `go-protobuf` only

```bash
go test -tags 'googlesql,googlesql_tier_b' -count=1 ./internal/ccall/go-protobuf/protobuf/
```

Expect link errors until Phases 3–4 align symbols (no `export_protobuf_*` from amalgamation, possible missing Abseil objects). This step checks that **`-lprotobuf_cgo`** resolves on your platform.

Optional Makefile target: **`make local/test-tier-b`** (passes `-tags googlesql,googlesql_tier_b`).

## Phase 3 — Unified `absl` / `google` macros (generator)

1. Uncomment / set in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml):

   ```yaml
   cclib:
     global_exclude_replace_names:
       - absl
       - google
   ```

2. Run `go run .` in [`internal/cmd/generator`](../internal/cmd/generator) and fix compile/link failures iteratively.

**Risk:** omitting `absl` rename can surface **duplicate Abseil symbols** across CGO packages that each still compile pieces of Abseil. Mitigations:

- Prefer **not** compiling Abseil `.cc` in every shard; link **one** `libabsl` (Bazel-built, matching protobuf’s Abseil) similarly to protobuf.
- Or keep **`--allow-multiple-definition`** only while migrating (already in [`Makefile`](../Makefile)).

## Phase 4 — Descriptor / runtime patches

After the link is stable, revisit vendored edits under [`internal/ccall/protobuf/google/protobuf/`](../internal/ccall/protobuf/google/protobuf) that existed to paper over **multi-TU duplicate registration**; many may shrink or move to [`vendorpatch`](../internal/vendorpatch).

## Phase 5 — Downstream

Align [`go-googlesqlite`](https://github.com/vantaboard/go-googlesqlite) and [`bigquery-emulator`](https://github.com/goccy/bigquery-emulator) `CGO_LDFLAGS` and tags once go-googlesql’s default or documented path is fixed.

## Build tags summary

| Tag | Meaning |
|-----|---------|
| `zetasql` | Normal CGO GoogleSQL/GoogleSQL build (existing). |
| `googlesql_tier_b` | Use `bind_tier_b.go` in `go-protobuf/protobuf` (link `libprotobuf_cgo.a`); requires archive + symlink. |

Use **both** for Tier B experiments: `-tags 'googlesql,googlesql_tier_b'`.
