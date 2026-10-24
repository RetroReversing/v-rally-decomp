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

extern M2C_UNK D_800A73E0;

void func_8003CB8C(void *arg0) {
    s32 temp_v0;
    u32 temp_v1;
    void *temp_a2;

    temp_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), void **, 0x24);
    if (temp_a2 != NULL) {
        temp_v1 = *M2C_FIELD(temp_a2, s32 **, 0x70) + 1;
        if (((u8) M2C_FIELD(&D_800A73E0, u8 *, 0x6C00) >= temp_v1) && (temp_v1 != M2C_FIELD(&D_800A73E0, u8 *, 0x6C00))) {
            M2C_FIELD(arg0, s32 *, 0x80) = (s32) (M2C_FIELD(arg0, s32 *, 0x80) & ~4);
            temp_v0 = *M2C_FIELD(temp_a2, s32 **, 0x70);
            M2C_FIELD(arg0, s16 *, 0x7A) = (s16) temp_v0;
            if ((s16) temp_v0 >= 0xA) {
                M2C_FIELD(arg0, s16 *, 0x7A) = 0;
                return;
            }
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x80) = (s32) (M2C_FIELD(arg0, s32 *, 0x80) | 4);
    }
}
