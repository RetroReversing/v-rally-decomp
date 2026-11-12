extern void *gSelectState;
extern s8 gStreamPhase;
extern s32 InitRaceHud;
extern s32 select_update_record_bars;
s32 select_arm_if_clear(void);
s32 select_reset_text(s32, s32);
s32 asset_list_teardown(void);

/* Leaves the car select screen for the race: resets the select text, sets the stream phase to 2,
 * points the select state's two callbacks at InitRaceHud and select_update_record_bars, then tears down the
 * asset list. Returns 0. */
s32 select_exit_to_race(s32 arg0, s32 arg1)
{
    select_arm_if_clear();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    *(s32 **)((s8 *)gSelectState + 0x288) = &InitRaceHud;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &select_update_record_bars;
    asset_list_teardown();
    return 0;
}
