/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g, tried by autopilot */
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

s32 func_8007F864(M2C_UNK, s32);                    /* extern */
extern u32 D_80000318;
extern M2C_UNK D_800A1924;
extern s8 D_800A19D0;
extern M2C_UNK D_800C02AE;

s32 func_8007F910(void) {
    if ((u32) D_80000318 > 0x400000U) {
        M2C_FIELD(&D_800C02AE, s32 *, 0x702E) = func_8007F864(0x80400000, D_80000318 - 0x400000);
        D_800A19D0 = 1;
    } else {
        M2C_FIELD(&D_800C02AE, s32 *, 0x702E) = (s32) M2C_FIELD(&D_800C02AE, s32 *, 0x7032);
    }
    M2C_FIELD(&D_800C02AE, M2C_UNK **, 0x5906) = &D_800A1924;
    return 1;
}
