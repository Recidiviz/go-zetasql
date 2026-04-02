DOCKER_IMAGE ?= go-zetasql
DOCKER_DEV_IMAGE ?= go-zetasql:dev
# Persist GOCACHE/GOMODCACHE across `docker run` test invocations (host paths so all repos can share).
# Use the same DOCKER_GO_CACHE_ROOT in go-zetasqlite / bigquery-emulator so one warm cache serves the stack.
DOCKER_GO_CACHE_ROOT ?= $(HOME)/.cache/go-zetasql-docker
# Default matches .github/workflows/go.yml (root package only). Set TESTPKG=./... to test all packages.
TESTPKG ?= ./

.PHONY: docker/build docker/build-dev docker-cache-dirs test test/linux test-docker

docker-cache-dirs:
	mkdir -p "$(DOCKER_GO_CACHE_ROOT)/gocache" "$(DOCKER_GO_CACHE_ROOT)/gomodcache"

docker/build:
	docker build -t $(DOCKER_IMAGE) .

docker/build-dev: docker-cache-dirs
	docker build -t $(DOCKER_DEV_IMAGE) --target dev .

# Preferred path for ZetaSQL upgrades and local CI parity: tests run inside $(DOCKER_DEV_IMAGE)
# with the working tree mounted and shared host paths for GOCACHE/GOMODCACHE.
# Do not run heavy tests in parallel with go-zetasqlite / bigquery-emulator on the same host (memory).
test: test/linux
test-docker: test/linux

test/linux: docker/build-dev
	docker run --rm \
		-e CGO_ENABLED=1 -e CC=clang -e CXX=clang++ \
		-v "$(CURDIR)":/go-zetasql \
		-v "$(DOCKER_GO_CACHE_ROOT)/gocache":/root/.cache/go-build \
		-v "$(DOCKER_GO_CACHE_ROOT)/gomodcache":/go/pkg/mod \
		-w /go-zetasql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "go test -race -v $(TESTPKG) -count=1"
