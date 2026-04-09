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

Regenerate with `go run .` from [`internal/cmd/generator`](../internal/cmd/generator). The generator emits [`templates/bind_link_only.cc.tmpl`](../internal/cmd/generator/templates/bind_link_only.cc.tmpl) instead of [`templates/bind.cc.tmpl`](../internal/cmd/generator/templates/bind.cc.tmpl) for those packages.

**Default:** the list is empty so behavior is unchanged.

## Prerequisites

1. **Protobuf alignment** — same `GOOGLE_PROTOBUF_VERSION` / codegen as Bazel `@com_google_protobuf` ([prebuilt-cgo.md](prebuilt-cgo.md)).
2. **Prebuilt GoogleSQL** — symbols referenced from `bridge.inc` must be defined in `libgooglesql.a` (or merged archives), built from the same Bazel graph as your headers.
3. **No duplicate Abseil** — follow [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md).

## Namespace alignment (required for real opt-in)

[`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) merges **plain Bazel** `*.pic.o` from `//googlesql/...` targets. Those objects use **upstream** C++ namespaces (`googlesql::`, `google::protobuf::`, etc.).

Generated CGO `bind.cc` translation units apply **per-package rename macros** (for example `#define googlesql googlesql_public_analyzer_googlesql` before including headers) so multiple CGO packages can link in one binary without symbol collisions. Bridge code and `bridge.inc` therefore expect **mangled** symbol names, not the unmangled names inside raw Bazel archives.

This is the same *shape* of constraint described for Tier B protobuf in [protobuf-vendoring.md](protobuf-vendoring.md) (**Bazel object symbols do not match amalgamation renaming**). Until a **namespace-aligned** GoogleSQL static library is produced (same defines as the generator applies for that package, or an equivalent single-owner story), **`cclib.link_only_bind_packages` should stay empty** for production `googlesql/public/*` shards: linking raw `libgooglesql.a` into those CGO packages will not satisfy the linker.

**Phase 4 status:** Generator support (`bind_link_only.cc.tmpl`, `link_only_bind_packages`) and unified C ABI extensions ([`googlesql_unified_capabilities`](../internal/ccall/go-googlesql-unified/include/googlesql_unified.h)) are in place; first production opt-in is gated on an aligned archive pipeline (local experiments may set `GOOGLESQL_UNIFIED_BAZEL_TARGETS` to include `//googlesql/public:analyzer` for a larger smoke archive — see [libgooglesql-unified.md](libgooglesql-unified.md)).

## Rollout

Enable **one** package at a time, run `go test` for packages that depend on it, then widen. Parser and flex amalgamation have extra generator hooks; treat them as late-stage migrations. **Do not** enable `link_only_bind_packages` for a `googlesql/public/*` library until the namespace alignment issue above is resolved for that library’s bridge symbols.
