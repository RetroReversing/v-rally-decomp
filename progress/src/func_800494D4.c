extern s32 gPadFlags;
extern u8 gOrderState[];
extern u8 gStreamState[];

/* Sets pad flag 0x4000, and when the stream header's word at +0x1E is zero,
 * marks order slot `slot` (0x44-byte entries at +0x2410) with flag 2. */
void func_800494D4(s32 slot)
{
    s32 offset;

    if (!(gPadFlags & 0x4000))
    {
        gPadFlags |= 0x4000;
    }
    if (*(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x1E) == 0)
    {
        offset = (slot & 0xFF) * 0x44;
        *(u16 *)(gOrderState + 0x2410 + offset) |= 2;
    }
}
