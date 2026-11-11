typedef struct SelectDefaults {
    s32 a;
    s32 b;
    s8 c;
} SelectDefaults;

extern SelectDefaults D_800A5CF0;
extern u8 *gSelectState;
extern s8 gStreamPhase;
void func_800580D0(s32, s32);
void records_restore_from_order(void);
void select_menu_setup(s32, s32);
void asset_list_teardown(void);

/* Enters the select screen: sets the busy flag, clears entry 0's flags, restores
 * the saved records, copies the default selection block into the select state,
 * sets up the screen and tears down the asset list. */
s32 select_screen_enter(void) {
    SelectDefaults *src = &D_800A5CF0;
    SelectDefaults *dst;

    gSelectState[0x2BD] = 1;
    func_800580D0(0, 0);
    gSelectState[0x24D] = 0;
    records_restore_from_order();
    dst = (SelectDefaults *)(gSelectState + 0x204);
    __builtin_memcpy(dst, src, 9);
    select_menu_setup(0, 0);
    gStreamPhase = 2;
    asset_list_teardown();
    return 0;
}
