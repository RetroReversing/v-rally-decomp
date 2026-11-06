# Unmatched source alternatives

These sources are experiments, not selected build inputs or claimed matches.
Historical scores do not establish valid C or current selection. Revalidate the
actual source, header, compiler profile and linked target before revisiting.


## Current open-function snapshot — 6 November 2026

The live project has 2,077 matched functions, 16 open functions and 28 retained
assembly functions. The table lists current saved research drafts, not selected
standalone C or proofs of whole-program correctness. The older sections below
are historical: some functions have since matched, and several lower-scoring sources
have been rejected for concrete C defects. Start with the linked investigation
and its latest source hash rather than an old alternative filename.

| Function | Current score | Investigation |
| --- | ---: | --- |
| `func_80049DB0` | 40 | [Current evidence](func_80049DB0-investigation.md) |
| `func_800529F0` | 135 | [Current evidence](func_800529F0-investigation.md) |
| `func_80086F40` | 325 | [Current evidence](func_80086F40-investigation.md) |
| `func_8002FFA4` | 107 | [Current evidence](func_8002FFA4-investigation.md) |
| `func_80030180` | 107 | [Current evidence](func_80030180-investigation.md) |
| `func_8006603C` | 305 | [Current evidence](func_8006603C-investigation.md) |
| `func_8006C024` | 1733 | [Current evidence](func_8006C024-investigation.md) |
| `func_8007A29C` | 22 | [Current evidence](func_8007A29C-investigation.md) |
| `func_8006BA44` | 695 | [Current evidence](func_8006BA44-investigation.md) |
| `func_8006D10C` | 505 | [Current evidence](func_8006D10C-investigation.md) |
| `func_8006E394` | 1200 | [Current evidence](func_8006E394-investigation.md) |
| `func_80059A60` | 750 | [Current evidence](func_80059A60-investigation.md) |
| `func_8007B4A4` | 52 | [Current evidence](func_8007B4A4-investigation.md) |
| `func_80040CF4` | 518 | [Current evidence](func_80040CF4-investigation.md) |
| `func_80029EAC` | 215 | [Current evidence](func_80029EAC-investigation.md) |
| `func_8003E6D8` | 565 | [Current evidence](func_8003E6D8-investigation.md) |

Current 695/1200/22 drafts supersede historical drafts for 6BA44/6E394/7A29C
respectively; do not reinstate an old source merely because it scores lower.
Removing unsupported qualifiers, padding or invalid dataflow may worsen a score while correcting the source model. Native coverage also belongs
to a particular starting source: the old padded 7A29C lane did not cover its
current 22 draft, while 6D10C's old initialized 505 lane does use the current source.
Check the per-function ledger before commissioning another search.

Latest bounded negative controls are summarized in [the late audit](late-audit-2026-11-06.md). No new C was accepted by these controls.

## Historical alternatives


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


## func_80029AA8 (improved live draft)

The portable snapshot now preserves a **70-score unmatched draft**, improved
from 130 through the ordinary live judge. It introduces a saved original-right
index before the sign test and a one-shot scope around the base/right updates.
The triangle permutation is unchanged: negative selects diagonal/down/right;
nonnegative retains the original indices. `cell` and the constant-one local
remain unchanged. All instruction sequence/order differences are resolved;
fourteen register operands still differ. No selected C or full-cartridge
acceptance is claimed.

Frozen alternative: `func_80029AA8-70.c` (also saved in the portable snapshot), SHA-256
`349a2449a309a833165994f5a1e5f848c25451a95869ff7b33b407bdb0d337bc`.
Profile: KMC GCC 2.7.2, `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`; frozen
global context SHA-256
`dbba70193bdbe4bf36bd3dea87145596d4b5b0679f13793d34b74728e3b3f212`.

A bounded scan of 544 symbolically valid copy rotations did not improve the
original 130 result. Direct scalar temporaries alone scored 295; explicit
byte-offset and native-index phase reuse hoisted work or changed allocation;
register storage-class hints did not help. The productive scope changes
affect allocator reference weighting. Continue the register-lifetime
investigation rather than repeating those negative grids.
