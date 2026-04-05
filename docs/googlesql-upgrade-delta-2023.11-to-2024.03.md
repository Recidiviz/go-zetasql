# Googlesql upgrade delta: `2023.11.1` → `2024.03.1`

This note tracks **upstream** changes between tags `2023.11.1` and `2024.03.1` in [ZetaSQL](https://github.com/google/zetasql) (`zetasql/` at those tags) and how they relate to **go-zetasql**, **go-zetasqlite**, and **bigquery-emulator**.

Upstream ships as **one** export commit on `2024.03.1`. Mechanical churn is concentrated in `zetasql/public/options.proto`, `zetasql/public/builtin_function.proto`, `zetasql/resolved_ast/`, `zetasql/parser/` (including `token_disambiguator.{cc,h}`), and `zetasql/public/value.*`.

## go-zetasql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2024.03.1`. Prefer `GO_ZETASQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run ./internal/cmd/vendorpatch` and `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

**`.proto` files:** The updater `Skip` callback does not copy `*.proto` from the submodule; sync them explicitly, e.g. `rsync` of `*.proto` from `internal/cmd/updater/zetasql/zetasql/` into `internal/ccall/zetasql/`.

**`*.pb.h` / `*.pb.cc`:** Regenerate with **protoc 23.3** (matches vendored protobuf 4.23.x) from `internal/ccall`, e.g. all `zetasql/**/*.proto` excluding broken `testdata` protos — see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md).

**Parser codegen:** Run `zetasql/parser/gen_parse_tree.py` (Python 3 + `absl-py`, `jinja2`, `protobuf`, generated `ast_enums_pb2.py`) for `parse_tree_generated.*`, `parse_tree.proto`, serializers, then `gen_extra_files.py`, then `protoc` on `parse_tree.proto`.

**Resolved AST codegen:** Run `zetasql/resolved_ast/gen_resolved_ast.py` with `resolved_ast_enums_pb2.py` on the template sets that produce `resolved_ast.proto`, `resolved_ast.h`, visitors, etc., then `protoc` on the generated `resolved_ast*.proto`.

**Flex:** Keep the existing flex/post-copy policy in [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) `applyPostCopyOverlays` and [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) in sync with tokenizer changes.

Carry forward the submodule patch **guard status payloads when protobuf descriptors are absent in CGO shards** (was `b4be268f` on `2023.11.1`) by cherry-picking onto `2024.03.1` unless upstream already subsumes it.

## Themes relevant to the Go stack

### `options.proto`

- **`LanguageFeature`**: New entries include `FEATURE_JSON_QUERY_LAX` (`115`), `FEATURE_TOKENIZED_SEARCH` (`51`, in_development), `FEATURE_EXTERNAL_SCHEMA_DDL` (`111`), `FEATURE_TEMPLATED_SQL_FUNCTION_RESOLVE_WITH_TYPED_ARGS` (`114`). Several features **graduate** from `in_development` (e.g. `FEATURE_CREATE_TABLE_WITH_CONNECTION`, `FEATURE_V_1_4_REMOTE_MODEL`, `FEATURE_V_1_4_GROUPING_BUILTIN`, `FEATURE_V_1_4_GROUPING_SETS`, `FEATURE_V_1_4_ARRAY_ZIP`, `FEATURE_V_1_4_ENABLE_FLOAT_DISTANCE_FUNCTIONS`). **CORRESPONDING / set ops**: `FEATURE_V_1_4_SET_OPERATION_COLUMN_PROPAGATION_MODE` and `FEATURE_V_1_4_CORRESPONDING_BY` are **replaced** by a single feature `FEATURE_V_1_4_CORRESPONDING_FULL` (`14023`); old id `14024` reserved. New **1.4** features: `FEATURE_V_1_4_ENFORCE_STRICT_MACROS`, `LIMIT_OFFSET_EXPRESSIONS`, `MAP_TYPE`, `DISABLE_FLOAT32`, `LITERAL_CONCATENATION`, `DOT_PRODUCT`, `OPT_IN_NEW_BEHAVIOR_NOT_LIKE_ANY_SOME_ALL`, `MANHATTAN_DISTANCE`, `L1_NORM`, `L2_NORM`, `STRUCT_BRACED_CONSTRUCTORS`, `WITH_RECURSIVE_DEPTH_MODIFIER`, JSON array/value extraction bundles, `ENFORCE_CONDITIONAL_EVALUATION`, etc.
- **`ResolvedASTRewrite`**: `REWRITE_SET_OPERATION_CORRESPONDING` removed; new rewrites `REWRITE_INSERT_DML_VALUES` (`24`), `REWRITE_MULTIWAY_UNNEST` (`25`), `REWRITE_AGGREGATION_THRESHOLD` (`26`); reserved id `21` adjusted.

### `builtin_function.proto`

- **NOT LIKE ANY/ALL**: New ids `302`–`309` (`FN_STRING_NOT_LIKE_ANY` … `FN_BYTE_ARRAY_NOT_LIKE_ALL`).
- **Internal**: `FN_WITH_SIDE_EFFECTS` (`1107`) for conditional evaluation when `FEATURE_V_1_4_ENFORCE_CONDITIONAL_EVALUATION` is on.
- **Aggregates**: `FN_ELEMENTWISE_SUM_*` / `FN_ELEMENTWISE_AVG_*` (`2746`–`2763`).
- **Geography**: `FN_ST_LINE_INTERPOLATE_POINT`, `FN_ST_GEOG_FROM_WKB_EXT`, `FN_ST_GEOG_FROM_WKB_HEX_EXT`.
- **Distances / vectors**: `approx_cosine_distance`, `approx_euclidean_distance`, `dot_product`, `approx_dot_product`, `manhattan_distance`, `l1_norm`, `l2_norm` (multiple type variants, ids `2355`–`2380`).
- **JSON extraction**: Many `FN_JSON_TO_*` / `FN_JSON_LAX_TO_*` for arrays and scalar types (`2627`–`2650`).
- **Maps**: `FN_MAP_FROM_ARRAY` (`3000`).

### `resolved_ast` / parser (C++)

- Large template and builder churn; `token_disambiguator` added. Refresh via updater + codegen paths above.

## go-zetasqlite / bigquery-emulator

- **go-zetasqlite**: Sync **LanguageFeature** / `ResolvedASTRewrite` enums and **builtin registration** / `function_bind.go` if new signature ids or JSON/geo functions are exposed in tests.
- **bigquery-emulator**: Add or extend HTTP/query tests when user-visible builtins change; otherwise rely on existing suites after zetasqlite passes.
