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



s32 func_80027CB4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;

    var_v0 = arg3 & 0xFF;
    var_a2 = arg2 & 0xFF;
    var_a2 <<= 8;
    var_v0 += var_a2;
    var_a1 = arg1 & 0xFF;
    var_a1 <<= 0x10;
    var_v0 += var_a1;
    var_a0 = arg0 << 0x18;
    var_v0 += var_a0;
    return var_v0;
}
