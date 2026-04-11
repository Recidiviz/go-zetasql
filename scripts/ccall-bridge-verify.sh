#!/usr/bin/env bash
# Run bridge FQDN guard check (no full generator regen). See docs/bridge-generator-upgrades.md
set -euo pipefail
ROOT="$(git rev-parse --show-toplevel 2>/dev/null || true)"
if [[ -z "$ROOT" ]] || [[ ! -d "$ROOT/internal/cmd/generator" ]]; then
	ROOT="$(cd "$(dirname "$0")/.." && pwd)"
fi
cd "$ROOT/internal/cmd/generator"
exec go run . -verify-zetasql-fqdn
