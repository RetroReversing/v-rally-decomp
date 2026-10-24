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

extern unsigned char D_800AFA5C;
extern int D_800C81D4;


s32 func_80086B34();
s32 func_80086D90();
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80038F0C(void) {
    if ((D_800AFA5C != 0) || (M2C_FIELD(*(void * *)(D_800C02AE + 0x325A), s16 *, 2) != 0)) {
        func_80086B34(D_800C81D4 + 0x1B0);
        func_80086D90(D_800C81D4 + 0x1B0, 0x30);
    }
}
