# Tier B (without amalgamation) — Phase 4: Generator link-only CGO + unified bridge growth

**Repository:** `go-googlesql`  
**Scope:** Phase 4 only — migrate generated CGO packages from amalgamated `bind.cc.tmpl` to link-only `bind_link_only.cc.tmpl`, grow `googlesql_unified.h` / C bridge as parser/analyzer surfaces are exposed, and prove the default developer path no longer compiles megabyte-scale amalgamation translation units for migrated packages.

---

## Objectives

1. **Gradually opt in** packages via `cclib.link_only_bind_packages` so `generateBindCC` emits thin TUs that include headers and `bridge.inc` only — implementations resolve at link time from prebuilt archives (unified `libgooglesql.a` and Tier B protobuf/Abseil policy).
2. **Extend the stable C ABI** in `internal/ccall/go-googlesql-unified/include/googlesql_unified.h` (and the small C anchor + `cxx/googlesql_unified_wrapper.cc`) as real parser/analyzer entry points are wired, without breaking smoke/link contracts.
3. **Roll out vertically:** start with a **parser-only or analyzer-only** vertical slice (one functional area end-to-end), then widen to additional `BasePkg/Name` entries.
4. **Exit criteria:** On the default dev path, **migrated packages do not compile amalgamation-scale `.cc` bodies** inside generated `bind.cc`; those TUs remain header + bridge glue only. CI and local `go test` remain green with documented linker/CGO flags.

---

## Prerequisites (from prior phases)

- **Protobuf / codegen alignment** with Bazel `@com_google_protobuf` (see `docs/prebuilt-cgo.md`).
- **Unified archive** pipeline: `libgooglesql.a` built from `GOOGLESQL_UNIFIED_BAZEL_TARGETS` matching the symbols referenced from each package’s `bridge.inc` (see `docs/libgooglesql-unified.md`, `extract_googlesql_unified_lib.sh`).
- **Abseil / overlap policy** to avoid duplicate symbols (see `docs/prebuilt-absl-overlap.md`).
- Existing docs: `docs/link-only-cgo-migration.md`, `docs/native-build-pipeline.md`.

---

## To-dos

Track Phase 4 work item-by-item; check off as completed. The **Deliverables checklist** at the end of this doc is the phase-complete bar; these items are the usual execution order.

### Generator and opt-in

- [ ] Pick the first **vertical slice** (parser-only *or* analyzer-only) and the corresponding `BasePkg/Name` key(s).
- [ ] Verify **symbol closure**: all C++ symbols used by that package’s `bridge.inc` are present in `libgooglesql.a` (or merged archives) at the pinned submodule/Bazel graph — use `nm` / linker errors as needed.
- [ ] Append key(s) to `cclib.link_only_bind_packages` in `internal/cmd/generator/config.yaml` (keep list ordered for review).
- [ ] From `internal/cmd/generator`, run `go run .` (or the repo’s documented generator entrypoint) and commit regenerated outputs (`bind.cc` and any touched ancillary files **for opted-in packages only**).
- [ ] Confirm **`export.inc` / `syncExportInc`** behavior for each opted-in package (link-only path must not incorrectly pull amalgamated `deps/export.inc` chains).

### Unified archive and Bazel graph

- [ ] If new wrapper or bridge deps are required, update **`extract_googlesql_unified_lib.sh`** and/or **`GOOGLESQL_UNIFIED_BAZEL_TARGETS`** so the unified build includes all needed `cc_library` symbols.
- [ ] Rebuild / refresh prebuilts per `docs/libgooglesql-unified.md` when the graph changes.

### Bridge ABI growth (`googlesql_unified.h`)

- [ ] Add **C-callable** declarations to `internal/ccall/go-googlesql-unified/include/googlesql_unified.h` for the chosen vertical slice (`googlesql_unified_*`, `extern "C"`, ownership documented).
- [ ] Implement forwarding in `internal/ccall/go-googlesql-unified/cxx/googlesql_unified_wrapper.cc` (thin calls into Bazel-built GoogleSQL APIs).
- [ ] Run **`scripts/smoke_link_googlesql_unified.sh`**, **`make verify-prebuilt-googlesql-unified`** (and `make local/build-prebuilt-googlesql-unified` as needed); repeat **duplicate-symbol** checks per `docs/prebuilt-absl-overlap.md`.
- [ ] Document new symbols / ABI notes in **`docs/libgooglesql-unified.md`** (and align Go-side `googlesql_unified_prebuilt` tags / CI expectations).

### Rollout beyond the first slice

- [ ] Add additional `BasePkg/Name` entries in **small batches** (dependency order: leaves before roots when failures point to missing symbols).
- [ ] **Defer** full parser + flex + token disambiguator migration until generator + archive + CI story for those hooks is validated (unless explicitly scoped and tested).

### Testing and exit verification

- [ ] Run **narrow** `go test ./path/to/package/...` first, then widen to importers and reverse-dependents (CGO as required).
- [ ] Confirm **CI** is green (including `.github/workflows/go-googlesql-unified-prebuilt.yml` if applicable).
- [ ] **Exit criterion:** For migrated packages, default dev path **does not** compile amalgamation-scale `.cc` bodies inside generated `bind.cc` — thin header + bridge glue only; optionally capture **before/after** compile time or `-ftime-trace` / build log size for regression guard.

### Documentation

- [ ] Update **`docs/link-only-cgo-migration.md`**, **`docs/libgooglesql-unified.md`**, and **`docs/native-build-pipeline.md`** (or other pipeline doc) as needed for config keys, commands, and ABI additions.

---

## Generator workflow

| Step | Action |
|------|--------|
| 1 | Edit `internal/cmd/generator/config.yaml` under `cclib.link_only_bind_packages` (list of `BasePkg/Name` strings, same key format the generator uses: `fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)`). |
| 2 | From `internal/cmd/generator`, run `go run .` (or the repo’s documented generator entrypoint) to regenerate CGO outputs. |
| 3 | For each opted-in library, `generateBindCC` selects `templates/bind_link_only.cc.tmpl` instead of `templates/bind.cc.tmpl`; output is still written as `bind.cc` in the package output directory. Parser packages still get `wrapParserBindTokenDisambiguatorInclude` where applicable. |
| 4 | Confirm `export.inc` / related sync behavior (`syncExportInc`) matches expectations for the package (link-only path must not pull amalgamated `deps/export.inc` chains — implementations live in archives). |
| 5 | Re-run targeted `go test` and full package tests for dependents. |

**Invariant:** Link-only `bind.cc` keeps `_cgo_export.h`, rename macros, `bridge.h`, `bridge_cc.inc`, and `bridge.inc` so the **Go export ABI is unchanged**; only the compilation unit’s inclusion of hundreds of `.cc` amalgamation bodies is removed.

---

## How to opt in a package

1. **Choose the key:** `BasePkg/Name` as used in generator config (example from docs: `googlesql/public/analyzer`).
2. **Verify closure:** All C++ symbols invoked through that package’s generated bridge must be present in the unified static lib (or explicitly merged archives) built from a **consistent** Bazel graph and submodule revision.
3. **Append** the key to `cclib.link_only_bind_packages` (keep the list ordered for reviewability, e.g. alphabetical or migration order).
4. **Regenerate** and commit generated `bind.cc` (and any touched ancillary outputs) for that package only.
5. **Validate:** Local `go test ./...` or the narrowest `./path/to/package/...` first, then widen to importers.

**Parser note:** The generator treats `googlesql/parser/parser` specially in some amalgamation lists; parser/flex amalgamation has extra hooks (`wrapParserBindTokenDisambiguatorInclude`, flex tokenizer expectations). Treat **parser migration as higher-risk / later** unless a slice is explicitly scoped and tested.

**Rollback:** Remove the package key from `link_only_bind_packages`, regenerate — restores amalgamated `bind.cc.tmpl` for that package (expect longer compile times again).

---

## Bridge ABI growth (`googlesql_unified.h` and C bridge)

**Current surface (smoke):** `googlesql_unified_anchor`, `googlesql_unified_version_string` (see `googlesql_unified.h` and `docs/libgooglesql-unified.md`).

**Phase 4 growth pattern:**

1. Add **C-callable** declarations to `googlesql_unified.h` with clear naming (`googlesql_unified_*`), `extern "C"` guards, and documented ownership of returned pointers/buffers (caller frees vs. static vs. arena — align with GoogleSQL conventions).
2. Implement in `internal/ccall/go-googlesql-unified/cxx/googlesql_unified_wrapper.cc` (thin forwarding to Bazel-built GoogleSQL APIs), keeping object code in the unified archive build.
3. Update `extract_googlesql_unified_lib.sh` / `GOOGLESQL_UNIFIED_BAZEL_TARGETS` when new `cc_library` dependencies are required for those wrappers.
4. Re-run **`nm` / link smoke** (`scripts/smoke_link_googlesql_unified.sh`, `make verify-prebuilt-googlesql-unified`) and duplicate-symbol checks per overlap policy.
5. Version or document **ABI additions** in `docs/libgooglesql-unified.md` so Go-side `googlesql_unified_prebuilt` tags and CI stay aligned.

**Ordering:** Prefer exposing **one vertical** first (e.g. parser *or* analyzer wrappers), prove link + tests, then add complementary symbols — avoids an oversized unified archive before it is needed.

---

## Vertical slice migration strategy

1. **Pick one slice:** Either **parser-only** or **analyzer-only** as the first end-to-end path (tests, prebuilt archive, optional Go callers).
2. **Migrate the corresponding generated package(s)** to `link_only_bind_packages` only after the unified lib contains their implementation symbols.
3. **Expand:** Add additional `BasePkg/Name` entries in small batches; prefer dependency order (leaves before roots) when compile/link failures point to missing symbols.
4. **Defer edge cases:** Full parser + flex + token disambiguator amalgamation until the generator and archive story for those hooks are validated in CI.

**Success signal:** A developer running the documented default build/tests **does not** wait on compiling huge amalgamation TUs for packages already on the link-only list.

---

## Testing strategy

| Layer | What to run |
|-------|-------------|
| **Unit / integration** | `go test` for the migrated package and reverse-dependents; CGO-enabled where required. |
| **Prebuilt unified** | `make prebuilt-libs-googlesql-unified`, `make verify-prebuilt-googlesql-unified`, `make local/build-prebuilt-googlesql-unified` (matches CI expectations in `libgooglesql-unified.md`). |
| **C link smoke** | `scripts/smoke_link_googlesql_unified.sh` after header/ABI changes. |
| **Symbol hygiene** | `nm` / linker checks for duplicate Abseil/protobuf per `prebuilt-absl-overlap.md`. |
| **CI** | `.github/workflows/go-googlesql-unified-prebuilt.yml` (submodule + bazel + Go build with tags). |

**Regression guard:** Compare **compile time** or **`-ftime-trace`** / build log size for migrated packages before vs. after opt-in — amalgamation removal should show a sharp drop in TU size for `bind.cc`.

---

## Risks and mitigations

| Risk | Mitigation |
|------|------------|
| **Missing symbols at link time** | Incremental opt-in; ensure `GOOGLESQL_UNIFIED_BAZEL_TARGETS` covers all libraries needed by `bridge.inc` for that package; use `nm` on `libgooglesql.a`. |
| **Header / implementation skew** | Pin submodule + bazel graph; single source of truth for extraction script; rebuild prebuilts when bumping GoogleSQL. |
| **Duplicate Abseil/protobuf** | Enforce overlap doc; avoid mixing prebuilts from different graphs. |
| **Parser/flex special cases** | Defer or isolate; use existing `wrapParserBindTokenDisambiguatorInclude` behavior and parser-specific tests. |
| **ABI churn in `googlesql_unified.h`** | Add symbols in backward-compatible ways; document stability expectations; keep smoke symbols always present. |
| **CI time / flake** | Keep unified prebuilt workflow dispatch-friendly; cache bazel outputs where policy allows. |

---

## Deliverables checklist (Phase 4 complete)

- [ ] One or more production packages on `link_only_bind_packages` with regenerated `bind.cc` verified in CI.
- [ ] `googlesql_unified.h` + wrapper extended for at least one parser or analyzer vertical slice, with smoke/tests updated.
- [ ] Documentation pointers updated (`link-only-cgo-migration.md`, `libgooglesql-unified.md`, pipeline doc as needed).
- [ ] **Exit criterion met:** Default dev path does not compile megabyte-scale amalgamation TUs for migrated packages; link-only `bind.cc` remains thin.
