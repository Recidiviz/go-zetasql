#!/usr/bin/env python3
"""
Scan Bazel BUILD files under a tree (intended for internal/ccall/googlesql).

Checks (all optional except legacy-name scan):

  A) Legacy filenames: paths containing "zetasql" (case-insensitive). Useful
     after GoogleSQL tree renames when old path segments remain in filenames.
     On by default.

  B) Orphan sources: hand-written source-like files under a package directory
     whose relative path never appears as a substring in that package's BUILD
     file. Skips packages that use glob(. Excludes generated protobuf
     (*.pb.h, *.pb.cc, *.pb.c) by default.

  C) Missing refs: quoted paths in BUILD that look like local files but are
     absent on disk. Skips glob patterns (contains '*'). Often noisy on a
     partial vendor tree — off by default.

This is heuristic; glob(), generated outputs, and label-only references
require human judgment.

Usage:
  ./scripts/ccall-build-orphan-check.py
  ./scripts/ccall-build-orphan-check.py --root internal/ccall/googlesql
  ./scripts/ccall-build-orphan-check.py --orphans
  ./scripts/ccall-build-orphan-check.py --orphans --missing-refs
  ./scripts/ccall-build-orphan-check.py --no-legacy-zetasql-names --orphans
  ./scripts/ccall-build-orphan-check.py --json --fail-on-findings

Exit code: 0 unless --fail-on-findings and something was reported.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
from pathlib import Path
from typing import Iterable

LOCAL_PATH_SUFFIXES = (
    "cc",
    "cpp",
    "c",
    "h",
    "hh",
    "hpp",
    "inc",
    "proto",
    "tm",
    "l",
    "y",
    "py",
    "md",
    "txt",
    "textproto",
    "json",
    "template",
    "bzl",
    "bazel",
    "yaml",
    "yml",
)

_exts = "|".join(sorted(set(LOCAL_PATH_SUFFIXES), key=len, reverse=True))
_QUOTED_FILE = re.compile(rf'["\']([^"\']+\.(?:{_exts}))["\']')

ORPHAN_SUFFIXES = frozenset(
    {
        ".cc",
        ".cpp",
        ".c",
        ".h",
        ".hh",
        ".hpp",
        ".inc",
        ".proto",
        ".tm",
        ".l",
        ".y",
        ".py",
        ".template",
    }
)

BUILD_NAMES = ("BUILD", "BUILD.bazel")


def _git_toplevel() -> Path | None:
    try:
        out = subprocess.run(
            ["git", "rev-parse", "--show-toplevel"],
            capture_output=True,
            text=True,
            check=True,
        )
        p = Path(out.stdout.strip())
        return p if p.is_dir() else None
    except (OSError, subprocess.CalledProcessError):
        return None


def find_build_files(root: Path) -> list[Path]:
    builds: list[Path] = []
    for name in BUILD_NAMES:
        builds.extend(root.rglob(name))
    return sorted(set(builds))


def subpackage_dirs(package_dir: Path) -> list[Path]:
    out: list[Path] = []
    for child in sorted(package_dir.iterdir()):
        if not child.is_dir():
            continue
        if any((child / bn).is_file() for bn in BUILD_NAMES):
            out.append(child)
    return out


def iter_owned_source_files(package_dir: Path) -> Iterable[Path]:
    subs = subpackage_dirs(package_dir)
    sub_resolved = {s.resolve() for s in subs}

    for dirpath, dirnames, filenames in os.walk(package_dir):
        pdir = Path(dirpath)
        if pdir.resolve() == package_dir.resolve():
            dirnames[:] = [
                d
                for d in dirnames
                if (package_dir / d).resolve() not in sub_resolved
            ]
        for fn in filenames:
            fp = pdir / fn
            if fp.name in BUILD_NAMES:
                continue
            suf = fp.suffix.lower()
            if fp.name.endswith(".cc.template"):
                yield fp
            elif suf in ORPHAN_SUFFIXES:
                yield fp


def should_skip_orphan_file(path: Path, include_generated_pb: bool) -> bool:
    if include_generated_pb:
        return False
    n = path.name.lower()
    if n.endswith(".pb.h") or n.endswith(".pb.cc") or n.endswith(".pb.c"):
        return True
    return False


def filter_local_path_candidate(raw: str) -> bool:
    if "//" in raw:
        return False
    if raw.startswith("@"):
        return False
    if "$(location" in raw or "${" in raw:
        return False
    if raw.startswith(":"):
        return False
    if "*" in raw:
        return False
    return True


def extract_quoted_paths(build_text: str) -> list[str]:
    return [m.group(1) for m in _QUOTED_FILE.finditer(build_text)]


def check_missing_refs(package_dir: Path, build_text: str) -> list[str]:
    missing: list[str] = []
    for raw in extract_quoted_paths(build_text):
        if not filter_local_path_candidate(raw):
            continue
        candidate = package_dir / raw
        if candidate.exists():
            continue
        missing.append(raw)
    return missing


def check_orphans(
    package_dir: Path,
    build_text: str,
    include_generated_pb: bool,
) -> tuple[list[str], str | None]:
    if "glob(" in build_text:
        return [], "skip: glob("

    orphans: list[str] = []
    for fp in iter_owned_source_files(package_dir):
        if should_skip_orphan_file(fp, include_generated_pb):
            continue
        rel = fp.relative_to(package_dir).as_posix()
        if rel not in build_text:
            orphans.append(rel)
    return sorted(orphans), None


def find_legacy_zetasql_names(root: Path) -> list[str]:
    out: list[str] = []
    for p in root.rglob("*"):
        if not p.is_file():
            continue
        if "zetasql" not in p.name.lower():
            continue
        out.append(str(p.relative_to(root)))
    return sorted(out)


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument(
        "--root",
        default="internal/ccall/googlesql",
        help="Directory root to scan (default: internal/ccall/googlesql)",
    )
    ap.add_argument("--json", action="store_true", help="Emit JSON report")
    ap.add_argument(
        "--fail-on-findings",
        action="store_true",
        help="Exit 1 when any enabled check reports findings",
    )
    ap.add_argument(
        "--no-legacy-zetasql-names",
        action="store_true",
        help='Disable scan for files whose names contain "zetasql" (legacy spelling; default: scan enabled)',
    )
    ap.add_argument(
        "--orphans",
        action="store_true",
        help="Report source-like files not mentioned in BUILD text",
    )
    ap.add_argument(
        "--orphans-include-generated-pb",
        action="store_true",
        help="With --orphans, also flag *.pb.h / *.pb.cc / *.pb.c (very noisy)",
    )
    ap.add_argument(
        "--missing-refs",
        action="store_true",
        help="Report quoted local paths in BUILD that are missing on disk",
    )
    args = ap.parse_args()
    legacy_zetasql_names = not args.no_legacy_zetasql_names

    root = Path(args.root)
    if not root.is_dir():
        tl = _git_toplevel()
        if tl:
            cand = tl / args.root
            if cand.is_dir():
                root = cand
        if not root.is_dir():
            print(f"error: root is not a directory: {args.root}", file=sys.stderr)
            return 2

    findings: dict = {
        "root": str(root.resolve()),
        "missing_refs": [],
        "orphans": [],
        "skipped_glob_packages": [],
        "legacy_zetasql_names": [],
    }

    for build_path in find_build_files(root):
        package_dir = build_path.parent
        try:
            build_text = build_path.read_text(encoding="utf-8", errors="replace")
        except OSError as e:
            print(f"warning: could not read {build_path}: {e}", file=sys.stderr)
            continue

        if args.missing_refs:
            for m in check_missing_refs(package_dir, build_text):
                findings["missing_refs"].append(
                    {"build": str(build_path), "missing": m}
                )

        if args.orphans:
            orphans, skip_reason = check_orphans(
                package_dir,
                build_text,
                include_generated_pb=args.orphans_include_generated_pb,
            )
            if skip_reason:
                findings["skipped_glob_packages"].append(
                    {"build": str(build_path), "reason": skip_reason}
                )
            else:
                for o in orphans:
                    findings["orphans"].append(
                        {"build": str(build_path), "orphan": o}
                    )

    if legacy_zetasql_names:
        findings["legacy_zetasql_names"] = [
            {"path": p} for p in find_legacy_zetasql_names(root)
        ]

    n_missing = len(findings["missing_refs"])
    n_orphans = len(findings["orphans"])
    n_legacy = len(findings["legacy_zetasql_names"])

    if args.json:
        print(json.dumps(findings, indent=2))
    else:
        print(f"ccall-build-orphan-check: root={root.resolve()}")
        print()
        if args.missing_refs:
            if findings["missing_refs"]:
                print("Missing referenced files (quoted in BUILD but not on disk):")
                for item in findings["missing_refs"]:
                    print(f"  {item['build']}")
                    print(f"    missing: {item['missing']}")
                print()
            else:
                print("Missing referenced files: none")
                print()

        if args.orphans:
            if findings["orphans"]:
                print(
                    "Orphan source-like files (path not substring in BUILD; "
                    "glob() skipped; *.pb.* excluded unless "
                    "--orphans-include-generated-pb):"
                )
                for item in findings["orphans"]:
                    print(f"  {item['build']}")
                    print(f"    orphan: {item['orphan']}")
                print()
            else:
                print("Orphan candidates: none")
                print()

            print(
                f"Packages skipped for orphan scan (glob): "
                f"{len(findings['skipped_glob_packages'])}"
            )

        if legacy_zetasql_names:
            print()
            if findings["legacy_zetasql_names"]:
                print(
                    "Paths with legacy 'zetasql' in the filename (review for stale duplicates):"
                )
                for item in findings["legacy_zetasql_names"]:
                    print(f"  {item['path']}")
            else:
                print("Legacy zetasql-spelling filenames: none")

        print()
        parts = []
        if legacy_zetasql_names:
            parts.append(f"legacy_zetasql={n_legacy}")
        if args.missing_refs:
            parts.append(f"missing_refs={n_missing}")
        if args.orphans:
            parts.append(f"orphans={n_orphans}")
        print("Summary: " + ", ".join(parts) if parts else "Summary: (no checks enabled)")

    exit_code = 0
    if args.fail_on_findings:
        if args.missing_refs and n_missing:
            exit_code = 1
        if args.orphans and n_orphans:
            exit_code = 1
        if legacy_zetasql_names and n_legacy:
            exit_code = 1
    return exit_code


if __name__ == "__main__":
    sys.exit(main())
