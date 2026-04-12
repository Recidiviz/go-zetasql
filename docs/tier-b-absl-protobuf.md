# Default protobuf prebuilts + unified Abseil / protobuf namespaces

**Consolidation program (shards, CI invariants, exit criteria):** [cgo-consolidation.md](cgo-consolidation.md).

Operational commands, env vars, and downstream notes: **[prebuilt-cgo.md](prebuilt-cgo.md)**.

This document is the **implementation roadmap** for combining:

1. **Default protobuf prebuilt** — link [`libprotobuf_cgo.a`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) built by Bazel in the submodule instead of the removed single-TU amalgamation bundle that previously lived under `go-protobuf/protobuf`.
2. **One namespace story** — use **plain** `absl::` and `google::protobuf::` everywhere in a single link, so protobuf code compiled in one archive matches headers included from analyzer/parser/other shards.

The naive “drop `#include` of the amalgamation and blank-import `go-protobuf`” approach fails because those shards currently use **`#define absl <fqdn>_absl`** (see [`templates/bind.cc.tmpl`](../internal/cmd/generator/templates/bind.cc.tmpl)), so templates and out-of-line references expect **renamed** Abseil types, while a separately built protobuf TU uses **plain** `absl::`. See [`docs/protobuf-single-owner-inventory.md`](protobuf-single-owner-inventory.md).

## Prebuilt tag policy (single Abseil owner)

**Rule:** the default protobuf prebuilt owner (with or without the deprecated `googlesql_tier_b` alias) and `googlesql_tier_b_absl` (link `libabsl_cgo.a`) must **not** both appear in the same binary — `libprotobuf_cgo.a` already embeds Abseil objects. Use **either** default protobuf prebuilts **or** the Abseil pilot in an isolated link.

- **Canonical matrix:** [`docs/prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md)
- **Preflight:** `task verify:tier-b-cgo-policy` ([`scripts/verify-tier-b-cgo-tag-policy.sh`](../scripts/verify-tier-b-cgo-tag-policy.sh))
- **CI:** default workflow [`.github/workflows/go.yml`](../.github/workflows/go.yml) and manual workflows [`.github/workflows/go-tier-b-prebuilt.yml`](../.github/workflows/go-tier-b-prebuilt.yml) (focused protobuf prebuilt verification) plus [`.github/workflows/go-tier-b-absl-prebuilt.yml`](../.github/workflows/go-tier-b-absl-prebuilt.yml) (Abseil pilot) run the same preflight policy before native builds.

Generator / bind files: [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go), [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go), [`templates/bind_tier_b_absl.go.tmpl`](../internal/cmd/generator/templates/bind_tier_b_absl.go.tmpl) — cross-check edits against `prebuilt-absl-overlap.md`. The longer-term single-owner direction for the main `googlesql` path is now the unified archive [`libgooglesql.a`](../internal/ccall/go-googlesql-unified/).

## Phase 0 — Tooling in this repo (done / ongoing)

| Piece | Role |
|--------|------|
| [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) | Builds `lib/$GOOS_$GOARCH/libprotobuf_cgo.a` and symlinks `lib/libprotobuf_cgo.a`. |
| [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) / [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go) | Default protobuf CGO bind files: link `libprotobuf_cgo.a` only (no amalgamated protobuf sources in this package). |
| Generator [`global_exclude_replace_names`](../internal/cmd/generator/config.yaml) under `cclib` | Set to **`[absl, google]`** so generated `bind.cc` omits per-shard `#define absl` / `#define google` where the generator applies global excludes (run `go run .` in `internal/cmd/generator` after edits). |
| [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt) + [`link_only_bind_packages`](../internal/cmd/generator/config.yaml) | First unified root slice: build parser/analyzer/catalog/sql_formatter objects into `libgooglesql.a`, then use thin link-only `bind.cc` stubs under `googlesql_unified_prebuilt`. |

## Phase 1 — Build the Bazel archive locally

```bash
# From go-googlesql repo root; requires bazelisk/bazel and populated submodule / cache per updater docs.
task prebuilt:protobuf
# (task alias: extract:protobuf)
```

Confirm `internal/ccall/go-protobuf/protobuf/lib/libprotobuf_cgo.a` exists (symlink to `linux_amd64/libprotobuf_cgo.a` or similar).

## Phase 2 — Try the default prebuilt link for `go-protobuf` only

```bash
go test -tags 'googlesql' -count=1 ./internal/ccall/go-protobuf/protobuf/
```

Expect link errors until Phases 3–4 align symbols (no `export_protobuf_*` from amalgamation, possible missing Abseil objects). This step checks that **`-lprotobuf_cgo`** resolves on your platform.

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
- Or keep **`--allow-multiple-definition`** only while migrating (already in [`Taskfile.yml`](../Taskfile.yml)).

## Phase 4 — Descriptor / runtime patches

After the link is stable, revisit vendored edits under [`internal/ccall/protobuf/google/protobuf/`](../internal/ccall/protobuf/google/protobuf) that existed to paper over **multi-TU duplicate registration**; many may shrink or move to [`vendorpatch`](../internal/vendorpatch).

## Phase 5 — Downstream

Align [`go-googlesqlite`](https://github.com/vantaboard/go-googlesqlite) and [`bigquery-emulator`](https://github.com/goccy/bigquery-emulator) `CGO_LDFLAGS` and tags once go-googlesql’s default or documented path is fixed.

## Current root-slice rollout

The first prebuilt-heavy slice now targets the **root Go package** (`TESTPKG=./`) by moving the largest public/parser CGO owners to a link-only path under `googlesql_unified_prebuilt`:

- `googlesql/public/analyzer`
- `googlesql/public/catalog`
- `googlesql/public/simple_catalog`
- `googlesql/public/sql_formatter`
- `googlesql/parser/parser`
- `googlesql/parser/bison_parser_generated_lib`

Use this slice with:

```bash
task prebuilt:protobuf verify-prebuilt-protobuf
task prebuilt:googlesql-unified verify-prebuilt-googlesql-unified
task build:googlesql-unified-root
task test:googlesql-unified-root
```

GoogleSQL CGO uses **`googlesql` + `googlesql_unified_prebuilt`** with prebuilt archives and link-only binds — see [link-only-cgo-migration.md](link-only-cgo-migration.md).

## Related tooling (repo root)

| Taskfile / script | Purpose |
|-------------------|---------|
| `task verify:protobuf-tier-b` | Warn if vendored protobuf is below Bazel 29.x-era macros; strict mode: `VERIFY_PROTOBUF_TIER_B_STRICT=1` |
| `task sync:protobuf-vendor-from-bazel` | Copy Bazel `@com_google_protobuf` sources into `internal/ccall/protobuf/` (then `go run ./internal/cmd/vendorpatch`) |
| `task regenerate:ccall-cpp-protos` | Regenerate `internal/ccall` `*.pb.{h,cc}` (googlesql, googleapis, proto) with Bazel-built `protoc` (`regenerate:googlesql-cpp-protos` is an alias) |
| `task verify:tier-b-cgo-policy` | Print supported / unsupported tag combinations |
| [link-only-cgo-migration.md](link-only-cgo-migration.md) | Generator opt-in `cclib.link_only_bind_packages` for thin `bind.cc` |

## Build tags summary

| Tag | Meaning |
|-----|---------|
| `googlesql` | Default CGO GoogleSQL build with the protobuf prebuilt owner. |
| `googlesql_tier_b` | Deprecated compatibility alias; protobuf already uses the prebuilt owner by default. |
| `googlesql_tier_b_absl` | Use `bind_tier_b_absl.go` in packages that define it (`go-absl/meta/type_traits`, `base/config`, `utility/utility`, …); link `libabsl_cgo.a` from [`extract_absl_cgo_lib.sh`](../internal/ccall/go-absl/extract_absl_cgo_lib.sh). See [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md) before combining with `googlesql_tier_b`. |

Use **`googlesql`** for the default protobuf prebuilt path: `-tags 'googlesql'`.  
Use **`googlesql` and `googlesql_tier_b_absl`** for the isolated Abseil pilot: `-tags 'googlesql,googlesql_tier_b_absl'`.
