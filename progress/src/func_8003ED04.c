extern char gStreamState[];
s32 func_80041564();

/* Sets node's 0x7A field from the table entry of the current slot: a raw code below 0x41 maps
 * to raw - 0x16, otherwise to code - 0x41. Negative results are clamped to 0. */
void func_8003ED04(void *node) {
    u8 *track;
    s32 base;
    s32 index;
    s32 raw;
    u32 code;
    u8 *entry;

    track = *(u8 **)((u8 *)(*(u8 **)((u8 *)node + 0xA8)) + 0x24);
    func_80041564();
    base = *(s32 *)(gStreamState + 0x32F2);
    index = *(u8 *)(base + **(s32 **)(track + 0x48) + 0x32);
    entry = (u8 *)(base + index * 40);
    entry = entry + *(u16 *)((u8 *)node + 0x78);
    raw = *(u8 *)(entry + 0x44);
    code = raw & 0xFF;
    if (code < 0x41) {
        *(s16 *)((u8 *)node + 0x7A) = raw - 0x16;
    } else {
        *(s16 *)((u8 *)node + 0x7A) = code - 0x41;
    }
    if (*(s16 *)((u8 *)node + 0x7A) < 0) {
        *(s16 *)((u8 *)node + 0x7A) = 0;
    }
}
