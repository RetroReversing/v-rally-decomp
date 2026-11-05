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


## func_8007A29C

`func_8007A29C-frame-alternative.c` is **unmatched and not selected**. Moving
the table-pointer declaration first and removing an unused eight-byte array
makes all body instruction words and spill offsets agree with the target,
but yields a frame of `0x58` instead of `0x60`. Twenty-two prologue/epilogue
words differ, including register saves and restores eight bytes too low.
Its corrected advisory score is **22**, versus **2** for the existing draft,
which only places the table pointer at `sp+0x34` instead of `sp+0x14`.

Earlier advisory scores were 82 and 62: six fictitious relocation operand
differences came from omitted masked-constant low-half annotations. The
diagnostic parser fix removes those differences; both ordinary linked
verdicts remain false. No new match or full-cartridge acceptance is claimed.

Pinned profile: KMC GCC 2.7.2,
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`. Use the frozen global context in
`include/decompdecomp_snapshot_800450b8.h`, SHA-256
`dbba70193bdbe4bf36bd3dea87145596d4b5b0679f13793d34b74728e3b3f212`.
Alternative source SHA-256:
`5dbcd2b326323fe77a346989efc20b86eeb05e993c13aa91cb695ad90c7d24f5`.

Negative evidence: unused array sizes/scopes, register qualifiers, aligned
locals, scalar/aggregate pointer carriers, early/late pointer copies, wider
integer carriers, caller-save/peephole/strength-reduction switches and
already-installed alternative N64 GCC builds did not produce exact bytes.
The remaining hypothesis is a spill-allocation high-water slot or source
lifetime shape retaining eight bytes after the real spills. That mechanism
is unproven; keep both alternatives open for later work.


## func_8007FC44

`func_8007FC44-delay-alternative.c` is **unmatched and not selected**. Keeping
`func_8008DD00(msg); osSpTaskStartGo(msg);` on one source line restores the
historical advisory score of **120**; the frozen saved source otherwise
reproduced 320 with the current context. The remaining difference swaps
argument setup (`a0` from the object pointer) and a `nop` between a conditional
branch delay slot and the following unconditional jump delay slot.

Pinned profile: KMC GCC 2.7.2,
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`. Use the frozen global context in
`include/decompdecomp_snapshot_800450b8.h`, SHA-256
`dbba70193bdbe4bf36bd3dea87145596d4b5b0679f13793d34b74728e3b3f212`.
Source SHA-256:
`9659377e329cc833be3395c2d0c748f3a697207653c9efb466cc8aa640ade1c6`.

RTL places argument setup after the shared label and both volatile stores.
Volatile-resource conflicts prevent speculation across those stores. Removing
volatility permits the wanted move but wrongly puts a store in another delay
slot. This explains the tested candidates, not the original source qualifiers.
About 250 targeted line/scope, capture, branch-shape, type and qualifier
experiments did not produce exact bytes. SDK scheduler sources supplied
context only; no verified same-function donor was found.

Controlled profile tests on this source/nonvolatile variant respectively:
`-fno-schedule-insns2` 1210/1460, `-g0` 120/370, `-g2` 280/160,
`-O1` 1490/1740, diagnostic `-fno-delayed-branch` 2110/2110.
Nearby verified plain `-O2` gave 120/370; `-O2 -ffast-math
-fno-schedule-insns` gave 250/500. These are negative results, not recommended
profile changes. No linked match or full-cartridge acceptance is claimed.
