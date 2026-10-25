#include "common.h"

extern s8 D_800AE850[];
extern s8 D_800C02AE[];

void func_800903F0(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    s32 h;

    a = *(volatile s32 *)0xA4600014;
    b = *(volatile s32 *)0xA4600018;
    c = *(volatile s32 *)0xA460001C;
    d = *(volatile s32 *)0xA4600020;
    e = *(volatile s32 *)0xA4600024;
    f = *(volatile s32 *)0xA4600028;
    g = *(volatile s32 *)0xA460002C;
    h = *(volatile s32 *)0xA4600030;
    D_800C02AE[0x758B] = 0;
    D_800AE850[0x78A1] = 1;
    D_800C02AE[0x7587] = a;
    D_800C02AE[0x758A] = b;
    D_800C02AE[0x7588] = c;
    D_800C02AE[0x7589] = d;
    D_800AE850[0x789D] = e;
    D_800AE850[0x78A0] = f;
    D_800AE850[0x789E] = g;
    D_800AE850[0x789F] = h;
}
