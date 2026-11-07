# Current sibling transfer — 6 November 2026

The best draft now scores **107**, improved from 177. A transfer of the current
`func_8002FFA4` representation changes the five interpolation constants from 50
to 500 and retains this function's declared `s16 *` output. Its byte-addressed
coordinate accesses and six-byte output preserve the existing defined storage
and arithmetic assumptions. This is a draft improvement, not an exact match.

Pinned KMC GCC 2.7.2, `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`, produces 476 bytes
with ordinary/diagnostic parity, SHA-256
`4e2ec3233b8a89afc8a1a973687bfd2c5524e954ef962f3bd40b66a124e1beee`.
The first mismatch remains the 32-byte frame versus the target's eight bytes;
early register allocation also differs. The normal live judge reproduced 107
and saved it as the best draft. All 2,077 selected source hashes and compiler
profiles were preserved before and after judging and the complete portable save.
No selected cartridge source changed or new exact-match claim was made.

Source SHA-256:
`d7be21356dd4e1ffcfb94fb85c201ccd389a28d8613e6a1db8027325ade8c9d2`.
The available 465 hydrated attempts and private source inventory contained no
token-identical transfer. Older measurements below remain historical evidence;
they do not describe the new best draft. Private receipts are retained in
`current-sibling-transfer-nov6`.

## Bounded search from the improved 107 draft

The new root received one separate 1,000-emission local search. Original,
macro-expanded and AST-printed C first reproduced the same 107/476-byte output
in ordinary and diagnostic builds. Full-translation-unit type information and
positive/negative guard controls were checked before generation.

Outcomes: 20 source duplicates, 437 guard rejections, 58 preflight rejections,
291 linked duplicates and 194 new linked results. Thus 485 generated candidates
compiled; none improved 107 or matched. The best newly scored result was 112.
The single generator completed its fixed quota and was reaped, with explicit
time and memory limits and no extension. Historical byte deduplication covers
only available receipts; these guards are conservative screens, not a complete
semantic proof. All 2,077 selected sources/profiles and the focal draft remained
unchanged. Private `current107-native1000-nov6` retains the terminal accounting.

Two controlled compositions also failed: replacing the known coordinate index
with literal 1 scored 327 with a 24-byte frame; simplifying the signed byte
address using the proven even point offset scored 480 with the target's
eight-byte frame. Both had ordinary/diagnostic parity. Fixing the frame alone
therefore did not repair the body; neither was adopted.

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


## 7 November: close the literal/direct-byte interaction

A fresh read-only audit confirmed the same current107 source and468 hydrated
attempts. Its completed exposed1,000-candidate search already covered COORD
arithmetic; macro visibility was not a new search opportunity.

The previously prepared but uncompiled direct-byteB was then tested as one
bounded interaction control, not as a newly established compiler mechanism.
It combines the proven-even signed byte-address formula with literal1 in the
coordinate producer, retaining the genuine `d[new_var]` consumer. Existing valid
storage, aligned halfword access and representable arithmetic premises remain;
no new type, ABI, padding, alias assertion or memory operation was introduced.
Source SHA-256:
`69dba155aa4197d6af64501bdb7329fb2c158927086f9f9b726ec587bcfaae94`.

Exactly two compiler calls produced ordinary/diagnostic480/480bytes/frame8.
The linked output is byte-identical to the earlier direct-byteA, SHA-256
`794fa0ca5e422ac7c6c8f7cf6156f170272bf0e582519eb9b7dfb547b941ddc5`.
The additional literal propagation therefore has no machine-code effect in
this combination. This closes the outstanding interaction without a broader
literal/scope/profile or native sweep. Both20-second/2GiB aggregate watchdogs
ended normally with no errors or surviving owned processes. Full focal and
selected-state snapshots compare equal; all2,077 selected matches/profiles and
OPEN107 remain unchanged. Private receipts are retained in
`direct-byte-literal-interaction-nov7`; no new cartridge progress is claimed.


## November 7: named point fields and reload placement

Loader-backed signed16 x/y/z records permit named-field controls without
flattening scalar members into a fictitious halfword array. Two finite controls
retain the original byte-offset branch arithmetic and else-do scope.

Caching named pa/pb fields only for the pre-output differences scores1327 on
452 bytes/frame16. It eliminates two intermediate USE homes, but also eliminates
actual target base/address reloads and extends pointer lifetimes. The output
COORD expression still leaves one temporary home. Sourcecdcdc4ce2164954226b724740150016aeee696f3d5d50af50cb8b0a6cd2eb6ca
links to016a270e238e62777a854796d00fc83aa7d2148ac04095e671bf3227000230a7.

A second control changes only the seven COORD producers into fresh named-field
reads at their original read points, preserving every later reload/store and
the real d[new_var] consumer. Its initial RTL has MEM_IN_STRUCT on these reads,
unlike the old raw direct-byte form. The compiler source consults that flag in
CSE and scheduling, so a measured interaction control was warranted. Nonetheless,
ordinary/diagnostic and independent relinks produce exactly the earlier
direct-byteA/B output: score480,480 bytes/frame8, SHA256
794fa0ca5e422ac7c6c8f7cf6156f170272bf0e582519eb9b7dfb547b941ddc5.
A real initial-RTL distinction need not change final machine code.

Exactly four compiler calls completed under20-second/2GiB aggregate watchdogs,
with independent relinks, no surviving workers and unchanged468 hydrated attempts,
full focal inputs and all2,077 selected sources/profiles. Preserve OPEN107; no
cartridge or new-match claim. Private current107-phase-nov7 and
current107-fresh-field-nov7 reports retain complete provenance and receipts.

## November 7: isolate signed-division and component frame reservations

Fresh read-only evidence preserves current107 source d7be2135,468 hydrated
attempts and all2,078 selected sources/effective profiles. The sole observed
direct caller forwards a signed16 coefficient without proving nonnegativity.
The target uses signed interpolation arithmetic and has no missing argument mask;
the new loop-argument-mask repair is not justified here.

Every coordinate byte offset is six times an index on the existing defined
arithmetic domain. Replacing only COORD's signed division by two with arithmetic
right shift therefore preserves even offsets, including negative ones, on the
actual MIPS implementation. It adds no unsigned-domain assumption, array bounds
or memory operation. The older array-index shift control used a different source
root and interface and did not cover this exact composition.

| Controlled source change | Score | Linked bytes | Frame | Remaining late USEs |
| --- | ---: | ---: | ---: | ---: |
| Current selected draft | 107 | 476 | 32 | 3 |
| Division by two to arithmetic right shift | 107 | 476 | 16 | 1 |
| Shift plus literal1 only in the known component address | 325 | 484 | 8 | 0 |

The first control removes the two signed-division correction reservations while
retaining the other body instructions. Its source SHA256 is
`66c40ed8931fbf59afdc7ab8bdc3805e42d5b5a871328b65eb579a307d06988c`,
linked SHA256 `301904c6ae30e457fd903304cf078c1b700725b84353c541258f4fb7116727c4`.
The remaining initial-RTL dynamic component addition explains the last
reservation. The second control replaces only COORD(b,new_var) with COORD(b,1),
retaining new_var=1 and its real d[new_var] output consumer. Source SHA256
`fa8781e432f32c928d6f89105438a21b69203b3d53f3fdf1f26809527dd52cee`,
linked SHA256 `0157d153cf02f8525324c089ac87076a583dd6e1449d37f95ed4691803b8b53e`.
It recovers the target frame but worsens the body by eight bytes. Frame identity
alone is not an exact match or a reason to replace the live draft.

Exactly four period compiler calls ran with the unchanged KMC2.7.2 profile,
ordinary/diagnostic parity and independent saved-object relinks. No Clang or
native generation ran. Aggregate/orphan-aware watchdogs completed normally;
all dependency/tool pins, full focal inputs,468 attempts and2,078 selected
sources/profiles remain unchanged. No live adoption or new match is claimed.
Private domain-revisit-nov7 retains both controls, full RTL and receipts. The
frame16 tie and frame8 research alternative remain private pending a grounded
follow-up; no replacement quota was automatically generated.
