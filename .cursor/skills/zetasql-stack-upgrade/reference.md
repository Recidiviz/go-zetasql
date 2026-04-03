# zetasql-stack-upgrade — reference

## Environment layout

Set these to absolute paths for your machine (example: sibling repos under `~/Code`):

```bash
export GO_ZETASQL_ROOT="${GO_ZETASQL_ROOT:-$HOME/Code/go-zetasql}"
export GO_ZETASQLITE_ROOT="${GO_ZETASQLITE_ROOT:-$HOME/Code/go-zetasqlite}"
export BIGQUERY_EMULATOR_ROOT="${BIGQUERY_EMULATOR_ROOT:-$HOME/Code/bigquery-emulator}"
export GOOGLESQL_ROOT="${GOOGLESQL_ROOT:-$HOME/Code/googlesql}"
```

Use **`GOOGLESQL_ROOT`** for `git log` / `git diff` between release tags (upstream may be **google/googlesql** or **google/zetasql**; tags like `2023.09.1` should match the submodule release you target).

The **go-zetasql** submodule path (for checkout inside the repo):

```text
$GO_ZETASQL_ROOT/internal/cmd/updater/zetasql
```

## Canonical tag and branch

- **Tag:** `YYYY.MM.P` (e.g. `2023.09.1`).
- **Branch:** `refactor/upgrade-to-2023.09.1` (dots, not hyphens in the version segment).

```bash
TAG="2023.09.1"
BRANCH="refactor/upgrade-to-${TAG}"
```

## Stash and branch (repeat per repo)

```bash
upgrade_repo() {
  local root="$1"
  local tag="$2"
  local branch="refactor/upgrade-to-${tag}"
  git -C "$root" status
  if ! git -C "$root" diff --quiet || ! git -C "$root" diff --cached --quiet; then
    git -C "$root" stash push -m "wip: pre zetasql upgrade to ${tag}"
  fi
  git -C "$root" fetch --all --prune
  if git -C "$root" show-ref --verify --quiet "refs/heads/${branch}"; then
    git -C "$root" checkout "$branch"
  else
    git -C "$root" checkout -b "$branch"
  fi
}

# upgrade_repo "$GO_ZETASQL_ROOT" "$TAG"
# upgrade_repo "$GO_ZETASQLITE_ROOT" "$TAG"
# upgrade_repo "$BIGQUERY_EMULATOR_ROOT" "$TAG"
```

## Upstream delta

```bash
FROM_TAG="2023.08.1"   # example; set from submodule or docs
TO_TAG="$TAG"

git -C "$GOOGLESQL_ROOT" fetch --tags
git -C "$GOOGLESQL_ROOT" log --oneline "${FROM_TAG}..${TO_TAG}"
git -C "$GOOGLESQL_ROOT" diff --stat "${FROM_TAG}..${TO_TAG}"
```

## Submodule bump (go-zetasql)

```bash
cd "$GO_ZETASQL_ROOT/internal/cmd/updater/zetasql"
git fetch --tags
git checkout "$TO_TAG"
git submodule status
cd "$GO_ZETASQL_ROOT"
# git add internal/cmd/updater/zetasql && git commit -m "chore(deps): bump zetasql submodule to ${TO_TAG}"
```

## Protobuf / vendorpatch (go-zetasql repo root)

```bash
cd "$GO_ZETASQL_ROOT"
# Optional: preserve protobuf tree during updater experiments
# export GO_ZETASQL_SKIP_PROTOBUF_COPY=1

go run ./internal/cmd/vendorpatch
# or: ./scripts/apply-vendor-patches.sh
```

Deep playbook: [docs/protobuf-vendoring.md](../../docs/protobuf-vendoring.md).

## Shared Go cache (stack tests)

```bash
export GOCACHE="${GOCACHE:-$HOME/.cache/go-zetasql-stack}"
export GOMODCACHE="${GOMODCACHE:-$HOME/.cache/go-mod}"
mkdir -p "$GOCACHE" "$GOMODCACHE"
export CGO_ENABLED=1
export CXX=clang++
```

## Tests (sequential — one repo at a time)

**go-zetasql** (from repo root):

```bash
cd "$GO_ZETASQL_ROOT"
make local/test
# or: make test/linux
# narrow: TESTPKG=./internal/... make local/test
```

**go-zetasqlite:**

```bash
cd "$GO_ZETASQLITE_ROOT"
go test -tags zetasql -count=1 .
```

**bigquery-emulator:**

```bash
cd "$BIGQUERY_EMULATOR_ROOT"
go test -count=1 ./...
```

## Existing upgrade delta docs (examples)

Browse [docs/](../../docs/) for files matching `googlesql-upgrade-*.md` — use as templates for new `docs/googlesql-upgrade-delta-<from>-to-<to>.md`.
