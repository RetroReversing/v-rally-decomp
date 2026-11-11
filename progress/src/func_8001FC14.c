extern s32 gTimerEffectBusy;
extern s32 D_800AFA6C;
extern void *gRecords;

/* Per-frame tick: advances the frame counter D_800AFA6C up to its cap of
 * 100000, also while the record's mode at +0x1E is not 8, and counts
 * gTimerEffectBusy down to zero. */
void func_8001FC14(void) {
    if ((*(u16 *)((char *)gRecords + 0x1E) != 8) || (D_800AFA6C != 0x186A0)) {
        D_800AFA6C += 1;
    }
    if (gTimerEffectBusy != 0) {
        gTimerEffectBusy -= 1;
    }
}
