/* Resets the select state and selects item 4 with fixed text. */ /* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

M2C_UNK selectStateReset(M2C_UNK);                     /* extern */
M2C_UNK selectSetItem(M2C_UNK, M2C_UNK);            /* extern */

s32 func_8005E360(void) {
    selectStateReset(1);
    selectSetItem(4, 1);
    return 0;
}
