# Protobuf and third-party patch inventory

This document catalogs **go-zetasql–specific** changes layered on top of vendored Google code (primarily **protobuf**, plus a few **third-party** trees touched by the updater). It explains **why** each class of patch exists, how it interacts with [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go), and how to maintain or automate it when upgrading ZetaSQL or refreshing dependency snapshots.

## Source of truth and upgrade axis

- **Upstream ZetaSQL** pins third-party versions via Bazel. This repo mirrors those artifacts into [`internal/cmd/updater/cache/external/`](../internal/cmd/updater/cache/external/) and copies selected trees into [`internal/ccall/`](../internal/ccall/) according to `copyExternalLibMap` / `copyOutExternalLibMap` in the updater (for example `com_google_protobuf/src` → [`internal/ccall/protobuf/`](../internal/ccall/protobuf/)).
- Prefer a **single coherent revision** of protobuf for runtime headers, generated `*.pb.h` / `*.pb.cc`, and sources. Mixing files from different commits causes version checks (`PROTOBUF_MIN_*`), missing symbols, and subtle API skew.
- **`GO_ZETASQL_SKIP_PROTOBUF_COPY`**: when set to **`1`**, the updater **skips** copying `com_google_protobuf/src` into `internal/ccall/protobuf`, so local patches or an in-progress vendor refresh are preserved (see `copyExternalLibMapForRun()` in the updater). Use a **full** copy when intentionally refreshing protobuf from the cache.

## Stable mechanical patches (amalgamation / CGO)

These exist because protobuf is built here as a **single translation unit** included from [`internal/ccall/go-protobuf/protobuf/export.inc`](../internal/ccall/go-protobuf/protobuf/export.inc), not as many TUs like Google’s Bazel build. Upstream `port_def.inc` / `port_undef.inc` assume one include/undef pair per header; amalgamation breaks that unless we gate repeated includes.

### `port_def.inc` / `port_undef.inc`

- **Files**: [`internal/ccall/protobuf/google/protobuf/port_def.inc`](../internal/ccall/protobuf/google/protobuf/port_def.inc), [`internal/ccall/protobuf/google/protobuf/port_undef.inc`](../internal/ccall/protobuf/google/protobuf/port_undef.inc).
- **Mechanism**: After the standard file header comments, the main body is wrapped in:
  - `#ifdef GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF` / `#else` / `#endif` (port_def)
  - `#ifdef GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF` / `#else` / `#endif` (port_undef)
- **Effect**: The amalgamation TU includes `port_def.inc` **once** with the skip macros undefined so macros are defined; nested includes from other headers see the skip macro set and skip the body, avoiding duplicate macro definitions and paired `#undef` issues.
- **Maintenance**: A full copy of `com_google_protobuf` **overwrites** these files and **removes** the wrappers. Re-apply them after every bulk copy, and ensure there is exactly **one** closing `#endif` for each guard (duplicate `#endif` lines cause hard-to-read preprocessor errors).

### `export.inc` (amalgamation preamble)

- **File**: [`internal/ccall/go-protobuf/protobuf/export.inc`](../internal/ccall/go-protobuf/protobuf/export.inc).
- **Role**:
  - Defines **`GO_EXPORT(x)`** → `export_protobuf_##x` and **`InsertIfNotPresent`** → `protobuf_InsertIfNotPresent` to reduce symbol collisions when linking the CGO static archive with other code.
  - Includes `google/protobuf/port_def.inc` **once**, then defines `GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_DEF` and `GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF` before pulling in protobuf `.cc`/`.h` sources in a defined order.
  - Includes `google/protobuf/stubs/macros.h` early so headers that expect `GOOGLE_DISALLOW_EVIL_CONSTRUCTORS` et al. compile in this TU.
  - Ends with `#undef GO_ZETASQL_PROTOBUF_AMALGAMATION_SKIP_PORT_UNDEF`, includes `port_undef.inc`, and cleans up export macros.

This file is **not** copied from upstream; treat it as part of the go-zetasql embedding layer.

## Updater: what is automated today vs gaps

[`applyPostCopyOverlays()`](../internal/cmd/updater/main.go) runs **after** copying external trees and applies **idempotent** string fixes, including:

| Area | File(s) | What it does |
|------|---------|----------------|
| ICU | [`internal/ccall/icu/common/bytesinkutil.h`](../internal/ccall/icu/common/bytesinkutil.h) | Adds `GO_ZETASQL_ICU_*` include guards around the file body. |
| ZetaSQL | `internal/ccall/zetasql/public/types/BUILD` | Appends a missing proto dependency line if absent. |
| ZetaSQL | `internal/ccall/zetasql/public/functions/date_time_util.cc` | Restores an `#undef FCT` after a specific `MakeEvalError` block when missing. |

**Gap (high value for automation):** protobuf **`port_def.inc` / `port_undef.inc` amalgamation guards are not re-applied here.** Any full refresh of `com_google_protobuf` should either run a dedicated post-step (see below) or be followed by a manual re-application of those wrappers.

## Local deltas that may track upstream over time

Some files under `internal/ccall/protobuf/` may carry **additional** edits beyond amalgamation guards—for example API surfaces that support `io::CodedInputStream` extension parsing, `ExtensionFinder` wiring, or inline helpers in headers. **On disk, search** for:

- `GO_ZETASQL`, `ExtensionFinder`, `CodedInputStream`-based `ParseField` overloads in [`extension_set.h`](../internal/ccall/protobuf/google/protobuf/extension_set.h) / [`extension_set.cc`](../internal/ccall/protobuf/google/protobuf/extension_set.cc) / [`extension_set_heavy.cc`](../internal/ccall/protobuf/google/protobuf/extension_set_heavy.cc).

Treat large or overlapping overload sets as **candidates to reconcile** with the exact protobuf revision pinned for your ZetaSQL upgrade: sometimes the durable fix is a **clean vendor snapshot** rather than preserving every local edit. After a refresh, **diff** these files against the new upstream and fold in only what amalgamation still requires.

## Symptoms of version skew (not “random compiler bugs”)

If you see errors such as:

- `#error` in generated `*.pb.h` about an **older protoc** vs headers,
- missing `PROTOBUF_*` macros or duplicate definitions from `port_def.inc`,
- missing or duplicate symbols in `ExtensionSet` / table-driven parsing,

assume **mixed revisions or incomplete post-copy patching** first. Re-copy a single protobuf tree, re-apply amalgamation guards, and regenerate or re-copy generated protos consistently.

## Upgrade playbook

1. Update the updater **cache** / pins so `com_google_protobuf` matches the ZetaSQL release you target.
2. Run the updater with `GO_ZETASQL_SKIP_PROTOBUF_COPY=1` when **preserving** local protobuf edits, or unset it when **forcing** a full refresh from cache.
3. Re-apply **amalgamation** patches to `port_def.inc` and `port_undef.inc` (or implement automation; see below).
4. Run `CGO_ENABLED=1 go test -count=1 ./internal/ccall/go-protobuf/protobuf/`, then broader tests as needed.
5. Inspect `extension_set*` and any other files previously touched for merge duplication or API drift.

## Future automation options

These are implementation choices for maintainers; none are required for a correct manual process.

| Approach | Idea | Tradeoffs |
|----------|------|-----------|
| **A. Updater hooks** | Add e.g. `applyProtobufAmalgamationPatches()` next to `applyPostCopyOverlays()`, using the same idempotent `replaceIfMissing` / `appendLineIfMissing` style. | Stable if anchored on unique substrings; must be updated if upstream rewrites those anchors. |
| **B. Patch files** | Store `git apply`/`patch -p1` patches under e.g. `internal/ccall/protobuf/patches/`. | Breaks when upstream context shifts; good for reviewable, explicit diffs. |
| **C. Anchor-based script** | Rewrite using stable comments (e.g. the “no include guard” paragraph in `port_def.inc`) rather than line numbers. | More resilient than line-based edits; still needs tests when protobuf changes structure. |

---

## Protobuf upgrade runbook (beyond amalgamation patches)

Use this when bumping **ZetaSQL** (and its pinned protobuf / Abseil) or when CGO fails after a vendor refresh. It complements the amalgamation rules above: first keep **one** coherent protobuf tree, then address **API** and **cross-package** skew.

### Blocking: table-driven merge and `CodedInputStream`

Amalgamation includes [`generated_message_table_driven_lite.cc`](../internal/ccall/protobuf/google/protobuf/generated_message_table_driven_lite.cc) and [`generated_message_table_driven.cc`](../internal/ccall/protobuf/google/protobuf/generated_message_table_driven.cc). Their `UnknownFieldHandler::*::ParseExtension` paths call `ExtensionSet::ParseField` with an **`io::CodedInputStream*`** (tag + stream + prototype + unknown-field sink).

Newer upstream protobuf may emphasize the **pointer + `ParseContext`** parser only. If your vendored headers drop the **`CodedInputStream` overloads**, the TU fails to compile or link even when amalgamation guards are correct.

**Preferred fix (compatibility layer):** restore or keep the **lite** overloads that delegate through `GeneratedExtensionFinder`, `FieldSkipper`, and `CodedOutputStreamFieldSkipper` (see [`wire_format_lite.h`](../internal/ccall/protobuf/google/protobuf/wire_format_lite.h)). Implement in [`extension_set.cc`](../internal/ccall/protobuf/google/protobuf/extension_set.cc) and declare in [`extension_set.h`](../internal/ccall/protobuf/google/protobuf/extension_set.h); full-runtime paths live in [`extension_set_heavy.cc`](../internal/ccall/protobuf/google/protobuf/extension_set_heavy.cc) (e.g. `UnknownFieldSetFieldSkipper`). Port from historical protobuf or from a single consistent upstream revision, adapting renames (`PROTOBUF_PREDICT`, `ExtensionInfo` layout, `Add*` / `descriptor` parameters).

**Larger alternative:** refactor table-driven merge to build `internal::ParseContext` + a zero-copy stream and call `ParseField(uint64_t tag, const char* ptr, …, ParseContext*)` only—only if restoring the compatibility layer is infeasible given current `Extension` internals.

**Validation:** `CGO_ENABLED=1 go test -count=1 ./internal/ccall/go-protobuf/protobuf/` until `ParseField` arity / overload errors are gone.

```mermaid
flowchart LR
  subgraph merge [Table-driven merge]
    T[MergePartialFromCodedStreamImpl]
    U[UnknownFieldHandler ParseExtension]
    T --> U
  end
  U --> E[ExtensionSet ParseField with CodedInputStream]
  E --> OK[Compiles and links]
```

### Abseil C++ standard (go-absl CGO)

Packages under [`internal/ccall/go-absl/`](../internal/ccall/go-absl/) that set **`-std=c++11`** can fail Abseil’s `policy_checks.h` (C++14+). Align with **`c++17`** (or at least **`c++14`**) on any `bind_*.go` that compiles Abseil headers, consistent with [`internal/ccall/go-protobuf/protobuf/bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go) and siblings.

### Updater and generator (ZetaSQL / parser / proto skew)

Parser errors (e.g. missing AST types or fields in generated headers) usually mean **vendored ZetaSQL C++** and **generated `.pb.*` / Go** are out of sync—not amalgamation alone.

1. Run [`internal/cmd/updater`](../internal/cmd/updater) with a populated **`cache/`** as required by the tool.
2. **Unset** `GO_ZETASQL_SKIP_PROTOBUF_COPY` (do **not** set `=1`) when you intend a **full** protobuf copy from cache for that upgrade.
3. Run [`internal/cmd/generator`](../internal/cmd/generator) so `includeDirs`, copied trees (e.g. `utf8_range`, protobuf), and generated Go stay aligned.
4. Re-check parser sources (e.g. [`parse_tree_serializer.cc`](../internal/ccall/zetasql/parser/parse_tree_serializer.cc)) against [`parse_tree.pb.h`](../internal/ccall/zetasql/parser/parse_tree.pb.h) after protos match the pinned tag (e.g. **2023.08.1**).

Commit large `internal/ccall` vendor updates separately from small CGO flag fixes, per conventional commits.

### Three-repository verification

After go-zetasql is green:

1. **[go-zetasql](../..)** — `go test ./...` (or narrow packages first).
2. **[go-zetasqlite](https://github.com/goccy/go-zetasqlite)** — same, after updating the `go-zetasql` module replace/version if needed.
3. **[bigquery-emulator](https://github.com/goccy/bigquery-emulator)** — same.

### Optional cleanup

- Remove or **gitignore** stray build artifacts (e.g. `libprotobuf_cgo.a` under `internal/ccall/go-protobuf/protobuf/lib/` if present).
- Reconcile [`.github/workflows/go.yml`](../.github/workflows/go.yml) if macOS or static-library steps were added for an abandoned static-archive approach.

### Risk notes

- Porting **`ParseField(CodedInputStream*)`** must stay consistent with current **`ExtensionInfo`** and **`ExtensionSet::Add*`** APIs; expect iterative compile fixes, not a blind copy-paste from old protobuf.
- Edits around **mutable default strings** / **`Arena`** in table-driven lite paths (e.g. [`generated_message_table_driven_lite.h`](../internal/ccall/protobuf/google/protobuf/generated_message_table_driven_lite.h)) can affect **non-empty default string** parsing; if tests regress, compare with [`arenastring.h`](../internal/ccall/protobuf/google/protobuf/arenastring.h) (`LazyString`, `InitExternal`, etc.).

---

**Related code**: updater [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) (`copyExternalLibMapForRun`, `applyPostCopyOverlays`, `copyExternalLibMap`).
