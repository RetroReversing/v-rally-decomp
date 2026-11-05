# Final byte-update loop investigation

The 215-instruction function remains OPEN at advisory score 140. The ordinary
linked-byte judge is nonexact. Its Stat, Game/Slot and Record layouts agree with
observed offsets and strides. Only the final two four-byte update loops differ:
the index and loaded/result byte occupy exchanged registers. Some advisory operand
differences are symbol annotations, not a reason to change targets or acceptance.

A bounded pass tested 1,000 native variants, 20 current first-page repair proposals,
149 helper manual compilations and 86 parent probes. No exact candidate emerged.
The nonmatching alternative beside this note declares the adjacent signed-halfword
pair as a two-element array while retaining the separate physical alias store.
It still scores 140 and is not selected in the standalone build.

Sound alternative SHA-256:
`3a861e2674587cb279027607eb171b5ff9fe8c1a80e206edc997b33e4800884f`.
No cartridge verification is claimed for this alternative. Compiler settings, target
bytes and previous verified C are unchanged. Negative results leave the target
available for future work; they do not prove it cannot be matched.
