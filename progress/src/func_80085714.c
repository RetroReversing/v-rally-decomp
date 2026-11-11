extern u8 *gContCtx;
s8 func_80084C0C(s32 slot, s32 mode);

/* Picks the gain mode for slot `slot` by matching `flags` against the slot's
 * two mask words (+0x68 selects mode 0x20000, +0x6C selects mode 0x10000);
 * returns 0 when neither matches, otherwise the gain from func_80084C0C. */
s8 func_80085714(s32 slot, s32 flags)
{
    s32 idx;
    u8 *base;
    u8 *entry;
    s32 mode;

    base = gContCtx;
    idx = slot & 0xFF;
    entry = base + idx * 0x14;
    if (flags == *(s32 *)(entry + 0x68)) {
        mode = 0x20000;
    } else if (flags == *(s32 *)(entry + 0x6C)) {
        mode = 0x10000;
    } else {
        return 0;
    }
    return func_80084C0C(idx, mode);
}
