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

void *func_80022318(s32, M2C_UNK *);                /* extern */
M2C_UNK func_800804C4(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_800A4F20;
extern M2C_UNK D_800A4F28;
extern M2C_UNK func_8004E094;

void func_8004E18C(s32 arg0) {
    s32 temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;

    temp_s0 = arg0 + 0x28;
    temp_v0 = func_80022318(temp_s0, &D_800A4F20);
    if (temp_v0 != NULL) {
        func_800804C4(M2C_FIELD(temp_v0, s32 *, 0x10), &func_8004E094);
    }
    temp_v0_2 = func_80022318(temp_s0, &D_800A4F28);
    if (temp_v0_2 != NULL) {
        temp_v0_3 = M2C_FIELD(temp_v0_2, void **, 0x10);
        temp_v1 = M2C_FIELD(temp_v0_3, void **, 0);
        M2C_FIELD(temp_v0_3, s32 *, 8) = 0;
        M2C_FIELD(temp_v1, s32 *, 0x30) = 1;
        M2C_FIELD(temp_v1, s32 *, 0x60) = 0;
        M2C_FIELD(temp_v1, s16 *, 0x6A) = 0x1000;
        M2C_FIELD(temp_v1, u16 *, 0x68) = (u16) (M2C_FIELD(temp_v1, u16 *, 0x68) | 1);
    }
}
