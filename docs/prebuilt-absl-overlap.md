# Abseil prebuilt archive: overlap with `libprotobuf_cgo.a`

## Finding

`libprotobuf_cgo.a` (from `make prebuilt-libs`) merges Bazel-built protobuf and utf8_range object files. Those objects **include Abseil code** linked into the archive (e.g. `absl::log_internal::*`, `absl::container_internal::*`). A quick check:

```bash
nm internal/ccall/go-protobuf/protobuf/lib/linux_amd64/libprotobuf_cgo.a | grep -E '^[0-9a-f]+ [TtW] _ZN4absl' | head
```

## Policy (until deduplicated archives exist)

| Build tags | Link `libabsl_cgo.a`? | Notes |
|------------|----------------------|--------|
| Default | No | Amalgamation compiles vendored C++. |
| `googlesql_tier_b` only | No (protobuf package links `libprotobuf_cgo.a`) | Protobuf archive already embeds Abseil objects. |
| `googlesql_tier_b_absl` only | Yes | Use for pilots and Abseil experiments **without** also relying on Tier B protobuf for the same link of duplicate Abseil symbols. |
| `googlesql_tier_b` **and** `googlesql_tier_b_absl` | Risk of **duplicate Abseil symbols** | Not supported until object-level dedup or a single merged archive is implemented. |

Tier B Abseil is validated with **default** protobuf (no `googlesql_tier_b`). Migrated link-only packages include **`meta/type_traits`**, **`base/config`**, **`base/core_headers`**, **`base/endian`**, **`base/errno_saver`**, **`base/prefetch`**, **`utility/utility`** (see [`prebuilt-cgo.md`](prebuilt-cgo.md)).

## If both protobuf Tier B and Abseil Tier B must appear in one link (future)

Today this combination is **unsupported** because `libprotobuf_cgo.a` already contains Abseil object code. When a concrete product needs **both** `googlesql_tier_b` and `googlesql_tier_b_absl` in the same binary, pick one of:

1. **Object-level dedup** — merge archives and strip duplicate ELF sections (fragile; needs a maintained symbol manifest).
2. **Single merged static archive** — one Bazel target that owns protobuf + Abseil + utf8_range with a single link line (see [`native-build-pipeline.md`](native-build-pipeline.md) “single owner”).
3. **Single CGO owner package** — one Go package links `-lprotobuf_cgo` (or a renamed unified archive); other packages use `cgo` `// #cgo LDFLAGS:` only if they do not pull a second copy of Abseil.

Defer implementation until there is a real linker failure or CI requirement—not for hypothetical builds.

## Multiple CGO packages each linking `-labsl_cgo`

Each migrated package passes **`-L…/go-absl/lib -labsl_cgo`** in its `bind_tier_b_absl.go`. The final link may pull the same static archive more than once; [`Makefile`](../Makefile) uses **`-Wl,--allow-multiple-definition`** while this is rolled out. If you see link failures or unexpected duplication, prefer Option B (single `prebuilt` owner) in [`native-build-pipeline.md`](native-build-pipeline.md).

## Bazel pin

Abseil is built from the same pin as [`internal/cmd/updater/googlesql/MODULE.bazel`](../internal/cmd/updater/googlesql/MODULE.bazel): `abseil-cpp` **20240722.1** (`repo_name = "com_google_absl"`). Vendored headers under `internal/ccall` should stay consistent with that revision.
