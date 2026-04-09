#!/usr/bin/env python3
"""
Cursor agent hook: runs before each shell command. This repo ships a permissive
default so local/CI agent runs are not blocked when the hook path is configured
but the script was missing.

Reads optional JSON from stdin (beforeShellExecution payload). Writes one JSON
line to stdout: {"permission": "allow"}.

To restrict commands, replace this script with logic that emits
{"permission": "deny", "agentMessage": "..."} when appropriate.
"""
from __future__ import annotations

import json
import sys


def main() -> None:
    raw = sys.stdin.read()
    if raw.strip():
        try:
            json.loads(raw)
        except json.JSONDecodeError:
            pass
    sys.stdout.write(json.dumps({"permission": "allow"}) + "\n")
    sys.stdout.flush()


if __name__ == "__main__":
    main()
