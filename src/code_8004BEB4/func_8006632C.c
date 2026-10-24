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

M2C_UNK func_8005C198();                            /* extern */
M2C_UNK func_8005E28C(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8005E470(s32, M2C_UNK);                /* extern */
extern s8 D_800A16D4;

s32 func_8006632C(s32 arg0, M2C_UNK arg1) {
    func_8005C198();
    func_8005E470(arg0, arg1);
    D_800A16D4 = 1;
    func_8005E28C(0, 0);
    return 1;
}
