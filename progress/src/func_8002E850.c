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

/* Wraps angle into the range [-0x800, 0x800) for a 4096-unit circle (one turn = 0x1000). */
s32 func_8002E850(s32 angle) {
    s32 biased;
    s32 wrapped;

    biased = angle;
    if (angle < 0) {
        biased = angle + 0xFFF;
    }
    wrapped = angle - ((biased >> 0xC) << 0xC);
    if (wrapped >= 0x800) {
        wrapped -= 0x1000;
    }
    if (wrapped < -0x800) {
        wrapped += 0x1000;
    }
    return wrapped;
}
