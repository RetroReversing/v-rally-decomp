# Provenance and licensing

This unfinished matching decompilation combines ROM-derived C from Claude Sonnet 5.5 sessions at low effort and a GPT-6.1 Sol-directed session, using decompdecomp, m2c, compiler feedback and local search/permutation tools. The latest Claude session's 1,000-function export was combined with four previously verified functions it did not select; the combined 1,004-function checkpoint passed the full cartridge rebuild. The supplied sessions did not consult original V-Rally source.

The 25 October 2026 update imports additional matching C, compiler settings and a shared prototype from the user-supplied `v-rally.zip` export. It retains the earlier 1,004 C functions and selects 1,392 after integration. The archive does not establish the model or source-access conditions of this additional work; no new attribution is inferred.

V-Rally and its original code/data belong to their respective rights holders. This repository grants no blanket license over recovered game code. Supply your own supported ROM. ROMs, extracted binary assets, compiler executables and generated assembly are excluded.

The generated build.py comes from RetroReversing/decompdecomp, a continuation of NDelic's decompdecomp and Sam Wolfs' decomp.wtf, and retains AGPL-3.0 licensing. The license is included under tools/. The preparation helper uses AGPL-3.0-only. Tool licenses do not establish rights to the game itself.
