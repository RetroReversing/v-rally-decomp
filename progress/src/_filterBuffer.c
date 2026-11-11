s32 osVirtualToPhysical();

/* Writes the display list commands that load a block of `count` pixels, with stride
 * `stride` halved, from the buffer described by desc. The block address comes from desc
 * (+0x28, converted to physical). Clears desc's word at +0x2C. Returns the address just
 * past the six words written to cmd. */
void *_filterBuffer(void *desc, s32 count, s32 stride, void *cmd)
{
    s32 *dst;
    u16 count16;
    s32 word1;
    void *new_var;

    count16 = count;
    dst = cmd;
    dst[0] = count16 | 0x08000000;
    word1 = (count16 << 0x10) | ((stride << 1) & 0xFFFF);
    dst[1] = word1;
    dst[2] = 0x0B000020;
    dst[3] = osVirtualToPhysical((char *) desc + 8, word1, (stride << 1) & 0xFFFF);
    new_var = dst + 6;
    dst[4] = (((*((u8 *) desc + 0x2F)) << 0x10) | 0x0E000000) | *((u16 *) ((char *) desc + 2));
    dst[5] = osVirtualToPhysical(*((s32 *) ((char *) desc + 0x28)));
    *((s32 *) ((char *) desc + 0x2C)) = 0;
    return new_var;
}
