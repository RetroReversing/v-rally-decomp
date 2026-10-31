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

M2C_UNK func_80059154(M2C_UNK);                     /* extern */
M2C_UNK func_80059FB4();                            /* extern */
M2C_UNK func_8005A0A8();                            /* extern */
M2C_UNK func_8007EE9C(M2C_UNK *);                   /* extern */
extern void *D_800A1468;

void func_8005A100(void) {
    M2C_UNK (*temp_v0)();
    M2C_UNK *temp_a0;
    M2C_UNK *temp_a0_2;
    M2C_UNK *temp_a0_4;
    M2C_UNK *temp_a0_5;
    M2C_UNK *temp_s2;
    M2C_UNK *var_s0_2;
    M2C_UNK *var_s0_3;
    M2C_UNK *var_s3;
    M2C_UNK *var_s3_2;
    M2C_UNK *var_s4;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s1_4;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    u8 temp_s0;
    void *temp_a0_3;

    temp_v0 = M2C_FIELD(D_800A1468, M2C_UNK (**)(), 0x294);
    if (temp_v0 != NULL) {
        temp_v0();
        M2C_FIELD(D_800A1468, M2C_UNK (**)(), 0x294) = NULL;
    }
    temp_s1 = M2C_FIELD(D_800A1468, s32 *, 0x14);
    M2C_FIELD(D_800A1468, s16 *, 0x222) = -1;
    if (temp_s1 != 0) {
        var_s4 = M2C_FIELD(D_800A1468, M2C_UNK **, 0xC);
        var_s1 = temp_s1 - 1;
        do {
            temp_s2 = var_s4;
            temp_s0 = M2C_FIELD(temp_s2, u8 *, 0x4C);
            var_s4 = M2C_FIELD(temp_s2, M2C_UNK **, 0);
            var_s3 = M2C_FIELD(temp_s2, M2C_UNK **, 0x28);
            if (temp_s0 != 0) {
                var_s0 = temp_s0 - 1;
                do {
                    temp_a0 = var_s3;
                    var_s3 = *temp_a0;
                    func_8007EE9C(temp_a0);
                } while (var_s0-- != 0);
            }
            func_8007EE9C(temp_s2);
        } while (var_s1-- != 0);
        M2C_FIELD(D_800A1468, s32 *, 0x14) = 0;
        M2C_FIELD(D_800A1468, s32 *, 0x10) = 0;
    }
    temp_s1_2 = M2C_FIELD(D_800A1468, s32 *, 8);
    var_s1_2 = temp_s1_2 - 1;
    if (temp_s1_2 != 0) {
        var_s3_2 = M2C_FIELD(D_800A1468, M2C_UNK **, 0);
        do {
            temp_a0_2 = var_s3_2;
            var_s3_2 = *temp_a0_2;
            func_8007EE9C(temp_a0_2);
        } while (var_s1_2-- != 0);
        M2C_FIELD(D_800A1468, s32 *, 8) = 0;
        M2C_FIELD(D_800A1468, s32 *, 4) = 0;
    }
    temp_a0_3 = D_800A1468;
    temp_s1_3 = M2C_FIELD(temp_a0_3, s32 *, 0x20);
    var_s1_3 = temp_s1_3 - 1;
    if (temp_s1_3 != 0) {
        var_s0_2 = M2C_FIELD(temp_a0_3, M2C_UNK **, 0x18);
        do {
            temp_a0_4 = var_s0_2;
            var_s0_2 = *var_s0_2;
            func_8007EE9C(temp_a0_4);
        } while (var_s1_3-- != 0);
        M2C_FIELD(D_800A1468, s32 *, 0x20) = 0;
        M2C_FIELD(D_800A1468, s32 *, 0x1C) = 0;
    }
    temp_s1_4 = M2C_FIELD(temp_a0_3, s32 *, 0x2C);
    if (temp_s1_4 != 0) {
        var_s0_3 = M2C_FIELD(temp_a0_3, M2C_UNK **, 0x24);
        var_s1_4 = temp_s1_4 - 1;
        do {
            temp_a0_5 = var_s0_3;
            var_s0_3 = *var_s0_3;
            func_8007EE9C(temp_a0_5);
        } while (var_s1_4-- != 0);
        M2C_FIELD(D_800A1468, s32 *, 0x2C) = 0;
        M2C_FIELD(D_800A1468, s32 *, 0x28) = 0;
    }
    func_80059154(1);
    func_80059154(4);
    func_80059FB4();
    func_8005A0A8();
}
