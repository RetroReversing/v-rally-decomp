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

## November 6: saved-source reconciliation and caller declaration

A fresh hydrated audit found the actual saved518 draft still used the old
`D_8009FFDA - 2` expression and obsolete constructor/copy declarations. The
current corrected draft uses unsigned target-address subtraction and the actual
selected helper signatures. Ordinary and diagnostic builds agree at518 with
linked SHA256 `987595106b20b7aa1d4715573b633add774d0aac057311791555132302176df1`.
This is a target-specific mapped-address model with object, alignment, lifetime
and integer-pointer assumptions; it does not establish portable C provenance.
The direct-root object expression remains a separate818 alternative.

The sole direct caller, func_8000F660, declared this void(u8) entry as an
old-style s32-returning function. Both concrete calls pass literal zero and
ignore the result. A declaration-only correction to void(u8) independently
matches all2760 linked bytes under that caller's own profile, including the
ordinary/diagnostic parity check. Full-cartridge and normal-import evidence is
recorded separately before accepting the selected-source correction.

New controls using a real consumed scratch pointer (void pointer or union)
scored614; naming the actual game-object/item root symbols independently and
together scored518. These controls do not explain the saved-register mismatch.
The733 hydrated historical attempts supply no admissible lower-scoring seed.
No blind native, formatting or compiler-profile sweep was repeated.

Parent acceptance completed: the declaration correction passed the complete
12,582,912-byte cartridge comparison, SHA256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All2071 compiler profiles and other2070 selected C objects were preserved.
Normal saved-source verification independently rejudged the corrected caller
exact; all2071 matches remain. The corrected focal518 draft was retained through
the normal source-scoped quality/adoption path. Neither correction adds a match.

## November 6: explicit pointer-macro exposure

The current source remains OPEN518 (SHA256
81a0eaa8119b2e5cb40ee9800b18fd0a0df11023e5e187b11d1f3d427988b3d0).
Explicit gObj/gItem expansion exposes six global pointer accesses to the native
parser, but no hidden rectangle geometry. Full pinned-preprocessor TU AST and
binding structure agree, with physical lines preserved. Exactly two new exposed
ordinary/diagnostic builds both retain all1544 original bytes and SHA256
987595106b20b7aa1d4715573b633add774d0aac057311791555132302176df1.
No native run or printer compilation followed: no new supported allocation
transform emerged. The exposed seed is retained privately for a future specific
pointer-address hypothesis, rather than another broad replay.

The old unsafe native-independent-valid candidates444 and459 are already rejected
by the current initialization guard with either original or exposed macros.
That historical safety follow-up is resolved; it does not need another app fix.
All2071 selected rows/profiles and the protected input groups remain unchanged.
Private cause-nov6/REPORT.md retains comparisons and allocation-phase limits.


## November 6: typed slot-address search

A later native type-API audit established a concrete gap: the six opaque global
pointer identifiers raise KeyError in build_typemap/decayed_expr_type, whereas
per-use expansion exposes Obj*/Item* values and Obj**/Item** slot addresses.
The 737 hydrated attempts (616 distinct sources) contained no explicit Obj slot
dereference or Obj** local. Item-only exposure already occurs in earlier work.
Original, expanded and printed full translation units retain the same 46 AST
roots, including declaration binding, attributes and qualifiers. Expanded and
printed ordinary/diagnostic builds all reproduce score518 and the linked hash
above.

One fixed 1,000-raw-variant lane used six existing transformations, with internal
random type changes disabled and all sources/lineages saved before filtering.
Its reconciled outcomes are 736 initialization/inventory guard rejects, 203
conservative effect rejects, 38 retained compiler judgments, eight parser rejects
and 15 source duplicates. There were 45 actual compiler calls; seven early calls
were retrospectively excluded when effect review identified unproved movement.
Of the 38 retained results, 37 score518 and one scores11271. No improvement or
exact match was accepted. Thirty-five retained judgments reproduce baseline
bytes; the remaining two share another score518 object.

Thirty-five raw sources reached the newly typed double-pointer family, but all
were rejected (28 guard, seven effect). This therefore does not establish that
safe slot-address captures cannot help. Several captures hoist or reuse slot
addresses across statements, calls or control flow. The effect filter also
initially excludes inverse address/dereference spellings; a separate review of
those exclusions is pending, using only saved, previously unjudged sources.

The shared initialization guard from app PR715 catches loss of an existing
recognized integer local's initialization, but does not track every record
pointer. A constructed conditional Obj** initialization loss passes that guard
and is rejected by Clang. Neither the guard nor syntax checks prove semantic
safety. No live state or selected source/profile changed: all 2,077 matched
sources/profiles and the complete focal inputs were preserved. Private receipts
are in func80040CF4/typed-layout-nov6/REPORT.md and lane/reconciled-summary.json.


### Follow-up: address capture versus pointee capture

Review of the saved candidates distinguished caching a fixed symbolic address
from moving a memory read. Two sources (raw118/119) only cache
`(Obj **)(D_800C02AE + 0x32F2)`, optionally through a second pointer local.
Both original short-circuit Obj pointer loads remain at their original uses.
The BSS symbol and offset resolve to the same four-byte-aligned slot at
0x800C35A0; these sources retain the original mapped-address/storage assumptions.
After substituting the immutable address captures, all46 actual preprocessed TU
roots agree. Their ordinary/diagnostic builds both score638,1544bytes, SHA256
`8f730c2b558d941a7ecb6092ff87415739c515c6ad06b7d1de4f99268012dea9`.
Neither is an improvement. A separate existing control using six immediately
consumed per-use slot-address captures scores518 and reproduces baseline bytes
in both modes. No additional random generation occurred.

The private effect checker was corrected to distinguish actual lexical bindings
from record fields/prototype parameters. Baseline and the six-capture control
pass; seventeen unary-identity controls cover qualifiers, retained single
side effects, evaluation paths and negative bitfield/register/cast cases.
Rechecking196 previously unjudged effect rejects and28 typed guard rejects
finds none admissible under its strict immediate-use rule. That rule deliberately
does not prove immutable-address motion; the two638 controls above required
separate manual review rather than treating the filter as a semantic proof.
The shared app guard is unchanged. Private address118119-proof.json and
typed-fixture-proof.json retain source, type, binding and compiler receipts.


## November 7: local hard conflicts and isolated branch-binding control

Fresh packed read-only capture confirms current518 source81a0eaa8,737 hydrated
attempts and all2077 selected full sources/effective profiles unchanged. Exact
installed global-priority calculations reproduce all17 allocation priorities:
item is already highest22560, height2758, rectangle2689. However local allocation
has already placed vertical x2/horizontal y2 in s2 and both widths in s3. Their
hard conflicts block the target rectangle/item mapping; merely raising a global
priority cannot allocate a conflicting hard register.

The proposed second horizontal y2 store was rejected without compilation:
current RTL already uses HI269 for both stores, across all four calls, despite
the second source spelling y. Thus no lifetime extension would occur. Shared
item was previously523; destructive full-to-half width reuse does not correspond
to the target's actual sharing. These were not repeated as fresh tests.

One isolated control unifies only the two branch-local coordinate bindings and
the two width bindings into outer s16 scratches. Older combined controls also
changed height, item, stores and geometry, so did not isolate this mechanism.
All definitions remain at their original evaluation positions and retain the
same narrowing; branches are exclusive and every use is dominated by its branch
definition. Necessary C89 declaration movement adds no initialized operation.
No other fields, calls, loads or store order change.

Source70350f0975093b2f56380a0ba92a55269262b54d1df67b10d2067b34c2a3d5aa
scores4563 in ordinary/-da,1544bytes, linked SHA256
12ff8257fab0e1438384f9b552fcd1a07331418f796b601f87e7127b2831cf3d.
The causal prediction is confirmed: both new bindings become global and remove
the hard s2/s3 conflicts. That is insufficient: highest-priority item takes s2,
height s3, rectangle s4, coordinate s7, and width spills. Preserve518 rather than
adopting a structurally motivated but worse result.

Both saved objects independently relink identically. Two compiler calls total,
20-second/2GiB aggregate owned-tree bounds, terminal0/no survivors. All2077 full
selected sources/profiles,737 history records and focal inputs remain unchanged.
Private current518-causal-nov7 retains prior-coverage audits, exact binding/effects
review, commands, phase dumps and preservation. No live writes, new match or
cartridge acceptance claimed.


## November 7: split item phases and recover local layout roles

Fresh capture retains737 hydrated attempts and all2,078 selected sources and
effective profiles. One genuine CFG item-result phase split leaves only the
case2 final result in the outer binding, with separate case1/vertical/horizontal
and final-tail bindings. Calls, arguments, stores and common-join definitions
are unchanged. Source0155e117e2b7ff6960508aa3540129d5f00ccc02a9ffde9fcdb88d9fed2ce897
scores533/1544bytes; paired linked SHA-256
5c8ce3295d4ce630b49030871490b9c0b033937591a79ad3bf05217abdfb92e8.
It changes17 to21 global allocnos but does not remove the coordinate/width local
conflicts. Keep518. Evidence: `fresh-reconcile-nov7`.

A second source-reviewed composition uses branch-local rectangle pointers,
removes the unobserved overwrite in `p->y=(hh=(y+hh)+1)`, and captures the
horizontal signed-halfword height at its first store for reuse by the second.
The original vertical h/h2 calculation is preserved: existing RTL already
makes h2 local and kills the initial full height at division, so a proposed
non-destructive height rewrite was rejected without compilation.

The composition sourcef5af7681242e19297f34a15c8314c0d769ed7a39d7cb799cd90f88ee1f968af6
produces565/1548bytes, ordinary/diagnostic linked SHA-256
4a0adeef523ea3474f2e6477d1eb824920d1a0c621ce808a9db5f50e572d9371.
It is a worse aggregate score but a useful causal frontier: register differences
fall from roughly102 to17, with one extra instruction. The horizontal branch
now has the target roles: table s0, half-width s1, rectangle s2, height s3,
y coordinate s4 and width s5. Vertical half-height becomes local s0, table s1,
rectangle s2 and width s5, while x2/h2 occupy s3/s4 in the opposite target order.
The common item result now occupies target s6. The initial object pointer,
initial height and first constructor result still differ.

The initial per-pseudo summaries showed equal x2/h2 reference counts and
lifetimes. The merged-quantity observation below independently confirms this
particular tie; those summaries alone did not establish it. Removing the dead hh overwrite also
changes the second-y expression to anonymous temporaries. First scheduling moves
the x2 store before the two y additions, unlike the target. This is a measured
remaining scheduling/lifetime cause, not proof that arbitrary declaration order
will repair it. The sole extra move captures the horizontal height from the
initial height's still-wrong register.

Four compiler calls total across these two controls, each bounded20s/2GiB with
no owned survivors; saved objects independently reload/relink identically.
All frozen focal inputs/history and all2,078 selected source/profile records
remain byte-identical. No live adoption or cartridge claim. Evidence:
`local-layout-nov7/REPORT.md`.


A named second-y temporary alone was tested as a separate control.
Sourcec3a557a28b9accf1b7964d72218ddd4fe6a4952391cd4055d0ee9d19a70b6669
produces exactly the same565/1548-byte linked body as f5af above, ordinary and
diagnostic with independent relinks. Its REG_USERVAR marker survives CSE and
local allocation, but scheduling and the vertical quantity tie are unchanged.
Naming is therefore not the cause; do not repeat a name-only temporary control.
All focal inputs/history and2,078 selected source/profile records are preserved.
Evidence: `second-y-nov7/REPORT.md`.


The f5af source is committed separately as
`func_80040CF4-local-layout-frontier.c`, unmatched research material excluded
from the build manifest. Preserve it alongside the live score518 draft.

A further finite control splits the actual second-y arithmetic into
`hh=y+hh; hh+=1; p->y=hh`, at the same original evaluation point.
Source861f73cee924322af448d8e17beac353b372fa2ff8d3ca6692bd8e96fccec3c6
produces6655/1428bytes, linked SHA-256
b9728ac2145600ba76eb7ccaacfaef9d1a5810ed5241dd4a364cfd362d1e62b7.
Ordinary/diagnostic and independent relinks agree. First CSE retains self-SETs,
flow records only one final death for hh, and it becomes locally allocatable.
This confirms the specific `flow.c` dead-or-set rule and `local-alloc.c`472
one-death eligibility rule. It does not establish a successful repair.

Vertical rectangle/height/coordinate/width roles now match, but half-height
and table swap s1/s0, other global roles regress, and late cross-jumping shares
more calls than the target. CSE, flow, combine, first scheduling and local
allocation retain equal instruction counts between the two controls. Reload
first removes nine additional instructions; late jump optimization reduces
24 statically present calls to22 by tail sharing. This is not evidence of
missing source calls or changed intended behavior. The frame becomes0x60,
wrong for the target0x68. All2,078 selected source/profile records and the737
focal history remain unchanged; watchdogs are clean. Evidence:
`self-update-nov7/REPORT.md` and `phase-counts.json`.

Printed per-pseudo reference/lifetime values must not be substituted for local
quantity priorities: local allocation can merge several pseudos and sum their
references while extending the interval. The observed order is authoritative;
exact merged quantities require additional evidence. No priority claim based
only on the individual register summaries is used to select a further rewrite.


## Direct observation of merged local quantities (November 7)

A private, read-only observer now records the pinned KMC compiler's actual
local-allocation quantity arrays immediately before and after its existing sort.
It leaves comparator results and compiler data unchanged. Its executable-path,
architecture, comparator-address, array-shape and pinned compiler-hash gates are
specific to the investigated toolchain. It is not an installed app feature.
A nongame sorting fixture validates forwarding and path rejection. Injected dyld
images can precede the executable, so image zero was an invalid assumption;
locating the unique MH_EXECUTE image fixed the diagnostic without relaxing gates.

One diagnostic replay of each unchanged candidate reproduces its cached ordinary
and diagnostic linked bytes, including independent saved-object relinks. Both
runs preserve all 2,078 selected sources/profiles and 737 focal history records.
No candidate was adopted. Each ran under the 20-second/2-GiB aggregate watchdog,
with no owned survivors.

The compiler's density is truncated from
`floor_log2(refs) * refs * size / (death - birth) * 10000`.
These are actual merged quantities, not individual pseudo-register summaries:

| Vertical value | f5af refs / interval / density | 861f refs / interval / density |
| --- | --- | --- |
| Half-height | 11 / 6..92 / 3837 | 11 / 6..92 / 3837 |
| Table address | 13 / 26..128 / 3823 | 13 / 30..128 / 3979 |
| x2 | 3 / 2..86 / 357 | 3 / 2..90 / 340 |
| h2 | 3 / 12..96 / 357 | 3 / 12..96 / 357 |

Thus the table/half-height reversal is caused by the table quantity's later
birth, not a higher reference count. Half-height's merged chain loses the two
anonymous add-result pseudos in 861f, but its total references and interval stay
identical. The x2/h2 reversal comes from x2's later death: f5af genuinely ties
and quantity number breaks that tie; 861f gives h2 higher density. Both pairs
have no hard-register suggestions. Rectangle pointers have suggestions, so
raw density alone does not explain the complete allocation order.

Evidence: private `quantity-executable-f5af-nov7/quantities.log` and
`quantity-executable-selfupdate-nov7/vertical-quantities.json`, with watchdog,
source/profile preservation and independent relink receipts alongside them.
Keep live score 518 and the unmatched f5af research frontier. The next source
control must explain these real intervals rather than adding artificial uses.


A proposed move of the two real hh self-updates before the second x store was
withdrawn without compiling. The existing 861f first-scheduling dump already
hoists update instructions 457/460 before the first vertical constructor 372,
after initial table loads 345/359. The second copy 446, item-id store 451,
x store 454 and y store 463 occur later. Moving the source statements would
not establish a new dependency. This early hoist also ends the original y
value's lifetime early and helps explain the global allocation/frame regression;
it is not merely an ordering difference next to the second rectangle stores.
No legitimate dependency that retains one-death eligibility while preventing
that early hoist has been established. Do not add fake barriers, aliasing or
unused reads to manufacture one. No additional compiler call was made.


## November 7: fixed search preparation from the new layout frontier

The f5af causal frontier had no exact-source native coverage:4,724 bounded
private source files contained only its five direct/observer baseline copies,
and737 hydrated live attempts contained no exact root. Older native lanes used
different sources. This justifies a single independent fixed batch, not another
quota from the old roots or a score-selected portfolio.

The two object macros were expanded token-for-token. Whole-translation-unit
preprocessing yields the same1,785 tokens; native printing preserves the full
AST. The printed seed SHA-256 is
`25860eb76a7eeaeefd85ce694bc80e2fdae9af9e34869d84dc7740083a3198fa`.
Strict C89 preflight includes declaration-after-statement errors. Ordinary/-da
builds and independent saved-object relinks retain565/1548bytes and the exact
f5af linked hash4a0adeef523ea3474f2e6477d1eb824920d1a0c621ce808a9db5f50e572d9371.
Thus the printer does not silently replace this search root's machine behavior.

Generation completed one fixed job, seed0x40cf4565, with1,000 distinct raw
protocol emissions and one done record. Every source, cumulative transformation
lineage and protocol line was retained before delivery guards or judging.
Only temporary expression capture, statement/declaration order, assignment
splitting, commutation and block insertion were enabled; external type mutation
was disabled. Native internal retries/deduplication remain bounded by4,000 loop
iterations:1,000 emitted sources is not a claim of1,000 internal proposals.
There is no score feedback, replacement quota or source portfolio.

The generation protocol SHA-256 is
`c4866e7da7a81dec4f318f3e284f6449d206d348eae0f91a30c387a0da52171f`.
At generation completion zero candidates had been judged. Generation took24.02s,
peak aggregate sampled RSS127,984KiB; inner/outer watchdogs completed normally
with no survivors. All2,078 selected sources/profiles and737 focal attempts/full
inputs remain unchanged. Source files and compiler/native/app implementation
pins are private under `frontier-native-nov7/`; judging requires its separate
reviewed phase and no matching result is claimed here.


### Fixed batch completed

All1,000 raw emissions were judged without feedback or a replacement quota:
407 delivery-guard rejects,88 strict-Clang preflight rejects, and505 compiled
and linked outputs. Those505 represent252 distinct linked bodies and253 duplicate
linked bodies. No output matched or beat the live score518. Each successful
GCC-command launch produced a retained linked output; this is not an inference
from wrapper invocation counts alone.

The judging watchdog finished normally in687.82seconds, peak sampled aggregate
RSS458,464KiB, with no remembered orphan RSS, cleanup errors or surviving owned
processes. Raw sources, complete lineages, objects, linked bytes and individual
preflight/compiler receipts remain private. This closes the fixed quota; it
does not establish exhaustion of possible C rewrites.

One numerically promising555 variant moved a rectangle-width store past calls
that consume the rectangle. It is semantically rejected. A reviewed550 variant
only swaps disjoint local rectangle width/height stores before the first
constructor; it remains worse than518. The genuine horizontal arithmetic
capture at560 likewise remains a private structural observation, not a new match.

The batch exposed an app guard defect: field spelling such as p->x made the
verdict for local x unknown. Shared initialization checks now hide member names
from binding-specific write checks while retaining base/index/RHS reads and
opaque macros. PR754 merged as1cf13e62;173 related tests passed, followed by117
initialization tests including the final macro regression, and whole-tree Ruff.
Read-only replay rejects the previously missed local-x initialization loss in
candidate43. Candidate6's separate temporary remains unknown: this is bounded
initialization analysis, not a complete equivalence proof. The pinned judging
runner was not changed mid-batch, and the running app was not updated.

Root independently compared the before/after-judge selected and focal snapshot
files byte-for-byte: all2,078 complete selected sources/effective profiles and
all737 hydrated focal attempts/full inputs are preserved. No live draft,
selected source or compiler profile was adopted. Function remains OPEN518.


### Two finite vertical-order controls

The completed batch contains990 parseable raw sources (ten malformed sources
were already guard-rejected); none declared or defined vertical h2 before x2.
A broader7,569-record/6,996-source audit finds no exact A/B control. One older
native source has an earlier declaration but a different prefix/root. This was
a bounded coverage gap, not a claim of exhaustive semantic novelty.

Two source-reviewed controls then ran under the unchanged KMC profile/context:

| Control | Score | Bytes | Observation |
| --- | ---: | ---: | --- |
| h2 declaration before x2, actual calculations unchanged |565|1548|Exact f5af baseline bytes |
| Existing independent hh/h/h2 calculations before x2/w2 |3821|1448|Worse, not adopted |

A source SHA25636f4a9b7a98d01ccff0d9023b2dc37397c0032418d118463e74bdff75c14316f
links to4a0adeef523ea3474f2e6477d1eb824920d1a0c621ce808a9db5f50e572d9371.
B source SHA2566d6e56ffdc216e9d189735c779c232e744e2a616e48963c588228878eb76af5d
links to3f6b46fe989290691b034f9ce53190c5401981881d7bf14712d77ef790cc44f0.
Both preserve scalar calculations, types, memory accesses, calls and ABI; B only
reorders independent unaddressed local arithmetic before the same stores.

The causal limit matters: local quantities are created at scheduled first birth,
not C declaration order. A changes pseudo identities but keeps physical roles
(h2=s4,x2=s3). B truly constructs h2 before x2, yet assigns h2=s5,x2=s3. Its
per-pseudo lifetimes become45/39 rather than43/43; those are not newly observed
merged-quantity densities. Earlier definition can lengthen a live interval and
lose priority instead of merely exchanging a tie. Both forms have25 calls
through second scheduling; late jump sharing reduces A to24 and B to22, helping
explain the shorter B body. No observer or further ordering grid was run.

Exactly two strict-C89 preflights and four ordinary/diagnostic game calls ran.
All four saved objects were independently reloaded/relinked with paired raw-byte
agreement. The outer phase completed in7.458seconds, sampled peak aggregate
RSS622,728KiB; every20-second/2GiB child and180-second outer watcher completed
normally with no resource failure, error or surviving owned process. Pins passed
start/end checks. Root independently compared full before/after snapshots:
all2,078 selected sources/profiles and737 focal attempts remain byte-identical.
No live update or match. Private quantity-order-controls-nov7 retains complete
diffs, coverage limits, phase evidence, object receipts and preservation checks.
