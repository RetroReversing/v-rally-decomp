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

void func_80010F3C(void *arg0, s32 arg1) {
    u16 var_v0;
    void *var_v1;

    if (arg1 != 0) {
        var_v1 = D_800C02AE + 0x7CD6;
        var_v1 = *(void * *)(D_800C02AE + 0x7CD6);
        var_v0 = *(u16 *)((char *)var_v1 + 0x20);
        var_v0 |= 0x40;
        goto block_4;
    }
    var_v1 = D_800C02AE + 0x7CD6;
    var_v1 = *(void * *)(D_800C02AE + 0x7CD6);
    var_v0 = *(u16 *)((char *)var_v1 + 0x20);
    var_v0 &= 0x40;
    if (var_v0 != 0) {
        var_v0 = *(u16 *)((char *)arg0 + 0x68);
        var_v0 |= 2;
        *(u16 *)((char *)arg0 + 0x68) = var_v0;
        var_v0 = *(u16 *)((char *)var_v1 + 0x20);
        var_v0 &= 0xFFBF;
block_4:
        *(u16 *)((char *)var_v1 + 0x20) = var_v0;
    }
}
