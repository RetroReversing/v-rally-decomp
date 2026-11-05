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
