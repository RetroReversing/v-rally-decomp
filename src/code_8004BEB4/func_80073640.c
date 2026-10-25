#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_8000BF2C();
s32 func_8000C1EC();
void func_8000C200(s32, f32, f32, f32);
s32 func_8000C22C();

void func_80073640(char *arg0) {
    s32 temp;
    s32 y;
    u32 i;

    *(s32 *)(arg0 + 0x44) = *(s32 *)(D_800C02AE + 0x103BA);
    *(s32 *)(arg0 + 0x40) = func_8000BF2C(*(s32 *)(D_800C02AE + 0x103BA));
    func_8000C200(*(s32 *)(arg0 + 0x40), 1.0f, 1.0f, 1.0f);
    func_8000C22C(*(s32 *)(arg0 + 0x40), 0xFF, 0xFF, 0xFF, 0xFF);
    func_8000C1EC(*(s32 *)(arg0 + 0x40), 0x80, 0x30);
    i = 0;
    y = -0x140;
    temp = 0x20;
    do {
        *(s16 *)(arg0 + 0xC + i * 2) = temp;
        temp += 8;
        *(s16 *)(arg0 + 0x24 + i * 2) = y;
        i++;
    } while (i < 0xC);
    if (*(s32 *)(D_800AE850 + 0x8030) != 1) {
        *(s32 *)(arg0 + 0x3C) = 0;
    } else {
        *(s32 *)(arg0 + 0x3C) = *(s32 *)(D_800AE850 + 0x8030);
    }
    *(s32 *)(arg0 + 0x48) = 1;
}
