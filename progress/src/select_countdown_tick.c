extern void *gSelectState;

/* Decrements the select-screen countdown byte at +0x22F while it is non-zero. Always returns 0. */
s32 select_countdown_tick(void) {
    u8 temp_v0;

    temp_v0 = *(u8 *)((s8 *)gSelectState + 0x22F);
    if (temp_v0 != 0) {
        *(u8 *)((s8 *)gSelectState + 0x22F) = (u8)(temp_v0 - 1);
    }
    return 0;
}
