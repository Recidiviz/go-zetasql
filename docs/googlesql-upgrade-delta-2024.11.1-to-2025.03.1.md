# Googlesql upgrade delta: `2024.11.1` → `2025.03.1`

This note tracks **upstream** changes between tags `2024.11.1` and `2025.03.1` in [GoogleSQL](https://github.com/google/googlesql) (`zetasql/` at those tags) and how they relate to **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator**.

Upstream ships as a single **“Export of internal GoogleSQL changes”** commit on `2025.03.1` (`94ff7f5f`), with **~980 files** changed—large churn in `resolved_ast` (validator, `sql_builder`, `rewrite_utils`), parser, formatter, and tests. Prioritize **protos**, **FunctionSignatureId**, **TypeKind** / **ValueProto**, **resolved_ast** codegen, and **builtin** surfaces when syncing this repo.

## go-googlesql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2025.03.1`. Prefer `GO_GOOGLESQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run ./internal/cmd/vendorpatch` (invoked by the updater) and `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

**`.proto` files:** The updater `Skip` callback does not copy `*.proto` from the submodule; sync them explicitly, e.g. `rsync` of `*.proto` from `internal/cmd/updater/googlesql/zetasql/` into `internal/ccall/zetasql/`.

**`*.pb.h` / `*.pb.cc`:** Regenerate with **protoc 23.3** (matches vendored protobuf 4.23.x) from `internal/ccall`, e.g. all `zetasql/**/*.proto` excluding broken `testdata` protos — see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md).

**Parser codegen:** Run `zetasql/parser/gen_parse_tree.py` (Python 3 + `absl-py`, `jinja2`, `protobuf`, generated `ast_enums_pb2.py`) when parse tree / AST enums change, then `gen_extra_files.py`, then `protoc` on `parse_tree.proto`.

**Resolved AST codegen:** Run `zetasql/resolved_ast/gen_resolved_ast.py` with `resolved_ast_enums_pb2.py` when resolved AST templates change, then `protoc` on the generated `resolved_ast*.proto`.

**Flex:** Keep the existing flex/post-copy policy in [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) `applyPostCopyOverlays` and [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) in sync with tokenizer changes.

**Root `bind.cc` / `root_bind.cc.tmpl`:** Include [`root_analyzer_amalgamation_macros.inc`](../internal/ccall/go-googlesql/root_analyzer_amalgamation_macros.inc) **before** `_cgo_export.h` (same ordering constraints as prior upgrades).

### Embedding-only fixes (not in the submodule)

Do **not** add commits inside [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql). Check out the **upstream release tag** only ([`zetasql-submodule-policy.md`](zetasql-submodule-policy.md)).

If go-googlesql needs CGO-specific changes (for example guarding **status payloads** when protobuf descriptors are missing in amalgamation shards), apply them in **`internal/ccall/zetasql/`** after the updater copies sources, or via `go run ./internal/cmd/vendorpatch` / overlays in [`protobuf-vendoring.md`](protobuf-vendoring.md).

## Themes relevant to the Go stack (high level)

### Upstream release notes (selected)

- **Pico time / timestamps:** Cast picotime to string with format; `CastFormatTimestampToString(PicoTime)` signature additions; ongoing **ValueProto** pico representation updates.
- **SQL pipes:** Pipe **WITH**; named windows in pipe SELECT / EXTEND; WINDOW pipe operator marked deprecated in favor of EXTEND.
- **JSON:** **`JSON_CONTAINS`** (`FN_JSON_CONTAINS = 2651`) and related JSON surface churn — verify **FunctionSignatureId** in zetasqlite if exposing builtins.
- **Analyzer / catalogs:** **`BuiltinOnlyCatalog`** and rewriter validation changes (builtins-only catalog paths, `FunctionSignatureRewriteOptions`).
- **Language features:** Several features leave `in_development` (e.g. `FEATURE_V_1_4_PIPE_RECURSIVE_UNION`, multilevel aggregation in UDAs, tokenized search, `FEATURE_DISABLE_VALIDATE_REWRITERS_REFER_TO_BUILTINS` versioning cleanup).
- **Differential privacy / aggregation threshold:** CTE rewrite ordering and epsilon assignment fixes upstream.
- **Spanner:** `CREATE LOCALITY GROUP` in parser (may be dialect-gated upstream).

### `resolved_ast`

- Heavy updates to **`validator.*`**, **`sql_builder.*`**, **`rewrite_utils.*`** — regenerate resolved AST artifacts and rerun the generator; fix Go bridge only if new **ResolvedNode** kinds or enums surface in generated headers.

### `zetasql/proto` / public protos

- Small diffs in **`function.proto`**, **`logging.proto`**, **`type_annotation.proto`** BUILD/metadata — re-verify after sync.

## go-googlesqlite / bigquery-emulator

- **go-googlesqlite:** Sync **FunctionSignatureId** / builtin registration and `function_bind.go` for new builtins you choose to support (e.g. `JSON_CONTAINS`); **TypeKind** / **ValueProto** changes may require type mapping. Add **query tests** for any newly implemented behavior.
- **bigquery-emulator:** Add or extend HTTP/query tests when user-visible builtins or types change; otherwise rely on existing suites after zetasqlite passes.
