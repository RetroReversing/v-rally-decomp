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

extern s32 D_8009D538;

void func_8003A6D4(void *arg0, void *arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x94) != 0) {
        M2C_FIELD(arg0, u8 *, 0x90) = (u8) M2C_FIELD(arg1, u8 *, 0);
        M2C_FIELD(arg0, u8 *, 0x91) = (u8) M2C_FIELD(arg1, u8 *, 1);
        M2C_FIELD(arg0, u8 *, 0x92) = (u8) M2C_FIELD(arg1, u8 *, 2);
        M2C_FIELD(arg0, u8 *, 0x93) = (u8) M2C_FIELD(arg1, u8 *, 3);
        if (!(D_8009D538 & 2)) {
            M2C_FIELD(arg0, u8 *, 0x94) = (u8) (M2C_FIELD(arg0, u8 *, 0x94) - 1);
        }
    } else {
        M2C_FIELD(arg0, u8 *, 0x90) = 0xFFU;
        M2C_FIELD(arg0, u8 *, 0x91) = 0xFFU;
        M2C_FIELD(arg0, u8 *, 0x92) = 0xFFU;
        M2C_FIELD(arg0, u8 *, 0x93) = 0xFFU;
    }
}
