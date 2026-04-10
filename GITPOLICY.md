# Git Workflow for Snakemake Pipeline (IEC 62304 Prototype)

This document defines the Git workflow and best practices for developing the Snakemake pipeline (v9.17.2) under an IEC 62304-oriented prototype setup.

---

# 1. Core Principles

* `main` branch must always be:

  * Stable
  * Reproducible
  * Passing CI
* No direct commits to `main`
* All changes go through Pull Requests (PRs)
* One branch = one topic

---

# 2. Branching Strategy

## Long-lived branches

* `main`: production-ready code only

## Short-lived branches

Use descriptive prefixes:

* `feature/...` → new functionality
* `fix/...` → bug fixes
* `refactor/...` → internal improvements
* `docs/...` → documentation changes
* `test/...` → testing only
* `chore/...` → CI, tooling, maintenance
* `hotfix/...` → urgent fixes on main

# 3. Daily Workflow

```bash
# Start from latest main
git checkout main
git pull origin main

# Create new branch
git checkout -b feature/my-feature
```

Work in small increments:

```bash
git add <files>
git commit -m "feat(scope): description"
```

Push branch:

```bash
git push -u origin feature/my-feature
```

Open a Pull Request into `main`.

---

# 4. Commit Massage Convention

Format:

```
type(scope): short description
```

### Types

* `feat` – new feature
* `fix` – bug fix
* `refactor` – internal change
* `test` – tests
* `docs` – documentation
* `chore` – maintenance
* `ci` – CI/CD changes

### Examples

```
feat(qc): add FastQC summary rule
fix(config): validate missing reference path
test(trimming): add edge-case tests
docs(setup): describe installation
```

---

# 6. Pull Request (PR) Guidelines

Each PR must include:

```
## What
Describe the change

## Why
Reason for the change

## Impact
Affected components (rules, configs, outputs)

## Validation
- [ ] dry-run passed
- [ ] tests passed
- [ ] integration tested (if applicable)
- [ ] docs updated (if needed)

## Notes
Risks or follow-ups
```

---

# 8. Keeping Branches Updated

```bash
git checkout main
git pull origin main

git checkout feature/my-feature
git rebase main
```

Resolve conflicts if needed:

```bash
git add <file>
git rebase --continue
```

Push updated branch:

```bash
git push --force-with-lease
```

---

# 9. Merge Strategy

Use **Squash and Merge** for all PRs.

Benefits:

* Clean history
* One PR = one commit
* Easier traceability

---

# 11. Release Management

Tag stable versions:

```bash
git checkout main
git pull origin main

git tag -a v0.1.0 -m "Prototype release"
git push origin v0.1.0
```

Each release must correspond to:

* Fixed Snakemake version (9.17.2)
* Known environment
* Passing test

