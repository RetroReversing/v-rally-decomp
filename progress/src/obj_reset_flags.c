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

/* Resets the per-object state: clears the flag at +0xD1, copies +0x3C into +0x8C, and keeps bit 6 of +0xB5 in +0xD2. */ void obj_reset_flags(void *obj) {
    M2C_FIELD(obj, s8 *, 0xD1) = 0;
    M2C_FIELD(obj, s32 *, 0x8C) = (s32) M2C_FIELD(obj, s32 *, 0x3C);
    M2C_FIELD(obj, s8 *, 0xD2) = (s8) (M2C_FIELD(obj, u8 *, 0xB5) & 0x40);
}
