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



extern int D_800B65E8;


extern char D_800AE850[];

s32 func_8008949C(s32 arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;

    var_a2 = 0;
    do {
        temp_a1 = D_800B65E8 * 2;
        temp_v0 = D_800B65E8 & 0x48000000;
        temp_v1 = (temp_v0 == 0x48000000) | (temp_v0 == 0x08000000);
        D_800B65E8 = temp_a1;
        var_a2 += 1;
        if (temp_v1 != 0) {
            D_800B65E8 = (s32) (temp_a1 | 1);
        }
    } while (var_a2 < 8);
    return (s32) ((f32) arg0 * ((f32) D_800B65E8 * 0.000015258789f * 0.000015258789f));
}
