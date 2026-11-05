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
