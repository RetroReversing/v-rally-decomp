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

extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;

void func_80062334(void) {
    M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u16 *, 0x1E) = (u16) M2C_FIELD(&stream_state, u16 *, 0x324E);
    M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u16 *, 0x20) = (u16) M2C_FIELD(&stream_state, u16 *, 0x80C0);
    M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x32F2), u16 *, 0x22) = (u16) M2C_FIELD(&gOrderState, u16 *, 0x87A0);
}
