s32 slot_set_selected(s32, s32);
s32 select_stream_char(u8, u8, u8);
extern void *gSelectState;
extern s32 gStreamState;

/* Steps the stream entry chosen by select_stream_char: if its count at +0x14 is non-zero it is
 * decremented and the new count is passed to slot_set_selected. Always returns 1. */
s32 func_8006B4A4(s32 arg0) {
    u8 count;
    u8 next_count;
    char *group;
    char *entry;

    group = *(char **)((char *)&gStreamState + 0x32F2) + ((*(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + *(s8 *)((char *)gSelectState + 0x228) + 0x32) * 0x28) + 0x44);
    entry = group + (select_stream_char(*(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + 0x1F), *(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + 0x21), *(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + 0x23)) & 0xFF);
    count = *(u8 *)(entry + 0x14);
    if (count != 0) {
        next_count = count - 1;
        *(u8 *)(entry + 0x14) = next_count;
        slot_set_selected(arg0, next_count & 0xFF);
    }
    return 1;
}
