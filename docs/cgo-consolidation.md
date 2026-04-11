# CGO / prebuilt consolidation program

This document defines the **explicit project** to shrink redundant CGO shards and stale `export.inc` preludes while preserving **single-owner** Abseil and protobuf rules. It complements [protobuf-single-owner-inventory.md](protobuf-single-owner-inventory.md), [tier-b-absl-protobuf.md](tier-b-absl-protobuf.md), [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md), and [link-only-cgo-migration.md](link-only-cgo-migration.md).

## In scope

- Inventory and classification of `internal/ccall/**/bind.cc` files that `#include` native `.cc` sources.
- Namespace / archive policy decisions (Abseil, cctz, protobuf) aligned with unified prebuilts.
- Generator and [internal/exportinc](../internal/exportinc/exportinc.go) hygiene for `export.inc` vs link-only `bind.cc`.
- CI gate: link-only `bind.cc` files must not regress to amalgamated `.cc` includes (see [scripts/cgo-shard-inventory.sh](../scripts/cgo-shard-inventory.sh)).
- Downstream verification notes (go-googlesqlite, bigquery-emulator).

## Out of scope

- Rewriting the GoogleSQL engine in pure Go or removing CGO from the public API.
- “Remove all of `internal/ccall/go-absl`” in one change set (multi-quarter effort; see risk register below).

## Hard constraints (every phase)

| Constraint | Reference |
|------------|-----------|
| Default tags **`googlesql` + `googlesql_unified_prebuilt`** with **`libprotobuf_cgo.a`** + **`libgooglesql.a`** | [prebuilt-cgo.md](prebuilt-cgo.md), [link-only-cgo-migration.md](link-only-cgo-migration.md) |
| Do **not** mix default protobuf prebuilts with **`googlesql_tier_b_absl`** + `libabsl_cgo.a` in one binary | [tier-b-absl-protobuf.md](tier-b-absl-protobuf.md), [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md) |
| **`cclib.global_exclude_replace_names`** (`absl`, `google`) stays coherent with `libprotobuf_cgo.a` | [internal/cmd/generator/config.yaml](../internal/cmd/generator/config.yaml) `cclib` |

## Baseline metrics (snapshot)

Regenerate counts with:

```bash
./scripts/cgo-shard-inventory.sh --summary
```

Optional dependency graph (unified prebuilt tags):

```bash
go list -tags googlesql,googlesql_unified_prebuilt -deps ./... | sort -u | head -80
```

Approximate scale (see also [protobuf-single-owner-inventory.md](protobuf-single-owner-inventory.md)):

- **780+** `bind.cc` files under `internal/ccall/go-googlesql/`.
- **`./scripts/cgo-shard-inventory.sh --summary`** reports how many `bind.cc` files anywhere under `internal/ccall/` still `#include` a `.cc` source (baseline snapshot: on the order of **~100** total, mostly **`go-absl`**, on the order of **10–12** **`go-googlesql`**, plus **`go-algorithms`**, **`go-proto`**, **`go-base`** — rerun for current counts).
- Many **link-only** binds (header comment: `Link-only bind.cc`; **~400** files) — implementations in **`libgooglesql.a`**; CI **`--check`** ensures these never `#include` amalgamated `.cc` bodies.
- **`go-absl/**`**, **`go-proto/**`**, and some **non-link-only** `go-googlesql/**` shards still `#include` `.cc` sources where a separate TU or single-owner rule requires it.

## Shard classification (A / B / C)

| Class | Meaning | Examples |
|-------|---------|----------|
| **A — Must compile in-repo** | True single-owner TU or flex/parser shard; cannot be dropped without moving symbols into an archive | cctz `time_zone` vs objects dropped from `libprotobuf_cgo.a` ([unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md)); flex tokenizer `.cc` in parser packages |
| **B — Candidate for consolidation** | Symbols likely already in `libgooglesql.a` / `libprotobuf_cgo.a` but shard still lists `.cc` in **non-link-only** generated binds | Legacy generator output (e.g. `zetasql_*` guards); requires **link/nm/runtime** proofs before removal |
| **C — Generated proto shard** | Small `*_cc_proto` packages with `.pb.cc` in `bind.cc` | [`go-proto`](../internal/ccall/go-proto) packages; consolidate only with descriptor / registration audit |

**Deliverable:** extend this table as you retire shards; do not delete packages without Phase 4 proofs.

## Archive and namespace policy (locked)

1. **Default binary:** Abseil / `google::protobuf` objects come from **`libprotobuf_cgo.a`** and **`libgooglesql.a`** with **`cclib.global_exclude_replace_names: [absl, google]`** so TUs match plain namespaces in those archives ([tier-b-absl-protobuf.md](tier-b-absl-protobuf.md) Phase 3).
2. **Tier B Abseil pilot:** **`googlesql_tier_b_absl`** + **`libabsl_cgo.a`** only for **isolated** package sets — **never** combined with the default protobuf prebuilt owner ([prebuilt-cgo.md](prebuilt-cgo.md)).
3. **cctz / civil_time:** Keep **extract** script dropped-object list ([extract_protobuf_cgo_lib.sh](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh)) aligned with [go-absl/time](../internal/ccall/go-absl/time) blank-import and civil_time policy ([unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md)).

## Generator and export.inc (audit)

- **Link-only `bind.cc`** is generated from [bind_link_only.cc.tmpl](../internal/cmd/generator/templates/bind_link_only.cc.tmpl) when the generator applies link-only mode for `googlesql/*` and packages listed under `cclib.link_only_bind_packages` ([config.yaml](../internal/cmd/generator/config.yaml)).
- Such files **must not** `#include` amalgamated `googlesql/.../*.cc` bodies; implementations are in **`libgooglesql.a`**. CI enforces this via `./scripts/cgo-shard-inventory.sh --check`.
- **[internal/exportinc](../internal/exportinc/exportinc.go)** derives `export.inc` preludes from `bind.cc` and applies **policy** (strip stray `go-protobuf/protobuf/export.inc`, analyzer `options.pb.cc` / `type.pb.cc` duplication guards, etc.). Link-only `bind.cc` preludes should remain **header-only**; stale `#include "*.cc"` lines in **on-disk** `export.inc` under link-only packages should be regenerated with `go run ./internal/cmd/generator` and exportinc sync — not hand-edited inconsistently.

**Regeneration:** `go run .` from [internal/cmd/generator](../internal/cmd/generator) after `config.yaml` changes ([link-only-cgo-migration.md](link-only-cgo-migration.md)).

## Phase 4 — Remove or merge shards (playbook)

For each **B** candidate:

1. **Link proof:** `task test:local TESTPKG=./path/to/pkg` or `go test -c -tags googlesql,googlesql_unified_prebuilt` with `-run '^$'`.
2. **Duplicate symbol proof:** `nm -C` / `llvm-nm` on `libprotobuf_cgo.a` and `libgooglesql.a` ([libgooglesql-unified.md](libgooglesql-unified.md)).
3. **Runtime proof:** full `task test:local`; watch for startup issues ([unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md)).
4. **Edit** [`bind_unified_prebuilt_linux.go` / `bind_unified_prebuilt_darwin.go`](../internal/ccall/go-googlesql/bind_unified_prebuilt_linux.go) blank imports only when link order is proven safe (**import order matters**).

**Status:** The stale duplicate package `internal/ccall/go-googlesql/public/timestamp_pico_value` (legacy `zetasql_*` amalgamation; no matching `cc_library` in `googlesql/public/BUILD`) was removed; the supported CGO shard is `internal/ccall/go-googlesql/public/timestamp_picos_value` (link-only + unified prebuilt). Use this checklist for further PRs.

**Example B candidates** (non-exhaustive; still use legacy `zetasql_*` guards or `#include "*.cc"` in `bind.cc` — regenerate to link-only before removal): `internal/ccall/go-googlesql/analyzer/rewriters/*`, `public/range_value`, `parser/flex_tokenizer`, and similar paths from `./scripts/cgo-shard-inventory.sh --list` filtered to `go-googlesql`.

## Phase 5 — CI and downstream

| Check | Command / workflow |
|-------|-------------------|
| Link-only invariant | `./scripts/cgo-shard-inventory.sh --check` (runs in **Go** workflow) |
| Consumer prebuilts | [.github/workflows/go-prebuilt-consumer.yml](../.github/workflows/go-prebuilt-consumer.yml) |
| Downstream | Pin **go-googlesqlite** / **bigquery-emulator** to the same module tag and prebuilt layout ([tier-b-absl-protobuf.md](tier-b-absl-protobuf.md) Phase 5) |

## Exit criteria (program “done”)

1. This charter + inventory script + CI check are in place (this document).
2. **Symbol ownership** policy is documented above and unchanged by accident (no new duplicate-definition regressions vs baseline).
3. **`task test:local`**, **`task test:protobuf-cgo`**, consumer workflow, and `./scripts/cgo-shard-inventory.sh --check` stay green.
4. Downstream smoke on **go-googlesqlite** / **bigquery-emulator** remains documented in their READMEs when bumping **go-googlesql**.

## Risk register

| Risk | Mitigation |
|------|------------|
| Per-shard `absl` rename vs plain `absl::` in archives | [protobuf-single-owner-inventory.md](protobuf-single-owner-inventory.md) spike writeup |
| `go` import order vs cgo link order | [`bind_unified_prebuilt_*`](../internal/ccall/go-googlesql/bind_unified_prebuilt_linux.go), generator `ImportGoLibsLinkOrderFirst` |
| Scope creep | Prefer **documented ownership** and **CI invariants** before bulk deletion |
