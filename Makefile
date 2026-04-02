DOCKER_IMAGE ?= go-zetasql
DOCKER_DEV_IMAGE ?= go-zetasql:dev
# Shared host tree for GOCACHE, GOMODCACHE, and ccache (CGO). Default matches go-zetasqlite and
# bigquery-emulator Makefiles so Docker runs and local/build share one warm cache.
GO_CACHE_ROOT ?= $(HOME)/.cache/go-zetasql
# Default matches .github/workflows/go.yml (root package only). Set TESTPKG=./... to test all packages.
TESTPKG ?= ./
# For local/build: package pattern passed to go build (default all modules under repo root).
BUILDPKG ?= ./...

# Parallel go build/test workers (-p). CGO compiles are memory-heavy; default caps jobs from
# ~80% of MemAvailable (Linux /proc/meminfo) divided by GO_BUILD_MEM_PER_JOB_KB (~2GiB per job).
# Override: make local/build GO_BUILD_P=4  OR  GO_BUILD_MEM_PER_JOB_KB=1572864 (1.5GiB).
GO_BUILD_MEM_PER_JOB_KB ?= 2097152
GO_BUILD_P ?= $(shell \
	CPU=$$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4); \
	if [ -r /proc/meminfo ]; then \
		P=$$(awk -v per="$(GO_BUILD_MEM_PER_JOB_KB)" '/^MemAvailable:/ {print int($$2 * 0.8 / per)}' /proc/meminfo); \
	else \
		P=$$((CPU / 2)); \
	fi; \
	if [ -z "$$P" ] || [ "$$P" -lt 1 ] 2>/dev/null; then P=1; fi; \
	if [ "$$P" -gt "$$CPU" ] 2>/dev/null; then P=$$CPU; fi; \
	echo "$$P")

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
	local/build local/test \
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

# --- Local host (no Docker): ccache + clang + same GO_CACHE_ROOT as Docker ----------
# Requires: clang, clang++, ccache on PATH.

# Example: make local/build BUILDPKG=./internal/ccall/go-zetasql
local/build: cache-dirs
	CGO_ENABLED=1 \
	CC="ccache clang" \
	CXX="ccache clang++" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go build -p "$(GO_BUILD_P)" -tags zetasql $(BUILDPKG)

# Same toolchain as local/build; mirrors test/linux but runs on the host (no -race unless you add it).
local/test: cache-dirs
	CGO_ENABLED=1 \
	CC="ccache clang" \
	CXX="ccache clang++" \
	CCACHE_DIR="$(GO_CACHE_ROOT)/ccache" \
	CCACHE_COMPRESS=1 \
	GOCACHE="$(GO_CACHE_ROOT)/gocache" \
	GOMODCACHE="$(GO_CACHE_ROOT)/gomodcache" \
	go test -p "$(GO_BUILD_P)" -tags zetasql -v $(TESTPKG) -count=1

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
