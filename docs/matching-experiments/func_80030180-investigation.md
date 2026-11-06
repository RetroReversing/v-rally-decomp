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

## November 6: combine move and local frame storage

Fresh ordinary/-da full linked parity reproduces compatible357. The earliest
residual move is combine instruction138: repeated signed byte-offset division
by two and scale-back arithmetic becomes a separate pseudo copy. It survives
scheduling/local allocation; global allocation assigns the pair to v1/a1.
Three genuine once-bound signed quotient controls emit identical357 linked code;
consuming the original offsets as halfword-index phase variables scores1215.
Previously tested signed index*3 ownership815/945 forms were found and not repeated.

The saved assembly diagnostic describes the24-byte frame as local vars24,
register saves0, outgoing args0 and extra0. It excludes an outgoing-call-area
explanation. A reference allocator suggests spill reservation, but the precise
extra slot cause is not proven without the pinned allocator's actual decision.
No exact/better source is found, no compiler profile changes, and all existing
signed-negative-even, array extent, alignment and effective-type assumptions stay
explicit. The parent is separately checking historical seed provenance before
any newly authorized bounded native search; this phase report does not claim a
native result or a new accepted function.


## November 6: current177 provenance and component phase controls

The selected draft is now OPEN177, not the historical357 above: source SHA256
`e3ff993950c6a02527594ca6e606c459599e9ea6433534e90db5596401193b87`.
It originated as native357 candidate120 and retains a genuine component index
shared by a coordinate macro and local array read. Ordinary and diagnostic
476-byte output agree, SHA256
`ee856cf06f933c466971785191ad79d76115d8a2fefa203708fb1ab8cd986e3f`.
All actual delta stack accesses remain at0/2/4. The current frame is32 versus
8 in the target; compiler-added late memory USEs occupy12/20/28, not real loads
or stores in those locations. The earlier literal ablation397 retains24 bytes
and two such USEs. This associates temporary reservation with source expression
handling without proving the exact allocator routine responsible.

Two bounded same-layout controls isolate constant propagation from initializer
placement. Declaring the real component as const int initialized to1 produces
397/484bytes/frame24, exactly the prior literal-ablation bytes. Plain int with
that same entry initializer produces1202/512bytes/frame24 and retains indexed
stack-address computation. Both have full ordinary/diagnostic parity; neither
improves177. Exactly two ordinary and two diagnostic compiler calls. No new
selected source, ABI, compiler profile or dummy operation was introduced.

Provenance audit distinguishes the completed native357 lane from an actual177
seed. Each batch began357, with evolving native variants within the batch.
Its saved parser input still contains COORD calls: the arguments are mutable,
but the macro's address arithmetic is hidden from native AST rewrites. Historical
manual address/unit/helper controls overlap many expanded forms. A missing
current177/exposed lane alone is not proof of a new compiler mechanism or a
claim of success. Private phase-audit-nov6 reports retain full comparisons and
source/target/header/profile/symbol/prelude binding checks.


The subsequent single unsigned-coordinate model retains the real captured
component and all original accesses. For even signed byte offsets x, unsigned
halfword division followed by scale-back recovers x+2c modulo2^32; the final
pinned s32 conversion recovers the signed byte displacement before pointer
arithmetic. This does not use huge unsigned array indexing or convert the base
pointer to an integer. Representable final displacement, valid aligned backing
storage and the pinned signed conversion remain explicit premises.
Ordinary/diagnostic output is177/476bytes/frame16, SHA256
`df94a93f58700c59ccf6f288b63b8a2d02f2d266035269f45f12013d29e5589d`.
Only the two SP-adjustment words differ from the selected177 output; all other
468 bytes are identical. It is a structural tie, not a selected improvement.

Two single-use attribution controls then isolate the last reservation. Propagate
component1 only in the coordinate expression, retaining its real delta-array use:
395/484bytes/frame8, no late USE. Propagate only in the delta read, retaining its
coordinate use:177/476bytes/frame16, identical to the unsigned model. All four
compiler calls have full ordinary/diagnostic parity. This directly identifies
the coordinate intermediate as the remaining temporary reservation; removing
it also changes allocation/body length adversely, so it does not solve the match.
No broader literal/type/scope sweep followed.

Before the newly authorized bounded native run, actual pinned preprocessing
exposes all COORD arithmetic. Original, physical-layout exposed and unmodified
native-printer source have the same full-TU AST. Both new baseline forms have
ordinary/diagnostic177/476bytes/frame32 and exactly the original linked bytes.
No lexical layout backport is required. The run uses this exposed original177,
not the unsigned structural tie; results are recorded separately on completion.


## Exposed current177 native lane completed

The single independent run completed its exact1000 raw-emission quota over16
batches. Each batch starts the same frozen exposed original177; ordinary native
within-batch KEEP evolution is recorded. Six bounded source-rewrite methods were
used without an external-type, ABI, qualifier or fixed-register search. All raw
emissions and16 done receipts reconcile. Counts:660 compiler attempts,658 linked
numeric scores,272 guard rejects,57 preflight rejects and11 duplicates. Two
compiled candidates require the unsupported __divdi3 helper and are symbol rejects,
not numeric negative judgments. No ordinary compiler failures or exact matches.
The best remains177; no candidate improved it. Ten frame8 cases retain complete
source/object/linked bytes/diff/stack references, but none improves the body.

All seven source/header/profile/target/assembly/symbol/prelude input groups remain
unchanged after the run. It was not restarted or extended, and no candidate was
promoted as the next batch seed. This is bounded coverage, not proof that every
valid source transformation has been exhausted. Private exposed177-lane receipts
and final input guards remain outside the repository.


The final single declaration-only s16 component control is also negative.
Value1, assignment position and both real consumers remain unchanged. Initial
RTL now represents the component as HI and explicitly promotes it to SI at
both consumers; CSE removes those promotions. Ordinary/diagnostic476 linked
bytes are exactly the selected177 bytes, frame32 with the same three late USEs.
One ordinary and one diagnostic compile close this measured mode control.
No aliases, QI/signedness matrix, unsigned composition or extra native quota
followed. The selected draft remains OPEN177; all2071 matched sources/profiles
are preserved. Private NARROW-ELIGIBILITY.md retains the range and phase evidence.
