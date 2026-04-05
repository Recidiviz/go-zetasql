# Googlesql upgrade delta: `2023.10.1` → `2023.11.1`

This note tracks **upstream** changes between tags `2023.10.1` and `2023.11.1` in [ZetaSQL](https://github.com/google/zetasql) (`zetasql/` at those tags) and how they relate to **go-zetasql**, **go-zetasqlite**, and **bigquery-emulator**.

Upstream ships as **one** export commit (`589026c4` on `2023.11.1`). Mechanical churn is concentrated in `zetasql/public/options.proto`, `zetasql/public/builtin_function.proto`, `zetasql/resolved_ast/` (sql builder, validator, `target_syntax.h`, templates), and `zetasql/public/value.*`.

## go-zetasql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2023.11.1`. Prefer `GO_ZETASQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run ./internal/cmd/vendorpatch` and `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

**`.proto` files:** The updater `Skip` callback does not copy `*.proto` from the submodule; sync them explicitly, e.g. `rsync` of `*.proto` from `internal/cmd/updater/zetasql/zetasql/` into `internal/ccall/zetasql/`.

**`*.pb.h` / `*.pb.cc`:** Regenerate with **protoc 23.3** (matches vendored protobuf 4.23.x) from `internal/ccall`, e.g. all `zetasql/**/*.proto` excluding broken `testdata` protos — see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md).

**Parser codegen:** Run `zetasql/parser/gen_parse_tree.py` (Python 3 + `absl-py`, `jinja2`, `protobuf`, generated `ast_enums_pb2.py`) for `parse_tree_generated.*`, `parse_tree.proto`, serializers, then `gen_extra_files.py`, then `protoc` on `parse_tree.proto`.

**Resolved AST codegen:** Run `zetasql/resolved_ast/gen_resolved_ast.py` with `resolved_ast_enums_pb2.py` on the template sets that produce `resolved_ast.proto`, `resolved_ast.h`, visitors, etc., then `protoc` on the generated `resolved_ast*.proto`.

**Flex:** Remove the `yyFlexLexer::yylex` / `yywrap` stub block that conflicts with `%option yyclass="FlexTokenizer"` (handled in [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) `applyPostCopyOverlays` and by dropping `ZETASQL_PARSER_FLEX_TOKENIZER_SUPPRESS_FLEXLEXER_STUBS` from the parser bind prelude in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml)).

Carry forward the submodule patch **guard status payloads when protobuf descriptors are absent in CGO shards** (was `d2421b28` on `2023.10.1`) by cherry-picking onto `2023.11.1` unless upstream already subsumes it.

## Themes relevant to the Go stack

### `options.proto`

- **`LanguageFeature`**: new entries include `FEATURE_ENABLE_CONSTANT_EXPRESSION_IN_JSON_PATH`, parser-related flags (`FEATURE_TEXTMAPPER_PARSER` moved/deprecated semantics, `FEATURE_SHADOW_PARSING`, `FEATURE_DISABLE_TEXTMAPPER_PARSER`), `FEATURE_DISABLE_PIVOT_REWRITER_UDA_ERRORS`, `FEATURE_IDENTITY_COLUMNS`; versioned features `FEATURE_V_1_4_ENABLE_FLOAT_DISTANCE_FUNCTIONS`, `FEATURE_V_1_4_ENABLE_MEASURES`, `FEATURE_V_1_4_GROUP_BY_ALL`; `FEATURE_V_1_4_SET_OPERATION_COLUMN_PROPAGATION_MODE` and `FEATURE_V_1_4_CORRESPONDING_BY` no longer marked `in_development`.
- **`ErrorMessageStability`**: new enum (`ERROR_MESSAGE_STABILITY_UNSPECIFIED`, `PRODUCTION`, `TEST_REDACTED`) for error text stability modes.

### `builtin_function.proto`

- **`FunctionSignatureId`**: `ARRAY_ZIP` lambda signatures consolidated (mode is optional trailing arg); `FN_ARRAY_ZIP_*_MODE_LAMBDA` ids **reserved** (`2554`, `2557`, `2560`); new float dense distance ids `FN_COSINE_DISTANCE_DENSE_FLOAT` (`2353`), `FN_EUCLIDEAN_DISTANCE_DENSE_FLOAT` (`2354`).

### `resolved_ast` (C++)

- New `target_syntax.h`, updates to `sql_builder.cc`, `validator.cc`, `query_expression.*`, `rewrite_utils.*`, `gen_resolved_ast.py`, templates, and tests; refreshed via updater + generator (not hand-edited).

## go-zetasqlite / bigquery-emulator

- **go-zetasqlite**: If generated builtin enums or ARRAY_ZIP / distance registrations drift, update `internal/function_register.go` and implementations; align **LanguageFeature** / analyzer options if new SQL surface is enabled in tests.
- **bigquery-emulator**: Add or extend HTTP/query tests if user-visible builtins or ARRAY_ZIP behavior changes; otherwise verify with existing suites.
