typedef struct { s32 w[20]; } Copy80;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
s32 func_8007EAA0(s32, s32);
u32 func_8008E118(u8 *);
s32 func_80098180(s32, void *);
extern u8 D_800A4E4C;
extern u8 D_800A4E50;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];

void func_80048D4C(void *arg0) {
    volatile s32 frame_pad[2];
    s32 temp_s6;
    s32 var_t3;
    s32 temp_v0_2;
    s8 var_a0;
    u32 *var_s1;
    u32 temp_v0;
    u32 var_s4;
    u32 var_t2;
    u8 *temp_s5;
    u8 *var_t4;
    u8 temp_s7;
    void *temp_t0;
    void *var_a2;
    void *var_a2_2;
    void *var_a2_3;
    void *var_a2_4;
    void *var_a2_5;
    void *var_a2_6;
    void *var_a3;
    void *var_a3_2;
    void *var_a3_3;
    void *var_a3_4;
    void *var_a3_5;
    void *var_a3_6;
    void *var_s0;
    void *var_s2;
    void *var_t0;

    var_s1 = NULL;
    var_s0 = NULL;
    temp_s7 = *(u8 *)(*(void **)(D_800C02AE + 0x32F2) + 0xF);
    var_s2 = **(void ***)(D_800AE850 + 0x6D94);
    var_s4 = 1;
    if (temp_s7 != 0) {
        temp_s6 = (s32)arg0 + 0x4C;
        temp_s5 = (u8 *)arg0 + 0x98;
        do {
            if (func_80098180(temp_s6, &D_800A4E4C) == 0) {
                *(s8 *)((char *)var_s2 + 0x3C) = (s8)*(s32 *)((char *)arg0 + 0x128);
                *(s8 *)((char *)var_s2 + 0x3D) = (s8)*(s32 *)((char *)arg0 + 0x174);
                var_s1 = (u32 *)((char *)var_s2 + 0x1C);
                var_s0 = (char *)var_s2 + 0xC;
                *(s8 *)((char *)var_s2 + 0x3E) = (s8)*(s32 *)((char *)arg0 + 0x1C0);
            } else if (func_80098180(temp_s6, &D_800A4E50) == 0) {
                *(s8 *)((char *)var_s2 + 0x74) = (s8)*(s32 *)((char *)arg0 + 0x128);
                *(s8 *)((char *)var_s2 + 0x75) = (s8)*(s32 *)((char *)arg0 + 0x174);
                var_s1 = (u32 *)((char *)var_s2 + 0x54);
                var_s0 = (char *)var_s2 + 0x44;
                *(s8 *)((char *)var_s2 + 0x76) = (s8)*(s32 *)((char *)arg0 + 0x1C0);
            }
            *(s32 *)((char *)var_s0 + 0x2C) = func_8007EAA0(1, 8);
            temp_v0 = func_8008E118(temp_s5);
            *var_s1 = temp_v0;
            *(s32 *)((char *)var_s0 + 0x24) = func_8007EAA0(6, temp_v0 * 0xF0);
            *(s32 *)((char *)var_s0 + 0x28) = func_8007EAA0(6, *var_s1 * 0xF0);
            var_t4 = temp_s5;
            var_t2 = 0;
            if (*var_s1 != 0) {
                var_t3 = 0;
                do {
                    temp_v0_2 = *var_t4 - 0x30;
                    *(s8 *)((char *)var_s1 + var_t2 + 4) = temp_v0_2;
                    var_a0 = temp_v0_2;
                    var_t0 = **(void ***)var_s0;
                    if (var_a0 & 0xFF) {
                        do {
                            var_t0 = *(void **)((char *)var_t0 + 4);
                            var_a0 -= 1;
                        } while (var_a0 & 0xFF);
                    }
                    var_a3 = var_t0;
                    var_a2 = (char *)var_t3 + *(s32 *)((char *)var_s0 + 0x24);
*(Copy80 *)var_a2 = *(Copy80 *)var_a3;
                    var_a3_2 = var_t0;
                    var_a2_2 = (char *)((var_t2 + *var_s1) * 0x50 + *(s32 *)((char *)var_s0 + 0x24));
*(Copy80 *)var_a2_2 = *(Copy80 *)var_a3_2;
                    var_a3_3 = var_t0;
                    var_a2_3 = (char *)(((*var_s1 * 2) + var_t2) * 0x50 + *(s32 *)((char *)var_s0 + 0x24));
*(Copy80 *)var_a2_3 = *(Copy80 *)var_a3_3;
                    var_a3_4 = var_t0;
                    var_a2_4 = (char *)var_t3 + *(s32 *)((char *)var_s0 + 0x28);
*(Copy80 *)var_a2_4 = *(Copy80 *)var_a3_4;
                    var_a3_5 = var_t0;
                    var_a2_5 = (char *)((var_t2 + *var_s1) * 0x50 + *(s32 *)((char *)var_s0 + 0x28));
*(Copy80 *)var_a2_5 = *(Copy80 *)var_a3_5;
                    var_a3_6 = var_t0;
                    temp_t0 = (char *)var_a3_6 + 0x50;
                    var_a2_6 = (char *)(((*var_s1 * 2) + var_t2) * 0x50 + *(s32 *)((char *)var_s0 + 0x28));
*(Copy80 *)var_a2_6 = *(Copy80 *)var_a3_6;
                    var_t4 += 1;
                    var_t2 += 1;
                    var_t3 += 0x50;
                } while (var_t2 < (u32)*var_s1);
            }
            var_s2 = *(void **)((char *)var_s2 + 4);
            var_s4 += 1;
        } while (temp_s7 >= var_s4);
    }
}
