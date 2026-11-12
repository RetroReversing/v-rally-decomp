/* Stores two 16-bit values at +8 and +0xA of entry 'index' in the 16-byte entry table kept at obj+0x70.
 * Each value is the low 16 bits of its argument shifted left by 6. */
void func_80008C58(void *obj, s32 index, s32 x, s32 y) {
    unsigned int mask;
    s32 offset;

    mask = 0xFFFF;
    offset = (index & mask) * 0x10;
#ifdef PORT
    *((s16 *)(((char *)(offset + (*((char **)(((char *)obj) + 0x70))))) + 8)) = (s16)((x & mask) << 6);
    *((s16 *)(((char *)(offset + (*((char **)(((char *)obj) + 0x70))))) + 0xA)) = (s16)((y & mask) << 6);
#else
    *((s16 *)(((char *)(offset + (*((s32 *)(((char *)obj) + 0x70))))) + 8)) = (s16)((x & mask) << 6);
    *((s16 *)(((char *)(offset + (*((s32 *)(((char *)obj) + 0x70))))) + 0xA)) = (s16)((y & mask) << 6);
#endif
}
