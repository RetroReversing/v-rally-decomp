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


### Fixed 10,000-candidate search, 6–7 November 2026

A separate fixed batch started from the proven macro-exposed current source,
with seed `20261106729001`, 16 jobs (15 × 640 plus 400), and no feedback from
scores into generation. It used temporary-expression capture, statement and
declaration ordering, assignment splitting, commutation and block insertion;
internal type randomization was disabled. All 10,000 sources and complete
transformation lineages were saved before filtering. Neither an interrupted
preflight nor a partial compiler result was counted as a completed negative.

The batch is now fully judged, rather than merely generated:

| Outcome | Count |
| --- | ---: |
| Scored linked outputs | 5,932 |
| Unscored compiler/link outcomes | 9 |
| Guard rejections | 3,173 |
| Clang preflight rejections | 373 |
| Exact source duplicates | 513 |
| **Total saved candidates** | **10,000** |

The nine unscored outcomes are retained `.rodata` relocation/link failures,
not score-zero matches. Scored outputs represent 2,314 distinct linked bodies.
None beat score 22 or matched exactly. Every scored object/binary hash and every
raw source/job/lineage was independently checked. Four complete results at the
last time limit were validated, relinked and rescored from retained objects,
then recovered without recompilation.

Judging used four sequential execution phases. The later phases allowed four
independent compiler subprocesses for this one function, with at most four
admitted but uncommitted candidates and ordered durable results. Per-call
limits were 20 seconds/2 GiB; each outer judging phase had an 1,800-second/2 GiB
aggregate limit. The final phase finished normally in 1,396.63 seconds, with
peak aggregate RSS 1,226,628 KiB and no cleanup errors or surviving owned
processes. Phase 2 was deliberately cancelled; its final outer receipt was
not written after a cleanup exception. Its aggregate peak remains **unknown**.
That interruption was reconciled through independent source/result, PID/start
and snapshot audits; later measurements do not replace the missing measurement.

A target-sized frame alone was again misleading. Many 96-byte outputs spill
into the target's unused gap or move memory reads across potentially aliased
writes. Other candidates read a captured pointer on a path that bypasses its
initialization. These were not promoted. The embedded pointer-initialization
case led to app PR #730, merged as `c95ae389`; it checks that specific class of
initialization paths, not general C equivalence or alias separation.

Two additional source-reviewed controls were then compiled with ordinary/`-da`
parity, exactly four game compiler calls total:

| Control | Score | Result |
| --- | ---: | --- |
| Join the entire function body onto one physical line | 22 | Same 88-byte frame and exact baseline linked bytes |
| Correct candidate 6007's integer-temporary/null-pointer comparison | 445 | Worse; ordinary and diagnostic bytes agree |

The first control preserves preprocessing tokens and the complete actual
compiler-preprocessed AST, including the header. It therefore closes this
specific whole-body line-layout hypothesis for this root/profile; it does not
establish that line layout never affects this compiler. Its linked SHA-256 is
`2bac576f07fa5f85ac2a35fe22658dc2c859d96c47c41f917d5ced4aec2784b7`.
The corrected control changes only `prev == new_var` back to `prev == 0`,
retaining the initialized, unaddressed integer-zero temporary in integer
comparison and byte-offset uses. Its linked SHA-256 is
`64f59b07f03ad89aef91ca2aa138491c9faa4c6d782d4e0797e56ee3c8b8bcc4`.
Its actual full preprocessing AST also passes the reviewed-source check.

This exposes a useful limitation of expression capture: replacing identical
literal-zero ASTs in every context can lose the null pointer constant property.
Likewise, a clean preflight log does not prove equivalence: pointer/integer
comparison has a separate diagnostic from assignment conversion. These controls
were checked against all 782 hydrated historical attempts, the initial exact
source cache and the fixed batch before compiling.

All before/after snapshots retain the same 2,077 selected matched records and
782 focal history entries. No selected source, profile, header or live app
record was changed; no new cartridge-progress claim is made. `func_8007A29C`
remains **OPEN at score 22**. Private evidence stays outside the repository;
ROM bytes, extracted assembly, compiler outputs and local databases are not
published here.


## November 7: coordinate provenance constrains unit rewrites

Fresh read-only audit preserves OPEN22 source0992fd5f, 782 hydrated attempts
and all 2,077 selected sources/profiles. No compiler or generator ran.

The consumed eight-byte initializer-record hypothesis already scored3886 with
a96-byte frame, but moved all four spill homes rather than leaving the target
gap unused. Table word-unit literal and variable-component controls also exist
and leave the baseline bytes unchanged. These are not new eligible tests.

A proposed alternative interpretation of local off was checked against actual
consumers. Selected func_800683CC obtains the same node through
func_800592AC(0), reads node+8 as s16 and passes it through func_800596F4 as a
coordinate to func_8000CC04. The increment20 therefore does not establish that
the value is a record byte offset or divisible by20. No initialization invariant
was proven that permits replacing it by a record index. Manufacturing quotient
and remainder carriers solely to create stack space would not recover such a
source model. Preserve the current draft and remaining eight-byte frame gap.
Private current22-phase-nov7/REPORT.md retains the evidence and preservation audit.

## November 7: fresh frame-gap coverage check

The current0992fd5f draft remains OPEN22 after a fresh strict read-only audit
of782 hydrated attempts and all2,078 selected source/profile records. Real
aggregate and field captures have already produced measured spills with the
wrong geometry; unit rewrites leave no late USE, and callback effects prevent
assuming freely hoistable global reads. Coordinate provenance still supplies
no record-index invariant. The historical unused pad artifact was not treated
as the current source or as a legitimate missing object. Widening the bounded
outer loop counter alone provides no demonstrated frame-gap mechanism, so no
random type probe was run. Before/after frozen evidence agrees byte-for-byte.
No compiler, preflight, generator or live mutation ran. Preserve OPEN22; the
private revisit-nov7/REPORT.md records this bounded coverage decision.

## November 7: constant-table coverage and late-slot provenance

A fresh full read-only audit preserves OPEN22,782 hydrated attempts and all2,078
selected rows/profiles. Actual eight-byte count/offset table recipes already
exist, including const/nonconst paired arrays and count/offset structures.
Their historical root differs from current0992 in pointer declaration order
and one blank line; unresolved .rodata references prevent treating their scores
as clean linked negatives. The exact current-root explicit eight-field scalar
initializer is separately negative at3886/frame96: its real byte storage shifts
all four pointer homes, rather than leaving the target's unused48..55 gap above
unchanged homes20/28/36/44. Exact current-root array recipes remain unmeasured;
no newly observed late elimination mechanism justified repeating the family.

Pinned KMC-compatible compiler source places second CSE after loop optimization
and before flow/allocation/reload. It cannot remove a slot first created by
reload. Reload-local elimination and later jump optimization could theoretically
leave frame high water, but current retained dumps show no fifth home, wide/FP
transfer, caller-save scratch or standalone USE. The genuine r/arr addresses are
four bytes apart and both consumed; their relationship alone supplies no late
elimination proof. Existing191 target-sized frame outputs were reviewed rather
than rerun:185 use the alleged gap, and the six gap-free controls already have
rejected effect/alias changes. No valid new candidate or compiler call followed.

Source provenance: decompals/mips-gcc-2.7.2 commit e6271f14, toplev.c SHA256
3d14cc1f9cdc145e21c9acb86e2027d9d6475d1fc9d956a6297378a9221479b2.
This is compiler-source evidence, not instrumentation of the original vendor
binary. Private table-lifetime-nov7/REPORT.md binds source, receipts, exact
coverage limits and preservation. The audit also found that app phase capture
included CSE2 while its comparison omitted it; that diagnostic fix is separate
from the unresolved game function. No live mutation or new match is claimed.


## November 7: consumed-address reconstruction controls

On the exact current score-22 source, two isolated, defined same-object pointer
representations were tested: `r = arr - 4` in place of `r = cnt + i`, and
`q = cnt + 4` in place of `q = base + 0x241`. Existing captured pointers share
one allocation, with cnt at base+0x23d, q at base+0x241 and i in0..3. Neither
change adds storage, accesses, calls or a global-read caching assumption.
A bounded retained-source/history check found no exact current-source duplicate.

The first scored222; the second reproduced22. Both remained1004 bytes with an
88-byte frame. The first introduced an actual subtract-four instruction rather
than the target's move; neither created a fifth stack home. The four existing
homes stayed20/28/36/44. Ordinary/diagnostic pairs and independent persisted
object relinks agreed across four compiler calls and four relinks. Complete
focal/history and all2,079 selected rows/profiles remained unchanged before,
after and at the final check. Pinned compiler binaries preceded the tests;
outer7.19s/293,520KiB completed without owned survivors. No live adoption.

The table-linking audit separately confirmed normal judge behavior: unnamed
candidate-local data requires a corresponding target relocation or known named
symbol. Historical table candidates retain extra blockcopy loads with no target
address reference. Inventing a ROM placement would not make those instructions
match. Their unresolved references are not evidence of an importer bug or a
clean linked negative. Current array composition remains unmeasured; no valid
late allocation mechanism was established. Private table-lifetime-nov7/address-phase
retains exact sources, receipts and preservation snapshots.
