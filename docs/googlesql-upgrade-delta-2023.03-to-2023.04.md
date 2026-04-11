# Googlesql upgrade delta: `2023.03.2` → `2023.04.1`

This note captures a **tag-scoped review** of upstream changes between `2023.03.2` and `2023.04.1` in [googlesql](https://github.com/google/googlesql) history (paths under `zetasql/` at those tags; the open-source tree may use `googlesql/` today). The range contains **two** squashed export commits (`06e004b3`, then `206e78c8`); **commit bodies list internal change titles** but not every file. Use **`git diff 2023.03.2..2023.04.1 -- zetasql/`** for line-level detail.

## Scale

| Metric | Value |
|--------|------|
| Commits in range (`git log 2023.03.2..2023.04.1`) | 2 |
| Files under `zetasql/` (diff stat) | ~289 |
| Net change | large insertions in JSON, RANGE, builtins, tests |

## Upstream themes → go-googlesql / go-googlesqlite / emulator

### JSON (`zetasql/public/functions/json.cc`, `json_internal.h`, `reference_impl/functions/json.cc`)

| Upstream change (2023.03.2→2023.04.1) | go-googlesql | go-googlesqlite | Notes |
|--------------------------------------|------------|---------------|-------|
| **`JsonPathEvaluator`**: escaping callback `(string_view)` → `(string_view, bool is_key)`; legacy one-arg callback retained | Vendored C++ in [`internal/cmd/updater/googlesql/`](../internal/cmd/updater/googlesql/) tracks this tree when updated | [`internal/function_json.go`](../../go-googlesqlite/internal/function_json.go) uses **goccy/go-json** paths, not the C++ JSONPath extractor—**behavioral parity** for “escape needed” callbacks is **not** 1:1 with C++; re-check if you add native JSONPath |
| **`JsonArray` / `JsonObject` helpers** (variadic `Value` → JSON array/object; duplicate keys skip later values) | N/A (runtime in reference impl) | **`JSON_ARRAY`**, **`JSON_OBJECT`** in [`function_json.go`](../../go-googlesqlite/internal/function_json.go); duplicate keys **first wins** (matches upstream) | Covered by [`query_test.go`](../../go-googlesqlite/query_test.go) (`json_object_duplicate_keys_first_wins`, `json_array_*`) |
| **Reference impl**: `JsonExtractFunction` rename from `JsonFunction`; **`ConvertJsonFunction`** (INT64/DOUBLE/BOOL from JSON), **`ConvertJsonLaxFunction`**, **`JsonTypeFunction`**, **`JsonArrayFunction`** (`JSON_ARRAY` builtin) | Analyzer emits `FunctionKind`s; protos in [`builtin_function.proto`](../internal/cmd/updater/googlesql/zetasql/public/builtin_function.proto) | [`function_register.go`](../../go-googlesqlite/internal/function_register.go): `int64`, `json_type`, `lax_*`, `json_array`, etc. | End-to-end JSON cast tests in `query_test.go` (`json_int64`, `json_bool`, `json_float64`, `json_type`, LAX tests) |

### RANGE (`zetasql/public/functions/range.cc` **new**)

| Upstream | go-googlesqlite |
|----------|----------------|
| **`ParseRangeBoundaries`**: parse string literals `[start, end)` for **relational RANGE** type; strict `", "` delimiter | **Not** wired: zetasqlite has **window** `RANGE` / `RANGE_BUCKET` / geography-style uses, not full **RANGE&lt;T&gt;** values + `CAST(string AS RANGE …)` end-to-end |

**Follow-up:** when `FEATURE_RANGE_TYPE` is enabled in tests, port boundary parsing and CAST from STRING using the same grammar as [`range.cc`](https://github.com/google/googlesql/blob/master/zetasql/public/functions/range.cc) (or current `googlesql` equivalent).

### Built-ins and language surface

| Item | Proto / feature in vendored tree | go-googlesqlite runtime |
|------|-----------------------------------|------------------------|
| **`GROUPING()`** scalar | `FN_GROUPING` in [`builtin_function.proto`](../internal/cmd/updater/googlesql/zetasql/public/builtin_function.proto); `FEATURE_V_1_4_GROUPING_BUILTIN` in [`options.proto`](../internal/cmd/updater/googlesql/zetasql/public/options.proto) | **Not** registered in [`function_register.go`](../../go-googlesqlite/internal/function_register.go). Aggregate path documents `GROUPING SETS` only in [`transformer_scan_aggregate.go`](../../go-googlesqlite/internal/transformer_scan_aggregate.go) |
| **`ARRAY_ZIP_MODE`** (opaque enum) | [`array_zip_mode.proto`](../internal/cmd/updater/googlesql/zetasql/public/functions/array_zip_mode.proto) | **`ARRAY_ZIP` not** implemented; named-argument / `AS` alias form for zip args appears in upstream parser tests |
| **Function call arguments with alias** | Parser: `ASTExpressionWithAlias` in [`zetasql/parser/bison_parser.y`](../internal/cmd/updater/googlesql/zetasql/parser/bison_parser.y), tests `function_call_argument_alias.test` | **Supported** wherever the **linked GoogleSQL/GooglesSQL library** version supports it (go-googlesql uses CGO + vendored parser). Resolver rejects invalid alias use at analysis time |

### CORRESPONDING, FLATTEN, alias resolution

- **UNION CORRESPONDING**: feature flags / tests upstream; emulator and zetasqlite only need parity if you enable **`FEATURE_CORRESPONDING`** and implement set ops—treat as **analyzer/catalog** follow-up, not a single function registration.
- **FLATTEN ordering**: reference-impl change (unordered when input unordered)—only if you expose `FLATTEN`.
- **Aliased table name resolution** (`table_name_resolver.cc`): fixed in analyzer; pick up with vendored library refresh.

### Lower priority for local SQLite engine

- Differential privacy / anonymization dependency churn
- Java `AnnotationMap`, formatter internals
- `ResolvedASTVisitor` stack depth limits (safety; match if you replicate depth checks in Go)

### Commit `206e78c8` (follow-up)

- Extra JSON tests / `functions_testlib_json.cc`
- **ALTER … SET OPTIONS** parser coverage (`alter_set_options.test`)
- RewriteVisitor error-path tests

---

## bigquery-emulator

- HTTP/API surface unchanged unless you expose new analyzer warnings or options.
- SQL parity is inherited from **go-googlesqlite**; add **integration** tests in [`server/server_test.go`](../../bigquery-emulator/server/server_test.go) for critical builtins (see `TestSimpleQuery`).

## Verifying

```bash
# Upstream
cd /path/to/googlesql && git diff 2023.03.2..2023.04.1 --stat -- zetasql/

# Focused
git diff 2023.03.2..2023.04.1 -- zetasql/public/functions/json.cc zetasql/reference_impl/functions/json.cc zetasql/public/functions/range.cc
```

### Building / testing (CGO memory and cache)

Heavy **`go test ./...`** runs can **OOM** (`clang++: signal: killed`) when many CGO packages compile at once. Align with the [`.envrc`](../.envrc) / [Taskfile](../Taskfile.yml) setup in **go-googlesql** (install [direnv](https://direnv.net/) and run **`direnv allow`** so your shell matches **`task`**):

- Prefer **`task test:local`** from the `go-googlesql` checkout with `TESTPKG` set to a **single package** (default `./`), or **`task test:linux`** inside **`go-googlesql:dev`** so **GOCACHE**, **GOMODCACHE**, and **ccache** stay warm.
- Use **low `-p`** ([`scripts/go-googlesql-env.sh`](../scripts/go-googlesql-env.sh) defaults **`GO_BUILD_P_MAX`** to **2**; use **`GO_BUILD_P=1`** or **`go test -p 1`** on tight hosts).
- When **`mold`** is on `PATH`, **`task build:local`** / **`task test:local`** pass **`CGO_LDFLAGS=-fuse-ld=mold`** for faster linking (Linux).

**go-googlesqlite** / **bigquery-emulator**: run targeted tests on the **root or one package** (e.g. `go test -p 1 -run 'TestQuery/json_float64_wide_number_mode' .` in go-googlesqlite) with the same **`CC="ccache clang"`** / **`GO_CACHE_ROOT`** env as above—not unbounded `./...` without Docker or a large machine.

Regenerate Go protos if you bump vendored `*.proto`: **`go run ./internal/cmd/generator`** from [`internal/cmd/generator`](../internal/cmd/generator) (see [protobuf-vendoring.md](protobuf-vendoring.md)).

## Recommended follow-ups

1. Implement **`GROUPING(...)`** scalar evaluation for `ROLLUP`/`CUBE` rows once the analyzer emits it (may require grouping-id vector in aggregate executor).
2. Register **`ARRAY_ZIP`** and plumb **`ARRAY_ZIP_MODE`** if product requires it.
3. **RANGE** type: `CAST` from string + conditional/order-by behavior per upstream compliance once types are enabled.
4. Keep vendored **parser/analyzer** in sync so **`ASTExpressionWithAlias`** in function calls matches production GooglesQL.
