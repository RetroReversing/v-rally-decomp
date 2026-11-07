# func_8008B624: handwritten SDK queue pop

## November 7: positive source provenance and returned-head ABI

The clean nested ultralib checkout used by the local Snowboard Kids 2 project
contains LEAF(__osPopThread) in src/os/exceptasm.s:1187. Provenance is
https://github.com/cdlewis/ultralib at commit
c2badeea898d1de3b3722a2c038e5d9597a477b8. The tracked source matches HEAD;
THREAD_NEXT is zero. The parent game checkout being dirty does not imply this
nested Git checkout is dirty.

The primitive loads the old queue head into v0, reads its next pointer into t9,
writes that pointer through a0, and returns the old head. Scheduling the store
into the return delay slot agrees with the four target instructions. This is
source-level correspondence and raw target inspection, not a newly assembled
or linked donor-object comparison. No donor object or full cartridge was built.

The 16-byte boundary ends at the next function, 0x8008B634. All seven observed
direct JAL callers consume the returned v0 as a thread pointer. This supports
OSThread* __osPopThread(OSThread**) and contradicts treating the best void draft
as a complete semantic model. It does not exclude unobserved computed calls.

The unusual scratch register has positive handwritten-source provenance. t9 is
a caller-clobbered general register, not the assembler temporary (at). Existing
typed returned-old, const, volatile, comma-return and register-keyword controls
already score 10 across 105 hydrated attempts. No new pure-C control was
justified. Forcing t9, adding artificial register pressure, or embedding the
whole assembly body would not establish a recovered C match. This is not a
theorem that every possible compiler/profile must fail.

Keep this genuine SDK assembly separate from matched C. The identification can
support an evidence-backed normal app rename without reopening or counting a
new match. No live rename, source adoption, compiler, Clang or generator ran.
All 2,077 selected full sources and compiler/context fields remain unchanged.
Private recovery-nov7/REPORT.md retains caller scans, donor hashes and final
read-only preservation evidence.
