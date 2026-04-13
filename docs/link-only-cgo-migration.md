# Link-only CGO (unified prebuilt)

This document complements [tier-b-absl-protobuf.md](tier-b-absl-protobuf.md) and [libgooglesql-unified.md](libgooglesql-unified.md). Broader consolidation program, inventory script, and CI invariant: [cgo-consolidation.md](cgo-consolidation.md).

## Goal

Generated `bind.cc` files for GoogleSQL are **link-only** translation units that:

- Keep `_cgo_export.h`, rename macros, and `bridge.h` / `bridge.inc` so the Go export ABI is unchanged.
- Omit amalgamated `.cc` bodies — implementations come from **one** prebuilt static archive (`libgooglesql.a`) plus Tier B `libprotobuf_cgo.a`.

## Generator support

Every `googlesql/*` cc_library uses thin [`bind_link_only.cc.tmpl`](../internal/cmd/generator/templates/bind_link_only.cc.tmpl) (`linkOnlyBind` in [`internal/cmd/generator/pkg/generator.go`](../internal/cmd/generator/pkg/generator.go)). Non-googlesql packages that share the same path are listed under `cclib.link_only_bind_packages` in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) (e.g. `base/status`).

Regenerate with **`go run ./internal/cmd/generator`** from the repository root.

Go entry points are **`bind_unified_prebuilt_linux.go` / `bind_unified_prebuilt_darwin.go`** with `//go:build googlesql_unified_prebuilt`. They compile with `-DGOOGLESQL_LINK_ONLY_BIND` and link [`libgooglesql.a`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) plus a blank import of [`googlesqlunified`](../internal/ccall/go-googlesql-unified/googlesqlunified/doc.go) for link order.

**Pilot:** [`base/status`](../internal/ccall/go-base/status) uses **per-package** `exclude_replace_names` so `googlesql::` / `re2::` / etc. match Bazel objects in `libgooglesql.a` (see below).

## Prerequisites

1. **Protobuf alignment** — same `GOOGLE_PROTOBUF_VERSION` / codegen as Bazel `@com_google_protobuf` ([prebuilt-cgo.md](prebuilt-cgo.md)).
2. **Prebuilt GoogleSQL** — symbols referenced from `bridge.inc` must be defined in `libgooglesql.a`, built from the same Bazel graph as your headers.
3. **No duplicate Abseil** — follow [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md).

## Namespace alignment

[`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) merges **plain Bazel** `*.pic.o` from `//googlesql/...` targets. Those objects use **upstream** C++ namespaces (`googlesql::`, `google::protobuf::`, etc.).

Generated CGO normally applies **per-package rename macros** so multiple CGO packages can link in one binary without symbol collisions. Bridge code expects **mangled** symbol names unless you use **Strategy D** (per-package `exclude_replace_names` + unified prebuilt), as in `base/status`.

**Global** `global_exclude_replace_names: [absl, google]` keeps Abseil and `google::protobuf` consistent with Tier B.

## Operational

**After every `config.yaml` change:** regenerate (**`go run ./internal/cmd/generator`** from the repository root).

**Primary gate:** **`task test:local`** (same tags and prebuilts: `verify-prebuilt-protobuf` + `verify-prebuilt-googlesql-unified`) or `go test -tags googlesql,googlesql_unified_prebuilt` with the same toolchain as the [`Taskfile.yml`](../Taskfile.yml).

**Protobuf-only CI (no `libgooglesql.a`):** `task test:protobuf-cgo` — verifies protobuf prebuilts and tests [`internal/ccall/go-protobuf/protobuf/`](../internal/ccall/go-protobuf/protobuf/) only.

**Verification commands**

1. **Full tree / narrowed package:** `task test:local` with `TESTPKG` and optional `GO_TEST_FLAGS='-run ^$'` for compile-only smoke.
2. **Shard gate:** `task test:googlesql-unified-root` (see `TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT` in [`Taskfile.yml`](../Taskfile.yml)).
3. **Prebuilts:** `bash scripts/verify-prebuilt-googlesql-unified.sh` and `bash scripts/verify-prebuilt-protobuf.sh`.

**Low memory (avoid OOM during `clang++`):** `GO_BUILD_P_MAX=1`, `GOMAXPROCS=1`, [`scripts/cgo-go.sh`](../scripts/cgo-go.sh). Narrow compile: `task test:compile-root-unified` or `task test:local GO_TEST_FLAGS='-run ^$'`.

**Triage:** Unresolved symbols → extend [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt) and re-run [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh); duplicate `ABSL_FLAG` / static init → [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md) and [unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md).
