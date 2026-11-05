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

void *func_80022318(void **, u8 *);
void *func_800801D0();
s32 func_80080440();

s32 func_800223B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_s0;
    void *temp_v0;

    if (arg4 == 0) {
        temp_v0 = func_80022318((void **)(arg0), (u8 *)(arg3));
        if (temp_v0 != NULL) {
            return M2C_FIELD(temp_v0, s32 *, 0x10);
        }
        goto block_4;
    }
block_4:
    temp_s0 = func_800801D0(arg0, 0x1C);
    M2C_FIELD(temp_s0, s32 *, 0x10) = func_80080440();
    M2C_FIELD(temp_s0, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_s0, s32 *, 0x18) = arg2;
    M2C_FIELD(temp_s0, s32 *, 0xC) = arg3;
    return M2C_FIELD(temp_s0, s32 *, 0x10);
}
