# Googlesql upgrade delta: `2023.04.1` → `2023.08.1`

This note tracks **upstream** changes between tags `2023.04.1` and `2023.08.1` in [googlesql](https://github.com/google/googlesql) (`zetasql/` at those tags) and how they relate to **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator`.

## go-googlesql source snapshot

The vendored tree under [`internal/cmd/updater/googlesql/zetasql/`](../internal/cmd/updater/googlesql/zetasql/) was **byte-identical** to tag `2023.08.1` for checked protos (`public/options.proto`, `public/builtin_function.proto`, `public/function.proto`, `resolved_ast/serialization.proto`).

Refreshing `internal/ccall/` is done with [`internal/cmd/updater`](../internal/cmd/updater) against a populated Bazel `cache/` layout (see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). A full updater run without a matching `execroot`/`external` cache can break CGO links; do not run it ad hoc without that runbook.

Regenerating Go/CGO bridges after intentional tree changes: `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) (see other delta docs).

## Themes relevant to the Go stack

### `options.proto`

- New / adjusted **LanguageFeature** values (differential privacy, JSON mutators, DDL, v1.4 grouping sets / CORRESPONDING / LIKE variants, **FEATURE_V_1_4_FIRST_AND_LAST_N** (14027), **FEATURE_V_1_4_NULLIFZERO_ZEROIFNULL** (14028), **FEATURE_V_1_4_PI_FUNCTIONS** (14029), etc.).
- **ResolvedASTRewrite**: `REWRITE_SET_OPERATION_CORRESPONDING`, `REWRITE_INLINE_SQL_UDAS`, `REWRITE_GROUPING_SET`; new **`RewriteOptions`** / **`GroupingSetRewriteOptions`**.
- **Removed** `FEATURE_FUNCTION_ARGUMENT_NAMES_HIDE_LOCAL_NAMES` (55) — now **reserved** (name-resolution behavior change if anything relied on it).

### `builtin_function.proto`

- **PI**: `FN_PI_DOUBLE`, `FN_PI_NUMERIC`, `FN_PI_BIGNUMERIC`.
- **NULLIFZERO / ZEROIFNULL**: per-type IDs.
- **Arrays**: `FN_ARRAY_FIRST_N`, `FN_ARRAY_LAST_N`, `FN_ARRAY_REMOVE_FIRST_N`, `FN_ARRAY_REMOVE_LAST_N`.
- **JSON**: `FN_JSON_OBJECT` (extra overloads), mutators `FN_JSON_REMOVE`, `FN_JSON_SET`, `FN_JSON_STRIP_NULLS`, `FN_JSON_ARRAY_INSERT`, `FN_JSON_ARRAY_APPEND`.
- **Range**: reserved legacy NULL-dispatch IDs; `FN_GENERATE_*_RANGE_ARRAY`, `FN_RANGE_CONTAINS_*`.

### `function.proto`

- `SignatureArgumentKind`: **`ARG_TYPE_SEQUENCE = 22`**.

### Resolved AST

- **`SequenceRefProto`**; **`ResolvedDropIndexStmtEnums.IndexType`**.

### Catalog (`catalog.h`)

- **`Catalog::SuggestSequence`**; **`Column`** API uses **`GetExpression()`** / **`ExpressionAttributes`** (default vs generated) instead of older default-only helpers.

## go-googlesqlite / bigquery-emulator

Runtime parity for new **scalar** builtins and tests live in **go-googlesqlite** (`internal/function_register.go`, `function_bind.go`, JSON/array/math helpers). **bigquery-emulator** inherits SQL behavior through the driver; add HTTP/query tests when exposing new surface area.

See **go-googlesqlite** `query_test.go` for end-to-end checks. Enable analyzer features as needed via raw `LanguageFeature` numeric IDs in [`internal/analyzer.go`](../../go-googlesqlite/internal/analyzer.go) when the Go `enum.go` has not yet gained named constants for v1.4 flags.
