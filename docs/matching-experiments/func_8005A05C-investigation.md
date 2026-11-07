# func_8005A05C: defined source replacement

The previous selected exact source used an uninitialized counter in a short-
circuit condition and duplicated an identical flag-store/return behind an
unrelated global test. An empty list is legitimate: the constructor initializes
its head to null, and the target checks for that case. Exact compiler output
therefore did not establish valid source.

The reviewed replacement initializes the integer counter before testing the head,
computes the byte-masked argument once inside the nonempty guard before the
backward label, compares integers, follows next links and updates the node flag.
It adds no artificial branch, memory access, qualifier or ABI change. Argument
range0..255 bounds the counter before return, avoiding signed overflow.

With unchanged KMC GCC2.7.2 `-G0 -mips3 -mgp32 -mfp32 -O2 -g3`, header,
prelude, symbols and target, ordinary and diagnostic builds both produce exact
76-byte linked output. Source SHA256:
39166d38127fe89cb128ef357ea6cf119e8fee2cf6f6347b746a009d2d63da08.
Linked SHA256:
20b70d0a224cef285ad5d4fe84c746b77e297a3c3e77a7942aa5783728e031d6.
Saved objects were independently reloaded and relinked.

A single control inlining only the argument mask instead scores60 in both
builds. It recomputes the mask on the backedge and allocates node/count to
argument registers. The common exit tail is identical; a proposed loop-break
control was unnecessary and was not run. The production `loop_argument_mask`
repair generates an independently exact candidate with the original entry guard
and backedge preserved. App PR759 adds that bounded rule and compiler guidance.

The copied full cartridge is byte-identical,12,582,912 bytes, SHA256
`d510b5ccf5a0513ce0a3776f045f7ef9a4983a07e0d00a31f0b1ae5d3eb2d4a7`.
All other2,077 selected sources, effective profiles and objects were preserved.
An initial20-second linker timeout was followed by a separately bounded
162-second successful link. A bookkeeping assumption about compressed-cartridge
metadata then failed; pure final comparisons established the actual full-image
identity without recompiling or relinking. All failure receipts remain private.

The normal app `make_readable` interface accepted the reviewed source and
rejudged it byte-exact. A fresh read-only check confirms2,078 matched functions,
all prior effective profiles and the other2,077 selected source hashes unchanged.
The full portable progress snapshot was saved, including existing drafts and
metadata, rather than exporting only this function. This is a correction of an
existing match and does not increase the count. The bounded initialization guard
returns unknown for this unsupported old shape; no broader checker guarantee is
claimed. Private evidence: `func8005A05C/source-validity-nov7`.
