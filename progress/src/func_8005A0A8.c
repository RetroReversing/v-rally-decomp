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

M2C_UNK func_800803C0(void *, void **);             /* extern */
extern M2C_UNK D_800C02AE;

void func_8005A0A8(void) {
    void *temp_a0;
    void *var_s0;

    var_s0 = *M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x5A7E), void ***, 0x10);
    if (var_s0 != NULL) {
        do {
            temp_a0 = var_s0;
            var_s0 = M2C_FIELD(var_s0, void **, 4);
            func_800803C0(temp_a0, M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x5A7E), void ***, 0x10));
        } while (var_s0 != NULL);
    }
}
