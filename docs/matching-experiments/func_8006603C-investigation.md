# Scene-state preservation investigation

The 155-instruction function remains OPEN. Its older score-200 draft is not a
correct starting point: after requiring saved1E == 2 it tests
(saved22 & saved1E) == 4, which is impossible. Recompilation emits an AND with 2,
not the target's low-halfword mask. This is a source error, not a compiler bug.

The clean alternative beside this note restores the real conjunction, removes
fabricated volatile qualification and duplicate storage-class declarations,
materializes a mode comparison as an initialized ordinary boolean, and moves
actual restore-byte conversions earlier. It reproduces the target's repeated
mode checks and register allocation. Its ordinary score is 300, nonexact: two
low-halfword masks remain missing, with consequent branch offsets. It is a safer
starting point despite the higher score and is not selected as standalone C.

973 native candidates plus bounded source/type/profile probes found no exact
match. One lower-scoring native candidate was rejected: a new temporary was
initialized only inside a branch but read as a final call argument outside it.
The app safety fix is tracked separately. Existing target bytes, profiles, scorer
and prior verified C remain unchanged; no full cartridge claim is made here.

Clean alternative SHA-256:
`5961efac8cdac2671f39f1bf45e0a1acb184069576575e48876688dab1ddccc9`.

## Second revisit: interface audit and narrowing probes


No exact C match. No live mutations, app changes, or full cartridge build.

## Fresh capture

Live database opened strictly read-only. Function was OPEN, score200, unclaimed.
Frozen inputs SHA256 c64f81d61e7dbb2b7b40156093cd8b03344dfa62235471dc7807a753412c7b00.
Normal linked judge uses pinned private app 11fc2ea7, effective frozen per-function
profile/context/symbols and original private image. Existing 200 draft remains
invalid for the reasons in the canonical investigation; it was not optimized.

## New hypotheses, all negative

- Five narrow-load representations: short/int bitfields, pointer/indexed getters,
  and a union-based local word/halfword view. Best300, no missing-mask recovery.
- Sixteen coordinated signed/unsigned field, getter-return and saved-value types.
  Best300. Signed-return variants add sign-extension differences.
- Five inline equality helpers with genuine comparison semantics. Best910; they
  select xor/branch forms rather than the target compare sequence.
- Twelve word/doubleword local and getter types. Best305 with ordinary word types;
  doubleword types add register traffic rather than the two required masks.
- Nine properly aligned union word getters returning masked/cast low halfwords.
  All305: late narrowing still optimizes away. No fabricated volatile or asm.
- Three byte-pointer row formulations. All nonexact; ordinary pointer arithmetic
  commutes one addu operand (305), indexed scalar expression worse470.
- Removing the two prepared arguments from the actual61F34 call costs90 score.
  This does not establish its true signature; all three known machine callers
  retain scene/base in a0/a1 and all corresponding selected callers pass them.

No repeated flat native search was run; the earlier973 attempts were respected.

## Corrected provisional draft

corrected-final.c is score305, nonexact. It retains the actual conjunction, ordinary
initialized values, repeated mode checks, and caller-evidenced two-argument61F34
interface. It additionally fixes the 6A24C return to s32 and represents8A290's actual
integer address-storage argument with an explicit N64 function-pointer-to-s32 cast;
that cast is implementation-defined for the pinned32-bit MIPS ABI, not portable C.
57B40's argument widths and8A0D8's actual integer/char interface now match selected
callees. Pointer row traversal uses real byte-pointer arithmetic. 592AC is declared
void* returning (actual v0 is dereferenced), requiring the existing selected void
592AC definition to be corrected jointly before whole-program acceptance. The
61F34 selected void(void) definition also requires jointly reconciled ignored
parameters if this caller-evidenced interface is adopted.5C0E8 is declared with
three actual arguments; its selected unused fourth parameter is not supplied.

caller-audit.json records all three61F34 and all six5C0E8 callers (seven callsites).
No5C0E8 site prepares a fourth argument; the unused fourth formal is an existing
selected-source contract defect. Do not invent an actual argument to accommodate it.

Remaining target differences: two low-halfword masks, eight consequent branch
operands, and one commuted addu operand. Two rendered symbol operands reflect the
existing relocation display; the ordinary judge, not rendered names, is authority.

These results do not justify a new automatic repair. Next useful route is actual
compiler narrow-value range propagation evidence, not additional equivalent masks
or unrestricted random candidates. The function must remain OPEN.


## Current reviewed correction and first-CSE evidence — 5 November 2026

The normal app review now selects **OPEN 305**, source SHA256
`cca3426471e1197ebc26bcb291294268c1e20b7a1579e76f47ae5b59d4ab9103`.
Parent ordinary compilation reproduces the private linked proof: 612 candidate
bytes versus 620 target bytes, no linker problems. The historical 200 predicate
is invalid: `(a & a) == 2` forces `a == 2`, making `(b & a) == 4` impossible.
The target compares the original halfwords independently against 2 and 4.
Initialized fields `(2, 4)` distinguish the required stores; no gameplay trace
establishes that this pair was observed. Real snapshot/restore operations and
stored-byte conversions are retained, without claiming globally reconciled raw
object/effective-type, scene-bound or nullability contracts.

New genuine aggregate, initialized output-pointer and byte-representation value
transports did not help. Three additional actual-predicate switch/fallback forms
also stay at 305. GCC RTL contains the two required halfword zero extensions in
initial/jump phases. First CSE substitutes the getters' already narrowed values
and deletes them; combine later forms LHU. This is earlier than register
allocation. Ordinary and diagnostic canonical linked bytes agree (SHA256
`0a7b03fe163c92a11dc7e602b02eed5b3600a0455175a6704a2de34bdc781dac`),
although raw ELF diagnostic metadata differs. No new exact match or successful
automatic repair is claimed. Keep open and avoid repeating final-allocation or
mask-spelling sweeps without a new first-CSE hypothesis.

## November 6: first-CSE dataflow and resolved interfaces

A fresh read-only capture confirms current source/context/profile/target unchanged,
OPEN305 and unclaimed. The history contains772 attempt-detail rows and529 unique
complete sources. Target masks at0x800661B8 and0x800661C4 follow the actual LHU
loads of fields1E/22 and copies to saved values. Intervening writes affect the
unrelated byte flag and fieldE; they do not supply a changed halfword producer.
Initial RTL still has both zero extensions. First CSE substitutes the already
narrowed getter values before combine. No new producer, alias barrier or meaningful
narrowing operation was established, so another mask-spelling sweep was not run.

The interface warnings earlier in this historical note are now resolved, not
remaining acceptance blockers. Current selected definitions are matched at0:
func_800592AC returns void* from u32 index; func_80061F34 accepts the actual
scene/base pointers; func_8005C0E8 takes the actual three arguments. Their selected
source SHA256 prefixes are d8234b15,10520bb1 and922183b1 respectively. Current
callers and full hashes are recorded in private cse-dataflow-nov6/current-contracts.json.
No duplicate contract compilation was needed. The ordinary/diagnostic baseline
recheck retains612 linked bytes and SHA256
0a7b03fe163c92a11dc7e602b02eed5b3600a0455175a6704a2de34bdc781dac.
No exact match, live source edit or new automatic repair is claimed.

## November 6: word producers, signed snapshots and combine links

A further history audit found that the proposed full-word producer was already
covered by focused-after-contracts/word3.c. It retains both masks but scores625
with620 bytes: LW1C/20 remain where the target uses LHU1E/22. A single new
 diagnostic compile reproduced its ordinary linked SHA256
81d6e9e1584fe37a40c81056dc6237d9b093176c9f34cc0b82cdac84c7760dfd.
The full-word snapshots have only real narrow consumers, with no full-word escape.
RTL shows the producer LOG_LINK attached to the earlier byte extraction while the
saved word remains live. The later halfword extraction has REG_DEAD but no
producer LOG_LINK, so this compile cannot combine that chain into LHU. This is
an observed phase explanation, not a general claim about all GCC code.

Signed-producer alternatives were also already covered: actual signed-halfword
snapshots score1605; the cleaner cast-based signed getter scores625 and uses LH
rather than LHU. No new source variant was compiled. Scene alignment/effective-type
provenance does not justify adopting a full-word view merely to retain masks.
No eligible real reconvergent branch exists at the snapshot point: preceding
conditions exit, and moving reads into failed paths introduces accesses. Earlier
reconvergence crosses actual calls, without a proved safe motion contract.

Current source remains OPEN305, SHA256
cca3426471e1197ebc26bcb291294268c1e20b7a1579e76f47ae5b59d4ab9103.
All2071 selected records/profiles and the seven protected input groups are unchanged.
Private word-producer-nov6/REPORT.md retains the source-bound history and RTL evidence.
No match or automatic repair is claimed.


## November 7: targeted CSE flag coverage audit

Fresh packed read-only capture preserves OPEN305,774 hydrated attempts and all2077
selected full sources/effective profiles. No compiler or generator calls occurred.
Historical flags300.py binds the earlier valid safe300 source, not current305;
no-cse-follow-jumps, no-cse-skip-blocks and no-expensive-optimizations each retained
score300 and the two missing masks. These are not current-source flag receipts.

The local GCC source's same-word SUBREG/ZERO_EXTEND equivalence path has no
integer flag guard for those switches. Follow/skip controls extend basic blocks;
rerun-cse controls a later pass; function-cse controls forcing call addresses into
pseudos rather than general scalar CSE. Installed binary symbols corroborate the
named functions/flags, but this audit does not claim full binary/source identity
for that CSE path. The actual retained RTL already locates the deletion in first
CSE. No new narrow flag or genuine producer contract justifies another matrix.
Preserve the current draft and revisit when new source/data-flow evidence exists.
Private current305-normalization-nov7 retains the report and unchanged snapshots.


## November 7: producer contracts and initialized16-bit local records

Fresh read-only capture preserves OPEN305,774 hydrated attempts and all2,077
selected sources/profiles. The saved halfwords come from direct inlined u16
field loads, not an external return or snapshot argument. Late byte conversion
already appears in737 historical sources; it does not address the two missing
pre-call halfword comparison masks. An8-bit snapshot replacement would change
comparisons above255 and was not tested.

One finite control represents each actual full16-bit snapshot with a single
unsigned-int:16 local field. Every field is initialized before use; no padding
value is observed in C, no union raw view or dummy member is added, and all
65,536 possible input values and later byte conversions are retained. This
differs from earlier memory-field controls. Compiler-source inspection predicts
a scalar record mode but partial-register field insertion on big-endian MIPS.

Ordinary/-da and independent relinks agree at945/632 bytes, SHA256
5d8dbb25ae1fe05254cb464f31d9e24e4589b72d9eca553726b68a84b79ed510;
sourcef1881bc0d36937dc1ced52fc9c7e66048e6f1182e962e6b24e9fa2657bbcf78c.
The predicted partial-register AND/SLL/OR/extraction path occurs. Comparison
zero extensions now survive first CSE, but combine removes both using the
resulting known upper bits. Extra packing operations remain, saved roles change
and the frame grows0x20→0x28. Moving a deletion to a later pass is not a fix.

Exactly two compiler calls completed under20-second/2GiB aggregate limits,
with independent relinks and unchanged full focal/history/selected snapshots.
No further signedness, width, flag or record-layout matrix follows. Preserve305.
Private current305-contract-phase-nov7/REPORT.md retains all phase evidence,
compiler identities, source review and final receipts.


## November 7: fresh donor and compiler-range reconciliation

A strict read-only audit retains774 hydrated attempts, OPEN305 and all2,078
selected sources/effective profiles. No new focal history exists since the
16-bit local-record control. Ranking3,805 matched imported functions of130–180
instructions finds no exact mnemonic donor; the nearest are the already known
scene functions63FFC and71B3C. Their actual byte/fullword producers do not
justify transplanting qualifiers or a wider field view into this function.

Actual baseline zero extensions263/267 disappear in first CSE; the local-record
control retains them until combine, which can prove the extracted values have
zero upper16 bits. No genuine widening, reconvergent producer or storage contract
was found that retains both masks while producing the target LHU instructions.

Historical profile scripts bind valid safe300, not current305; they cover KMC
flag variants and do not establish SN/PM coverage. That gap alone is not target
evidence. The nearest20 matched same-unit neighbors,800654AC–80066B88, all use
the current KMC2.7.2 profile. Other installed binaries have no demonstrated
provenance for this function, so no alternate-compiler matrix followed.

Zero compiler, Clang, preprocessor or generator calls; complete before/after
focal/history/selected snapshots agree. Preserve305. Private evidence:
`mask-frontier-nov7/REPORT.md`, `donor-audit.json`, `profile-neighbors.json` and
`preservation.json`.
