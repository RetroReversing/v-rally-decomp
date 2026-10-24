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



s32 func_80035438();
s32 func_800803C0();
extern void **D_800A11B0;

void func_8004D31C(void) {
    void *temp_a0;
    void *var_s0;

    var_s0 = *D_800A11B0;
    if (var_s0 != NULL) {
        do {
            func_80035438(*(s32 *)((char *)var_s0 + 0xC));
            temp_a0 = var_s0;
            var_s0 = *(void * *)((char *)var_s0 + 4);
            func_800803C0(temp_a0, D_800A11B0);
        } while (var_s0 != NULL);
    }
    *D_800A11B0 = NULL;
}
