## Continue in decompdecomp

In a current decompdecomp build, choose **Continue a public decomp**, enter this
repository URL, then supply your own **Europe (PAL)** ROM. The app detects the
bundled `progress/` save and restores its sources, best drafts, names, notes,
headers and compiler profiles, verifying saved matches against your ROM.
No ROM, compiler installation or database is included in this repository.
Accept any required proprietary compiler terms in the app before installing them.

For older app versions, clone the repository and choose **Open a saved project**
with the local `progress/` folder and your ROM. The root `.decomp.wtf.json` also
describes the standalone build for public-decomp importers, but restoring
`progress/` is the way to retain saved drafts and app metadata.

# V-Rally Edition 99 - Nintendo 64 matching decompilation

[![Progress](https://bytematch.dev/RetroReversing/v-rally-decomp.svg)](https://bytematch.dev/RetroReversing/v-rally-decomp)

An unfinished matching decompilation of the European revision 0 release (`NVLP`). It began with ROM-derived C from Claude Sonnet 5.5 (low effort) and GPT-6.1 Sol-directed sessions, and now includes a newer user-supplied decompdecomp export. See [NOTICE.md](NOTICE.md) for provenance.

## Verified checkpoint

### Exact parser bounds match — 5 November 2026

`func_8002B180` now matches all **87 instructions / 348 bytes**. The live app's
ordinary judge accepted score **0** with a function-only KMC GCC 2.7.2
`-G0 -mips3 -mgp32 -mfp32 -O2 -fno-thread-jumps` profile. An explicit return guard
in the outer loop condition and a correct inner-loop exit recovered the target's
branches. Neither the isolated guard nor the isolated flag change matched; see
[compiler matching notes](docs/compiler-matching-notes.md) for the controlled trials.

The complete sync includes **4 new C functions / 2,508 matching
bytes**, retaining every earlier C selection. Independent function checks and the
complete **12,582,912-byte cartridge comparison** passed. There
is one standalone integration exception: `func_8000C9B0` remains in assembly because its
C object overlaps the next function by four bytes. Its app-matched C is preserved
in the portable save. Additional app matches arrived after the standalone checkpoint
was prepared: `func_8007EAA0`, `func_8007EE9C`. Their C is also saved in portable
progress and remains assembly in the selected build pending independent integration.

The portable snapshot preserves **2,048
matches and 57 best drafts**, plus current names, headers,
notes, symbols and compiler profiles. The selected build contains **2,045
C / 79 assembly entries**.


### Live return-address dispatcher match — 5 November 2026

`func_8007F12C` now matches **81 instructions / 324 bytes**. The running app's
`live_return_address` repair found it with **one generated proposal and two compiles,
including the baseline**. Its exact source, header context and unchanged
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3` profile are retained together. The complete
**12,582,912-byte cartridge** rebuilt byte-identically, retaining every earlier C
selection. The final cartridge link uses the actual source saved by the app.

The missing operation reads the **current live MIPS return-address register** after
an optional callback. `__builtin_return_address(0)` instead reads the function-entry
caller, so it is not equivalent. The fixed, no-argument compatibility intrinsic and
automatic repair are merged in [decompdecomp #493](https://github.com/RetroReversing/decompdecomp/pull/493).
The standalone private header carries the same trusted definition for direct builds;
no arbitrary target assembly was substituted. See [compiler matching notes](docs/compiler-matching-notes.md).

At that checkpoint, the standalone selection was **2,041 C / 83 assembly entries**, covering
**547,168 / 599,940 candidate-code bytes (91.20%)**. The fresh portable
[`progress/`](progress/README.md) snapshot retains **2,046 app matches, 59 best drafts
and 27,580 notes**, including two further app matches that arrived during verification.
At that point, five exact app matches were portable progress pending independent standalone
integration: `func_8000C9B0`, `func_800199DC`, `func_8002B180`, `func_8003D9C8`,
and `func_80084C0C`. They were excluded from that standalone C count. Four are integrated in the newer parser checkpoint above.

### Exact text-rendering match — 5 November 2026

`func_8000CC04` now matches **868 instructions / 3,472 bytes**. The running app
accepted score **0** with exact linked bytes and a ready standalone layout; the
canonical repository's independent function check also passes. The complete
**12,582,912-byte normalized cartridge** rebuilt byte-identically with this C
selected. Every earlier standalone C selection and the existing local edits are retained.

The compiler remains KMC-compatible GCC 2.7.2 with
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`. The assertion path uses the fixed
`__builtin_mips_debug_break()` compatibility intrinsic from decompdecomp #481;
its trusted definition is included in the private repository header for direct builds.
This is not a native GCC 2.7 builtin or arbitrary submitted assembly. Keep the
verified source line breaks: the branch-tail integer temporary's separate lines
place an assembler hazard NOP before the shared branch destination. A one-line
rewrite changed two branch encodings and scored 20. See [compiler matching notes](docs/compiler-matching-notes.md).

The standalone selection is **2,040 C / 84 assembly entries**, covering
**546,844 / 599,940 candidate-code bytes (91.15%)**. The refreshed portable
[`progress/`](progress/README.md) snapshot retains all **2,043 app matches,
62 best drafts and 27,537 notes**, plus names, headers and compiler settings.
Three other app matches are preserved in that snapshot but are not yet selected
as standalone C: `func_800199DC`, `func_8003D9C8`, and `func_80084C0C`.
They were excluded from that standalone C count. Four are integrated in the newer parser checkpoint above.

### Complete app progress sync — 4 November 2026

This checkpoint adds **11 verified C functions / 6,148 matching bytes**:
`func_8000E428`, `func_80010468`, `func_80010BFC`, `func_8002B344`, `func_8002B540`, `func_8002E688`, `func_8003970C`, `func_80048D4C`, `func_80063FFC`, `func_8007BA1C`, `func_800855F8`. Every earlier C selection is retained. Each addition passed its independent
compiler/link check and the complete **12,582,912-byte cartridge** rebuilt byte for byte.
There are no integration exceptions.

The fresh portable [`progress/`](progress/README.md) snapshot preserves **2,039
matches and 66 best drafts**, with 27,002 notes, names, headers,
symbols, knowledge and compiler settings. Its sources and metadata were compared with the
live app after saving. The standalone build selects **2,039 C / 85
assembly entries**, covering **543,372 / 599,940 exported candidate-code
bytes (90.57%)**. Drafts remain non-matching progress; active workers can make
newer changes after this checkpoint.


### Exact controller-update match — 4 November 2026

`func_800347A4` now matches all **529 instructions / 2,116 bytes** with the
unchanged KMC GCC 2.7.2 profile. The running app accepted score **0**, the
independent repository check passed, and the complete **12,582,912-byte cartridge**
rebuilt byte for byte. No target, assembly, shared-header or compiler-profile
edits were needed. See [compiler matching notes](docs/compiler-matching-notes.md).

The complete sync adds **11 verified C functions / 14,724 bytes**,
retains every earlier C selection, and has no integration exceptions. The
portable snapshot preserves **2,028 matches and 77 best drafts**,
plus current notes, names, headers and compiler profiles. The standalone build
now selects **2,028 C / 96 assembly entries**.



### Exact header-rendering match — 3 November 2026

`func_80074BF8` now matches all **567 instructions / 2,268 bytes** with the
unchanged KMC GCC 2.7.2 compiler profile. The running app accepted score **0**;
an independent linked comparison and the complete **12,582,912-byte cartridge**
rebuild also passed. Every earlier C selection is retained, with no integration
exceptions. The refreshed portable snapshot contains **2,017 matches and 88 best
drafts**, including notes, names, headers and compiler profiles.

Reusing a temporary with a separate later lifetime fixed the final addition's
operand order without changing earlier scheduling. See
[compiler matching notes](docs/compiler-matching-notes.md) for the measured repair.



### Latest complete sync — 3 November 2026

Added five independently verified C matches: `func_80007CA0`, `func_8001A340`,
`func_8002BD40`, `func_80036C48`, and `func_8006786C` (**2,532 bytes**).
Every earlier C selection is retained. The complete **12,582,912-byte cartridge**
rebuild is byte-identical, with no integration exceptions. The portable app
snapshot preserves **2,016 matches and 89 best drafts**, including current
notes, names, headers and compiler profiles. Unmatched drafts remain drafts.


### Earlier complete sync — renderer recovery, 3 November 2026

`func_80016B3C` is now an exact **1,023-instruction / 4,092-byte** C match under
the unchanged KMC GCC 2.7.2 `-G0 -mips3 -mgp32 -mfp32 -O2 -g3` profile.
Scoped accumulators fixed register allocation; using one consistent typed game-state
global resolved the final scheduling difference. No inline assembly or target edits
were used. See [compiler matching notes](docs/compiler-matching-notes.md).

This sync also includes 12 other new app matches: **13 C functions / 13,436
matching bytes** in total. Every earlier selected C function is retained, and the
complete **12,582,912-byte cartridge** rebuild remains byte-identical. There are no
integration exceptions. The portable snapshot contains **2,011 matches and 94 best
drafts**, with current notes, names, symbols, headers and compiler profiles.

### Earlier complete sync — 3 November 2026

This update adds **20 verified C functions / 15,044 matching bytes**, retaining
every earlier C selection. All additions passed independent compiler/link checks
and complete **12,582,912-byte cartridge comparisons**. No integration exceptions remain
in this update. The portable snapshot includes **1,998 matches and 107 best drafts**,
with names, notes, symbols, headers and compiler profiles. The standalone checkpoint
now covers **84.05%** of all exported candidate-code bytes.

### Previous complete sync — 2 November 2026

The latest session adds four exact matches: `func_8006F3C0`, `func_8004E094`, `inflate_codes` and `func_80057B40` (**2,304 bytes**). Two were found in the matching session and two by existing app agents. All passed independent function verification and the complete **12,582,912-byte cartridge comparison**. Every earlier selected C function is retained. The portable snapshot includes **1,978 matches and 127 best drafts**, plus names, notes, symbols, headers and compiler profiles.

The app reports **83.52% of eligible code** (487,620 / 583,868 bytes) and **1,978 / 2,086 eligible functions** (94.82%), with 35 functions set aside. The standalone checkpoint covers **81.54% of all exported candidate-code bytes**; its denominator includes additional preserved coverage and assembly entries. These are point-in-time snapshots.

Two unmatched drafts also improved: `func_80011178` from score **790 to 490**, and `func_80049DB0` from **60 to 20**. They are retained as drafts and do not count as matches. [Compiler matching notes](docs/compiler-matching-notes.md) record the verified fixes and the uncredited square-root lead.

The `func_8004E094` fix requires two coordinated source-layout changes under KMC GCC 2.7.2 and binutils 2.6. Each change alone scores **110**, worse than the starting **60**; together they reproduce the target at **0**. Preserve the accepted physical line boundaries and separate inline conversion helpers rather than formatting or deduplicating them without rechecking the bytes.

The final menu-function repair preserved the original compiler profile and the complete
662-instruction sequence. It resolved register allocation by keeping the raw coordinate live
past narrowing and adjusting two temporary lifetimes. Pure unsigned/bitwise identities in the
matching C cancel to unchanged values and disappear from the emitted code; they are compiler
shape workarounds, not a reconstruction of the original author's spelling.

The 2 November boundary audit restores five complete compiled-function targets that the importer had truncated to 4–12 bytes: `func_8000CC04`, `func_80011178`, `func_80016B3C`, `func_8004AFB8`, and `func_8007C694`. Their remaining **24,376 bytes** are now code rather than opaque binary ranges. The recovered targets remain assembly until independently verified C is available. The standalone linker uses `--no-keep-memory` to reduce linker memory usage; the final full-ROM comparison passed with that option. This increases the code-coverage denominator; a lower displayed percentage does not mean matched code was lost. The recovery retained all **1,957 pre-reimport matches**. The refreshed portable snapshot contains **1,962 matches**. Five further C functions are now integrated, including recovered `func_8004AFB8` and `func_8007C694` (9,024 bytes), after independent compilation and a complete cartridge comparison. The seven previously reported exceptions are reconciled: three already had curated repository C under older names, and four now pass standalone and complete-cartridge verification. The portable snapshot also retains newer drafts and restored private header assignments.

- **2,045 selected C functions / 549,676 matching bytes**, about **91.62% of 599,940 exported candidate-code bytes**.
- **2,121 app functions**; export includes **2,124 entries**, selecting **2,045 C and 79 assembly functions**.
- Full **12,582,912-byte original normalized cartridge rebuilt byte for byte**, with no C build fallbacks.
- The 29 October 2026 app snapshot adds **113 C functions and 54,932 matching bytes** over the 1,587-function checkpoint. Every previously selected C function is retained. The additional sources have isolated snapshot headers and the compiler settings used for their verification. Readable symbol aliases remain provisional.
- The 29 October app snapshot reported **1,706 matches**. Six remained assembly because they cannot yet be integrated faithfully into the standalone build: `func_8003354C`, `osCreateThread`, `guFrustum`, `guOrtho`, `osCreateViManager`, and `alEnvmixerPull` (3,116 bytes combined). Names and types remain provisional.


The latest 31 October checkpoint preserves the three trig/matrix helper matches (520 bytes) and adds `func_8006090C`: **883 instructions / 3,532 bytes**, verified through both the app's normal judge and the standalone build. All previously selected C remains intact, and the complete cartridge comparison passes. Its source formatting, isolated header context and unchanged KMC GCC 2.7.2 compiler profile are retained together.

The follow-up adds `func_8004C2B8` (**46 instructions / 184 bytes**) as an exact match. Reordering two independent struct-field stores produced the target instruction order. Its source, isolated header and compiler profile pass the standalone check, and the complete rebuilt cartridge remains byte-identical.

The next exact match is `func_8004A0A0` (**966 instructions / 3,864 bytes**). Its reconstructed C, isolated header and KMC GCC 2.7.2 `-g3` profile are retained together. Reusing an existing local for the masked width recovered the final register allocation. Helper expressions and local lifetimes are reconstruction choices, not evidence of the original source spelling. All earlier selected C is preserved.

The `sqrtf` match at `0x8008DFB0` is now included as C; its 2-instruction source and isolated compiler profile reproduce the target bytes.

This is a partial decompilation. Candidate boundaries, compiler identity, names and types remain provisional. Detected-code coverage is not a percentage of the whole game, and a matching build still uses original assembly for remaining functions.

The 31 October 2026 snapshot adds **22 verified C functions and 9,092 matching bytes** while retaining every one of the 1,700 previously committed C functions, including those not currently verified in the app. Seven additional app matches still fail standalone integration and remain assembly in this checkpoint. The new sources use a separate header and their recorded compiler flags.

The later 31 October matching session adds **four byte-exact C functions and 872 matching bytes**: `func_8001C2E4`, `func_800830C8`, `func_80086A34`, and `func_800988C8`. Their source formatting, isolated header, and verified compiler settings are retained. All 1,722 earlier C functions remain selected. Two additional non-matching draft improvements stay in the local app and are not counted here.

The follow-up export audit recovers **six previously excluded app matches / 3,116 bytes** into the standalone build. Five require the recorded KMC profile without `-g3`; `osCreateViManager` also needs an explicit eight-byte storage gap so its private BSS addresses agree with the original. All earlier C remains selected.

### Export audit

The fresh app export fell back to assembly for 57 entries. Independent compiler/link checks explain every case:

- **52 compiler-profile mismatches:** the same app C and header match when `-g3` is omitted. Of these, 47 already had verified C preserved in this repository; the other five are now integrated. Debug options change the resulting instruction stream with this period toolchain, so compiler settings must be retained per function.
- **4 translation units with extra function bodies:** their target function matches, but exporting all the bodies would overlap other functions. The repository already contains verified versions with unused bodies replaced by declarations.
- **1 private-data layout mismatch:** `osCreateViManager` has correct instructions, but the initial BSS offsets require two different section bases. An explicit eight-byte gap after its thread storage and an adjusted stack alignment make every BSS reference use the same verified base. The gap is a reconstruction choice, not a claim about the original source declaration.

The app's saved matched count can therefore exceed what a fresh export rebuilds as C. Preserve the source, header context and compiler profile that passed verification together, and recheck a match when any of them changes. The combined checkpoint below passes the full cartridge comparison.

The latest verified sync adds **two C functions / 668 matching bytes**: `func_80085C58` and `__osCheckPackId` (exported as `func_80096104`). All earlier C is retained. The app reports **50.0%** using its eligible-code denominator; the standalone figure above uses all detected candidate-code bytes. The complete cartridge remains byte-identical.

### Complete app progress snapshot — 31 October 2026

The latest complete sync adds **five C functions / 5,376 verified bytes**: `func_80022BE8`,
`func_80026ED4` (820 instructions), `func_8003035C`, `func_8003E4A8`, and `func_80053F44`.
All previously selected C is retained. A recount also corrects the older summary: the previous
checkout selected 1,746 C functions / 290,592 bytes, rather than the stale 1,741-function figure.
Each addition passed its standalone compiler/link check,
and the complete original cartridge rebuilt byte for byte. Objdiff metadata and per-function
compiler profiles are updated together.

[`progress/`](progress/README.md) is a portable snapshot of the complete decompdecomp PAL project:
**1,751 recorded matches and 349 saved best attempts**, with names, headers, notes, symbols and
compiler settings. Best attempts are drafts, not additional matching C. The saved project and
standalone build use different selection histories; the verified standalone totals above remain
the build's authority. Future progress commits include the whole app snapshot, not just the
last function discussed. This is an explicit snapshot, not continuous automatic synchronization.

### Additional exact match — 31 October 2026

`func_8005A790` now matches all **775 instructions / 3,100 bytes**, verified by the app's
linked-byte judge and independently by `build.py check`. Repairs corrected a missing call
argument, unified aliased global accesses, used typed object fields for scheduling, and
separated a matrix-result temporary. The compiler remains KMC GCC 2.7.2 with
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.

The portable progress snapshot records **1,756 matches and 344 best drafts**. The app and
standalone build retain different earlier selections; `func_80082EB8` and `func_80098560`
are newly retained in that snapshot but have not been added to the standalone C selection.

The 1 November 2026 checkpoint adds **7 C functions / 6,816 matching bytes** and updates an existing match while retaining all earlier C. `func_80076060` is now an exact **845-instruction / 3,380-byte** match in the live app and standalone build. Separate local draw-pair blocks and staged second-call arguments resolved its final register allocation. The complete original cartridge comparison passed before publishing these source files. The portable `progress/` snapshot includes all current app matches, drafts, names, headers and compiler settings.

The selected-byte summary is now calculated from original function-symbol sizes, correcting a **1,436-byte** overstatement in the previous summary.

### Complete app progress sync — 1 November 2026

This checkpoint adds **4 verified C functions / 6,896 matching bytes**:
`func_800131C0`, `func_80034134`, `func_8003946C`, `func_80069A08`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,766 matches
and 334 best drafts**, alongside current names, 20,672 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

Three app matches remain snapshot-only: `func_8005D0B0` has non-contiguous constant pools;
`func_800869B8` and `func_80087DE4` emit extra function bodies. The previously verified
`func_80086A34` remains selected as C while the app retains its newer draft. Nine existing
repository sources were also refreshed and passed the complete-image check. All saved
source formatting is retained because it can affect period compiler output.

### Follow-up app reconciliation — 1 November 2026

This checkpoint adds **2 verified C functions / 676 matching bytes**:
`func_80035B04`, `func_8003B660`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,768 matches
and 332 best drafts**, alongside current names, 20,682 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

`func_800911B0` finished matching after the standalone build snapshot. Its exact app source,
header context and verified compiler evidence are included in `progress/`; it remains assembly
in the **1,767-C-function standalone checkpoint** until its own standalone integration and
complete-image verification. The portable snapshot records **1,768 app matches and 332 drafts**.
No app progress is omitted from the snapshot; this is a deliberate distinction between saved
app evidence and the separately verified standalone source selection.

### Complete app progress sync — 1 November 2026

This checkpoint adds **35 verified C functions / 25,804 matching bytes**:
`func_800122A4`, `func_80017B38`, `func_80018C04`, `func_80019F9C`, `func_80023B7C`, `func_80031F2C`, `func_800344F0`, `func_80035C4C`, `func_800370E8`, `func_8003B310`, `func_8003E1BC`, `func_80043150`, `func_800475E4`, `func_8005073C`, `func_80051994`, `func_800526E4`, `func_800545E4`, `func_80063790`, `func_80067AC4`, `func_8006874C`, `func_8006C3E4`, `func_8006CE1C`, `func_8006E8A0`, `func_8007F278`, `func_8008328C`, `func_800839C4`, `func_800859A0`, `func_80085D90`, `func_80086854`, `func_8008A31C`, `func_8008D31C`, `func_800911B0`, `func_80092BD0`, `func_80096830`, `func_80097B8C`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,804 matches
and 296 best drafts**, alongside current names, 20,735 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

Two app matches, `func_800869B8` and `func_80087DE4`, are preserved in the
portable snapshot but remain assembly in the standalone build: their current candidates
emit extra bodies or need declaration cleanup. Thus the app snapshot has 1,804 matches
while the verified standalone selection has 1,802 C functions and 320 assembly functions.

### Complete app progress sync — 1 November 2026

This checkpoint adds **1 verified C functions / 2,760 matching bytes**:
`func_8000F660`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,805 matches
and 295 best drafts**, alongside current names, 20,735 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

#### What made `func_8000F660` match

The 690-instruction candidate needed two address corrections: the result store goes to
`0x800B7040` rather than `0x800C7040`, and the following clear goes to `0x800B6AFC`
rather than `0x800C6AFC` (`D_800C02AE + 0x684E`). The raw LUI/store instruction
words established the addresses; symbolic relocation annotations obscured them.
Both corrections together passed the normal linked-byte judge without changing the
compiler profile or control flow, followed by the complete byte-identical cartridge build.

The two snapshot-only app matches remain `func_800869B8` and `func_80087DE4`:
their candidates need extra-body/declaration cleanup before standalone selection.
The current snapshot therefore contains 1,805 app matches versus 1,803 selected C
functions and 319 assembly functions in the verified standalone build.

### Structured-loop match and complete progress sync — 1 November 2026

This checkpoint adds **2 verified C functions / 3,412 matching bytes**:
`func_80028E94`, `func_8006C640`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,807 matches
and 293 best drafts**, alongside current names, 20,737 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

### Exact `func_80030A0C` match — 1 November 2026

`func_80030A0C` now matches all **814 instructions / 3,256 bytes**. It passed
the normal live app judge, the independent standalone function check and a complete
**12,582,912-byte cartridge comparison**. All earlier selected C is retained;
**316 functions remain assembly** in the standalone build.

The final repair separates the second loop's unsigned count from later temporaries,
preserves the guarded initial count read, and explicitly normalizes the loop index
before the shared test. A mathematically false guard controls otherwise unused
compiler spill reservations: its signed-short temporary uses the selected KMC
compiler's two's-complement narrowing convention. The guard emits no call or data.
These source details reproduce the original NOP, immediate shift and stack frame;
the compiler flags and exact-match checks are unchanged from the verified app profile.

The portable [`progress/`](progress/README.md) snapshot also preserves all current
app work: **1,817 matches and 283 best drafts**, with names, notes, headers
and compiler settings. Saved app matches not selected in this standalone build remain
snapshot progress, rather than being counted as independently integrated C. This is a
verified snapshot, not continuous synchronization while other workers are active.

### Complete recent progress sync — 1 November 2026

This checkpoint adds **10 verified C functions / 11,708 matching bytes**:
`func_8002C6EC`, `func_80030A0C`, `func_800354F4`, `func_8003C968`, `func_8003FFB4`, `func_8004D7D4`, `func_8004EF40`, `func_8006CF7C`, `func_800864F8`, `guLookAtReflectF`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,819 matches
and 281 best drafts**, alongside current names, 23,679 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

### Additional matches captured during synchronization — 1 November 2026

This checkpoint adds **2 verified C functions / 556 matching bytes**:
`func_80016204`, `func_80059618`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,820 matches
and 280 best drafts**, alongside current names, 23,683 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

The portable snapshot additionally retains `func_800869B8` and `func_80087DE4`, whose
extra emitted bodies prevent standalone integration, and the newly captured
`func_8006F4A8` app match, which arrived after the build verification cutoff.
These remain assembly in the verified cartridge; their saved C is preserved as progress.

### Latest complete app progress sync — 1 November 2026

This checkpoint adds **26 verified C functions / 16,000 matching bytes**:
`func_800075BC`, `func_80009ED8`, `func_8000EC94`, `func_80020B04`, `func_800324B4`, `func_8003EE84`, `func_80041F24`, `func_80042DE0`, `func_80042F40`, `func_8004E224`, `func_800516BC`, `func_800540A0`, `func_80055904`, `func_80057014`, `func_8005D4A4`, `func_800643F0`, `func_80064F98`, `func_80067474`, `func_8006CCD0`, `func_8006F4A8`, `func_80077054`, `func_8008276C`, `func_80086138`, `func_80088008`, `func_8008871C`, `func_8008FBC0`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,846 matches
and 254 best drafts**, alongside current names, 24,143 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

The portable snapshot also preserves `func_8005F5C4`, `func_800869B8`, `func_80087DE4`.
The export blockers for `func_800869B8` and `func_80087DE4` remain recorded
in `decompdecomp-sync.json`; the additional
new match arrived after the verified build capture. These saved sources remain assembly
in the standalone checkpoint until independently integrated.

### Exact reconstruction of `func_80039A00` — 1 November 2026

`func_80039A00` now matches all **741 instructions / 2,964 bytes** through the app's
ordinary linked-byte judge and an independent standalone comparison. The complete
12,582,912-byte cartridge also rebuilds byte for byte. Its function-only profile uses
KMC GCC 2.7.2 with `-G0 -mips3 -mgp32 -mfp32 -O2`, without a debug flag; `-g3` changes
this compiler/assembler's scheduling. Matching choices include unsigned-halfword
arithmetic, a single-case switch, and explicit selector scaling with qualification
of existing byte reads. These reconstruct the original machine code, not the original
source spelling; names and types remain provisional. No original game source was consulted.

The same sync integrates `func_80052CF4`, `func_8005F5C4` and `func_80068D9C`: **four
additional C functions / 4,640 matching bytes** in total, retaining all earlier C.
The refreshed portable snapshot holds **1,850 matches and 250 best drafts**, with
names, notes, headers, symbols and compiler profiles captured at its saved timestamp.
`func_800869B8` and `func_80087DE4` remain snapshot-only because their current candidates
emit extra bodies. The newer `func_8003CD18` match arrived after the build capture and
is also retained in the snapshot, pending standalone integration. Agents remain active;
this is a verified checkpoint, not continuous synchronization.

### Complete app progress sync — 1 November 2026

This checkpoint adds **6 verified C functions / 6,248 matching bytes**:
`func_80027E8C`, `func_800376C8`, `func_8003CD18`, `func_80050048`, `func_80062E68`, `func_80087594`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,855 matches
and 245 best drafts**, alongside current names, 24,513 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

`func_800869B8` and `func_80087DE4` remain snapshot-only: their saved candidates
emit additional function bodies and are not selected as standalone C. All previously
verified C is retained. Active agents can add work after this captured checkpoint.

### Latest complete app progress sync — 1 November 2026

This checkpoint adds **4 verified C functions / 1,776 matching bytes**:
`func_8001BDA0`, `func_8004FD5C`, `func_8005A100`, `func_8006F8E0`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,859 matches
and 241 best drafts**, alongside current names, 24,734 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

### Latest complete app progress sync — 2 November 2026

This checkpoint adds **9 verified C functions / 4,352 matching bytes**:
`func_80006EF8`, `func_80008500`, `func_800169DC`, `func_800415A8`, `func_8004CEB4`, `func_8005639C`, `func_8006ECB4`, `func_800710F0`, `func_80089300`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,872 matches
and 228 best drafts**, alongside current names, 24,943 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

Snapshot-only matches: `func_80054BB8`, `func_800635A0`, `func_80063C60`, `func_80063D9C`, `func_800869B8`, `func_80087DE4`.
The two existing helper-emitting candidates remain excluded from standalone C;
four additional matches arrived during verification and are preserved in the snapshot
pending standalone integration. No previously selected C was removed.

### All recent app progress synchronized — 2 November 2026

This checkpoint adds **35 verified C functions / 23,748 matching bytes**:
`func_8000A2C4`, `func_8000BF2C`, `func_80011058`, `func_80015780`, `func_80018D7C`, `func_80027DB4`, `func_80028740`, `func_80035684`, `func_8003737C`, `func_8003FD0C`, `func_800407D0`, `func_80044908`, `func_800548A0`, `func_80054BB8`, `func_80055EE8`, `func_80057D5C`, `func_80061F34`, `func_800635A0`, `func_80063C60`, `func_80063D9C`, `func_80066B88`, `func_80069158`, `func_8006EE3C`, `func_8006F0E0`, `func_80072984`, `func_8007A01C`, `func_80080674`, `func_80083C28`, `func_800848A0`, `func_80089554`, `func_80089C48`, `func_8008CDBC`, `func_80094BE0`, `func_80095E18`, `func_800964EC`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,904 matches
and 196 best drafts**, alongside current names, 25,180 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

### Exact menu-function match — 2 November 2026

`func_800754D4` now matches all **739 instructions / 2,956 bytes**, verified by the live
app's normal ROM judge and independently by `build.py check func_800754D4`. Its original
KMC GCC 2.7.2 profile (`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`) and isolated header are retained.
Temporary reuse, equivalent formatter-call branches and initialization order recovered the
register allocation and final instruction scheduling. These are reconstruction choices,
not evidence of the original source spelling.

All previously selected C remains intact. The full **12,582,912-byte** cartridge rebuild
passes the byte-for-byte comparison. The portable `progress/` snapshot contains **1,905
matches and 195 best drafts**, including the same verified source and compiler evidence;
the standalone build selects **1,903 C functions**, with **219 assembly functions** remaining.

### Exact func_80021064 match and complete progress sync — 2 November 2026

`func_80021064` matches all **619 instructions / 2,476 bytes** under the unchanged
KMC-compatible GCC 2.7.2 profile (`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`). The live
app, independent linked-code/data check and complete cartridge rebuild agree.

The final near miss contained only a counter-initialization store in the wrong order.
Deriving the five-step value from the existing wheel index, instead of maintaining a
separate counter, recovered the compiler-generated initialization order. Removing an
obsolete identical-arm scheduling guard was also necessary. Earlier, reusing a pair of
scalar temporaries recovered the vector-subtraction register choices. These coupled
changes explain why instruction-similar drafts can resist isolated edits; they do not
establish the spelling of the original source. No inline assembly or fixed registers
were added.

This checkpoint adds **2 verified C functions / 2,888 matching bytes**:
`func_80019608`, `func_80021064`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,913 matches
and 187 best drafts**, alongside current names, 25,186 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

The portable snapshot additionally preserves three integration blockers
(`func_8005D0B0`: non-contiguous constant pools; `func_800869B8` and `func_80087DE4`:
extra function bodies). Six more app matches arrived during the long rebuild and remain
snapshot-only pending standalone verification: `func_800051B4`, `func_8001AAB4`, `func_8003C354`, `func_80048394`, `func_8007159C`, `func_8008910C`.
The earlier verified `func_80086A34` remains selected as C while the app retains its newer
draft. No previously selected C was removed. The snapshot is a point-in-time save;
other agents can continue working after it.

### Complete progress sync after func_800754D4 — 2 November 2026

This checkpoint adds **38 verified C functions / 24,904 matching bytes**:
`func_800051B4`, `func_80006B4C`, `func_800070CC`, `func_80008E80`, `func_80009164`, `func_8000C244`, `func_80015168`, `func_80015534`, `func_80015C74`, `func_80016910`, `func_80018900`, `func_8001AAB4`, `func_8001AF54`, `func_8001CB88`, `func_8001D07C`, `func_8001FFC4`, `func_80024584`, `func_8002AA18`, `func_8003647C`, `func_8003C354`, `func_8003D8F4`, `func_8003E3E0`, `func_8003F834`, `func_80048394`, `func_800485F8`, `func_80049E28`, `func_8004C98C`, `func_8004F89C`, `func_80050FC4`, `func_80056AB8`, `func_8006556C`, `func_80065C04`, `func_80069734`, `func_8007159C`, `func_80077724`, `func_800783A8`, `func_8007BDC4`, `func_8008910C`. All earlier selected C is retained. Each addition
passed its independent compiler/link check, and the complete original 12,582,912-byte
cartridge rebuilt byte for byte. Objdiff source links and compiler profiles are updated together.

The refreshed portable [`progress/`](progress/README.md) snapshot contains **1,946 matches
and 154 best drafts**, alongside current names, 25,298 notes, headers, symbols and
compiler settings. Drafts remain non-matching progress. Snapshot sources, names, notes, symbols
and compiler profiles were compared with the live app after saving.

Standalone integration exceptions retained in the portable snapshot:
`func_8005D0B0` has non-contiguous constant pools; `func_800869B8` and `func_80087DE4`
still emit extra function bodies. They remain assembly in the verified cartridge build.

### Pointer/index allocation recovery — 2 November 2026

`func_80057810` now matches **52 instructions / 208 bytes** in the live app and standalone
build. The recorded KMC GCC 2.7.2 profile is unchanged. Typed pointer/index locals inside
a one-shot scope recover the final register swap; this is a verified reconstruction shape,
not a claim about the original source. The normal linked-byte/data check and complete
cartridge rebuild both passed. All earlier selected C is retained.

This verified checkpoint selects **1,963 C / 161 assembly entries**
(475,240 bytes in selected code targets, including their listed padding). Its fresh portable `progress/` snapshot retains
**1,963 app matches and 142 best drafts**, with names,
headers, symbols, notes and compiler profiles checked against the live app. Snapshot
matches remain distinct from independently verified standalone C. See `decompdecomp-sync.json`
for integration exceptions; previous standalone sources are preserved.

## Build

Use Python 3.12+, uv and a platform supported by [RetroReversing/decompdecomp](https://github.com/RetroReversing/decompdecomp). The combined export was verified using tool revision `4030a3ba87fe583be8506a712da167f1c7696746` and its pinned toolchains. Most functions use KMC-compatible GCC 2.7.2; per-function ranges also select IDO 5.3 and SN GCC 2.8.1. Install required proprietary tools only after accepting their licensing conditions. This is a working compiler hypothesis, not proof of the game's original compiler release.

```sh
git clone https://github.com/RetroReversing/v-rally-decomp.git
cd v-rally-decomp
uv venv --python 3.12
uv pip install --python .venv/bin/python "decompnet @ git+https://github.com/RetroReversing/decompdecomp.git@4030a3ba87fe583be8506a712da167f1c7696746"
.venv/bin/decomp setup
.venv/bin/python tools/prepare.py "/path/to/your/V-Rally Europe ROM"
.venv/bin/python build.py
```

Preparation detects byte order from the ROM magic and verifies the fixed hash. Your original stays untouched. The build regenerates assembly and assets locally; keep those files private. On Apple Silicon the period KMC tools require Rosetta. Windows uses the equivalent environment executables and supported toolchain setup described in the fork's README.

Expected final comparison:

```text
identical: build/game.z64 matches baserom.z64 byte for byte (1943 of 2122 functions in C)
```

## Supported input

| Field | Value |
| --- | --- |
| Game code | NVLP |
| Region / revision | Europe / 0 |
| Normalized size | 12,582,912 bytes |
| Normalized SHA-1 | da3f262dfb86cff1376c9a1aa081212e5a7aad64 |
| Normalized SHA-256 | d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7 |

## Continuing

Read AGENTS.md. Work on C and headers, preserve targets/compiler settings, and use `build.py check FUNCTION_NAME` in the configured environment for a candidate comparison. Run the full build before accepting an integrated checkpoint. Keep originals, generated files, databases, compilers and local evidence out of Git.

[The AI-assisted N64 tutorial](https://www.retroreversing.com/ai-assisted-n64-decompilation) explains the workflow and model comparisons. See [NOTICE.md](NOTICE.md) for provenance and licensing.

## ByteMatch progress reports

`tools/progress.py` runs the full verified build, assembles the original comparison
objects, and regenerates `objdiff.json` from `build.json` and the source tree.
Then run `objdiff-cli report generate -o build/NVLP/report.json` (create
`build/NVLP` first). Unit names follow the source folders. Assembly-only functions
compare against an empty object and remain incomplete; their source path records
the ROM-generated assembly, which is intentionally not published. ByteMatch
can show the committed C; generated assembly has no public source to display. The report step
regenerates `include/bytematch_names.h` from the compiled C symbols so ByteMatch
can find readable names that differ from the original report symbols. This
header is not included by the build. There is
no separate list of functional, non-matching C, so no `functional.json` is emitted.

Reports distinguish completed/linked progress from raw object matching.
Some linked C units can have small object-level differences even when the full
cartridge is identical; neither measure is a whole-game completion percentage.

The workflow uploads only `NVLP_report`, containing `report.json`, on main pushes
or manual dispatch. It requires a **dedicated self-hosted runner** labelled
`bytematch`, with Git and a supported build host (including Rosetta on Apple Silicon).
CI installs Python, the pinned build dependency, and its pinned objdiff tool. Set repository Actions variable
`NVLP_ROM_PATH` to an absolute path to your legally supplied ROM **outside** the
checkout. No secrets or ROM uploads are used. Do not enable pull-request triggers
on this runner. A hosted runner cannot rebuild this project without game data.

After ByteMatch has read a successful default-branch run, use its source-link
checker as described in [the source-linking guide](https://bytematch.dev/docs/source-linking):

```sh
python3 /path/to/ByteMatch/scripts/check-source-links.py RetroReversing/v-rally-decomp --version NVLP
```

### Exact rendering-function match — 2 November 2026

`func_80073B64` now matches all **727 instructions / 2,908 bytes** in the live app and
standalone build. The unchanged KMC GCC 2.7.2 profile is
`-G0 -mips3 -mgp32 -mfp32 -O2 -g3`; its isolated header, source layout and per-function
profile are preserved together. The complete **12,582,912-byte cartridge rebuilt byte
for byte**, SHA1 `da3f262dfb86cff1376c9a1aa081212e5a7aad64`. All earlier selected C is retained.

The final register-only miss needed two coupled changes: small nested single-execution
scopes changed the compiler's loop-depth-weighted register priorities, and restoring Y
from an existing equal saved value kept that value live after a conditional call. This
avoided the last redundant copy. These are verified reconstruction choices, not evidence
that the original source used these wrappers or variable names. No inline assembly or
fixed register bindings were added.

The refreshed portable [`progress/`](progress/README.md) snapshot preserves **1,892 app
matches and 208 best drafts**, including current names, notes, headers and compiler profiles.
The standalone selection is separately verified: **1,867 C / 255 assembly entries**.
26 app matches are saved in the snapshot but are not selected as standalone C
in this single-function integration; the previously verified `func_80086A34` remains
selected even though the app currently keeps a newer draft. The exact reconciliation is
recorded in `decompdecomp-sync.json`. Snapshot matches and drafts are not additional
independently verified standalone functions.

### Additional boundary and export recovery (2 November)

Two directly called, complete framed functions are now explicit assembly targets:
`func_8000A840` (4,304 bytes) and `func_80078760` (3,500 bytes). The importer recovered them on a copy
without changing any of the 1,962 existing matches. Their 7,804 code bytes increase the denominator;
they are not new C matches. The live app needs the updated importer and a reimport to expose these targets.

Four further standalone C selections are `func_8005D0B0`, `func_800869B8`, `func_80087DE4`, and
`guS2DInitBg`. Source isolation preserves the actual target body and line breaks. The first uses
matching-only entry extraction: every compile passes the normal linked code/data judge before its
compiler-derived entry is emitted. Two eight-byte constant ranges have explicit reviewed ROM/RAM
mappings; unmapped or conflicting reads fail. The bundled `export_entry.py` also works with the installed
app runtime. All prior selected C is retained, and the complete normalized cartridge remains byte-identical.
The refreshed portable snapshot retains concurrent drafts, notes and the restored private header units.

### Latest full progress sync (2 November)

Eight additional C functions add **6,756 matching bytes**: `func_80018A14`,
`func_8002ABC0`, `func_800480B0`, `func_8005508C`, `func_8006A438`,
`func_80078018`, `func_80081260`, and `_getRate` (standalone entry `func_80092FD4`).
All 1,963 earlier C selections are retained. Each addition passed an independent
compiler/link check, followed by a byte-identical complete normalized cartridge
rebuild. There are no integration exceptions in this sync. The portable `progress/`
snapshot includes all **1,971 app matches and 134 best drafts**, with current
names, notes, headers and compiler settings. The standalone selection is now
**1,971 C / 153 assembly entries**, or **482,008 / 599,940 candidate-code bytes (80.34%)**.
A fresh instruction-byte recount corrects the previous summary's 12-byte undercount;
that correction is not an additional match.


### Verified live-register allocation update

Saved **2,046 standalone C functions** and all **2,049 app matches**
in the portable progress snapshot. `func_8007EAA0` passed the standalone and full
cartridge byte comparison. Remaining app-only matches stay in `progress/` pending
independent build integration.
