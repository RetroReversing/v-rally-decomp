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



extern void *D_800A1468;

s32 func_80067644(void) {
    s8 temp_v0;

    temp_v0 = *(s8 *)((char *)D_800A1468 + 0x280);
    if (temp_v0 >= 0) {
        goto block_3;
    }
    *(u8 *)((char *)D_800A1468 + 0x281) = (u8) (*(u8 *)((char *)D_800A1468 + 0x281) - 1);
    if ((s8) *(u8 *)((char *)D_800A1468 + 0x281) >= 0) {
        goto block_8;
    }
    *(u8 *)((char *)D_800A1468 + 0x281) = 0x19U;
    goto block_8;
block_3:
    if (temp_v0 > 0) {
        goto block_5;
    }
    goto block_7;
block_5:
    *(s8 *)((char *)D_800A1468 + 0x280) = 0;
    goto block_8;
block_7:
    *(s8 *)((char *)D_800A1468 + 0x280) = -8;
block_8:
    return 0;
}
