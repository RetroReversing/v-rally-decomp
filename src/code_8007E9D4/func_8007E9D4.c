#include "common.h"

extern s32 D_800C02AE;
extern s32 D_800AE850;
extern s32 func_8000BF2C(s32);
extern void func_8000C200(s32, f32, f32, f32);
extern void func_8000C1EC(s32, s32, s32);
void func_8007E9D4(void) {
    s32 value;
    s32 handle;
    f32 one;

    value = *(s32 *)((s8 *)&D_800C02AE + 0x103BA);
    *(s32 *)((s8 *)&D_800AE850 + 0x1CFC) = value;
    handle = func_8000BF2C(value);
    one = 1.0f;
    *(s32 *)((s8 *)&D_800AE850 + 0x1D00) = handle;
    func_8000C200(handle, one, one, one);
    func_8000C1EC(*(s32 *)((s8 *)&D_800AE850 + 0x1D00), 0x80, 0x30);
    *(s16 *)((s8 *)&D_800AE850 + 0x1D04) = 0x2EE;
    *(s16 *)((s8 *)&D_800AE850 + 0x1D06) = 0;
    *((s8 *)&D_800C02AE + 0x8116) = 0;
    *((s8 *)&D_800C02AE + 0x8117) = 0x19;
}
