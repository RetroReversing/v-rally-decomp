#include "common.h"

s32 func_8005946C();
extern char D_800C02AE[];

s32 func_800718F4(s32 arg0)
{
    char *p;
    s32 v;

    p = *((char **)(D_800C02AE + 0x32F2));
    if (*((u16 *)(p + 0x22)) == 0) {
        v = *((u16 *)(*((char **)(D_800C02AE + 0x10386 + *((u16 *)(p + 0x1E)) * 4)) + *((u16 *)(p + 0x20)) * 0x2C4 + 0x14));
    } else {
        v = *((u16 *)(p + 0x22));
    }
    *((u16 *)(p + 0x22)) = v - 1;
    func_8005946C(arg0, *((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x22)));
    return 0;
}
