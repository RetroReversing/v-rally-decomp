extern u8 stream_state[];

/* Advances the frame counter at +4 of the record that ctx+0x6C points to. While the stream
 * state byte is 3, a counter that sits on a multiple of 3 is nudged up by one more. */
void func_80020DB0(void *ctx)
{
    s32 count;
    u8 *frame;
    u8 *frame2;

    frame = *(u8 **)((u8 *)ctx + 0x6C);
    *(s32 *)(frame + 4) = *(s32 *)(frame + 4) + 1;
    if (stream_state[0x7681] == 3) {
        frame2 = *(u8 **)((u8 *)ctx + 0x6C);
        count = *(s32 *)(frame2 + 4);
        if (count == (*(s32 *)(frame2 + 4) / 3) * 3) {
            *(s32 *)(frame2 + 4) = count + 1;
        }
    }
}
