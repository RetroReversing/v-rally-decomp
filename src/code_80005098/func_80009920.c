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



void func_80009920(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    void *var_v0;
    void *var_v1;

    var_v1 = *(void * *)((char *)arg0 + 0x14);
    var_a1 = arg1 & 0x1F;
    var_a1 <<= 0x11;
    var_a2 = arg2 & 0x1F;
    var_a2 <<= 9;
    var_a1 |= var_a2;
    var_a3 = arg3 & 0x1F;
    var_a3 *= 2;
    var_a1 |= var_a3;
    var_v0 = (void *)0x05000000;
    var_a1 |= 0x05000000;
    *(s32 *)((char *)var_v1 + 0) = var_a1;
    *(s32 *)((char *)var_v1 + 4) = 0;
    var_v0 = *(void * *)((char *)arg0 + 0x14);
    var_v1 = var_v0 + 8;
    *(void * *)((char *)arg0 + 0x14) = var_v1;
}
