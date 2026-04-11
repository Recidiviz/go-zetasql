#!/usr/bin/env bash
# List bind.cc files that #include native .cc sources; optional --check for link-only invariant.
# See docs/cgo-consolidation.md
set -euo pipefail

ROOT="$(git rev-parse --show-toplevel 2>/dev/null || true)"
if [[ -z "$ROOT" ]] || [[ ! -d "$ROOT/internal/ccall" ]]; then
	ROOT="$(cd "$(dirname "$0")/.." && pwd)"
fi
CCALL="$ROOT/internal/ccall"

usage() {
	echo "Usage: $0 [--summary | --list | --check | --help]" >&2
	echo "  --summary  Print counts of bind.cc with #include \"*.cc\" by top-level ccall subtree." >&2
	echo "  --list     Print one path per line (bind.cc that includes a .cc file)." >&2
	echo "  --check    Fail if any bind.cc contains 'Link-only bind.cc' AND #includes a .cc source." >&2
	echo "  (default)  Same as --summary" >&2
}

list_bind_with_cc() {
	find "$CCALL" -name bind.cc -print0 | while IFS= read -r -d '' f; do
		if grep -qE '#include "[^"]+\.cc"' "$f" 2>/dev/null; then
			printf '%s\n' "$f"
		fi
	done
}

cmd_summary() {
	echo "CGO shard inventory (bind.cc that #include a .cc file)"
	echo "Repo: $ROOT"
	echo ""
	local total
	total="$(list_bind_with_cc | wc -l)"
	echo "Total bind.cc with #include \"*.cc\": $total"
	echo ""
	echo "By subtree (first path component under internal/ccall):"
	list_bind_with_cc | sed "s|^$CCALL/||" | awk -F/ '{print $1}' | sort | uniq -c | sort -nr
	echo ""
	echo "Link-only bind.cc files (header marker):"
	find "$CCALL" -name bind.cc -print0 | while IFS= read -r -d '' f; do
		if grep -q 'Link-only bind\.cc' "$f" 2>/dev/null; then
			printf '%s\n' "$f"
		fi
	done | wc -l | awk '{print "  count: " $1}'
}

cmd_check() {
	local bad=0
	while IFS= read -r -d '' f; do
		if grep -q 'Link-only bind\.cc' "$f" 2>/dev/null && grep -qE '#include "[^"]+\.cc"' "$f" 2>/dev/null; then
			echo "ERROR: link-only bind.cc must not #include .cc sources: $f" >&2
			bad=1
		fi
	done < <(find "$CCALL" -name bind.cc -print0)
	exit "$bad"
}

case "${1:---summary}" in
	--help|-h)
		usage
		;;
	--list)
		list_bind_with_cc | sort
		;;
	--check)
		cmd_check
		;;
	--summary|"")
		cmd_summary
		;;
	*)
		echo "Unknown option: $1" >&2
		usage
		exit 2
		;;
esac
