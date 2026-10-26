#include "common.h"

s32 func_8008BD90(s32 a0);
void func_8008BDB0(s32 a0);
extern u16 *D_800A3A34;

void osViBlack(s32 arg0) {
    s32 temp;
    u16 *p;

    temp = func_8008BD90(arg0);
    if (arg0 & 0xFF) {
        p = D_800A3A34;
        *p = *p | 0x20;
    } else {
        p = D_800A3A34;
        *p = *p & 0xFFDF;
    }
    func_8008BDB0(temp);
}
