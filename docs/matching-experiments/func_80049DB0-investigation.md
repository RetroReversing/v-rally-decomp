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
