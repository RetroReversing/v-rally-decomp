extern void *gSelectState;
extern s8 gStreamPhase;
extern s32 func_80070C34;
extern s32 best_times_select_update;
s32 func_8005C198(void);
s32 select_reset_text(s32, s32);
s32 asset_list_teardown(void);

/* Leaves the select screen for the best times screen: resets the select text, sets the stream
 * phase to 2, points the select state's two callbacks at func_80070C34 and best_times_select_update,
 * then tears down the asset list. Returns 0. */
s32 select_exit_to_best_times(s32 arg0, s32 arg1)
{
    func_8005C198();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    *(s32 **)((s8 *)gSelectState + 0x288) = &func_80070C34;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &best_times_select_update;
    asset_list_teardown();
    return 0;
}
