# Packed record decoding investigation

Legacy score1465 draft is not sound: reads new_var5 uninitialized, doubles the sp14 base through u16 pointer arithmetic, overwrites the selector and multiplies the original frame argument by four inside each iteration. Clean baseline2524 fixes these and removes unused volatile. Explicit invariant frame_record capture improves to2259, still nonexact, SHA256 0639d8615e7f6fbc198513a9aab3280e0e8caf97f669698a4ebd282f8a7b487f. See docs/matching-experiments/func_8006C024-nonmatching-alternative.c. Readable alternative with inherited redundant do scopes removed scores2454. 1000 native candidates plus targeted probes (including51 parent judgments) found no exact match. Lower2031 candidate rejected for artificial duplicated identical branches. Remaining issue: invariant frame<<6 occupies fp and frame_record spills, unlike target; scalar phase/lifetime and hoist/type probes did not fix register allocation/scheduling. Other-region machine draft transfers back to same7292 baseline, not a hidden matched donor. OPEN and revisitable; no target/profile/ABI/judge edits or selected standalone C.


## Current contract and source correction — 5 November 2026

The normal app review now selects corrected **OPEN 2454**, source SHA256
`6f08b04ceec49aab7689819f5e056d14f87ba2eb1af834b5ce9218dd2a86d842`.
This replaces the historical 1465 draft's uninitialized selector, double-scaled
halfword pointer and selector/channel mutations. It agrees with the current
selected byte-input selector and integer-input record helper. The modulo-u32
numerator is retained. A parent ordinary compile and linked comparison reproduced
2454; all 2,070 matched source files remain unchanged. This is a provisional
nonmatching draft, not a new cartridge match. Earlier scores above are historical
controls under their captured inputs, not freshly measured competing seeds.

Thirty-six new meaningful record/slot/driver layout, loop-backedge, lifetime and
selector controls found no exact match or improvement. GCC's loop dump identifies
an invariant channel-shift hoist. A genuine goto backedge prevents it and restores
the target's 0x50 frame, but scores 2650; selector coalescing scores 2575. Diagnostic
and ordinary canonical linked output agree despite different raw ELF metadata.
Frame size alone is not an acceptance criterion.

The sole raw caller loops over eight cars and channels below a record count whose
actual upper bound remains unproven. Aligned storage, raw global/effective-type
representations and a nonzero divisor remain runtime preconditions. The byte
selector and three iterations bound the floating conversion to finite 0..1150.5;
this is not a proof of every game's storage declaration. Keep the function open.
The next useful hypothesis concerns real channel/iteration interference under
the backedge, rather than another copy-width or layout sweep.


## November 6: grounded three-phase register reuse

A fresh current-contract freeze reproduces OPEN2454 with full ordinary/-da
linked parity. Compiler dumps locate the channel shift in ordinary CSE inside
the conditional body; loop optimization moves insn222 to541 before the loop and
shares371. This is earlier than final register allocation.

Four new controls reuse one genuine value across initial channel, loop index
and signed-delta phases: SI structured4009, SI goto3205, HI structured3033 and
HI goto2635. None improves2454, and none is adopted. Hydrated437 saved attempts
were checked; no native, flag or arbitrary declaration sweep was run. No new
positive automated repair follows from these controls. Do not repeat this phase
copy family without new source/domain evidence. Existing runtime bounds and
raw-storage assumptions remain explicit. Private receipts: current-nov6/REPORT.md.


## November 6: consumed offset and shared table staging (OPEN1848)

A genuine consumed record-offset local improved2454 to2238. The byte selector
bounds its shift to0..16320. Removing both identical branch-tail multiplications
and evaluating once at their common successor improved2238 to2043. Capturing
the actual char-array table base before use then improved2043 to1848. Existing
raw-storage, alignment, effective-type and nonzero-divisor premises still apply.
This is a retained unmatched draft, not an additional exact match.

Parent ordinary linking independently reproduced1848; ordinary/-da agree on976
linked bytes, SHA256
`49ef27fc54e7c9d887c939136d0672dcba160eedc3a6d5935b4d013fed9c1f92`.
Source SHA256:
`d5f948d6b4dbfe727396e6d8bedce0963fd988d38c3f3b58c6c1ff266a56a9e9`.
Normal app compilation retained this source; all2071 selected matches remain.

The initial current-source native lane persisted549 candidates, including one
interrupted in-flight candidate, and linked224. Two empty-do scaffolding
candidates were excluded, leaving222 audited linked candidates.576 outputs were
requested;27 unobserved outputs are not counted as received. The terminated lane
was not restarted. A separate refinement from2238 completed451 received and214
linked comparisons, with no exact match. A candidate retaining an overwritten
duplicate assignment was rejected. Six grounded controls yielded1848.

App PR651 rejects newly introduced literal-zero empty-do scaffolding before
random/deep judging, preserving existing wrappers, actual nonempty blocks and
dynamic waits. It is a bounded source-shape guard, not a C equivalence checker.
Private evidence: current-nov6-native and refinement-2238 under func8006C024.


## November 6: diagnose the accepted1848 revision

For source d5f948d6, the older2454 channel-shift hoist is no longer present.
Loop optimization hoists the two table bases and byte constant1. Global allocation
spills frame_record, with an88-byte frame versus target80. This is an observation,
not a proven recipe for restoring the target allocation. Removing/delaying the
consumed offset scores2054; phase sharing2913, decoded consolidation2473/4213,
and actual field-pointer capture1948 are negative controls.

An explicit narrowing of the already0..15 high nibble scores1733, but remains
review-only and is not retained: a genuine consumed byte-local control scores2193,
so the cast alone does not establish recovered original storage. No padding,
dead assignments or identity-only scheduling rule is introduced. The accepted
unmatched draft remains1848. No further native quota ran. Evidence is bound to
the exact source in private diagnose-1848/RESULT.json.

App PR652 now generates the genuine common-tail edit from the frozen2238 input,
independently reproducing2043;125 focused tests passed. This is not a new exact
match and does not attribute the separate table capture to the same family.


## November 6: byte-phase review and retained1733 draft

The earlier1733 review-only disposition is superseded by a source-level audit.
The conversion `(u8)(temp_t0 >> 4)` occurs at the actual unsigned-byte packed
field extraction. The load is0..255, the unsigned shift produces0..15, and the
conversion expresses the byte-sized decoded value before widening into the
existing signed/unsigned integer carriers. Both existing assignments and all
validity, channel-bit and table-offset consumers remain. No read, call, local,
dead store or control operation is added. This is coherent reconstructed C,
not proof of the unique original type. A conversion is not dummy scaffolding
merely because the inferred input range makes it value-preserving.

Whole-function byte declarations scored2133/2008; a separate byte local2193
and storage-first splitting4358 were negative. Those different models do not
invalidate the meaningful conversion at the actual decoding expression.
Parent independently reproduced1733; ordinary/-da agree on980 linked bytes,
SHA256 dd2cc3353257d93b212c98bbc1b96b78358044ee9ecf5667511b81a779e3e9b8.
Source SHA256 8c509f910f6587fb430aa8c28e3685c27f0102ab81f39fb0ae1328703793808c.
Normal MCP compilation retained it as an OPEN draft, preserving all2071 matched
sources. This is not an exact match or complete-cartridge acceptance. Existing
storage and arithmetic premises remain unchanged. Private byte-phase-review/
RESULT.json retains the range/evaluation audit and fresh parity evidence.


## November 6: focused1733 search and automatic repair

One newly frozen1733 lane completed normally:256 requested and received, four
completion receipts,179 linked, no exact match or improvement. The seven fixed
methods were expression temporaries, statement reorder, assignment splitting,
factor multiplication/shift, commutative order and real block insertion. Current
shared safety guards ran before compilation; no declaration/type/flag methods
or replacement quota were used. Private native-1733-focused/RESULT.json retains
lineage and raw accounting.

A printed baseline scores1833. Restoring its original conversion statement
boundary recovers1733. The best real field-pointer staging candidate similarly
recovers only1733 after that one boundary restoration. This is a measured
formatting effect, not a general printer limitation or a hidden improvement.

App PR653 adds the bounded decoded_byte_normalization local/deep hypothesis:
the generated edit independently reproduces1848 to1733 from the copied witness.
It requires a known32-bit C profile, a visible unsigned-byte load, unchanged
unescaped local range and existing chained scalar assignments. It adds no reads,
locals, assignments or control.124 focused tests and whole Ruff passed, including
a host-C exhaustive byte/shift equivalence check. No new exact match is claimed.

## November 6: repair composition coverage

The current1733 source already combines the shared multiplication, real table
capture and byte-decoding conversion. Both current bounded generators emit zero
further candidates on this source; there was no missing broad composition.
One distinct placement from the earlier common-tail generator remained untested:
the existing consumed multiplication before, rather than after, the independent
literal assignment. It was absent from all440 hydrated attempt sources and the
private C inventory. Ordinary/diagnostic compilation produces the same980 linked
bytes, score1733 and SHA256dd2cc3353257d93b212c98bbc1b96b78358044ee9ecf5667511b81a779e3e9b8.
No new source, match or automatic family was accepted. This closes that specific
composition hypothesis without another native/profile/type sweep. Private
composition-audit-nov6/REPORT.md and history/before-literal receipts retain the
fresh context/profile/target/symbol checks.


## November 6: remaining invariant lifetimes and byte-return declaration

A fresh source-bound audit locates the current remaining invariant motion in the
two actual table bases and output-byte constant 1. These conflict with the
frame-record pointer, which spills; the frame is 88 bytes rather than the target's
80. This is distinct from the old 2454 channel-shift diagnosis. Existing direct
unsigned floating conversion, channel/index reuse and three-phase/backedge
controls already cover the obvious hypotheses. No further C024 compiler or
native quota was justified, and the selected draft remains 1733.

The audit found a separate real declaration mismatch: the selected byte-input
selector returns u8, while caller func_8006DDD8 declared an s32 return. Changing
only that declaration to u8 preserves all 1,072 target bytes in ordinary and
diagnostic builds (SHA256 e207bbb08f8da14370e704f4dc25f3ba253cd9449ea3f8ae073c363845fb58e2).
The parent independently verified the full 12,582,912-byte cartridge, with the
other 2,070 selected objects and all 2,071 compiler profiles preserved. Normal
saved-source verification accepted the correction. This repairs an existing
match's C interface; it is not an additional function match or a C024 repair.
Private evidence is retained in cause-nov6/ddd8 and ddd8-parent-gate.


## November 6: shared tail outside both decoder arms

The current1733 source has no macro calls, so the nearby decoder's opaque-macro
type eligibility gap does not transfer. All440 hydrated attempts and2557 available
private C files were audited for the actual shared-tail scope. Prior renamed
join/tail labels remain nested in the second successful decoder arm; outer labels
only govern loop/backedge control. None places the four shared tail statements
after both arms.

One new source does exactly that, replacing each invalid path with a jump to the
unchanged increment. Both successful paths retain their original reads, BF30
call, writes, sign handling and definitions of var_s1/var_a2/var_s0 before the
tail. The first/second path's different 0x34/0x38 store order is preserved.
Floating conversion, declaration types, u8 loop counter, increment and loop test
are unchanged. Parent independently reviewed the source diff and path coverage.

Exactly two bounded calls, ordinary and diagnostic, produce identical current
bytes: score1733,980bytes, SHA256
`dd2cc3353257d93b212c98bbc1b96b78358044ee9ecf5667511b81a779e3e9b8`.
The same LOOP invariants remain: table6E77, table6E26 and QI literal1. Moving this
shared tail therefore does not resolve the invariant lifetimes or frame spill.
No candidate was adopted, and no random lane or additional compiler test ran.
A proposed common char-pointer anchor is textually absent from history, but
current RTL already models the bases as CONST(symbol+offset); there is no new
phase mechanism justifying another equivalent constant-address spelling.

Fresh before/after captures preserve all2077 matched full sources/profiles,
complete focal inputs and440 hydrated attempt records. Private
current1733-structure-nov6 retains shared-tail.c/diff, result.json, RTL, source
path proof and preservation receipts. No live state or runtime was changed.


## November 7: current-root lifetime composition (private1715)

A fresh read-only audit binds current1733 source8c509f91,440 hydrated attempts,
and all2077 selected full sources/effective profiles. Installed cc1 disassembly
confirms loop motion runs before the strength-reduction flag is consulted; the
actual39-option table has no selective loop-motion switch. Current-root native
coverage is256 emissions/179 linked candidates, not the older1000-emission root.

The previous hoist explanation needs qualification: table pseudos140/156 and
literal188 already have REG_EQUIV constants and are rematerialized, not saved
register occupants. The real extra saved carrier is the mode<<6 offset computed
before the decoder call. One scope around the final genuine store raises the
record pointer's priority but still spills it (1838). Moving the pure bounded
offset after the call removes that carrier, but loop optimization then hoists
mode<<6 into fp (1939). Both are negative, ordinary/diagnostic byte-identical.

Combining the delayed offset with the already proven equivalent goto backedge
on this actual current root prevents that motion, recovers target80-byte frame,
960-byte output and fp record pointer, but reverses iterator/mode registers
(1765). One single-execution scope around the existing increment raises the
iterator's measured references6→8, priority662→1325 above mode765. This recovers
all target saved-register roles and improves the score to1715. Ordinary/-da and
independent raw relink agree, SHA256
 d81931bcc6aea5910edc72a938ac186c0142502cfcfa1570144af0902bc2e5ab.
Source SHA2569f7cd6b0e5db777975887833b89983acadba4befe09489b3ea17b559ad31c32d.
This remains nonmatching:57 advisory register rows and other operand/scheduling
issues remain. Existing app loop_weight_scope can produce the increment scope;
this is a measured composition, not proof of a new repair family.

A fifth conversion-preserving index/delta phase reuse worsens the result to2150,
956bytes. Its longer merged lifetime changes interference; keep1715 privately.
Ten individually authorized compiler calls total, ordinary/diagnostic pairs,
20-second/2GiB aggregate owned-process guards; no random generation or live writes
by the helper. Parent normal app retention is a separate operation, not yet
claimed completed here. No exact match, selected standalone C or cartridge claim.
Private current1733-invariant-nov7 retains source/effects reviews, phase dumps,
raw objects, independently relinked bodies and preservation/terminal receipts.

## 7 November: remove a redundant consumed selector alias

The normal app judge retained the earlier1715 draft. A fresh read-only audit
hydrated441 attempts and identified a local/global source lifetime split:
`temp_s5` was assigned once and then copied into a separate same-type `s32`
local. The original remained read by a floating conversion, while the copy
served two later arithmetic uses. The compiler retained the copy and locally
allocated the first pseudo to v0 before moving it into global s5.

Deleting only the redundant declaration and assignment, and replacing the two
later uses with the unchanged original, yields1700/956 bytes, frame80. The
selector becomes one global pseudo (five references, lifetime168, two crossed
calls) assigned directly to s5; the extra register move disappears. Actual shared
header/profile ordinary and diagnostic builds independently relink identically:
SHA-256 `23d669f77eadaeea39d9e333aef312ae70c951d69d1e4e3fc84150454fb95304`.
The source hash is
`41e45e53829b102b0aae06bede6b927f36687ec6764ad52dea3046bf9e5d4ea1`.

The normal live judge also retained1700 and a fresh portable snapshot includes
it. All2,077 selected source hashes and effective profiles remain unchanged.
This is an improvement, not an exact match; mode-register copies, table commoning
and local output-address scheduling still differ. Exactly two bounded compiler
calls; no surviving processes. Private receipts: `current1715-phase-nov7`.

Existing non-overlapping integer lifetime merges do not directly cover this
case: the original still has a read after the copy assignment. A reusable alias
removal would need to prove same types, value equality and definite assignment
on every relevant CFG edge, with no intervening source writes, escaping storage,
shadowing or macro effects; textual substitution alone is insufficient.

## 7 November: mode/index phase sharing is rescheduled before the call

On the retained1700 draft, one control places the initial masked mode in the
existing later-loop index local, passes it unchanged to `func_8006B9E0`, then
copies it into the persistent mode local immediately afterward. The two same-type
locals have disjoint intended source phases; the index is overwritten before
its first loop consumer. No call, access, arithmetic value or ABI is changed.

Result1915/960 bytes, frame80, paired ordinary/diagnostic and independent relink
SHA-256 `0d4c7b83bcd297bca47f00f420599b3acbde44ef54f04e69b8790aaa5249add3`.
The initial mode does occupy s0 and a real s4 copy exists. However first scheduling
hoists that copy before the first call, while first CSE reuses the initial index
pseudo for frame-offset calculation. Target register roles alone do not establish
the required copy order. Keep1700. Two bounded compiler calls; all442 hydrated
attempts and2,077 selected source hashes/profiles remain unchanged. Private
receipts: `current1700-phase-nov7`.

### Automatic alias removal available on app main

RetroReversing/decompdecomp [PR #749](https://github.com/RetroReversing/decompdecomp/pull/749)
adds `cfg_equal_value_alias`, reproducing exactly the reviewed1715→1700 source
and the independently linked956-byte output. It uses bounded must-equal and
must-initialization facts, visible ordinary integer types and conservative
context/escape checks. The shared pipeline proposes at most four candidates and
the normal judge remains mandatory. Synthetic/integration coverage passes137
tests; this does not claim a new exact function or general proof for arbitrary C.
The separately built shareable macOS app includes the change at4e565105; the
running dev app has not been updated or restarted by this change.


## November 7: call-boundary dependency audit

Fresh strict read-only capture retains OPEN1700, all442 hydrated attempts
(376 distinct sources), and all2,078 selected sources/effective profiles. The
actual `u8 func_8006B9E0(u8,u8)` return is consumed as the selector; it cannot
be replaced by a fictional void call or by returning the input mode.

The existing1915 control already has a post-call mode copy in initial RTL
(call43, selector capture45/46, mode copy49). First scheduling moves49 before43.
Actual GCC `sched.c`1730 adds a last-call dependency to a pseudo destination
only when `reg_n_calls_crossed` is zero; the analogous read rule is at1889.
This persistent mode already crosses later calls. A scalar inline wrapper's
ordinary argument/result remapping (`integrate.c`1545–1632) therefore does not
provide the missing dependency. No wrapper compile was justified, and no
artificial barrier, extra output storage or ABI change was introduced.

A bounded mnemonic screen of12,061 other-project functions of720–1200bytes
finds only two high-similarity regional drafts, both unmatched:960-byte
`func_8006C954` at7272 and1036-byte `func_8006C374` at8149. The same-shape
regional machine transfer was already negative in earlier work. This is not
an exhaustive semantic donor search. No new candidate, compiler, Clang or
generator calls followed. Complete before/after frozen inputs agree; no live
claim or write. Private evidence: `call-return-audit-nov7/REPORT.md` and
`preservation.json`. Keep1700 and seek a different causal mechanism.


## November 7: current-root repair coverage and scheduling priorities

Eight bounded pure shared generators from app main d978ff39 produced16 source
variants: eight phase-lifetime, seven integer-lifetime and one conversion-tail
candidate. Five other generators produced none. All16 are token-new in the
bounded442-attempt plus2,576-private-source inventory; novelty alone does not
establish a repair. The conversion wrapper covers an already matching trunc/mfc1
pair. The local phase merges have no demonstrated connection to the remaining
mode-copy/output-address mismatches. None was compiled or adopted.

A separate source-only proposal on the retained1915 control moves the existing
selector-dependent `temp_fs1` setup immediately after the real selector call,
before the mode copy. It crosses no call or memory write and changes no load
value. The exact composition was absent from3,018 bounded history/source records.
Source SHA-256:
`9220fd71d3e3b80e755b556d71de8a78c3b4997231106231c1e37c970802c2bd`.
It remains an untested proposal, not a negative compiler result.

Retained scheduling evidence explains why this is not a justified tie control:
mode copy49 has priority1, call43 priority3. The compiler's rank_for_schedule
compares priority before dependency class and original instruction order.
Moving the coefficient setup changes no relevant dependency graph; source order
alone therefore does not target the deciding priority difference. This narrows
the next experiment without claiming that all legal schedules or source shapes
are exhausted. The earlier missing last-call dependency explains freedom to
hoist; these priorities explain the observed choice within that freedom.

All2,078 selected complete sources/effective profiles,442 focal attempts and
all focal inputs are unchanged. Zero compiler/native-worker calls, live writes,
claims, restarts or selected-source changes. Keep OPEN1700. Private
`repair-coverage-nov7/REPORT.md` retains generated diffs, source bindings,
coverage bounds, scheduler evidence and final preservation receipts.


## November 7: preserve the current native baseline before search

Current1700 source41e45e53 has a materially different selector/interference graph
from the older1733 native roots, not just a new formatting hash. Removing the
must-equal alias eliminated a local selector and its global copy. A bounded6899-
record audit found only audit/control copies of the current source, no native
batch rooted there. Existing app searches already support improvement feedback;
adding feedback was not a missing feature identified by this audit.

The actual Candidate/to_c printer failed byte parity: original ordinary/-da
1700/956bytes linked23d669f77eadaeea39d9e333aef312ae70c951d69d1e4e3fc84150454fb95304;
printed ordinary/-da1760/960bytes linked
6c6854b0a15e4e1b6e283076d1dbfe274a8040db02a0dc492f321175a2a02183.
A single extra NOP follows MFC1 when the printer splits the original two conversion
assignments onto different physical lines. Restoring only that original boundary
produces source7750b13595da122189e52a496337bf80bfc162369166ea0905a77ec8f33ea7aa
and recovers exact original1700 bytes in another ordinary/-da pair. All six saved
objects independently relinked. Two preprocessing and two strict-C89 checks ran;
an earlier pure AST gate stopped before tools because the normalizer braced a
single final goto. The revised check permits only that exact transparent wrapper,
not arbitrary AST changes. Raw AST/tokens are not claimed identical.

App PR757 merged ase5d2063c. Its generic native formatter preserves unique
unchanged adjacent assignments that shared an original physical line. It retains
physical coordinates through comments, changes whitespace only, verifies the
candidate AST, and declines ambiguous or preprocessing-sensitive contexts. The
production helper reproduces the measured7750 source byte-for-byte.68 related
tests and final18 formatting cases (including actual native generation) passed,
with whole-tree Ruff. No game match is claimed for this baseline repair.

### Fixed256 protocol retained; unsafe score improvement rejected

Exactly one job, seed60241700, emitted256 distinct raw sources plus complete
lineages and one done record. Six allowed families: expression capture,
statement/declaration order, assignment splitting, commutation and block insertion.
Type randomization was identity; no feedback, portfolio or replacement quota.
The unchanged KEEP0.6/four-try loop permits at most1024 internal iterations;
574 recorded lineage events are not the raw-emission count. Protocol SHA256:
ed4d7d23afc234abc75e125dc381149f6aecda595560fdde5a9446a193e3451e.
Generation completed normally in7.22seconds (12.33seconds including outer work),
with no surviving owned processes or resource failure.

Judging stopped as prescribed at raw210's apparent1505/964byte improvement.
Review rejects it: the new pointer is assigned only inside the first decoder arm
and read in the alternate arm, without established initialization on that path.
It was never adopted or promoted. At this stop:175 guard rejects,7 boundary
rejects,28 Clang calls and28 compiled/linked outputs (12 distinct/16 duplicates).
The remaining46 raw sources211–256 are retained but UNJUDGED; no exhaustion claim.
The judging outer watcher finished normally in82.54seconds, sampled peak aggregate
RSS406416KiB, with no cleanup error or survivors. All2078 selected complete
sources/effective profiles and442 focal attempts/full context remain preserved.

The initialization checker previously returned unknown for a pointer capture
embedded in another local assignment's arithmetic RHS. App PR758 adds a bounded
unconditional-copy CFG transfer; it rejects this exact candidate while accepting
a control initialized before the branch. Conditional evaluation, calls, other
writes and unsupported shapes remain unknown.234 related tests and whole-tree
Ruff passed. This is a safety correction, not a generally valid1505 frontier.
The separately approved continuation processed only retained211–256:31 guard
rejects,3 boundary rejects,12 strict-C89/ordinary linked results,5 new distinct
outputs and7 linked duplicates. Best score1700 equals the starting source; no
valid improvement or exact match. The continuation completed in29.35seconds,
peak aggregate RSS465580KiB, with no errors, resource failure or surviving owned
processes. End pins and read-only all2078/focal442/claims preservation passed.
All256 original candidates are now resolved, with210 explicitly rejected; no
replacement generation or source promotion occurred.

Live source remains OPEN1700. After explicit user approval the dev app restarted
on merged main e3cc68e5; health reports that revision. The arm64 macOS
1.0.9-alpha.4 shareable app was rebuilt from the same clean commit and both
production helper files verified against the source.
Private current-root-search-nov7 retains full proofs, objects, protocol and receipts.

## November 7: preserve original parents through expression rewrites

The retained256-candidate audit finds246 candidates with the original pair keys,
four changed adjacent keys and six cases where adjacency is lost. None of the
changed adjacent pairs had reached compilation: a source-bound boundary gate
rejected them first. That rejection alone was not measured scheduling evidence.

Candidate232 captures the conversion's actual f64 subtraction into an initialized
local immediately before use. The conversion assignment parent remains adjacent
to its high-bit mask, but its expression AST changes, so the old text-key-only
formatter loses the known shared line. The candidate passes the strengthened
initialization/effect guards. Joining only that whitespace preserves its complete
AST. A strict C89 preflight passed; four ordinary/-da compiler calls then show:

| Retained candidate232 layout | Score | Bytes | Linked SHA256 |
| --- | ---: | ---: | --- |
| Split |1760|960|6c6854b0a15e4e1b6e283076d1dbfe274a8040db02a0dc492f321175a2a02183|
| Original shared boundary |1700|956|23d669f77eadaeea39d9e333aef312ae70c951d69d1e4e3fc84150454fb95304|

All four persisted objects were independently reopened, relinked and rescored.
The joined output is exactly the existing baseline, not a newly better function
or a new match. Child20s/2GiB aggregate/orphan watchers and the outer controller
finish normally; outer14.08s/529,216KiB peak aggregate RSS, no errors or survivors.
Full before/after state preserves2,078 selected sources/profiles and444 attempts.

Native AST deep copies preserve original assignment-parent coordinates even when
a child expression changes. A pure fixture models precisely retained232 without
randomization and proves the production origin API emits the measured joined
sourcecacbe248d5e314093624fed815b8ec6841c2ffd9df33d67029cbdb8d19d0e2ae
with an identical complete AST. App PR764, merged14f53a54, binds only unique
original parents and restores a group only while they remain unique and adjacent.
Duplicated, separated, reordered or new coordinate-less parents are declined;
printed pair uniqueness, preprocessor exclusions and final AST verification remain.
61 formatting/related tests and full Ruff passed. GitHub reported no CI checks.
No live candidate adoption, runtime restart or game-progress change occurred.
Private lineage-revisit-nov7 retains the bounded audit, origin proof and receipts.

### Close the other source-valid changed adjacent pair

Retained candidate24 is the only other changed adjacent pair passing the
strengthened initialization/effect guard;233/234 fail initialization and were
not compiled. Its subtraction capture precedes the conversion branch, unlike
232. The actual game coefficient values2^31,4.5,1.5 and masked integer factors
put the floating input in exact half-steps from0 through1530. On the existing
premise that those coefficient objects retain their cartridge values, the
additional subtraction is exact and introduces no floating status exception.
This does not prove const qualification or equivalence for arbitrary mutable
coefficients/NaNs. Candidate24 also carries one byte load through an existing
signed32 local; paired split/join changes only the conversion/mask whitespace.

Four bounded ordinary/-da calls with independent persisted-object relinks give
split1965/960bytes (sourcefabe9140, linked
`f9d1e649cc52cbde172cecbedb28e2ec107007b22a149605db6c754df38eb702`)
and joined1905/956bytes (sourcece96247a, linked
`ebdaa1019015889c5ee62839b99d4f7978e380f7bade95133d2d758cc333ee11`).
Thus the same known boundary recovers60points/four bytes in a distinct body,
but neither beats the selected1700. Strict C89 preflight passed. All444 attempts,
2,078 selected sources/profiles and complete before/after inputs remain unchanged;
no generator, live adoption or new match. Private lineage-revisit-nov7/raw24
retains domain review, full source bindings and terminal watchdog receipts.
This completes the four changed-pair dispositions from the fixed256 batch.


## November 7: actual unsigned conversion carrier reuse

One exact-current control retained the floating expression, threshold compare,
signed casts and high-bit OR, but stored both conversion arms in the existing
unsigned temp_t0 instead of reusing the initial selector var_a0. The byte mask
consumed that actual result; decoder loads overwrite temp_t0 before its later
uses. All field reads, callbacks, output effects and shared physical conversion
line were preserved. This does not require newly immutable coefficients or a
replacement unsigned-cast lowering.

Source SHA256
`214d4e616b42b5678d9975ed5f9752a5d2cfd6ebbe6fc89d2eb07b2df610a059`
scored1855/956bytes in both ordinary/diagnostic modes, worse than1700. Fresh
processes reopened and relinked both saved objects with the same score and
linked SHA256
`96c8e2c8206feac6652dfff565e5414189f19bbceb4034b9256c01779f433d23`.
The conversion moved to pseudo92/hard t0 rather than baseline pseudo90/a0;
its actual byte mask still moved the result to a0. The80-byte frame, mode-copy
and table-address discrepancies remained. No adoption or automatic repair follows.

Two setup gates stopped before compilation on separate external progress-revision
updates; their raw receipts remain preserved. The successful phase used exactly
two compiler calls and two independent relinks, outer7.94s/415,392KiB with clean
aggregate/orphan-aware watchdogs. All694 pins,2,079 complete selected rows/profiles,
444 hydrated focal attempts and actual source/context/symbol/prelude/profile
inputs remained unchanged. Only external configuration.progress_revision changed
19193→19194; complete configuration snapshots are therefore not called identical.
Private conversion-flow-nov7 retains full receipts and the explicit external delta.
