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

M2C_UNK record_reset(s32);                         /* extern */
s32 poolAllocNode(s32, M2C_UNK);                    /* extern */
extern M2C_UNK gStreamState;

s32 func_8001B614(void) {
    s32 temp_v0;

    temp_v0 = poolAllocNode(M2C_FIELD(&gStreamState, s32 *, 0x6C5E), 0xF4);
    M2C_FIELD(&gStreamState, s32 *, 0x32F2) = temp_v0;
    record_reset(temp_v0);
    return M2C_FIELD(&gStreamState, s32 *, 0x32F2);
}
