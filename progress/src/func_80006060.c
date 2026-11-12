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

/* Returns a running time value for a gfx context: a 32-bit base at +0x70 plus a 16-bit counter at +0x7A scaled by 16. */ s32 func_80006060(void *gfx_ctx) {
    return M2C_FIELD(gfx_ctx, s32 *, 0x70) + (M2C_FIELD(gfx_ctx, u16 *, 0x7A) * 0x10);
}
