s32 asset_list_teardown();
s32 select_reset_text(s32, s32);
s32 func_8005C198();
extern void *gSelectState;
extern s8 gStreamPhase;
extern s32 func_80071B3C;
extern s32 func_80071E08;
extern s32 func_80072364;

/* Resets the select screen: clears the stream phase, points the three select-state
 * callbacks at their handlers, and tears down the asset list. */
s32 select_init_handlers(s32 arg0, s32 arg1)
{
    func_8005C198();
    select_reset_text(arg0, arg1);
    gStreamPhase = 0;
    *(s32 **)((char *)gSelectState + 0x288) = &func_80071B3C;
    *(s32 **)((char *)gSelectState + 0x290) = &func_80071E08;
    *(s32 **)((char *)gSelectState + 0x28C) = &func_80072364;
    asset_list_teardown();
    return 0;
}
