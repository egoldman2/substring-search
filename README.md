# Naive substring search and KMP

A reproducible C++17 comparison for Advanced Algorithms 41052, Programming
Assignment 2. Ethan Goldman is the individual submitter and primary owner of both
algorithm modules. Both search immutable byte sequences and return the **first**
matching byte index, `std::string_view::npos` if absent, and zero for an empty pattern.
Embedded zero bytes are valid. The public technical report is part of a larger
submission package; personal submission sections are maintained separately.

## Build and correctness

A C++17 compiler, `make` and Python 3.12 or newer are sufficient for the searches,
tests and experiment collection. On macOS use the Command Line Tools. On Debian
or Ubuntu, the corresponding packages are `build-essential python3 python3-venv`.
From the repository root:

```sh
make all
make test
python3 tests/workflow_test.py
make sanitize
```

The suite checks 104,600 answers using hand-specified cases, all 16,129 pairs of
binary strings through length six, and 10,000 seeded cases against the standard
library. Counted and ordinary entry points both run. Failures do not depend on
`assert`. The workflow test checks all 363 generated inputs and the binary CLI.
Sanitizers require compiler support. To verify a build with disabled assertions:

```sh
make -B test CXXFLAGS='-std=c++17 -O2 -DNDEBUG -Wall -Wextra -Wpedantic'
```

## Search files

```sh
printf ABABABAC > build/text.bin
printf ABABAC > build/pattern.bin
./build/search naive build/text.bin build/pattern.bin
./build/search kmp build/text.bin build/pattern.bin
```

Both commands print `2`. Output is a byte index or `npos`, with a newline.
Usage errors return 2, file/read failures return 1, and a successful search,
including absence, returns 0. Empty and binary pattern files are supported.

## Benchmark smoke test

```sh
python3 scripts/experiment.py --smoke --instances 1 --repetitions 3 --output build/smoke
```

This collects six small instances using the same driver as the full study. The
output directory must be new: choose another name when rerunning. The collector
forces rebuilding the optimized driver even when source and binary timestamps
coincide, and records executable and source hashes. It warms up, calibrates batches,
alternates execution order, verifies answers outside timing and retains all rows.
KMP preprocessing is included on every call. Input loading and generation are not.

The main study uses three instances and nine timed batches per configuration:

```sh
python3 scripts/experiment.py --output results/new-run
```

This command reruns noisy measurements and never replaces the committed study.
Each driver has a 30-second timeout and collection a 15-minute budget. To choose a
compiler or flags, set `CXX` and `CXXFLAGS` for the collector; it passes both to
Make and records them. Do not enable LTO or declare searches pure without checking
that repeated calls remain inside the timed loop.

## Regenerate the evidence and documents

These commands use committed results and **do not rerun the measurements**:

```sh
python3 -m venv build/venv
build/venv/bin/python -m pip install -r requirements.txt
build/venv/bin/python scripts/analyse.py
build/venv/bin/python scripts/build_report.py
build/venv/bin/python scripts/build_presentation.py
```

The two document dependencies are Matplotlib and ReportLab, pinned in
`requirements.txt`. Search and benchmark code have no third-party dependency.
`make clean` removes the build directory, including this optional environment.

- [Technical report](report/report.pdf), [editable report text](report/report.template.md).
- [Editable PowerPoint](presentation/slides.pptx), [slide PDF](presentation/slides.pdf).
- [Script and timed storyboard](presentation/script.md), [recording and rehearsal](presentation/recording.md).
- [Summary table](results/tables.md), [all configuration summaries](results/summary.csv).
- [Requirements and status](docs/checklist.md), [decisions](docs/decisions.md).

The report template draws numeric facts from `results/facts.json`. Slide content
comes from `presentation/slides.template.json`; the generated layout, script and
portable PDF share those facts. The PowerPoint has native text, tables, byte cells
and an editable chart with an embedded data workbook. To change that deck, edit
its objects in PowerPoint and export its PDF, or use the portable source/PDF path
above. The public scripts regenerate the slide PDF, content and layout; they do
not rebuild the PowerPoint package. Keep any PowerPoint edits consistent with the
source and script. Helvetica in the portable PDF corresponds to Arial in the deck.

The script is estimated at about 10-11 minutes. Actual rehearsal and recording
remain required, and the final video must be at most 12 minutes.

## Evidence and limits

The final analysis selects `results/main-verified-2026-10-27` and
`results/mismatch-verified-2026-10-27`. Main data contain 363 instances and 6,534
timed batches. The controlled follow-up contains 18 instances. The original pilot,
main and mismatch directories remain as **superseded** evidence after a stale
executable was discovered. See [the correction](docs/measurement-correction.md).
No old and replacement timings are pooled. Dated original and follow-up predictions
remain unchanged.

Each run has raw batch nanoseconds, counts, order, batch size, correctness,
parameters, seeds, hashes and environment metadata. Summaries take a median of
nine batch-per-call times within an instance, then the median and inclusive IQR
of the three instance medians. Within-instance spread is retained separately.
An IQR is not a confidence interval. Counts include equality tests only, with
preprocessing split out. The corpus's provenance is in [data/README.md](data/README.md).

Performance measurements use one Apple M1 Pro with Apple Clang on macOS. The
three structured variants preserve the same repetition structure, and prose uses
related windows from one repeated excerpt. Fast batches can hit the call cap below
the target duration. Large adversarial advantages are better supported than tiny
percentage differences. No processor-level cause is inferred from timings alone.
See [verification](docs/verification.md) for actual macOS/Linux checks and the
remaining human tasks. No software licence has been selected.
