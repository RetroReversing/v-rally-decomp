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

M2C_UNK func_80049450();                            /* extern */
M2C_UNK func_800857A0(M2C_UNK);                     /* extern */
extern s32 D_8009D538;
extern void *D_800A0384;

s32 func_80049D50(void) {
    func_800857A0(0);
    func_800857A0(1);
    func_800857A0(2);
    func_800857A0(3);
    M2C_FIELD(D_800A0384, s8 *, 0x384) = 0;
    if (D_8009D538 & 0x4000) {
        func_80049450();
    }
    return 1;
}
