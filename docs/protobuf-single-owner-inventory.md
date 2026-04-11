# Protobuf amalgamation — scale and consolidation notes

**Related:** multi-phase CGO/prebuilt consolidation charter, inventory script, and CI checks — [cgo-consolidation.md](cgo-consolidation.md).

This doc captures **inventory** from the protobuf CGO consolidation effort and the **blocking constraint** on a naive “single owner” layout.

## Scale (current generator output)

- Generator policy and [`internal/exportinc`](../internal/exportinc/exportinc.go) **strip** any stray `#include "go-protobuf/protobuf/export.inc"` line from `export.inc` preludes outside `go-protobuf/protobuf`; the **file itself is removed** — default protobuf comes from Bazel **`libprotobuf_cgo.a`** linked in [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) / [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go).
- **780+** `bind.cc` files under `internal/ccall/go-googlesql/`.
- Each **separate** Go CGO package with its own `bind.cc` is a **separate
  translation unit**; cross-package protobuf symbols are satisfied by the shared prebuilt archive plus consistent `#define` policy (see [`tier-b-absl-protobuf.md`](tier-b-absl-protobuf.md)).

## Historical spike: link-only import without prebuilt alignment

An earlier experiment removed `#include "go-protobuf/protobuf/export.inc"` from non-`go-protobuf`
packages and relied only on blank-importing
[`internal/ccall/go-protobuf/protobuf`](../internal/ccall/go-protobuf/protobuf)
**without** aligning Abseil rename policy to a single-owner archive.

**Link failed** with missing `google::protobuf::…` / `AssignDescriptors(…,
<renamed absl>::once_flag*, …)`-style symbols.

**Root cause:** shards compile with **per-shard preprocessor
renames**, e.g. `#define absl googlesql_public_analyzer_googlesql_absl`, so
protobuf headers in those TUs instantiate templates in the **renamed**
Abseil namespace. The **default prebuilt** path uses **plain** `absl::` inside
`libprotobuf_cgo.a`; the generator’s **`cclib.global_exclude_replace_names`** (and related knobs) keeps that link coherent.

So consolidation is not only “one archive”—it requires a **single Abseil /
protobuf macro domain** for everything that must link together, or a redesigned
boundary.

## Practical follow-ups (in order of structural impact)

1. **Tier B + unified namespaces** — phased roadmap in
   **[`docs/tier-b-absl-protobuf.md`](tier-b-absl-protobuf.md)** (build tag
   default protobuf prebuilts, [`bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) /
   [`bind_darwin.go`](../internal/ccall/go-protobuf/protobuf/bind_darwin.go),
   generator `cclib.global_exclude_replace_names`). Prebuilt archive:
   [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh).
   Also [protobuf-vendoring.md](protobuf-vendoring.md) § *Single-owner protobuf*.

2. **Reduce duplicates inside one macro island** — e.g. merge includes so fewer
   TUs repeat the same amalgamation **without** crossing absl rename boundaries.

3. **Keep** [`Taskfile.yml`](../Taskfile.yml) / [`.envrc`](../.envrc) / [`scripts/go-googlesql-env.sh`](../scripts/go-googlesql-env.sh) (`CGO_LDFLAGS_BASE`, allowlist) using
   `-Wl,--allow-multiple-definition` until duplicate protobuf objects are
   actually eliminated by design—not by accident.

## Verification (when changing layout)

- `task test:local` with `TESTPKG=./` when exercising the root package; then go-googlesqlite / bigquery-emulator with
  shared `GOCACHE` per the googlesql-stack-debug skill.
- On link errors involving `…_absl::` vs `absl::`, suspect **macro / ABI
  mismatch** before chasing “missing patch” in vendored protobuf.
