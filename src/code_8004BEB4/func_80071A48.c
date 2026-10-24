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

M2C_UNK func_800593FC(s32, M2C_UNK);                /* extern */
M2C_UNK func_8005946C(s32, u16);                    /* extern */
M2C_UNK func_8005A388(s32);                         /* extern */
M2C_UNK func_8005C198();                            /* extern */
M2C_UNK func_8007EE9C(s32);                         /* extern */
extern void *D_800A1468;
extern s32 D_800A14D0;
extern M2C_UNK D_800C02AE;
extern M2C_UNK func_80071B3C;
extern M2C_UNK func_80071E08;
extern M2C_UNK func_80072364;

s32 func_80071A48(s32 arg0) {
    M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), s16 *, 0x1E) = 5;
    M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x22) = 0U;
    if (!(M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x2C) & 0x200)) {
        if (M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x325A), s16 *, 2) == 3) {
            M2C_FIELD(D_800A1468, s8 *, 0x245) = 0;
            func_8005A388(arg0);
            M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80071B3C;
            M2C_FIELD(D_800A1468, M2C_UNK **, 0x290) = &func_80071E08;
            M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80072364;
            func_8005C198();
            if (D_800A14D0 != 0) {
                func_8007EE9C(D_800A14D0);
                D_800A14D0 = 0;
                return 0;
            }
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 0;
        }
        goto block_5;
    }
block_5:
    M2C_FIELD(D_800A1468, s8 *, 0x245) = 1;
    func_800593FC(arg0, 0x21);
    func_8005946C(arg0, M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x22));
    return 0;
}
