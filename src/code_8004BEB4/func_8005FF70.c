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



s32 func_800592F4();
extern char D_800C02AE[];

s32 func_8005FF70(void) {
    s32 var_a1;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x2A);
    if (!(temp_v1 & 0x1000)) {
        goto block_2;
    }
    goto block_4;
block_2:
    M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x2A) = (u16) (temp_v1 | 0x1000);
    var_a1 = 1;
    goto block_10;
block_4:
    if (!(temp_v1 & 0x2000)) {
        goto block_6;
    }
    goto block_8;
block_6:
    M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x2A) = (u16) (temp_v1 | 0x2000);
    var_a1 = 2;
    goto block_10;
block_8:
    var_a1 = 3;
    if (temp_v1 & 0x4000) {
        goto block_10;
    }
    M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u16 *, 0x2A) = (u16) (temp_v1 | 0x4000);
block_10:
    func_800592F4(0x1B, var_a1);
    return 0;
}
