# func_80049DB0 private revisit

Scope: function 946 only. Fresh readonly snapshot showed open, score 20, no claim. App worktree is detached origin/main 4bd73b7c02c7cfdc76ab2ddda29db1ebce963686. No live/canonical writes, claims, or restarts.

## Audit before searching

Prior scratch evidence records at least 2000 long-walk attempts, 300 typed-walk attempts, 190 generator candidates and many directed controls. Those used an inadmissible baseline: scalar globals addressed thousands of bytes beyond their object bounds and four deliberate XOR cancellation assignments. The frozen current best_source contains those same constructs. Its score 20 does not establish source validity.

The actual BSS symbols have captured extents 72286 and 66514 bytes. clean.c uses those array extents, removes all cancellation assignments, and otherwise preserves the observed control and memory accesses. N64 pointer-to-s32 and s32-to-pointer conversions are deliberate implementation-defined 32-bit machine address conversions; no signed arithmetic is used on them. Fields are accessed at observed aligned addresses. There are no callees or prototypes to reconcile in this leaf function.

The target chooses the first node's value outside mode 2. In mode 2 it follows one next link, optionally a second next link when choice==1, compares the first value with 15000, returns 1 when unequal, otherwise compares the selected value. Loads and pointer traversals are retained even when the first value is unequal, as in the target.

Directed controls: frozen baseline20; cleaned array-storage baseline60 (12 register operands); typed field source375. Removing the independent result temporary from clean source gives40 (8 register operands). These are linked-byte judgments using the frozen target, profile and symbols with the pinned compiler. Typed source reproduces the semantic reads but changes scheduling, and is not selected as the search baseline.

## One native lane

Exactly one independent lane starts every batch from clean.c, seed499176, <=1000 actual generated candidates. It does not use a search portfolio or promote a frontier. Each candidate has a unique Clang preflight path. Native guards reject asm, register and volatile tokens and explicit identity lineage. Post-generation source audit is still required: native mutators can produce hidden cancellation operations and signed increments/decrements; these cannot be accepted on a low score. Generated p++/p-- and value=value score20 examples have already been identified and excluded from admissible results.

Frozen manifest includes source, header, target bytes/assembly, profile, complete symbols, ROM hash and input snapshot. Frozen files are mode0444. No ROM, extracted assembly, DB or assets are to be published. Exact acceptance would require parent independent linked bytes plus complete 12582912-byte cartridge comparison preserving prior accepted objects/profiles; no such claim has been made.

Final lane counts and admissible result will be recorded in evidence.json when complete.

Final: 975 actual generated attempts across16 batches;95 duplicates,103 token/lineage rejects,107 Clang failures,670 compiled and scored. No exact. Only sub40 candidate was rejected attempt113. Best corrected raw-memory draft40 is admissible40.c; raw-memory pointer views and implementation-defined N64 pointer/integer roundtrips are explicit representation caveats. These guards and review do not constitute whole-project ISO strict-alias proof. No second lane run. No full cartridge gate run because no exact candidate.


## Parent recovery after terminal search

The parent created its own project-scoped manual MCP connection, claimed only this unclaimed function, compiled the corrected40 source with the ordinary judge, and attached it to a structured candidate-quality report on the historical20 source. The connection was revoked, freeing only its own claims. The ordinary GUI corrective-alternative adoption rejudged and selected40. Readonly confirmation: OPEN40, unclaimed, source SHA256 `ea647ba17af5ef82350d47c9b2e13d28a3e2325a058a8ba8781612f88abe9216`. This is an explicit review of an exploratory machine-memory draft, not an exact match or complete ISO alias/prototype proof. No selected cartridge C or compiler/header/target changed. Historical warning is retained and blocks silently reselecting the old reported shape. All current progress is being saved normally.


## Inline return-lifetime and compiler-release controls

The current valid40 draft was freshly frozen unchanged. Sixty-three new source
controls compiled and linked, with six unsupported attribute-syntax failures
excluded. Whole/partial genuine inline evaluation regions, sentinel phases,
actual pointer-carrier reuse and wide-value forms found no exact or sub40
result. A byte-neutral full inline helper does create a return-preferred pseudo
in v0, but the real p value remains in a0. Return preference alone therefore
does not recover the missing coalescing or local temporary allocation. Four
representative ordinary/diagnostic compilations have identical raw linked bytes.

A separate ten-build compiler-release check on valid40/60 sources made20
attempts. Four candidates could be judged: KMC40/60 and PM GCC2.8.1 180/605.
Four outputs had the wrong byte order and12 builds failed; neither group is
negative matching evidence. SN-AS with a legitimate g0 profile compiles both
sources at180/605. Sixteen compiled PM inline-region controls have a minimum
145 and124 bytes versus the120-byte target, not an improvement over valid40.

Source, header, target, symbols and selected profile remain unchanged. No
profile or source was adopted and no new automatic rule is demonstrated. The
function remains OPEN40 and revisitable. Normal app notes and a full portable
progress snapshot retain the results; historical cancellation/OOB20 remains
rejected. No full-cartridge claim is made for an unmatched candidate.


## November 6: current contract audit

A fresh read-only audit confirms the six protected input groups unchanged:
source, header, target, assembly, compiler profile and symbols. Ordinary linking
reproduces40 over120 bytes with eight register differences. The sole direct
matched caller49E28 invokes the actual no-argument entry and consumes its byte-cast
boolean result; it provides no legitimate extra parameter or lifetime bridge.
No new candidate or repeated native/inline/flag sweep was run. Previous controls
remain bounded negative evidence, not proof that all C is exhausted. Keep this
function open; a further experiment needs a new grounded source/allocation cause.
Private evidence: nov6-contract-audit/REPORT.md and evidence.json, source
`ea647ba17af5ef82350d47c9b2e13d28a3e2325a058a8ba8781612f88abe9216`.

## November 6: explicit current40 native provenance

The earlier score60 lane described above is not the only completed native run.
A separate native40-nov6 lane already uses exact current ea647ba1 source in all
16 persisted batch jobs. Independent receipt audit recounts1000 raw emissions
(15 batches of64 and one40), each with result/lineage; scored source hashes agree.
Counts:88 duplicates,239 forbidden-lineage,153 forbidden-text,68 preflight
failures,452 compiled/linked. Minimum40, including253 score40 candidates;
no exact. These filters are not a complete semantic proof. Batches do not
promote an earlier candidate into the next seed; in-batch chained mutation
lineages remain recorded. The lane is terminal and was not restarted.

Fresh ordinary/-da120 linked bytes agree at40, SHA256
fd57a65fbf7ca4e513da7ed31de59cd9ff6f170cbbdf7a6c8d21f810604125e1.
The macro-expanded seed is byte-identical to current source and reproduces
those bytes. Three successful compiler calls audit provenance, not a new search.
All six protected input groups are unchanged and the function remains unclaimed.
Private seed-audit-nov6/REPORT.md and result.json resolve the documentation
ambiguity; neither old60 nor current40 native quota needs repeating without a
new source/compiler mechanism.


### Allocation-priority audit

Saved actual KMC dumps rule out initial pseudo identity alone as the global
priority rule: current order is77,72,75, while the separate-result control
orders79,72,77,75. The return-preferred79 gets v0, but root then precedes p
and their required allocation reverses. Local chain/sentinel temporaries are
already assigned v0 before global allocation; return preference does not fix
that separate obstacle. Use/lifetime and preference-sensitive priority are
supported, but the exact comparator/tie-break formula was not independently
established. Existing grounded source families cover these mechanisms; no
new admissible candidate or compiler call followed. All2077 selected hashes/
profiles and focal inputs remained unchanged. Private phase-priority-audit-nov6
retains the source-bound dump references and preservation hashes.


### 7 November: exact installed allocator rule

Read-only inspection of the actual registered macOS x86_64 KMC-compatible
`cc1`, SHA-256
`3160c6f0fb4697cdc6bd3412333a5a8e64b23e9e4dd6d01951422a63bee2c60a`,
resolves the earlier comparator uncertainty. Its priority is
`trunc(((double)(floor_log2(refs) * refs) / live_length) * 10000.0 * size)`.
Higher values sort first; ties use allocation number, not necessarily the raw
pseudo number. References are summed per allocation unit, live length is their
maximum, and size is mode size rounded to target register words.

Current p77/root72/game75 priorities are16666/15882/4285. The separate-result
control gives result79/root72/p77/game75 priorities20000/15882/7142/4285.
These reproduce both retained compiler dump orders without executing a compiler.
The installed comparator does not read preferences; sorting precedes preference
pruning. The earlier phrase “preference-sensitive priority” is therefore corrected:
reference/lifetime/size inputs determine sorting, while hard-register preferences
can affect later assignment. Local v0 assignments remain a separate obstacle.

No admissible new source control emerged and none was invented to manipulate
reference counts. Strict read-only before/after snapshots preserve all2,077
selected sources/profiles,907 hydrated attempts and the complete OPEN40 inputs.
No compiler, Clang or generator calls, live writes or new match occurred.
The compiler guide and learning log now document this verified rule and its
build-specific limits in merged decompdecomp PR
[#743](https://github.com/RetroReversing/decompdecomp/pull/743).
Private exact-binary and preservation evidence stays in `allocator-cause-nov7`.


### November 7: isolated pointer-load reference weighting improves to35

The previous separate-result control scores60. One new control wraps only its
existing branch p=*(s32*)p statement in two nested one-shot do/while(0) scopes.
No expression, memory access or runtime operation is added. Previous scope
controls also enclosed the subsequent root chain and did not isolate this load.

Actual p references rise5→9 with lifetime14, priority19285; root remains9refs
with lifetime18. Global order becomes result79,p77,root72,game75, recovering
target resultv0/pa0/roota1/gamea2. This confirms the measured reference-weight
mechanism, not a general guarantee that scopes improve allocation.

Ordinary/-da and independent relinks agree on120 bytes at score35, SHA256
106b50062ea6ca0352e90b7e08dbe588e5d68a45d84a7fabc98538825dd5dc70.
Five raw positions remain different: two loads are reordered at+0x40/+0x44,
and chain/sentinel/compare use localv0 instead ofv1 at+0x48/+0x4C/+0x50.
The candidate is valid reviewed private progress, not an exact match. Its source
SHA256 is5299eb5c188e409e7ffe82abb1e9092f16b750d1e20623c545a711bd32346b0b.

Exactly two compiler calls completed under20-second/2GiB aggregate limits.
All907 hydrated attempts, complete focal inputs and2,077 selected sources/profiles
remain identical. Live score40 is unchanged; normal app import is pending.
No cartridge gate or new matched-count claim is warranted. Private
current40-contract-phase-nov7 retains complete source delta, linked outputs,
RTL, independent relinks and preservation receipts.


### November 7: staged chain reaches a valid20

Three source-reviewed followups preserve actual memory effects and ABI.

| Control from reviewed35 | Score | Observation |
| --- | ---: | --- |
| Move the whole chain before the weighted p load | 35 | Trades which two loads are reordered |
| Name the real intermediate link; load p between the two chain reads | 20 | Target instruction order and global roles recovered |
| Initialize the existing returned default after mode choice, with a common return | 300 | Local v0 remains; return value moves to v1 and adds a terminal copy |

The valid20 source is6c1afd73395fb0dc9e112992912acf1c52ff7cd9ab76647e2483a48c33eb9309.
Ordinary/diagnostic and independent relinks agree on120 bytes, SHA256
e5a6b361d7a334e1b208ae84997183b483d4db8b9e8fabccad0486815719d97d.
This is not the historical invalid XOR/out-of-bounds20 source. The explicit
link is consumed once; no extra read, storage padding or alias assumption is
introduced. Four register operands differ at+0x40/+0x48/+0x4C/+0x50.

The late-default control demonstrates the remaining allocation obstacle:
local link and sentinel retain v0; returned value79 has8 references/lifetime11
but a hard-v0 conflict, so higher global rank still allocates it to v1. The
real default assignment sinks into the branch delay slot, but that scheduling
change does not undo earlier local allocation. Its paired output is124 bytes,
SHA2569f38ab22c5cf365a0a4d4754aa280073e416e025bf4048e5255073d84a50a5ee.

Exactly six followup calls completed under independent20-second/2GiB aggregate
limits. Independent relinks and fresh read-only snapshots preserve907 hydrated
attempts, complete focal state and all2,077 selected sources/profiles. Retain
valid20 as reviewed private progress pending normal app verification; live40
and matched count remain unchanged. No cartridge acceptance is claimed. Private
load-order/staged-link/late-default reports retain complete source-bound receipts.

## 7 November: returned statement expression does not reserve v0

After normal live retention of the valid staged score20 draft, a fresh audit
hydrated910 attempts. None combined the consumed nested pointer-load scopes
with a GNU statement expression as the first operand of a returned logical OR.
The control preserves the actual load order and short-circuits the root load
exactly as before; its purpose was to make the genuine Boolean return live in
v0 while the remaining chain temporaries were allocated.

The result is negative:1040/136 bytes, ordinary/diagnostic parity and independent
relink SHA-256
`b880466ca3aba73b5ba64559d841ba06fc8dedd663f0ffad9e95167c759b5bcd`.
The compiler initializes a new pseudo93 rather than hard v0. A subsequent
pure-comma control below establishes that O2 CSE discards the hard target
earlier; `safe_from_p` rejecting the statement expression's `RTL_EXPR` is an
additional restriction, not the primary cause. Initial RTL then copies that result to v0 only
at the return. Local link80 stays in v0; result93 becomes a2 and extra Boolean
branches/moves appear. This does not repair the four local-register differences.

Exactly two compiler calls under20s/2GiB descendant-aware watchdogs, no survivors;
all2,077 selected source hashes/profiles and all910 attempts preserved. Keep
valid20, distinct from the older invalid XOR/OOB20. Private receipts:
`current20-local-phase-nov7`. No new automatic repair family is justified.


### Pure comma expression isolates the earlier hard-target restriction

The next control uses an ordinary comma expression for the same chain loads in
the first operand of the returned OR, within two real one-shot scopes. It has
no GNU statement expression or additional access. Result785/132 bytes, paired
ordinary/diagnostic and independent relink SHA-256
`19821b42916de802d482974b25542c92b73a180c236146f162134e539864ef8f`.

This corrects the earlier causal explanation: with CSE expected, `expr.c`
4110–4118 strips the hard return target into a null subtarget (4058–4062 already
clears a hard subtarget). Even the pure expression initializes pseudo87, then
copies it to hard v0 at the return; the link and sentinel remain local v0.
The whole-expression scopes also raise root references to15 versus p14, changing
their global order, rather than preserving the isolated load's weighting. The
extra result pseudo takes v1 and further branches/moves remain.

No source-only Boolean-expression mechanism for reserving hard v0 across these
loads was established under the actual O2 profile. Do not repeat comma versus
statement-expression syntax as if only `safe_from_p` caused the failure. This
second two-call control preserved all selected hashes/profiles and the valid20
draft. No live or canonical source changes; only this negative record is added.

## November 7: shared constant survives first CSE, not second CSE

A fresh audit preserves valid20, all 910 hydrated attempts and all 2,078
selected sources/effective profiles. A bounded regional size/assembly scan
found no newly exact donor; nearest `func_80049F50` remains open at745 with a
different global sentinel. This is bounded donor evidence, not an exhaustive
semantic search of every imported function.

One source-reviewed control adds an ordinary `s32 one = 1` at the mode2 body
entry and consumes it in the existing mode1 comparison and early return. It
changes no memory access, branch meaning or ABI. Earlier shared-one controls
used different pointer/return shapes or the rejected XOR/OOB lineage; they did
not establish the outcome on the current valid source.

The new source, SHA-256
`fcc71de65639fc0dd48883e48c64692aaeda919a444e87a19d089aab6d7664f2`,
still produces20/120bytes. Ordinary/diagnostic and independent relinks reproduce
the current linked body `e5a6b361d7a334e1b208ae84997183b483d4db8b9e8fabccad0486815719d97d`.
The shared constant survives first CSE and loop motion, but second CSE folds
the return copy back to literal1. Its lifetime then ends at the earlier mode
comparison; local link and sentinel temporaries still choose v0.

The installed compiler supports CSE follow-jump/skip-block controls. The actual
propagation crosses a skip-block edge, so disabling jump-following alone would
not target it. More importantly, `global.c` attempts local-register eviction only
after failing its ordinary/preferred/alternate searches. A global return
preference alone cannot evict local v0 while other usable registers remain.
Retaining the constant therefore does not establish the desired allocation.
No speculative flag sweep followed; the current verified profile is unchanged.

Exactly two compiler calls completed under20-second/2GiB aggregate process and
orphan limits, with no survivors. No live writes, claims or new match. Private
`current20-return-cfg-nov7` retains the paired receipts, complete preservation
audit, `REPORT.md` and `FLAG-AUDIT.md`.


## November 7: narrow return-mode mechanism audit

Fresh read-only freeze confirms valid20 source6c1afd73,910 hydrated attempts
and all2078 complete selected sources/effective profiles. A bounded16232-file
private C scan finds no exact current-root byte/halfword-return control. This
alone is not reason to repeat the older valid40 controls: both u8 and u16 already
retained40 and the same local-v0 obstacle.

Actual compiler code preserves narrow modes: convert.c145–153 retags comparison
expressions to QI/HI, and mips.h1906 retains TYPE_MODE in FUNCTION_VALUE. It is
incorrect to dismiss narrow returns as automatically SI at every compiler phase.
The obstruction is later: stmt.c2638 sets cleanups, and2853–2868 evaluates the
nonvoid scalar RHS with a null target before the late return move. expr.c4110
strips hard targets when CSE is expected regardless of mode;9891 creates a pseudo
for a null store-flag target. No demonstrated interaction with the staged link
load changes this mechanism. No duplicate compile or diagnostic-only replay ran.

The known caller still declares s32 and consumes the result through ANDI0xff;
byte consumption does not establish original return type or permit inconsistent
C prototypes. Full indirect-call closure remains unproved. Root independently
compared before/after frozen and selected snapshot files byte-for-byte: unchanged.
No compiler, preflight, generator, claim, live write, adoption or match.
Private return-mode-nov7/REPORT.md records source references, caller evidence and
coverage limitations. App PR755 documents both this return-mode limit and the
separate measured local-quantity birth controls in the compiler guide/ledger.

## November 7: block-lifetime revisit

Fresh strict read-only before/after snapshots preserve valid20 source6c1afd73,
910 hydrated attempts and all2,078 complete selected sources/effective profiles.
The remaining four differing operands at body offsets0x40,0x48,0x4c and0x50
use local link/sentinel v0 where the target uses v1. A meaningful branch-
distributed link could cross a block boundary, but existing allocator evidence
supplies neither the required v1 preference nor a solution for the separate
local sentinel. A global preference cannot evict local v0 while usable free
registers remain. No compiler or generator ran and no live state changed.
Preserve OPEN20 pending a new causal mechanism rather than repeat the existing
return-mode, CSE, constant and expression-shape searches. Private revisit-nov7
retains the source references and byte-identical preservation receipts.


## 2026-11-07: current-root pointer/value separation

Two isolated controls preserved the actual pointer loads, branch conditions and
signed 32-bit return contract while separating the pointer carrier from loaded
integer values. Neither improved the selected score of 20:

| Control | Source SHA-256 | Ordinary / diagnostic score | Linked bytes |
| --- | --- | ---: | ---: |
| Reuse returned-value carrier | `612d93c16734ac25e33c5dbde5898ee5e98e3092e4f13d29ef5d4676365b4b12` | 75 / 75 | 120 |
| Separate pointer-loaded value | `320b5c189726f1affe8156a0167583ccc6840426aa13604bb10dce39bd6a6e62` | 60 / 60 | 120 |

Both assigned the root to a0 and the pointer to a1, opposite the target. The
second obtained a v1 loaded-value local but retained v0 for the link and sentinel;
getting one desired local register does not establish the complete role mapping.
The first extended the returned value across the chain and also changed its
return register. These are finite negative controls, not a new automatic repair.

Exactly four compiler calls and four independent persisted-object relinks agreed.
The bounded controller completed without surviving owned processes. Fresh read-only
snapshots preserved all 2,079 complete selected rows/effective profiles, all 910
hydrated focal attempts, source, context, symbols and configuration. No live write,
new match or cartridge acceptance is claimed. Private pointer-value-roles-nov7
retains sources, pinned tools, watchdogs and relink receipts.
