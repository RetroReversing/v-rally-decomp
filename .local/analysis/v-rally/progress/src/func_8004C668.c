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

extern M2C_UNK D_800C02AE;

void func_8004C668(void **arg0) {
    M2C_UNK (*temp_v0)(void *);
    void *temp_s1;
    void *temp_s2;
    void *var_s0;

    var_s0 = *arg0;
    temp_s2 = M2C_FIELD(&D_800C02AE, void **, 0x7CD6);
    if (var_s0 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s0, void **, 4);
            if (M2C_FIELD(var_s0, s32 *, 0xC) & 1) {
                temp_v0 = M2C_FIELD(var_s0, M2C_UNK (**)(void *), 0x54);
                if (temp_v0 != NULL) {
                    temp_v0(var_s0);
                }
                if (!(M2C_FIELD(var_s0, s32 *, 0xC) & 2)) {
                    M2C_FIELD(var_s0, M2C_UNK (**)(s32, void *), 0x50)(M2C_FIELD(temp_s2, s32 *, 0x178), var_s0);
                }
            }
            var_s0 = temp_s1;
        } while (var_s0 != NULL);
    }
}
