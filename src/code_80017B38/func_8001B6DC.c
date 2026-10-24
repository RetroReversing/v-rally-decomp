#include "common.h"

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

extern short D_800C3548;
extern short D_800C354A;
extern short D_800C354C;
extern short D_800C354E;
extern short D_800C3554;
extern short D_800C3550;
extern short D_800C3552;
extern int D_800C3558;


extern char D_800C02AE[];

void func_8001B6DC(void) {
    D_800C3548 = 4;
    D_800C354A = 4;
    D_800C354C = 2;
    D_800C354E = 5;
    D_800C3554 = 0;
    D_800C3550 = 0;
    D_800C3552 = 0;
    D_800C3558 = 0;
}
