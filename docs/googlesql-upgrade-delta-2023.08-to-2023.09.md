# Googlesql upgrade delta: `2023.08.1` → `2023.09.1`

This note tracks **upstream** changes between tags `2023.08.1` and `2023.09.1` in [ZetaSQL](https://github.com/google/zetasql) (`zetasql/` at those tags) and how they relate to **go-zetasql**, **go-zetasqlite**, and **bigquery-emulator**.

The tag range is a **single** export commit (`0b082e84` on top of `2023.08.1` at `54d659fe`). Most churn is in analyzer tests and anonymization; **public protos** and **serialization** changes below are the main integration surface for this stack.

## go-zetasql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2023.09.1`. Prefer `GO_ZETASQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

## Themes relevant to the Go stack

### `options.proto`

- **`FEATURE_EXTRACT_ONEOF_CASE = 50`**: `EXTRACT` pseudo-accessor for proto oneof (requires `FEATURE_V_1_3_EXTRACT_FROM_PROTO`).
- **`FEATURE_ENABLE_ALTER_ARRAY_OPTIONS = 102`** (in development): `+=` / `-=` for array options in `ALTER`.
- **`FEATURE_V_1_4_SINGLETON_UNNEST_INFERS_ALIAS = 14031`**: infer column alias for single-argument `UNNEST` in `FROM` (breaking for name resolution).
- **`FEATURE_V_1_4_ARRAY_ZIP = 14032`**: `ARRAY_ZIP` (lambda and non-lambda).
- **`FEATURE_V_1_4_MULTIWAY_UNNEST = 14033`**: explicit `UNNEST` with multiple arguments in `FROM`.

Comment-only tweak for **`FEATURE_DISABLE_OUTER_JOIN_ARRAY`** (wording).

### `builtin_function.proto`

- Geography: **`FN_ST_HAUSDORFF_DISTANCE = 2090`**.
- Vector / string helpers: **`FN_COSINE_DISTANCE_*`**, **`FN_EUCLIDEAN_DISTANCE_*`** (dense and sparse overloads), **`FN_EDIT_DISTANCE = 2351`**.

### `function.proto`

- **`SignatureArgumentKind`**: **`ARG_TYPE_ANY_3 = 23`**, **`ARG_ARRAY_TYPE_ANY_3 = 24`** (templated “same type” family, e.g. lambdas / `MAX` over arrays).
- **`FunctionEnums.ArgumentAliasKind`**: documents whether function arguments support aliases (`F(<arg> AS <alias>)`).

### `resolved_ast/serialization.proto`

No diff between `2023.08.1` and `2023.09.1` for this file in the upstream export.

## go-zetasqlite / bigquery-emulator

New **scalar** builtins (cosine/euclidean distance, edit distance, `ST_HAUSDORFF_DISTANCE`) need registration and bindings in **go-zetasqlite** if exposed end-to-end. Analyzer **LanguageFeature** flags for v1.4 items may use raw numeric IDs in [`internal/analyzer.go`](../../go-zetasqlite/internal/analyzer.go) until named constants exist in generated `enum.go`.

**bigquery-emulator** inherits behavior through the driver; add HTTP/query tests when adding user-visible SQL surface.
