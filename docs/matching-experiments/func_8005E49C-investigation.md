# func_8005E49C revisit

No exact candidate. Live source is semantically wrong despite score 25. No live, canonical, API, claim, runtime, compiler-profile, or judge mutation was made.

## Frozen inputs

Fresh read-only claims check immediately before capture found function 1222 open, score 25, attempts 738, unclaimed. Final read found identical state. Inputs are frozen privately under `frozen/inputs.json`; source, context header, profile, symbols, target, compiler executables, and linked-object hashes are in `evidence.json`. Private detached app checkout is origin/main 4bd73b7c02c7cfdc76ab2ddda29db1ebce963686. Pinned GCC 2.7.2 KMC flags are unchanged. This capture's source/header/target/profile hashes equal the previous investigation's, so the old native search is relevant.

## Required semantic repair

The target resets s1 to zero in the delay slot at 0x8005E598 before the second loop. The live source omits this reset. For example, when func_80084E10 returns 2 and all checked entries pass, the first loop leaves s1=2. Live C then writes only entry 2 before stopping; target writes entries 0, 1, 2. Returning a zero count can conceal the defect. A source that simply removes the reset cannot be accepted.

`clean.c` adds exactly this required initialization and scores 140 on the current app. Its linked object is 500 bytes versus target 496 bytes. Target's conditional branch delay sets a0=s4 and the following jal delay resets s1. GCC emits these two in reverse order and then needs one extra a0=s4 setup on the failure path. The obsolete `exact.c` filename in the parent directory never represented a match.

## Callee contract audit

Read-only inspection of matched callee sources establishes that func_80084E10 returns u8 (bounded by 4), func_800857C0 returns s32 boolean and ignores the caller's second argument, func_80084AF4 is an empty stub, func_80084AD8 is a void wrapper, and func_8005A338 returns s32 zero while ignoring caller arguments. The caller machine code nevertheless deliberately sets a0/a1 for the latter calls. These machine/source contract inconsistencies do not justify deleting the induction reset. `clean_contracts.c` corrects the known return types and gives func_8005A338 an unspecified parameter list to retain the machine-observed legacy extra arguments; its score remains 140. Empty matched stub prototypes alone cannot recover original parameter declarations.

## Directed tests and prior negatives

Five newly generated directed candidates compile: failure early return 1720, failure goto 225, each with known return contracts 1720/225, clean with contracts 140. Every source has a separate retained pathname and result. These genuine control-flow variants avoid arbitrary dummy branches, arithmetic identities, cancellation, fabricated volatile/register qualifiers, or uninitialized values. No candidate is exact.

The earlier private investigation already tested reset placement, independent counter lifetimes and types, declaration scope, argument staging, control-flow inversion, inline wrappers, verified profiles, and 3,000 compiled native mutations from this same frozen source/header/profile/target. None produced a valid improvement over the repaired baseline. A fresh native lane would repeat the same audited baseline without new concrete evidence, so none was launched. Current counts: 5 generated directed candidates, 5 compiled, 2 baseline compiles, 6 linked evidence recompiles, 0 new native attempts. Native guards in prior work are not a complete UB proof.

## Handoff

Parent may recover the required reset as a higher-score draft using its ordinary scoped manual MCP report/revoke/GUI quality adoption workflow; helpers made no API writes. The scheduling mismatch is the remaining concrete lead. No candidate qualifies for acceptance. No full cartridge gate was run: any eventual exact candidate still requires parent independent byte comparison of the entire 12,582,912-byte cartridge while preserving all 2,065 prior objects/profiles. All game data and evidence remain private.

## Raw proof correction

The first evidence script mistakenly labeled `LinkResult.candidate.code` as linked bytes. That object is the canonical relocation-bearing diff representation and contains zero address fields. The corrected script uses `LinkResult.linked_code`, the fully relocated machine instructions at the frozen function VRAM using frozen symbols and the ROM read callback. It asserts that the first two relocated instructions equal the target. `evidence.json` has been regenerated; its linked hashes and raw differences now describe actual relocated instructions. Exact verdicts and advisory scores were unaffected.

The recovery candidate is `clean.c`, SHA-256 `816e9a79bb56ad2bf4187ec62387f1667bc25bf0b8818dbb9c74f8420b76d2b3`, score 140. This is solely a required loop-reset repair for source quality review. Its constructor/reset call declaration remains `extern void func_8005A338(s32, s32, ...);`, whereas the matched callee source is `s32 func_8005A338(void)` and ignores arguments. Thus it does not certify a recovered interprocedural C prototype. `clean_contracts.c` changes the return type to s32 and uses unspecified arguments to preserve machine-observed caller setup; it does not prove that historical extra arguments are valid against a strict void-parameter definition. The empty func_80084AF4 stub has the same ignored-argument ambiguity. Neither draft is an exact acceptance candidate.


## Parent corrective adoption

The parent used its own temporary project-scoped MCP connection to claim, normally compile and report the missing reset against the historical25 source, attaching clean_contracts.c as a measured alternative. It revoked only that connection and its claims, then used the ordinary GUI candidate-review adoption to rejudge and select the corrected140 draft. This fixes the definite loop counterexample; unresolved legacy ignored-argument/callee prototype compatibility remains explicit. No exact match or cartridge acceptance is claimed. All current progress was saved normally.

## November 5: allocation provenance and interface audit

Six new call-preserving boolean accumulation controls scored140,940 or1206; none matched. The selected allocator and independent users establish20-byte page arrays,12-byte subentries and12-byte data records. The old pointer/offset views have been replaced in the separate research source with these actual arrays. Resource helper pointer declarations were reconciled privately. Both changes preserve the exact same500 linked candidate bytes and score140, against496 target bytes.

The new starting point is `func_8005E49C-layout-research.c`, SHA256 `a74af4ca17516bcedc0dc1bcf3025858c379234fcb74a2c92dcd52743f3d5f47`. It is research, not accepted matched C. Actual input counts must still establish at least four pages, three subentries in page3, four data records per selected subentry and three records in page0. Mixed zero/one-argument and zero/two-argument uses of two stubs remain unresolved; do not invent required parameters for them.

A separate direct-caller audit found all nine calls to `func_800857C0` pass second integer argument2. Adding an unused second `s32` formal and correcting five caller declarations passes six individual pinned linked checks. This also corrects one caller's `s8` return declaration to the callee's `s32`. Full cartridge verification and normal app acceptance are pending; no new match is claimed. The first parameter and complete callee body are unchanged. The audit covers direct calls, not proof of every possible indirect reference.

App PR606 adds bounded advisory empty-stub interface warnings. It does not change any signature, target or verdict. Existing loop-reset safety guidance already covers the earlier missing-reset defect. Private byte evidence and game data remain outside this repository.

### Joint contract correction accepted

All six corrected sources passed the full12,582,912-byte cartridge comparison (SHA256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7). All2069 selected profiles and2063 other C objects are unchanged. The normal saved-source import rejudged all six exact; readonly final source hashes agree. Standalone source bodies were also compared against frozen live bodies before replacement; only include wrappers differed. No new matched function is counted. A fresh normal ALL-progress snapshot accompanies this correction.

## Delay-slot dependency revisit

Twenty-four unique source controls across 25 measured runs did not match.
The allocation-grounded baseline stays at 140. The target places argument setup
in the conditional branch delay slot and the required counter reset in the
following call delay slot; GCC reverses those assignments and needs an extra
argument-setup instruction on the failure path (500 versus 496 bytes).

Switch order, genuine success early return/common-call factoring, reset lifetime
placement, conventional source-line layouts and real three-field record copies
were tested. Debug-line notes can affect scheduling: compacting the prefix
worsened the score to 660, while local reset/branch layout stayed at 140. This
negative result does not justify a formatting repair family. The required reset
was never removed; no dummy branch, register binding or volatile was introduced.
Mixed-arity helper contracts and record-bound preconditions remain unresolved.
No exact claim, full-cartridge claim or live source change is made for this pass.


## Accepted exact checkpoint: selected empty-callee contract

The previous negative results are superseded by a 496-byte exact match. Selected
`func_80084AF4` is an empty `void(void)` function. Correcting its caller-owned
declaration and dropping its side-effect-free scalar arguments allows argument
setup for a later failure-path call to occupy the earlier branch delay slot.
Using the genuine incoming parameters directly, rather than copying them into
unchanged scalar locals, then recovers register allocation. The required reset
is retained. No padding, dummy operation, volatile or register binding was added.

The first proposal from the bounded composed automatic repair reproduces the exact
source (SHA256 `3bad25f35c369a7ef51a2fcbda2242a5ab8e1540fe655a78cd602ec7390dda9e`).
Ordinary pinned compilation and linking establish all 124 instructions / 496 bytes
exact. The normal app judge accepted score 0. The full 12,582,912-byte cartridge
comparison passed, preserving all previous 2,069 C objects and profiles.

The pre-existing `func_8005A338` zero/two-argument interface inconsistency remains.
Its selected definition is not empty and is not eligible for this repair. The
original two genuine arguments are retained; no extra arguments or ABI tricks were
invented. Array bounds, callback/resource validity and the retained mixed-arity
interface limit the semantic claim: this is verified byte identity, not proof of
whole-program C conformance. All portable progress accompanies the match.
