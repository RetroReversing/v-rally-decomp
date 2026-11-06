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


## November 6 component capture and joint coordinate contracts

The normal app now retains an OPEN177 draft (previously420), 476 bytes, with a
genuinely consumed component-index local. It is not exact. A 1200-case host
oracle screen covers complete scalar-field records and s16-array outputs,
negative interior-base indices and signed fraction boundaries; that screen does
not establish all game storage lifetimes or arithmetic bounds.

Four existing selected functions were corrected jointly: 3035C,316C4,32AE4 and
317D4. The common coordinate helper uses void-pointer object/output contracts,
actual scalar field accesses at4C/54/8A and complete record/array addresses.
3035C returns s32; its callers explicitly preserve s16 narrowing. All known ten
direct2FFA4 calls and six direct3035C calls are covered; unknown indirect callers
and complete allocation/initialization evidence remain unproven.

Each corrected selected function independently links exactly, with ordinary/-da
parity. The complete 12,582,912-byte cartridge equals the original SHA256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All2071 selected profiles and other2067 selected C objects are preserved. Normal
saved-source verification accepted all four before the draft was retained.

A bounded qualifier control is informative: adding const to3035C's new position
formal and byte/halfword read casts scores790/824 bytes; removing those added
qualifications restores exact844 bytes. This does not isolate a single qualifier
or justify blanket const removal. PR642 records the evidence in the KMC guide.

One frozen177 native search delivered1000 charged wrapper candidates,392 linked
scores and no improvement. Raw generator emissions were not captured: the
wrapper filters some candidates before delivery. Do not report this as1000 raw
emissions or restart the exhausted lane without new grounded evidence. Detailed
private receipts remain in current-nov6/closure3035C and the parent cartridge gate.
