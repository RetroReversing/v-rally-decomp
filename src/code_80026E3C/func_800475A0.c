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

M2C_UNK func_8000A2C4(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_80022668(void *, s32);                     /* extern */
extern M2C_UNK D_800C02AE;

void func_800475A0(void) {
    if (func_80022668(M2C_FIELD(&D_800C02AE, void **, 0x7672), M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x7672), s32 *, 8)) != 0) {
        func_8000A2C4(M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x7CD6), s32 *, 0x178), 0, 0, 0);
    }
}
