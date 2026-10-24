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

extern int D_800C8054;


extern s16 D_8009BBB4;
extern s32 D_8009BBB8;
extern s16 D_8009CEBC;
extern char D_800C02AE[];

void func_80015B00(void) {
    D_8009CEBC = 0x1C;
    D_8009BBB4 = 0;
    D_800C8054 = (s32) D_8009BBB8;
}
