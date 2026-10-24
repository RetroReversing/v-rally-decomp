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

M2C_UNK func_8005A388();                            /* extern */
extern void *D_800A1468;
extern s8 D_800A16D4;
extern M2C_UNK func_800724A4;
extern M2C_UNK func_80072984;

s32 func_80072458(void) {
    func_8005A388();
    D_800A16D4 = 3;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_800724A4;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80072984;
    return 0;
}
