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

extern M2C_UNK stream_state;

/* Resets three byte fields in stream_state: 0x38EE is set to 0x14, 0x38EF and 0x38F1 to 0. */ void stream_reset_state_bytes(void) {
    M2C_FIELD(&stream_state, s8 *, 0x38EE) = 0x14;
    M2C_FIELD(&stream_state, s8 *, 0x38EF) = 0;
    M2C_FIELD(&stream_state, s8 *, 0x38F1) = 0;
}
