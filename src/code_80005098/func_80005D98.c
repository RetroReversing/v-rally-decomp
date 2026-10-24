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

M2C_UNK func_8007EBF4(s32, s32);                    /* extern */

void func_80005D98(void *arg0) {
    s32 temp_a0;
    s32 temp_s0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x10);
    temp_s0 = M2C_FIELD(arg0, u16 *, 0x7A) * 0x10;
    func_8007EBF4(temp_a0, ((s32) (M2C_FIELD(arg0, s32 *, 0x14) - temp_a0) >> 3) * 8);
    func_8007EBF4(M2C_FIELD(arg0, s32 *, 0x70), temp_s0);
}
