# GoogleSQL upstream policy (pinned tag, no submodule)

Upstream **[google/googlesql](https://github.com/google/googlesql)** is **not** a Git submodule in this repo. The release tag is pinned in [`internal/cmd/updater/googlesql.ref`](../internal/cmd/updater/googlesql.ref) (single line, e.g. `2026.01.1`).

## How the workspace is populated

1. **Docker updater (recommended for refreshing `internal/ccall/googlesql`)** — From [`internal/cmd/updater`](../internal/cmd/updater), run **`make update`**: builds a Docker image that clones the pinned tag, runs Bazel, exports artifacts into `internal/cmd/updater/cache/`, then runs **`go run ./internal/cmd/updater`** from the repository root. See [`internal/cmd/updater/Makefile`](../internal/cmd/updater/Makefile) and [`internal/cmd/updater/Dockerfile`](../internal/cmd/updater/Dockerfile).

2. **Host / CI Bazel (prebuilts, scripts)** — Run [`scripts/ensure-googlesql-workspace.sh`](../scripts/ensure-googlesql-workspace.sh) to shallow-clone the same tag into [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) when that directory is missing or needs to match the ref. GitHub Actions runs this after checkout for workflows that invoke Bazel.

## Rules

1. **Upstream release tags only** — Bump [`googlesql.ref`](../internal/cmd/updater/googlesql.ref) to the target **google/googlesql** tag. Do not point at arbitrary `main` commits for releases.

2. **No local commits inside the clone** — The checkout under `internal/cmd/updater/googlesql` should be a clean shallow clone of the tag. Do not cherry-pick or maintain a vendor branch there. After local Bazel runs, you may see untracked files (for example `MODULE.bazel.lock`); do not commit those into go-googlesql—they belong to the upstream workspace only if you were publishing from that clone.

3. **Embedding-specific fixes live in the parent repo** — CGO integration edits belong **after** the updater copies sources into **`internal/ccall/`**, or in automation on this tree:
   - [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) (`applyPostCopyOverlays` and related),
   - [`go run ./internal/cmd/vendorpatch`](../internal/cmd/vendorpatch/main.go) and [`scripts/apply-vendor-patches.sh`](../scripts/apply-vendor-patches.sh),
   - committed patches under [`internal/ccall/protobuf/patches/`](../internal/ccall/protobuf/patches/README.md) where appropriate (see [`protobuf-vendoring.md`](protobuf-vendoring.md)).

   Edit the copies under `internal/ccall/googlesql/`, not files inside the cloned upstream tree that you intend to keep reproducible.

4. **Historical docs** — Older notes may refer to a Git submodule; that workflow is **retired** in favor of `googlesql.ref` + Docker export + `ensure-googlesql-workspace.sh`.

## Related

- Bridge generator regen: [bridge-generator-upgrades.md](bridge-generator-upgrades.md)
- Stack upgrade runbook: [`.cursor/commands/googlesql-stack-upgrade.md`](../.cursor/commands/googlesql-stack-upgrade.md)
- Debug and test discipline: [`.cursor/skills/googlesql-stack-debug/SKILL.md`](../.cursor/skills/googlesql-stack-debug/SKILL.md)
- Protobuf / vendor layering: [`protobuf-vendoring.md`](protobuf-vendoring.md)
