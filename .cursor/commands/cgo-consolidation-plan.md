**Cursor:** Use the slash command **`/cgo-consolidation-plan`** to insert this prompt in chat. Prefer **Plan** mode first so the agent drafts a **Cursor plan** (phases, todos, exit criteria) before any repo edits or long test runs.

---

You are helping consolidate **CGO / prebuilt** layout in **go-googlesql**: fewer redundant `internal/ccall` shards and clearer symbol ownership, **without** breaking single-owner Abseil/protobuf rules or the default **`googlesql` + `googlesql_unified_prebuilt`** path.

## Canonical docs (read before planning)

- **[docs/cgo-consolidation.md](../../docs/cgo-consolidation.md)** — Program charter, A/B/C classification, archive policy, Phase 4 playbook, exit criteria, risks.
- **[docs/prebuilt-cgo.md](../../docs/prebuilt-cgo.md)**, **[docs/link-only-cgo-migration.md](../../docs/link-only-cgo-migration.md)**, **[docs/tier-b-absl-protobuf.md](../../docs/tier-b-absl-protobuf.md)**, **[docs/protobuf-single-owner-inventory.md](../../docs/protobuf-single-owner-inventory.md)**, **[docs/prebuilt-absl-overlap.md](../../docs/prebuilt-absl-overlap.md)**
- **[scripts/cgo-shard-inventory.sh](../../scripts/cgo-shard-inventory.sh)** — `--summary`, `--list`, `--check` (CI enforces link-only invariant).

## Skill (when builds fail)

Apply **[`.cursor/skills/googlesql-stack-debug/SKILL.md`](../skills/googlesql-stack-debug/SKILL.md)** for triage: sync vs link vs codegen, **`task test:local`**, cache, `-p 1`, symptom→cause.

## User input (optional)

If the user named a **target** (e.g. a package under `internal/ccall/go-googlesql/...`), scope the plan to that shard first. If not, the plan should **start from inventory** and then pick **one** **B**-class candidate (redundant with prebuilts or migratable to link-only). **Do not** start by removing **cctz** / **`go-absl/time`** shards unless the user explicitly requests it and the plan includes extra nm/link proofs per **[docs/unified-prebuilt-root-segfault-investigation.md](../../docs/unified-prebuilt-root-segfault-investigation.md)**.

---

## Deliverable: a Cursor plan (not code yet)

Produce a **structured plan** (with clear phases and checkboxes/todos) that an agent can execute later in **Agent** mode. The plan must include the following **steps in order**, adapted to the chosen scope:

### 1. Baseline

- Run (or instruct running) **`./scripts/cgo-shard-inventory.sh --summary`** and optionally **`--list`**; record counts for later comparison.
- Run **`./scripts/cgo-shard-inventory.sh --check`** — must pass (link-only `bind.cc` must not `#include` amalgamated `.cc` bodies).

### 2. Choose work item

- From **`--list`** or **[docs/cgo-consolidation.md](../../docs/cgo-consolidation.md)** (example B candidates), pick **one** shard or small group for this iteration.
- State **why** it is class **B** (or justify **A** if unavoidable) and what **success** looks like (e.g. link-only `bind.cc`, fewer `#include "*.cc"`, no duplicate symbols).

### 3. Phase 4 proofs (before deleting packages or blank imports)

Per **[docs/cgo-consolidation.md](../../docs/cgo-consolidation.md)** Phase 4:

1. **Link proof** — `task test:local TESTPKG=./internal/ccall/...` and/or `go test -c -tags googlesql,googlesql_unified_prebuilt -run '^$'` for the affected packages.
2. **Duplicate-symbol proof** — `nm` / `llvm-nm` on **`libprotobuf_cgo.a`** and **`libgooglesql.a`** vs the new TU set; align with **[docs/libgooglesql-unified.md](../../docs/libgooglesql-unified.md)** smoke steps.
3. **Runtime proof** — **`task test:local`** at an appropriate scope; watch for startup issues per **[docs/unified-prebuilt-root-segfault-investigation.md](../../docs/unified-prebuilt-root-segfault-investigation.md)**.

### 4. Generator and export.inc

- If **[internal/cmd/generator/config.yaml](../../internal/cmd/generator/config.yaml)** changes: **`go run .`** from **[internal/cmd/generator](../../internal/cmd/generator)**; diff review; keep **[internal/exportinc](../../internal/exportinc/exportinc.go)** / `export.inc` policy in sync with link-only preludes.

### 5. Blank imports (last)

- Edits to **[internal/ccall/go-googlesql/bind_unified_prebuilt_linux.go](../../internal/ccall/go-googlesql/bind_unified_prebuilt_linux.go)** / **darwin** only **after** proofs — **import order affects cgo link order**.

### 6. Downstream (if the change is non-trivial)

- Smoke **go-googlesqlite** / **bigquery-emulator** with documented tags and `replace` per **[docs/prebuilt-cgo.md](../../docs/prebuilt-cgo.md)** / **[docs/tier-b-absl-protobuf.md](../../docs/tier-b-absl-protobuf.md)** Phase 5.

### 7. Documentation and CI

- Update **[docs/cgo-consolidation.md](../../docs/cgo-consolidation.md)** or delta notes if ownership or inventory changed materially.
- Ensure **`./scripts/cgo-shard-inventory.sh --check`** still passes; **[.github/workflows/go.yml](../../.github/workflows/go.yml)** runs it on PRs.

---

## Hard constraints (must appear in the plan)

- Default tags remain **`googlesql` + `googlesql_unified_prebuilt`** with **`libprotobuf_cgo.a`** + **`libgooglesql.a`**.
- **Never** mix default protobuf prebuilts with **`googlesql_tier_b_absl`** + **`libabsl_cgo.a`** in one binary.
- **`cclib.global_exclude_replace_names`** (`absl`, `google`) must stay coherent with archives — see **[internal/cmd/generator/config.yaml](../../internal/cmd/generator/config.yaml)** `cclib`.

## Out of scope for this command

- Rewriting the engine in pure Go or removing CGO entirely.
- “Delete all of `go-absl`” in a single iteration — call out as multi-quarter if mentioned.

---

**End of command.** After the plan is agreed, switch to **Agent** mode to execute it step by step.
