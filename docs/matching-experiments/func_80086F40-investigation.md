# Audio DMA cache investigation

The 117-instruction function remains OPEN and revisitable. A bounded pass of
515 ordinary compile/link judgments found no exact candidate and left the best
advisory score at 265. This is negative evidence, not a proof of impossibility.

The main differences are a saved-register allocation swap and first-argument
staging around a five-word structure argument copy. Related SDK `__amDMA`
implementations helped identify the linked-list DMA cache and predecessor/alignment
lifetimes, but did not provide an exact donor for this version.

Tested without improvement: separate pointer/alignment locals, same-type phase
unions, declaration/storage variants, load and call staging, statement chains,
source-line boundaries, and the existing 20-candidate repair first page. Exploratory
prototype/ABI alternatives were rejected and are not inferred declarations. No
alternative C is accepted, and the original source/profile/target remain intact.

Immutable private capture SHA-256:
`b76c48a920b871341650c19ad44974c622a90d60070f7e262d8594700982dfe3`.
