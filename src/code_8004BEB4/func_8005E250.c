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



s32 func_8005E470();
extern s8 D_800A13B2;
extern s8 D_800A14D5;
extern s8 D_800A1548;

s32 func_8005E250(void) {
    D_800A13B2 = 0;
    func_8005E470();
    D_800A14D5 = 0;
    D_800A1548 = 3;
    return 0;
}
