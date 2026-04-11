# go-googlesql

![Go](https://github.com/vantaboard/go-googlesql/workflows/Go/badge.svg)
[![GoDoc](https://godoc.org/github.com/vantaboard/go-googlesql?status.svg)](https://pkg.go.dev/github.com/vantaboard/go-googlesql?tab=doc)

Go bindings for [GoogleSQL](https://github.com/google/googlesql)

GoogleSQL can parse all queries related to Cloud Spanner and BigQuery. This functionality is provided from the Go language using cgo. 

# Features

- No need to install GoogleSQL as a separate system library
  - The repository vendors GoogleSQL sources and CGO bindings. **Supported development and releases** rely on **prebuilt static archives** (`libprotobuf_cgo.a`, `libgooglesql.a` under unified prebuilt) and **link-only** CGO — see [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md) and [`docs/link-only-cgo-migration.md`](docs/link-only-cgo-migration.md). A full source compile path may still exist during transition but is **deprecated** as a long-term mode.

- Can create a portable single binary even though it using cgo
  - You can create a static binary even with `CGO_ENABLED=1` by specifying the following options at build time: `--ldflags '-extldflags "-static"'`

- Can access all the APIs of the GoogleSQL parser
  - The GoogleSQL parser is not publicly available, but it is available in go-googlesql

- Can access analyzer APIs

# Status

In the features of GoogleSQL, you can use the functions of the following packages. Will be added sequentially.

| Package        | Supported  |
| ----           | ----       |
| parser         | yes        |
| public         | partial    |
| analyzer       | yes        |
| scripting      | no         |
| reference_impl | no         |

# Prerequisites

go-googlesql uses cgo. Therefore, `CGO_ENABLED=1` is required to build.  
Also, the compiler recommends `clang++`. Please set `CXX=clang++` to install.

|  Environment Name |  Value                   |
| ----              | ----                     |
|  CGO_ENABLED      |  1  ( required )         |
|  CXX              |  clang++ ( recommended ) |

## Build modes (quick reference)

**Supported direction:** **`googlesql` + `googlesql_unified_prebuilt`**, Bazel-built **`libgooglesql.a`** + **`libprotobuf_cgo.a`**, and **link-only** CGO binds — minimal native linkage, not fat single-TU amalgamation. See [`docs/link-only-cgo-migration.md`](docs/link-only-cgo-migration.md).

| Mode | Build tags | Bazel needed? | Notes |
|------|------------|---------------|--------|
| **Default protobuf prebuilt** | `googlesql` (typical) | **Yes** to *produce* `libprotobuf_cgo.a`; **no** if you use a [release tarball](docs/prebuilt-cgo.md#release-tarballs-linux_amd64) | Default protobuf path. Links `libprotobuf_cgo.a`; set `CGO_CXXFLAGS=-stdlib=libc++` as in [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md). |
| **Deprecated compatibility alias** | `googlesql,googlesql_tier_b` | Same as default | Kept only so older scripts still resolve to the same default protobuf prebuilt behavior. |
| **Tier B Abseil (pilot)** | `googlesql,googlesql_tier_b_absl` | Yes to build `libabsl_cgo.a` | Use only for isolated `go-absl` pilot packages; do **not** combine with the default protobuf prebuilt owner in one link — [`docs/prebuilt-absl-overlap.md`](docs/prebuilt-absl-overlap.md). |
| **Unified `libgooglesql.a` (bootstrap)** | `googlesql,googlesql_unified_prebuilt` | Yes for Bazel extract | **Primary path** for GoogleSQL C++ in Go: [`docs/libgooglesql-unified.md`](docs/libgooglesql-unified.md). |
| **Deprecated — fat amalgamation (non-unified)** | `googlesql` without `googlesql_unified_prebuilt` | Varies | Legacy `//go:build !googlesql_unified_prebuilt` binds; **deprecated**, not co-equal with unified prebuilt. May still appear in transitional CI. |

**Removed path:** protobuf amalgamation is no longer the supported/default CGO build mode in this repo. The normal Linux/Darwin protobuf bind files now link the prebuilt archive. Deeper context: [`docs/native-build-pipeline.md`](docs/native-build-pipeline.md).

**Contributor quick path (prebuilts):** clone → unpack release assets (or run `make prebuilt-libs` and unified extract targets as in [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md)) → prefer **`make local/test-root-unified`** (or `go test` with `-tags googlesql,googlesql_unified_prebuilt`). Legacy **`make local/test`** / `go test -tags googlesql` without unified prebuilt is **deprecated** for long-term work but may still match some CI until migration completes. CI cache layout for Bazel: [`docs/ci-bazel-cache.md`](docs/ci-bazel-cache.md).

# Installation

```
go get github.com/vantaboard/go-googlesql
```

The first time you run it, it takes time to build all the GoogleSQL code used by go-googlesql.

## Development

**Fast path (stack work):** `make docker/build-dev` in this repo → optional `make docker/warm-cache` → use the same **`GO_CACHE_ROOT`** (default `~/.cache/go-googlesql`) when running **`make test/linux`** in sibling checkouts **`go-googlesqlite`** and **`bigquery-emulator`**. Those READMEs document **`GO_CACHE_ROOT`**, **ccache**, **mold** (Linux), and optional warm-up for host and Docker workflows.

**Sequential tests (multi-repo):** If you work in `go-googlesql`, `go-googlesqlite`, and `bigquery-emulator` together, run heavy `go test` **one repo at a time**. Running full CGO test suites in parallel on one machine often exhausts memory.

**Host `go test` memory cap (systemd):** [`scripts/cgo-go.sh`](scripts/cgo-go.sh) optionally wraps `go build` / `go test` in a user or system scope with **`GOOGLESQL_CGO_MEMORY_MAX`** (default `22G`). If you still have automation using **`ZETASQL_CGO_MEMORY_MAX`**, rename it—only **`GOOGLESQL_CGO_MEMORY_MAX`** is read now.

**Reuse local compile cache:** Point the same Go caches at all three checkouts so `go-googlesql` objects are not rebuilt for every downstream test:

```console
export GOCACHE=$HOME/.cache/go-googlesql-stack
export GOMODCACHE=$HOME/.cache/go-mod
mkdir -p "$GOCACHE" "$GOMODCACHE"
```

Then run tests with `CGO_ENABLED=1 CC=clang CXX=clang++` as usual.

**GitHub Actions** uses **`ccache clang`** / **`ccache clang++`** with a persisted **`CCACHE_DIR`** so CI gets incremental C++ compiles across runs, similar in spirit to **`make local/build`**.

**Mold (Linux):** The **`go-googlesql:dev`** image installs **`mold`** and sets **`CGO_LDFLAGS=-fuse-ld=mold`**. On Linux hosts, if **`mold`** is on **`PATH`**, **`make local/build`** / **`local/test-root-unified`** (and legacy **`local/test`**) pass the same flag for faster linking.

**Rough cold vs warm timing:** **`make profile-bottleneck`** runs two **`go test -c`** passes and prints **`ccache -s`** (install **`ccache`** locally for stats). Uses **`TESTPKG`** like other targets.

**Default Bazel protobuf archive (Linux/macOS):** **`make extract-protobuf-lib`** (alias **`make prebuilt-libs`**) runs [`internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh`](internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) and produces the default protobuf archive used by **`bind_linux.go`** / **`bind_darwin.go`**.

**Default protobuf prebuilt path:** After **`make prebuilt-libs`**, use **`make local/build`** with **`-tags googlesql`** (requires **`libprotobuf_cgo.a`** under [`internal/ccall/go-protobuf/protobuf/lib/`](internal/ccall/go-protobuf/protobuf/)). For the **supported** unified stack, add prebuilt GoogleSQL + **`make local/test-root-unified`** per [`docs/link-only-cgo-migration.md`](docs/link-only-cgo-migration.md). Legacy **`make local/test`** without unified tags is **deprecated** long term. **`make verify-prebuilt-protobuf`** fails fast if the archive is missing. **`make verify-protobuf-tier-b-alignment`** warns when vendored protobuf is still below the Bazel 29.x line (use **`make sync-protobuf-vendor-from-bazel`** + **`go run ./internal/cmd/vendorpatch`** + **`make regenerate-googlesql-cpp-protos`** to align). Full details: [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md), [`docs/native-build-pipeline.md`](docs/native-build-pipeline.md), [`docs/link-only-cgo-migration.md`](docs/link-only-cgo-migration.md). Install-prefix / **pkg-config** template: [`contrib/googlesql.pc.example`](contrib/googlesql.pc.example). Set **`GOOGLESQL_PREBUILT_PREFIX`** when using a consolidated prefix (documented in the `.pc` example); protobuf prebuilts currently use fixed paths under `go-protobuf/protobuf/lib/`.

**Prebuilt Abseil (experimental):** **`make prebuilt-libs-absl`** builds **`libabsl_cgo.a`** under [`internal/ccall/go-absl/lib/`](internal/ccall/go-absl/). **`make local/test-prebuilt-absl`** runs **`go test`** on the migrated packages (default: **`meta/type_traits`**, **`base/config`**, **`utility/utility`**) with **`-tags googlesql,googlesql_tier_b_absl`**. Read [`docs/prebuilt-absl-overlap.md`](docs/prebuilt-absl-overlap.md) before combining with the default protobuf prebuilt owner. **Tag matrix / mutual exclusion:** do not mix the default protobuf prebuilt owner and **`googlesql_tier_b_absl`** in one binary unless the final link is known not to import `go-protobuf`. **`make verify-tier-b-cgo-policy`** prints the same policy for CI and local preflight.

**Downstream (`go-googlesqlite`, `bigquery-emulator`):** Keep **`replace`** pointed at the same checkout where you ran **`make prebuilt-libs`** / **`make prebuilt-libs-absl`**, and pass the **same** **`-tags`** (plus matching **`CGO_*`** / **`Makefile`-style** `CGO_LDFLAGS_ALLOW`) when using the default protobuf prebuilt path; see [`docs/prebuilt-cgo.md`](docs/prebuilt-cgo.md#downstream-repositories).

**Unified GoogleSQL prebuilt (root slice):** `make prebuilt-libs-googlesql-unified` builds `libgooglesql.a` for parser + analyzer + catalog + simple_catalog + sql_formatter, in addition to the proto/base closure. CI (see [`.github/workflows/go-googlesql-unified-prebuilt.yml`](.github/workflows/go-googlesql-unified-prebuilt.yml)) runs `make prebuilt-libs` first ( **`libprotobuf_cgo.a`** is gitignored), then `make prebuilt-libs-googlesql-unified` → `make verify-prebuilt-googlesql-unified` → `make local/build-prebuilt-googlesql-unified` → `make local/build-prebuilt-googlesql-unified-root` → `make local/test-prebuilt-googlesql-unified-root` (default **`public/analyzer`** test package) → `bash scripts/smoke_link_googlesql_unified.sh`. For local experiments, `GOOGLESQL_UNIFIED_BAZEL_TARGETS` overrides the archive label list and `GOOGLESQL_UNIFIED_GOPROXY` overrides the extractor's Bazel module proxy. See [`docs/libgooglesql-unified.md`](docs/libgooglesql-unified.md), [`docs/link-only-cgo-migration.md`](docs/link-only-cgo-migration.md), and [`contrib/googlesql.pc.example`](contrib/googlesql.pc.example) / [`Dockerfile.prebaked`](Dockerfile.prebaked) for the longer-term consolidated install-prefix story.

**Docker-based tests (recommended):** Use **`make test`** or **`make test/linux`** — this builds a slim **`go-googlesql:dev`** image (**`--target dev`**: Go + clang + **ccache** only; no module compile in the image build) and runs **`go test`** with your **working tree** and **`GO_CACHE_ROOT`** (default **`~/.cache/go-googlesql`**) bind-mounted as **`gocache/`**, **`gomodcache/`**, and **`ccache/`** (Clang object cache for CGO). After a cold cache or toolchain change, run **`make docker/warm-cache`** once: it runs **`go test -race`** with **`-run '^$'`** (matches no tests) so you **pre-compile** the same **`-race`** graph without executing tests; later **`test/linux`** stays much faster. Set **`TESTPKG=./...`** to widen scope. **`go-googlesqlite`** and **`bigquery-emulator`** **`make test/linux`** use the same **`GO_CACHE_ROOT`** so the stack shares one warm cache. Host-only **`make local/build`** / **`local/test-root-unified`** (or legacy **`local/test`**) use the same default tree. Rebuild **`go-googlesql:dev`** after Dockerfile changes (**`make docker/build-dev`**). The default **`docker build`** (release image) still runs **`go install`** with BuildKit cache mounts for registry builds; that path is separate from local test caches.

**Downstream Docker images:** `bigquery-emulator` accepts `GO_GOOGLESQL_BASE` (default: the Recidiviz base image). After building `go-googlesql:dev`, you can point the emulator at it, for example:

```console
# in bigquery-emulator/
make docker/build GO_GOOGLESQL_BASE=go-googlesql:dev
```

# Editor Tips

Opening this repository in VS Code or Cursor can be expensive because the Go extension loads a large CGO-backed package graph.

- Open `go-googlesql.code-workspace` when you only need this repository. This avoids indexing sibling repositories in the same window.
- The repository includes `.vscode/settings.json` with conservative Go extension defaults for this module:
  - disables build, lint, and vet on save
  - reduces `gopls` background work
  - excludes large vendored C++ trees from search and file watching
- If you still see high memory use, disable the Go extension for this workspace when you are only reading generated binding code.

# Synopsis

## Parse SQL statement

```go
package main

import (
  "github.com/vantaboard/go-googlesql"
  "github.com/vantaboard/go-googlesql/ast"
)

func main() {

  stmt, err := googlesql.ParseStatement("SELECT * FROM Samples WHERE id = 1", nil)
  if err != nil {
    panic(err)
  }

  // use type assertion and get concrete nodes.
  queryStmt := stmt.(*ast.QueryStatementNode)
}
```

If you want to know the specific node of ast.Node, you can traverse by using ast.Walk.

```go
package main

import (
  "fmt"

  "github.com/vantaboard/go-googlesql"
  "github.com/vantaboard/go-googlesql/ast"
)

func main() {

  stmt, err := googlesql.ParseStatement("SELECT * FROM Samples WHERE id = 1", nil)
  if err != nil {
    panic(err)
  }

  // traverse all nodes of stmt.
  ast.Walk(stmt, func(n ast.Node) error {
    fmt.Printf("node: %T loc:%s\n", n, n.ParseLocationRange())
    return nil
  })
}
```

## Analyze SQL statement

If you have table information, you can use the analyzer API by using it as a Catalog.
By using analyzer API, you can parse SQL based on table information and output normalized node.
If you want to know the specific node of resolved_ast.Node, you can traverse by using resolved_ast.Walk.

```go
package main

import (
  "fmt"

  "github.com/vantaboard/go-googlesql"
  "github.com/vantaboard/go-googlesql/resolved_ast"
  "github.com/vantaboard/go-googlesql/types"
)

func main() {
  const tableName = "Samples"
  catalog := types.NewSimpleCatalog("catalog")
  catalog.AddTable(
    types.NewSimpleTable(tableName, []types.Column{
      types.NewSimpleColumn(tableName, "id", types.Int64Type()),
      types.NewSimpleColumn(tableName, "name", types.StringType()),
    }),
  )
  catalog.AddGoogleSQLBuiltinFunctions()
  out, err := googlesql.AnalyzeStatement("SELECT * FROM Samples WHERE id = 1000", catalog, nil)
  if err != nil {
    panic(err)
  }

  // get statement node from googlesql.AnalyzerOutput.
  stmt := out.Statement()

  // traverse all nodes of stmt.
  if err := resolved_ast.Walk(stmt, func(n resolved_ast.Node) error {
    fmt.Printf("%T\n", n)
    return nil
  }); err != nil {
    panic(err)
  }
}
```


Also, you can use the `node.DebugString()` API to dump the result of resolved_ast.Node.
This helps to understand all nodes of statement.

```go
stmt := out.Statement()
fmt.Println(stmt.DebugString())
```

# License

Apache-2.0 License

Since go-googlesql builds all source code including dependencies at install time, it directly contains the source code of the following libraries. Therefore, the license is set according to the license of the dependent library.

- [GoogleSQL (upstream)](https://github.com/google/googlesql): [Apache License 2.0](https://github.com/google/googlesql/blob/master/LICENSE)
- [abseil](https://github.com/abseil/abseil-cpp): [Apache License 2.0](https://github.com/abseil/abseil-cpp/blob/master/LICENSE)
- [json](https://github.com/nlohmann/json): [MIT License](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT)
- [re2](https://github.com/google/re2): [BSD 3-Clause](https://github.com/google/re2/blob/main/LICENSE)
- [boringssl](https://github.com/google/boringssl): [ISC License](https://github.com/google/boringssl/blob/master/LICENSE)
- [protobuf](https://github.com/protocolbuffers/protobuf): [License](https://github.com/protocolbuffers/protobuf/blob/master/LICENSE)
- [icu](https://github.com/unicode-org/icu): [ICU License](https://github.com/unicode-org/icu/blob/main/icu4c/LICENSE)
- [farmhash](https://github.com/google/farmhash): [MIT License](https://github.com/google/farmhash/blob/master/COPYING)
- [googletest](https://github.com/google/googletest): [BSK 3-Clause](https://github.com/google/googletest/blob/main/LICENSE)
