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
