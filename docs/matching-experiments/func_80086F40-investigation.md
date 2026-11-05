# Audio DMA cache investigation

The 117-instruction function remains OPEN and revisitable. A bounded pass of
515 ordinary compile/link judgments found no exact candidate and left the best
advisory score at 265. This is negative evidence, not a proof of impossibility.

The main differences are a saved-register allocation swap and first-argument
staging around a five-word structure argument copy. Related SDK `__amDMA`
implementations helped identify the linked-list DMA cache and predecessor/alignment
lifetimes, but did not provide an exact donor for this version.

Tested without improvement: separate pointer/alignment locals, same-type phase
unions, declaration/storage variants, load and call staging, statement chains,
source-line boundaries, and the existing 20-candidate repair first page. Exploratory
prototype/ABI alternatives were rejected and are not inferred declarations. No
alternative C is accepted, and the original source/profile/target remain intact.

Immutable private capture SHA-256:
`b76c48a920b871341650c19ad44974c622a90d60070f7e262d8594700982dfe3`.

## Contract audit superseding the old score baseline

The earlier 265-point baseline and five-word-call description above were superseded by the selected-callee audit below. They are retained as historical negative evidence, not valid source contracts.


No exact match. Keep the function OPEN/revisitable. No live project or runtime mutation was performed.

## Honest baseline and actual contracts

Fresh read-only capture SHA-256: `b52fe4120d4cc845bcb018e3e36e80e9759661a505cb32d03b97b24d6cb29ae4`.

Preferred corrected draft: `corrected.c`, SHA-256 `4fd369c155ee0c1911ce715a03ff34e7b7f6aaf563083c3213098f2bb11f4ae5`. Unchanged ordinary pinned compiler/link judge: score **325**, not exact. The old 265 is not a valid improvement baseline: it used incompatible cross-TU callee declarations and an out-of-bounds pointer intermediate.

Actual selected `func_80081040` takes `(s32, s32, u32, struct { s32 w[6]; })`, rather than five arguments splitting the final aggregate. Actual selected `alLink` uses a two-field node with `next` and pointer-to-next-field `prev`, taking `(N *, N **)`. `alUnlink` takes `void *`, and `osVirtualToPhysical` takes `s32`. The corrected callback embeds that link structure as its first member and uses the actual field addresses. The cache-hit address calculation uses unsigned 32-bit machine-address arithmetic before the explicit address conversion, avoiding the invalid intermediate `data + full_ROM_address` pointer.

The parent independently traced the factory and selected SDK-derived audio consumers to `ALDMAproc(s32, s32, void *)`. The corrected callback retains the genuinely unused third state argument and converts its signed input address to an unsigned local for comparisons. Existing selected frame/counter globals are `u32`, retained in the corrected draft. These are actual contract corrections, not guessed ABI variants used to manipulate allocation. The larger legacy cross-TU SDK chain is not globally proven ISO-typed.

Normal game preconditions still matter: nonnegative bounded request lengths, valid cached ranges without signed end overflow, a valid free-list pool and corresponding allocated packet table, and frame-reset bounded DMA counter. Parent investigation of selected initialization/frame-reset functions supplies this context; arbitrary invalid callers are not claimed safe.

## New negative evidence

212 non-native ordinary compile/link judgments (211 compile successfully; one deliberately staged assignment violates the old compiler's declaration placement and is rejected). 83 are the current shared repair generator's bounded proposals. No improvement from:

- compatible six-word aggregate staging, copies and call-argument assignment/comma placement;
- genuinely dead input/local reuse and initialization placement;
- predecessor/parity split and disjoint-lifetime storage union;
- unsigned address/counter/local representations;
- loop-shape and predecessor-capture placement;
- current shared allocation/debug-line/local repair proposals.

Exploratory alternative aggregate layouts were negative only and are **not** compatible replacement types for the selected six-word-array definition. None is proposed for acceptance.

A private safe native lane completed 500 scored candidates, best 325, no exact. It ran from the corrected callee/address baseline before the parent supplied the final unused callback state argument and unsigned global declarations. Those final contract changes independently preserve score325; the native results are negative exploration rather than proof about every variant of the final declaration. Candidates were filtered for invented qualifiers/asm/register, trivial identities/self assignments and Clang-detected uninitialized use. No random candidate was accepted.

Remaining differences are chiefly the saved-register allocation swap and scheduling of the first outgoing argument across the aggregate copy. No reusable repair family was demonstrated to solve them. Suggest preventing token-wasting searches on an inconsistent lower-score draft by presenting known selected-callee/callback contracts before launching the search; do not weaken exact-byte acceptance.

Evidence: `negative-evidence.json`, `corrected.json`, `shared-results.json`, `native-safe/results.json`, and immutable `frozen/` capture. Private ROM/assembly/captures must not be committed.

## Cursor and outgoing-aggregate lifetime revisit

Twenty new controls preserved the real four-argument, six-word Packet contract
but found no exact match. Typed previous-link cursors retained 325 and the same
walker/predecessor register swap. Ten genuine dead-address/aligned-address
lifetime controls scored 325–865 without improvement. Four meaningful inline
DMA-submission extractions recovered outgoing argument/table/copy register
choices, but removed the target's saved-register subtract plus argument move;
they became one instruction shorter and scored 500. The first aggregate-word
load also remained earlier than the target's size load.

Eight original-address/return-parity lifetime controls were prepared but not
tested: a foreign app-agent claim appeared before the first compile, so the
private investigation stopped. Do not count them as negative results. Recheck
current source, context, compiler profile and ownership before continuing.
The saved source hash at this checkpoint was
`4fd369c155ee0c1911ce715a03ff34e7b7f6aaf563083c3213098f2bb11f4ae5`.
No native search was repeated, no claim was taken or released, and no match or
live source change is claimed. A concise source-hash-bound investigation note
was also sent through the app's normal add_note tool for future agents.


## Completed parity and lifetime controls

A fresh read-only freeze confirmed the corrected325 baseline and selected callee
contracts. The eight previously untested address/parity controls now compile,
but score585–1398. In total43 new source controls compiled without an exact
match: formal reuse, typed predecessor/parity separation, initialization order,
loop/predecessor-hit placement and six disjoint phase-union forms. The unions
read only their active member; none relies on inactive-member type punning.

Nineteen supported compiler/debug/optimization controls also found no
improvement. Disabling forced memory operands scores330 only because it
reverses operands of a commutative cache-hit addition; it does not fix the
saved-register swap or outgoing aggregate argument staging. One newer option
was rejected by the period compiler and excluded.

Source, context, target, symbols and profile remained unchanged. No source was
adopted and no new repair family was demonstrated. The results are retained
in normal app notes and portable progress; this function remains OPEN325 and
revisitable. Do not restart the old native sweep or use the incompatible265
draft as an apparent improvement baseline.
