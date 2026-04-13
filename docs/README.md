# Documentation index (`docs/`)

Use this map to find the right note. **Supported default:** `googlesql` + `googlesql_unified_prebuilt`, Bazel-built **`libprotobuf_cgo.a`** + **`libgooglesql.a`**, link-only generated `bind.cc` — see [link-only-cgo-migration.md](link-only-cgo-migration.md) and [prebuilt-cgo.md](prebuilt-cgo.md).

## Operational / onboarding

| Doc | Purpose |
|-----|---------|
| [prebuilt-cgo.md](prebuilt-cgo.md) | Tags, env, building and verifying archives, release tarballs, downstream repos |
| [link-only-cgo-migration.md](link-only-cgo-migration.md) | Link-only `bind.cc`, generator workflow, verification commands |
| [libgooglesql-unified.md](libgooglesql-unified.md) | `libgooglesql.a` layout, C ABI, Bazel target list, Textmapper gotchas |
| [native-build-pipeline.md](native-build-pipeline.md) | Bazel → static archives, install-prefix sketch, shard rollout history |

## Policy and namespaces

| Doc | Purpose |
|-----|---------|
| [tier-b-absl-protobuf.md](tier-b-absl-protobuf.md) | Default protobuf prebuilts vs `absl`/`google` rename policy, Tier B pilot |
| [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md) | Tag matrix: when `libprotobuf_cgo.a` and `libabsl_cgo.a` must not mix |
| [protobuf-single-owner-inventory.md](protobuf-single-owner-inventory.md) | Why naive “drop amalgamation” failed; scale notes; points to Tier B doc |
| [protobuf-vendoring.md](protobuf-vendoring.md) | Vendored protobuf patches, `vendorpatch`, upgrade runbook |

## Upstream and generator

| Doc | Purpose |
|-----|---------|
| [googlesql-submodule-policy.md](googlesql-submodule-policy.md) | Pinned `googlesql.ref`, Docker updater, no submodule (historical name) |
| [bridge-generator-upgrades.md](bridge-generator-upgrades.md) | When to run `go run ./internal/cmd/generator`, orphan dirs |

## CI and program tracking

| Doc | Purpose |
|-----|---------|
| [ci-bazel-cache.md](ci-bazel-cache.md) | GitHub Actions caches for Go, ccache, Bazel |
| [cgo-consolidation.md](cgo-consolidation.md) | Shard inventory, CI `--check`, open decisions (e.g. GMock binds) |

## Investigation / historical

| Doc | Purpose |
|-----|---------|
| [unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md) | Startup SIGSEGV / libc++ vs libstdc++ / cctz duplicate-TU notes (keep for triage) |

No separate “legacy amalgamation” build path is documented here; the default is unified prebuilts + link-only CGO only.
