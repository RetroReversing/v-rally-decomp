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

extern M2C_UNK D_800AE850;

void func_8002D830(void *arg0) {
    M2C_FIELD(&D_800AE850, u16 *, 0x7928) = (u16) M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD(&D_800AE850, u16 *, 0x792A) = (u16) M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD(&D_800AE850, u16 *, 0x792C) = (u16) M2C_FIELD(arg0, u16 *, 4);
    M2C_FIELD(&D_800AE850, u16 *, 0x792E) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(&D_800AE850, u16 *, 0x7930) = (u16) M2C_FIELD(arg0, u16 *, 8);
    M2C_FIELD(&D_800AE850, u16 *, 0x7932) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    M2C_FIELD(&D_800AE850, u16 *, 0x7934) = (u16) M2C_FIELD(arg0, u16 *, 0xC);
    M2C_FIELD(&D_800AE850, u16 *, 0x7936) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
    M2C_FIELD(&D_800AE850, u16 *, 0x7938) = (u16) M2C_FIELD(arg0, u16 *, 0x10);
}
