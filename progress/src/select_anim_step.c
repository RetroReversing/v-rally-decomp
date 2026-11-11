extern void *gSelectState;

/* Steps the select screen's animation state: the signed timer at +0x280 counts
 * a frame (stored at +0x281, wrapping at 26) while positive, is cleared when
 * negative, and is reloaded with 8 when zero. */
s32 select_anim_step(void)
{
    s8 timer;

    timer = *(s8 *)((char *)gSelectState + 0x280);
    if (timer > 0) {
        *(u8 *)((char *)gSelectState + 0x281) = (u8)(*(u8 *)((char *)gSelectState + 0x281) + 1);
        if ((s8)*(u8 *)((char *)gSelectState + 0x281) == 0x1A) {
            *(u8 *)((char *)gSelectState + 0x281) = 0U;
        }
    } else if (timer < 0) {
        *(s8 *)((char *)gSelectState + 0x280) = 0;
    } else {
        *(s8 *)((char *)gSelectState + 0x280) = 8;
    }
    return 0;
}
