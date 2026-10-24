#include "common.h"

/* identical to func_8004C0C4 (matched), with its names changed by decompdecomp */
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

extern u8 D_800A03DB;

void func_8004C088(void *arg0) {
    s32 temp_v1;

    if ((u8) D_800A03DB >= 2U) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xC);
        if (!(temp_v1 & 6)) {
            M2C_FIELD(arg0, s32 *, 0xC) = (s32) (temp_v1 | 2);
        }
    } else {
        D_800A03DB += 1;
    }
}
