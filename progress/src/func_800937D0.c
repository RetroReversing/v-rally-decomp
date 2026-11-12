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

extern void *stream_default_slot;

/* Returns the word at +4 of obj, falling back to the default object D_800A2520 when obj is NULL. */ s32 func_800937D0(void *obj) {
    void *p;

    p = obj;
    if (p == NULL) {
        p = stream_default_slot;
    }
    return M2C_FIELD(p, s32 *, 4);
}
