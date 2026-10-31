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

s32 func_8001FEDC(void *);                          /* extern */
s32 func_8002D2A0(s32);                             /* extern */
M2C_UNK func_8002E778(s32 *, s32 *);                /* extern */
M2C_UNK func_800306A8(void *, s32, s32 *);          /* extern */
extern s32 D_8009EB80;
extern M2C_UNK D_8009EB90;
extern M2C_UNK D_8009F510;
extern M2C_UNK D_800C02AE;

void func_800344F0(void *arg0, void *arg1) {
    s32 sp10;
    s32 sp18;
    s32 temp_s3;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_s4;
    s32 var_v1_2;
    u16 temp_a0;
    u32 temp_v1_2;
    void *temp_s5;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v1;
    void *var_v1;
    void *var_v1_3;

    temp_v1 = M2C_FIELD(arg1, void **, 0x60);
    temp_s5 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x8C), void **, 0x2C);
    temp_s6 = M2C_FIELD(temp_v1, s32 *, 0x170);
    temp_s3 = M2C_FIELD(temp_v1, s32 *, 0x2C);
    M2C_FIELD(arg0, void **, 0) = temp_s5;
    M2C_FIELD(arg0, s32 *, 0xC) = temp_s3;
    temp_v0 = M2C_FIELD(arg1, void **, 0x60);
    var_s4 = M2C_FIELD(temp_v0, s32 *, 0x154);
    var_s0 = M2C_FIELD(temp_v0, s32 *, 0x150);
    temp_s7 = func_8001FEDC(arg1);
    if ((var_s0 == M2C_FIELD(temp_s5, s32 *, 0x58)) || ((var_s0 == (s32) temp_s5) & (var_s4 < temp_s3))) {
        temp_v0_2 = M2C_FIELD(var_s0, s32 *, 0x5C);
        if (temp_v0_2 != 0) {
            var_s0 = temp_v0_2;
            if (M2C_FIELD(M2C_FIELD(var_s0, void **, 0x78), u16 *, 0x18) == 0x2EE0) {
                do {
                    var_s0 = M2C_FIELD(var_s0, s32 *, 0x5C);
                } while (M2C_FIELD(M2C_FIELD(var_s0, void **, 0x78), u16 *, 0x18) == 0x2EE0);
            }
        }
        var_s4 = (s32) M2C_FIELD(M2C_FIELD(var_s0, void **, 0x78), u8 *, 0x1A);
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x60), s32 *, 0x154) = var_s4;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x60), s32 *, 0x150) = var_s0;
    }
    M2C_FIELD(arg0, s32 *, 4) = var_s0;
    M2C_FIELD(arg0, s32 *, 8) = var_s4;
    temp_a0 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0x78), u16 *, 0x18);
    M2C_FIELD(arg0, u32 *, 0x10) = (u32) temp_a0;
    if (temp_s6 == 0) {
        M2C_FIELD(arg0, u32 *, 0x10) = (u32) (temp_a0 - ((temp_a0 * *(&D_8009F510 + (M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x16) * 0x30))) / 100));
    }
    temp_v1_2 = *(&D_8009EB90 + (D_8009EB80 * 0x18));
    if ((u32) M2C_FIELD(arg0, u32 *, 0x10) < temp_v1_2) {
        M2C_FIELD(arg0, u32 *, 0x10) = temp_v1_2;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    var_v1 = temp_s5;
    var_a0 = 0;
    if (var_v1 != var_s0) {
loop_12:
        temp_v0_3 = M2C_FIELD(var_v1, void **, 0x5C);
        if (temp_v0_3 != NULL) {
            var_v1 = temp_v0_3;
            var_a0 += 1;
            if (var_v1 != var_s0) {
                goto loop_12;
            }
        }
    }
    if (var_a0 < 4) {
        func_800306A8((void *) var_s0, var_s4, &sp10);
        sp10 -= M2C_FIELD(M2C_FIELD(arg1, void **, 0x80), s32 *, 0x2CC);
        sp18 -= M2C_FIELD(M2C_FIELD(arg1, void **, 0x80), s32 *, 0x2D4);
        func_8002E778(&sp10, &sp10);
        M2C_FIELD(arg0, s32 *, 0x14) = func_8002D2A0(sp10 + sp18);
    } else {
        M2C_FIELD(arg0, s32 *, 0x14) = 0xFDE8;
    }
    var_v1_2 = M2C_FIELD(arg0, s32 *, 0x14);
    if (var_v1_2 < 0) {
        var_v1_2 += 0x7F;
    }
    temp_v0_4 = var_v1_2 >> 7;
    var_v1_3 = temp_s5;
    var_a0_2 = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) ((s32) (temp_s7 - M2C_FIELD(arg0, u32 *, 0x10)) / (s32) (temp_v0_4 + (temp_v0_4 == 0)));
    if (var_v1_3 != var_s0) {
loop_20:
        if (M2C_FIELD(var_v1_3, u16 *, 0xA) & 0x800) {
            var_v1_3 = M2C_FIELD(var_v1_3, void **, 0x5C);
            var_a0_2 += 1;
            if (var_v1_3 != var_s0) {
                goto loop_20;
            }
        }
    }
    M2C_FIELD(arg0, s32 *, 0x18) = var_a0_2;
}
