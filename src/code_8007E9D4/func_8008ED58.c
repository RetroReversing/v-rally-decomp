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

M2C_UNK func_800914E0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_800A6FE0;
extern M2C_UNK D_800A6FE4;

s32 __nextSampleTime(void *arg0, void **arg1) {
    s32 var_s1;
    void *var_a0;

    var_s1 = 0x7FFFFFFF;
    if (M2C_FIELD(arg0, void **, 0) == NULL) {
        func_800914E0(&D_800A6FE0, &D_800A6FE4, 0x133);
    }
    *arg1 = NULL;
    var_a0 = M2C_FIELD(arg0, void **, 0);
    if (var_a0 != NULL) {
        do {
            if ((M2C_FIELD(var_a0, s32 *, 0x10) - M2C_FIELD(arg0, s32 *, 0x20)) < var_s1) {
                *arg1 = var_a0;
                var_s1 = M2C_FIELD(var_a0, s32 *, 0x10) - M2C_FIELD(arg0, s32 *, 0x20);
            }
            var_a0 = M2C_FIELD(var_a0, void **, 0);
        } while (var_a0 != NULL);
    }
    return M2C_FIELD(*arg1, s32 *, 0x10);
}
