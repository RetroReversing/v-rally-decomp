# Packed record encoding investigation

The saved score-325 draft is invalid: state[31] selector is overwritten by state[35], and n is read uninitialized. Target uses two independent bytes. Required-prelude clang confirms the uninitialized read; clean alternative passes. Audited clean source score600, nonexact, SHA256 0371890309c8cb74ddde07673d0381a05b118f5eee7676ddc05b5cb10f486ccf. Main residuals: initial selector/index register allocation, one extra move after byte narrowing, loop arithmetic temporary allocation and consequent branch offsets. 1000 guarded native candidates, 125 helper manual probes and 40 parent probes found no exact match. Safe q-hoist alternative scores505 but diverges in loop register lifetimes. Use docs/matching-experiments/func_8006D10C-nonmatching-alternative.c as sound starting point. OPEN and revisitable; no target/profile/judge changes or selected standalone C.

## November 5 bounded revisit

Fourteen new bounded mode-offset and packed-offset controls did not improve the corrected505 baseline. The saved325 source still reads uninitialized n after overwriting the separate mode byte. A normal compile retained corrected attempt307944, and a structured source-scoped quality report now links it. Review adoption was requested; the HTTP observation timed out, and current source is still325, so adoption is not claimed. No exact match or repeated native search. Broader caller/object preconditions remain unresolved. Private frozen inputs, source hashes and raw linked evidence remain on the Data volume; no game data is included here.

### Retained correction and review guard fix

The exact corrected505 research source is also retained as `func_8006D10C-initialization-corrected.c` (SHA2566dd89f6e9c0f6bbef3bad5ec7d0287437f29034edd3b356be766c8f9f0a895b0). It requires the frozen project context and remains nonmatching, with the broader object/caller preconditions described above. The source-scoped normal report links measured attempt307944; no live database writes bypassed the app.

PR611 fixes an independently reproduced review failure: an autosave can increment the progress manifest counter while the judge runs. The old code compared complete serialized configs and could reject that bookkeeping change as a build-settings change. The fix excludes only progress_revision, preserving every actual configuration, context, source and status guard. Twenty-nine recovery tests passed, including concurrent real compiler changes. The live adoption request timed out and remains unconfirmed; this explanation does not assert it was the only cause of the timeout. Updating/restarting the running app requires separate user approval under its AGENTS.md.

### Corrected draft selected normally

The saved-file reimport rejudged505 but did not retain the draft as selected. A fresh ordinary scoped claim and compile then selected the exact corrected source hash6dd89f6e9c0f6bbef3bad5ec7d0287437f29034edd3b356be766c8f9f0a895b0 at505. Readonly inspection confirms OPEN505 and the saved best file exists; only the parent's temporary connection/claim was revoked. All current progress was exported normally. This replaces the definite local uninitialized-value defect, not a new exact match or a claim of global C correctness. No app update/restart or direct database write was used.

## Packing-oriented revisit

The ROM constants are verified as 4.5 and 1.5. This routine packs three 12-bit
entries: two status bits plus a capped signed-difference representation, with
an all-ones sentinel for code 5. For byte n and loop i in 0..2, exhaustive byte
checks establish q & 255 = 4 * ((n + i) & 1), including wrapped byte j. This is a
semantic aid, not a proposed replacement of the target's floating operations.

Thirty-four new linked controls (ten sequenced packing expressions, twelve
whole-entry inline helpers, twelve high/low-lane inline helpers) did not improve
the initialized score-505 seed. Meaningful early-return helpers inline; some
whole-helper if/else forms do not and become much worse. Neither produced an
exact candidate. The remaining issue is loop-invariant arithmetic placement and
register lifetime. No native or whitespace sweep was repeated. The invalid old
325 draft remains rejected. A source-hash-bound summary was also added through
the app's normal note interface to help subsequent agents start from this
verified packing structure. No live source/profile/target change is claimed.

## November 6: expression identity before loop motion

Fresh ordinary/-da linked parity reproduces initialized505 and the older
statement-split600. In505, CSE creates a single-definition n*9 temporary111;
the loop pass explicitly moves its shift/product out of the loop and global
allocation assigns it s7 across iterations/calls. In600 the product writes the
same q pseudo overwritten by the final subtraction; it stays in the loop, but
its source identity ties it to across-call q. A separate normalized-byte copy
arises in the second CSE and survives with different v0/s5 allocations. This
locates earlier causes instead of attributing everything to the final scheduler.

Three new phase-driven controls fail: a real two-output packed-position helper
inlines but its consumed output locals stay stack-backed (10961); a genuine
intermediate position accumulator keeps the multiply inside the loop but uses
the wrong sum/shift register (620); reusing that temporary for the real byte-cursor
bit term is680. The latter two were checked against3,359 historical exact/token
source hashes and are new. All ordinary/diagnostic FULL linked bytes agree.
No native/profile/whitespace/declaration sweep was repeated. No new generic repair
or exact result is established; do not repeat these forms solely because their
loop placement is closer. Valid505 remains selected and unclaimed. Normal-game
record bounds, alignment and representable signed-difference assumptions remain.

## November 6: wider caller-contract audit

The actual saved initialized505 source and all four previously captured selected
caller/callee sources are unchanged. Fresh input SHA256:
`32bb62b2af5da882b29a8b94a3df8591e8fa6799b48494d855c041ff11a6e86f`. No new source
relationship justified repeating native, formatting or profile sweeps.

A bounded declaration-only correction in selected caller func_8005A790 changes
its erroneous s32-returning declaration of this actual void(void) entry. Its
statement-only calls and other source are unchanged; ordinary and diagnostic
builds preserve all3100 linked bytes, exact against target. This private proof
is not accepted selected C: the wider caller scan identified unresolved pointer
return/storage, SDK matrix and extra-argument contracts. Correcting only the
focal declaration does not close those known obligations. No live source or
compiler profile was changed, no match was added, and no cartridge acceptance
is claimed for the private caller alternative.

The remaining obligations and exact declaration proof are retained privately in
current-nov6-grounded/RESULT.md, caller-contract-scan.json and caller-5A790/proof.json.
Future work should close coherent actual interfaces before accepting a broader
caller correction, retaining all selected neighbors and runtime storage premises.


## November 6: consumed byte-position phase controls

Three further range/evaluation-grounded models were absent from3380 historical
source hashes: capture the actual output-byte cursor7270, modulo256 byte-position
arithmetic1015, and their combination7335. All have complete ordinary/-da linked
parity. None improves the current initialized505 source or supplies a successful
new automatic family. No native/profile/format/declaration sweep or live source
change occurred. Private bytephase-nov6/RESULT.md and results.json retain scope,
source hashes and judgments; this does not rule out other reconstructions.


## November 6: hydrated cause and contract audit

A fresh read-only capture retains OPEN505, source SHA256
`6dd89f6e9c0f6bbef3bad5ec7d0287437f29034edd3b356be766c8f9f0a895b0`.
All740 hydrated attempt sources and the effective source/header/profile/target,
assembly, symbols and actual empty source prelude were checked. All2071 selected
matched rows remained identical through a final independent read-only query.

Existing RTL establishes the source of the residual: a single-definition n*9
pseudo moves out of the loop and occupies the target table-address register.
The split600 source prevents that motion but ties the product to a different
live value and adds a normalized-n copy. Real accumulators, consumed helper
outputs, cursor/byte phases, widening and selector-offset controls already cover
the grounded alternatives. Selected callee and neighboring record layouts support
the source's actual data accesses but do not establish a new loop dependence or
alias restriction. No new source change or compiler run was justified by this
audit. These are bounded negative findings, not proof that no C can match.
Private cause-audit-nov6/RESULT.md and final-readonly-equality.json retain evidence.


## November 6: current-declaration backedge and SN compiler controls

Fresh capture retains initialized505 source6dd89f6e and740 complete hydrated
attempt rows. Its actual KMC flags are -G0 -mips3 -mgp32 -mfp32 -O2 -g3, with an
empty prelude. The invalid older325 draft is not a starting point.

An explicit-backedge form exists in prior history, but only with a different
local declaration order (2642). One finite current-root composition changes only
do/while into a label and conditional goto, preserving every declaration,
statement, condition, floating evaluation and counter operation. It is absent
from3405 private C files and the hydrated attempts. Ordinary/diagnostic builds
both score2642/1104bytes, SHA256
`1f248a8dffc8e1d218a85b889584289df6039996f986df6b75ed3cc31bdff3b8`.
LOOP no longer has structured loop notes and n*9 stays inside the real backedge,
but other lifetimes diverge much further. This confirms the intended mechanism
without establishing an improvement; the result equals the older goto score.

A separate finite compiler comparison uses the unchanged505 source with all its
actual KMC flags plus registered SN dialect/assembler flags -mgas -meb
-mhard-float. Installed/license-accepted binaries and the wrapper are pinned.
No SN defaults or extra optimization combinations are substituted.

| SN build | Score | Bytes | Linked SHA256 |
| --- | ---: | ---: | --- |
| 0001 | 3475 | 1128 | 730fe6a709a27bf976c744e82d553c5a48af6d088267cc8288741ac69241fbbd |
| 0004 | 2717 | 1116 | 3c80231ade32fda9e42f7a7c686b81742431d8f5d53af73060ba33c72bbce182 |
| 0006 | 4336 | 1116 | d9334dca722cafdd88fb36bd5d758686f5e9d11d261763b37727317b507938cd |

Each ordinary/diagnostic pair has full linked parity. All three still move n*9
out of the loop. Build0001 saves floating registers with separate swc1 halves;
0004/0006 use sdc1 pairs but retain other extra saves and mismatches. The0001
save behavior must not be generalized to the other binaries.

Exactly eight calls ran, no new random lane or source/profile adoption. An
independent20-second/2GiB aggregate descendant-RSS watcher bounded each call;
all completed without resource kills. Private current505-causal-nov6 retains
actual commands, source/context bindings, linked bytes, RTL and resource receipts.

Final independent read-only equality checks preserve all2077 matched rows and
effective profiles,740 complete hydrated attempt records and every focal input.
The initialized505 draft remains unchanged; workers are terminal and reaped.


## November 7: immutable conversion threshold with explicit backedge

The initialized505 root and all740 hydrated attempts remain unchanged. An audit
of3413 private candidate sources found prior explicit unsigned conversions and
goto combinations, but no literal2147483648.0 threshold control. Prior versions
used a mutable external threshold and often changed several other bindings.

One finite control adds a genuinely consumed immutable f64 threshold before the
current-root goto loop and expands the conversion into signed low/high branches.
Mutable coefficient loads remain per iteration. The expansion preserves the
original defined finite f64-to-u32 domain and the final u8 conversion; it does
not establish equivalence on inputs for which the original conversion is undefined.
Actual KMC flags remain -G0 -mips3 -mgp32 -mfp32 -O2 -g3, empty prelude.

Ordinary and -da builds independently relink to identical1100-byte outputs,
score3055, SHA256046b1619c09f12158a2bb3a74cb271a341ad1878511890d9fdc04f47944f922e.
The intended threshold lifetime is recovered before the backedge, and the frame
returns to72bytes. However, threshold/fs1 occupy f22/f20, opposite target roles.
Explicit conversion also removes the high-bit OR before byte narrowing and
changes branch scheduling. Recovering a single lifetime is therefore insufficient
for a closer match. Preserve505; this is not a new match or adopted draft.

Exactly two compiler calls completed under independent20-second/2GiB aggregate
limits, with ordinary/diagnostic parity and independent relinks. All2077 selected
full sources/profiles,740 attempts and focal inputs remain identical. No live
operations or further matrix ran. Private current505-phase-nov7 retains source
delta, actual linked bytes, RTL and resource receipts.


## November 7: exact-root shared repair coverage

Eight bounded pure repair generators from app main d978ff39 were checked on
initialized505 source6dd89f6e with the actual context/profile. Six yielded no
candidate. Four conversion-tail materializations did not address the established
hoist and were not compiled. One integer-lifetime repair was genuinely new to
740 hydrated attempts and2,426 retained private source files: reuse dead u8
selector b as the real loop counter after all selector uses, resetting it at
the original i=0 point. No extra operation, memory access or iteration is added.

Candidate36c235ca3153c3b98434493fdddb3fce4dd5e29adaba414c649d44830462db76
was tested exactly twice, ordinary/-da. Both independently saved-object relinks
produce505/1112bytes, SHA-256
`a6f59a70c198a0812c99c0b12fa5a85b9bf7bc9418cf86078f3489b48e02bdd4`.
Independently relinking the retained exact-root baseline object proves identical
raw bytes, rather than only an equal score. The merged source binding survives,
but its initial value dies before the reset, allowing the same physical roles.
The n*9 product is still hoisted into s7; counter remains s4 and initial
normalization v1. This lifetime merge supplies no new repair mechanism here.

The earlier literal-threshold setup-order suggestion was not compiled: actual
liveness ranks fs1 ahead of the longer-lived threshold, so placing the threshold
earlier does not establish a fix. Genuine three-iteration early-exit loop forms
were already covered; no artificial barrier or threshold use was added.

Both20-second/2-GiB aggregate watchers finish cleanly under one second, with no
owned survivors. All2,078 full selected rows/effective profiles,740 focal attempts
and complete focal inputs remain unchanged. No selected source, live app,
compiler profile or cartridge-progress change. Evidence: private
`repair-coverage-nov7/REPORT.md`, `baseline-parity.json` and preservation receipts.
