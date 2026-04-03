---
name: zetasql-stack-upgrade
description: >-
  Upgrades the go-zetasql, go-zetasqlite, and bigquery-emulator stack to a new
  ZetaSQL/googlesql release tag: upstream delta review, submodule bump,
  protobuf-safe regeneration, builtin parity, emulator integration tests, and
  sequential CGO test runs. Use when the user says zetasql-upgrade, upgrade
  zetasql, bump googlesql or zetasql tag, or names a version like 2023.09.1.
---

# ZetaSQL stack upgrade

End-to-end workflow for bumping **google/zetasql** (submodule in go-zetasql) and keeping **go-zetasqlite** and **bigquery-emulator** aligned. Follow phases in order; downstream assumes upstream is green.

## Triggers and inputs

- **Phrases:** `zetasql-upgrade to <tag>`, `upgrade zetasql to <tag>`, `bump googlesql to <tag>`.
- **Required:** Target **tag** (canonical form `YYYY.MM.P`, e.g. `2023.09.1`). Normalize user input (strip `v`, collapse spaces) to that form.
- **Optional `from` tag:** If omitted, derive from the current submodule commit in [internal/cmd/updater/zetasql](../../internal/cmd/updater/zetasql) (`git describe --tags`) or from the latest [docs/googlesql-upgrade-delta-*.md](../../docs/) baseline.

## Phase 0 — Workspace prep (all three repos)

Repositories (adjust if your layout differs; set env vars or use [reference.md](reference.md)):

| Variable | Typical path |
|----------|----------------|
| `GO_ZETASQL_ROOT` | go-zetasql checkout |
| `GO_ZETASQLITE_ROOT` | go-zetasqlite checkout |
| `BIGQUERY_EMULATOR_ROOT` | bigquery-emulator checkout |
| `GOOGLESQL_ROOT` | Sibling clone of **google/zetasql** or **google/googlesql** for `git log` / diff between release tags |

**Branch naming:** `refactor/upgrade-to-<tag>` using **dots** in the version to match git tags (e.g. `refactor/upgrade-to-2023.09.1`).

For **each** of `GO_ZETASQL_ROOT`, `GO_ZETASQLITE_ROOT`, `BIGQUERY_EMULATOR_ROOT`:

1. `git status`. If dirty: `git stash push -m "wip: pre zetasql upgrade to <tag>"` unless the user forbids stashing.
2. `git fetch --all --prune`.
3. Create or switch to the upgrade branch: prefer `git checkout -b refactor/upgrade-to-<tag>` when the branch does not exist; if it exists, `git checkout refactor/upgrade-to-<tag>` and merge/rebase per user preference.

**Local stack:** Confirm `replace` lines in go-zetasqlite and bigquery-emulator `go.mod` point at sibling `../go-zetasql` and `../go-zetasqlite` when testing the full stack locally.

## Phase 1 — Upstream delta (googlesql / zetasql)

Before large mechanical edits, understand what changed between **`from`** and **`to`**:

- `git -C "$GOOGLESQL_ROOT" log <from>..<to>` — commit messages may be sparse; **file diffs** carry the signal.
- Optionally: `git -C "$GOOGLESQL_ROOT" diff --stat <from>..<to>` or path-limited diffs for `zetasql/public`, `zetasql/resolved_ast`, protos, builtins.

**Focus areas** relevant to this stack: **resolved AST**, **public API**, **builtins**, **protos** (`options`, `builtin_function`, `function`, `serialization`, enums).

**Deliverable:** A short checklist (bullet list) of upgrade-relevant items to implement or verify in go-zetasql → go-zetasqlite → emulator. Add or extend a delta doc under `docs/` (see Phase 2).

## Phase 2 — go-zetasql

1. **Submodule:** In `GO_ZETASQL_ROOT`, update [internal/cmd/updater/zetasql](../../internal/cmd/updater/zetasql) to tag `<to>` (`git checkout <to>` inside submodule), commit the submodule pointer when ready.
2. **Regeneration / vendoring:**
   - A **full** run of `internal/cmd/updater` can **break the CGO link** (duplicate symbols, protobuf/flex skew). Prefer **incremental** steps and document what you ran.
   - Use `GO_ZETASQL_SKIP_PROTOBUF_COPY=1` when refreshing ZetaSQL sources while **preserving** the existing protobuf vendoring story (see [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md)).
   - After copying protobuf or vendor trees, run **`go run ./internal/cmd/vendorpatch`** or **`scripts/apply-vendor-patches.sh`** so amalgamation and git patches apply.
3. **Documentation:** Add `docs/googlesql-upgrade-delta-<from>-to-<to>.md` (match existing naming) summarizing upstream changes and how this repo addresses them.
4. **Tests:** `CGO_ENABLED=1` with `CXX=clang++` (and ccache/mold on Linux per README). Use `make local/test` / `make local/build` or `make test/linux` with `TESTPKG` narrowed when iterating. Do **not** run the heaviest suites in parallel with downstream repos.

**Pointers:** [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md), [internal/cmd/updater/main.go](../../internal/cmd/updater/main.go).

## Phase 3 — go-zetasqlite

1. Ensure module uses the intended go-zetasql (`replace` or bumped version).
2. Align **LanguageFeature** / analyzer options and **builtin registration** with new upstream surface (`internal/analyzer.go`, `internal/function_register.go`, function implementations).
3. Add **tests** (e.g. `query_test.go` subtests named for the release).
4. Run tests **after** go-zetasql passes: e.g. `go test -tags zetasql .` or Makefile targets from the repo README. Keep **one repo at a time** for heavy CGO loads.

## Phase 4 — bigquery-emulator

1. With `replace` deps pointing at local zetasql + zetasqlite, add or extend **integration tests** (e.g. `server/server_test.go`) for new builtins or behaviors.
2. Run emulator tests **last**, **sequentially** (not parallel with full zetasql/zetasqlite test runs).

## Verification order and caching

```text
go-zetasql  →  go-zetasqlite  →  bigquery-emulator
```

- **Never** run full `go test` across all three repos **simultaneously** on one machine (OOM risk).
- Reuse **shared** `GOCACHE` and `GOMODCACHE` (and `GO_CACHE_ROOT` / `make test/linux` as documented in the three READMEs) so CGO artifacts are not rebuilt from scratch each step.

## Failure triage

| Symptom | Where to look |
|---------|----------------|
| Duplicate symbols / link failures after updater | [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md), `vendorpatch`, partial vs full updater run |
| Protobuf version / `port_def` errors | Amalgamation guards, `go run ./internal/cmd/vendorpatch` |
| OOM during tests | Sequential repo tests; narrow `TESTPKG`; free parallel agents |
| New builtins fail in emulator only | zetasqlite registration vs server query path |

## Additional resources

- Command templates and paths: [reference.md](reference.md)
- Vendoring playbook: [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md)
- Example delta write-ups: [docs/googlesql-upgrade-delta-2023.04-to-2023.08.md](../../docs/googlesql-upgrade-delta-2023.04-to-2023.08.md)
