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

extern M2C_UNK gOrderState;

/* Returns the view's GFX context id (field at +0x20); falls back to the default context inside gOrderState when the view has none. */ s32 view_get_ctx_id(void *view) {
    s32 ctx_id;

    ctx_id = M2C_FIELD(view, s32 *, 0x20);
    if (ctx_id == 0) {
        ctx_id = M2C_FIELD(&gOrderState, s32 *, 0x7400);
    }
    return ctx_id;
}
