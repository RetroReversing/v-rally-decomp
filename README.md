# V-Rally Edition 99 - Nintendo 64 matching decompilation

An unfinished matching decompilation of the European revision 0 release (`NVLP`), combining ROM-derived C from Claude Sonnet 5.5 (low effort) and GPT-6.1 Sol-directed sessions. Existing original game source was not consulted in these sessions.

## Verified checkpoint

- **1,004 selected C functions / 72,604 matching bytes**, about **12.83% of 565,980 detected candidate-code bytes**.
- **2,121 detected functions**; export includes **2,122 entries**, selecting **1,004 C and 1,118 assembly functions**.
- Full **12,582,912-byte original normalized cartridge rebuilt byte for byte**, with no automatic C fallbacks. Reconstruction in the supplied ROM's original byte order also matched.
- Claude's latest verified export selected 1,000 C functions. The combined checkpoint retains four previously verified functions absent from that export and adds 312 new functions over the prior 692-function repository state. All 1,004 pass together in the full cartridge rebuild.

This is a partial decompilation. Candidate boundaries, compiler identity, names and types remain provisional. Detected-code coverage is not a percentage of the whole game, and a matching build still uses original assembly for remaining functions.

## Build

Use Python 3.12+, uv and a platform supported by [RetroReversing/decompdecomp](https://github.com/RetroReversing/decompdecomp). The combined export was verified using tool revision `72cac6c9df215754aae698283cafc68b3ed26bb3` and its pinned KMC-compatible GCC 2.7.2 toolchain. This is a working compiler hypothesis, not proof of the game's original compiler release.

```sh
git clone https://github.com/RetroReversing/v-rally-decomp.git
cd v-rally-decomp
uv venv --python 3.12
uv pip install --python .venv/bin/python "decompnet @ git+https://github.com/RetroReversing/decompdecomp.git@72cac6c9df215754aae698283cafc68b3ed26bb3"
.venv/bin/decomp setup
.venv/bin/python tools/prepare.py "/path/to/your/V-Rally Europe ROM"
.venv/bin/python build.py
```

Preparation detects byte order from the ROM magic and verifies the fixed hash. Your original stays untouched. The build regenerates assembly and assets locally; keep those files private. On Apple Silicon the period KMC tools require Rosetta. Windows uses the equivalent environment executables and supported toolchain setup described in the fork's README.

Expected final comparison:

```text
identical: build/game.z64 matches baserom.z64 byte for byte (1004 of 2122 functions in C)
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
