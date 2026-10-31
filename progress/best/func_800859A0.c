extern signed char D_800AFA40;
void func_80086138(s32, u8);
void func_800862A0(s32);
s32 osContInit(void *, u8 *, void *);
extern void *D_800A1B70;
extern char D_800AE850[];

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

s32 func_800859A0(s32 arg0) {
    s32 s3_reg;
    s32 s4_reg;
    u8 sp10;
    s32 var_s0;
    s32 var_s1;
    s32 var_v0;
    void *temp_v0;

    s4_reg = 1;
    s3_reg = 0xFFFF;
    var_s0 = 0;
    var_s1 = 0x1C;
    osContInit(D_800AE850 + 0x5A38, &sp10, D_800A1B70 + 0xC);
loop_1:
    if ((((s32)sp10 >> var_s0) & 1) && !(M2C_FIELD((D_800A1B70 + (var_s0 * 4)), u8 *, 0xF) & 8)) {
        if (var_s0 == 0) {
            D_800AFA40 = (s8)s4_reg;
        }
        M2C_FIELD(((M2C_FIELD(D_800A1B70, s32 *, 4) * 4) + D_800A1B70), void **, 0x34) = (void *)(D_800A1B70 + var_s1);
        M2C_FIELD((D_800A1B70 + var_s0), s8 *, 8) = 0;
        temp_v0 = (char *)((var_s0 * 2)); temp_v0 += (s32)(D_800A1B70);
        M2C_FIELD(temp_v0, s16 *, 0x44) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x4C) = (s16)s3_reg;
        M2C_FIELD(temp_v0, s16 *, 0x54) = 0;
        func_80086138(var_s0, sp10);
        func_800862A0(var_s0);
        M2C_FIELD(D_800A1B70, u8 *, 0x39C) |= 1;
        M2C_FIELD(D_800A1B70, s32 *, 4) += 1;
        var_v0 = M2C_FIELD(D_800A1B70, volatile s32 *, 4);
        if (var_v0 != arg0) {
            goto block_6;
        }
    } else {
block_6:
        var_s0 += 1;
        var_s1 += 6;
        if (var_s0 >= 4) {
            var_v0 = M2C_FIELD(D_800A1B70, s32 *, 4);
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
