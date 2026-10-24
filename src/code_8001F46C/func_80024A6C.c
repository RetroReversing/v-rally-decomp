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



s32 func_80024A6C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_a0;
    s32 var_a2;

    var_a2 = (s32) (-arg2 * arg4) >> 9;
    if (arg0 < var_a2) {
        goto block_2;
    }
    temp_a0 = -arg0;
    goto block_4;
block_2:
    var_a2 = arg0 - 0x46;
    goto block_6;
block_4:
    if (var_a2 >= temp_a0) {
        goto block_6;
    }
    var_a2 = temp_a0 + 0x46;
block_6:
    return (s32) (var_a2 * arg1) >> 0xA;
}
