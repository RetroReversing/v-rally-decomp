extern u32 *gContCtx;
s32 func_80085778(s32, s32, s32, void *);

/* Reads the controller slot `slot` from the context table and builds a bit mask of which
 * of the buttons in `pressed` are set in its per-button words, then passes it on. */
void func_800855F8(s32 slot, s32 pressed) {
    u32 *base = gContCtx;
    s32 index = slot & 0xFF;
    u32 *entry = (u32 *)((u8 *)base + index * 0x38);
    u32 first = *(u32 *)((u8 *)entry + 0xAC);
    u32 second = *(u32 *)((u8 *)entry + 0xB0);
    s32 mask;
    if (pressed & first) mask = 1;
    else mask = 0;
    if (pressed & second) mask |= 2;
    if (pressed & *(u32 *)((u8 *)entry + 0xB4)) mask |= 4;
    if (pressed & *(u32 *)((u8 *)entry + 0xB8)) mask |= 8;
    if (pressed & *(u32 *)((u8 *)entry + 0xBC)) mask |= 0x10;
    if (pressed & *(u32 *)((u8 *)entry + 0xC0)) mask |= 0x20;
    if (pressed & *(u32 *)((u8 *)entry + 0xC4)) mask |= 0x100;
    if (pressed & *(u32 *)((u8 *)entry + 0xC8)) mask |= 0x200;
    if (pressed & *(u32 *)((u8 *)entry + 0xCC)) mask |= 0x400;
    {
        u32 *p;
        if (pressed & *(u32 *)((u8 *)entry + 0xD0)) { mask |= 0x800; p = entry; } else p = entry;
        if (pressed & *(u32 *)((u8 *)p + 0xD4)) mask |= 0x1000;
        if (pressed & *(u32 *)((u8 *)p + 0xD8)) mask |= 0x2000;
        if (pressed & *(u32 *)((u8 *)p + 0xDC)) mask |= 0x4000;
    }
    if (pressed & *(u32 *)((u8 *)entry + 0xE0)) mask |= 0x8000;
    func_80085778(index, mask, pressed, entry);
}
