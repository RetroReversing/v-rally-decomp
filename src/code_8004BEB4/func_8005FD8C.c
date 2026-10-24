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

void *func_800592D0(M2C_UNK);                       /* extern */
M2C_UNK func_80059618(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800596F4(void *, s16, s16, M2C_UNK *); /* extern */
extern M2C_UNK D_800A550C;

void func_8005FD8C(void) {
    void *temp_v0;

    temp_v0 = func_800592D0(0);
    func_80059618(temp_v0, 0xFF, 0, 0, 0xFF);
    func_800596F4(temp_v0, M2C_FIELD(temp_v0, s16 *, 6), (s16) (M2C_FIELD(temp_v0, u16 *, 8) + 0x10), &D_800A550C);
}
