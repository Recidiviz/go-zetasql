# syntax=docker/dockerfile:1.7
FROM golang:1.24-bookworm

ARG VERSION

RUN apt-get update && apt-get install -y --no-install-recommends clang \
	&& rm -rf /var/lib/apt/lists/*

ENV CGO_ENABLED=1
ENV CC=clang
ENV CXX=clang++

WORKDIR /go-zetasql

COPY go.mod go.sum ./
RUN --mount=type=cache,target=/go/pkg/mod \
	--mount=type=cache,target=/root/.cache/go-build \
	go mod download

COPY . ./

RUN --mount=type=cache,target=/go/pkg/mod \
	--mount=type=cache,target=/root/.cache/go-build \
	go install -buildmode=archive .
