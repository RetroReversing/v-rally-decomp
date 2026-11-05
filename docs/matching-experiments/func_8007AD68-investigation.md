# func_8007AD68 independent revisit

Result: ordinary compile/link exact, 848/848 bytes equal, using `LinkResult.linked_code` rather than the relocatable candidate `.text`. Canonical/live data untouched. Parent independent full 12,582,912-byte gate preserving all 2,065 prior objects and profiles remains required before acceptance.

Use `exact.c` (same contents as `exact-compatible595EC.c`), SHA-256 52735d3eda7a2a6fdabe224c924b1d4eb5820278c9e924988ae6dd9797d3320c. Evidence, immutable input hashes and pinned compiler/profile are in evidence.json and frozen/. App private worktree is detached b2566a57506e7a1ea273abba78e2214177a7350c. Fresh initial and final database reads: open, score60, no claims.

## Previous evidence audit

The live score60 source, previous base/correct-callee source, scheduler notes, evidence.json and fresh-basin-evidence.json were reviewed before searching. The score60 basin explicitly contains `if (func_80065860)` whose two arms are identical increment-and-call sequences. This is an artificial constant function-address condition and is disallowed; its near match is not a valid seed. Its many recorded native lanes and scope/qualifier/scheduler probes therefore do not establish a valid source match. Previous native families also included self assignment and cancellation transforms; their results were not reused.

The independent prior `redraft/switch-address-cached.c` is a real control/data-flow reconstruction: data-dependent switch over the u16 mode, separate case0 and case1..4 entries, original goto joins, no artificial constant branch. Its ordinary recompile is score70. The duplicated *case bodies* express real different switch cases, unlike the invalid constant function-address if. This is the only baseline used here.

## Controlled repair

1. Replace m2c integer-address slot indexing with structs that encode the same offsets and strides: League.current@3, teams@0x10; Team.slots@8/stride20; Slot.obj@4/stride12; Object.state@0x2c. Replace callback stores through s32**/void** with actual function-pointer slot types. Score remains70, demonstrating these type fixes alone do not obtain the match.
2. Replace the standalone signed assignment `*(s8 *)(state+0x228) = (s8)(cached_signed_byte + 1)` with standalone `++((u8 *)state)[0x228]`. Score0/exact. Standalone postincrement is also exact; both discard expression value, so their result-value distinction is irrelevant. An explicit unsigned temporary then assignment is independently exact. Merely changing destination cast to unsigned stays70. Incrementing the signed cached temporary then assigning worsens290. Other index type changes worsen470/1005/860/610.
3. Correct three address-only string/object declarations from scalar s32 to u8 arrays, passing the array address directly. Exact remains unchanged. No object contents are read locally.

Unsigned conversion proof: let stored byte b be any value0..255, and let signed decode s=b when b<128 else b-256. The original arithmetic s+1 is representable in int. On this pinned compiler, final conversion to signed8 and storage writes (b+1) mod256. New unsigned byte increment performs int promotion, adds1, and assignment conversion to u8 is defined modulo256. Both write the same byte. The byte is reloaded by the new source, but between cached load and increment there is only a nonvolatile team-index load and a pure condition; no call/write changes it. Preconditions: ordinary single-threaded game state, no external asynchronous modification of this nonvolatile byte, valid pointer objects and valid team/slot indices as the original accesses require. No new signed overflow, uninitialized values, fabricated volatile/register, assembly, or artificial cancellation.

12 directed candidate attempts,12 successful compiles,4 exact variants; zero native generation and zero Clang preflight attempts. Proof recompiles are separate from candidate search counts. No broad lane needed.

## Callee and cross-translation-unit contract audit

Current matched-source snapshots are private `func_*-callee.json`. func_8005A388 is actually int(int,int), explicitly returns0; candidate preserves this and ignores its result. func_8006F0E0 is void(u8); func_8007A688 is void(void); func_800407D0 is void(void); candidate results unused. No preserved-return-register hypothesis is used. func_800595EC's matched machine draft declares void(s32) but forwards that word to func_800594F4; another current matched caller declares char* and passes a stack text buffer. Thus the s32 legacy declaration is not proof of integer semantics: here three named object addresses are passed in the same 32-bit argument register. Candidate retains the prior void* pointer interpretation; downstream exact C type remains unresolved, explicitly not a proved cross-TU prototype contract.

Callbacks are only stored, never called here. `Callback = void (*)(void)` expresses storage representation and does not prove downstream callback signatures. Their address identity and all linked operands are unchanged. No callee return values are consumed.

`cross-tu-globals.json` records current matched declaration evidence. Existing independent translations disagree heavily: D_800A1468 appears as void*, u8*, multiple struct pointers and even s32; D_800C35A0 similarly; D_800C3508 has multiple unrelated struct-pointer views. They agree operationally on loading pointer words from these symbol addresses. This candidate uses void*/u8*/League* views and observed field offsets; it does not establish globally compatible C declarations across independently generated TUs. Three address-only objects now use byte arrays rather than unjustified scalar objects. Linking each generated unit and reconstructing bytes is supported; whole-program language-level compatibility remains an existing project limitation. Pointer reconstruction is not a complete runtime equivalence proof.

## Proposed reusable family (no app edits here)

A bounded directed family may rewrite a standalone byte increment assignment to ++/post++ of an unsigned byte lvalue, only when the expression value is discarded, the byte lvalue is nonvolatile/non-atomic, its address evaluation has no side effects, and source arithmetic is proved equivalent after byte conversion. For a cached signed byte, additionally require unique reaching definition as a load of the same exact byte, no intervening call/store/volatile operation or escaping alias that could change it, and cached value dead afterward (or preserved unchanged). Reject result-used increments, decrement/other arithmetic, wider/unknown types, side-effecting address expressions, volatile/atomic loads, or uncertain cached alias/lifetime. Direct `*p = (u8)(*p+1)` is the simplest safe initial family; cached s8 form requires def-use proof and should not be matched by broad regex. Generate at most two discarded-value spellings from one audited baseline, retain provenance, ordinary link-judge both. No target/ABI/profile modifications.

## Parent-requested selected-signature control

The final preferred source changes func_800595EC's formal to its selected matched definition `void(s32)` and explicitly casts each of the three byte-array addresses to s32. On the known N64 32-bit pointer representation this preserves the exact address word; all848 linked bytes remain equal. This resolves this caller's conflict with the selected definition without asserting that legacy machine draft's integer parameter is semantically ideal. Five exact candidate spellings now found in13directed attempts/compiles, including this control; proof recompiles counted separately.

Selected func_8005A388 is int(int,int), compatible with s32(s32,s32). Selected definitions for callbacks635A0,63790,6556C,65860,70C34,7159C,7A9A8,7AA94 are all void(void), matching candidate declarations. Callback7A29C remains open with no selected matched definition; its existing void(void) declaration is unproved. This function merely stores its address and makes no call. `selected-callback-signatures.json` records the actual definition lines.


## Parent acceptance

The independent full-cartridge gate passed for exact-compatible595EC.c: all12,582,912 bytes equal the fixed original (SHA256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7). Every prior selectedC object/profile is unchanged. The normal live API accepted the same sourceSHA52735d3eda7a2a6fdabe224c924b1d4eb5820278c9e924988ae6dd9797d3320c. All portable progress was saved; standalone selection and ByteMatch unit metadata now include2066 C functions. The autogenerated family replay is separately undergoing a full cartridge check; it is not counted as another game match.
