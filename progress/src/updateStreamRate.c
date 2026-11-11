extern s32 gStreamState;

/* Sets the stream rate target for a vehicle (+0x6C) from its track data and
 * toggles bit 0x4 of its flags (+0x80) based on the current stream state. */
void updateStreamRate(u8 *vehicle) {
    s32 flags;
    u32 rate;
    s32 mode;
    void *stream;
    void *ctl;
    u16 state;

    ctl = *(void **)(vehicle + 0xA8);
    stream = *(void **)((u8 *)ctl + 0x24);
    if (stream != NULL) {
        state = *(u16 *)(*(u8 **)((u8 *)&gStreamState + 0x32F2) + 0xE);
        if (((state >= 2U) && (*(s32 *)((u8 *)ctl + 0x20) & 0x880000)) || (state == 1)) {
            rate = *(u32 *)(*(u8 **)((u8 *)stream + 0x4C) + 4);
            if (rate < 0x7D1U) {
                rate = 0x7D0;
            }
            mode = *(s32 *)(*(u8 **)((u8 *)stream + 0x78) + 4);
            if ((rate >= 0x7D1U) & (mode == 0x1F40)) {
                rate += rate >> 1;
            }
            if ((rate >= 0x7D1U) & (mode == 0x2710)) {
                rate += rate >> 2;
            }
            if (rate >= 0x2EE1U) {
                rate = 0x2EE0;
            }
            *(s16 *)(vehicle + 0x6C) = (s16)(rate * 4);
            flags = *(s32 *)(vehicle + 0x80) & ~4;
        } else {
            flags = *(s32 *)(vehicle + 0x80) | 4;
        }
        *(s32 *)(vehicle + 0x80) = flags;
    }
}
