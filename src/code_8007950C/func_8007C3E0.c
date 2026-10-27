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

s32 func_8007C570(s32, s32);                        /* extern */
s32 func_80084BF0(M2C_UNK);                         /* extern */
s32 func_80084DD4(M2C_UNK);                         /* extern */
extern s32 D_8009D540;
extern s32 D_800A18D0;
extern M2C_UNK D_800C02AE;
extern u8 D_800C83C4[]; extern volatile u8 D_800C83C5;
extern u16 D_800C8240[];
extern void *D_800C35A0;

void func_8007C3E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_a0;
    u16 temp_v1;

    if (func_80084DD4(0) != 0) {
        temp_a0 = func_80084BF0(0);
        switch (D_800C83C4[0]) { /* irregular */
        case 0:
            func_8007C570(temp_a0, arg0);
            return;
        case 1:
            func_8007C570(temp_a0, arg1);
            return;
        case 2:
            func_8007C570(temp_a0, arg2);
            return;
        case 3:
            if (func_8007C570(temp_a0, arg3) != 0) {
                temp_v1 = M2C_FIELD(D_800C35A0, u16 *, 0x2C);
                if (temp_v1 & 0x8000) {
                    D_800C83C4[0] = 0U;
                    D_800A18D0 |= arg4;
                    D_800C83C5 = (s8) D_8009D540;
                    return;
                }
                M2C_FIELD(D_800C35A0, u16 *, 0x2C) = (u16) (temp_v1 | arg4);
                D_800C83C4[0] = 0U;
                D_800C8240[0] = (u16) (D_800C8240[0] | arg4);
                D_800C83C5 = (s8) D_8009D540;
                return;
            }
            break;
        default:
            D_800C83C4[0] = 0U;
            D_800C83C5 = (s8) D_8009D540;
            break;
        }
    }
}
