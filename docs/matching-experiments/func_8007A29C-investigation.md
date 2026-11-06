# func_8007A29C revisit

Private evidence is in `revisit/`; no live or canonical project writes, claims, restarts, or accepted candidates were made.

Fresh readonly claim checks before capture found project 1/function 1546 open, score 2, unclaimed. Private app worktree is current origin/main 4bd73b7c02c7cfdc76ab2ddda29db1ebce963686. Immutable input capture is `revisit/frozen/inputs.json`, SHA256 a6d23a93841caeee2d0103bf9417407b232bbc1456c188f6f212d0d87eacfa61. ROM remains private.

## Directed evidence

Baseline reproduces score 2 and fails ordinary linked exactness. Exactly two linked words differ: table pointer store at 0x8007a3a0 and load at 0x8007a42c use stack +0x34 instead of target +0x14. Frame is 0x60. Previous work already tested extensive padding/order/carrier/flag permutations; its body-exact declaration-order alternative has frame 0x58 and fails 22 frame save/restore words. These experiments were inspected and not repeated.

Source contract audit found accepted wrapper sources 800592AC and 800592D0 declared void, but their machine instructions preserve the pointer returned by traversal 8005A744. Pointer-return caller use is machine-supported; accepted void sources are inconsistent metadata. Function 80069974 actually takes no arguments. Correcting its declaration/call, correcting 592AC's argument to s32, 5937C's second argument to s32, and 7EE9C's result to s32 leaves the same two raw differences. Explicit void parameter lists for three zero-argument callees also leave score 2. These controls are in `revisit/linked-controls.json` and `frozen/callee-contracts.json`.

The existing unreferenced pad[2] has no reads and is not an uninitialized-value dependency. It is nevertheless unexplained source padding, not proof of original source semantics. Removing it produces frame 0x58 and score32. No new dummy arrays, artificial register/volatile declarations or reads were added. Narrowing lexical lifetime of ctx, base, or tbl retains score2. Grouping actual existing live pointers into genuine local aggregates (2 or4 fields, no artificial fields) regresses to2167/2157.

Parent-suggested genuine addressable helper control: static inline table_flag(u8 **table, index) called with &tbl changes allocation to sp+0x18 and regresses1086, with other spill/scheduling changes. A paired direct pointer-value helper retains2. Moving tbl to first/second/third declaration positions under the addressable helper leaves1086. This is evidence that early addressability affects allocation, but does not reproduce the target.

Two final parent-directed controls also failed: pointer-to-const-pointer table_flag formal retained1086; separate table_base(u8 *const*) getter embedded in original H lookup scored1276. Sources and dependencies are retained in revisit/constgetter.py.

## Bounded native experiment

One independent native lane from the contract-corrected baseline completed1000 candidates delivered by the Generator.batch wrapper:48 duplicates,72 preflight rejects,123 forbidden-token rejects,757 compiled/scored. Best remains2; no improvement or exact result. Each distinct candidate has an independent Clang file, initialization diagnostics, retained lineage and separate attempted/compiled/preflight counts. This is not a complete UB checker; any exact candidate still requires semantic audit and parent independent full 12582912-byte cartridge verification preserving prior2065 objects/profiles.

No second native lane was run. No exact candidate was found, so the full-cartridge gate was not run. No match/acceptance claim is made. Final readonly check remains open score2 and unclaimed. The concrete remaining lead is genuine early addressable local allocation changing stack placement, with the controlled getter variants above as negative evidence. Further work requires a new source-shape hypothesis, not repetition of padding or these controls.

## November 5 bounded revisit

A fresh unclaimed freeze reproduced score2. Correcting three additional helper declarations preserves the same two spill-slot differences. Removing unexplained padding scores32; removing the single do/while wrapper scores52. Prior native/padding searches were not repeated. The known return-wrapper interface discrepancy remains unresolved, so a low score is not a global C correctness proof. No live source, compiler profile or target changed. Private frozen inputs, source hashes and raw linked evidence remain on the Data volume; no game data is included here.

## Current-contract, padding-free revisit

The pointer-return/u32-index wrapper and first-word storage corrections are now
accepted. Correcting the focal declarations and removing unsupported `pad[2]`
reproduces a padding-free score 32 control, with frame 0x58 rather than target 0x60.
Actual declaration initializers at their original evaluation points produce a fresh
score 30 variant, recovering one spill slot but not the frame or other slots. This
is not best-ever: an older valid frame-different alternative scored 22. None matches.

The fresh run records 66 admissible controls, 65 compiled, including 20 profile
controls; one CDK compilation fails and is not a negative match result. Meaningful
count/offset initialization recipes, nonoverlapping pointer phases, genuinely used
earlier table/record pointers, inline node filtering, actual table-record extents
and const views all fail. Two preliminary overlapping-lifetime union controls were
excluded by source review. No artificial padding or new native sweep was used.

Earlier profile sweeps used padded seeds. The new padding-free KMC O1/O2/O3 and
five debug-level combinations, plus four successfully compiled installed SN packs,
still find no exact object. No setting was adopted. These results require a new
allocation/lifetime explanation before repeating the same families. The function
remains OPEN; the app now carries a note explaining why saved score 2 is misleading.


## November 6: corrected draft selected and frame gap isolated

The live OPEN draft is now the current-contract padding-free22 alternative,
source SHA256 `0992fd5f932c882374207447c72f8454725febfb28fc93cd329ba0a3dda51841`.
A source-scoped quality report and normal corrective rejudge replaced the
misleading score2 padded draft. All2071 selected matched sources are unchanged.
The old corrected-contract-draft file above is historical and must not be used
as the current seed merely because of its filename.

Ordinary and diagnostic compiles agree. All body instructions and four genuine
pointer spill positions14/1c/24/2c already match. RTL reports an88-byte frame:
32 local bytes,40 saved-register bytes and16 outgoing argument bytes. The target
has the same ten saved registers but an eight-byte unused gap30..37 before them,
for a96-byte frame. No independently grounded fifth persistent value or genuine
eight-byte local object was found. Do not manufacture padding or repeat the
exhausted lifetime/helper/profile/native controls. This remains an unmatched,
revisitable function with explicit runtime storage and arithmetic assumptions.


## November 6: outgoing-area audit and native coverage correction

A fresh frozen source/header/profile/target audit confirms the current
padding-free22 draft. Across13 target JAL sites there are no outgoing stack
argument stores: stack writes are the ten saved registers plus the four genuine
pointer spills. Eleven current direct callee definitions show no incoming-stack
argument reads or aggregate/variadic evidence. A24-byte outgoing area is therefore
not a grounded explanation for the missing eight frame bytes.

The older native runner explicitly seeds the padded contracts.c score2 draft.
It does not establish coverage of current0992 padding-free22. Its1000 iterations
count candidates delivered by Generator.batch; raw internal emission count is
not established by that runner. Treating the old lane as exhausting the current
source was an overstatement. A new independent bounded lane from the corrected
source is justified, with separate emission/delivery/rejection/compiler counts
and full source/linked review required before acceptance. No result is claimed
for that new lane until its recorded process finishes.

The corrected-source lane finished without improvement or exact match:1000
received/persisted candidates,610 distinct candidates fully linked. Classification:
51 duplicates,214 lineage rejections,100 safety/text rejections and25 Clang
preflight failures. Requested jobs total1016; an interrupted batch leaves16
possible unobserved outputs, so1000 is not a proven raw-generation count.
An initial over-narrow symbol guard rejected85 compiled candidates that used
legitimate baseline address aliases. Those85 and two interrupted candidates
were rejudged from their recorded sources with the exact baseline undefined-symbol
allowlist.695 successful compiler invocations include these87 replay invocations;
they are not695 distinct candidates. The guard failures are not matching negatives.

Current source, header, profile, target and dependencies were revalidated unchanged;
no live project mutation or match acceptance occurred. A final bounded diagnostic
review of recorded candidates checks frame versus body differences separately,
rather than assuming the lowest total score is always the only useful seed.

That diagnostic review replayed eight recorded candidates at distinct low scores
26/27/30/32/42/46/50/52. Each retains the88-byte frame and1004-byte linked size;
none provides the target96-byte frame. This scope does not establish the frame
of every candidate in the lane. No further source proposal or generic app repair
was demonstrated by these results.
