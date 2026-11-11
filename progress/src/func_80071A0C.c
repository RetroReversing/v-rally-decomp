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

M2C_UNK league_set_flag14(s32);                         /* extern */
extern void *gSelectState;
extern M2C_UNK gStreamState;

s32 func_80071A0C(void) {
    M2C_FIELD(gSelectState, s8 *, 0x245) = 0;
    league_set_flag14(M2C_FIELD(&gStreamState, s32 *, 0x325A));
    return M2C_FIELD(M2C_FIELD(&gStreamState, void **, 0x32F2), u16 *, 0x20) + 0x15;
}
