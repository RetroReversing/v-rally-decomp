extern unsigned char gCurCount;
extern char gGameState[];

/* Reads the byte-offset field helper for obj. */
#define OBJ_FIELD(e, t, off) (*(t *)((s8 *)(e) + (off)))

/* Compares the next counter (one past the value at obj->+0xA8->+0x24->+0x70) with the byte limit gCurCount.
 * When it equals the limit, loads the 3-byte value FE D5 1E into obj+0x90 and clears flag bit 4 in obj+0x80;
 * otherwise sets that bit. Sets the bit again when the counter exceeds the limit. */
void obj_update_flag_vs_count(void *obj) {
    u32 counter;

    counter = *OBJ_FIELD(OBJ_FIELD(OBJ_FIELD(obj, void *, 0xA8), void *, 0x24), s32 *, 0x70) + 1;
    if (counter == gCurCount) {
        OBJ_FIELD(obj, u8, 0x90) = 0xFE;
        OBJ_FIELD(obj, u8, 0x91) = 0xD5;
        OBJ_FIELD(obj, s8, 0x92) = 0x1E;
        OBJ_FIELD(obj, s32, 0x80) &= ~4;
    } else {
        OBJ_FIELD(obj, s32, 0x80) |= 4;
    }
    if ((u8) gCurCount < counter) {
        OBJ_FIELD(obj, s32, 0x80) |= 4;
    }
}
