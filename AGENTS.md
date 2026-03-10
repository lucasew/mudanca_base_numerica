# Project Conventions & Operational Memory

This repository is governed by specific rules and directory conventions. Maintainers and agents should respect these layout patterns for any future structural changes.

## Directory Structure & Responsibilities

- `src/` -> Core business logic, domain models, and shared utilities.
  - Examples: `basecalc.c` (domain logic), `error_reporter.c` (centralized utility).
- `tests/` -> Isolated test files strictly responsible for validating business rules.
- `main.c` -> Entrypoint. Responsible for routing interactive CLI I/O and routing the `--test` flag.

## Centralized Error Reporting

- All codebase errors that are unrecoverable or denote invalid usage must be funneled through the centralized error reporting utility (`src/error_reporter.h`).
- Avoid raw `printf` and `abort` outside of the centralized error handler context.

## General Coding Standards

- No downloaded binaries, installers, or generated tool artifacts (e.g. `basecalc`) should be committed.
- Pin tools with `mise` (always avoid `latest` or `lts` aliases).
- Keep formatting strict to the defined `clang-format` version.
