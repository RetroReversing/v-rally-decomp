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

void func_8005A05C(s32 arg0) {
    s32 var_a0;
    s32 var_a1;
    void **var_v0;
    void *var_v1;

    var_v0 = D_800C02AE + 0x5A7A;
    var_v0 = *(void ** *)(D_800C02AE + 0x5A7A);
    var_v0 = *(void ** *)((char *)var_v0 + 0x10);
    var_v1 = *var_v0;
    var_a1 = 0;
    if (var_v1 != NULL) {
        var_a0 = arg0 & 0xFF;
loop_2:
        var_v0 = (void **) (var_a1 & 0xFF);
        if (var_v0 == var_a0) {
            var_v0 = *(void ** *)((char *)var_v1 + 0xC);
            var_v0 = (void **) ((s32) var_v0 | 2);
            *(void ** *)((char *)var_v1 + 0xC) = var_v0;
            return;
        }
        var_v1 = *(void * *)((char *)var_v1 + 4);
        var_a1 += 1;
        if (var_v1 == NULL) {

        } else {
            goto loop_2;
        }
    }
}
