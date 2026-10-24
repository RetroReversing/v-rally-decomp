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

extern M2C_UNK (*D_8009BBB8)();
extern void *D_800A0384;
extern M2C_UNK D_800C02AE;

void func_80015E4C(void) {
    D_8009BBB8();
    if ((D_800A0384 != NULL) && (M2C_FIELD(D_800A0384, u8 *, 0x384) == 0)) {
        M2C_FIELD(&D_800C02AE, s16 *, 0x5A4A) = 0;
    }
}
