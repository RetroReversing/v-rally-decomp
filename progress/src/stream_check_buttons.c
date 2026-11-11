typedef struct StreamState { u8 pad0[0x8116]; u8 matchCount; u8 timeScale; } StreamState;
extern StreamState gStreamState;
extern s32 gRecordTimeScale;

void func_80085778(s32 port, s32 mask);

/* Compares the pressed buttons against the recorded target. On an exact match it clears the
 * port's flags, bumps the match counter and resets the time scale, returning 1. Otherwise, while
 * the time scale is below 2 and the buttons don't overlap the target, it resets the match state. */
s32 stream_check_buttons(s32 buttons, s32 target) {
    if (buttons == target) {
        func_80085778(0, buttons);
        gStreamState.matchCount = (u8) (gStreamState.matchCount + 1);
        gStreamState.timeScale = (u8) gRecordTimeScale;
        return 1;
    }
    if ((u8) gStreamState.timeScale < 2U) {
        if (!(buttons & target)) {
            gStreamState.matchCount = 0U;
            gStreamState.timeScale = (u8) gRecordTimeScale;
        }
    }
    return 0;
}
