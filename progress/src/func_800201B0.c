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

/* Copies src's state word (+0x90) into ctrl+0x1C, then sets the flag at ctrl's sub-block +0x6C: 0 when the state is 7, otherwise 1. */ void func_800201B0(void *src, void *ctrl) {
    s32 state;

    state = M2C_FIELD(src, s32 *, 0x90);
    *M2C_FIELD(ctrl, s32 **, 0x1C) = state;
    if (state == 7) {
        M2C_FIELD(M2C_FIELD(ctrl, void **, 0x30), s32 *, 0x6C) = 0;
        return;
    }
    M2C_FIELD(M2C_FIELD(ctrl, void **, 0x30), s32 *, 0x6C) = 1;
}
