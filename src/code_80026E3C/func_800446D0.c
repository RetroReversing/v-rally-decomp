#include "common.h"

extern s32 D_800B5B48;
extern char D_800AE850[];
extern char D_800A4E20[];
void func_80043F70();
void func_800447A0();
s32 func_8000BF2C();
s32 func_8000C1EC();
void func_8000C200(s32, f32, f32, f32);
void *func_80022318();
void *func_800223B4();
void *func_800801D0();

void func_800446D0(char *arg0) {
    char *s0;
    char *v0;
    s32 a0;

    s0 = arg0 + 0x28;
    v0 = func_80022318(s0, D_800A4E20);
    if (v0 != NULL) {
        goto block_5;
    }
    s0 = func_800801D0(func_800223B4(s0, func_80043F70, func_800447A0, D_800A4E20, 0), 0x18);
    goto block_6;
block_5:
    s0 = *(char **)(*(char **)(v0 + 0x10));
block_6:
    s0[0xE] = 1;
    s0[0xF] = 0;
    a0 = D_800B5B48;
    *(s16 *)(s0 + 0xC) = 0;
    *(s32 *)(s0 + 0x14) = a0;
    *(s32 *)(s0 + 0x10) = func_8000BF2C(a0);
    func_8000C200(*(s32 *)(s0 + 0x10), 1.0f, 1.0f, 1.0f);
    func_8000C1EC(*(s32 *)(s0 + 0x10), 0x80, 0x33);
}
