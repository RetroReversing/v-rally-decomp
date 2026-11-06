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
