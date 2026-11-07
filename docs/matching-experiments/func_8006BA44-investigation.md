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


## November 6: current695 SN backend and flag controls

Fresh source-bound read-only capture confirms the corrected546e06d5 source,
825 hydrated attempts and the unchanged695 KMC draft. Prior native controls are
already current-source coverage; no random generation was repeated. Available
focal receipts supplied no SN result bound to this corrected source.

The actual saved KMC profile is -G8 -mips3 -mgp32 -mfp32 -O2 -ffast-math
-fno-strength-reduce -g3. First comparing installed SN registered defaults changes
both backend and flags. That produced0001 score3525/1040bytes,0004 score4022/1020,
and0006 score5532/1020. This alone cannot isolate a compiler-backend effect.

A second paired comparison copies all the actual KMC flags and adds the registered
SN assembler/dialect flags -mgas -meb -mhard-float. All flags were accepted without
removal or retries; emitted SN assembly banners retain them and real .loc records.
Correct32-bit big-endian ELF and successful linking are measured; flag acceptance
is not a general proof of every ABI edge case.

| Build | Score with current flags | Bytes | Linked SHA256 |
| --- | ---: | ---: | --- |
| 0001 | 3525 | 1040 | d6123ea814ef9eb9e869133e278abc5c6fe6926210dc7a44a24c6cc5ef48045d |
| 0004 | 3817 | 1020 | 86612dea830a6cd5469a03849297fc29899b122341b2f6a407d8d70337195b1b |
| 0006 | 5327 | 1020 | a4b197d8c346e26ad84fa762c450146cb3aedb8c2f5031b085f489a383762efc |

All six ordinary/diagnostic pairs agree in raw and linked bytes, with frame80 and
no unresolved links. SN0001 is unchanged by these flags;0004/0006 change, confirming
why defaults could not substitute for the second comparison. All results remain
worse than695. Exactly12 bounded compiler calls ran, with no new source variant,
profile adoption or game-data changes. All825 attempts,2077 full matched sources
and effective profiles, and complete focal inputs are preserved. Workers reaped.
Private current695-causal-nov6/REPORT.md, individual result files and
currentflags-summary.json retain commands, manifests, resource and byte receipts.


Resource-method clarification: these twelve calls used the shared macOS watchdog
with a20-second wall ceiling and a2GiB limit per descendant process. Inspection
of its implementation shows that it does not sum the tree's RSS; earlier private
wording describing an aggregate limit was incorrect. This correction changes no
source, command, linked-byte, parity or preservation result. No calls were rerun.


## November 7: local preferences and loop-motion composition

Fresh actual profile/source freeze preserves corrected695,825 hydrated attempts
and all2077 selected full sources/effective profiles. Profile remains G8/O2/
ffast-math/fno-strength-reduce/g3. Four individually reviewed controls ran exactly
eight compiler calls, with ordinary/-da byte parity and independent relinking:

| Control | Score | Bytes | Frame |
| --- | ---: | ---: | ---: |
| Shared first/second decoded magnitude local |1445|1028|80|
| Earlier shared tail plus equivalent explicit outer backedge |1602|1012|72|
| Same backedge, genuine immutable threshold captured before product |1110|1020|80|
| Same threshold form plus shared magnitude |2050|1020|80|

The magnitude merge removes the promoted first-byte local's s0 preference and
recovers index s0, record s1, decoded magnitude s2, but changes other scheduling.
The explicit backedge prevents unwanted slot-shift/byte-constant loop hoists,
while also losing the useful threshold hoist. Capturing the existing extern-const
finite2^31 value recovers threshold f20/product f22 and output base fp. This uses
the existing const-object contract, not a newly established readonly-section
proof. No calls are crossed and no arithmetic/rounding operation changes.
Recovering these structural properties is insufficient for an exact match.

Target AND12 at8006BC04 remains a real residual. It exists in initial/loop RTL;
combine deletes its chain and uses the prior narrowed value directly. A known
mask-sink control retains it but loses needed sign extension and changes calls.
A newly suggested conversion-carrier merge was not compiled: combine's current
last-value/label-tick information takes precedence over global all-definition
bit bounds, so a preceding unknown value does not establish the desired effect.
The new explicit-backedge forms also common table addresses in first CSE rather
than preserving the target's separate address formation. No artificial barrier,
volatile qualifier or type/width sweep follows. Retain695.

A host-width hypothesis was checked and rejected without compiler execution:
Mac release is Mach-O64, but configure selects i386/xm-linux.h and xm-i386.h
sets HOST_BITS_PER_INT/LONG to32; installed floor_log2_wide uses32-bit storage
and shifts. Mach-O64 therefore does not establish HOST_WIDE_INT64. No Linux VM,
new compiler or cross-host comparison was started or claimed.

All eight owned compiler trees completed within20s/2GiB aggregate limits with
no surviving owned processes. Complete selected sources/profiles,825 history
records and focal inputs remain unchanged. Private current695-causal-nov7
retains full source/effects reviews, commands, phase dumps, paired objects/raw
linked bodies and terminal/preservation receipts. No live edits, adoption,
new match or complete-cartridge claim.
