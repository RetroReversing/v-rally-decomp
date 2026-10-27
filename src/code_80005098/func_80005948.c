#include "common.h"

/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
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

M2C_UNK func_8000DA84();                            /* extern */
M2C_UNK func_8000E2B0(s32);                         /* extern */
M2C_UNK osViBlack(M2C_UNK);                         /* extern */
extern s32 D_8009B5A4;
extern s32 D_8009B5A8;
extern s32 D_8009B5AC;
extern M2C_UNK D_800C02AE;

s32 func_80005948(void) {
    osViBlack(1);
    M2C_FIELD(&D_800C02AE, s8 *, 0x5BA6) = 4;
    func_8000DA84();
    if (D_8009B5A4 != 0) {
        func_8000E2B0(D_8009B5A4);
        D_8009B5A4 = 0;
    }
    if (D_8009B5A8 != 0) {
        func_8000E2B0(D_8009B5A8);
        D_8009B5A8 = 0;
    }
    if (D_8009B5AC != 0) {
        func_8000E2B0(D_8009B5AC);
        D_8009B5AC = 0;
    }
    return 1;
}
