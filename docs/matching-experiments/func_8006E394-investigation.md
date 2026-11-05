# func_8006E394: packet decoder (open)

No byte-exact candidate has been found. No live project, canonical repository, runtime, target, judge, or compiler profile was changed by this helper. The function remains revisitable.

## Frozen inputs

- Project 1, function 1452, 323 target instructions, originally OPEN with advisory score 1155 and no claim.
- App revision f409cb26; frozen inputs SHA-256 6e7889f8495099992b59c9ccaff0562f40982d1f29f9f86ec9d8df206ae5df25.
- Profile: gcc-2.7.2-kmc, -G0 -mips3 -mgp32 -mfp32 -O2 -g3, timeout 20.
- ROM read from a private verified copy; SHA-256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7.

## Source audit

The saved source adds volatile halfword reads to force particular loads. There is no demonstrated volatile device/object here; these were removed from all proposed clean alternatives. One-shot do/while(0) scopes are valid ordinary C, and remain legitimate scheduling hypotheses; they are not fabricated runtime branches. No uninitialized use was found in the starting source. Counter increments are bounded: the four counters at 800B6600 (also 800AE850+7DB0) are reset before up to eight increments of 4/2/1.

This decoder assumes a valid serialized game record: selected slot nibbles must be below four and unused slots must exist when selected. The actual machine code makes the same unchecked accesses; no artificial bounds guard or changed stack object was introduced. The source is not a claim of safety for arbitrary corrupt packet bytes. Pointer alignment and genuine object/record views are also required.

## Useful recovery: matched encoder's local record type

The already matched adjacent serializer func_8006E8A0 contains a local Packet definition for the same buffer, 800C7112 = 800C02AE+6E64. Its fields f15/f14/f13/f8/f4/f0/g12/g8 describe the packed input; sums[4] begin at offset 10, with three-byte counters and a byte mask preceding them. This gives stronger layout evidence than inferred masks alone. It obtains slot bytes from the game's selected slots, consistent with the decoder's valid-record domain.

Replacing raw scalar casts with this actual Packet's bitfield reads naturally restores the target's reloads without volatile. Packet-only pointer use avoids an extra saved-register pointer copy. packetptr0.c scores 1350 with the original profile; parent-packet-fields2.c is an equally scoring readable version that uses named byte and sum fields too. An integer v version removes the redundant switch truncation but changes allocation and scores 1540.

Parent RTL diagnostic (parent-rtl-finding.md, private dumps under rtl/) shows a controlled mechanism: raw source load is mem:HI, mode field store mem/s:HI; a raw halfword reload present in .rtl disappears in first .cse. Packet fields instead have compatible mem/s:HI classification and retain the needed reload. This is evidence about this pinned old GCC's aggregate/scalar treatment, not a general alias proof or proof of a compiler bug.

The app's current related-source context path borrows verified headers and requires already referenced type names. It misses this useful local typedef in matched_source and the equivalent object address expressed through a different symbol plus offset. Potential improvement: offer matched-local record hints anchored by resolved identical addresses, with ordinary compilation and linked verification. No automatic repair is claimed from this non-match.

## Experiments

- Clean raw-source baseline 2395; raw mode store through a halfword cast 1710.
- Removing only volatile while retaining original variables/scopes: parent 2415; additionally removing the n=8/base=0 one-shot scope 2395. Scope retention alone does not solve aliasing.
- Independent native baseline lane: 1000 unique candidates actually compiled and judged, each generated from the same clean baseline, not from a best-candidate portfolio; best 2265, no exact match.
- Independent native Packet lane: another 1000 unique, actually compiled/scored candidates from packetptr0.c, no best-candidate portfolio and no exact result. Best 1200 via a pure inline offset helper; static __inline__ control inline0.c also scores 1200. Its u8 argument receives j in 0..3, its 0x7DB0+j*4 arithmetic is bounded, and there is no new unresolved helper call. It has 52 rendered differing positions, with 2 extra and 1 missing instruction; the unmodified Packet baseline has 2 extra/3 missing. Header/profile/target were unchanged.
- Directed probes cover width/sign of v/n/base, direct halfword branch capture, input declarations and pointer types, raw/field/global block views, direct counter lvalues, precomputed map destination, explicit loop shapes, and 16 scope combinations for n/base assignments. None exact.
- Scoped n=4 alone (or n=8 alone) gives 1330 with byte v. This is an ordinary single-execution scope and uses an already supported scheduling technique; it is not evidence for a new repair family.
- Builtin memcpy halfword reads were supported but worse (2353/2958/7628); no extra target calls were accepted.
- Parent flag diagnostics and private Packet flag diagnostics are negative for exact matching. Raw mode plus no-expensive-optimizations 1545 is a separate-profile alternative, not a like-for-like baseline improvement. Packet no-expensive-optimizations worsened 1350 to 1525. No live profile changed.

## Remaining differences

The first packet/slot decoding phase now agrees structurally. The remaining phase differs in the n/base/m register allocation, hoisting an outer-loop nonzero guard into a boolean instead of retaining masked n, hoisting the counter address, map address/result scheduling, and byte-v switch truncation. The target also retains a computed flag-base address that appears unused in the later phase. A pure inline offset helper changes counter-address construction and reduces the physical differences, but does not recover the target address/lifetime pattern. Do not manufacture dead identities or false branches to force it; recover a real lifetime/layout explanation.

Additional negative controls: 24 declaration permutations of m/n/base/q all stay 1350; real matched Game/Entry (entry at 0x44, v.w at +0xA) is neutral at 1350/1540. No source is promoted to a match.

Final read-only check: OPEN 1155, unclaimed, frozen target/header unchanged. All native processes are terminal; evidence.json records exact source hashes and both 1000/1000 compile counts.

All candidates still require semantic review. A lower advisory score is not a match, and no full cartridge build was warranted for these non-exact candidates.

## Native helper linkage finding

Parent compilation-symbol audit (parent-inline-symbols.json) found that the native perm_inline variant emitted a GLOBAL inline_fn helper, 16 bytes in .text, even though the selected target had inlined its call. Across generated translation units this can add unaccounted text or collide with another helper definition. The static __inline__ variant emits no helper symbol and retains the same 1200 score. The generator-only safeguard for newly introduced inline helpers was merged in decompdecomp PR #528 (https://github.com/RetroReversing/decompdecomp/pull/528), with a two-unit linkage/execution regression and 138 focused tests. Original source functions must remain unchanged. This is a tooling correctness finding, not a new game match or evidence of full-cartridge equality.

## November 5 bounded revisit

Eleven new packed-field and limit-lifetime controls were nonexact. The actual selected helper contract is void(s32,s32), whereas the earlier decoder declared void(u8,u16). Correcting the nonvolatile research prototype retains1200; this is not an exact match and does not establish the original interface independently. PR609 now flags bounded simple explicit prototype discrepancies in full briefs. No live source or profile change was made. Private frozen inputs, source hashes and raw linked evidence remain on the Data volume; no game data is included here.
