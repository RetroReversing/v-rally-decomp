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



s32 func_8008DCAC();
s32 func_8008DCCC();

void func_8008EC30(void *arg0) {
    s32 var_s0;
    void *var_s1;

    var_s1 = arg0;
    var_s0 = *(s32 *)((char *)var_s1 + 0x14);
    if (var_s0 != 0) {
        do {
            func_8008DCCC(var_s0);
            func_8008DCAC(var_s0, var_s1 + 4);
            var_s0 = *(s32 *)((char *)var_s1 + 0x14);
        } while (var_s0 != 0);
    }
}
