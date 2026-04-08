# Googlesql upgrade delta: `2024.08.1` → `2024.08.2`

This note tracks **upstream** changes between tags `2024.08.1` and `2024.08.2` in [GoogleSQL](https://github.com/google/zetasql) (`zetasql/` at those tags) and how they relate to **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator**.

Upstream ships as a single **“Export of internal GoogleSQL changes”** commit on `2024.08.2` (highlights: **Measure type** placeholder in `type.proto`, **TO_JSON** signature with `unsupported_fields`, **map_replace** builtins, **map_insert** return type clarification, **analyzer** `CycleDetector` wiring in `AnalyzerOptions`, **lambda** handling in builtin registry scalar APIs, **per-column OPTIONS** / **WITH COLUMN OPTIONS**, parser/bison and `gen_parse_tree.py` churn, `execute_query` tooling). Mechanical churn also touches `zetasql/public/functions/to_json*`, `unsupported_fields.proto`, formatter, and many tests.

## go-googlesql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2024.08.2`. Prefer `GO_GOOGLESQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run ./internal/cmd/vendorpatch` and `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

**`.proto` files:** The updater `Skip` callback does not copy `*.proto` from the submodule; sync them explicitly, e.g. `rsync` of `*.proto` from `internal/cmd/updater/zetasql/zetasql/` into `internal/ccall/zetasql/`.

**`*.pb.h` / `*.pb.cc`:** Regenerate with **protoc 23.3** (matches vendored protobuf 4.23.x) from `internal/ccall`, e.g. all `zetasql/**/*.proto` excluding broken `testdata` protos — see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md).

**Parser codegen:** Run `zetasql/parser/gen_parse_tree.py` (Python 3 + `absl-py`, `jinja2`, `protobuf`, generated `ast_enums_pb2.py`) for `parse_tree_generated.*`, `parse_tree.proto`, serializers, then `gen_extra_files.py`, then `protoc` on `parse_tree.proto`.

**Resolved AST codegen:** Run `zetasql/resolved_ast/gen_resolved_ast.py` with `resolved_ast_enums_pb2.py` on the template sets that produce `resolved_ast.proto`, `resolved_ast.h`, visitors, etc., then `protoc` on the generated `resolved_ast*.proto`.

**Flex:** Keep the existing flex/post-copy policy in [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) `applyPostCopyOverlays` and [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) in sync with tokenizer changes.

**Root `bind.cc` / `root_bind.cc.tmpl`:** Include [`root_analyzer_amalgamation_macros.inc`](../internal/ccall/go-googlesql/root_analyzer_amalgamation_macros.inc) **before** `_cgo_export.h` (same ordering constraints as prior upgrades).

### Embedding-only fixes (not in the submodule)

Do **not** add commits inside [`internal/cmd/updater/zetasql`](../internal/cmd/updater/zetasql). Check out the **upstream release tag** only ([`zetasql-submodule-policy.md`](zetasql-submodule-policy.md)). If go-googlesql needs CGO-specific status-payload or related fixes, apply them under **`internal/ccall/zetasql/`** after the updater, or via [`vendorpatch` / `protobuf-vendoring.md`](protobuf-vendoring.md).

*Historical note:* Older delta docs described cherry-picking into the submodule; that workflow is **retired**.

## Themes relevant to the Go stack

### `options.proto`

- **`LanguageFeatureOptions`**: **Next id** comment moves `14065` → `14068` (no additional `LanguageFeature` enum entries in the proto diff between these tags in the upstream tree used here).

### `builtin_function.proto`

- **`FunctionSignatureId`**: **Next id** `1949`.
- **JSON:** New `FN_TO_JSON_UNSUPPORTED_FIELDS` (`1948`) — `to_json` with optional `unsupported_fields` argument (see `to_json.cc` / `unsupported_fields.proto` upstream).
- **Maps:** Comments updated: `FN_MAP_INSERT` / `FN_MAP_INSERT_OR_REPLACE` return **`map<K,V>`** (not `bool`). New: `FN_MAP_REPLACE_KV_PAIRS` (`3015`), `FN_MAP_REPLACE_K_REPEATED_V_LAMBDA` (`3016`).

### `type.proto`

- New empty message **`MeasureTypeProto`** (beginning of Measure type support).

### `analyzer` / catalog

- **`AnalyzerOptions`**: Default **`CycleDetector`** stored in `owned_cycle_detector`, wired into `find_options.set_cycle_detector` for catalog `Find*` behavior.

### `resolved_ast` / parser (C++)

- Parser and unparser updates (including match recognize / braced constructors / tablesample testdata). Regenerate parse tree and verify bridge/enum/AST in go-googlesql if new nodes surface in generated headers.

## go-googlesqlite / bigquery-emulator

- **go-googlesqlite:** Sync **FunctionSignatureId** / builtin registration and `function_bind.go` for **`FN_TO_JSON_UNSUPPORTED_FIELDS`**, **`map_replace`** variants, and any **`to_json`** arity changes; align **map_insert** semantics if implementations assumed bool return.
- **bigquery-emulator:** Add or extend HTTP/query tests when user-visible builtins change; otherwise rely on existing suites after zetasqlite passes.
