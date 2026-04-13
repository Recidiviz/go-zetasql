#!/usr/bin/env bash
# Fail fast if unified libgooglesql.a is missing (see docs/libgooglesql-unified.md).
set -euo pipefail
REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"
GOOS_GOARCH="$(go env GOOS)_$(go env GOARCH)"
LIB="$REPO_ROOT/internal/ccall/go-googlesql-unified/lib/${GOOS_GOARCH}/libgooglesql.a"
if [[ ! -f "$LIB" ]]; then
	echo "prebuilt libgooglesql.a not found: $LIB" >&2
	echo "Build it with: task prebuilt:googlesql-unified  (requires bazelisk/bazel and a populated submodule)" >&2
	exit 1
fi
echo "ok: $LIB"
check_symbol() {
	local label="$1"
	local pattern="$2"
	if (nm -C "$LIB" 2>/dev/null || true) | grep -qE "$pattern"; then
		echo "ok: $label"
	else
		echo "missing expected libgooglesql.a symbol for $label: $pattern" >&2
		exit 1
	fi
}

# ICU major is embedded in the mangled namespace (icu_76::, icu_74::, …).
check_symbol "icu" 'icu_[0-9]+::Normalizer2::getNFKDInstance\(UErrorCode&\)'
check_symbol "re2" 're2::Prog::CompileSet'
check_symbol "googleapis date proto" 'google::type::Date::GetMetadata\(\) const'
check_symbol "reflection proto" 'googlesql::reflection::Column::Column\(google::protobuf::Arena\*\)'
check_symbol "parser ast enums" 'googlesql::ASTGraphPathSearchPrefixEnums_PathSearchPrefixType_descriptor\(\)'

# Strong (T) symbol overlap with libprotobuf_cgo.a should be empty: duplicate global definitions
# plus -Wl,--allow-multiple-definition caused undefined behavior at runtime (DescriptorPool init).
PROTO="$REPO_ROOT/internal/ccall/go-protobuf/protobuf/lib/${GOOS_GOARCH}/libprotobuf_cgo.a"
if [[ -f "$PROTO" ]] && command -v llvm-nm >/dev/null 2>&1; then
	n_overlap="$(comm -12 \
		<(llvm-nm "$LIB" 2>/dev/null | awk '$2=="T"{print $3}' | sort -u) \
		<(llvm-nm "$PROTO" 2>/dev/null | awk '$2=="T"{print $3}' | sort -u) | wc -l)"
	n_overlap="${n_overlap// /}"
	if [[ "${n_overlap:-0}" -ne 0 ]]; then
		echo "verify-prebuilt-googlesql-unified: duplicate global T symbols between libgooglesql.a and libprotobuf_cgo.a: count=$n_overlap" >&2
		exit 1
	fi
	echo "ok: no duplicate global (T) symbols vs libprotobuf_cgo.a"
fi
