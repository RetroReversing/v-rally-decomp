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



s32 func_80008B28();

void func_80008D70(void *arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_a3;

    temp_a2 = (*(u16 *)((char *)arg0 + 0x8A) * 2) & 0xFFFF;
    temp_a3 = (*(u16 *)((char *)arg0 + 0x88) * 2) & 0xFFFF;
    func_80008B28(arg0, arg1 & 0xFFFF, temp_a2, temp_a3, temp_a2, 0, 0, 0, 0, temp_a3);
}
