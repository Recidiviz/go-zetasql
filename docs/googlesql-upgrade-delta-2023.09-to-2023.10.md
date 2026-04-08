# Googlesql upgrade delta: `2023.09.1` → `2023.10.1`

This note tracks **upstream** changes between tags `2023.09.1` and `2023.10.1` in [GoogleSQL](https://github.com/google/zetasql) (`zetasql/` at those tags) and how they relate to **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator**.

The tag range spans **three** export commits (`a745bef4` on `2023.10.1`). Mechanical churn is concentrated in `zetasql/resolved_ast/` (sql builder, validator, templates). **Proto** and **resolved_ast_enums** deltas below are the main integration surface for this stack.

## go-googlesql source snapshot

Refresh `internal/ccall/zetasql` with [`internal/cmd/updater`](../internal/cmd/updater) after bumping the submodule to `2023.10.1`. Prefer `GO_GOOGLESQL_SKIP_PROTOBUF_COPY=1` when protobuf vendoring should stay on the existing pin ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Then run `go run .` from [`internal/cmd/generator`](../internal/cmd/generator) so CGO amalgamation and generated Go stay aligned.

## Themes relevant to the Go stack

### `options.proto`

- **`AllowedHintsAndOptionsProto`**: new `allow_alter_array` — whether `+=` / `-=` are allowed for **array** fields in options (pairs with language feature work around array alter options).

### `function.proto`

- **`FunctionArgumentTypeOptionsProto`**: new `must_be_constant_expression` — argument must be a constant expression or value.

### `resolved_ast/resolved_ast_enums.proto`

- **`ResolvedGeneratedColumnInfoEnums`**: new `GeneratedMode` enum (`ALWAYS`, `BY_DEFAULT`).
- **`ResolvedOptionEnums`**: new `AssignmentOp` (`DEFAULT_ASSIGN`, `ADD_ASSIGN`, `SUB_ASSIGN`) for option assignment operators.

### `resolved_ast` (C++)

- Substantial updates to `sql_builder.cc`, `validator.cc`, `gen_resolved_ast.py`, templates, and related tests; refreshed via updater + generator (not hand-edited).

## go-googlesqlite / bigquery-emulator

No new **`builtin_function.proto`** enum values in this tag range (per upstream diff). **go-googlesqlite** may only need **LanguageFeature** or analyzer tweaks if tests surface new resolved nodes or option syntax; otherwise verify with existing tests. **bigquery-emulator** inherits behavior through the driver; add HTTP/query tests if user-visible SQL surface expands.
