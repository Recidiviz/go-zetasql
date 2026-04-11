# Link-only CGO migration (no amalgamation)

This document complements [tier-b-absl-protobuf.md](tier-b-absl-protobuf.md) and [libgooglesql-unified.md](libgooglesql-unified.md).

## Goal

Replace generated `bind.cc` files that `#include` hundreds of `.cc` sources with a **link-only** translation unit that:

- Keeps `_cgo_export.h`, rename macros, and `bridge.h` / `bridge.inc` so the Go export ABI is unchanged.
- Omits amalgamated `.cc` bodies and `deps/export.inc` chains — implementations come from **one** prebuilt static archive (e.g. expanded `libgooglesql.a`) plus Tier B `libprotobuf_cgo.a`.

## Generator support

In [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml), set `cclib.link_only_bind_packages` to a list of Bazel cc_library keys (`BasePkg/Name`), for example:

```yaml
cclib:
  link_only_bind_packages:
    - googlesql/public/analyzer
```

Regenerate with `go run .` from [`internal/cmd/generator`](../internal/cmd/generator). For opted-in libraries, the generator emits a **merged** [`bind.cc`](../internal/cmd/generator/templates/bind_link_only.cc.tmpl):

- **Default** (`bind_linux.go` / `bind_darwin.go` with `//go:build !googlesql_unified_prebuilt`): the **amalgamation** branch (same as historical `bind.cc.tmpl`) so existing `go test` / CI without prebuilts is unchanged.
- **Unified prebuilt** (`bind_unified_prebuilt_*_go.go` with `//go:build googlesql_unified_prebuilt`): compiles with `-DGOOGLESQL_LINK_ONLY_BIND` and links [`libgooglesql.a`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) plus an import of [`googlesqlunified`](../internal/ccall/go-googlesql-unified/googlesqlunified/doc.go) for link order.

**Pilot:** [`base/status`](../internal/ccall/go-base/status) is the first production opt-in, with **per-package** `exclude_replace_names` so `googlesql::` / `re2::` / etc. match Bazel objects in `libgooglesql.a` (see below).

## Prerequisites

1. **Protobuf alignment** — same `GOOGLE_PROTOBUF_VERSION` / codegen as Bazel `@com_google_protobuf` ([prebuilt-cgo.md](prebuilt-cgo.md)).
2. **Prebuilt GoogleSQL** — symbols referenced from `bridge.inc` must be defined in `libgooglesql.a` (or merged archives), built from the same Bazel graph as your headers.
3. **No duplicate Abseil** — follow [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md).

## Namespace alignment (required for real opt-in)

[`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) merges **plain Bazel** `*.pic.o` from `//googlesql/...` targets. Those objects use **upstream** C++ namespaces (`googlesql::`, `google::protobuf::`, etc.).

Generated CGO `bind.cc` translation units normally apply **per-package rename macros** (for example `#define googlesql googlesql_public_analyzer_googlesql` before including headers) so multiple CGO packages can link in one binary without symbol collisions. Bridge code and `bridge.inc` therefore expect **mangled** symbol names, not the unmangled names inside raw Bazel archives.

### Resolution strategies (repository decision)

| Strategy | Description |
|----------|-------------|
| **A — Bazel-side alignment** | Build GoogleSQL (or a wrapper `cc_library`) with the **same** preprocessor defines the generator uses for that package so `*.pic.o` match amalgamation symbol names. |
| **B — Single merged archive** | One native archive produced from the same TU model as amalgamation (heavier; overlaps [native-build-pipeline.md](native-build-pipeline.md)). |
| **C — Pilot outside `googlesql/public/*`** | Lower-risk slices; still subject to rename rules unless combined with Strategy **D**. |
| **D — Per-package `exclude_replace_names` + unified prebuilt** (implemented for `base/status`) | For a **single** package, omit `#define` lines for `googlesql`, `googlesql_base`, `googlesql_bison_parser`, `re2`, and `differential_privacy` so headers use **upstream** namespaces that match `libgooglesql.a`. Use **only** with `-tags googlesql,googlesql_unified_prebuilt` and a built `libgooglesql.a`; the default amalgamation path uses `//go:build !googlesql_unified_prebuilt` and does not require the archive. |

**Global** `global_exclude_replace_names: [absl, google]` already keeps Abseil and `google::protobuf` consistent with Tier B; Strategy D extends that idea to **googlesql\*** / **re2** / **differential_privacy** for selected packages.

**Phase 4 status:** Generator support (`bind_link_only.cc.tmpl`, merged `bind.cc`, `bind_unified_prebuilt_*_go.go`, `link_only_bind_packages`) and unified C ABI extensions ([`googlesql_unified_capabilities`](../internal/ccall/go-googlesql-unified/include/googlesql_unified.h)) are in place. The first production opt-in was **`base/status`** using Strategy D; the next root-package slice extends the same pattern to **`googlesql/public/analyzer`**, **`googlesql/public/catalog`**, **`googlesql/public/simple_catalog`**, **`googlesql/public/sql_formatter`**, **`googlesql/parser/parser`**, and **`googlesql/parser/bison_parser_generated_lib`** under `-tags googlesql,googlesql_unified_prebuilt`.

## Rollout

Enable **one** package at a time, run `go test` for packages that depend on it, then widen. Parser and flex amalgamation have extra generator hooks; treat them as late-stage migrations. **Do not** enable `link_only_bind_packages` for a `googlesql/public/*` library until the namespace alignment issue above is resolved for that library’s bridge symbols (unless using Strategy A/B).

## Operational rollout

`cclib.link_only_bind_packages` in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) is a **single global list**. The intended production order matches Strategy D opt-ins:

`base/status` → `googlesql/public/analyzer` → `googlesql/public/catalog` → `googlesql/public/simple_catalog` → `googlesql/public/sql_formatter` → `googlesql/parser/parser` → `googlesql/parser/bison_parser_generated_lib`.

**Staged trimming (when debugging):** If link failures or duplicate symbols involve several thin binds at once, temporarily reduce `link_only_bind_packages` to `base/status` plus only the **prefix** of that list up to the slice you are fixing (for example `base/status` and `googlesql/public/analyzer` only). Regenerate binds (`go run .` from [`internal/cmd/generator`](../internal/cmd/generator)), re-run tests, then add the next package and repeat. Restore the **full** list once the whole chain passes under unified prebuilt.

**After every `config.yaml` change:** regenerate so merged [`bind.cc`](../internal/cmd/generator/pkg/generator.go) (amalgamation vs `-DGOOGLESQL_LINK_ONLY_BIND`) stays in sync.

**Primary supported path (link-only + prebuilt):** For ongoing development and rollout exit criteria, treat **`make local/test-root-unified`** (or `go test` with `-tags googlesql,googlesql_unified_prebuilt` and the same prebuilts as the Makefile) as the **main** gate. Maintaining the fat amalgamation branch (`//go:build !googlesql_unified_prebuilt`) in parallel is **optional** — you can standardize on prebuilt-only to avoid two CGO modes.

**Verification commands** (same toolchain as [`Makefile`](../Makefile) `local/test` / `local/test-root-unified`):

1. **Unified prebuilt link-only (primary):** `make local/test-root-unified` with `GO_TEST_FLAGS='-run ^$'` for compile/link/startup smoke, then widen `-run` or use `TESTPKG` to narrow scope.
2. **Legacy fat amalgamation (optional):** `make local/test` — `-tags googlesql` without `googlesql_unified_prebuilt`; useful during migration or comparison, not required for a prebuilt-only policy.
3. **Analyzer shard gate (optional):** `make local/test-prebuilt-googlesql-unified-root` (see `TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT` in the Makefile).
4. **Prebuilts:** `bash scripts/verify-prebuilt-googlesql-unified.sh` and `bash scripts/verify-prebuilt-protobuf.sh` before trusting archive-boundary changes.


**Low memory (avoid OOM during `clang++`):** Prefer serialized package builds: `GO_BUILD_P_MAX=1`, `GOMAXPROCS=1`, and a high `GO_BUILD_MEM_PER_JOB_KB` (see [`Makefile`](../Makefile)) so the Makefile’s `-p` heuristic stays at 1. For a narrow compile gate without running tests: `make local/compile-root-unified-test` or `make local/test-root-unified GO_TEST_FLAGS='-run ^$'`. [`scripts/cgo-go.sh`](../scripts/cgo-go.sh) wraps `go test`/`go build` with `-p 1` and optional `systemd-run` memory limits. Avoid `go test -a` unless you need a clean rebuild; it defeats the build cache and increases peak RAM.

**Triage:** Unresolved symbols → extend [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt) and re-run [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh); duplicate `ABSL_FLAG` / static init → [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md) and [unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md).
