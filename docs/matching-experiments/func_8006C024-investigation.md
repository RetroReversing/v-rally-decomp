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
