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

extern int D_800C72DC;
extern int D_800C72E0;


s32 func_8007F864();
extern u32 D_80000318;
extern char D_800A1924[];
extern s8 D_800A19D0;
extern char D_800C02AE[];

s32 func_8007F910(void) {
    if ((u32) D_80000318 > 0x400000U) {
        D_800C72DC = func_8007F864(0x80400000, D_80000318 - 0x400000);
        D_800A19D0 = 1;
    } else {
        D_800C72DC = (s32) D_800C72E0;
    }
    *(s32 * *)(D_800C02AE + 0x5906) = &D_800A1924;
    return 1;
}
