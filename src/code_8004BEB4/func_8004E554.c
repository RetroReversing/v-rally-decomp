#include "common.h"

/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

void func_8004E554(void *arg0) {
    s32 temp_a1;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16 *, 2);
    temp_a2 = temp_v1 - 1;
    temp_a1 = temp_v1 & 0xFFFF;
    if ((u32) (temp_a2 & 0xFFFF) < 2U) {
        if (temp_a1 == 1) {
            M2C_FIELD(arg0, u16 *, 2) = (u16) (temp_v1 + 1);
        } else if (temp_a1 == 2) {
            M2C_FIELD(arg0, u16 *, 2) = temp_a2;
        }
        temp_a1_2 = M2C_FIELD(arg0, u16 *, 6);
        if ((temp_a1_2 & 0xFFFF) != 2) {
            M2C_FIELD(arg0, u16 *, 6) = (u16) (1 - temp_a1_2);
        }
    }
}
