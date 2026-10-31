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

M2C_UNK func_8005A360(M2C_UNK, M2C_UNK);            /* extern */
extern void *D_800A1468;
extern M2C_UNK D_800A57B8;
extern M2C_UNK D_800C02AE;
extern M2C_UNK func_80066E20;
extern M2C_UNK func_80066EBC;

s32 func_80069734(void) {
    M2C_UNK sp10;
    s32 var_a0;
    s32 var_v0;
    s32 var_v0_2;
    s8 temp_v1;
    u8 temp_t0;
    u8 temp_v0;
    u8 var_a0_2;
    void *temp_a1;

    sp10 = M2C_UNALIGNED32(D_800A57B8);
    func_8005A360(0, 0);
    M2C_FIELD(D_800A1468, s8 *, 0x245) = 0;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x288) = &func_80066E20;
    M2C_FIELD(D_800A1468, M2C_UNK **, 0x28C) = &func_80066EBC;
    M2C_FIELD(D_800A1468, s8 *, 0x24D) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x22B) = -1;
    temp_a1 = M2C_FIELD(&D_800C02AE, void **, 0x32F2) + M2C_FIELD(D_800A1468, s8 *, 0x228);
    temp_t0 = M2C_FIELD(temp_a1, u8 *, 0x32);
    temp_v1 = M2C_FIELD(D_800A1468, s8 *, 0x22A);
    if ((temp_t0 & 0xFF) != temp_v1) {
        M2C_FIELD(temp_a1, u8 *, 0x32) = (u8) temp_v1;
        var_a0 = 0;
        if (M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0x32) == M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0x33)) {
            do {
                temp_v0 = M2C_FIELD((M2C_FIELD(&D_800C02AE, void **, 0x32F2) + (var_a0 & 0xFF)), u8 *, 0x32);
                var_a0 += 1;
                *(&sp10 + temp_v0) = 1;
            } while ((u32) (var_a0 & 0xFF) < 4U);
            var_a0_2 = 0;
            var_v0 = 0 & 0xFF;
loop_5:
            if (*(&sp10 + var_v0) != 0) {
                var_a0_2 += 1;
                var_v0 = var_a0_2 & 0xFF;
                if ((u32) (var_a0_2 & 0xFF) < 4U) {
                    goto loop_5;
                }
            }
            M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0x33) = var_a0_2;
        } else {
            var_v0_2 = 0 & 0xFF;
loop_9:
            if ((var_v0_2 == M2C_FIELD(D_800A1468, s8 *, 0x228)) || (M2C_FIELD((M2C_FIELD(&D_800C02AE, void **, 0x32F2) + var_v0_2), u8 *, 0x32) != M2C_FIELD(D_800A1468, s8 *, 0x22A))) {
                var_a0 += 1;
                var_v0_2 = var_a0 & 0xFF;
                if ((u32) (var_a0 & 0xFF) < 4U) {
                    goto loop_9;
                }
            }
            M2C_FIELD((M2C_FIELD(&D_800C02AE, void **, 0x32F2) + (var_a0 & 0xFF)), u8 *, 0x32) = temp_t0;
        }
    }
    M2C_FIELD(D_800A1468, s8 *, 0x24E) = 0;
    M2C_FIELD(D_800A1468, s8 *, 0x245) = 0;
    return 0;
}
