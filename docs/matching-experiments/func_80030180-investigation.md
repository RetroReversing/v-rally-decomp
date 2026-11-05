# Coordinate interpolation with a 500-step interval

The previous score435 draft was invalid: __repair_addr was read uninitialized and the second coordinate loaded through *(u8 **)arg0 rather than *(u8 **)(arg0+0x54). A sound related-function transfer (denominator500) judged420 through normal API, still nonexact. Cleaner same420 research alternative SHA256 0802eb1468b0ed22a0a9b8e42e55b16d07752a0cc050f1ae9a2d24ef5331c74b removes unused locals and dead post-use assignment; Clang initialization checks pass, unlike original. 1000 guarded native candidates,176 helper manual trials,144 parent probes (including declaration duplicates) found no exact match. Residual register allocation and arithmetic scheduling remain; no target/profile/ABI/judge changes. OPEN and revisitable; not selected as standalone C. Clean source: docs/matching-experiments/func_80030180-nonmatching-alternative.c.

## November 5 revisit: index lifetimes and coordinate views

A fresh frozen-input run tested 80 unique structural candidates: 48 index/neighbor lifetime and aggregate-delta forms, followed by 32 point-unit indexing and branch-placement forms. None improved the sound score420 draft or produced an exact match. The pinned profile remained `gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3`; no target, ABI or compiler selection changed. Initialization checks reported no failures.

The sound draft remains SHA256 `0802eb1468b0ed22a0a9b8e42e55b16d07752a0cc050f1ae9a2d24ef5331c74b`. Its linked body is480 bytes against476 target bytes; this is still a nonmatch, not an accepted source correction. Frozen inputs SHA256: `2effd9cc3bcb5ea0fc1fe6087b73a7014f763c200d2537cbb2b001738740d316`. Private evidence stays outside this repository. These negative families should not be repeated without a new compiler or lifetime hypothesis. The function remains OPEN and eligible for future work.

## Deeper structural replay

A later fresh investigation compiled 242 cases (217 distinct sources within that
matrix) and transferred 59 representative cases to the denominator-50 twin. None
matched; best remained 420. The cases cover genuine coordinate arrays, byte versus
halfword indexing, bound table pointers, separate neighbor/index lifetimes, signed
coordinate alternatives and explicit incoming narrowing. All 242 passed an
initialization screen and 100 sampled functional cases each. These screens are
additional evidence, not a MIPS equivalence or whole-game aliasing proof.

The inverse routine and actual caller support six-byte three-halfword coordinates
and a genuine `s16[3]` output. The denominator-50 twin is itself OPEN and therefore
is not a verified source donor. The residual is still allocation/scheduling and an
extra instruction. Compiler diagnostics were replayed with a frozen judge; no live
source, profile or accepted count changed. These negative families should be retained
to avoid repeating expensive searches without a new hypothesis.


## Compatible signed halfword-unit candidate — 5 November 2026

The normal app judge now selects **OPEN 357**, improved from 420, SHA256
`42937dab3c761235e2543330a631a9b0ffe2e19dc06e7e487998ec234b97f9c6`.
Parent ordinary linked reproduction agrees; all 2,070 matched sources remain
unchanged. This is a 480-byte nonmatching candidate against a 476-byte target,
with an extra move and larger frame, not a new matched function.

The public `void *` formal matches the actual selected caller `func_80033E34`;
a genuinely consumed byte-base local preserves byte arithmetic. The raw direct
call scan finds only that caller (site 0x80033ECC), not a proof about arbitrary
indirect calls. Typed prototype and initialization checks pass. Per-use casts
score 807; a compatible byte-address baseline remains 420.

Signed halfword-unit coordinate access removes a retained byte-offset lifetime.
Both relevant offsets are six times an index, so signed division by two preserves
negative even offsets too, within the original defined signed-arithmetic domain.
Unsigned/shift controls scoring 355 are not selected: they need additional domain
proof. New accessor/component helpers score 525–2145 and actual index-lifetime
representations 815/945. Ordinary and diagnostic canonical linked bytes agree;
ELF metadata differs. Preferred linked SHA256 is
`50aa274dfa9ba1d4176136b0f248b0761b66217b271ce41f2c61e80713b69de8`.

Actual decoded indices are not globally proven overflow-free. The backing
coordinate storage must be a suitably aligned, sufficiently large u16 array
object; a cast alone does not establish this. These are explicit defined-domain
and storage assumptions, not a whole-game C proof. The real caller's three-element
output array supplies its output extent. An automatic byte-to-element rewrite
would need those type/alignment/bounds/divisibility facts before being generalized.
Keep the function open and preserve these controls instead of repeating prior
formatting, profile and native sweeps.
