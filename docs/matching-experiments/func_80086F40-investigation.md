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

## November 6: compiler-stage origin, without a new source sweep

Fresh saved-source hydration confirmed the reviewed325 draft, SHA256
`4fd369c155ee0c1911ce715a03ff34e7b7f6aaf563083c3213098f2bb11f4ae5`.
Ordinary and diagnostic builds agree on all468 linked bytes, SHA256
`629f7e0135af0b13cc1fd48fbdfc417152d3593192871c69488df9ff6623ad13`.
The647 hydrated attempts include obsolete lower-scoring contracts; those do
not supersede the reviewed source.

The walker and predecessor/parity remain global pseudos through local
allocation. Global allocation visits the walker first and assigns s0, then
assigns s1 to the predecessor; the target uses the reverse. Separately, initial
argument expansion copies the aggregate's final20 bytes and loads its first
word into a3 before assigning scalar a0. The copy temporaries therefore precede
the scalar argument's lifetime, before scheduling. This separates expansion
and allocation causes from a generic scheduler mismatch.

Previously tested genuine call staging, lifetime reuse, initialization, loop
and phase-union controls already cover these observations. No new native,
formatting or profile sweep was justified. No accepted repair or new match
resulted; the function remains OPEN325. Runtime allocation/callback assumptions
and the broader historical SDK factory chain remain explicit limitations.

## November 6: local donor and machine-code coverage

The next audit hashed23 local callback-containing C files, explicitly retaining
fork/region duplicates rather than claiming23 independent implementations.
Named __amDMA search found15 files across12 projects. Most submit via the
seven-argument osPiStartDma or explicit OSIoMesg/osEPiStartDma interfaces,
which cannot replace this function's verified six-word Packet ABI.

The read-only database ranking inspected38976 rows, with4812 actual target
byte bodies available. PROJECT rows without target bytes were recorded as
not disassembled, not scored as dissimilar. Above0.70 mnemonic similarity,
the regional V-Rally callback has no source and the South Park candidate is
OPEN3215, so neither is a verified donor. The named matched Turok callback
scores0.396 mnemonic similarity; its name alone supplies no exact transfer.

One distinct source lifetime from Snowboard Kids was tested: cache the initial
list head for the no-free-buffer return, before any list mutation/call on that
route. Submission and all current contracts are unchanged. The control scores
1985 with444 linked bytes versus current325/468. Ordinary/diagnostic bytes
agree, SHA256d53ab0f53275984e5723192e200c0805ffea6d1111830d023532d47ad2b1f140.
Frame0x38 and saved registers are unchanged; walker/predecessor remain in the
wrong s0/s1 allocation. Common physical-address returns fold and the independent
head reload disappears, producing the shorter body. This is negative evidence,
not an accepted replacement or automatic repair. Private donor-audit-nov6 holds
source inventory, target ranking, exact-history check and linked receipts.


## 7 November: distinguish global priority from earlier local allocation

The fresh audit hydrated 647 attempts (455 unique sources). Selected `alLink`
uses the same `N *, N **` interface as this draft, `alUnlink` uses its existing
backlinks, `func_80081040` accepts the six-word aggregate, and
`osVirtualToPhysical` is `s32(s32)`. Substituting a different SDK interface is
not justified. Actual profile remains KMC GCC 2.7.2,
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

Eight nested one-shot scopes around each existing parity assignment genuinely
raise its weighted references from 17 to 33 and move it ahead of the walker in
global allocation order. Nevertheless the result is byte-identical to the
325 baseline: 468 bytes, SHA-256
`629f7e0135af0b13cc1fd48fbdfc417152d3593192871c69488df9ff6623ad13`.
The call-lived data pointer was already locally assigned `s0`; parity overlaps
it and cannot use that register regardless of global priority. Walker dies at
the data load and can reuse `s0`. Rank-only controls cannot remove this cause.

Binding the existing raw data load to the same consumed C local in both return
paths makes it global and removes the earlier hard-register reservation. It
also creates a real walker/data overlap before the cache-hit start load, adding
`s3` and growing the frame from 0x38 to 0x40. Result: 888, 476 bytes, SHA-256
`6dfc01d2f01ab94ee6c0866f236ec2504edbc3397b30168d146e38212e472435`.

A third control stages the existing start-field load before data in the hit
path and combines this with the consumed parity-assignment scopes. Flow analysis
ends the walker lifetime at the data load, but first scheduling moves the tail
data load before both node stores and recreates the overlap. Walker `s1` and
parity `s0` are recovered, while data still needs `s3`. Result: 1013, 476 bytes,
frame 0x40, SHA-256
`17be2dfb3c7ae52d34ae1c9d1f8bbad6e32e73c18671b8e6e824a7ef7e8d9291`.

These six bounded compiler calls have ordinary/diagnostic parity and independent
relinks. No added memory reads, dummy values, ABI changes or accepted C. All
2,077 selected source hashes/profiles remain unchanged. A further read-only compiler audit rules out raw field spelling as a way to
restore this dependency: `true_dependence` calls `memrefs_conflict_p` before
consulting `MEM_IN_STRUCT`, and the identical base with distinct fixed offsets
(+16 versus +8/+12) already proves the accesses disjoint. No additional compile
is warranted by that flag alone. Do not repeat a flat register-priority or raw
field-flag sweep for this cause. Private receipts: `current325-contract-phase-nov7`.
