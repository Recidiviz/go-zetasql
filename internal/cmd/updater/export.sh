#!/bin/bash

BAZEL_GOOGLESQL=$(readlink bazel-googlesql)
CACHE_ROOT=$BAZEL_GOOGLESQL/../../
cp -r $CACHE_ROOT/* /tmp/
