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

M2C_UNK osCreateMesgQueue(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK osCreateThread(M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK *, s32); /* extern */
M2C_UNK osStartThread(M2C_UNK *);                   /* extern */
extern M2C_UNK D_800A7780;
extern M2C_UNK D_800A9930;
extern s32 D_800B730C;
extern s32 D_800B7310;
extern M2C_UNK D_800C6E90;
extern M2C_UNK D_800C7938;
extern M2C_UNK func_80081130;

void func_800811E0(void) {
    osCreateMesgQueue(&D_800C7938, &D_800C6E90, 1);
    osCreateThread(&D_800A7780, 0xA, &func_80081130, 0, &D_800A9930, 0x7F);
    osStartThread(&D_800A7780);
    D_800B730C = 0;
    D_800B7310 = 0;
}
