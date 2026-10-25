#include "common.h"

s32 func_80034FF0();
void *func_80040260();
extern char D_800C02AE[];
extern s32 func_8003FC80;

void func_8003FB48(s32 arg0, s32 arg1)
{
    u8 *obj;
    u8 *temp_v0;
    u32 i;
    s32 y;
    s32 x;
    void *temp_s0;
    s32 new_var;
    u32 off;

    obj = *(u8 **)(D_800C02AE + 0x32F2);
    off = obj[0x32] * 0x28;
    if (*(u8 *)(obj + off + 0x48) & 4) {
        if ((*(u16 *)(obj + 0x1E) != 0) & (*(u16 *)(obj + 0x1E) != 7)) {
            if (*(u16 *)(obj + 0xE) == 1) {
                temp_v0 = *(u8 **)(*(u8 **)(D_800C02AE + 0x7CD6) + 0x178);
                y = *(u16 *)(temp_v0 + 0xA) + 6;
                x = (*(u16 *)(temp_v0 + 0x8) + 0x36) << 16;
                for (i = 0; i < 4; i++) {
                    temp_s0 = func_80040260(arg0, x >> 16, (s16)(y + i * 11 - 2), 5, &func_8003FC80, 1);
                    new_var = func_80034FF0(arg1 + 0x4C, 0);
                    *(s32 *)((u8 *)temp_s0 + 0xA4) = new_var;
                    *(u16 *)((u8 *)temp_s0 + 0x78) = i + 1;
                }
            }
        }
    }
}
