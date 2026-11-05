# func_8006D564: typed pointer capture reuse

Fresh read-only, unclaimed OPEN25 capture: input hashes in frozen/hashes.json. Same pinned KMC GCC2.7.2 profile -G0 -mips3 -mgp32 -mfp32 -O2 -g3 throughout, source/header/target/profile frozen. No live writes, claims, app restarts or profile changes by this helper.

## Audit and exact source

Baseline488instructions differs only five register operands: first Record pointer uses s4 where target s2; its derived Group pointer uses s2 where target s4. Source already fixed an old scalar out-of-bounds store with a real slot prefix. Preferred source further integrates Slot[4] into Game at0x44, keeping its actual byte store at offset0 in a40byte slot. Item uses four genuine s32 words (16bytes), making its representation appropriate for the word-block copier; the item-reset callee accesses the byte representation at6,7,8,C. Group64bytes, Record708bytes, count@14/groups@2C. Compile-time Clang/MIPS size/offset controls pass.

Actual called6F820 returns s32 and accepts(void*,s32); caller retains its real byte conversion explicitly. Corrected6DDD8 long-return,6F75C s32-return and2B618 s32(u8*,u8*) prototypes preserve byte-identical caller setup. CB9C's pre-existing spurious incoming arguments are removed in a separate audited correction: actual B924 reads only its first pointer; corrected CB9C(void) uses a local result assigned from a one-argument B924 call. CB9C remains independently exact at the same cached profile. See cb9c-proof.json/cb9c-inputs-proof.json; this is a contract correction to an already matched function, not a new match.

Real later capture sites originally use p=(u8*)table[n], k=0, then p=(u8*)GROUP(p,j). Reusing existing Record*r for only the initial capture and using r at the sink preserves each evaluation and intervening statement. The old r is dead on all paths, including subsequent iterations. One such reuse worsens25->40; two independent sites recover all register allocation differences and exact0. Four sites yield6exact pairs,4non-exact singles. This is real reuse of existing initialized/dead pointer storage, not fabricated instructions, self assignments, dummy arrays, padding, volatile/register annotations or ABI changes.

Preferred exact-words.c SHA442dc8dd042da0e11bbd28239a22803a4f2aac5ca53727f15abbf988e67448f7. LinkResult.linked_code equals all1952targetbytes /488instructions, SHA b8ca6d1a357e91799a5053d34b78b82335fe16eae9e62778eda8547eadbde725. Clang/MIPS independent initialization and layout checks pass. Full cartridge validation/publication are parent responsibilities, not established by this helper's linked proof alone.

Valid game input assumptions remain explicit: mode record0 is an8-record allocation, its count fits10groups, other mode record group counts match the loops, and the byte player argument indexes a valid one of4slots. The known matched caller passes a byte from configuration offset0x229; this alone does not prove the full domain0..3. Existing project's global declarations are not yet globally unified across translation units; do not confuse this focused contract audit with a whole-project ISO-C aliasing proof.

## Negative controls

80 existing shared shortlist variants, declaration ordering/scopes, pointer-vs-void/byte views, direct indexing, const pointer bindings, genuinely reused whole-record/group lifetimes and loop/inline-helper forms did not improve25. Some const-pointee and integer-address representation experiments were negative and are not proposed repairs. A filtered native lane reached at least704persisted attempts/563scored candidates, best25, no exact. It was interrupted only after directed real lifetime reuse found exact (own PID47883, exit130); any partial final batch is not counted. No new native lane was restarted.

## Reusable app improvement

Private branch fix/pointer-capture-reuse in /Volumes/Data/Codex/tmp/pointer-capture-reuse adds a bounded family with constant in-bounds explicitly typed pointer-array captures, unescaped pointer locals, CFG liveness and unique straight-line sink paths. It preserves statement boundaries, rejects unknown calls/effects/macros/qualifiers/shadows/escapes, and offers independent pairs before singles. Generated first candidate generated0.c is independently exact for the same single function; this is regression evidence, not another new match. Shared pointer-declaration parsing also stops confusing a preceding macro formal with a function parameter.

## Final contract and generator refinements

Final CB9C uses the actual B924(u8*) prototype and an explicit byte-pointer argument, not the ABI-equivalent but C-incompatible void* parameter type. cb9c-final.c SHA0d12b32ba341a66788277abdb1d649988c18a9f50420b4a5157e36291ce50e2f independently matches all308bytes. The already-matched caller684F4 forward declaration is corrected to void6D564(s32), retaining its existing explicit byte argument conversion; caller684f4-final.c SHAd9df96bc0e7111b59a254b65c4c30faf6786a0f5eb28544b0584157bc73a0cfc matches all204bytes. Both frozen unclaimed rows, contexts and effective profiles are in per-function JSON proofs.

The final generator retains the original byte-pointer type at its sink: GROUP(((u8*)r),j), rather than substituting r without a cast, so arbitrary p+1 arithmetic cannot acquire a record stride. Generated-final.c SHA7738f087db8fa968908c7ecf8d176ece25beb9658d0bcc3fe8e4eac7642efbad remains exact0. Forty-seven new adversarial/host tests and164shared tests pass, including UBSan caller-order/table-mutation controls, raw byte-step arithmetic, macro-identifier qualification, hidden callbacks, CFG backedges/incoming jumps and aliases. Whole repository Ruff and diff checks pass. Parent owns the final full-cartridge gate with these refined contract sources; earlier generated/contract proofs are superseded as publication inputs, not silently reused.

## Final independent acceptance

Both the preferred source and the final automatically generated repair passed independent full 12,582,912-byte cartridge comparisons (SHA-256 d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7). There are2068 selected C functions. All2067 prior compiler profiles and2065 other prior C objects are unchanged; two existing functions received the audited signature corrections described above. The assembly run loses exactly the new compiled function include. The normal live saved-source importer accepted all three final sources at score0.

The reusable repair merged in decompdecomp PR567. Final local validation passed248 selected tests and repository Ruff checks; GitHub reported no CI checks for that PR. These include the final byte-pointer cast and rejection of shadowed table roots.
