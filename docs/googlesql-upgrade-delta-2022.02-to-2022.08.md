# Googlesql upgrade delta: `2022.02.1` → `2022.08.1`

This note captures a **directory-scoped review** of upstream changes between tags `2022.02.1` and `2022.08.1` in the [googlesql](https://github.com/google/zetasql) history (paths under `zetasql/` at those tags). Export commits bundle **hundreds** of internal CLs; only a subset of bullets appear in commit messages—this file focuses on **proto / public API / builtins** relevant to **go-zetasql**, **go-zetasqlite**, and **bigquery-emulator**.

## Scale

| Metric | Value |
|--------|------|
| Commits in range | 3 (squashed exports) |
| Files touched (hot dirs) | 402 under `zetasql/public`, `resolved_ast`, `analyzer`, `parser` |
| Insertions/deletions (hot dirs) | ~31k / ~8k lines |

## Proto and public API (`zetasql/public`)

### `type.proto`

- New `TypeKind`: **`TYPE_RANGE`** (`29`), gated by `FEATURE_RANGE_TYPE`.
- `TypeProto` gains optional **`RangeTypeProto`** (`range_type`), field id `8`.
- New message **`RangeTypeProto`** with `element_type` (`TypeProto`).

### `type_parameters.proto`

- `NumericTypeParametersProto`: **extension range** `1000–2000` for engine-specific extensions.

### `functions/rounding_mode.proto` (new file)

- Enum **`RoundingMode`**: `ROUNDING_MODE_UNSPECIFIED`, `ROUND_HALF_AWAY_FROM_ZERO`, `ROUND_HALF_EVEN`.
- Used by `ROUND(numeric|bignumeric, digits, rounding_mode)` overloads in the function catalog.

### `builtin_function.proto`

Notable new or adjusted **`FunctionSignatureId`** entries (non-exhaustive):

- Control flow: `FN_IFERROR`, `FN_NULLIFERROR`, `FN_ISERROR`.
- Math: `FN_ROUND_WITH_ROUNDING_MODE_NUMERIC`, `FN_ROUND_WITH_ROUNDING_MODE_BIGNUMERIC`, `FN_CBRT_*`, hyperbolic inverses `FN_CSCH_DOUBLE`, `FN_SECH_DOUBLE`, `FN_COTH_DOUBLE`.
- Arrays: `FN_ARRAY_INCLUDES_ALL`, `FN_ARRAY_FIRST`, `FN_ARRAY_LAST`, `FN_ARRAY_SLICE`.
- Geography: `FN_ST_IS_CLOSED`.
- Anonymization / keys: many new `FN_ANON_*` and `FN_KEYS_*` IDs.
- Comment fixes for `$like_any_array` / internal names.

### `options.proto`

- **`LanguageVersion`**: `VERSION_1_3` described as frozen May 2022; adds **`VERSION_1_4 = 14000`** (freeze May 2023).
- **`LanguageFeature`**: new / reserved IDs; several features graduated from `in_development`.
- New cross-version features (examples): **`FEATURE_RANGE_TYPE`**, **`FEATURE_ROUND_WITH_ROUNDING_MODE`**, **`FEATURE_CBRT_FUNCTIONS`**, **`FEATURE_INVERSE_TRIG_FUNCTIONS`** (deprecated marker), **`FEATURE_SPANNER_LEGACY_DDL`**, **`FEATURE_NON_SQL_PROCEDURE`**, etc.
- Rename: `FEATURE_DEPRECATED_DISALLOW_PROTO3_HAS_SCALAR_FIELD` → **`FEATURE_V_1_3_DEPRECATED_DISALLOW_PROTO3_HAS_SCALAR_FIELD`**.

### Other `.proto` files touched in this range

- `ast_enums.proto`: e.g. `ASTSpannerInterleaveClauseEnums`.
- `formatter_options.proto`, `simple_table.proto`, `type_annotation.proto`, `value.proto`: minor or supporting changes—review diffs if your bindings deserialize these.

## Parser (`zetasql/parser`)

- **`RANGE`** as a **data type** in the grammar (not only window `RANGE` framing).
- Parse-tree fixes called out in export logs: **`IN`**, **`BETWEEN`**, **`<<`**, array element **error span** behavior when `FULL_SCOPE`.

## Analyzer / resolved AST (templates and C++)

- **`let_expr_rewriter` → `with_expr_rewriter`**: WITH-expression resolution path.
- **`sql_builder`**, **`validator`**, **`rewrite_utils`**, **`resolved_collation`**: substantive edits—**collation propagation** and **AnalyzeSubstitute**-related fixes.
- **`resolved_ast*.template`**, **`resolved_ast_builder`**: builder rules (optional fields, `Build()` checks) per export notes.
- **`FlattenRewriter`**: bugfix for invalid `ResolvedAST` on some shapes.

## go-zetasqlite builtin parity (runtime)

Cross-check of **2022.08.1-relevant** builtins vs [`internal/function_register.go`](../../go-zetasqlite/internal/function_register.go) and [`internal/function_bind.go`](../../go-zetasqlite/internal/function_bind.go):

| Area | Upstream (2022.02→08) | go-zetasqlite |
|------|------------------------|---------------|
| `ARRAY_FIRST` / `ARRAY_LAST` / `ARRAY_SLICE` | Added to catalog | **Registered** (`bindArrayFirst`, etc.) |
| `ARRAY_MIN` | Signature in library | **Not** in `normalFuncs` (use `min` aggregate or add binding if required) |
| `ARRAY_INCLUDES_ALL` | New ID | **Not** registered under that name (verify analyzer mapping) |
| `ISERROR` / `IFERROR` / `NULLIFERROR` | New IDs | **Not** in `normalFuncs` |
| `DEGREES` / `RADIANS` / `PI` | Trig additions in export | **Not** registered |
| `CBRT` (DOUBLE/NUMERIC/BIGNUMERIC) | New IDs | **Not** registered |
| `ROUND` + `RoundingMode` (NUMERIC/BIGNUMERIC) | New overloads | **`bindRound`** supports 1–2 args only; no rounding-mode enum |
| `COTH` / `SECH` / `CSCH` | Hyperbolic | **Registered** (`coth`, `sech`, `csch`) |
| `IEEE_DIVIDE` | Existing | **Registered** (`ieee_divide`) |
| `LIKE ALL` NULL-pattern semantics | Reference + rewriter changes | **No** dedicated tests in repo; behavior follows analyzer + SQLite func layer—add targeted queries if you support `LIKE ALL` |

**NaN / FORMAT / ROUND**: Upstream **canonicalizes CAST/FORMAT of NaN and 0** and extends **ROUND** with **banker’s rounding** for Numeric types—confirm [`internal/function_math.go`](../../go-zetasqlite/internal/function_math.go) and FORMAT paths match compliance expectations when you enable those language features.

## Recommended follow-ups

1. Regenerate or diff **go-zetasql** bindings against protos and resolved-AST templates after pinning the new library version.
2. Add bindings + tests for **high-demand** gaps: `ISERROR` family, `CBRT`, `DEGREES`/`RADIANS`/`PI`, `ROUND(..., rounding_mode)`, **`ARRAY_MIN`** (if exposed as scalar), **`ARRAY_INCLUDES_ALL`**.
3. **`TYPE_RANGE`**: requires **value type** support in decode/eval—not only parser—before enabling `FEATURE_RANGE_TYPE` in tests.

### Verifying without heavy **bigquery-emulator** tests

Building and running `bigquery-emulator/server` tests loads **CGO** and the full emulator stack and can use **large amounts of RAM** (enough to stress IDEs). Prefer:

- **`go-zetasqlite`** [`query_test.go`](../../go-zetasqlite/query_test.go) (and related tests) for ARRAY builtins, math, and SQL semantics.
- CI or a dedicated machine with ample memory if you need end-to-end HTTP/API checks against the emulator.
