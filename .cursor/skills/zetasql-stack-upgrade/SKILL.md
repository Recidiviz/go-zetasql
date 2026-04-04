---
name: zetasql-stack-upgrade
description: >-
  Upgrades the go-zetasql, go-zetasqlite, and bigquery-emulator stack to a new
  ZetaSQL/googlesql release tag: upstream delta review, submodule bump,
  protobuf-safe regeneration, builtin parity, emulator integration tests, and
  sequential CGO test runs. Use when the user says zetasql-upgrade, upgrade
  zetasql, bump googlesql or zetasql tag, or names a version like 2023.09.1.
---

# ZetaSQL stack upgrade

The full procedure lives in the Cursor custom command prompt:

- **Slash command:** `/zetasql-stack-upgrade` — source file: [.cursor/commands/zetasql-stack-upgrade.md](../../commands/zetasql-stack-upgrade.md)

Follow that document end-to-end. Supplementary bash templates and env vars: [reference.md](reference.md).
