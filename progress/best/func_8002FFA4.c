/* Partial candidate from function #24876 in project #57; rechecked locally. */
void func_8002FFA4(u8 *arg0, s32 arg1, s32 arg2, s16 *arg3) {
char *__repair_addr;

    s16 sp[3];
    s16 t1;
    s32 a0;
    s32 a1;
    s32 a3;
    s32 t0;
    s32 v1;
    s16 d0;
    s16 d1;
    s16 d2;
    u8 *base;

    a0 = arg1 * *(u16 *)(arg0 + 0x8A) + *(s32 *)(arg0 + 0x4C);
    t0 = a0 - 2;
    v1 = a0 + 2;
    if (t1 < 0x32) {
        base = *(u8 **)(arg0 + 0x54);
        a1 = a0 * 6;
        a3 = t0 * 6;
__repair_addr = (char *)(base + a3);

        d0 = *(u16 *)(base + a1) - *(u16 *)(__repair_addr);
    } else {
        base = *(u8 **)(arg0 + 0x54);
        a1 = v1 * 6;
        a3 = a0 * 6;
        d0 = *(u16 *)(base + a1) - *(u16 *)(base + a3);
        t1 -= 0x32;
    }
    sp[0] = d0;
    d1 = *(u16 *)(*(u8 **)(arg0 + 0x54) + a1 + 2) - *(u16 *)(*(u8 **)(arg0 + 0x54) + a3 + 2);
    sp[1] = d1;
    d2 = *(u16 *)(*(u8 **)(arg0 + 0x54) + a1 + 4) - *(u16 *)(*(u8 **)(arg0 + 0x54) + a3 + 4);
    sp[2] = d2;
    sp[0] = ((s16)d0 * t1) / 50;
    sp[1] = ((s16)d1 * t1) / 50;
    sp[2] = ((s16)d2 * t1) / 50;
    arg3[0] = *(u16 *)(*(u8 **)(arg0 + 0x54) + a3) + sp[0];
    arg3[1] = *(u16 *)(*(u8 **)(arg0 + 0x54) + a3 + 2) + sp[1];
    arg3[2] = *(u16 *)(*(u8 **)(arg0 + 0x54) + a3 + 4) + sp[2];
}
