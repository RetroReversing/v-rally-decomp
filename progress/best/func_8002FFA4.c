#define PTS(off) (*(u16 *)((off) + *(u8 **)(arg0 + 0x54)))
void func_8002FFA4(u8 *o, s32 arg1, s16 arg2, s16 *out)
{
    u8 *arg0 = o;
    s16 d[3];
    s32 t;
    s32 idx;
    s32 prev, next;
    s32 a, b;
    s16 d0;
    u8 *base;

    idx = *(s32 *)(arg0 + 0x4C) + arg1 * *(u16 *)(arg0 + 0x8A);
    t = arg2;
    prev = idx - 2;
    next = idx + 2;
    if (t < 50) {
        base = *(u8 **)(arg0 + 0x54);
        a = idx * 6;
        b = prev * 6;
        d0 = *(u16 *)(a + base) - *(u16 *)(b + base);
    } else {
        base = *(u8 **)(arg0 + 0x54);
        a = next * 6;
        b = idx * 6;
        d0 = *(u16 *)(a + base) - *(u16 *)(b + base);
        t -= 50;
    }
    d[0] = d0;
    d[1] = PTS(a + 2) - PTS(b + 2);
    d[2] = PTS(a + 4) - PTS(b + 4);
    d[0] = d[0] * t / 50;
    d[1] = d[1] * t / 50;
    d[2] = d[2] * t / 50;
    out[0] = PTS(b) + d[0];
    out[1] = PTS(b + 2) + d[1];
    out[2] = PTS(b + 4) + d[2];
}
