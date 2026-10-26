# V-Rally Edition 99 - Nintendo 64 matching decompilation

[![Progress](https://bytematch.dev/RetroReversing/v-rally-decomp.svg)](https://bytematch.dev/RetroReversing/v-rally-decomp)

An unfinished matching decompilation of the European revision 0 release (`NVLP`). It began with ROM-derived C from Claude Sonnet 5.5 (low effort) and GPT-6.1 Sol-directed sessions, and now includes a newer user-supplied decompdecomp export. See [NOTICE.md](NOTICE.md) for provenance.

## Verified checkpoint

- **1,437 selected C functions / 155,380 matching bytes**, about **27.45% of 565,980 detected candidate-code bytes**.
- **2,121 detected functions**; export includes **2,122 entries**, selecting **1,437 C and 685 assembly functions**.
- Full **12,582,912-byte original normalized cartridge rebuilt byte for byte**, with no C build fallbacks.
- The 26 October 2026 app snapshot adds **45 exported C functions and 16,772 matching bytes** over the 1,392-function checkpoint, retaining every previously selected C function. It also exports **27 improved function names**, including SDK and audio routines.
- The app reports one additional match, `osCreateViManager` (416 bytes). Its associated data layout cannot currently be represented by the exporter, so this repository deliberately keeps it as assembly and excludes it from the selected C totals. Names and types remain provisional.


This is a partial decompilation. Candidate boundaries, compiler identity, names and types remain provisional. Detected-code coverage is not a percentage of the whole game, and a matching build still uses original assembly for remaining functions.

## Build

Use Python 3.12+, uv and a platform supported by [RetroReversing/decompdecomp](https://github.com/RetroReversing/decompdecomp). The combined export was verified using tool revision `2084cdb66947eed55cba580457fc07cbcd5735f3` and its pinned KMC-compatible GCC 2.7.2 toolchain. This is a working compiler hypothesis, not proof of the game's original compiler release.

```sh
git clone https://github.com/RetroReversing/v-rally-decomp.git
cd v-rally-decomp
uv venv --python 3.12
uv pip install --python .venv/bin/python "decompnet @ git+https://github.com/RetroReversing/decompdecomp.git@2084cdb66947eed55cba580457fc07cbcd5735f3"
.venv/bin/decomp setup
.venv/bin/python tools/prepare.py "/path/to/your/V-Rally Europe ROM"
.venv/bin/python build.py
```

Preparation detects byte order from the ROM magic and verifies the fixed hash. Your original stays untouched. The build regenerates assembly and assets locally; keep those files private. On Apple Silicon the period KMC tools require Rosetta. Windows uses the equivalent environment executables and supported toolchain setup described in the fork's README.

Expected final comparison:

```text
identical: build/game.z64 matches baserom.z64 byte for byte (1437 of 2122 functions in C)
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

## ByteMatch progress reports

`tools/progress.py` runs the full verified build, assembles the original comparison
objects, and regenerates `objdiff.json` from `build.json` and the source tree.
Then run `objdiff-cli report generate -o build/NVLP/report.json` (create
`build/NVLP` first). Unit names follow the source folders. Assembly-only functions
compare against an empty object and remain incomplete; their source path records
the ROM-generated assembly, which is intentionally not published. ByteMatch
can show the committed C; generated assembly has no public source to display. The report step
regenerates `include/bytematch_names.h` from the compiled C symbols so ByteMatch
can find readable names that differ from the original report symbols. This
header is not included by the build. There is
no separate list of functional, non-matching C, so no `functional.json` is emitted.

The refreshed report records 1,437 completed units (155,380 bytes) and 1,432
raw object matches. The report distinguishes completed/linked progress from raw object matching.
Some linked C units can have small object-level differences even when the full
cartridge is identical; neither measure is a whole-game completion percentage.

The workflow uploads only `NVLP_report`, containing `report.json`, on main pushes
or manual dispatch. It requires a **dedicated self-hosted runner** labelled
`bytematch`, with Git and a supported build host (including Rosetta on Apple Silicon).
CI installs Python, the pinned build dependency, and its pinned objdiff tool. Set repository Actions variable
`NVLP_ROM_PATH` to an absolute path to your legally supplied ROM **outside** the
checkout. No secrets or ROM uploads are used. Do not enable pull-request triggers
on this runner. A hosted runner cannot rebuild this project without game data.

After ByteMatch has read a successful default-branch run, use its source-link
checker as described in [the source-linking guide](https://bytematch.dev/docs/source-linking):

```sh
python3 /path/to/ByteMatch/scripts/check-source-links.py RetroReversing/v-rally-decomp --version NVLP
```
