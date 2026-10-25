#include "common.h"

extern s32 *D_800A19C0;
extern s32 D_800A19C4;
extern s32 D_800A1920;
extern char D_800A1924[];
extern char D_800C02AE[];
s32 func_8007F864(s32 *a0, u32 a1, s32 a2);

s32 func_8007F894(void)
{
    s32 *a0;
    u32 a1;
    s32 *p;
    u32 n;
    s32 val;
    s32 ret;

    a0 = D_800A19C0;
    a1 = D_800A19C4;
    if (a0 != NULL) {
        n = a1 >> 2;
        val = D_800A1920;
        if (n != 0) {
            p = a0;
            do {
                *p = val;
                p++;
                n--;
            } while (n != 0);
        }
        *(s32 *)(D_800C02AE + 0x7032) = func_8007F864(a0, a1, val);
        *(char **)(D_800C02AE + 0x590A) = D_800A1924;
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}
