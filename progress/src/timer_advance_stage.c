extern s32 gTimerEffectBusy;
s32 func_80038A8C();

/* Advances the timer's stage counter (+0x7A) and sets its delay to 200. At stage 4 the timer is marked finished. Otherwise, if no effect is busy, it plays the effect for the new stage and marks an effect as busy for 4 ticks. */
void timer_advance_stage(char *timer) {
    s16 stage;

    *((u16 *)(timer + 0x7A)) += 1;
    *((u8 *)(timer + 0x93)) = 0xC8;
    stage = *((s16 *)(timer + 0x7A));
    if (stage == 4) {
        *((s32 *)(timer + 0x80)) = (*((s32 *)(timer + 0x80)) & ~1) | 4;
    } else if (gTimerEffectBusy == 0) {
        func_80038A8C((u8)(stage + 7));
        gTimerEffectBusy = 4;
    }
}
