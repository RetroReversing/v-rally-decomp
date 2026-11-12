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

void *order_table_search(s32, s32);                 /* extern */
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;

s32 order_lookup_info(s32 arg0, s32 *arg1, s8 *arg2) {
    void *temp_v0;

    temp_v0 = order_table_search(M2C_FIELD(&gOrderState, s32 *, 0x8AB8), arg0);
    *arg1 = M2C_FIELD(temp_v0, s32 *, 0x10);
    if (M2C_FIELD(temp_v0, u16 *, 0x1A) == 0) {
        *arg2 = 0;
    } else {
        *arg2 = 1;
    }
    return M2C_FIELD(&gOrderState, s32 *, 0x8AB0) + M2C_FIELD(temp_v0, s32 *, 0x1C) + (M2C_FIELD(temp_v0, s32 *, 0x28) - M2C_FIELD(&stream_state, s32 *, 0x308A));
}
