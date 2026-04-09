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

**Phase 4 status:** Generator support (`bind_link_only.cc.tmpl`, merged `bind.cc`, `bind_unified_prebuilt_*_go.go`, `link_only_bind_packages`) and unified C ABI extensions ([`googlesql_unified_capabilities`](../internal/ccall/go-googlesql-unified/include/googlesql_unified.h)) are in place. The first production opt-in is **`base/status`** using Strategy D; additional `googlesql/public/*` shards remain gated until the same alignment pattern is validated or Strategy A/B is implemented.

## Rollout

Enable **one** package at a time, run `go test` for packages that depend on it, then widen. Parser and flex amalgamation have extra generator hooks; treat them as late-stage migrations. **Do not** enable `link_only_bind_packages` for a `googlesql/public/*` library until the namespace alignment issue above is resolved for that library’s bridge symbols (unless using Strategy A/B).
