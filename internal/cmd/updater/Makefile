# Docker builds upstream google/googlesql at internal/cmd/updater/googlesql.ref and exports
# Bazel artifacts into ./cache; then the Go updater copies into internal/ccall.
GOOGLESQL_REF ?= $(shell tr -d ' \n\r' < googlesql.ref)
IMAGE ?= googlesql-updater
REPO_ROOT := $(abspath $(CURDIR)/../../..)

.PHONY: build export-cache update

build:
	docker build -t $(IMAGE) --build-arg GOOGLESQL_REF=$(GOOGLESQL_REF) .

# Populate internal/cmd/updater/cache (external/, execroot/googlesql/, googlesql/googlesql/).
export-cache: build
	docker run --rm -v "$(CURDIR)/cache:/out" $(IMAGE) /out

# Export cache from Docker, then run the updater from the repo root (single root go.mod).
update: export-cache
	cd $(REPO_ROOT) && go run ./internal/cmd/updater

# Legacy alias
export: export-cache
