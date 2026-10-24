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



s16 func_80010DEC();

void func_800735D0(void *arg0, s32 arg1) {
    u16 temp_v0;
    u32 var_s1;
    void *var_s0;

    var_s1 = 0;
    var_s0 = arg0;
loop_1:
    temp_v0 = *(u16 *)((char *)var_s0 + 0xC);
    if (temp_v0 == 0) {
        goto block_3;
    }
    *(u16 *)((char *)var_s0 + 0xC) = (u16) (temp_v0 - 1);
    goto block_4;
block_3:
    *(s16 *)((char *)var_s0 + 0x24) = func_80010DEC(*(s16 *)((char *)var_s0 + 0x24), arg1, 0x28);
block_4:
    var_s1 += 1;
    var_s0 += 2;
    if (var_s1 < 0xCU) {
        goto loop_1;
    }
    return;
}
