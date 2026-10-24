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

M2C_UNK func_80005810(void *, M2C_UNK);             /* extern */
M2C_UNK func_8000A2C4(void *, s16, s16, M2C_UNK);   /* extern */
void *func_80022668(s32, s32);                      /* extern */
M2C_UNK func_800475E4(void *, void *);              /* extern */
extern void *D_8009B5A4;
extern M2C_UNK D_800C02AE;

void func_80047B54(void *arg0, s32 arg1, s16 arg2, s16 arg3) {
    u16 temp_v1;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_v0;

    temp_s1 = M2C_FIELD(arg0, void **, 0x178);
    temp_v0 = func_80022668(M2C_FIELD(&D_800C02AE, s32 *, 0x7672), arg1 & 0xFFFF);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_s1, void **, 0x2C) = temp_v0;
        temp_s1_2 = *M2C_FIELD(M2C_FIELD(temp_v0, void **, 0xC), void ***, 4);
        temp_v1 = M2C_FIELD(temp_s1_2, u16 *, 6);
        if ((temp_v1 >= 0x200U) || (temp_v1 == M2C_FIELD(D_8009B5A4, s16 *, 4))) {
            func_80005810(M2C_FIELD(arg0, void **, 0x178), 5);
            func_8000A2C4(M2C_FIELD(arg0, void **, 0x178), arg2, arg3, 0);
            return;
        }
        func_80005810(M2C_FIELD(arg0, void **, 0x178), 0);
        func_800475E4(M2C_FIELD(arg0, void **, 0x178), temp_s1_2);
    }
}
