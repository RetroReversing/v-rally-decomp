/* Clears the pending select-state request flags, resets the select state, and sets the mask slot to 3. */ /* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g, tried by autopilot */
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

M2C_UNK select_reset_all();                            /* extern */
extern s8 select_reset_requested;
extern s8 D_800A14D5;
extern s8 gMaskSlot;

s32 select_reset_requests(void) {
    select_reset_requested = 0;
    select_reset_all();
    D_800A14D5 = 0;
    gMaskSlot = 3;
    return 0;
}
