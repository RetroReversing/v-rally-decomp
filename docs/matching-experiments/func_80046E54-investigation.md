# func_80046E54 revisit

Fresh read-only capture: open, distance 140, 215 instructions / 860 bytes, no claim. Inputs frozen in `frozen/inputs.json`; pinned app at ee123501; unchanged KMC GCC2.7.2 flags -G0 -mips3 -mgp32 -mfp32 -O2 -g3. No live mutations, profile changes, helper children, or app changes.

## Contract audit

Target Stat stride76, value@68 produces input offsets0x90/0xdc/0x128+76*i. Game players@0xe, diff@0x16, state@0x1e, order@0x32, Slot stride40/car@7, base0x48 gives targetcar@0x4f. This is a provisional memory representation; another function's slots@0x44 may name a different prefix of the same physical region. Record stride708/count@0x14. Normal index bounds remain game preconditions, not universal arbitrary-input guarantees.

Original `((s16*)&D_800ADFDC)[1]=0` runs past a separately declared scalar object. `defined.c` removes that expression and uses named unsigned-halfword D_800ADFDE (compatible with selected reader44908), removes unused inline helper and pointer local. It compiles score260. Valid aligned object-representation state access retained; replacing it by direct Game.state changes alias scheduling and scores480. This corrected260 draft is preferred unless the adjacent record representation below is accepted after cross-TU audit.

`aggregate.c`: models the four adjacent actual bytes as Cursor{s16 marker;u16 position;} beginningDC; all focal accesses use these fields and no overlapping DE extern. Score140, so the zero-store scheduling matches again. This is conditional on cross-TU physical-object/representation audit, not proof the original source had this aggregate. Parent independently handles the selected44D9C/44908 contracts and wrapper1E524 explicitpointerforwarding (exact28bytes).

## Grouped negative experiments

- Named zero-store forms (unsigned compatible lvalue, pointer local, address-of, assignment expression, index-carried zero) score260; bytewise zero680. Moving before conditional280. No new memory effects retained.
- Tail loaded-value temporaries/reusing prior v and additive-order forms260–1060. Inline address/load helpers380–1685.
- 81 declaration order controls all260: declaration order does not resolve this case.
- Explicit Game pointer capture with required global reload260; replacing all later globals with one captured pointer525 (not target).
- Formatting controls: blank lines unchanged260; collapsing final tail region to one line420, collapsing other regions unchanged260. No exact. This changes scheduling only; do not treat it as a demonstrated reusable winning repair.
- Tail array end-relative anchors: signed-index forms all140 (aggregate hypothesis). Unsigned-subtraction cases are **rejected as potentially out-of-bounds for j<anchor**, even though compiler output was same. No such candidate accepted.
- Earlier private investigation already tried diverse tail loop/index/pointer/inline/reuse forms plus1000 native proposals, none exact; these were not rerun indiscriminately.

Remaining mismatch on aggregate candidate: last two four-byte boost loops use index a0 / loaded byte v1, target index v1 / byte a0. Rendered relocation names also differ, but many resolve to identical actual high halves; judge exact remains false. No full cartridge build because no new exact candidate. No verified new autopilot repair from this revisit.

## Exact follow-up (supersedes initial no-exact conclusion)

Parent audited physical DC/DE storage as an interior four-byte view of the actual BSS symbol, with no independent definitions/boundaries, and independently proved consistent Cursor accesses in selected44D9C/44908. The aggregate is now an admissible representation hypothesis subject to joint cartridge verification.

The remaining tail fix is a same-type loaded byte **compound update**, not a binary-expression direct store:
`u8 value; value=D[j]; value += value>>1; D[j]=value;`
and similarly `value += (value*D[4])/100`. Both sites together produce exact860linkedbytes SHA c9985315abcb8f7268a488807f5158bd07bb40eb27a2c4bf820717f37c66dcfd. Either single remains a miss. Conversion into u8 before the final u8 store is identical modulo256; multiplication <=65025 is defined in the supported32bit target ABI. Ordinary nonvolatile reads have no intervening writes/calls. No invented qualifiers or identities.

`exact.c` SHA fa162f92c7024590cef39ff6d7318bfbad18092b513313791fc3158ffa3bbb4f is preferred manual source; `exact-proof.json` records immutable inputs/profile/header/target/raw linked hash. A symbolic scoring.diff still says80 because relocation annotations differ, whereas **normal match.diff returns0 and linked_code equals target.code exactly**. This is no scoring/target change.

New bounded shared family `loaded_byte_compound` implemented in isolated /Volumes/Data/Codex/tmp/loaded-byte-compound on fresh b929bc41. `generated-final.c` / generated-final-proof.json independently demonstrate its first of three proposals exact; the remaining singles miss. The same family on the separate named-global defined260 draft improves200 but does not match, so do not claim the family alone repairs the old scalar-overrun source. Shared tests129pass, wholeRuff/diffcheckpass; includes host-compiled exhaustive256x256byte/factor equivalence, all5knownarchitecture type adapters, and guard coverage. Parent owns full4function jointcartridge/build/liveaccept/export/PRmerge.

# Parent contract audit

## Existing caller

Canonical matched func_8001E524 has an unprototyped call with no explicit arguments to func_80046E54. The caller target is28bytes: stack save, jal46E54, return. Its a0 register is preserved, while the callee reads its incoming Stat* parameter.

A private corrected caller declares incomplete tagged struct Stat, the actual void46E54(Stat*) prototype, and explicitly forwards Stat*s. Normal pinned-profile compiler/link verification is exact28bytes, score0. Source, fresh frozen row/context/profile/target, and proof are under parent-wrapper/. It has NOT been applied live or counted as a new match. Joint cartridge validation is still required before any selected C update. Broader callback-entry contracts are not globally reconstructed.

## Globals

Selected44D9C declares D_800ADFDC as short and uses signedcomparison. Selected44908 declares D_800ADFDE as u16. New46E54 should use compatible s16/u16 declarations and named stores. Writing ((s16*)&D_800ADFDC)[1] crosses the separately declared scalar object and is not an admissible way to tune scheduling.

## Layout

Target46E54 car field is0x4f relative to the game object, compatible with this view's Slots@0x48/car@7. The earlier6D564 view models a40byte region beginning0x44, so the differently named logical slot boundaries alone do not prove either offset wrong. Keep actual accessed byte offsets authoritative.

## App follow-up

Existing argument_repairs.py already handles some tiny wrappers when machine evidence shows missing forwarded arguments, but requires nonempty call arguments and does not repair this already-matched noargument call. A future known-callee contract diagnostic could expose such cases. Do not introduce a duplicate family or guess parameter values.

## Four-byte representation audit

The frozen symbol table places0x800ADFDC..0x800ADFE0 inside the actual BSS allocation D_800A73E0 (base0x800A73E0,size29808). It has no independent typed allocation or boundary at DC/DE. This supports a four-byte storage view, not a claim to original source types.

All known selected named accesses were checked:44D9C can use Cursor.marker(s16),44908 can use Cursor.position(u16), both through consistently tagged Cursor D_800ADFDC, removing the overlapping D_800ADFDE declaration. BOTH corrected sources independently compile/link byte-exact with their frozen original profiles/contexts. Their sources, proofs and snapshots remain private in parent-func_80044D9C/ and parent-func_80044908/. Together with focal aggregate.c this gives compatible field types across all known named references and eliminates scalar-boundary indexing without adding memory operations or objects. Full joint cartridge validation is still required. Broader BSS aliases in other inferred views are not globally unified.

## Final independent cartridge gate

The preferred source and three audited existing contract corrections jointly reproduce all12,582,912 cartridge bytes (SHA-256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7). There are2069 selected C functions. All2068 prior compiler profiles and2065 other prior C objects remain unchanged. The old single-function assembly run is no longer linked. No ROM, assembly, binaries or database is published.

## Earlier checkpoint evidence retained

The preceding nonmatching investigation tested1000 native variants,20 first-page repair proposals,149 helper compilations and86 parent probes without an exact candidate. Its alternative SHA-256 was3a861e2674587cb279027607eb171b5ff9fe8c1a80e206edc997b33e4800884f. It modeled a two-halfword array while retaining a separate alias and was never selected as cartridge-verified C. The current consistent Cursor view and compound local updates supersede that candidate; these earlier negative experiments remain useful controls.
