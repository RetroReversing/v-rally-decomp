extern u32 *D_800A1B70;
s32 func_80085778(s32, s32, s32, void *);
void func_800855F8(s32 arg0, s32 arg1) {
    u32 *base = D_800A1B70;
    s32 index = arg0 & 0xFF;
    u32 *entry = (u32 *)((u8 *)base + index * 0x38);
    u32 first = *(u32 *)((u8 *)entry + 0xAC);
    u32 second = *(u32 *)((u8 *)entry + 0xB0);
    s32 flags;
    if (arg1 & first) flags = 1;
    else flags = 0;
    if (arg1 & second) flags |= 2;
    if (arg1 & *(u32 *)((u8 *)entry + 0xB4)) flags |= 4;
    if (arg1 & *(u32 *)((u8 *)entry + 0xB8)) flags |= 8;
    if (arg1 & *(u32 *)((u8 *)entry + 0xBC)) flags |= 0x10;
    if (arg1 & *(u32 *)((u8 *)entry + 0xC0)) flags |= 0x20;
    if (arg1 & *(u32 *)((u8 *)entry + 0xC4)) flags |= 0x100;
    if (arg1 & *(u32 *)((u8 *)entry + 0xC8)) flags |= 0x200;
    if (arg1 & *(u32 *)((u8 *)entry + 0xCC)) flags |= 0x400;
    {
        u32 *p;
        if (arg1 & *(u32 *)((u8 *)entry + 0xD0)) { flags |= 0x800; p = entry; } else p = entry;
        if (arg1 & *(u32 *)((u8 *)p + 0xD4)) flags |= 0x1000;
        if (arg1 & *(u32 *)((u8 *)p + 0xD8)) flags |= 0x2000;
        if (arg1 & *(u32 *)((u8 *)p + 0xDC)) flags |= 0x4000;
    }
    if (arg1 & *(u32 *)((u8 *)entry + 0xE0)) flags |= 0x8000;
    func_80085778(index, flags, arg1, entry);
}
