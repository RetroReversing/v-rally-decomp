# V-Rally PAL compiler matching notes

These are measured results from the PAL target, not a reconstruction of the original author's source spelling. Keep target bytes, addresses and the exact-match judge unchanged. A lower score is useful evidence, not a match.

## KMC GCC 2.7.2 and binutils 2.6: paired debug-line boundaries

`func_8004E094` is 62 instructions / 248 bytes. Its starting draft had the right instructions and registers, but an extra NOP before a floating-point multiply and a missing NOP after an MFC1. The original compiler profile was retained: `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

Two ordinary C changes reproduced the target:

1. Put `new_var2 = 0.5f;` on the **same physical source line** as the `p6` multiplication, moving the unused-until-later constant assignment from its earlier location.
2. Give the second negative float-to-short conversion its own equivalent inline helper, defined on different source lines from the first helper.

Saved compiler assembly showed different `.line` label boundaries around the `li.s` expansion and the two conversion sequences. Those boundaries affect this assembler's hazard scheduling. Preserve the accepted source layout and both helper definitions when editing this function.

| Controlled trial | Score | Exact linked bytes |
| --- | ---: | --- |
| Starting draft | 60 | No |
| Constant-line change alone | 110 | No |
| Separate conversion helper alone | 110 | No |
| Both changes | 0 | Yes |

Both isolated edits look worse to a greedy score-only search. A useful automatic repair should recognize NOP-only drift, inspect the emitted line boundaries, and try the small paired change with the normal byte/data judge. This does not justify dropping NOPs or accepting instruction equivalence instead of exact bytes. The observations are specific to this compiler, assembler, flags and source context; arbitrary line changes are not generally beneficial.

The accepted implementation is in [func_8004E094.c](../src/code_8004BEB4/func_8004E094.c).

## Branch-local tail pointers in `inflate_codes`

An existing app agent matched the 354-instruction / 1,416-byte decoder during the same window. The change introduces a fresh `src0` local, assigns it after advancing the aligned word-copy pointers, assigns it separately in the unaligned branch, and passes that local to the final byte-copy call. The residual `chunk &= 3` follows both updated pointer calculations.

That reproduces the target's argument-address setup before its final ANDI. Initializing the extra pointer eagerly before the word-copy branch did not reproduce the target in our separate trial. Keep the value's lifetime at the branch join where it is needed; moving an equivalent address calculation earlier can change scheduling and allocation. The accepted standalone symbol remains `func_80082930`; the app records the readable name `inflate_codes`.

## Pair the helper return contract with its comparison use

Another existing app agent matched the 135-instruction / 540-byte `func_80057B40`. Its accepted source changes the local declaration of `func_8000C9B0` from an `s16` return to `s32`, and writes both max comparisons as `r > max` instead of `max < r`.

Replaying the four combinations with the same source context and original compiler profile showed an interaction:

| Controlled trial | Score | Exact linked bytes |
| --- | ---: | --- |
| Starting draft | 60 | No |
| Corrected helper return width alone | 60 | No |
| Comparison spelling alone | 80 | No |
| Both changes | 0 | Yes |

A prototype repair can make a source-shape variant productive even when neither isolated trial improves the score. Test these small combinations against the actual caller and target; equivalent comparison spellings and narrower declarations are not interchangeable build inputs for this compiler.

## Volatile state updates: keep the mask and stores together

`func_8006F3C0` is 25 instructions / 100 bytes. The earlier draft truncated the final value to eight bits. The successful candidate preserves the `0x2044` mask and the verified placement of the local mask operation relative to the volatile halfword stores. Simplifying the expression or reordering stores by semantic intuition is not enough: compile and compare the resulting bytes.

See [func_8006F3C0.c](../src/code_8004BEB4/func_8006F3C0.c).

## Camera draft: narrow a helper return where its value is used

The 999-instruction `func_80011178` improved from score **790 to 730 to 490**, but remains unmatched. A pointer-lifetime experiment fixed its initial table/camera load ordering. Keeping `r` as a 32-bit helper return, with explicit `(s16)` narrowing at the subsequent `D0` arithmetic uses, fixed both call delay-slot schedules. The intervening halfword array store already performs the required narrowing.

Preserve the distinction between a helper's return width and the width needed at a particular use. Moving narrowing from the definition to the use can change register lifetimes without changing the intended value at that use. The saved draft is in [progress/best/func_80011178.c](../progress/best/func_80011178.c); it is not selected as matching C.

## Uncredited square-root lead

The live compiler settings for `func_8002E688` were not changed. A separate diagnostic profile adding `-ffast-math` to the original flags, as already used by other verified square-root functions in this repository, removes the library fallback and gets this draft to score **10 (99.8%)**. The normal app diagnostic confirmed two remaining floating-point register operands: the target's last multiply writes `$f2`, while the candidate writes `$f4`; the following truncation reads that result. This is **not an exact match** and contributes no progress.

Keep the multiline `if` / `else` form below when replaying the trial: it recovered a separate NOP difference. Recheck the source, header, compiler and ROM target together; the diagnostic profile is a hypothesis until the exact verdict and complete cartridge verification pass.

```c
s32 func_8002E688(s32 *arg0, s32 *arg1)
{
 f32 v[3]; f32 len; s32 n;
 v[0]=(f32)arg0[0]; v[1]=(f32)arg0[1]; v[2]=(f32)arg0[2];
 len=v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
 if(len!=0.0f) {
 n=(s32)__builtin_sqrtf(len);
 } else {
 n=0;
 }
 if(n==0)n=1;
 arg1[0]=(s32)(((f32)arg0[0]/(f32)n)*4096.0f);
 arg1[1]=(s32)(((f32)arg0[1]/(f32)n)*4096.0f);
 len=((f32)arg0[2]/(f32)n)*4096.0f;
arg1[2]=(s32)len;
 return n;
}
```

## `func_80016B3C`: scoped accumulators and consistent global identity (3 November)

Exact live and standalone result: 4,092 bytes / 1,023 instructions, KMC GCC 2.7.2
with bundled GNU as 2.6, `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.
Starting from score 550, block-local `t` in the distance calculation reached 480;
a separate local `t` in the brightness loop reached 440. A stray scheduling NOP
then shifted many later branches. The final fix declares `extern Game *D_800C7F84`
and uses it consistently for `gGame` and the visibility check, replacing a mixture
of byte-array-base-plus-offset access and a bare integer pointer. That source
change produced score 0 with unchanged flags, targets and verification rules.

An earlier colour-byte prefetch scored 80 but loaded it too early, so it was not
a match. The ten-minute app deep pass tested 202 candidates without improving 80;
more than 2,200 focused command-block permutations and many packing, width, helper,
formatting, copy and flag probes also failed. The final correction came from
checking the high-level global identity, not an increasingly elaborate packing
expression. A lower score was not the best seed for that correction. These are
controlled reconstruction choices, not proof of the original source spelling.

The final source was accepted by the normal running-app API (linked bytes and
instructions exact), independently integrated, and included in a complete
byte-identical cartridge rebuild. Twelve other concurrent new matches and all
current progress were saved with it. The last concurrent match, `func_80051D10`,
also passed its independent check and complete-cartridge comparison. Earlier selected C is retained.

## `func_80074BF8`: reuse a later temporary to avoid unwanted coalescing

The final accepted function is **567 instructions / 2,268 bytes**, using the
unchanged KMC GCC 2.7.2 profile `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.
The near-exact draft differed only in the source operand order of one `addu`:
the target required `$s0 = $t0 + $v0`, while the candidate emitted
`$s0 = $v0 + $t0`. Commutative equivalence is insufficient for a byte match.

A fresh subtotal and fresh destination preserved the expression's operand order,
but GCC's local allocator tied the dying subtotal to the result, assigning both
to `$s0`. Reusing the earlier display-handle variable avoided this tie, but moved
an earlier mask instruction ahead of an argument move. That alternate was useful
evidence even though its score was worse.

The successful source instead reuses `temp_s0_8`, which has a separate later
lifetime in the same function:

```c
base74 = D_800A17EA + sp10C;
temp_s0_8 = base74 + temp_s0_3;
/* Existing header draw and colour calls. */
temp_s0_4 = ((u32)(temp_s0_8 & 0xFFFF)) >> 1;
```

This preserves the subtotal in `$t0`, the call return in `$v0`, and the sum in
`$s0`, while retaining the original early instruction schedule. The normal app
API accepted score **0** with exact linked bytes and instructions; an independent
ROM-backed comparison also found **567 equal instructions and no differences**.
The standalone integration and complete byte-identical cartridge rebuild passed.
No target edits, inline assembly, fixed-register declarations or compiler-profile
changes were used.

For automatic repairs, retain alternatives that fix the residual operand pattern,
even when another part gets worse. When a fresh destination coalesces with the
wrong dying input, try a bounded set of compatible locals with genuinely separate
lifetimes. Check that their old values are dead and their later values are
redefined before use. Recompile the whole function and verify the complete build;
source-level equivalence and register-allocation reasoning do not prove a match.
These are measured reconstruction choices, not evidence of the original source
spelling.


### Exact controller update: copied values, allocation and debug boundaries (4 November 2026)

`func_800347A4` now matches all 529 instructions / 2,116 bytes through the live app
with the unchanged KMC GCC 2.7.2 profile (`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`).
No assembly, target bytes, shared header or compiler-profile edits were used.

Useful measured repairs were splitting scan-local nearest/index lifetimes, naming a
repeated distance load in the second scan, keeping the signed `/128` adjustment
explicit, sharing the switch increment tail, and separating a normalized divisor
from the predicate that reuses its former temporary. Statement boundaries around
the final divide also mattered: the compact form allowed an instruction into the
post-`mflo` gap; the separated form retained the target's two NOPs under `-g3`.
Preserve those line boundaries in matching source.

Installed-compiler diagnostics showed why a seemingly helpful shared tail changed
allocation: it reduced one variable's reference count enough to reorder allocation.
Several unsigned 32-bit zero identities preserve behavior and compile away while
affecting the legacy compiler's flow/allocation evidence. This is a controlled
compiler experiment, not a recommendation to add arbitrary padding or assume
weights determine every hard register.

The final two mismatches were `bgez`/`addiu` reading the original `a3` instead of
the already copied `v0`. Clearing the no-longer-needed nearest variable immediately
after copying it prevented that substitution; the dead clear disappeared and the
normal byte judge returned exact. This is safe here because that source value has
no further read before its independent redefinition; do not generalize the clear
without checking liveness, aliases and volatility.

A three-minute deep-permuter run at score 330 used 482 compiler invocations without
an improvement. Targeted source experiments reached zero afterwards. This is one
measured function, not a general model or token-cost comparison.
