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

M2C_UNK func_800237B0();                            /* extern */

void func_8002441C(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;

    func_800237B0();
    temp_v0 = M2C_FIELD(arg0, void **, 0x58);
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0;
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x58);
    M2C_FIELD(temp_v0_2, s32 *, 0x70) = 0;
    M2C_FIELD(temp_v0_2, s32 *, 0x74) = 0;
    M2C_FIELD(temp_v0_2, s32 *, 0x78) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xC) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x54);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0x10) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x58);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0x14) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x5C);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xE8) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x54) * 0x10);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xEC) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x58) * 0x10);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xF0) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x5C) * 0x10);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xC0) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x40) * 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xC4) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x46) * 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xC8) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x4C) * 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xD4) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x42) * 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xD8) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x48) * 4);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xDC) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x4E) * 4);
    temp_v0_3 = M2C_FIELD(arg0, void **, 0x2C);
    M2C_FIELD(temp_v0_3, s32 *, 0x20) = 0;
    M2C_FIELD(temp_v0_3, s32 *, 0x24) = 0;
    M2C_FIELD(temp_v0_3, s32 *, 0x28) = 0;
    temp_v0_4 = M2C_FIELD(arg0, void **, 0x2C);
    M2C_FIELD(temp_v0_4, s32 *, 0x34) = 0;
    M2C_FIELD(temp_v0_4, s32 *, 0x38) = 0;
    M2C_FIELD(temp_v0_4, s32 *, 0x3C) = 0;
    temp_v0_5 = M2C_FIELD(arg0, void **, 0x2C);
    M2C_FIELD(temp_v0_5, s32 *, 0x98) = 0;
    M2C_FIELD(temp_v0_5, s32 *, 0x9C) = 0;
    M2C_FIELD(temp_v0_5, s32 *, 0xA0) = 0;
    temp_v0_6 = M2C_FIELD(arg0, void **, 0x2C);
    M2C_FIELD(temp_v0_6, s32 *, 0xAC) = 0;
    M2C_FIELD(temp_v0_6, s32 *, 0xB0) = 0;
    M2C_FIELD(temp_v0_6, s32 *, 0xB4) = 0;
}
