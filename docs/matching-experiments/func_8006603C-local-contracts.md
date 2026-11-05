# Local renderer interface corrections

Seven already-matched sources were corrected together. These are not new matches.
All seven passed ordinary linked-byte checks and an independent complete
12,582,912-byte cartridge build, preserving all 2,069 compiler profiles and the
other 2,062 selected C objects. Cartridge SHA-256:
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.

All seven live source hashes were confirmed matched after the normal saved-file
import. The complete progress snapshot is exported alongside the selected C.
The parent additionally found zero aligned absolute ROM pointer words and zero
non-call address relocations referencing either changed interface. Dynamically
computed addresses are not excluded by that check; global soundness is not claimed.

# Seven local callee/caller corrections

No new matched function. All seven are already selected matches. No live or canonical mutation was made. Each candidate uses its own frozen source/header/profile/target/symbols. All seven ordinary pinned linked instruction hashes equal their full target hashes; nonzero canonical-diff scores20/10 are relocation-display differences, not raw differences.

61F34 is a matched void(void) body with three actual raw JAL callers:6603C,71B3C,63FFC. Each already passes two arguments in a0/a1. Selected body overwrites argument registers and never reads entry values. Correct definition uses void(void *scene,void *base), retaining actual ignored arguments without fake use or dummy work. Both matched callers now have matching void(void*,void*) declarations.63FFC's second actual is an integer representation of the real record-base address, explicitly converted to void* for the pinned32bitMIPS model. No narrowing, extra memory operation or object-bound change is introduced. The remaining OPEN6603C provisional corrected-final.c already declares this interface; old invalid200 still declares SceneState*,u8* and needs later normal correction.

5C0E8 is a matched body with three actual arguments start(s32),offset(u32),end(u32). Its unused fourth u16 formal is never read. All seven raw JAL sites across six callers supply only three arguments; no source fourth actual exists. Definition drops only unused fourth formal. Five matched caller declarations corrected to void(s32,u32,u32):66E20,70630(two sites),70A34,71B3C,63FFC. Existing OPEN6603C provisional corrected-final.c already uses these exact three formal types. Integer arguments converted to u32 preserve the real32bit values; individual rawlinked proof verifies each full function. Calls ignore the genuine void return. No variadic or unspecified-function workaround, invented fourth argument, force-register directive, target change or profile change.

raw-jal-callers.json records direct target-derived callers for these two interfaces and the broader592AC dependency. All selected project sources were also scanned; no additional 61F34 or5C0E8 references beyond the known declarations/calls were found. Full indirect ROM pointer-table audit for these seven is pending parent scope check; no changed function's address was intentionally replaced. Global source type consistency is NOT asserted: legacy592AC/592D0/5A744 return/representation defects,61F34 own external prototypes, and oldOPEN6603C invalid predicate/interface remain separate. This package does not authorize acceptance of the305focal seed or erase those dependencies.

The corrected6603C positive conjunction is still nonexact305. It is outside this seven-member existing-match package; parent owns independent full cartridge gate and all integration.

## Acceptance scope

The audit above describes the private proposal before integration. Its pending
absolute-pointer-table check was subsequently completed as described above.
The separate 592AC/592D0/5A744 representation closure remains private and is not
part of these seven accepted sources. The old OPEN6603C predicate is still
invalid; the nonexact corrected seed is not accepted by this change alone.
