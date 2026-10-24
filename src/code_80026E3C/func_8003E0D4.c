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

void func_8003E0D4(void *arg0) {
    s16 var_v0;
    void *temp_v1;

    temp_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), void **, 0x24);
    if (temp_v1 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x7A) = (s16) M2C_FIELD(M2C_FIELD(temp_v1, void **, 0x6C), s32 *, 8);
        if (M2C_FIELD(M2C_FIELD(temp_v1, void **, 0x6C), s32 *, 8) == 1) {
            var_v0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), void **, 0x178), u16 *, 0xA) + 6;
        } else {
            var_v0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), void **, 0x178), u16 *, 0xA) + 0x10;
        }
        M2C_FIELD(arg0, s16 *, 0xE) = var_v0;
    }
}
