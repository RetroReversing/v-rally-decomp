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

s32 func_8007F050(M2C_UNK);                         /* extern */
extern s32 D_8009B960;
extern s32 D_8009B964;
extern s32 D_8009B9D8;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;

void func_80069974(void) {
    D_8009B960 = func_8007F050(1);
    D_8009B964 = func_8007F050(2);
    M2C_FIELD(&D_800AE850, s32 *, 0x881C) = (s32) D_8009B9D8;
    D_8009B960 = func_8007F050(1);
    D_8009B964 = func_8007F050(2);
    M2C_FIELD(&D_800C02AE, s32 *, 0x5BA2) = -1;
}
