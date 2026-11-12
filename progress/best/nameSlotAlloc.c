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

M2C_UNK strCpy(void *, s32);                        /* extern */
extern M2C_UNK gOrderState;

s32 nameSlotAlloc(s32 arg0) {
    s32 temp_v1;
    void *temp_s0;

    temp_v1 = M2C_FIELD(&gOrderState, s32 *, 0x8ABC);
    M2C_FIELD(&gOrderState, s32 *, 0x8ABC) = (s32) (temp_v1 + 1);
    temp_s0 = M2C_FIELD(&gOrderState, s32 *, 0x8AC4) + (temp_v1 * 0x468);
    strCpy(temp_s0, arg0);
    M2C_FIELD(temp_s0, s32 *, 0x10) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x7C) = 0;
    return (s32) temp_s0;
}
