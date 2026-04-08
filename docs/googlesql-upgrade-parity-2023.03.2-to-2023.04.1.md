# googlesql / GoogleSQL parity: `2023.03.2` → `2023.04.1`

This document maps upstream changes in [googlesql](https://github.com/google/zetasql) between tags `2023.03.2` and `2023.04.1` to this repo and related **go-googlesqlite** / **bigquery-emulator** work. It complements the high-level delta list in the upgrade notes.

## Upstream commits in range

| Commit     | Role |
|-----------|------|
| `06e004b3` | Large export (behavior, parser, builtins, reference impl, tests). |
| `206e78c8` | Follow-up: JSON tests/compliance, `ALTER … SET OPTIONS` parser coverage, release fixes. |

## JSON (`zetasql/public/functions/json.cc`, `json_internal.h`, `reference_impl/functions/json.cc`)

| Upstream change | go-googlesql / go-googlesqlite notes |
|-----------------|----------------------------------|
| `JsonPathEvaluator` / `JSONPathExtractor`: escaping callback `(string_view)` → `(string_view, bool is_key)` plus legacy one-arg path | **go-googlesqlite** uses **goccy/go-json** for path extraction, not the C++ `JsonPathExtractor`. Behavioral parity for “escape key vs value” is **not** a line-for-line port; re-validate with JSON function tests if you change path handling. |
| New **`JsonArray` / `JsonObject`** helpers in `json.cc` | **go-googlesqlite**: `JSON_OBJECT` already implemented in `go-googlesqlite/internal/function_json.go`. **`JSON_ARRAY`** added as variadic builder using `Value.ToJSON()` (same encoding model as `TO_JSON`). `JSON_OBJECT` duplicate keys: first value kept (matches upstream). |
| Reference impl: **`JSON_ARRAY`** registration, rename extract classes to `JsonExtractFunction` / `JsonExtractArrayFunction` | Naming is C++ only. Runtime parity is the variadic **`JSON_ARRAY`** behavior. |
| **`INT64`/`FLOAT64`/`BOOL`/`LAX_*`/`JSON_TYPE`** on JSON | Already wired in **go-googlesqlite** (`bindInt64`, `bindDouble`, `bindLax*`, `bindJsonType`); inputs are typically **already resolved** to typed values for literals. |

## RANGE (`zetasql/public/functions/range.cc` — new)

| Upstream change | Notes |
|-----------------|-------|
| **`ParseRangeBoundaries`** for string literals `[START, END)` (strict `", "` delimiter optional) | Used for **CAST / RANGE typed value** parsing in the reference engine. **go-googlesqlite** does not yet model BigQuery **RANGE&lt;T&gt;** values end-to-end; **no** Go port added in this parity pass. Track when RANGE types land in the analyzer + coordinator. |

## Built-ins: `GROUPING`, `ARRAY_ZIP_MODE`

| Item | go-googlesql (bundled C++) | go-googlesqlite |
|------|---------------------------|---------------|
| **`GROUPING`** | Registered as an **aggregate** behind `FEATURE_V_1_4_GROUPING_BUILTIN` in `builtin_function_internal_2.cc` (`FN_GROUPING`). | **No** `grouping` aggregate in `go-googlesqlite/internal/function_register.go`. Requires aggregate evaluation tied to `GROUP BY` / `ROLLUP` / `CUBE` — **backlog**. |
| **`ARRAY_ZIP_MODE`** proto / `ARRAY_ZIP` | Upstream enum for **ARRAY_ZIP** and **UNNEST** options. | **Not** implemented in SQLite function layer; **backlog** if you expose those options. |

## Parser: `ASTExpressionWithAlias` (function call argument aliases)

| Upstream change | go-googlesql |
|-----------------|------------|
| Function arguments may be `ASTExpressionWithAlias` (e.g. `f(x AS alias)`) | The **bundled** tree in `internal/ccall/zetasql/parser/parse_tree_generated.h` includes **`ASTExpressionWithAlias`**. Analyzer resolution consumes this before SQL reaches go-googlesqlite. **No Go change** required for parse shape if the library revision matches. |

## Suggested verification commands (googlesql checkout)

```bash
git diff 2023.03.2..2023.04.1 -- zetasql/public/functions/json.cc zetasql/reference_impl/functions/json.cc
git diff 2023.03.2..2023.04.1 -- zetasql/public/functions/range.cc
```

## Tests added for this parity pass

- **go-googlesqlite**: `query_test.go` cases for **`JSON_ARRAY`** (empty, mixed types, NULL).
- **bigquery-emulator**: Node test exercising **`JSON_ARRAY`** through the running emulator.
