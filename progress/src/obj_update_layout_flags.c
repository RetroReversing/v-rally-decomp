extern char stream_state[];

/* Updates the 0x4 flag on this object and its partner, and its position. When any of the
 * `count` entries in the flag list is set, the position is recomputed from the
 * config bias values, and the flags are cleared; otherwise both get the flag set. */
void obj_update_layout_flags(void *obj) {
    char pad[8];
    u32 active;
    s32 *flags;
    void *ctx;
    void *cfg;
    void *item;
    void *partner;
    u32 k;
    u16 count;
    s32 bias2;
    s32 bias1;
    s16 pos;

    ctx = *(void **)((u8 *)obj + 0xA8);
    item = *(void **)((u8 *)ctx + 0x24);
    if (item != NULL) {
        k = 0;
        cfg = *(void **)((u8 *)ctx + 0x178);
        active = 0;
        flags = *(s32 **)(*(u8 **)((u8 *)item + 0x6C));
        bias2 = *(s16 *)((u8 *)cfg + 0xA) + 6;
        bias1 = *(s16 *)((u8 *)cfg + 0xE) - 8;
        count = *(u16 *)((u8 *)obj + 0x76);
        if (count != 0) {
            do {
                k++;
                active += *flags != 0;
                flags++;
            } while (k < count);
        }
        if (active != 0) {
            if ((*(u16 *)((u8 *)(*(void **)(stream_state + 0x32F2)) + 0xE) >= 2) & (active >= 3)) {
                active = 2;
            }
            *(s32 *)((u8 *)obj + 0x80) &= ~4;
            *(s32 *)((u8 *)(*(void **)((u8 *)obj + 0x8C)) + 0x80) &= ~4;
            pos = (bias2 + bias1) - ((active + 2) * 0xA) - 8;
            *(s16 *)((u8 *)obj + 0xE) = pos;
            *(s16 *)((u8 *)(*(void **)((u8 *)obj + 0x8C)) + 0xE) = pos;
            return;
        }
        partner = *(void **)((u8 *)obj + 0x8C);
        *(s32 *)((u8 *)obj + 0x80) |= 4;
        *(s32 *)((u8 *)partner + 0x80) |= 4;
    }
}
