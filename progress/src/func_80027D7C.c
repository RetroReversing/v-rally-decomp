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

/* Steps arg0 toward arg1 by 50/128 of the difference (wrapped to 8 bits); results below 2 are returned as 0. */
s32 func_80027D7C(s32 from, s32 to) {
    u32 step;

    step = (from + ((u32) ((to - from) * 0x32) >> 7)) & 0xFF;
    return step & -(step >= 2U);
}
