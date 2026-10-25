#include "common.h"

s32 func_8006B924(void *, s32);
extern s32 D_800ADF70;
extern char D_800C3A50[];
extern u16 D_800C72C6[];

void func_8006CB9C(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 temp_s1;
    u8 var_s2;
    u8 var_s3;
    s32 var_a0;
    u16 *temp_s4;

    temp_s4 = D_800C72C6;
    var_s3 = 0;
    do {
        var_s2 = 0;
        do {
            var_s0 = var_s2;
            temp_s1 = var_s0 << 4;
            arg1 = func_8006B924(temp_s1 + D_800C3A50, arg1);
            if ((arg1 & 0xFF) == 5) {
                temp_s4[var_s0] = 0xFFFF;
            } else {
                var_a0 = D_800ADF70 - *(s32 *)(D_800C3A50 + temp_s1);
                if (var_a0 >= 0) {
                    if (var_a0 >= 0x4000) {
                        var_a0 = 0x3FFE;
                    }
                    var_a0 &= ~1;
                } else {
                    var_a0 = -var_a0;
                    if (var_a0 >= 0x4000) {
                        var_a0 = 0x3FFE;
                    }
                    var_a0 |= 1;
                }
                temp_s4[var_s2] = var_a0 | ((arg1 & 0xFF) << 14);
            }
            var_s2++;
        } while (var_s2 < 3);
        var_s3++;
    } while (var_s3 < 4);
}
