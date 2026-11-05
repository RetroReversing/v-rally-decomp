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

One independent native lane from the contract-corrected baseline completed1000 actual generated attempts:48 duplicates,72 preflight rejects,123 forbidden-token rejects,757 compiled/scored. Best remains2; no improvement or exact result. Each distinct candidate has an independent Clang file, initialization diagnostics, retained lineage and separate attempted/compiled/preflight counts. This is not a complete UB checker; any exact candidate still requires semantic audit and parent independent full 12582912-byte cartridge verification preserving prior2065 objects/profiles.

No second native lane was run. No exact candidate was found, so the full-cartridge gate was not run. No match/acceptance claim is made. Final readonly check remains open score2 and unclaimed. The concrete remaining lead is genuine early addressable local allocation changing stack placement, with the controlled getter variants above as negative evidence. Further work requires a new source-shape hypothesis, not repetition of padding or these controls.
