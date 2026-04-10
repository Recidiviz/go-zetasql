DOCKER_IMAGE ?= go-googlesql
DOCKER_DEV_IMAGE ?= go-googlesql:dev
# Shared host tree for GOCACHE, GOMODCACHE, and ccache (CGO). Default matches go-googlesqlite and
# bigquery-emulator Makefiles so Docker runs and local/build share one warm cache.
GO_CACHE_ROOT ?= $(HOME)/.cache/go-googlesql
# Default matches .github/workflows/go.yml (root package only). Set TESTPKG=./... to test all packages.
TESTPKG ?= ./
# Appended to go test for local/test and local/test-fresh (e.g. GO_TEST_FLAGS=-short).
GO_TEST_FLAGS ?=
# For local/build: package pattern passed to go build (default all modules under repo root).
BUILDPKG ?= ./...

# Parallel go build/test workers (-p). CGO + GoogleSQL C++ amalgamation is very memory-heavy; each
# concurrent job can peak at multiple GiB. Default: estimate jobs from ~80% MemAvailable /
# GO_BUILD_MEM_PER_JOB_KB, cap by CPU, then cap again by GO_BUILD_P_MAX (default 2) so IDEs do not OOM.
# Override examples: make local/build GO_BUILD_P=6
#   make local/build GO_BUILD_P_MAX=4
#   make local/build GO_BUILD_MEM_PER_JOB_KB=3145728   (assume ~3GiB per job → fewer workers)
GO_BUILD_MEM_PER_JOB_KB ?= 4194304
GO_BUILD_P_MAX ?= 2
GO_BUILD_P ?= $(shell \
	CPU=$$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4); \
	MAX="$(GO_BUILD_P_MAX)"; \
	if [ -r /proc/meminfo ]; then \
		P=$$(awk -v per="$(GO_BUILD_MEM_PER_JOB_KB)" '/^MemAvailable:/ {print int($$2 * 0.8 / per)}' /proc/meminfo); \
	else \
		P=$$((CPU / 2)); \
	fi; \
	if [ -z "$$P" ] || [ "$$P" -lt 1 ] 2>/dev/null; then P=1; fi; \
	if [ "$$P" -gt "$$CPU" ] 2>/dev/null; then P=$$CPU; fi; \
	if [ "$$P" -gt "$$MAX" ] 2>/dev/null; then P=$$MAX; fi; \
	echo "$$P")

# When `mold` is on PATH (e.g. go-googlesql:dev image), speed up the final link step.
MOLD_LD := $(shell command -v mold >/dev/null 2>&1 && echo -fuse-ld=mold)

DOCKER_DEV_ENV := \
	-e CGO_ENABLED=1 \
	-e CC=clang \
	-e CXX=clang++ \
	-e CCACHE_DIR=/root/.ccache \
	-e CCACHE_COMPRESS=1

DOCKER_DEV_VOLUMES := \
	-v "$(CURDIR)":/go-googlesql \
	-v "$(GO_CACHE_ROOT)/gocache":/root/.cache/go-build \
	-v "$(GO_CACHE_ROOT)/gomodcache":/go/pkg/mod \
	-v "$(GO_CACHE_ROOT)/ccache":/root/.ccache

.PHONY: docker/build docker/build-dev cache-dirs docker/warm-cache cache-clean-cgo \
	local/build local/test local/test-fresh \
	local/test-prebuilt-absl local/build-prebuilt-absl \
	local/build-prebuilt-googlesql-unified local/build-prebuilt-googlesql-unified-root local/test-prebuilt-googlesql-unified-root local/test-root-unified local/compile-root-unified-test \
	prebuilt-libs prebuilt-libs-absl prebuilt-libs-googlesql-unified package-protobuf-prebuilt-tarball \
	verify-prebuilt-protobuf verify-prebuilt-absl verify-prebuilt-googlesql-unified smoke-link-googlesql-unified \
	verify-protobuf-tier-b-alignment verify-tier-b-cgo-policy sync-protobuf-vendor-from-bazel regenerate-googlesql-cpp-protos \
	profile-bottleneck extract-protobuf-lib extract-absl-lib extract-googlesql-unified-lib \
	test test/linux test-docker

cache-dirs:
	mkdir -p \
		"$(GO_CACHE_ROOT)/gocache" \
		"$(GO_CACHE_ROOT)/gomodcache" \
		"$(GO_CACHE_ROOT)/ccache"

# After a full disk, kernel OOM, or unexplained SIGSEGV in go test, remove stale object code:
#   make cache-clean-cgo && make local/test-fresh
# If it still crashes at runtime after compile succeeds, try linking without mold:
#   make local/test CGO_LDFLAGS_BASE='-Wl,--no-gc-sections -Wl,--allow-multiple-definition'
# Or use Docker: make test/linux
cache-clean-cgo:
	rm -rf "$(GO_CACHE_ROOT)/gocache"/* "$(GO_CACHE_ROOT)/ccache"/*

docker/build:
	docker build -t $(DOCKER_IMAGE) .

docker/build-dev: cache-dirs
	docker build -t $(DOCKER_DEV_IMAGE) --target dev .

# --- Local host (no Docker): clang + same GO_CACHE_ROOT as Docker ----------
# Requires: clang, clang++ on PATH. Optional: ccache (see CGO_CC / CGO_CXX).
#
# Default compilers are plain clang: wrapping with `ccache clang` has produced incorrect
# CGO-linked parser code for this tree (MERGE/TextMapper); override if you accept that risk:
#   make local/test CGO_CC='ccache clang' CGO_CXX='ccache clang++'
CGO_CC ?= clang
CGO_CXX ?= clang++

# Default prebuilt protobuf: libprotobuf_cgo.a comes from Bazel with libc++ (not libstdc++).
# Every CGO C++ TU must
# use the same -stdlib or template instantiations (e.g. ArenaStringPtr with std::string) mangle as
# std::__cxx11:: vs std::__1:: and the link fails with undefined protobuf internals.
CGO_CXXFLAGS_PREBUILT ?= -stdlib=libc++
# g++ does not support -stdlib=libc++; keep default clang++ for prebuilts. If you override CXX to g++,
# clear this only when you have a libstdc++-matched prebuilt (not the default Bazel libc++ archive).

# --allow-multiple-definition: needed while multiple CGO TUs each embed overlapping C++ (incl.
# protobuf amalgamation). Removing it requires a single macro/link domain for protobuf+absl;
# see docs/protobuf-vendoring.md "Single-owner protobuf".
#
# Go rejects non-allowlisted #cgo LDFLAGS; bind_linux.go uses -Wl,--whole-archive etc. This list
# must stay in sync with internal/ccall/go-protobuf/protobuf/bind_*.go.
# -stdlib=libc++: without this, cmd/link invokes the external linker with GCC/C++ defaults and
# pulls libstdc++.so alongside Bazel-built libc++ prebuilts → mixed std:: ABI and startup SIGSEGV
# in protobuf/Abseil (see docs/unified-prebuilt-root-segfault-investigation.md).
CGO_LDFLAGS_ALLOW_LIST := -Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group|-stdlib=libc\+\+
CGO_LDFLAGS_BASE := -Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD) -stdlib=libc++

# Example: make local/build BUILDPKG=./internal/ccall/go-googlesql
local/build: cache-dirs verify-prebuilt-protobuf
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_PREBUILT)" \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags googlesql $(BUILDPKG)

# Same toolchain as local/build; mirrors test/linux but runs on the host (no -race unless you add it).
local/test: cache-dirs verify-prebuilt-protobuf
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_PREBUILT)" \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql -v $(TESTPKG) -count=1 $(GO_TEST_FLAGS)

# Like local/test but forces rebuilding every package (-a). Use after cache-clean-cgo or toolchain bumps.
local/test-fresh:
	$(MAKE) local/test GO_TEST_FLAGS=-a

# Rough cold vs warm timing + ccache stats. Uses TESTPKG (default ./). Requires ccache + clang on PATH.
profile-bottleneck: cache-dirs
	@echo "=== ccache stats (before) ==="; ccache -s 2>/dev/null || echo "(install ccache for stats)"
	@echo "=== cold: zero ccache counters ==="; ccache -z 2>/dev/null || true
	@echo "=== cold: compile test binary ==="; \
		time env CGO_ENABLED=1 $(if $(MOLD_LD),CGO_LDFLAGS=$(MOLD_LD),) \
		CC="ccache clang" CXX="ccache clang++" \
		CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" CCACHE_COMPRESS=1 \
		GOCACHE="$(GO_CACHE_ROOT)/gocache" GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
		go test -count=1 -c -o /dev/null $(TESTPKG)
	@echo "=== warm: compile again ==="; \
		time env CGO_ENABLED=1 $(if $(MOLD_LD),CGO_LDFLAGS=$(MOLD_LD),) \
		CC="ccache clang" CXX="ccache clang++" \
		CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" CCACHE_COMPRESS=1 \
		GOCACHE="$(GO_CACHE_ROOT)/gocache" GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
		go test -count=1 -c -o /dev/null $(TESTPKG)
	@echo "=== ccache stats (after) ==="; ccache -s 2>/dev/null || true

# Build the default protobuf prebuilt archive via Bazel (Linux/macOS).
extract-protobuf-lib:
	bash internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh

# Default protobuf prebuilt archive for this checkout.
prebuilt-libs: extract-protobuf-lib

verify-prebuilt-protobuf:
	bash scripts/verify-prebuilt-protobuf.sh

# Tarball of internal/ccall/go-protobuf/protobuf/lib for releases (after prebuilt-libs).
package-protobuf-prebuilt-tarball: verify-prebuilt-protobuf
	bash scripts/package-protobuf-prebuilt.sh

# Warn if vendored protobuf runtime is below Bazel 29.x-era macros (Tier B needs alignment). Strict: VERIFY_PROTOBUF_TIER_B_STRICT=1
verify-protobuf-tier-b-alignment:
	bash scripts/verify-protobuf-tier-b-alignment.sh

# Print supported googlesql_tier_b / googlesql_tier_b_absl tag combinations (see docs/prebuilt-absl-overlap.md).
# Optional: VERIFY_TIER_B_CGO_POLICY_ENFORCE=1 reserved for future strict checks (script still exits 0 until implemented).
verify-tier-b-cgo-policy:
	bash scripts/verify-tier-b-cgo-tag-policy.sh

# Refresh internal/ccall/protobuf/google/protobuf from Bazel external @com_google_protobuf (then vendorpatch + regenerate protos).
sync-protobuf-vendor-from-bazel:
	bash scripts/sync-protobuf-cpp-runtime-from-bazel.sh

regenerate-googlesql-cpp-protos:
	bash scripts/regenerate-googlesql-cpp-protos.sh

# Bazel-built libabsl_cgo.a (see internal/ccall/go-absl/extract_absl_cgo_lib.sh, docs/prebuilt-absl-overlap.md).
extract-absl-lib:
	bash internal/ccall/go-absl/extract_absl_cgo_lib.sh

prebuilt-libs-absl: extract-absl-lib

verify-prebuilt-absl:
	bash scripts/verify-prebuilt-absl.sh

# Tier B Abseil: migrated packages below (expand TESTPKG_PREBUILT_ABSL / BUILDPKG_ABSL as you add more).
local/build-prebuilt-absl: cache-dirs verify-prebuilt-absl
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags googlesql,googlesql_tier_b_absl $(BUILDPKG_ABSL)

# Default: migrated Tier B absl packages (override to widen, e.g. ./internal/ccall/go-absl/meta/...).
BUILDPKG_ABSL ?= ./internal/ccall/go-absl/meta/type_traits/ ./internal/ccall/go-absl/types/any/ ./internal/ccall/go-absl/types/bad_any_cast/ ./internal/ccall/go-absl/types/bad_any_cast_impl/ ./internal/ccall/go-absl/types/bad_optional_access/ ./internal/ccall/go-absl/types/bad_variant_access/ ./internal/ccall/go-absl/types/compare/ ./internal/ccall/go-absl/types/optional/ ./internal/ccall/go-absl/types/span/ ./internal/ccall/go-absl/types/variant/ ./internal/ccall/go-absl/base/config/ ./internal/ccall/go-absl/base/core_headers/ ./internal/ccall/go-absl/base/endian/ ./internal/ccall/go-absl/base/errno_saver/ ./internal/ccall/go-absl/base/prefetch/ ./internal/ccall/go-absl/utility/utility/
TESTPKG_PREBUILT_ABSL ?= ./internal/ccall/go-absl/meta/type_traits/ ./internal/ccall/go-absl/types/any/ ./internal/ccall/go-absl/types/bad_any_cast/ ./internal/ccall/go-absl/types/bad_any_cast_impl/ ./internal/ccall/go-absl/types/bad_optional_access/ ./internal/ccall/go-absl/types/bad_variant_access/ ./internal/ccall/go-absl/types/compare/ ./internal/ccall/go-absl/types/optional/ ./internal/ccall/go-absl/types/span/ ./internal/ccall/go-absl/types/variant/ ./internal/ccall/go-absl/base/config/ ./internal/ccall/go-absl/base/core_headers/ ./internal/ccall/go-absl/base/endian/ ./internal/ccall/go-absl/base/errno_saver/ ./internal/ccall/go-absl/base/prefetch/ ./internal/ccall/go-absl/utility/utility/

local/test-prebuilt-absl: cache-dirs verify-prebuilt-absl
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql,googlesql_tier_b_absl -v $(TESTPKG_PREBUILT_ABSL) -count=1

# Unified libgooglesql.a (GoogleSQL Bazel *.pic.o + C anchor); see docs/libgooglesql-unified.md.
extract-googlesql-unified-lib:
	bash internal/ccall/go-googlesql-unified/extract_googlesql_unified_lib.sh

prebuilt-libs-googlesql-unified: extract-googlesql-unified-lib

verify-prebuilt-googlesql-unified:
	bash scripts/verify-prebuilt-googlesql-unified.sh

# Root package slice that swaps the largest public/parser CGO shards to link-only bind.cc under
# googlesql_unified_prebuilt while still pulling libprotobuf_cgo.a via the normal go-protobuf package.
BUILDPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT ?= ./
# Default gate: analyzer CGO shard (startup-safe unified link). Full repo `./` also needs
# internal/ccall/go-googlesql/bind.cc split for unified like base/status (bind_linux !unified +
# bind_unified_prebuilt_*); until then override: TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT=./
TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT ?= ./internal/ccall/go-googlesql/public/analyzer/

local/build-prebuilt-googlesql-unified: cache-dirs verify-prebuilt-googlesql-unified
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_PREBUILT)" \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags googlesql,googlesql_unified_prebuilt ./internal/ccall/go-googlesql-unified/googlesqlunified/

local/build-prebuilt-googlesql-unified-root: cache-dirs verify-prebuilt-protobuf verify-prebuilt-googlesql-unified
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_PREBUILT)" \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags googlesql,googlesql_unified_prebuilt $(BUILDPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT)

# Default package is the analyzer CGO shard (see TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT). CI runs
# this target after local/build-prebuilt-googlesql-unified-root (see go-googlesql-unified-prebuilt.yml).
local/test-prebuilt-googlesql-unified-root: cache-dirs verify-prebuilt-protobuf verify-prebuilt-googlesql-unified
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_PREBUILT)" \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql,googlesql_unified_prebuilt -v $(TESTPKG_PREBUILT_GOOGLESQL_UNIFIED_ROOT) -count=1

# Root module tests (default TESTPKG=./) with unified prebuilt link-only root bind.cc + libgooglesql.a.
# Requires the same prebuilts as local/test-prebuilt-googlesql-unified-root. Startup may still
# SIGSEGV if protobuf/Abseil ownership across archives is inconsistent; see
# docs/unified-prebuilt-root-segfault-investigation.md.
local/test-root-unified: cache-dirs verify-prebuilt-protobuf verify-prebuilt-googlesql-unified
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_PREBUILT)" \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql,googlesql_unified_prebuilt -v $(TESTPKG) -count=1 $(GO_TEST_FLAGS)

# Link-only: compile the root unified-prebuilt test binary without running it (no startup SIGSEGV).
# Confirms CGO + duplicate-symbol posture after extract_protobuf_cgo_lib / bridge edits; see
# docs/unified-prebuilt-root-segfault-investigation.md.
local/compile-root-unified-test: cache-dirs verify-prebuilt-protobuf verify-prebuilt-googlesql-unified
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_PREBUILT)" \
	CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)' \
	CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql,googlesql_unified_prebuilt -c -o "$(GO_CACHE_ROOT)/googlesql_root_unified.test" $(TESTPKG)

smoke-link-googlesql-unified:
	bash scripts/smoke_link_googlesql_unified.sh

# Compile-only warm-up: same -race toolchain as tests; -run '^$' matches no tests.
# -exec /bin/true skips executing the linked test binary (still compiles/links it), so caches are
# warmed without running init/test harness code—handy when the harness would SIGSEGV (e.g. tight RAM).
docker/warm-cache: docker/build-dev
	docker run --rm $(DOCKER_DEV_ENV) $(DOCKER_DEV_VOLUMES) \
		-w /go-googlesql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "set -e; bash scripts/verify-prebuilt-protobuf.sh; \
		export CGO_CXXFLAGS='$(CGO_CXXFLAGS_PREBUILT)'; \
		export CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)'; \
		export CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)'; \
		go test -race -p $(GO_BUILD_P) -tags googlesql $(TESTPKG) -count=1 -run '^$$' -exec /bin/true"

# Preferred path for GoogleSQL upgrades and local CI parity: tests run inside $(DOCKER_DEV_IMAGE)
# with the working tree mounted and shared host paths for GOCACHE/GOMODCACHE.
# Do not run heavy tests in parallel with go-googlesqlite / bigquery-emulator on the same host (memory).
test: test/linux
test-docker: test/linux

test/linux: docker/build-dev
	docker run --rm $(DOCKER_DEV_ENV) $(DOCKER_DEV_VOLUMES) \
		-w /go-googlesql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "set -e; bash scripts/verify-prebuilt-protobuf.sh; \
		export CGO_CXXFLAGS='$(CGO_CXXFLAGS_PREBUILT)'; \
		export CGO_LDFLAGS_ALLOW='$(CGO_LDFLAGS_ALLOW_LIST)'; \
		export CGO_LDFLAGS='$(CGO_LDFLAGS_BASE)'; \
		go test -race -p $(GO_BUILD_P) -tags googlesql -v $(TESTPKG) -count=1"
