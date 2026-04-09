# Unified static library `libgooglesql.a`

This document describes the **unified prebuilt** archive layout and C ABI. It complements [`native-build-pipeline.md`](native-build-pipeline.md), [`prebuilt-cgo.md`](prebuilt-cgo.md), and [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md).

## Bootstrap scope

**Goal:** A reproducible **`libgooglesql.a`** output path, verification scripts, **public C header** ([`include/googlesql_unified.h`](../internal/ccall/go-googlesql-unified/include/googlesql_unified.h)), pkg-config shape, and a **single CGO owner** package so the repo can grow toward a full GoogleSQL static library.

### C ABI (stable symbols)

| Symbol | Purpose |
|--------|---------|
| `void googlesql_unified_anchor(void)` | Link / smoke anchor ([`c/googlesql_unified_anchor.c`](../internal/ccall/go-googlesql-unified/c/googlesql_unified_anchor.c)). |
| `const char* googlesql_unified_version_string(void)` | Human-readable label ([`cxx/googlesql_unified_wrapper.cc`](../internal/ccall/go-googlesql-unified/cxx/googlesql_unified_wrapper.cc)). Returns `0.3.0-unified+analyzer` when the archive was built with `//googlesql/public:analyzer` in the Bazel target list (see below). |
| `const char* googlesql_unified_capabilities(void)` | Comma-separated tags describing what was linked into the archive (`proto,base,resolved_ast` by default; adds `analyzer` when `GOOGLESQL_UNIFIED_INCLUDES_ANALYZER` was set during wrapper compile — i.e. `//googlesql/public:analyzer` appears in `GOOGLESQL_UNIFIED_BAZEL_TARGETS` or the default list). |

Future versions can add parse/analyzer-specific C entry points once a **namespace-aligned** link story exists for CGO (see [link-only-cgo-migration.md](link-only-cgo-migration.md) **Namespace alignment**). The **North-star analyzer build** and optional target override below remain the path to a larger `libgooglesql.a`.

### What is inside `libgooglesql.a`

- Object files from **GoogleSQL Bazel `cc_library` / `cc_proto_library` targets** listed in [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt) (comments and blank lines ignored), merged from `*.pic.o` under the Bazel `bazel-bin/googlesql` tree after a successful `bazel build`. The extract script [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) reads that file unless **`GOOGLESQL_UNIFIED_BAZEL_TARGETS`** is set.
- The compiled C anchor object and **C++ wrapper** object (version string).

The **default list** is intentionally **not** the full `//googlesql/public:analyzer` link closure: in many environments the analyzer depends on **parser codegen** that pulls **`com_github_inspirer_textmapper`** (see **Textmapper / module fetch**). The default closure instead covers **Layer A** (`//googlesql/base:*` infrastructure) plus **all `cc_proto_library` targets** under `//googlesql/public/...`, `//googlesql/proto/...`, and `//googlesql/resolved_ast/...` — i.e. protobuf-backed types on the road to AST and analyzer, without loading `//googlesql/parser:*`.

### Phase 3 — Bazel target list (layers)

Targets are **explicit, sorted labels** in [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt). Override for experiments:

```bash
GOOGLESQL_UNIFIED_BAZEL_TARGETS='//googlesql/base:logging …' make prebuilt-libs-googlesql-unified
```

| Layer | Purpose | In default file? |
|-------|---------|------------------|
| **A** | `//googlesql/base:*` core (logging, status, check, arena, strings, stl_util, base, endian, …) | Yes — first block in `default_bazel_targets.txt` |
| **B–D (proto)** | `cc_proto_library` for public protos, internal `//googlesql/proto:*`, function enums, `information_schema`, `public/proto`, and **`//googlesql/resolved_ast:*_cc_proto`** | Yes — remainder of the file |
| **E (optional monolith)** | `//googlesql/public:analyzer` as a single label | **No** in the committed default list (keeps CI extract time predictable). Add via `GOOGLESQL_UNIFIED_BAZEL_TARGETS` when your workspace resolves Textmapper/parser gen (see below). When this label is built, the extract script sets `GOOGLESQL_UNIFIED_INCLUDES_ANALYZER` for the wrapper so `googlesql_unified_version_string` / `googlesql_unified_capabilities` report the expanded archive. **Link-only CGO** for generated packages still requires [namespace-aligned objects](link-only-cgo-migration.md#namespace-alignment-required-for-real-opt-in), not raw Bazel `*.pic.o` alone. |

**North-star analyzer build:** From `internal/cmd/updater/googlesql`, the intended check is:

```bash
bazel build //googlesql/public:analyzer --cxxopt=-std=c++20 --host_cxxopt=-std=c++20
```

If analysis fails while fetching **`gazelle~~go_deps~com_github_inspirer_textmapper`** (e.g. **HTTP 401** to a private module proxy), the first failing hop is typically **`//googlesql/parser:generate_tm_parser`** → `textmapper` **before** C++ compiles. That is an **environment / registry authentication** issue, not something the extract script can fix. After fixing fetch (or using a machine with access), re-run the build; use the **default proto + base closure** in this repo until `//googlesql/public:analyzer` analyzes cleanly.

**Bazel queries** (when the workspace loads — from `internal/cmd/updater/googlesql`):

```bash
bazel query 'kind(cc_library, deps(//googlesql/public:analyzer))' --output=label
bazel query 'deps(//googlesql/public:analyzer, 1)' --output=label
```

Use the output to justify expanding `GOOGLESQL_UNIFIED_BAZEL_TARGETS` toward parser and analyzer `cc_library` targets once Textmapper is available.

### Textmapper / `go_deps` (401 and other fetch failures)

- **Module:** `com_github_inspirer_textmapper` is declared in [`internal/cmd/updater/googlesql/MODULE.bazel`](../internal/cmd/updater/googlesql/MODULE.bazel) via Gazelle `go_deps`. The parser’s **Textmapper** genrule needs the **`textmapper`** binary from that module.
- **Symptom:** Bazel reports **`401 Unauthorized`** (or timeouts) while fetching `github.com/inspirer/textmapper@…` through a **private** Go module proxy (e.g. Artifact Registry). The Go toolchain may suggest adding the registry host to **`GONOPROXY`** / **`GOPRIVATE`** and using credential helpers.
- **Mitigations (pick what matches org policy):** configure **`GOPROXY` / `GONOPROXY`** so public modules resolve from `proxy.golang.org` or direct VCS; use **`artifact-registry-go-tools`** or org credential helpers for private mirrors; **vendor** the module; populate **Bazel / module cache** on an online machine and reuse offline; run builds on a host or VPN that can reach the registry.

### Relationship to protobuf / Abseil prebuilts

- **`libgooglesql.a` does not replace** `libprotobuf_cgo.a` or `libabsl_cgo.a`. It holds **GoogleSQL-owned** object code (including generated `*.pb.cc` from `cc_proto_library`) plus anchor/wrapper.
- **`cc_proto_library` objects** reference **protobuf C++ runtime** symbols (`google::protobuf::…`); those resolve when you link **`libprotobuf_cgo.a`** (or an equivalent single-owner archive) in the same binary. **`nm`** on `libgooglesql.a` will show **undefined (`U`)** or **weak** references to Abseil/logging where generated code and `//googlesql/base` expect the runtime linked later.
- **Do not** combine `googlesql_unified_prebuilt` with `googlesql_tier_b` or `googlesql_tier_b_absl` in the **same** link without an audited single-owner plan — risk of duplicate or inconsistent Abseil/protobuf objects (see the unified + Tier B row in [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md)).

### Linking `libgooglesql.a` with `libprotobuf_cgo.a`

For a binary that uses both GoogleSQL protos and the default protobuf prebuilt archive:

1. **Single owner for protobuf + Abseil** — Prefer linking **`libprotobuf_cgo.a`** once (default protobuf prebuilt path) so protobuf and embedded Abseil objects come from one Bazel-built archive; **`libgooglesql.a`** adds GoogleSQL `.o` files that **call into** that runtime.
2. **Order** — Depend on package / linker order documented in [`prebuilt-cgo.md`](prebuilt-cgo.md). If the linker reports **duplicate symbol** errors for `absl::` or `google::protobuf::`, compare **`nm …/libgooglesql.a`** vs **`nm …/libprotobuf_cgo.a`** and follow [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md) (avoid mixed Tier B tags; adjust `-l` order before using **`--allow-multiple-definition`** as a crutch).
3. **Smoke-only unified tag** — `googlesql_unified_prebuilt` builds in CI link with flags similar to **`Makefile`** `local/build-prebuilt-googlesql-unified` (see below); they do **not** pull `libprotobuf_cgo.a` unless you add a second CGO package that does.

Spot-check (after building both archives):

```bash
nm -C internal/ccall/go-googlesql-unified/lib/$(go env GOOS)_$(go env GOARCH)/libgooglesql.a | grep -E 'google::protobuf::|absl::' | head
nm -C internal/ccall/go-protobuf/protobuf/lib/$(go env GOOS)_$(go env GOARCH)/libprotobuf_cgo.a | grep -E 'google::protobuf::|absl::' | head
```

Expect overlap in **symbol names** only where both archives define or reference the same ABI; resolve duplicates per the overlap doc.

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

Workflow **[`.github/workflows/go-googlesql-unified-prebuilt.yml`](../.github/workflows/go-googlesql-unified-prebuilt.yml)** runs **`make prebuilt-libs-googlesql-unified`** (using the **default** [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt)), **`make verify-prebuilt-googlesql-unified`**, **`make local/build-prebuilt-googlesql-unified`**, and **`scripts/smoke_link_googlesql_unified.sh`**.

- **Triggers:** `workflow_dispatch` (manual) and a **weekly** `schedule` cron for regression signal and cache warmth. Forks may disable scheduled workflows unless enabled in repository settings.
- **Full analyzer closure** (e.g. after fixing Textmapper fetch) is **not** the default CI graph; run a manual workflow or override **`GOOGLESQL_UNIFIED_BAZEL_TARGETS`** locally when expanding toward `//googlesql/public:analyzer`.
- Requires **`submodules: recursive`** checkout so [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) is present.

## Quick verification checklist

- [ ] `bazel build` of the labels in `default_bazel_targets.txt` succeeds in `internal/cmd/updater/googlesql`.
- [ ] `make prebuilt-libs-googlesql-unified` produces `internal/ccall/go-googlesql-unified/lib/$(go env GOOS)_$(go env GOARCH)/libgooglesql.a`.
- [ ] `make verify-prebuilt-googlesql-unified` passes.
- [ ] `bash scripts/smoke_link_googlesql_unified.sh` passes.
- [ ] `make local/build-prebuilt-googlesql-unified` passes with unified prebuilt tags.
