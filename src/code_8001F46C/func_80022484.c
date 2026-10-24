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

void func_80022484(void **arg0) {
    void *var_s0;

    if (arg0 != NULL) {
        var_s0 = *arg0;
        if (var_s0 != NULL) {
            do {
                M2C_FIELD(var_s0, M2C_UNK (**)(s32), 0x18)(M2C_FIELD(var_s0, s32 *, 0x10));
                var_s0 = M2C_FIELD(var_s0, void **, 4);
            } while (var_s0 != NULL);
        }
    }
}
