#include "common.h"

void *func_800592AC();
extern char D_800C02AE[];
void func_8005937C(s32 arg0, s32 arg1)
{
    s32 i;
    char *p;
    char *cur;
    char *obj;
    char *base;
    p = *(char **)(D_800C02AE + 0x325A);
    base = *(char **)(p + 0x10);
    arg0 -= *(u8 *)(base + *(s16 *)(p + 2) * 0x14 + 0xD);
    obj = func_800592AC(arg0, base);
    *((s8 *)obj + 0x4D) = arg1;
    *((s8 *)obj + 0x4E) = 1;
    cur = *(char **)(obj + 0x28);
    i = 0;
    if (arg1 > 0) {
        do {
            *((s8 *)cur + 0x1B) = 0;
            cur = *(char **)cur;
            i++;
        } while ((i & 0xFF) < arg1);
    }
}
