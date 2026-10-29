#include "snapshot29_0433f7af8f6d.h"

/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
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

M2C_UNK func_8002FA10(void *);                      /* extern */
void *func_8007EAA0(M2C_UNK, s32);                  /* extern */
extern M2C_UNK D_800C02AE;

void func_80020694(void *arg0, void *arg1) {
    s32 temp_v0_2;
    s32 var_s0;
    u16 temp_v1;
    u32 var_s0_2;
    u32 var_s1;
    void *temp_v0;

    temp_v0 = func_8007EAA0(1, 0x54);
    M2C_FIELD(M2C_FIELD(arg1, void **, 0x38), void **, 0) = temp_v0;
    var_s0 = 0;
    if ((u16) M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0xE) < 3U) {
        do {
            M2C_FIELD((((var_s0 & 0xFF) * 4) + temp_v0), void **, 0x38) = func_8007EAA0(1, 0xE);
            var_s0 += 1;
        } while ((u32) (var_s0 & 0xFF) < 7U);
        var_s0_2 = M2C_FIELD(arg0, u32 *, 0x90);
        if ((u8) (M2C_FIELD(&D_800C02AE, u8 *, 0x7678) - 1) < 2U) {
            var_s0_2 = var_s0_2 >> 1;
        } else if ((M2C_FIELD(&D_800C02AE, u8 *, 0x7678) & 0xFF) == 3) {
            var_s0_2 = var_s0_2 >> 2;
        }
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x38), s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xDC);
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x38), s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x128);
        var_s1 = M2C_FIELD(arg0, u32 *, 0x174);
        if (((u32) (M2C_FIELD(&D_800C02AE, u8 *, 0x7678) - 1) < 2U) || (temp_v1 = M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x1E), (temp_v1 == 5)) || ((temp_v1 != 0) & (temp_v1 < 5U))) {
            var_s1 = var_s1 >> 1;
        }
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C0); M2C_FIELD(temp_v0, s16 *, 4) = (s16) (temp_v0_2 * temp_v0_2);
        M2C_FIELD(temp_v0, void **, 0) = func_8007EAA0(1, var_s0_2 * 0x24);
        M2C_FIELD(temp_v0, s16 *, 0x14) = (s16) var_s0_2;
        M2C_FIELD(temp_v0, void **, 0x10) = func_8007EAA0(1, var_s1 * 0x24);
        M2C_FIELD(temp_v0, s16 *, 0x16) = (s16) var_s1;
        func_8002FA10(temp_v0);
    }
}
