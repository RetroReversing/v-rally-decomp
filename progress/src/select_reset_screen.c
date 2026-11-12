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

M2C_UNK func_8002FB64();                            /* extern */
M2C_UNK select_reset_text_default();                            /* extern */
M2C_UNK select_begin_reset();                            /* extern */
M2C_UNK func_80084AD8();                            /* extern */
M2C_UNK stub_noop_80084AF4();                            /* extern */

/* Resets the select screen: restores default text, runs the reset steps in order, then marks the reset pending. Returns 0. */ s32 select_reset_screen(void) {
    select_reset_text_default();
    stub_noop_80084AF4();
    func_80084AD8();
    func_8002FB64();
    select_begin_reset();
    return 0;
}
