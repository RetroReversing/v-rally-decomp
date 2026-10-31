#include "snapshot31_verified.h"

void func_80024754(void **arg0) {
    s32 temp_a1_2, temp_t1, temp_v0, temp_v0_2, temp_v0_3, temp_v0_4;
    s32 temp_v1, temp_v1_4, var_a1, loop_idx, loop_sum, var_a3, var_v1;
    u8 var_v0;
    void *temp_a1, *temp_a1_3, *temp_a1_4, *temp_a2, *temp_t0, *temp_t2;
    void *temp_v1_2, *temp_v1_3, *temp_v1_5, *var_a0, *var_v1_2;

    var_a0 = *arg0;
    if (var_a0 != NULL) {
        do {
            temp_a2 = *(void **)((u8 *)var_a0 + 0x50);
            temp_a1 = *(void **)((u8 *)var_a0 + 0x48);
            temp_t2 = *(void **)((u8 *)var_a0 + 0x4C);
            temp_t1 = *(s32 *)*(s32 **)((u8 *)var_a0 + 0x58);
            var_a3 = *(s32 *)temp_a2;
            temp_t0 = (u8 *)temp_a1 + 4;
            if ((temp_t1 < 0x7D0) & (var_a3 < 3)) {
                if ((*((u8 *)temp_a1 + 8) != 0) || ((var_v1 = 0, (*(s32 *)((u8 *)temp_a2 + 4) & 2) != 0) && *((u8 *)temp_a1 + 9) != 0)) {
                    temp_a1_2 = (*(s32 *)(*(void **)((u8 *)var_a0 + 0x78) + 4) - *(s32 *)((u8 *)temp_t2 + 4) + 0x3E8) >> 4;
                    if (temp_a1_2 >= 0x65) temp_a1_2 = 0x64;
                    temp_v0 = temp_t1 >> 4;
                    if (temp_t1 >= 0) var_v1 = temp_a1_2 - temp_v0;
                    else var_v1 = temp_a1_2 + temp_v0;
                }
            } else var_v1 = 0;
            if (var_v1 < 0) {
                *(s32 *)((u8 *)*(void **)((u8 *)var_a0 + 0x48) + 0x18) = 0;
            } else {
                *(s32 *)((u8 *)*(void **)((u8 *)var_a0 + 0x48) + 0x18) = var_v1;
            }

            temp_v1 = *((u8 *)temp_t0 + 3) & 0xEF;
            switch (temp_v1) {
            case 0x20:
                if ((var_a3 < *(s32 *)(*(void **)((u8 *)var_a0 + 0x7C) + 0x20)) &&
                    ((temp_v0_2 = *(s32 *)((u8 *)*(void **)((u8 *)var_a0 + 0x50) + 4), temp_v0_2 == 0) ||
                     ((temp_v0_2 != 0) & (var_a3 < 2)))) var_a3 += 1;
                var_v0 = *((u8 *)temp_t0 + 2) & 0xDF;
                *((u8 *)temp_t0 + 2) = var_v0;
                break;
            case 0x40:
                if ((var_a3 > 0) &&
                    ((temp_v0_3 = *(s32 *)((u8 *)*(void **)((u8 *)var_a0 + 0x50) + 4), temp_v0_3 == 0) ||
                     ((temp_v0_3 != 0) & (var_a3 < 3)))) var_a3 -= 1;
                var_v0 = *((u8 *)temp_t0 + 2) & 0xBF;
                *((u8 *)temp_t0 + 2) = var_v0;
                break;
            }
            temp_v1_2 = *(void **)((u8 *)var_a0 + 0x50);
            if (*(s32 *)((u8 *)temp_v1_2 + 4) != 0) {
                if (*(s32 *)((u8 *)temp_v1_2 + 8) == 0) {
                    temp_a1_2 = 0;
                    loop_idx = 0;
                    var_v1_2 = *(void **)((u8 *)var_a0 + 0x54);
                    for (; loop_idx < 4; loop_idx++)
                        temp_a1_2 += *(s32 *)((u8 *)var_v1_2 + 0x10 + loop_idx * 4);
                    loop_sum = temp_a1_2;
                    if (((u32)(loop_sum + 0xAFF) < 0x15FFU) &&
                        ((*(s32 *)(*(void **)((u8 *)var_a0 + 0x78) + 4) - 0x5DC) < *(s32 *)((u8 *)temp_t2 + 4)) &&
                        ((var_a3 < *(s32 *)(*(void **)((u8 *)var_a0 + 0x7C) + 0x20)) & (var_a3 > 0)) &&
                        (*(s32 *)((u8 *)*(void **)((u8 *)var_a0 + 0x48) + 0x18) == 0)) var_a3 += *((u8 *)temp_t0 + 4) != 0;
                    temp_a1_2 = *(s32 *)((u8 *)temp_t2 + 4);
                    if (temp_a1_2 >= 0)
                        var_a3 -= (temp_a1_2 < (*(s32 *)(*(void **)((u8 *)var_a0 + 0x78) + 4) - 0xFA0)) & (var_a3 >= 3);
                    if ((*((u8 *)temp_t0 + 5) != 0) && (*(s32 *)*(void **)((u8 *)var_a0 + 0x48) != 5)) {
                        if ((u32)(temp_t1 + 0x12B) < 0x257U) {
                            temp_v1_3 = *(void **)((u8 *)var_a0 + 0x50);
                            var_a3 = 0;
                            *(s32 *)((u8 *)temp_v1_3 + 4) |= 2;
                        }
                    } else {
                        temp_a1_3 = *(void **)((u8 *)var_a0 + 0x50);
                        temp_v1_4 = *(s32 *)((u8 *)temp_a1_3 + 4);
                        if (temp_v1_4 & 2) var_a3 = 2;
                        *(s32 *)((u8 *)temp_a1_3 + 4) = temp_v1_4 & ~2;
                    }
                }
            }
            if (*((u8 *)temp_t0 + 3) & 0x10)
                *(s32 *)((u8 *)*(void **)((u8 *)var_a0 + 0x7C) + 0x2C) = 0xFF;
            else
                *(s32 *)((u8 *)*(void **)((u8 *)var_a0 + 0x7C) + 0x2C) = 0;
            temp_a1_4 = *(void **)((u8 *)var_a0 + 0x50);
            if (((var_a3 != *(s32 *)temp_a1_4) & (var_a3 >= 3)) && (*(s32 *)*(void **)((u8 *)var_a0 + 0x4C) == 2))
                *(s32 *)((u8 *)temp_a1_4 + 8) = 0xA;
            *(s32 *)*(void **)((u8 *)var_a0 + 0x50) = var_a3;
            temp_v1_5 = *(void **)((u8 *)var_a0 + 0x50);
            temp_v0_4 = *(s32 *)((u8 *)temp_v1_5 + 8);
            if (temp_v0_4 != 0) *(s32 *)((u8 *)temp_v1_5 + 8) = temp_v0_4 - 1;
            var_a0 = *(void **)((u8 *)var_a0 + 4);
        } while (var_a0 != NULL);
    }
}