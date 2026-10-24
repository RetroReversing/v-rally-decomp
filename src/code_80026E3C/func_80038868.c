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



void func_80038868(void *arg0, void *arg1) {
    s32 temp_v1;

    temp_v1 = *(s32 *)((char *)arg0 + 0x90);
    if (temp_v1 != 0) {
        goto block_2;
    }
    M2C_FIELD(*(void * *)((char *)arg1 + 0x94), s32 *, 4) = 0;
    return;
block_2:
    if (temp_v1 == 1) {
        goto block_4;
    }
    if (temp_v1 != 2) {
        goto block_5;
    }
block_4:
    M2C_FIELD(*(void * *)((char *)arg1 + 0x94), s32 *, 4) = temp_v1;
block_5:
    return;
}
