DOCKER_IMAGE ?= go-zetasql
DOCKER_DEV_IMAGE ?= go-zetasql:dev
# Persist GOCACHE/GOMODCACHE (and ccache for CGO) across `docker run`. Use the same paths in
# go-zetasqlite / bigquery-emulator so one warm cache serves the stack.
DOCKER_GO_CACHE_ROOT ?= $(HOME)/.cache/go-zetasql-docker
# Default matches .github/workflows/go.yml (root package only). Set TESTPKG=./... to test all packages.
TESTPKG ?= ./

DOCKER_DEV_ENV := \
	-e CGO_ENABLED=1 \
	-e CC=clang \
	-e CXX=clang++ \
	-e CCACHE_DIR=/root/.ccache \
	-e CCACHE_COMPRESS=1

DOCKER_DEV_VOLUMES := \
	-v "$(CURDIR)":/go-zetasql \
	-v "$(DOCKER_GO_CACHE_ROOT)/gocache":/root/.cache/go-build \
	-v "$(DOCKER_GO_CACHE_ROOT)/gomodcache":/go/pkg/mod \
	-v "$(DOCKER_GO_CACHE_ROOT)/ccache":/root/.ccache

.PHONY: docker/build docker/build-dev docker-cache-dirs docker/warm-cache test test/linux test-docker

docker-cache-dirs:
	mkdir -p \
		"$(DOCKER_GO_CACHE_ROOT)/gocache" \
		"$(DOCKER_GO_CACHE_ROOT)/gomodcache" \
		"$(DOCKER_GO_CACHE_ROOT)/ccache"

docker/build:
	docker build -t $(DOCKER_IMAGE) .

docker/build-dev: docker-cache-dirs
	docker build -t $(DOCKER_DEV_IMAGE) --target dev .

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
