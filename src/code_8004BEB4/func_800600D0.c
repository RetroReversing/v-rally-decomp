#include "common.h"

s32 func_800592F4();
s32 func_8006FA8C();
extern char D_800C02AE[];

s32 func_800600D0(void) {
    s32 s0;
    s32 v1;
    s32 t0;
    s32 a2;
    s32 a3;
    u8 a0;
    u8 *a1;

    s0 = 0;
    t0 = 1;
    a2 = 3;
    a3 = -9;
loop_1:
    a1 = *(u8 **)(D_800C02AE + 0x32F2);
    a0 = a1[0x2F];
    v1 = s0 & 0xFF;
    if (((a0 >> v1) & 1) != 0) {
        goto block_4;
    }
    if (v1 == 0) {
        goto block_9;
    }
    s0 -= 1;
    a1[0x2F] = a0 & ~(t0 << s0);
    goto block_9;
block_4:
    if (v1 == a2) {
        a1[0x2F] = a0 & a3;
        goto block_9;
    }
    s0 += 1;
    if ((u32) (s0 & 0xFF) < 4U) {
        goto loop_1;
    }
block_9:
    func_8006FA8C(a0, a1, a2, a3);
    func_800592F4(0x1C, s0 & 0xFF);
    return 0;
}
