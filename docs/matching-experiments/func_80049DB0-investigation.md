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
