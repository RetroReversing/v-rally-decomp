#include "snapshot29_0433f7af8f6d.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_800535F4();
s32 func_8006C640();
s32 func_8006F75C();
s32 func_80098290();
extern s32 D_8009D540;
extern char D_800AE850[];
extern char D_800C02AE[];
extern void *D_800C35A0;
extern char D_800C3780[];
extern char D_800C3750[];
extern char D_800C375C[];

void func_80052FA0(void) {
char *__repair_addr;

    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_s0;
    s32 temp_s0_3;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_s2;
    u16 temp_v0;
    u32 temp_v1_3;
    u32 temp_v1_4;
    void *temp_a2;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s3;
    void *temp_v1;

    temp_a2 = D_800C35A0; temp_s3 = D_800AE850 + 0x7DB0;
    var_s2 = 0;
    if (M2C_FIELD(temp_a2, u16 *, 0xE) != 0) {
        do {
            temp_v0 = M2C_FIELD(temp_a2, u16 *, 0x20);
            temp_a0 = var_s2 & 0xFF;
            temp_s0 = temp_a0 * 4;
            temp_s1 = (void *)((temp_v0 << 6) + (s32)D_800C3780);
            M2C_FIELD(temp_s1, s32 *, 0) = (s32)M2C_FIELD((void *)((temp_v0 * 0x10) + (s32)temp_s3 + temp_s0), s32 *, 0x58);
__repair_addr = (char *)(((M2C_FIELD((temp_a2 + temp_a0), u8 *, 0x32) * 0x28) + temp_a2));

            M2C_FIELD(temp_s1, s8 *, 4) = (s8)M2C_FIELD(__repair_addr, u16 *, 0x4E);
            M2C_FIELD(temp_s1, s8 *, 5) = (s8)M2C_FIELD(D_800C35A0, u16 *, 0x16);
            func_80098290((s32)temp_s1 + 6, (s32)(D_800C35A0 + ((M2C_FIELD((D_800C35A0 + temp_a0), u8 *, 0x32) * 0x28) + 0x44)));
            var_a2 = 0;
            var_a1 = 0;
            temp_s0_2 = (void *)(temp_s0 + (s32)temp_s3);

            temp_v1 = (void *)(*(s32 *)(D_800C02AE + 0x10386 + (M2C_FIELD(D_800C35A0, u16 *, 0x1E) * 4)) + (M2C_FIELD(D_800C35A0, u16 *, 0x20) * 0x2C4));
            temp_a0_2 = M2C_FIELD(temp_s0_2, s32 *, 0x118);
            if (temp_a0_2 != 0) {
                var_a2 = M2C_FIELD(temp_v1, s32 *, 0x22C);
                var_a1 = temp_a0_2;
            }
            temp_a0_3 = M2C_FIELD(temp_s0_2, s32 *, 0x128);
            if (temp_a0_3 != 0) {
                var_a1 += temp_a0_3;
                var_a2 += M2C_FIELD(temp_v1, s32 *, 0x230);
            }
            temp_s0_3 = M2C_FIELD(temp_s0_2, s32 *, 0x138);
            if (temp_s0_3 != 0) {
                var_a1 += temp_s0_3;
                var_a2 += M2C_FIELD(temp_v1, s32 *, 0x234);
            }
            { u32 result = (u32)(var_a2 * D_8009D540 * 0xE10) / (u32)(var_a1 * 0x3E8);
            M2C_FIELD(temp_s1, s8 *, 0xB) = 0;
            M2C_FIELD(temp_s1, s8 *, 0xC) = 1;
            M2C_FIELD(temp_s1, s8 *, 0xA) = result; }
            if (M2C_FIELD(D_800C35A0, u16 *, 0x2C) & 0x4000) {
                temp_v1_2 = M2C_FIELD(D_800C35A0, u16 *, 0x20) << 6;
                if (*(u8 *)(D_800C375C + temp_v1_2) != 0) {
                    temp_v1_3 = *(u32 *)(D_800C3750 + temp_v1_2);
                    if (temp_v1_3 >= 0x33U) {
                        M2C_FIELD(temp_s1, s32 *, 0) = (s32)(temp_v1_3 - 3);
                    }
                } else {
                    temp_v1_4 = *(u32 *)(D_800C3750 + temp_v1_2);
                    if (temp_v1_4 >= 0x33U) {
                        M2C_FIELD(temp_s1, s32 *, 0) = (s32)(temp_v1_4 - 0xA);
                    }
                }
            }
            func_800535F4((M2C_FIELD(D_800C35A0, u16 *, 0x20) << 6) + (s32)(D_800C3750));
            var_s2 += 1;
            temp_a2 = D_800C35A0;
        } while ((u32)(var_s2 & 0xFF) < (u16)M2C_FIELD(D_800C35A0, u16 *, 0xE));
    }
    func_8006C640();
    func_8006F75C();
}
