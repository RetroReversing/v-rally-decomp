#include "common.h"

extern char *D_800A1468;
extern char D_800C02AE[];
s32 func_800592F4();

s32 func_8006AFC0(s32 arg0)
{
    char *base;
    char *obj;
    u8 idx;

    base = *(char **)(D_800C02AE + 0x32F2);
    idx = *(u8 *)(base + *(s8 *)(D_800A1468 + 0x228) + 0x32);
    obj = base + (idx * 40 + 0x44);
    if (*(u8 *)(obj + 9) == 0) {
        *(u8 *)(obj + 9) = *(u8 *)(obj + 9) + 1;
    } else {
        *(u8 *)(obj + 9) = *(u8 *)(obj + 9) - 1;
    }
    func_800592F4(arg0, *(u8 *)(obj + 9));
    return 1;
}
