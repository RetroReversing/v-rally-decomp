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

extern int D_800C81D4;


s32 func_80086B34();
s32 func_80086D90();
extern char D_800C02AE[];

void func_80038ED4(void) {
    func_80086B34(D_800C81D4 + 0x1A4);
    func_80086D90(D_800C81D4 + 0x1A4, 0x30);
}
