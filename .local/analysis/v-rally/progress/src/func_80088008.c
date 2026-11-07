typedef struct S88008 {
    u8 pad00[0x30];
    s32 x30;
    s32 x34;
    u8 pad38[0x40];
    s32 x78;
    u8 pad7C[4];
    s32 x80;
    s32 x84;
    u8 pad88[0x12];
    s16 x9A;
    s16 x9C;
} S88008;

s32 func_80088008(S88008 *arg0, u8 *arg1) {
    s32 x, y, b, c, d, e, f;

    x = *arg1++;
    b = *arg1++;
    c = *arg1++;
    d = *arg1++;
    arg0->x9A = 1;
    y = c << 8;
    y += d;
    arg0->x34 = arg0->x84 + y;
    e = *arg1++;
    f = *arg1++;
    y = e << 8;
    y += f;
    arg0->x9C = 1;
    arg0->x30 = arg0->x80 + y;
    x <<= 8;
    x += b;
    return arg0->x78 + x;
}
