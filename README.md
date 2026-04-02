# go-zetasql

![Go](https://github.com/goccy/go-zetasql/workflows/Go/badge.svg)
[![GoDoc](https://godoc.org/github.com/goccy/go-zetasql?status.svg)](https://pkg.go.dev/github.com/goccy/go-zetasql?tab=doc)

Go bindings for [ZetaSQL](https://github.com/google/zetasql)

ZetaSQL can parse all queries related to Cloud Spanner and BigQuery. This functionality is provided from the Go language using cgo. 

# Features

- No need to install ZetaSQL library
  - go-zetasql contains all the source code needed to build ZetaSQL and builds at `go get github.com/goccy/go-zetasql` timing. Therefore, there is no need to install dependent libraries separately.

- Can create a portable single binary even though it using cgo
  - You can create a static binary even with `CGO_ENABLED=1` by specifying the following options at build time: `--ldflags '-extldflags "-static"'`

- Can access all the APIs of the ZetaSQL parser
  - The ZetaSQL parser is not publicly available, but it is available in go-zetasql

- Can access analyzer APIs

# Status

In the features of ZetaSQL, you can use the functions of the following packages. Will be added sequentially.

| Package        | Supported  |
| ----           | ----       |
| parser         | yes        |
| public         | partial    |
| analyzer       | yes        |
| scripting      | no         |
| reference_impl | no         |

# Prerequisites

go-zetasql uses cgo. Therefore, `CGO_ENABLED=1` is required to build.  
Also, the compiler recommends `clang++`. Please set `CXX=clang++` to install.

|  Environment Name |  Value                   |
| ----              | ----                     |
|  CGO_ENABLED      |  1  ( required )         |
|  CXX              |  clang++ ( recommended ) |

# Installation

```
go get github.com/goccy/go-zetasql
```

The first time you run it, it takes time to build all the ZetaSQL code used by go-zetasql.

## Development

**Sequential tests (multi-repo):** If you work in `go-zetasql`, `go-zetasqlite`, and `bigquery-emulator` together, run heavy `go test` **one repo at a time**. Running full CGO test suites in parallel on one machine often exhausts memory.

**Reuse local compile cache:** Point the same Go caches at all three checkouts so `go-zetasql` objects are not rebuilt for every downstream test:

```console
export GOCACHE=$HOME/.cache/go-zetasql-stack
export GOMODCACHE=$HOME/.cache/go-mod
mkdir -p "$GOCACHE" "$GOMODCACHE"
```

Then run tests with `CGO_ENABLED=1 CC=clang CXX=clang++` as usual.

**Docker-based tests (recommended):** Use **`make test`** or **`make test/linux`** — this builds a slim **`go-zetasql:dev`** image (**`--target dev`**: Go + clang + **ccache** only; no module compile in the image build) and runs **`go test`** with your **working tree** and **`GO_CACHE_ROOT`** (default **`~/.cache/go-zetasql`**) bind-mounted as **`gocache/`**, **`gomodcache/`**, and **`ccache/`** (Clang object cache for CGO). After a cold cache or toolchain change, run **`make docker/warm-cache`** once: it runs **`go test -race`** with **`-run '^$'`** (matches no tests) so you **pre-compile** the same **`-race`** graph without executing tests; later **`test/linux`** stays much faster. Set **`TESTPKG=./...`** to widen scope. **`go-zetasqlite`** and **`bigquery-emulator`** **`make test/linux`** use the same **`GO_CACHE_ROOT`** so the stack shares one warm cache. Host-only **`make local/build`** / **`local/test`** use the same default tree. Rebuild **`go-zetasql:dev`** after Dockerfile changes (**`make docker/build-dev`**). The default **`docker build`** (release image) still runs **`go install`** with BuildKit cache mounts for registry builds; that path is separate from local test caches.

**Downstream Docker images:** `bigquery-emulator` accepts `GO_ZETASQL_BASE` (default: the Recidiviz base image). After building `go-zetasql:dev`, you can point the emulator at it, for example:

```console
# in bigquery-emulator/
make docker/build GO_ZETASQL_BASE=go-zetasql:dev
```

# Editor Tips

Opening this repository in VS Code or Cursor can be expensive because the Go extension loads a large CGO-backed package graph.

- Open `go-zetasql.code-workspace` when you only need this repository. This avoids indexing sibling repositories in the same window.
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
  "github.com/goccy/go-zetasql"
  "github.com/goccy/go-zetasql/ast"
)

func main() {

  stmt, err := zetasql.ParseStatement("SELECT * FROM Samples WHERE id = 1", nil)
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

  "github.com/goccy/go-zetasql"
  "github.com/goccy/go-zetasql/ast"
)

func main() {

  stmt, err := zetasql.ParseStatement("SELECT * FROM Samples WHERE id = 1", nil)
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

  "github.com/goccy/go-zetasql"
  "github.com/goccy/go-zetasql/resolved_ast"
  "github.com/goccy/go-zetasql/types"
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
  catalog.AddZetaSQLBuiltinFunctions()
  out, err := zetasql.AnalyzeStatement("SELECT * FROM Samples WHERE id = 1000", catalog, nil)
  if err != nil {
    panic(err)
  }

  // get statement node from zetasql.AnalyzerOutput.
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

Since go-zetasql builds all source code including dependencies at install time, it directly contains the source code of the following libraries. Therefore, the license is set according to the license of the dependent library.

- [zetasql](https://github.com/google/zetasql): [Apache License 2.0](https://github.com/google/zetasql/blob/master/LICENSE)
- [abseil](https://github.com/abseil/abseil-cpp): [Apache License 2.0](https://github.com/abseil/abseil-cpp/blob/master/LICENSE)
- [json](https://github.com/nlohmann/json): [MIT License](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT)
- [re2](https://github.com/google/re2): [BSD 3-Clause](https://github.com/google/re2/blob/main/LICENSE)
- [boringssl](https://github.com/google/boringssl): [ISC License](https://github.com/google/boringssl/blob/master/LICENSE)
- [protobuf](https://github.com/protocolbuffers/protobuf): [License](https://github.com/protocolbuffers/protobuf/blob/master/LICENSE)
- [icu](https://github.com/unicode-org/icu): [ICU License](https://github.com/unicode-org/icu/blob/main/icu4c/LICENSE)
- [farmhash](https://github.com/google/farmhash): [MIT License](https://github.com/google/farmhash/blob/master/COPYING)
- [googletest](https://github.com/google/googletest): [BSK 3-Clause](https://github.com/google/googletest/blob/main/LICENSE)
