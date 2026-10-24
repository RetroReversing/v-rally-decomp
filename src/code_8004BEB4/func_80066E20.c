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

void *func_800592AC(M2C_UNK);                       /* extern */
M2C_UNK func_8005BB5C();                            /* extern */
M2C_UNK func_8005BC60();                            /* extern */
M2C_UNK func_8005C0E8(M2C_UNK, M2C_UNK, s32);       /* extern */
M2C_UNK func_8008A0D8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern void *D_800A1468;
extern M2C_UNK D_800C02AE;

void func_80066E20(void) {
    func_8005BC60();
    func_8005BB5C();
    if ((u16) M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0xE) < 2U) {
        func_8008A0D8(M2C_FIELD(&D_800C02AE, s32 *, 0x325A), 1, 0);
        M2C_FIELD(func_800592AC(1), s8 *, 0x41) = 0;
        func_8005C0E8(1, 1, M2C_FIELD(D_800A1468, s32 *, 0x14));
    }
    M2C_FIELD(D_800A1468, s8 *, 0x245) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x228) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x22B) = -1;
}
