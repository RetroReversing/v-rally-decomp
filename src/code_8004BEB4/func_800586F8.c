#include "snapshot29_0433f7af8f6d.h"

typedef s32 M2C_UNK;
M2C_UNK *func_8007EAA0(M2C_UNK, M2C_UNK);
M2C_UNK func_80098290(M2C_UNK *, void *);
extern void *D_800A1468;
extern f64 D_800A5240;

void func_800586F8(void *arg0) {
    M2C_UNK *temp_s1;
    M2C_UNK *temp_v0;
    M2C_UNK *temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    s32 flag;
    void *temp_v1_2;
    void *list;

    temp_v0 = func_8007EAA0(1, 0x50);
    *(s16 *)((s8 *)temp_v0 + 0x4A) = (s16)*(s32 *)((s8 *)arg0 + 0x90);
    *(s16 *)((s8 *)temp_v0 + 8) = (s16)*(s32 *)((s8 *)arg0 + 0xDC);
    *(s16 *)((s8 *)temp_v0 + 0xA) = (s16)*(s32 *)((s8 *)arg0 + 0x128);
    *(s16 *)((s8 *)temp_v0 + 0xC) = (s16)*(s32 *)((s8 *)arg0 + 0x174);
    temp_s1 = (void *)((u8 *)temp_v0 + 4);
    *(u8 *)((s8 *)temp_v0 + 0xE) = (s8)*(s32 *)((s8 *)arg0 + 0x1C0);
    if (*(u8 *)((s8 *)arg0 + 0x210) != 0) {
        *(u8 *)((s8 *)temp_v0 + 0x30) = 0;
    } else {
        func_80098290((void *)((s32)temp_v0 + 0x30), (void *)((s8 *)arg0 + 0x1C8));
    }
    var_a0 = 0;
    do {
        temp_v1 = var_a0 & 0xFF;
        var_a0 += 1;
        flag = *(s32 *)((s8 *)arg0 + 0x2A4);
        temp_v1_2 = (u8 *)temp_v0 + temp_v1 * 2;
        *(u8 *)((s8 *)temp_v1_2 + 0x42) = 0;
        *(u8 *)((s8 *)temp_v1_2 + 0x41) = (s8)(flag == 1);
    } while ((u32)(var_a0 & 0xFF) < 4U);
    if (*(s32 *)((s8 *)arg0 + 0x44) >= 9) {
        *(u8 *)((s8 *)temp_s1 + 0xB) = (s8)*(s32 *)((s8 *)arg0 + 0x2F0);
        *(u8 *)((s8 *)temp_s1 + 0xC) = (s8)*(s32 *)((s8 *)arg0 + 0x33C);
        *(u8 *)((s8 *)temp_s1 + 0xD) = (s8)*(s32 *)((s8 *)arg0 + 0x388);
        if (*(s32 *)((s8 *)arg0 + 0x44) >= 12) {
            *(u8 *)((s8 *)temp_s1 + 0xE) = (s8)*(s32 *)((s8 *)arg0 + 0x3D4);
            if (*(s32 *)((s8 *)arg0 + 0x44) >= 13) {
                *(f32 *)((s8 *)temp_s1 + 0x10) = (f32)((f64)*(s32 *)((s8 *)arg0 + 0x46C) * D_800A5240);
                *(f32 *)((s8 *)temp_s1 + 0x14) = (f32)((f64)*(s32 *)((s8 *)arg0 + 0x4B8) * D_800A5240);
            } else {
                *(f32 *)((s8 *)temp_s1 + 0x10) = 1.0f;
                *(f32 *)((s8 *)temp_s1 + 0x14) = 1.0f;
            }
        } else {
            *(u8 *)((s8 *)temp_s1 + 0xE) = 0xff;
            *(f32 *)((s8 *)temp_s1 + 0x10) = 1.0f;
            *(f32 *)((s8 *)temp_s1 + 0x14) = 1.0f;
        }
    } else {
        *(u8 *)((s8 *)temp_s1 + 0xB) = 200;
        *(u8 *)((s8 *)temp_s1 + 0xC) = 200;
        *(u8 *)((s8 *)temp_s1 + 0xD) = 200;
        *(u8 *)((s8 *)temp_s1 + 0xE) = 0xff;
        *(f32 *)((s8 *)temp_s1 + 0x10) = 1.0f;
        *(f32 *)((s8 *)temp_s1 + 0x14) = 1.0f;
    }
    *(u8 *)((s8 *)temp_s1 + 0xE) = 0xcc;
    list = D_800A1468;
    *(s16 *)((s8 *)temp_s1 + 0x18) = 0;
    temp_v0_2 = *(M2C_UNK **)((s8 *)list + 0x10);
    if (temp_v0_2 != NULL) {
        *temp_v0_2 = (s32)temp_v0;
    } else {
        *(M2C_UNK **)((s8 *)list + 0xC) = temp_v0;
    }
    *(M2C_UNK **)((s8 *)D_800A1468 + 0x10) = temp_v0;
    *(M2C_UNK **)((s8 *)D_800A1468 + 0x1F0) = temp_v0;
    *(s32 *)((s8 *)D_800A1468 + 0x14) += 1;
    *(u8 *)((s8 *)temp_v0 + 0x4C) = 0;
    *(u8 *)((s8 *)temp_v0 + 0x4D) = 0;
    *(u8 *)((s8 *)temp_v0 + 0x4E) = 0;
    *(s32 *)((s8 *)temp_v0 + 0x28) = 0;
    *(s32 *)((s8 *)temp_v0 + 0x2C) = 0;
}
