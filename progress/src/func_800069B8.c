/* Writes three consecutive 16-byte records of the table at obj->+0x70, starting at record index.
 * Each record's bytes at +0xC, +0xD, +0xE (and the next two records' +0xC..+0xE) are set from the
 * arguments: r0* goes to record index, r1* to index+1, r2* to index+2. */
void func_800069B8(void *obj, u16 index, s8 r0a, s8 r0b, u8 r0c, u8 r1a, u8 r1b, u8 r1c, u8 r2a, u8 r2b, u8 r2c) {
    s32 off;

    off = (index & 0xFFFF) * 0x10;
#ifdef PORT
    *(s8 *)(off + *(char **)((char *)obj + 0x70) + 0xC) = r0a;
    *(s8 *)(off + *(char **)((char *)obj + 0x70) + 0xD) = r0b;
    *(u8 *)(off + *(char **)((char *)obj + 0x70) + 0xE) = r0c;
    *(u8 *)(off + *(char **)((char *)obj + 0x70) + 0x1C) = r1a;
    *(u8 *)(off + *(char **)((char *)obj + 0x70) + 0x1D) = r1b;
    *(u8 *)(off + *(char **)((char *)obj + 0x70) + 0x1E) = r1c;
    *(u8 *)(off + *(char **)((char *)obj + 0x70) + 0x2C) = r2a;
    *(u8 *)(off + *(char **)((char *)obj + 0x70) + 0x2D) = r2b;
    *(u8 *)(off + *(char **)((char *)obj + 0x70) + 0x2E) = r2c;
#else
    *(s8 *)(off + *(s32 *)((char *)obj + 0x70) + 0xC) = r0a;
    *(s8 *)(off + *(s32 *)((char *)obj + 0x70) + 0xD) = r0b;
    *(u8 *)(off + *(s32 *)((char *)obj + 0x70) + 0xE) = r0c;
    *(u8 *)(off + *(s32 *)((char *)obj + 0x70) + 0x1C) = r1a;
    *(u8 *)(off + *(s32 *)((char *)obj + 0x70) + 0x1D) = r1b;
    *(u8 *)(off + *(s32 *)((char *)obj + 0x70) + 0x1E) = r1c;
    *(u8 *)(off + *(s32 *)((char *)obj + 0x70) + 0x2C) = r2a;
    *(u8 *)(off + *(s32 *)((char *)obj + 0x70) + 0x2D) = r2b;
    *(u8 *)(off + *(s32 *)((char *)obj + 0x70) + 0x2E) = r2c;
#endif
}
