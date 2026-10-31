extern u32 D_800C339C;
extern s32 func_8008E13C(u32, u32, s32);

s32 func_800821A4(u32 src, u32 len) {
    u32 dst, n, bytes, cnt, s;
    volatile u32 *gp;
    if (!len) return 0;
    gp = &D_800C339C;
    n = len >> 2;
    dst = D_800C339C;
    bytes = n << 2;
    s = src + bytes;
    cnt = bytes >> 2;
    if ((dst < s) & (src < dst)) {
        dst += bytes;
        while (cnt) { s -= 4; dst -= 4; *(u32 *)dst = *(u32 *)s; cnt--; }
    } else {
        s = src;
        while (cnt) { *(u32 *)dst = *(u32 *)s; s += 4; dst += 4; cnt--; }
    }
    *gp += n << 2;
    len = len % 4;
    func_8008E13C(D_800C339C, src + (n << 2), len);
    *gp += len << 2;
    return 0;
}
