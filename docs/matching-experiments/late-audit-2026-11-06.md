# Late bounded audits — 6 November 2026

These are negative controls, not new matches. The checkpoint remains 2,077
matched functions, 16 open functions and 28 retained as assembly. Lower mismatch
scores are better; exactness still requires the ordinary linked bytes and the
complete cartridge comparison. No selected C or compiler profile changed.

## Current-source local search: func_80029EAC

The actual score-215 source has SHA-256
`b4bf2e530440ceaaaf9d1f7d94093194bc3c8c6bdf449ec4cbc9657fe8b0787b`.
Original, fully macro-expanded and permuter-printed forms produce identical
1,560-byte linked output, SHA-256
`fdf2ef030607f526edba357f056787d01aeb4a344f47cb760e81585b4da830cd`.
The compiler profile and actual shared context were retained.

A single bounded native search retained exactly 200 raw emissions. Of these,
103 failed transformation guards, six failed preflight, and 91 compiled. The
compiled set contained 41 previously seen linked outputs and 50 newly scored
outputs. The best new score was 226; none improved 215 or matched exactly.
Rejected and duplicate emissions counted against the cap. The generator had a
separate 2 GiB/300-second watchdog; it exited normally without either limit
firing. This lane was not extended or restarted.

Earlier 1,000-emission coverage belonged to the older score-295 source. It did
not cover this source. Conversely, the new 200-emission result is not an
exhaustion proof for all equivalent C programs. Mutation guards screen known
hazards; they do not establish universal semantic equivalence.

The current phase evidence places the missing copy in combine: the copy from
slot to height survives CSE and flow, then combine substitutes the long-lived
slot into its consumers. Merely arranging a branch delay slot does not address
that earlier transformation.

## Stack-origin audit: func_8007B4A4

One direct call was found, at `0x8001A6E4`, passing owner in `a0` and zero mode
in `a1`; no result is consumed. The function has three calls, each with at most
three register arguments. No DI integer or double arithmetic/conversion was
found. Its four wide operations only save and restore FPR pairs.

Thus neither an observed hidden return nor outgoing arguments nor an observed
wide computation explains the unused stack region at offsets 64..79. No new
candidate was compiled. The existing score-52 source remains selected as a
nonmatching draft. A genuine temporary allocated during expansion and eliminated
later could in principle leave a stack high-water reservation, but no focal
expression has yet justified testing that mechanism. Do not add padding or an
unread enlarged matrix to reproduce the frame size.

## Secondary-result ABI: func_8009A2D0

All 19 saved attempts and the actual callers/callees were reviewed. The fast
helper returns quotient in `v0:v1` and leaves remainder in `t1`; the slow helper
returns quotient in `v0:v1` and leaves remainder in `a0:a1`. The wrapper saves
`ra` in `t5`, calls a helper, and repackages that secondary result. A numeric
conversion caller consumes its low remainder as a digit index, then calls the
neighboring quotient dispatcher for the next dividend.

This differs from the successful ordinary-C tail dispatcher `func_8009A2B0`:
the wrapper must work after the call and consume a private secondary-result
contract. GCC 4.4 sibling-call support alone supplies neither that contract nor
the required link-register preservation. No supported ordinary-C declaration
route was found, so no speculative quotient-return candidate was compiled.
This is a bounded capability finding, not a proof that every possible compiler
or calling convention is incapable of reproducing the bytes. Assembly remains.

## Preservation and evidence

Read-only packed-storage-aware database snapshots before and after each audit
confirmed all 2,077 matched source hashes and effective profiles, plus each
focal source/header/target/profile input, were unchanged. No live claims,
source adoption or runtime deployment occurred.

Detailed private receipts are retained under the investigation directories
`current215-native200-nov6`, `abi-wide-origin-nov6`, and
`vrally-remainder-2110-nov6`. They include raw candidates, lineage, compiler
outputs and preservation snapshots; these game-derived artifacts are not
published in this repository.
