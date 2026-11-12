void *poolAlloc(s32, s32);
s32 obj_reset_records(void *);
extern char stream_state[];

/* Builds the per-object draw block: allocates the 0x54-byte header and the sub-entry arrays
 * (7 small ones, plus the main and secondary tables sized from the source's counts), fills
 * in the scale and the table sizes, then hands the block to obj_reset_records. */
void func_80020694(void *src, void *dst) {
    s32 freq;
    s32 i;
    u16 gameMode;
    u32 count;
    u32 count2;
    void *block;
    u8 *p;

    block = poolAlloc(1, 0x54);
    *(void **)(*(u8 **)((u8 *)dst + 0x38)) = block;
    i = 0;
    if ((u16) *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0xE) < 3U) {
        do {
            *(void **)(((i & 0xFF) * 4) + (u8 *)block + 0x38) = poolAlloc(1, 0xE);
            i += 1;
        } while ((u32) (i & 0xFF) < 7U);
        count = *(u32 *)((u8 *)src + 0x90);
        if ((u8) (*(u8 *)(stream_state + 0x7678) - 1) < 2U) {
            count = count >> 1;
        } else if ((*(u8 *)(stream_state + 0x7678) & 0xFF) == 3) {
            count = count >> 2;
        }
        *(s32 *)(*(u8 **)((u8 *)dst + 0x38) + 4) = (s32) *(s32 *)((u8 *)src + 0xDC);
        *(s32 *)(*(u8 **)((u8 *)dst + 0x38) + 8) = (s32) *(s32 *)((u8 *)src + 0x128);
        count2 = *(u32 *)((u8 *)src + 0x174);
        if (((u32) (*(u8 *)(stream_state + 0x7678) - 1) < 2U) || (gameMode = *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x1E), (gameMode == 5)) || ((gameMode != 0) & (gameMode < 5U))) {
            count2 = count2 >> 1;
        }
        freq = *(s32 *)((u8 *)src + 0x1C0); *(s16 *)((u8 *)block + 4) = (s16) (freq * freq);
        *(void **)block = poolAlloc(1, count * 0x24);
        *(s16 *)((u8 *)block + 0x14) = (s16) count;
        *(void **)((u8 *)block + 0x10) = poolAlloc(1, count2 * 0x24);
        *(s16 *)((u8 *)block + 0x16) = (s16) count2;
        obj_reset_records(block);
    }
}
