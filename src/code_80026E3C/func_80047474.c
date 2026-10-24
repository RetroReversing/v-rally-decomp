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

M2C_UNK func_80097E30(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 D_8009C230;

void func_80047474(void) {
    s32 temp_s1;
    s32 var_s0;

    var_s0 = D_8009C230;
    temp_s1 = var_s0;
    do {
        func_80097E30(M2C_FIELD(var_s0, s32 *, 0x74), 0, 0x20);
        var_s0 = M2C_FIELD(var_s0, s32 *, 0x5C);
    } while ((var_s0 != temp_s1) & (var_s0 != 0));
}
