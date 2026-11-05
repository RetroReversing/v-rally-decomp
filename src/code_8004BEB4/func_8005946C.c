#include "decompdecomp_snapshot_8005946c.h"
#line 1 "func.c"
void *func_800592AC(u32);
extern char D_800C02AE[];
void func_8005946C(s32 arg0, s32 arg1)
{
    char *p;
    char *base;
    char *obj;
    char *cur;
    u32 i;
    u8 n;
    p = *(char **)(D_800C02AE + 0x325A);
    base = *(char **)(p + 0x10);
    obj = func_800592AC(arg0 - *(u8 *)(base + *(s16 *)(p + 2) * 0x14 + 0xD));
    n = *(u8 *)(obj + 0x4D);
    cur = *(char **)(obj + 0x28);
    i = 0;
    if (n != 0) {
        do {
            if ((i & 0xFF) == arg1) {
                *(s8 *)(cur + 0x1B) = 1;
            } else {
                *(s8 *)(cur + 0x1B) = 0;
            }
            cur = *(char **)cur;
            i++;
        } while ((i & 0xFF) < n);
    }
}

