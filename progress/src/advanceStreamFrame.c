extern u16 D_8009BEE4;
extern u32 D_800A18D0;
extern u8 gRecordTier[];
extern u8 *gRecords;

/* Advances the frame counter of a stream (wrapping at a limit that is one lower when
 * flag bit 1 is clear) and, for objects whose +0x20 word is zero, saves it in the record table. */
void advanceStreamFrame(u8 *stream, u8 *owner)
{
    u32 frame;
    u32 flag;
    u8 *obj;
    s32 limit;

    frame = *(u32 *)(stream + 0x30);
    flag = D_800A18D0 & 2;
    frame = frame + 1;
    *(u32 *)(stream + 0x30) = frame;
    limit = D_8009BEE4 - (flag == 0);
    if (!(frame < limit))
    {
        *(u32 *)(stream + 0x30) = 0;
    }
    obj = *(u8 **)(owner + 0x48);
    if (*(s32 *)(obj + 0x20) == 0)
    {
        gRecordTier[*(gRecords + *(s32 *)obj + 0x32)] = *(u32 *)(stream + 0x30);
    }
}
