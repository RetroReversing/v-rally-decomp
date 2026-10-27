#include "common.h"

extern int D_800B6B00;
extern int D_800B5C40;
extern int D_800C7410;
extern int D_800B7040;
extern s32 D_8009D6B0;
extern char D_800A4950[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_80022184();
extern s32 func_800221D4();
extern s32 func_800223B4();
extern s32 func_80080440();
extern s32 func_800227AC;
extern s32 func_800227C8;
extern s32 func_80080478;

void func_8002283C(void) {
    s32 *var_s0;
    s32 var_s1;
    if (func_80022184(D_800AE850 + 0x7320) != 0) goto block_7;
    if (*(u16 *)(*(void **)(D_800C02AE + 0x32F2) + 0x1E) != 7) goto block_3;
    D_800B6B00 = 2;
    var_s1 = 0;
    goto block_4;
block_3:
    D_800B6B00 = 0;
    var_s1 = 0;
block_4:
    var_s0 = (s32 *)(D_800C02AE + 0x7162);
loop_5:
    var_s1 += 1;
    *var_s0 = func_80080440();
    var_s0 += 1;
    if (var_s1 == 0) goto loop_5;
    D_8009D6B0 = 0;
    D_800B5C40 = D_800C7410;
    func_800221D4(D_800AE850 + 0x7320, &func_800227C8);
    func_800223B4(D_800B7040, &func_800227AC, &func_80080478, &D_800A4950, 0);
block_7:
    return;
}
