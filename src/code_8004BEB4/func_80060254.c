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





s32 func_800592F4();
extern char D_800C02AE[];

s32 func_80060254(s32 arg0) {
    s32 var_a1;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x2C);
    if (temp_v1 & 0x800) {
        goto block_2;
    }
    goto block_4;
block_2:
    M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x2C) = (u16) (temp_v1 & 0xF7FF);
    var_a1 = 0;
    goto block_5;
block_4:
    M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x2C) = (u16) (temp_v1 | 0x800);
    var_a1 = 1;
block_5:
    func_800592F4(arg0, var_a1);
    return 0;
}
