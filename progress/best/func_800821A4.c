extern u32 D_800C339C;
extern u8 *func_8008E13C(u8 *, u8 *, s32);

s32 func_800821A4(u8 *src, u32 len)
{
    u32 n;
    u32 *gp;

    if (len == 0) {
        return 0;
    }
    n = len >> 2;
    {
        u32 dst = D_800C339C;
        u32 bytes = n << 2;
        u8 *s = src + bytes;
        u32 cnt;

        if ((dst < (u32)s) & ((u32)src < dst)) {
            cnt = bytes >> 2;
            dst += bytes;
            while (cnt) {
                s -= 4;
                dst -= 4;
                *(u32 *)dst = *(u32 *)s;
                cnt--;
            }
        } else {
            cnt = bytes >> 2;
            s = src;
            while (cnt) {
                *(u32 *)dst = *(u32 *)s;
                s += 4;
                dst += 4;
                cnt--;
            }
        }
    }
    gp = &D_800C339C;
    *gp += n << 2;
    func_8008E13C((u8 *)D_800C339C, src + (n << 2), len & 3);
    *gp += (len & 3) << 2;
    return 0;
}
