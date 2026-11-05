# Linked-list contracts and unsigned countdown evidence

This is an existing-match source correction, not a new function match. The 85-member
package changes 84 selected sources and retains one unchanged dependency. All 85
independently reproduce their entire linked target functions. The joint private
12,582,912-byte cartridge rebuild is identical to the original image, SHA-256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All 2,069 compiler profiles and the other 1,984 selected C objects are preserved.
Normal linked-byte acceptance restored all 2,069 live matches. The current pointer-return accessor and wrapper layout were included in a fresh identical cartridge rebuild. These are existing-match corrections, not additional matched functions.

## The recovered contracts

`func_8005A744` follows the first-word pointer link of a live aligned list node.
`func_800592AC` and `func_800592D0` supply the actual widget/style head and forward
its pointer result. All three take an unsigned 32-bit index. The target decrements
and tests the old value; it contains no signed comparison. Caller declarations,
actual incoming argument forwarding and genuine narrow argument conversions were
corrected together: 44 direct widget callers, 34 style callers, 12 generic walker
callers and the eight upstream callers of two forwarding functions were audited.

Construction/read operations use actual `void *` link/head/tail storage rather than
loading a pointer through an `s32 *` lvalue. Context, widget, style and group
initialization/append sites and the typed first-link readers were checked jointly.
Recorded allocations cover the used offsets and the normal lookup contract is
`index < node_count`, with live aligned traversed nodes. No terminal-link store or
extra memory operation was invented to make a source model convenient.

## A reusable compiler control

With KMC GCC 2.7.2, `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`, plain unsigned
`while (count--)` scores 1115. A genuinely consumed snapshot (`before=count; count--;
if(before)`) recovers all 32 target bytes, exact score 0. The generated
`unsigned_countdown_guard` repair independently reproduces them. It preserves the
zero-test decrement, uses defined unsigned wrap and does not convert arbitrary
signed loops to unsigned. App PR #618 adds the bounded shared repair and synthetic
C90/pinned-compiler controls. This is a regression of a known match, not another
newly matched function.

## Limits

The allocator's optional-argument/dispatch contracts remain legacy work. Constructors
do not explicitly initialize terminal next words; lookup within the recorded count
does not read the selected terminal's next, but the existing destructor does read
it on its final iteration. Allocator zeroing has not been proved. The package retains
that preexisting issue and does not claim whole-game C memory soundness or global
record-typedef consistency. OPEN `func_8006603C`, `func_80059A60` and the foreign-claimed
`func_8007A29C` are excluded from the accepted-source proposal.

## Further focal controls

The corrected positive predicate in `func_8006603C` remains nonexact 305 after 21
additional wide/signed getter, tuple-predicate and record-address controls. Wide
getters retain masks but introduce the wrong memory load. They are not a solution.

`func_8006C024` remains nonexact 2454 after 42 additional valid controls. Unsigned
numerator arithmetic removes signed-overflow reliance without changing bytes.
Real wide incoming parameters with byte narrowing at uses reproduce two dependent
callees, but that does not establish a complete caller/storage closure. The old
1465 source has known correctness defects and must not be reused as the seed.

`func_8006BA44` has a grounded private 765 candidate after 51 controls. The exact
logical complement `!(threshold <= value)` recovers the floating branch shape;
`value < threshold` is not equivalent for unordered values. Caching an actually
consumed invariant output-table pointer improves 935 to 765. The BF30 interface
and global representations still need closure, so the candidate is not accepted.
No exact focal match was obtained in these passes.
