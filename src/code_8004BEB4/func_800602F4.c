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



extern char D_800C02AE[];

s32 func_800602F4(void *arg0) {
    s8 temp_a0;
    s8 temp_a0_2;
    s8 temp_v1;

    if (M2C_FIELD(*(void * *)(D_800C02AE + 0x32F2), u8 *, 0x2E) == 0x17) {
        goto block_17;
    }
    temp_v1 = *(s8 *)((char *)arg0 + 0);
    if (temp_v1 != 0x4D) {
        goto block_3;
    }
    return 6;
block_3:
    if (temp_v1 != 0x43) {
        goto block_8;
    }
    temp_a0 = *(s8 *)((char *)arg0 + 1);
    if (temp_a0 != 0x4F) {
        goto block_6;
    }
    return 4;
block_6:
    if (temp_a0 != 0x41) {
        goto block_19;
    }
    return 2;
block_8:
    if (temp_v1 == 0x49) {
        goto block_18;
    }
    if (temp_v1 != 0x5A) {
        goto block_11;
    }
    return 5;
block_11:
    if (temp_v1 != 0x53) {
        goto block_16;
    }
    temp_a0_2 = *(s8 *)((char *)arg0 + 1);
    if (temp_a0_2 != 0x41) {
        goto block_14;
    }
    return 3;
block_14:
    if (temp_a0_2 != 0x55) {
        goto block_19;
    }
    return 7;
block_16:
    if (temp_v1 != 0x52) {
        goto block_19;
    }
block_17:
    return 1;
block_18:
block_19:
    return 0;
}
