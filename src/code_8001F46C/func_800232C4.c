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





s32 func_800231EC();
s32 func_80023228();

s32 func_800232C4(s32 arg0) {
    if (arg0 == 0) {
        goto block_9;
    }
    if (func_800231EC(arg0, 1) == 0) {
        goto block_8;
    }
    if (func_800231EC(arg0, 2) == 0) {
        goto block_7;
    }
    if (func_800231EC(arg0, 4) == 0) {
        goto block_6;
    }
    if (func_800231EC(arg0, 8) != 0) {
        goto block_10;
    }
    return func_80023228(arg0, 8, 3);
block_6:
    return func_80023228(arg0, 4, 2);
block_7:
    return func_80023228(arg0, 2, 1);
block_8:
    return func_80023228(arg0, 1, 0);
block_9:
block_10:
    return 0;
}
