/* Writes a 16-byte entry in the table at obj+0x70: two shorts at +0 and +2, and the low half of extra at +4. */
void func_800067C8(char *obj, unsigned short index, short a, short b, s32 extra)
{
    int o = index << 4;
#ifdef PORT
    *(short *)(o + *(char **)(obj + 0x70)) = a;
    *(short *)(o + *(char **)(obj + 0x70) + 2) = b;
    *(short *)(o + *(char **)(obj + 0x70) + 4) = ((u16 *)&extra)[1];
#else
    *(short *)(o + *(int *)(obj + 0x70)) = a;
    *(short *)(o + *(int *)(obj + 0x70) + 2) = b;
    o += *(int *)(obj + 0x70);
    *(short *)(o + 4) = ((u16 *)&extra)[1];
#endif
}
