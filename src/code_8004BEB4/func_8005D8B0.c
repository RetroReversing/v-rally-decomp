#include "checkpoint_common.h"

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

extern u8 D_800AFA49;
extern void *D_800C3508;
extern s32 D_800C8118;

void func_8005D8B0(void) {
    if (D_800C8118 > 0) {
        D_800C8118 -= 1;
        return;
    }
    if (D_800C8118 == 0) {
        D_800C8118 = -1;
        M2C_FIELD(D_800C3508, s16 *, 4) = 0;
    }
    if (D_800AFA49 == 1) {
        M2C_FIELD(((M2C_FIELD(D_800C3508, s16 *, 2) * 0x14) + M2C_FIELD(D_800C3508, s32 *, 0x10)), s32 *, 0x10) = (s32) D_800AFA49;
        return;
    }
    M2C_FIELD(((M2C_FIELD(D_800C3508, s16 *, 2) * 0x14) + M2C_FIELD(D_800C3508, s32 *, 0x10)), s32 *, 0x10) = 0x32;
}
