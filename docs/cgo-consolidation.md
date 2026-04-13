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
- **`./scripts/cgo-shard-inventory.sh --summary`** reports how many `bind.cc` files anywhere under `internal/ccall/` still `#include` a `.cc` source (rerun for current counts; recent snapshot: **~98** total — mostly **`go-absl`**, plus **`go-algorithms`** (3) and **`go-base`** (1); **`go-googlesql`** is link-only for generated shards; **`go-proto`** differential-privacy protos below are link-only).
- Many **link-only** binds (header comment: `Link-only bind.cc`; on the order of **~416** files) — implementations in **`libgooglesql.a`**; CI **`--check`** ensures these never `#include` amalgamated `.cc` bodies.
- **`go-absl/**`** still `#include` `.cc` sources where a separate TU or single-owner rule requires it. **`go-algorithms`** still has **three** shards that compile a `.cc` in the bind TU (`bounded-mean-ci`, `count-tree`, `gaussian-dp-calculator` under `go_internal` / `go-algorithms`); treat as **class A** until `nm` / Bazel closure proves those bodies live in **`libgooglesql.a`** (or extend the unified extract). **`go-base/logging`** still compiles `base/logging.cc` in the bind TU.

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

**Regeneration:** **`go run ./internal/cmd/generator`** from the repo root after `config.yaml` changes ([link-only-cgo-migration.md](link-only-cgo-migration.md)).

## Phase 4 — Remove or merge shards (playbook)

For each **B** candidate:

1. **Link proof:** `task test:local TESTPKG=./path/to/pkg` or `go test -c -tags googlesql,googlesql_unified_prebuilt` with `-run '^$'`.
2. **Duplicate symbol proof:** `nm -C` / `llvm-nm` on `libprotobuf_cgo.a` and `libgooglesql.a` ([libgooglesql-unified.md](libgooglesql-unified.md)).
3. **Runtime proof:** full `task test:local`; watch for startup issues ([unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md)).
4. **Edit** [`bind_unified_prebuilt_linux.go` / `bind_unified_prebuilt_darwin.go`](../internal/ccall/go-googlesql/bind_unified_prebuilt_linux.go) blank imports only when link order is proven safe (**import order matters**).

**Status:** The stale duplicate package `internal/ccall/go-googlesql/public/timestamp_pico_value` (legacy `zetasql_*` amalgamation; no matching `cc_library` in `googlesql/public/BUILD`) was removed; the supported CGO shard is `internal/ccall/go-googlesql/public/timestamp_picos_value` (link-only + unified prebuilt). Use this checklist for further PRs.

**Example B candidates** (non-exhaustive): any `--list` paths still looking like legacy amalgamation under `go-googlesql` — use Phase 4 before changing `bind_unified_prebuilt_*` imports (rerun `./scripts/cgo-shard-inventory.sh --list`; many `googlesql/*` shards are already link-only).

**Done (link-only + generator):** `googlesql/public/range_value` is now a normal `cc_library` in [`internal/ccall/googlesql/public/BUILD`](../internal/ccall/googlesql/public/BUILD) and regenerated like other `googlesql/public/*` shards (`bind_link_only.cc.tmpl`, `zetasql`/`zetasql_base` namespace overrides and status-macro prelude in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml)).

- **`algorithms/util`** and **`algorithms/distributions`:** listed under `cclib.link_only_bind_packages` in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml); thin `bind.cc` + unified-prebuilt `bind_unified_prebuilt_*.go` like `base/status`. [`export.inc`](../internal/ccall/go-algorithms/util/export.inc) / [`export.inc`](../internal/ccall/go-algorithms/distributions/export.inc) omit `algorithms/util.cc` / `algorithms/distributions.cc` via `filterAlgorithmsUtilLinkOnlySources` in [internal/exportinc/exportinc.go](../internal/exportinc/exportinc.go) so parent TUs that include those `export.inc` chains do not compile those `.cc` bodies again; object code is expected from **`libgooglesql.a`** (objects under `com_google_cc_differential_privacy` collected by [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh)).

- **`algorithms/numerical-mechanisms`**, **`algorithms/rand`**, **`algorithms/internal/gaussian-stddev-calculator`:** same link-only + `filterAlgorithmsUtilLinkOnlySources` pattern as util/distributions; `.pic.o` objects for **`numerical-mechanisms.cc`**, **`rand.cc`**, and **`gaussian-stddev-calculator.cc`** are merged into **`libgooglesql.a`**. Remaining **`go-algorithms`** shards that still `#include` a `.cc` in `bind.cc` are **`bounded-mean-ci`**, **`count-tree`**, and **`gaussian-dp-calculator`** — not flipped to link-only in this iteration (missing or partial symbol closure in the unified archive vs thin wrappers; see Phase 4 `nm` before a future change).

- **Differential-privacy `go-proto` shards** (`proto/confidence_interval_cc_proto`, `proto/data_cc_proto`, `proto/numerical_mechanism_cc_proto`, `proto/summary_cc_proto`): link-only `bind.cc` + `cclib.link_only_bind_packages` + `exclude_replace_names` (aligned with `base/status`) so `.pb.cc` bodies are not compiled in the CGO TU; implementations are expected from **`libgooglesql.a`** (external `com_google_*_differential_privacy` objects merged by the unified extract script). Regenerate `bind.cc` / `export.inc` with **`go run ./internal/cmd/generator`** after `config.yaml` changes (requires a full `internal/ccall` proto/googleapis checkout — run [`scripts/regenerate-ccall-cpp-protos.sh`](../scripts/regenerate-ccall-cpp-protos.sh) first if headers are missing); sync `export.inc` via [internal/exportinc](../internal/exportinc/exportinc.go) (`BuildFromBindCC`) if editing bind preludes by hand.
  - **Phase 4 checks (with prebuilts):** `task test:local TESTPKG=./internal/ccall/go-algorithms/... GO_TEST_FLAGS="-run '^$'"` (compile/link proof — these packages `#include` the `go-proto/*/export.inc` chain); `task verify:prebuilt-googlesql-unified` (includes **duplicate global (T) symbol** check vs `libprotobuf_cgo.a`). The four `internal/ccall/go-proto/*_cc_proto/` trees have **no** standalone `package` Go files; they are only pulled through dependents (e.g. `go-algorithms`). **`bind_unified_prebuilt_*`:** no blank-import change — link order is unchanged; root still imports `go-protobuf/protobuf` only.

- **`googlesql/parser/flex_istream`:** `cc_library` in [`internal/ccall/googlesql/parser/BUILD`](../internal/ccall/googlesql/parser/BUILD), link-only `bind.cc` (avoids pulling the full `go-absl/strings` amalgamation into the TU, which duplicated `absl::strings` stringify headers). `flex_tokenizer` depends on `:flex_istream`.
- **`googlesql/parser/macros/flex_token_provider`:** `inject_replace_names` / `symbol_define_overrides` for `zetasql` + `exclude_replace_names` (same idea as `base/status`) so `GOOGLESQL_*` status macros are not broken by namespace `#define`s; sources use `GOOGLESQL_ASSIGN_OR_RETURN` in the inline/header path.
- **GMock-only `cc_library` targets** (`optional_ref_matchers`, `edge_matchers`, `nfa_matchers`) are listed under `cclib.excludes` so the generator does not emit CGO packages that require `gmock/gmock.h` in default CI headers.
- Removed the orphan **`go-googlesql/parser/token_codes`** CGO directory (headers remain owned by `flex_tokenizer` / includes).

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
