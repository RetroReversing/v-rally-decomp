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

M2C_UNK func_800592F4(M2C_UNK, s32);                /* extern */
void *func_8005A744(M2C_UNK, s32);                  /* extern */
M2C_UNK func_8008A0D8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern void *D_800A1468;
extern f32 D_800A14CC;
extern f64 D_800A5480;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;

void func_8005DC40(void) {
    M2C_FIELD(D_800A1468, s8 *, 0x245) = 1;
    func_800592F4(7, M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0xE) - 1);
    M2C_FIELD(D_800A1468, s8 *, 0x245) = 0;
    if (M2C_FIELD(D_800A1468, u8 *, 0x248) == 0) {
        func_8008A0D8(M2C_FIELD(&D_800C02AE, s32 *, 0x325A), 9, 0);
        M2C_FIELD(func_8005A744(5, M2C_FIELD(D_800A1468, s32 *, 0xC)), s8 *, 0x41) = 0;
    }
    M2C_FIELD(D_800A1468, s16 *, 0x220) = 0;
    D_800A14CC = (f32) ((f64) (M2C_FIELD(&D_800AE850, u8 *, 0x2544) + M2C_FIELD(&D_800AE850, u8 *, 0x2545) + M2C_FIELD(&D_800AE850, u8 *, 0x2546) + M2C_FIELD(&D_800AE850, u8 *, 0x2547) + M2C_FIELD(&D_800AE850, u8 *, 0x2548)) * D_800A5480);
}
