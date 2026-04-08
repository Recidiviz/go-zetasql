# Googlesql upgrade delta: `2024.06.1` → `2024.08.1`

This note tracks **upstream** changes between tags `2024.06.1` and `2024.08.1` in [GoogleSQL](https://github.com/google/zetasql) (`zetasql/` at those tags) and how they relate to **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator**.

Upstream ships as a single **“Exported GoogleSQL changes”** commit on `2024.08.1` (highlights: **SQL pipe syntax**, new language features, documentation). Mechanical churn is concentrated in `zetasql/public/options.proto`, `zetasql/public/builtin_function.proto`, `zetasql/public/function.proto`, `zetasql/public/types/` (e.g. removal of `list_backed_type`), and `zetasql/resolved_ast/` (`sql_builder`, `rewrite_utils`, `validator`, `gen_resolved_ast.py`).

## go-googlesql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2024.08.1`. Prefer `GO_GOOGLESQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run ./internal/cmd/vendorpatch` and `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

**`.proto` files:** The updater `Skip` callback does not copy `*.proto` from the submodule; sync them explicitly, e.g. `rsync` of `*.proto` from `internal/cmd/updater/googlesql/zetasql/` into `internal/ccall/zetasql/`.

**`*.pb.h` / `*.pb.cc`:** Regenerate with **protoc 23.3** (matches vendored protobuf 4.23.x) from `internal/ccall`, e.g. all `zetasql/**/*.proto` excluding broken `testdata` protos — see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md).

**Parser codegen:** Run `zetasql/parser/gen_parse_tree.py` (Python 3 + `absl-py`, `jinja2`, `protobuf`, generated `ast_enums_pb2.py`) for `parse_tree_generated.*`, `parse_tree.proto`, serializers, then `gen_extra_files.py`, then `protoc` on `parse_tree.proto`.

**Resolved AST codegen:** Run `zetasql/resolved_ast/gen_resolved_ast.py` with `resolved_ast_enums_pb2.py` on the template sets that produce `resolved_ast.proto`, `resolved_ast.h`, visitors, etc., then `protoc` on the generated `resolved_ast*.proto`.

**Flex:** Keep the existing flex/post-copy policy in [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) `applyPostCopyOverlays` and [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) in sync with tokenizer changes.

**Root `bind.cc` / `root_bind.cc.tmpl`:** Include [`root_analyzer_amalgamation_macros.inc`](../internal/ccall/go-googlesql/root_analyzer_amalgamation_macros.inc) **before** `_cgo_export.h` (same ordering constraints as prior upgrades).

### Embedding-only fixes (not in the submodule)

Do **not** add commits inside [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql). Check out the **upstream release tag** only ([`zetasql-submodule-policy.md`](zetasql-submodule-policy.md)). If go-googlesql needs CGO-specific status-payload or related fixes, apply them under **`internal/ccall/zetasql/`** after the updater, or via [`vendorpatch` / `protobuf-vendoring.md`](protobuf-vendoring.md).

*Historical note:* Older delta docs described cherry-picking into the submodule; that workflow is **retired**.

## Themes relevant to the Go stack

### `options.proto`

- **`LanguageFeature`**: New **Next id** comment `14065` on `LanguageFeatureOptions`. **Reserved** list gains `108` (former `FEATURE_DISABLE_PIVOT_REWRITER_UDA_ERRORS` removed upstream).
- **Pipes:** `FEATURE_PIPES` (`101`); `FEATURE_PIPE_STATIC_DESCRIBE` (`112`); `FEATURE_PIPE_ASSERT` (`113`) — separate from base pipes because they introduce resolved AST nodes.
- **Other:** `FEATURE_CREATE_INDEX_PARTITION_BY` (`117`, in_development); `FEATURE_TO_JSON_UNSUPPORTED_FIELDS` (`119`, in_development).
- **1.4:** `FEATURE_V_1_4_KLL_FLOAT64_PRIMARY_WITH_DOUBLE_ALIAS` (`14064`); `FEATURE_V_1_4_DISALLOW_PIVOT_AND_UNPIVOT_ON_ARRAY_SCANS` (`14066`).
- **`ResolvedASTRewrite`**: **Next ID** `29`. New: `REWRITE_PIPE_ASSERT` (`27`, in_development); `REWRITE_ORDER_BY_AND_LIMIT_IN_AGGREGATE` (`28`). `REWRITE_INLINE_SQL_FUNCTIONS` (`10`) and `REWRITE_INLINE_SQL_UDAS` (`22`) no longer carry `in_development` on the rewriter options in proto.

### `builtin_function.proto`

- **Strings:** `FN_SPLIT_SUBSTR` (`1083`).
- **Maps:** `FN_MAP_EMPTY` (`3012`), `FN_MAP_INSERT` (`3013`), `FN_MAP_INSERT_OR_REPLACE` (`3014`).

### `resolved_ast` / parser (C++)

- Pipe syntax and new resolved nodes may require **bridge** / **enum** / **AST** updates in go-googlesql if exposed through the Go API; add parser tests with `FEATURE_PIPES` (and related features) when validating this release.

## go-googlesqlite / bigquery-emulator

- **go-googlesqlite:** Sync **LanguageFeature** / **FunctionSignatureId** where referenced; **builtin registration** and `function_bind.go` for `SPLIT_SUBSTR` and new map builtins.
- **bigquery-emulator:** Add or extend HTTP/query tests when user-visible builtins change; otherwise rely on existing suites after zetasqlite passes.
