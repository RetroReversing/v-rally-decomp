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

extern f32 D_8009BB94;
extern f32 D_8009BB98;
extern f32 D_8009BB9C;
extern f32 D_8009BBA0;

void func_8001C79C(void *arg0) {
    D_8009BB94 = (f32) M2C_FIELD(arg0, s32 *, 0x90);
    D_8009BB98 = (f32) M2C_FIELD(arg0, s32 *, 0xDC);
    D_8009BB9C = (f32) M2C_FIELD(arg0, s32 *, 0x128);
    D_8009BBA0 = (f32) M2C_FIELD(arg0, s32 *, 0x174);
}
