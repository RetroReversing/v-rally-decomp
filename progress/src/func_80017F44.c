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

extern f32 vtx_scale;
extern f32 uv_scale;
extern f32 D_8009CEC8;

/* Scales the three words of the record that `*ref` points to: word 0 by vtx_scale, word 4
 * by uv_scale and word 8 by D_8009CEC8, truncating each back to an integer. */
void func_80017F44(void **ref) {
    void *rec;

    rec = *ref;
    M2C_FIELD(rec, s32 *, 0) = (s32) ((f32) M2C_FIELD(rec, s32 *, 0) * vtx_scale);
    M2C_FIELD(rec, s32 *, 4) = (s32) ((f32) M2C_FIELD(rec, s32 *, 4) * uv_scale);
    M2C_FIELD(rec, s32 *, 8) = (s32) ((f32) M2C_FIELD(rec, s32 *, 8) * D_8009CEC8);
}
