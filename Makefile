DOCKER_IMAGE ?= go-zetasql
DOCKER_DEV_IMAGE ?= go-zetasql:dev
# Named volumes persist Go build/mod caches across repeated test runs (avoids full CGO rebuilds).
GOCACHE_VOLUME ?= go-zetasql-gocache
GOMODCACHE_VOLUME ?= go-zetasql-gomodcache

.PHONY: docker/build docker/build-dev test/linux

docker/build:
	docker build -t $(DOCKER_IMAGE) .

docker/build-dev:
	docker build -t $(DOCKER_DEV_IMAGE) .

# Tests the mounted working tree (not the layer baked at image build time).
# Reuses GOCACHE/GOMODCACHE volumes so incremental runs stay fast. Do not run
# heavy go-zetasql tests in parallel with go-zetasqlite / bigquery-emulator on
# the same host (memory).
test/linux: docker/build-dev
	docker run --rm \
		-e CGO_ENABLED=1 -e CC=clang -e CXX=clang++ \
		-v "$(CURDIR)":/go-zetasql \
		-v $(GOCACHE_VOLUME):/root/.cache/go-build \
		-v $(GOMODCACHE_VOLUME):/go/pkg/mod \
		-w /go-zetasql \
		$(DOCKER_DEV_IMAGE) \
		bash -c "go test -race -v ./ -count=1"
