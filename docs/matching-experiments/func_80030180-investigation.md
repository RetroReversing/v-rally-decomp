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
