# Working on this project

- Preserve target bytes, function addresses, compiler settings, and verification rules.
- Accept C only after an exact compiler/link comparison and complete cartridge rebuild; report assembly remaining.
- Use relevant local source and documentation when available, recording provenance. The initial combined checkpoint was ROM-derived and did not use original game source.
- Keep speculative names and types clearly provisional.
- Never commit ROMs, generated assembly/assets, build output, compilers, credentials, or local databases.
- Obtain proprietary compiler license acceptance before installation. The current KMC-compatible compiler is free software.

## Keep app and repository progress synchronized

- Use this main checkout as the canonical V-Rally Europe repository. The linked decompdecomp PAL project is `v-rally`; `v-rally-2` is a separate project.
- Fetch `origin/main` before starting work and fast-forward a clean checkout when needed. Preserve local work and all previously verified C when importing a newer app snapshot.
- After progress changes, reconcile the app project and standalone repository before reporting completion. Check source, header context, symbol names and each function's verified compiler profile together. Keep newer drafts and readable names; a matched count alone does not establish equivalence.
- Apply app changes through its normal verification paths. Recheck the final saved state: a file refresh can reopen functions, and stale matched records can fail export under different compiler flags. Never write the live app database directly.
- Verify changed functions independently and the complete cartridge before accepting repository C. Update the build manifest, generated objdiff metadata and documented counts. Commit and push authorized progress, then confirm the local and remote commits agree.
- Report any remaining app/repository differences explicitly. Do not claim continuous automatic synchronization; these checks are required whenever updating progress.
