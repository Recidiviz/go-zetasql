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
