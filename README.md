# V-Rally Edition 99 - Nintendo 64 matching decompilation

[![Progress](https://bytematch.dev/RetroReversing/v-rally-decomp.svg)](https://bytematch.dev/RetroReversing/v-rally-decomp)

An unfinished matching decompilation of the European revision 0 release (`NVLP`). It began with ROM-derived C from Claude Sonnet 5.5 (low effort) and GPT-6.1 Sol-directed sessions, and now includes a newer user-supplied decompdecomp export. See [NOTICE.md](NOTICE.md) for provenance.

## Verified checkpoint

- **1,751 selected C functions / 295,968 matching bytes**, about **52.29% of 565,980 detected candidate-code bytes**.
- **2,121 detected functions**; export includes **2,122 entries**, selecting **1,751 C and 371 assembly functions**.
- Full **12,582,912-byte original normalized cartridge rebuilt byte for byte**, with no C build fallbacks.
- The 29 October 2026 app snapshot adds **113 C functions and 54,932 matching bytes** over the 1,587-function checkpoint. Every previously selected C function is retained. The additional sources have isolated snapshot headers and the compiler settings used for their verification. Readable symbol aliases remain provisional.
- The 29 October app snapshot reported **1,706 matches**. Six remained assembly because they cannot yet be integrated faithfully into the standalone build: `func_8003354C`, `osCreateThread`, `guFrustum`, `guOrtho`, `osCreateViManager`, and `alEnvmixerPull` (3,116 bytes combined). Names and types remain provisional.


The latest 31 October checkpoint preserves the three trig/matrix helper matches (520 bytes) and adds `func_8006090C`: **883 instructions / 3,532 bytes**, verified through both the app's normal judge and the standalone build. All previously selected C remains intact, and the complete cartridge comparison passes. Its source formatting, isolated header context and unchanged KMC GCC 2.7.2 compiler profile are retained together.

The follow-up adds `func_8004C2B8` (**46 instructions / 184 bytes**) as an exact match. Reordering two independent struct-field stores produced the target instruction order. Its source, isolated header and compiler profile pass the standalone check, and the complete rebuilt cartridge remains byte-identical.

The next exact match is `func_8004A0A0` (**966 instructions / 3,864 bytes**). Its reconstructed C, isolated header and KMC GCC 2.7.2 `-g3` profile are retained together. Reusing an existing local for the masked width recovered the final register allocation. Helper expressions and local lifetimes are reconstruction choices, not evidence of the original source spelling. All earlier selected C is preserved.

The `sqrtf` match at `0x8008DFB0` is now included as C; its 2-instruction source and isolated compiler profile reproduce the target bytes.

This is a partial decompilation. Candidate boundaries, compiler identity, names and types remain provisional. Detected-code coverage is not a percentage of the whole game, and a matching build still uses original assembly for remaining functions.

The 31 October 2026 snapshot adds **22 verified C functions and 9,092 matching bytes** while retaining every one of the 1,700 previously committed C functions, including those not currently verified in the app. Seven additional app matches still fail standalone integration and remain assembly in this checkpoint. The new sources use a separate header and their recorded compiler flags.

The later 31 October matching session adds **four byte-exact C functions and 872 matching bytes**: `func_8001C2E4`, `func_800830C8`, `func_80086A34`, and `func_800988C8`. Their source formatting, isolated header, and verified compiler settings are retained. All 1,722 earlier C functions remain selected. Two additional non-matching draft improvements stay in the local app and are not counted here.

The follow-up export audit recovers **six previously excluded app matches / 3,116 bytes** into the standalone build. Five require the recorded KMC profile without `-g3`; `osCreateViManager` also needs an explicit eight-byte storage gap so its private BSS addresses agree with the original. All earlier C remains selected.

### Export audit

The fresh app export fell back to assembly for 57 entries. Independent compiler/link checks explain every case:

- **52 compiler-profile mismatches:** the same app C and header match when `-g3` is omitted. Of these, 47 already had verified C preserved in this repository; the other five are now integrated. Debug options change the resulting instruction stream with this period toolchain, so compiler settings must be retained per function.
- **4 translation units with extra function bodies:** their target function matches, but exporting all the bodies would overlap other functions. The repository already contains verified versions with unused bodies replaced by declarations.
- **1 private-data layout mismatch:** `osCreateViManager` has correct instructions, but the initial BSS offsets require two different section bases. An explicit eight-byte gap after its thread storage and an adjusted stack alignment make every BSS reference use the same verified base. The gap is a reconstruction choice, not a claim about the original source declaration.

The app's saved matched count can therefore exceed what a fresh export rebuilds as C. Preserve the source, header context and compiler profile that passed verification together, and recheck a match when any of them changes. The combined checkpoint below passes the full cartridge comparison.

The latest verified sync adds **two C functions / 668 matching bytes**: `func_80085C58` and `__osCheckPackId` (exported as `func_80096104`). All earlier C is retained. The app reports **50.0%** using its eligible-code denominator; the standalone figure above uses all detected candidate-code bytes. The complete cartridge remains byte-identical.

### Complete app progress snapshot — 31 October 2026

The latest complete sync adds **five C functions / 5,376 verified bytes**: `func_80022BE8`,
`func_80026ED4` (820 instructions), `func_8003035C`, `func_8003E4A8`, and `func_80053F44`.
All previously selected C is retained. A recount also corrects the older summary: the previous
checkout selected 1,746 C functions / 290,592 bytes, rather than the stale 1,741-function figure.
Each addition passed its standalone compiler/link check,
and the complete original cartridge rebuilt byte for byte. Objdiff metadata and per-function
compiler profiles are updated together.

[`progress/`](progress/README.md) is a portable snapshot of the complete decompdecomp PAL project:
**1,751 recorded matches and 349 saved best attempts**, with names, headers, notes, symbols and
compiler settings. Best attempts are drafts, not additional matching C. The saved project and
standalone build use different selection histories; the verified standalone totals above remain
the build's authority. Future progress commits include the whole app snapshot, not just the
last function discussed. This is an explicit snapshot, not continuous automatic synchronization.

## Build

Use Python 3.12+, uv and a platform supported by [RetroReversing/decompdecomp](https://github.com/RetroReversing/decompdecomp). The combined export was verified using tool revision `4030a3ba87fe583be8506a712da167f1c7696746` and its pinned toolchains. Most functions use KMC-compatible GCC 2.7.2; per-function ranges also select IDO 5.3 and SN GCC 2.8.1. Install required proprietary tools only after accepting their licensing conditions. This is a working compiler hypothesis, not proof of the game's original compiler release.

```sh
git clone https://github.com/RetroReversing/v-rally-decomp.git
cd v-rally-decomp
uv venv --python 3.12
uv pip install --python .venv/bin/python "decompnet @ git+https://github.com/RetroReversing/decompdecomp.git@4030a3ba87fe583be8506a712da167f1c7696746"
.venv/bin/decomp setup
.venv/bin/python tools/prepare.py "/path/to/your/V-Rally Europe ROM"
.venv/bin/python build.py
```

Preparation detects byte order from the ROM magic and verifies the fixed hash. Your original stays untouched. The build regenerates assembly and assets locally; keep those files private. On Apple Silicon the period KMC tools require Rosetta. Windows uses the equivalent environment executables and supported toolchain setup described in the fork's README.

Expected final comparison:

```text
identical: build/game.z64 matches baserom.z64 byte for byte (1751 of 2122 functions in C)
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

Reports distinguish completed/linked progress from raw object matching.
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
