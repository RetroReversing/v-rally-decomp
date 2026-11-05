# Remaining-function other-region audit

Read-only comparison with the other imported V-Rally region. Exact means a
relocation-normalized machine fingerprint, not matched C or an accepted transfer.
Nearest candidates compare instruction mnemonic sequences; matching mnemonics
alone do not establish relocation identity or a safe source mapping.

| PAL function | Exact fingerprint counterpart | Closest candidate (similarity) |
|---|---|---|
| func_80029EAC | func_800292C4 (open) | func_800292C4 (open, 1.000) |
| func_8002FFA4 | func_8002FEE4 (open) | func_800300C0 (open, 1.000), func_8002FEE4 (open, 1.000) |
| func_80030180 | func_800300C0 (open) | func_800300C0 (open, 1.000), func_8002FEE4 (open, 1.000) |
| func_8003E6D8 | None | func_8003EA5C (open, 0.904) |
| func_80040CF4 | None | None above 0.9 |
| func_80043A78 | None | func_80043CB8 (open, 0.990) |
| func_80049DB0 | None | None above 0.9 |
| func_80059A60 | None | func_8005A7B0 (open, 0.963) |
| func_8005E49C | None | None above 0.9 |
| func_8006603C | None | func_80066924 (open, 1.000) |
| func_8006BA44 | None | func_8006C374 (open, 1.000) |
| func_8006C024 | None | func_8006C954 (open, 1.000) |
| func_8006D10C | None | func_8006DA3C (open, 1.000) |
| func_8006E394 | None | func_8006ECEC (open, 1.000) |
| func_8007A29C | None | None above 0.9 |
| func_8007B4A4 | None | func_8007CA54 (open, 0.969) |
| func_80086F40 | None | None above 0.9 |

All listed counterparts are OPEN. No matched other-region source was found
for a direct transfer to these remaining functions. The separate 529F0 audit
also found an OPEN counterpart without saved C. This rules out that particular
source of free matches at this checkpoint; it is not an impossibility verdict.
No live project or target was changed.
