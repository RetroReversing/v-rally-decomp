# func_80059A60: audited dispatch baseline, unresolved

Private, read-only investigation of project1's 328-instruction function. No live attempt, selected source/profile change, canonical write, cartridge gate or new match claim.

## Frozen facts

Frozen inputs SHA256 `51f1da6d956c04d1fce93d207be84b827949a07de61333ebeb6a03bdc8bcc1a0`; function was OPEN, score200, unclaimed. Compiler: gcc-2.7.2-kmc `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

The saved draft manufactures a redundant `if(i==4)` whose two arms perform exactly the same assignment/call. Do not accept or generalize this as a repair. Removing it produces `clean.c`, score750. Also remove an unnecessary Group pointer copy. `formatted.c` is the same computation with ordinary multiline formatting, score630; its lower score does not mean physically closer code.

## Semantic audit

All Style/Widget/Group/Menu/Task field offsets agree with target loads/stores. The first dispatch runs indices0..4, selector2 for0/1 and1 otherwise, skips null tasks, and suppresses task1 only when f24D is nonzero. Calls and later global reloads retained.

The target's Group loops do **not** advance the outer Group pointer: s3 stays fixed through both loops. Only inner Style and Widget chains advance. Do not add a seemingly obvious `g=g->next` fix. n is u8, consistent with target count masks; i/j increments and wrap masks are retained. The u16 widget count may exceed an 8-bit induction counter; source retains that machine behavior rather than changing termination rules.

D_800C02AE+0x807A is address0x800C8328, aligned to4, and target loads a word there. f24B decrements only for nonnegative signed-byte values (result -1..126). f249 is an unsigned byte decremented only when nonzero. No uninitialized reads, fabricated volatile, inline assembly or new identities introduced. Ordinary game-pointer/list validity remains required, as in the machine routine.

## Remaining physical discrepancy

The original clean formatting matches the rest of the body apart from a missing dead s2=4 initialization at80059AF8 and beqz vs beql for the first selector case, with subsequent branch destinations shifted by4 bytes. s2's next occurrence after this definition is an unconditional zero definition80059C90; later loops independently zero it at80059D94/80059E78/80059EB8; epilogue restores the caller's saved register. Calls preserve s2. Thus this initial4 has no architectural consumer, and it is not evidence for an invented branch in source.

Multiline formatted630 introduces additional register/scheduling differences despite its smaller advisory score. Preserve both baselines; prefer physical review over treating630 as proof of better C.

## Failed directed experiments

No exact result from: equivalent loop bounds <=4/!=5 and unsigned casts; meaningful local bound4 with u8/s8/u16/s16/s32/u32 types; reuse of j/n as the bound; complete finite dispatch case groupings; direct per-case call formulations; legitimate terminal break forms; switch-line scheduling layouts; compiler debug/scheduling/CSE/strength-reduction variants. These preserve program computation (except separate diagnostic variants explicitly not proposed for adoption) but do not recover exact bytes. See scripts and per-candidate JSON files.

Native lane uses one independent clean baseline, never a candidate portfolio, filters expand_expr lineages, applies uninitialized-read preflight, and records every actually judged candidate. Rejected native best0's cast of a boolean to float was unnecessary; removing it produces the same formatted630 score. Do not retain arbitrary boolean-float casts as a matching technique.

Leave this function OPEN and revisitable. No new automatic rule is justified by the unresolved dead-initialization case.

## Final run evidence

1000 unique independent native candidates actually compiled and linked; no exact result. Best recorded advisory score630 was not a new semantic repair: ordinary formatting alone produces it. The six final do/while hypotheses (`i++<4`, `i++!=4`, `++i<5`, preserving continue-to-condition semantics) were also negative: clean scores1305/1610/1150; multiline1745/2050/1310.

## Valid byte-view and interface revisit

# func_80059A60 revisit: contract and enclosing byte-view audit

No exact match. Forty fresh private linked judgments compiled; no native search repeated. Live function remains OPEN200, unchanged and unclaimed on final read. No runtime, canonical repository, target, profile or live mutations. The previous 1000 native and 78 directed controls remain prior negative evidence, not this run's counts.

## Fresh capture

`fresh-inputs.json` freezes current function, project, header/context17, compiler profile and symbols; input SHA256 is in `evidence.json`. Target bytes unchanged from prior capture. Pinned app imports: `/Volumes/Data/Codex/tmp/loaded-byte-compound/src`, compiler gcc-2.7.2-kmc `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

## Important quality corrections

The live200 baseline still has the previously rejected identical-arm `if(i==4)`. It also takes `&w->active` then indexes `[1]`, crossing that scalar member's subobject. A direct `w->mode` rewrite is semantically right but changes allocation: previous clean750 becomes1256. Instead, an unsigned-character view of the actual enclosing object, `flags=(u8*)w+0x41`, permits inspecting both bytes inside Widget. This preserves750 with no identity branch. `cast-corrected.c` additionally declares actual47B54's `(void*,s32,s16,s16)` argument ABI and explicitly converts signed f233 to u16 before passing it, retaining the machine's unsigned-halfword argument behavior.

A genuine two-byte `Widget.flags[2]` representation also preserves750, but the enclosing-object byte view avoids introducing a separate layout representation solely to retain allocation.

Fresh selected-source evidence (`callee-sources.json`, parent-selected-contracts.json) exposes further legacy discrepancies:

- 599D0's second argument is s32, not u8. Correcting this and passing Style through a byte view preserves750.
- 592AC's actual parameter is s32, not u16. Its selected definition is incorrectly void while forwarding 5A744's pointer result; 592D0 has the same return forwarding problem. Their genuine pointer-return definitions need joint correction before calling the whole chain C-contract-clean. This revisit does not silently alter those selected functions.
- 57918's selected definition returns s32 and accepts `(s32*,s32)`, not `(s32,u16)->void*`.
- 596F4's selected argument ABI is `(Arg*,s16,u16,s32)`, not `(Style*,s16,s16,void*)`.
- Actual distinct structural pointer types across translation units are not globally reconciled. `contracts.c`/`explicit-narrow.c` are argument-ABI probes, not claims of full ISO cross-TU type compatibility.

Correcting known scalar argument ABI mismatches jointly gives1135; explicit halfword argument conversions give950. Neither is exact. Individual corrections and their exact diffs are preserved. Lower advisory scores do not excuse invalid source, and larger scores do not refute a necessary interface correction.

## New negative controls

The prior typed-bound experiment used multiline formatting. This revisit tested clean-layout typed bounds and literal forms with lawful member or array views: these are new combinations, not another blind native run. The apparently closer410 result retains `s2=5` as a genuinely consumed runtime bound and uses `slt`, whereas the target has dead `s2=4` followed by immediate `sltiu ...5`. It therefore does not recover the original behavior of compiler passes. No distinct legitimate task4 effect was found that would justify inventing a branch just to preserve that dead initialization.

All 40 judgments have per-source JSON and source SHA256 in evidence.json. No cartridge build was warranted for a nonmatch.

## Automation implications

A useful diagnostic is to distinguish character views anchored to an enclosing object from arithmetic past a scalar member. An automatic source rewrite can propose `w->mode` or the proven enclosing byte view and rejudge; it must never prefer the invalid low-score version simply because allocation was closer. Existing function-signature repair should surface the actual selected scalar ABI and propose explicit caller conversions when required by target argument preparation. Pointer-return wrapper corrections require a joint contract gate and full cartridge validation, not a local-only claim.

No new matching repair family is demonstrated by this unresolved function. Keep it OPEN and revisitable; retain prior negative evidence. Do not generalize the fake identical-arm task4 branch or an arbitrary dead initialization into the permuter.

## Current-contract correction and late jump-pass evidence

The ordinary app review flow now retains a corrected **OPEN 950** draft,
SHA-256 `51ea779e856af16f83bfe157f916705ace2cd72d49ee285fce446ca7c2272407`.
The parent independently reproduced its ordinary linked score, reported the
historical source's quality defects and adopted the compiled alternative.
All **2,071 matched sources remain unchanged**. This is a provisional draft,
not a new match, and no selected cartridge C changed.

The correction removes the invented identical-arm task-4 branch, replaces
indexing beyond the active scalar with an enclosing-object character view,
and agrees with the current selected wrapper/callee types, with explicit
required argument conversions. Underlying raw-storage/effective-type and valid
list/callback lifecycle assumptions remain explicit, not globally proven.

Diagnostic and ordinary linked bytes agree. In the rejected old source, the
task-4 comparison survives register allocation (`greg`) with its loop-hoisted
constant in s2. `jump2` then merges the duplicated call/store arms and removes
the comparison, leaving the dead constant. This explains the rejected draft's
artifact; it does not prove the original source had that artificial branch.
Seven genuinely finite task-context/call-region helper controls are nonexact;
old native and formatting sweeps were not repeated. The reusable negative
finding is recorded in app [PR #636](https://github.com/RetroReversing/decompdecomp/pull/636).

Actual task setup distinguishes slot 4's creation context, but the dispatcher
still selects context 1 for slots 2/3/4. No real slot-4-only dispatch effect was
found to justify a redundant branch. Runtime-resolved callback descriptors do
not supply a complete signature proof.

Changing the drawing callee's second coordinate from unsigned to signed
halfword preserves its private exact object and gives a prospective focal
score 750. That callee has additional concrete direct-callee contract defects,
so neither the signed interface nor the score-750 caller is selected. Future
work must close those contracts and preserve all selected callers before any
such adoption. Continue from the reviewed 950 draft, not the invalid 200 seed.

## November 6: current-source and compiler-stage audit

The actual saved OPEN950 source was hydrated and matched the reviewed baseline
(SHA256 `51ea779e856af16f83bfe157f916705ace2cd72d49ee285fce446ca7c2272407`).
Ordinary and diagnostic builds produced identical linked code. The latest lower
460/940 histories still contain the rejected duplicate task branch and old type
contracts; they are not admissible seeds merely because their scores are lower.

Three residuals arise at different stages: the unused task-4 assignment is
already absent from initial RTL; the first selector's ordinary versus annulled
delay slot is chosen in the late `dbr` pass; and the signed versus unsigned
halfword load follows the selected drawing callee's unsigned coordinate formal.
A private signed-coordinate callee control requires closure of its other direct
call contracts before adoption. These facts do not establish a safe automatic
rewrite, and no invented guard or repeated native/profile sweep was run.

This audit changed no selected C or compiler profile and found no new match.
The underlying allocation, lifetime and indirect-callback assumptions remain
explicit limitations. Private evidence manifest SHA256:
`46071ce0b756bb34ba3ee42a62964454de3e0b08e4b1c12b380558f1f5bfa874`.

## November 6: complete drawing-interface correction and guarded values

The signed-coordinate lead is now integrated. A coordinated50-source correction
makes four implementation interfaces and their actual caller declarations
compatible. Public opaque pointer interfaces retain typed
views at existing accesses. Three register colour inputs use integer formals
and actual byte stores; the stack alpha input stays byte-sized. Four scale
arguments now read the same-offset floating fields rather than numerically
converting loaded integer bits. Existing narrowing is retained explicitly.

New early pointer-view initializers changed scheduling; casts at existing
accesses preserved exactness. Promoted stack count/mode locals or entry
assignments changed homes/allocation, so those controls were rejected. The last
caller instead propagates values already proved by its existing equality guards
into six call arguments. No configuration read, condition, capture or observable
call is removed. The locals are unescaped, unchanged and dominated by their
guards; the sibling label cannot enter the true arm. That caller returns from
825 to exact. This is a correction of an existing match, not an additional one.

All50 selected sources independently pass ordinary/diagnostic raw-byte equality.
The full12,582,912-byte cartridge comparison passes, SHA256
 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7.
All2071 profiles and the other2021 selected objects are unchanged. Normal saved
source verification independently accepted all50. The normal scoped compile
path retains the improved OPEN750 focal draft, SHA256
 e56b4b68c62f2ff061ffc358f42ed9240dcbae1e902e8b0aa5a3000cd53219cd.
All2071 matches remain;16 functions are open and34 remain assembly.

The helper retained148 compiler invocations, including rejected controls, in its
private contracts-nov6 report and handoff manifest. Parent independent cartridge
and normal-import receipts are in parent-gate. Direct-JAL and literal-address
audits do not exclude dynamically built indirect references. Existing raw-storage,
lifecycle and private layout assumptions remain explicit. App PR667 is merged (5e19c7bd): the shared guarded_call_value family independently
reproduces the exact825-to0 repair, with ordinary/diagnostic parity. The actual
bounded pipeline emits the validated source; the exported arm64 alpha.4 app
reproduces it too.274 targeted tests pass. This remains a controlled replay of
an existing match, not an additional game match or measured token saving. No
automatic global interface rewrite is claimed.


### Current 750 draft: consumed countdown control

A fresh signed countdown in the first loop (`remaining = 4`, tested against
zero, decremented in the existing loop update) visits exactly indices 0 through
4, including the original continue path. It worsened the score to 1475 with
ordinary/diagnostic byte parity. Its initialization stays live in s0 and the
latch becomes BGEZ, rather than explaining the target's residual dead s2=4 and
unsigned index latch. This is negative evidence against another countdown sweep;
the 750 draft remains selected. No artificial branch or unused operation was
introduced. Private proof and paired receipts are retained in
`current750-nov6/countdown-control`.


### Typed alias visibility and printer baseline

The native parser sees 31 uses of the object-like MENU alias without its typed
pointer expansion. Expanding each use at its original location preserves every
global reload. Three pinned preprocessor runs confirmed identical current and
expanded tokens, and complete translation-unit AST equality including declarations
for the current, expanded and native-printer forms. The expanded source retains
score 750 with ordinary/diagnostic parity. The native printer alone scores 630,
but adds seven operand and two reordered differences; this is a formatting
baseline, not evidence of a better source repair or a new match. It was not adopted.
The current residual includes the target's extra initialization to 4 and a
branch-likely difference; displaced branch operands account for much of the score.
Private preparation evidence: `current750-nov6/exposure-proof.json` and paired
`exposed-control` / `printer-control` receipts.
