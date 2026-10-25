#include "common.h"

extern signed char D_800C3AC4;
extern signed char D_800C3AC5;
extern signed char D_800C3ACA;
extern signed char D_800C3ACB;
extern signed char D_800C3ACC;
extern s32 D_800C3AC0;
extern void *D_800C35A0;
s32 func_800535F4();
s32 func_80098290();
extern char D_800AE850[];

void func_80054E8C(void)
{
    s32 *var_s1;
    s32 var_s0;
    s32 var_a0;
    char *temp_a2;
    char *var_s3;
    char *temp_v0;

    temp_a2 = D_800C35A0;
    var_s3 = D_800AE850 + 0x7DB0;
    if (*((u16 *) (temp_a2 + 0xE)) != 0)
    {
        var_s1 = &D_800C3AC0;
        var_s0 = 0;
        do
        {
            var_a0 = var_s0 & 0xFF;
            *var_s1 = *((s32 *) (var_s3 + (var_a0 * 4) + 0x168));
            temp_v0 = temp_a2 + ((*((u8 *) (temp_a2 + var_a0 + 0x32))) * 0x28);
            D_800C3AC4 = *((u16 *) (temp_v0 + 0x4E));
            D_800C3AC5 = *((u16 *) (temp_a2 + 0x16));
            func_80098290((char *) var_s1 + 6, temp_a2 + ((*((u8 *) (temp_a2 + var_a0 + 0x32))) * 0x28 + 0x44), temp_a2);
            D_800C3ACA = 0;
            D_800C3ACB = 0;
            D_800C3ACC = 1;
            func_800535F4((char *) var_s1 - 0x30);
            var_s0++;
            temp_a2 = D_800C35A0;
        }
        while ((u32)(var_s0 & 0xFF) < *((u16 *) (temp_a2 + 0xE)));
    }
}
