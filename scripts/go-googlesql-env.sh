#!/usr/bin/env bash
# Shared CGO / cache defaults for go-googlesql. Sourced from `.envrc` (direnv) and from Taskfile tasks.
# Usage: source path/to/scripts/go-googlesql-env.sh && go_googlesql_env_export

go_googlesql_env_export() {
	export GO_CACHE_ROOT="${GO_CACHE_ROOT:-$HOME/.cache/go-googlesql}"
	mkdir -p "$GO_CACHE_ROOT/gocache" "$GO_CACHE_ROOT/gomodcache" "$GO_CACHE_ROOT/ccache"

	# Match legacy Makefile: empty CGO_CXXFLAGS_PREBUILT must not skip -stdlib=libc++.
	if [[ ! -v CGO_CXXFLAGS_PREBUILT ]] || [[ -z "${CGO_CXXFLAGS_PREBUILT// }" ]]; then
		export CGO_CXXFLAGS_PREBUILT=-stdlib=libc++
	fi

	if command -v mold >/dev/null 2>&1; then
		export MOLD_LD=-fuse-ld=mold
	else
		export MOLD_LD=
	fi

	export CGO_LDFLAGS_ALLOW_LIST='-Wl,--no-gc-sections|-Wl,--allow-multiple-definition|-fuse-ld=mold|-Wl,--whole-archive|-Wl,--no-whole-archive|-Wl,--start-group|-Wl,--end-group|-stdlib=libc\+\+'
	export CGO_LDFLAGS_BASE="-Wl,--no-gc-sections -Wl,--allow-multiple-definition ${MOLD_LD} -stdlib=libc++"
	export GOOGLESQL_BUILD_TAGS=googlesql,googlesql_unified_prebuilt
	export GOCACHE="$GO_CACHE_ROOT/gocache"
	export GOMODCACHE="$GO_CACHE_ROOT/gomodcache"
	export CCACHE_DIR="$GO_CACHE_ROOT/ccache"
	export CC="${CGO_CC:-clang}"
	export CXX="${CGO_CXX:-clang++}"
	export CCACHE_COMPRESS=1

	local GO_BUILD_MEM_PER_JOB_KB="${GO_BUILD_MEM_PER_JOB_KB:-4194304}"
	local GO_BUILD_P_MAX="${GO_BUILD_P_MAX:-2}"
	local CPU
	CPU=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
	local P
	if [[ -r /proc/meminfo ]]; then
		P=$(awk -v per="$GO_BUILD_MEM_PER_JOB_KB" '/^MemAvailable:/ {print int($2 * 0.8 / per)}' /proc/meminfo)
	else
		P=$((CPU / 2))
	fi
	[[ -z "$P" || "$P" -lt 1 ]] && P=1
	[[ "$P" -gt "$CPU" ]] && P=$CPU
	[[ "$P" -gt "$GO_BUILD_P_MAX" ]] && P=$GO_BUILD_P_MAX
	export GO_BUILD_P="$P"
}
