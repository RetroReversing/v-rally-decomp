# Controller timeout transition: exact match

The normal app judge accepts `func_80043A78`: **1,272 bytes**, KMC GCC 2.7.2
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`. The neighboring selected profile already
uses `-g3`; only this previously open function's live profile changed.
The complete **12,582,912-byte cartridge** remains byte-identical, SHA-256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
There are now **2,071 matched / 16 open / 34 assembly** functions in the app.
All 2,070 previously selected profiles are preserved in both their respective
app and standalone checkpoints. The 2,052 other selected C objects are unchanged.

## Reusable matching change

A real inline timeout helper uses an inverted outer guard, performs the original
state-flag/timer updates and returns; its other original arm follows the guard.
This gives the required annulled branch and delay-slot fill. A positive terminal
layout scores 260; the inverse layout is exact. No runtime helper call, dummy
operation, fake condition, register directive or instruction padding is needed.
Ordinary and diagnostic linked bytes agree. Native controls cover the state/timer
transition; the shared app generator independently reproduces scores 260 and 0
with the final corrected signatures. App PR
[#635](https://github.com/RetroReversing/decompdecomp/pull/635) automates the bounded
terminal layouts across the shared repair pipeline.

## Existing contracts corrected with the match

The lookup takes both its list and name and explicitly forwards both to its
callees. Its update wrapper takes list/name/value, returns an integer, and uses
an ordinary positive nonnull branch. All 17 inventoried selected direct lookup
and updater functions are corrected; the focal caller also has compatible
incomplete Car/Pad tags and explicit pointer views. These 18 existing source
corrections remain exact under their original profiles. They are not new matches.
The focal also agrees with its selected getter and byte-output callee signatures.

## Concrete domain audit and limits

The relevant body field is entry 10 in a 12-word grid-column array. All 55 retail
track files, containing 2,255 grid records, were checked against the actual loader
layout. Centers are 2..6, columns 5..12; initialization, guarded stepping and
accepted/restored transitions retain columns 0..10. Thus the magnitude input is
-8..6 in normal initialized retail state, excluding INT_MIN. This is not a proof
for injected or corrupt values. Defined unsigned/wide alternatives scored 700
or worse and were not selected merely to improve a score.

The provisional sound-list name actually refers to UI items. Normal setup creates
and associates these items before controller dispatch. The source retains the
game's successful initialized-UI contract: consistent eligible player/view counts,
valid allocated records, and no interleaved teardown or reassignment. It does not
invent a valid null-plus-offset fallback. Existing object/effective-type assumptions,
allocation failure and unrelated selected-source defects remain outside this focused
proof. No whole-program memory-soundness claim is made.

All portable progress was saved after acceptance and compared against the live
matched sources, allowing only the save format's trailing newline normalization.
