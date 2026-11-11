extern void *gSelectState;
extern s8 gStreamPhase;
extern s32 InitRaceHud;
extern s32 func_80063790;
s32 func_8005C198(void);
s32 select_reset_text(s32, s32);
s32 asset_list_teardown(void);

/* Leaves the car select screen for the race: resets the select text, sets the stream phase to 2,
 * points the select state's two callbacks at InitRaceHud and func_80063790, then tears down the
 * asset list. Returns 0. */
s32 select_exit_to_race(s32 arg0, s32 arg1)
{
    func_8005C198();
    select_reset_text(arg0, arg1);
    gStreamPhase = 2;
    *(s32 **)((s8 *)gSelectState + 0x288) = &InitRaceHud;
    *(s32 **)((s8 *)gSelectState + 0x28C) = &func_80063790;
    asset_list_teardown();
    return 0;
}
