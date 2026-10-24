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

M2C_UNK func_80005E3C(s32);                         /* extern */
M2C_UNK func_8007EE9C(void *);                      /* extern */

s32 func_80005838(void *arg0) {
    void *temp_a0;

    func_80005E3C(M2C_FIELD(arg0, s32 *, 0x20));
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    func_80005E3C(M2C_FIELD(arg0, s32 *, 0x24));
    temp_a0 = M2C_FIELD(arg0, void **, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    if (temp_a0 != NULL) {
        func_8007EE9C(temp_a0);
    }
    func_8007EE9C(arg0);
    return 1;
}
