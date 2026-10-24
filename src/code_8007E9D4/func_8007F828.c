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



void func_8007F828(void *arg0, s32 arg1) {
    s32 var_v0;
    void *var_a1;

    var_a1 = arg0 + arg1;
    var_a1 -= 0x14;
    var_v0 = 1;
    *(void * *)((char *)arg0 + 0) = var_a1;
    *(s32 *)((char *)arg0 + 4) = 0;
    *(s8 *)((char *)arg0 + 8) = 1;
    *(s8 *)((char *)arg0 + 0xA) = 0;
    *(s8 *)((char *)arg0 + 0xB) = 0;
    *(s32 *)((char *)arg0 + 0x10) = 0;
    *(s32 *)((char *)var_a1 + 0) = 0;
    *(void * *)((char *)var_a1 + 4) = arg0;
    *(s8 *)((char *)var_a1 + 8) = 1;
    *(s8 *)((char *)var_a1 + 0xA) = 1;
    *(s8 *)((char *)var_a1 + 0xB) = 0;
}
