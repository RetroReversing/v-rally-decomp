# Constructor and matrix-forwarding interface corrections

These are corrections to existing matched functions, not newly matched functions.

The 24-source constructor cluster passed an independent full cartridge build.
Adding the seven matrix-forwarding corrections also preserved all 12,582,912
cartridge bytes with 2,069 selected C functions. All compiler profiles remained
unchanged, and 2,038 other selected C objects were preserved. Cartridge SHA-256:
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.

The reconciled structured variant of func_8003A794 also passed the complete
cartridge build, preserving its newer structured body while correcting the
constructor declaration and incoming text-pointer type. All 31 corrected live source hashes were subsequently confirmed matched,
restoring the live total to 2,069 matched / 18 open / 34 assembly. The complete
normal progress snapshot accompanies this source integration.

## Constructor caller audit

# Changed-interface caller audit and24-member local correction set

All24 candidate sources have independent fully relocated raw exact proof under their original own profile/context. This directory supersedes the20-source proposal without modifying it. No live or canonical changes, claims or focal compiles were performed. The parent must review and regate this expanded set before acceptance.

## func_8003A794

Four direct rawJAL caller functions, one emitted callsite each:3D780 at8003D8E0;3D8F4 at8003D9B4;3E3E0 at8003E494;3E4A8 at8003E5E0. Selected source has multiple branch-specific C call expressions which the compiler merges into each single raw site. Every expression was corrected, not just one textual occurrence.

Old definition: `void(s32,s32,s16,void*,u8*,u16,u8*)`. New definition: `void(s32,s32,s32,SpriteHook,u8*,u16,u8*)`, with SpriteHook=`void(*)(void)`. Actual target already narrows y inside3A794 (sll at8003A7C8 and sra at8003A7D0); changing the incoming y formal to32 bits while retaining the real existing body casts preserves its target exactly. No constructor coordinate widening was necessary.

The three old unspecified upstream declarations returned s32, while selected callee returns void; their callback symbols3AD18/3B660/3B574 were also falsely declared object s32. They were NOT safe default argument conversions. Candidate sources replace them with the full matching seven-parameter function prototype, real callback function declarations, explicit SpriteHook casts from the actual function addresses, explicit u8* casts for existing integer-address text values, and normal prototype-driven u16/null pointer conversion.3AD18/3B574 have their real void(void*) declaration;3B660's void() declaration is compatible with its actual void(Obj*) function because pointer parameters retain their types under default promotions. It is used only to obtain/cast the function address, never called here.

3E4A8's old typed declaration was `void(void*,s32,s32,void(*)(),s32,u16,u8*)`, already incompatible with the original definition in its first/third/fifth formals. Its candidate declaration fully matches the new definition. Its first list address is explicitly converted to the existing s32 formal; its text address is explicitly converted to u8*; the actual callback address is explicitly converted to SpriteHook. These are real address/function-pointer conversions, not unchanged machine arguments being treated as implicit C conversions.

All four full-prototype caller controls with the old16-bit y formal were nonexact (1000,830,440,290) due new caller truncations. Widening the actual3A794 y formal as grounded above makes3A794 and ALLFOUR corrected upstream callers raw exact. No unsafe unprototyped declaration was restored to obtain a score.

## func_8003A9AC

Its sole direct raw caller is3D9C8, at8003DA80/8003DB2C/8003DC24/8003DCA4/8003DD40. Old definition forwarded a falsely object-typed s32* hook; old caller declaration/helper used void* hook and declared the seventh argument s32 while the definition takes u8*. Candidate definition/local use SpriteHook;3D9C8 now has the FULL matching prototype `(s32,s32,s32,SpriteHook,s32,u16,u8*)`, matching helper hook type, explicit function-pointer casts for3B310/3B240/3B2C0 and actual typed null seventh arguments. Both definition and caller remain raw exact. No other rawJAL or selected-source caller was found.

## func_8003C0CC

There are ZERO direct rawJAL callers and ZERO selected source declarations/call expressions outside its own definition. One aligned frozen-cartridge function-address entry exists at ROM0xA0A80 / VRAM0x8009FE80, in D_8009FE40's handler table. Actual selected dispatcher3FFB4 declares `void(*handler)(Obj*,u8*,s32)` and invokes three arguments. Original3C0CC was `void(Spr*,s32)`; candidate is `void(void*,s32)`. The original already had the wrong parameter count, incompatible first object-pointer type (Obj and Spr layouts differ) and incompatible pointer/integer second type for this indirect invocation. The candidate does not turn a previously compatible direct or selected indirect declaration into an incompatible one: this table invocation is explicitly defective both before and after. Dispatcher3FFB4 and its table are retained unchanged; no globally valid indirect call is asserted.

## Retained defects and evidence

The earlier explicit generic allocator missing optional third-argument read,80FE0 missing pointer return and40328 callback invocation-type defects remain UNFIXED. Existing integer-address representation interfaces outside the changed declarations remain outside this bounded proof.24 exact objects establish local byte preservation, not globally soundC.

Every member has `.inputs.json` with full frozen original function row/base64 target, project, symbols, own context/header/profile; `.original.c`, `.canonical.c` and `.proof.json`. Source/input/header/target/linked hashes are in manifest.json. The original18 constructor caller bodies and four added upstream bodies match canonical after export directives;802A0's canonical alias spelling difference was previously recorded. Full raw/source upstream reference evidence is in ../upstream-audit/raw-and-source-references.json; constructor coverage remains ../raw-direct-references.json (112 calls across19 functions). No further private compilation is needed for this proposal.

## Matrix-forwarding audit

# E514 coordinated declaration correction

Seven raw exact candidates, original selected C and complete own-context input captures are listed in manifest.json. All were unclaimed when frozen and before private compilation. Judge is pinned64a45869; equality compares LinkResult.linked_code, not relocatable candidate.code. No profile/target edits. No full cartridge gate or live writes performed.

Actual E3AC is void*(void*,void*,void*): it reads matrix halfwords0..8, vector halfwords0..2, computes into local out[3] before writing output halfwords0..2, and returns the output pointer. Thus input/output vector aliasing in focal and other callers is supported by real staging. E514 now explicitly forwards three pointer arguments and output return. No new narrowing conversions, extra loads/stores or dummy values. All matched callers change declarations only; public caller signatures remain unchanged, so no upstream signature correction is necessary.

Full target ASM search finds six matched callers and focal OPEN7B4A4:11178(4),21064(4),28740(1),35C4C(1),3647C(1),7BA1C(3),7B4A4(2). All arguments are pointer-valued, all results discarded. Focal compatible declaration exists separately in contracts.c but is nonexact and not part of seven-member gate.

## Retained downstream source defects, not newly introduced

E3AC signed sum arithmetic requires actual game-domain coefficient/vector bounds; this audit does not prove arbitrary-input no-overflow. Its typed halfword views must describe real array storage for strict C validity.

11178 uses actual s16m[9] in CarObj, s16mtx[16], s16vectors[3]; these directly meet focal matrix/vector read extents. 21064 uses s16localvectors[3], but matrix through owner bytes+0x40 still needs globally compatible object definition. 28740 has s16matrix[10], but its Vertex consists three scalar s16fields; E3AC output array access across scalar subobjects remains pre-existing incompatible representation. 35C4C and3647C use s32mtx[8] as halfword matrix and Part/Particle scalar-field output structs; both matrix alias typing and scalar-subobject stepping need real shared record reconciliation. 7BA1C uses s32m[8] as matrix and byte-array-backed globals; these representation defects also predate this declaration change. Focal uses s32m[12], while actual DA98 transpose record is32bytes; no fake16byte padding was used to reproduce frame.

Candidates remove function-call contract mismatches but do not claim to resolve these retained data-object problems. Parent must decide gate/acceptance scope with these limitations, preserve exact profiles and prior selected objects, and avoid describing declaration exactness as a new function match.

## Later bounded investigations

func_80049DB0 remained at 40 after twelve new controls. Raw linked bytes confirm
register-allocation differences rather than relocation display differences.
func_8002FFA4 remained at 420 after seventeen controls; its caller contracts
require a coordinated vector-storage audit including func_8003035C. Casting a
pointer to the first scalar member does not create an array spanning the record.
func_8006603C's initialization/control-flow-corrected source remains at 305;
seven new controls did not improve it. Its old 200 draft is not a valid solution.
No additional function match is claimed for these investigations.
