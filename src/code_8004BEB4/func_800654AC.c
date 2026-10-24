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

M2C_UNK func_8005A360(s32, M2C_UNK);                /* extern */
M2C_UNK func_8005C198();                            /* extern */
M2C_UNK func_8007EE9C(s32);                         /* extern */
extern void *D_800A1468;
extern s32 D_800A14D0;
extern M2C_UNK func_80064E48;
extern M2C_UNK func_80064E50;

s32 func_800654AC(s32 arg0, M2C_UNK arg1) {
    func_8005C198();
    if (D_800A14D0 != 0) {
        func_8007EE9C(D_800A14D0);
        D_800A14D0 = 0;
    }
    func_8005A360(arg0, arg1);
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80064E48;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80064E50;
    return 1;
}
