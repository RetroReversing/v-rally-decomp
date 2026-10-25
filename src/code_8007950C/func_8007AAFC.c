#include "common.h"

void *func_800592AC(u8, void *);
s32 func_800593FC(s32, s32);
s32 func_8005946C(s32, u8);
s32 func_8007A688(u8, void *);
s32 func_8007A6D0();
extern void *D_800A1468;
extern char D_800C02AE[];

s32 func_8007AAFC(s32 arg0) {
    char *base;
    char *p;
    char *rec;
    char *var_v1;
    char *pa;
    s32 var_a0;
    u8 s0;
    u8 s1;
    u8 temp_a0;

    *((u8 *)D_800A1468 + 0x2BC) = 4;
    *((u8 *)D_800A1468 + 0x245) = 1;
    pa = D_800A1468;
    base = *(char **)(D_800C02AE + 0x32F2);
    p = base + *((s8 *)pa + 0x228);
    rec = base + *(u8 *)(p + 0x32) * 0x28;
    s1 = *(u8 *)(rec + 0x4F);
    s0 = s1;
    temp_a0 = *(u8 *)(*(char **)(D_800C02AE + 0x103AA) + s0 * 0x2C4 + 0x15);
    if (temp_a0 == *(u8 *)(pa + 0x238)) {
        var_v1 = *(char **)((char *)func_800592AC(temp_a0, D_800A1468) + 0x28);
        var_a0 = 0;
        if (*(u8 *)(var_v1 + 0x22) != s0) {
            do {
                var_v1 = *(char **)var_v1;
                var_a0 += 1;
            } while (*(u8 *)(var_v1 + 0x22) != s0);
        }
        *((u8 *)D_800A1468 + 0x239) = var_a0;
        *((u8 *)D_800A1468 + 0x237) = s1;
    } else {
        *(pa + 0x239) = 0;
        func_8007A688(temp_a0, pa);
    }
    func_8007A6D0();
    *((u8 *)D_800A1468 + 0x2BD) = 1;
    p = *(char **)(D_800C02AE + 0x325A);
    func_800593FC(arg0, *(u8 *)(*(char **)(p + 0x10) + *(s16 *)(p + 2) * 0x14 + 0xD) + 4);
    func_8005946C(arg0, *((u8 *)D_800A1468 + 0x239));
    return 0;
}
