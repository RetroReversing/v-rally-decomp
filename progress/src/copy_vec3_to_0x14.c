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

/* Copies a 3-word vector into the object at offset 0x14 and returns the object. */ s8 *copy_vec3_to_0x14(s8 *obj, s32 *vec) {
    M2C_FIELD(obj, s32 *, 0x14) = (s32) M2C_FIELD(vec, s32 *, 0);
    M2C_FIELD(obj, s32 *, 0x18) = (s32) M2C_FIELD(vec, s32 *, 4);
    M2C_FIELD(obj, s32 *, 0x1C) = (s32) M2C_FIELD(vec, s32 *, 8);
    return obj;
}
