s32 osDisableInt(s32 a0);
void osRestoreInt(s32 a0);
extern u16 *__osViCurr;

/* Turns the VI blank bit (0x20 in the VI control word at __osViCurr) on when
 * active is non-zero, off otherwise. Interrupts are disabled around the update. */
void osViBlack(s32 active)
{
    s32 saved_int;
    u16 *ctrl;

    saved_int = osDisableInt(active);
    if (active & 0xFF) {
        ctrl = __osViCurr;
        *ctrl = *ctrl | 0x20;
    } else {
        ctrl = __osViCurr;
        *ctrl = *ctrl & 0xFFDF;
    }
    osRestoreInt(saved_int);
}
