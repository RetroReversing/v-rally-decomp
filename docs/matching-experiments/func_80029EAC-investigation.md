# func_80029EAC private investigation

Frozen from the live read-only project 1 database while OPEN, score 295 and unclaimed. No live/canonical writes, claims, compiler changes, app restarts or acceptance.

Private app checkout: b60a4174cd6da3cdaa274071ac5b15ad95be2c62. Original profile: gcc-2.7.2-kmc, `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

## Source audit

The function constructs a local triangle basis from grid vertices, optionally computes plane height for indices 4, 5, 10 and 11, normalizes the basis, transforms the point, transposes the basis, then records contacts with nonpositive depth.

`clean.c` removes an unused repair variable and explicitly wraps dot/numerator arithmetic and the final depth-times-16 calculation with unsigned arithmetic. This preserves advisory score 295. The arrays are indexed under the function's existing valid-grid/index contract; the shift count is derived from the matched leading-sign-bit helper. The signed divide still has the original valid division domain (the target has explicit overflow traps), rather than inventing saturation.

However this is **not yet an accepted sound source**: the original low-score draft only initializes `mat.h[0..8]`; `mat.h[9]` and `mat.pad[0..2]` are indeterminate. The callee func_8002DA98 copies input words at offsets 0x14, 0x18, 0x1c into the inverse, confirmed in actual machine instructions 8002DAF8 / 8002DB00 / 8002DB08. It does not initialize inverse offset0x12. The caller then copies all 32 inverse bytes at 8002A3B4..8002A3F0 and all 32 matrix bytes to the contact record at 8002A42C..8002A468. Thus it is unsafe to treat low advisory score295 as proof of defined scalar C. Aggregate/object-representation transport of padding is a different matter: this observation is not a blanket claim that all 32-byte copies are undefined. It is a real target unused-field/padding modeling issue; no invented pointer identity or branch solves it.

`initialized.c` initializes the whole input matrix aggregate: score2260. `sound.c` adds explicit zeros after the nine meaningful basis fields, initializes inverse reserved halfword before the callee, and retains the wrapping fixes: score870. These zero stores are deliberately conservative for research and are absent from the target; they are not claimed to reproduce the target's otherwise indeterminate reserved/translation bytes. No source was submitted to the live judge.

The matched neighboring func_8002A4C4 and func_80029AA8 use analogous full matrix copies, but that does not establish their unused fields are initialized and is not permission to copy the same issue into this function. Their sources and the actual transpose helper were captured privately for comparison.

## Native lane

Exactly 1000 independent generated attempts requested from the single audited initialized `sound.c` baseline, no selected-best portfolio. Each unique candidate receives a separate Clang preflight file with uninitialized and sometimes-uninitialized promoted to errors. Forbidden asm/volatile/register additions are rejected. Counts distinguish generator attempts, duplicate/rejected candidates, successful compiler runs and scored linked candidates. Native output is private, not automatically accepted.

See `native-independent/status.json`, `results.json` for actual totals and lineage. Generator-side scalar initialization checking can currently be disabled by unrelated macros, so Clang is independently required. Attempt11 is a concrete example: introduced `new_var` initialized only in the special-index branch but read unconditionally in later vertex indexing; preflight rejects it. This evidence was sent to the parent working on that generic safeguard.

## Directed probes

Separating final depth from earlier triangle-index `right` gives score955, and once-executed scope around the first `right` assignment gives1050. Neither is exact. No extra search lane was launched without a concrete different lead.

No exact match, cartridge gate or new match count is claimed until the final native status is inspected. Leave the function OPEN and preserve the baseline as research, not accepted code.

## Representation follow-up (concrete new lead)

The parent correctly identified that adding zero stores may change the intended endstate: whole aggregate/object-representation copying does not inherently evaluate each member as a scalar. `representation.c` changes Matrix into an aligned4 32-byte union with nine s16 values and an unsigned-char reserved array; score295 unchanged. That array has actual unsigned-char members, **not automatically padding**: DR451 cautions against calling arbitrary indeterminate unsignedchar values fully defined.

`padding.c` instead uses nine s16 values and unnamed unsigned-int bitfields :16,:32,:32,:32; this creates genuine no-value padding with size32/alignment4. It also preserves295. No semantic scalar read of the padding is made by this caller. However the current C reconstruction of transpose still performs typed s32 reads of tail words, so a representation-copy contract/source model is required before declaring the combined execution valid. The actual machine code's wordwise copy is compatible with a raw object-representation transfer, but that alone does not prove a current typed reconstruction valid. Potential later modeling uses aligned aggregate4 assignments for tail copies without accessing a scalar alignment member. No other matched function was altered or judged.

Primary standard discussion provided by the parent: WG14 DR222 (whole aggregate copies vs member evaluation), https://open-std.org/jtc1/sc22/wg14/www/docs/dr_222.htm ; DR451 (indeterminate character values ambiguity), https://open-std.org/jtc1/sc22/wg14/www/docs/dr_451.htm .

This concrete type-model lead justifies one additional independent1000-attempt lane from padding.c, with distinct output and Clang files in native-representation/. It is not a best-candidate portfolio and does not claim the representation model is fully proven yet.

Further directed probes: once-executed scopes around early assignments, separating/reusing final depth, and natural union/int-pointer reuse suggested by matched neighbor29AA8. No improvement in the initial probes. Target's early roles are right=s3, down=s1, diagonal=s0, saved-right=s2; candidate295 has right=s0, down=s1, diagonal=s2, saved-right=s3. Final depth target v0/a1 versus candidate long-lived s0 is another allocation difference. Swapping natural plane-height/slot lifetimes and six final-depth reuse choices did not improve295 (best335); no fake effects were introduced.

Period-compiler compile-time checks in padding-layout-assert.c establish sizeof(Matrix)==32 and sizeof(struct {char c;Matrix m;})==36, giving expected alignment4 for this layout; linked advisory295 unchanged. All23 nonoriginal declaration-order permutations are295. Moving saved-right and diagonal capture ahead of the sign call individually/together, or chaining right/slot initialization, is likewise neutral295. These negatives argue against another declaration-order sweep.

## Final outcome

Both native lanes ended normally. Initialized zero-field baseline:1000 attempts,715 successful compiled/scored candidates,53 duplicate,104 forbidden-token,128 rejected by Clang; minimum860 from chained zero-field assignments, noexact. Padding-model baseline:1000 attempts,740 successful compiled/scored candidates,58 duplicate,108 forbidden-token,94 rejected by Clang; minimum295 unchanged, noexact. Additionally55 recorded baseline/directed compiler judgments, allnonexact. No matched-code portfolio, liveacceptance, fullcartridgegate, apppatch or runtimechange. Livefinal remainsOPEN295/unclaimed with targetunchanged.

Keep padding.c as representation research with the callee-contract caveat; preserve sound.c only as conservative zero-field negative control. Do not replace livebest or count either as matched.

## Interface and representation-copy revisit

# Revisit result

No exact func_80029EAC match. Thirty-two bounded role-lifetime combinations all compiled and linked, minimum advisory295. No native sweep repeated. Correct return/type declarations preserve focal295 (`provisional-corrected.c`), research only.

Four existing selected callees have independently exact corrected sources in final-corrected-proofs.json. Three wrappers forward the actual typed arguments; E530 returns the actual E288 result. Transpose uses 32-byte/alignment4 nine-short Matrix plus genuine unnamed padding and copies three tail words by builtin memcpy using unsigned-char object offsets20/24/28. No scalar padding evaluation. Signed/unsigned16 aliases address the meaningful nine halfwords. No custom asm, volatile, register, identity tests or altered profile. All four independently frozen effective contexts equal focal. Parent owns joint declaration reconciliation and cartridge/acceptance. Changing transpose parameter type means affected external declarations must agree before any complete source-level contract claim. Other callers may use meaningful translation fields; representation copies preserve their bytes, but this research Matrix model does not establish those callers' type model.

Controls: library memcpy12 unresolved memcpy symbol/nonexact1740; unaligned builtin12 nonexact2130; aligned builtin12 nonexact760; aligned split4 with int arithmetic exact but superseded by unsigned-character-offset exact variant. The latter avoids int-pointer arithmetic across a Matrix object.

Runtime/live source/canonical repository never changed. Live DB accessed strictly readonly. Fresh final status: open, score295, claims0.

All eight direct transpose callers captured in transpose-callers.json use distinct frame-local outputs (inv/frame.mat/loc.sp30/spA8/m) with separate local or external/global inputs. No inplace call found; memcpy precondition is justified for this observed call graph, not a universal overlap-capable API claim. Unsupported builtin memmove4 is nonexact2555/unresolved; representation transport through local u32 temporary is nonexact820 due spills. Source audit did not establish absence of arbitrary indirect calls beyond existing symbol references.

Followup: opaque void*(void*,void*) transpose signature with local Matrix pointer conversions is exact0, superseding typed public signature. Period checks sizeof(Matrix)==32 and sizeof(struct{char c;Matrix m;})==36 both compile. Direct h[] indexing, with or without explicit unsigned source casts, scores790 due traversal codegen; exact opaque source preserves corresponding signed/unsigned16 alias accesses. Thus public parameter declarations need no new Matrix type contract. Return declarations still need agreement. final-corrected-proofs.json now points at transpose-opaque-1-fields-0.c.

### Independent cartridge gate and live-import status

Parent rebuilt a copied complete cartridge with the three forwarding-wrapper
corrections and the opaque transpose correction together. Output is exactly
12,582,912 bytes, SHA256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All 2,069 selected compiler profiles and 2,065 other selected C objects are
unchanged. This corrects existing matched sources; it adds no function match.
A separate three-wrapper-only cartridge control also passes full byte equality.

The ordinary saved-source files are staged for import, but the app's save
request timed out and read-only inspection had not yet confirmed these sources
in its database. Do not claim live acceptance from the copied build. The
adjacent corrected-source examples preserve the tested inputs for review.
The focal caller remains OPEN295 and the full cross-unit record types have not
been globally reconciled. No runtime update or restart was performed for this
revisit.

### Normal import confirmed

Subsequent read-only inspection confirms all four exact corrected source hashes in the live matched records. The canonical standalone tree now contains the same four tested corrections. The full normal progress export also retains current app source/profile alternatives; previously verified standalone variants remain selected for other functions until separately audited. This adds no match and keeps the copied full-image proof above.


## Triangle-role and depth-phase revisit

The current corrected opaque transpose preserves the genuine-padding Matrix
caller model at score295 without invented zero stores. Padding is transported
as object representation, not read as an uninitialized scalar. This bounded
model does not establish whole-program type reconciliation.

152 directed controls compiled (142 distinct sources):12 final-scope/copy forms,
72 triangle-role/depth lifetime combinations,48 assignment-in-condition/final-copy
forms and20 small record/array index-role forms. No exact match or improvement
was found. The record/array forms introduced unwanted memory traffic. Ten initial
C89 parsing forms were corrected before final tests and are not counted as
successful compiles. Nineteen supported compiler/debug/optimization controls also
found no improvement; one unsupported newer option was excluded.

The early vertex-role register allocation and final depth delayed move remain
unresolved. Live source, context, target, relocations, profile and symbols are
unchanged. No candidate was adopted or new full-cartridge claim made. Normal
project notes and the portable snapshot retain these results. This function
remains OPEN295 and revisitable; repeating the prior native sweeps or these
identical lifetime controls is not a new hypothesis.


## November 6: pass diagnosis and actual saved-source correction

A fresh live freeze exposed that the saved295 draft still had historical
`h[10]/int pad[3]` Matrix fields and obsolete helper declarations. Earlier private
padding-model probes and helper acceptance did **not** establish that this focal
caller source had been adopted. Those descriptions must not be used as a live
source fingerprint.

Normal source-scoped review has now retained the corrected OPEN295 source,
SHA256 `c4f8462e1b35641fdb411002210f28881f378922b1d06b8ea1cb21ce3f07b263`.
It uses nine meaningful halfwords with genuine unnamed Matrix padding, verified
size32/alignment4, the actual seven selected helper signatures, real delta[3]
and mat.h arrays, a caller-compatible void-pointer entry and scalar halfword
point accesses at byte offsets0/2/4. E530 remains its actual s16-pointer API;
it was not changed to an opaque interface. The transpose API is opaque.

Parent ordinary reproduction and diagnostic capture agree across1560 linked
bytes, hash `43749f2981db46d5d60b9c55e197097bba5947a7dafd3438477eafc777a86291`.
The output remains295/nonexact and all2071 matched sources are unchanged. This
removes concrete model/interface problems without claiming whole-game storage,
lifecycle or arithmetic safety. Valid grid indices and complete live objects,
helper output initialization and nonoverlap assumptions remain explicit.

Historical-live pass evidence locates deletion of the final depth copy in
combine, before scheduling; global allocation chooses the early vertex-role
cycle. Two new copy-before-condition controls both remain295. Earlier152 source
and19 profile controls were not repeated, and no new native lane was justified.
Do not automatically transfer historical pseudo/insn IDs to another source's
capture merely because its linked bytes are equal. Private proofs and corrected
source: rtl-revisit/REPORT.md and corrected-byte-point.c.

The approved dev-app update/restart reached mainc1ede929 on port6474. Independent
pre/post checks confirmed all2071 selected source hashes and compiler profiles
unchanged before the focal correction; its normal adoption preserved them too.
