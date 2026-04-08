DOCKER_IMAGE ?= go-zetasql
DOCKER_DEV_IMAGE ?= go-zetasql:dev
# Shared host tree for GOCACHE, GOMODCACHE, and ccache (CGO). Default matches go-zetasqlite and
# bigquery-emulator Makefiles so Docker runs and local/build share one warm cache.
GO_CACHE_ROOT ?= $(HOME)/.cache/go-zetasql
# Default matches .github/workflows/go.yml (root package only). Set TESTPKG=./... to test all packages.
TESTPKG ?= ./
# For local/build: package pattern passed to go build (default all modules under repo root).
BUILDPKG ?= ./...

# Parallel go build/test workers (-p). CGO + ZetaSQL C++ amalgamation is very memory-heavy; each
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

# When `mold` is on PATH (e.g. go-zetasql:dev image), speed up the final link step.
MOLD_LD := $(shell command -v mold >/dev/null 2>&1 && echo -fuse-ld=mold)

DOCKER_DEV_ENV := \
	-e CGO_ENABLED=1 \
	-e CC=clang \
	-e CXX=clang++ \
	-e CCACHE_DIR=/root/.ccache \
	-e CCACHE_COMPRESS=1

DOCKER_DEV_VOLUMES := \
	-v "$(CURDIR)":/go-zetasql \
	-v "$(GO_CACHE_ROOT)/gocache":/root/.cache/go-build \
	-v "$(GO_CACHE_ROOT)/gomodcache":/go/pkg/mod \
	-v "$(GO_CACHE_ROOT)/ccache":/root/.ccache

.PHONY: docker/build docker/build-dev cache-dirs docker/warm-cache \
	local/build local/test profile-bottleneck extract-protobuf-lib \
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

# --allow-multiple-definition: needed while multiple CGO TUs each embed overlapping C++ (incl.
# protobuf amalgamation). Removing it requires a single macro/link domain for protobuf+absl;
# see docs/protobuf-vendoring.md "Single-owner protobuf".

# Example: make local/build BUILDPKG=./internal/ccall/go-zetasql
local/build: cache-dirs
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags zetasql $(BUILDPKG)

# Same toolchain as local/build; mirrors test/linux but runs on the host (no -race unless you add it).
local/test: cache-dirs
	CGO_ENABLED=1 \
	CGO_LDFLAGS_ALLOW='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold' \
	CGO_LDFLAGS='-Wl,--no-gc-sections -Wl,--allow-multiple-definition $(MOLD_LD)' \
	CC="$(CGO_CC)" \
	CXX="$(CGO_CXX)" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags zetasql -v $(TESTPKG) -count=1

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

# Compile-only warm-up: same -race toolchain as tests, but -run '^$' matches no tests so this only
# populates gomodcache/gocache/ccache. Run after toolchain upgrades or cold cache; then test/linux stays incremental.
docker/warm-cache: docker/build-dev
	docker run --rm $(DOCKER_DEV_ENV) $(DOCKER_DEV_VOLUMES) \
		-w /go-zetasql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "go test -race $(TESTPKG) -count=1 -run '^$$'"

# Preferred path for ZetaSQL upgrades and local CI parity: tests run inside $(DOCKER_DEV_IMAGE)
# with the working tree mounted and shared host paths for GOCACHE/GOMODCACHE.
# Do not run heavy tests in parallel with go-zetasqlite / bigquery-emulator on the same host (memory).
test: test/linux
test-docker: test/linux

test/linux: docker/build-dev
	docker run --rm $(DOCKER_DEV_ENV) $(DOCKER_DEV_VOLUMES) \
		-w /go-zetasql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "go test -race -v $(TESTPKG) -count=1"
