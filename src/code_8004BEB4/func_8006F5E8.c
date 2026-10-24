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

extern unsigned char D_800C72CD;
extern unsigned char D_800C72CE;
extern unsigned char D_800C72CF;


extern char D_800C02AE[];

void *func_8006F5E8(void) {
    s32 var_v1;
    void *var_a0;
    void *var_v0;

    var_a0 = D_800C02AE + 0x701F;
    var_a0 = (void *) D_800C72CD;
    var_v1 = 0x44;
    var_v0 = NULL;
    if (var_a0 == (void *)0x44) {
        var_a0 = D_800C02AE + 0x7020;
        var_a0 = (void *) D_800C72CE;
        var_v1 = 0x45;
        if (var_a0 == (void *)0x45) {
            var_v0 = D_800C02AE + 0x7021;
            var_v0 = (void *) D_800C72CF;
            var_v0 = (void *) ((s32) var_v0 ^ 0x1D);
            var_v0 = (void *) (var_v0 == NULL);
        }
    }
    return var_v0;
}
