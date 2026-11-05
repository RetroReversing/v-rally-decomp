# Controller completion investigation

OPEN and revisitable. No new match or selected C.

## Current corrected alternative

The saved score-265 draft is unsuitable: one completion path skips the global-zero
store, and it uses a car pointer as a player index. Correcting those issues in that
text scores 1310. The earlier corrected alternative scores 655 with the current
compiler profile.

The [phase alternative](func_80043A78-phase-nonmatching-alternative.c) uses a genuine
integer-index to car-node active-member union, then a real slot base followed by
`+= index` and its field store. It never reinterprets an active union member. This
recovers all register differences: score **460** with the current profile, **240**
with the neighboring `-g3` profile. Five instruction positions remain different in
the latter, all in one branch/delay-slot cluster. This is not an accepted source or
compiler setting. Every immediate accepted neighbor uses the same KMC profile plus
`-g3`, but that alone cannot establish this function's original settings.

Candidate SHA-256: `fca92d19f650ac0b7f66edc02e21cf017f918fc83a123e00cc768868071aad48`.
Frozen input SHA-256: `225c3efff33503a23409a8e0ee35cd1a97279aa0e16ccd8808e3d4002b696607`.

## Exhausted controls

The November 5 revisit tested reverse active-member phases, both-branch index
reuse, slot-address lifetimes, state/mask/result lifetimes and ordering, flag-flow
forms, inline helpers, and signed/unsigned state types. It exhausted 128 physical
line-boundary partitions of the positive-polarity branch. None matched. Twenty-eight
installed period compiler/profile controls on two corrected sources also found no
exact result. Earlier native and offset/helper families should not be repeated
without a new grounded hypothesis.

Ordinary and `-da` diagnostic builds produce identical linked candidate bytes.
Compiler RTL confirms the remaining gap is nonannulled branch scheduling versus
the target's annulled equality branch and different delay-slot/arm order. This does
not justify forcing an instruction with assembly, volatile or dummy operations.

## Correctness limits

The target rebinds its state pointer during the other-car traversal and reads that
state in the final pad update; the alternative preserves this behavior. Sound-list
membership, initialized track/car objects and bounded track/speed arithmetic remain
explicit game-domain assumptions, not a proved whole-game invariant. Signed `abs`
of `INT_MIN` and speed-addition overflow are excluded cases in this unaccepted
research source. No invented null fallback is used. A future exact candidate still
needs a semantic audit, normal linked-byte acceptance and a complete cartridge check.

Detailed compiler receipts, frozen inputs and negative controls remain private;
no game image, extracted assembly or build output is included here.
