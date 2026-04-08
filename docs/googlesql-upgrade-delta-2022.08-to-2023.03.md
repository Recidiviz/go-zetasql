# Googlesql upgrade delta: `2022.08.1` → `2023.03.2`

This note captures a **directory-scoped review** of upstream changes between tags `2022.08.1` and `2023.03.2` in the [googlesql](https://github.com/google/zetasql) history (paths under `zetasql/` at those tags). Export commits are squashed; **commit messages do not list features**—review **`git diff 2022.08.1..2023.03.2 -- zetasql/`** for full detail. This file focuses on **proto / public API / builtins** relevant to **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator**.

## Scale

| Metric | Value |
|--------|------|
| Commits in range (`git log 2022.08.1..2023.03.2`) | 6 (squashed exports) |
| Files under `zetasql/` (diff stat) | ~876 (large churn) |
| Files under `zetasql/public/` | ~243 |

At these tags the tree uses the **`zetasql/`** directory name; the later **zetasql → googlesql** rename is not in this range.

### go-googlesql source snapshot

The vendored tree under [`internal/cmd/updater/googlesql/zetasql/`](../internal/cmd/updater/googlesql/zetasql/) in this repo is **newer than** tag `2023.03.2` (for example, `builtin_function.proto` is a strict superset in line count). It **includes** the delta below; **do not downgrade** protos to `2023.03.2` when tracking the `2023.08.x` upgrade line unless you intentionally pin that tag.

Regenerating bindings: run **`go run ./internal/cmd/generator`** from [`internal/cmd/generator`](../internal/cmd/generator) after intentional proto or C++ tree changes (see [`docs/protobuf-vendoring.md`](protobuf-vendoring.md)). Use **protoc 23.3** when regenerating `*.pb.{h,cc}` per that doc.

## Proto and public API (`zetasql/public`)

### `builtin_function.proto`

- **Reserved / removed:** `FN_KMS_ENCRYPT_STRING`, `FN_KMS_ENCRYPT_BYTES`, `FN_KMS_DECRYPT_STRING`, `FN_KMS_DECRYPT_BYTES` (**1920–1923**) marked **reserved**—KMS builtins removed from the language surface.
- **Time buckets:** `FN_DATETIME_BUCKET` (1862), `FN_DATE_BUCKET` (1863) (alongside `FN_TIMESTAMP_BUCKET`).
- **Geography:** `FN_ST_IS_RING`, `FN_ST_DUMP_POINTS`, `FN_ST_LINE_LOCATE_POINT`.
- **Anonymization:** `FN_ANON_AVG_DOUBLE_WITH_REPORT_JSON` / `_PROTO`.
- **Differential privacy (new ID block 2800–2831):** `FN_DIFFERENTIAL_PRIVACY_*` aggregates and report variants.
- **Arrays (2518–2543):** `ARRAY_SUM`, `ARRAY_AVG`, `ARRAY_MIN`, `ARRAY_MAX` (including float/double-specific max overloads), `ARRAY_OFFSET`, `ARRAY_OFFSETS`, `ARRAY_FIND`, `ARRAY_FIND_ALL`.
- **JSON:** `FN_JSON_LAX_TO_INT64` … `FN_JSON_LAX_TO_DOUBLE` (2606–2609); `FN_RANGE` (2605) and range helpers **2900–2915** (`is_start_unbounded`, `range_start`, `range_overlaps`, `range_intersect`, plus `*_INT64` NULL-dispatch overloads).

### `options.proto`

- **`LanguageFeature`:** New flags for anonymization thresholding, **differential privacy** (`FEATURE_DIFFERENTIAL_PRIVACY` and related), **JSON LAX** extractors, **proto base** for external products, **strict default-argument coercion**, **disable** switches for new array builtins, DDL for views/columns and **`CREATE TABLE ... WITH CONNECTION`**, etc.
- **Removed / reserved:** `FEATURE_JSON_NO_VALIDATION`, `FEATURE_JSON_LEGACY_PARSE` no longer appear as active enum members (replaced by **reserved** ranges—regenerate enums carefully). `FEATURE_V_1_4_COLLATION_IN_TYPE` (14001) removed and reserved.
- **Version 1.4–style features:** Array aggregation/find, **SAFE** calls with lambdas, remote models, struct positional access, array path in `FROM`, **SQL macros**, collation in `WITH RECURSIVE` / explicit `CAST`, load partitions/temp, **CORRESPONDING**, etc.
- **`ResolvedASTRewrite`:** Rewrites **13** and **15** reserved; new **`REWRITE_BUILTIN_FUNCTION_INLINER`** (16), **`REWRITE_INLINE_SQL_VIEWS`** (17).

### `type.proto`

- **`EnumTypeProto`:** `is_opaque` (field 5).
- **Protobuf extensions:** `OpaqueEnumTypeOptions` / `OpaqueEnumValueOptions` on `google.protobuf.EnumOptions` / `EnumValueOptions` for SQL-facing opaque enums.

### `function.proto`

- **`SignatureArgumentKind`:** `ARG_RANGE_TYPE_ANY = 18`.
- **`NamedArgumentKind`:** positional vs named argument rules for signatures.

### New protos under `zetasql/public/functions/`

- **`array_find_mode.proto`** — modes for `ARRAY_FIND` / `ARRAY_OFFSET`.
- **`differential_privacy.proto`** — enums for differential privacy options.

### Other

- **`deprecation_warning.proto`:** `QUERY_TOO_COMPLEX`, `DEPRECATED_ANONYMIZATION_OPTION_KAPPA`.
- **`formatter_options.proto`:** `capitalize_functions`.

## go-googlesqlite parity (runtime)

Cross-check against [`go-googlesqlite/internal/function_register.go`](../../go-googlesqlite/internal/function_register.go) and [`function_bind.go`](../../go-googlesqlite/internal/function_bind.go).

| Area | Upstream (2022.08→2023.03) | go-googlesqlite (this repo) |
|------|---------------------------|---------------------------|
| `ARRAY_SUM`, `ARRAY_AVG`, `ARRAY_MIN`, `ARRAY_MAX` | Scalar array aggregates | **Registered** (`array_sum`, `array_avg`, `array_min`, `array_max`) with tests |
| `LAX_INT64`, `LAX_BOOL`, `LAX_STRING`, `LAX_FLOAT64` / `LAX_DOUBLE` | JSON coercion | **Registered** (`lax_int64`, `lax_bool`, `lax_string`, `lax_double`, **`lax_float64`** alias for analyzer name) |
| `ARRAY_OFFSET`, `ARRAY_FIND`, … | Catalog + optional `ARRAY_FIND_MODE` | **Not** registered (follow-up) |
| `datetime_bucket`, `date_bucket`, `timestamp_bucket` | Time bucket functions | **Not** registered (follow-up) |
| `RANGE`, range predicates / `range_overlaps`, … | Range type + helpers | **Not** fully covered here (requires range value support end-to-end) |
| `FN_ST_IS_RING`, … | Geography | **Not** registered (no geography stack in zetasqlite) |
| `FN_DIFFERENTIAL_PRIVACY_*` | DP aggregates | **Not** registered (engine-specific; typically out of scope for local SQLite) |
| KMS `kms.encrypt` / `kms.decrypt_*` | Removed upstream | **Never** exposed in zetasqlite |

## bigquery-emulator

- **DDL / jobs:** New language features (view column options, `WITH CONNECTION`, remote models, macros, **CORRESPONDING**, load targets) matter only if the emulator implements those statements.
- **API:** Changes only if you surface new analyzer options or deprecation warning kinds in HTTP/API responses.

## Recommended follow-ups

1. Register **array find / offset** builtins and **`ARRAY_FIND_MODE`** once lambda/collation plumbing matches upstream expectations.
2. Implement **time bucket** (`timestamp_bucket`, `datetime_bucket`, `date_bucket`) with interval math aligned to BigQuery.
3. Extend **range** value evaluation if `FEATURE_RANGE_TYPE` is enabled in tests.
4. Keep **DP** and **geography** behind explicit feature gates or leave unimplemented with clear analyzer/catalog behavior.

### Verifying without heavy emulator tests

Prefer **go-googlesqlite** [`query_test.go`](../../go-googlesqlite/query_test.go) for SQL-level checks; run full **bigquery-emulator** tests only when you need HTTP/API coverage (memory-heavy).
