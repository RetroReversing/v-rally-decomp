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
extern M2C_UNK func_8007A29C;
extern M2C_UNK func_8007A9A8;
extern M2C_UNK func_8007AA94;

s32 func_8007A24C(void) {
    func_8005A388();
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_8007A29C;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_8007A9A8;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x290) = &func_8007AA94;
    M2C_FIELD(D_800A1468, s8 *, 0x228) = 0;
    return 0;
}
