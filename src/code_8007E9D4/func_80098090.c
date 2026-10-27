#include "checkpoint_common.h"

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

extern s32 D_800ADEE0;

s32 func_80098090(void) {
    s32 temp_lo;

    temp_lo = D_800ADEE0 * 0x41C64E6D;
    D_800ADEE0 = temp_lo + 0x3039;
    return ((s32) (temp_lo + 0x303A) >> 0x10) & 0x7FFF;
}
