# Verification and handoff

27 October 2026. Technical preparation is separate from recording and submission.

## Observed local checks

- Apple M1 Pro, macOS 27.2, Apple Clang 21.0.0, C++17.
- `make -B all` and `make test`: 104,600 answer checks plus exact comparison-count
  checks passed. The presentation example has naive=13 search tests, KMP=9 search
  tests and 7 preprocessing tests.
- `make sanitize`: address/undefined-behaviour checks passed.
- A warning-enabled `-DNDEBUG` test build passed with the same answer count.
- `python3 tests/workflow_test.py`: all 363 regenerated instances, manifest hashes,
  binary/empty CLI searches and CLI error statuses passed.
- Main replacement study: all 363 instances complete, nine timed batches per
  algorithm per instance, 6,534 timed batches. Follow-up: all 18 instances complete.
- Replacement runs started clean and have the same recorded executable hash.
  Forced compilation corrected the stale-executable problem; original runs remain
  visibly superseded. No incorrectly returned search answer was observed.
- The report and slide values are generated from the selected replacement data.
  The report is approximately 5,000 words. The script has 1,449 spoken words and
  estimates 10:23 at 145 words/minute with transitions; rehearsal is still required.
- All 13 public report pages, the private disclosure pages and all 12 slide renders were inspected for readability, indices, clipping
  and consistent data. The exact final PowerPoint was reimported and all 12 renders matched the inspected source previews byte for byte. It contains native editable text, tables,
  byte-cell diagrams and a chart with its literal data workbook.

## Final checkout and Linux

A fresh clone of published revision `0443603` passed the README build, tests,
sanitizers, NDEBUG check, both file-search examples (each printed `2`), and the
six-instance benchmark smoke run. Its optional document environment was created
from scratch with the pinned requirements. Nineteen regenerated summary, source
and figure files were byte-identical to the committed versions. Both regenerated
PDFs had identical extracted text; PDF timestamps are expected to differ.

[Linux CI run 40488385491](https://github.com/egoldman2/substring-search/actions/runs/40488385491)
passed on that same revision: compilation, tests, sanitizers, all generator/CLI
checks, smoke collection and complete figure/report/slide-PDF regeneration. The
local Docker daemon was unavailable, so Linux verification used GitHub Actions.
Performance data are from macOS only; Linux CI verifies correctness and portability.
The PowerPoint package is retained as editable source; the portable script rebuilds
its content, layout and PDF, not that package. Native PowerPoint playback has not
been tested. No independent human adversarial reviewer is claimed.

## Remaining human work

1. Review the code and report and trace the invariants without the narration.
   Personalise the private reflection, contribution statement and disclosure,
   stating what was personally checked and what was accepted on trust.
2. Rehearse, record and edit the narration personally. Check the entire exported
   video, readability, audio, access and actual duration <=12:00.
3. Submit the complete private report, separate reflection, repository and video
   through the course arrangements by the published deadline. The public technical
   report deliberately excludes submission-only sections. Nothing has been submitted.
4. Watch the three actual assigned peer videos and write about 200 words each,
   using the private template. Responses remain pending and are due one week after
   allocation. No assigned videos, responses or allocation date have been invented.

The verified course update states 11:59 pm Sunday 1 November 2026. Private submission
preparation is kept outside this public repository. No software licence was added.
