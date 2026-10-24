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

s32 func_80034FF0(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80081540(M2C_UNK *);                   /* extern */
extern M2C_UNK D_800A48C0;
extern M2C_UNK D_800C02AE;

void func_8001F4B0(void *arg0) {
    func_80081540(&D_800A48C0);
    M2C_FIELD(&D_800C02AE, s32 *, 0x6C22) = func_80034FF0(arg0 + 0x4C, 0);
    M2C_FIELD(&D_800C02AE, s8 *, 0x6C27) = (s8) M2C_FIELD(arg0, s32 *, 0xDC);
    M2C_FIELD(&D_800C02AE, s8 *, 0x6C26) = (s8) M2C_FIELD(arg0, s32 *, 0x128);
    M2C_FIELD(&D_800C02AE, s8 *, 0x6C28) = (s8) M2C_FIELD(arg0, s32 *, 0x174);
}
