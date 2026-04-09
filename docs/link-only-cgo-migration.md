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

## Rollout

Enable **one** package at a time, run `go test` for packages that depend on it, then widen. Parser and flex amalgamation have extra generator hooks; treat them as late-stage migrations.
