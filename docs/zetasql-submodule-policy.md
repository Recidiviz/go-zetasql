# ZetaSQL submodule policy (read-only upstream)

The Git submodule at [`internal/cmd/updater/zetasql`](../internal/cmd/updater/zetasql) tracks **[google/zetasql](https://github.com/google/zetasql)** release tags.

## Rules

1. **Checkout upstream tags only** — Inside the submodule, `git checkout <YYYY.MM.P>` for the release you are upgrading to. The parent repo’s submodule pointer should reference **that tag’s commit** (verify with `git -C internal/cmd/updater/zetasql describe --tags --exact-match` when HEAD is at the tag).

2. **No extra commits in the submodule** — Do not cherry-pick, rebase, or maintain a “vendor branch” on top of the tag. You do not need push access to a fork: the submodule remote stays the public upstream.

3. **Embedding-specific fixes live in the parent repo** — Changes needed only for go-zetasql’s CGO amalgamation (for example **status payload** handling when protobuf descriptors are not initialized in a shard, **flex** post-copy tweaks, or other build-integration edits) belong **after** the updater copies sources into **`internal/ccall/`**, or in automation that runs on the parent tree:
   - [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) (`applyPostCopyOverlays` and related),
   - [`go run ./internal/cmd/vendorpatch`](../internal/cmd/vendorpatch/main.go) and [`scripts/apply-vendor-patches.sh`](../scripts/apply-vendor-patches.sh),
   - committed patches under [`internal/ccall/protobuf/patches/`](../internal/ccall/protobuf/patches/README.md) where appropriate (see [`protobuf-vendoring.md`](protobuf-vendoring.md)).

   Typical ZetaSQL paths that have needed CGO-specific care in the past include `zetasql/public/error_helpers.cc`, `zetasql/base/status_payload.h`, and `zetasql/common/status_payload_utils.h`—**edit the copies under `internal/ccall/zetasql/`** (or the mechanism that produces them), not the submodule working tree.

4. **Historical docs** — Older `docs/googlesql-upgrade-delta-*.md` notes may mention cherry-picking into the submodule; that workflow is **retired** in favor of this policy.

## Related

- Stack upgrade runbook: [`.cursor/commands/zetasql-stack-upgrade.md`](../.cursor/commands/zetasql-stack-upgrade.md)
- Debug and test discipline: [`.cursor/skills/zetasql-stack-debug/SKILL.md`](../.cursor/skills/zetasql-stack-debug/SKILL.md)
- Protobuf / vendor layering: [`protobuf-vendoring.md`](protobuf-vendoring.md)
