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
extern M2C_UNK func_80068FE0;
extern M2C_UNK func_80069158;
extern M2C_UNK func_800693CC;

s32 func_80068F94(void) {
    func_8005A388();
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80068FE0;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80069158;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x290) = &func_800693CC;
    return 0;
}
