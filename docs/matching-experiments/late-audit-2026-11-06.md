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

## Additional local coverage: func_80049DB0

A deliberately larger search added 10,000 raw emissions on the actual score-40
source (`ea647ba17af5ef82350d47c9b2e13d28a3e2325a058a8ba8781612f88abe9216`).
This was additional finite coverage, not a newly discovered compiler cause.
Original and printed roots passed ordinary/diagnostic linked-byte parity before
launch. The one generator completed in about 19 minutes with no restart,
extension or watchdog failure.

Accounting: 2,972 normalized-source duplicates, 3,917 guard rejects, 262 preflight
rejects, and 2,849 successful compilations/links. The compiled set contained
2,521 previously seen linked outputs and 328 distinct scored outputs. None
improved 40 or matched exactly. The historical source filter includes the old
1,000-emission lane; historical byte deduplication is incomplete because its
452 judged records did not retain all linked bytes/hashes. No old compilation
was replayed solely to rebuild that missing cache.

Two new score-45 outputs were replayed ordinary and diagnostic, four compiler
calls total, with matching bytes in each pair. One changes the selected-value
load preference but moves its pointer to the wrong register; the other retains
the correct pointer register but the wrong value/result registers. Both retain
nine register-only differences instead of the baseline eight. Neither supplies
a better seed. This result does not justify repeating the same search without
new evidence or an explicitly larger search plan.

## Corrected-contract local coverage: func_8003E6D8

The current callback-contract source differs from the older native seeds even
though its ordinary output also scores 565. Original, expanded and printed
forms produced identical 1,580-byte output, SHA-256
`81939f9e2c8d53d7b473c79ca8840f3c242f506ae73b2978ffce9d91089f3c19`.
Exactly 200 new raw variants were generated once.

An inherited private runner guard initially mistook an existing global write
for an introduced local temporary and rejected every candidate. The corrected
guard was checked against baseline/legitimate-capture positives and changed-type
and cast negatives, then evaluated the same retained 200 candidates. Production
app code was not affected or changed.

The completed recorded replay rejected 78 at guards and 18 at preflight, then
compiled 104: 66 linked duplicates and 38 newly scored outputs. None improved
565 or matched. A preceding corrected replay failed while writing its receipt;
its extra compiler-call count is unaccounted. The duplicate evaluation is
explicitly retained in the private report, rather than counted as new emissions
or hidden inside a purported exact total. Future runners must persist outcomes
incrementally and test that the unchanged baseline passes their guards.

These random candidates remain semantic hypotheses. In particular, moving a
global read across a call requires alias/effect review, even when types match.
No candidate from either search was adopted.

## Focused follow-up controls

The score-215 `func_80029EAC` still differs at four tail positions. Reusing an
existing union member scored 270; assigning the depth in the condition scored
275. Replacing its genuine 32-byte matrix assignment with `__builtin_memcpy`
produced exactly the existing 215 bytes: the initial pointer plumbing disappears
during optimization.

A separate return-contract audit found one direct caller, which ignores the
result, and no recognized address-taking reference. This does not exclude every
computed indirect call. A private, consistently declared `int` fallthrough
control added no invented return expression. It also produced exactly the
baseline bytes, with identical saved compiler phases through delay scheduling.
Changing the return type therefore supplies no repair for this source.

Installed original SN alternatives also failed to improve the selected sources:

| Function | Current score | SN 0001 | SN 0004 | SN 0006 |
|---|---:|---:|---:|---:|
| `func_80049DB0` | 40 | 40, identical bytes | 50 | 265 |
| `func_800529F0` | 135 | 295 | 2,745 | 4,270 |
| `func_80029EAC` | 215 | 1,040 | 3,005 | 11,633 |

Each reported alternative has ordinary/diagnostic byte parity. These are paired
frontend/assembler results, not proof that every assembler or flag combination
has been tested. In particular, SN 0001 reproducing the score-40 bytes rules out
the reconstructed frontend alone as the explanation for that discrepancy.
No source or compiler selection was adopted.

## Preservation and evidence

Read-only packed-storage-aware database snapshots before and after each audit
confirmed all 2,077 matched source hashes and effective profiles, plus each
focal source/header/target/profile input, were unchanged. No live claims,
source adoption or runtime deployment occurred.

Detailed private receipts are retained under the investigation directories
`current215-native200-nov6`, `abi-wide-origin-nov6`, and
`vrally-remainder-2110-nov6`, `additional40-native10k`, and
`current565-native200-nov6`. They include raw candidates, lineage, compiler
outputs and preservation snapshots; these game-derived artifacts are not
published in this repository.
