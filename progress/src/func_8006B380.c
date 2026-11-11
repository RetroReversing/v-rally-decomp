s32 slot_set_selected(s32, s32);
s32 select_stream_char(u8, u8, u8);
extern void *gSelectState;
extern s32 gStreamState;

/* Steps the stream entry chosen by select_stream_char: if its step count at +0x18 is non-zero it is
 * decremented and the new count is passed to slot_set_selected. Always returns 1. */
s32 func_8006B380(s32 arg0) {
    u8 steps;
    u8 next_steps;
    char *group;
    char *entry;

    group = *(char **)((char *)&gStreamState + 0x32F2) + ((*(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + *(s8 *)((char *)gSelectState + 0x228) + 0x32) * 0x28) + 0x44);
    entry = group + (select_stream_char(*(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + 0x1F), *(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + 0x21), *(u8 *)(*(char **)((char *)&gStreamState + 0x32F2) + 0x23)) & 0xFF);
    steps = *(u8 *)(entry + 0x18);
    if (steps != 0) {
        next_steps = steps - 1;
        *(u8 *)(entry + 0x18) = next_steps;
        slot_set_selected(arg0, next_steps & 0xFF);
    }
    return 1;
}
