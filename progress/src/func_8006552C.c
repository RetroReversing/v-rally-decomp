s32 select_copy_entry_label();
extern void *gSelectState;
extern s32 league_season_setup;
extern s32 func_80065860;

/* Copies the entry label for the select screen, then stores its two callbacks in gSelectState. Returns 1. */
s32 func_8006552C(void) {
    select_copy_entry_label();
    *(s32 **)((s8 *)gSelectState + 0x288) = &league_season_setup;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &func_80065860;
    return 1;
}
