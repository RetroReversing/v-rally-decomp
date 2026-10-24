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



void func_8002D460(void *arg0, void *arg1, s32 arg2, s32 arg3, void *arg4) {
    *(s32 *)((char *)arg4 + 0) = (s32) ((*(s32 *)((char *)arg0 + 0) * arg2) + (*(s32 *)((char *)arg1 + 0) * arg3));
    *(s32 *)((char *)arg4 + 4) = (s32) ((*(s32 *)((char *)arg0 + 4) * arg2) + (*(s32 *)((char *)arg1 + 4) * arg3));
    *(s32 *)((char *)arg4 + 8) = (s32) ((*(s32 *)((char *)arg0 + 8) * arg2) + (*(s32 *)((char *)arg1 + 8) * arg3));
}
