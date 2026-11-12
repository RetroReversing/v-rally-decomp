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

void *dispatch_name_handler(s32, s32);              /* extern */
s32 str_len(s32);                                   /* extern */
M2C_UNK str_ncat(s32, M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_800A47BC;
extern M2C_UNK gOrderState;
extern M2C_UNK stream_state;

void func_8001D344(s32 arg0) {
    s32 temp_s0;
    void *temp_v0;

    temp_s0 = arg0 + 0x4C;
    str_ncat(temp_s0, &D_800A47BC, str_len(temp_s0));
    temp_v0 = dispatch_name_handler(M2C_FIELD(M2C_FIELD(&stream_state, void **, 0x5A72), s32 *, 0x10), arg0);
    M2C_FIELD(&gOrderState, void **, 0x8A28) = temp_v0;
    M2C_FIELD(temp_v0, s32 *, 0x80) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x80) | 0x40);
}
