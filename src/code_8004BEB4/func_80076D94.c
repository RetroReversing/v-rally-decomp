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

M2C_UNK func_80076060(s32);                         /* extern */
s32 func_80084BF0(s32);                             /* extern */
M2C_UNK func_80085778(u8, s32);                     /* extern */
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;

void func_80076D94(s32 *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    u16 temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;
    void *var_s1;

    func_80076060(*arg0);
    var_s1 = *M2C_FIELD(&D_800AE850, void ***, 0x73F0);
    if (var_s1 != NULL) {
        do {
            temp_a0 = M2C_FIELD(M2C_FIELD(var_s1, void **, 0x48), s32 *, 0);
            if (temp_a0 < 4) {
                temp_v0 = func_80084BF0(temp_a0 & 0xFF);
                func_80085778(M2C_FIELD(M2C_FIELD(var_s1, void **, 0x48), u8 *, 3), temp_v0);
                if ((temp_v0 & 8) && ((temp_v0_2 = M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x1E), (((temp_v0_2 == 0) | (temp_v0_2 >= 5U)) != 0)) || (M2C_FIELD(&D_800AE850, s32 *, 0x8030) != 2))) {
                    temp_v1 = M2C_FIELD(var_s1, void **, 0x9C);
                    M2C_FIELD(temp_v1, s32 *, 0x34) = (s32) (M2C_FIELD(temp_v1, s32 *, 0x34) + 1);
                }
                temp_v1_2 = M2C_FIELD(var_s1, void **, 0x9C);
                if (M2C_FIELD(temp_v1_2, s32 *, 0x34) >= 6) {
                    M2C_FIELD(temp_v1_2, s32 *, 0x34) = 0;
                }
            }
            var_s1 = M2C_FIELD(var_s1, void **, 4);
        } while (var_s1 != NULL);
    }
}
