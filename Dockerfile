# syntax=docker/dockerfile:1.7
FROM golang:1.24-bookworm AS base

ARG VERSION

RUN apt-get update && apt-get install -y --no-install-recommends clang ccache mold \
	&& rm -rf /var/lib/apt/lists/*

ENV CGO_ENABLED=1
ENV CC=clang
ENV CXX=clang++
# Faster final link for large C++ graphs (same idea as Makefile MOLD_LD on Linux hosts).
ENV CGO_LDFLAGS=-fuse-ld=mold
# ccache wraps clang/clang++ (same CC/CXX); persist CCACHE_DIR from the Makefile via volume.
ENV PATH="/usr/lib/ccache:${PATH}"
ENV CCACHE_COMPRESS=1
ENV CCACHE_DIR=/root/.ccache

WORKDIR /go-googlesql

# Local tests: `make docker/build-dev` builds this target only (Go + clang). Compilation runs inside
# `docker run` with host-mounted GOCACHE/GOMODCACHE so work is not duplicated by a separate image build.
FROM base AS dev
CMD ["bash"]

# Release / `docker build` default: download modules and verify compile. Uses BuildKit cache mounts (CI).
FROM base AS release
COPY go.mod go.sum ./
RUN --mount=type=cache,target=/go/pkg/mod \
	--mount=type=cache,target=/root/.cache/go-build \
	--mount=type=cache,target=/root/.ccache \
	go mod download
COPY . ./
RUN --mount=type=cache,target=/go/pkg/mod \
	--mount=type=cache,target=/root/.cache/go-build \
	--mount=type=cache,target=/root/.ccache \
	go install -buildmode=archive .
