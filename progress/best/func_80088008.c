s32 func_80088008(u8 *arg0, u8 *arg1) {
    s32 a2, t1, a3, v1, v0;

    t1 = *arg1++;
    a2 = *arg1++;
    v1 = *arg1++;
    a3 = *arg1++;
    v0 = *(s32 *)(arg0 + 0x84);
    *(s16 *)(arg0 + 0x9A) = 1;
    a3 = (a3 << 8) + v1;
    *(s32 *)(arg0 + 0x34) = v0 + a3;
    v0 = arg1[0];
    arg1 = (u8 *)(s32)arg1[1];
    v1 = *(s32 *)(arg0 + 0x80);
    a2 = (a2 << 8) + t1;
    *(s16 *)(arg0 + 0x9C) = 1;
    a3 = v0 << 8;
    v0 = *(s32 *)(arg0 + 0x78);
    a3 += (s32)arg1;
    v1 += a3;
    *(s32 *)(arg0 + 0x30) = v1;
    return v0 + a2;
}
