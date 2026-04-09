DOCKER_IMAGE ?= go-googlesql
DOCKER_DEV_IMAGE ?= go-googlesql:dev
# Shared host tree for GOCACHE, GOMODCACHE, and ccache (CGO). Default matches go-googlesqlite and
# bigquery-emulator Makefiles so Docker runs and local/build share one warm cache.
GO_CACHE_ROOT ?= $(HOME)/.cache/go-googlesql
# Default matches .github/workflows/go.yml (root package only). Set TESTPKG=./... to test all packages.
TESTPKG ?= ./
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

.PHONY: docker/build docker/build-dev cache-dirs docker/warm-cache \
	local/build local/test local/test-tier-b local/build-prebuilt local/test-prebuilt \
	local/test-prebuilt-absl local/build-prebuilt-absl \
	local/build-prebuilt-googlesql-unified \
	prebuilt-libs prebuilt-libs-absl prebuilt-libs-googlesql-unified \
	verify-prebuilt-protobuf verify-prebuilt-absl verify-prebuilt-googlesql-unified smoke-link-googlesql-unified \
	verify-protobuf-tier-b-alignment verify-tier-b-cgo-policy sync-protobuf-vendor-from-bazel regenerate-googlesql-cpp-protos \
	profile-bottleneck extract-protobuf-lib extract-absl-lib extract-googlesql-unified-lib \
	test test/linux test-docker

cache-dirs:
	mkdir -p \
		"$(GO_CACHE_ROOT)/gocache" \
		"$(GO_CACHE_ROOT)/gomodcache" \
		"$(GO_CACHE_ROOT)/ccache"

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

# Tier B: libprotobuf_cgo.a comes from Bazel with libc++ (not libstdc++). Every CGO C++ TU must
# use the same -stdlib or template instantiations (e.g. ArenaStringPtr with std::string) mangle as
# std::__cxx11:: vs std::__1:: and the link fails with undefined protobuf internals.
CGO_CXXFLAGS_TIER_B ?= -stdlib=libc++

# --allow-multiple-definition: needed while multiple CGO TUs each embed overlapping C++ (incl.
# protobuf amalgamation). Removing it requires a single macro/link domain for protobuf+absl;
# see docs/protobuf-vendoring.md "Single-owner protobuf".

# Example: make local/build BUILDPKG=./internal/ccall/go-googlesql
local/build: cache-dirs
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags googlesql $(BUILDPKG)

# Same toolchain as local/build; mirrors test/linux but runs on the host (no -race unless you add it).
local/test: cache-dirs
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql -v $(TESTPKG) -count=1

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

# Optional: build libprotobuf_cgo.a via Bazel (Linux/macOS). Not used by default bind_*.go (amalgamation).
extract-protobuf-lib:
	bash internal/ccall/go-protobuf/protobuf/extract_protobuf_cgo_lib.sh

# Alias for docs/prebuilt-cgo.md — produces Tier B protobuf archive.
prebuilt-libs: extract-protobuf-lib

verify-prebuilt-protobuf:
	bash scripts/verify-prebuilt-protobuf.sh

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

# Prebuilt Tier B: requires `make prebuilt-libs` first. Fails fast if libprotobuf_cgo.a is missing.
local/build-prebuilt: cache-dirs verify-prebuilt-protobuf
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_TIER_B)" \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags googlesql,googlesql_tier_b $(BUILDPKG)

local/test-prebuilt: cache-dirs verify-prebuilt-protobuf
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_TIER_B)" \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql,googlesql_tier_b -v $(TESTPKG) -count=1

# Bazel-built libabsl_cgo.a (see internal/ccall/go-absl/extract_absl_cgo_lib.sh, docs/prebuilt-absl-overlap.md).
extract-absl-lib:
	bash internal/ccall/go-absl/extract_absl_cgo_lib.sh

prebuilt-libs-absl: extract-absl-lib

verify-prebuilt-absl:
	bash scripts/verify-prebuilt-absl.sh

# Tier B Abseil: migrated packages below (expand TESTPKG_PREBUILT_ABSL / BUILDPKG_ABSL as you add more).
local/build-prebuilt-absl: cache-dirs verify-prebuilt-absl
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
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
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
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

local/build-prebuilt-googlesql-unified: cache-dirs verify-prebuilt-googlesql-unified
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags googlesql,googlesql_unified_prebuilt ./internal/ccall/go-googlesql-unified/googlesqlunified/

smoke-link-googlesql-unified:
	bash scripts/smoke_link_googlesql_unified.sh

# Experimental: go-protobuf links libprotobuf_cgo.a (see bind_tier_b.go, docs/tier-b-absl-protobuf.md).
# Requires `make extract-protobuf-lib`. Expect failures until global_exclude_replace_names + unified ABI land.
local/test-tier-b: cache-dirs
	CGO_ENABLED=1 \
	CGO_CXXFLAGS="$(CGO_CXXFLAGS_TIER_B)" \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags googlesql,googlesql_tier_b -v $(TESTPKG) -count=1

# Compile-only warm-up: same -race toolchain as tests, but -run '^$' matches no tests so this only
# populates gomodcache/gocache/ccache. Run after toolchain upgrades or cold cache; then test/linux stays incremental.
docker/warm-cache: docker/build-dev
	docker run --rm $(DOCKER_DEV_ENV) $(DOCKER_DEV_VOLUMES) \
		-w /go-googlesql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "go test -race $(TESTPKG) -count=1 -run '^$$'"

# Preferred path for GoogleSQL upgrades and local CI parity: tests run inside $(DOCKER_DEV_IMAGE)
# with the working tree mounted and shared host paths for GOCACHE/GOMODCACHE.
# Do not run heavy tests in parallel with go-googlesqlite / bigquery-emulator on the same host (memory).
test: test/linux
test-docker: test/linux

test/linux: docker/build-dev
	docker run --rm $(DOCKER_DEV_ENV) $(DOCKER_DEV_VOLUMES) \
		-w /go-googlesql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "go test -race -v $(TESTPKG) -count=1"
