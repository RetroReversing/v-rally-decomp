# Alternate packed record decoder investigation

The saved score-1000 source mutates invariant temp_s3 with <<=6 and duplicates an identical tail behind an artificial condition. Corrected source removes both. Frozen G8 profile produces unsupported .lit8 relocation; standard KMC GCC 2.7.2, -G0 -mips3 -mgp32 -mfp32 -O2 -g3 clean source is3004. Natural separate A/B tails improve1035; sound invariant-pointer recomputation improves945 under that standard profile, still NONEXACT with local .rodata mapping problem. Lower score is not directly comparable to frozen-profile1000. Best research SHA256 88b6fe6ba9aeb871805930fa253eb3eda1611df6daa5283049c4e9dcf9b7e7ec; see docs/matching-experiments/func_8006BA44-nonmatching-alternative.c. Final lane1000 native judgments found no exact; interrupted preliminary lanes and directed probes retained privately. Rejected unsafe perm_expand_expr: it recomputed captured row pointer after temp_s0 became decoded hv, changing later store addresses. The shared captured-expression safeguard was subsequently merged in decompdecomp PR #524: https://github.com/RetroReversing/decompdecomp/pull/524 . It rejects expansion after an operand changes while retaining eligible pre-mutation reads. Actual pinned-tool and C90 execution regressions passed; this is a safety improvement, not a new game match. Exact readonly constants verified: threshold2^31, factors4.5 and1.5. Explicit threshold and type/profile probes not exact. OPEN/revisitable; no live profile, target, ABI or judge edits; no standalone C selected.

## Byte-argument and literal-pool revisit

Fresh read-only capture remains OPEN1000, unclaimed. Six new semantically
admissible source probes were compiled under the unchanged KMC2.7.2 profile
`-G8 -mips3 -mgp32 -mfp32 -O2 -ffast-math -fno-strength-reduce -g3`.
Four exploratory shared-tail probes were excluded after finding inherited
artificial duplicate branches in a legacy baseline; two clean probes replaced
them. No native search was repeated. Actual caller/callee instructions support
byte arguments. The corrected natural provisional source is preserved beside
this note, but it is not a placed or exact candidate.

The provisional diagnostic1735 includes unsupported R_MIPS_LITERAL8; the
explicit original-threshold variant links without problems and scores2642.
A controlled G0-only profile hypothesis yielded diagnostic1545 for the natural
source and945 for the old audited best, both with unresolved anonymous pool
placement. The normal explicit-threshold alternative remains nonexact2642.
No profile was selected or altered in the live project. Lower diagnostic scores
with unresolved references are not improvements eligible for acceptance.

Private ELF inspection confirms literal relocation8 against the generated double
pool, with a signed addend offset by the assembler's GP value. The object GP is
not the game GP. The target uses an absolute threshold reference at another
instruction site. Raw ELF, assembly and ROM-pool captures stay private.
The existing type7 GPREL16 path is not a substitute for unsupported type8, and
literal support would still require actual target GP and address witnesses.


The target has no known GP and no GP instructions. Its absolute threshold
reference is at different instruction offsets from the candidate literal load.
Neither a guessed GP nor value-based pool placement is justified. A clearer
GP/literal diagnostic is useful; relocation support alone cannot solve this
function. The function remains OPEN. No live edit, accepted match or full
cartridge build was claimed for this provisional source.

### Compatible legacy byte-parameter interface control

The selected downstream byte-argument callee and an old-style C definition with
byte parameter declarations plus an integer prototype both reproduce exactly
the same linked bytes (SHA256
`64ccbfe0da49646ab64e535c5442b6b1f8e406153adb63a87642a8c6b47d807b`).
The old-style source SHA256 is
`9a4f7453cb3fa33842892ec998efb6cd5c2427e5a03da4a1897140726bd35758`.
This is a joint source-interface hypothesis: default argument promotions make
the integer prototype compatible with that old-style definition in period C,
not with the original ANSI byte-parameter definition. A C11 pedantic syntax
control also accepts this combination, with a deprecation warning; it is not
C23 syntax and must not be generalized to modern-language projects.

Using the compatible integer interface in the clean caller did not solve the
function: original G8 natural source1135 (unresolved literal8), explicit
threshold3099 without link problems; frame remains the target size. A final
G0-only natural control scores945 but still has its pool-address instructions
at different offsets from the target, so ordinary linking rejects placement.
It is byte-identical to the earlier audited-best diagnostic control, which
contains no artificial branch. No best-source portfolio, selected profile,
live callee correction or accepted match resulted from these controls.
