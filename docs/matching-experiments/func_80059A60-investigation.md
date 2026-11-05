# func_80059A60: audited dispatch baseline, unresolved

Private, read-only investigation of project1's 328-instruction function. No live attempt, selected source/profile change, canonical write, cartridge gate or new match claim.

## Frozen facts

Frozen inputs SHA256 `51f1da6d956c04d1fce93d207be84b827949a07de61333ebeb6a03bdc8bcc1a0`; function was OPEN, score200, unclaimed. Compiler: gcc-2.7.2-kmc `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

The saved draft manufactures a redundant `if(i==4)` whose two arms perform exactly the same assignment/call. Do not accept or generalize this as a repair. Removing it produces `clean.c`, score750. Also remove an unnecessary Group pointer copy. `formatted.c` is the same computation with ordinary multiline formatting, score630; its lower score does not mean physically closer code.

## Semantic audit

All Style/Widget/Group/Menu/Task field offsets agree with target loads/stores. The first dispatch runs indices0..4, selector2 for0/1 and1 otherwise, skips null tasks, and suppresses task1 only when f24D is nonzero. Calls and later global reloads retained.

The target's Group loops do **not** advance the outer Group pointer: s3 stays fixed through both loops. Only inner Style and Widget chains advance. Do not add a seemingly obvious `g=g->next` fix. n is u8, consistent with target count masks; i/j increments and wrap masks are retained. The u16 widget count may exceed an 8-bit induction counter; source retains that machine behavior rather than changing termination rules.

D_800C02AE+0x807A is address0x800C8328, aligned to4, and target loads a word there. f24B decrements only for nonnegative signed-byte values (result -1..126). f249 is an unsigned byte decremented only when nonzero. No uninitialized reads, fabricated volatile, inline assembly or new identities introduced. Ordinary game-pointer/list validity remains required, as in the machine routine.

## Remaining physical discrepancy

The original clean formatting matches the rest of the body apart from a missing dead s2=4 initialization at80059AF8 and beqz vs beql for the first selector case, with subsequent branch destinations shifted by4 bytes. s2's next occurrence after this definition is an unconditional zero definition80059C90; later loops independently zero it at80059D94/80059E78/80059EB8; epilogue restores the caller's saved register. Calls preserve s2. Thus this initial4 has no architectural consumer, and it is not evidence for an invented branch in source.

Multiline formatted630 introduces additional register/scheduling differences despite its smaller advisory score. Preserve both baselines; prefer physical review over treating630 as proof of better C.

## Failed directed experiments

No exact result from: equivalent loop bounds <=4/!=5 and unsigned casts; meaningful local bound4 with u8/s8/u16/s16/s32/u32 types; reuse of j/n as the bound; complete finite dispatch case groupings; direct per-case call formulations; legitimate terminal break forms; switch-line scheduling layouts; compiler debug/scheduling/CSE/strength-reduction variants. These preserve program computation (except separate diagnostic variants explicitly not proposed for adoption) but do not recover exact bytes. See scripts and per-candidate JSON files.

Native lane uses one independent clean baseline, never a candidate portfolio, filters expand_expr lineages, applies uninitialized-read preflight, and records every actually judged candidate. Rejected native best0's cast of a boolean to float was unnecessary; removing it produces the same formatted630 score. Do not retain arbitrary boolean-float casts as a matching technique.

Leave this function OPEN and revisitable. No new automatic rule is justified by the unresolved dead-initialization case.

## Final run evidence

1000 unique independent native candidates actually compiled and linked; no exact result. Best recorded advisory score630 was not a new semantic repair: ordinary formatting alone produces it. The six final do/while hypotheses (`i++<4`, `i++!=4`, `++i<5`, preserving continue-to-condition semantics) were also negative: clean scores1305/1610/1150; multiline1745/2050/1310.
