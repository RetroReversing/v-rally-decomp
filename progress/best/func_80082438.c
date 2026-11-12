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
extern M2C_UNK stream_state;

s32 func_80082438(s32 arg0) {
    s32 temp_v1;
    void *temp_s0;

    temp_v1 = M2C_FIELD(&gOrderState, s32 *, 0x8AC0);
    M2C_FIELD(&gOrderState, s32 *, 0x8AC0) = (s32) (temp_v1 + 1);
    temp_s0 = M2C_FIELD(&gOrderState, s32 *, 0x8AC8) + (temp_v1 * 0x2C);
    strCpy(temp_s0, arg0);
    M2C_FIELD(temp_s0, s32 *, 0x10) = (s32) M2C_FIELD(&gOrderState, s32 *, 0x8AD0);
    M2C_FIELD(temp_s0, s32 *, 0x14) = (s32) M2C_FIELD(M2C_FIELD(&gOrderState, void **, 0x8AE4), s32 *, 4);
    M2C_FIELD(temp_s0, u16 *, 0x1A) = (u16) M2C_FIELD(&stream_state, u16 *, 0x30BC);
    M2C_FIELD(temp_s0, u16 *, 0x18) = (u16) M2C_FIELD(&stream_state, u16 *, 0x30BA);
    M2C_FIELD(temp_s0, s32 *, 0x1C) = (s32) M2C_FIELD(&stream_state, s32 *, 0x30A6);
    M2C_FIELD(temp_s0, s32 *, 0x28) = (s32) M2C_FIELD(&stream_state, s32 *, 0x308E);
    M2C_FIELD(temp_s0, s32 *, 0x24) = (s32) M2C_FIELD(&stream_state, s32 *, 0x3092);
    M2C_FIELD(temp_s0, s32 *, 0x20) = (s32) M2C_FIELD(M2C_FIELD(&gOrderState, void **, 0x8AE4), s32 *, 0);
    return (s32) temp_s0;
}
