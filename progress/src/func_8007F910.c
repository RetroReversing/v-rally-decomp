s32 heapCreateBlock(s32, s32);
extern u32 osMemSize;
extern s32 D_800A1924;
extern s8 gHasExpansionPak;
extern s32 stream_state;

/* If the RAM size is above 4 MB (expansion pak present), hands the memory above
 * the base 4 MB to heapCreateBlock and sets the expansion-pak flag. Otherwise keeps
 * the stored value. Always returns 1. */
s32 func_8007F910(void)
{
    if ((u32) osMemSize > 0x400000U)
    {
        *(s32 *) ((s8 *) &stream_state + 0x702E) = heapCreateBlock(0x80400000, osMemSize - 0x400000);
        gHasExpansionPak = 1;
    }
    else
    {
        *(s32 *) ((s8 *) &stream_state + 0x702E) = (s32) *(s32 *) ((s8 *) &stream_state + 0x7032);
    }
    *(s32 **) ((s8 *) &stream_state + 0x5906) = &D_800A1924;
    return 1;
}
