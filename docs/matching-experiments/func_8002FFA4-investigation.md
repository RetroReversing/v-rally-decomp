# Coordinate interpolation investigation

This 119-instruction function remains OPEN and non-matching. The previous score-462
draft contained uninitialized reads, an artificial volatile local and an overwritten
output pointer. Those constructs are absent from the new sound score-460 draft.
The draft is retained in portable progress only, not selected as standalone C.

The clean candidate uses initialized short coordinate differences, preserves the
output pointer and uses a real `&d[0]` alias. Its final assignment to the interpolation
temporary occurs after the last use of that temporary in all three products.

The bounded pass examined 2,467 candidates, of which 2,412 compiled. Two native
lanes each tested 1,000 variants. Expanding the coordinate-load macro did not improve
the best result. Register allocation and scheduling remain unresolved. No exact
match or complete-cartridge verification is claimed for this draft.

Sound draft SHA-256:
`7046bbbaab55354db3d76f8ef3d0bf9f2054478f873456fb585b05da02fa09d2`.
Immutable private input SHA-256:
`f77ce652ba9cdf5871e5eada51e76c2e4a1ed5e5c2d30502f76a883105f29287`.


## Current coordinate-record revisit

The current saved baseline is420, superseding the older460 checkpoint above.
A fresh read-only freeze and final audit confirm unchanged source, target,
header, compiler profile and symbols. Historical invalid462 remains rejected.

Thirty-two distinct local-coordinate representation controls compiled, with
four non-applicable combinations skipped rather than counted. Actual three-field
s16 records, records containing a genuine s16[3], direct/aliased local access,
first-delta width and meaningful offset lifetimes found no exact match. Baseline,
scalar-record and nested-record forms emit identical480-byte code. Removing the
actual b+2 lifetime reaches476 bytes, the target length, but worsens score to505.
Four representative ordinary/diagnostic compilations have identical linked bytes.

Nineteen supported KMC scheduling/debug/optimization controls found no
improvement. Installed PM GCC2.8.1 with g3/g0 scores4260/4850. No source or
profile was adopted. Existing caller, valid-grid and aggregate-bound caveats
remain; these tests do not prove whole-program type safety. Findings are saved
in normal app notes and portable progress. Keep the function OPEN420 and
revisitable; no new automatic repair or cartridge acceptance is claimed.
