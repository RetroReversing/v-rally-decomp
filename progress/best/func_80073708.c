s32 func_80041564(void);
s32 func_80045404(s32, s32, s32, void *, s32, s32);
s32 func_80098290(void *, void *, void *);
extern s32 D_8009D540;
extern char D_800A73E0[];
extern char D_800AE850[];
extern unsigned char D_800C02AE[];
extern unsigned char D_800ADFE0;
extern int D_800C7F94;
extern unsigned int D_800C7FDC;
extern unsigned int D_800C7FC4;
extern unsigned char D_800C7FE9;
extern int D_800C7FE4;
extern int D_800C7FE0;
extern int D_800C7FF4;
extern int D_800C7FFC;
extern unsigned char D_800C8002;

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

void func_80073708(void) {
int __repair_literal;

    s32 *temp_a0;
    s32 *temp_v1_3;
    s32 *temp_v1_7;
    char *var_a0;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s1;
    u8 *temp_s5;
    s32 temp_s6;
    s32 temp_v1;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_s2;
    s32 var_v0;
    s32 var_v1;
    s8 var_s4;
    u16 temp_v1_2;
    u16 temp_v1_6;
    void *temp_s7;
    void *temp_fp;
    void *var_s3;

    temp_s5 = func_80041564();
    temp_fp = D_800AE850 + 0x6DAC;
    var_s3 = **(void ***)(D_800AE850 + 0x73F0);
    var_s4 = 0;
    if (var_s3 != NULL) {
        temp_s7 = D_800C02AE + 0x7CE2;
        temp_fp = D_800AE850 + 0x6DAC;
        do {
            var_a1 = 0;
            var_s2 = 0;
            temp_v1 = (s32)D_800ADFE0 - 1;
            var_a0 = (char *)M2C_FIELD(M2C_FIELD(var_s3, void **, 0x6C), s32 *, 0) + 4;
__repair_literal = 0;

            if (temp_v1 > __repair_literal) {
                do {
                    var_a1 += 1;
                    var_s2 += *(s32 *)var_a0;
                    var_a0 += 4;
                } while ((var_a1 & 0xFF) < temp_v1);
            }
            temp_s0 = var_s4 & 0xFF;
            temp_s6 = M2C_FIELD(M2C_FIELD(var_s3, void **, 0x6C), s32 *, 8) - 1;
            temp_s1 = ((u8)temp_s6 * 3) << 3;
            *(void **)(D_800C02AE + 0x7CF6 + temp_s1) = var_s3;
            func_80098290(temp_s1 + temp_s7, *(void **)(D_800C02AE + 0x32F2) + ((M2C_FIELD((*(void **)(D_800C02AE + 0x32F2) + temp_s0), u8 *, 0x32) * 0x28) + 0x44), *(void **)(D_800C02AE + 0x32F2));
            *(D_800C02AE + 0x7CF3 + temp_s1) = var_s4;
            *(s32 *)(D_800C02AE + 0x7CE6 + temp_s1) = var_s2;
            *(D_800C02AE + 0x7CF4 + temp_s1) = (s8)M2C_FIELD((*(void **)(D_800C02AE + 0x32F2) + (M2C_FIELD((*(void **)(D_800C02AE + 0x32F2) + temp_s0), u8 *, 0x32) * 0x28)), u16 *, 0x4E);
            if (var_s2 != 0) {
                *(s32 *)(D_800C02AE + 0x7CEE + temp_s1) = (u32)(M2C_FIELD(((M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x22) * 4) + temp_s5), s32 *, 0x22C) * D_8009D540 * 0xE10) / (u32)(var_s2 * 0x3E8); } else {
                *(s32 *)(D_800C02AE + 0x7CEE + temp_s1) = 0;
            }
            temp_v1_2 = M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x1E);
            if (temp_v1_2 != 5) {
                temp_a2 = (var_s4 & 0xFF) << 5;
                temp_v1_3 = (s32 *)((temp_v1_2 * 4) + temp_fp + temp_a2);
                *temp_v1_3 += var_s2;
                if (var_s2 != 0) {
                    temp_a0 = (s32 *)((M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x1E) * 4) + (D_800AE850 + 0x6DBC) + temp_a2);
                    *temp_a0 += M2C_FIELD(((M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x22) * 4) + temp_s5), s32 *, 0x22C);
                }
            }
            temp_v1_4 = *M2C_FIELD(var_s3, s32 **, 0x48);
            temp_a3 = (temp_s6 & 0xFF) * 0x18;
            *(D_800C02AE + 0x7CF2 + temp_a3) = (s8)temp_v1_4;
            if (((u32)(temp_v1_4 & 0xFF) < 4U) && (*(s32 *)(D_800C02AE + 0x7CE6 + temp_a3) != 0) && !(M2C_FIELD(var_s3, s32 *, 0x14) & 0x200)) {
                func_80045404(var_s2, temp_s5, *(D_800C02AE + 0x7CF4 + temp_a3), temp_a3 + temp_s7, (s32)M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u8 *, 0x17), *(s32 *)(D_800C02AE + 0x7CEE + temp_a3));
            }
            var_s3 = M2C_FIELD(var_s3, void **, 4);
            var_s4 += 1;
        } while (var_s3 != NULL);
    }
    var_a1_2 = 0;
    var_v1 = 0;
    do {
        temp_v1_5 = (var_v1 * 3) << 3;
        temp_a0_2 = *(s32 *)(D_800C02AE + 0x7CE6 + temp_v1_5);
        var_a1_2 += 1;
        if (temp_a0_2 != 0) {
            var_v0 = temp_a0_2 - D_800C7F94;
            if (var_v0 < 0) {
                var_v0 = -var_v0;
            }
            *(s32 *)(D_800C02AE + 0x7CEA + temp_v1_5) = var_v0;
        } else {
            *(s32 *)(D_800C02AE + 0x7CEA + temp_v1_5) = 0;
        }
        var_v1 = var_a1_2 & 0xFF;
    } while ((u32)(var_a1_2 & 0xFF) < 4U);
    if ((M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0xE) == 2) && ((u32)D_800C7FDC < (u32)D_800C7FC4)) {
        temp_v1_6 = M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x1E);
        if (temp_v1_6 != 5) {
            temp_v1_7 = (s32 *)((temp_v1_6 * 4) + (D_800AE850 + 0x6DAC) + (D_800C7FE9 << 5));
            *temp_v1_7 += 0x3A98;
            D_800C7FDC = 0U;
            D_800C7FE4 = 0;
            D_800C7FE0 = 0;
        }
    }
    func_80098290(D_800C02AE + 0x7D42, temp_s5 + ((M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x22) << 6) + 0x2C) + 6, D_800C02AE + 0x7CE6);
    D_800C7FF4 = (s32)M2C_FIELD((temp_s5 + (M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x22) << 6)), s32 *, 0x2C);
    D_800C7FFC = (s32)M2C_FIELD((temp_s5 + (M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x22) << 6)), u8 *, 0x36);
    D_800C8002 = (u8)M2C_FIELD((temp_s5 + (M2C_FIELD(*(void **)(D_800C02AE + 0x32F2), u16 *, 0x22) << 6)), u8 *, 0x30);
}
