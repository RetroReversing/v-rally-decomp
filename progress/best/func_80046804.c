typedef struct { s32 x, y, z, w; } Vec4_80046804;
extern void (*D_800A0264[])(u8 *, s32, u8 *, s32);
void func_80046804(u8 **arg0, u8 *arg1)
{
    Vec4_80046804 dv;
    Vec4_80046804 pos;
    Vec4_80046804 dd;
    s32 unused[2];
    s32 *p;
    s32 bit;
    u16 bit2;
    s32 t;
    s32 i;
    s32 n;
    u8 *e;

    p = (s32 *)*arg0;
    pos.x = *(s32 *)(*(u8 **)(arg1 + 0x80) + 0x2B8);
    pos.z = *(s32 *)(*(u8 **)(arg1 + 0x80) + 0x2C0);
    dd.x = pos.x - p[0];
    dd.z = pos.z - p[2];
    if ((u32)((dd.x >> 4) * (dd.x >> 4) + (dd.z >> 4) * (dd.z >> 4)) < 50000) {
        bit = 1;
        n = (u16)(*(u16 *)(*(u8 **)(arg1 + 0x48) + 0x2E) * 2 | 1);
        i = 0;
        if (n > 0) {
            do {
                bit = (bit & 0xFFFF) << 1;
                i++;
            } while (i < n);
        }
        dv.x = pos.x - p[0];
        dv.y = pos.y - p[1];
        dv.z = pos.z - p[2];
        t = (bit & 0xFFFF) << 1;
        bit2 = t;
        if (dv.x * p[3] + dv.z * p[5] < 0) {
            e = (u8 *)p + 0x1C;
            if ((*(u16 *)((u8 *)p + 0x1A) & t) == bit2) {
                i = 0;
                if (i < *(u16 *)((u8 *)p + 0x18)) {
loop:
                    D_800A0264[*(u16 *)e](e + 8, *(u16 *)(e + 2), arg1, 0);
                    i++;
                    e += *(s32 *)(e + 4) + 8;
                    if (i < *(u16 *)((u8 *)p + 0x18)) goto loop;
                }
            }
            *(u16 *)((u8 *)p + 0x1A) = (*(u16 *)((u8 *)p + 0x1A) | bit) & ~bit2;
        } else {
            *(u16 *)((u8 *)p + 0x1A) = (*(u16 *)((u8 *)p + 0x1A) | bit2) & ~bit;
        }
    }
}
