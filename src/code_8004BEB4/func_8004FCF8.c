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

M2C_UNK func_80022BE8(void *, s32);                 /* extern */
M2C_UNK func_800239CC(void *, void *);              /* extern */

void func_8004FCF8(s32 arg0, void *arg1, s32 arg2) {
    void *temp_s0;

    if (!(M2C_FIELD(arg1, s32 *, 0x14) & 0x80)) {
        temp_s0 = arg0 + ((arg2 & 0xFF) * 0x44);
        M2C_FIELD(temp_s0, s16 *, 0xC) = 0;
        func_80022BE8(arg1, M2C_FIELD(temp_s0, s32 *, 0));
        func_800239CC(arg1, temp_s0 + 0x1C);
    }
}
