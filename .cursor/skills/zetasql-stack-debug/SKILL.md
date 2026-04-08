---
name: zetasql-stack-debug
description: >-
  Debugs and tests the go-googlesql / go-googlesqlite / bigquery-emulator GoogleSQL
  stack after submodule bumps or CGO failures. Covers canonical test gates vs
  full-tree builds, CGO memory and cache pitfalls, and symptom-to-cause triage.
  Use when upgrading GoogleSQL, when tests fail in internal/ccall, on linker or
  protobuf errors, OOM during go test, or when the user mentions stack
  upgrades, CGO, zetasqlite parity, or emulator integration tests.
---

# GoogleSQL stack — debug and test

## Principles

1. **Classify before fixing** — Decide whether the failure is *sync drift* (updater/generator/vendorpatch not run), *link/amalgamation* (duplicate or missing symbols), *codegen* (missing `resolved_ast` / protos), or *runtime/semantic* (parser, status payloads, language features). Do not treat every red build as a random code bug.
2. **Delta-first** — Read or write `docs/googlesql-upgrade-delta-<from>-to-<to>.md` and skim upstream `git log`/`diff` between tags for protos, builtins, and `resolved_ast` churn before deep edits.
3. **Submodule is read-only upstream** — The checkout under `internal/cmd/updater/zetasql` must be an **upstream release tag only**; do not add commits inside the submodule. CGO-specific fixes belong in `internal/ccall/` (after the updater), `vendorpatch`, or documented overlays—see [`docs/zetasql-submodule-policy.md`](../../../docs/zetasql-submodule-policy.md).
4. **Pipeline order** — Submodule tag checkout → `internal/cmd/updater` (incremental; know what ran) → `go run ./internal/cmd/vendorpatch` or `scripts/apply-vendor-patches.sh` as needed → `go run ./internal/cmd/generator` → **then** tests. If C++ or Go bindings look impossible, suspect skipped steps.
5. **One heavy repo at a time** — Do not run full test suites for go-googlesql, go-googlesqlite, and bigquery-emulator in parallel (OOM).

## Canonical verification (go-googlesql)

- **Default gate:** `make local/test` from the **go-googlesql repo root**. The Makefile uses `TESTPKG ?= ./` (root package only), matching CI — not every subpackage under `internal/ccall/...`.
- **Narrow iteration:** `TESTPKG=./path/to/pkg make local/test` when iterating.
- **Do not** treat `go test ./...` across all `internal/ccall/go-*` packages as the primary signal unless you are deliberately hardening standalone subpackages. Split CGO packages often fail in isolation (`bridge_cc.inc` / `GoSlice`, include order, etc.) while the **root** build is correct.

## Environment

- `CGO_ENABLED=1`, `CXX=clang++` (per README). Reuse `GOCACHE` / `GOMODCACHE` across repos to avoid redundant CGO rebuilds.
- **Low memory / large TUs:** `GOMAXPROCS=2` (or `1`), `go test -tags googlesql -p 1 -count=1 ...`. Optional: `scripts/cgo-go.sh` for serialized packages and optional memory scope.
- **Stale CGO objects:** cgo may not rebuild when only nested C++ headers change. If behavior looks impossible after a header fix, force rebuild (e.g. touch relevant `bind.cc`, clean cache for that test, or documented project workaround).

## Build cache and incremental CGO

- **Dedicated cache dirs:** Point `GOCACHE` and `GOMODCACHE` at a stable prefix (e.g. `~/.cache/go-googlesql/gocache` and `.../gomodcache`) when jumping between go-googlesql, go-googlesqlite, and bigquery-emulator. A healthy tree is large (many GB is normal), contains sharded subdirs under `gocache`, and shows **recent mtimes** on those shards while a build runs. An empty sibling like `ccache/` means **compiler ccache is unused** unless you set `CCACHE_DIR` (or equivalent) yourself.
- **Avoid `-a` for routine work:** `go build -a` / `go test -a` forces rebuilding packages that are already up to date. That discards the main win of the build cache and can look like “the cache is broken” during long `clang++` runs on huge `bind.cc` units. Reserve `-a` for deliberate clean rebuilds (suspected cache corruption, toolchain change), not after regenerating a subset of files.
- **Piping hides progress:** `go test ... 2>&1 | tail -N` buffers until the test process produces enough output or exits, so a long CGO compile can appear stuck for many minutes. Drop the pipe or use `-x` / `-work` briefly when you need visibility.
- **Protobuf is a hub package:** `internal/ccall/go-protobuf/protobuf` is blank-imported from a large set of `internal/ccall/...` proto and GoogleSQL CGO packages. Changing generated wrappers, `export.inc`, or that package’s `bind_*.go` **correctly invalidates a wide CGO subgraph**—that is coupling by design, not a broken cache. Go still rebuilds **only stale packages** in the graph unless you pass `-a`.
- **Package granularity only:** You cannot ask Go to recompile “just part of” one CGO package. You *can* (optional) sanity-check the hub alone with `go build` / `go test` scoped to `./internal/ccall/go-protobuf/protobuf`, then run the real downstream test **without `-a`** so unrelated packages stay cache-hot.
- **Script default:** `scripts/cgo-go.sh` uses `-p 1 -count=1` and **does not** pass `-a`—prefer that shape for heavy CGO gates unless you explicitly need a forced rebuild.
- **Protobuf vs per-shard `absl` rename:** Each `bind.cc` uses `#define absl …_absl` (and similar) so symbols do not collide across CGO packages. Protobuf headers use `absl::` types; compiling protobuf in a **separate** `go-protobuf` TU with plain `absl::` while other shards use **renamed** `absl` breaks link with missing `google::protobuf::…` / wrong `once_flag` namespace. A “single-owner protobuf” layout needs **aligned Abseil/protobuf macro policy** or prebuilt libs with matching ABI—not only `GOCACHE`. See [`docs/protobuf-vendoring.md`](../../../docs/protobuf-vendoring.md) (*Single-owner protobuf*), [`docs/protobuf-single-owner-inventory.md`](../../../docs/protobuf-single-owner-inventory.md), and the roadmap [`docs/tier-b-absl-protobuf.md`](../../../docs/tier-b-absl-protobuf.md) (`googlesql_tier_b`, `make extract-protobuf-lib`, optional `cclib.global_exclude_replace_names`).

## Downstream

- **go-googlesqlite:** `go test -tags zetasql` (often `-p 1` for safety). Align `LanguageFeature` / analyzer / builtins with the delta doc; add targeted query tests for new surface.
- **bigquery-emulator:** After zetasql + zetasqlite are green locally with `replace` deps. Integration tests last.

## Symptom → look here

| Symptom | Likely cause | First moves |
|--------|----------------|------------|
| Missing types / enums / proto fields | Submodule vs generated Go/C++ out of sync | Updater + generator; check delta doc for proto changes |
| Duplicate symbols, link errors after updater | Full updater vs incremental; protobuf/amalgamation overlap | `docs/protobuf-vendoring.md`, `vendorpatch`, avoid duplicating same `.cc` in multiple CGO shards |
| `utf8_validity`, protobuf internal errors | Vendored protobuf path / single provider of `utf8_range` | Trace which TU should own the symbol; do not assume every subpackage build is valid |
| Crash in parse/analyze with OK error paths | Status payload / descriptor init in CGO shards (historical issue class) | Minimal repro; apply fixes under `internal/ccall/zetasql/` or vendorpatch—[`docs/zetasql-submodule-policy.md`](../../../docs/zetasql-submodule-policy.md); not in the submodule |
| Pass root tests, fail obscure subpackages only | Unsupported isolated compile of split packages | Confirm with `make local/test` / CI matrix |
| OOM | Parallel heavy CGO | One repo at a time; `-p 1`; `cgo-go.sh` |
| Long compile, “cache not working” | `-a`, pipe to `tail`, or protobuf-wide invalidation | Drop `-a`; check `GOCACHE` mtime/size; see **Build cache and incremental CGO** |
| Link: `undefined … google::protobuf` / `AssignDescriptors(…, *_absl::once_flag*, …)` | Shard compiles protobuf-facing code with **renamed** `absl`; separate `go-protobuf` TU uses plain `absl::` | Not a missing `.o` from cache—**ABI/macro mismatch**; see **Protobuf vs per-shard absl rename** and docs above |

## Slash command

Full phased upgrade workflow (Plan mode, branch naming, order of repos): `.cursor/commands/zetasql-stack-upgrade.md` — use **`/zetasql-stack-upgrade`** for the orchestrated checklist.
