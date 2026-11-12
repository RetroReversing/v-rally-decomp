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

M2C_UNK slot_set_selected(M2C_UNK, s32);                /* extern */
extern M2C_UNK gStreamState;

s32 func_8005FDF4(void) {
    u16 temp_a1;

    temp_a1 = 1 - M2C_FIELD(M2C_FIELD(&gStreamState, void **, 0x32F2), u16 *, 0x1C);
    M2C_FIELD(M2C_FIELD(&gStreamState, void **, 0x32F2), u16 *, 0x1C) = temp_a1;
    slot_set_selected(0x18, temp_a1 & 0xFFFF);
    return 0;
}
