---
name: zetasql-stack-debug
description: >-
  Debugs and tests the go-zetasql / go-zetasqlite / bigquery-emulator ZetaSQL
  stack after submodule bumps or CGO failures. Covers canonical test gates vs
  full-tree builds, CGO memory and cache pitfalls, and symptom-to-cause triage.
  Use when upgrading ZetaSQL, when tests fail in internal/ccall, on linker or
  protobuf errors, OOM during go test, or when the user mentions stack
  upgrades, CGO, zetasqlite parity, or emulator integration tests.
---

# ZetaSQL stack — debug and test

## Principles

1. **Classify before fixing** — Decide whether the failure is *sync drift* (updater/generator/vendorpatch not run), *link/amalgamation* (duplicate or missing symbols), *codegen* (missing `resolved_ast` / protos), or *runtime/semantic* (parser, status payloads, language features). Do not treat every red build as a random code bug.
2. **Delta-first** — Read or write `docs/googlesql-upgrade-delta-<from>-to-<to>.md` and skim upstream `git log`/`diff` between tags for protos, builtins, and `resolved_ast` churn before deep edits.
3. **Submodule is read-only upstream** — The checkout under `internal/cmd/updater/zetasql` must be an **upstream release tag only**; do not add commits inside the submodule. CGO-specific fixes belong in `internal/ccall/` (after the updater), `vendorpatch`, or documented overlays—see [`docs/zetasql-submodule-policy.md`](../../../docs/zetasql-submodule-policy.md).
4. **Pipeline order** — Submodule tag checkout → `internal/cmd/updater` (incremental; know what ran) → `go run ./internal/cmd/vendorpatch` or `scripts/apply-vendor-patches.sh` as needed → `go run ./internal/cmd/generator` → **then** tests. If C++ or Go bindings look impossible, suspect skipped steps.
5. **One heavy repo at a time** — Do not run full test suites for go-zetasql, go-zetasqlite, and bigquery-emulator in parallel (OOM).

## Canonical verification (go-zetasql)

- **Default gate:** `make local/test` from the **go-zetasql repo root**. The Makefile uses `TESTPKG ?= ./` (root package only), matching CI — not every subpackage under `internal/ccall/...`.
- **Narrow iteration:** `TESTPKG=./path/to/pkg make local/test` when iterating.
- **Do not** treat `go test ./...` across all `internal/ccall/go-*` packages as the primary signal unless you are deliberately hardening standalone subpackages. Split CGO packages often fail in isolation (`bridge_cc.inc` / `GoSlice`, include order, etc.) while the **root** build is correct.

## Environment

- `CGO_ENABLED=1`, `CXX=clang++` (per README). Reuse `GOCACHE` / `GOMODCACHE` across repos to avoid redundant CGO rebuilds.
- **Low memory / large TUs:** `GOMAXPROCS=2` (or `1`), `go test -tags zetasql -p 1 -count=1 ...`. Optional: `scripts/cgo-go.sh` for serialized packages and optional memory scope.
- **Stale CGO objects:** cgo may not rebuild when only nested C++ headers change. If behavior looks impossible after a header fix, force rebuild (e.g. touch relevant `bind.cc`, clean cache for that test, or documented project workaround).

## Downstream

- **go-zetasqlite:** `go test -tags zetasql` (often `-p 1` for safety). Align `LanguageFeature` / analyzer / builtins with the delta doc; add targeted query tests for new surface.
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

## Slash command

Full phased upgrade workflow (Plan mode, branch naming, order of repos): `.cursor/commands/zetasql-stack-upgrade.md` — use **`/zetasql-stack-upgrade`** for the orchestrated checklist.
