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

s32 func_80027C64(s32);                             /* extern */

void func_8004F504(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 0);
    if (temp_a0 < 5) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x48), s32 *, 0x20) = (s32) (func_80027C64(temp_a0 & 0xFFFF) & 0xFFFF);
    }
}
