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

M2C_UNK func_80005838(s32);                         /* extern */
s32 func_80005948();                                /* extern */
s32 func_80005DEC();                                /* extern */
extern s32 D_8009B6E0;
extern s32 D_8009B6E4;
extern M2C_UNK D_800C02AE;

s32 func_8000DAA8(void) {
    s32 var_v1;

    M2C_FIELD(&D_800C02AE, s32 *, 0x7E12) = (s32) D_8009B6E4;
    if (D_8009B6E0 != 0) {
        func_80005838(D_8009B6E0);
        D_8009B6E0 = 0;
    }
    var_v1 = func_80005DEC();
    if (var_v1 & 0xFF) {
        var_v1 = func_80005948();
    }
    return var_v1 & 0xFF;
}
