# Bridge generator: regen, orphan packages, and API drift

This complements [googlesql-submodule-policy.md](googlesql-submodule-policy.md) and [link-only-cgo-migration.md](link-only-cgo-migration.md).

## When to run the generator

After changing any of:

- [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml) — `cclib`, `global_symbols`, `inject_replace_names`, etc.
- [`internal/cmd/generator/bridge.yaml`](../internal/cmd/generator/bridge.yaml) — C++ methods exposed to Go
- [`internal/cmd/generator/import.yaml`](../internal/cmd/generator/import.yaml) — import-side packages

run from [`internal/cmd/generator`](../internal/cmd/generator) (nested Go module):

```bash
cd internal/cmd/generator && go run .
```

The generator rewrites `internal/ccall/go-googlesql/**` bind/bridge outputs for every `cc_library` / `cc_proto_library` parsed from `internal/ccall/googlesql/**/BUILD`. It also runs a post-check that rejects **stale `zetasql_*` FQDN include guards** (legacy prefix before `mapBazelRootToCcallPath` normalization). Namespace token lines such as `#define zetasql googlesql_…` are still allowed.

## Submodule tag bumps and `bridge.yaml` / `import.yaml`

1. Pin [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) to an upstream **release tag** (see submodule policy).
2. Refresh `internal/ccall/googlesql` via your updater/copy flow so BUILD files match the tag.
3. If public C++ APIs used by Go change (new methods, signature changes), update **`bridge.yaml`** (and **`import.yaml`** if needed), then `go run .` as above.
4. Verify with `task test:local` or narrow `go test` with `googlesql,googlesql_unified_prebuilt` (see [Taskfile.yml](../Taskfile.yml)).

Linker or compile errors in CGO packages usually mean bridge entries no longer match headers—diff the relevant `googlesql/.../*.h` in `internal/ccall/googlesql` against the methods listed in `bridge.yaml`.

## Orphan `go-googlesql` directories

If a directory under `internal/ccall/go-googlesql/` contains `bind.cc` but **no** corresponding `cc_library` exists in `internal/ccall/googlesql/**/BUILD`, it is **stale** (old generator output). List them:

```bash
cd internal/cmd/generator && go run . -orphan-dirs
```

Remove orphan trees (and any blank imports in `base/base.go`, `common/common.go`, or hand-maintained `export_deps.inc` that pointed at them), then run `go run .` again.

## Manual checks

```bash
cd internal/cmd/generator && go run . -list-packages   # expected go-googlesql paths from BUILD
cd internal/cmd/generator && go run . -verify-zetasql-fqdn   # stale FQDN guards only; no full regen
```

[`scripts/ccall-bridge-verify.sh`](../scripts/ccall-bridge-verify.sh) runs the verify step for CI or pre-commit.
