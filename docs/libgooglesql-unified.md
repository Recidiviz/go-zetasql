# Unified static library `libgooglesql.a`

This document describes the **v1** unified prebuilt archive layout and API. It complements [`native-build-pipeline.md`](native-build-pipeline.md), [`prebuilt-cgo.md`](prebuilt-cgo.md), and [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md).

## v1 scope (bootstrap)

**Goal:** Establish a reproducible **`libgooglesql.a`** output path, verification scripts, pkg-config shape, and a **single CGO owner** package so the repo can evolve toward a full GoogleSQL static library without changing the high-level story later.

**ABI (v1):** A minimal **C** entry point so non-C++ callers can sanity-check linking:

| Symbol | Purpose |
|--------|---------|
| `void googlesql_unified_anchor(void)` | Always present; forces the archive to export at least one resolvable symbol. |

Future versions can add `googlesql_parse_*`, analyzer wrappers, etc., once the Bazel closure you need builds in your environment (see **Analyzer / full stack** below).

**What is inside v1 `libgooglesql.a`:**

- Object files from **GoogleSQL Bazel `cc_library` targets** listed in `GOOGLESQL_UNIFIED_BAZEL_TARGETS` (default: `//googlesql/base:logging`), merged from `*.pic.o` under the Bazel `bazel-bin/googlesql` tree after a successful `bazel build`.
- The compiled C object for [`googlesql_unified_anchor.c`](../internal/ccall/go-googlesql-unified/c/googlesql_unified_anchor.c).

v1 is intentionally **not** the full `//googlesql/public:analyzer` closure: that target pulls generated parser tooling that may require extra network credentials in some environments (e.g. private Go module proxies). Expand `GOOGLESQL_UNIFIED_BAZEL_TARGETS` when your Bazel workspace can analyze those dependencies.

**Relationship to Tier B protobuf / Abseil archives:**

- v1 **`libgooglesql.a` does not replace** `libprotobuf_cgo.a` or `libabsl_cgo.a`. It holds **GoogleSQL-owned** object code plus the anchor.
- A binary that calls into generated GoogleSQL C++ APIs will generally still need to link **protobuf and Abseil** consistent with [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md). A future **single merged** archive built entirely inside one Bazel graph (or a audited `ar` merge) can subsume those steps; v1 does not claim to.

## Build

From the repository root:

```bash
make prebuilt-libs-googlesql-unified
```

Requires **bazelisk** or **bazel**, **clang**, and the populated submodule at [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql).

Override targets (space-separated):

```bash
GOOGLESQL_UNIFIED_BAZEL_TARGETS='//googlesql/base:logging //googlesql/base:status' make prebuilt-libs-googlesql-unified
```

## Verify

```bash
make verify-prebuilt-googlesql-unified
```

## Go build tag `googlesql_unified_prebuilt`

Package [`internal/ccall/go-googlesql-unified/googlesqlunified`](../internal/ccall/go-googlesql-unified/googlesqlunified) links `libgooglesql.a` when the archive exists. Use with `-tags googlesql,googlesql_unified_prebuilt` for smoke tests.

## Analyzer / full stack (future)

When `bazel build //googlesql/public:analyzer` succeeds in your environment, set `GOOGLESQL_UNIFIED_BAZEL_TARGETS=//googlesql/public:analyzer` (or add it to the default list in [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh)) and extend the C API with real wrappers. Re-run `nm` / link tests for duplicate Abseil/protobuf symbols per overlap policy.
