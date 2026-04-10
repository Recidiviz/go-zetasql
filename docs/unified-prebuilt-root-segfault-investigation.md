# Unified-prebuilt root runtime segfault — investigation notes

This document records the staged repro and GDB classification for
`make local/test-prebuilt-googlesql-unified-root` after Abseil **link** issues were resolved.
The failure mode is **runtime SIGSEGV**, not missing symbols at link time.

## Staged repro (link vs execute)

With the same toolchain as
[`Makefile`](../Makefile) `local/test-prebuilt-googlesql-unified-root` (`CGO_CXXFLAGS_PREBUILT`,
`CGO_LDFLAGS_BASE`, `CC`/`CXX`, `GOCACHE`/`GOMODCACHE`):

| Step | Command | Result |
|------|---------|--------|
| Compile + link only | `go test -tags googlesql,googlesql_unified_prebuilt -c -o /tmp/googlesql_root_prebuilt.test ./` | OK |
| Link, do not run binary | `go test -tags googlesql,googlesql_unified_prebuilt -count=1 -run '^$' -exec /bin/true ./` | OK |
| Run process, zero tests | `go test -tags googlesql,googlesql_unified_prebuilt -count=1 -run '^$' -v ./` | **SIGSEGV** |

**Conclusion:** the crash happens when the test **process starts** (dynamic init / `init` / C++
static constructors), **before** any `Test*` runs. `go test -list` also crashes for the same
reason.

## Test bisect

Because the crash occurs before test enumeration, filtering `-run '^TestFoo$'` does not isolate a
single test — all such invocations still load the same binary and hit the same startup path.

## Native / import chain (high level)

`go list -tags googlesql,googlesql_unified_prebuilt -deps ./` shows the root package pulling CGO
shards including (order not strict): `cctz/time_zone`, `googlesqlunified`, `utf8_range_link`,
`protobuf`, `bison_parser_generated_lib`, `parser`, `analyzer`, then `go-googlesql` and app packages.

## GDB backtrace (representative)

```text
Program received signal SIGSEGV, Segmentation fault.
0x... in absl::lts_20240722::container_internal::GroupSse2Impl::GroupSse2Impl(ctrl_t const*)
...
google::protobuf::DescriptorPool::Tables::Tables()
google::protobuf::DescriptorPool::DescriptorPool(...)
google::protobuf::(anonymous namespace)::NewGeneratedPool()
google::protobuf::DescriptorPool::internal_generated_pool()
google::protobuf::DescriptorPool::InternalAddGeneratedFile(...)
google::protobuf::internal::AddDescriptors(...)
__cxx_global_var_init
global constructors keyed to ...
__libc_start_main
_start
```

**Fault domain (classification):**

1. **Protobuf generated-descriptor static registration** — `AddDescriptors` /
   `InternalAddGeneratedFile` during C++ `__cxx_global_var_init`.
2. **Abseil SwissTable / raw_hash_set** — crash inside `GroupSse2Impl` while building
   `DescriptorPool::Tables` (flat hash map for well-known type names).

This is **not** tied to a specific Go test body. Next fixes should target **why** that table
construction fails at startup (e.g. invalid `ctrl_t*`, duplicate descriptor registration / multiple
protobuf runtime images, or header/runtime skew), not individual root `*_test.go` cases.

## Commands reference

```bash
# Build test binary
go test -tags googlesql,googlesql_unified_prebuilt -c -o /tmp/googlesql_root_prebuilt.test ./

# GDB backtrace at crash
gdb -q -batch -ex 'run -test.run ^$ -test.v' -ex 'thread apply all bt' /tmp/googlesql_root_prebuilt.test
```

## Resolution (2026)

**Root cause:** mixed C++ standard libraries in the same process. `ldd` on the unified-prebuilt
test binary showed `libstdc++.so.6` while `libprotobuf_cgo.a` and `libgooglesql.a` objects are built
with **libc++** (`std::__1::`, Bazel LLVM). `internal/ccall/utf8_range_link/bind_linux.go` used
`-lstdc++`; the external link also defaulted to libstdc++ until `CGO_LDFLAGS_BASE` gained
`-stdlib=libc++` (see [`Makefile`](../Makefile)). Linking `utf8_range_link` against
`libcxx_prebuilt.a` / `libcxxabi_prebuilt.a` (same as [`go-protobuf/protobuf/bind_linux.go`](../internal/ccall/go-protobuf/protobuf/bind_linux.go)) removes the extra libstdc++ load.

**Archive hygiene:** [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh) now filters out Abseil/protobuf/utf8_range `*.pic.o` paths so
`libgooglesql.a` does not embed duplicate ELF definitions of the same runtime as
`libprotobuf_cgo.a` (weak-symbol overlap is expected; **global `T`** overlap should stay zero —
`make verify-prebuilt-googlesql-unified` checks this when `llvm-nm` and `libprotobuf_cgo.a` exist).

**Unified prebuilt CGO shards:** generated `bind_unified_prebuilt_linux.go` now adds
`-L.../go-protobuf/protobuf/lib` and `-l:libcxx_prebuilt.a` / `-l:libcxxabi_prebuilt.a` so
per-package cgo links match the protobuf archive (see `bindGoParamUnifiedPrebuilt` in
[`internal/cmd/generator/pkg/generator.go`](../internal/cmd/generator/pkg/generator.go)).

**Full repo test `./`:** the top-level [`internal/ccall/go-googlesql/bind.cc`](../internal/ccall/go-googlesql/bind.cc) amalgamation + `export.inc` still hits protobuf static-registration collisions when built as a single TU; the default `make local/test-prebuilt-googlesql-unified-root` target uses
`TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT=./internal/ccall/go-googlesql/public/analyzer/` until the
root bind is split for unified the same way as [`base/status`](../internal/ccall/go-base/status/bind_linux.go) (`//go:build !googlesql_unified_prebuilt` + `bind_unified_prebuilt_linux.go`).

**Update (2026-04):** On a Linux host with `Makefile` `CGO_CXXFLAGS_PREBUILT` / `CGO_LDFLAGS_BASE` (`-stdlib=libc++`), `ldd` on the unified-prebuilt test binary shows **libc++.so.1** and **no libstdc++.so** — so mixed GNU/libstdc++ vs LLVM/libc++ is not the only failure mode.

**Duplicate Abseil cctz / `civil_time_detail` vs `libprotobuf_cgo.a`:** `libprotobuf_cgo.a` merges Abseil `*.pic.o` from Bazel. The same **IANA time_zone** object files and **`civil_time_detail.cc`** body also appear in Go CGO TUs (`internal/ccall/go-absl/time/.../cctz/time_zone`, `civil_time/export.inc`, etc.). With `-Wl,--allow-multiple-definition`, the linker can merge incompatible copies and the process still crashes in `DescriptorPool::Tables` / `GroupSse2Impl` at startup.

Mitigations in-tree:

- [`extract_protobuf_cgo_lib.sh`](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) **drops** Abseil members `time_zone_*.pic.o` and `zone_info_source.pic.o` from the merged `libprotobuf_cgo.a` so the **Go `cctz/time_zone` shard** is the single owner of that implementation.
- [`civil_time/export.inc`](../internal/ccall/go-absl/time/go_internal/cctz/civil_time/export.inc) no longer `#include`s `civil_time_detail.cc`; that TU stays in `libprotobuf_cgo.a` only. The `civil_time` CGO package [blank-imports `go-protobuf/protobuf`](../internal/ccall/go-absl/time/go_internal/cctz/civil_time/bind_linux.go) so out-of-line symbols resolve.
- [`public/analyzer/bridge_cc.inc`](../internal/ccall/go-googlesql/public/analyzer/bridge_cc.inc) uses a uniquely named helper `googlesql_public_analyzer_bridge_slice_to_strs` so link-only root + analyzer shards do not emit two globals named `slice_to_strs` when building **without** `--allow-multiple-definition`.

After these changes, `go test -tags googlesql,googlesql_unified_prebuilt -c ./` can link with **only** `-Wl,--no-gc-sections -fuse-ld=mold -stdlib=libc++` on `CGO_LDFLAGS` (no `--allow-multiple-definition`). **Running** the binary can still **SIGSEGV** at startup with the same GDB shape as above — so duplicate weak/local merging is not the only remaining hypothesis; further work may target descriptor registration / archive skew beyond global `T` overlap.

**Update (2026-04, GDB detail):** On `GroupSse2Impl::GroupSse2Impl`, **`rcx` is `0`** at the faulting `movdqu (%rcx)` — the SwissTable control pointer is null while `DescriptorPool::Tables::Tables()` runs the `well_known_types_.insert({…})` initializer list (see `descriptor.cc` in the vendored tree around `Tables::Tables`). `make verify-prebuilt-googlesql-unified` stays green (zero duplicate global **`T`** vs `libprotobuf_cgo.a`); **`ldd`** shows **libc++** and no **libstdc++**. Linking with **mold**, **bfd**, or **without** `--allow-multiple-definition` still crashes at run time. **Target bisection** (`GOOGLESQL_UNIFIED_BAZEL_TARGETS`) is still a valid next step if a duplicate `google::protobuf` / Abseil object hypothesis resurfaces after further vendor alignment.

## Hypotheses tested (2026-04)

| Hypothesis | Result |
|------------|--------|
| **`CGO_CXXFLAGS` empty** — environment `CGO_CXXFLAGS_PREBUILT=` defeats `?=` so CGO compiles without `-stdlib=libc++`, producing `std::__cxx11::` (libstdc++) symbols against Bazel **libc++** archives | **Confirmed** as a real footgun: link fails with undefined `std::__cxx11::` symbols. **Fix:** [`Makefile`](../Makefile) treats empty `CGO_CXXFLAGS_PREBUILT` like unset (`ifeq ($(strip …),)`) so `make local/*` always passes `-stdlib=libc++`. |
| **gofmt import order vs link order** — a single `import` block is sorted so `go-googlesql-unified` precedes `go-protobuf`, affecting cmd/link cgo LDFLAGS order | **Mitigation added:** generator emits **two** import blocks with `go-protobuf/protobuf` first ([`templates/bind.go.tmpl`](../internal/cmd/generator/templates/bind.go.tmpl), `ImportGoLibsLinkOrderFirst`). **Did not** eliminate startup SIGSEGV on `make local/test-root-unified` in the tested environment. |
| **`-lgooglesql` before `-lprotobuf_cgo`** — move `-lgooglesql` to tail of `CGO_LDFLAGS` only | **Tried** (then reverted): appending `-lgooglesql` via `Makefile` and/or stripping `#cgo` `-lgooglesql` from `googlesqlunified` did **not** stop the crash; restoring the original `googlesqlunified` `#cgo` LDFLAGS. |
| **`llvm-nm` on `.test`** | `DescriptorPool::Tables::Tables` appears as **local** `t` (duplicate lines at same address from COMDAT); no obvious second **global** `T` definition for the pool in the final binary beyond the archive-level check. |
| **Abseil `lts` tag mismatch** between `libgooglesql.a` and `libprotobuf_cgo.a` | **Strings** show **`lts_20240722`** in both — no obvious mixed Abseil era. |

**Still open:** same GDB stack (`Tables::Tables` → `GroupSse2Impl`) after correct `-stdlib=libc++` and protobuf-first imports; likely duplicate descriptor/static-init interaction between **link-only root `bind.cc`** TU and **`libgooglesql.a`**, or linker **`.init_array`** ordering — needs deeper bisect (targets) or bind split per [`docs/link-only-cgo-migration.md`](link-only-cgo-migration.md).
