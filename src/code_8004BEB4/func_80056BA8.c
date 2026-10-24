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



void func_80056BA8(void *arg0, void **arg1, s16 *arg2) {
    s16 var_v0;
    u8 temp_v1;

    temp_v1 = *(u8 *)((char *)arg0 + 3);
    if (temp_v1 == 6) {
        goto block_3;
    }
    if (temp_v1 == 0xA) {
        goto block_4;
    }
    return;
block_3:
    *arg1 = arg0 + 0xC;
    var_v0 = 3;
    goto block_5;
block_4:
    *arg1 = arg0 + 0x10;
    var_v0 = 4;
block_5:
    *arg2 = var_v0;
    return;
}
