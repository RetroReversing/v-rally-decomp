#include "common.h"

extern char D_800C02AE[];

void func_8003B884(void *arg0) {
    char pad[8];
    u32 n;
    s32 *ptr;
    void *p;
    void *q;
    void *v0;
    void *r;
    u32 i;
    u16 cnt;
    s32 t2;
    s32 t1;
    s16 tmp;

    p = *(void **)((u8 *)arg0 + 0xA8);
    v0 = *(void **)((u8 *)p + 0x24);
    if (v0 != NULL) {
        i = 0;
        q = *(void **)((u8 *)p + 0x178);
        n = 0;
        ptr = *(s32 **)(*(u8 **)((u8 *)v0 + 0x6C));
        t2 = *(s16 *)((u8 *)q + 0xA) + 6;
        t1 = *(s16 *)((u8 *)q + 0xE) - 8;
        cnt = *(u16 *)((u8 *)arg0 + 0x76);
        if (cnt != 0) {
            do {
                i++;
                n += *ptr != 0;
                ptr++;
            } while (i < cnt);
        }
        if (n != 0) {
            if ((*(u16 *)((u8 *)(*(void **)(D_800C02AE + 0x32F2)) + 0xE) >= 2) & (n >= 3)) {
                n = 2;
            }
            *(s32 *)((u8 *)arg0 + 0x80) &= ~4;
            *(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x8C)) + 0x80) &= ~4;
            tmp = (t2 + t1) - ((n + 2) * 0xA) - 8;
            *(s16 *)((u8 *)arg0 + 0xE) = tmp;
            *(s16 *)((u8 *)(*(void **)((u8 *)arg0 + 0x8C)) + 0xE) = tmp;
            return;
        }
        r = *(void **)((u8 *)arg0 + 0x8C);
        *(s32 *)((u8 *)arg0 + 0x80) |= 4;
        *(s32 *)((u8 *)r + 0x80) |= 4;
    }
}
