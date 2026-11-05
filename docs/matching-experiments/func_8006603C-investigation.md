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
