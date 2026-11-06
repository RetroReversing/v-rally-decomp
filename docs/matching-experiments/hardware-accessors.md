# Fixed architectural SDK accessors

## Verified and adopted: 6 November 2026

The FCSR exchange (`__osSetFpcCsr`, canonical `func_8008D630`) and Count read
(`func_800937B0`) are retained SDK hardware operations represented by fixed,
registered compiler intrinsics. This does not establish that their original
implementation was ordinary C. Source cannot select instruction streams or
general-purpose registers; the compiler allocates operands and emits returns.
The fixed templates are preserved in the standalone headers.

Pinned GCC 2.7.2 KMC flags: `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`.
Both accessors have independently equal ordinary and `-da` target bytes.
Two caller return declarations were corrected to unsigned 32-bit words and
remain byte-identical. The complete 12,582,912-byte cartridge is equal, SHA-256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All previous effective profiles and unaffected selected objects are preserved.
Normal app verification accepted both new sources and caller corrections;
other selected source hashes were compared before and after each operation.

The app improvements are merged in decompdecomp PRs #672 and #674. Their
bounded leaf seeds propose source for normal verification; they do not reopen
assembly automatically. Privilege, wrapping and ordering limits are documented
in the compiler guide. Volatile memory clobbers do not make these operations
general barriers for unrelated register expressions or interrupt atomicity.

The live snapshot is 2,073 matched, 16 open and 32 retained assembly entries.
The standalone export additionally preserves three coverage entries, so its
objdiff configuration has 2,124 units, 2,073 selected from C. Unmatched drafts
remain progress rather than verified source. At that checkpoint, the later Status
and Compare accessors were not yet counted.


## Status read and Compare write: subsequent 6 November checkpoint

Normal verification has now accepted `func_800937C0` (Status read) and
`func_800958F0` (Compare write), plus the unsigned Status-read declaration in
the initialization caller. Both new architectural sources are exact in ordinary
and diagnostic compilation; the complete cartridge remains byte-identical with
2,075 selected C functions. All previous effective profiles and unaffected C
objects were preserved. Existing caller declarations already agree with the
Compare writer's unsigned word input, whose hardware timer-interrupt clearing
side effect remains explicit.

The Status and Compare app improvements are merged in PRs #675 and #676.
All prior 2,073 live source hashes were preserved during the two promotions;
the later caller correction preserved the other 2,074 selected sources. The
full refreshed portable snapshot includes drafts and all metadata, not just
these three source files. Current live state: 2,075 matched, 16 open, 30 assembly.

The separately exact Status return-spacing accessor is not yet adopted in this
checkpoint. That narrower operation avoids a documented ITS immediate-branch
stall; it is not a general Status completion barrier. Handwritten provenance
and privilege/hazard caveats continue to apply to every accessor.
