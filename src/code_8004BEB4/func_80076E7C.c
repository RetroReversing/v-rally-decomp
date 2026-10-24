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

s32 func_80022318(s32, M2C_UNK *);                  /* extern */
s32 func_800223B4(s32, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_80073640(s32);                         /* extern */
s32 func_800801D0(s32, M2C_UNK);                    /* extern */
s32 func_80084BF0(M2C_UNK);                         /* extern */
M2C_UNK func_80085778(M2C_UNK, s32);                /* extern */
extern s32 D_800A1740;
extern void *D_800A1B70;
extern M2C_UNK D_800A5E2C;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;
extern M2C_UNK func_80076D94;
extern M2C_UNK func_80076F64;

void func_80076E7C(s32 arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x28;
    if (func_80022318(temp_s0, &D_800A5E2C) == 0) {
        func_80085778(0, func_80084BF0(0));
        D_800A1740 = 0;
        M2C_FIELD(D_800A1B70, s16 *, 0x1C) = 0;
        func_80073640(func_800801D0(func_800223B4(temp_s0, &func_80076D94, &func_80076F64, &D_800A5E2C, 0), 0x4C));
        if ((M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x1E) == 0) && (M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x1A) != 0)) {
            M2C_FIELD(&D_800AE850, u16 *, 0x2410) = (u16) (M2C_FIELD(&D_800AE850, u16 *, 0x2410) | 0x800);
            M2C_FIELD(&D_800AE850, u16 *, 0x2454) = (u16) (M2C_FIELD(&D_800AE850, u16 *, 0x2454) | 0x800);
        }
    }
}
