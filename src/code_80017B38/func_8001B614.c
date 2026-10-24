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

extern int D_800C6F0C;
extern int D_800C35A0;


s32 func_8001B5AC();
s32 func_800801D0();
extern char D_800C02AE[];

s32 func_8001B614(void) {
    s32 temp_v0;

    temp_v0 = func_800801D0(D_800C6F0C, 0xF4);
    D_800C35A0 = temp_v0;
    func_8001B5AC(temp_v0);
    return D_800C35A0;
}
