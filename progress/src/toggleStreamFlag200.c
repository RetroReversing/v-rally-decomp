extern u8 gStreamState[];
s32 slot_set_selected(s32, s32);

/* Toggles bit 0x200 of the flags halfword at +0x2C of the stream object (pointer at
 * gStreamState+0x32F2), then selects slot 0x17 with the bit's new state. */
s32 toggleStreamFlag200(void) {
    s32 on;
    u16 flags;

    flags = *(u16 *)((s8 *)*(void **)((s8 *)gStreamState + 0x32F2) + 0x2C);
    on = 0;
    if (flags & 0x200) {
        *(u16 *)((s8 *)*(void **)((s8 *)gStreamState + 0x32F2) + 0x2C) = (u16) (flags & 0xFDFF);
    } else {
        *(u16 *)((s8 *)*(void **)((s8 *)gStreamState + 0x32F2) + 0x2C) = (u16) (flags | 0x200);
        on = 1;
    }
    slot_set_selected(0x17, on);
    return 0;
}
