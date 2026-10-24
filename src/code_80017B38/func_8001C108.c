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



void func_8001C108(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    *arg4 = (*(f32 *)((char *)arg0 + 0) * arg1) + (*(f32 *)((char *)arg0 + 0x10) * arg2) + (*(f32 *)((char *)arg0 + 0x20) * arg3);
    *arg5 = (*(f32 *)((char *)arg0 + 4) * arg1) + (*(f32 *)((char *)arg0 + 0x14) * arg2) + (*(f32 *)((char *)arg0 + 0x24) * arg3);
    *arg6 = (*(f32 *)((char *)arg0 + 8) * arg1) + (*(f32 *)((char *)arg0 + 0x18) * arg2) + (*(f32 *)((char *)arg0 + 0x28) * arg3);
}
