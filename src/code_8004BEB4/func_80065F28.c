#include "common.h"

extern char D_800C02AE[];
extern char *D_800A1468;
extern char *D_800C35A0;
void func_8008A140(void *);

s32 func_80065F28(void)
{
    char *p;
    char *q;

    p = *(char **)(D_800C02AE + 0x32F2);
    q = D_800A1468;
    *(s16 *)(p + 0x22) = 0;
    *(s8 *)(q + 0x245) = 0;
    func_8008A140(*(void **)(D_800C02AE + 0x325A));
    if (*(s16 *)(*(char **)(D_800C02AE + 0x325A) + 2) == 2) {
        return *(u16 *)(D_800C35A0 + 0x20) + 9;
    }
    return *(u16 *)(D_800C35A0 + 0x20) + 4;
}
