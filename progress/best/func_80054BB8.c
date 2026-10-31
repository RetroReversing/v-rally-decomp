#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern int D_800C3A80;
extern signed char D_800C3A84;
extern signed char D_800C3A85;
extern signed char D_800C3A8B;
extern signed char D_800C3A8C;
extern signed char D_800C3A8A;
extern s32 func_800535F4();
extern s32 func_8006CB9C();
extern s32 func_8006F75C();
extern s32 func_80098180(const u8 *, const u8 *);
extern s32 func_80098290();
extern char D_800C02AE[];

void func_80054BB8(void) {
int __repair_literal;

    s32 sp10[4];
    s32 sp30;
    s32 sp50[4];
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_fp;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    u8 *temp_a0_2;
    s32 *temp_s0_3;
    s32 *temp_s2;

    var_fp = 0;
    do {
        temp_a1 = var_fp & 0xFF;
        temp_v0 = temp_a1 * 4;
        func_80098290(&sp30, (void *)(*(char **)(D_800C02AE + 0x32F2) + ((temp_a1 * 0x28) + 0x44)));
        var_s5 = 0;
        sp10[temp_a1] = 0;
        sp50[temp_a1] = 0;
    loop_2:
        var_s4 = 0;
        var_s1 = 0;
        temp_s3 = (var_s5 & 0xFF) << 6;
        temp_s2 = &sp10[temp_a1];
        {
            s32 searching = 1;
            do {
                temp_a1_2 = (var_s1 & 0xFF) * 16;
                temp_s0 = temp_a1_2 + temp_s3;
                if (*(u8 *)(D_800C02AE + 0x33AE + temp_s0) != 1) {
                    var_s1++;
                } else if (func_80098180((u8 *)&sp30, (u8 *)(D_800C02AE + 0x33A2 + temp_s0 + 6)) == 0) {
                    *temp_s2 += *(s32 *)(D_800C02AE + 0x33A2 + temp_s0);
                    var_s4 = 1;
                    temp_s2[4] += *(u8 *)(D_800C02AE + 0x33AC + temp_s0);
                    searching = 0;
                } else {
                    var_s1++;
                }
            } while (searching & ((u32)(var_s1 & 0xFF) < 3U));
        }
        var_s5 += 1;
        temp_v1 = var_s4 & 0xFF;
        if (((u32)(var_s5 & 0xFF) < 4U) && temp_v1) {
            goto loop_2;
        }
        var_s2 = 1;
        if (temp_v1 != 0) {
            var_s1_2 = 0;
            do {
                temp_s0_2 = (var_s1_2 & 0xFF) * 0x10;
                var_s1_2 += 1;
                if (func_80098180((u8 *)&sp30, (u8 *)(D_800C02AE + 0x37A8 + temp_s0_2)) == 0) {
                    var_s2 &= -(*(s32 *)(D_800C02AE + 0x37A2 + temp_s0_2) != sp10[temp_a1]);
                }
            } while ((u32)(var_s1_2 & 0xFF) < 3U);
            temp_a0 = var_fp & 0xFF;
            if (var_s2 & 0xFF) {
                temp_s0_3 = &sp10[temp_a0];
                temp_a0_2 = (u8 *)(*(char **)(D_800C02AE + 0x32F2) + temp_a0);
                D_800C3A80 = *temp_s0_3;
                D_800C3A84 = (s8) * (u16 *)(*(char **)(D_800C02AE + 0x32F2) + (temp_a0_2[0x32] * 0x28) + 0x4E);
                D_800C3A85 = (s8) * (u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0x16);
                func_80098290((void *)(D_800C02AE + 0x37D2 + 6), (void *)(*(char **)(D_800C02AE + 0x32F2) + (temp_a0_2[0x32] * 0x28 + 0x44)));
                D_800C3A8B = 0;
                D_800C3A8C = 1;
                D_800C3A8A = (s8)((u32)temp_s0_3[4] / 18U);
                func_800535F4((s32)(D_800C02AE + 0x37D2 - 0x30));
            }
        }
        var_fp += 1;
    } while ((u32)(var_fp & 0xFF) < 4U);
    func_8006CB9C(&sp30);
    func_8006F75C();
}
