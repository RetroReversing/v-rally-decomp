# Packed record decoding investigation

Legacy score1465 draft is not sound: reads new_var5 uninitialized, doubles the sp14 base through u16 pointer arithmetic, overwrites the selector and multiplies the original frame argument by four inside each iteration. Clean baseline2524 fixes these and removes unused volatile. Explicit invariant frame_record capture improves to2259, still nonexact, SHA256 0639d8615e7f6fbc198513a9aab3280e0e8caf97f669698a4ebd282f8a7b487f. See docs/matching-experiments/func_8006C024-nonmatching-alternative.c. Readable alternative with inherited redundant do scopes removed scores2454. 1000 native candidates plus targeted probes (including51 parent judgments) found no exact match. Lower2031 candidate rejected for artificial duplicated identical branches. Remaining issue: invariant frame<<6 occupies fp and frame_record spills, unlike target; scalar phase/lifetime and hoist/type probes did not fix register allocation/scheduling. Other-region machine draft transfers back to same7292 baseline, not a hidden matched donor. OPEN and revisitable; no target/profile/ABI/judge edits or selected standalone C.


## Current contract and source correction — 5 November 2026

The normal app review now selects corrected **OPEN 2454**, source SHA256
`6f08b04ceec49aab7689819f5e056d14f87ba2eb1af834b5ce9218dd2a86d842`.
This replaces the historical 1465 draft's uninitialized selector, double-scaled
halfword pointer and selector/channel mutations. It agrees with the current
selected byte-input selector and integer-input record helper. The modulo-u32
numerator is retained. A parent ordinary compile and linked comparison reproduced
2454; all 2,070 matched source files remain unchanged. This is a provisional
nonmatching draft, not a new cartridge match. Earlier scores above are historical
controls under their captured inputs, not freshly measured competing seeds.

Thirty-six new meaningful record/slot/driver layout, loop-backedge, lifetime and
selector controls found no exact match or improvement. GCC's loop dump identifies
an invariant channel-shift hoist. A genuine goto backedge prevents it and restores
the target's 0x50 frame, but scores 2650; selector coalescing scores 2575. Diagnostic
and ordinary canonical linked output agree despite different raw ELF metadata.
Frame size alone is not an acceptance criterion.

The sole raw caller loops over eight cars and channels below a record count whose
actual upper bound remains unproven. Aligned storage, raw global/effective-type
representations and a nonzero divisor remain runtime preconditions. The byte
selector and three iterations bound the floating conversion to finite 0..1150.5;
this is not a proof of every game's storage declaration. Keep the function open.
The next useful hypothesis concerns real channel/iteration interference under
the backedge, rather than another copy-width or layout sweep.


## November 6: grounded three-phase register reuse

A fresh current-contract freeze reproduces OPEN2454 with full ordinary/-da
linked parity. Compiler dumps locate the channel shift in ordinary CSE inside
the conditional body; loop optimization moves insn222 to541 before the loop and
shares371. This is earlier than final register allocation.

Four new controls reuse one genuine value across initial channel, loop index
and signed-delta phases: SI structured4009, SI goto3205, HI structured3033 and
HI goto2635. None improves2454, and none is adopted. Hydrated437 saved attempts
were checked; no native, flag or arbitrary declaration sweep was run. No new
positive automated repair follows from these controls. Do not repeat this phase
copy family without new source/domain evidence. Existing runtime bounds and
raw-storage assumptions remain explicit. Private receipts: current-nov6/REPORT.md.


## November 6: consumed offset and shared table staging (OPEN1848)

A genuine consumed record-offset local improved2454 to2238. The byte selector
bounds its shift to0..16320. Removing both identical branch-tail multiplications
and evaluating once at their common successor improved2238 to2043. Capturing
the actual char-array table base before use then improved2043 to1848. Existing
raw-storage, alignment, effective-type and nonzero-divisor premises still apply.
This is a retained unmatched draft, not an additional exact match.

Parent ordinary linking independently reproduced1848; ordinary/-da agree on976
linked bytes, SHA256
`49ef27fc54e7c9d887c939136d0672dcba160eedc3a6d5935b4d013fed9c1f92`.
Source SHA256:
`d5f948d6b4dbfe727396e6d8bedce0963fd988d38c3f3b58c6c1ff266a56a9e9`.
Normal app compilation retained this source; all2071 selected matches remain.

The initial current-source native lane persisted549 candidates, including one
interrupted in-flight candidate, and linked224. Two empty-do scaffolding
candidates were excluded, leaving222 audited linked candidates.576 outputs were
requested;27 unobserved outputs are not counted as received. The terminated lane
was not restarted. A separate refinement from2238 completed451 received and214
linked comparisons, with no exact match. A candidate retaining an overwritten
duplicate assignment was rejected. Six grounded controls yielded1848.

App PR651 rejects newly introduced literal-zero empty-do scaffolding before
random/deep judging, preserving existing wrappers, actual nonempty blocks and
dynamic waits. It is a bounded source-shape guard, not a C equivalence checker.
Private evidence: current-nov6-native and refinement-2238 under func8006C024.


## November 6: diagnose the accepted1848 revision

For source d5f948d6, the older2454 channel-shift hoist is no longer present.
Loop optimization hoists the two table bases and byte constant1. Global allocation
spills frame_record, with an88-byte frame versus target80. This is an observation,
not a proven recipe for restoring the target allocation. Removing/delaying the
consumed offset scores2054; phase sharing2913, decoded consolidation2473/4213,
and actual field-pointer capture1948 are negative controls.

An explicit narrowing of the already0..15 high nibble scores1733, but remains
review-only and is not retained: a genuine consumed byte-local control scores2193,
so the cast alone does not establish recovered original storage. No padding,
dead assignments or identity-only scheduling rule is introduced. The accepted
unmatched draft remains1848. No further native quota ran. Evidence is bound to
the exact source in private diagnose-1848/RESULT.json.

App PR652 now generates the genuine common-tail edit from the frozen2238 input,
independently reproducing2043;125 focused tests passed. This is not a new exact
match and does not attribute the separate table capture to the same family.


## November 6: byte-phase review and retained1733 draft

The earlier1733 review-only disposition is superseded by a source-level audit.
The conversion `(u8)(temp_t0 >> 4)` occurs at the actual unsigned-byte packed
field extraction. The load is0..255, the unsigned shift produces0..15, and the
conversion expresses the byte-sized decoded value before widening into the
existing signed/unsigned integer carriers. Both existing assignments and all
validity, channel-bit and table-offset consumers remain. No read, call, local,
dead store or control operation is added. This is coherent reconstructed C,
not proof of the unique original type. A conversion is not dummy scaffolding
merely because the inferred input range makes it value-preserving.

Whole-function byte declarations scored2133/2008; a separate byte local2193
and storage-first splitting4358 were negative. Those different models do not
invalidate the meaningful conversion at the actual decoding expression.
Parent independently reproduced1733; ordinary/-da agree on980 linked bytes,
SHA256 dd2cc3353257d93b212c98bbc1b96b78358044ee9ecf5667511b81a779e3e9b8.
Source SHA256 8c509f910f6587fb430aa8c28e3685c27f0102ab81f39fb0ae1328703793808c.
Normal MCP compilation retained it as an OPEN draft, preserving all2071 matched
sources. This is not an exact match or complete-cartridge acceptance. Existing
storage and arithmetic premises remain unchanged. Private byte-phase-review/
RESULT.json retains the range/evaluation audit and fresh parity evidence.


## November 6: focused1733 search and automatic repair

One newly frozen1733 lane completed normally:256 requested and received, four
completion receipts,179 linked, no exact match or improvement. The seven fixed
methods were expression temporaries, statement reorder, assignment splitting,
factor multiplication/shift, commutative order and real block insertion. Current
shared safety guards ran before compilation; no declaration/type/flag methods
or replacement quota were used. Private native-1733-focused/RESULT.json retains
lineage and raw accounting.

A printed baseline scores1833. Restoring its original conversion statement
boundary recovers1733. The best real field-pointer staging candidate similarly
recovers only1733 after that one boundary restoration. This is a measured
formatting effect, not a general printer limitation or a hidden improvement.

App PR653 adds the bounded decoded_byte_normalization local/deep hypothesis:
the generated edit independently reproduces1848 to1733 from the copied witness.
It requires a known32-bit C profile, a visible unsigned-byte load, unchanged
unescaped local range and existing chained scalar assignments. It adds no reads,
locals, assignments or control.124 focused tests and whole Ruff passed, including
a host-C exhaustive byte/shift equivalence check. No new exact match is claimed.
