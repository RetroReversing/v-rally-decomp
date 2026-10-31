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

extern char D_800C02AE[];

void func_8001D954(s32 arg0) {
    char *var_v1;
    s32 temp_v0;
    s32 var_a1;
    void *var_a0;

    var_a1 = 1;
    var_v1 = D_800C02AE + 0x10370;
    var_a0 = arg0 + 0x4C;
    do {
        temp_v0 = M2C_FIELD(var_a0, s32 *, 0x44);
        var_a0 += 0x4C;
        var_a1 += 1;
        *(s16 *)var_v1 = (s16) temp_v0;
        var_v1 += 2;
    } while (var_a1 < 0xB);
}
