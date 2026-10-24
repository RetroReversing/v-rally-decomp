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

M2C_UNK func_80091E24(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80094580(s32, M2C_UNK, s32);           /* extern */
M2C_UNK func_80094F90(s32, M2C_UNK, s32);           /* extern */

s32 func_80095AD0(void *arg0, s16 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_a2;
    s32 temp_s0;

    temp_s0 = arg1 * 0x4C;
    func_80091E24(M2C_FIELD(arg0, s32 *, 0x34) + temp_s0 + 0x20, arg2, arg3);
    temp_a2 = M2C_FIELD(arg0, s32 *, 0x34) + temp_s0;
    func_80094F90(temp_a2 + 0x20, 1, temp_a2);
    func_80094580(M2C_FIELD(arg0, s32 *, 0x30), 2, M2C_FIELD(arg0, s32 *, 0x34) + temp_s0 + 0x20);
    return M2C_FIELD(arg0, s32 *, 0x34) + temp_s0 + 0x20;
}
