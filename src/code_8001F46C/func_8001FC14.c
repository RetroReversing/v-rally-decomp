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

extern int D_800AFA6C;
extern int D_800AE858;


extern char D_800AE850[];
extern char D_800C02AE[];

void func_8001FC14(void) {
    if ((M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x1E) != 8) || (D_800AFA6C != 0x186A0)) {
        D_800AFA6C = (s32) (D_800AFA6C + 1);
    }
    if (D_800AE858 != 0) {
        D_800AE858 = (s32) (D_800AE858 - 1);
    }
}
