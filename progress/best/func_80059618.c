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

M2C_UNK func_8000C22C(s32, s32, s32, s32, s32);     /* extern */
extern s32 D_800A1468;

void func_80059618(s8 *arg0, u8 arg1, s32 arg2, s32 arg3, u8 arg4) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_t0;
    s32 var_v0;
    u8 var_s0;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = D_800A1468 + (M2C_FIELD(arg0, s8 *, 0xA) * 2);
    var_s0 = M2C_FIELD(temp_v0, u8 *, 0xD0);
    temp_a0 = var_s0 & 0xFF;
    temp_t0 = D_800A1468;
    if (temp_a0 < (temp_a0 + M2C_FIELD(temp_v0, u8 *, 0xD1))) {
        var_v0 = temp_a0 * 4;
        do {
            func_8000C22C(M2C_FIELD((var_v0 + temp_t0), s32 *, 0xE4), arg1 & 0xFF, arg2 & 0xFF, arg3 & 0xFF, (s32) arg4);
            temp_v0_2 = D_800A1468 + (M2C_FIELD(arg0, s8 *, 0xA) * 2);
            var_s0 += 1;
            temp_a0_2 = var_s0 & 0xFF;
            var_v0 = temp_a0_2 * 4;
        } while (temp_a0_2 < (M2C_FIELD(temp_v0_2, u8 *, 0xD0) + M2C_FIELD(temp_v0_2, u8 *, 0xD1)));
    }
}
