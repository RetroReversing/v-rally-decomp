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

M2C_UNK func_80005B00(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8000DB14(s32, M2C_UNK);                /* extern */
s32 func_8007EAA0(M2C_UNK, M2C_UNK);                /* extern */
extern s32 D_8009B5A8;
extern s32 D_8009B9D8;

void func_8005BB14(void) {
    D_8009B9D8 = func_8007EAA0(3, 0x54C70);
    func_80005B00(0, 0x2217);
    func_8000DB14(D_8009B5A8, 0);
}
