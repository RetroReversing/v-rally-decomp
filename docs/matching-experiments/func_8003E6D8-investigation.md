# func_8003E6D8 private investigation

Frozen read-only from project1/id805, OPEN635/unclaimed,395 instructions. Source/header/target/profile are in frozen/inputs.json; all compiles use the captured gcc-2.7.2-kmc profile -G0 -mips3 -mgp32 -mfp32 -O2 -g3.

No live or canonical writes, claims, app restarts or acceptance were performed by this helper. Parent may intentionally submit start-pos.c as an ordinary NONEXACT565 draft; this is not a new selected C match.

## Source behavior and audit

The function creates UI sprite components in two game modes. Preconditions: current manager/game/position pointers are valid; selected slot indices are0..3; renderer allocation returns a valid Spr; resource ID arithmetic uses the captured32-bit machine representation; first branch loop j runs0..3 and mode2 i runs1..2. Coordinates originate in signed16-bit fields, so small additions fit signed32; narrowing back to signed16 has the period compiler's two's-complement behavior. Loops and derived offsets are bounded.

Original635 source has three concrete defects:

- Mode1/state!=0 uses new_var as a resource argument without any initialization on that path.
- The initial x expression is x=(x=pos->x)+20, with conflicting assignments before a sequence point; this must not be retained as a way of obtaining GCC's fortuitous code generation.
- Subsequent mode1/state0 sprites must use ORIGINAL pos.x+28/+36; target uses fp loaded from pos.x at8003E720 and addiu a1,fp,0x1c/0x24 at8003E7D4/8003E81C. The old source nominally adds these to already shifted x.

clean.c fixes these but score1800. Explicit base_x plus x=base_x+20 restores required lifetimes: base-x.c880. Moving first resource-address setup after the first sprite allocation gives late-pointer.c650. Using a separate start_pos pointer for initial coordinate reads (mode2 retains pos) gives start-pos.c565 and fixes initial/mode2 register reuse; direct-pos.c565 is equivalent. start-pos.c passes independent Clang uninitialized/sometimes-uninitialized preflight. No introduced asm, volatile, fake branch/identity, boundary, target or judge changes.

## Important cross-function type caveats

These remain machine-behavior drafts, not fully audited whole-program C. func_80040260's selected C currently declares void return/five arguments, while its actual machine code leaves the allocated sprite pointer in v0 and this caller uses it; the caller also supplies an ignored sixth mode argument. A compatible reconstructed constructor prototype and existing callee source need later review, preserving its exact object. The current caller correctly reflects the observed pointer return, but consistency with selected C is not established.

func_80034FF0's selected C returns Pack3* and takes s32 resource ID plus extra size; the caller's generic void* argument/s32 return stubs are representation compatible on MIPS32 but are inconsistent C declarations. Spr.tex is naturally a Pack3* rather than a semantic integer. All four callback bodies take one pointer argument, while caller stubs currently declare void(void). These issues were explicitly sent to the parent; no callee source or header was altered. Do not use lower score565 as a claim of validated global signatures or a cartridge acceptance.

## Directed negative controls

- u16 cast on j inhibits old loop strength reduction but leaves an unwanted ANDI before first renderer. Removing the cast triggers strength reduction to an incremental coordinate; score2957 from650,2880 from565. Cast after product or final sum, inline multiply helper and one-shot do scope do not stop this.
- Signed/unsigned counter and <4/!=4 comparisons, with do/for loop forms and no early j cast:16 variants, all2780+.
- Eight normal11*j arithmetic trees (3*4-1, shifts/adds,10+1,8+3) still strength reduce, all2880.
- Moving resource setup inside the flags branch gives980; setting pointer after first renderer inside the loop, with early/late j increment and u32/s32/u16 types, gives800+ in12 probes.
- Six natural i/k/resource setup permutations give565/567; noneexact.
- Late j increment alone is840; moving resource pointer into loop plus late increment does not improve800.
- Diagnostic -fno-strength-reduce with no early j cast gives1175 from650; disabling instruction scheduling is substantially worse. No profile was applied live. Parent requested remaining diagnostic against565 separately.

## Native evidence

First lane: single frozen late-pointer.c650 baseline, private app712acaac. Exactly1000 generated attempts,705 successful compiled/scored,54duplicate,121forbidden-token,120 rejected by independent Clang preflight. No exact and no improvement below650. No selected-best portfolio.

Second lane: concrete valid improvement start-pos.c565 justifies one independent lane (no portfolio), fresh app565 worktree at99cfce3e. Native outputs and unique per-candidate Clang files are in native-565/. Inspect final status before reporting counts. Do not restart or retroactively change the first lane's app revision. Both lanes retain lineage.

## Final directed controls and ABI follow-up

A real backward goto prevents the induction strength reduction and restores the target-like multiply-by11 tree, independently confirmed by the parent's synthetic pinned-compiler probe. It also loses the C-loop invariant hoisting: naive goto forms1950+. Explicitly hoisting the callback address, constant mode1 and resource ID before the label yields goto-hoist1.c795 (no exact), predominantly register allocation and preheader/increment placement differences. This is a verified compiler mechanism, **not a matching repair**.

Two final meaningful-width probes (signed/unsigned64-bit j*11, narrowed into yy) are both3505. The case1-invariant j+=mode diagnostic is1437. These did not justify any extra broad lane. With565, diagnostic no-strength-reduce + uncastj is1090; u16counter + no-strength-reduce is785.

Parent refined possible constructor contract: returning void* with five existing fixed arguments (s32,s16,s16,s16,s32 hook) and variadic ignored mode matches observed machine use without inventing a meaningful sixth field. Callback addresses could then be explicitly represented as s32 hook bits. This requires a separate exact-object and full-cartridge proof for the already selected constructor before any change. No callee modifications were made here.

## Terminal outcome

Both native processes ended normally. First:1000 generated attempts705 compiled/scored,54duplicate,121forbidden-token,120Clang-rejected; best650 unchanged. Second:999 actual generated attempts710 compiled/scored,58duplicate,97forbidden-token,132Clang-rejected; best565 unchanged. The second lane requested16 batches bounded by1000 attempts; one attempt was not yielded by the native generator. No quota-filling restart or additional lane was used. These are preflight-passing compiler counts, not claims that every random transformation is semantically proven.

Additional recorded baseline/directed compiler judgments: 87, allnonexact. Parent intentionally improved live ordinarydraft635->565 with stable start-pos.c; finalreadonly state {'status': 'open', 'best_score': 565, 'target_unchanged': True, 'best_source_sha256': '9cf5f07ba15d2d557b01bf48bc8348e11a2df8e4396eddddaf2f866ebc7ceefd', 'claims': []}. No selected C match or cartridge gate. All metadata and source hashes are in evidence.json.
