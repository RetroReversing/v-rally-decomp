# func_8007B4A4 — private investigation

No exact match. The function remains OPEN, score 330, unclaimed at the final readonly check. No live project, canonical repository, runtime or profile edits were made.

Frozen app revision 045c7eb2, effective header and symbols/target/profile in frozen/inputs.json (SHA256 d3ccd904b74ce81c1712740a522a08e9a63e0901d7552c661149a8ff28c12b8e). Compiler gcc-2.7.2-kmc: -G0 -mips3 -mgp32 -mfp32 -O2 -ffast-math -g3. ROM SHA256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7.

## Audited alternative

clean.c SHA256 cdb68a244649bb04c21cc0f8046ccd430bea4f97a8221ff05f5fd9b94ae2d3fb retains linked advisory score 330. Unlike the saved seed it uses unsigned color/packing temporaries, so c<<24 and color additions do not overflow signed int, and unsigned coordinate differences before the existing halfword truncation. No uninitialized variables, fake branches or volatile found/added. Struct offsets match target: V16 size16 col12; V24 size24 xyz4/6/8 col0; LObj v24=0x30 v16=0x60 n16=0x90 n24=0xA8.

This is game-domain C, not a universal input proof. Requires valid aligned pointers and array lengths indicated by the counts, nonzero vector lengths, and finite floating results representable by the target float-to-u32 casts. The source preserves the target's normalization, divide and conversion behavior rather than adding clamps or zero-vector guards. Initial coordinate casts implement wrapping before existing signed halfword truncation; inner L->b coordinates hold prior s16 values under the normal nonaliasing game-object layout.

Matched neighbor func_8007BA1C confirms the same light/camera globals and float/coordinate record, but does not provide an alternate matching donor for the two vertex loops.

## Searches

- 1,000 independent native candidates from this one audited baseline; no selected-best portfolio. Filtered stale expand_expr lineages before string conversion and rejected asm/volatile/register and compiler uninitialized warnings. No match or improvement. Sources and results preserved in native-independent. Caveat: the regex enforcing static inline helper definitions converted TracedVariant to str, so stored lineage metadata is empty; filtering occurred before conversion. The future script preserves metadata. No candidate was selected as new best.
- 20 directed controls: packing declaration permutations, u8/u16/s32 color widths, distinct float-ratio lifetime, V24 root/member staging, packing reassociation. Best330; narrowing color worsened1495/1105, reassociation1315/865.
- 57 scope/line-boundary controls: plain blocks and blank lines generally neutral; do0 around first color assignment350, conversion410; pointer and full initialization scopes1842/1857. No improvement.
- 32 targeted float lifetime/statement/scope controls: ratio/distance staging, splitting multiply/divide and dot additions. Best330; split multiplication350, dot550, separate distance775. No changed floating operation association accepted.
- Nine flags controls: no-strength-reduce2790, no-expensive-optimizations1546, no-schedule-insns7518, no-schedule-insns2 2315, neither8554. no-cse-follow-jumps/no-gcse/no-thread-jumps/no-caller-saves neutral330. No profile changed.

Residual same-size mismatch:42 register positions and4 reordered positions. Color result c and hi occupy v1/v0 instead of target v0/v1; second vertex root/color-pointer a2/a1 rather than a1/a2; first fade ratio remains f4 instead of f2; invariant 2^31 float constant loads after rather than before full/ambient setup. No semantic rule has been proven from these residual register choices. Parent is separately testing real tag/final color packing and loop-local packing lifetimes.

Final nine explicit brightness/u32-conversion capture controls, first loop/second loop/both: all330, no exact. Parent six packing/lifetime controls: loop-local360; directtag2115/1975/2360. No reusable automation rule proved.

Parent final controls: moving the full-color assignment into its only consuming branch (first loop, second loop, both) preserves the330 score in all three cases. These remove a redundant assignment on other paths; no new instructions or false branches were added. No exact result.

## Current structural and regional controls

A fresh revisit tested 107 new grounded controls without a match. Correct unsigned
packing and actual helper declarations preserve 310. A 32-byte fixed matrix model
scores 322. Actual position arrays/records, genuine normalized-direction and relative
Float3 objects, color lifetimes and meaningful lighting helpers do not improve it.
No unsupported 48-byte object was introduced to force the target frame.

The independent US counterpart `8007CA54` is also OPEN. It has the same 0x70 frame and
p/q/m locations. Its matrix-vector routine is byte-identical to the PAL target;
both transpose implementations access a 32-byte representation. The extra US
instructions concern loop-address recurrences, not new matrix fields or lighting
math. The first 85 instruction patterns agree after address/callee substitution.
This supports the model but does not provide verified donor C or identify a flag.

Forty-eight normal installed period profiles and four additional debug controls on
the actual 32-byte matrix source find no exact result. No download, profile adoption
or selected C change occurred. A read-only mnemonic search found no matched US donor
above 0.85 similarity for any of the 18 remaining PAL functions; this is a search
result, not proof of semantic dissimilarity. Revisit only with a new grounded stack
allocation, source or compiler mechanism. Function-specific app notes retain these
negatives and the unsafe signed-packing warning.

## November 6: measured packing and conversion progress

Current live source remains OPEN310, unclaimed and unchanged. That score is not a
correctness baseline: the saved source still has signed overflowing color shifts
and an unsupported 48-byte matrix extent. The corrected 32-byte matrix and
unsigned-packing draft scores322. A fresh compiler-phase investigation now gives
new evidence, rather than another profile/native/whitespace sweep.

Preserving low-first order, split each `hi = (c << 16) + tag` into
`hi = c << 16; hi += tag;`. Across all six packing sites this removes30 register
differences, score172. Individual-site edits remain322. Initial RTL creates a local
shifted temporary for the expression, whereas the staged form reuses the global
high pseudo. Its use count rises24 to60; allocator order changes and color loses a
hard-register2 conflict. The earlier FP-conversion-clobber explanation was rejected
by the live ranges. Ordinary and `-da` builds link identically for each input.
Parent independently reproduced322/172 and the final generated combined repair172.
App PR639 (`cd710019`) implements bounded `unsigned_shift_staging` through shared
repair generation, with visible unsigned-int bindings and invocation/escape guards.
231 focused/shared tests pass; compiler-guide/ledger updates distinguish this
improvement from an exact match.

A further full unsigned conversion helper preserves both low and high range paths,
including the2^31 subtraction and high-bit OR. A genuinely consumed early boundary
value fixes constant-load ordering. Compiler assembly shows a debug-line label
causing the assembler to add a NOP; putting the two actual independent setup
assignments on the same physical line removes that barrier. Staging the converted
high value before its OR fixes four more register positions. Parent independently
reproduces score52, with the correct350 instruction count. It is still NOT exact:
eight vertex-root/derived-position register differences and twelve frame offsets
remain; actual frame0x60 versus target0x70.

Real address-taken normalization components produce the desired rounded frame but
retain six stores and regress. No dummy escape, invented matrix padding or
uninitialized storage is a valid remedy. The private API correction also needs the
sole selected caller1A340 to declare `void(void *,s32)`; its actual `(lists,0)` call
is preserved and that declaration-only caller test is exact under its own profile.
The focal API consumes `void *owner` and has the observed unused second formal.
A flat nine-halfword matrix rotation and three-element p/q arrays preserve172.
Neither caller correction nor focal draft is accepted into the live project yet;
a future exact result requires the joint contract and whole-cartridge gates.

The usual live-object bounds, nonzero finite vector normalization, float conversion
range, alignment and effective-type/lifetime assumptions remain explicit. Actual
ambient writers do not prove a global0..255 bound, so no signed-conversion shortcut
or elided high-range branch is justified. Private evidence is retained separately;
no cartridge data or compiler dumps are published here.

Final bounded-revisit source SHA256:
`d457155effea643fb9755e667a9d39969d566c516432f4c80995f8ab41b646cd`.
Ordinary and diagnostic builds produce identical1,400-byte linked code, SHA256
`edcd5058b3efeaf8838b3ffbb7cbc761c69350a8cfa9a3edc4f0bc9fe3b2268a`.
Two genuine Vec3-by-value normalization helper controls retain aggregate traffic
and regress to3559/3142, with frames0x78/0x80. An indexed-vertex control also fails.
No justified exact frame/pointer repair was found. Live inputs and ownership are
unchanged; retain the function as OPEN and revisitable without calling this52 an
accepted match or repeating these failed controls.
