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



s32 func_80098180();

void *func_8002255C(void *arg0, s32 arg1) {
    void *var_s0;

    var_s0 = arg0;
    if (*(s32 *)((char *)var_s0 + 0xC) == 0) {
        goto block_7;
    }
loop_2:
    if (func_80098180(arg1, var_s0) == 0) {
        goto block_4;
    }
    var_s0 += 0x14;
    goto block_6;
block_4:
    return var_s0;
block_6:
    if (*(s32 *)((char *)var_s0 + 0xC) != 0) {
        goto loop_2;
    }
block_7:
    return NULL;
}
