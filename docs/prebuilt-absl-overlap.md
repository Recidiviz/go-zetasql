# Abseil prebuilt archive: overlap with `libprotobuf_cgo.a`

**Single Abseil owner:** In any one final link, Abseil object code must come from **either** the objects embedded in the default `libprotobuf_cgo.a` owner **or** from `libabsl_cgo.a` (when using `googlesql_tier_b_absl` in isolated pilot packages), **not both**. The default protobuf prebuilt owner and `googlesql_tier_b_absl` are mutually exclusive until deduplication or a merged archive exists.

**Canonical tag matrix** (base tag `googlesql` is implied for Tier B columns):

| Build tags | Link `libabsl_cgo.a`? | Link `libprotobuf_cgo.a`? | Status |
|------------|------------------------|----------------------------|--------|
| `googlesql` *(default)* | No | Yes | **Supported** — default protobuf prebuilt path. |
| `googlesql_tier_b` | No (Abseil is inside the protobuf archive) | Yes | **Deprecated compatibility alias** — same protobuf prebuilt owner as default. |
| `googlesql_tier_b_absl` | Yes (migrated `go-absl` packages) | No, unless some imported package pulls the default protobuf owner | **Pilot only** — safe only for isolated `go-absl` package sets that do not also link the default protobuf owner. |
| default protobuf owner (with or without `googlesql_tier_b`) **and** `googlesql_tier_b_absl` | Yes + embedded Abseil | Yes | **Unsupported** — duplicate Abseil objects until dedup or one merged archive. |
| `googlesql_unified_prebuilt` | N/A (partial stack) | N/A | **Supported** with constraints; see below and [`libgooglesql-unified.md`](libgooglesql-unified.md). |
| `googlesql_unified_prebuilt` **+** `googlesql_tier_b` and/or careless overlap with Tier B Abseil archives | Risk of duplicate / inconsistent native objects | — | **Unsupported** without an audited single-owner plan. |

CI / local preflight: `make verify-tier-b-cgo-policy` (prints this policy; [`scripts/verify-tier-b-cgo-tag-policy.sh`](../scripts/verify-tier-b-cgo-tag-policy.sh)). Optional future **enforcement** (fail the job if forbidden combinations appear in scripts) may be gated behind `VERIFY_TIER_B_CGO_POLICY_ENFORCE=1` when implemented.

## Finding

`libprotobuf_cgo.a` (from `make prebuilt-libs`) merges Bazel-built protobuf and utf8_range object files. Those objects **include Abseil code** linked into the archive (e.g. `absl::log_internal::*`, `absl::container_internal::*`). A quick check:

```bash
nm internal/ccall/go-protobuf/protobuf/lib/linux_amd64/libprotobuf_cgo.a | grep -E '^[0-9a-f]+ [TtW] _ZN4absl' | head
```

## Policy detail (same matrix as the table above)

The following rows expand the **Canonical tag matrix** with the same rules:

| Build tags | Link `libabsl_cgo.a`? | Notes |
|------------|----------------------|--------|
| Default (`googlesql`) | No | Default protobuf prebuilt path; protobuf archive already embeds Abseil objects. |
| `googlesql_tier_b` only | No (protobuf package still links `libprotobuf_cgo.a`) | Compatibility alias for the same default protobuf owner. |
| `googlesql_tier_b_absl` only | Yes | Use only for isolated pilots and Abseil experiments that do **not** also pull the default protobuf owner into the same binary. |
| default protobuf owner (with or without `googlesql_tier_b`) **and** `googlesql_tier_b_absl` | Risk of **duplicate Abseil symbols** | Not supported until object-level dedup or a single merged archive is implemented. |
| `googlesql_unified_prebuilt` (links [`libgooglesql.a`](../internal/ccall/go-googlesql-unified/lib)) | **GoogleSQL `.o` only** in v1; does **not** replace `libprotobuf_cgo.a` / `libabsl_cgo.a` | See [`libgooglesql-unified.md`](libgooglesql-unified.md). Do not also link overlapping Abseil/protobuf objects without a symbol audit; full analyzer closure should grow inside one Bazel build or a audited merge. |
| `googlesql_unified_prebuilt` **and** `googlesql_tier_b` (or `googlesql_tier_b_absl`) in the **same** link | Risk of **duplicate** native objects or inconsistent Abseil/protobuf copies | Treat like overlapping Tier B archives: prefer **one** prebuilt story per binary until a single merged `libgooglesql.a` (or single CGO owner) covers the full closure. |

Tier B Abseil is validated only for isolated `go-absl` pilot packages that do not also link the default protobuf prebuilt owner. Migrated link-only packages include **`meta/type_traits`**, all nine **`types/*`** shards under [`go-absl/types`](../internal/ccall/go-absl/types), **`base/config`**, **`base/core_headers`**, **`base/endian`**, **`base/errno_saver`**, **`base/prefetch`**, **`utility/utility`** (see [`prebuilt-cgo.md`](prebuilt-cgo.md)).

## If both default protobuf prebuilts and Abseil Tier B must appear in one link (future)

Today this combination is **unsupported** because `libprotobuf_cgo.a` already contains Abseil object code. When a concrete product needs the default protobuf owner and `googlesql_tier_b_absl` in the same binary, pick one of:

1. **Object-level dedup** — merge archives and strip duplicate ELF sections (fragile; needs a maintained symbol manifest).
2. **Single merged static archive** — one Bazel target that owns protobuf + Abseil + utf8_range with a single link line (see [`native-build-pipeline.md`](native-build-pipeline.md) “single owner”).
3. **Single CGO owner package** — one Go package links `-lprotobuf_cgo` (or a renamed unified archive); other packages use `cgo` `// #cgo LDFLAGS:` only if they do not pull a second copy of Abseil.

Defer implementation until there is a real linker failure or CI requirement—not for hypothetical builds.

**Checklist when duplicate Abseil symbols appear at link time**

1. Identify which archives contribute the symbol (e.g. `nm …/libprotobuf_cgo.a | grep SYMBOL` vs `…/libabsl_cgo.a`).
2. Prefer **avoiding mixed owners** in one link: either use the default protobuf prebuilt path without `libabsl_cgo.a`, or isolate the `googlesql_tier_b_absl` experiment so it does not also pull `go-protobuf`.
3. If the product truly needs both tags, choose a **single owner** (merged archive or one CGO package) before attempting fragile object-level stripping.

## Unified `libgooglesql.a` (`googlesql_unified_prebuilt`)

v1 **`libgooglesql.a`** contains GoogleSQL-owned object code from selected Bazel targets plus a C anchor ([`libgooglesql-unified.md`](libgooglesql-unified.md)). It is **not** a full replacement for protobuf or Abseil static archives. When a future single merged archive subsumes protobuf + Abseil + GoogleSQL in **one** Bazel link, prefer **one** `-l` line and tighten link flags: the long-term goal in [`native-build-pipeline.md`](native-build-pipeline.md) is to **stop relying** on **`-Wl,--allow-multiple-definition`** for correctness once a single owner or merged archive removes duplicate ELF definitions.

## Multiple CGO packages each linking `-labsl_cgo`

Each migrated package passes **`-L…/go-absl/lib -labsl_cgo`** in its `bind_tier_b_absl.go`. The final link may pull the same static archive more than once; [`Makefile`](../Makefile) uses **`-Wl,--allow-multiple-definition`** while this is rolled out. If you see link failures or unexpected duplication, prefer Option B (single `prebuilt` owner) in [`native-build-pipeline.md`](native-build-pipeline.md), or the unified `libgooglesql.a` path once it covers your symbol closure.

## Bazel pin

Abseil is built from the same pin as [`internal/cmd/updater/googlesql/MODULE.bazel`](../internal/cmd/updater/googlesql/MODULE.bazel): `abseil-cpp` **20240722.1** (`repo_name = "com_google_absl"`). Vendored headers under `internal/ccall` should stay consistent with that revision.
