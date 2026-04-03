# Optional git patches (go-zetasql protobuf)

Committed **`*.patch`** files here are applied **in sorted filename order** after
[`ApplyProtobufAmalgamationPatches`](../../../vendorpatch/amalgamation.go) when you run:

- `go run ./internal/cmd/vendorpatch` (repository root), or
- [`scripts/apply-vendor-patches.sh`](../../../../scripts/apply-vendor-patches.sh)

**Requirements:** `git` on `PATH`. Patches must be unified diffs with paths **relative to the repository root** (e.g. `internal/ccall/protobuf/google/protobuf/extension_set.cc`). Prefer numeric prefixes so order is explicit (`01-foo.patch`, `02-bar.patch`).

**Regenerating after a protobuf refresh:** if `git apply` fails, recreate the patch from a clean vendored file, e.g.:

```bash
# edit files under internal/ccall/protobuf/..., then:
git diff -- internal/ccall/protobuf/path/to/file.cc > internal/ccall/protobuf/patches/01-name.patch
```

Or drop the patch if the fix landed upstream. See [docs/protobuf-vendoring.md](../../../../docs/protobuf-vendoring.md).

There are no patches in-tree by default; add them only when you need layered diffs beyond amalgamation guards.
