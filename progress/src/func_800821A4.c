extern u32 D_800C339C;
extern u8 *func_8008E13C(u8 *, u8 *, s32);

/* Appends len bytes from src to the output position D_800C339C and advances it. Copies
   whole words first (in reverse when the source and destination overlap), then the
   0-3 leftover bytes through func_8008E13C. */
s32 func_800821A4(u8 *src, u32 len)
{
    u32 words;
    u32 *outPos;
    if (len == 0)
    {
        return 0;
    }
    if (src)
    {
        words = len >> 2;
    }
    else
    {
        words = len >> 2;
    }
    {
        u32 dst = D_800C339C;
        u32 bytes = words << 2;
        u8 *s = src + bytes;
        u32 cnt;
        if ((dst < ((u32) s)) & (((u32) src) < dst))
        {
            cnt = bytes >> 2;
            dst += bytes;
            while (cnt)
            {
                s -= 4;
                dst -= 4;
                *((u32 *) dst) = *((u32 *) s);
                cnt--;
            }

        }
        else
        {
            cnt = bytes >> 2;
            s = src;
            while (cnt)
            {
                *((u32 *) dst) = *((u32 *) s);
                s += 4;
                dst += 4;
                cnt--;
            }

        }
    }
    outPos = &D_800C339C;
    *outPos += words << 2;
    func_8008E13C((u8 *) D_800C339C, src + (words << 2), len & 3);
    *outPos += (len & 3) << 2;
    return 0;
}
