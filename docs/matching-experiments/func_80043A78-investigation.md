# Controller completion investigation

OPEN / revisitable. No exact candidate; no C selected and no full cartridge gate.

The frozen score425 draft calls func_80042F40 in the wrong control-flow location. Target calls it only in shared finish, after clearing the global word. Draft also uses a Car pointer as a player index. Repaired baseline is655 with frozen flags; privately recorded -g3 produces435. This near source is safe7.c, SHA recorded in evidence.json. It retains abs on a signed coordinate delta, so does not establish behavior for INT_MIN. The defined unsigned magnitude alternative abs-constant1.c produces1115. Neither is accepted C.

Residual near-source differences are one branch-likely choice plus register allocation and scheduling near game-state/player-slot/list setup. Targeted branch factoring, expression order, scalar temporaries, slot pointers, cached game pointers, debug options, scheduler options, and unsigned absolute-value forms did not produce an exact object. No general compiler rule was inferred.

Native search results and all candidate sources remain in native-independent/. Batches independently start from clean.c, do not promote candidates into a portfolio, and exclude every expand_expr lineage because captured-pointer recomputation can change semantics. A lower advisory score would still require independent source audit and linked-byte verification.

All experiments use the isolated app worktree, repair-tests-venv and frozen read-only inputs. Live claims/database/projects, canonical source, target, ABI, profiles and judge remain unchanged. The original2065 selected profiles and objects were untouched.
