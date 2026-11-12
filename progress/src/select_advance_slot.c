/* Moves the select state's slot index (offset 0x228) to the next entry whose name starts with an uppercase letter. */ /* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s8 select_next_named_slot(s8);                               /* extern */
extern void *gSelectState;

s32 select_advance_slot(void) {
    M2C_FIELD(gSelectState, s8 *, 0x228) = select_next_named_slot(M2C_FIELD(gSelectState, s8 *, 0x228));
    return 0;
}
