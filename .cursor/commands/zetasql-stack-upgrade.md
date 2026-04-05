**Cursor:** Use the slash command **`/zetasql-stack-upgrade`** to insert this prompt in chat or Agent.

**Required — Plan mode:** The **user** must switch this conversation to **Plan** mode before you proceed with any repo edits, submodule bumps, or test runs. Stay in Plan mode until there is an agreed upgrade plan (tag, `from`/`to`, branch names, and order of operations); only then switch to Agent mode to execute. If the session is not in Plan mode, stop and ask the user to enable Plan mode first.

This workflow upgrades **go-zetasql**, **go-zetasqlite**, and **bigquery-emulator** to a new ZetaSQL/googlesql release tag. It covers upstream delta review, submodule bump, protobuf-safe regeneration, builtin parity, emulator integration tests, and sequential CGO test runs. Take the target **tag** from the user in this chat (canonical `YYYY.MM.P`, e.g. `2023.09.1`); normalize input (strip `v`, collapse spaces). Follow the phases below in order; downstream assumes upstream is green.

## Slash command vs skill

- **This file (`/zetasql-stack-upgrade`)** — End-to-end *phases*: workspace prep, upstream delta, submodule, regeneration order, verification sequence, branch naming, Plan mode. Use for the upgrade *runbook*.
- **Skill `zetasql-stack-debug`** — [`.cursor/skills/zetasql-stack-debug/SKILL.md`](../skills/zetasql-stack-debug/SKILL.md) — Reusable *debugging and testing* rules: classify failures (sync vs link vs codegen vs semantics), canonical `make local/test` gate vs misleading `go test ./...` on `internal/ccall`, CGO cache, memory (`-p 1`, `scripts/cgo-go.sh`), symptom→cause triage. **Apply this skill whenever builds fail during an upgrade** or when triaging CGO/stack issues; it complements this command rather than replacing it.

## Methodology (avoid brute-force loops)

1. **Delta before mechanics** — Complete Phase 1 (upstream diff) and draft or update `docs/googlesql-upgrade-delta-<from>-to-<to>.md` *before* chasing unrelated test failures. Prior edits should follow known proto/builtin/`resolved_ast` themes.
2. **Regeneration pipeline** — Submodule → updater (incremental; document flags like `GO_ZETASQL_SKIP_PROTOBUF_COPY=1`) → vendorpatch → **sync `*.proto` into `internal/ccall` if needed** (updater `Skip` rules may **omit `.proto`** — stale `options.proto` / enums cause confusing failures) → **protoc** / `gen_parse_tree` / `gen_resolved_ast` (order per [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md) and your delta doc) → **`go run` generator** → tests. If C++ or bindings look inconsistent, assume a skipped step before deep debugging.
3. **Canonical green definition** — **go-zetasql:** `make local/test` (`TESTPKG` defaults to `./`, root package — matches CI). Do not treat failures from `go test ./...` across every `internal/ccall/...` shard as blocking unless that scope is explicitly in scope (see skill).
4. **Classify the failure** — Sync drift, linker/amalgamation, protobuf vendoring, or runtime/semantic (parser, language features, emulator path). Fix the matching layer; avoid alternating random edits with full tree rebuilds.
5. **Generator and exportinc** — Manual edits to `bind.cc` templates, `export.inc`, or [`internal/cmd/generator`](../../internal/cmd/generator) / `exportinc` can be **overwritten** on the next generate pass. If a fix “comes back” after regeneration, change the **generator or policy** (e.g. flex suppress flags), not only the generated file.
6. **Resume after OOM or agent crash** — Re-read `git status` in each repo; do not assume partial work was saved. Continue with **one repo**, `go test -p 1` / `GOMAXPROCS=1`, and narrowed `TESTPKG` before broad suites.

# ZetaSQL stack upgrade

End-to-end workflow for bumping **google/zetasql** (submodule in go-zetasql) and keeping **go-zetasqlite** and **bigquery-emulator** aligned.

## Triggers and inputs

- **Cursor Plan mode (mandatory):** User has enabled **Plan** mode for this chat before starting; agent does not begin Phase 0+ implementation until planning is complete and mode allows execution.
- **Phrases:** `zetasql-upgrade to <tag>`, `upgrade zetasql to <tag>`, `bump googlesql to <tag>`.
- **Required:** Target **tag** (canonical form `YYYY.MM.P`, e.g. `2023.09.1`). Normalize user input (strip `v`, collapse spaces) to that form.
- **Optional `from` tag:** If omitted, derive from the current submodule commit in [internal/cmd/updater/zetasql](../../internal/cmd/updater/zetasql) (`git describe --tags`) or from the latest [docs/googlesql-upgrade-delta-*.md](../../docs/) baseline.
- **Submodule not exactly on a tag:** Run `git -C internal/cmd/updater/zetasql describe --tags --always`. If you see `<tag>-<N>-g<hash>` with **N ≥ 1**, there are **local commits on top of the upstream tag** (e.g. vendor patches). Plan to **cherry-pick or rebase** those commits onto `<to>` after bumping the submodule, and record the new submodule SHA in the delta doc.

## Phase 0 — Workspace prep (all three repos)

Repositories (adjust if your layout differs; set env vars per **Reference → Environment layout** below):

| Variable | Typical path |
|----------|--------------|
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

- **Confirm the target tag exists** in the sibling clone: `git -C "$GOOGLESQL_ROOT" fetch --tags` then `git -C "$GOOGLESQL_ROOT" rev-parse "$TO_TAG^{}"` (fail fast before submodule checkout).
- `git -C "$GOOGLESQL_ROOT" log <from>..<to>` — commit messages may be sparse; **file diffs** carry the signal.
- Optionally: `git -C "$GOOGLESQL_ROOT" diff --stat <from>..<to>` or path-limited diffs for `zetasql/public`, `zetasql/resolved_ast`, protos, builtins.

**Focus areas** relevant to this stack: **resolved AST**, **public API**, **builtins**, **protos** (`options`, `builtin_function`, `function`, `serialization`, enums).

**Deliverable:** A short checklist (bullet list) of upgrade-relevant items to implement or verify in go-zetasql → go-zetasqlite → emulator. Add or extend a delta doc under `docs/` (see Phase 2).

## Phase 2 — go-zetasql

1. **Submodule:** In `GO_ZETASQL_ROOT`, update [internal/cmd/updater/zetasql](../../internal/cmd/updater/zetasql) to tag `<to>` (`git checkout <to>` inside submodule), commit the submodule pointer when ready.
   - **Vendor patches on top of the tag:** If you add commits in the submodule (patches above the upstream tag), the parent repo will point at a **specific submodule SHA**, not the tag tip. **Push that submodule commit** to whatever remote CI and teammates use *before* (or with) pushing `go-zetasql`, so clones resolve the submodule. Split commits logically: submodule pointer vs generator/ccall mirror in the parent.
2. **Regeneration / vendoring:**
   - A **full** run of `internal/cmd/updater` can **break the CGO link** (duplicate symbols, protobuf/flex skew). Prefer **incremental** steps and document what you ran.
   - Use `GO_ZETASQL_SKIP_PROTOBUF_COPY=1` when refreshing ZetaSQL sources while **preserving** the existing protobuf vendoring story (see [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md)).
   - **Protos under `internal/ccall`:** If enums or generated Go/C++ look wrong after updater, **rsync or copy `*.proto` from the submodule** and rerun **protoc** (and parse_tree / resolved_ast helpers) — the updater does not always refresh every proto in ccall.
   - **Flex:** Conflicting `yyFlexLexer` stubs vs `%option yyclass` in generated flex output may require **post-copy fixes** (e.g. [`internal/cmd/updater/main.go`](../../internal/cmd/updater/main.go) `applyPostCopyOverlays`) and generator config (e.g. `ZETASQL_PARSER_FLEX_TOKENIZER_SUPPRESS_FLEXLEXER_STUBS` in [`internal/cmd/generator/config.yaml`](../../internal/cmd/generator/config.yaml)) so regenerations stay consistent.
   - After copying protobuf or vendor trees, run **`go run ./internal/cmd/vendorpatch`** or **`scripts/apply-vendor-patches.sh`** so amalgamation and git patches apply.
   - **Go AST / bridge parity:** New syntax or nodes (e.g. `GROUP BY ALL`) may need updates to [`internal/cmd/generator/bridge.yaml`](../../internal/cmd/generator/bridge.yaml), **`bridge.inc` by hand** (generator may not overwrite existing file), **[`enum.go`](../../enum.go)** (`LanguageFeature` values), and **[`ast/node.go`](../../ast/node.go)**, plus a **parser test** that enables the feature. Not every upgrade needs this — follow upstream delta and user-facing API gaps.
3. **Documentation:** Add `docs/googlesql-upgrade-delta-<from>-to-<to>.md` (match existing naming) summarizing upstream changes and how this repo addresses them.
4. **Tests:** `CGO_ENABLED=1` with `CXX=clang++` (and ccache/mold on Linux per README). Use `make local/test` / `make local/build` or `make test/linux` with `TESTPKG` narrowed when iterating. Prefer the **root** package gate (`TESTPKG` unset or `./`); see **Failure triage** and skill `zetasql-stack-debug` before interpreting `go test ./...` failures under `internal/ccall`. Do **not** run the heaviest suites in parallel with downstream repos. For memory-constrained machines, use `go test -p 1` and optionally [`scripts/cgo-go.sh`](../../scripts/cgo-go.sh).

**Pointers:** [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md), [internal/cmd/updater/main.go](../../internal/cmd/updater/main.go).

## Phase 3 — go-zetasqlite

1. Ensure module uses the intended go-zetasql (`replace` or bumped version).
2. Align **LanguageFeature** / analyzer options and **builtin registration** with new upstream surface (`internal/analyzer.go`, `internal/function_register.go`, function implementations). Watch for **signature changes** (extra args, types) — update `function_bind.go` and builtins (e.g. JSON helpers) when upstream changes function catalogs.
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

Use [`.cursor/skills/zetasql-stack-debug/SKILL.md`](../skills/zetasql-stack-debug/SKILL.md) for expanded triage and test discipline.

| Symptom | Where to look |
|---------|---------------|
| Many failures only under `go test ./...` / isolated `internal/ccall` packages; root `make local/test` passes | Often **unsupported** standalone shard builds — confirm CI/Makefile default (`TESTPKG=./`) before “fixing” |
| Duplicate symbols / link failures after updater | [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md), `vendorpatch`, partial vs full updater run; which TU owns shared `.cc` (e.g. `utf8_validity` / `utf8_range` — avoid linking the same `.cc` in multiple CGO packages). **Do not** “fix” with `-Wl,--allow-multiple-definition` — it can **crash at runtime**; fix ownership instead (see skill). |
| Undefined `yywrap` / duplicate flex globals / parser segfaults | Multiple TUs compiling the same flex/bison stack; `YY_DECL` / tokenizer name drift; `ZETASQL_PARSER_FLEX_TOKENIZER_SUPPRESS_FLEXLEXER_STUBS` interaction with [`flex_tokenizer`](../../internal/ccall/zetasql/parser/flex_tokenizer.h); namespace macros must match between root and parser/analyzer amalgamation — use **zetasql-stack-debug** before large structural experiments (e.g. “header-only” parser binds can duplicate ICU). |
| Protobuf version / `port_def` errors | Amalgamation guards, `go run ./internal/cmd/vendorpatch` |
| Stale behavior after C++ header edits | CGO/cache: may need `bind.cc` bump or clean rebuild of affected package |
| Crashes in parse/analyze / odd status handling | Minimal repro; CGO/amalgamation **renamed namespaces** can break template matches; `Status` payload / `GetTypeUrl` paths may need explicit handling vs `descriptor()` — not always fixed by rerunning the full suite |
| OOM during tests | Sequential repo tests; `GOMAXPROCS` + `-p 1`; [`scripts/cgo-go.sh`](../../scripts/cgo-go.sh); narrow `TESTPKG` |
| `ENOSPC` / disk full (build or test) | Free space on the volume holding `GOCACHE`, `GOMODCACHE`, and build dirs; partial test runs can leave large artifacts |
| Stale protos / wrong enums / parse options mismatch | Updater did not sync all `*.proto` into `internal/ccall` — copy from submodule + protoc / parse_tree / resolved_ast pipeline (see Phase 2 and delta doc) |
| New builtins fail in emulator only | zetasqlite registration vs server query path |
| Builtin compile errors after bump (arity, types) | Upstream **function signature** change — align `function_bind.go` and implementation files, not only registration lists |

## Reference — environment, scripts, and tests

### Environment layout

Set these to absolute paths for your machine (example: sibling repos under `~/Code`):

```bash
export GO_ZETASQL_ROOT="${GO_ZETASQL_ROOT:-$HOME/Code/go-zetasql}"
export GO_ZETASQLITE_ROOT="${GO_ZETASQLITE_ROOT:-$HOME/Code/go-zetasqlite}"
export BIGQUERY_EMULATOR_ROOT="${BIGQUERY_EMULATOR_ROOT:-$HOME/Code/bigquery-emulator}"
export GOOGLESQL_ROOT="${GOOGLESQL_ROOT:-$HOME/Code/googlesql}"
```

Use **`GOOGLESQL_ROOT`** for `git log` / `git diff` between release tags (upstream may be **google/googlesql** or **google/zetasql**; tags like `2023.09.1` should match the submodule release you target).

The **go-zetasql** submodule path (for checkout inside the repo):

```text
$GO_ZETASQL_ROOT/internal/cmd/updater/zetasql
```

### Canonical tag and branch

- **Tag:** `YYYY.MM.P` (e.g. `2023.09.1`).
- **Branch:** `refactor/upgrade-to-2023.09.1` (dots, not hyphens in the version segment).

```bash
TAG="2023.09.1"
BRANCH="refactor/upgrade-to-${TAG}"
```

### Stash and branch (repeat per repo)

```bash
upgrade_repo() {
  local root="$1"
  local tag="$2"
  local branch="refactor/upgrade-to-${tag}"
  git -C "$root" status
  if ! git -C "$root" diff --quiet || ! git -C "$root" diff --cached --quiet; then
    git -C "$root" stash push -m "wip: pre zetasql upgrade to ${tag}"
  fi
  git -C "$root" fetch --all --prune
  if git -C "$root" show-ref --verify --quiet "refs/heads/${branch}"; then
    git -C "$root" checkout "$branch"
  else
    git -C "$root" checkout -b "$branch"
  fi
}

# upgrade_repo "$GO_ZETASQL_ROOT" "$TAG"
# upgrade_repo "$GO_ZETASQLITE_ROOT" "$TAG"
# upgrade_repo "$BIGQUERY_EMULATOR_ROOT" "$TAG"
```

### Upstream delta

```bash
FROM_TAG="2023.08.1"   # example; set from submodule or docs
TO_TAG="$TAG"

git -C "$GOOGLESQL_ROOT" fetch --tags
git -C "$GOOGLESQL_ROOT" log --oneline "${FROM_TAG}..${TO_TAG}"
git -C "$GOOGLESQL_ROOT" diff --stat "${FROM_TAG}..${TO_TAG}"
```

### Submodule bump (go-zetasql)

```bash
cd "$GO_ZETASQL_ROOT/internal/cmd/updater/zetasql"
git fetch --tags
git checkout "$TO_TAG"
git submodule status
cd "$GO_ZETASQL_ROOT"
# git add internal/cmd/updater/zetasql && git commit -m "chore(deps): bump zetasql submodule to ${TO_TAG}"
```

### Protobuf / vendorpatch (go-zetasql repo root)

```bash
cd "$GO_ZETASQL_ROOT"
# Optional: preserve protobuf tree during updater experiments
# export GO_ZETASQL_SKIP_PROTOBUF_COPY=1

go run ./internal/cmd/vendorpatch
# or: ./scripts/apply-vendor-patches.sh
```

Deep playbook: [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md).

### Shared Go cache (stack tests)

```bash
export GOCACHE="${GOCACHE:-$HOME/.cache/go-zetasql-stack}"
export GOMODCACHE="${GOMODCACHE:-$HOME/.cache/go-mod}"
mkdir -p "$GOCACHE" "$GOMODCACHE"
export CGO_ENABLED=1
export CXX=clang++
# Optional after OOM or on memory-constrained hosts:
# export GOMAXPROCS=1
```

### Tests (sequential — one repo at a time)

**go-zetasql** (from repo root):

```bash
cd "$GO_ZETASQL_ROOT"
make local/test
# or: make test/linux
# narrow: TESTPKG=./internal/... make local/test
# After OOM: narrow TESTPKG, use go test -p 1, optional GOMAXPROCS=1 (see Phase 2 and zetasql-stack-debug)
```

**go-zetasqlite:**

```bash
cd "$GO_ZETASQLITE_ROOT"
go test -tags zetasql -count=1 -p 1 .
```

**bigquery-emulator:**

```bash
cd "$BIGQUERY_EMULATOR_ROOT"
go test -count=1 -p 1 ./...
```

### Existing upgrade delta docs (examples)

Browse [docs/](../../docs/) for files matching `googlesql-upgrade-*.md` — use as templates for new `docs/googlesql-upgrade-delta-<from>-to-<to>.md`.

## Additional resources

- Vendoring playbook: [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md)
- Example delta write-ups: [docs/googlesql-upgrade-delta-2023.04-to-2023.08.md](../../docs/googlesql-upgrade-delta-2023.04-to-2023.08.md)
