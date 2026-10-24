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



s32 func_80097E30();

void func_8001B514(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s8 temp_a0;
    s8 var_a1;
    void *temp_v1;

    func_80097E30(arg0, 0, 0x28);
    var_a1 = 0;
    *(s16 *)((char *)arg0 + 0xC) = 0;
    *(s8 *)((char *)arg0 + 9) = 1;
    do {
        temp_v0 = var_a1 << 0x18;
        temp_a0 = var_a1 + 1;
        var_a1 = temp_a0;
        temp_v0_2 = temp_v0 >> 0x18;
        temp_v1 = arg0 + temp_v0_2;
        *(s8 *)((char *)temp_v1 + 0x10) = 1;
        *(s8 *)((char *)temp_v1 + 0x14) = 1;
        *(s8 *)((char *)temp_v1 + 0x18) = 1;
        M2C_FIELD(((temp_v0_2 * 2) + arg0), s16 *, 0x1C) = 0;
    } while (temp_a0 < 4);
    *(s16 *)((char *)arg0 + 0xA) = 8;
    *(s8 *)((char *)arg0 + 4) = 7;
    *(s32 *)((char *)arg0 + 0x24) = 0x75834210;
}
