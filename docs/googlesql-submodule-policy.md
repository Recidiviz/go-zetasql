# GoogleSQL submodule policy (read-only upstream)

The Git submodule at [`internal/cmd/updater/googlesql`](../internal/cmd/updater/googlesql) tracks **[google/googlesql](https://github.com/google/googlesql)** release tags.

## Rules

1. **Checkout upstream tags only** — Inside the submodule, `git checkout <YYYY.MM.P>` for the release you are upgrading to. The parent repo’s submodule pointer should reference **that tag’s commit** (verify with `git -C internal/cmd/updater/googlesql describe --tags --exact-match` when HEAD is at the tag).

2. **No extra commits in the submodule** — Do not cherry-pick, rebase, or maintain a “vendor branch” on top of the tag. You do not need push access to a fork: the submodule remote stays the public upstream. The parent repo’s gitlink must point at the **tag commit**, not a later upstream `main` revision (verify with `git -C internal/cmd/updater/googlesql describe --tags --exact-match`). After running Bazel inside the submodule, remove untracked artifacts (for example `MODULE.bazel.lock`) so `git status` in the submodule stays clean.

3. **Embedding-specific fixes live in the parent repo** — Changes needed only for go-googlesql’s CGO amalgamation (for example **status payload** handling when protobuf descriptors are not initialized in a shard, **flex** post-copy tweaks, or other build-integration edits) belong **after** the updater copies sources into **`internal/ccall/`**, or in automation that runs on the parent tree:
   - [`internal/cmd/updater/main.go`](../internal/cmd/updater/main.go) (`applyPostCopyOverlays` and related),
   - [`go run ./internal/cmd/vendorpatch`](../internal/cmd/vendorpatch/main.go) and [`scripts/apply-vendor-patches.sh`](../scripts/apply-vendor-patches.sh),
   - committed patches under [`internal/ccall/protobuf/patches/`](../internal/ccall/protobuf/patches/README.md) where appropriate (see [`protobuf-vendoring.md`](protobuf-vendoring.md)).

   Typical GoogleSQL paths that have needed CGO-specific care in the past include `googlesql/public/error_helpers.cc`, `googlesql/base/status_payload.h`, and `googlesql/common/status_payload_utils.h`—**edit the copies under `internal/ccall/googlesql/`** (or the mechanism that produces them), not the submodule working tree.

4. **Historical docs** — Older `docs/googlesql-upgrade-delta-*.md` notes may mention cherry-picking into the submodule; that workflow is **retired** in favor of this policy.

## Related

- Stack upgrade runbook: [`.cursor/commands/googlesql-stack-upgrade.md`](../.cursor/commands/googlesql-stack-upgrade.md)
- Debug and test discipline: [`.cursor/skills/googlesql-stack-debug/SKILL.md`](../.cursor/skills/googlesql-stack-debug/SKILL.md)
- Protobuf / vendor layering: [`protobuf-vendoring.md`](protobuf-vendoring.md)
