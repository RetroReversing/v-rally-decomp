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
