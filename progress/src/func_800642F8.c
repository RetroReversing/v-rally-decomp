typedef struct { s32 a; s32 b; s8 c; } S56;
extern void *gSelectState;
extern s8 gStreamPhase;
extern S56 D_800A56A0;
extern s32 func_800580D0(s32, s32);
extern s32 select_menu_setup(s32, s32);
extern s32 asset_list_teardown(void);

/* Resets the select screen state: copies the default select block into the state, then tears down the assets. */
s32 func_800642F8(void) {
    S56 *src = &D_800A56A0;
    S56 *dst;
    s8 c;
    *(s8 *)((u8 *)gSelectState + 0x2BD) = 1;
    func_800580D0(0, 0);
    *(s8 *)((u8 *)gSelectState + 0x24D) = 0;
    dst = (S56 *)((u8 *)gSelectState + 0x204);
    __builtin_memcpy(dst, src, 9);
    c = dst->c;
    select_menu_setup(0, 0);
    gStreamPhase = 2;
    asset_list_teardown();
    return 0;
}
