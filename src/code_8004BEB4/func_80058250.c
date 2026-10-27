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

M2C_UNK *func_8007EAA0(M2C_UNK, M2C_UNK);           /* extern */
extern void *D_800A1468;
extern f64 D_800A5238;

void func_80058250(void *arg0) {
    M2C_UNK **temp_v1_4;
    M2C_UNK *temp_v0;
    M2C_UNK *temp_v0_4;
    s32 var_a0;
    s32 temp_v1;
    s8 temp_v1_3;
    u8 var_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_2;
    void *temp_v1_5;

    temp_v0 = func_8007EAA0(1, 0x24);
    M2C_FIELD(temp_v0, s16 *, 4) = (s16) M2C_FIELD(arg0, s32 *, 0x90);
    M2C_FIELD(temp_v0, s16 *, 6) = (s16) M2C_FIELD(arg0, s32 *, 0xDC);
    M2C_FIELD(temp_v0, s16 *, 8) = (s16) M2C_FIELD(arg0, s32 *, 0x128);
    var_a0 = 0;
    M2C_FIELD(temp_v0, s8 *, 0xA) = (s8) M2C_FIELD(arg0, s32 *, 0x174);
    do {
        temp_v1 = var_a0 & 0xFF;
        var_a0 += 1;
        temp_v1_2 = (u8 *)temp_v0 + (temp_v1 * 2);
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C0) == 1;
        M2C_FIELD(temp_v1_2, s8 *, 0x1B) = 0;
        M2C_FIELD(temp_v1_2, s8 *, 0x1A) = temp_v1;
    } while ((u32) (var_a0 & 0xFF) < 4U);
    if (M2C_FIELD(arg0, s32 *, 0x44) >= 6) {
        M2C_FIELD(temp_v0, u8 *, 0xB) = (u8) M2C_FIELD(arg0, s32 *, 0x20C);
        M2C_FIELD(temp_v0, u8 *, 0xC) = (u8) M2C_FIELD(arg0, s32 *, 0x258);
        M2C_FIELD(temp_v0, u8 *, 0xD) = (u8) M2C_FIELD(arg0, s32 *, 0x2A4);
        if (M2C_FIELD(arg0, s32 *, 0x44) >= 9) {
            M2C_FIELD(temp_v0, u8 *, 0xE) = (u8) M2C_FIELD(arg0, s32 *, 0x2F0);
            if (M2C_FIELD(arg0, s32 *, 0x44) >= 0xA) {
                temp_v1_3 = M2C_FIELD(arg0, s8 *, 0x2F8);
                if (temp_v1_3 == 0x53) {
                    M2C_FIELD(temp_v0, f32 *, 0x10) = (f32) ((f64) M2C_FIELD(arg0, s32 *, 0x388) * D_800A5238);
                    M2C_FIELD(temp_v0, f32 *, 0x14) = (f32) ((f64) M2C_FIELD(arg0, s32 *, 0x3D4) * D_800A5238);
                    if (M2C_FIELD(arg0, s32 *, 0x44) == 0xD) {
                        M2C_FIELD(temp_v0, s16 *, 0x18) = (s16) M2C_FIELD(arg0, s32 *, 0x420);
                        goto finished;
                    } else {
                        M2C_FIELD(temp_v0, s16 *, 0x18) = 0;
                        goto finished;
                    }
                } else if (temp_v1_3 == 0x52) {
                    M2C_FIELD(temp_v0, s16 *, 0x18) = (s16) M2C_FIELD(arg0, s32 *, 0x388);
                    M2C_FIELD(temp_v0, f32 *, 0x10) = 1.0f;
                    M2C_FIELD(temp_v0, f32 *, 0x14) = 1.0f;
                }
            } else {
                goto block_17;
            }
        } else {
            M2C_FIELD(temp_v0, s16 *, 0x18) = 0;
            M2C_FIELD(temp_v0, u8 *, 0xE) = 0xFFU;
            M2C_FIELD(temp_v0, f32 *, 0x10) = 1.0f;
            M2C_FIELD(temp_v0, f32 *, 0x14) = 1.0f;
        }
    } else {
        temp_v0_2 = M2C_FIELD(D_800A1468, void **, 0x1F0);
        if (temp_v0_2 == NULL) {
            M2C_FIELD(temp_v0, u8 *, 0xB) = 0xC8U;
            M2C_FIELD(temp_v0, u8 *, 0xC) = 0xC8U;
            M2C_FIELD(temp_v0, u8 *, 0xD) = 0xC8U;
            M2C_FIELD(temp_v0, u8 *, 0xE) = 0xFF;
            goto block_17;
        } else {
            M2C_FIELD(temp_v0, u8 *, 0xB) = (u8) M2C_FIELD(temp_v0_2, u8 *, 0xF);
            M2C_FIELD(temp_v0, u8 *, 0xC) = (u8) M2C_FIELD(M2C_FIELD(D_800A1468, void **, 0x1F0), u8 *, 0x10);
            M2C_FIELD(temp_v0, u8 *, 0xD) = (u8) M2C_FIELD(M2C_FIELD(D_800A1468, void **, 0x1F0), u8 *, 0x11);
            var_v0 = M2C_FIELD(M2C_FIELD(D_800A1468, void **, 0x1F0), u8 *, 0x12);
        }
        M2C_FIELD(temp_v0, u8 *, 0xE) = var_v0;
block_17:
        M2C_FIELD(temp_v0, s16 *, 0x18) = 0;
block_18:
        M2C_FIELD(temp_v0, f32 *, 0x10) = 1.0f;
        M2C_FIELD(temp_v0, f32 *, 0x14) = 1.0f;
    }
finished:
    temp_v0_3 = M2C_FIELD(D_800A1468, void **, 0x1F0);
    if (temp_v0_3 != NULL) {
        temp_v1_4 = M2C_FIELD(temp_v0_3, M2C_UNK ***, 0x2C);
        if (temp_v1_4 != NULL) {
            *temp_v1_4 = temp_v0;
        } else {
            M2C_FIELD(temp_v0_3, M2C_UNK **, 0x28) = temp_v0;
        }
        M2C_FIELD(M2C_FIELD(D_800A1468, void **, 0x1F0), M2C_UNK **, 0x2C) = temp_v0;
        temp_v1_5 = M2C_FIELD(D_800A1468, void **, 0x1F0);
        M2C_FIELD(temp_v1_5, u8 *, 0x4C) = (u8) (M2C_FIELD(temp_v1_5, u8 *, 0x4C) + 1);
        return;
    }
    temp_v0_4 = M2C_FIELD(D_800A1468, M2C_UNK **, 4);
    if (temp_v0_4 != NULL) {
        *(void **)temp_v0_4 = temp_v0;
    } else {
        M2C_FIELD(D_800A1468, M2C_UNK **, 0) = temp_v0;
    }
    M2C_FIELD(D_800A1468, M2C_UNK **, 4) = temp_v0;
    M2C_FIELD(D_800A1468, s32 *, 8) = (s32) (M2C_FIELD(D_800A1468, s32 *, 8) + 1);
}
