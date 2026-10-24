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

void *func_8004240C(s32);                           /* extern */
M2C_UNK func_80042440(void *, s32);                 /* extern */
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;

void func_800422C8(void) {
    s32 temp_a1;
    s32 var_s1;
    s32 var_s2;
    u8 temp_s0;
    void *var_s0;

    var_s0 = *M2C_FIELD(&D_800AE850, void ***, 0x73F0);
    if (var_s0 != NULL) {
        var_s2 = 0;
        var_s1 = 1;
        do {
            if (*M2C_FIELD(var_s0, s32 **, 0x48) < 4) {
                var_s2 += 2;
                temp_a1 = var_s1;
                var_s1 += 2;
                func_80042440(var_s0, temp_a1);
                func_80042440(var_s0, var_s2);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 4);
        } while (var_s0 != NULL);
    }
    temp_s0 = M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0xF);
    M2C_FIELD(func_8004240C(0), s32 *, 0x24) = 0;
    M2C_FIELD(func_8004240C((temp_s0 * 2) | 1), s32 *, 0x24) = 0;
}
