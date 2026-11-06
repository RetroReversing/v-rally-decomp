# Unsigned 64-bit tail dispatcher

The six-instruction `func_8009A2B0` tests `a2` and jumps to one of two arithmetic
helpers. A direct caller supplies a 64-bit numerator in `a0:a1` and denominator
in `a2:a3`, and consumes the quotient in `v0:v1`. Both helpers corroborate
unsigned division. Earlier 32-bit wrapper attempts did not model this ABI.

KMC GCC 2.7.2 has self-tail-recursion optimization, but its ordinary external
calls emit `jal` and clobber `ra`. Registered GCC 4.4 provides genuine sibling
calls and compiles ordinary unsigned-64 forwarding C to the exact target.
No assembly macro, fixed registers, padding or dead work is used.

Profile: `gcc-4.4.0-n64 -G0 -march=vr4300 -mabi=32 -mno-abicalls -fno-pic -O2`.
The live app and portable snapshot use a function-specific profile. The frozen
standalone build uses an equivalent unique 24-byte range, preserving every
previous selection. This proves a modern compiler reconstruction; original
handwritten SDK provenance remains, and no original retail GCC 4.4 use or exact
SDK symbol name is asserted.

Validation: actual shared header and source prelude; ordinary/`-da` linked raw
parity; normal copied app claim/compile with all 2,076 source hashes/profiles
preserved; normal live acceptance and complete portable save; full 12,582,912-byte
cartridge equality, SHA-256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.

The app improvement is RetroReversing/decompdecomp PR #688: bounded raw-pattern
advice asks for caller/callee ABI and compiler capability before more variants.
It does not infer 64-bit types, change profiles or accept matches automatically.
