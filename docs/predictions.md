# Predictions saved before performance measurements

27 October 2026, Australia/Sydney. Correctness tests have run; no comparative
performance pilot or measurement has run in this project at this point.
This record will remain unchanged after results arrive.

| Question | Prediction from the implementation | Refuting experiment |
| --- | --- | --- |
| Random bytes, early mismatches | Naive may be competitive or faster because most candidates fail at the first byte and it builds no table. | Compare identical seeded inputs at alphabet sizes 2, 4, 26 and 256, recording verified match positions and comparisons. |
| Long partial matches | KMP should use fewer comparisons and become faster as the pattern grows on text `a^n`, pattern `a^(m-1)b`. | Sweep n and m, include preprocessing in time and counts. A persistent naive win for large m would challenge the runtime prediction. |
| Short searches | At a match at index zero, KMP's preprocessing should matter increasingly as m grows. Naive should usually win. | Hold text size fixed, vary m and compare beginning versus end matches with separately counted preprocessing. |
| Periodicity | KMP should benefit on periodic inputs with many long partial matches, but periodicity alone need not make naive slow. | Compare a periodic matching pattern with an almost identical absent pattern. |
| Alphabet size | A smaller random alphabet should increase naive's repeated work. It may improve KMP's relative runtime, but no crossover location is predicted. | Hold n, m and absence fixed while varying alphabet size and measuring both counts and time. |
| Ordinary prose | There is no confident winner. Short shared prefixes may favour naive, while repeated prefixes may favour KMP. | Use a public-domain prose excerpt with verified beginning, end and absent searches. |

No numerical crossover is predicted. All predictions concern these C++17
implementations and first-occurrence searches, not every implementation of the
algorithms. Reusing a preprocessed pattern is excluded from the main study.

## Bounded design

- Text-size sweep: 1,024, 16,384 and 262,144 bytes, pattern length 32.
- Pattern-size sweep: 1, 8, 32, 128 and 512 bytes at text size 65,536.
- Families: random, repeated near-match, periodic and ordinary prose.
- Three independent seeds or prose windows per configuration, nine timed
  repetitions per instance, with separate instance and within-instance summaries.
- A small pilot selects batching policy before the main run. A target of roughly
  1 ms per batch and a maximum of 65,536 calls bound very fast workloads.
- Maximum generated n is 262,144 and m is 512. Each driver has a 30-second
  process timeout and the complete run a 15-minute budget. Any interruption or
  cap is recorded, never converted into a completed timing.
- Validate with `std::string::find` before admission. Generated beginning/end/
  absent labels are accepted only when the actual first index matches the label.
- Count byte equality tests separately, splitting KMP table construction and
  search. Primary timing has counting compiled out.
- Warm up each search. Alternate which algorithm runs first each repetition,
  with a seed-dependent starting order. Keep raw batch elapsed nanoseconds.
- Timing includes every KMP allocation, LPS construction and destruction.
  Generation, input files, process startup, oracle checks and printing are outside.

## Interpretation policy

Report medians and inclusive linear-interpolation IQR (25th to 75th percentile).
Summarise repetitions within each instance first, then the three instance medians.
Do not pool incompatible configurations or call an IQR a confidence interval.
Investigate units, input identities, positions and counts before explaining an
unexpected timing. No cache, allocation or branch-prediction cause will be claimed
without a discriminating measurement.
