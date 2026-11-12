extern s32 gOrderState;
extern s32 stream_state;

/* Syncs the stream position (stream_state+0x3092) with the order counter (gOrderState+0x8ACC).
 * When the stream is ahead, the counter is clamped to at least 0, +0x311A gets the stream
 * base (+0x308E) plus the counter, +0x3116 gets the gap, and the stream position becomes the
 * counter. Otherwise +0x3116 is cleared. The counter is then reduced by the stream position. */
void order_sync_stream_pos(void)
{
    s32 *counter;

    if ((*((s32 *)(((char *)(&stream_state)) + 0x3092))) > (*((s32 *)(((char *)(&gOrderState)) + 0x8ACC))))
    {
        counter = (s32 *)(((char *)(&gOrderState)) + 0x8ACC);
        if ((*((s32 *)(((char *)(&gOrderState)) + 0x8ACC))) < 0)
        {
            *((s32 *)(((char *)(&gOrderState)) + 0x8ACC)) = 0;
        }
        *((s32 *)(((char *)(&stream_state)) + 0x311A)) = (s32)((*((s32 *)(((char *)(&stream_state)) + 0x308E))) + (*((s32 *)(((char *)(&gOrderState)) + 0x8ACC))));
        *((s32 *)(((char *)(&stream_state)) + 0x3116)) = (s32)((*((s32 *)(((char *)(&stream_state)) + 0x3092))) - (*((s32 *)(((char *)(&gOrderState)) + 0x8ACC))));
        *((s32 *)(((char *)(&stream_state)) + 0x3092)) = (s32)(*counter);
    }
    else
    {
        *((s32 *)(((char *)(&stream_state)) + 0x3116)) = 0;
    }
    *((s32 *)(((char *)(&gOrderState)) + 0x8ACC)) = (s32)((*((s32 *)(((char *)(&gOrderState)) + 0x8ACC))) - (*((s32 *)(((char *)(&stream_state)) + 0x3092))));
}
