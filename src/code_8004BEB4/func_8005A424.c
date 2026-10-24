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

extern void *D_800A1468;

s32 func_8005A424(void) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(D_800A1468, u8 *, 0x22F);
    if (temp_v0 != 0) {
        M2C_FIELD(D_800A1468, u8 *, 0x22F) = (u8) (temp_v0 - 1);
    }
    return 0;
}
