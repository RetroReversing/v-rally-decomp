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
remain progress rather than verified source. Later privately verified Status
and Compare accessors are not counted in this checkpoint.
