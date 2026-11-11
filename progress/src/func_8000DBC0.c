/* Folds this object's counters into its peak values (+4 and +6), clears the
   per-pass counters, rewrites the flag bits in +0x84 and resets the +0x14 end
   pointer to the +0x10 start pointer. */
void func_8000DBC0(char *obj)
{
    s32 count;
    u16 peak;
    s32 flags;

    count = (*((s32 *)(obj + 0x14)) - *((s32 *)(obj + 0x10))) >> 3;
    if (*((u16 *)(obj + 4)) < count) {
        *((u16 *)(obj + 4)) = count;
    }
    peak = *((u16 *)(obj + 0x7A));
    if (*((u16 *)(obj + 6)) < peak) {
        *((u16 *)(obj + 6)) = peak;
    }
    *((s32 *)(obj + 8)) = 0;
    *((u16 *)(obj + 0x7A)) = 0;
    *((u16 *)(obj + 0x78)) = 0;
    *((s32 *)(obj + 0x7C)) = 0;
    *((s32 *)(obj + 0x80)) = 0;
    *((s32 *)(obj + 0x18)) = 0;
    flags = *((s32 *)(obj + 0x84)) | 0x80000000;
    flags &= 0x87FFFFFF;
    flags |= 0x08000000;
    flags |= 0x04000000;
    flags &= 0xFCFFFFFF;
    flags &= 0xFF3FFFFF;
    flags |= 0x00400000;
    *((s32 *)(obj + 0x84)) = flags;
    *((s32 *)(obj + 0x14)) = *((s32 *)(obj + 0x10));
}
