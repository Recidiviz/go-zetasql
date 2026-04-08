# Protobuf amalgamation — scale and consolidation notes

This doc captures **inventory** from the protobuf CGO consolidation effort and the **blocking constraint** on a naive “single owner” layout.

## Scale (current generator output)

- **~150+** `export.inc` files under `internal/ccall/go-googlesql/` reference
  `#include "go-protobuf/protobuf/export.inc"` (plus parallel paths under
  `legacy_zetasql/`).
- **780+** `bind.cc` files under `internal/ccall/go-googlesql/`.
- Each **separate** Go CGO package with its own `bind.cc` is a **separate
  translation unit**. The `PROTOBUF_EXPORT_H` guard in `export.inc` only
  deduplicates **within** one TU, not across packages—so the amalgamation is
  compiled **many times** unless the build model changes.

## Why “link-only go-protobuf” (Tier A) does not drop in

A spike removed `#include "go-protobuf/protobuf/export.inc"` from non-`go-protobuf`
packages and relied on blank-importing
[`internal/ccall/go-protobuf/protobuf`](../internal/ccall/go-protobuf/protobuf).

**Link failed** with missing `google::protobuf::…` / `AssignDescriptors(…,
<renamed absl>::once_flag*, …)`-style symbols.

**Root cause:** [`go-protobuf/protobuf`](../internal/ccall/go-protobuf/protobuf)
compiles the amalgamation with **plain** `absl::` and stable `google::protobuf::`.
Analyzer, parser, and other shards compile with **per-shard preprocessor
renames**, e.g. `#define absl googlesql_public_analyzer_googlesql_absl`, so
protobuf headers in those TUs instantiate templates and types in the **renamed**
Abseil namespace. A separately built `go-protobuf` TU cannot satisfy those
symbols: it is not the same C++ ABI as “protobuf + renamed absl” in the shard.

So consolidation is not only “one archive”—it requires a **single Abseil /
protobuf macro domain** for everything that must link together, or a redesigned
boundary.

## Practical follow-ups (in order of structural impact)

1. **Tier B + unified namespaces** — phased roadmap in
   **[`docs/tier-b-absl-protobuf.md`](tier-b-absl-protobuf.md)** (build tag
   `googlesql_tier_b`, [`bind_tier_b.go`](../internal/ccall/go-protobuf/protobuf/bind_tier_b.go),
   generator `cclib.global_exclude_replace_names`). Prebuilt archive:
   [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh).
   Also [protobuf-vendoring.md](protobuf-vendoring.md) § *Single-owner protobuf*.

2. **Reduce duplicates inside one macro island** — e.g. merge includes so fewer
   TUs repeat the same amalgamation **without** crossing absl rename boundaries.

3. **Keep** [`Makefile`](../Makefile) `CGO_LDFLAGS` using
   `-Wl,--allow-multiple-definition` until duplicate protobuf objects are
   actually eliminated by design—not by accident.

## Verification (when changing layout)

- `make local/test` (root package), then go-googlesqlite / bigquery-emulator with
  shared `GOCACHE` per the zetasql-stack-debug skill.
- On link errors involving `…_absl::` vs `absl::`, suspect **macro / ABI
  mismatch** before chasing “missing patch” in vendored protobuf.
