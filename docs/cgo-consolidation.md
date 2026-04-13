# CGO / prebuilt consolidation program

This document defines the **explicit project** to shrink redundant CGO shards and stale `export.inc` preludes while preserving **single-owner** Abseil and protobuf rules. It complements [protobuf-single-owner-inventory.md](protobuf-single-owner-inventory.md), [tier-b-absl-protobuf.md](tier-b-absl-protobuf.md), [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md), and [link-only-cgo-migration.md](link-only-cgo-migration.md).

## In scope

- Inventory and classification of `internal/ccall/**/bind.cc` files that `#include` native `.cc` sources.
- Namespace / archive policy decisions (Abseil, cctz, protobuf) aligned with unified prebuilts.
- Generator and [internal/exportinc](../internal/exportinc/exportinc.go) hygiene for `export.inc` vs link-only `bind.cc`.
- CI gate: link-only `bind.cc` files must not regress to amalgamated `.cc` includes (see [scripts/cgo-shard-inventory.sh](../scripts/cgo-shard-inventory.sh)).
- Downstream verification notes (go-googlesqlite, bigquery-emulator).

## Out of scope

- Rewriting the GoogleSQL engine in pure Go or removing CGO from the public API.
- “Remove all of `internal/ccall/go-absl`” in one change set (multi-quarter effort; see risk register below).

## Hard constraints (every phase)

| Constraint | Reference |
|------------|-----------|
| Default tags **`googlesql` + `googlesql_unified_prebuilt`** with **`libprotobuf_cgo.a`** + **`libgooglesql.a`** | [prebuilt-cgo.md](prebuilt-cgo.md), [link-only-cgo-migration.md](link-only-cgo-migration.md) |
| Do **not** mix default protobuf prebuilts with **`googlesql_tier_b_absl`** + `libabsl_cgo.a` in one binary | [tier-b-absl-protobuf.md](tier-b-absl-protobuf.md), [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md) |
| **`cclib.global_exclude_replace_names`** (`absl`, `google`) stays coherent with `libprotobuf_cgo.a` | [internal/cmd/generator/config.yaml](../internal/cmd/generator/config.yaml) `cclib` |

## Baseline metrics (snapshot)

Regenerate counts with:

```bash
./scripts/cgo-shard-inventory.sh --summary
```

Optional dependency graph (unified prebuilt tags):

```bash
go list -tags googlesql,googlesql_unified_prebuilt -deps ./... | sort -u | head -80
```

Approximate scale (see also [protobuf-single-owner-inventory.md](protobuf-single-owner-inventory.md)):

- **780+** `bind.cc` files under `internal/ccall/go-googlesql/`.
- **`./scripts/cgo-shard-inventory.sh --summary`** reports how many `bind.cc` files anywhere under `internal/ccall/` still `#include` a `.cc` source. **Snapshot (2026-04):** **3** total — **`go-absl`** (3) only; **`go-base`** has **no** such shards after **`base/logging`** went link-only. **`./scripts/cgo-shard-inventory.sh --list`** has **no** entries under **`go-googlesql/`**, **`go-algorithms/`**, or **`go-base/`** (generated `googlesql/*` shards are link-only; **`go-proto`** differential-privacy protos below are link-only). The **3** remaining amalgamation binds are: **`debugging/leak_check_disable`** (vendored TU), **`log/scoped_mock_log`**, and **`status/status_matchers`** (GMock policy). **Tenth / Eleventh follow-ups** retired **`civil_time`**, **`absl/time/time`**, **`kernel_timeout_internal`**, and **`time/go_internal/cctz/time_zone`** (IANA **`*.pic.o`** in **`libprotobuf_cgo.a`** + **`exclude_amalgamation_sources`**).
- Many **link-only** binds (header comment: `Link-only bind.cc`; snapshot **420** files) — implementations in **`libgooglesql.a`**; CI **`--check`** ensures these never `#include` amalgamated `.cc` bodies.
- **`go-absl/**`** still `#include` `.cc` sources where a separate TU or single-owner rule requires it. Recent default-path slices retired **`types/bad_*`**, **`strings/string_view`**, and a 10-shard single-file batch (**`base/{throw_delegate,log_severity,strerror,spinlock_wait}`**, **`numeric/int128`**, **`hash/{city,low_level_hash}`**, **`profiling/exponential_biased`**, **`crc/cpu_detect`**, **`random/seed_gen_exception`**) by listing sources under **`cclib.exclude_amalgamation_sources`** in [config.yaml](../internal/cmd/generator/config.yaml): implementations are expected from **`libprotobuf_cgo.a`** (verify with `ar t` / `nm -C` before similar changes). **`cclib.link_only_bind_packages`** is **not** used for these packages: the generator’s link-only **Go** output path (`bind_unified_prebuilt_*` only, no `bind_linux.go`) applies to **`googlesql/*`** and would break normal **`go-absl`** CGO. **`go-algorithms/go_internal`** **bounded-mean-ci**, **count-tree**, and **`algorithms/gaussian-dp-calculator`** are **link-only** (targets in [default_bazel_targets.txt](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt); **`algorithms/internal/bounded-mean-ci`** / **`algorithms/internal/count-tree`** under `cclib.link_only_bind_packages` in [config.yaml](../internal/cmd/generator/config.yaml)). Rebuild **`libgooglesql.a`** (`task prebuilt:googlesql-unified`) after changing that list. **`base/logging`** is **link-only** (`logging.pic.o` from **`//googlesql/base:logging`** in **`libgooglesql.a`**; see [extract_googlesql_unified_lib.sh](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh)); **`export.inc`** drops **`base/logging.cc`** via **`filterGoBaseLoggingLinkOnlySources`** in [internal/exportinc/exportinc.go](../internal/exportinc/exportinc.go).

## Shard classification (A / B / C)

| Class | Meaning | Examples |
|-------|---------|----------|
| **A — Must compile in-repo** | True single-owner TU or flex/parser shard; cannot be dropped without moving symbols into an archive | flex tokenizer `.cc` in parser packages; vendored one-offs (e.g. **`leak_check_disable`**) |
| **B — Candidate for consolidation** | Symbols likely already in `libgooglesql.a` / `libprotobuf_cgo.a` but shard still lists `.cc` in **non-link-only** generated binds | Legacy generator output (e.g. `zetasql_*` guards); requires **link/nm/runtime** proofs before removal |
| **C — Generated proto shard** | Small `*_cc_proto` packages with `.pb.cc` in `bind.cc` | [`go-proto`](../internal/ccall/go-proto) packages; consolidate only with descriptor / registration audit |

**Deliverable:** extend this table as you retire shards; do not delete packages without Phase 4 proofs.

## Archive and namespace policy (locked)

1. **Default binary:** Abseil / `google::protobuf` objects come from **`libprotobuf_cgo.a`** and **`libgooglesql.a`** with **`cclib.global_exclude_replace_names: [absl, google]`** so TUs match plain namespaces in those archives ([tier-b-absl-protobuf.md](tier-b-absl-protobuf.md) Phase 3).
2. **Tier B Abseil pilot:** **`googlesql_tier_b_absl`** + **`libabsl_cgo.a`** only for **isolated** package sets — **never** combined with the default protobuf prebuilt owner ([prebuilt-cgo.md](prebuilt-cgo.md)).
3. **cctz / civil_time:** **`libprotobuf_cgo.a`** owns IANA **`time_zone_*.pic.o`** (merged by [extract_protobuf_cgo_lib.sh](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh)); **`go-absl/time`** blank-imports and **`exclude_amalgamation_sources`** stay aligned ([unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md)).

## Generator and export.inc (audit)

- **Link-only `bind.cc`** is generated from [bind_link_only.cc.tmpl](../internal/cmd/generator/templates/bind_link_only.cc.tmpl) when the generator applies link-only mode for `googlesql/*` and packages listed under `cclib.link_only_bind_packages` ([config.yaml](../internal/cmd/generator/config.yaml)). For **`go-absl`** shards, prefer **`cclib.exclude_amalgamation_sources`** when the implementation is already in **`libprotobuf_cgo.a`** / **`libgooglesql.a`** but the package must keep **`bind_linux.go`** / **`bind_darwin.go`** (do not add **`go-absl`** to **`link_only_bind_packages`** unless the generator is extended to split Go output paths).
- Such files **must not** `#include` amalgamated `googlesql/.../*.cc` bodies; implementations are in **`libgooglesql.a`**. CI enforces this via `./scripts/cgo-shard-inventory.sh --check`.
- **[internal/exportinc](../internal/exportinc/exportinc.go)** derives `export.inc` preludes from `bind.cc` and applies **policy** (strip stray `go-protobuf/protobuf/export.inc`, analyzer `options.pb.cc` / `type.pb.cc` duplication guards, etc.). Link-only `bind.cc` preludes should remain **header-only**; stale `#include "*.cc"` lines in **on-disk** `export.inc` under link-only packages should be regenerated with `go run ./internal/cmd/generator` and exportinc sync — not hand-edited inconsistently.

**Regeneration:** **`go run ./internal/cmd/generator`** from the repo root after `config.yaml` changes ([link-only-cgo-migration.md](link-only-cgo-migration.md)).

## Phase 4 — Remove or merge shards (playbook)

For each **B** candidate:

1. **Link proof:** `task test:local TESTPKG=./path/to/pkg` or `go test -c -tags googlesql,googlesql_unified_prebuilt` with `-run '^$'`.
2. **Duplicate symbol proof:** `nm -C` / `llvm-nm` on `libprotobuf_cgo.a` and `libgooglesql.a` ([libgooglesql-unified.md](libgooglesql-unified.md)).
3. **Runtime proof:** full `task test:local`; watch for startup issues ([unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md)).
4. **Edit** [`bind_unified_prebuilt_linux.go` / `bind_unified_prebuilt_darwin.go`](../internal/ccall/go-googlesql/bind_unified_prebuilt_linux.go) blank imports only when link order is proven safe (**import order matters**).

**Status:** The stale duplicate package `internal/ccall/go-googlesql/public/timestamp_pico_value` (legacy `zetasql_*` amalgamation; no matching `cc_library` in `googlesql/public/BUILD`) was removed; the supported CGO shard is `internal/ccall/go-googlesql/public/timestamp_picos_value` (link-only + unified prebuilt). Use this checklist for further PRs.

**Example B candidates** (non-exhaustive): legacy amalgamation under `go-googlesql` **when** `--list` shows such paths — use Phase 4 before changing `bind_unified_prebuilt_*` imports. **As of the 2026-04 inventory snapshot, `--list` contains no `go-googlesql/` or `go-algorithms/` paths.** Broader pulls remain **go-absl**-scoped audits (respecting time/cctz policy).

**Done (link-only + generator):** `googlesql/public/range_value` is now a normal `cc_library` in [`internal/ccall/googlesql/public/BUILD`](../internal/ccall/googlesql/public/BUILD) and regenerated like other `googlesql/public/*` shards (`bind_link_only.cc.tmpl`, `zetasql`/`zetasql_base` namespace overrides and status-macro prelude in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml)).

- **`base/logging`:** listed under `cclib.link_only_bind_packages` next to **`base/status`**; thin **`bind.cc`** + unified-prebuilt **`bind_unified_prebuilt_*.go`**. [`export.inc`](../internal/ccall/go-base/logging/export.inc) omits **`base/logging.cc`** via **`filterGoBaseLoggingLinkOnlySources`** in [internal/exportinc/exportinc.go](../internal/exportinc/exportinc.go) so dependents (e.g. [`go-algorithms/algorithm/export.inc`](../internal/ccall/go-algorithms/algorithm/export.inc)) do not compile **`logging.cc`** again; **`logging.pic.o`** is in **`libgooglesql.a`** from **`//googlesql/base:logging`**.

- **`algorithms/util`** and **`algorithms/distributions`:** listed under `cclib.link_only_bind_packages` in [`internal/cmd/generator/config.yaml`](../internal/cmd/generator/config.yaml); thin `bind.cc` + unified-prebuilt `bind_unified_prebuilt_*.go` like `base/status`. [`export.inc`](../internal/ccall/go-algorithms/util/export.inc) / [`export.inc`](../internal/ccall/go-algorithms/distributions/export.inc) omit `algorithms/util.cc` / `algorithms/distributions.cc` via `filterAlgorithmsUtilLinkOnlySources` in [internal/exportinc/exportinc.go](../internal/exportinc/exportinc.go) so parent TUs that include those `export.inc` chains do not compile those `.cc` bodies again; object code is expected from **`libgooglesql.a`** (objects under `com_google_cc_differential_privacy` collected by [`extract_googlesql_unified_lib.sh`](../internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh)).

- **`algorithms/numerical-mechanisms`**, **`algorithms/rand`**, **`algorithms/internal/gaussian-stddev-calculator`:** same link-only + `filterAlgorithmsUtilLinkOnlySources` pattern as util/distributions; `.pic.o` objects for **`numerical-mechanisms.cc`**, **`rand.cc`**, and **`gaussian-stddev-calculator.cc`** are merged into **`libgooglesql.a`**.

- **`algorithms/gaussian-dp-calculator`:** link-only + `cclib.link_only_bind_packages` + `filterAlgorithmsUtilLinkOnlySources`; **`gaussian-dp-calculator.pic.o`** is built into **`libgooglesql.a`** via **`@com_google_cc_differential_privacy//algorithms:gaussian-dp-calculator`** in [default_bazel_targets.txt](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt) (rebuild prebuilts after changing that list).

- **`algorithms/internal/bounded-mean-ci`** and **`algorithms/internal/count-tree`:** same link-only + generator pattern as **`gaussian-dp-calculator`**; **`bounded-mean-ci.pic.o`** / **`count-tree.pic.o`** from **`@com_google_cc_differential_privacy//algorithms/internal:bounded-mean-ci`** and **`:count-tree`** in [default_bazel_targets.txt](../internal/ccall/go-googlesql-unified/default_bazel_targets.txt).

- **Differential-privacy `go-proto` shards** (`proto/confidence_interval_cc_proto`, `proto/data_cc_proto`, `proto/numerical_mechanism_cc_proto`, `proto/summary_cc_proto`): link-only `bind.cc` + `cclib.link_only_bind_packages` + `exclude_replace_names` (aligned with `base/status`) so `.pb.cc` bodies are not compiled in the CGO TU; implementations are expected from **`libgooglesql.a`** (external `com_google_*_differential_privacy` objects merged by the unified extract script). Regenerate `bind.cc` / `export.inc` with **`go run ./internal/cmd/generator`** after `config.yaml` changes (requires a full `internal/ccall` proto/googleapis checkout — run [`scripts/regenerate-ccall-cpp-protos.sh`](../scripts/regenerate-ccall-cpp-protos.sh) first if headers are missing); sync `export.inc` via [internal/exportinc](../internal/exportinc/exportinc.go) (`BuildFromBindCC`) if editing bind preludes by hand.
  - **Canonical `internal/ccall/proto/*.proto`:** checked-in copies track [google/differential-privacy](https://github.com/google/differential-privacy) `proto/*.proto`. Regenerate **`*.pb.{h,cc}`** with the repo’s Bazel **`protoc`** (see script; `MODULE.bazel` **`protobuf`** version must match **`internal/ccall/protobuf`**). The script rewrites duplicate **`_static_init2_`** static-init names per file so multiple generated `.pb.cc` files can coexist in one amalgamation TU. **[proto/util.h](../internal/ccall/proto/util.h)** must stay aligned with **`data.proto`** (upstream **`Output.ErrorReport`** does not carry **`noise_confidence_interval`**; CI is on **`Output.Element`** only).
  - **Phase 4 checks (with prebuilts):** run compile-only proofs for **`bounded-mean-ci`** and **`count-tree`** (e.g. `task test:local TESTPKG=./internal/ccall/go-algorithms/go_internal/bounded-mean-ci GO_TEST_FLAGS='-run ^$'` and the same for **`count-tree`**); `task verify:prebuilt-googlesql-unified`. A full **`task test:local TESTPKG=./internal/ccall/go-algorithms/...`** compile may still fail in packages that pull a very large single-TU amalgamation (e.g. **`quantiles`**: duplicate **`absl`** helpers such as **`kMaxCodePoint`** / **`__cpuid`** when the same `.cc` is included twice — unrelated to the DP proto regeneration). The four `internal/ccall/go-proto/*_cc_proto/` trees have **no** standalone `package` Go files; they are only pulled through dependents (e.g. `go-algorithms`). **`bind_unified_prebuilt_*`:** no blank-import change — link order is unchanged; root still imports `go-protobuf/protobuf` only.

- **`absl/types/bad_optional_access`**, **`absl/types/bad_variant_access`**, **`absl/types/bad_any_cast_impl`:** `cclib.exclude_amalgamation_sources` in [config.yaml](../internal/cmd/generator/config.yaml) so generated `bind.cc` no longer `#include` the Abseil `.cc` bodies; link against **`libprotobuf_cgo.a`**. Existing **`go-absl/types/`** `export.inc` policy (dependencies-only preludes) is unchanged.

- **`absl/strings/string_view`:** same **`exclude_amalgamation_sources`** pattern; `string_view.pic.o` is merged into **`libprotobuf_cgo.a`**. Regenerated `export.inc` keeps the header prelude (not the **`go-absl/types/`** dependencies-only exception).

- **10-shard default-path batch (single-file go-absl slices):** `exclude_amalgamation_sources` for **`absl/base/{throw_delegate,log_severity,strerror,spinlock_wait}`**, **`absl/numeric/int128`**, **`absl/hash/{city,low_level_hash}`**, **`absl/profiling/exponential_biased`**, **`absl/crc/cpu_detect`**, and **`absl/random/seed_gen_exception`**. Generated `bind.cc` files no longer include those `.cc` bodies; inventories dropped **90 -> 80** with `./scripts/cgo-shard-inventory.sh --check` still green.

- **Second 10-shard default-path batch (single `.cc` per shard):** `exclude_amalgamation_sources` for **`absl/base/{poison,scoped_set_env,malloc_internal,raw_logging_internal}`**, **`absl/profiling/periodic_sampler`**, **`absl/synchronization/graphcycles_internal`**, **`absl/debugging/{stacktrace,leak_check}`**, **`absl/debugging/stack_consumption`** ( **`examine_stack`** was deferred here and later handled in the **Seventh follow-up** once archive ownership was proven), and **`absl/strings/pow10_helper`**. Object code is expected from **`libprotobuf_cgo.a`**. Inventories dropped **80 -> 70** with `./scripts/cgo-shard-inventory.sh --check` still green. **`absl/flags/*`**, **`absl/time/*`**, large multi-`.cc` amalgamations, and broad **`absl/strings/*`** bundles remain deferred per the consolidation playbook.

- **Third reduction wave (70 → 58):** **Tier 1** — single-`.cc` excludes for **`absl/hash/hash`**, **`absl/container/raw_hash_set`**, **`absl/status/statusor`**, and **`absl/random/internal/{platform,pool_urbg,randen,randen_hwaes,randen_hwaes_impl,randen_slow,seed_material}`** (generator **`pkg:`** keys use Bazel **`absl/random/internal/...`**, not the on-disk **`go-absl/random/go_internal/...`** path). **Tier 2** — **`absl/container/hashtablez_sampler`** with **two** sources in one block. **Debugging helper:** **`absl/debugging/utf8_for_code_point`** also listed so `export.inc` no longer re-embeds **`utf8_for_code_point.cc`** next to **`decode_rust_punycode.cc`** in the same TU (fixes **`kMaxCodePoint`** redefinition when pulling **`raw_hash_set`** / **`hashtablez_sampler`** / **`statusor`** chains). **`seed_sequences`** and remaining **`absl/log/*`** singles are natural follow-ups; treat **`absl/flags/*`**, **`absl/time/*`** / **cctz**, the **demangle / symbolize** subgraph ( **`examine_stack`** was later retired via **`exclude_amalgamation_sources`** once **`examine_stack*.pic.o`** was confirmed in **`libprotobuf_cgo.a`** — see **Seventh follow-up** below), and mega-shards (**`strings/strings`**, **`synchronization/synchronization`**, **`base/base`**) as **separate epics** with coordinated proofs.

- **Fourth wave (58 → 46):** **`absl/random/seed_sequences`**; **`absl/log/{die_if_null,globals,initialize,log_entry,log_sink}`**; **`absl/log/internal/{check_op,conditions,fnmatch,format}`** (source **`log_format.cc`**). **Multi-source:** **`absl/random/distributions`** (**`discrete_distribution.cc`** + **`gaussian_distribution.cc`**), **`absl/crc/crc_internal`** (**`crc.cc`** + **`crc_x86_arm_combined.cc`**). **`absl/status/status_matchers`** and **`absl/log/flags`** were **not** used here: no matching **`status_matchers*.pic.o`** / obvious **`log/flags`** object in **`libprotobuf_cgo.a`** under the usual `ar t` naming—prove archive membership before similar excludes. **Epics (unchanged):** **`absl/flags/*`** (bulk), **`absl/time/*`** / **cctz**, **debugging** demangle/symbolize chains, mega **`strings`** / **`synchronization`** / **`base/base`**.

- **Fifth / sixth wave (46 → 11):** **`cclib.exclude_amalgamation_sources`** for the remaining **log** singles (where proven), **`crc_cord_state`**, **`cordz_{functions,handle,info}`**, **`absl/status/status`** (3× `.cc`), the full **`absl/flags/*`** single-file set, the **debugging** batch (**`demangle_*`**, **`decode_rust_punycode`**, **`debugging_internal`**, **`symbolize`**), and the **mega** shards (**`base/base`**, **`crc32c`**, **`strings/*`**, **`synchronization/synchronization`**). **`absl/time/*`**, **`kernel_timeout_internal`**, and related cctz TUs are **not** excluded: removing those amalgamation bodies caused **undefined `absl::time_internal::cctz::*`** symbols at link time against the current **`libprotobuf_cgo.a`** + **`libgooglesql.a`** closure; keep compiling those `.cc` bodies in-repo until cctz extract / duplicate-TU policy allows a safe proof (see comment in [config.yaml](../internal/cmd/generator/config.yaml) near **`exclude_amalgamation_sources`**). **`log/flags`**, **`scoped_mock_log`**, **`status_matchers`**, **`cordz_sample_token`**, and the three **debugging** singles left in the inventory are unchanged for **gmock** / archive / **`export.inc`** reasons documented above.

- **Seventh follow-up (11 → 10):** **`absl/debugging/examine_stack`** — `ar t libprotobuf_cgo.a` includes **`examine_stack*.pic.o`**; **`cclib.exclude_amalgamation_sources`** for **`absl/debugging/internal/examine_stack.cc`** so the CGO TU no longer compiles that body (implementation from the archive). At the time, **`absl/log/flags`**, **`cordz_sample_token`**, **`failure_signal_handler`**, and **`leak_check_disable`** lacked obvious archive TUs (**`log/flags`** / **`cordz_*`** / **`failure_signal`** resolved later in **Ninth follow-up**; **`leak_check_disable`** remains [**vendored**](../internal/ccall/absl/debugging/leak_check_disable.cc)).

- **GMock / test helpers (default prebuilt path):** **`log/scoped_mock_log`** and **`status/status_matchers`** depend on **GTest/GMock** headers. [extract_protobuf_cgo_lib.sh](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) filters out **`status_matchers`**, **`gmock`**, and **`gtest`** members so **`libprotobuf_cgo.a`** does not force a **libgtest** link in normal binaries. Treat these shards as **not** candidates for “implementation-only-in-`libprotobuf_cgo.a`” excludes on the default **`googlesql` + `googlesql_unified_prebuilt`** path unless prebuilt policy changes.

- **Time / cctz (archive-owned IANA, Eleventh follow-up):** [extract_protobuf_cgo_lib.sh](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) **merges** cctz **`time_zone_*.pic.o`** / **`zone_info_source.pic.o`** into **`libprotobuf_cgo.a`**; **`cclib.exclude_amalgamation_sources`** for **`absl/time/internal/cctz/time_zone`** keeps the Go shard **link-only** for `.cc` bodies. Historical duplicate-TU risk ([unified-prebuilt-root-segfault-investigation.md](unified-prebuilt-root-segfault-investigation.md)) is avoided by **single** ownership in the archive + thin **`bind.cc`**.

- **Eighth follow-up (`nm` verification, 2026-04):** Historical snapshot on **`libprotobuf_cgo.a`** before explicit Abseil Bazel builds: **`nm -C`** plus substring search found **no** symbols suggestive of **`failure_signal_handler`** or **`leak_check_disable`** TUs; **`SampleToken`** names did not appear; **`absl/log/flags.cc`** had no obvious dedicated TU footprint. **Superseded for `log/flags`, `cordz_sample_token`, and `failure_signal_handler` by Ninth follow-up** (explicit **`bazel build`** + extract merge). **`leak_check_disable`** remains a separate case (vendored TU).

- **Ninth follow-up (10 → 7):** **`extract_protobuf_cgo_lib.sh`** now runs explicit **`bazel build`** for **`@com_google_absl//absl/log:flags`**, **`//absl/strings:cordz_sample_token`**, **`//absl/debugging:failure_signal_handler`** before collecting **`.pic.o`** files, so **`56_flags_flags.pic.o`**, **`90_cordz_sample_token_cordz_sample_token.pic.o`**, and **`30_failure_signal_handler_failure_signal_handler.pic.o`** merge into **`libprotobuf_cgo.a`**; **`cclib.exclude_amalgamation_sources`** in [config.yaml](../internal/cmd/generator/config.yaml) drops those **`#include "*.cc"`** bodies from the corresponding go-absl shards. **`leak_check_disable`** remains amalgamated: implementation is [**`internal/ccall/absl/debugging/leak_check_disable.cc`**](../internal/ccall/absl/debugging/leak_check_disable.cc) (vendored local TU), not upstream Abseil **`cc_library`** output.

- **Tenth follow-up (7 → 4, Option B):** **`cclib.exclude_amalgamation_sources`** for **`absl/time/internal/cctz/civil_time`**, **`absl/time/time`**, and **`absl/synchronization/kernel_timeout_internal`** — implementations from **`libprotobuf_cgo.a`**.

- **Eleventh follow-up (4 → 3, Option A):** [extract_protobuf_cgo_lib.sh](../internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh) no longer filters out IANA **`time_zone_*.pic.o`** / **`zone_info_source.pic.o`**; **`cclib.exclude_amalgamation_sources`** for **`absl/time/internal/cctz/time_zone`** (nine **`absl/time/internal/cctz/src/*.cc`** paths) + **`go run ./internal/cmd/generator`**. **`task verify:prebuilt-protobuf`** / **`task verify:prebuilt-googlesql-unified`** gate duplicate globals.

- **GMock shard policy (decision):** **`log/scoped_mock_log`** and **`status/status_matchers`** stay **generated** and **not** listed under **`cclib.excludes`** (unlike **`optional_ref_matchers`**, **`edge_matchers`**, etc.). The default module tests do not import them; they exist for **optional** downstream or test binaries that link **GTest/GMock**. Expect them to remain in the amalgamation **inventory** until a separate policy removes test-oriented CGO packages.

- **Open product decisions (GMock inventory):** No further **default-path** generator work until the team chooses one of: (1) leave **`scoped_mock_log`** / **`status_matchers`** as optional **GMock** shards (inventory stays at **3** non-test shards if **`leak_check_disable`** is also deferred), (2) list under **`cclib.excludes`** like other GMock-only targets (requires consumers that need matchers to opt in explicitly), or (3) remove test-oriented CGO packages from the module. **Tier B** **`libabsl_cgo.a`** remains a separate pilot — not a shortcut for default inventory.

- **cctz / `kernel_timeout` future PR checklist:** **Landed (2026-04):** Tenth + Eleventh follow-ups completed **Option B** + **Option A** for time/cctz (see bullets above). **Remaining optional work:** vendored **`leak_check_disable`**, GMock inventory (policy), or downstream smoke on releases.

- **Optional — `leak_check_disable` .pic.o merge:** To drop amalgamation for [**`internal/ccall/absl/debugging/leak_check_disable.cc`**](../internal/ccall/absl/debugging/leak_check_disable.cc), add a reproducible **`cc_library`** (or equivalent) that compiles that file with the same ABI as Abseil, merge its **`.pic.o`** into **`libprotobuf_cgo.a`** (same staging pattern as other members), then **`exclude_amalgamation_sources`**. **Deferred:** one-off TU; low priority vs cctz epic.

- **`googlesql/parser/flex_istream`:** `cc_library` in [`internal/ccall/googlesql/parser/BUILD`](../internal/ccall/googlesql/parser/BUILD), link-only `bind.cc` (avoids pulling the full `go-absl/strings` amalgamation into the TU, which duplicated `absl::strings` stringify headers). `flex_tokenizer` depends on `:flex_istream`.
- **`googlesql/parser/macros/flex_token_provider`:** `inject_replace_names` / `symbol_define_overrides` for `zetasql` + `exclude_replace_names` (same idea as `base/status`) so `GOOGLESQL_*` status macros are not broken by namespace `#define`s; sources use `GOOGLESQL_ASSIGN_OR_RETURN` in the inline/header path.
- **GMock-only `cc_library` targets** (`optional_ref_matchers`, `edge_matchers`, `nfa_matchers`) are listed under `cclib.excludes` so the generator does not emit CGO packages that require `gmock/gmock.h` in default CI headers.
- Removed the orphan **`go-googlesql/parser/token_codes`** CGO directory (headers remain owned by `flex_tokenizer` / includes).

## Phase 5 — CI and downstream

| Check | Command / workflow |
|-------|-------------------|
| Link-only invariant | `./scripts/cgo-shard-inventory.sh --check` (runs in **Go** workflow) |
| After **`extract_protobuf_cgo_lib.sh`** changes | **`task prebuilt:protobuf`**, **`task verify:prebuilt-protobuf`**, **`task test:local TESTPKG=./`** — **`libprotobuf_cgo.a`** is gitignored ([prebuilt-cgo.md](prebuilt-cgo.md)) |
| Consumer prebuilts | [.github/workflows/go-prebuilt-consumer.yml](../.github/workflows/go-prebuilt-consumer.yml) |
| Downstream | Pin **go-googlesqlite** / **bigquery-emulator** to the same module tag and prebuilt layout ([tier-b-absl-protobuf.md](tier-b-absl-protobuf.md) Phase 5) |

## Exit criteria (program “done”)

1. This charter + inventory script + CI check are in place (this document).
2. **Symbol ownership** policy is documented above and unchanged by accident (no new duplicate-definition regressions vs baseline).
3. **`task test:local`**, **`task test:protobuf-cgo`**, consumer workflow, and `./scripts/cgo-shard-inventory.sh --check` stay green.
4. Downstream smoke on **go-googlesqlite** / **bigquery-emulator** remains documented in their READMEs when bumping **go-googlesql**.

## go-absl retirement (incremental; not a single PR)

Full removal of **`internal/ccall/go-absl`** remains a **multi-quarter** effort. Progress on the **default** path (`googlesql` + **`googlesql_unified_prebuilt`**, **`libprotobuf_cgo.a`** + **`libgooglesql.a`**) should continue in **small slices** with Phase 4 proofs ([link-only-cgo-migration.md](link-only-cgo-migration.md), [prebuilt-absl-overlap.md](prebuilt-absl-overlap.md)).

**After successive consolidation waves through 2026-04:** `./scripts/cgo-shard-inventory.sh --summary` reports **3** `bind.cc` files that still `#include` a `.cc` — all under **`go-absl`** (see §Baseline metrics). **`go-googlesql/`**, **`go-base/`**, and **`go-algorithms/`** remain clear on `--list`.

**Likely next steps (priority order; snapshot **3** amalgamation binds under **`go-absl`** — see §Baseline metrics):**

1. **Optional:** merge vendored **`leak_check_disable`** **`.pic.o`** into **`libprotobuf_cgo.a`** then **`exclude_amalgamation_sources`** — low leverage; see **Optional — `leak_check_disable`** bullet above.
2. **GMock shards (`scoped_mock_log`, `status_matchers`):** policy remains **generated for optional consumers**; inventory **3 → 1** only if product **removes test-oriented CGO** or changes **Tier B** / **`cclib.excludes`** policy (see **Open product decisions (GMock inventory)** above). **Open product decision:** keep as-is vs exclude from default generator output.
3. **`googlesql_tier_b_absl`** + **`libabsl_cgo.a`** stays a **separate Tier B pilot** — not a substitute for shrinking the default inventory ([tier-b-absl-protobuf.md](tier-b-absl-protobuf.md)).

## Risk register

| Risk | Mitigation |
|------|------------|
| Per-shard `absl` rename vs plain `absl::` in archives | [protobuf-single-owner-inventory.md](protobuf-single-owner-inventory.md) spike writeup |
| `go` import order vs cgo link order | [`bind_unified_prebuilt_*`](../internal/ccall/go-googlesql/bind_unified_prebuilt_linux.go), generator `ImportGoLibsLinkOrderFirst` |
| Scope creep | Prefer **documented ownership** and **CI invariants** before bulk deletion |
