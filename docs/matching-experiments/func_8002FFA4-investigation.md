# Coordinate interpolation investigation

This 119-instruction function remains OPEN and non-matching. The previous score-462
draft contained uninitialized reads, an artificial volatile local and an overwritten
output pointer. Those constructs are absent from the new sound score-460 draft.
The draft is retained in portable progress only, not selected as standalone C.

The clean candidate uses initialized short coordinate differences, preserves the
output pointer and uses a real `&d[0]` alias. Its final assignment to the interpolation
temporary occurs after the last use of that temporary in all three products.

The bounded pass examined 2,467 candidates, of which 2,412 compiled. Two native
lanes each tested 1,000 variants. Expanding the coordinate-load macro did not improve
the best result. Register allocation and scheduling remain unresolved. No exact
match or complete-cartridge verification is claimed for this draft.

Sound draft SHA-256:
`7046bbbaab55354db3d76f8ef3d0bf9f2054478f873456fb585b05da02fa09d2`.
Immutable private input SHA-256:
`f77ce652ba9cdf5871e5eada51e76c2e4a1ed5e5c2d30502f76a883105f29287`.


## Current coordinate-record revisit

The current saved baseline is420, superseding the older460 checkpoint above.
A fresh read-only freeze and final audit confirm unchanged source, target,
header, compiler profile and symbols. Historical invalid462 remains rejected.

Thirty-two distinct local-coordinate representation controls compiled, with
four non-applicable combinations skipped rather than counted. Actual three-field
s16 records, records containing a genuine s16[3], direct/aliased local access,
first-delta width and meaningful offset lifetimes found no exact match. Baseline,
scalar-record and nested-record forms emit identical480-byte code. Removing the
actual b+2 lifetime reaches476 bytes, the target length, but worsens score to505.
Four representative ordinary/diagnostic compilations have identical linked bytes.

Nineteen supported KMC scheduling/debug/optimization controls found no
improvement. Installed PM GCC2.8.1 with g3/g0 scores4260/4850. No source or
profile was adopted. Existing caller, valid-grid and aggregate-bound caveats
remain; these tests do not prove whole-program type safety. Findings are saved
in normal app notes and portable progress. Keep the function OPEN420 and
revisitable; no new automatic repair or cartridge acceptance is claimed.


## November 6 component capture and joint coordinate contracts

The normal app now retains an OPEN177 draft (previously420), 476 bytes, with a
genuinely consumed component-index local. It is not exact. A 1200-case host
oracle screen covers complete scalar-field records and s16-array outputs,
negative interior-base indices and signed fraction boundaries; that screen does
not establish all game storage lifetimes or arithmetic bounds.

Four existing selected functions were corrected jointly: 3035C,316C4,32AE4 and
317D4. The common coordinate helper uses void-pointer object/output contracts,
actual scalar field accesses at4C/54/8A and complete record/array addresses.
3035C returns s32; its callers explicitly preserve s16 narrowing. All known ten
direct2FFA4 calls and six direct3035C calls are covered; unknown indirect callers
and complete allocation/initialization evidence remain unproven.

Each corrected selected function independently links exactly, with ordinary/-da
parity. The complete 12,582,912-byte cartridge equals the original SHA256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All2071 selected profiles and other2067 selected C objects are preserved. Normal
saved-source verification accepted all four before the draft was retained.

A bounded qualifier control is informative: adding const to3035C's new position
formal and byte/halfword read casts scores790/824 bytes; removing those added
qualifications restores exact844 bytes. This does not isolate a single qualifier
or justify blanket const removal. PR642 records the evidence in the KMC guide.

One frozen177 native search delivered1000 charged wrapper candidates,392 linked
scores and no improvement. Raw generator emissions were not captured: the
wrapper filters some candidates before delivery. Do not report this as1000 raw
emissions or restart the exhausted lane without new grounded evidence. Detailed
private receipts remain in current-nov6/closure3035C and the parent cartridge gate.

## November 6: native printer and component-index coverage

The current177 source SHA256 is
c9eb9bba2ab18bf55f17feb610007d0d89a926402635533ad10a1f720a4fd279.
Original source, lane seed-expanded.c and the pinned native Candidate's
unmutated printed source all reproduce the same476 linked bytes, score177,
SHA2563ad2a8555f67f4c9d76475f869a89a66a52b9b4c07e450f02d99435ae83af9a1.
Each ordinary/diagnostic pair agrees. There is no baseline printer regression,
so no formatting backport matrix was run.

The lane's named expanded seed is actually byte-identical to the original:
m2cfix.expand_macros leaves PTS/COORD function-like macros intact. Candidate
parses their uses as calls, and reinserts directives; only KMC expands them.
Thus this lane does not establish mutation coverage of arithmetic hidden inside
COORD. That is a source-visibility distinction, not a new match or proof that a
fully preprocessed seed will improve the function.

Existing native records314/315/479 capture component index2 and score997/488
bytes, but also abstract the unrelated y-output byte offset2. One new control
isolates the actual z component's coordinate loads, delta/scaling and output,
preserving the y offset and current y-index carrier. It produces exactly those
historical997 linked bytes, SHA256
061608a9c4103405e1eb718a29aab1174a1c019ad89ff3c6a013f79a53590fad.
A partial z capture already stays177 and a historical y capture scores757.
Eight successful compiler calls cover three baseline pairs and one z pair;
zero new native emissions/jobs. Private layout-replay-nov6/REPORT.md preserves
fresh inputs and exact pinned printer provenance. Selected source is unchanged.

The subsequent visibility check establishes a genuinely different eligible seed.
The actual pinned KMC preprocessor's focal function body was reinserted into the
original header and original physical body line layout. Full preprocessed tokens,
including header, match the original. Its printed expanded form changes redundant
parentheses but preserves the full parsed header/body AST signature. Both forms
independently retain177/476 and the same linked SHA above, with ordinary/-da parity.
Candidate now sees zero calls instead of seven COORD calls,68 binary operations
instead of33,25 unary operations instead of11 and29 casts instead of15. Assignment,
array-reference and compound counts remain27/12/3. No effect or interface was added.
Private exposed-audit.json, visibility.json and full-ast-parity.json retain proof.

A newly bounded native lane from this actual exposed seed is authorized, with
up to1000 raw emissions and separate lineage/safety/preflight/link accounting.
This is not another macro-opaque starting point. No search result, improved
source or exact match is claimed until its recorded run completes and reviewed
ordinary judging confirms it.

## November 6: expanded-seed result and retained107 draft

The lane completed normally:1000 raw emissions and16 completion receipts,
21 duplicates,180 text/current-safety rejections,96 Clang preflight failures,
703 compiled,3 new-symbol rejections and700 linked. No compiler failures or
exact match. Current guard module paths/checksums, raw variants, lineage and
receipts are retained in exposed-lane. Filters are not a complete C proof.

Candidate622 improves177 to107 with only perm_ins_block lineage: a nonempty
single-pass do/while(0) groups the existing else-arm interval calculations.
Its five assignments keep their original order, reads, types and arithmetic;
there is no break, continue, declaration, call, new value operation or runtime
loop operation. Removing precisely this DoWhile node recovers the original
focal AST. Both same-line plain braces and same-line unwrapped statements
return177, isolating the control-group compiler phase rather than line joining.
The mutation is outside COORD, so this result does not prove that macro visibility
caused the gain; the expanded-seed lane found it.

Parent independently backported only the group onto the original readable
macro-retaining source. Ordinary/-da476 linked bytes agree at107, SHA256
214a6c593abbd38500961001781af585057904adf7ab0f95751ea4fae9666e74.
Source SHA2561ca0e9baf9af8dffa7940587000666889c0fe7c5f3d1356089d8dce114decd41.
Remaining differences are21 register operands and two frame adjustments
(target8 bytes versus candidate32), with no added/missing/different opcode.
No whole-cartridge acceptance is claimed for an unmatched draft.

The normal app compile committed attempt313964 and selected OPEN107. Its MCP
response failed after the successful database commit; read-only verification
confirmed the exact source/score instead of resubmitting. All2071 selected C
sources equal the prior portable snapshot, and the parent's connection/claim
was revoked. No quality override, target or compiler change was used.
Private parent107/proof.json and normal-retain-result.json retain the independent
proof and post-error verification. Native tests and attribution receipts remain
in layout-replay-nov6.

## Focused107 search and controlled frame mechanism

Both original-macro and exposed107 printer baselines preserve107. Only one raw
emission in the earlier lane has622's exact grouping; the next resets lineage,
so no visible descendants explored the improved seed. This does not reconstruct
unseen internal generator states. A focused exposed107 lane therefore ran with
the same fixed methods, current guards and preserved single nonempty group.
It completed1000 raw emissions/16 receipts:696 compiled/linked,216 text/safety
rejections,72 preflight failures,16 duplicates and no exact/improvement. Earlier
lane source hashes seed the duplicate cache; duplicate emissions remain charged.
Observation timeouts poll the same process, and none occurred.

Pinned RTL identifies the actual origin of three late USE references: address
intermediates for signed COORD off/2 and b/2+component. They are SImode, not
hypothesized DImode constant-divide-by50 products. Actual d-array memory atsp0/2/4
is present and must remain; residual-only diff rendering did not show it because
it already matches. Extra USE references map tosp12/20/28 after global allocation.
Their allocator alignment policy was not instrumented.

One controlled composition replaces only ((off/2+c)*2) with off+2*c in COORD.
All a/b definitions are representable index*6, hence even; c is0/1/2, including
the unchanged immutable index1. Negative even offsets divide exactly. On the
original defined arithmetic/storage domain, offsets and overflow constraints
agree, and both expressions perform one final pointer addition from the same
backing allocation. No unsigned cast, shift, extra read/store or intermediate
out-of-object pointer was introduced. A scan of9284 private C files found no
prior grouped107/division-free composition.

The result has the target8-byte frame and removes all three obsolete USE slots,
while preserving the real6-byte array. This directly links the extra24-byte
reservation to the signed-half-offset representation in this context. It does
not establish every internal allocator decision. Overall code regresses to475,
480 bytes, including one extra NOP and register/scheduling differences, so it is
not selected over107. Ordinary/-da agree, source SHA256
6dc0fad0dd45db2ce0493439866d02bceea31a1368ba5ec9363917a1e4706af5,
linked SHA256f9f4aa559248ccce0e282a9ef8376bc8253cded240332f84d481cae968227dd0.
Private rtl-group107-even-address and group107-even-address.json hold the proof.

The frame8/475 frontier also preserves its score, bytes and full preprocessed
header/body AST after actual macro exposure and native printing. One targeted
local reorder moves only x scaling after x-delta initialization, before y/z
input loads; it preserves coordinate read order, output writes and local types,
with no escaped local array address or call crossed. It moves the divisor's
LUI earlier as intended, but regresses to1840/460bytes, frame8. Ordinary/-da
agree, linked SHA256
2a2ee819b500f6b0b86de63656c310cc19391ea606027569350aa10eabd06bab.
No source is adopted from that control.

One bounded1000-raw lane is now authorized from the proven compiler-exposed
frame8/475 representation, not the failed early-scaling variant. Earlier fixed
methods did not supply the exact-even algebra rewrite; this is a distinct
structural frontier with the target frame, despite its worse scalar score.
Original107 remains selected. No result is claimed for the pending lane.
