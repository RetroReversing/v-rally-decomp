#include "common.h"

extern u8 D_800C02AE[];

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Quad;

void func_8001B284(s16 *arg0, u8 *arg1, s32 arg2, u8 *arg3);

void func_800425F4(u8 *arg0) {
    s32 sp10[8];
    u8 *temp_a3;
    u8 *temp_v0;
    u8 *temp_a0;
    u8 *temp_v1;
    s32 var_t0;

    temp_a3 = *(u8 **)(arg0 + 0x24);
    if (temp_a3 != NULL) {
        if (*(u32 *)(arg0 + 0x20) & 0x880000) {
            temp_v1 = *(u8 **)(temp_a3 + 0x88);
            temp_a0 = *(u8 **)(D_800C02AE + 0x32F2);
            *(s32 *)(temp_v1 + 0x78) = 1;
            if (*(u16 *)(temp_a0 + 0x1E) == 7) {
                var_t0 = 0;
            } else {
                var_t0 = **(s32 **)(temp_a3 + 0x48);
            }
            if (*(u16 *)(*(u8 **)(D_800C02AE + 0x7CD6) + 0x20) & 0x40) {
                func_8001B284((s16 *)(*(u8 **)(temp_a3 + 0x5C) + 0x40), arg0 + 0x38, var_t0, temp_a3);
                return;
            }
            temp_v0 = *(u8 **)(temp_a3 + 0x5C);
            *(Quad *)&sp10[0] = *(Quad *)(temp_v0 + 0x40);
            *(Quad *)&sp10[4] = *(Quad *)(temp_v0 + 0x50);
            *(s16 *)((u8 *)sp10 + 0x0) = -*(u16 *)(*(u8 **)(temp_a3 + 0x5C) + 0x40);
            *(s16 *)((u8 *)sp10 + 0x6) = -*(u16 *)(*(u8 **)(temp_a3 + 0x5C) + 0x46);
            *(s16 *)((u8 *)sp10 + 0xC) = -*(u16 *)(*(u8 **)(temp_a3 + 0x5C) + 0x4C);
            *(s16 *)((u8 *)sp10 + 0x4) = -*(u16 *)(*(u8 **)(temp_a3 + 0x5C) + 0x44);
            *(s16 *)((u8 *)sp10 + 0xA) = -*(u16 *)(*(u8 **)(temp_a3 + 0x5C) + 0x4A);
            *(s16 *)((u8 *)sp10 + 0x10) = -*(u16 *)(*(u8 **)(temp_a3 + 0x5C) + 0x50);
            func_8001B284((s16 *)sp10, arg0 + 0x38, var_t0, temp_a3);
            return;
        }
        *(s32 *)(*(u8 **)(temp_a3 + 0x88) + 0x78) = 0;
    }
}
