# Alternate packed record decoder investigation

The saved score-1000 source mutates invariant temp_s3 with <<=6 and duplicates an identical tail behind an artificial condition. Corrected source removes both. Frozen G8 profile produces unsupported .lit8 relocation; standard KMC GCC 2.7.2, -G0 -mips3 -mgp32 -mfp32 -O2 -g3 clean source is3004. Natural separate A/B tails improve1035; sound invariant-pointer recomputation improves945 under that standard profile, still NONEXACT with local .rodata mapping problem. Lower score is not directly comparable to frozen-profile1000. Best research SHA256 88b6fe6ba9aeb871805930fa253eb3eda1611df6daa5283049c4e9dcf9b7e7ec; see docs/matching-experiments/func_8006BA44-nonmatching-alternative.c. Final lane1000 native judgments found no exact; interrupted preliminary lanes and directed probes retained privately. Rejected unsafe perm_expand_expr: it recomputed captured row pointer after temp_s0 became decoded hv, changing later store addresses. The shared captured-expression safeguard was subsequently merged in decompdecomp PR #524: https://github.com/RetroReversing/decompdecomp/pull/524 . It rejects expansion after an operand changes while retaining eligible pre-mutation reads. Actual pinned-tool and C90 execution regressions passed; this is a safety improvement, not a new game match. Exact readonly constants verified: threshold2^31, factors4.5 and1.5. Explicit threshold and type/profile probes not exact. OPEN/revisitable; no live profile, target, ABI or judge edits; no standalone C selected.

## Byte-argument and literal-pool revisit

Fresh read-only capture remains OPEN1000, unclaimed. Six new semantically
admissible source probes were compiled under the unchanged KMC2.7.2 profile
`-G8 -mips3 -mgp32 -mfp32 -O2 -ffast-math -fno-strength-reduce -g3`.
Four exploratory shared-tail probes were excluded after finding inherited
artificial duplicate branches in a legacy baseline; two clean probes replaced
them. No native search was repeated. Actual caller/callee instructions support
byte arguments. The corrected natural provisional source is preserved beside
this note, but it is not a placed or exact candidate.

The provisional diagnostic1735 includes unsupported R_MIPS_LITERAL8; the
explicit original-threshold variant links without problems and scores2642.
A controlled G0-only profile hypothesis yielded diagnostic1545 for the natural
source and945 for the old audited best, both with unresolved anonymous pool
placement. The normal explicit-threshold alternative remains nonexact2642.
No profile was selected or altered in the live project. Lower diagnostic scores
with unresolved references are not improvements eligible for acceptance.

Private ELF inspection confirms literal relocation8 against the generated double
pool, with a signed addend offset by the assembler's GP value. The object GP is
not the game GP. The target uses an absolute threshold reference at another
instruction site. Raw ELF, assembly and ROM-pool captures stay private.
The existing type7 GPREL16 path is not a substitute for unsupported type8, and
literal support would still require actual target GP and address witnesses.


The target has no known GP and no GP instructions. Its absolute threshold
reference is at different instruction offsets from the candidate literal load.
Neither a guessed GP nor value-based pool placement is justified. A clearer
GP/literal diagnostic is useful; relocation support alone cannot solve this
function. The function remains OPEN. No live edit, accepted match or full
cartridge build was claimed for this provisional source.

### Compatible legacy byte-parameter interface control

The selected downstream byte-argument callee and an old-style C definition with
byte parameter declarations plus an integer prototype both reproduce exactly
the same linked bytes (SHA256
`64ccbfe0da49646ab64e535c5442b6b1f8e406153adb63a87642a8c6b47d807b`).
The old-style source SHA256 is
`9a4f7453cb3fa33842892ec998efb6cd5c2427e5a03da4a1897140726bd35758`.
This is a joint source-interface hypothesis: default argument promotions make
the integer prototype compatible with that old-style definition in period C,
not with the original ANSI byte-parameter definition. A C11 pedantic syntax
control also accepts this combination, with a deprecation warning; it is not
C23 syntax and must not be generalized to modern-language projects.

Using the compatible integer interface in the clean caller did not solve the
function: original G8 natural source1135 (unresolved literal8), explicit
threshold3099 without link problems; frame remains the target size. A final
G0-only natural control scores945 but still has its pool-address instructions
at different offsets from the target, so ordinary linking rejects placement.
It is byte-identical to the earlier audited-best diagnostic control, which
contains no artificial branch. No best-source portfolio, selected profile,
live callee correction or accepted match resulted from these controls.


## Modern compatible interface and corrected 705 draft

A fresh audit found the previous 765 source still incompatible with the selected
ANSI byte-parameter helper and the integer-parameter caller of this function.
The earlier root85 correction did not cover this separate interface. Nine direct
machine call sites identify six callers of `func_8006BF30`: four matched functions
and two open drafts.

The selected helper now uses integer parameters and four genuine byte locals.
This preserves its byte conversions and exact machine code. Four matched callers
now declare its actual void return and integer parameters, with explicit byte
casts wherever their previous prototypes supplied narrowing. All five normal
app rechecks are exact. The complete 12,582,912-byte cartridge remains identical,
preserving all 2,070 profiles and the 2,065 other selected C objects. No K&R syntax
or artificial ABI mechanism is needed. Other unselected draft interfaces are not
claimed globally reconciled.

In the focal function, an integer incoming category followed by a genuinely
consumed `u8` local improves 765 to 705. Per-use casts and self-assignment into
the wide parameter produce different code. The actual invariant output-table
pointer remains cached, the slot stays unchanged and the artificial duplicate
tail is absent. The normal app judge has selected the corrected 705 draft. It
is still OPEN and has not been selected as standalone C.

The observed caller supplies categories 1..4 and bounded slots. Converted values
are finite and at most 79.5; this supports the low-arm signed conversion here,
not a generic floating-cast rule. The actual ordered/unordered threshold predicate
is preserved. Dynamic records still require a nonzero divisor and valid storage,
and existing raw-memory/effective-type assumptions remain explicit. This removes
definite local errors and aligns the selected interface; it is not a whole-game
C-conformance proof.

Thirty-two valid new research compiles, including an independent proof replay,
found no exact match. One exploratory tail probe that skipped an update was
excluded. A prototype automatic typed-entry-local transformation reproduces 705
from the 1100 entry-mask control in two proposals. It remains private pending
type-inspection, language and promotion guards; no new app repair is claimed
enabled by this checkpoint. All current progress is saved normally.


## November 6: independent zero initialization and shared repair

The current-contract OPEN draft improves705 to695 by splitting
`var_a2 = (var_t0 = 0);` into two actual independent zero initializations, in the
target's a2-then-t0 order. No local, interface, profile, guard or unused operation
is added. Ordinary and diagnostic linked output agree across1028 bytes. This is
not an exact match; register, control and conversion residuals remain.

The bounded shared `split_local_zero_chain` generator reproduces exactly the
researched source SHA256
`546e06d57cd3af8ab046b04ee6804ab740a7c1d692d6217d383256f9f0be93de`
and score695. PR644 adds direct C32 invocation/type/binding/escape guards and175
focused tests. It is merged; the normal app judge retained the draft, preserving
all2071 selected matched sources. The compiler guide records the limits rather
than suggesting arbitrary assignment chains can be reversed.

Three further grounded controls were negative: actual byte slot local895,
separate conversion-index role725 and genuine group-phase local2340. Hydrated
attempt history was checked before testing; physical NULL source fields are not
missing history. No additional native/profile/declaration sweep was run. Existing
valid runtime category/slot/storage and finite nonzero arithmetic premises remain
explicit and are not a whole-game C-conformance proof.

## November 6: corrected695 native coverage

The previous native scripts start from older1030/1035/3004 models, and the last
app deep pass starts at1000. They do not establish coverage of the current
corrected695 source. A fresh capture confirmed its exact source hash and
ordinary/diagnostic parity:1028 linked bytes, SHA256
`44f1eac0a47b73c507baa853c1952341ba2b4592006a8a223f1253f7492879c4`.

One independent raw-protocol run completed16 jobs and1000 received candidates:
21 duplicates,343 forbidden-history rejections,97 text/current-safety rejections,
44 Clang failures and495 linked comparisons. No game-compiler or symbol failures
occurred after those guards. No candidate improved695 or matched exactly;
177 reproduced695. These bounded guards do not constitute a complete C proof.

Several native layouts preserve baseline code, so the lighting function's
formatter regression is not a blanket explanation here. No extra layout
controls or replacement candidates were generated. This exact starting source
now has recorded native coverage; another run requires a new grounded cause.
No live source, compiler profile or selected C changed. Private receipts are
current-nov6-native/RESULT.md, RESULT.json and coverage-audit.json.

## November 6: early common-tail phase control

The current695 source already obtains the target shared tail in jump2, after
register allocation. One new control ports only the real four-statement tail
into an early source goto/join, preserving both arms' signed decoded values,
narrowing, load/store order, addresses and initialized locals. No artificial
condition, local, interface or compiler setting was introduced. Its source SHA256
is2a0e0a3ad478380d70ef8cd7d93d92a082099006155a741779cd2ddd1e6ca968.
Ordinary and diagnostic builds agree at2819,1036bytes, linked SHA256
433a238cba754fe6e2d07e2a861dcc0cdaa8b806800948a5d30a917070609d9c.

The early join lets CSE share slot-shift pseudo173; loop hoists it and byte
constant195. Global allocation uses31 rather than29 registers;173 takes s6,
and invariant output base95 loses its fp allocation and spills atsp1C. Frame
increases0x50 to0x58. This measured control shows why merely making this join
earlier is not a repair. A separate residual mask is present in initial/loop
RTL and removed in combine, not lost by parsing. No mask-spelling sweep followed.

Exactly two compiler calls were made. All2071 selected rows/profiles and seven
protected input groups remain unchanged; current draft stays OPEN695/unclaimed.
No automatic improvement or match is claimed. Private phase-nov6/REPORT.md
retains full source/diff, branch mapping, objects and phase evidence.
