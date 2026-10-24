#include "common.h"

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

void *func_80006008();                              /* extern */
M2C_UNK func_80006014(s32, s32);                    /* extern */
M2C_UNK func_80006298(s32);                         /* extern */
M2C_UNK func_800068C0(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_80006CF8(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80007404(s32, s32, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_800A1798;

void func_8007347C(s32 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_s1;
    s32 temp_s3;
    void *temp_v0;

    temp_v0 = func_80006008();
    M2C_FIELD(temp_v0, s32 *, 0) = 0xDE000000;
    M2C_FIELD(temp_v0, M2C_UNK **, 4) = &D_800A1798;
    func_80006014(arg0, temp_v0 + 8);
    temp_s3 = func_80006CF8(arg0, 0) & 0xFFFF;
    temp_s0 = arg2 - 3;
    temp_s1 = arg1 + arg3;
    temp_s0_2 = temp_s0 + arg4;
    func_800068C0(arg0, temp_s3, arg1, temp_s0, -4, (s32) arg1, (s32) temp_s0_2, -4, (s32) temp_s1, (s32) temp_s0_2, -4, (s32) temp_s1, (s32) temp_s0, -4);
    func_80007404(arg0, temp_s3, 0x1E, 0x32, 0x94, 0x78, 0x1E, 0x32, 0x94, 0x78, 0x1E, 0x32, 0x94, 0x78, 0x1E, 0x32, 0x94, 0x78);
    func_80006298(arg0);
}
