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

void *func_80009FE4();                              /* extern */
M2C_UNK func_8000BA0C(void *);                      /* extern */
s32 coss(u16);                             /* extern */
s32 sins(u16);                             /* extern */

void func_8000B910(void *arg0, s32 arg1, s32 arg2) {
    s32 var_a0;
    s32 var_s2;
    u16 temp_s0;
    u16 temp_s3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    temp_v0 = func_80009FE4();
    M2C_FIELD(arg0, void **, 0x58) = temp_v0;
    func_8000BA0C(temp_v0);
    temp_s0 = M2C_FIELD(arg0, u16 *, 0x5C);
    temp_s3 = M2C_FIELD(arg0, u16 *, 0x5E);
    var_s2 = (s32) (coss(temp_s0) << 0x10) >> 0xF;
    var_a0 = (s32) (sins(temp_s0) << 0x10) >> 0xF;
    if (var_s2 == 0xFFFE) {
        var_s2 = 0x10000;
    }
    if (var_a0 == 0xFFFE) {
        var_a0 = 0x10000;
    }
    if (var_s2 == 0xFFFE) {
        var_s2 = -0x10000;
    }
    if (var_a0 == 0xFFFE) {
        var_a0 = -0x10000;
    }
    if (temp_s3 == 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0x10) = (s16) (arg1 * 4);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0x12) = (s16) (arg2 * 4);
    }
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x58);
    M2C_FIELD(temp_v0_2, s32 *, 0xC) = var_s2;
    M2C_FIELD(temp_v0_2, s32 *, 0) = var_s2;
    temp_v1 = M2C_FIELD(arg0, void **, 0x58);
    M2C_FIELD(temp_v1, s32 *, 8) = var_a0;
    M2C_FIELD(temp_v1, s32 *, 4) = (s32) -var_a0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), u16 *, 0x14) = (u16) M2C_FIELD(arg0, u16 *, 0x42);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), u16 *, 0x16) = (u16) M2C_FIELD(arg0, u16 *, 0x4A);
}
