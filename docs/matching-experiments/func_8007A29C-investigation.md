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


## November 6: historical profile frame inventory

All20 recorded padding-free profile receipts were inventoried separately for
frame/save/restore and positional differences:19 successful linked outputs and
one CDK failure. Fifteen KMC controls plus SN0001 use88-byte frames;
SN0004/0006/970404 use72. None allocates96.

These receipts bind historical c1fbef6f source, not current0992fd5f; the table
pointer declaration order and a blank line differ. Header/profile/target agree,
but this is not fresh current-source profile evidence or alignment-aware body
equivalence. No new compiler run or sweep was performed. Private evidence:
profile-frame-audit-nov6/REPORT.md, results.json and audit.py.

## November 6: recorded storage lifetimes and callback barriers

The610 linked native receipts do not retain objects, so their complete frame
inventory cannot be inferred without recompilation. Five structurally relevant
recorded candidates were replayed. Frames/scores:104/2837,88/397,96/3110,
88/597 and96/1020. The two target-sized frames are not acceptable seeds:
one substitutes nonconstant integer nulls and caches a count across calls;
the other hoists a global pointer across unresolved callbacks.

The latter's immediate global capture and genuinely consumed local pointer
copy are safe in isolation, but removing only the unsupported early global
capture returns frame88/267. Eleven direct callee checks and a seven-function
closure do not establish global stability: func_8007EE9C invokes three
unresolved callbacks. Absence of a direct named writer is insufficient.

A two-phase table pointer captures each read at its original phase, consumes
both definitions and reloads after callbacks. It produces88/122,1004 linked
bytes with ordinary/diagnostic parity. Its differences are22 frame offsets
and20 register allocations, with no opcode, branch or inserted-operation
differences. It does not improve selected22 or justify unused frame padding.
No live source or compiler profile was changed. Private evidence:
current-nov6-storage/storage-frame-audit/REPORT.md and
0992-consumed-table-phases artifacts.

## Real word-unit address controls — 6 November

A distinct compiler-slot observation from another function motivated one actual
halfword table-flags read expressed as a word index plus field index8. The
original byte offset is (signed-byte-index + signed-byte-loop-index)*708 +16.
Both operand ranges give a bounded even product; unsigned32 divide/add/scale
then the period MIPS32 signed conversion recovers precisely the same signed
byte offset, including negative offsets. One final byte-pointer addition and
the original halfword read remain. No typed-array provenance assumption, dummy
storage, extra memory operation or interface change was introduced. Parent
arithmetic checking covered all65,536 signed-byte operand pairs; this does not
prove whole-game storage bounds, which remain the original model's premise.

A fresh full live input binding and historical782-attempt/3,531-source audit
found no equivalent composition. Ordinary and diagnostic builds both produce
score22, frame88,1004 bytes, linked SHA256
2bac576f07fa5f85ac2a35fe22658dc2c859d96c47c41f917d5ced4aec2784b7,
exactly the baseline bytes. Initial RTL folds the word field back into byte16
before late allocation; no new USE or scratch slot appears.

One follow-up captures the actual field index8 in a fully consumed ordinary
integer local. The initial declaration-after-statement form failed C89 parsing;
only its syntax was corrected by declaring at the start of the existing inner
do block and assigning at the same intended point, without adding scope.
Removing that declaration/assignment and propagating8 exactly recovers the
approved first control. The successful ordinary/diagnostic pair still produces
the identical baseline bytes and frame88. Although register146=8 and the word
addition survive initial RTL, no standalone USE remains at late allocation.
This precise unit/lifetime hypothesis is closed; neither source is adopted.
Private receipts: func8007A29C/word-units-nov6, including full RTL and prelude.

## Frame origin and fresh context phases — 6 November

An actual target/compiled stack map identifies the gap precisely. Both have
four real SI pointer homes at20/28/36/44, with actual stores and reloads.
The current16-byte outgoing area and32-byte local area are followed by ten
saved registers at48..84. The target retains the same homes but saves those
registers at56..92, leaving48..55 unused. The22 unequal instructions are two
frame adjustments and20 register saves/restores. No target access identifies
a fifth value. All13 retained pinned RTL stages contain only QI/HI/SI modes,
no DI/floating conversion, no standalone USE, and no visible local stack
aggregate or fifth scratch request. GNU reference allocator code cannot prove
the unavailable vendor binary's internal allocation history.

One fresh two-phase context binding reloads D_800C3508 into the existing ctx
local immediately before the final block, consuming it there in place of that
block's three global reads. The initial ctx definition remains consumed by ent;
all earlier callback barriers and inside-loop global reloads remain unchanged.
There is no call or write between the fresh final capture and its consumers.
Undoing only this edit recovers the current source exactly. Ordinary/diagnostic
parity gives597/1004bytes/frame88; the same four homes remain, and body changes
regress overall. No adoption. This differs from the earlier D_800C35A0 table
phase experiment, which captured a different global.

An additional eligibility audit identifies a genuine arithmetic carrier model:
off has only its declaration, initial u16 load, existing u16 store and +=20.
Its address never escapes and no intermediate value is compared or used as an
index. A u32 carrier preserves all observed low16 values through unsigned
wrapping arithmetic, with the actual load/store widths unchanged. The target
uses lhu/addiu/sh without masking that carrier. Prior wide-offset82 receipts
are different source compositions; the exact current-source control is being
measured separately, without asserting improvement in advance.

The sole current-source off declaration change u16→u32 compiled with
ordinary/diagnostic parity but reproduces22/frame88 and exactly the baseline
linked bytes. Off's RTL mode changes HI→SI and remains in s5; its actual field
load/store are still halfwords. The same four pointer spill homes remain.
Thus local arithmetic width is ambiguous from these bytes, but this valid
carrier model does not explain the missing frame space and is not adopted.
No inferred allocator-request instrumentation is claimed.

## Compiler-expanded search visibility — 6 November

The recorded current-source native batch retains B/P/H/SH as opaque calls:
25 byte,10 pointer,7 unsigned-halfword and4 signed-halfword macro uses. Actual
m2cfix processing leaves this input unchanged. The pinned native AST sees59
calls, of which only13 are real calls,33 binary operators,8 casts and6 unary
operators. Actual compiler preprocessing of the focal body exposes those46
macro uses:13 real calls,79 binary operators,100 casts and52 unary operators.
Assignments48, declarations44, compounds13, array references6 and the three
original do constructs remain unchanged.

Both the expanded source and unmodified native printer reproduce the baseline
22/frame88/1004bytes with ordinary/diagnostic parity. Full preprocessed header
and body ASTs also agree. This establishes a distinct search input, not a new
match or a claim that every macro expansion preserves code generation.
One bounded1,000-raw lane is authorized from this proven exposed seed with six
fixed meaningful transformations and current safety guards. Every linked
candidate records actual frame and SP geometry; target-sized candidates retain
objects so their frame inventory can be reviewed without recompiling or
selecting solely by scalar diff score. No result is claimed while it runs.

The exposed lane completed exactly1,000 raw emissions and16 done receipts:
675 linked/compiled,262 safety/grouping rejects,40 preflight rejects and23
duplicates; no compiler/symbol failure, exact match or result below22. Every
linked candidate has recorded geometry:435 frames88,191 frames96,36 frames104,
11 frames112 and2 frames80. Objects/bytes/source for all191 frame96 outputs
are retained. There are145 distinct linked frame96 bodies.

Manual review rejects stale-node capture, unsupported global hoisting and
conditionally initialized pointers among the apparent frame frontiers.
Candidate28's field-address capture and late entry-pointer phase appear valid
on the original object domain, but its96-byte frame has a real fifth spill
at52, unlike the target's unused gap. It does not solve the geometry. The
late-entry-only component already exists as candidate27 (157/frame88), so it
should not be recompiled as a new experiment. A field-address-only isolation
is prepared but has not been compiled or adopted.

This run exposed a reusable app defect: the shared initialization guard checked
introduced integer locals but missed pointer captures. PR661 extends the same
bounded analysis to known integer/void pointer types and distinguishes a
pointee write from initializing the pointer itself. Replay flags ten additional
possible uninitialized pointer captures that previously reached compilation;
two manually confirmed bad captures are rejected while the reviewed valid
field-address capture remains allowed. This is not a complete C equivalence
checker or a general performance estimate.158 related tests, whole-tree Ruff
and diff checks passed; PR661 was inspected and merged asffba8794 (no CI checks
were reported). A shareable arm64 v1.0.9-alpha.3 app was exported and verified;
the running app was not updated or restarted. Live function remains OPEN22.

The prepared field-address-only isolation was subsequently tested once with
ordinary/diagnostic parity:461/frame96/1016bytes, linked SHA256
 d9a946d64ad1457513dbcdbf575dae30635e20a6895c2d4ae3bb3152ba1d1211.
It introduces an actual fifth home for node_head at36; cnt/q shift to44/52,
with tbl/ent at20/28. The pointer-address materialization, spill and reload add
three runtime instructions. The original late-entry phase is not required for
this additional slot. This controlled result closes the field-capture path;
it does not recover the target's unused gap. No draft or selected C changed.

### Complete frame96 geometry review

Reviewing every retained target-sized output finds185/191 receipts accessing
the target's unused48..55 region. Six receipts, representing three distinct
bodies, retain only the original four homes and the target save area:
186/187 (700),547/616/685 (500),587 (845). Their source changes are not accepted:
186 moves the required node-byte store onto only one branch;547 captures a row
address before the original node-byte write and can change a later aliased index
read;587 moves a nested record-field address before an earlier byte write.
The latter two require alias separation not established by the existing model.
No valid unused-gap representation was found.

The derived save-slot classifier previously treated any store from a saved
register as a callee save, potentially hiding a body spill into the gap. Raw
SP-reference receipts were always retained and correct; the final inventory
classifies by actual offsets and save/restore placement instead.

Moving547's row capture after the byte store would preserve the original read
point. History checking found this exact meaningful model already recorded as
old current-source candidate107: successful replay27/frame88/1004bytes, linked
SHA25623e1b908695ba59fcc702c9b2ce8555b32be18020b3b6ecd7dfbc3b86c7d48b3.
The exposed lane also contains the same body as961. It was not recompiled as
new work. This closes the gap-preserving candidates from this lane; OPEN22
remains unchanged while a different function's macro visibility is investigated.
