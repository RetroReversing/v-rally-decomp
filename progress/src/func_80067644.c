extern void *gSelectState;

/* Steps the select screen's blink state. While the phase at +0x280 is negative, the counter at
 * +0x281 counts down and wraps to 0x19. A positive phase resets to 0. Otherwise the phase is
 * set to -8. Always returns 0. */
s32 func_80067644(void) {
    s8 phase;

    phase = *(s8 *)((char *)gSelectState + 0x280);
    if (phase >= 0) {
        goto block_3;
    }
    *(u8 *)((char *)gSelectState + 0x281) = (u8) (*(u8 *)((char *)gSelectState + 0x281) - 1);
    if ((s8) *(u8 *)((char *)gSelectState + 0x281) >= 0) {
        goto block_8;
    }
    *(u8 *)((char *)gSelectState + 0x281) = 0x19U;
    goto block_8;
block_3:
    if (phase > 0) {
        goto block_5;
    }
    goto block_7;
block_5:
    *(s8 *)((char *)gSelectState + 0x280) = 0;
    goto block_8;
block_7:
    *(s8 *)((char *)gSelectState + 0x280) = -8;
block_8:
    return 0;
}
