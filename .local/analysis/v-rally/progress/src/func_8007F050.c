extern s32 D_800A19B0, D_800B5B40;
extern void (*D_800C8090)(s32), (*D_800C80A8)(s32);
extern s32 D_800C72D8[];
extern s32 func_80080F08(s32);
s32 func_8007F050(s32 arg0)
{
    volatile s32 sp10;
    s32 result = 0;
    s32 p;
    s32 q;
    if (D_800A19B0 == 1) D_800C80A8(D_800B5B40 - 4);
    D_800A19B0 = 1;
    do { D_800B5B40 = (s32) __builtin_mips_live_return_address(); } while (0);
    if (!(arg0 & 0xffff0000)) { p = D_800C72D8[arg0]; sp10 = arg0; } else { p = arg0; sp10 = 1; }
    if (p == 0) { D_800C8090(D_800B5B40 - 4); q = 0; } else q = p - 8;
    if (q) result = func_80080F08(q + 8);
    D_800A19B0 = 0;
    return result;
}
