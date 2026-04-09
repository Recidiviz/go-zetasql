---
name: Tier B Phase 3 — Unified libgooglesql.a
overview: Expand GOOGLESQL_UNIFIED_BAZEL_TARGETS and extract_googlesql_unified_lib.sh toward parser→analyzer Bazel closure; document targets, Textmapper/go_deps caveats, and libgooglesql.a + libprotobuf_cgo.a link policy; align CI with the documented default subset.
todos:
  - id: phase3-north-star-bazel
    content: From internal/cmd/updater/googlesql, confirm bazel build //googlesql/public:analyzer (or document first failing hop); run §4 deps queries for transitive cc_library footprint
    status: completed
  - id: phase3-classify-layers
    content: Classify query output into layers A–E (§5); note parser/lexer/AST/analyzer boundaries for incremental expansion
    status: completed
  - id: phase3-expand-targets
    content: Incrementally add explicit Bazel labels to GOOGLESQL_UNIFIED_BAZEL_TARGETS / extract script default; use overrides for experiments; one logical slice per commit when committing
    status: completed
  - id: phase3-verify-increment
    content: After each increment — extract_googlesql_unified_lib.sh (or make prebuilt-libs-googlesql-unified), make verify-prebuilt-googlesql-unified, scripts/smoke_link_googlesql_unified.sh, make local/build-prebuilt-googlesql-unified
    status: completed
  - id: phase3-link-audit
    content: "When overlap appears, nm sample absl::/google::protobuf:: in libgooglesql.a vs libprotobuf_cgo.a; record link order, duplicates, and mitigations per docs/prebuilt-absl-overlap.md"
    status: completed
  - id: phase3-docs-target-list
    content: Add “Phase 3 target list” table to docs/libgooglesql-unified.md (labels, purpose, default vs GOOGLESQL_UNIFIED_BAZEL_TARGETS override)
    status: completed
  - id: phase3-docs-textmapper
    content: Document Textmapper / com_github_inspirer_textmapper and 401-class module fetch failures with actionable mitigations
    status: completed
  - id: phase3-docs-linking
    content: Document combining libgooglesql.a with libprotobuf_cgo.a for smoke binary; cross-link prebuilt-absl-overlap.md
    status: completed
  - id: phase3-ci-workflow
    content: Align .github/workflows/go-googlesql-unified-prebuilt.yml with documented defaults; optional workflow_dispatch/schedule for full closure if default CI stays subset
    status: completed
  - id: phase3-exit-checklist
    content: Satisfy §7 exit criteria and §8 quick verification checklist (Bazel targets, prebuilt path, analyzer direction, linking, CI matches doc)
    status: completed
isProject: false
---

# Phase 3 — Unified `libgooglesql.a` toward analyzer/parser closure (Tier B, no amalgamation)

**Roadmap:** Tier B without amalgamation · **Repository:** `go-googlesql` (`/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql`)

**Scope:** Grow [`internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) and the `GOOGLESQL_UNIFIED_BAZEL_TARGETS` default until the static archive materially covers the **parser → analyzer** direction, while keeping **thin CGO + prebuilts** viable. This phase is about **Bazel closure discovery**, **documented target lists**, **link hygiene** vs `libprotobuf_cgo.a`, and **environment notes** (e.g. Textmapper / private module access).

**Non-goals for Phase 3:** Full C ABI for `AnalyzeStatement` in production; replacing amalgamation-based `bind.cc` trees; a single merged archive that subsumes protobuf + Abseil + GoogleSQL (that remains a later pipeline milestone per [`docs/prebuilt-absl-overlap.md`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/docs/prebuilt-absl-overlap.md)).

## To-dos

Statuses in the YAML frontmatter (`todos`) are the source of truth for Cursor plan tracking; use this checklist for at-a-glance progress in the doc.

- [ ] **North-star Bazel** — `bazel build //googlesql/public:analyzer` from the submodule (or document the first failing hop); capture transitive `cc_library` deps with §4 queries.
- [ ] **Layer classification** — Map deps to layers A–E (§5) to plan incremental expansion.
- [ ] **Target expansion** — Grow `GOOGLESQL_UNIFIED_BAZEL_TARGETS` / extract script defaults with explicit labels; use env overrides for experiments; commit in sensible slices.
- [ ] **Per-increment verification** — Re-run extract, `make verify-prebuilt-googlesql-unified`, `scripts/smoke_link_googlesql_unified.sh`, and `make local/build-prebuilt-googlesql-unified`.
- [ ] **Link audit** — `nm` overlap vs `libprotobuf_cgo.a` when needed; document order and duplicate-symbol handling (see [`docs/prebuilt-absl-overlap.md`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/docs/prebuilt-absl-overlap.md)).
- [ ] **Docs: target list** — Phase 3 Bazel label table in [`docs/libgooglesql-unified.md`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/docs/libgooglesql-unified.md) (default vs override).
- [ ] **Docs: Textmapper / fetch** — `com_github_inspirer_textmapper`, 401-class failures, mitigations (credentials, vendor, cache, VPN).
- [ ] **Docs: linking** — How `libgooglesql.a` combines with `libprotobuf_cgo.a` for the smoke path; cross-links to the overlap doc.
- [ ] **CI** — `.github/workflows/go-googlesql-unified-prebuilt.yml` matches documented defaults; document subset vs optional full closure (dispatch/schedule).
- [ ] **Exit** — All §7 criteria and the §8 quick verification checklist satisfied.

---

## 1. Objective

- **Primary:** Establish a **reviewed, version-controlled list of Bazel labels** that `bazel build` can consume in CI and locally, such that `extract_googlesql_unified_lib.sh` produces a **`libgooglesql.a`** whose object set is **large enough to smoke-link** a minimal Go binary (`googlesql_unified_prebuilt`) and documents the path to **`//googlesql/public:analyzer`** (or an equivalent decomposition if the monolithic label is unsuitable).
- **Secondary:** Document and mitigate **parser toolchain** constraints (Textmapper via `com_github_inspirer_textmapper` in [`internal/cmd/updater/googlesql/MODULE.bazel`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/internal/cmd/updater/googlesql/MODULE.bazel)), including failures that present as **HTTP 401** or other blocked fetches.
- **Linking:** Define a **repeatable policy** for combining `libgooglesql.a` with **`libprotobuf_cgo.a`** (and optionally Tier B tags) without silent **duplicate Abseil/protobuf** definitions—see [`docs/prebuilt-absl-overlap.md`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/docs/prebuilt-absl-overlap.md).

---

## 2. Prerequisites

- Populated submodule at `internal/cmd/updater/googlesql`.
- `bazelisk` or `bazel`, `clang`/`clang++`, same C++20 flags as the extract script (`--cxxopt=-std=c++20`).
- Read access to any **non-public** module hosts your GoogleSQL pin requires (if `bazel build` fails during Gazelle/go module resolution, capture the exact URL and fix credentials or mirror—do not paper over in the extract script).

---

## 3. Concrete work steps

### 3.1 Baseline and dependency graph

1. From `internal/cmd/updater/googlesql`, confirm the **north-star** build:
   - `bazel build //googlesql/public:analyzer` (or document the first failing hop if it does not).
2. Capture the **transitive `cc_library` footprint** without building tests:
   - Use the Bazel query suggestions in §4 to list deps of `//googlesql/public:analyzer` and of intermediate targets (`//googlesql/parser/...`, `//googlesql/public/...` as needed).
3. Classify targets into **layers** (see §5): infrastructure (`base`, `strings`, …), **parser/lexer generated code**, **AST**, **analyzer core**, **public shim**.

### 3.2 Incremental target expansion

1. Keep the **default** `GOOGLESQL_UNIFIED_BAZEL_TARGETS` conservative until CI proves the wider graph; use **documented override lists** for experiments:
   - `GOOGLESQL_UNIFIED_BAZEL_TARGETS='...' make prebuilt-libs-googlesql-unified`
2. Expand in **increments** (one logical slice per change when committing in-repo):
   - Add the **minimal parser-related** `cc_library` targets that unblock the next `bazel build` slice.
   - Prefer **explicit labels** over wildcards in the default list so reproducibility and code review stay tractable.
3. After each increment:
   - Re-run `extract_googlesql_unified_lib.sh` (or `make prebuilt-libs-googlesql-unified`).
   - Run `make verify-prebuilt-googlesql-unified` and **`scripts/smoke_link_googlesql_unified.sh`**.
   - Run **`make local/build-prebuilt-googlesql-unified`** (matches CI) for the **thin CGO** path with `-tags googlesql,googlesql_unified_prebuilt`.

### 3.3 Link audit: `libgooglesql.a` + `libprotobuf_cgo.a`

1. When the archive first includes code that **also** appears (directly or via inlined templates) in protobuf or Abseil objects, run **`nm`** comparisons:
   - Sample `absl::` / `google::protobuf::` symbols in `libgooglesql.a` vs `internal/ccall/go-protobuf/protobuf/lib/.../libprotobuf_cgo.a`.
2. If the link reports **duplicate symbol** errors (or you rely on `--allow-multiple-definition`), record:
   - Which archive defined the symbol first in the **actual** link order used by the Go linker / CGO flags.
   - Whether the fix is **ordering**, **omitting** a redundant `-l`, or **stopping** duplicate object inclusion (align with [`docs/prebuilt-absl-overlap.md`](../../Code/googlesql_workspace/go-googlesql/docs/prebuilt-absl-overlap.md)).
3. Prefer **one owner** for protobuf+Abseil native objects in a given binary until a merged archive exists; do not combine `googlesql_unified_prebuilt` with conflicting Tier B tags without an explicit matrix row in the docs.

### 3.4 Documentation updates (`docs/libgooglesql-unified.md` and related)

1. Add a **“Phase 3 target list”** subsection: table of Bazel labels, short purpose, and whether they are **default** or **opt-in** via `GOOGLESQL_UNIFIED_BAZEL_TARGETS`.
2. Document **Textmapper / `go_deps`** behavior:
   - Point to `com_github_inspirer_textmapper` in `MODULE.bazel` and note that **module fetch failures** (e.g. **401 Unauthorized**) are an **environment/registry** problem, not something the shell extract fixes.
   - List mitigations: credential helpers, vendoring the module, Bazel offline caches, or using a machine/VPN that can resolve the dependency—pick what matches org policy.
3. Cross-link **link-order and duplicate-symbol** guidance to [`docs/prebuilt-absl-overlap.md`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/docs/prebuilt-absl-overlap.md) whenever Phase 3 mentions combining archives.

### 3.5 CI and reproducibility

1. Align **GitHub Actions** (`.github/workflows/go-googlesql-unified-prebuilt.yml`) with the **documented** default target set once CI can build it reliably.
2. If the full analyzer closure is **too heavy** for default CI, keep CI on a **smaller documented subset** and run the **full list** on `workflow_dispatch` or a scheduled job—state that explicitly in the doc.

---

## 4. Bazel query suggestions

Run from `internal/cmd/updater/googlesql` after `bazel` can load the workspace.

**Transitive C++ libraries for the analyzer (inspect only; may be large):**

```bash
bazel query 'kind(cc_library, deps(//googlesql/public:analyzer))' --output=label
```

**Direct deps of analyzer (lighter):**

```bash
bazel query 'deps(//googlesql/public:analyzer, 1)' --output=label
```

**Path discovery (what pulls in a label):**

```bash
bazel query 'somepath(//googlesql/public:analyzer, //googlesql/parser:TARGET_NAME)' --output=label
```

**Parser subtree inventory:**

```bash
bazel query '//googlesql/parser/...' --output=label
```

**Filter out testonly** (when refining a candidate list):

```bash
bazel query 'kind(cc_library, deps(//googlesql/public:analyzer)) except attr(testonly, 1, //googlesql/...)' --output=label
```

Use query output to **justify** each label added to `GOOGLESQL_UNIFIED_BAZEL_TARGETS` (or to document why a wildcard is unacceptable).

---

## 5. Target expansion strategy

| Layer | Intent | Notes |
|-------|--------|--------|
| **A — Current default** | `//googlesql/base:*` subset | Already in [`extract_googlesql_unified_lib.sh`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh); smoke-only. |
| **B — Parser prerequisites** | Lexer/parser `cc_library` targets that do not require generated sources, or generated sources already checked in | If build fails on **genrules**, fix **Textmapper/module fetch** first. |
| **C — Parser + AST glue** | Targets bridging parser outputs to AST | Watch for **duplicate .o** if the same file is pulled via multiple paths. |
| **D — Analyzer stack** | Libraries on the path to `//googlesql/public:analyzer` | May duplicate symbols with vendored Go CGO until naming policy is unified—track with `nm`. |
| **E — Public entry (optional monolith)** | `//googlesql/public:analyzer` **as a single label** in `GOOGLESQL_UNIFIED_BAZEL_TARGETS` | Simplest operationally if Bazel closure is clean; largest archive and longest builds. |

**Decision rule:** Prefer **E** if CI and local builds succeed; otherwise ship **layered lists** (B+C+D) with a documented “equivalent to analyzer” bundle verified by `bazel build //googlesql/public:analyzer` separately.

---

## 6. Risks

| Risk | Mitigation |
|------|------------|
| **Private or authenticated module fetch (e.g. 401)** for Textmapper or other `go_deps` | Fix registry auth; vendor; or document blocked environments and keep a smaller default target set. |
| **Duplicate Abseil/protobuf** across `libgooglesql.a` and `libprotobuf_cgo.a` | Symbol audit (`nm`), single-owner link policy, avoid mixed Tier B tags per overlap doc. |
| **Archive size / link time** | Incremental defaults; split “CI subset” vs “full closure” in docs. |
| **Stale `*.pic.o` collection** | Script already prefers objects **newer than build marker**; if weirdness persists, clean `bazel clean` once per investigation. |
| **Generated parser drift** | Ensure submodule pin and generated sources match; align with [`docs/googlesql-upgrade-delta-*`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/docs) when bumping GoogleSQL. |

---

## 7. Exit criteria (Phase 3 complete)

Phase 3 is **done** when all of the following hold:

1. **Documented Bazel target list** in [`docs/libgooglesql-unified.md`](/home/brighten-tompkins/Code/googlesql_workspace/go-googlesql/docs/libgooglesql-unified.md) that is **sufficient** to build a **smoke** native + Go path: the listed targets (default or clearly labeled “full closure” override) **build under Bazel**, `extract_googlesql_unified_lib.sh` succeeds, and **`make local/build-prebuilt-googlesql-unified`** passes with **thin CGO** and prebuilt `libgooglesql.a`.
2. **Analyzer/parser direction** is explicitly covered: either **`//googlesql/public:analyzer`** is included in the documented list, or the doc explains **why not** and names the **verified substitute** target set that still builds `//googlesql/public:analyzer` in the submodule.
3. **Textmapper / module fetch** caveats (including **401**-class failures) are documented with **actionable** mitigations.
4. **Linking** section states how **`libgooglesql.a`** combines with **`libprotobuf_cgo.a`** for the smoke binary (order, known duplicate classes of symbols, and what to do when `ld` errors).
5. **CI** behavior matches the doc (default subset vs optional full closure), so a new contributor can reproduce the smoke path from the markdown alone.

---

## 8. Quick verification checklist

- [ ] `bazel build <documented targets>` succeeds in `internal/cmd/updater/googlesql`.
- [ ] `make prebuilt-libs-googlesql-unified` produces `internal/ccall/go-googlesql-unified/lib/$(go env GOOS)_$(go env GOARCH)/libgooglesql.a`.
- [ ] `make verify-prebuilt-googlesql-unified` passes.
- [ ] `bash scripts/smoke_link_googlesql_unified.sh` passes.
- [ ] `make local/build-prebuilt-googlesql-unified` passes with unified prebuilt tags.
- [ ] Spot-check: `nm …/libgooglesql.a | …` and `nm …/libprotobuf_cgo.a | …` for unexpected overlap (document findings).

---

*Phase 3 stops at a documented, reproducible **closure strategy** and smoke link. Deeper C wrappers for analyzer APIs and production CGO integration belong to subsequent phases.*
