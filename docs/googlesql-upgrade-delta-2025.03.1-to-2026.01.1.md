# Googlesql upgrade delta: `2025.03.1` → `2026.01.1`

This note tracks **upstream** changes between tags `2025.03.1` and `2026.01.1` in [google/googlesql](https://github.com/google/googlesql) and how **go-googlesql**, **go-googlesqlite**, and **bigquery-emulator** align.

## GoogleSQL → GoogleSQL (upstream)

Upstream publishes **`zetasql_to_googlesql_migration.md`** at the repo root. Summary:

- **C++ tree:** top-level directory is **`googlesql/`** (replacing `zetasql/zetasql` layout).
- **Namespaces:** `zetasql` / `zetasql_base` → **`googlesql` / `googlesql_base`**.
- **Includes:** `#include "zetasql/..."` → **`#include "googlesql/..."`**.
- **Macros:** `ZETASQL_*` → **`GOOGLESQL_*`**; Abseil flags `zetasql_*` → **`googlesql_*`** (and corresponding `no...` variants).
- **Parser:** Bison/Flex-based `bison_parser.cc` / `flex_tokenizer.*` are **removed** from source; lexer/parser are generated from **`googlesql.tm`** via **Textmapper** (`tm_lexer.*`, `tm_parser.*`, `tm_token.h`). The go-googlesql build runs **`textmapper generate`** on `googlesql.tm` after copying sources into `internal/ccall/googlesql/parser/`.

The **Go module** remains **`github.com/vantaboard/go-googlesql`** (no rename).

## go-googlesql source snapshot

1. Submodule at **`2026.01.1`** only ([`docs/zetasql-submodule-policy.md`](zetasql-submodule-policy.md)).
2. [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go): copy **`internal/cmd/updater/googlesql/googlesql`** → **`internal/ccall/googlesql`**; Bazel execroot walk uses **`com_google_googlesql`** / **`googlesql`**; optional overlay from cache; run **Textmapper** when `textmapper` is on `PATH`.
3. **`go run ./internal/cmd/vendorpatch`** after copies; protobuf policy unchanged ([`docs/protobuf-vendoring.md`](protobuf-vendoring.md)); `GO_GOOGLESQL_SKIP_PROTOBUF_COPY=1` when preserving protobuf pin.
4. Sync **`*.proto`** from submodule `googlesql/` into `internal/ccall/googlesql/` as needed; **protoc 23.3** per vendoring doc.
5. Parser/codegen: **`gen_parse_tree.py`** / **`gen_resolved_ast.py`** when templates change; then **`go run .`** in [`internal/cmd/generator`](../internal/cmd/generator) with **`googlesql/`** BUILD trees and updated [`config.yaml`](../internal/cmd/generator/config.yaml) / [`bridge.yaml`](../internal/cmd/generator/bridge.yaml).

## go-googlesqlite / bigquery-emulator

- Align **LanguageFeature**, analyzer options, **builtin** registration / `function_bind.go` with upstream **FunctionSignatureId** and catalogs.
- Add **query tests** / emulator integration tests for new or changed behavior as needed.

## Verification

Sequential: **`task test:local`** (go-googlesql, `googlesql,googlesql_unified_prebuilt`) → **`go test -tags googlesql,googlesql_unified_prebuilt -p 1`** (zetasqlite) → **emulator** last.
