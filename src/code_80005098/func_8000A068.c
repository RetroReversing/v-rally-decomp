#include "common.h"

#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif



s32 func_80009FA0();
s32 func_8000BA0C();
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_8000A00C;

void func_8000A068(void) {
    s32 *temp_v1;
    s32 temp_v0;

    *(s32 *)(D_800C02AE + 0x32FA) = func_80009FA0(0x40);
    temp_v0 = func_80009FA0(0x40);
    *(s32 *)(D_800C02AE + 0x32FE) = temp_v0;
    *(s32 *)(D_800C02AE + 0x330A) = 0;
    *(s32 *)(D_800C02AE + 0x330E) = 0x40;
    *(s32 *)(D_800C02AE + 0x3306) = temp_v0;
    *(s32 *)(D_800C02AE + 0x3302) = (s32) *(s32 *)(D_800C02AE + 0x32FA);
    func_8000BA0C(D_800AE850 + 0x20, *(s32 *)(D_800C02AE + 0x32FA));
    temp_v1 = *(s32 * *)(D_800C02AE + 0x7DA6);
    *(s32 * *)(D_800C02AE + 0x7DA6) = &func_8000A00C;
    *(s32 * *)(D_800C02AE + 0x32E6) = temp_v1;
}
