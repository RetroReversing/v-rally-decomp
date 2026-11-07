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

void func_8002D460(void *arg0, void *arg1, s32 arg2, s32 arg3, void *arg4) {
    M2C_FIELD(arg4, s32 *, 0) = (s32) ((M2C_FIELD(arg0, s32 *, 0) * arg2) + (M2C_FIELD(arg1, s32 *, 0) * arg3));
    M2C_FIELD(arg4, s32 *, 4) = (s32) ((M2C_FIELD(arg0, s32 *, 4) * arg2) + (M2C_FIELD(arg1, s32 *, 4) * arg3));
    M2C_FIELD(arg4, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s32 *, 8) * arg2) + (M2C_FIELD(arg1, s32 *, 8) * arg3));
}
