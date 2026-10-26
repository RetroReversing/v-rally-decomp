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
extern void *D_800A1468;
extern s32 D_800C35A0;

void func_80067034(void) {
    s32 temp_s0;

    temp_s0 = M2C_FIELD(D_800A1468, u8 *, 0x22A) * 0x28;
    func_800592F4(0x1C, M2C_FIELD((D_800C35A0 + temp_s0), u8 *, 0x48) & 1);
    func_800592F4(0x1D, ((u8) M2C_FIELD((D_800C35A0 + temp_s0), u8 *, 0x48) >> 1) & 1);
    func_800592F4(0x1E, ((u8) M2C_FIELD((D_800C35A0 + temp_s0), u8 *, 0x48) >> 2) & 1);
    func_800592F4(0x1F, ((u8) M2C_FIELD((D_800C35A0 + temp_s0), u8 *, 0x48) >> 3) & 1);
}
