# Championship accumulation investigation

The saved score-135 draft is semantically sound; audited layout sums=0x58, laps=0x118, total=0x168. The clean alternative only removes unused locals, remains 135/nonexact, SHA256 3e63cc2d3f1051e701f8a1ebdf88af2a96b5f08ce5ed141e7e5acd4a25b737f2. 1000 native candidates,59 generic repairs and targeted probes (including61 parent probes, some overlapping helper probes) found no exact match. Residuals: first summing loop accumulator v1 versus candidate a1 and row pointer a1 versus candidate v1; flag address hoists before rather than after switch constants. Sum commutation/scope/type/reuse, bound capture, address forms, independent bindings, switch order, flag lifetime placement, total accumulation forms and simple source-line changes did not improve135. Full minification changes scheduling but worsens295; do not infer formatting is inert. OPEN/revisitable, no compiler/profile/target/ABI/judge changes, no selected standalone C. Clean source: docs/matching-experiments/func_800529F0-nonmatching-alternative.c.

## Register-lifetime and scheduling revisit

# func_800529F0 fresh sequential revisit

No exact match. The existing sound score135 source remains the best result; no
live mutations, app changes, repeated native search or full cartridge claim.

Fresh read-only freeze:87bd0602700106439e9a414c43f9320e6e27e86d253f7bddd7da685f15986d96.
The function was OPEN135 and unclaimed. Pinned private app11fc2ea7 and the actual
frozen effective compiler/profile/header/symbols judge every candidate normally.
No external calls: no imported callback or callee ABI contract to correct.
Layout and bounds retain existing assumptions: selected record index<12,
record lap count<=5, four competitors. Unsigned accumulation wraps normally;
rank is0..3, so switch always sets points. Existing draft has no UB found.

## Real differences verified from linked bytes

linked-byte-audit.json compares fully relocated machine bytes, not symbolic
renderings. Exactly12 words differ, lengths equal. Seven offsets5c,70,74,80,8c,
a4,b0 are the first loop's accumulator v1 versus a1 and row pointer a1 versus v1.
Offsets c8,cc,d0,d4,d8 are the constant1/2/3 materializations reordered with flag
address lui/addiu. All other words, including branch targets and relocated
addresses, are identical. Thus this is actual allocation/preheader scheduling.

##62 new bounded probes

12 phase-lifetime probes reused the existing, currently dead byte-pointer flag
capture as the actual first-phase lap-row iterator, advancing16bytes per lap,
then rebinding it for the independent rank/flag phase. Both existing pointers,
three rebind positions and two real typed load forms were tested. Best795.
The real lifetime hypothesis changes register pressure but does not recover the
wanted accumulator/row register allocation.

18 complete inline summation helpers used a by-value count, all six table/count/
column parameter orders and three load forms. Best380: extra bound hoisting
removes a target move and disturbs allocation.

12 helpers instead received the record pointer and read its actual count inside
the sum loop. All six parameter orders and direct/staged load bodies tested.
Best155, exact instruction count, but counter/bound allocation differs in
addition to the original accumulator/row swap.

16 combinations of real inline record/count/flag accessors and loop-initializer
placement. Without count accessor135; count accessor1905. No identity helpers,
volatile, register bindings, or forced instruction templates used.

Four accumulator widths (signed/unsigned long and long long). Word widths135;
doubleword widths995, adding unwanted widened arithmetic allocation.

## Deliverables

baseline.c SHA2563e63cc2d3f1051e701f8a1ebdf88af2a96b5f08ce5ed141e7e5acd4a25b737f2,
baseline.json normal score135/nonexact; evidence.json contains all62 probes.
No demonstrated reusable automatic repair. Keep the function OPEN; do not
publish an exact claim or repeat the old1000-candidate flat search.

## Sum-update and other-region revisit

Fourteen additional bounded controls retained the score-135 best. Six inline
helpers including the sum, sum-store and total update all emitted identical
448-byte score-155 code. Linked-byte comparison showed that they fixed none of
the original twelve word differences and added four counter/bound differences.
Three sequenced post-increment or staged-load forms canonicalized to the saved
135 code. Three typed row traversals emitted identical 444-byte score-850 code.
Two unsigned modular-add spellings stayed at 135; commuting the addition did
not repair the underlying register allocation. No native search was repeated.

The other imported region's semantic counterpart is func_800537DC (114
instructions versus PAL's 112), but it remains OPEN with neither matched C nor
a saved best draft. Its effective compiler profile is identical. The code's
configuration, record, table and flag addresses can be mapped through real
machine hi/lo pairs; those mappings do not supply missing source or prove an
exact twin. No transplant or profile change was justified. No new match or
reusable automatic repair is claimed.


## Count-bound interference investigation

A fresh freeze reproduced score135 and the same12 differing raw instruction words.
The ordinary and diagnostic `-da` compilations emitted identical linked bytes.
GCC's global allocation dump identifies the row pointer ahead of the accumulator
in allocation priority; the accumulator additionally conflicts with the hoisted
initial lap-count value. This explains a concrete interference difference, but
does not establish a source fix.

112 new source controls found no improvement: four scalar aggregate forms, eight
counter/scope controls, 55 individual adjacent source-line merges, 16 guarded
initialization forms, nine destination-pointer captures, 12 block reductions and
eight memory reductions. All55 line controls were also independently recompiled
and raw-linked: every one emitted the same baseline machine-code hash. Nineteen
supported compiler/debug/optimization controls likewise found no improvement;
one unsupported newer compiler option was excluded.

The source, target, header, symbols and compiler profile remained unchanged. No
exact match, source adoption or cartridge claim is made. These results are saved
in the ordinary app notes and full portable progress. Keep this function OPEN
and revisitable; further work needs a new actual data-flow or allocation cause,
not another repetition of the same line edits or flat native search.

## November 6: enclosing-object row induction

Fresh cd710019 inputs reproduce OPEN135 and ordinary/diagnostic linked parity.
Six new byte traversal controls start at the real enclosing ChTable object,
advance16 bytes per lap and access the existing lap subobject at0x118+i*4.
The previous traversal controls began at the lap array; these use a different
source ownership model without forming an invalid interior fictitious struct.
Within the retained idx<12 and n<=5 domain, the byte addresses stay within the
actual table. Scores345/345/500/500/515/520: no exact result or improvement.

RTL gives a more precise allocation observation: the row pseudo has11 weighted
uses across8 instructions; the accumulator has12 across22. The row is allocated
first. The extra initial-count conflict is real, but it is not alone a proven
cause of the undesired ordering. Explicit traversal also changes initialization
relative to the count guard; it is not the target graph with a register fixed.
Ordinary/-da linked bytes agree for baseline and representative traversal.
No new reusable source repair is established. Source/header/target/relocations/
profile/symbols and ownership remain unchanged. Prior flat native, helper, count,
line and flag controls remain negative; no such sweep was repeated.

## November 6: caller interface and genuine pointer phases

The fresh hydrated857-attempt history still has minimum135; the actual saved
focal draft and ordinary/diagnostic448-byte output are unchanged. Global
allocation prioritizes the row over the accumulator; the accumulator also
conflicts with the initial count. Prior grounded count, scope, traversal and
helper controls already cover these relationships, so no new blind sweep ran.

The sole visible matched caller, func_8005322C, declared a three-argument
interface and passed three pure local reads to the actual void(void) entry.
Removing these invented arguments preserves all340 linked bytes. A separate
follow-up keeps the scratch pointer byte-typed for H's byte-offset halfword
accesses, then uses an explicit s32 pointer for the existing final word store.
This removes the old incompatible-pointer assignment warning without adding
storage or operations. Combined source SHA256:
`9febe0896c23072a1175ed6494281bd64faa5da49e5c024c6b6d2f8c7ce5cdd5`.
Ordinary and diagnostic linked bytes agree, SHA256
`cd01eefeed5ade0a23691ddb70538596a7d95cc0a29a671b2c3b648d9a9d6e62`.

Actual raw linked equality takes precedence over the advisory score20 for
symbolic operands. This correction does not resolve the focal135 mismatch.
It retains existing storage/alignment/effective-type premises for the raw
configuration object and the final word store; no whole-program safety claim.
Full-cartridge and normal-import acceptance are recorded after their gates.

Parent acceptance: the combined declaration and pointer-phase correction passed
the complete12,582,912-byte cartridge comparison, SHA256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All2071 compiler profiles and other2070 selected C objects were preserved.
Normal saved-source import independently rejudged the combined caller exact;
all2071 matches remain. The earlier declaration-only version was also gated
but was not imported as a separate intermediate source.


## November 6: current seed already exposes every field

A fresh read-only freeze confirms OPEN135,857 hydrated attempt rows, and source
SHA25677abee0e749b35cfa3c738d5aa663dddbc745b3b99c1900bcd5cabb257597d54.
This is byte-identical to the historical native sound-start.c seed. Both previous
and PR664 macro expansion leave it unchanged: actual ChCfg/ChRec/ChTable field
and array expressions are already visible. The focal AST contains15 struct
references,13 array references,4 for loops,23 assignments and zero calls.
There is no hidden H/F accessor in this actual source and thus no new macro
coverage to search. No compiler or new native run was justified by this audit.
All2071 selected records/profiles and seven input groups remain unchanged.
Historical native-safe outputs were saved only after screening and did not
fully constrain derived temporary types; do not claim exhaustive safe-grammar
coverage from that old run. Private macro-audit-nov6/REPORT.md retains the
current source/parser comparisons. No caller contract was reopened.


## November 6: consuming the lap count inside each competitor iteration

One new control captured rec->n separately for each outer iteration and consumed
it as a remaining count alongside the increasing lap index. The inner loop has
only reads; lap reads and unsigned additions retain their order, and the count
is read anew after each outer sum/total write. Existing valid-object premises,
idx<12 and n<=5 remain explicit. Remaining reaches zero without underflow.
The hydrated/private audit found no earlier countdown spelling in2268 source
units; no syntax or profile sweep followed.

Ordinary/diagnostic baselines agree at135/448bytes. The control agrees at
1450/436bytes, linked SHA256
cd04a5b421b5393d8463ee280b3db0541c92242bc2fb6190dd8ae2c98bd458d9.
Initial RTL and CSE retain decrement/nonzero control rather than the target's
increasing unsigned comparison. Global allocation still gives the row v1;
remaining takes a1 and the accumulator moves to a2. The control also loses the
8-byte frame. Removing the old bound lifetime therefore changes the instruction
graph without recovering target allocation. No improvement or exact match.

All2077 matched-source hashes/profiles and complete focal inputs remained
unchanged. No source adoption, app update or cartridge claim. Private
focused-allocation-nov6 retains the before/after snapshots and paired outputs.


## November 6: current-root compiler coverage reconciliation

A fresh read-only capture finds859 hydrated attempts and the same77abee0e source,
with all2077 selected full sources/profiles and complete focal inputs preserved.
No compiler calls or random generation were performed in this audit. The apparent
missing SN coverage is already present in private registered-sn0004-nov6 and
registered-sn-alternatives-nov6 receipts, bound to this exact source/header.
Original registered defaults yield0001 score295/452bytes,0004 score2745/432bytes,
and0006 score4270/432bytes, each with ordinary/diagnostic linked parity. None
repairs the accumulator/row allocation.

The same current source is also bound to parent-profiles/debug-opt-results.json:
g0/g1/g2/ggdb each yield295/452bytes; O1 yields4845/460bytes and O3 retains
135/448bytes. Those older debug result summaries do not retain complete per-command
or paired diagnostic receipts; this limitation is explicit rather than treating
them as a newly verified compiler pair. Count, scope, traversal and scalar-phase
proposals duplicate prior real controls, so no further quota was justified.
Private current135-causal-nov6/REPORT.md and audit.json retain the reconciliation.


## November 7: isolated late-consumer allocation-priority control

The installed KMC comparator audit distinguished weighted-reference priority from
hard-register preferences. Current135 gives row pseudo199 11 references over
8 live instructions (priority41250), versus accumulator99 12/22 (16363).
The actual target accumulator is v1, with row in a1. Earlier v0 descriptions were
incorrect. The installed flow pass counts references by linear loop depth.

One previously uncovered control wrapped only the two existing late sum stores
in six nested single-execution do/while(0) scopes. It added no references,
storage, effects or control transfers and preserved evaluation order. The
prediction was that the two real sum uses would raise its priority above row.
Exactly two compiler calls, ordinary and diagnostic, produced identical448-byte
linked bodies, score410 (worse than135), SHA256
c2a9fc03f3bab1bdc1992ae8a607f6b956cdb22d16c62c3565843045ba91aa6d.

The causal prediction was partly confirmed: accumulator99 became24 references
with live length21 (priority45714), took target v1, and row took target a1.
However, the scopes also increased the column/total-pointer priorities and
changed other allocations and increment scheduling. The separate flag scheduling
residual remained. A desired register pair alone is not an overall improvement;
retain current135. This does not justify a generic scope-depth sweep or adoption.

Each owned compiler tree completed normally within20 seconds and2GiB aggregate
memory, with no surviving owned processes. Private current135-priority-nov7
retains candidate/source-effects review, ordinary/diagnostic objects, raw linked
bodies, RTL, watchdog receipts and the full preservation audit. No live writes or
new match are claimed. The existing app loop_weight_scope family covers scalar
increments at depths1/3; it cannot generate this late indirect-store group, but
this negative control does not establish that extending it would gain matches.
