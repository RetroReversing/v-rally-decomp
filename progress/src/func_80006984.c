/* Sets the three colour/flag bytes (+0xC, +0xD, +0xE) of entry 'index' in the 16-byte entry table
 * that the object keeps at +0x70. The index is masked to 16 bits. */
void func_80006984(void *obj, s32 index, s8 arg2, s8 arg3, u8 arg4) {
    s32 offset;

    offset = (index & 0xFFFF) * 0x10;
#ifdef PORT
    *(s8 *)(offset + *(s8 **)((s8 *)obj + 0x70) + 0xC) = arg2;
    *(s8 *)(offset + *(s8 **)((s8 *)obj + 0x70) + 0xD) = arg3;
    *(u8 *)(offset + *(s8 **)((s8 *)obj + 0x70) + 0xE) = arg4;
#else
    *(s8 *)(offset + *(s32 *)((s8 *)obj + 0x70) + 0xC) = arg2;
    *(s8 *)(offset + *(s32 *)((s8 *)obj + 0x70) + 0xD) = arg3;
    *(u8 *)(offset + *(s32 *)((s8 *)obj + 0x70) + 0xE) = arg4;
#endif
}
