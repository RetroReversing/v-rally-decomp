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





extern int D_800B5C50;
extern int D_800AFB3C;


s32 func_80005E3C();
extern char D_800AE850[];

s32 func_80005DEC(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_800B5C50 != 0) {
        func_80005E3C(D_800B5C50);
        D_800B5C50 = 0;
        func_80005E3C(D_800AFB3C);
        var_v0 = 1;
        D_800AFB3C = 0;
    }
    return var_v0;
}
