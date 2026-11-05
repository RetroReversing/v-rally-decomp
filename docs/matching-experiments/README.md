# Unmatched source alternatives

These sources are experiments, not selected build inputs or claimed matches.
Keep the better saved app draft and revisit these independently.

## func_8007AD68

The structured alternative in `func_8007AD68-structured.c` compiles to the
correct 848-byte size and complete control-flow graph, but scores **70**,
versus **60** for the existing app draft. It does not contain the older draft's
redundant duplicated `if`. Both remain unresolved.

Pinned profile: KMC GCC 2.7.2,
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`. Use the frozen global context in
`include/decompdecomp_snapshot_800450b8.h` (SHA-256
`dbba70193bdbe4bf36bd3dea87145596d4b5b0679f13793d34b74728e3b3f212`).
The source SHA-256 is `f8dabeb2f1252ff1451327178fef6b8451136d827d1c2386b3da74ab846b5636`.

Three linked words differ: at `8007ADF4`, the signed index is copied to `a2`
instead of `a0`; at `8007AE04` and `8007AE08`, the argument restore and index
increment occupy different positions around the branch delay slot. The
original score-60 draft instead swaps only the subsequent argument move and
byte store. Prioritize index lifetime/allocation and branch-delay eligibility
when revisiting. No standalone/full-cartridge acceptance is claimed here.

The fresh path was measured: raw goto draft 3,594, corrected aliases 2,255;
restoring the first switch alone 1,245, second alone 1,675, both 545.
Pointer address staging alone reduced 545 to 495; cached callback/global loads
alone reduced it to 120; both produced 70. This is a source alternative, not a
new live match or automated repair result.

Negative evidence: the recorded fresh search tried 90 shared repairs, at least
282 raw-goto native candidates, 464 restored-switch candidates and 150
score-70 native candidates without an exact match. The interrupted goto lane
may have additional uncheckpointed trials; do not report its saved count as
an exact total. Sixteen scalar-lifetime probes did not improve 70; four formal
parameter phase-reuse probes all scored 708. Earlier register/scope, comma,
queued-increment, function-pointer and bounded compiler-stage probes did not
solve the score-60 scheduling tie.
