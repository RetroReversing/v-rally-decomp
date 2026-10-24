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



s32 func_8007EE9C();

s32 func_80005E3C(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;
    void *var_s0;
    void *var_s1;

    var_s0 = arg0;
    var_s1 = var_s0;
    if (var_s0 != NULL) {
        temp_a0 = *(void * *)((char *)var_s0 + 0x10);
        if (temp_a0 != NULL) {
            func_8007EE9C(temp_a0);
            *(void * *)((char *)var_s0 + 0x10) = NULL;
        }
        temp_a0_2 = *(void * *)((char *)var_s0 + 0x70);
        if (temp_a0_2 != NULL) {
            func_8007EE9C(temp_a0_2);
            *(void * *)((char *)var_s0 + 0x70) = NULL;
        }
        return func_8007EE9C(var_s1);
    }
    return 0;
}
