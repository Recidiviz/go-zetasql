# Googlesql upgrade delta: `2024.03.1` → `2024.06.1`

This note tracks **upstream** changes between tags `2024.03.1` and `2024.06.1` in [GoogleSQL](https://github.com/google/googlesql) (`zetasql/` at those tags) and how they relate to **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator**.

Upstream ships as **three** export commits on `2024.06.1`. Mechanical churn is concentrated in `zetasql/public/options.proto`, `zetasql/public/builtin_function.proto`, `zetasql/resolved_ast/` (especially `rewrite_utils`, `sql_builder`, `validator`), and parser-adjacent files.

## go-googlesql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2024.06.1`. Prefer `GO_GOOGLESQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run ./internal/cmd/vendorpatch` and `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

**`.proto` files:** The updater `Skip` callback does not copy `*.proto` from the submodule; sync them explicitly, e.g. `rsync` of `*.proto` from `internal/cmd/updater/googlesql/zetasql/` into `internal/ccall/zetasql/`.

**`*.pb.h` / `*.pb.cc`:** Regenerate with **protoc 23.3** (matches vendored protobuf 4.23.x) from `internal/ccall`, e.g. all `zetasql/**/*.proto` excluding broken `testdata` protos — see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md).

**Parser codegen:** Run `zetasql/parser/gen_parse_tree.py` (Python 3 + `absl-py`, `jinja2`, `protobuf`, generated `ast_enums_pb2.py`) for `parse_tree_generated.*`, `parse_tree.proto`, serializers, then `gen_extra_files.py`, then `protoc` on `parse_tree.proto`.

**Resolved AST codegen:** Run `zetasql/resolved_ast/gen_resolved_ast.py` with `resolved_ast_enums_pb2.py` on the template sets that produce `resolved_ast.proto`, `resolved_ast.h`, visitors, etc., then `protoc` on the generated `resolved_ast*.proto`.

**Flex:** Keep the existing flex/post-copy policy in [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) `applyPostCopyOverlays` and [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) in sync with tokenizer changes.

**Root `bind.cc` / `root_bind.cc.tmpl`:** Include [`root_analyzer_amalgamation_macros.inc`](../internal/ccall/go-googlesql/root_analyzer_amalgamation_macros.inc) **before** `_cgo_export.h`. Upstream split `zetasql/common/warning_sink.cc` out of the errors bundle; if `_cgo_export.h` pulls nested includes that reach `go-googlesql/public/analyzer/export.inc` before the `zetasql` → `zetasql_public_analyzer_zetasql` macro is set, `WarningSink` is compiled under the wrong namespace and the linker reports undefined references to `zetasql_public_analyzer_zetasql::WarningSink::*`.

### Embedding-only fixes (not in the submodule)

Do **not** add commits inside [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql). Check out the **upstream release tag** only ([`zetasql-submodule-policy.md`](zetasql-submodule-policy.md)). If go-googlesql needs CGO-specific status-payload or related fixes, apply them under **`internal/ccall/zetasql/`** after the updater, or via [`vendorpatch` / `protobuf-vendoring.md`](protobuf-vendoring.md).

*Historical note:* Older delta docs described cherry-picking into the submodule; that workflow is **retired**.

## Themes relevant to the Go stack

### `options.proto`

- **`LanguageFeature`**: `FEATURE_TEXTMAPPER_PARSER` (`999004`) removed; id **reserved** (use `FEATURE_JSON_KEYS_FUNCTION` = `118` instead of reusing old numbers carelessly). New: `FEATURE_JSON_KEYS_FUNCTION` (`118`). Several features **graduate** from `in_development` (e.g. `FEATURE_EXTERNAL_SCHEMA_DDL`, `FEATURE_V_1_4_CREATE_FUNCTION_LANGUAGE_WITH_CONNECTION`, `FEATURE_V_1_4_MULTIWAY_UNNEST`, `FEATURE_V_1_4_JSON_ARRAY_VALUE_EXTRACTION_FUNCTIONS`). New **1.4** entries: `FEATURE_V_1_4_IMPLICIT_COERCION_STRING_LITERAL_TO_BYTES` (`14056`), `FEATURE_V_1_4_UUID_TYPE` (`14057`, in_development), `FEATURE_V_1_4_MULTILEVEL_AGGREGATION` (`14058`, in_development), `FEATURE_V_1_4_REPLACE_FIELDS_ALLOW_MULTI_ONEOF` (`14060`). `FEATURE_V_1_4_JSON_MORE_VALUE_EXTRACTION_FUNCTIONS` (`14055`) no longer shares `in_development` with trailing siblings — structure change in proto.
- **`ResolvedASTRewrite`**: Comment **Next ID** advances to `28` (no new rewriter id beyond `26` in this tag).
- **`ErrorMessageStability`**: New `ERROR_MESSAGE_STABILITY_TEST_REDACTED_WITH_PAYLOADS` (`3`); clarified semantics for `TEST_REDACTED` (`2`).

### `builtin_function.proto`

- **UUID**: `FN_NEW_UUID` (`2657`).
- **JSON**: `FN_JSON_KEYS` (`2656`).
- **Geography**: `FN_ST_HAUSDORFF_DWITHIN` (`2095`).
- **Maps / proto map**: `FN_MODIFY_MAP` renamed to **`FN_PROTO_MODIFY_MAP`** (same id `2510`); **`FN_CONTAINS_KEY`** → **`FN_PROTO_MAP_CONTAINS_KEY`** (same id `2508`).
- **Vector distances**: Several `*_WITH_OPTIONS` ids renamed to `*_WITH_JSON_OPTIONS`; new **`*_WITH_PROTO_OPTIONS`** ids (`2381`–`2387`) for cosine/euclidean/dot_product variants.
- **Maps**: `FN_MAP_ENTRIES_SORTED` (`3001`).

### `resolved_ast` / parser (C++)

- Large template and builder churn (`rewrite_utils`, `sql_builder`, `validator`, etc.). Refresh via updater + codegen paths above.

## go-googlesqlite / bigquery-emulator

- **go-googlesqlite**: Sync **LanguageFeature** / **FunctionSignatureId** names where referenced; **builtin registration** / `function_bind.go` for renamed map helpers and new JSON/UUID/geo signatures.
- **bigquery-emulator**: Add or extend HTTP/query tests when user-visible builtins change; otherwise rely on existing suites after zetasqlite passes.
