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



s32 func_80005744();
extern char D_800C02AE[];

void *func_80042290(void *arg0) {
    s32 var_a0;
    void *var_s0;
    void *var_v0;

    var_s0 = arg0;
    var_a0 = *(s32 *)((char *)var_s0 + 0x178);
    *(void * *)(D_800C02AE + 0x7CD6) = var_s0;
    func_80005744(var_a0);
    var_v0 = var_s0;
    return var_v0;
}
