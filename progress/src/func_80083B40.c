extern u8 gOrderState, stream_state;
extern s32 inflateBlock(s32 *);
extern s32 func_800821A4(void *, s32, s32);

/* Inflates the deflate stream one block at a time until the last block, tracking the largest
 * block's output size. Returns the first error from inflateBlock; otherwise hands the total
 * output length to func_800821A4 and returns 0. */
s32 func_80083B40(void)
{
    s32 lastBlock;
    s32 ret;
    u32 *blockLen;
    u32 blockOut;
    u32 maxBlockOut = 0;

    {
        u32 *totalOut = (u32 *)(&stream_state + 0x310A);
        blockLen = totalOut - 5;
        *totalOut = 0;
    }
    *(u32 *)(&stream_state + 0x3112) = 0;
    *(u32 *)(&stream_state + 0x310E) = 0;
    do {
        *blockLen = 0;
        ret = inflateBlock(&lastBlock);
        if (ret) {
            return ret;
        }
        blockOut = *blockLen;
        if (maxBlockOut < blockOut) {
            maxBlockOut = blockOut;
        }
    } while (lastBlock == 0);
    func_800821A4(&gOrderState + 0x8AE8, *(s32 *)(&stream_state + 0x310A), 0);
    return 0;
}
