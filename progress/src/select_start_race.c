typedef struct { s32 a,b; s8 c; } Rec;
extern Rec D_800A56E0;
extern u8 *gSelectState;
extern s8 gStreamPhase;
void select_set_entry_flag(s32,s32); void records_restore_from_order(void); void select_menu_setup(s32,s32); void asset_list_teardown(void);

/* Starts a race from the select screen. Sets the select state's +0x2BD flag and clears its
 * +0x24D flag, resets the entry at index 0 (select_set_entry_flag), restores the saved records,
 * copies the 9-byte default block (D_800A56E0) into the select state at +0x204, runs the
 * select screen setup (select_menu_setup), sets the stream phase to 2 and frees the asset
 * list. Returns 0. */
s32 select_start_race(void) {
    Rec *src = &D_800A56E0;
    Rec *dst;

    gSelectState[0x2BD] = 1;
    select_set_entry_flag(0, 0);
    gSelectState[0x24D] = 0;
    records_restore_from_order();
    dst = (Rec *)(gSelectState + 0x204);
    __builtin_memcpy(dst, src, 9);
    select_menu_setup(0, 0);
    gStreamPhase = 2;
    asset_list_teardown();
    return 0;
}
