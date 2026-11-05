# Rectangle-layout builder: func_80040CF4

Status: OPEN; no exact match accepted. Private copied inputs and compiler judgments only. No live claims, API mutations, canonical source edits, profile changes, or cartridge gate.

## Frozen evidence

Project 1, function id 836, 386 target instructions. Frozen OPEN 518 with no claim. Snapshot `frozen/inputs.json`, header, target, symbols, effective compiler profile and 12,582,912-byte ROM are private. Full hashes are in `evidence.json`.

Compiler: KMC GCC 2.7.2, `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

## Semantics and two useful alternatives

The function constructs screen/player rectangles and creates UI objects with sequential ids. The target reads the low byte at game-state offset 0xF for its initial count, but checks the full halfword at 0xE for the final split-screen adjustment. The source's `u8 n = o->mode` and final full `u16` read preserve this distinction. Signed extent promotion before division and narrowing at rectangle stores matter.

The saved source's second rectangle copy used `D_8009FFDA - 2`, subtracting before the declared byte array. This is not a sound ordinary C object expression. Two alternatives were measured:

- `address0.c`: do the subtraction in the target's unsigned integer address domain before converting to `Rect *`: `*(Rect *)((u32)D_8009FFDA - 2U)`. This uses the already resolved field symbol and mapped object address; it does not invent a symbol or alter the judge. Score 518, same 386 instructions. SHA256 `cd49cc207f101bbc8246dc68bb833610a8fb4e261a9ce602906f098fbe8b825d`.
- `clean.c`: read the actual root object directly as `D_8009FFD8`. Simpler C object ownership; score 818. SHA256 `c7193d038eabed3bd69a71c3c6d2a32a0faaeac33d3d362411c6bb8e356dcb9b`. GCC retains the root address across calls and removes two address-setup instructions, changing allocation throughout the function.

Neither is exact. For the 518 form, the advisory diff reports 102 register and 8 stack operand positions. The stack entries include width/height store alignment in the diff; they do not establish that the actual `Rect` field offsets are incorrect. The target and candidate store to the same rectangle layout, using different allocation/order.

Matched local renderers use conventional four-short rectangles and confirm extent/layout context; no matched donor for this exact function was found. The other imported region did not supply a close instruction-sequence donor in the 300–500-instruction range.

## Search and negative controls

Two independent native lanes start from their named audited baseline, not from a best-source portfolio. Each excludes expression-expansion lineage and uses the app's current generated-helper linkage guard. The harness attempted a Clang uninitialized-local preflight before the ordinary compiler/link judge. Two concurrent lanes accidentally shared the same preflight scratch file, so their preflight metadata is unreliable during overlap. Actual compiler/link verdicts always used each real candidate. Both retained baselines passed a later independent unique-path preflight. No exact or improved candidate was accepted.

The initial `native-independent` lane produced zero judgments because a private overbroad identity regex mistook ordinary member stores such as `r.h = h` for self-assignment. The actual generator was healthy. That own process was stopped and the filter removed; the valid new lane is `native-independent-valid`. Its results, not the zero-attempt lane, are the independent search evidence.

Directed controls include: signed versus full-width scalar locals, store order, one shared item pointer, separate initialized scalar declarations, genuine once-executed do/while scopes, real inline rectangle-copy helpers, and conventional local aggregate initialization. None matched. Removing the redundant-looking final assignment to `hh` changed scheduling/allocation substantially, worsening to 11531; source lifetime shape matters despite the assignment's value being unused afterwards.

Eight legitimate compiler controls: default/no debug/no-strength-reduce all 518; `-g`/`-g2` 678; disabling delayed branches or either scheduling pass worsened. No profile changed in the project.

**Discarded private prototypes:** `reuse.py` and `reuse-fixed.py` contain a global textual `p->w = w2` replacement that also touched the other branch. Their variants are not valid semantic repair evidence. Some also failed C90 declaration ordering. Do not import or count these as usable candidates. `reuse-local.py` and `reuse-subsets.py` restrict the replacement to the actual vertical branch; these valid controls also did not improve. Parent narrow-preserving controls are separate and should be described from their own result files.

## Remaining direction

A real lifetime/type/layout source reconstruction is still needed to reproduce the target's saved-register allocation, particularly item pointer s6, rectangle pointer s2, initial width s5 and height s3, and the split-screen half-extent lifetimes. Fixed-register declarations, fabricated arithmetic identities, fake branches, volatile qualifiers, assembly, ABI changes and judge changes are not remedies. Keep this function OPEN and revisit with new evidence.

## Final measured results

- Direct-root baseline lane: 1,000 attempted candidates, 990 compiled and scored, best 818, no exact. A later unique-path Clang audit found 957 safe scored candidates; 41 total preflight failures include candidates that also failed the game compiler.
- A small distinct ten-candidate supplement (before stopping quota filling): ten compiled/scored, best 818, no exact; eight pass the independent unique-path audit.
- Integer-address baseline lane: 1,000 attempted candidates, 990 compiled and scored, best 518, no exact. Per-candidate preflight metadata is not claimed reliable during the overlap.

All candidate sources, attempted hashes, lineages, ordinary results and audit logs remain private. Do not combine attempted, compiled/scored and preflight-audited counts. No additional candidates were generated just to reach an arbitrary passing-audit quota.

Final readonly state: OPEN 518, unclaimed, frozen target and header unchanged. No live writes, app deployment, profile changes, selected-C change or cartridge gate.

## Possible app safeguard follow-up

The app's limited introduced-scalar initialization guard currently gives no verdict for an entire function when any CFG node names a macro. Here gObj/gItem and a self-casting function-call macro disable it. Native candidate 444 compiles but uses a new scalar whose zero assignment exists only in the opposite branch; candidate 459 has a similarly uninitialized introduced pointer. Their scores are worse and neither was accepted. A future improvement could reason narrowly about known object-like/self-cast macros or analyze safely preprocessed source; arbitrary macros cannot be treated as pure reads. This is negative safety evidence, not a new match or proof of a complete C equivalence checker.

## November 5: forwarding-interface recovery

Twelve new bounded geometry/lifetime controls did not improve the focal score518. The constructor establishes allocated item storage; all17 direct calls to the matched label-copy wrapper pass item and label pointers. The old single-integer wrapper contract omitted that second parameter. The corrected two-pointer forwarding wrapper and a declaration-only correction in its matched caller each passed the ordinary linked judge. Canonical and live function bodies were compared before replacement; no unrelated alternative body was imported.

The separate two-source correction passed the full12,582,912-byte cartridge comparison, SHA256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7. All2069 compiler profiles and2067 other selected C objects are unchanged. Normal saved-source import has independently rejudged both exact and confirmed the corrected hashes. This is an existing-match contract repair, not a new match for the focal function.

The direct-call audit does not establish every indirect reference. Label string lengths were not proven from the available frozen segment mapping, so ordinary valid-buffer/string preconditions remain explicit; an incomplete bounds scan is not a safety proof. The downstream copy implementation's broader legacy typing was not silently rewritten. Private game evidence remains outside the repository.

## Independent declaration and extent-width revisit

Fourteen new controls separated declaration order from the earlier combined
load/declaration-order experiment. Corrected constructor/copy prototypes and
the audited unsigned mapped-address copy retained score 518. Declaration-only
height/extent order, rectangle/item declaration placement and branch-local
result lifetimes scored 518/523/533, without improvement. Signed rectangle
fields alone retained 518. Narrow width locals scored 3758, narrow height 1407,
and both 4897, regardless of signed versus unsigned stored rectangle fields.
Stored halfword fields do not establish narrow scalar intermediate lifetimes.

All matched neighbors from 80040084 through 800424C0 use the original KMC
profile. The prior compiler controls already covered no-debug, g/g2, strength
reduction, delayed branches and both scheduling passes. No new profile evidence,
exact match, native search or live source change resulted from this revisit.
