# func_8006E394: packet decoder (open)

No byte-exact candidate has been found. No live project, canonical repository, runtime, target, judge, or compiler profile was changed by this helper. The function remains revisitable.

## Frozen inputs

- Project 1, function 1452, 323 target instructions, originally OPEN with advisory score 1155 and no claim.
- App revision f409cb26; frozen inputs SHA-256 6e7889f8495099992b59c9ccaff0562f40982d1f29f9f86ec9d8df206ae5df25.
- Profile: gcc-2.7.2-kmc, -G0 -mips3 -mgp32 -mfp32 -O2 -g3, timeout 20.
- ROM read from a private verified copy; SHA-256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7.

## Source audit

The saved source adds volatile halfword reads to force particular loads. There is no demonstrated volatile device/object here; these were removed from all proposed clean alternatives. One-shot do/while(0) scopes are valid ordinary C, and remain legitimate scheduling hypotheses; they are not fabricated runtime branches. No uninitialized use was found in the starting source. Counter increments are bounded: the four counters at 800B6600 (also 800AE850+7DB0) are reset before up to eight increments of 4/2/1.

This decoder assumes a valid serialized game record: selected slot nibbles must be below four and unused slots must exist when selected. The actual machine code makes the same unchecked accesses; no artificial bounds guard or changed stack object was introduced. The source is not a claim of safety for arbitrary corrupt packet bytes. Pointer alignment and genuine object/record views are also required.

## Useful recovery: matched encoder's local record type

The already matched adjacent serializer func_8006E8A0 contains a local Packet definition for the same buffer, 800C7112 = 800C02AE+6E64. Its fields f15/f14/f13/f8/f4/f0/g12/g8 describe the packed input; sums[4] begin at offset 10, with three-byte counters and a byte mask preceding them. This gives stronger layout evidence than inferred masks alone. It obtains slot bytes from the game's selected slots, consistent with the decoder's valid-record domain.

Replacing raw scalar casts with this actual Packet's bitfield reads naturally restores the target's reloads without volatile. Packet-only pointer use avoids an extra saved-register pointer copy. packetptr0.c scores 1350 with the original profile; parent-packet-fields2.c is an equally scoring readable version that uses named byte and sum fields too. An integer v version removes the redundant switch truncation but changes allocation and scores 1540.

Parent RTL diagnostic (parent-rtl-finding.md, private dumps under rtl/) shows a controlled mechanism: raw source load is mem:HI, mode field store mem/s:HI; a raw halfword reload present in .rtl disappears in first .cse. Packet fields instead have compatible mem/s:HI classification and retain the needed reload. This is evidence about this pinned old GCC's aggregate/scalar treatment, not a general alias proof or proof of a compiler bug.

The app's current related-source context path borrows verified headers and requires already referenced type names. It misses this useful local typedef in matched_source and the equivalent object address expressed through a different symbol plus offset. Potential improvement: offer matched-local record hints anchored by resolved identical addresses, with ordinary compilation and linked verification. No automatic repair is claimed from this non-match.

## Experiments

- Clean raw-source baseline 2395; raw mode store through a halfword cast 1710.
- Removing only volatile while retaining original variables/scopes: parent 2415; additionally removing the n=8/base=0 one-shot scope 2395. Scope retention alone does not solve aliasing.
- Independent native baseline lane: 1000 unique candidates actually compiled and judged, each generated from the same clean baseline, not from a best-candidate portfolio; best 2265, no exact match.
- Independent native Packet lane: another 1000 unique, actually compiled/scored candidates from packetptr0.c, no best-candidate portfolio and no exact result. Best 1200 via a pure inline offset helper; static __inline__ control inline0.c also scores 1200. Its u8 argument receives j in 0..3, its 0x7DB0+j*4 arithmetic is bounded, and there is no new unresolved helper call. It has 52 rendered differing positions, with 2 extra and 1 missing instruction; the unmodified Packet baseline has 2 extra/3 missing. Header/profile/target were unchanged.
- Directed probes cover width/sign of v/n/base, direct halfword branch capture, input declarations and pointer types, raw/field/global block views, direct counter lvalues, precomputed map destination, explicit loop shapes, and 16 scope combinations for n/base assignments. None exact.
- Scoped n=4 alone (or n=8 alone) gives 1330 with byte v. This is an ordinary single-execution scope and uses an already supported scheduling technique; it is not evidence for a new repair family.
- Builtin memcpy halfword reads were supported but worse (2353/2958/7628); no extra target calls were accepted.
- Parent flag diagnostics and private Packet flag diagnostics are negative for exact matching. Raw mode plus no-expensive-optimizations 1545 is a separate-profile alternative, not a like-for-like baseline improvement. Packet no-expensive-optimizations worsened 1350 to 1525. No live profile changed.

## Remaining differences

The first packet/slot decoding phase now agrees structurally. The remaining phase differs in the n/base/m register allocation, hoisting an outer-loop nonzero guard into a boolean instead of retaining masked n, hoisting the counter address, map address/result scheduling, and byte-v switch truncation. The target also retains a computed flag-base address that appears unused in the later phase. A pure inline offset helper changes counter-address construction and reduces the physical differences, but does not recover the target address/lifetime pattern. Do not manufacture dead identities or false branches to force it; recover a real lifetime/layout explanation.

Additional negative controls: 24 declaration permutations of m/n/base/q all stay 1350; real matched Game/Entry (entry at 0x44, v.w at +0xA) is neutral at 1350/1540. No source is promoted to a match.

Final read-only check: OPEN 1155, unclaimed, frozen target/header unchanged. All native processes are terminal; evidence.json records exact source hashes and both 1000/1000 compile counts.

All candidates still require semantic review. A lower advisory score is not a match, and no full cartridge build was warranted for these non-exact candidates.

## Native helper linkage finding

Parent compilation-symbol audit (parent-inline-symbols.json) found that the native perm_inline variant emitted a GLOBAL inline_fn helper, 16 bytes in .text, even though the selected target had inlined its call. Across generated translation units this can add unaccounted text or collide with another helper definition. The static __inline__ variant emits no helper symbol and retains the same 1200 score. The generator-only safeguard for newly introduced inline helpers was merged in decompdecomp PR #528 (https://github.com/RetroReversing/decompdecomp/pull/528), with a two-unit linkage/execution regression and 138 focused tests. Original source functions must remain unchanged. This is a tooling correctness finding, not a new game match or evidence of full-cartridge equality.

## November 5 bounded revisit

Eleven new packed-field and limit-lifetime controls were nonexact. The actual selected helper contract is void(s32,s32), whereas the earlier decoder declared void(u8,u16). Correcting the nonvolatile research prototype retains1200; this is not an exact match and does not establish the original interface independently. PR609 now flags bounded simple explicit prototype discrepancies in full briefs. No live source or profile change was made. Private frozen inputs, source hashes and raw linked evidence remain on the Data volume; no game data is included here.

## November 6: masked-limit Boolean phase

Fresh inputs under app cd710019 reproduce the nonvolatile real-Packet/current
void(s32,s32) callee-contract baseline1200. CSE emits a0<n Boolean; loop invariant
motion hoists it; combine rewrites it as ne(subreg(n),0), materializing an extra
sltu instead of retaining the target's masked integer count. This identifies
where the representation differs; it does not prove the original source shape.

Three new bounded controls were negative. A genuine equality-sentinel loop
removes the Boolean but uses a wrong lower-backedge representation, score1350.
Two genuine consumed pointer-output range helpers spill count/base and score4247.
Ordinary and diagnostic linked bytes agree for the baseline and all three controls.
No new native, flag, declaration or whitespace sweep was run; earlier explicit
if/do controls were not repeated. Live source remains OPEN1155 and unclaimed,
with the historical invented-volatile warning intact. No exact result or generic
repair is established. Normal project notes retain this new phase evidence.

## November 6: actual saved draft versus reviewed storage model

A fresh hydrated audit found the live1155 draft still used invented volatile
reads and declared func_80053C28 as void(u8,u16), rather than the actual selected
void(s32,s32). The selected serializer func_8006E8A0 establishes an ordinary RAM
Packet view at800C7112. The sole raw direct caller, func_80052BB0, agrees with
the focal void(void) interface. This evidence supersedes the old low-score
source; volatile cannot be retained solely to improve register allocation.

The corrected nonvolatile Packet draft has SHA256
`ce810760308848a369be6bcf3ea5135b31ed8ff03b013d3c33115d6fd1303787`.
Independent ordinary and diagnostic runs agree on1292 linked bytes at1200,
SHA256 `e1623e8600bd92ee548aaa3f27f07f17d633651f0d2ba2f6fac30f155f3c0a5d`.
It remains unmatched. No exhausted native, formatting or profile search was
repeated. These declarations do not prove all backing allocations, indirect
uses or arithmetic domains; existing explicit storage/alignment/lifetime and
integer-domain premises still apply. The immutable private handoff manifest
SHA256 is `aeef537f0e9e86c9c3ff3d90d422954dd5574476a89977f0f5e26be184a59c55`.

Parent independently reproduced1200, then normal source-scoped reporting and
adoption retained this exact source in the live project. A fresh ALL-progress
save confirmed the portable best draft agrees. All2071 selected matched C
sources remain unchanged by this unmatched-draft correction. Source formatting
(including existing whitespace) is retained exactly as judged, because debug
line structure can affect this period compiler's output.


## November 6: serializer-grounded component decoding

The actual serializer accumulates each two-bit component shifted by twice its
index. The decoder target instead uses two complemented-mask equality booleans.
Six new controls tested real alternative encodings without new memory effects:
if-bit accumulation2571, ternary2945, direct inverse extraction3168, complement
pair3483, and pure static-inline component helpers returning byte/int1200 each.
Both helpers preserve baseline linked hash e1623e86; all six ordinary/diagnostic
comparisons agree and have no link problems. Local inverse equivalence was
checked over524288 byte/index cases, not as proof of whole-record safety.

Accepted ce810760 source stays OPEN1200. No new native/profile/format sweep,
source adoption or positive automatic repair is justified. Private evidence:
serializer-nov6/REPORT.md and RESULT.json. These negative controls do not rule
out other valid matching source representations.

## November 6: accessor visibility audit

Current OPEN1200 source ce810760 remains unchanged and unclaimed. PR664 leaves
the current source and both historical native seeds byte-identical: its supported
two-argument accessors do not cover this source's one-argument H or object-like R.
H argument arithmetic was already visible to the native AST; the remaining opacity
is the dereference and R identity. Existing directed raw/Packet controls cover
those forms. This closes only a PR664-based repeat, not the function's search.
No compiler, preprocessing or native candidate generation ran. All2071 selected
rows/profiles remain unchanged. Private visibility-nov6/REPORT.md retains frozen
provenance and parser comparisons.


## November 6: serializer-backed separate storage objects

The matched serializer supplies independent named halfword flags and byte-map
arrays, while the decoder's current source models them as members of one inferred
aggregate. A previously untested control used separate s32 counters[4], u16
flags[12], and u8 map[12][4] objects at the same fixed RAM addresses. The existing
n/base branches bound indices to 0..7 or 8..11, and map columns to 0..3. Access
order, reads, stores, calls and physical source lines were preserved. Existing
raw byte-alias/storage assumptions remain; this is not a whole-program lifetime
proof or an invented overlapping object layout.

The ordinary and diagnostic results both score 1640, worse than the retained
1200. Their 1292 raw linked bytes agree, SHA256
 d25532994600715a6a816c5ac025e17ed335e5fbeb75c87c4e455820621ac724.
Separate symbols stop aggregate-base address sharing, but do not recover the
target's unused flag-base initialization or the count representation. No source
was adopted and no native/profile sweep followed. Private evidence, source/diff,
range audit and compiler artifacts are retained in cause-nov6.


## November 6: range copy-out and typed memory visibility

The previous two-byte aggregate-return range helper was already tested with
direct member consumers. One distinct control copied its count/base fields
back into the original u8 n/base locals before the unchanged loops. It reads
the mode once at the original branch point and introduces no new memory
access to game state. Ordinary/diagnostic output agrees at2673/1328bytes,
SHA256 d9481072334dcb3e364a39c3c776f2acd9a920fb59b303f9cca91e169db5b650.
CSE still emits a zero-extended count comparison; invariant motion hoists it
and combination retains ne(subreg(n),0). The scalar copy-out does not repair
the masked-limit mechanism. No range/profile sweep followed.

A separate parser-API check refines the earlier visibility audit. The H call's
argument arithmetic was visible, but native type inference raises KeyError H
and classifies the call as effectful/non-lvalue. R is absent from its type map.
Thus those seeds did not expose a well-typed halfword lvalue or the alias's
field types for native load/address temporary selection. This is a concrete
search-coverage distinction, not evidence that the original count diagnosis
is solved or that historical native candidates were all safe.

Manual expansion at each use preserves all22 global pointer uses and physical
lines. Actual pinned-preprocessor full translation-unit ASTs, including header,
qualifiers, bitfields, local scopes and static helper, are identical for original,
expanded and printer forms (41 root declarations, AST SHA256
bbde938923fcace967cdd9cea0b9a2dfa8475ae923e9bc6473c866724f4d5bd0).
Both expanded and printer ordinary/diagnostic pairs retain the original1200
and exact linked hash e1623e86. The native API now recognises a pure u16
dereference lvalue and the actual aliased field types. These preparation
checks do not constitute equivalence proofs for subsequent mutations.
Private current1200-coverage-nov6 retains the snapshots and paired receipts.


### Fixed typed-source search and rejected apparent improvement

One fixed expanded-source lane completed1000 raw emissions:464 compiled,
459 guard rejections,64 syntax rejections and13 lane-source duplicates.
All raw sources and prefilter lineage records reconcile; compiled output
contains291 distinct linked hashes. The historical byte cache is explicitly
incomplete. Type-aware temporary generation actually ran on the newly exposed
loads/addresses, rather than merely repeating opaque argument arithmetic.
A missing private helper import failed before any output; its zero-raw receipts
were retained. After the explicit import-only correction, the same fixed seeds,
root and1000 quota ran without a replacement lane or score feedback.

There was no exact match. The sole sub1200 result,1195, moved the mask load
into only the n=8/base=0 else arm; the n=4 arm then reads uninitialized m.
The parent independently reviewed that exact one-statement move and rejected
it. No validation compile, draft adoption or normal app mutation followed.
Warning preflight and the private new-temporary guard missed this existing-
local path regression; passing other screens is not a semantics proof.

The actual shared native guard also excluded existing locals. App PR715
(merged26ed3628) now compares supported per-binding initialization verdicts
against the parent. Unknown/unsafe parents remain distinct from initialized
parents. Synthetic scalar/pointer and traced-wrapper cases pass; replay rejects
the invalid1195 witness and flags four other previously compiled proposals,
while allowing the unchanged parent.141 related tests, whole-tree Ruff and
diff checks passed after current-main integration; GitHub reported no CI jobs.
Matching notes and the KMC guide were updated. This is a guard improvement,
not a new game match or a complete C-equivalence check.

All2077 selected full rows/profiles and complete focal inputs were preserved;
the live draft remains OPEN1200. The driver, generator and watchdog were
reaped. No app deployment/restart or cartridge claim. Private receipts remain
in current1200-coverage-nov6, including shared-existing-init-replay.json.


## November 7: current count-guard and decoded-word composition

Fresh read-only capture preserves current valid1200 sourcece810760,690 hydrated
attempts and all2077 selected full sources/effective profiles. The reviewed
explicit-guard control already retains the desired masked count at entry and
unsigned lower backedge (1613), but loses the target frame/register arrangement.
Earlier word-valued decoded-v tests used older seeds. One uncovered composition
changed only that guard control's local v declaration from u8 to s32.
Its only definition ORs two equality booleans, giving0..3; its map-byte store and
switch therefore retain the same values. Mask initialization remains before both
loops and after both count branches; no invalid1195 path regression is reused.

Exactly two bounded compiler calls produce ordinary/-da raw linked parity at1803,
1272bytes, SHA256
77869948d77bed105a5941f0c38b116f2bf36abe186fe280e178ff6b7c391a29.
Source SHA256c918a9cb61726bb361b4af92db8daab2f4ce2300ad58e390d41d46a859e4d0e6.
The count remains a hoisted zero-extended integer rather than a Boolean and the
switch no longer truncates v, but frame32/absent s1 and other allocation remain
wrong. Fixing these two representations together is not sufficient. Keep1200;
no further type/guard quota or adoption follows.

Objects independently reload/relink to the saved bodies. Both owned-process
watchdogs complete within20s/2GiB aggregate limits with no survivors. All selected
sources/profiles,690 history records and full focal inputs remain unchanged.
Private current1200-causal-nov7 retains reviews, range/definition-use evidence,
phase dumps and receipts. Outer worker commands were recorded; compiler flag
and executable templates were reconstructed, not literal ephemeral temp paths.
No live writes, generation, new match, cartridge or app deployment claim.

## November 7: identify the saved value before repairing allocation

A fresh read-only audit leaves the same 690 attempts and all 2,077 selected
sources and effective profiles unchanged. Reused diagnostic dumps identify the
baseline's saved `s1` value as the hoisted whole-RAM base, not the masked count
held in `s1` by the target. A matching frame size or saved-register name therefore
does not establish a matching lifetime. Initial CSE and loop motion introduce the
Boolean count guard before scheduling; the base-address expression is also
separated before allocation.

The decoded-byte local already occupies `a0` through local allocation, before
global allocation. A global-priority or scalar-copy repair alone cannot explain
its truncation. The earlier explicit guard and guard-plus-word controls already
test the relevant representation changes, without recovering the target layout.
No new justified source control emerged, so this audit made zero compiler,
Clang or candidate-generator calls. Keep the valid 1200 draft and investigate
another function. Private evidence: `current1200-stage-phase-nov7/REPORT.md`
and `phase-provenance.json`; the reused dumps are not a fresh compiler replay.
