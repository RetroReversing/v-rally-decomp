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





s32 func_8004C2B8();

void func_8004C1B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8) {
    s32 sp1C;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s5;
    s32 temp_s6;
    u16 temp_fp;
    u16 temp_s2;

    temp_a1 = arg1 & 0xFFFF;
    sp1C = temp_a1;
    temp_fp = arg2 & 0xFFFF;
    temp_s2 = arg3 & 0xFFFF;
    func_8004C2B8(arg0, temp_a1, temp_fp, temp_s2, (s32) arg4, 0xB4);
    temp_s0 = arg5 & 0xFFFF;
    temp_s1 = arg6 & 0xFFFF;
    func_8004C2B8(arg0, temp_s2, arg4, temp_s0, temp_s1, 0xB4);
    temp_s5 = arg7 & 0xFFFF;
    temp_s6 = arg8 & 0xFFFF;
    func_8004C2B8(arg0, (u16) temp_s0, (u16) temp_s1, temp_s5, temp_s6, 0xB4);
    func_8004C2B8(arg0, (u16) temp_s5, (u16) temp_s6, sp1C, (s32) temp_fp, 0xB4);
    return;
}
