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

M2C_UNK func_8000574C(s32, void **, void **);       /* extern */
M2C_UNK func_80005824(s32, f32, s32);               /* extern */
void **func_80005CB8(u16, u16, u16, M2C_UNK, s32);  /* extern */

void func_800421A4(void *arg0) {
    f32 temp_fv1;
    u16 temp_a1;
    void **temp_v0;
    void **temp_v0_2;
    void *temp_s1;

    temp_a1 = M2C_FIELD(arg0, u16 *, 0x186);
    if (temp_a1 != 0) {
        temp_v0 = func_80005CB8(M2C_FIELD(arg0, u16 *, 0x184), temp_a1, M2C_FIELD(arg0, u16 *, 0x188), 1, 6);
        temp_s1 = arg0 + 0x10;
        *temp_v0 = temp_s1;
        temp_v0_2 = func_80005CB8(M2C_FIELD(arg0, u16 *, 0x184), M2C_FIELD(arg0, u16 *, 0x186), M2C_FIELD(arg0, u16 *, 0x188), 1, 6);
        *temp_v0_2 = temp_s1;
        func_8000574C(M2C_FIELD(arg0, s32 *, 0x178), temp_v0, temp_v0_2);
        temp_fv1 = M2C_FIELD(arg0, f32 *, 0x18C);
        if (temp_fv1 != 0.0f) {
            func_80005824(M2C_FIELD(arg0, s32 *, 0x178), temp_fv1, M2C_FIELD(arg0, s32 *, 0x190));
        }
    }
}
