/* Partial candidate from function #24294 in project #57; rechecked locally. */
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

void *func_80008500(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13, s32 arg14, s32 arg15) {
    s32 temp_a0;
    s32 temp_a1;
    s32 var_a0;
    s32 var_t5;
    s32 var_v0;
    s32 var_v1;
    void *temp_t3;
    void *temp_t3_2;
    void *temp_t3_3;
    void *temp_t3_4;
    void *temp_t3_5;
    void *temp_t3_6;

    temp_t3_2 = arg0 + 8;
    temp_t3_3 = temp_t3_2 + 8;
    temp_t3_4 = temp_t3_3 + 8;
    temp_t3_5 = temp_t3_4 + 8;
    temp_a0 = (arg2 & 7) << 0x15;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (temp_a0 | 0xFD100000);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (arg1 + ((s32) (arg6 * arg3) / 2));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_a0 | 0xF5100000);
    M2C_FIELD(temp_t3_2, s32 *, 4) = (s32) (((arg11 & 3) << 0x12) | (((arg13 & 0xF) << 0xE) | 0x07000000) | ((arg15 & 0xF) << 0xA) | ((arg10 & 3) << 8) | ((arg12 & 0xF) * 0x10) | (arg14 & 0xF));
    M2C_FIELD(temp_t3_2, s32 *, 8) = 0xE6000000;
    M2C_FIELD(temp_t3_3, s32 *, 4) = 0;
    M2C_FIELD(temp_t3_3, s32 *, 8) = 0xF3000000;
    var_t5 = arg3;
    if (arg3 < 0) {
        var_t5 = arg3 + 0xF;
    }
    temp_a1 = var_t5 >> 4;
    var_v1 = 0x800;
    if (temp_a1 > 0) {
        var_v1 = temp_a1 + 0x7FF;
    }
    var_a0 = ((s32) ((arg3 * arg8) + 3) >> 2) - 1;
    if (var_a0 >= 0x800) {
        var_a0 = 0x7FF;
    }
    if (temp_a1 > 0) {
        var_v0 = (var_v1 / temp_a1) & 0xFFF;
    } else {
        var_v0 = var_v1 & 0xFFF;
    }
    M2C_FIELD(temp_t3_4, s32 *, 4) = (s32) (((var_a0 & 0xFFF) << 0xC) | 0x07000000 | var_v0);
    temp_t3_6 = temp_t3_5 + 8;
    temp_t3 = temp_t3_6 + 8;
    M2C_FIELD(temp_t3_4, s32 *, 8) = 0xE7000000;
    M2C_FIELD(temp_t3_5, s32 *, 4) = 0;
    M2C_FIELD(temp_t3_6, s32 *, 4) = (s32) (((arg9 & 0xF) << 0x14) | ((arg11 & 3) << 0x12) | ((arg13 & 0xF) << 0xE) | ((arg15 & 0xF) << 0xA) | ((arg10 & 3) << 8) | ((arg12 & 0xF) * 0x10) | (arg14 & 0xF));
    M2C_FIELD(temp_t3_5, s32 *, 8) = (s32) (((arg2 & 7) << 0x15) | (((((s32) ((arg3 >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5000000));
    M2C_FIELD(temp_t3_6, s32 *, 8) = 0xF2000000;
    M2C_FIELD(temp_t3, s32 *, 4) = (s32) (((((arg3 - 1) * 4) & 0xFFF) << 0xC) | (((arg8 - 1) * 4) & 0xFFF));
    return temp_t3 + 8;
}
