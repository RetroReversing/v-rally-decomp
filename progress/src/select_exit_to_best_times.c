extern void *gSelectState;
extern s8 gStreamPhase;
extern s32 finish_race_results;
extern s32 best_times_select_update;
s32 select_arm_if_clear(void);
s32 select_reset_text(s32, s32);
s32 asset_list_teardown(void);

/* Leaves the select screen for the best times screen: resets the select text, sets the stream
 * phase to 2, points the select state's two callbacks at finish_race_results and best_times_select_update,
 * then tears down the asset list. Returns 0. */
s32 select_exit_to_best_times(s32 arg0, s32 arg1)
{
    select_arm_if_clear();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    *(s32 **)((s8 *)gSelectState + 0x288) = &finish_race_results;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &best_times_select_update;
    asset_list_teardown();
    return 0;
}
