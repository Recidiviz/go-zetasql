# Unified static library `libgooglesql.a`

This document describes the **unified prebuilt** archive layout and C ABI. It complements [`native-build-pipeline.md`](native-build-pipeline.md), [`prebuilt-cgo.md`](prebuilt-cgo.md), and [`prebuilt-absl-overlap.md`](prebuilt-absl-overlap.md).

## Bootstrap scope

**Goal:** A reproducible **`libgooglesql.a`** output path, verification scripts, **public C header** ([`include/googlesql_unified.h`](../internal/ccall/go-googlesql-unified/include/googlesql_unified.h)), pkg-config shape, and a **single CGO owner** package so the repo can grow toward a full GoogleSQL static library.

**Policy:** **Link-only CGO + these prebuilt archives** is the supported direction. The older non-unified fat-amalgamation build (`//go:build !googlesql_unified_prebuilt`) is **deprecated** and not a parallel product to maintain long term — see [link-only-cgo-migration.md](link-only-cgo-migration.md).

### C ABI (stable symbols)

| Symbol | Purpose |
|--------|---------|
| `void googlesql_unified_anchor(void)` | Link / smoke anchor ([`c/googlesql_unified_anchor.c`](../internal/ccall/go-googlesql-unified/c/googlesql_unified_anchor.c)). |
| `const char* googlesql_unified_version_string(void)` | Human-readable label ([`cxx/googlesql_unified_wrapper.cc`](../internal/ccall/go-googlesql-unified/cxx/googlesql_unified_wrapper.cc)). Returns `0.4.0-unified+root-api` when the archive was built with the root slice (`//googlesql/public:analyzer` in the Bazel target list; see below). |
| `const char* googlesql_unified_capabilities(void)` | Comma-separated tags describing what was linked into the archive (`proto,base,resolved_ast` by default; adds `analyzer,parser,catalog,simple_catalog,sql_formatter` when `GOOGLESQL_UNIFIED_INCLUDES_ANALYZER` was set during wrapper compile — i.e. `//googlesql/public:analyzer` appears in `GOOGLESQL_UNIFIED_BAZEL_TARGETS` or the default list). |

Future versions can add parse/analyzer-specific C entry points once a **namespace-aligned** link story exists for CGO (see [link-only-cgo-migration.md](link-only-cgo-migration.md) **Namespace alignment**). The **North-star analyzer build** and optional target override below remain the path to a larger `libgooglesql.a`.

### What is inside `libgooglesql.a`

- Object files from **GoogleSQL Bazel `cc_library` / `cc_proto_library` targets** listed in [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt) (comments and blank lines ignored), merged from `*.pic.o` under the Bazel `bazel-bin/googlesql` tree after a successful `bazel build`. The extract script [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) reads that file unless **`GOOGLESQL_UNIFIED_BAZEL_TARGETS`** is set.
- The extract script also pulls the small non-protobuf external closure that the root slice now expects `libgooglesql.a` to own: RE2 `*.pic.o`, Google APIs proto objects for `google/type:{date,timeofday}` and `google/rpc:status`, plus ICU objects extracted from Bazel's `libicuuc.a`, `libicui18n.a`, and `libicudata.a`.
- The compiled C anchor object and **C++ wrapper** object (version string).

The **default list** now includes the first **root API slice** in addition to the proto/base closure: `//googlesql/public:analyzer`, `//googlesql/public:catalog`, `//googlesql/public:simple_catalog`, `//googlesql/public:sql_formatter`, `//googlesql/parser:parser`, and `//googlesql/parser:bison_parser_generated_lib`. That is enough to support the top-level Go package under `-tags googlesql,googlesql_unified_prebuilt` once the corresponding CGO packages are emitted as link-only stubs. These labels still depend on **parser codegen** that pulls **`com_github_inspirer_textmapper`** (see **Textmapper / module fetch**), so environments without access to that module may need to override `GOOGLESQL_UNIFIED_BAZEL_TARGETS` back down to the proto/base closure.

### Phase 3 — Bazel target list (layers)

Targets are **explicit, sorted labels** in [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt). Override for experiments:

```bash
GOOGLESQL_UNIFIED_BAZEL_TARGETS='//googlesql/base:logging …' make prebuilt-libs-googlesql-unified
```

| Layer | Purpose | In default file? |
|-------|---------|------------------|
| **A** | `//googlesql/base:*` core (logging, status, check, arena, strings, stl_util, base, endian, …) | Yes — first block in `default_bazel_targets.txt` |
| **B–D (proto)** | `cc_proto_library` for public protos, internal `//googlesql/proto:*`, function enums, `information_schema`, `public/proto`, and **`//googlesql/resolved_ast:*_cc_proto`** | Yes — remainder of the file |
| **E (root API slice)** | `//googlesql/public:analyzer` plus parser/catalog/simple_catalog/sql_formatter labels | **Yes** in the committed default list. This is the first slice used for prebuilt-heavy Go builds of `TESTPKG=./`. When `//googlesql/public:analyzer` is built, the extract script sets `GOOGLESQL_UNIFIED_INCLUDES_ANALYZER` for the wrapper so `googlesql_unified_version_string` / `googlesql_unified_capabilities` report the expanded archive. **Link-only CGO** for generated packages still requires [namespace-aligned objects](link-only-cgo-migration.md#namespace-alignment-required-for-real-opt-in), not raw Bazel `*.pic.o` alone. |

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

Use the output to justify widening beyond the root API slice once Textmapper is available and the current link-only package set is stable.

### Textmapper / `go_deps` (401 and other fetch failures)

- **Module:** `com_github_inspirer_textmapper` is declared in [`internal/cmd/updater/googlesql/MODULE.bazel`](../internal/cmd/updater/googlesql/MODULE.bazel) via Gazelle `go_deps`. The parser’s **Textmapper** genrule needs the **`textmapper`** binary from that module.
- **Symptom:** Bazel reports **`401 Unauthorized`** (or timeouts) while fetching `github.com/inspirer/textmapper@…` through a **private** Go module proxy (e.g. Artifact Registry). The Go toolchain may suggest adding the registry host to **`GONOPROXY`** / **`GOPRIVATE`** and using credential helpers.
- **Default extractor behavior:** [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) now passes `--repo_env=GOPROXY=https://proxy.golang.org,direct` by default for the unified archive build so public Textmapper fetches do not depend on the host’s private proxy configuration. Override with **`GOOGLESQL_UNIFIED_GOPROXY`** if your environment needs something different.
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

The verification script does a small `nm -C` spot check in addition to confirming the archive exists. It checks representative ownership symbols for ICU, RE2, Google APIs date/time protos, `googlesql::reflection::*`, and parser AST enums so archive-boundary regressions fail fast. When **`llvm-nm`** is on `PATH` and **`libprotobuf_cgo.a`** exists (run **`make prebuilt-libs`** first), it also asserts **zero** overlapping **global (`T`)** symbol names between `libgooglesql.a` and `libprotobuf_cgo.a` — duplicate globals plus **`-Wl,--allow-multiple-definition`** risk undefined behavior at startup (see [`unified-prebuilt-root-segfault-investigation.md`](unified-prebuilt-root-segfault-investigation.md)).

## Native C link smoke

After the archive exists:

```bash
bash scripts/smoke_link_googlesql_unified.sh
```

Compiles [`smoke/smoke_main.c`](../internal/ccall/go-googlesql-unified/smoke/smoke_main.c) against **`-I…/include`** and **`-L…/lib -lgooglesql`**, then runs the binary.

## Go build tag `googlesql_unified_prebuilt`

Package [`internal/ccall/go-googlesql-unified/googlesqlunified`](../internal/ccall/go-googlesql-unified/googlesqlunified) links `libgooglesql.a` when the archive exists. Use with `-tags googlesql,googlesql_unified_prebuilt` for smoke tests and the first root-package slice.

[`Makefile`](../Makefile) target **`local/build-prebuilt-googlesql-unified`** remains the archive smoke build for package `googlesqlunified`. Use **`local/build-prebuilt-googlesql-unified-root`** for the full-repo build slice (default **`BUILDPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT=./`**). **`local/test-prebuilt-googlesql-unified-root`** defaults to the **`public/analyzer`** package so the process exercises unified-prebuilt CGO + `libprotobuf_cgo.a` without requiring a root **`bind.cc`** split; override **`TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT=./`** only after that split lands (same pattern as [`base/status`](../internal/ccall/go-base/status/bind_linux.go)). The Makefile sets **`CGO_CXXFLAGS_PREBUILT`**, **`CGO_LDFLAGS_ALLOW`**, and **`CGO_LDFLAGS`** (including **`-stdlib=libc++`**) for Bazel **libc++** / mold-compatible links on Linux.

**Root `TESTPKG=./`:** use **`make local/compile-root-unified-test`** to **`go test -c`** only (writes **`$(GO_CACHE_ROOT)/googlesql_root_unified.test`**). That validates link + CGO without executing the test harness (startup may still **SIGSEGV** when run; see [`unified-prebuilt-root-segfault-investigation.md`](unified-prebuilt-root-segfault-investigation.md)). Use **`make local/test-root-unified`** when you need to execute tests after rebuilding **`libprotobuf_cgo.a`** (`extract_protobuf_cgo_lib.sh` filters duplicate Abseil **cctz** members) and the **`civil_time`** / analyzer bridge fixes described there.

### Root unified-prebuilt dependency graph (`go list`)

For **`TESTPKG=./`** with **`-tags googlesql,googlesql_unified_prebuilt`**, the interesting CGO packages are a small set (run locally to refresh):

```bash
go list -tags googlesql,googlesql_unified_prebuilt -deps -f '{{.ImportPath}}' ./ | rg 'internal/ccall/go-(absl|googlesql|protobuf|googlesql-unified)|utf8_range'
```

Typical output includes:

- `…/go-absl/time/go_internal/cctz/time_zone` — single-owner IANA **cctz** after `extract_protobuf_cgo_lib.sh` drops duplicate `time_zone_*.pic.o` from `libprotobuf_cgo.a`.
- `…/go-googlesql-unified/googlesqlunified` — pulls **`libgooglesql.a`** (anchor).
- `…/go-googlesql` (root) plus `…/go-googlesql/public/analyzer`, `…/parser/parser`, `…/parser/bison_parser_generated_lib` — link-only binds + bridges.
- `…/go-protobuf/protobuf` — **single** package that links **`libprotobuf_cgo.a`** with **`--whole-archive`** (required so symbols are not dropped).
- `…/utf8_range_link` — utf8_range closure aligned with libc++ (see investigation doc).

There is **one** import path for **`go-protobuf/protobuf`** in this graph (no duplicate protobuf CGO packages). Blank-import lines in generated `bind_unified_prebuilt_*.go` are sorted by **`go/format`** (alphabetically by import path), so **Go `init` order is not manually controlled** from those lines; C++ static constructors still follow the linker’s `.init_array` order.

**Note:** `scripts/verify-protobuf-tier-b-alignment.sh` checks vendored **`GOOGLE_PROTOBUF_VERSION`** vs `MODULE.bazel`; keep it green when changing `libprotobuf_cgo.a` or vendored headers.

## CI (GitHub Actions)

Workflow **[`.github/workflows/go-googlesql-unified-prebuilt.yml`](../.github/workflows/go-googlesql-unified-prebuilt.yml)** runs this sequence (matches a green local run):

1. **`make prebuilt-libs`** — produces **`libprotobuf_cgo.a`** (required for any unified-prebuilt link that imports **`go-protobuf`**; not committed).
2. **`make prebuilt-libs-googlesql-unified`** using the committed default [`default_bazel_targets.txt`](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt)
3. **`make verify-prebuilt-googlesql-unified`** (install **`llvm`** on the runner so **`llvm-nm`** can enforce the duplicate-**`T`** check when both archives exist)
4. **`make local/build-prebuilt-googlesql-unified`**
5. **`make local/build-prebuilt-googlesql-unified-root`**
6. **`make local/test-prebuilt-googlesql-unified-root`** (default analyzer shard)
7. **`make local/compile-root-unified-test`** — link-only **`go test -c ./`** for the full root module (no test execution; safe CI signal while runtime startup is still triaged)
8. **`bash scripts/smoke_link_googlesql_unified.sh`**

- **Triggers:** `workflow_dispatch` (manual) and a **weekly** `schedule` cron for regression signal and cache warmth. Forks may disable scheduled workflows unless enabled in repository settings.
- **Full analyzer closure** (e.g. after fixing Textmapper fetch) is **not** the default CI graph; run a manual workflow or override **`GOOGLESQL_UNIFIED_BAZEL_TARGETS`** locally when expanding toward `//googlesql/public:analyzer`.
- Requires **`submodules: recursive`** checkout so [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) is present.

## Local overrides

The unified-prebuilt flow has two main operator knobs for reproducible experiments:

- **`GOOGLESQL_UNIFIED_BAZEL_TARGETS`** overrides the Bazel label list used to build `libgooglesql.a`. Leave it unset to match CI exactly.
- **`GOOGLESQL_UNIFIED_GOPROXY`** overrides the extractor's Bazel `--repo_env=GOPROXY=...` value. Leave it unset to use `https://proxy.golang.org,direct`, which is what the extract script uses by default.

Examples:

```bash
# Match CI exactly.
make prebuilt-libs-googlesql-unified

# Narrow the archive to a smaller experiment without changing the committed default list.
GOOGLESQL_UNIFIED_BAZEL_TARGETS='//googlesql/base:logging //googlesql/base:status' \
  make prebuilt-libs-googlesql-unified

# Reproduce the same build with a different module proxy configuration.
GOOGLESQL_UNIFIED_GOPROXY='https://proxy.golang.org,direct' \
  make prebuilt-libs-googlesql-unified
```

## Quick verification checklist

- [ ] `bazel build` of the labels in `default_bazel_targets.txt` succeeds in `internal/cmd/updater/googlesql`.
- [ ] `make prebuilt-libs-googlesql-unified` produces `internal/ccall/go-googlesql-unified/lib/$(go env GOOS)_$(go env GOARCH)/libgooglesql.a`.
- [ ] `make verify-prebuilt-googlesql-unified` passes.
- [ ] `make local/build-prebuilt-googlesql-unified` passes with unified prebuilt tags.
- [ ] `make local/build-prebuilt-googlesql-unified-root` passes (default **`BUILDPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT=./`**).
- [ ] `bash scripts/smoke_link_googlesql_unified.sh` passes.
- [ ] `make local/test-prebuilt-googlesql-unified-root` passes (default analyzer **`TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT`**).
- [ ] `make local/compile-root-unified-test` passes (`TESTPKG=./`; link-only — full **`local/test-root-unified`** may still hit startup SIGSEGV until [`unified-prebuilt-root-segfault-investigation.md`](unified-prebuilt-root-segfault-investigation.md) is fully closed).
- [ ] **`CGO_CXXFLAGS_PREBUILT`** is not set to an **empty** string in the environment (that skips `-stdlib=libc++` and breaks links against Bazel libc++ prebuilts; the [`Makefile`](../Makefile) treats empty like unset).
