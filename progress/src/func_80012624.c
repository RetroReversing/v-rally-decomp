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

/* Resets the state fields of obj: clears 0x8C and 0x84, sets 0x88 to 0x33. */ void func_80012624(void *obj) {
    M2C_FIELD(obj, s32 *, 0x8C) = 0;
    M2C_FIELD(obj, s16 *, 0x84) = 0;
    M2C_FIELD(obj, s32 *, 0x88) = 0x33;
}
