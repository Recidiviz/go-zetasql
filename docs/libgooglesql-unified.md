# Unified static library `libgooglesql.a`

This document describes the **unified prebuilt** archive layout and C ABI. It complements [`native-build-pipeline.md`](native-build-pipeline.md), [`prebuilt-cgo.md`](prebuilt-cgo.md), and [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md).

## Bootstrap scope

**Goal:** A reproducible **`libgooglesql.a`** output path, verification scripts, **public C header** ([`include/googlesql_unified.h`](../internal/ccall/go-googlesql-unified/include/googlesql_unified.h)), pkg-config shape, and a **single CGO owner** package so the repo can grow toward a full GoogleSQL static library.

### C ABI (stable symbols)

| Symbol | Purpose |
|--------|---------|
| `void googlesql_unified_anchor(void)` | Link / smoke anchor ([`c/googlesql_unified_anchor.c`](../internal/ccall/go-googlesql-unified/c/googlesql_unified_anchor.c)). |
| `const char* googlesql_unified_version_string(void)` | Human-readable label ([`cxx/googlesql_unified_wrapper.cc`](../internal/ccall/go-googlesql-unified/cxx/googlesql_unified_wrapper.cc)). |

Future versions can add parse/analyzer wrappers once the Bazel closure you need builds in your environment (see **Analyzer / full stack** below).

### What is inside `libgooglesql.a`

- Object files from **GoogleSQL Bazel `cc_library` targets** listed in `GOOGLESQL_UNIFIED_BAZEL_TARGETS` (default: five parser-safe `//googlesql/base:*` targets — see [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh)), merged from `*.pic.o` under the Bazel `bazel-bin/googlesql` tree after a successful `bazel build`.
- The compiled C anchor object and **C++ wrapper** object (version string).

This is intentionally **not** the full `//googlesql/public:analyzer` closure by default: that target may pull generated parser tooling that requires extra network credentials in some environments. Expand `GOOGLESQL_UNIFIED_BAZEL_TARGETS` when your Bazel workspace can analyze those dependencies.

### Relationship to Tier B protobuf / Abseil archives

- **`libgooglesql.a` does not replace** `libprotobuf_cgo.a` or `libabsl_cgo.a`. It holds **GoogleSQL-owned** object code plus anchor/wrapper.
- A binary that calls into generated GoogleSQL C++ APIs will generally still need to link **protobuf and Abseil** consistent with [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). A future **single merged** archive from one Bazel graph can subsume those steps.

## Build

From the repository root:

```bash
make prebuilt-libs-googlesql-unified
```

Requires **bazelisk** or **bazel**, **clang** / **clang++**, and the populated submodule at [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql).

Override targets (space-separated):

```bash
GOOGLESQL_UNIFIED_BAZEL_TARGETS='//googlesql/base:logging //googlesql/base:status' make prebuilt-libs-googlesql-unified
```

## Verify

```bash
make verify-prebuilt-googlesql-unified
```

## Native C link smoke

After the archive exists:

```bash
bash scripts/smoke_link_googlesql_unified.sh
```

Compiles [`smoke/smoke_main.c`](../internal/ccall/go-googlesql-unified/smoke/smoke_main.c) against **`-I…/include`** and **`-L…/lib -lgooglesql`**, then runs the binary.

## Go build tag `googlesql_unified_prebuilt`

Package [`internal/ccall/go-googlesql-unified/googlesqlunified`](../internal/ccall/go-googlesql-unified/googlesqlunified) links `libgooglesql.a` when the archive exists. Use with `-tags googlesql,googlesql_unified_prebuilt` for smoke tests.

[`Makefile`](../Makefile) target **`local/build-prebuilt-googlesql-unified`** matches what CI runs for the Go step (with `CGO_LDFLAGS_ALLOW` / `CGO_LDFLAGS` for mold-compatible links on Linux).

## CI (GitHub Actions)

Workflow **[`.github/workflows/go-googlesql-unified-prebuilt.yml`](../.github/workflows/go-googlesql-unified-prebuilt.yml)** (`workflow_dispatch`): `make prebuilt-libs-googlesql-unified`, verify, **`make local/build-prebuilt-googlesql-unified`** (with `CGO_ENABLED` and linker allowlists set), then **`scripts/smoke_link_googlesql_unified.sh`**. Requires **`submodules: recursive`** checkout so [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) is present.

## Analyzer / full stack (future)

When `bazel build //googlesql/public:analyzer` succeeds in your environment, set `GOOGLESQL_UNIFIED_BAZEL_TARGETS` accordingly and extend the C API with real wrappers. Re-run `nm` / link tests for duplicate Abseil/protobuf symbols per overlap policy.
