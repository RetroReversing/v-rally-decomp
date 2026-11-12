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

M2C_UNK input_clear_flags(M2C_UNK, s32);            /* extern */
extern s32 D_8009D540;
extern M2C_UNK stream_state;

s32 stream_check_buttons(s32 arg0, s32 arg1) {
    if (arg0 == arg1) {
        input_clear_flags(0, arg0);
        M2C_FIELD(&stream_state, u8 *, 0x8116) = (u8) (M2C_FIELD(&stream_state, u8 *, 0x8116) + 1);
        M2C_FIELD(&stream_state, u8 *, 0x8117) = (u8) D_8009D540;
        return 1;
    }
    if ((u8) M2C_FIELD(&stream_state, u8 *, 0x8117) < 2U) {
        if (!(arg0 & arg1)) {
            M2C_FIELD(&stream_state, u8 *, 0x8116) = 0U;
            M2C_FIELD(&stream_state, u8 *, 0x8117) = (u8) D_8009D540;
        }
    }
    return 0;
}
