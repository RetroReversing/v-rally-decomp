# Provenance and licensing

This unfinished matching decompilation combines ROM-derived C from Claude Sonnet 5.5 sessions at low effort and a GPT-6.1 Sol-directed session, using decompdecomp, m2c, compiler feedback and local search/permutation tools. The latest Claude session's 1,000-function export was combined with four previously verified functions it did not select; the combined 1,004-function checkpoint passed the full cartridge rebuild. The supplied sessions did not consult original V-Rally source.

The 25 October 2026 update imports additional matching C, compiler settings and a shared prototype from the user-supplied `v-rally.zip` export. It retains the earlier 1,004 C functions and selects 1,392 after integration. The archive does not establish the model or source-access conditions of this additional work; no new attribution is inferred.

The 26 October 2026 update exports a snapshot of the local decompdecomp project,
including additional verified matches and provisional SDK/audio names. It retains
all 1,392 previously selected C functions and exports 1,437 after integration.
One additional app match, `osCreateViManager`, remains assembly because its data
placement is not currently representable by the exporter. This snapshot alone
does not establish model attribution or source-access conditions for each new
match, so no additional attribution is inferred. Two newly exported translation
units had unused static helper definitions removed to avoid overlapping the next
function. The linker also preserves explicit private-data placement without
adding section-alignment padding. The retained function code is checked by the
full cartridge rebuild.

The 27 October 2026 update exports another local app snapshot and integrates 150
additional C functions, for 1,587 selected functions. All 1,437 earlier C functions
remain selected. For 56 omitted by the fresh export, the earlier source and header
context are retained with their previously verified compiler settings. These
headers use the `checkpoint_` prefix so current context changes do not alter those
translation units. The previous unused-static-helper removals and explicit
private-data alignment fix are retained. Six app matches remain assembly because
the export cannot currently represent them faithfully. The combined checkpoint
passes the complete cartridge comparison. This snapshot does not establish the
model or source-access conditions of each new match, so no attribution is inferred.

The 29 October 2026 update adds 113 verified C functions and 54,932 matching
bytes from a snapshot of the local app, selecting 1,700 C functions in total.
All 1,587 earlier C functions remain selected, with their earlier contexts and
settings preserved. New translation units use isolated `snapshot29_` headers and
per-function compiler settings. Six app matches remain assembly because their standalone comparison or private-data
placement cannot be preserved faithfully. The complete cartridge rebuild
is checked byte for byte. No model or source-access attribution is inferred from
this snapshot. Readable aliases remain in the symbol table; generated assembly
paths are normalized to the build manifest so a clean extraction uses the same
function identities as the committed sources. Source formatting is retained to
preserve compiler behavior.

The 31 October 2026 app snapshot adds 22 independently verified C functions and
9,092 matching bytes, selecting 1,722 C functions. All 1,700 earlier C functions
and their compiler settings remain unchanged. New sources use the isolated
`snapshot31_verified.h` header and per-function
compiler settings. Duplicate non-target function bodies in three app drafts are
replaced by declarations, retaining line counts; their target functions are reverified.
Seven other app matches are not accepted by the standalone
comparison and remain assembly. No model or source-access attribution is inferred.

V-Rally and its original code/data belong to their respective rights holders. This repository grants no blanket license over recovered game code. Supply your own supported ROM. ROMs, extracted binary assets, compiler executables and generated assembly are excluded.

The generated build.py comes from RetroReversing/decompdecomp, a continuation of NDelic's decompdecomp and Sam Wolfs' decomp.wtf, and retains AGPL-3.0 licensing. The license is included under tools/. The preparation helper uses AGPL-3.0-only. Tool licenses do not establish rights to the game itself.
