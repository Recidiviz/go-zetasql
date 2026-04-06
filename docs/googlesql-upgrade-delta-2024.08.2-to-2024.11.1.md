# Googlesql upgrade delta: `2024.08.2` → `2024.11.1`

This note tracks **upstream** changes between tags `2024.08.2` and `2024.11.1` in [ZetaSQL](https://github.com/google/zetasql) (`zetasql/` at those tags) and how they relate to **go-zetasql**, **go-zetasqlite**, and **bigquery-emulator**.

Upstream ships as a single **“Export of internal ZetaSQL changes”** commit on `2024.11.1` (`a516c6b2`), with **~711 files** changed—large churn in `resolved_ast` (validator, sql_builder, rewrite_utils), parser/bison, formatter, and tests. Prioritize **protos**, **FunctionSignatureId**, **TypeKind**, **resolved_ast** codegen, and **builtin** surfaces when syncing this repo.

## go-zetasql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2024.11.1`. Prefer `GO_ZETASQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run ./internal/cmd/vendorpatch` and `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

**`.proto` files:** The updater `Skip` callback does not copy `*.proto` from the submodule; sync them explicitly, e.g. `rsync` of `*.proto` from `internal/cmd/updater/zetasql/zetasql/` into `internal/ccall/zetasql/`.

**`*.pb.h` / `*.pb.cc`:** Regenerate with **protoc 23.3** (matches vendored protobuf 4.23.x) from `internal/ccall`, e.g. all `zetasql/**/*.proto` excluding broken `testdata` protos — see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md).

**Parser codegen:** Run `zetasql/parser/gen_parse_tree.py` (Python 3 + `absl-py`, `jinja2`, `protobuf`, generated `ast_enums_pb2.py`) for `parse_tree_generated.*`, `parse_tree.proto`, serializers, then `gen_extra_files.py`, then `protoc` on `parse_tree.proto`.

**Resolved AST codegen:** Run `zetasql/resolved_ast/gen_resolved_ast.py` with `resolved_ast_enums_pb2.py` on the template sets that produce `resolved_ast.proto`, `resolved_ast.h`, visitors, etc., then `protoc` on the generated `resolved_ast*.proto`.

**Flex:** Keep the existing flex/post-copy policy in [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) `applyPostCopyOverlays` and [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) in sync with tokenizer changes.

**Root `bind.cc` / `root_bind.cc.tmpl`:** Include [`root_analyzer_amalgamation_macros.inc`](../internal/ccall/go-zetasql/root_analyzer_amalgamation_macros.inc) **before** `_cgo_export.h` (same ordering constraints as prior upgrades).

### Embedding-only fixes (not in the submodule)

Do **not** add commits inside [`internal/cmd/updater/zetasql`](../internal/cmd/updater/zetasql). Check out the **upstream release tag** only ([`zetasql-submodule-policy.md`](zetasql-submodule-policy.md)).

If go-zetasql needs CGO-specific changes (for example guarding **status payloads** when protobuf descriptors are missing in amalgamation shards), apply them in **`internal/ccall/zetasql/`** after the updater copies sources, or via `go run ./internal/cmd/vendorpatch` / overlays in [`protobuf-vendoring.md`](protobuf-vendoring.md). Upstream **edited** `zetasql/public/error_helpers.cc` in `2024.08.2..2024.11.1`—reconcile any embedding fixes with **`internal/ccall`** copies, not the submodule.

*Historical note:* Older delta docs described cherry-picking into the submodule; that workflow is **retired**.

## Themes relevant to the Go stack

### `type.proto`

- **`TypeKind`**: `NEXT_ID` → **36**. New kinds: **`TYPE_TIMESTAMP_PICOS` (35)**, **`TYPE_GRAPH_ELEMENT` (30)**, **`TYPE_GRAPH_PATH` (33)**, **`TYPE_MEASURE` (34)** (graph / measure features gated by language features).
- **`TypeProto`**: New optional fields for **`graph_element_type`**, **`graph_path_type`**, **`measure_type`**; new messages **`GraphElementTypeProto`**, **`GraphPathTypeProto`** (and related nested types).

### `builtin_function.proto`

- **`FunctionSignatureId`**: **Next id** moves (see upstream file for current `// Next id:` comment).
- **JSON:** Adds **`FN_SAFE_TO_JSON` (1949)**; documents **`FN_TO_JSON`** / unsupported_fields / **`FN_JSON_QUERY`** comments and ID layout churn.
- **Timestamps:** Additional unix-millis/micros **uint64** signature IDs alongside existing int64 variants (`FN_TIMESTAMP_FROM_UNIX_*`).
- **Differential privacy:** New function IDs **2832–2839** for DP approx-count-distinct plumbing (init/merge/extract/report variants).
- **SQL Graph:** New IDs for graph primitives (e.g. **`FN_IS_SOURCE_NODE`**, **`FN_IS_DEST_NODE`**, **`FN_SAME_GRAPH_ELEMENT`**, **`FN_ALL_DIFFERENT_GRAPH_ELEMENT`**, **`FN_PROPERTY_EXISTS`**, etc.—see upstream enum).

### `resolved_ast_enums.proto`

- New enum groups for **MATCH_RECOGNIZE** (skip mode, pattern anchors, pattern operations), **graph** scans and label expressions, **graph path** mode and search prefix, **`ResolvedOnConflictClauseEnums`**, **`ResolvedLockModeEnums`**, and related resolved-node support upstream.

### `options.proto`

- No diff between `2024.08.2` and `2024.11.1` in the paths sampled for this note; still re-verify after sync if your tree differs.

### Analyzer / validator / SQL builder

- Large updates to **`validator.*`**, **`sql_builder.*`**, **`rewrite_utils.*`**, **`query_expression.*`**—regenerate resolved AST and rerun the generator; fix Go bridge only if new **ResolvedNode** kinds or enums surface in generated headers.

## go-zetasqlite / bigquery-emulator

- **go-zetasqlite:** Sync **FunctionSignatureId** / builtin registration and `function_bind.go` for new builtins you choose to support; **TypeKind** additions may require type mapping if exposed. Add **query tests** for any newly implemented behavior.
- **bigquery-emulator:** Add or extend HTTP/query tests when user-visible builtins or types change; otherwise rely on existing suites after zetasqlite passes.
