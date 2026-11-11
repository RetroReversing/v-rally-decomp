extern s8 D_8009BBBC; extern void *gSelectState; extern u8 gStreamPhase, gStreamReady; extern s32 D_800C8374; extern char gStreamState[]; s32 stream_alloc_slots(s32);
/* Per-frame stream state machine: runs the step for gStreamPhase and,
 * in phase 3, clears the first control entry of the current stream. */
void stream_state_update(void) {
    s32 one = 1;
    s32 bank;
    s32 phase;
    s32 *stream;
    s32 *entry;

    *(s8 *)((char *)gSelectState + 0x2BD) = one;
    phase = gStreamPhase;
    switch (phase) {
    case 0:
        bank = *(s32 *)(gStreamState + 0x80C6);
        D_8009BBBC = one;
        stream_alloc_slots(bank);
        gStreamReady = 0;
        break;
    case 1:
    case 2:
        break;
    case 3:
        if (gStreamReady) {
            stream = *(s32 **)(gStreamState + 0x325A);
            entry = stream;
            entry = *(s32 **)((char *)stream + 0x10) + (*(s16 *)((char *)stream + 2) * 5);
            entry[4] = 0;
        }
        break;
    }
}
