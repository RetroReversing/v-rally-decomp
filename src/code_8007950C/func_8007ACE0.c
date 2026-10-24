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

M2C_UNK func_8005946C(s32, u8);                     /* extern */
M2C_UNK func_8007A688(u8);                          /* extern */
M2C_UNK func_8007A6D0();                            /* extern */
extern void *D_800A1468;

s32 func_8007ACE0(s32 arg0) {
    u8 temp_a0;

    temp_a0 = M2C_FIELD(D_800A1468, u8 *, 0x239);
    if ((s32) temp_a0 >= (M2C_FIELD((D_800A1468 + M2C_FIELD(D_800A1468, u8 *, 0x238)), u8 *, 0x23D) - 1)) {
        M2C_FIELD(D_800A1468, u8 *, 0x239) = 0U;
    } else {
        M2C_FIELD(D_800A1468, u8 *, 0x239) = (u8) (temp_a0 + 1);
    }
    M2C_FIELD(D_800A1468, s8 *, 0x2BD) = 1;
    func_8007A688(temp_a0);
    func_8007A6D0();
    func_8005946C(arg0, M2C_FIELD(D_800A1468, u8 *, 0x239));
    return 0;
}
